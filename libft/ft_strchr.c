/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:36:43 by trurgot           #+#    #+#             */
/*   Updated: 2021/10/17 09:13:36 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&((char *)s)[i]);
	return (NULL);
}

/*#include <stdio.h>
*int	main(void)
*{
*	char	s[21] = "11223344556677889900";
*	int		c = '5';
*	printf("String: %s\n", s);
*	printf("strchr:\t\tChar %c is placed in address %p\n", (char)c, \
*	strchr(s, c));
*	printf("ft_strchr:\tChar %c is placed in address %p\n", (char)c, \
*	ft_strchr(s, c));
*}*/
/* Call it:
* gcc -Wall -Wextra -Werror ft_strchr.c && ./a.out */