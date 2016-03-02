/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:33:18 by cattouma          #+#    #+#             */
/*   Updated: 2016/03/02 16:18:33 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	to_allocate(const char *s)
{
	size_t	size;

	size = 0;
	while (ft_isspace(*s) && *s)
		s++;
	while (*s)
	{
		while (ft_isspace(*s))
			s++;
		if ((*s && (!ft_isspace(*s))) && ((ft_isspace(*(s + 1))) || *(s + 1) == '\0'))
			size++;
		if (*s)
			s++;
	}
	return (size);
}

static size_t	ft_strlenchar(const char *s)
{
	size_t i;

	i = 0;
	while (ft_isspace(*s) && *s)
		s++;
	while (!ft_isspace(*s) && *s)
	{
		i++;
		s++;
	}
	return (i);
}

int				is_symbol(char c)
{
	return(c == '-' || c == '~');
}

char			*replace_symbol(char *s, t_dict *env)
{
	char	*key;
	t_dict	*symbols;

	symbols = dict_create();
	dict_insert(symbols, "-", "OLDPWD");
	dict_insert(symbols, "~-", "HOME");
	dict_insert(symbols, "~+", "HOME");
	dict_insert(symbols, ".", "PWD");
	if ((key = dict_search(symbols, s)))
	{
		key = ft_strdup(key);
		free(s);
		dict_destroy(symbols);
		//ft_putendl((dict_search(env, "OLDPWD")));
		//exit(4);
		return(dict_search(env, key));
	}
	return (s);
}

char			**split_parse(char const *s, t_dict *env)
{
	char	**new;
	size_t	len;
	size_t	i;
	size_t	strlen;

	if (s == NULL)
		return (NULL);
	i = 0;
	strlen = 0;
	len = to_allocate(s);
	new = (char **)ft_memalloc(len + 1);
	if (!new)
		return (NULL);
	while (len--)
	{
		while (ft_isspace(*s))
			s++;
		strlen = ft_strlenchar(s);
		new[i] = ft_strndup(s, strlen);
		new[i] = replace_symbol(new[i], env);
		s += strlen;
		i++;
	}
	new[i] = NULL;
	return (new);
}
