/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 13:59:36 by cattouma          #+#    #+#             */
/*   Updated: 2016/03/16 09:33:53 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 64

typedef struct		s_file
{
	int				fd;
	char			*buffer;
	struct s_file	*right;
	struct s_file	*left;
}					t_file;

int					get_next_line(int const fd, char **line);

#endif
