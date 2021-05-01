#include "cub3d.h"

void	init_mlx(t_cub *cub)
{
	cub->mlx = mlx_init();
	cub->win = mlx_new_window(cub->mlx, cub->width, cub->height, "cub3D");
	cub->core_img.img = mlx_new_image(cub->mlx, cub->width, cub->height);
	cub->core_img.addr = mlx_get_data_addr(cub->core_img.img,
		&cub->core_img.bits_per_pixel, &cub->core_img.line_length, &cub->core_img.endian);
}

void	ft_forward(t_cub *cub)
{
	cub->player.origin_x = cub->player.origin_x - cos(cub->player.angle);
	cub->player.origin_y = cub->player.origin_y + sin(cub->player.angle);
}

void ft_back(t_cub *cub)
{
	cub->player.origin_x = cub->player.origin_x + cos(cub->player.angle);
	cub->player.origin_y = cub->player.origin_y - sin(cub->player.angle);
}

void ft_left(t_cub *cub)
{
	cub->player.origin_x = cub->player.origin_x + sin(cub->player.angle);
	cub->player.origin_y = cub->player.origin_y - cos(cub->player.angle);
}

void ft_right(t_cub *cub)
{
	cub->player.origin_x = cub->player.origin_x - sin(cub->player.angle);
	cub->player.origin_y = cub->player.origin_y + cos(cub->player.angle);
}

int	motions(int keycode, t_cub *cub)
{
	if (keycode == ESC)
		mlx_destroy_window(cub->mlx, cub->win);
	else if (keycode == W)
		ft_forward(cub);
	else if (keycode == S)
		ft_back(cub);
	else if (keycode == A)
		ft_left(cub);
	else if (keycode == D)
		ft_right(cub);
}

void background(t_cub *cub)
{
	int	x;
	int y;

	y = 0;
	while (y < cub->height)
	{
		x = 0;
		while (x < cub->width)
			my_mlx_pixel_put(&cub->core_img, x++, y, 0xFFFFFF);
		y++;
	}
}

int	draw_screen(t_cub *cub)
{
	background(cub);
	raycast(cub);
}


int	main(int argc, char **argv)
{
	t_cub	cub;

	cub.height = 720;
	cub.width = 1280;

	init_mlx(&cub);
	parse_map(&cub, argv[1]);
	print_map(&cub);
//	raycast(&cub);
	mlx_loop_hook(cub.mlx, draw_screen, &cub);
	mlx_hook(cub.win, 2, 1L<<0, motions, &cub);
	mlx_put_image_to_window(cub.mlx, cub.win, cub.core_img.img, 0, 0);
	mlx_loop(cub.mlx);
}
