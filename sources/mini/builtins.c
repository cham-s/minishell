#include "minishell.h"
#include "cd.h"

void	start_env(t_dict *env, t_cmd *cmd)
{
	//do some stuff here like the real env
	t_cmd	tcmd;
	char	**s_line;

	if (cmd->ac == 1)
	{
		ft_putenv(env);
		return ;
	}
	s_line = NULL;
	s_line = cmd->av + 1;
	if (initcmd(env, &tcmd, s_line) != -1)
		launch_exec(&tcmd, env);
	else
		launch_exec(&tcmd, env);
}

void	start_unsetenv(t_dict *env, t_cmd *cmd)
{
	// check if there is more to add
	ft_unsetenv(cmd->av[1], env);
}

void	start_setenv(t_dict *env, t_cmd *cmd)
{
	if (cmd->ac == 1)
		ft_putendl_fd("setenv: too few arguments", 2);
	else if (cmd->ac > 4)
		ft_putendl_fd("setenv: too many arguments", 2);
	else
		if (cmd->ac == 4)
			ft_setenv(cmd->av[1], cmd->av[2], env, ft_atoi(cmd->av[3]));
		else
			ft_setenv(cmd->av[1], cmd->av[2], env, 0);
}

void	start_exit(t_dict *env, t_cmd *cmd)
{
	//test
	(void)env;
	if (cmd->ac > 2)
		ft_putendl_fd("exit: too many arguments", 2);
	else
	{
		if (cmd->ac == 1)
			exit(0);
		else
		{
			if (is_numeric(cmd->av[1]))
				exit(ft_atoi(cmd->av[1]));
			else
			{
				ft_putendl_fd("exit: ", 2);
				ft_putendl_fd(cmd->av[1], 2);
				ft_putendl_fd(": not a numeric value", 2);
				exit(-1);
			}
		}
	}
}

void	start_cd(t_dict *env, t_cmd *cmd)
{
	ft_cd(cmd->ac, cmd->av, env);
}
