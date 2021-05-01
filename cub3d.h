//
// Created by Profit Kayleen on 4/27/21.
//

#ifndef CUB_3D_CUB3D_H
#define CUB_3D_CUB3D_H
#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include "mlx.h"
#include <stdio.h>
#include <math.h>

#define SCALE 10
#define FOV M_PI/3

enum	keywords {
	ESC = 53,
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	ROTATE_LEFT = 123,
	ROTATE_RIGHT = 124,
	texWidth = 64,
	texHeight = 64,
};

typedef struct s_image
{
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}  t_image;

typedef struct s_player
{
	double	player_x;
	double	player_y;
	double	origin_x;
	double	origin_y;
	double	angle;
	double	ray_x;
	double	ray_y;
}	t_player;

typedef struct s_cub
{
    void    *mlx;
    void    *win;
    double    width;
    double     height;
    char	**map;
    t_image core_img;
    t_player player;
}   t_cub;

void	parse_map(t_cub *cub, char *argv);
void	init_map(t_cub *cub, t_list *list);
void	check_player(t_player *player, char *line, int y);
void	select_direction(double *angle, char direct);
void	print_map(t_cub *cub);
void	change_pixel(t_image *img, int x, int y, int color);
void	my_mlx_pixel_put(t_image *data, int x, int y, int color);
void	raycast(t_cub *cub);
void	define_height(t_cub *cub, double dist_w, double x, double y, double angle);

#endif //CUB_3D_CUB3D_H
