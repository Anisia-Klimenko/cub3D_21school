/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_minimap_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acristin <acristin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:06:04 by trurgot           #+#    #+#             */
/*   Updated: 2022/04/06 14:44:14 by acristin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	my_print__minimap2(t_game *game, int i, int j)
{
	if (i == (int)game->p_pos_x && j == (int)game->p_pos_y)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->player.img, i * game->minimap_multiplier,
			j * game->minimap_multiplier);
}

void	my_print__minimap(t_game *game)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	while (j < game->map_hght)
	{
		i = 0;
		while (game->map_components[j][i])
		{
			if (game->map_components[j][i] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->wall.img, i * game->minimap_multiplier,
					j * game->minimap_multiplier);
			if (game->map_components[j][i] == '0')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->empty.img, i * game->minimap_multiplier,
					j * game->minimap_multiplier);
			my_print__minimap2(game, i, j);
			i++;
		}
		j++;
	}
}
