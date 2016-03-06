#include "minishell.h"

int		is_tokenchr(char c)
{
	if (c == '-' || c == '~')
		return (1); 
	return (0);
}

char	*is_tokenstr(char *s)
{
	if (!s[1])
	{
		if (is_tokenchr(s[0]))
		{
			return (s[0] == '-' ? ft_strdup("-"): ft_strdup("~"));
		}
	}
	else if (ft_strchr(s, '/') - s == 2)
	{
		if (!ft_strncmp(s, "~+", 2) || !ft_strncmp(s, "~-", 2))
			return (ft_strndup(s, 2));
	}
	else if (ft_strchr(s, '/') - s == 1)
	{
		if (s[0] == '-' || s[0] == '~')
			return (ft_strndup(s, 1));
	}
	else if (!ft_strcmp(s, "~+") || !ft_strcmp(s, "~-"))
		return (ft_strdup(s));
	return (NULL);
}