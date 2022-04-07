/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acristin <acristin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:33:59 by trurgot           #+#    #+#             */
/*   Updated: 2022/04/06 14:53:23 by acristin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	my_store_imgs(t_game *game)
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
	return (0);
}

static void	init_game(t_game *game)
{
	int	i;

	game->ceil_color = 16777216;
	game->ceil_color_old = 8778996;
	game->floor_color = 16777216;
	game->floor_color_old = 9578022;
	game->map_hght = 0;
	game->map_h_tmp = 0;
	game->img_resolution_x = 2400;
	game->img_resolution_y = 1200;
	i = -1;
	while (++i < 5)
		game->textur[i].ptr = NULL;
}

static void	init_alloc_game(t_game *game)
{
	game->mlx = mlx_init();
	game->column = malloc(sizeof(t_column) * game->img_resolution_x);
	if ((game->mlx == NULL) || !game->column)
	{
		ft_putstr_fd("Error\nCannot allocate mamory\n", 2);
		exit (errno);
	}
}

int	my_cub3d(const char *map, int fd)
{
	t_game	game;
	int		err;

	init_game(&game);
	init_alloc_game(&game);
	if (pars_map(&game, map, fd))
		exit (1);
	err = my_store_imgs(&game);
	if (err)
	{
		ft_putstr_fd("Error\nCannot load textures\n", 2);
		exit (err);
	}
	err = my_play_game(&game);
	my_free_map_components(&game);
	free (game.column);
	exit (err);
	return (0);
}
