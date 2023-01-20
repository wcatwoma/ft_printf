/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 09:36:03 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/02/16 09:36:10 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		check_flags(t_flags *flags, char ch)
{
	if (ch == '+')
		flags->plus = 1;
	else if (ch == '-')
		flags->minus = 1;
	else if (ch == ' ')
		flags->space = 1;
	else if (ch == '#')
		flags->lattice = 1;
	else if (ch == '0')
		flags->zero = 1;
}

void		check_widht_accuracy(int *value, int *minus, char **str, va_list ap)
{
	*value = **str == '*' ? va_arg(ap, int) : ft_atoi(*str);
	if (*value < 0 && minus)
	{
		*minus = 1;
		*value *= -1;
	}
	while (ft_isdigit(*(*str + 1)))
		(*str)++;
}

int			check_accuracy(char **str, t_printf *mdfr, va_list ap)
{
	(*str)++;
	mdfr->accuracy_true = 1;
	check_widht_accuracy(&(mdfr->accuracy), NULL, str, ap);
	if (mdfr->accuracy < 0)
		mdfr->accuracy_true = 0;
	return (2);
}

void		new_elem(t_printf *modifier)
{
	modifier->accuracy = 0;
	modifier->widht = 0;
	modifier->percent = 0;
	modifier->accuracy_true = 0;
	modifier->widht_true = 0;
	modifier->flags.lattice = 0;
	modifier->flags.minus = 0;
	modifier->flags.plus = 0;
	modifier->flags.space = 0;
	modifier->flags.zero = 0;
}

t_printf	parse_modifier(char *str, char end, va_list ap)
{
	t_printf	modifier;
	int			flag;

	flag = 0;
	new_elem(&modifier);
	while (*str != end)
	{
		if (flag < 1)
			check_flags(&modifier.flags, *str);
		if (((*str >= '1' && *str <= '9') || *str == '*') && flag < 2)
		{
			modifier.widht_true = 1;
			check_widht_accuracy(&modifier.widht, \
				&modifier.flags.minus, &str, ap);
			flag = 1;
		}
		if (*str == '.' && flag < 3)
			flag = check_accuracy(&str, &modifier, ap);
		if (*str != end)
			str++;
	}
	return (modifier);
}
