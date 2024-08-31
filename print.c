/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 20:10:56 by sandre-a          #+#    #+#             */
/*   Updated: 2024/08/31 23:46:35 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

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
