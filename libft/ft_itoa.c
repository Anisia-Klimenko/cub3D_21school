/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:00:01 by trurgot           #+#    #+#             */
/*   Updated: 2021/10/04 14:00:06 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_len_int(int n)
{
	int		len_int;

	if (n == 0)
		return (1);
	len_int = 0;
	if (n < 0)
	{
		len_int = 1;
		n *= (-1);
	}
	while (n)
	{
		n /= 10;
		len_int++;
	}
	return (len_int);
}

static void	my_fill_str(int sign, int len_int, int n, char *outp)
{
	int		tmp;
	int		i;

	i = 1;
	while (i < len_int)
	{
		tmp = n % 10;
		outp[len_int - i] = tmp + '0';
		i++;
		n = (n / 10);
	}
	if (sign == 0)
	{
		tmp = n % 10;
		outp[0] = tmp + '0';
	}
	outp[len_int] = '\0';
}

char	*ft_itoa(int n)
{
	char	*outp;
	int		len_int;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len_int = my_len_int(n);
	outp = (char *)malloc(sizeof(char) * (len_int + 1));
	if (!outp)
		return (NULL);
	if (n < 0)
	{
		outp[0] = '-';
		n *= (-1);
		my_fill_str(1, len_int, n, outp);
	}
	else
		my_fill_str(0, len_int, n, outp);
	return (outp);
}

/*#include <stdio.h>
*int main(void)
*{
*	char	*outp;
*	int n = -1245;
*	outp = ft_itoa(n);
*	printf ("n \t\t= %d\nft_itoa \t= %s\n", n, outp);
*	free (outp);
*	return (0);
*}*/
/* Call it:
* gcc -Wall -Wextra -Werror ft_itoa.c ft_strdup.c && ./a.out */