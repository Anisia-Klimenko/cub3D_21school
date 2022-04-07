/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 07:19:47 by trurgot           #+#    #+#             */
/*   Updated: 2021/10/19 17:24:40 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void	*), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*outp;	

	outp = 0;
	if (!lst)
		return (NULL);
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&outp, del);
			lst = 0;
			return (NULL);
		}
		else
			ft_lstadd_back(&outp, tmp);
		lst = lst->next;
	}
	return (outp);
}
