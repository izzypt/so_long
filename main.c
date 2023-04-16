/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 13:55:50 by smagalha          #+#    #+#             */
/*   Updated: 2023/04/16 19:26:38 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

//Read the map line by line and assign it to a 2D array.
char	**create_matrix(int fd)
{
	t_map_data	*map_data;
	char		**matrix;
	int			i;

	i = 0;
	map_data = malloc(sizeof(t_map_data) + 1);
	matrix = malloc(sizeof(char *) * 1000);
	if (matrix == NULL)
		exit(1);
	while (1)
	{
		matrix[i] = get_next_line(fd);
		if (matrix[i] == NULL)
		{
			map_data->lines_num = i;
			map_data->line_len = ft_strlen(matrix[0]);
			map_data->collectables_num = 0;
			break ;
		}
		i++;
	}
	validate_map(matrix, map_data);
	close(fd);
	return (matrix);
}

//Open the map and and call function to create matrix from it
void	read_map(char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	create_matrix(fd);
}

int	main(int argc, char **argv)
{
	int		fd;

	if (argc < 2)
	{
		perror("Please provide a map\n");
		return (0);
	}
	read_map(argv[1]);
	draw_window();
	//mlx_key_hook(vars.win_ptr, &deal_key, &vars);
}