/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:18:54 by trurgot           #+#    #+#             */
/*   Updated: 2021/10/19 17:29:28 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, \
						size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
	i = 0;
	while (src[i])
		i++;
	return (i);
}

/*#include <stdio.h>
*int main(void)
*{
*	char	dst[21] = "11111111111111111111";
*	char	dst1[21] = "11111111111111111111";
*	char	src[21] = "22222222222222222222";
*	int		dstsize = 20;
*	printf ("strlcpy:\tsize = %lu dst = \t%s\n", \
*				strlcpy(dst, src, dstsize), dst);
*	printf ("ft_strlcpy:\tsize = %zu dst1 = \t%s\n", \
*				ft_strlcpy(dst1, src, dstsize), dst1);
*	return (0);
*}*/
/* Call it:
* gcc -Wall -Wextra -Werror ft_strlcpy.c && ./a.out */