/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakyuz <aakyuz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:49:06 by aakyuz            #+#    #+#             */
/*   Updated: 2024/10/22 23:28:21 by aakyuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int num, int *counter, char *base)
{
	char	*str;

	str = ft_hex(num, base);
	ft_putstr(str, counter);
	free(str);
}
