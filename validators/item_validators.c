/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_validators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:23:18 by smagalha          #+#    #+#             */
/*   Updated: 2023/04/19 22:53:25 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	register_map_components(char element, int x, int y)
{
	if (element == 'C')
		map()->collectable_num++;
	if (element == 'P')
	{
		map()->players_num++;
		player()->x = x;
		player()->y = y;
	}
	if (element == 'E')
		map()->exit_num++;
	return (1);
}

void	validate_collectable_nums(void)
{
	char	*err;

	err = "Map must have one exit, one player and , at least, 1 collectable.";
	if (map()->exit_num != 1 || map()->collectable_num < 1 \
	|| map()->players_num != 1)
	{
		perror(err);
		exit(0);
	}
}

void	collect_items(void)
{
	if (player()->num_collections < map()->collectable_num)
		player()->num_collections++;
	if (player()->num_collections == map()->collectable_num)
	{
		mlx_put_image_to_window(map()->mlx, map()->win, \
		map()->spr.exit, portal()->x * 32, portal()->y * 32);
	}
}

void	handle_portal(void)
{
	if (player()->num_collections == map()->collectable_num)
		exit_game();
}
