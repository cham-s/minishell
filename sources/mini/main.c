/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 08:52:33 by cattouma          #+#    #+#             */
/*   Updated: 2016/03/16 08:53:36 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dict	*g_tokens;

int		main(int ac, char **av, char **env)
{
	t_cmd	cmd;
	t_dict	*envc;

	(void)ac;
	(void)av;
	signal(SIGINT, sig_handler);
	envc = envcpy(env);
	init_tokens(g_tokens);
	interpret_command(envc, &cmd);
	dict_destroy(g_tokens);
	dict_destroy(envc);
	cmd_free(&cmd);
	return (0);
}
