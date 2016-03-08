#include "minishell.h"

t_dict	*g_tokens;

int     main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	char *line;
	t_cmd	cmd;

	t_dict *envc = envcpy(env);
	init_tokens(g_tokens);
	while (1)
	{
		ft_putstr("\x1B[33mminishell\033[0m$> ");
		get_next_line(0, &line);
		if (initcmd(envc, &cmd, line) != -1)
			launch_exec(&cmd, envc);
		free(line);
	}
	dict_destroy(g_tokens);
	dict_destroy(envc);
	return (0);
}

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
