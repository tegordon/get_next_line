/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tegordon <tegordon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 19:53:33 by tegordon          #+#    #+#             */
/*   Updated: 2019/04/26 21:15:17 by tegordon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list			*node_handling(t_list **fd_list, size_t fd)
{
	t_list			*runner;

	if (*fd_list == NULL)
		return (*fd_list = ft_lstnew(ft_strnew(0), fd));
	runner = *fd_list;
	while (runner->next || (runner->content_size == fd))
	{
		if (runner->content_size == fd)
			return (runner);
		runner = runner->next;
	}
	runner->next = ft_lstnew(ft_strnew(0), fd);
	return (runner->next);
}

void			full_newline(char *wya, t_list *fd_node_ptr, char **line)
{
	char	*buffy;

	buffy = fd_node_ptr->content;
	*wya = '\0';
	*line = ft_strdup(fd_node_ptr->content);
	fd_node_ptr->content = ft_strdup(wya + 1);
	free(buffy);
}

void			eof_newline(t_list **fd_list, t_list *fd_node_ptr, char **line)
{
	t_list		*tmp_runner;

	*line = fd_node_ptr->content;
	if (*fd_list == fd_node_ptr)
	{
		*fd_list = fd_node_ptr->next;
		free(fd_node_ptr);
		return ;
	}
	tmp_runner = *fd_list;
	while (tmp_runner->next)
	{
		if (tmp_runner->next == fd_node_ptr->next)
		{
			tmp_runner->next = tmp_runner->next->next;
			free(fd_node_ptr);
			return ;
		}
		tmp_runner = tmp_runner->next;
	}
}

int				is_wya(t_list **fd_list, char *wya,
							t_list *fd_node_ptr, char **line)
{
	if (!wya)
	{
		eof_newline(fd_list, fd_node_ptr, line);
		return (0);
	}
	full_newline(wya, fd_node_ptr, line);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*fd_list;
	t_list			*fd_node_ptr;
	char			bowl[BUFF_SIZE + 1];
	char			*wya;
	int				x;

	if ((read(fd, bowl, 0) == -1) || fd < 0 || !line)
		return (-1);
	fd_node_ptr = node_handling(&fd_list, fd);
	while (!(wya = ft_strchr(fd_node_ptr->content, '\n'))
					&& ((x = read(fd, bowl, BUFF_SIZE)) != 0))
	{
		bowl[x] = '\0';
		fd_node_ptr->content = ft_strjoinfree(fd_node_ptr->content, bowl);
	}
	if (fd_node_ptr->content)
		return (is_wya(&fd_list, wya, fd_node_ptr, line));
	return (0);
}
