/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosartor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 22:16:00 by sosartor          #+#    #+#             */
/*   Updated: 2019/09/18 22:16:06 by sosartor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *res;

	res = (t_list*)malloc(sizeof(t_list));
	if (res == NULL)
		return (NULL);
	if (content == NULL)
	{
		res->content = NULL;
		res->content_size = 0;
	}
	else
	{
		res->content = ft_memdup(content, content_size);
		if (res->content == NULL)
			return (NULL);
		res->content_size = content_size;
	}
	res->next = NULL;
	return (res);
}
