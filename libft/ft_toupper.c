/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:31:55 by trurgot           #+#    #+#             */
/*   Updated: 2021/10/04 13:31:58 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/*/#include <stdio.h>
*#include <ctype.h>
*int	main(void)
*{
*	int c = 97;
*	printf("toupper: \t%c\n", (char)toupper(c));
*	printf("ft_toupper: \t%c\n", (char)ft_toupper(c));
*	return (0);
*}*/
/* Call it:
* gcc -Wall -Wextra -Werror ft_toupper.c && ./a.out */