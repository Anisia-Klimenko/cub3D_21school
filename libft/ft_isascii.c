/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:33:44 by trurgot           #+#    #+#             */
/*   Updated: 2021/10/04 12:33:49 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/*#include <stdio.h>
*#include <ctype.h>
*int	main(void)
*{
*	int	c = 128;
*	printf("isascii: \t%d\n", isascii(c));
*	printf("ft_isascii: \t%d\n", ft_isascii(c));
*	return (0);
*}*/
/* Call it:
* gcc -Wall -Wextra -Werror ft_isascii.c && ./a.out */