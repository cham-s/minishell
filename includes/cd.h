#ifndef CD_H
# define CD_H
# include "minishell.h"
# include "dict.h"
# define CD_OPT			"LP"
# define OPTIN(a, b)	ft_strchr(a, b)			
# define NOTPWD			1

typedef	struct	s_cdflag
{
	int		l;
	int		p;
}				t_cdflag;

extern	t_cdflag g_options;

void			getoptions(int ac, char **av);
int				getdir(int ac, char **av, t_dict *env, char **buffer);
int				ft_cd(int ac, char **av, t_dict *env);
void			initoptions(t_cdflag *options);
void			put_cd_error(int cderrno, char *dir);

#endif
