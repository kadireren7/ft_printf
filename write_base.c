/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaaltint@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 18:19:09 by kaaltint          #+#    #+#             */
/*   Updated: 2026/11/07 18:19:19 by kaaltint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putbase(unsigned long n, char *base)
{
	int	count;
	int	result;

	count = 0;
	if (n >= 16)
	{
		result = ft_putbase(n / 16, base);
		if (result == -1)
			return (-1);
		count += result;
	}
	result = ft_putchar(base[n % 16]);
	if (result == -1)
		return (-1);
	return (count + result);
}

int	ft_puthex(unsigned int n, int uppercase)
{
	if (uppercase)
		return (ft_putbase(n, "0123456789ABCDEF"));
	return (ft_putbase(n, "0123456789abcdef"));
}

int	ft_putptr(void *ptr)
{
	int	count;
	int	result;

	if (!ptr)
		return (ft_putstr("(nil)"));
	count = ft_putstr("0x");
	if (count == -1)
		return (-1);
	result = ft_putbase((unsigned long)ptr,
			"0123456789abcdef");
	if (result == -1)
		return (-1);
	return (count + result);
}
