/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acristin <acristin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:33:59 by trurgot           #+#    #+#             */
/*   Updated: 2022/04/06 13:25:18 by acristin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	my_return_mistake1(int i)
{
	if (i == 11)
		ft_putstr_fd("Error\nTexture is duplicated\n", 2);
	else if (i == 12)
		ft_putstr_fd("Error\nCannot load textures\nUnknown file's type\
		\nUse .xpm files as textures\n", 2);
	else if (i == 13)
		ft_putstr_fd("Error\nFloor and celling weren't set\nRight format:\
		\nF 220,100,0 and C 225,30,0 where R,G,B - colors in range [0,255]\n", 2);
	else if (i == 14)
		ft_putstr_fd("Error\nTextures weren't set\nRight format:\
		\nNO (SO, WE, EA) ./path_to_the_texture\
		\nUse .xpm files as textures\n", 2);
	else if (i == 15)
		ft_putstr_fd("Error\nStart position is duplicated\n", 2);
	else if (i == 16)
		ft_putstr_fd("Error\nThe map must be closed/surrounded by walls\n", 2);
	return (1);
}

int	my_return_mistake(int i)
{
	if (i == 1)
		ft_putstr_fd("Error\nUse it: ./cub3d MAP_NAME.cub\n", 2);
	else if (i == 2)
		ft_putstr_fd("Error\nThe extension of map must be .cub\n", 2);
	else if (i == 3)
		ft_putstr_fd("Error\nCannot read the map\n", 2);
	else if (i == 4)
		ft_putstr_fd("Error\nMap is not valid\n", 2);
	else if (i == 5)
		ft_putstr_fd("Error\nCannot allocate mamory\n", 2);
	else if (i == 6)
		ft_putstr_fd("Error\nCannot load textures\n", 2);
	else if (i == 7)
		ft_putstr_fd("Error\nFloor or ceilling color is duplicated\n", 2);
	else if (i == 8)
		ft_putstr_fd("Error\nWrong floor or celling format\nRight format: \
		\nF 220,100,0 and C 225,30,0 where R,G,B - colors in range [0,255]\n", 2);
	else if (i == 9)
		ft_putstr_fd("Error\nMap is not exist\n", 2);
	else if (i == 10)
		ft_putstr_fd("Error\nWronr textures format\nRight format:\
		\nNO (SO, WE, EA) ./path_to_the_texture\n", 2);
	return (my_return_mistake1(i));
}

int	my_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] != '\n'))
		i++;
	return (i);
}

static int	my_check_map_extension(const char *map)
{
	char	*tmp;

	tmp = ft_strrchr(map, '.');
	if (!tmp || ft_strcmp(tmp, ".cub"))
		return (my_return_mistake(3));
	return (0);
}

int	main(int argc, char **argv)
{
	int	fd;
	int	err;

	if (argc != 2)
		return (my_return_mistake(1));
	if (my_check_map_extension(argv[1]) == 1)
		return (my_return_mistake(2));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (my_return_mistake(3));
	err = my_cub3d(argv[1], fd);
	close (fd);
	return (err);
}
