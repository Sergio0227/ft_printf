/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_with_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 00:35:18 by sandre-a          #+#    #+#             */
/*   Updated: 2025/01/19 02:32:24 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	handle_width(t_prtf *data)
{
	int	remaining;

	if (data->spec == '%')
		return ;
	remaining = data->width - ft_strlen(data->buffer);
	if (*data->buffer && data->flags.minus)
		data->length += ft_putstr(data->buffer);
	while (remaining > 0)
	{
		if (data->flags.zero)
		{
			if (ft_atol(data->buffer) < 0 && data->spec != 'u'
				&& (ft_isdigit(*data->buffer) || *data->buffer == '-'))
			{
				data->length += ft_putchar('-');
				while (remaining--)
					data->length += ft_putchar('0');
			}
			else
				data->length += ft_putchar('0');
		}
		else
			data->length += ft_putchar(' ');
		remaining--;
	}
}

static void	handle_precision(t_prtf *data)
{
	int	remaining;

	remaining = data->precision - ft_strlen(data->buffer);
	if (ft_atol(data->buffer) < 0 && data->spec != 'x' && data->spec != 'X')
		remaining++;
	if (data->spec != 's')
	{
		while (remaining > 0)
		{
			if (ft_atol(data->buffer) < 0 && data->spec != 'u'
				&& data->spec != 'x' && data->spec != 'X')
			{
				data->length += ft_putchar('-');
				while (remaining--)
					data->length += ft_putchar('0');
			}
			else
				data->length += ft_putchar('0');
			remaining--;
		}
		return;
	}
	if (data->precision && data->precision < (int)ft_strlen(data->buffer))
		data->buffer[data->precision] = 0;
	else if (!data->precision)
		data->buffer[0] = 0;
}

void	putstr_with_flags(t_prtf *data)
{
	if (data->width || (!data->width && data->flags.minus))
		handle_width(data);
	else if (data->precision != -1)
		handle_precision(data);
	else if (data->flags.plus)
	{
		if (((data->spec == 'i' || data->spec == 'd')
				&& ft_atol(data->buffer) >= 0) || data->spec == 'p')
			data->length += ft_putchar('+');
	}
	else if (data->flags.space && ft_atol(data->buffer) >= 0 && (data->width))
		data->length += ft_putchar(' ');
	else if (data->flags.hashtag && data->spec == 'x' && data->buffer[0] != '0')
		data->length += ft_putstr("0x");
	else if (data->flags.hashtag && data->spec == 'X' && data->buffer[0] != '0')
		data->length += ft_putstr("0X");
	if (data->flags.zero && ft_atoi(data->buffer) < 0
		&& data->width > (int)ft_strlen(data->buffer) && data->spec != 'u')
		data->length += ft_putstr(data->buffer + 1);
	else if (data->precision && ft_atoi(data->buffer) < 0
		&& data->precision >= (int)ft_strlen(data->buffer) && data->spec != 'u')
		data->length += ft_putstr(data->buffer + 1);
	else if (!data->flags.minus)
		data->length += ft_putstr(data->buffer);
	free(data->buffer);
	return ;
}
