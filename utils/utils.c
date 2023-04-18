/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:08:53 by simao             #+#    #+#             */
/*   Updated: 2023/04/18 16:02:13 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_map_data	*map(void)
{
	static t_map_data	map;

	return (&map);
}

t_player	*player(void)
{
	static t_player	player;

	return (&player);
}

int	exit_game(void)
{
	/*char	**matrix;
	int		i;


	i = 0;
	matrix = map()->matrix;
	mlx_destroy_window(map()->mlx, map()->win);
	mlx_destroy_display(map()->mlx);
	while (i < map()->lines_num)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);*/
	exit(0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	x;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (i < len && big[i] != '\0')
	{
		x = 0;
		while (little[x] == big[i + x] && (i + x) < len)
		{
			if (little[x + 1] == '\0')
				return ((char *)&big[i]);
			x++;
		}
		i++;
	}
	return (0);
}

