/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosartor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:11:21 by sosartor          #+#    #+#             */
/*   Updated: 2019/09/11 21:40:28 by sosartor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	length;
	char	*res;

	length = ft_strlen(str);
	res = (char *)malloc(sizeof(char) * (length + 1));
	if (res == 0)
		return (res);
	res = ft_strcpy(res, str);
	return (res);
}
