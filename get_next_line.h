/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:25:21 by mmeerber          #+#    #+#             */
/*   Updated: 2023/09/11 13:25:26 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char			*get_next_line(int fd);
char			*ft_strjoin(char *s1, char *buff);
char			*backup(char *content);
char			*ft_strchr(char *s, int c);
size_t			ft_strlen(char *s);

#endif
