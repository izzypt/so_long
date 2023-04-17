/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:28:01 by smagalha          #+#    #+#             */
/*   Updated: 2023/04/17 14:40:21 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "mlx_linux/mlx.h"
# include "printf/ft_printf.h"

# define TOP_LFT_CRNR_PTH "./sprites/beach_walls/left_corner.xpm"
# define TOP_RGT_CRNR_PTH "./sprites/beach_walls/right_corner.xpm"
# define TOP_MID_PTH "./sprites/beach_walls/top_mid.xpm"
# define LFT_MID_WALL_PTH "./sprites/beach_walls/left_mid.xpm"
# define RGHT_MID_WALL_PTH "./sprites/walls/right_mid.xpm"
# define BOT_MID_WALL_PTH "./sprites/walls/bottom_mid.xpm"
# define BOT_RGT_CRNR_PTH "./sprites/walls/bottom_right_corner.xpm"
# define BOT_LFT_CRNR_PTH "./sprites/walls/bottom_left_corner.xpm"

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

int		validate_map(char **map, t_map_data *map_info);
int		validate_line_len(char *line, size_t valid_len);
int		validate_edges(char *top_line, char *bottom_line);
int		validate_sides(char *line, int last_char_pos);
int		count_map_components(char element, t_map_data *map_info);
void	draw_window(char **map_matrix, t_map_data *map_info);
void	draw_player(void *mlx, void *window);
void	draw_walls(char **map_matrix, void *mlx, void *window);

#endif  