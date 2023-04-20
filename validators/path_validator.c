/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:40:26 by smagalha          #+#    #+#             */
/*   Updated: 2023/04/20 12:10:47 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_clone(char **matriz)
{
	int	i;

	i = 0;
	while (i < map()->lines_num)
	{
		free(matriz[i]);
		i++;
	}
	free(matriz);
}

void	validate_clone(char **matriz)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map()->lines_num)
	{
		while (j < map()->line_len)
		{
			ft_printf("%c ", matriz[i][j]);
			j++;
		}
		j = 0;
		i++;
		ft_printf("\n");
	}
	if (i == map()->lines_num)
		free_clone(matriz);
}

void	fill_clone(char **matriz, int x, int y)
{
	if (x < 0 || y < 0 || x >= map()->line_len || y >= map()->lines_num)
		return ;

	if (matriz[y][x] == 'P' || matriz[y][x] == '0' || \
	matriz[y][x] == 'E' || matriz[y][x] == 'C')
	{
		matriz[y][x] = '1';
		fill_clone(matriz, x - 1, y);
		fill_clone(matriz, x + 1, y);
		fill_clone(matriz, x, y - 1);
		fill_clone(matriz, x, y + 1);
	}
	ft_printf("Reached the end\n");
	validate_clone(matriz);
}

char	**make_clone(char **matrix)
{
	char	**clone;
	int		i;
	int		j;

	i = 0;
	j = 0;
	clone = malloc(sizeof(char *) * map()->lines_num);
	printf("Making clone\n");
	while (i < map()->lines_num)
	{
		clone[i] = malloc(map()->line_len + 1);
		while (j < (int)map()->line_len)
		{
			clone[i][j] = matrix[i][j];
			printf("%c", clone[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
	fill_clone(clone, player()-> x, player()-> y);
	return (clone);
}
