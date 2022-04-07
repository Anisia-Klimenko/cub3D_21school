/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:35:07 by trurgot           #+#    #+#             */
/*   Updated: 2021/10/04 12:35:10 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

/*#include <stdio.h>
*#include <ctype.h>
*int	main(void)
*{
*	int	c = 127;
*	printf("isprint: \t%d\n", isprint(c));
*	printf("ft_isprint: \t%d\n", ft_isprint(c));
*	return (0);
*}*/
/* Call it:
* gcc -Wall -Wextra -Werror ft_isprint.c && ./a.out */