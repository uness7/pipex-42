#include "pipex.h"

static int	ft_count_words(char *s)
{
	int	i;
	int	in_word;
	int	count;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] <= 32)
			in_word = 0;
		else if (!in_word)
		{
			count++;
			in_word = 1;
		}
		i++;
	}
	return (count);
}

static char	**ft_extract_words(char *s, char **res, int start, int temp)
{
	int	i;
	int	k;
	int	count;

	i = 0;
	count = ft_count_words(s);
	k = -1;
	while (++k < count)
	{
		while (s[i] <= 32)
			i++;
		start = i;
		while (s[i] > 32)
			i++;
		res[k] = malloc(sizeof(char) * ((i - start) + 1));
		if (!res[k])
			return (NULL);
		temp = -1;
		while (++temp < (i - start))
			res[k][temp] = s[start + temp];
		res[k][temp] = '\0';
	}
	res[count] = NULL;
	return (res);
}

char	**ft_split(char *s)
{
	int		start;
	int		temp;
	int		count;
	char	**result;

	start = 0;
	temp = 0;
	count = ft_count_words(s);
	result = malloc(sizeof(char *) * (count + 1));
	if (result == NULL)
		return (NULL);
	return (ft_extract_words(s, result, start, temp));
}
