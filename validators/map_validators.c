/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 15:45:08 by smagalha          #+#    #+#             */
/*   Updated: 2023/04/18 21:55:23 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	validate_map(char **matrix)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	validate_edges(matrix[0], matrix[map()->lines_num - 1]);
	while (++i < map()->lines_num)
	{
		validate_line_len(matrix[i], map()->line_len);
		validate_sides(matrix[i]);
		while (matrix[i][j] != '\0' && matrix[i][j] != '\n')
		{
			count_map_components(matrix[i][j]);
			printf("%c", matrix[i][j]);
			j++;
		}
		j = 0;
	}
	validate_collectable_nums();
	draw_window();
	return (1);
}

int	validate_line_len(char *line, size_t valid_len)
{
	if (ft_strlen(line) != valid_len)
	{
		perror("Map lines must have the same length\n");
		exit(1);
	}
	return (1);
}

int	validate_edges(char	*top_line, char *bottom_line)
{
	while (*top_line != '\n')
	{
		if (*top_line != '1')
		{
			perror("Top/1st line must contain only walls");
			exit(1);
		}
		top_line++;
	}
	while (*bottom_line != '\n')
	{
		if (*bottom_line != '1')
		{
			perror("Invalid bottom line");
			exit(1);
		}
		bottom_line++;
	}
	return (1);
}

int	validate_sides(char *line)
{
	if (line[0] != '1')
	{
		perror("First column must always be a wall");
		exit(1);
		return (0);
	}
	if (line[map()->line_len - 2] != '1')
	{
		perror("Last column must always be a wall");
		exit(1);
		return (0);
	}
	return (1);
}
