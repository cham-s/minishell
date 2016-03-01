#include "minishell.h"

t_dict	*envcpy(char **env)
{
	t_dict	*envdict;
	int		start;
	char	*key;
	char	*value;
	int		i;

	envdict = dict_create();
	if (!envdict)
		return (NULL);
	i = 0;
	while (env[i])
	{
		start = ft_strlenchr(env[i], '=');
		key = ft_strndup(env[i], start);
		value = ft_strdup(env[i] + start + 1);
		dict_insert(envdict, key, value);
		i++;
		free(key);
		free(value);
	}
	return (envdict);
}

void	ft_putenv(t_dict *env)
{
	int		i;
	t_elt	*e;

	i = 0;
	while (i < env->size)
	{
		e = env->table[i];
		while (e)
		{
			ft_putstr(e->key);
			ft_putchar('=');
			ft_putendl(e->value);
			e = e->next;
		}
		i++;
	}
}
