#include "minishell.h"

t_dict	*envcpy(char **env, t_list **envlist)
{
	t_dict	*envdict;
	int		start;
	char	*key;
	char	*value;
	int		i;

	envdict = dict_create(void);
	if (!envdict)
		return (NULL);
	i = 0;
	while (env[i])
	{
		start = ft_strlenchr(env[i], '=');
		key = ft_strndup(env[i], start);
		value = ft_strdup(env[i] + start + 1);
		dict_insert(envidict, key, value);
		i++;
	}
	free(key);
	free(value);
	return (envdict);
}

void	ft_putenv(t_dict *envdict)
{
	t_list *current;

	current = *env;
	while (current)
	{
		ft_putstr(((t_env *)current->content)->var);
		ft_putchar('=');
		ft_putendl(((t_env *)current->content)->value);
		current = current->next;
	}
}

t_env	*get_env(t_list **envlist, char *var)
{
	t_list *current;

	current = *envlist;
	while (current)
	{
		if (!ft_strcmp(((t_env *)current->content)->var, var))
			return ((t_env *)current->content);
		current = current->next;
	}
	return (NULL);
}
