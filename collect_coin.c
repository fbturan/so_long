/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_coin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatturan <fatturan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:39:34 by fatturan          #+#    #+#             */
/*   Updated: 2023/09/27 05:43:24 by fatturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move(t_game *main, int x, int y)
{
	if (main->copy_map[y][x] != '1'
		&& main->map[y][x] != '1')
	{
		main->copy_map[y][x] = '1';
		if (main->map[y][x] == 'U')
			return (1);
		if (ft_move(main, x, y + 1))
			return (1);
		if (ft_move(main, x - 1, y))
			return (1);
		if (ft_move(main, x, y - 1))
			return (1);
		if (ft_move(main, x + 1, y))
			return (1);
	}
	return (0);
}

void	ft_coin(t_game *main)
{
	main->map[main->c_y][main->c_x] = 'U';
	ft_char_loc(main, 'E', main->e_x, main->e_y);
	ft_char_loc(main, 'P', main->p_x, main->p_y);
	main->map[main->e_y][main->e_x] = '1';
	ft_copymap(main);
	main->collected_c += ft_move(main, main->p_x, main->p_y);
	main->map[main->e_y][main->e_x] = 'E';
	main->map[main->c_y][main->c_x] = 'C';
	ft_free(main->copy_map);
}

void	ft_c_loc(t_game *main)
{
	int	c_count;
	int	x;
	int	y;

	c_count = 0;
	y = 0;
	while (main->map[y])
	{
		x = 0;
		while (main->map[y][x])
		{
			if (main->map[y][x] == 'C')
			{
				c_count++;
				ft_location(main, 'C', x, y);
				ft_coin(main);
			}
			x++;
		}
		y++;
	}
	if (!ft_gate(main, c_count))
		ft_str_exit("can not reach to exit!", main);
}

int	ft_gate(t_game *main, int c_count)
{
	if (c_count != main->collected_c)
		ft_str_exit("can not reach to coin!", main);
	main->map[main->e_y][main->e_x] = 'U';
	ft_copymap(main);
	if (ft_move(main, main->p_x, main->p_y))
	{
		main->map[main->e_y][main->e_x] = 'E';
		ft_free(main->copy_map);
		return (1);
	}
	ft_free(main->copy_map);
	return (0);
}

int	ft_close_game(t_mlx *mlx)
{
	mlx_destroy_image(mlx->init, mlx->img->player);
	mlx_destroy_image(mlx->init, mlx->img->coin);
	mlx_destroy_image(mlx->init, mlx->img->wall);
	mlx_destroy_image(mlx->init, mlx->img->ground);
	mlx_destroy_image(mlx->init, mlx->img->exit);
	ft_free(mlx->main->map);
	free(mlx->main);
	mlx_destroy_window(mlx->init, mlx->w);
	exit(1);
}
