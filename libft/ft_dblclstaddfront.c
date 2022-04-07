/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblclstaddfront.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 07:31:42 by trurgot           #+#    #+#             */
/*   Updated: 2021/12/27 14:20:46 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dblclst	*ft_dblclstaddfront(t_dblclst **lst, t_dblclst **new)
{
	if (*lst != NULL && *new != NULL)
	{
		(*lst)->prev->next = *new;
		(*new)->prev = (*lst)->prev;
		(*lst)->prev = *new;
		(*new)->next = *lst;
	}
	if (*new != NULL)
		*lst = *new;
	return (*lst);
}
