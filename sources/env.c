#include "minishell.h"

void	envcpy(char **env, t_list **envlist)
{
	t_env	new;
	int		start;
	int		i;

	i = 0;
	while (env[i])
	{
		start = ft_strlenchr(env[i], '=');
		new.var = ft_strndup(env[i], start);
		new.value = ft_strdup(env[i] + start + 1);
		ft_lstappend(envlist, ft_lstnew(&new, sizeof(t_env)));
		i++;
	}
}

void	ft_putenv(t_list **env)
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
