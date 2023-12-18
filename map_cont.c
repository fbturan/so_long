/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cont.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatturan <fatturan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:39:03 by fatturan          #+#    #+#             */
/*   Updated: 2023/09/27 09:26:40 by fatturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_is_rectangle(t_game **main)
{
	int	x;
	int	y;

	ft_map_x(*main);
	y = 0;
	while ((*main)->map[y])
	{
		x = 0;
		while ((*main)->map[y][x] && (*main)->map[y][x] != '\n')
			x++;
		if (x != (*main)->m_x)
			ft_str_exit("map is not rectangle!", *main);
		y++;
	}
}

static int	ft_strchr2(char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '\n')
			continue ;
		else if (s[i] != (char)c)
			return (1);
	}
	return (0);
}

void	ft_is_wall(t_game *main)
{
	int	y;

	y = 0;
	while (main->map[y])
	{
		if (y == 0 || y == main->m_y - 1)
		{
			if (ft_strchr2(main->map[y], '1'))
				ft_str_exit("map is not surrounded by walls", main);
		}
		else
		{
			if (main->map[y][0] != '1' || main->map[y][main->m_x - 1] != '1')
				ft_str_exit("map is not surrounded by walls", main);
		}
		y++;
	}
}

static void	ft_char_count(t_game *main, char cc)
{
	if (cc == 'P')
		main->p_num++;
	else if (cc == 'E')
		main->e_num++;
	else if (cc == 'C')
		main->c_num++;
}

void	ft_is_char(t_game *main)
{
	int	x;
	int	y;

	y = 0;
	while (main->map[y])
	{
		x = 0;
		while (main->map[y][x])
		{
			if (main->map[y][x] == 'P' || main->map[y][x] == 'E'
				|| main->map[y][x] == 'C' || main->map[y][x] == '0'
				|| main->map[y][x] == '1' || main->map[y][x] == '\n')
			{
				ft_char_count(main, main->map[y][x]);
				x++;
				continue ;
			}
			ft_str_exit("map contains invalid characters!", main);
		}
		y++;
	}
	if (main->p_num != 1 || main->e_num != 1 || main->c_num == 0)
		ft_str_exit("invalid character count!", main);
}
