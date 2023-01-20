/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 08:17:12 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/02/16 09:31:30 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_atoi(const char *str)
{
	unsigned long	res;
	int				sign;

	res = 0;
	sign = 1;
	while (*str == '\t' || *str == '\f' || *str == '\n'
				|| *str == ' ' || *str == '\r' || *str == '\v')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str++ - '0');
		if (res > 9223372036854775807 && sign == -1)
			return (0);
		if (res > 9223372036854775807 && sign == 1)
			return (-1);
	}
	return ((int)res * sign);
}

void	*ft_calloc(size_t num, size_t size)
{
	char	*new;
	size_t	max;

	max = (size_t)~0;
	if ((num && max / num < size) ||
		(size && max / size < num))
		return (NULL);
	num *= size;
	new = malloc(num);
	if (new == NULL)
		return (NULL);
	while (num--)
		*((char*)new + num) = 0;
	return (new);
}

int		ft_isdigit(int ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char*)b;
	while (len-- > 0)
		*(ptr++) = (unsigned char)c;
	return (b);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
