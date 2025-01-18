/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:47:30 by sandre-a          #+#    #+#             */
/*   Updated: 2025/01/18 22:32:38 by sandre-a         ###   ########.fr       */
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
	char	*buffer;
	char	spec;
	va_list	args;
	t_flags	flags;
}			t_prtf;

int			ft_printf(const char *format, ...);
int			ft_putchar(char c);
int			ft_putstr(char *str);
void 		ft_putnbr(long nbr, t_prtf *data);
int			ft_putaddres(unsigned long long address);
int			ft_puthex(unsigned long long num, char *case_type);

//BONUS
void	buffer_string(char specifier, t_prtf *data);
void	putstr_with_flags(t_prtf *data);


#endif