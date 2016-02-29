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

char	*join_with_chr(char *var, char *value, char c)
{
	char	*new;
	size_t	varlen;
	size_t	valuelen;

	varlen = ft_strlen(var);
	valuelen = ft_strlen(value);
	new = ft_strnew(varlen + valuelen + 1);
	if (!new)
		return (NULL);
	ft_strncpy(new, var, varlen);
	new[varlen] = c;
	ft_strncpy(new + varlen + 1, value, valuelen);
	return (new);
}

char	**list_to_tab(t_list **envlist)
{
	char	**env;
	t_list	*cur;
	size_t	len;	
	int		i;

	cur = *envlist;
	i = 0;
	len = ft_lstlen(envlist);
	env = (char **)ft_memalloc(len);
	if (!env)
		return (NULL);
	while (cur)
	{
		env[i] = join_with_chr(T_ENV(cur)->var, T_ENV(cur)->value, '=');
		cur = cur->next;
		i++;
	}
	return (env);
}

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
