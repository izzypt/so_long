#include "../so_long.h"

void	draw_water(int i, int j)
{
	mlx_put_image_to_window(\
	map()->mlx, map()->win, map()->spr.water, i * 32, j * 32);
}

void	draw_rock(int i, int j)
{
	mlx_put_image_to_window(\
	map()->mlx, map()->win, map()->spr.rock, i * 32, j * 32);
}

void	draw_fish(int i, int j)
{
	mlx_put_image_to_window(\
	map()->mlx, map()->win, map()->spr.fish, i * 32, j * 32);
}
