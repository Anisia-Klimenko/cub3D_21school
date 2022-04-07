/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblclstsize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 08:59:08 by trurgot           #+#    #+#             */
/*   Updated: 2021/11/30 12:38:18 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dblclstsize(t_dblclst *lst)
{
	t_dblclst	*tmp;
	int			len_lst;

	len_lst = 0;
	if (lst != NULL)
	{
		len_lst = 1;
		if (lst->next != NULL)
		{
			tmp = lst->next;
			while (tmp != lst)
			{
				len_lst++;
				tmp = tmp->next;
			}
		}
	}
	return (len_lst);
}
