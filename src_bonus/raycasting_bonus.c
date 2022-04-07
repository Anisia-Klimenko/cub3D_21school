/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acristin <acristin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 07:13:34 by trurgot           #+#    #+#             */
/*   Updated: 2022/04/06 14:57:38 by acristin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static t_dtype	ray_intersect_x(t_game *game, t_dtype step)
{
	t_dtype	check;

	check.x = (int)game->p_pos_x + (step.x > 0) - (step.x < 0);
	if (step.x > 0)
		check.y = game->p_pos_y + step.y * \
								(1 - (game->p_pos_x - (int)game->p_pos_x));
	else
		check.y = game->p_pos_y + step.y * (game->p_pos_x - (int)game->p_pos_x);
	while ((unsigned)check.y < game->map_hght && \
			(unsigned)check.x < game->map_lnght && \
			game->map_components[(unsigned)check.y][(unsigned)check.x] != '1')
		check = (t_dtype){check.x + step.x, check.y + step.y};
	check.x += (step.x < 0);
	return (check);
}

static t_dtype	ray_intersect_y(t_game *game, t_dtype step)
{
	t_dtype	check;

	check.y = (int)game->p_pos_y + (step.y > 0) - (step.y < 0);
	if (step.y > 0)
		check.x = game->p_pos_x + step.x * \
								(1 - (game->p_pos_y - (int)game->p_pos_y));
	else
		check.x = game->p_pos_x + step.x * (game->p_pos_y - (int)game->p_pos_y);
	while ((unsigned)check.y < game->map_hght && \
			(unsigned)check.x < game->map_lnght && \
			game->map_components[(unsigned)check.y][(unsigned)check.x] != '1')
		check = (t_dtype){check.x + step.x, check.y + step.y};
	check.y += (step.y < 0);
	return (check);
}

static void	ray_intersect(t_game *game, double angle, unsigned int ray)
{
	const int		stx = 1 - 2 * !(angle <= M_PI_2 || angle > 3 * M_PI_2);
	const int		sty = 1 - 2 * (angle > M_PI);
	const t_dtype	x1 = ray_intersect_x(game, \
	(t_dtype){stx, stx * tan(angle)});
	const t_dtype	y1 = ray_intersect_y(game, \
	(t_dtype){sty / tan(angle), sty});
	const t_dtype	distance = {game->p_vect_x * (x1.x - game->p_pos_x) + \
								game->p_vect_y * (x1.y - game->p_pos_y),
		game->p_vect_x * (y1.x - game->p_pos_x) + \
								game->p_vect_y * (y1.y - game->p_pos_y)};

	if (distance.x < distance.y)
		game->column[ray] = (t_column){distance.x, \
		game->col_scale / distance.x, \
		x1.y - (int)x1.y, "EW"[x1.x < game->p_pos_x]};
	else
		game->column[ray] = (t_column){distance.y, \
		game->col_scale / distance.y, \
		y1.x - (int)y1.x, "SN"[y1.y < game->p_pos_y]};
	if (game->column[ray].dir == 'W' || game->column[ray].dir == 'S')
		game->column[ray].texture_pos = 1. - game->column[ray].texture_pos;
}

void	my_raycasting(t_game *game)
{
	unsigned int	ray;
	double			angle;

	ray = -1;
	while (++ray < game->img_resolution_x)
	{
		angle = game->p_angle + atan(ray / game->col_center - 1);
		if (angle < 0)
			angle += PI2;
		else if (angle > PI2)
			angle -= PI2;
		ray_intersect(game, angle, ray);
	}
}
