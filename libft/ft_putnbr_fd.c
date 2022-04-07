/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:05:45 by trurgot           #+#    #+#             */
/*   Updated: 2021/10/04 14:05:48 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
		write (fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write (fd, "-", 1);
			n *= (-1);
		}
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		else
		{
			c = n + '0';
			write (fd, &c, 1);
		}
	}
}

/*#include <stdio.h>
*# include <fcntl.h>
*int main(void)
*{
* //int	ft_display_file2(char *file_name)
*	int		fd;
*	char	buffer[20000];
*	int		ifread;
*	int		n = -2147483648;
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
*	ft_putnbr_fd(n, fd);
*	close(fd);
*	printf("\nn = %d\n", n);
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
* gcc -Wall -Wextra -Werror ft_putnbr_fd.c && ./a.out */