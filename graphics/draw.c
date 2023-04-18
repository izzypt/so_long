/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:03:15 by smagalha          #+#    #+#             */
/*   Updated: 2023/04/18 20:57:15 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_sprites(t_sprites *spr)
{
	spr->rock = mlx_xpm_file_to_image(map()->mlx, ROCK, &spr->width, &spr->height);
	spr->water = mlx_xpm_file_to_image(map()->mlx, WATER, &spr->width, &spr->height);
	spr->fish = mlx_xpm_file_to_image(map()->mlx, FISH, &spr->width, &spr->height);
	spr->player_right = mlx_xpm_file_to_image(map()->mlx, PLAYER_RIGHT, &spr->width, &spr->height);
	spr->player_up = mlx_xpm_file_to_image(map()->mlx, PLAYER_UP, &spr->width, &spr->height);
	spr->player_down = mlx_xpm_file_to_image(map()->mlx, PLAYER_DOWN, &spr->width, &spr->height);
	spr->player_left = mlx_xpm_file_to_image(map()->mlx, PLAYER_LEFT, &spr->width, &spr->height);
	spr->exit = mlx_xpm_file_to_image(map()->mlx, EXIT, &spr->width, &spr->height);
}

void	draw_window(void)
{
	int		win_wdth;
	int		win_hght;

	win_wdth = (map()->line_len - 1) * 32;
	win_hght = (map()->lines_num) * 32;
	map()->mlx = mlx_init();
	map()->win = mlx_new_window(map()->mlx, win_wdth, win_hght, "SoLong");
	mlx_key_hook(map()->win, hook_handler, NULL);
	mlx_hook(map()->win, 17, 0, exit_game, NULL);
	init_sprites(&map()->spr);
	draw_map();
	mlx_loop(map()->mlx);
}


void	draw_map(void)
{
	size_t	i;
	int		j;
	char	**matrix;

	i = 0;
	j = 0;
	matrix  = map()->matrix;
	while (j < map()->lines_num)
	{
		while (i < map()->line_len)
		{
			if (matrix[j][i] == '1')
				mlx_put_image_to_window(map()->mlx, map()->win, map()->spr.rock, i * 32, j * 32);
			else
				mlx_put_image_to_window(map()->mlx, map()->win, map()->spr.water, i * 32, j * 32);
			if (matrix[j][i] == 'P')
			{
				mlx_put_image_to_window(map()->mlx, map()->win, map()->spr.player_right, i * 32, j * 32);
				player()->x = i;
				player()->y = j;
			}
			if (matrix[j][i] == 'C')
				mlx_put_image_to_window(map()->mlx, map()->win, map()->spr.fish, i * 32, j * 32);
			if (matrix[j][i] == 'E')
			{
				portal()->x = i;
				portal()->y = j;
			}
			i++;
		}
		i = 0;
		j++;
	}
}
