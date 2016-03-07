/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:32:33 by cattouma          #+#    #+#             */
/*   Updated: 2016/03/07 15:24:30 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		ft_unsetenv(const char *key, t_dict *env)
{
	if (!key || ft_strchr(key, '=') || key[0] == '\0')
		return (-1);
	dict_delete(env, key);
	return (0);
}

int		ft_setenv(const char *key, const char *value, t_dict *env, int overwrite)
{
	if (!key || ft_strchr(key, '=') || key[0] == '\0' || !value || overwrite != 0 || overwrite != 1)
		return (-1);

	if (overwrite)
		dict_delete(env, key);
	dict_insert(env, key, value);
	return (0);
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
