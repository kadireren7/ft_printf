/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaaltint@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 17:54:07 by kaaltint          #+#    #+#             */
/*   Updated: 2026/11/07 18:19:17 by kaaltint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;
	int	count;

	if (!str)
		str = "(null)";
	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_putchar(str[i]) == -1)
			return (-1);
		count++;
		i++;
	}
	return (count);
}
