/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_textures1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acristin <acristin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:31:58 by trurgot           #+#    #+#             */
/*   Updated: 2022/04/06 12:57:55 by acristin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	pars_textures1_1(t_game *game, char *line, int sign)
{
	unsigned int	len;
	int				i;
	char			*tmp;

	tmp = line;
	len = ft_strlen(line);
	if (len < 5)
		return (my_return_mistake(12));
	tmp[len - 1] = '\0';
	if (ft_memcmp(".xpm", tmp + len - 5, 4) == 0)
		game->textur[sign].ptr = mlx_xpm_file_to_image(game->mlx, line, \
		(int *)&game->textur[sign].width, (int *)&game->textur[sign].height);
	else
		return (my_return_mistake(12));
	if (game->textur[sign].ptr == NULL)
		return (my_return_mistake(6));
	game->textur[sign].data_addr = \
	(unsigned int *)mlx_get_data_addr(game->textur[sign].ptr, &i, &i, &i);
	game->textur[sign].aspect_ratio = game->textur[sign].width / \
	game->textur[sign].height;
	return (0);
}

int	pars_textures1(t_game *game, char *line)
{
	int	sign;

	if (line[0] == 'N' && line[1] == 'O')
		sign = 0;
	else if (line[0] == 'S' && line[1] == 'O')
		sign = 1;
	else if (line[0] == 'E' && line[1] == 'A')
		sign = 2;
	else if (line[0] == 'W' && line[1] == 'E')
		sign = 3;
	else
		return (my_return_mistake(10));
	if (game->textur[sign].ptr != NULL)
		return (my_return_mistake(11));
	if (line[2] != ' ')
		return (my_return_mistake(10));
	line += 2;
	while (*line && *line == ' ')
		line++;
	return (pars_textures1_1(game, line, sign));
}
