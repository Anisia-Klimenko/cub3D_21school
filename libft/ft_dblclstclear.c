/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblclstclear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:06:22 by trurgot           #+#    #+#             */
/*   Updated: 2021/12/08 13:20:23 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_fct(t_dblclst *lst)
{
	lst->val = 0;
	lst->next = NULL;
	lst->prev = NULL;
	free (lst);
}

void	ft_dblclstclear(t_dblclst **lst)
{
	t_dblclst	*tmp;
	t_dblclst	*tmp2;

	if (*lst)
	{
		tmp = *lst;
		while (tmp->next)
		{
			tmp2 = tmp->next;
			tmp->next = NULL;
			free_fct (tmp);
			tmp = tmp2;
		}
		free_fct (tmp);
		*lst = NULL;
	}
}
