#include "minishell.h"

int		initcmd(t_env *path, t_cmd *cmd, char *line)
{
	char	**bins;
	char	*exepath;
	int		i;

	i = 0;
	bins = ft_strsplit(path->value, ':');
	if (!bins)
	{
		(cmd)->error = 45;
		return(-1);
	}
	(cmd)->exepath = NULL;
	(cmd)->av = ft_splitspaces(line);
	if ((cmd)->av[0])
	{
		while (bins[i])
		{
			// free exepath
			exepath = join_with_chr(bins[i], (cmd)->av[0], '/');
			if (!access(exepath, F_OK))
			{
				(cmd)->exepath = exepath;
				break ;
			}
			i++;
		}
		if (!(cmd)->exepath)
			return (-1);
	}
	return (1);
}
