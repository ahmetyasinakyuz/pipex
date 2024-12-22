/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakyuz <aakyuz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:57:29 by aakyuz            #+#    #+#             */
/*   Updated: 2024/10/11 19:24:12 by aakyuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*m;

	m = (unsigned char *)b;
	while (len != 0)
	{
		len--;
		m[len] = c;
	}
	return ((void *)b);
}
