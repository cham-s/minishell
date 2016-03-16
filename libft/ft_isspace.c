/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 09:29:53 by cattouma          #+#    #+#             */
/*   Updated: 2016/03/16 09:33:00 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_isspace(int c)
{
	unsigned char tc;

	tc = (unsigned char)c;
	if (tc == '\t' || tc == ' ' || tc == '\r'
		|| tc == '\v' || tc == '\f')
		return (true);
	return (false);
}
