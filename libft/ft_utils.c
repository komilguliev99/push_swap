/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:45:21 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/01 17:29:42 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			is_flag(char c)
{
	if (c == '+' || c == '0' || c == '-' || c == '#' || c == ' ')
		return (1);
	return (0);
}

int			is_modifier(char c)
{
	if (c == 'l' || c == 'h' || c == 'L')
		return (1);
	return (0);
}

void		set_flag(char *flags, char c)
{
	flags[(int)c] = 1;
}

void		set_modifier(t_format *fm, char *mod)
{
	if (mod[0] == 'l' && mod[1] == 'l')
		fm->modfr = 2;
	else if (mod[0] == 'l')
		fm->modfr = 1;
	else if (mod[0] == 'h' && mod[1] == 'h')
		fm->modfr = 4;
	else if (mod[0] == 'h')
		fm->modfr = 3;
	else if (mod[0] == 'L')
		fm->modfr = 5;
}

int			is_type(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'f'
			|| c == 'x' || c == 'X' || c == 'c' || c == 's'
				|| c == 'p' || c == 'u' || c == '%')
		return (1);
	return (0);
}
