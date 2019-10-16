/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosartor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:50:04 by sosartor          #+#    #+#             */
/*   Updated: 2019/09/19 19:20:12 by sosartor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int n;
	unsigned int i;
	unsigned int dlen;
	unsigned int srclen;

	srclen = ft_strlen(src);
	dlen = 0;
	while (dst[dlen] != '\0' && dlen < dstsize)
		dlen++;
	n = 0;
	while (dst[n] != '\0')
		n++;
	if (n >= dstsize)
	{
		return (dlen + srclen);
	}
	i = 0;
	while (n < dstsize - 1 && src[i] != '\0')
	{
		dst[n++] = src[i++];
	}
	dst[n] = '\0';
	return (dlen + srclen);
}
