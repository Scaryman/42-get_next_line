/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosartor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:42:45 by sosartor          #+#    #+#             */
/*   Updated: 2019/09/19 20:25:59 by sosartor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	ch;
	size_t			i;

	s = (unsigned char*)str;
	ch = (unsigned char)c;
	i = -1;
	while (++i < n)
		if (s[i] == ch)
			return ((void *)&str[i]);
	return (NULL);
}
