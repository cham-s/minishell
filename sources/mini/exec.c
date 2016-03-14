/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:32:41 by cattouma          #+#    #+#             */
/*   Updated: 2016/03/07 17:02:41 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "cd.h"

static int		check_bltn(t_cmd *cmd, t_dict *dictenv)
{
	int is_blt;

	is_blt = 0;
	if (cmd->ac > 0)
	{
		if (!ft_strcmp(cmd->av[0], "env"))
			is_blt = start_env(dictenv, cmd);
		else if (!ft_strcmp(cmd->av[0], "setenv"))
			is_blt = start_setenv(dictenv, cmd);
		else if (!ft_strcmp(cmd->av[0], "unsetenv"))
			is_blt = start_unsetenv(dictenv, cmd);
		else if (!ft_strcmp(cmd->av[0], "cd"))
			is_blt = start_cd(dictenv, cmd);
		else if (!ft_strcmp(cmd->av[0], "exit"))
			is_blt = start_exit(dictenv, cmd);
		if (is_blt)
			return (1);
	}
	return (0);
}

void			launch_exec(t_cmd *cmd, t_dict *dictenv, char **env)
{
	pid_t	child_pid;	
	pid_t	t_pid = 0;	
	int		status;

	if (!dictenv)
		return ;
	if (check_bltn(cmd, dictenv))
		return ;
	child_pid = fork();
	if (child_pid == 0)
	{
		execve(cmd->exepath, cmd->av, env);
		put_error(cmd->exepath, cmd->av[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(t_pid, &status, 0);
		cmd_free(cmd);
		return ;
	}
}
