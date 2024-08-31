/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:47:30 by sandre-a          #+#    #+#             */
/*   Updated: 2024/08/31 23:47:07 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_flags
{
	bool	zero;
	bool	hashtag;
	bool	space;
	bool	plus;
	bool	minus;
}			t_flags;

typedef struct s_prtf
{
	int		length;
	int		width;
	int		precision;
	char	*inval;
	char	*buffer[8096];
	va_list	args;
	t_flags	flags;
}			t_prtf;

int			ft_printf(const char *format, ...);
int			ft_putchar(char c);
int			ft_putstr(char *str);
void		ft_putnbr(long nbr, t_prtf *data);
int			ft_putaddres(unsigned long long address);
int			ft_puthex(unsigned long long num, char specifier);
int		ft_hex(unsigned long long num, char *case_type);

#endif