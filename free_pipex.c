#include "pipex.h"

void	free_pipex(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_args[i++])
		free(pipex->cmd_args[i]);
	free(pipex->cmd_args);
	free(pipex->cmd);
}

void	free_pipex_end(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_path[i])
	{
		free(pipex->cmd_path[i]);
		i++;
	}
	free(pipex->cmd_path);
}
