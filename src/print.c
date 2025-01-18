/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 20:10:56 by sandre-a          #+#    #+#             */
/*   Updated: 2025/01/17 23:58:46 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = 0;
	while (str[len])
		len += ft_putchar(str[len]);
	return (len);
}

void	ft_putnbr(long nbr, t_prtf *data)
{
	if (nbr < 0)
	{
		data->length += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10, data);
		data->length += ft_putchar(nbr % 10 + 48);
	}
	else
		data->length += ft_putchar(nbr % 10 + 48);
}
int	ft_putaddres(unsigned long long address)
{
	int	count;

	if (!address)
		return (ft_putstr("(nil)"));
	count = ft_putstr("0x");
	count += ft_puthex(address, "0123456789abcdef");
	return (count);
}

int	ft_puthex(unsigned long long num, char *case_type)
{
	int	count;

	count = 0;
	if (num > 15)
		count += ft_puthex(num / 16, case_type);
	ft_putchar(case_type[num % 16]);
	count++;
	return (count);
}