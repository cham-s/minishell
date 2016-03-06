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

	initoptions(&g_options);
	ac = ft_tablen(av);
	getoptions(ac, av);
	directory = getdir(ac, av, env);
	ft_putendl(directory);
	exit(1);

	/* char	*pwd; */

	/* if (ft_tablen(av) > 3) */
	/* { */
	/* 	//change function prototype or cd has it's own errors set */
	/* 	//like string not in pwd */
	/* 	put_error(MANYARGS, "cd"); */
	/* 	return (-1); */
	/* } */
	/* pwd = ft_strdup(dict_search(env, "PWD")); */
	/* dict_delete(env, "OLDPWD"); */
	/* dict_insert(env, "OLDPWD", pwd); */
	/* free(pwd); */
	/* if (dict_search("CDPATH")) */
	/* { */
	/* 	if (av[0] && !av[1]) */
	/* 	{ */
	/* 		if (chdir(dict_search(env, "HOME")) == -1) */
	/* 			return (-1); */
	/* 		return */ 
	/* 	} */
	/* } */

	/* return (1); */

	if (ac == 1)
	{
		if (!(directory = dict_search(env, "HOME")))
		{
			// improve this
			ft_putendl_fd("the HOME environment variable is not set", 2);
			exit(1);
		}
	}
	else
	{
	}
}
