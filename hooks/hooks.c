/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 23:57:05 by simao             #+#    #+#             */
/*   Updated: 2023/04/19 13:35:46 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	hook_handler(int keycode)
{
	if (keycode == ESC)
		exit_game();
	if (keycode == A)
		move_left();
	if (keycode == S)
		move_down();
	if (keycode == W)
		move_up();
	if (keycode == D)
		move_right();
	return (0);
}

int	move_up(void)
{
	if (map()->matrix[player()->y - 1][player()->x] == 'C')
		collect_items();
	if (map()->matrix[player()->y - 1][player()->x] == 'E')
		handle_portal();
	if (map()->matrix[player()->y - 1][player()->x] == '1')
		return (0);
	else
	{
		player()->num_moves++;
		draw_moves_str();
		mlx_put_image_to_window(map()->mlx, map()->win, \
		map()->spr.water, player()->x * 32, player()->y * 32);
		player()->y -= 1;
		mlx_put_image_to_window(map()->mlx, map()->win, \
		map()->spr.player_up, player()->x * 32, player()->y * 32);
		return (1);
	}
}

int	move_down(void)
{
	if (map()->matrix[player()->y + 1][player()->x] == 'C')
		collect_items();
	if (map()->matrix[player()->y + 1][player()->x] == 'E')
		handle_portal();
	if (map()->matrix[player()->y + 1][player()->x] == '1')
		return (0);
	else
	{
		player()->num_moves++;
		draw_moves_str();
		mlx_put_image_to_window(map()->mlx, map()->win, \
		map()->spr.water, player()->x * 32, player()->y * 32);
		player()->y += 1;
		mlx_put_image_to_window(map()->mlx, map()->win, \
		map()->spr.player_down, player()->x * 32, player()->y * 32);
		return (1);
	}
}

int	move_right(void)
{
	if (map()->matrix[player()->y][player()->x + 1] == 'C')
		collect_items();
	if (map()->matrix[player()->y][player()->x + 1] == 'E')
		handle_portal();
	if (map()->matrix[player()->y][player()->x + 1] == '1')
		return (0);
	else
	{
		player()->num_moves++;
		draw_moves_str();
		mlx_put_image_to_window(map()->mlx, map()->win, map()->spr.water, \
		player()->x * 32, player()->y * 32);
		player()->x += 1;
		mlx_put_image_to_window(map()->mlx, map()->win, \
		map()->spr.player_right, player()->x * 32, player()->y * 32);
		return (1);
	}
}

int	move_left(void)
{
	if (map()->matrix[player()->y][player()->x - 1] == 'C')
		collect_items();
	if (map()->matrix[player()->y][player()->x - 1] == 'E')
		handle_portal();
	if (map()->matrix[player()->y][player()->x - 1] == '1')
		return (0);
	else
	{
		player()->num_moves++;
		draw_moves_str();
		mlx_put_image_to_window(map()->mlx, map()->win, map()->spr.water, \
		player()->x * 32, player()->y * 32);
		player()->x -= 1;
		mlx_put_image_to_window(map()->mlx, map()->win, map()->spr.player_left, \
		player()->x * 32, player()->y * 32);
		return (1);
	}
}
