/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatturan <fatturan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:38:27 by fatturan          #+#    #+#             */
/*   Updated: 2023/09/27 09:35:47 by fatturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_x(t_game *main)
{
	int	line_len;

	line_len = 0;
	while (main->map[0][line_len] && main->map[0][line_len] != '\n')
		line_len++;
	main->m_x = line_len;
}

int	ft_map_y(t_game *main, char **av)
{
	int		map_fd;
	int		res;
	char	*buff;

	res = 0;
	map_fd = open(av[1], O_RDONLY);
	while (1)
	{
		buff = get_next_line(map_fd);
		if (buff)
		{
			res++;
			free(buff);
		}
		else
			break ;
	}
	main->m_y = res;
	close(map_fd);
	return (res);
}

static void	ft_map_cont(t_game *main)
{
	ft_is_rectangle(&main);
	ft_is_wall(main);
	ft_is_char(main);
	ft_c_loc(main);
	ft_xpm_cont(main);
}

void	ft_read_map(t_game **main, char **av)
{
	int		map_fd;
	int		i;
	char	**tmp;
	int		line;

	line = ft_map_y(*main, av);
	map_fd = open(av[1], O_RDONLY);
	if (map_fd < 0)
		ft_str_exit("map file error!", *main);
	tmp = malloc(sizeof(char *) * line + 1);
	i = 0;
	while (1)
	{
		tmp[i] = get_next_line(map_fd);
		if (!tmp[i])
			break ;
		i++;
	}
	close (map_fd);
	(*main)->map = tmp;
	if (ft_nl_count(*main) != line)
		ft_str_exit("newline at the end of the map file!", *main);
	ft_map_cont(*main);
}

int	main(int ac, char **av)
{
	t_game		*main;
	t_mlx		mlx;
	t_picture	img;

	if (ac != 2)
		exit(1);
	main = malloc(sizeof(t_game));
	main->map = NULL;
	ft_map_name(main, av);
	ft_read_map(&main, av);
	mlx.init = mlx_init();
	mlx.w = mlx_new_window(mlx.init, main->m_x * 64, main->m_y * 64, "so_long");
	ft_img_init(&img, &mlx);
	ft_map_to_img(main, &mlx, &img);
	mlx.main = main;
	mlx.img = &img;
	mlx_hook(mlx.w, 2, (1L << 0), ft_key_handler, &mlx);
	mlx_hook(mlx.w, 17, 0L, ft_close_game, &mlx);
	mlx_loop(mlx.init);
}
