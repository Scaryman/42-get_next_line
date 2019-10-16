/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosartor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:46:45 by sosartor          #+#    #+#             */
/*   Updated: 2019/09/19 20:47:34 by sosartor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t j;

	if (*s2 == '\0')
		return ((char*)s1);
	if (*s1 == '\0')
		return (0);
	i = 0;
	while (i < len && s1[i] != '\0')
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			while (j + i < len)
			{
				j++;
				if (s2[j] == '\0')
					return ((char*)&s1[i]);
				if (s1[i + j] != s2[j])
					break ;
			}
		}
		i++;
	}
	return (0);
}
