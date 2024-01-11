#include "pipex.h"

static void	ft_open_files(t_pipex *pipex, char **av, int ac)
{
	pipex->infile = open(av[1], O_RDONLY);
	if (pipex->infile == -1)
		ft_puterr(INFILE);
	pipex->outfile = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (pipex->outfile == -1)
		ft_puterr(OUTFILE);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	if (ac != 5)
		ft_puterr(ARGS);
	if (pipe(pipex.fd) < 0)
		ft_puterr(PIPE);
	ft_open_files(&pipex, av, ac);
	pipex.paths = find_path(envp);
	pipex.cmd_path = ft_strtok(pipex.paths);
	pipex.id1 = fork();
	if (pipex.id1 == 0)
		run_cmd1(pipex, av, envp);
	pipex.id2 = fork();
	if (pipex.id2 == 0)
		run_cmd2(pipex, av, envp);
	close_pipes(&pipex);
	waitpid(pipex.id1, NULL, 0);
	waitpid(pipex.id2, NULL, 0);
	close_files_fd(&pipex);
	free_pipex_end(&pipex);
	return (0);
}
