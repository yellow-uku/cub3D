//
// Created by Profit Kayleen on 4/28/21.
//

#include "cub3d.h"

void define_height(t_cub *cub, double dist_w, double x, double y, double angle)
{
	int	start;
	int	end;

	start = cub->height / 2  - cub->height / (dist_w * cos(angle)) / 2 * SCALE;
	end = cub->height / 2 + cub->height / (dist_w * cos(angle)) / 2 * SCALE;
	while (start < end)
	{
		my_mlx_pixel_put(&cub->core_img, (int) x, (int) start, 0x00ffff);
		start++;
	}
}


void	raycast(t_cub *cub)
{
	double	k;
	double	x;
	double	y;
	double	step_angle;
	double	curr_angle;
	int x_vert;

//	mlx_put_image_to_window(cub->mlx, cub->win, cub->core_img.img, 0, 0);
	x_vert = 0;
	step_angle = FOV / cub->width; //angle - player_a
	curr_angle = cub->player.angle - FOV / 2; // angle
	while (curr_angle < (cub->player.angle + FOV/2))
	{
		k = 0.25;
		// put pixels for one ray
		while (x < cub->width && y < cub->height)
		{
			x = cub->player.origin_x + k * cos(curr_angle);
			y = cub->player.origin_y + k * sin(curr_angle);
			my_mlx_pixel_put(&cub->core_img, (int) x, (int) y, 0xFFFF00);
			if (cub->map[(int) y / SCALE][(int) x / SCALE] == '1')
				break;
			k += 0.01;
		}
		define_height(cub, k, x_vert++, y, curr_angle - cub->player.angle);
		curr_angle += step_angle;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->core_img.img, 0, 0);

}


