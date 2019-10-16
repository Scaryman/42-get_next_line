/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosartor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:28:35 by sosartor          #+#    #+#             */
/*   Updated: 2019/09/15 20:43:58 by sosartor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*res;
	size_t	begin;
	size_t	end;
	size_t	i;

	if (s == NULL)
		return (NULL);
	begin = 0;
	while (s[begin] == ' ' || s[begin] == '\n' || s[begin] == '\t')
		begin++;
	if (s[begin] == '\0')
		return (ft_strnew(0));
	end = ft_strlen(s) - 1;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	res = (char*)malloc(sizeof(char) * (end - begin + 2));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (begin <= end)
		res[i++] = s[begin++];
	res[i] = '\0';
	return (res);
}
