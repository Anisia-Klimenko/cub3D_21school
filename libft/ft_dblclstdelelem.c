/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblclstdelelem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 09:28:23 by trurgot           #+#    #+#             */
/*   Updated: 2021/12/01 09:04:42 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dblclst	*ft_dblclstdelelem(t_dblclst *lst)
{
	t_dblclst	*prev;
	t_dblclst	*next;

	prev = lst->prev;
	next = lst->next;
	prev->next = lst->next;
	next->prev = lst->prev;
	free(lst);
	return (next);
}
