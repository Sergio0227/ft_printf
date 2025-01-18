/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:54:00 by sandre-a          #+#    #+#             */
/*   Updated: 2025/01/17 23:57:51 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** va_list: Declares a variable of type va_list to store information about
	the variable argument list.
** va_start: Initializes the va_list variable with the first argument after
	the fixed arguments.
	Takes two arguments: the va_list and the name of the last fixed argument.
** va_arg: Retrieves the next argument from the variable argument list.
	Takes two arguments: the va_list and the type of the expected argument.
** va_end: Cleans up the variable argument list.
*/

static void	check_specifier(char specifier, t_prtf *data);

int	ft_printf(const char *format, ...)
{
	t_prtf	data;

	va_start(data.args, format);
	data.length = 0;
	while (*format)
	{
		if (*format == '%')
			check_specifier(*(++format), &data);
		else
			data.length += ft_putchar(*format);
		format++;
	}
	return (data.length);
}

static void	check_specifier(char specifier, t_prtf *data)
{
	if (specifier == 'c')
		data->length += ft_putchar(va_arg(data->args, int));
	if (specifier == 's')
		data->length += ft_putstr(va_arg(data->args, char *));
	if (specifier == 'p')
		data->length += ft_putaddres(va_arg(data->args, unsigned long));
	if (specifier == 'd')
		ft_putnbr(va_arg(data->args, int), data);
	if (specifier == 'i')
		ft_putnbr(va_arg(data->args, int), data);
	if (specifier == 'u')
		ft_putnbr(va_arg(data->args, unsigned int), data);
	if (specifier == 'x')
		data->length += ft_puthex(va_arg(data->args, unsigned int),
				"0123456789abcdef");
	if (specifier == 'X')
		data->length += ft_puthex(va_arg(data->args, unsigned int),
				"0123456789ABCDEF");
	if (specifier == '%')
		data->length += ft_putchar('%');
}


