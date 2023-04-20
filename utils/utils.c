/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:08:53 by simao             #+#    #+#             */
/*   Updated: 2023/04/20 20:15:51 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_portal	*portal(void)
{
	static t_portal	exit;

	return (&exit);
}

t_map_data	*map(void)
{
	static t_map_data	map;

	return (&map);
}

t_map_clone	*map_clone(void)
{
	static t_map_clone	clon;

	return (&clon);
}

t_player	*player(void)
{
	static t_player	player;

	return (&player);
}

int	exit_game(void)
{
	free_clone(map_clone()->clone);
	exit(0);
}
