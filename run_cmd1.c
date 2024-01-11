#include "pipex.h"

void	run_cmd1(t_pipex pipex, char **av, char **envp)
{
	dup2(pipex.fd[1], 1);
	close(pipex.fd[0]);
	dup2(pipex.infile, 0);
	pipex.cmd_args = ft_split(av[2]);
	pipex.cmd = find_cmd(pipex.cmd_path, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		free_pipex(&pipex);
		ft_puterr(CMD);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
	free_pipex_end(&pipex);
}
