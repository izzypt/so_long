/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:28:01 by smagalha          #+#    #+#             */
/*   Updated: 2023/04/17 18:51:19 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "mlx_linux/mlx.h"
# include "printf/ft_printf.h"

# define ROCK "./sprites/beach_walls/rock.xpm"
# define WATER "./sprites/beach_walls/water.xpm"
# define PIXEL_WDTH 32
# define PIXEL_HEIGHT 32

typedef struct t_sprites
{
	void	*rock;
	void	*water;
	int		width;
	int		height;
}	t_sprites;

typedef struct t_map_data
{
	int			lines_num;
	size_t		line_len;
	int			collectables_num;
	int			walls_num;
	int			players_num;
	int			floor_num;
	int			exit_num;
	void		*mlx;
	void		*win;
	t_sprites	spr;
}	t_map_data;

int			validate_map(char **matrix);
int			validate_line_len(char *line, size_t valid_len);
int			validate_edges(char *top_line, char *bottom_line);
int			validate_sides(char *line, int last_char_pos);
int			count_map_components(char element);
void		draw_window(char **map_matrix);
void		draw_player(void *mlx, void *window);
void		draw_walls(char **map);
t_map_data	*map(void);

#endif  