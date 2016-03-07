#ifndef MINISHELL_H
# define MINISHELL_H
# include <sys/types.h>
# include <sys/wait.h>
# include "libft.h"
# include "dict.h"
# define	NOFILE			1	
# define	NOEXE			2
# define	NOWR			3
# define	NORD			4
# define	NOACCESS		5
# define	EMPTYPATH		6
# define	MANYARGS		7

typedef struct		s_cmd
{
	char	**av;
	int		ac;
	char	*exepath;
	int		error;
}					t_cmd;

extern t_dict	*g_tokens;

t_dict				*envcpy(char **env);
void				ft_putenv(t_dict *env);
char				**dict_to_tab(t_dict *env);
char				*join_with_chr(char *var, char *value, char c);
int					initcmd(t_dict *env, t_cmd *cmd, char *line);
int					check_exepath(char *exepath);
void				put_error(int error, char *cmd);
void				launch_exec(t_cmd *cmd, t_dict *env);
void				free_tab(char **tab);
char				**split_parse(char const *s, t_dict *env);
int					ft_setenv(const char *key, const char *value, t_dict *env, int overwrite);
int					ft_unsetenv(const char *key, t_dict *env);
int					is_tokenchr(char c);
char				*is_tokenstr(char *s);
int					init_tokens(t_dict *tokens);
void				env_missing(char *envkey);

#endif
