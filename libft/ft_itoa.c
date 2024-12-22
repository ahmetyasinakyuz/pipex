/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakyuz <aakyuz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:30:17 by aakyuz            #+#    #+#             */
/*   Updated: 2024/10/13 10:04:01 by aakyuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_len(long src)
{
	int	i;

	i = 0;
	if (src < 0)
	{
		src *= -1;
		i++;
	}
	while (src > 0)
	{
		src /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		i;
	long	num;

	if (n == 0)
		return (ft_strdup("0"));
	num = n;
	i = ft_len(num);
	ret = malloc(i + 1);
	if (ret == NULL)
		return (NULL);
	if (n < 0)
	{
		num *= -1;
		ret[0] = '-';
	}
	ret[i] = 0;
	i--;
	while (i >= 0 && num > 0)
	{
		ret[i] = (num % 10) + '0';
		num /= 10;
		i--;
	}
	return (ret);
}
