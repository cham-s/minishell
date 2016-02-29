/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 11:08:58 by cattouma          #+#    #+#             */
/*   Updated: 2016/02/28 13:51:42 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		new.key = ft_strndup(env[i], start);
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
		ft_putstr(((t_env*)current->content)->key);
		ft_putchar('=');
		ft_putendl(((t_env*)current->content)->value);
		current = current->next;
	}
}

/*
char	**get_env_values(char **env, char *var)
{
	int		i;
	char	**values;

	i = 0;

	while (env[i])
	{
		start = ft_strlenchr(env[i], '=');
		if (!ft_strncmp(var, env[i], start))
		{
			values  = ft_strsplit(env[i] + start + 1, ':');
			break ;
		}
		i++;
	}

	return (NULL);
}
*/

void	free_tab(char **tab)
{
	char **tmp;

	tmp = tab;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(tab);
}
