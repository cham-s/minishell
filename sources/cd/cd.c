/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 11:09:25 by cattouma          #+#    #+#             */
/*   Updated: 2016/02/28 11:09:27 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "cd.h"

t_cdflag g_options;

int		ft_cd(char **av, t_dict *env)
{
	int ac;
	char *directory;

	directory = NULL;
	initoptions(&g_options);
	ac = ft_tablen(av);
	getoptions(ac, av);
	if (getdir(ac, av, env, &directory) == 0)
	{
		ft_putendl(directory);
		return (-1);
	}
	return (0);
}
