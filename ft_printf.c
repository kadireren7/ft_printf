/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaaltint@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 18:19:22 by kaaltint          #+#    #+#             */
/*   Updated: 2026/11/07 19:59:37 by kaaltint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	if (c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	if (c == '%')
		return (ft_putchar('%'));
	return (-1);
}

static int	ft_print_format(const char *format, va_list args)
{
	int		i;
	int		count;
	int		result;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			result = ft_format(format[++i], args);
		else
			result = ft_putchar(format[i]);
		if (result == -1)
			return (-1);
		count += result;
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	count = ft_print_format(format, args);
	va_end(args);
	return (count);
}
