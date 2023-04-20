/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:40:26 by smagalha          #+#    #+#             */
/*   Updated: 2023/04/20 20:21:20 by smagalha         ###   ########.fr       */
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
		while (j < (int)map()->line_len)
		{
			if (matriz[i][j] == 'C' || matriz[i][j] == 'E')
			{
				perror("Map is invalid!");
				exit(0);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	fill_clone(char **matriz, int x, int y, int *counter)
{
	if (x < 0 || y < 0 || x >= (int)map()->line_len || \
	y >= map()->lines_num || matriz[y][x] == '1')
		return ;
	if (matriz[y][x] == 'P' || matriz[y][x] == '0' || \
	matriz[y][x] == 'E' || matriz[y][x] == 'C')
	{
		matriz[y][x] = '1';
		(*counter)++;
		fill_clone(matriz, x - 1, y, counter);
		fill_clone(matriz, x + 1, y, counter);
		fill_clone(matriz, x, y - 1, counter);
		fill_clone(matriz, x, y + 1, counter);
		(*counter)--;
	}
	if (*counter == 0)
		validate_clone(matriz);
}

char	**make_clone(char **matrix)
{
	char	**clone;
	int		i;
	int		j;
	int		clone_calls;

	i = 0;
	j = 0;
	clone_calls = 0;
	clone = malloc(sizeof(char *) * map()->lines_num);
	while (i < map()->lines_num)
	{
		clone[i] = malloc(map()->line_len + 1);
		while (j < (int)map()->line_len)
		{
			clone[i][j] = matrix[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	fill_clone(clone, player()-> x, player()-> y, &clone_calls);
	return (clone);
}
