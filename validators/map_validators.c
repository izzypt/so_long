/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 15:45:08 by smagalha          #+#    #+#             */
/*   Updated: 2023/04/17 02:23:06 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	validate_map(char **map, t_map_data *map_info)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	validate_edges(map[0], map[map_info->lines_num - 1]);
	while (i < map_info->lines_num)
	{
		validate_line_len(map[i], map_info->line_len);
		validate_sides(map[i], map_info->line_len - 2);
		while (map[i][j] != '\0' && map[i][j] != '\n')
		{
			count_map_components(map[i][j], map_info);
			j++;
		}
		j = 0;
		i++;
	}
	printf("The map is valid\n");
	printf("Map info:\n");
	printf("Walls: %d\n", map_info->walls_num);
	printf("Floors: %d\n", map_info->floor_num);
	printf("Collectibles: %d\n", map_info->collectables_num);
	printf("Exits: %d\n", map_info->exit_num);
	printf("Players: %d\n", map_info->players_num);
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