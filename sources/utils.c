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

char	**envdup(char **env)
{
	char	**newenv;
	size_t	len;
	int		i;

	i = 0;
	len = ft_tablen(env);
	newenv = (char **)ft_memalloc(len);
	if (!newenv)
		return (NULL);
	while (len--)
	{
		newenv[i] = ft_strdup(env[i]);
		i++;
	}
	return (newenv);
}

void	free_tab(char **tab)
{
	char **tmp;

	tmp = tab;
	while (*tab)
	{
		free(*tab);
		tab++;
	}
	free(tmp);
}

void	ft_putenv(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
}
