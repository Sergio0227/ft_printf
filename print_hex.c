/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 09:56:49 by sandre-a          #+#    #+#             */
/*   Updated: 2024/08/31 22:53:10 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_hex(unsigned long long num, char *case_type)
{
	char	*hexchars;
	char	hex[17];
	int		i;
	int		len;

	if (!num)
		return ft_putchar('0');
	len = 0;
	i = 16;
	hexchars = case_type;
	hex[i--] = 0;
	while (num && i >= 0)
	{
		hex[i--] = hexchars[num % 16];
		num /= 16;
	}
	i++;
	while (hex[i])
		len += ft_putchar(hex[i++]);
	return (len);
}

int	ft_putaddres(unsigned long long address)
{
	if (!address)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ft_putstr("0x");
	return (ft_hex(address, "0123456789abcdef") + 2);
}

int	ft_puthex(unsigned long long num, char specifier)
{
	if (specifier == 'x')
		return (ft_hex(num, "0123456789abcdef"));
	else
		return (ft_hex(num, "0123456789ABCDEF"));
}