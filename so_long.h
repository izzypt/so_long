/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:28:01 by smagalha          #+#    #+#             */
/*   Updated: 2023/04/18 16:53:34 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libs/get_next_line/get_next_line.h"
# include "libs/mlx_linux/mlx.h"
# include "libs/printf/ft_printf.h"

# define ROCK "./sprites/beach_walls/rock.xpm"
# define WATER "./sprites/beach_walls/water.xpm"
# define FISH "./sprites/collectibles/fish.xpm"
# define PLAYER_UP "./sprites/boat/boat_up.xpm"
# define PLAYER_DOWN "./sprites/boat/boat_down.xpm"
# define PLAYER_LEFT "./sprites/boat/boat_left.xpm"
# define PLAYER_RIGHT "./sprites/boat/boat_right.xpm"
# define EXIT "./sprites/exits/portal.xpm"
# define ESC 65307
# define A 97
# define D 100
# define S 115
# define W 119

typedef struct t_sprites
{
	void	*rock;
	void	*water;
	void	*player_up;
	void	*player_right;
	void	*player_left;
	void	*player_down;
	void	*fish;
	void	*exit;
	int		width;
	int		height;
}	t_sprites;

typedef struct t_map_data
{
	char		**matrix;
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

typedef struct t_player
{
	int	x;
	int	y;
	int	num_moves;
	int	num_collections;

}	t_player;


t_player	*player(void);
t_map_data	*map(void);
int			validate_map(char **matrix);
int			validate_line_len(char *line, size_t valid_len);
int			validate_edges(char *top_line, char *bottom_line);
int			validate_sides(char *line);
int			count_map_components(char element);
void		draw_window(void);
void		draw_walls(void);
void		init_sprites(t_sprites *spr);
char		*ft_strnstr(const char *big, const char *little, size_t len);
int			hook_handler(int keycode);
int			move_up(void);
int			move_down(void);
int			move_left(void);
int			move_right(void);
int			exit_game(void);

#endif  