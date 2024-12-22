/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakyuz <aakyuz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:49:19 by aakyuz            #+#    #+#             */
/*   Updated: 2024/10/23 01:33:18 by aakyuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(void *ptr, int *counter)
{
	char					*str;
	unsigned long long		ptr_address;

	ptr_address = (unsigned long long)ptr;
	ft_putstr("0x", counter);
	str = ft_hex(ptr_address, "0123456789abcdef");
	ft_putstr(str, counter);
	free(str);
}
