/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:04:27 by trurgot           #+#    #+#             */
/*   Updated: 2021/10/04 14:04:31 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

/*#include <stdio.h>
*# include <fcntl.h>
*int main(void)
*{
* //int	ft_display_file2(char *file_name)
*	int		fd;
*	char	buffer[20000];
*	int		ifread;
*	char	c = 'H';
*
*	fd = open("test.txt", O_RDWR);
*	if (fd == -1)
*	{
*		printf("Cannot read file.\n");
*		return (3);
*	}
*	ifread = read(fd, buffer, 20000);
*	while (ifread > 0)
*	{
*		printf("%s", buffer);
*		ifread = read(fd, buffer, 20000);
*	}
*	if (ifread == -1)
*	{
*		printf("Cannot read file.\n");
*		return (3);
*	}
*	ft_putchar_fd(c, fd);
*	close(fd);
*	printf("\nc = %c\n", c);
*	fd = open("test.txt", O_RDWR);
*	if (fd == -1)
*	{
*		printf("Cannot read file.\n");
*		return (3);
*	}
*	ifread = read(fd, buffer, 20000);
*	while (ifread > 0)
*	{
*		printf("%s", buffer);
*		ifread = read(fd, buffer, 20000);
*	}
*	if (ifread == -1)
*	{
*		printf("Cannot read file.\n");
*		return (3);
*	}	
*	close(fd);
*	printf("\n");
*	return (0);
*}*/
/* Call it:
* gcc -Wall -Wextra -Werror ft_putchar_fd.c && ./a.out */