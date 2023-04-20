/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 13:55:50 by smagalha          #+#    #+#             */
/*   Updated: 2023/04/20 00:01:00 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**create_matrix(char *map_path)
{
	int			i;
	int			fd;

	i = -1;
	fd = open(map_path, O_RDONLY);
	map()->matrix = malloc(sizeof(char *) * map()->lines_num + 1);
	if (map()->matrix == NULL)
		exit(1);
	while (++i < map()->lines_num)
		map()->matrix[i] = get_next_line(fd);
	map()->line_len = ft_strlen(map()->matrix[0]);
	validate_map(map()->matrix);
	close(fd);
	return (map()->matrix);
}

void	read_map(char *map_file)
{
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
	{
		perror("cannot open provided map");
		exit(1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line)
			map()->lines_num++;
		else
			break ;
		free(line);
	}
	close(fd);
	create_matrix(map_file);
}

int	main(int argc, char **argv)
{
	char	*accepted_format;

	accepted_format = ".ber";
	if (argc < 2)
	{
		perror("Please provide a map\n");
		return (0);
	}
	if (!ft_strnstr(argv[1], accepted_format, ft_strlen(argv[1])))
	{
		perror("Map format must be .ber");
		return (0);
	}
	else
		read_map(argv[1]);
}
