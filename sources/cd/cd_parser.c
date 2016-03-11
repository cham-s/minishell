#include "cd.h"

void			getoptions(int ac, char **av)
{
	int		i;
	int		j;
	int flaire;

	flaire = 0;
	i = 0;
	i++;
	while (ac-- > 1 && av[i][0] == '-' && av[i][1] != '\0')
	{
		j = 1;
		if (ft_strcmp(av[i], "--") == 0)
			break ;
		while (av[i][j])
		{
			if (OPTIN(CD_OPT, av[i][j]) == NULL)
			{
				flaire = 1;
				break ;
			}
			else
			{
				if (av[i][j] == 'P' && !g_options.p)
					g_options.p = 1;
				else if (av[i][j] == 'L' && !g_options.l)
					g_options.l = 1;
			}
			j++;
		}
		if (flaire)
			break ;
		i++;
	}
}

int				check_solo_arg(t_dict *env, char **buffer)
{
	char *home;

	home = dict_search(env, "HOME");
	if (!home)
	{
		env_missing("HOME");
		return (-1);
	}
	*buffer = ft_strdup(home);
	return (0);
}

int				getdir(int ac, char **av, t_dict *env, char **buffer)
{
	int		i;
	int		j;
	int flaire;

	flaire = 0;
	i = 0;
	i++;
	if(!av[i])
		return (check_solo_arg(env, buffer));
	while (ac-- > 1 && av[i][0] == '-' && av[i][1] != '\0')
	{
		j = 1;
		if (ft_strcmp(av[i], "--") == 0)
			break ;
		while (av[i][j])
		{
			if (OPTIN(CD_OPT, av[i][j]) == NULL)
			{
				ac++;
				i--;
				flaire = 1;
				break ;
			}
			j++;
		}
		if (flaire)
			break ;
		i++;
	}
	if (ac > 3)
	{
		ft_putendl_fd("cd : too many arguments", 2);
		return (-1);
	}
	if (!av[i + 1])
	{
		if (check_dir(av[i]) != -1)
			*buffer = ft_strdup((av[i]));
	}
	else
	if (check_dir(av[i + 1]) != -1)
	{
		*buffer = ft_strdup(av[i + 1]);
	}
	return (0);
}

int			check_dir(char *dir)
{
	char		*message;
	struct stat	file;

	message = NULL;
	if (stat(dir, &file) < 0)
		message = "No such file or directory: ";
	else if (access(dir, X_OK))
		message = "Permission denied: ";
	else if (!S_ISDIR(file.st_mode))
		message = "Not a directory: ";
	if (!message)
		return (0);
	else
	{
		ft_putstr_fd("cd: ", 2); 
		ft_putstr_fd(message, 2);
		ft_putendl_fd(dir, 2);
		return (-1);
	}
}
