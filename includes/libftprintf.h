/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <sandre-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:22:54 by sandre-a          #+#    #+#             */
/*   Updated: 2024/11/08 15:45:55 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# define PERCENT_SIGN '%'

typedef char	*string;

typedef struct s_flag
{
	int field_width;   //! field minimum width
	int precision;     //? precision for '.' flag
	bool left_justify; //! '-'
	bool zero_pad;     //? '0'
	bool prefix;       //! '#' flag
	bool plus;         //? '+' flag for positive numbers
	bool space;        //! space for positive numbers
}				t_flags;

typedef struct s_ft_print
{
	int			length;
	string		buffer;
	t_flags		flags;
}				t_ft_print;

int				ft_printf(const char *, ...);
int				ft_putchar(int c);
int				ft_putstr(string str);
void			ft_strcpy(string dest, string str);

#endif