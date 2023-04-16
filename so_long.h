/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:28:01 by smagalha          #+#    #+#             */
/*   Updated: 2023/04/16 19:25:50 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "get_next_line/get_next_line.h"
#include "mlx_linux/mlx.h"
#include "printf/ft_printf.h"

typedef struct t_map_data
{
	int		lines_num;
	size_t	line_len;
	int		collectables_num;
	int		walls_num;
	int		players_num;
	int		floor_num;
	int		exit_num;
}	t_map_data;

int		validate_line_len(char *line, size_t valid_len);
int		validate_edges(char *top_line, char *bottom_line);
int		validate_sides(char *line, int last_char_pos);
int		count_map_components(char element, t_map_data *map_info);
void	draw_window(void);
void	draw_player(void *mlx, void *window);

#endif  