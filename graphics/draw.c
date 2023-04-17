/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:03:15 by smagalha          #+#    #+#             */
/*   Updated: 2023/04/17 19:16:00 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	int_img(t_sprites *spr)
{
	spr->rock = mlx_xpm_file_to_image(map()->mlx, ROCK, &spr->width, &spr->height);
	printf("%p\n", spr->rock);
	spr->water = mlx_xpm_file_to_image(map()->mlx, WATER, &spr->width, &spr->height);
}

void	draw_window(char **map_matrix)
{
	int		win_wdth;
	int		win_hght;

	win_wdth = (map()->line_len - 1) * 32;
	win_hght = (map()->lines_num) * 32;
	map()->mlx = mlx_init();
	map()->win = mlx_new_window(map()->mlx, win_wdth, win_hght, "SoLong");
	int_img(&map()->spr);
	draw_player(map()->mlx, map()->win);
	draw_walls(map_matrix);
	mlx_loop(map()->mlx);
}


void	draw_walls(char **maps)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (j < map()->lines_num)
	{
		while (i < map()->line_len)
		{
			if (maps[j][i] == '1')
				mlx_put_image_to_window(map()->mlx, map()->win, map()->spr.rock, i * 32, j * 32);
			else
				mlx_put_image_to_window(map()->mlx, map()->win, map()->spr.water, i * 32, j * 32);
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
