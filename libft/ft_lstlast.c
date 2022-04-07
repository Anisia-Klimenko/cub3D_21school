/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 07:16:55 by trurgot           #+#    #+#             */
/*   Updated: 2021/10/06 07:16:59 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (lst)
	{
		tmp = lst;
		while (tmp->next)
			tmp = tmp->next;
		return (tmp);
	}
	return (NULL);
}

/*#include <stdio.h>
*int	main(void)
*{
*	t_list	*list;
*	t_list	*tmp;
*
*	list = ft_lstnew("аптека");
*	tmp = ft_lstnew("фонарь, ");
*	ft_lstadd_front(&list, tmp);
*	tmp = ft_lstnew("улица, ");
*	ft_lstadd_front(&list, tmp);
*	tmp = ft_lstnew("Ночь, ");
*	ft_lstadd_front(&list, tmp);
*	tmp = list;
*	while (tmp)
*	{
*		printf("%s\n", (char *)tmp->content);
*		tmp = tmp->next;
*	}
*	tmp = ft_lstlast(list);
*	printf("The last element of the list = %s\n", (char *)tmp->content);
*	free(list);
*	return (0);
*}*/
/* call it:
* gcc -Wall -Wextra -Werror ft_lstnew.c ft_lstadd_front.c \
* ft_lstlast.c && ./a.out */