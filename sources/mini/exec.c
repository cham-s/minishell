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

void	launch_exec(t_cmd *cmd, t_dict *dictenv, char **env)
{
	pid_t	child_pid;	
	pid_t	t_pid = 0;	
	int		status;

	if (!env)
		return ;
	if (cmd->ac > 0)
	{
		if (!ft_strcmp(cmd->av[0], "env"))
		{
			start_env(dictenv, cmd);
			return ;
		}
		else if (!ft_strcmp(cmd->av[0], "setenv"))
		{
			start_setenv(dictenv, cmd);
			return ;
		}
		else if (!ft_strcmp(cmd->av[0], "unsetenv"))
		{
			start_unsetenv(dictenv, cmd);
			return ;
		}
		else if (!ft_strcmp(cmd->av[0], "cd"))
		{
			start_cd(dictenv, cmd);
			return ;
		}
		else if (!ft_strcmp(cmd->av[0], "exit"))
		{
			start_exit(dictenv, cmd);
			return ;
		}
	}
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
		return ;
	}
}
