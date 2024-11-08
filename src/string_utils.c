/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <sandre-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:35:54 by sandre-a          #+#    #+#             */
/*   Updated: 2024/11/08 15:49:05 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(string str)
{
	int	len;

	len = 0;
	while (*str)
		len += ft_putchar(*(str++));
	return (len);
}


void	ft_strcpy(string dest, string str)
{
	int i;

	i = -1;
	while (str[++i])
		dest[i] = str[i];
	dest[i] = 0;
}