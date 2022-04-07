/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acristin <acristin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 08:02:11 by trurgot           #+#    #+#             */
/*   Updated: 2022/04/06 14:49:39 by acristin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	pars_textures(t_game *game, int fd, char **line)
{
	int		result;
	char	*tmp;

	result = 0;
	tmp = get_next_line(fd);
	*line = ft_strtrim(tmp, " ");
	free (tmp);
	while ((*line) != NULL)
	{
		if (**line == 'N' || **line == 'S' || **line == 'E' || **line == 'W')
			result = pars_textures1(game, *line);
		else if (**line == 'C' || **line == 'F')
			result = pars_textures2(game, *line, **line);
		else if (**line != '\0' && (**line == '1' || **line == ' '
				|| **line == '2'))
			return (0);
		free(*line);
		if (result)
			return (1);
		*line = get_next_line(fd);
		game->map_h_tmp++;
	}
	if ((*line) == NULL)
		return (my_return_mistake(9));
	return (0);
}

static int	is_settings_valid(t_game *game)
{
	int	i;

	if (game->floor_color > 16777215 || game->ceil_color > 16777215)
		return (my_return_mistake(13));
	i = -1;
	while (++i < 4)
	{
		if (game->textur[i].ptr == NULL)
			return (my_return_mistake(14));
	}
	return (0);
}

static unsigned int	my_calc_lines(t_game *game, const char *map)
{
	unsigned int	result;
	int				fd;
	char			*tmp;

	result = 1;
	fd = open (map, O_RDONLY);
	if (fd == -1)
		return (my_return_mistake(3));
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		result++;
		free(tmp);
		tmp = get_next_line(fd);
		if (result > game->map_h_tmp && tmp != (void *)0)
			game->map_hght++;
	}
	close (fd);
	return (result);
}

int	pars_map(t_game *game, const char *map, int fd)
{
	char			*line;
	unsigned int	i;

	if ((pars_textures(game, fd, &line)) || (is_settings_valid(game)))
		return (1);
	if (my_calc_lines(game, map) < 3)
		return (1);
	game->map_components = (char **)malloc(sizeof (char *) * game->map_hght);
	if (!game->map_components)
		return (my_return_mistake(5));
	i = -1;
	while (++i < (game->map_hght))
	{
		game->map_components[i] = malloc(1000);
		if (game->map_components[i] == NULL)
			return (my_free_map_components2(game));
		ft_memcpy(game->map_components[i], line, ft_strlen(line));
		game->map_components[i][ft_strlen(line) - 1] = '\0';
		free(line);
		line = get_next_line(fd);
	}
	return (my_check_map(game));
}
