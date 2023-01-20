/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 09:35:25 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/02/16 09:35:33 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		denouement(int type, t_printf modifier, va_list ap)
{
	if (type == 0)
		return (handler_char(modifier, va_arg(ap, int)));
	else if (type == 1)
		return (handler_string(modifier, va_arg(ap, char*)));
	else if (type == 2)
		return (handler_i_u_x_p(modifier, \
			long_dec_to_hex_string(va_arg(ap, long unsigned)), 1));
	else if (type == 3 || type == 4)
		return (handler_i_u_x_p(modifier, int_to_string(va_arg(ap, int)), 0));
	else if (type == 5)
		return (handler_i_u_x_p(modifier, \
			unsigned_to_string(va_arg(ap, unsigned)), 0));
	else if (type == 6)
		return (handler_i_u_x_p(modifier, \
			dec_to_hex_string(va_arg(ap, unsigned), 1), 0));
	else if (type == 7)
		return (handler_i_u_x_p(modifier, \
			dec_to_hex_string(va_arg(ap, unsigned), 0), 0));
	else
	{
		modifier.accuracy_true = 0;
		return (handler_i_u_x_p(modifier, ft_strdup("%"), 0));
	}
}

int		search_specifier(char **argv, va_list ap)
{
	char	*specifier;
	char	*start_argv;
	int		i;
	int		size;

	specifier = ft_strdup("cspdiuxX%%");
	(*argv)++;
	start_argv = *argv;
	while (**argv)
	{
		i = -1;
		while (specifier[++i])
			if (specifier[i] == **argv)
			{
				size = denouement(i, \
					parse_modifier(start_argv, specifier[i], ap), ap);
				free(specifier);
				return (size);
			}
		(*argv)++;
	}
	free(specifier);
	return (0);
}

int		ft_printf(const	char *argv, ...)
{
	char	*argv_e;
	int		size;
	va_list	ap;

	argv_e = (char*)argv;
	va_start(ap, argv);
	size = 0;
	while (*argv_e)
	{
		if (*argv_e == '%')
		{
			size += search_specifier(&argv_e, ap);
		}
		else
		{
			ft_putchar_fd(*argv_e, 1);
			size++;
		}
		if (!*argv_e)
			break ;
		argv_e++;
	}
	va_end(ap);
	return (size);
}
