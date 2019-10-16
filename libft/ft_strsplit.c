/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosartor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:54:57 by sosartor          #+#    #+#             */
/*   Updated: 2019/09/19 21:02:19 by sosartor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	words;
	size_t	i;
	size_t	n;
	size_t	begin;

	if (s == NULL)
		return (NULL);
	words = ft_countwords((char*)s, c);
	res = (char**)malloc(sizeof(char*) * (words + 1));
	if (res == NULL)
		return (NULL);
	i = -1;
	n = 0;
	while (++i < words)
	{
		while (s[n] == c)
			n++;
		begin = n;
		while (s[n] != c && s[n] != '\0')
			n++;
		res[i] = ft_strsub((const char*)s, begin, n - begin);
	}
	res[i] = 0;
	return (res);
}
