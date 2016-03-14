#include "minishell.h"

int		ft_isnum(char c)
{
	return (c >= '0' && c <= '9');
}

int		is_numeric(char *s)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		if (!ft_isnum(s[i]))
			return (0);
		i++;
	}
	return (1);
}

void	put_error(char *path, char *cmd)
{
	char		*message;

	message = NULL;
	if (access(path, F_OK))
		message = "command not found";
	else if (access(path, X_OK))
		message = "Permission denied";
	else
		message = "Permission denied";
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(cmd, 2);
}

void	env_missing(char *envkey)
{
	ft_putstr_fd(envkey, 2);
	ft_putendl_fd(": environement variable missing, you can set it using setenv", 2);
}
