/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 17:42:50 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/03 15:18:25 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					handle_char(t_state *st)
{
	if (st->fm->min_w > 1)
		st->space_len = st->fm->min_w - 1;
	if (st->fm->flags['-'])
	{
		ft_putchar(st->arg[0]);
		ft_putchar_cnt(' ', st->space_len);
		return (st->space_len + 1);
	}
	else
	{
		ft_putchar_cnt(' ', st->space_len);
		ft_putchar(st->arg[0]);
		return (st->space_len + 1);
	}
}
