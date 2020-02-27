/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_float.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:34:07 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/03 17:29:19 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long double		ft_getmiskin(int prec)
{
	long double		dop;
	int				i;

	dop = 5.0;
	i = 0;
	while (i++ < prec + 1)
		dop /= 10;
	return (dop);
}

void					set_float(t_state *st, long double f)
{
	long long int	exp;
	int				i;

	if (f < 0)
		f -= ft_getmiskin(st->fm->prec);
	else
		f += ft_getmiskin(st->fm->prec);
	exp = (long long int)f;
	st->arg = ft_itoa_base(exp, 10, 0);
	f -= exp;
	f = f < 0 ? -f : f;
	i = 0;
	while (i < st->fm->prec)
	{
		st->fl[i++] = (int)(f *= 10) + '0';
		f -= (int)f;
	}
	if (st->fm->prec >= 20 && f >= 0.5 && st->fl[i - 1] <= '8')
		st->fl[i - 1] += 1;
	st->fl[i] = '\0';
}
