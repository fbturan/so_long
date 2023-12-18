/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatturan <fatturan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:39:23 by fatturan          #+#    #+#             */
/*   Updated: 2023/09/27 09:27:31 by fatturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_location(t_game *main, char c, int x, int y)
{
	if (c == 'P')
	{
		main->p_x = x;
		main->p_y = y;
	}
	else if (c == 'C')
	{
		main->c_x = x;
		main->c_y = y;
	}
	else
	{
		main->e_x = x;
		main->e_y = y;
	}
}

void	ft_char_loc(t_game *main, char c, int x, int y)
{
	y = 0;
	while (main->map[y])
	{
		x = 0;
		while (main->map[y][x])
		{
			if (main->map[y][x] == c)
			{
				if (c == 'P')
					ft_location(main, 'P', x, y);
				else if (c == 'E')
					ft_location(main, 'E', x, y);
			}
			x++;
		}
		y++;
	}
}

void	ft_copymap(t_game *main)
{
	int	y;
	int	j;

	y = main->m_y;
	main->copy_map = malloc(sizeof(char *) * (y + 1));
	j = 0;
	while (j < y)
	{
		main->copy_map[j] = malloc(sizeof(char) * main->m_x + 1);
		ft_memset((void *)main->copy_map[j], '0', main->m_x);
		j++;
	}
	main->copy_map[j] = 0;
}

int	ft_nl_count(t_game *main)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	y = 0;
	while (main->map[y])
	{
		x = 0;
		while (main->map[y][x])
		{
			if (main->map[y][x] == '\n')
				count++;
			x++;
		}
		y++;
	}
	return (count + 1);
}

void	ft_free(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
