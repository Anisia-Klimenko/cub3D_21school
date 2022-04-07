/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:47:33 by trurgot           #+#    #+#             */
/*   Updated: 2021/11/09 09:43:13 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_numlen(const char *s)
{
	size_t	len;

	len = 0;
	while (ft_isdigit(*s))
	{
		len++;
		s++;
	}
	return (len);
}

static int	my_if_overlong(const char *str)
{
	int		sgn;
	size_t	len;

	sgn = -1;
	if (*str == '-')
		sgn = 0;
	if (*str == '+' || *str == '-')
		str++;
	len = my_numlen(str);
	if (len > 19)
		return (sgn);
	if (sgn == -1 && len == 19 && \
		ft_strncmp(str, "9223372036854775807", 19) > 0)
		return (sgn);
	if (sgn == 0 && len == 19 && ft_strncmp(str, "9223372036854775808", 19) > 0)
		return (sgn);
	return (1);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					minus;
	unsigned long long	outp;

	while (*str && (*str == '\n' || *str == '\t' || *str == '\v' || \
		*str == '\r' || *str == '\f' || *str == 32))
		str++;
	minus = my_if_overlong(str);
	if (minus != 1)
		return (minus);
	i = 0;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	outp = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		outp = outp * 10 + str[i] - '0';
		i++;
	}
	return ((int)outp * minus);
}

/*
**#include <stdio.h>
**#include <stdlib.h>
**int main(void)
**{
**	//char	s[100] = "  \t\n\r\v\f   -9223372036854775807kjknhjygbmngh45";
**	char	s[100] = "  \t\n\r\v\f   -2147483649kjknhjygbmngh45";
**	printf("atoi: \t\t%d\n", atoi(s));
**	printf("ft_atoi:\t%d\n", ft_atoi(s));
**	return (0);
**}
*/
/* Call it:
* gcc -Wall -Wextra -Werror ft_atoi.c ft_strncmp.c ft_isdigit.c  && ./a.out */