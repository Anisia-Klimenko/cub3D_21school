/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblclstaddback.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 07:31:42 by trurgot           #+#    #+#             */
/*   Updated: 2021/12/27 14:16:34 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dblclst	*ft_dblclstaddback(t_dblclst **lst, t_dblclst **new)
{
	if (*lst != NULL && *new != NULL)
	{
		(*lst)->prev->next = *new;
		(*new)->prev = (*lst)->prev;
		(*lst)->prev = *new;
		(*new)->next = *lst;
	}
	if (*lst == NULL)
		*lst = *new;
	return (*lst);
}
