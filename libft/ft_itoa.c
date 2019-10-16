/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosartor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 22:09:21 by sosartor          #+#    #+#             */
/*   Updated: 2019/09/19 13:22:24 by sosartor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		len;
	char	*res;
	long	tmp;

	len = ft_ilen(n);
	tmp = (long)n;
	res = ft_strnew(len);
	if (res == NULL)
		return (NULL);
	if (tmp < 0)
	{
		res[0] = '-';
		tmp = -tmp;
	}
	else
		res[0] = '0';
	while (tmp != 0)
	{
		res[--len] = tmp % 10 + '0';
		tmp = tmp / 10;
	}
	return (res);
}
