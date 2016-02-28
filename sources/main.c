#include "libft.h"
#include "minishell.h"
#include <unistd.h>

void	ft_delsplit(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int     main (int ac, char **av, char **env)
{
	ac++;
	av++;
	env++;
	char *line;
	char *tmp;
	char **split;
	int i;

	while (1)
	{
		i = 0;
		ft_putstr("minishell>");
		get_next_line(0, &line);
		tmp = line;
		split = ft_strsplitspc(line);
		while (split[i])
		{
			ft_putendl(split[i]);
			i++;
		}
		free(tmp);
	}
	return (0);
}
