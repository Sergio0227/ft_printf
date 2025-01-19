/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_with_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 00:35:18 by sandre-a          #+#    #+#             */
/*   Updated: 2025/01/20 00:23:31 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	handle_width(t_prtf *data, int remaining)
{
	remaining = data->width - ft_strlen(data->buffer) + 1;
	if (!*data->buffer && data->spec == 'c')
	{
		data->length += ft_putchar(data->buffer[0]);
		remaining--;
	}
	if (data->flags.minus)
		data->length += ft_putstr(data->buffer);
	while (--remaining > 0)
	{
		if 			(data->flags.zero)
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
	}
}

static void	handle_precision(t_prtf *data, int remaining)
{
	remaining = data->precision - ft_strlen(data->buffer);
	if (ft_atol(data->buffer) < 0 && data->spec != 'x' && data->spec != 'X')
		remaining++;
	while (remaining > 0 && data->spec != 's')
	{
		if (ft_atol(data->buffer) < 0 && data->spec != 'u' && data->spec != 'x'
			&& data->spec != 'X')
		{
			data->length += ft_putchar('-');
			while (remaining--)
				data->length += ft_putchar('0');
		}
		else
			data->length += ft_putchar('0');
		remaining--;
	}
	if (data->spec != 's')
		return ;
	if (data->precision && data->precision < (int)ft_strlen(data->buffer))
		data->buffer[data->precision] = 0;
	else if (!data->precision)
		data->buffer[0] = 0;
}

void	putstr_with_flags(t_prtf *d)
{
	if (d->width || (!d->width && d->flags.minus))
		handle_width(d, 0);
	else if (d->precision != -1)
		handle_precision(d, 0);
	else if (d->flags.plus && (((d->spec == 'i' || d->spec == 'd')
				&& ft_atol(d->buffer) >= 0) || d->spec == 'p'))
		d->length += ft_putchar('+');
	else if (d->flags.space && ft_atol(d->buffer) >= 0 && d->spec != 's')
		d->length += ft_putchar(' ');
	else if (d->flags.hashtag && d->spec == 'x' && d->buffer[0] != '0')
		d->length += ft_putstr("0x");
	else if (d->flags.hashtag && d->spec == 'X' && d->buffer[0] != '0')
		d->length += ft_putstr("0X");
	if (d->flags.zero && ft_atoi(d->buffer) < 0
		&& d->width > (int)ft_strlen(d->buffer) && d->spec != 'u')
		d->length += ft_putstr(d->buffer + 1);
	else if (d->precision && ft_atoi(d->buffer) < 0
		&& d->precision >= (int)ft_strlen(d->buffer) && d->spec != 'u')
		d->length += ft_putstr(d->buffer + 1);
	else if (!d->flags.minus)
		d->length += ft_putstr(d->buffer);
	free(d->buffer);
	return ;
}
