/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaaltint@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 18:19:11 by kaaltint          #+#    #+#             */
/*   Updated: 2026/11/07 18:19:12 by kaaltint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	nb;
	int		count;
	int		result;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		result = ft_putchar('-');
		if (result == -1)
			return (-1);
		count++;
		nb = -nb;
	}
	if (nb >= 10)
	{
		result = ft_putnbr(nb / 10);
		if (result == -1)
			return (-1);
		count += result;
	}
	result = ft_putchar((nb % 10) + '0');
	if (result == -1)
		return (-1);
	return (count + result);
}

int	ft_putunbr(unsigned int n)
{
	int	count;
	int	result;

	count = 0;
	if (n >= 10)
	{
		result = ft_putunbr(n / 10);
		if (result == -1)
			return (-1);
		count += result;
	}
	result = ft_putchar((n % 10) + '0');
	if (result == -1)
		return (-1);
	return (count + result);
}
