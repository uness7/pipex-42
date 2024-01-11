#include "pipex.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t		s_size;
	char		*block;
	int			i;
	const char	*temp;

	s_size = 0;
	temp = s;
	while (*s)
	{
		s_size++;
		s++;
	}
	block = (char *)malloc(s_size + 1);
	if (block == NULL)
		return (NULL);
	i = 0;
	while (temp[i] != '\0')
	{
		block[i] = temp[i];
		i++;
	}
	block[i] = '\0';
	return (block);
}
