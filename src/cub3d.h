/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:04:01 by trurgot           #+#    #+#             */
/*   Updated: 2022/01/15 16:47:17 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <errno.h>

typedef struct s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}	t_rgb;

typedef struct s_textur
{
	void			*ptr;
	unsigned int	*data_addr;
	double			aspect_ratio;
	unsigned int	width;
	unsigned int	height;
}	t_textur;

typedef struct s_dtype
{
	double	x;
	double	y;
}	t_dtype;

# define PI2		6.28318530718

typedef struct s_column
{
	double			distance;
	unsigned int	height;
	double			texture_pos;
	char			dir;
}				t_column;

typedef struct s_game
{
	unsigned int	map_lnght;
	unsigned int	map_hght;
	unsigned int	map_h_tmp;
	char			**map_components;
	unsigned int	ceil_color;
	unsigned int	floor_color;
	unsigned int	ceil_color_old;
	unsigned int	floor_color_old;
	t_rgb			rgb;
	t_textur		textur[4];
	void			*img_ptr;
	unsigned int	*img_data_addr;
	unsigned int	img_resolution_x;
	unsigned int	img_resolution_y;
	double			p_pos_x;
	double			p_pos_y;
	double			p_angle;
	double			p_vect_x;
	double			p_vect_y;
	float			col_center;
	double			col_scale;
	t_column		*column;
	void			*mlx;
	void			*mlx_win;
}	t_game;

int		my_check_map(t_game *game);
int		my_cub3d(const char *map, int fd);
void	my_free_map_components(t_game *game);
int		my_free_map_components2(t_game *game);
int		game_loop(t_game *game);
int		pars_map(t_game *game, const char *map, int fd);
int		pars_textures1(t_game *game, char *line);
int		pars_textures2(t_game *game, char *line, char c);
int		my_play_game(t_game *game);
int		my_strlen(const char *s);
void	my_raycasting(t_game *game);
int		my_return_mistake(int i);

#endif
