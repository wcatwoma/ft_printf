/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 09:36:52 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/02/16 09:36:54 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

typedef struct		s_flags
{
	int				plus;
	int				minus;
	int				space;
	int				lattice;
	int				zero;
}					t_flags;

typedef struct		s_printf
{
	t_flags			flags;
	int				widht;
	int				accuracy;
	int				percent;
	int				widht_true;
	int				accuracy_true;
}					t_printf;

int					ft_printf(const char *str, ...);
t_printf			parse_modifier(char *str, char end, va_list ap);
int					handler_char(t_printf mdfr, char res);
int					handler_i_u_x_p(t_printf mdfr, char *res, int p_true);
int					handler_string(t_printf mdfr, char *str);
char				*handler(t_printf mdfr, int size, char *res);
char				*unsigned_to_string(unsigned n);
char				*int_to_string(int n);
char				*dec_to_hex_string(unsigned number, int type);
char				*long_dec_to_hex_string(long unsigned number);
void				*ft_calloc(size_t num, size_t size);
int					ft_atoi(const char *str);
int					ft_isdigit(int ch);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
char				*ft_strdup(char const *s);
char				*ft_strjoin(char const *s1, char const *s);
int					ft_strlen(char *str);
char				*ft_substr(char const *s, unsigned int start, size_t len);

#endif
