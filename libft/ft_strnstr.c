/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkayleen <pkayleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:57:10 by pkayleen          #+#    #+#             */
/*   Updated: 2020/11/21 19:23:08 by pkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *sb, size_t len)
{
	size_t	i;
	size_t	j;
	char	*hay;

	hay = (char *)haystack;
	if (ft_strlen(sb) == 0)
		return (hay);
	i = 0;
	while (hay[i] && i < len)
	{
		j = 0;
		if (hay[i] == sb[j])
		{
			while ((i + j) < len && j < ft_strlen(sb) && (hay[i + j] == sb[j]))
				j++;
			if (j == ft_strlen(sb))
				return (hay + i);
		}
		i++;
	}
	return (NULL);
}
