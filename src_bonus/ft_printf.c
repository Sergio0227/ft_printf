/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:54:00 by sandre-a          #+#    #+#             */
/*   Updated: 2025/01/18 22:32:21 by sandre-a         ###   ########.fr       */
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

static void	check_flags(char spec, t_prtf *data);
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
	va_end(data.args);
	return (data.length);
}


static int	parse_input(t_prtf *data, const char *format)
{
	char	*start;

	reset(data);
	start = (char *)format;
	format++;
	if (*format == 0)
		return (0);
	while (ft_strchr("0# +-", *format))
		check_flags(*(format++), data);
	if (ft_isdigit(*format))
		data->width = ft_atoi(format);
	while (ft_isdigit(*format) || *format == '.')
	{
		if (*(format) == '.' && data->precision != -1)
			break ;
		if (*(format++) == '.' && data->precision == -1)
			data->precision = ft_atoi(format);
	}
	if (!ft_strchr("cspdiuxX%", *format))
		data->inval = start;
	data->spec = *format;
		buffer_string(*format, data);
	return (format - start - 1);
}

static void	check_flags(char spec, t_prtf *data)
{
	if (spec == '0')
		data->flags.zero = true;
	if (spec == '#')
		data->flags.hashtag = true;
	if (spec == ' ')
		data->flags.space = true;
	if (spec == '+')
		data->flags.plus = true;
	if (spec == '-')
		data->flags.minus = true;
	return ;
}

static void	reset(t_prtf *data)
{
	data->inval = NULL;
	data->width = 0;
	data->precision = -1;
	data->flags.hashtag = false;
	data->flags.zero = false;
	data->flags.space = false;
	data->flags.minus = false;
	data->flags.plus = false;
}
