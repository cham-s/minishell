#include "minishell.h"

char	is_tokenchr(char c)
{
	if (c == '-' || c == '~')
		return (c); 
	return ('\0');
}

char	*is_tokenstr(char *s)
{
	if (!s[1])
	{
		if (s[0] == '-' || s[0] == '~')
			return (s);
	}
	else
		if (!ft_strncmp(s, "~+", 2) || !ft_strncmp(s, "~-", 2))
			return (s);
	return (NULL);
}

char	*search_n_replace(char *s)
{
	if (dict_search(dict, s))
	{
		if (is_token(s[0] && s[1]) || is_token())
	}
	return (s);
}
