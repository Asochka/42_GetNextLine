/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smana <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:22:23 by smana             #+#    #+#             */
/*   Updated: 2021/11/22 13:22:25 by smana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

long	reading(int fd, char *buf, int *i)
{
	long	count;

	count = read(fd, buf, BUFFER_SIZE);
	if (count <= 0)
		return (0);
	buf[count] = '\0';
	*i = 0;
	return (count);
}

char	*ft_check(char *word)
{
	if (word[0] == '\0')
	{
		free (word);
		return (NULL);
	}
	else
		return (word);
}

char	*ft_slash_n(char *word)
{
	free(word);
	word = malloc(2);
	word[0] = '\n';
	word[1] = '\0';
	return (word);
}

char	*ft_first_word(char *word)
{
	word = malloc(1);
	if (!word)
		return (NULL);
	word[0] = '\0';
	return (word);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE * (2 * (BUFFER_SIZE > 0) - 1) + 1];
	static int	i;
	char		*word;
	char		*word2;
	long		count;

	if (read(fd, (void *)0, 0) != 0 || BUFFER_SIZE <= 0)
		return (NULL);
	word = NULL;
	word = ft_first_word(word);
	if (buf[i] == '\n' && buf[++(i)] == '\n')
		return (ft_slash_n(word));
	while (buf[i] == '\0' || buf[i] != '\n')
	{
		if (buf[i] == '\0')
		{
			count = reading(fd, buf, &i);
			if (count == 0)
				return (ft_check(word));
		}
		word2 = ft_create_line(&i, buf, word, word2);
		word = ft_strjoin(word, word2);
	}
	return (ft_check(word));
}

int main()
{
	int fd;
	fd = open("test.txt", O_RDONLY);
	char *s = get_next_line(fd);
// 	char *m = get_next_line(fd);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
	free(s);
// 	free(m);
	close(fd);
} 