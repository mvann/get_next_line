/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 09:56:49 by mvann             #+#    #+#             */
/*   Updated: 2017/10/03 17:00:39 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> //##############################################

// char	*new_fd_str(t_list **lst, int fd)
// {
// 	t_fd_str *fd_str;
//
// 	fd_str = (t_fd_str *)malloc(t_fd_str);
// 	fd_str->fd = fd;
// 	fd_str->str = (char *)malloc(BUFF_SIZE);
// 	return ((*lst)->str);
// }
//
// static char	*get_fd_str(t_list **lst, int fd)
// {
// 	if ((*lst)
//
// 	if (!(*lst))
// 	{
// 		lst = ft_lstnew(new_fd_str(fd), sizeof(t_fd_str));
// 		return (new_fd_str(&lst, fd));
// 	}
// 	if (lst->content->fd == fd)
// 		return (lst->content->str);
// 	return get_fd_str(lst->next, fd);
// }

static int	check_leftover(char **leftover, char **line)
{
	char	*tmp;
	int		i;

	if (!(tmp = ft_strchr(*leftover, '\n')))
		return (0);
	i = 0;
	while ((*leftover)[i] != '\n')
		i++;
	if (!(*line = ft_strsub(*leftover, 0, i)))
		return (-1);
	if (!(tmp = ft_strdup(tmp + 1)))
		return (-1);
	free(*leftover);
	*leftover = tmp;
	return (1);
}

static int	append(char **leftover, char **buffer)
{
	char *tmp;

	if (!(tmp = ft_strjoin(*leftover, *buffer)))
		return (0);
	free(*leftover);
	*leftover = tmp;
	return (1);
}

static int	done_reading(char **leftover, char **line)
{
	if (!(*line = ft_strdup(*leftover)))
		return (-1);
	free(*leftover);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char		*leftover;
	char			*buffer;
	int				ret;

	if (!leftover)
		if (!(leftover = ft_strnew(BUFF_SIZE)))
			return (-1);
	if (!(buffer = ft_strnew(BUFF_SIZE)))
		return (-1);
	if ((ret = check_leftover(&leftover, line)))
		return (ret);
	while((ret = read(fd, buffer, BUFF_SIZE)))
	{
		if (ret < 0 || !append(&leftover, &buffer))
			return (-1);
		if ((ret = check_leftover(&leftover, line)))
			return (ret);
	}
	free(buffer);
	return (ret < 0 ? -1 : done_reading(&leftover, line));
}
