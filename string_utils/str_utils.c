#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>


char *ft_strjoin_all(char **av,int ac)
{
  char *str;
  char *tmp;
  int i = 0;
	str  = NULL;
  while(i < ac)
  {
	tmp = ft_strjoin(str," ");
	free(str);
	str = ft_strjoin(tmp,av[i]);
	free(tmp);
	i++;
  }
    return str;
}
