/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatturan <fatturan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:50:07 by fatturan          #+#    #+#             */
/*   Updated: 2023/09/27 05:44:20 by fatturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next_line(char *s)
{
	char	*res;
	int		len;
	int		i;

	len = ft_line_size(s);
	if (!s[len])
	{
		free(s);
		return (0);
	}
	res = malloc (sizeof(char) * (ft_strlen(s) - ft_line_size(s)) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s[len])
		res[i++] = s[len++];
	res[i] = '\0';
	free(s);
	return (res);
}

char	*ft_cut_to_newline(char *s)
{
	char	*line;
	int		i;

	if (!ft_line_size(s))
		return (0);
	line = malloc (sizeof (char) * ft_line_size(s) + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_until_newline(int fd, char *s)
{
	char	*buffer;
	int		rd;

	rd = 1;
	buffer = malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_is_newline(s) && rd != 0)
	{
		rd = read (fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free (s);
			free (buffer);
			return (0);
		}
		buffer[rd] = '\0';
		s = ft_strjoin(s, buffer);
	}
	free (buffer);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*dest;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	dest = ft_until_newline(fd, dest);
	if (!dest)
		return (0);
	line = ft_cut_to_newline(dest);
	dest = ft_next_line(dest);
	return (line);
}
