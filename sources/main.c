#include "minishell.h"

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
	t_dict *envc = envcpy(env);
	char *line;
	t_cmd	cmd;

	while (1)
	{
		ft_putstr("minishell $>");
		get_next_line(0, &line);
		//make var for enncpy **char to be free later
		if (initcmd(envc, &cmd, line) != -1)
			launch_exec(&cmd, envc);
		free(line);
	}
	return (0);
}
