/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:43:16 by cattouma          #+#    #+#             */
/*   Updated: 2016/03/02 12:14:59 by cattouma         ###   ########.fr       */
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
		if ((cmd->error = check_exepath(exepath)) == 0)
		{
			cmd->exepath = exepath;
			return (0);
		}
		i++;
	}
	return (0);
}

int		initcmd(t_dict *env, t_cmd *cmd, char *line)
{
	char	**bins;

	bins = ft_strsplit(dict_search(env, "PATH"), ':');
	cmd->exepath = NULL;
	cmd->av = split_parse(line, env);
	if (cmd->av[0])
	{
		if ((cmd->error = check_exepath(cmd->av[0]) == 0))
		{
			cmd->exepath = ft_strdup(cmd->av[0]);
			return (0);
		}
		else
			return (loop_paths(cmd, bins));
	}
	return (-1);
}
