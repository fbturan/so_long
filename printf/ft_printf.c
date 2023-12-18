/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatturan <fatturan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:23:18 by fatturan          #+#    #+#             */
/*   Updated: 2023/09/27 05:44:32 by fatturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cont(char format)
{
	if (format == 'c' || format == 'd' || format == 'i'
		|| format == 's' || format == 'u' || format == 'p'
		|| format == 'x' || format == 'X' || format == '%')
		return (0);
	return (1);
}

int	format(va_list args, char format)
{
	if (format == 'c')
		return (printchar(va_arg(args, int)));
	else if (format == 'd' || format == 'i')
		return (printnbr(va_arg(args, int), 10));
	else if (format == 's')
		return (printstr(va_arg(args, char *)));
	else if (format == 'p')
	{
		write (1, "0x", 2);
		return (printpointer(va_arg(args, unsigned long)) + 2);
	}
	else if (format == 'u')
		return (printnbr(va_arg(args, unsigned int), 10));
	else if (format == 'X')
		return (printhex(va_arg(args, unsigned int), 16, 1));
	else if (format == '%')
		return (write (1, "%", 1));
	else if (format == 'x')
		return (printhex(va_arg(args, unsigned int), 16, 2));
	return (0);
}

int	ft_printf(const char *ar, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, ar);
	while (*ar)
	{
		if (*ar == '%')
		{
			if (cont(*(ar + 1)) == 1)
			{
				ar++;
				continue ;
			}
			len += format(args, *(ar + 1));
			ar++;
		}
		else
			len += printchar(*ar);
		ar++;
	}
	va_end(args);
	return (len);
}
