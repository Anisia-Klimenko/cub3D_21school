/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:21:16 by trurgot           #+#    #+#             */
/*   Updated: 2022/01/11 08:13:37 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*my_fill_str(int fd, char str[MAX_FD + 1][MAX_LEN_STR])
{
	char			*buf;
	int				qty_bytes;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	qty_bytes = 1;
	while (qty_bytes != 0 && !ft_strchr(str[fd], '\n'))
	{
		qty_bytes = read(fd, buf, BUFFER_SIZE);
		if (qty_bytes == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[qty_bytes] = '\0';
		ft_strcat(str[fd], buf);
	}
	free (buf);
	return (str[fd]);
}

static unsigned int	my_calc_len(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

static char	*my_fill_outp(char *outp, char *src, unsigned int len_outp)
{
	unsigned int	i;

	i = 0;
	while (i < len_outp)
	{
		outp[i] = src[i];
		i++;
	}
	outp[i] = '\0';
	ft_strcpy(src, &(src[i]));
	return (outp);
}

char	*get_next_line(int fd)
{
	static char		str[MAX_FD + 1][MAX_LEN_STR];
	char			*outp;
	unsigned int	len_outp;

	if ((fd < 0) || (fd >= MAX_FD) || (BUFFER_SIZE <= 0))
		return (NULL);
	my_fill_str(fd, str);
	if (!str[fd])
		return (NULL);
	len_outp = my_calc_len(str[fd]);
	outp = (char *)malloc(sizeof(char) * (len_outp + 1));
	if (!outp)
		return (NULL);
	my_fill_outp(outp, str[fd], len_outp);
	if (outp[0] == '\0')
	{
		free (outp);
		return (NULL);
	}
	return (outp);
}
