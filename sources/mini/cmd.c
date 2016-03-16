/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:43:16 by cattouma          #+#    #+#             */
/*   Updated: 2016/03/16 08:37:45 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		loop_paths(t_cmd *cmd, t_dict *env)
{
	int		i;
	char	*exepath;
	char	**binlist;

	binlist = ft_strsplit(dict_search(env, "PATH"), ':');
	i = 0;
	exepath = NULL;
	while (binlist[i])
	{
		if (exepath)
			free(exepath);
		exepath = join_with_chr(binlist[i], (cmd)->av[0], '/');
		if (!access(exepath, F_OK))
		{
			cmd->exepath = ft_strdup(exepath);
			break ;
		}
		i++;
	}
	ft_delsplit(binlist);
	free(exepath);
	return (0);
}

int				initcmd(t_dict *env, t_cmd *cmd, char **split_line)
{
	cmd->exepath = NULL;
	cmd->av = split_line;
	cmd->ac = ft_tablen(cmd->av);
	if (cmd->av[0])
	{
		if (!access(cmd->av[0], F_OK))
		{
			cmd->exepath = ft_strdup(cmd->av[0]);
			return (0);
		}
		else
			return (loop_paths(cmd, env));
	}
	return (-1);
}
