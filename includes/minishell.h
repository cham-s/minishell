#ifndef MINISHELL_H
# define MINISHELL_H
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include "libft.h"
# include "dict.h"

typedef struct		s_cmd
{
	char	**av;
	int		ac;
	char	*exepath;
}					t_cmd;

typedef				void(*fbuiltin)(t_dict *env, t_cmd *cmd);

typedef struct		s_func
{
	char			*key;
	fbuiltin		func;
	struct s_func	*next;
}					t_unc;

extern t_dict	*g_tokens;

t_dict				*envcpy(char **env);
void				ft_putenv(t_dict *env);
char				**dict_to_tab(t_dict *env);
char				*join_with_chr(char *var, char *value, char c);
int					initcmd(t_dict *env, t_cmd *cmd, char **line);
void				put_error(char *path, char *cmd);
void				launch_exec(t_cmd *cmd, t_dict *env, char **env_tab);
void				free_tab(char **tab);
char				**split_parse(char const *s, t_dict *env);
int					ft_setenv(const char *key, const char *value, t_dict *env, int overwrite);
int					ft_unsetenv(const char *key, t_dict *env);
int					is_tokenchr(char c);
char				*is_tokenstr(char *s);
int					init_tokens(t_dict *tokens);
void				env_missing(char *envkey);
int					is_numeric(char *s);
int					start_env(t_dict *env, t_cmd *cmd);
int					start_unsetenv(t_dict *env, t_cmd *cmd);
int					start_setenv(t_dict *env, t_cmd *cmd);
int					start_exit(t_dict *env, t_cmd *cmd);
int					start_cd(t_dict *env, t_cmd *cmd);
void				ft_delsplit(char **split);
void				cmd_free(t_cmd *cmd);
void				sig_handler(int signal);

#endif
