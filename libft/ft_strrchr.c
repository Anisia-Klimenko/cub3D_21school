/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:38:40 by trurgot           #+#    #+#             */
/*   Updated: 2021/10/04 13:38:49 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		tmp;
	char	*outp;

	i = 0;
	tmp = -1;
	outp = (char *)s;
	while (outp[i])
	{
		if (outp[i] == (char) c)
		{
			tmp = i;
		}
		i++;
	}
	if ((char) c == '\0')
		tmp = i;
	if (tmp == -1)
		return (NULL);
	else
		return (&outp[tmp]);
}

/*#include <stdio.h>
*int	main(void)
*{
*	// Массив со строкой для поиска
*	char str[11]="0163456769";
*	// Код искомого символа
*	int ch = '6';
*	char *outp;
*
*	printf ("str %s\n", str);
*	printf ("ch %c\n", ch);
*	outp = strrchr(str, ch);
*	if (outp == NULL)
*	   printf ("Символ в строке не найден\n");
*	else
*	{
*	   printf ("strrchr: outp %s\n",outp);
*	   printf ("strrchr: outp - str %ld\n",outp-str);
*	   printf ("strrchr: Искомый символ на позиции # %ld\n", outp-str+1);
*	}
*	outp = ft_strrchr(str, ch);
*	if (outp == NULL)
*	   printf ("Символ в строке не найден\n");
*	else
*	{
*	   printf ("ft_strrchr: outp %s\n",outp);
*	   printf ("ft_strrchr: outp - str %ld\n",outp-str);
*	   printf ("ft_strrchr: Искомый символ на позиции # %ld\n", outp-str+1);
*	}
*   return 0;
*}*/
/* Call it:
* gcc -Wall -Wextra -Werror ft_strrchr.c && ./a.out */