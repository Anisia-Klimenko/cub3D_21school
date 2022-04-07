/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:00:47 by trurgot           #+#    #+#             */
/*   Updated: 2021/10/04 14:00:52 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*outp;
	unsigned long	len_s;

	if (!s)
		return (NULL);
	len_s = 0;
	while (s[len_s])
		len_s++;
	outp = (char *)malloc(sizeof(char) * (len_s + 1));
	if (!outp)
		return (NULL);
	outp[len_s] = '\0';
	while (len_s > 0)
	{
		outp[len_s - 1] = f(len_s - 1, s[len_s - 1]);
		len_s--;
	}
	return (outp);
}

/*#include <stdio.h>
*char	my_ft_toupper(unsigned int i, char c)
*{
*	if (c >= 'a' && c <= 'z')
*		c -= i;
*	return (c);
*}
*int	main(void)
*{
*	char	s[200] = "Applies the function ’f’ to each character of the \
*string ’s’ to create a new string (with malloc(3)) resulting from \
*successive applications of ’f’.";
*	char	*outp;
*
*	outp = ft_strmapi(s, &my_ft_toupper);
*	printf ("ORIGINAL:\t%s\nft_strmapi:\t%s\n", s, outp);
*	free (outp);
*	return (0);
*}*/
/* Call it:
* gcc -Wall -Wextra -Werror ft_strmapi.c && ./a.out */