/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:43:16 by cattouma          #+#    #+#             */
/*   Updated: 2016/03/07 14:35:25 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		loop_paths(t_cmd *cmd, char **binlist)
{
	int		i;
	char	*exepath;

	i = 0;
	while (binlist[i])
	{
		exepath = join_with_chr(binlist[i], (cmd)->av[0], '/');
		if (!access(exepath, F_OK))
		{
			cmd->exepath = exepath;
			return (0);
		}
		i++;
	}
	return (0);
}

int		initcmd(t_dict *env, t_cmd *cmd, char **split_line)
{
	char	**bins;

	bins = ft_strsplit(dict_search(env, "PATH"), ':');
	cmd->exepath = NULL;
	//malloc;
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
			return (loop_paths(cmd, bins));
	}
	return (-1);
}
