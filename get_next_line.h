/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 10:14:44 by mvann             #+#    #+#             */
/*   Updated: 2017/10/03 16:41:45 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# define BUFF_SIZE 20
# define FD_ARR_SIZE 6000

typedef struct		s_fd_str
{
	int				fd;
	char			*str;
}					t_fd_str;

// typedef struct		s_dict
// {
// 	t_list			**arr;
// 	int				len;
// }					t_dict;

typedef struct			s_buff
{
	char				str[BUFF_SIZE];
	int					i;
}						t_buff;

int get_next_line(const int fd, char **line);

#endif
