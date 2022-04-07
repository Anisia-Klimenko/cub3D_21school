/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 07:20:47 by trurgot           #+#    #+#             */
/*   Updated: 2021/10/06 07:20:51 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*outp;

	outp = (t_list *)malloc(sizeof(t_list));
	if (outp == NULL)
		return (NULL);
	outp->content = content;
	outp->next = NULL;
	return (outp);
}

/*#include <stdio.h>
*int	main(void)
*{
*	t_list	*list;
*
*	list = ft_lstnew("Hello, word!");
*	printf("list->content = %s\n", (char *)list->content);
*	printf("list->next = %s\n", (char *)list->next);
*	printf("list.content = %s\n", (char *)(*list).content);
*	free(list);
*	return (0);
*}*/
/* call it:
* gcc -Wall -Wextra -Werror ft_lstnew.c && ./a.out */