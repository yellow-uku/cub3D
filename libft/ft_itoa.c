/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkayleen <pkayleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 19:50:45 by pkayleen          #+#    #+#             */
/*   Updated: 2020/11/16 19:15:34 by pkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	count_num(long int num)
{
	long int	count;

	count = 0;
	if (num < 0)
	{
		num *= -1;
		count++;
	}
	while (num >= 10)
	{
		num = num / 10;
		count++;
	}
	count++;
	return (count);
}

static long int	power(long int num, long int p)
{
	long int	res;

	if (p == 0)
		res = 1;
	else
		res = num * power(num, p - 1);
	return (res);
}

static long int	if_neg(long int *num, char *s, long int *len)
{
	if (*num < 0)
	{
		*num *= -1;
		s[0] = '-';
		*len = *len - 1;
		return (1);
	}
	else
		return (0);
}

char			*ft_itoa(int n)
{
	char		*str;
	long int	len;
	long int	i;
	long int	d;
	long int	num;

	num = n;
	len = count_num(num);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	i = if_neg(&num, str, &len);
	while (len != 0)
	{
		d = num / (power(10, len - 1));
		str[i++] = d + '0';
		num = num - d * (power(10, len - 1));
		len--;
	}
	str[i] = '\0';
	return (str);
}
