/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosartor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 22:12:56 by sosartor          #+#    #+#             */
/*   Updated: 2019/09/18 22:13:01 by sosartor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(void const *content, size_t content_size)
{
	void	*res;

	res = ft_memalloc(content_size);
	if (res == NULL)
		return (NULL);
	return (ft_memcpy(res, content, content_size));
}
