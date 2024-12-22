/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakyuz <aakyuz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:47:58 by aakyuz            #+#    #+#             */
/*   Updated: 2024/10/23 00:39:04 by aakyuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hex(unsigned long long n, char *base)
{
	char					*str;
	int						num_len;
	unsigned long long		tmp_n;

	tmp_n = n;
	num_len = 1;
	while (tmp_n >= 16)
	{
		tmp_n /= 16;
		num_len++;
	}
	str = malloc((num_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[num_len] = '\0';
	while (num_len)
	{
		num_len = num_len - 1;
		str[num_len] = base[n % 16];
		n /= 16;
	}
	return (str);
}
