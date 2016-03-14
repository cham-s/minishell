#include "minishell.h"

t_dict	*g_tokens;

void	interpret_command(t_dict *dictenv, t_cmd *cmd)
{
	char *line;
	char **big_line;
	char **split_line;
	char **env;
	char *prompt;
	int	i = 0;

	while (1)
	{
		prompt = dict_search(dictenv, "PWD");
		prompt = (dict_search(dictenv, "PWD") ? prompt : "minishell");
		ft_putstr("\x1B[33m");
		ft_putstr(prompt);
		ft_putstr(" $> ");
		ft_putstr("\033[0m");
		if (get_next_line(0, &line) == 0)
			exit(0);
		env = dict_to_tab(dictenv);
		big_line = ft_strsplit(line, ';');
		i = 0;
		while (big_line[i])
		{
			split_line = split_parse(big_line[i], dictenv);
			if (initcmd(dictenv, cmd, split_line) != -1)
				launch_exec(cmd, dictenv, env);
			ft_delsplit(split_line);
			i++;
		}
		free(line);
		ft_delsplit(big_line);
		ft_delsplit(env);
	}
}

int     main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	t_cmd	cmd;
	t_dict *envc;

	signal(SIGINT, sig_handler);
	envc = envcpy(env);
	init_tokens(g_tokens);
	interpret_command(envc, &cmd);
	dict_destroy(g_tokens);
	dict_destroy(envc);
	cmd_free(&cmd);
	return (0);
}

