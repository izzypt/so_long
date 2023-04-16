/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:03:15 by smagalha          #+#    #+#             */
/*   Updated: 2023/04/16 20:21:58 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_window(void)
{
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 500, 500, "SoLong!");
	draw_player(mlx, window);
	mlx_loop(mlx);
}

void draw_wall()
{

}

void	draw_player(void *mlx, void *window)
{
	void	*img;
	void	*wall_img;
	int		img_wdth;
	int		img_hght;
	char	*img_path;
	char	*wall_path;

	img_path = "./sprites/jump.xpm";
	wall_path = "./sprites/walls/top_left_corner.xpm";
	img = mlx_xpm_file_to_image(mlx, img_path, &img_wdth, &img_hght);
	wall_img = mlx_xpm_file_to_image(mlx, wall_path, &img_wdth, &img_hght);
	mlx_put_image_to_window(mlx, window, img, 250, 250);
	mlx_put_image_to_window(mlx, window, wall_img, 0, 0);
}