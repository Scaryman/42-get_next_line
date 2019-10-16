/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosartor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 18:34:16 by sosartor          #+#    #+#             */
/*   Updated: 2019/09/19 20:57:12 by sosartor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (s != NULL)
	{
		res = (char*)malloc(sizeof(char) * (len + 1));
		if (res == NULL)
			return (NULL);
		i = 0;
		while (i < len && s[start] != '\0')
			res[i++] = s[start++];
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}
