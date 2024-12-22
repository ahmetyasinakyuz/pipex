/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakyuz <aakyuz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:02:51 by aakyuz            #+#    #+#             */
/*   Updated: 2024/10/09 17:28:43 by aakyuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	d;
	unsigned char	*m;
	size_t			i;

	d = c;
	i = 0;
	m = (unsigned char *)s;
	while (i != (ft_strlen((char *)m) + 1) && m)
	{
		if (s[i] == d)
			return ((char *)(s + (i * sizeof(char))));
		else
			i++;
	}
	return (NULL);
}
