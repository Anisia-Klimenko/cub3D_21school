/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblclstswap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 09:40:08 by trurgot           #+#    #+#             */
/*   Updated: 2022/04/05 18:13:21 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_dblclstswap1(t_dblclst *lst1, t_dblclst *lst2)
{
	t_dblclst	*prev1;
	t_dblclst	*next2;

	prev1 = lst1->prev;
	next2 = lst2->next;
	lst1->next = next2;
	lst1->prev = lst2;
	lst2->next = lst1;
	lst2->prev = prev1;
	next2->prev = lst1;
	prev1->next = lst2;
}

static void	ft_dblclstswap2(t_dblclst *lst1, t_dblclst *lst2)
{
	t_dblclst	*next1;
	t_dblclst	*prev2;

	prev2 = lst2->prev;
	next1 = lst1->next;
	lst1->next = lst2;
	lst1->prev = prev2;
	lst2->next = next1;
	lst2->prev = lst1;
	next1->prev = lst2;
	prev2->next = lst1;
}

static void	ft_dblclstswap3(t_dblclst *lst1, t_dblclst *lst2)
{
	t_dblclst	*prev1;
	t_dblclst	*next1;
	t_dblclst	*prev2;
	t_dblclst	*next2;

	prev1 = lst1->prev;
	prev2 = lst2->prev;
	next1 = lst1->next;
	next2 = lst2->next;
	prev1->next = lst2;
	lst2->next = next1;
	prev2->next = lst1;
	lst1->next = next2;
	lst2->prev = prev1;
	next2->prev = lst1;
	lst1->prev = prev2;
	next1->prev = lst2;
}

t_dblclst	*ft_dblclstswap(t_dblclst *lst1, t_dblclst *lst2, \
		t_dblclst *head)
{
	if (lst1->next->next == lst1)
		head = lst2;
	if (lst1 == head)
		head = lst2;
	if (lst2 == head)
		head = lst1;
	if (lst2 == lst1->next)
		ft_dblclstswap1(lst1, lst2);
	else if (lst1 == lst2->next)
		ft_dblclstswap2(lst1, lst2);
	else
		ft_dblclstswap3(lst1, lst2);
	return (head);
}

void	ft_dblclstswap_head(t_dblclst **lst)
{
	int	tmp;

	if (*lst && *lst != (*lst)->next)
	{
		tmp = (*lst)->val;
		(*lst)->val = (*lst)->next->val;
		(*lst)->next->val = tmp;
	}
}
