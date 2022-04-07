/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:17:20 by trurgot           #+#    #+#             */
/*   Updated: 2021/10/04 13:17:23 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Если цель левее источника, то надо слева направо копировать, */
/* чтоб не перезаписать (не потерять) источник. */
/* Если цель правее источника, то надо справа налево копировать, */
/* чтобы не перезаписать (не потерять) источник. */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;

	if (src < dst)
	{
		while (len--)
		{
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
		}
	}
	else
	{
		i = 0;
		if (!len || dst == src)
			return (dst);
		while (i < (unsigned int) len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}

/*#include <stdio.h>
*int	main(void)
*{
*	char	src[20] = "11111111111111111111";
*	char	dst[21] = "zxcvbnmasdfghjklqwer";
*	char	dsc[21] = "zxcvbnmasdfghjklqwer";
*	int		len = 9;
*
*	printf("memmove:\t%s\n", (char *) memmove(dst, src, len));
*	printf("ft_memmove:\t%s\n", (char *) ft_memmove(dsc, src, len));
*	return (0);
*}*/
/* Call it:
* gcc -Wall -Wextra -Werror ft_memmove.c && ./a.out */