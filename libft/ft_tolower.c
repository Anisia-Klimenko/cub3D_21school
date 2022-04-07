/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:34:20 by trurgot           #+#    #+#             */
/*   Updated: 2021/10/04 13:34:22 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/*#include <stdio.h>
*#include <ctype.h>
*int	main(void)
*{
*	int c = 69;
*	printf("tolower: \t%c\n", (char)tolower(c));
*	printf("ft_tolower: \t%c\n", (char)ft_tolower(c));
*	return (0);
*}*/
/* Call it:
* gcc -Wall -Wextra -Werror ft_tolower.c && ./a.out */