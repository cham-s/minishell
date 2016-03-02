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

int		check_exepath(char *exepath)
{
	if (!access(exepath, X_OK))
		return (0);
	else if (access(exepath, F_OK))
		return (NOFILE);
	else if (access(exepath, X_OK))
		return (NOEXE);
	else if (access(exepath, W_OK))
		return (NOWR);
	else if (access(exepath, R_OK))
		return (NORD);
	else
		return (NOACCESS);
}

void	put_error(int error, char *cmd)
{
	char *message;

	message = NULL;
	if (error == NOFILE)
		message = ": command not found";
	else if (error == NOEXE || error == NOWR ||
			error == NORD || error == NOACCESS)
		message = ": Permission denied";
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putendl_fd(message, 2);
	exit(0);
}

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
			return (1);
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
			return (1);
		}
		else
			return (loop_paths(cmd, bins));
	}
	return (0);
}
