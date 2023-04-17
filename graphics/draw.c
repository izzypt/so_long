/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:03:15 by smagalha          #+#    #+#             */
/*   Updated: 2023/04/17 20:30:33 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_sprites(t_sprites *spr)
{
	spr->rock = mlx_xpm_file_to_image(map()->mlx, ROCK, &spr->width, &spr->height);
	printf("%p\n", spr->rock);
	spr->water = mlx_xpm_file_to_image(map()->mlx, WATER, &spr->width, &spr->height);
	spr->fish = mlx_xpm_file_to_image(map()->mlx, FISH, &spr->width, &spr->height);
	spr->player_right = mlx_xpm_file_to_image(map()->mlx, PLAYER_RIGHT, &spr->width, &spr->height);
	spr->player_up = mlx_xpm_file_to_image(map()->mlx, PLAYER_UP, &spr->width, &spr->height);
	spr->player_down = mlx_xpm_file_to_image(map()->mlx, PLAYER_DOWN, &spr->width, &spr->height);
	spr->player_left = mlx_xpm_file_to_image(map()->mlx, PLAYER_LEFT, &spr->width, &spr->height);
	spr->exit = mlx_xpm_file_to_image(map()->mlx, EXIT, &spr->width, &spr->height);
}

void	draw_window(char **map_matrix)
{
	int		win_wdth;
	int		win_hght;

	win_wdth = (map()->line_len - 1) * 32;
	win_hght = (map()->lines_num) * 32;
	map()->mlx = mlx_init();
	map()->win = mlx_new_window(map()->mlx, win_wdth, win_hght, "SoLong");
	init_sprites(&map()->spr);
	draw_walls(map_matrix);
	mlx_loop(map()->mlx);
}


void	draw_walls(char **matrix)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (j < map()->lines_num)
	{
		while (i < map()->line_len)
		{
			if (matrix[j][i] == '1')
				mlx_put_image_to_window(map()->mlx, map()->win, map()->spr.rock, i * 32, j * 32);
			else
				mlx_put_image_to_window(map()->mlx, map()->win, map()->spr.water, i * 32, j * 32);
			if (matrix[j][i] == 'P')
				mlx_put_image_to_window(map()->mlx, map()->win, map()->spr.player_right, i * 32, j * 32);
			if (matrix[j][i] == 'C')
				mlx_put_image_to_window(map()->mlx, map()->win, map()->spr.fish, i * 32, j * 32);
			if (matrix[j][i] == 'E')
				mlx_put_image_to_window(map()->mlx, map()->win, map()->spr.exit, i * 32, j * 32);
			i++;
		}
		i = 0;
		j++;
	}
}

void	draw_player()
{
	mlx_put_image_to_window(map()->mlx, map()->win, map()->spr.player_right, 70, 70);
}
