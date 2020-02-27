/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_state.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:48:56 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/03 15:56:52 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		reset_format(t_format *fm)
{
	fm->flags['#'] = 0;
	fm->flags[' '] = 0;
	fm->flags['+'] = 0;
	fm->flags['-'] = 0;
	fm->flags['0'] = 0;
	fm->modfr = 0;
	fm->type = 0;
	fm->prec = -1;
	fm->min_w = -1;
}

void		reset_state(t_state *st, int clear)
{
	reset_format(st->fm);
	if (clear && st->arg != NULL)
		free(st->arg);
	st->arg = NULL;
	st->arg_len = 0;
	st->right = 1;
	st->sign = '+';
	st->zero_len = 0;
	st->space_len = 0;
	st->mem_alloc = 0;
}

t_state		*initialize_state(void)
{
	t_state		*st;

	if (!(st = (t_state *)malloc(sizeof(t_state))))
		return (NULL);
	st->fm = NULL;
	if (!(st->fm = (t_format *)malloc(sizeof(t_format))))
	{
		free(st);
		return (0);
	}
	else
		reset_state(st, 0);
	return (st);
}

void		clear_memory(t_state *st)
{
	free(st->fm);
	free(st->arg);
	free(st);
}
