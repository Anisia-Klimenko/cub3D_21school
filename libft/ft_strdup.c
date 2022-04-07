/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:51:04 by trurgot           #+#    #+#             */
/*   Updated: 2021/10/13 15:32:35 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*outp;
	unsigned long	i;

	i = 0;
	while (s1[i])
		i++;
	outp = malloc((i + 1) * sizeof(char));
	if (outp == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		outp[i] = s1[i];
		i++;
	}
	outp[i] = '\0';
	return (outp);
}

/*#include <string.h>
*#include <stdio.h>
*int	main(int argc, char **argv)
*{
*	if (argc > 1)
*	{
*		char	*str1;
*		char	*str2;
*		str1 = strdup(argv[1]);
*		str2 = ft_strdup(argv[1]);
*		printf("strdup \t\tof %s is %s\n", argv[1], str1);
*		printf("ft_strdup \tof %s is %s\n", argv[1], str2);
*		free (str1);
*		free (str2);
*		return (0);
*	}
*}*/
/* call it:
* gcc -Wall -Wextra -Werror ft_strdup.c && ./a.out "School 21" */