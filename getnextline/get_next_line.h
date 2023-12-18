/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatturan <fatturan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:13:50 by fatturan          #+#    #+#             */
/*   Updated: 2023/08/04 15:51:27 by fatturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

# include <stdlib.h>
# include <unistd.h>

char	*ft_until_newline(int fd, char *s);
char	*ft_cut_to_newline(char *s);
char	*ft_next_line(char *s);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s, char *buffer);
int		ft_is_newline(char *s);
int		ft_line_size(char *s);
int		ft_strlen(char *s);

#endif