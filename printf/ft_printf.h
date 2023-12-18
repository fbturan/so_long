/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatturan <fa.betulturan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 00:13:14 by fatturan          #+#    #+#             */
/*   Updated: 2023/07/22 15:09:28 by fatturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	printchar(char c);
int	printstr(char *s);
int	printnbr(long int nbr, int base);
int	printhex(unsigned int nbr, int base, int b);
int	printpointer(unsigned long p);
int	format(va_list args, char format);
int	cont(char format);
int	ft_printf(const char *ar, ...);

#endif