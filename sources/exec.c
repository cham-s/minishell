/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:32:41 by cattouma          #+#    #+#             */
/*   Updated: 2016/03/02 10:53:14 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	launch_exec(t_cmd *cmd, char **env)
{
	pid_t	child_pid;	
	pid_t	t_pid = 0;	
	int		status;

	child_pid = fork();
	if (child_pid == 0)
	{
		execve(cmd->exepath, cmd->av, env);
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
