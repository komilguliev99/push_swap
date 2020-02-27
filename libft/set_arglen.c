/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_arglen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 12:40:36 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/03 16:56:19 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			set_arglen(t_state *st)
{
	if (st->fm->type == 'c' && st->arg[0] == '^' && st->arg[1] == '@')
		st->arg_len = 1;
	else if (st->fm->type == 'f')
		st->arg_len = ft_strlen(st->arg) + ft_strlen(st->fl) + 1;
	else
		st->arg_len = ft_strlen(st->arg);
	if (st->fm->type != 'f')
		st->sign = (st->arg && st->arg[0] == '-') ? '-' : '+';
}
