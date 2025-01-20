/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:39:46 by sandre-a          #+#    #+#             */
/*   Updated: 2025/01/20 16:40:20 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	buffer_char(char c, t_prtf *data)
{
	data->buffer = malloc(2);
	data->buffer[0] = c;
	data->buffer[1] = 0;
}

static void	buffer_str(char *str, t_prtf *data)
{
	if (!str)
		data->buffer = ft_strdup("(null)");
	else
		data->buffer = ft_strdup(str);
}

static void	buffer_nbr(long nbr, t_prtf *data)
{
	char	temp[50];
	bool	negative;
	int		index;

	negative = false;
	if (nbr < 0)
	{
		negative = true;
		nbr = -nbr;
	}
	index = 0;
	while (nbr > 9)
	{
		temp[index++] = (nbr % 10) + 48;
		nbr /= 10;
	}
	temp[index++] = (nbr % 10 + 48);
	if (negative)
		temp[index++] = '-';
	temp[index] = 0;
	data->buffer = ft_strrev(temp);
}

void	buffer_hex(unsigned long long num, char *case_type, t_prtf *data,
		bool address)
{
	int		index;
	char	temp[50];

	index = 0;
	if (address && !num)
	{
		data->buffer = ft_strdup("(nil)");
		return ;
	}
	while (num > 15)
	{
		temp[index++] = case_type[num % 16];
		num /= 16;
	}
	temp[index++] = case_type[num % 16];
	if (address)
	{
		temp[index++] = 'x';
		temp[index++] = '0';
	}
	temp[index] = 0;
	data->buffer = ft_strrev(temp);
}

void	buffer_string(char spec, t_prtf *data)
{
	if (spec == 'c')
		buffer_char(va_arg(data->args, int), data);
	if (spec == 's')
		buffer_str(va_arg(data->args, char *), data);
	if (spec == 'p')
		buffer_hex(va_arg(data->args, unsigned long long), "0123456789abcdef",
			data, true);
	if (spec == 'd')
		buffer_nbr(va_arg(data->args, int), data);
	if (spec == 'i')
		buffer_nbr(va_arg(data->args, int), data);
	if (spec == 'u')
		buffer_nbr(va_arg(data->args, unsigned int), data);
	if (spec == 'x')
		buffer_hex(va_arg(data->args, unsigned int), "0123456789abcdef", data,
			false);
	if (spec == 'X')
		buffer_hex(va_arg(data->args, unsigned int), "0123456789ABCDEF", data,
			false);
	if (spec == '%')
		buffer_char('%', data);
	putstr_with_flags(data);
}
