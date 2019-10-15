/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosartor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 18:25:19 by sosartor          #+#    #+#             */
/*   Updated: 2019/10/15 22:10:23 by sosartor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_fdlist
{
	int				fd;
	char			*buf;
	struct s_fdlist	*next;
}					t_fdlist;
int					get_next_line(const int fd, char **line);
static t_fdlist		*new_fd_item(int fd, t_fdlist *next);
static t_fdlist		*get_fd_item(const int fd, t_fdlist **fd_list);
static int			del_fd(t_fdlist **fd_list, int fd);
static char			*line_join(char *line, char *buf);
char				*ft_strnew(size_t size);
void				ft_memdel(void **ap);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *str1, const char *str2);
void				*ft_memset(void *str, int c, size_t n);
#endif
