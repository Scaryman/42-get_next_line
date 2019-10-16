/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosartor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:48:02 by sosartor          #+#    #+#             */
/*   Updated: 2019/09/19 20:11:22 by sosartor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*d;
	const char	*s;

	d = (char*)dest;
	s = (const char*)src;
	while (n-- > 0)
	{
		*d = *s;
		if (*s == (const char)c)
			return (++d);
		d++;
		s++;
	}
	return (NULL);
}
