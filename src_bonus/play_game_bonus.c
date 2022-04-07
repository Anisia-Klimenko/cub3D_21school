/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acristin <acristin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 09:58:15 by trurgot           #+#    #+#             */
/*   Updated: 2022/04/06 14:59:15 by acristin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	step_right_left(int keycode, t_game *game)
{
	if (keycode == 0)
	{
		if (game->map_components[(int)game->p_pos_y][(int)(game->p_pos_x
			+ 0.1 * game->p_vect_x)] == '0')
			game->p_pos_x += 0.1 * game->p_vect_y;
		if (game->map_components[(int)(game->p_pos_y - 0.1
				* game->p_vect_x)][(int)game->p_pos_x] == '0')
			game->p_pos_y -= 0.1 * game->p_vect_x;
	}
	else if (keycode == 2)
	{
		if (game->map_components[(int)game->p_pos_y][(int)(game->p_pos_x
			- 0.1 * game->p_vect_x)] == '0')
			game->p_pos_x -= 0.1 * game->p_vect_y;
		if (game->map_components[(int)(game->p_pos_y + 0.1
				* game->p_vect_x)][(int)game->p_pos_x] == '0')
			game->p_pos_y += 0.1 * game->p_vect_x;
	}
}

static void	my_chose_step(int keycode, t_game *game)
{
	if (keycode == 13)
	{
		if (game->map_components[(int)game->p_pos_y][(int)(game->p_pos_x
			+ 0.1 * game->p_vect_x)] == '0')
			game->p_pos_x += 0.1 * game->p_vect_x;
		if (game->map_components[(int)(game->p_pos_y + 0.1
				* game->p_vect_y)][(int)game->p_pos_x] == '0')
			game->p_pos_y += 0.1 * game->p_vect_y;
	}
	else if (keycode == 1)
	{
		if (game->map_components[(int)game->p_pos_y][(int)(game->p_pos_x
			- 0.1 * game->p_vect_x)] == '0')
			game->p_pos_x -= 0.1 * game->p_vect_x;
		if (game->map_components[(int)(game->p_pos_y - 0.1
				* game->p_vect_x)][(int)game->p_pos_x] == '0')
			game->p_pos_y -= 0.1 * game->p_vect_y;
	}
	else if (keycode == 0 || keycode == 2)
		step_right_left(keycode, game);
}

static void	key_rotate_color(int keycode, t_game *game)
{
	unsigned int	tmp;

	if (keycode == 123)
		game->p_angle -= 0.05;
	if (keycode == 124)
		game->p_angle += 0.05;
	if (keycode == 8 || keycode == 49)
	{
		tmp = game->ceil_color;
		game->ceil_color = game->ceil_color_old;
		game->ceil_color_old = tmp;
		tmp = game->floor_color;
		game->floor_color = game->floor_color_old;
		game->floor_color_old = tmp;
	}
}

static int	key_hook(int keycode, t_game *game)
{
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		my_chose_step(keycode, game);
	if (keycode == 123 || keycode == 124 || keycode == 8 || keycode == 49)
		key_rotate_color(keycode, game);
	if (keycode == 46)
	{
		if (game->minimap_enable == 1)
			game->minimap_enable = 0;
		else
			game->minimap_enable = 1;
	}
	if (keycode == 53)
		exit (0);
	__sincos(game->p_angle, &game->p_vect_y, &game->p_vect_x);
	game->key[keycode] = 1;
	return (0);
}

int	my_play_game(t_game *game)
{
	mlx_hook(game->mlx_win, 2, 1L << 0, key_hook, game);
	mlx_hook(game->mlx_win, 17, 0L, my_if_closed_window, game);
	mlx_hook(game->mlx_win, 6, 1L << 10, mouse_move, game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
	return (0);
}
