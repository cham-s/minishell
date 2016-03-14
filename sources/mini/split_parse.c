/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:33:18 by cattouma          #+#    #+#             */
/*   Updated: 2016/03/11 18:44:16 by cattouma         ###   ########.fr       */
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

int		slash_position(char *s)
{
	return (ft_strchr(s, '/') - s );
}

int		replace_s(char **s, t_dict *env, char **key, int s_pos)
{
	char	*tmp;
	char	*envar;

	envar = dict_search(env, dict_search(g_tokens, *key));
	if (!envar)
	{
		env_missing(dict_search(g_tokens, *key));
		return (-1);
	}
	tmp = *s;
	*s = ft_strjoin(envar, *s + s_pos);
	free(tmp);
	free(*key);
	return (0);
}

int		replace_all(char **s, t_dict *env, char **key)
{
	char	*tmp;
	char	*envar;

	envar = dict_search(env, dict_search(g_tokens, *key));
	if (!envar)
	{
		env_missing(dict_search(g_tokens, *key));
		return (-1);
	}
	tmp = *s;
	*s = ft_strdup(envar);
	free(tmp);
	free(*key);
	return (0);
}

char			*replace_symbol(char *s, t_dict *env)
{
	char	*key;
	int		slash_pos;

	slash_pos = slash_position(s);
	if ((key = is_tokenstr(s)))
	{
		if (slash_pos == 2 || slash_pos == 1)
		{
			if (replace_s(&s, env, &key, slash_pos) == -1)
				return (s);
		}
		else
			if (replace_all(&s, env, &key) == -1)
				return (s);
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
