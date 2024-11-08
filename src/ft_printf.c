/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <sandre-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:08:01 by sandre-a          #+#    #+#             */
/*   Updated: 2024/11/08 16:00:16 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void     buffer_char(string buffer, int c)
{
    buffer[0] = c;
    buffer[1] = 0;
}

void     buffer_str(string buffer, string str)
{
    int i;

    i = -1;
    while (str[++i]  && i < 4095)
        buffer[i] = str[i];
    buffer[i] = 0;
}

void    buffer_hex(string buffer, long nbr)
{
    int i;
    char hex_chars[16 + 1];

    i = 0;
    ft_strcpy(hex_chars, "0123456789ABCDEF");
    if (nbr == 0)
         buffer[i++] = '0';
    
    while (nbr)
    {
        buffer[i] = hex_chars[nbr % 16];
        nbr = nbr / 16;
        i++;
    }
    buffer[i] = 0;
}

void	check_specifier(t_ft_print *data, va_list arg, char specifier)
{
	data->buffer = malloc(4096);
	if (specifier == 'c')
        buffer_char(data->buffer, va_arg(arg, int));
	else if (specifier == 's')
        buffer_str(data->buffer, va_arg(arg, string));
	else if (specifier == 'p')
        buffer_hex(data->buffer, va_arg(arg, long));
		// 		else if (specifier == 'd' && specifier == 'i')
		// 				else if (specifier == 'u')
	else if (specifier == 'x' || specifier == 'X')
        buffer_hex(data->buffer, va_arg(arg, long));
    data->length += ft_putstr(data->buffer);
    free(data->buffer);
	return ;
}

void init_vars(t_ft_print *data)
{
    data->length = 0;
    data->flags.field_width = 0;
    data->flags.precision = 0;
    data->flags.left_justify = false;
    data->flags.plus = false;
    data->flags.prefix = false;
    data->flags.space = false;
    data->flags.zero_pad = false;
}

int	ft_printf(const char *format, ...)
{
	va_list		arg;
	t_ft_print	data;

	va_start(arg, format);
    init_vars(&data);
	while (*format)
	{
		if (*format == PERCENT_SIGN && *(format + 1) != PERCENT_SIGN)
			check_specifier(&data, arg, *(++format));
		else
			data.length += ft_putchar(*format);
		format++;
	}
    va_end(arg);
}

#include <stdio.h>
int	main(int argc, string *argv)
{
    int x = 5;
	ft_printf("%p", &x);
    printf("\n%p", &x);
	return (0);
}