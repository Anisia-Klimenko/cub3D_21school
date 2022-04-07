/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:32:17 by trurgot           #+#    #+#             */
/*   Updated: 2021/10/04 12:32:20 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || \
		(c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/*#include <stdio.h>
*#include <ctype.h>
*int	main(void)
*{
*	int	c = '{';
*	printf("isalnum: \t%d\n", isalnum(c));
*	printf("ft_isalnum: \t%d\n", ft_isalnum(c));
*	return (0);
*}*/
/* Call it:
* gcc -Wall -Wextra -Werror ft_isalnum.c && ./a.out */