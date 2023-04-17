/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 13:55:50 by smagalha          #+#    #+#             */
/*   Updated: 2023/04/17 19:41:04 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map_data	*map(void)
{
	static t_map_data	map;

	return (&map);
}

char	**create_matrix(char *map_path)
{
	char		**matrix;
	int			i;
	int			fd;

	i = -1;
	fd = open(map_path, O_RDONLY);
	matrix = malloc(sizeof(char *) * map()->lines_num + 1);
	if (matrix == NULL)
		exit(1);
	while (++i < map()->lines_num)
		matrix[i] = get_next_line(fd);
	map()->line_len = ft_strlen(matrix[0]);
	validate_map(matrix);
	draw_window(matrix);
	close(fd);
	return (matrix);
}

void	read_map(char *map, t_map_data *map_data)
{
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		perror("cannot open provided map");
		exit(1);
	}
	while (1)
	{
		if (get_next_line(fd))
			map_data->lines_num ++;
		else
			break ;
	}
	close(fd);
	create_matrix(map);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		perror("Please provide a map\n");
		return (0);
	}
	read_map(argv[1], map());
}
//mlx_key_hook(vars.win_ptr, &deal_key, &vars);