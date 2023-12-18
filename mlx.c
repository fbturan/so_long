/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatturan <fatturan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 05:32:58 by fatturan          #+#    #+#             */
/*   Updated: 2023/09/27 10:20:25 by fatturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_shift(t_mlx *mlx, int x, int y)
{
	static int	footstep = 1;

	if (mlx->main->collected_c == 0 && mlx->main->map[y][x] == 'E')
	{
		mlx->main->map[mlx->main->p_y][mlx->main->p_x] = '0';
		mlx->main->map[y][x] = 'P';
		mlx->main->p_y = y;
		mlx->main->p_x = x;
		ft_printf("Move Count:%d\n", footstep);
		footstep++;
		ft_str_exit("game finish:)", mlx->main);
	}
	else if (mlx->main->map[y][x] != '1' && mlx->main->map[y][x] != 'E')
	{
		if (mlx->main->map[y][x] == 'C')
			mlx->main->collected_c -= 1;
		mlx->main->map[mlx->main->p_y][mlx->main->p_x] = '0';
		mlx->main->map[y][x] = 'P';
		mlx->main->p_y = y;
		mlx->main->p_x = x;
		ft_printf("Move Count: %d\n", footstep);
		footstep++;
	}
}

int	ft_key_handler(int keycode, t_mlx *mlx)
{
	if (keycode == 2)
		ft_shift(mlx, mlx->main->p_x + 1, mlx->main->p_y);
	else if (keycode == 13)
		ft_shift(mlx, mlx->main->p_x, mlx->main->p_y - 1);
	else if (keycode == 0)
		ft_shift(mlx, mlx->main->p_x - 1, mlx->main->p_y);
	else if (keycode == 1)
		ft_shift(mlx, mlx->main->p_x, mlx->main->p_y + 1);
	else if (keycode == 53)
		ft_close_game(mlx);
	ft_map_to_img(mlx->main, mlx, mlx->img);
	return (keycode);
}

void	ft_img_send(t_mlx *mlx, t_picture *img, char c)
{
	if (c == 'C')
		mlx_put_image_to_window(mlx->init, mlx->w, img->coin, mlx->pixel_x,
			mlx->pixel_y);
	else if (c == 'E')
		mlx_put_image_to_window(mlx->init, mlx->w, img->exit, mlx->pixel_x,
			mlx->pixel_y);
	else if (c == '0')
		mlx_put_image_to_window(mlx->init, mlx->w, img->ground, mlx->pixel_x,
			mlx->pixel_y);
	else if (c == '1')
		mlx_put_image_to_window(mlx->init, mlx->w, img->wall, mlx->pixel_x,
			mlx->pixel_y);
	else if (c == 'P')
		mlx_put_image_to_window(mlx->init, mlx->w, img->player, mlx->pixel_x,
			mlx->pixel_y);
}

void	ft_map_to_img(t_game *main, t_mlx *mlx, t_picture *img)
{
	int	x;
	int	y;

	mlx->pixel_y = 0;
	y = -1;
	while (main->map[++y])
	{
		x = -1;
		mlx->pixel_x = 0;
		while (main->map[y][++x])
		{
			ft_img_send(mlx, img, main->map[y][x]);
			mlx->pixel_x += 64;
		}
		mlx->pixel_y += 64;
	}
}

void	ft_img_init(t_picture *img, t_mlx *mlx)
{
	img->player = mlx_xpm_file_to_image(mlx->init, "./textures/p.xpm", &img->x,
			&img->y);
	img->coin = mlx_xpm_file_to_image(mlx->init, "./textures/c.xpm", &img->x,
			&img->y);
	img->ground = mlx_xpm_file_to_image(mlx->init, "./textures/g.xpm", &img->x,
			&img->y);
	img->wall = mlx_xpm_file_to_image(mlx->init, "./textures/w.xpm", &img->x,
			&img->y);
	img->exit = mlx_xpm_file_to_image(mlx->init, "./textures/e.xpm", &img->x,
			&img->y);
}
