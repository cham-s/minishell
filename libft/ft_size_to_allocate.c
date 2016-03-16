/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_to_allocate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 09:32:14 by cattouma          #+#    #+#             */
/*   Updated: 2016/03/16 09:32:15 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	size_to_allocate(const char *s, char c)
{
	size_t	size;

	size = 0;
	while (*s == c && *s)
		s++;
	while (*s)
	{
		while (*s == c)
			s++;
		if ((*s && (*s != c)) && ((*(s + 1) == c) || *(s + 1) == '\0'))
			size++;
		if (*s)
			s++;
	}
	return (size);
}
