/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smana <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:21:35 by smana             #+#    #+#             */
/*   Updated: 2021/11/22 13:21:38 by smana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# define MAX_FD 256

typedef struct s_stat {
	char	buf[BUFFER_SIZE * (2 * (BUFFER_SIZE > 0) - 1) + 1];
	int		i;
}	t_stat;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*ft_create_line(int	*i, char	*buf, char	*word, int	*j);
char	*ft_create_word(int	*i, char *buf, int fd, int *j);

#endif
