#include "minishell.h"

//extern char *g_tokens[5] = { "-", "~", ".", "..", NULL}

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
		ft_putstr("minishell>");
		get_next_line(0, &line);
		//make var for enncpy **char to be free later
		if (initcmd(dict_search(envc, "PATH"), &cmd, line) != -1)
			launch_exec(&cmd, dict_to_tab(envc));
		free(line);
	}
	return (0);
}
