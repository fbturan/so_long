/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatturan <fatturan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 00:41:58 by fatturan          #+#    #+#             */
/*   Updated: 2023/09/27 09:24:43 by fatturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "./getnextline/get_next_line.h"
# include "./printf/ft_printf.h"
# include "./mlx/mlx.h"

typedef struct s_game
{
	char	**map;
	char	**copy_map;
	int		m_y;
	int		m_x;
	int		c_num;
	int		e_num;
	int		p_num;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		c_x;
	int		c_y;
	int		collected_c;
}				t_game;

typedef struct s_picture
{
	void	*player;
	void	*coin;
	void	*wall;
	void	*ground;
	void	*exit;
	int		x;
	int		y;
}			t_picture;

typedef struct s_mlx
{
	void		*init;
	void		*w;
	int			x;
	int			y;
	int			pixel_x;
	int			pixel_y;
	t_game		*main;
	t_picture	*img;
}			t_mlx;

void	ft_is_wall(t_game *main);
void	ft_is_rectangle(t_game **main);
void	ft_is_char(t_game *main);
void	ft_c_loc(t_game *main);
void	ft_map_x(t_game *main);
void	ft_char_loc(t_game *main, char c, int x, int y);
void	ft_location(t_game *main, char c, int x, int y);
void	ft_copymap(t_game *main);
void	ft_free(char **map);
void	ft_img_init(t_picture *img, t_mlx *mlx);
void	ft_map_to_img(t_game *main, t_mlx *mlx, t_picture *img);
void	ft_init_struct(t_game *main);
void	ft_str_exit(char *str, t_game *main);
void	ft_map_name(t_game *main, char **av);
void	ft_xpm_cont(t_game *main);
void	ft_replace_C(t_game *main);
void	*ft_memset(void *b, int c, int len);
int		ft_map_y(t_game *main, char **av);
int		ft_move(t_game *main, int x, int y);
int		ft_gate(t_game *main, int c_count);
int		ft_nl_count(t_game *main);
int		ft_key_handler(int keycode, t_mlx *mlx);
int		ft_close_game(t_mlx *mlx);

#endif