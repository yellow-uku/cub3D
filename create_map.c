//
// Created by Profit Kayleen on 4/28/21.
//

#include "cub3d.h"

void select_direction(double *angle, char direct)
{
	if (direct == 'N')
		*angle = M_PI / 2;
	else if (direct == 'S')
		*angle = 3 * M_PI / 2;
	else if (direct == 'W')
		*angle = M_PI;
	else if (direct == 'E')
		*angle = 0;
}

void check_player(t_player *player, char *line, int y)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W')
		{
			player->origin_x = i * SCALE + SCALE / 2;
			player->origin_y = y * SCALE + SCALE / 2;
			select_direction(&player->angle, line[i]);
			return ;
		}
		i++;
	}
}

void init_map(t_cub *cub, t_list *list)
{
	int i;

	i = 0;
	while (list)
	{
		check_player(&cub->player, list->content, i);
		cub->map[i++] = list->content;
		list = list->next;
	}
	cub->map[i] = NULL;
}

