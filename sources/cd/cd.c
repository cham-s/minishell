/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 11:09:25 by cattouma          #+#    #+#             */
/*   Updated: 2016/03/11 17:17:01 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "cd.h"

t_cdflag g_options;

int		ft_cd(int ac, char **av, t_dict *env)
{
	char *directory;
	char *oldpwd;
	char *pwd;
	char buff[PATH_MAX + 1];

	directory = NULL;
	initoptions(&g_options);
	getoptions(ac, av);
	if (getdir(ac, av, env, &directory) == 0)
	{
		oldpwd = getcwd(buff, PATH_MAX + 1);
		if (chdir(directory) < 0)
		{
			free(directory);
			return (-1);
		}
		ft_setenv("OLDPWD", (!oldpwd ? NULL : oldpwd), env, 1);
		pwd = getcwd(buff, PATH_MAX + 1);
		ft_setenv("PWD", (!pwd ? NULL : pwd), env, 1);
		free(directory);
		return (0);
	}
	return (-1);
}
