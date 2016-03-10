#include "minishell.h"

t_dict	*g_tokens;

void	interpret_command(t_dict *dictenv, t_cmd *cmd)
{
	char *line;
	char **split_line;
	char **env;

	while (1)
	{
		ft_putstr("\x1B[33mminishell\033[0m$> ");
		if (get_next_line(0, &line))
		{
			env = dict_to_tab(dictenv);
			split_line = split_parse(line, dictenv);
			if (initcmd(dictenv, cmd, split_line) != -1)
				launch_exec(cmd, dictenv, env);
			free(line);
			ft_delsplit(split_line);
			ft_delsplit(env);
		}
	}
}

int     main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	t_cmd	cmd;

	t_dict *envc = envcpy(env);
	init_tokens(g_tokens);
	interpret_command(envc, &cmd);
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
