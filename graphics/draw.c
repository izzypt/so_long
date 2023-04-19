/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:03:15 by smagalha          #+#    #+#             */
/*   Updated: 2023/04/19 13:41:47 by simao            ###   ########.fr       */
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
	int		win_wth;
	int		win_hgt;

	win_wth = (map()->line_len - 1) * 32;
	win_hgt = (map()->lines_num) * 32;
	map()->mlx = mlx_init();
	map()->win = mlx_new_window(map()->mlx, win_wth, win_hgt, "SoLong");
	mlx_key_hook(map()->win, hook_handler, NULL);
	mlx_hook(map()->win, 17, 0, exit_game, NULL);
	init_sprites(&map()->spr);
	draw_map();
	mlx_string_put(map()->mlx, map()->win, 48, 48, 0x000000, "0");
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

void draw_moves_str(void)
{
    char *moves;

    moves = ft_itoa(player()->num_moves);
    mlx_put_image_to_window(map()->mlx, map()->win, map()->spr.water, 32, 32);
    mlx_string_put(map()->mlx, map()->win, 48, 48, 0x000000, moves);
    free(moves);
}