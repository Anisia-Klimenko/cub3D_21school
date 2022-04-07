/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:38:38 by trurgot           #+#    #+#             */
/*   Updated: 2021/10/04 12:38:46 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	while (len >= 1)
	{
		((unsigned char *)b)[len - 1] = (unsigned char)c;
		len--;
	}
	return (b);
}

/*#include <stdio.h>
*int	main(void)
*{
*	char	buf[10000];
*
*	memset(buf, '\0', 100);
*	memset(buf, '1', 20);
*	printf ("%s\n", (char *) buf);
*	ft_memset(buf, '2', 11);
*	printf ("%s\n", (char *) buf);
*	return (0);
*}*/
/* Call it:
* gcc -Wall -Wextra -Werror ft_memset.c && ./a.out  */