#include "pipex.h"

void	run_cmd2(t_pipex pipex, char **av, char **envp)
{
	dup2(pipex.fd[0], 0);
	close(pipex.fd[1]);
	dup2(pipex.outfile, 1);
	pipex.cmd_args = ft_split(av[3]);
	pipex.cmd = find_cmd(pipex.cmd_path, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		free_pipex(&pipex);
		ft_puterr(CMD);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
	free_pipex(&pipex);
}
