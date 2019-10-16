/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosartor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 18:24:53 by sosartor          #+#    #+#             */
/*   Updated: 2019/10/15 22:10:23 by sosartor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fdlist	*new_fd_item(int fd, t_fdlist *next)
{
	t_fdlist	*new;

	if ((new = (t_fdlist*)malloc(sizeof(t_fdlist))) == NULL)
		return (NULL);
	new->fd = fd;
	if ((new->buf = ft_strnew(BUFF_SIZE + 1)) == NULL
		|| read(fd, new->buf, BUFF_SIZE) < 0)
	{
		ft_memdel((void**)&new);
		return (NULL);
	}
	new->next = next;
	return (new);
}

t_fdlist	*get_fd_item(const int fd, t_fdlist **fd_list)
{
	t_fdlist	*t;
	t_fdlist	*prev;
	t_fdlist	*new;

	t = *fd_list;
	prev = NULL;
	while (t && t->fd <= fd)
	{
		if (t->fd == fd)
		{
			if (!(*t->buf)
			&& read(t->fd, ft_memset(t->buf, '\0', BUFF_SIZE), BUFF_SIZE) < 0)
				return (NULL);
			return (t);
		}
		prev = t;
		t = t->next;
	}
	if ((new = new_fd_item(fd, t)) == NULL)
		return (NULL);
	if (prev)
		prev->next = new;
	else
		*fd_list = new;
	return (new);
}

int			del_fd(t_fdlist **fd_list, int fd)
{
	t_fdlist	*tmp;
	t_fdlist	*prev;

	tmp = *fd_list;
	prev = NULL;
	while (tmp && tmp->fd < fd)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp && tmp->fd == fd)
	{
		ft_memdel((void**)&(tmp->buf));
		if (prev)
			prev->next = tmp->next;
		else if (tmp->next)
			*fd_list = tmp->next;
		else
			*fd_list = NULL;
		ft_memdel((void**)&tmp);
	}
	return (-1);
}

char		*line_join(char *line, char *buf)
{
	char *tmp;

	tmp = line;
	if ((line = ft_strjoin(line, buf)) == NULL)
		return (NULL);
	ft_memdel((void**)&tmp);
	return (line);
}

int			get_next_line(const int fd, char **line)
{
	static t_fdlist	*fd_list;
	t_fdlist		*fd_item;
	char			*tmp;

	if (fd < 0 || BUFF_SIZE < 0 || read(fd, NULL, 0) < 0
		|| (fd_item = get_fd_item(fd, &fd_list)) == NULL
		|| (*line = ft_strnew(0)) == NULL)
		return (del_fd(&fd_list, fd));
	while (*(fd_item->buf))
	{
		if ((tmp = ft_strchr(fd_item->buf, '\n')))
			*tmp = '\0';
		if ((*line = line_join(*line, fd_item->buf)) == NULL)
			return (del_fd(&fd_list, fd));
		if (tmp)
		{
			fd_item->buf = ft_strcpy(fd_item->buf, ++tmp);
			return (1);
		}
		fd_item->buf = ft_memset(fd_item->buf, '\0', BUFF_SIZE);
		if (read(fd_item->fd, fd_item->buf, BUFF_SIZE) < 0)
			return (del_fd(&fd_list, fd));
	}
	del_fd(&fd_list, fd);
	return (*line[0] != '\0');
}
