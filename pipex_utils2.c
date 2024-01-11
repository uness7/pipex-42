#include "pipex.h"

void	close_files_fd(t_pipex *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
}

void	close_pipes(t_pipex *pipex)
{
	close(pipex->fd[0]);
	close(pipex->fd[1]);
}

char	*find_path(char **envp)
{
	if (envp == NULL)
		return (NULL);
	while (*envp != NULL)
	{
		if (ft_strncmp("PATH=", *envp, 5) == 0)
			return (*envp + 5);
		envp++;
	}
	return (NULL);
}

char	*find_cmd(char **paths, char *cmd)
{
	char	*command;
	char	*command0;

	while (*paths)
	{
		command0 = ft_strjoin(*paths, "/");
		command = ft_strjoin(command0, cmd);
		free(command0);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*j_str;
	size_t	i;
	size_t	j;

	j_str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!j_str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		j_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		j_str[i] = s2[j];
		i++;
		j++;
	}
	j_str[i] = '\0';
	return (j_str);
}
