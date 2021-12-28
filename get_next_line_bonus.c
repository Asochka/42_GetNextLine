/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smana <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:21:43 by smana             #+#    #+#             */
/*   Updated: 2021/11/22 13:21:46 by smana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static t_stat	bufi[MAX_FD];
	char		*word;
	char		*word2;
	long		count;

	if (read(fd, (void *)0, 0) != 0 || BUFFER_SIZE <= 0)
		return (NULL);
	word = NULL;
	word = ft_first_word(word);
	if (bufi[fd].buf[bufi[fd].i] == '\n' && (bufi[fd].buf[++bufi[fd].i]) == '\n')
		return (ft_slash_n(word));
	while (bufi[fd].buf[bufi[fd].i] == '\0' || bufi[fd].buf[bufi[fd].i] != '\n')
	{
		if (bufi[fd].buf[bufi[fd].i] == '\0')
		{
			count = reading(fd, bufi[fd].buf, &bufi[fd].i);
			if (count == 0)
				return (ft_check(word));
		}
		word2 = ft_create_line(&bufi[fd].i, bufi[fd].buf, word, word2);
		word = ft_strjoin(word, word2);
	}
	return (ft_check(word));
}

// int main()
// {
// 	int fd;
// 	fd = open("test.txt", O_RDONLY);
// 	char *s = get_next_line(fd);
// 	// char *m = get_next_line(fd);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	free(s);
// 	// free(m);
// 	close(fd);
// } 