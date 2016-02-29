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

/* char	*check_path(char *cmd, char *path, char **path_tab) */	
/* { */
/* 	int		i; */
/* 	char	*cmdpath; */

/* 	i = 0; */
/* 	while (path_tab[i]) */
/* 	{ */
/* 		cmdpath = join_with_chr(path_tab[i], cmd, '/'); */
/* 		if (access(cmdpath, F_OK) != -1) */
/* 			return (cmdpath); */
/* 		i++; */
/* 	} */
/* 	return (NULL); */
/* } */

void	launch_exec(char *cmd, char **av, t_list **envlist)
{
	pid_t	child_pid;	
	pid_t	t_pid = 0;	
	int		status;

	child_pid = fork();
	if (child_pid == 0)
	{
		execve(cmd, av, list_to_tab(envlist));
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

int     main (int ac, char **av, char **env)
{
	ac++;
	av--;
	char *line;
	t_list *envlist;
	t_cmd	cmd;

	envlist = NULL;
	envcpy(env, &envlist);
	while (1)
	{
		ft_putstr("minishell>");
		get_next_line(0, &line);
		initcmd(get_env(&envlist, "PATH"), &cmd, line);
		launch_exec(cmd.exepath, cmd.av, &envlist);
		free(line);
	}
	return (0);
}
