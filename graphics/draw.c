/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:03:15 by smagalha          #+#    #+#             */
/*   Updated: 2023/04/17 01:47:44 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_window(char **map_matrix, t_map_data *map_info)
{
	void	*mlx;
	void	*window;
	int		win_width;
	int		win_height;

	win_width = (map_info->line_len - 1) * 32;
	win_height = (map_info->lines_num) * 32;
	mlx = mlx_init();
	window = mlx_new_window(mlx, win_width, win_height, "SoLong!");
	draw_player(mlx, window);
	draw_walls(map_matrix, mlx, window);
	mlx_loop(mlx);
}

void	draw_walls(char **map_matrix, void *mlx, void *window)
{
	int		i;
	void	*left_corner;
	void	*right_corner;
	void	*top_mid;
	void	*lft_mid_wall;
	void	*bot_rgt_corner;
	void	*bot_mid;
	int		wdth;
	int		hght;

	i = 0;
	wdth = 32;
	hght = 32;
	left_corner = mlx_xpm_file_to_image(mlx, TOP_LFT_CRNR_PTH, &wdth, &hght);
	right_corner = mlx_xpm_file_to_image(mlx, TOP_RGT_CRNR_PTH, &wdth, &hght);
	top_mid = mlx_xpm_file_to_image(mlx, TOP_MID_PTH, &wdth, &hght);
	lft_mid_wall = mlx_xpm_file_to_image(mlx, LFT_MID_WALL_PTH, &wdth, &hght);
	bot_rgt_corner = mlx_xpm_file_to_image(mlx, BOT_RGT_CRNR_PTH, &wdth, &hght);
	bot_mid = mlx_xpm_file_to_image(mlx, BOT_MID_WALL_PTH, &wdth, &hght);
	while (map_matrix[0][i] != '\n')
	{
		if (i == 0)
			mlx_put_image_to_window(mlx, window, left_corner, 0, 0);
		else if (map_matrix[0][i + 1] == '\n')
			mlx_put_image_to_window(mlx, window, right_corner, 32 * i, 0);
		else
			mlx_put_image_to_window(mlx, window, top_mid, 32 * i, 0);
		i++;
	}
	i = 0;
	while (map_matrix[i][0] < 5)
	{
		if (i != 0)
			mlx_put_image_to_window(mlx, window, lft_mid_wall, 0, 32 * i);
		i++;
	}
}

void	draw_player(void *mlx, void *window)
{
	void	*img;
	int		img_wdth;
	int		img_hght;
	char	*player_path;

	player_path = "./sprites/jump.xpm";
	img_wdth = 32;
	img_hght = 32;
	img = mlx_xpm_file_to_image(mlx, player_path, &img_wdth, &img_hght);
	mlx_put_image_to_window(mlx, window, img, 250, 250);
}
