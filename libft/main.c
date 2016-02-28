#include "includes/libft.h"

int main()
{
	char *str;
	char **tab;
	char envcpy;
	str = "salut comment allez vous";
	tab = ft_strsplitspc(str);
	envcpy  = envdup(tab);
	return (0);
}
