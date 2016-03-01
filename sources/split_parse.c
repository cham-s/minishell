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

char			*is_symbol(char *s, size_t len, t_list **env)
{
	t_env env;
	while ()
	env = get_env()
	if (get_)
}

char			**ft_splitspaces(char const *s, t_list **env)
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
		s += strlen;
		i++;
	}
	new[i] = NULL;
	return (new);
}
