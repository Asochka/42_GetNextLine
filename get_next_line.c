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

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE * (2 * (BUFFER_SIZE > 0) - 1) + 1];
	static int	i;
	char		*word;
	int			j;

	if (read(fd, (void *)0, 0) != 0 || BUFFER_SIZE <= 0)
		return (NULL);
	word = malloc(1);
	if (!word)
		return (NULL);
	word[0] = '\0';
	word = ft_create_word(&i, buf, fd, &j);
	if (!word)
		return (NULL);
	if (j == 0 && buf[i] == '\n')
	{
		free(word);
		word = malloc(2);
		word[0] = '\n';
		word[1] = '\0';
	}
	if (word[0])
		return (word);
	free(word);
	return (NULL);
}
