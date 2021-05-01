/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkayleen <pkayleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 21:58:29 by pkayleen          #+#    #+#             */
/*   Updated: 2020/11/23 15:41:30 by pkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*subs;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	subs = (char *)malloc(len + 1);
	if (!s || !subs)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		subs[i] = '\0';
		return (subs);
	}
	while (i != start)
		i++;
	j = 0;
	while (j != len && s[i] != '\0')
	{
		subs[j] = s[i];
		i++;
		j++;
	}
	subs[j] = '\0';
	return (subs);
}
