/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:49:53 by trurgot           #+#    #+#             */
/*   Updated: 2021/11/06 22:01:21 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/errno.h>

void	*ft_calloc(size_t count, size_t size)
{
	void			*outp;
	unsigned long	i;
	size_t			mem;

	mem = count * size;
	if (count && size != (mem / count))
	{
		errno = ENOMEM;
		return (NULL);
	}
	outp = malloc(mem);
	if (outp == NULL)
		return (NULL);
	i = 0;
	while (i < mem)
	{
		((unsigned char *)outp)[i] = 0;
		i++;
	}
	return (outp);
}

/*#include <string.h>
**#include <stdio.h>
**int	main(void)
**{
**	char	*str1;
**	char	*str2;
**	unsigned long i1 = 0;
**	unsigned long i2 = 4294967295;
**	unsigned long	i = 0;
**
**	str1 = (char *)calloc(i1, i2);
**	str2 = (char *)ft_calloc(i1, i2);
**	printf("calloc \t\tallocates mamory at %p\n", str1);
**	printf("ft_calloc \tallocates mamory at %p\n", str2);
**	while (i < i1 * i2)
**	if (str1)
**	{
**		printf("element #%lu calloc: %d,   ft_calloc: %d\n", i, str1[i], str2[i]);
**		i++;
**	}
**	free (str1);
**	free (str2);
**	return (0);
**}*/
/* Call it:
* gcc -Wall -Wextra -Werror ft_calloc.c ft_memset.c && ./a.out */