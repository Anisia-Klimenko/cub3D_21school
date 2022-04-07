/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:40:00 by trurgot           #+#    #+#             */
/*   Updated: 2022/03/31 10:16:10 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_free_map_components(t_game *game)
{
	unsigned int	hght_tmp;

	hght_tmp = -1;
	while (++hght_tmp < game->map_hght)
	{
		if (game->map_components[hght_tmp])
			free(game->map_components[hght_tmp]);
	}
	if (game->map_components)
		free (game->map_components);
}

int	my_free_map_components2(t_game *game)
{
	unsigned int	hght_tmp;

	hght_tmp = -1;
	while (++hght_tmp < game->map_hght)
	{
		if (game->map_components[hght_tmp])
			free(game->map_components[hght_tmp]);
	}
	if (game->map_components)
		free (game->map_components);
	if (game->column)
		free (game->column);
	ft_putstr_fd("Error\nCannot allocate mamory\n", 2);
	return (1);
}
