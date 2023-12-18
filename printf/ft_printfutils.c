/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatturan <fatturan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:15:33 by fatturan          #+#    #+#             */
/*   Updated: 2023/09/27 05:44:41 by fatturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	printstr(char *s)
{
	int	len;

	len = 0;
	if (!s)
		s = "(null)";
	while (*s)
		len += printchar(*s++);
	return (len);
}

int	printnbr(long int nbr, int base)
{
	int		len;
	char	*basestr;

	basestr = "0123456789";
	len = 0;
	if (nbr < 0)
	{
		len += printchar('-');
		nbr *= -1;
	}
	if (nbr >= 10)
		len += printnbr(nbr / base, base);
	len += write(1, &basestr[nbr % base], 1);
	return (len);
}

int	printhex(unsigned int nbr, int base, int b)
{
	int		len;
	char	*basestr;
	char	*basestr2;

	basestr = "0123456789ABCDEF";
	basestr2 = "0123456789abcdef";
	len = 0;
	if (nbr >= 16)
		len += printhex(nbr / base, base, b);
	if (b == 1)
		len += write(1, &basestr[nbr % base], 1);
	else
		len += write(1, &basestr2[nbr % base], 1);
	return (len);
}

int	printpointer(unsigned long p)
{
	char	*basestr;
	int		len;

	len = 0;
	basestr = "0123456789abcdef";
	if (p >= 16)
		len += printpointer (p / 16);
	len += write(1, &basestr[p % 16], 1);
	return (len);
}
