/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 13:55:50 by smagalha          #+#    #+#             */
/*   Updated: 2023/04/17 12:05:55 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	draw_window(matrix, map_data);
	close(fd);
	return (matrix);
}

void	read_map(char *map)
{
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		perror("cannot open provided map");
		exit(1);
	}
	create_matrix(fd);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		perror("Please provide a map\n");
		return (0);
	}
	read_map(argv[1]);
}
//mlx_key_hook(vars.win_ptr, &deal_key, &vars);