/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 07:21:51 by trurgot           #+#    #+#             */
/*   Updated: 2021/10/06 07:21:54 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		len_lst;

	len_lst = 0;
	tmp = lst;
	while (tmp)
	{
		len_lst++;
		tmp = tmp->next;
	}
	return (len_lst);
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
*	printf("size = %d\n", ft_lstsize(list));
*	free(list);
*	return (0);
*}*/
/* call it:
* gcc -Wall -Wextra -Werror ft_lstnew.c ft_lstadd_front.c \
* ft_lstsize.c && ./a.out */