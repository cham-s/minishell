#include "libft.h"
#include "minishell.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char *g_tokens[5] = { "-", "~", ".", "..", NULL}

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

int     main(int ac, char **av, char **env)
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
		//make var for enncpy **char to be free later
		if (initcmd(get_env(&envlist, "PATH"), &cmd, line) != -1)
			launch_exec(&cmd, &envlist);
		free(line);
	}
	return (0);
}
