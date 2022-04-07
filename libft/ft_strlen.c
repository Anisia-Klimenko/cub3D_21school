/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:36:42 by trurgot           #+#    #+#             */
/*   Updated: 2021/10/04 12:37:12 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	unsigned long	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

/*#include <stdio.h>
*int	main(void)
*{
*	char s[200] = "qwertyuiopasdfg212121hjkl;";
*	printf("strlen:\t\t%lu\n", strlen(s));
*	printf("ft_strlen:\t%zu\n", ft_strlen(s));
*	return (0);
*}*/
/* Call it:
* gcc -Wall -Wextra -Werror ft_strlen.c && ./a.out */