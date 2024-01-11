#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>

# define MAX_STRING_LENGTH 100

typedef struct s_command
{
	char	*command;
	char	*args;
}			t_command;

typedef struct s_pipex
{
	pid_t	id1;
	pid_t	id2;
	int		infile;
	int		outfile;
	int		fd[2];
	char	*paths;
	char	**cmd_path;
	char	**cmd_args;
	char	*cmd;
}			t_pipex;

typedef struct s_obj
{
	int		i;
	int		k;
	int		temp;
	int		start;
	int		word_len;
	int		count_words;
	char	**res;
}		t_obj;

# define INFILE "The infile doesn't exist\n"
# define ARGS "Too few or too many arguments!\n"
# define PIPE "Something is wrong with pipe :(\n"
# define CMD "One of commands entered are not valid\n"
# define OUTFILE "Something is wrong with outfile\n"

char		*find_path(char **envp);
char		*find_cmd(char **paths, char *cmd);
void		run_cmd1(t_pipex pipex, char **av, char **envp);
void		run_cmd2(t_pipex pipex, char **av, char **envp);
int			count_words(char *s);
int			ft_strncmp(char *s1, char *s2, unsigned int n);
char		**ft_split(char *s);
char		**ft_strtok(char *s);
char		*ft_strdup(const char *s);
size_t		ft_strlen(char *s);
char		*ft_strjoin(char *s1, char *s2);
void		close_pipes(t_pipex *pipex);
void		close_files_fd(t_pipex *pipex);
void		ft_puterr(char *error);
void		free_pipex(t_pipex *pipex);
void		free_pipex_end(t_pipex *pipex);
void		extract_command(char *input, t_command command);

#endif
