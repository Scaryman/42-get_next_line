/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosartor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 22:52:06 by sosartor          #+#    #+#             */
/*   Updated: 2019/09/12 22:55:05 by sosartor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (*s1 && i < n)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
			break ;
		i++;
	}
	if (i == n)
		return (0);
	else
		return ((unsigned char)*s1 - (unsigned char)*s2);
}
