#include "cd.h"

void			getoptions(int ac, char **av)
{
	int		i;
	int		j;

	i = 0;
	i++;
	//exit(3);
	while (ac-- > 1 && av[i][0] == '-' && av[i][1] != '\0')
	{
		j = 1;
		if (ft_strcmp(av[i], "--") == 0)
			break ;
		while (av[i][j])
		{
			if (OPTIN(CD_OPT, av[i][j]) == NULL)
				// add a generic function for errors
				break ;
			else
				if (av[i][j] == 'P' && !g_options.p)
					g_options.p = 1;
				else if (av[i][j] == 'L' && !g_options.l)
					g_options.l = 1;
			j++;
		}
		i++;
	}
}

int				getdir(int ac, char **av, t_dict *env, char **buffer)
{
	int		i;
	int		j;
	i = 0;
	i++;
	if(!av[i])
	{
		if (!dict_search(env, "HOME"))
		{
			env_missing("HOME");
			return (-1);
		}
		*buffer = ft_strdup(dict_search(env, "HOME"));
		//ft_putendl(buffer);
		return (0);
	}
	while (ac-- > 1 && av[i][0] == '-' && av[i][1] != '\0')
	{
		j = 1;
		if (ft_strcmp(av[i], "--") == 0)
			break ;
		while (av[i][j])
		{
			if (OPTIN(CD_OPT, av[i][j]) == NULL)
				break ;
			j++;
		}
		i++;
	}
	//ft_putnbr(ac);
	//exit(4);
	if (!*(av + 1))
		*buffer = ft_strdup(*(av));
	else
		*buffer = ft_strdup(*(av + 1));
	return (0);
}

void			put_cd_error(int cderrno, char *dir)
{
	char *message;

	message = NULL;
	if (cderrno == NOTPWD)
		message = "string not in pwd: ";
	else if (cderrno == MANYARGS)
		message = "too many arguments";
	ft_putstr_fd("cd: ", 2);
	ft_putstr_fd(message, 2);
	if (cderrno == NOTPWD)
		ft_putendl_fd(dir, 2);
}
