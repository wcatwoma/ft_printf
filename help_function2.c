/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_function2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 09:02:11 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/02/16 09:03:22 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		ft_putchar_fd(*s++, fd);
}

char	*ft_strdup(char const *s)
{
	int		i;
	char	*new;

	i = -1;
	if (!s)
		return (NULL);
	new = (char*)malloc(sizeof(char) * (ft_strlen((char*)s) + 1));
	if (!new)
		return (NULL);
	while (*(s + ++i))
		*(new + i) = *(s + i);
	*(new + i) = '\0';
	return (new);
}

char	*ft_strjoin(char const *s1, char const *s)
{
	int		i;
	int		k;
	char	*new;

	if (!s1 || !s)
		return (NULL);
	i = -1;
	k = -1;
	new = (char*)malloc(sizeof(char) *
	(ft_strlen((char*)s1) + ft_strlen((char*)s) + 1));
	if (!new)
		return (NULL);
	while (*(s1 + ++i))
		*(new + i) = *(s1 + i);
	while (*(s + ++k))
		*(new + i + k) = *(s + k);
	*(new + i + k) = '\0';
	free((char*)s1);
	free((char*)s);
	return (new);
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	size;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	size = ft_strlen((char*)s);
	if (start > size)
		return (ft_strdup(""));
	if ((size - start) < len)
		len = size - start;
	new = (char*)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (i < len)
	{
		*(new + i) = *(s + start + i);
		i++;
	}
	*(new + len) = '\0';
	return (new);
}
