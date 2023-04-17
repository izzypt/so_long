/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:03:15 by smagalha          #+#    #+#             */
/*   Updated: 2023/04/17 15:39:00 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_window(char **map_matrix, t_map_data *map_info)
{
	void	*mlx;
	void	*window;
	int		win_width;
	int		win_height;

	win_width = (map_info->line_len - 1) * 32;
	win_height = (map_info->lines_num) * 32;
	mlx = mlx_init();
	window = mlx_new_window(mlx, win_width, win_height, "SoLong!");
	draw_player(mlx, window);
	draw_walls(map_matrix, mlx, window, map_info);
	mlx_loop(mlx);
}

void	draw_walls(char **map, void *mlx, void *win, t_map_data *map_inf)
{
	int		i;
	int		j;
	void	*rock;
	void	*water;
	int		wdth;
	int		height;


	i = 0;
	j = 0;
	wdth = 32;
	height = 32;
	rock = mlx_xpm_file_to_image(mlx, ROCK, &wdth, &height);
	water = mlx_xpm_file_to_image(mlx, WATER, &wdth, &height);
	while (map[j] != 0)
	{
		while (map[j][i] != '\n')
		{
			if (j == 0)
				mlx_put_image_to_window(mlx, win, rock, i * 32, 0);
			else if (j != 0 && i == 0)
				mlx_put_image_to_window(mlx, win, rock, 0, j * 32);
			else if (j == map_inf->lines_num - 1)
				mlx_put_image_to_window(mlx, win, rock, i * 32, j * 32);
			else if ((size_t)i == map_inf->line_len - 2)
				mlx_put_image_to_window(mlx, win, rock, i * 32, j * 32);
			else
			{
				if (map[j][i] == '1')
					mlx_put_image_to_window(mlx, win, rock, i * 32, j * 32);
				else
					mlx_put_image_to_window(mlx, win, water, i * 32, j * 32);
			}
			i++;
		}
		i = 0;
		j++;
	}
}

void	draw_player(void *mlx, void *window)
{
	void	*img;
	int		img_wdth;
	int		img_hght;
	char	*player_path;

	player_path = "./sprites/jump.xpm";
	img_wdth = 32;
	img_hght = 32;
	img = mlx_xpm_file_to_image(mlx, player_path, &img_wdth, &img_hght);
	mlx_put_image_to_window(mlx, window, img, 250, 250);
}
