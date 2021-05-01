//
// Created by Profit Kayleen on 4/28/21.
//

#include "cub3d.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void change_pixel(t_image *img, int x, int y, int color)
{
	int	dx;
	int dy;

	dx = x;
	dy = y;
	while (dy < SCALE + y)
	{
		while (dx < SCALE + x)
		{
			my_mlx_pixel_put(img, dx, dy, color);
			dx++;
		}
		dy++;
		dx = x;
	}
}

void	print_map(t_cub *cub)
{
	int	x;
	int y;

	y = -1;
	x = -1;
	while(cub->map[++y])
	{
		x = -1;
		while(cub->map[y][++x])
		{
			// wall
			if (cub->map[y][x] == '1')
				change_pixel(&cub->core_img, x * SCALE, y * SCALE, 0xFF0000);
			// sprite
			if (cub->map[y][x] == '2')
				change_pixel(&cub->core_img, x * SCALE, y * SCALE, 0x00FF00);
			// player
			if (cub->map[y][x] == 'N' || cub->map[y][x] == 'S'
				|| cub->map[y][x] == 'E' || cub->map[y][x] == 'W')
				change_pixel(&cub->core_img, x * SCALE, y * SCALE, 0x0000FF);
		}
	}
}