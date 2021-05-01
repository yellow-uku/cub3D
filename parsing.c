//
// Created by Profit Kayleen on 4/28/21.
//
#include "cub3d.h"

void parse_map(t_cub *cub, char *argv)
{
	t_list	*list;
	int		fd;
	char	*line;

	list = NULL;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		ft_lstadd_back(&list, ft_lstnew(line));
	ft_lstadd_back(&list, ft_lstnew(line));
	cub->map = malloc((ft_lstsize(list) + 1) * sizeof(char *));
	init_map(cub, list);
}
