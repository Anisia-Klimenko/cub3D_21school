/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acristin <acristin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:02:55 by trurgot           #+#    #+#             */
/*   Updated: 2022/04/06 15:03:01 by acristin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	my_check_border(t_game *game)
{
	unsigned int	i;
	unsigned int	j;

	i = -1;
	while (++i < game->map_hght)
	{
		j = 0;
		while (game->map_components[i][j])
		{
			if (ft_strchr("0NSEW", game->map_components[i][j]))
			{
				if ((i == 0) || (i == game->map_hght - 1) || \
				(j == 0) || (j == ft_strlen(game->map_components[i]) - 1))
				{
					return (my_return_mistake(16));
				}
				if ((game->map_components[i - 1][j] == ' ') || \
	(game->map_components[i + 1][j] == ' ') || (game->map_components[i][j - 1] \
	== ' ') || (game->map_components[i][j + 1] == ' '))
					return (my_return_mistake(16));
			}
			j++;
		}
	}
	return (0);
}

void	set_field_of_view(t_game *game)
{
	game->col_center = (float)game->img_resolution_x / 2;
	game->col_scale = 1 / (tan(M_PI_2 / (game->img_resolution_x)));
}

static void	my_fill_heroe_position(t_game *game, int y, int x)
{
	game->p_pos_x = x + 0.5;
	game->p_pos_y = y + 0.5;
	game->p_angle = M_PI_2 * (ft_strchr("ESWN", game->map_components[y][x]) \
	- "ESWN");
	game->map_components[y][x] = '0';
	__sincos(game->p_angle, &game->p_vect_y, &game->p_vect_x);
	set_field_of_view(game);
}

static int	my_check_chars_and_heroes(t_game *game)
{
	unsigned int	i;
	int				j;
	int				qty_heroes;

	qty_heroes = 0;
	i = -1;
	while (++i < game->map_hght)
	{
		j = -1;
		while (game->map_components[i][++j] != '\0')
		{
			if (!ft_strchr(" 01NSEW", game->map_components[i][j]))
				return (my_return_mistake(4));
			if (ft_strchr("NSEW", game->map_components[i][j]))
			{
				if (qty_heroes > 0)
					return (my_return_mistake(15));
				qty_heroes = 1;
				my_fill_heroe_position(game, i, j);
			}
		}
	}
	return (0);
}

int	my_check_map(t_game *game)
{
	unsigned int	i;
	unsigned int	j;

	game->map_lnght = my_strlen(game->map_components[0]);
	i = -1;
	while (++i < game->map_hght)
	{
		if (game->map_lnght < (unsigned int)my_strlen(game->map_components[i]))
			game->map_lnght = (unsigned int)my_strlen(game->map_components[i]);
	}
	if (my_check_chars_and_heroes(game) || my_check_border(game))
	{
		my_free_map_components(game);
		return (1);
	}
	i = -1;
	while (++i < game->map_hght)
	{
		j = game->map_lnght;
		game->map_components[i][j] = '\0';
		while (game->map_components[i][--j] != '1')
			game->map_components[i][j] = ' ';
	}
	return (0);
}
