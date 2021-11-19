#include "get_next_line.h"
#define BUFFER_SIZE 12

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	static int	i;
	static int	count_lines;
	char		*word;
	char		*word2;
	char		*word3;
	int			j;
	long		count;

	word = malloc(1);
	if (!word)
		return (NULL);
	word[0] = '\0';
	if (buf[i] == '\n')
		i++;
	j = 0;
	while (count_lines == 0 || buf[i] != '\n')
	{
		if (buf[i] == '\0')
		{
			count = read(fd, buf, BUFFER_SIZE);
			if (count <= 0)
			{
				printf("%s", word);
				free(word);
				return ("\n");
			}
			buf[count] = '\0';
			i = 0;
		}
		while (buf[i + j] && buf[i + j] != '\n')
			j++;
		word2 = malloc(j + 1 + (buf[i + j] == '\n'));
		if (!word2)
		{
			free(word);
			return (NULL);
		}
		j = 0;
		while (buf[i] && buf[i] != '\n')
			word2[j++] = buf[i++];
		if (buf[i] == '\n')
		{
			count_lines++;
			word2[j++] = '\n';
		}
		word2[j] = '\0';
		word3 = ft_strjoin(word, word2);
		free(word);
		free(word2);
		word = word3;
	}
	//free(word);
	return (word3);
}

int main()
{
	int fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
}