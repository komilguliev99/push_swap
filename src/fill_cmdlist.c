/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cmdlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 12:21:05 by dcapers           #+#    #+#             */
/*   Updated: 2020/03/04 12:23:00 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					fill_cmdlist(t_list **cmd)
{
	char	*command;
	int		error;

	command = NULL;
	error = 0;
	*cmd = NULL;
	while (get_next_line(0, &command) > 0)
	{
		if (!(ft_strcmp(command, "sa") == 0 || ft_strcmp(command, "sb") == 0 ||
			ft_strcmp(command, "ss") == 0 || ft_strcmp(command, "pa") == 0 ||
			ft_strcmp(command, "pb") == 0 || ft_strcmp(command, "ra") == 0 ||
			ft_strcmp(command, "rb") == 0 || ft_strcmp(command, "rr") == 0 ||
			ft_strcmp(command, "rra") == 0 || ft_strcmp(command, "rrb") == 0
			|| ft_strcmp(command, "rrr") == 0))
			error = 1;
		ft_list_push(cmd, command);
	}
	if (error)
	{
		if (cmd)
			ft_list_clear(cmd);
		free(command);
	}
	return (!error);
}
