/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakyuz <aakyuz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:07:47 by aakyuz            #+#    #+#             */
/*   Updated: 2024/10/09 10:28:40 by aakyuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	int				flg;
	unsigned char	*str;
	unsigned char	d;

	d = c;
	str = (unsigned char *)s;
	i = 0;
	flg = -1;
	while (i != (ft_strlen((char *)str) + 1))
	{
		if (str[i] == d)
			flg = i;
		i++;
	}
	if (flg != -1)
		return ((char *)(s + (flg * sizeof(char))));
	return (0);
}
