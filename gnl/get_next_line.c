/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkayleen <pkayleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 19:39:05 by pkayleen          #+#    #+#             */
/*   Updated: 2021/03/12 22:16:02 by pkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strfree(char **str)
{
	while (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}

char	*check_total(char **line, char **total)
{
	char	*ptr;

	ptr = NULL;
	if (*total)
	{
		ptr = ft_strchr(*total, '\n');
		if (ptr)
		{
			*ptr = '\0';
			*line = ft_strdup(*total);
			*total = ft_strcpy(*total, ++ptr);
		}
		else
		{
			*line = ft_strdup(*total);
			ft_strfree(total);
		}
	}
	else
		*line = ft_strdup("");
	return (ptr);
}

int	make_line(char **line, char *buf)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strjoin(*line, buf);
	if (!(*line))
		return (-1);
	free(tmp);
	return (1);
}

int	check_n(char **line, char **total, char **ptr, char *buf)
{
	char	*tmp;

	*ptr = ft_strchr(buf, '\n');
	if (*ptr)
	{
		**ptr = '\0';
		tmp = *total;
		*total = ft_strdup(++(*ptr));
		if (!(*total))
			return (-1);
		free(tmp);
	}
	if ((make_line(line, buf)) == -1)
		return (-1);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*total;
	char		*buf;
	char		*ptr;
	int			buf_read;

	buf = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || !line || (read(fd, "", 0) == -1))
		return (-1);
	ptr = check_total(line, &total);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(buf))
		exit(1);
	while (!ptr)
	{
		buf_read = read(fd, buf, BUFFER_SIZE);
		if (buf_read <= 0)
			break ;
		buf[buf_read] = '\0';
		if (check_n(line, &total, &ptr, buf) == -1)
			exit(1);
	}
	free(buf);
	return (total || buf_read > 0);
}
