/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:03:15 by smagalha          #+#    #+#             */
/*   Updated: 2023/04/19 17:17:28 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_sprites(t_sprites *spr)
{
	spr->rock = mlx_xpm_file_to_image(\
	map()->mlx, ROCK, &spr->width, &spr->height);
	spr->water = mlx_xpm_file_to_image(\
	map()->mlx, WATER, &spr->width, &spr->height);
	spr->fish = mlx_xpm_file_to_image(\
	map()->mlx, FISH, &spr->width, &spr->height);
	spr->player_right = mlx_xpm_file_to_image(\
	map()->mlx, PLAYER_RIGHT, &spr->width, &spr->height);
	spr->player_up = mlx_xpm_file_to_image(\
	map()->mlx, PLAYER_UP, &spr->width, &spr->height);
	spr->player_down = mlx_xpm_file_to_image(\
	map()->mlx, PLAYER_DOWN, &spr->width, &spr->height);
	spr->player_left = mlx_xpm_file_to_image(\
	map()->mlx, PLAYER_LEFT, &spr->width, &spr->height);
	spr->exit = mlx_xpm_file_to_image(\
	map()->mlx, EXIT, &spr->width, &spr->height);
}

void	draw_window(void)
{
	int		win_wth;
	int		win_hgt;
	void	*addr;

	win_wth = ((map()->line_len) - 1) * 32;
	win_hgt = ((map()->lines_num)) * 32;
	map()->mlx = mlx_init();
	addr = mlx_new_window(map()->mlx, win_wth, win_hgt, "SoLong");
	map()->win = addr;
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

	i = -1;
	j = -1;
	matrix = map()->matrix;
	while (++j < map()->lines_num)
	{
		while (++i < map()->line_len)
		{
			if (matrix[j][i] == '1')
				draw_rock(i, j);
			else
				draw_water(i, j);
			if (matrix[j][i] == 'P')
				draw_player(i, j);
			if (matrix[j][i] == 'C')
				draw_fish(i, j);
			if (matrix[j][i] == 'E')
				set_portal_cord(i, j);
		}
		i = -1;
	}
}

void	draw_player(int i, int j)
{
	mlx_put_image_to_window(\
	map()->mlx, map()->win, map()->spr.player_right, i * 32, j * 32);
	player()->x = i;
	player()->y = j;
}

void	draw_moves_str(void)
{
	char	*moves;

	moves = ft_itoa(player()->num_moves);
	mlx_put_image_to_window(map()->mlx, map()->win, map()->spr.water, 32, 32);
	mlx_string_put(map()->mlx, map()->win, 48, 48, 0x000000, moves);
	free(moves);
}
