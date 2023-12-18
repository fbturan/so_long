/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatturan <fatturan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 05:30:16 by fatturan          #+#    #+#             */
/*   Updated: 2023/09/27 10:36:18 by fatturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_struct(t_game *main)
{
	main->m_y = 0;
	main->m_x = 0;
	main->c_num = 0;
	main->e_num = 0;
	main->p_num = 0;
	main->p_x = 0;
	main->p_y = 0;
	main->e_x = 0;
	main->e_y = 0;
	main->c_x = 0;
	main->c_y = 0;
	main->collected_c = 0;
}

void	*ft_memset(void *b, int c, int len)
{
	int				i;
	unsigned char	*a;

	a = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		a[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	ft_str_exit(char *str, t_game *main)
{
	ft_printf("%s", str);
	ft_free(main->map);
	free(main);
	system("leaks so_long");
	exit(1);
}

void	ft_map_name(t_game *main, char **av)
{
	int	i;

	i = 0;
	while (av[1][i])
		i++;
	if (av[1][i - 1] != 'r' || av[1][i - 2] != 'e' || av[1][i - 3] != 'b'
		|| av[1][i - 4] != '.' || i < 5)
	{
		ft_printf("invalid map name!");
		free(main);
		system("leaks so_long");
		exit(1);
	}
	ft_init_struct(main);
}

void	ft_xpm_cont(t_game *main)
{
	int	fd;

	fd = open("./textures/p.xpm", O_RDONLY);
	if (fd < 0)
		ft_str_exit("xpm file error!", main);
	close(fd);
	fd = open("./textures/c.xpm", O_RDONLY);
	if (fd < 0)
		ft_str_exit("xpm file error!", main);
	close(fd);
	fd = open("./textures/w.xpm", O_RDONLY);
	if (fd < 0)
		ft_str_exit("xpm file error!", main);
	close(fd);
	fd = open("./textures/g.xpm", O_RDONLY);
	if (fd < 0)
		ft_str_exit("xpm file error!", main);
	close(fd);
	fd = open("./textures/e.xpm", O_RDONLY);
	if (fd < 0)
		ft_str_exit("xpm file error!", main);
	close(fd);
}
