/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakyuz <aakyuz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:48:40 by aakyuz            #+#    #+#             */
/*   Updated: 2024/10/22 23:29:20 by aakyuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_format(va_list va, char *str, int *counter)
{
	if (*str == 'c')
		ft_putchar(va_arg(va, int), counter);
	else if (*str == 's')
		ft_putstr(va_arg(va, char *), counter);
	else if (*str == 'p')
		ft_putptr(va_arg(va, void *), counter);
	else if (*str == 'i' || *str == 'd')
		ft_putnbr(va_arg(va, int), counter);
	else if (*str == 'u')
		ft_putuint(va_arg(va, unsigned int), counter);
	else if (*str == 'x' || *str == 'X')
	{
		if (*str == 'x')
			ft_puthex(va_arg(va, unsigned int), counter, "0123456789abcdef");
		else
			ft_puthex(va_arg(va, unsigned int), counter, "0123456789ABCDEF");
	}
	else if (*str == '%')
		ft_putchar(*str, counter);
}

int	ft_printf(char const *str, ...)
{
	va_list		va;
	int			counter;

	if (!str)
		return (0);
	counter = 0;
	va_start(va, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_format(va, (char *)str, &counter);
		}
		else
			ft_putchar(*str, &counter);
		str++;
	}
	va_end(va);
	return (counter);
}
