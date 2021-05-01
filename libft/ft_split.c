/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkayleen <pkayleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:32:17 by pkayleen          #+#    #+#             */
/*   Updated: 2020/11/26 17:59:16 by pkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*read_word(const char *s, int *j, char delimiter)
{
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != delimiter)
		i++;
	*j += i;
	return (ft_substr(s, 0, i));
}

static int			count_words(char const *s, char delimiter)
{
	int		i;
	int		len;
	int		count;

	len = 0;
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != delimiter)
		{
			len++;
			if (len == 1)
				count++;
		}
		else
			len = 0;
		i++;
	}
	return (count);
}

static char			**free_leaks(char **str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char				**ft_split(char const *s, char c)
{
	char	**str_split;
	int		i;
	int		j;
	int		w_cntr;
	int		len;

	if (!s)
		return (NULL);
	len = count_words(s, c);
	if (!(str_split = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	i = 0;
	j = 0;
	w_cntr = 0;
	while (w_cntr < len)
	{
		while (s[i] == c)
			i++;
		if (!(str_split[w_cntr++] = read_word(&(s[i]), &j, c)))
			return (free_leaks(str_split));
		i += j;
		j = 0;
	}
	str_split[w_cntr] = NULL;
	return (str_split);
}
