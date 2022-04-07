/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:24:42 by trurgot           #+#    #+#             */
/*   Updated: 2021/10/04 12:26:00 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/*#include <stdio.h>
*#include <ctype.h>
*int	main(void)
*{
*	int	c = ':';
*	printf("isalpha: \t%d\n", isalpha(c));
*	printf("ft_isalpha: \t%d\n", ft_isalpha(c));
*	return (0);
*}*/
/* Call it:
* gcc -Wall -Wextra -Werror ft_isalpha.c && ./a.out */