/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosartor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 18:24:53 by sosartor          #+#    #+#             */
/*   Updated: 2019/10/14 22:24:16 by sosartor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fdlist	*get_fd_struct(const int fd, t_fdlist **fd_list)
{
	t_fdlist	*tmp;
	t_fdlist	*prev;
	t_fdlist	*new;

	tmp = *fd_list;
	prev = NULL;
	while (tmp && tmp->fd <= fd)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (prev && prev->fd == fd)
		return (prev);
	if ((new = (t_fdlist*)malloc(sizeof(t_fdlist))) == NULL)
		return (NULL);
	new->fd = fd;
	if ((new->buf = ft_strnew(BUFF_SIZE + 1)) == NULL)
	{
		free(new);
		return (NULL);
	}
	new->next = tmp;
	if (prev)
		prev->next = new;
	else
		*fd_list = new;
	return (new);
}

void		delfd(t_fdlist **fd_list, int fd)
{
	t_fdlist	*tmp;
	t_fdlist	*prev;

	tmp = *fd_list;
	prev = NULL;
	while (tmp->fd < fd)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	free(tmp->buf);
	if (prev)
		prev->next = tmp->next;
	else
		*fd_list = NULL;
	free(tmp);
}

int			get_next_line(const int fd, char **line)
{
	static t_fdlist	*fd_list;
	t_fdlist		*fd_struct;
	long			res;
	char			*tmp;
	char			*tmp2;

	if (fd < 0 || BUFF_SIZE < 0 || read(fd, NULL, 0) < 0)
		return (-1);
	if ((fd_struct = get_fd_struct(fd, &fd_list)) == NULL)
		return (-1);
	*line = ft_strnew(0);
	if (!*(fd_struct->buf))
		res = read(fd_struct->fd, fd_struct->buf, BUFF_SIZE);
	while (*(fd_struct->buf))
	{
		if ((tmp = ft_strchr(fd_struct->buf, '\n')))
		{
			*tmp = '\0';
			tmp2 = *line;
			*line = ft_strjoin(*line, fd_struct->buf);
			free(tmp2);
			ft_strcpy(fd_struct->buf, ++tmp);
			return (1);
		}
		tmp2 = *line;
		*line = ft_strjoin(*line, fd_struct->buf);
		free(tmp2);
		ft_strclr(fd_struct->buf);
		if ((res = read(fd_struct->fd, fd_struct->buf, BUFF_SIZE)) < 0)
			return (-1);
	}
	delfd(&fd_list, fd);
	return (*line[0] != '\0');
}

