/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acristin <acristin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 08:17:21 by trurgot           #+#    #+#             */
/*   Updated: 2022/04/06 15:03:59 by acristin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <errno.h>

# define PI2		6.28318530718

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

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		multiplier;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_column
{
	double			distance;
	unsigned int	height;
	double			texture_pos;
	char			dir;
}	t_column;

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
	t_textur		sprite[12];
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
	int				key[280];
	int				minimap_enable;
	int				minimap_multiplier;
	t_data			empty;
	t_data			wall;
	t_data			collect;
	t_data			door;
	t_data			player;
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
void	my_print__minimap(t_game *game);
int		my_store_imgs(t_game *game);
int		my_strlen(const char *s);
void	my_raycasting(t_game *game);
int		my_return_mistake(int i);
int		mouse_move(int x, int y, t_game *game);
int		my_if_closed_window(int keycode, t_game *game);

#endif
