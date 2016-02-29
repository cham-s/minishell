#include "libft.h"
#include "minishell.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void	ft_delsplit(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

/*
void run(char *cmd, char **argv, char **env_values)
{
	pid_t	child_pid;	
	pid_t	t_pid = 0;	
	int		status;

	child_pid = fork();
	if (child_pid == 0)
	{
		execve(cmd, argv, NULL);
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd(": no command found", 2);
		exit(0);
	}
	else
	{
		waitpid(t_pid, &status, 0);
		return ;
	}
}
*/

int     main (int ac, char **av, char **env)
{
	ac++;
	av--;
	//char *line;
	t_list *envlist;

	envcpy(env, &envlist);
	ft_putenv(&envlist);
	/*
	while (1)
	{
		ft_putstr("minishell>");
		get_next_line(0, &line);
		run(cmd, argv, env);
		free(line);
		ft_delsplit(argv);
	}
	*/
	return (0);
}
