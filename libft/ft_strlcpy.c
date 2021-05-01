/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkayleen <pkayleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:22:08 by pkayleen          #+#    #+#             */
/*   Updated: 2020/11/09 15:49:46 by pkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	int	i;

	if (src == NULL)
		return (0);
	if (n == 0 || dst == NULL)
	{
		return (ft_strlen(src));
	}
	i = 0;
	while (n > 1 && src[i] != '\0')
	{
		n--;
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
