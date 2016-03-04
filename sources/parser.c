#include "minishell.h"

char	is_tokenchr(char c)
{
	if (c == '-' || c == '~')
		return (c); 
	return ('\0');
}

char	*is_tokenstr(char *s)
{
	if (!ft_strcmp(s, "-") || !ft_strcmp(s, "~"))
		return (s);
	return (NULL);
}

/* char	*search_n_replace(char *s) */
/* { */
/* 	if (dict_search(dict, s)) */
/* 	{ */
/* 		if (is_token(s[0] && s[1])) */
/* 	} */
/* 	return (s); */
/* } */
