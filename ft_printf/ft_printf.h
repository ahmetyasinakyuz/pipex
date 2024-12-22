/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakyuz <aakyuz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:48:53 by aakyuz            #+#    #+#             */
/*   Updated: 2024/10/23 00:25:06 by aakyuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(char const *str, ...);
void	ft_putchar(char c, int *counter);
void	ft_putstr(char *str, int *counter);
void	ft_putnbr(int num, int *counter);
void	ft_putuint(unsigned int num, int *counter);
void	ft_puthex(unsigned int num, int *counter, char *base);
void	ft_putptr(void *ptr, int *counter);
char	*ft_hex(unsigned long long n, char *base);

#endif
