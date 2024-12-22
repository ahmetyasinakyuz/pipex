/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakyuz <aakyuz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:49:12 by aakyuz            #+#    #+#             */
/*   Updated: 2024/10/22 23:28:26 by aakyuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int num, int *counter)
{
	if (num == -2147483648)
	{
		ft_putnbr((num / 10), counter);
		ft_putchar('8', counter);
	}
	else if (num < 0)
	{
		ft_putchar('-', counter);
		ft_putnbr(-num, counter);
	}
	else
	{
		if (num > 9)
			ft_putnbr((num / 10), counter);
		ft_putchar(('0' + num % 10), counter);
	}
}
