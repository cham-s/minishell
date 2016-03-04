#include "minishell.h"

int		check_exepath(char *exepath)
{
	if (!access(exepath, X_OK))
		return (0);
	else if (access(exepath, F_OK))
		return (NOFILE);
	else if (access(exepath, X_OK))
		return (NOEXE);
	else if (access(exepath, W_OK))
		return (NOWR);
	else if (access(exepath, R_OK))
		return (NORD);
	else
		return (NOACCESS);
}

void	put_error(int error, char *cmd)
{
	char *message;

	message = NULL;
	if (error == NOFILE)
		message = ": command not found";
	else if (error == NOEXE || error == NOWR ||
			error == NORD || error == NOACCESS)
		message = ": Permission denied";
	else if (error == MANYARGS)
		message = ": too many arguments";
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putendl_fd(message, 2);
	exit(0);
}
