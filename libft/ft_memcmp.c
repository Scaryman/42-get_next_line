/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosartor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:10:16 by sosartor          #+#    #+#             */
/*   Updated: 2019/09/11 20:44:09 by sosartor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *buf1, const void *buf2, size_t n)
{
	size_t		i;
	const char	*b1;
	const char	*b2;

	i = -1;
	b1 = (const char*)buf1;
	b2 = (const char*)buf2;
	while (++i < n)
		if (b1[i] != b2[i])
			return ((unsigned char)b1[i] - (unsigned char)b2[i]);
	return (0);
}
