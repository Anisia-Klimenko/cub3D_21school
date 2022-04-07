/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:57:56 by trurgot           #+#    #+#             */
/*   Updated: 2021/12/27 14:06:39 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_qty_of_words(char const *s, char c)
{
	unsigned long	i;
	int				outp;

	i = 0;
	outp = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			outp++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (outp);
}

static char	**my_free_array(char **outp)
{
	unsigned int	i;

	i = 0;
	while (outp[i])
	{
		free(outp[i]);
		i++;
	}
	free(outp);
	return (NULL);
}

static char	*my_fill_array(char const *str, char c)
{
	char			*outp;
	unsigned int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	outp = malloc(sizeof(char) * (i + 1));
	if (!outp)
	{
		my_free_array(&outp);
		return (NULL);
	}
	i = 0;
	while (str[i] && str[i] != c)
	{
		outp[i] = str[i];
		i++;
	}
	outp[i] = '\0';
	return (outp);
}

static char	**my_split(char **outp, char const *s, char c)
{
	unsigned int	i;

	i = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s && *s != c)
		{
			outp[i] = my_fill_array(s, c);
			if (!outp[i])
				return (NULL);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	outp[i] = NULL;
	return (outp);
}

char	**ft_split(char const *s, char c)
{
	int				qty_words;
	char			**outp;

	if (!s)
		return (NULL);
	qty_words = my_qty_of_words(s, c);
	outp = (char **)malloc((qty_words + 1) * sizeof(char *));
	if (!outp)
		return (NULL);
	return (my_split(outp, s, c));
}

/*#include <stdio.h>
*int	main(void)
*{
*	char	s[400] = "Allocates (with malloc(3)) and returns an array of \
*strings obtained by splitting ’s’ using the character ’c’ as a delimiter. \
*The array must be ended by a NULL pointer.";
*	char	c = 'i';
*	char	**outp;
*	unsigned long	i;
*
*	outp = ft_split(s, c);
*	printf("s1: %s\nc: %c\n", s, c);
*	i = 0;
*	while (outp[i])
*	{
*		printf("outp[%lu]: %s\n", i, outp[i]);
*		i++;
*	}
*	free (outp);
*	return (0);
*}*/
/* Call it: 
* gcc -Wall -Wextra -Werror ft_split.c && ./a.out */