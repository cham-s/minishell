#include "minishell.h"
#include "cd.h"

void			env_usage(char c)
{
	ft_putstr_fd("env: illegal options : -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putendl_fd("", 2);
	ft_putendl_fd("Usage: env [-i] [command]", 2);
}

int			check_options(int ac, char **av, int *f, int *start)
{
	int		i;
	int		j;

	i = 0;
	i++;
	while (ac-- > 1 && av[i][0] == '-' && av[i][1] != '\0')
	{
		j = 1;
		if (ft_strcmp(av[i], "--") == 0)
			break ;
		while (av[i][j])
		{
			if (av[i][j] != 'i')
			{
				(*start)++;
				env_usage(av[i][j]);
				return (-1);
			}
			else
				*f = 1;
			j++;
		}
		(*start)++;
		i++;
	}
	return (0);
}

void	start_env(t_dict *env, t_cmd *cmd)
{
	t_cmd	tcmd;
	char	**s_line;
	int		f;
	int		start;
	char	**env_tab;

	f = 0;
	start = 0;
	if (cmd->ac == 1)
	{
		ft_putenv(env);
		return ;
	}
	if (check_options(cmd->ac, cmd->av, &f, &start) == -1)
		return ;
	s_line = NULL;
	if (!f)
		s_line = cmd->av + 1;
	else
		s_line = cmd->av + start + (f ? 1 : 0);
	if (initcmd(env, &tcmd, s_line) != -1)
	{
		env_tab = dict_to_tab(env);
		if (!f)
			launch_exec(&tcmd, env, env_tab);
		else
			launch_exec(&tcmd, env, NULL);
		ft_delsplit(env_tab);
	}
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
