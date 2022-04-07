/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_imgs_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acristin <acristin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:29:22 by trurgot           #+#    #+#             */
/*   Updated: 2022/04/06 13:07:01 by acristin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	my_store_imgs2(t_game *game)
{
	int	x;
	int	y;

	game->player.img = mlx_xpm_file_to_image(game->mlx, "pics/player.xpm", &x, \
	&y);
	if (game->player.img == NULL)
		return (errno);
	game->player.addr = mlx_get_data_addr(game->player.img, \
	&game->player.multiplier, &game->player.line_length, \
	&game->player.endian);
	return (0);
}

static int	my_store_imgs1(t_game *game)
{
	int	x;
	int	y;

	game->empty.img = mlx_xpm_file_to_image(game->mlx, "pics/empty.xpm", &x, \
	&y);
	if (game->empty.img == NULL)
		return (errno);
	game->empty.addr = mlx_get_data_addr(game->empty.img, \
	&game->empty.multiplier, &game->empty.line_length, \
	&game->empty.endian);
	game->wall.img = mlx_xpm_file_to_image(game->mlx, "pics/wall.xpm", &x, &y);
	if (game->wall.img == NULL)
		return (errno);
	game->wall.addr = mlx_get_data_addr(game->wall.img, \
	&game->wall.multiplier, &game->wall.line_length, &game->wall.endian);
	return (my_store_imgs2(game));
}

int	my_store_imgs(t_game *game)
{
	int	n;

	errno = 0;
	game->mlx_win = mlx_new_window(game->mlx, game->img_resolution_x, \
	game->img_resolution_y, "cub3D by Attack Cristina & Trifle Urgot");
	if (game->mlx_win == NULL)
		return (errno);
	game->img_ptr = mlx_new_image(game->mlx, game->img_resolution_x, \
	game->img_resolution_y);
	if (game->img_ptr == NULL)
		return (errno);
	game->img_data_addr = (unsigned int *)mlx_get_data_addr(game->img_ptr, \
	&n, &n, &n);
	return (my_store_imgs1(game));
}
