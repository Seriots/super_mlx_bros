/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 22:50:48 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/06/08 22:51:37 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>

# include <stdarg.h>
# define BASE_HEXA_MIN "0123456789abcdef"
# define BASE_HEXA_MAJ "0123456789ABCDEF"
# define FLAG_BASE "0 +-#"
# define ATTRIBUT_BASE "cspdiuxX%"

typedef struct s_arg
{
	int		f_zero;
	int		f_space;
	int		f_plus;
	int		f_minus;
	int		f_hashtag;
	int		min_champs;
	int		precision;
	int		precision_detected;
	char	attribut;
}			t_arg;

/*ft_printf*/
int		ft_printf(const char *s, ...);

/*ft_printf_components*/
int		ft_check_parse(t_arg element, va_list ap, int *i, const char *s);
int		ft_printfwork(va_list ap, const char *s);
t_arg	ft_parse(const char *s, int *position);
int		ft_printf_args(t_arg element, va_list ap);

/*ft_printf_utils*/
int		ft_is_base(char c, char *base);
t_arg	ft_convert_flags(int flags[5], t_arg elem0);
void	ft_setzero(int flags[5]);
int		ft_abs(int n);
void	ft_init(t_arg *elem);

/*ft_printf_utils2.h*/
int		ft_print_minchamps(t_arg elem);
int		ft_print_precision(t_arg elem);

#endif
