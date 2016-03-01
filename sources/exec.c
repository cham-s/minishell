#include "minishell.h"

void	launch_exec(t_cmd *cmd, t_list **envlist)
{
	pid_t	child_pid;	
	pid_t	t_pid = 0;	
	int		status;
	char **env; 

	env = list_to_tab(envlist);
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
