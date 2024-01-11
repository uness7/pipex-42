#include "pipex.h"

void	ft_puterr(char *error)
{
	perror(error);
	exit(EXIT_FAILURE);
}
