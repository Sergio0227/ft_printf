/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:54:00 by sandre-a          #+#    #+#             */
/*   Updated: 2024/08/31 23:43:23 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

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
static void	check_flags(char specifier, t_prtf *data);
static void	reset(t_prtf *data);
static int	parse_input(t_prtf *data, const char *format);

int	ft_printf(const char *format, ...)
{
	t_prtf	data;
	int		new_pos;

	va_start(data.args, format);
	data.length = 0;
	while (*format)
	{
		if (*format == '%')
		{
			reset(&data);
			new_pos = parse_input(&data, format++);
			if (data.inval)
			{
				ft_putchar(*data.inval - 1);
				while (ft_strchr("cspdiuxX%", *data.inval))
					ft_putchar(*(++data.inval));
			}
			else
				format += new_pos;
		}
		else
			data.length += ft_putchar(*format);
		format++;
	}
	return (data.length);
}

static int	parse_input(t_prtf *data, const char *format)
{
	char	*start;

	start = (char *)format;
	format++;
	while (ft_strchr("0# +-", *format))
		check_flags(*(format++), data);
	if (ft_isdigit(*format))
		data->width = ft_atoi(format);
	while (ft_isdigit(*format) || *format == '.')
		if (*(format++) == '.' && data->precision == 0)
			data->precision = ft_atoi(format);
	if (!ft_strchr("cspdiuxX%", *format))
		data->inval = start;
	else
		check_specifier(*format, data);
	return (format - start - 1);
}

static void	check_specifier(char specifier, t_prtf *data)
{
	if (specifier == 'c')
		data->length += ft_putchar(va_arg(data->args, int));
	if (specifier == 's')
		data->length += ft_putstr(va_arg(data->args, char *));
	if (specifier == 'p')
		data->length += ft_putaddres(va_arg(data->args, unsigned long long));
	if (specifier == 'd')
		ft_putnbr(va_arg(data->args, int), data);
	if (specifier == 'i')
		ft_putnbr(va_arg(data->args, int), data);
	if (specifier == 'u')
		ft_putnbr(va_arg(data->args, unsigned int), data);
	if (specifier == 'x' || specifier == 'X')
		data->length += ft_puthex(va_arg(data->args, unsigned int), specifier);
	if (specifier == '%')
		data->length += ft_putchar('%');
}

static void	check_flags(char specifier, t_prtf *data)
{
	if (specifier == '0')
		data->flags.zero = true;
	if (specifier == '#')
		data->flags.hashtag = true;
	if (specifier == ' ')
		data->flags.space = true;
	if (specifier == '+')
		data->flags.plus = true;
	if (specifier == '-')
		data->flags.minus = true;
	return ;
}

static void	reset(t_prtf *data)
{
	data->inval = NULL;
	data->width = 0;
	data->precision = 0;
	data->flags.hashtag = false;
	data->flags.zero = false;
	data->flags.space = false;
	data->flags.minus = false;
	data->flags.plus = false;
}
