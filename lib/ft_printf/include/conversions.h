/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:51:35 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/06/09 00:54:48 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSIONS_H
# define CONVERSIONS_H

# include "ft_printf.h"

/*ft_putchar*/
int		ft_check_putchar(t_arg elem, char c);
int		ft_check_flags_putchar(t_arg elem, char c, int print);
int		ft_putchar(char c, int print);

/*ft_putstr*/
int		ft_check_putstr(t_arg elem, char *s);
int		ft_check_flags_putstr(t_arg elem, char *s, int print);
int		ft_putstr(const char *s, t_arg elem, int print);

/*ft_putnbr*/
void	ft_check_flags_putnbr2(int *i, t_arg elem, int n, int print);
void	ft_check_flags_putnbr3(int *i, t_arg elem, int n, int print);
int		ft_check_putnbr(t_arg elem, int n);
int		ft_check_flags_putnbr(t_arg elem, int n, int print);
void	ft_putnbr(int n, int *i, int print);

/*ft_putnbr_unsigned*/
int		ft_check_putnbrunsigned(t_arg elem, unsigned int n);
int		ft_check_flags_putnbr_unsigned(t_arg elem, unsigned int n, int print);
void	ft_putnbr_unsigned(unsigned int n, int *i, int print);

/*ft_putpointeur*/
int		ft_check_putpointeur(t_arg elem, void *ptr);
void	ft_check_flags_putpointeur3(int *i, void *ptr, int print, t_arg elem);
void	ft_check_flags_putpointeur2(int *i, void *ptr, int print, t_arg elem);
int		ft_check_flags_putpointeur(t_arg elem, void	*ptr, int print);
void	ft_writepointeur(unsigned long addr, int *i, int print);
int		ft_putpointeur(void	*p, int print);

/*ft_puthexa_maj*/
int		ft_check_puthexa_maj(t_arg elem, unsigned int n);
void	ft_check_puthexa_maj2(int *i, t_arg elem, unsigned int n, int print);
int		ft_check_flags_puthexa_maj(t_arg elem, unsigned int n, int print);
void	ft_puthexa_maj(unsigned int n, int *i, int print);

/*ft_puthexa_min*/
int		ft_check_puthexa_min(t_arg elem, unsigned int n);
void	ft_check_puthexa_min2(int *i, t_arg elem, unsigned int n, int print);
int		ft_check_flags_puthexa_min(t_arg elem, unsigned int n, int print);
void	ft_puthexa_min(unsigned int n, int *i, int print);

#endif
