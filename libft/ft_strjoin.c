/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosartor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:53:27 by sosartor          #+#    #+#             */
/*   Updated: 2019/09/19 21:01:19 by sosartor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*res;
	char const	*ts1;
	char const	*ts2;
	char		*tres;

	if (s1 != NULL && s2 != NULL)
	{
		res = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		ts1 = s1;
		ts2 = s2;
		if (res == NULL)
			return (NULL);
		tres = res;
		while (*ts1)
			*tres++ = (char)*ts1++;
		while (*ts2)
			*tres++ = (char)*ts2++;
		*tres = '\0';
		return (res);
	}
	return (NULL);
}
