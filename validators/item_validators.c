/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_validators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:23:18 by smagalha          #+#    #+#             */
/*   Updated: 2023/04/18 21:53:51 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_map_components(char element)
{
	if (element == 'C')
		map()->collectable_num++;
	if (element == 'P')
		map()->players_num++;
	if (element == 'E')
		map()->exit_num++;
	return (1);
}

void	validate_collectable_nums(void)
{
	char	*err;

	printf("map data:");
	printf("exit_num:%d\n", map()->exit_num);
	printf("collectable_num:%d\n", map()->collectable_num);
	printf("players_num:%d\n", map()->players_num);
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
	if (player()->num_collections == map()->collectable_num)
	{
		mlx_put_image_to_window(map()->mlx, map()->win, \
		map()->spr.exit, portal()->x * 32, portal()->y * 32);
	}
	if (player()->num_collections < map()->collectable_num)
		player()->num_collections++;
}

void	handle_portal(void)
{
	if (player()->num_collections == map()->collectable_num)
		exit_game();
}
