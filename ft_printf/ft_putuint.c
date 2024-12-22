/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakyuz <aakyuz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:49:30 by aakyuz            #+#    #+#             */
/*   Updated: 2024/10/22 23:28:40 by aakyuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putuint(unsigned int num, int *counter)
{
	if (num > 9)
		ft_putnbr((num / 10), counter);
	ft_putchar(('0' + num % 10), counter);
}
