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

char	*get_next_line(int fd)
{
	static t_stat	bufi[MAX_FD];
	char			*word;
	int				j;

	if (read(fd, (void *)0, 0) != 0 || BUFFER_SIZE <= 0)
		return (NULL);
	word = malloc(1);
	if (!word)
		return (NULL);
	word[0] = '\0';
	word = ft_create_word(&bufi[fd].i, bufi[fd].buf, fd, &j);
	if (!word)
		return (NULL);
	if (j == 0 && bufi[fd].buf[bufi[fd].i] == '\n')
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
