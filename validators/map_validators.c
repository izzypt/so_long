/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 15:45:08 by smagalha          #+#    #+#             */
/*   Updated: 2023/04/16 18:38:09 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	validate_line_len(char *line, size_t valid_len)
{
	if (ft_strlen(line) != valid_len)
	{
		printf("original line length: %zu", valid_len);
		printf("current line length: %zu", ft_strlen(line));
		perror("Map lines must have the same length\n");
		exit(1);
	}
	return (1);
}

int	validate_edges(char	*top_line, char *bottom_line)
{
	int	i;

	i = 0;
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

int	validate_sides(char *line, int last_char_pos)
{
	if (line[0] != '1')
	{
		perror("First column must always be a wall");
		exit(1);
		return (0);
	}
	if (line[last_char_pos] != '1')
	{
		perror("Last column must always be a wall");
		exit(1);
		return (0);
	}
	return (1);
}

int	count_map_components(char element, t_map_data *map_info)
{
	if (element == 'C')
		map_info->collectables_num += 1;
	if (element == '1')
		map_info->walls_num += 1;
	if (element == '0')
		map_info->floor_num += 1;
	if (element == 'P')
		map_info->players_num += 1;
	if (element == 'E')
		map_info->exit_num += 1;
	return (1);
}