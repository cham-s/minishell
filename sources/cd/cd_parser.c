#include "cd.h"

void			check_opts(char *str, int *flair)
{
	int i;

	i = 1;
	while (str[i])
	{
		if (OPTIN(CD_OPT, str[i]) == NULL)
		{
			*flair = 1;
			break ;
		}
		else
		{
			if (str[i] == 'P' && !g_options.p)
				g_options.p = 1;
			else if (str[i] == 'L' && !g_options.l)
				g_options.l = 1;
		}
		i++;
	}
}

void			getoptions(int ac, char **av)
{
	int		i;
	int flair;

	flair = 0;
	i = 0;
	i++;
	while (ac-- > 1 && av[i][0] == '-' && av[i][1] != '\0')
	{
		if (ft_strcmp(av[i], "--") == 0)
			break ;
		check_opts(av[i], &flair);
		if (flair)
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

int				add_to_buff(int ac, char **av, int *i, char ***buffer)
{
	if (ac > 3)
	{
		ft_putendl_fd("cd : too many arguments", 2);
		return (-1);
	}
	if (!av[*i + 1])
	{
		if (check_dir(av[*i]) != -1)
			**buffer = ft_strdup((av[*i]));
	}
	else
	if (check_dir(av[*i + 1]) != -1)
	{
		**buffer = ft_strdup(av[*i + 1]);
	}
	return (0);
}

void			chk(char *str,int *ac, int *i, int *flair)
{
	int j;

	j = 1;
	while (str[j])
	{
		if (OPTIN(CD_OPT, str[j]) == NULL)
		{
			(*ac) += 1;
			(*i) += 1;
			*flair = 1;
			break ;
		}
		j++;
	}
}

int				getdir(int ac, char **av, t_dict *env, char **buffer)
{
	int		i;
	int flair;

	flair = 0;
	i = 0;
	i++;
	if(!av[i])
		return (check_solo_arg(env, buffer));
	while (ac-- > 1 && av[i][0] == '-' && av[i][1] != '\0')
	{
		if (ft_strcmp(av[i], "--") == 0)
			break ;
		// while
		chk(av[i], &ac, &i, &flair);
		if (flair)
			break ;
		i++;
	}
	return add_to_buff(ac, av, &i, &buffer);
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
