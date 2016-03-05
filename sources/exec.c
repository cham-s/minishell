/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:32:41 by cattouma          #+#    #+#             */
/*   Updated: 2016/03/05 10:08:21 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	launch_exec(t_cmd *cmd, t_dict *env)
{
	pid_t	child_pid;	
	pid_t	t_pid = 0;	
	int		status;
	char	**tab_env;

	if (!env)
		return ;
	if (cmd->av[0])
	{
		if (!ft_strcmp(cmd->av[0], "env"))
		{
			ft_putenv(env);
			return ;
		}
		else if (!ft_strcmp(cmd->av[0], "unsetenv"))
		{
			ft_unsetenv(cmd->av[1], env);
			return ;
		}
		else if (!ft_strcmp(cmd->av[0], "setenv"))
		{
			ft_setenv(cmd->av[1], cmd->av[2], env, 0);
			return ;
		}
		else if (!ft_strcmp(cmd->av[0], "exit"))
		{
			if (cmd->av[1])
				put_error(MANYARGS, "exit");
			else
				exit(0);
		}
	}
	child_pid = fork();
	tab_env = dict_to_tab(env);
	if (child_pid == 0)
	{
		execve(cmd->exepath, cmd->av, tab_env);
		put_error(cmd->error, cmd->av[0]);
	}
	else
	{
		waitpid(t_pid, &status, 0);
		//free_tab(env);
		//free_tab(cmd->av);
		return ;
	}
}
