#ifndef MINISHELL_H
# define MINISHELL_H
# include <sys/types.h>
# include <sys/wait.h>
# include "libft.h"
# define 	T_ENV(node) ((t_env*)node->content)
# define 	T_CMD(node) ((t_cmd*)node->content)
# define	NOFILE			1	
# define	NOEXE			2
# define	NOWR			3
# define	NORD			4
# define	NOACCESS		5
# define	EMPTYPATH		6
# define	INIT_SIZE		30	
# define	MULTIPLAYER		97
# define	GROWTH_FACTOR	2
# define	MAX_LOAD_FACTOR	1

typedef struct		s_elt
{
	char			*key;		
	char			*value;		
	struct s_elt	*next; 
}					t_elt;

typedef struct		s_dict
{
	int				size;
	int				n;
	t_elt			**table;
}					t_dict;

typedef struct	s_cmd
{
	char	**av;
	char	*exepath;
	int		error;
}				t_cmd;

t_dict	*dict_create(void);
void	dict_destroy(t_dict *dict);
void	dict_insert(t_dict *d, const char *key, const char *value);
char	*dict_search(t_dict *d, const char *key);
void	dict_delete(t_dict *d, const char *key);
void	envcpy(char **env, t_list **envlist);
t_env	*get_env(t_list **envlist, char *var);
void	free_env(t_env **envlist);
void	ft_putenv(t_list **env);
char	**list_to_tab(t_list **envlist);
char	*join_with_chr(char *var, char *value, char c);
int		initcmd(t_env *path, t_cmd *cmd, char *line);
int		check_exepath(char *exepath);
void	put_error(int error, char *cmd);
void	launch_exec(t_cmd *cmd, t_list **envlist);
void	free_tab(char **tab);

#endif
