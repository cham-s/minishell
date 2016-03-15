#include "minishell.h"

t_dict	*g_tokens;

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

