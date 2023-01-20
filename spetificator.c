/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spetificator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 09:34:53 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/02/16 09:35:02 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*handler_widht(t_printf mdfr, int size, char *res)
{
	char	*str;
	char	*kost;
	int		widht;

	widht = mdfr.widht - size;
	str = ft_calloc(widht + 1, sizeof(char));
	str = ft_memset(str, mdfr.flags.zero && (mdfr.flags.zero + mdfr.flags.minus
	+ mdfr.accuracy_true == 1) ? '0' : ' ', widht);
	if (*res == '-' && *str == '0')
	{
		str = ft_strjoin(ft_strdup("-"), str);
		kost = res;
		res = ft_substr(res, 1, ft_strlen(res));
		free(kost);
	}
	res = mdfr.flags.minus ?
		ft_strjoin(res, str) : ft_strjoin(str, res);
	return (res);
}

char	*handler_accuracy(int accuracy, int *size, char *res)
{
	int		widht;
	char	*kost;
	char	*str;

	widht = accuracy - *size;
	str = ft_memset(ft_calloc(widht + 1, sizeof(char)), '0', widht);
	if (*res == '-')
	{
		str = ft_strjoin(ft_strdup("-0"), str);
		kost = res;
		res = ft_substr(res, 1, ft_strlen(res));
		free(kost);
		widht += 1;
	}
	res = ft_strjoin(str, res);
	*size += widht;
	return (res);
}

int		handler_string(t_printf mdfr, char *res)
{
	int		size;
	char	*str;

	if (!(res = ft_strdup(res)))
		res = ft_strdup("(null)");
	size = ft_strlen(res);
	if (mdfr.accuracy < size && mdfr.accuracy_true)
	{
		str = res;
		res = ft_substr(res, 0, mdfr.accuracy);
		free(str);
		size = mdfr.accuracy;
	}
	if (mdfr.widht > size && mdfr.widht_true)
		res = handler_widht(mdfr, size, res);
	ft_putstr_fd(res, 1);
	size = ft_strlen(res);
	free(res);
	return (size);
}

int		handler_char(t_printf mdfr, char ch)
{
	char	*res;
	int		size;

	size = ch < 30 ? 1 : 0;
	if (ch < 30)
		res = ft_strdup("");
	else
		res = ft_memset(ft_calloc(2, sizeof(char)), ch, 1);
	if (1 < mdfr.widht && mdfr.widht_true)
		res = handler_widht(mdfr, 1, res);
	size += ft_strlen(res);
	if (!mdfr.flags.minus)
		ft_putstr_fd(res, 1);
	if (ch < 30)
		ft_putchar_fd(ch, 1);
	if (mdfr.flags.minus)
		ft_putstr_fd(res, 1);
	free(res);
	return (size);
}

int		handler_i_u_x_p(t_printf mdfr, char *res, int p_true)
{
	char	*kost;
	int		size;

	if (mdfr.accuracy == 0 && mdfr.accuracy_true && *res == '0')
	{
		kost = res;
		res = ft_strdup("");
		free(kost);
	}
	size = ft_strlen(res);
	if ((size < mdfr.accuracy || (size < mdfr.accuracy + 1 && *res == '-'))\
			&& mdfr.accuracy_true)
		res = handler_accuracy(mdfr.accuracy, &size, res);
	if (p_true)
	{
		res = ft_strjoin(ft_strdup("0x"), res);
		size += 2;
	}
	if (size < mdfr.widht && mdfr.widht_true)
		res = handler_widht(mdfr, size, res);
	ft_putstr_fd(res, 1);
	size = ft_strlen(res);
	free(res);
	return (size);
}
