/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosartor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 22:43:55 by sosartor          #+#    #+#             */
/*   Updated: 2019/09/12 22:47:44 by sosartor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *s1, const char *s2)
{
	char *pos;
	char *tmp;

	if (*s2 == '\0')
		return ((char*)s1);
	while (*s1)
	{
		if (*s1 != *s2)
		{
			s1++;
			continue;
		}
		pos = (char*)s1;
		tmp = (char*)s2;
		while (*tmp)
		{
			if (*s1++ != *tmp++)
				break ;
			if (*tmp == '\0')
				return (pos);
		}
		s1 = pos;
		s1++;
	}
	return (0);
}
