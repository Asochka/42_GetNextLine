/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smana <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:22:12 by smana             #+#    #+#             */
/*   Updated: 2021/11/22 13:22:16 by smana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	newstr = (char *)malloc((len + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	while (s1 && s1[j] != '\0')
		newstr[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
	free(s1);
	free(s2);
	return (newstr);
}

char	*ft_create_line(int	*i, char *buf, char	*word, char *word2)
{
	int		j;

	j = 0;
	while (buf[*i + j] && buf[*i + j] != '\n')
		j++;
	word2 = (char *)malloc(sizeof(char) * (j + 1 + (buf[*i + j] == '\n')));
	if (!word2)
	{
		free(word);
		return (NULL);
	}
	j = 0;
	while (buf[*i] && buf[*i] != '\n')
		word2[j++] = buf[(*i)++];
	if (buf[*i] == '\n')
		word2[j++] = '\n';
	word2[j] = '\0';
	return (word2);
}
