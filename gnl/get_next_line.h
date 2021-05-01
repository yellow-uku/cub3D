/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkayleen <pkayleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:53:11 by pkayleen          #+#    #+#             */
/*   Updated: 2021/03/13 00:01:00 by pkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int			get_next_line(int fd, char **line);
char		*ft_strcpy(char *dst, const char *src);
void		ft_strfree(char **str);

# define BUFFER_SIZE 32

#endif
