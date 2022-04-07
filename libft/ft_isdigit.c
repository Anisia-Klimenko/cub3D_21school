/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:31:28 by trurgot           #+#    #+#             */
/*   Updated: 2021/10/04 12:31:32 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/*#include <stdio.h>
*#include <ctype.h>
*int	main(void)
*{
*	int	c = 'p';
*	printf("isdigit: \t%d\n", isdigit(c));
*	printf("ft_isdigit: \t%d\n", ft_isdigit(c));
*	return (0);
*}*/
/* Call it:
* gcc -Wall -Wextra -Werror ft_isdigit.c && ./a.out */