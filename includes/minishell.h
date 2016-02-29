#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"

typedef	struct	s_env
{
	char *key;
	char *value;
}				t_env;

char	**envdup(char **env);
void	envcpy(char **env, t_list **envlist);
char	**get_env_values(char **env, char *var);
void	free_tab(char **tab);
void	ft_putenv(t_list **env);

#endif
