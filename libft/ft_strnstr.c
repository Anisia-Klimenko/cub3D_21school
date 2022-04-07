/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:46:12 by trurgot           #+#    #+#             */
/*   Updated: 2021/10/04 13:46:16 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;
	char	*outp;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (i < (int)len && haystack[i])
	{
		if (haystack[i] == needle [0])
		{
			outp = &((char *)haystack)[i];
			j = 0;
			while (haystack[i + j] && needle[j] && haystack[i + j] == needle[j])
				j++;
			if (needle[j] == '\0' && (i + j) <= (int)len)
				return (outp);
		}
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
*int main(void)
*{
*	char *p;
*	char	haystack[200] = "this is tesatablished a test, is a second test";
*	char	needle[200] = "tes";
*	size_t i = 11;
*	p = strnstr(haystack, needle, i);
*	printf("strnstr:\t%s\n", p);
*	p = ft_strnstr(haystack, needle, i);
*	printf("ft_strnstr:\t%s\n", p);
*	return 0;
*}*/
/* Call it:
* gcc -Wall -Wextra -Werror ft_strnstr.c && ./a.out */