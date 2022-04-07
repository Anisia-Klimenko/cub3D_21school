/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblclstinit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 08:21:17 by trurgot           #+#    #+#             */
/*   Updated: 2021/12/17 10:09:22 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dblclst	*ft_dblclstinit(int val)
{
	t_dblclst	*outp;
	int			i;

	outp = (t_dblclst *)malloc(sizeof(t_dblclst));
	if (outp == NULL)
		return (NULL);
	outp->val = val;
	outp->position = 0;
	outp->flag = 0;
	outp->next = outp;
	outp->prev = outp;
	i = 0;
	while (i < 32)
	{
		outp->binar[i] = '0';
		i++;
	}
	outp->binar[i] = '\0';
	return (outp);
}
