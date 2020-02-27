/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cmdlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 22:08:31 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/27 22:09:01 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					fill_cmdlist(t_list **cmd)
{
	char	*command;

	command = NULL;
	*cmd = NULL;
	while (get_next_line(0, &command) > 0)
	{
		if (!(ft_strcmp(command, "sa") == 0 || ft_strcmp(command, "sb") == 0 ||
			ft_strcmp(command, "ss") == 0 || ft_strcmp(command, "pa") == 0 ||
			ft_strcmp(command, "pb") == 0 || ft_strcmp(command, "ra") == 0 ||
			ft_strcmp(command, "rb") == 0 || ft_strcmp(command, "rr") == 0 ||
			ft_strcmp(command, "rra") == 0 || ft_strcmp(command, "rrb") == 0
			|| ft_strcmp(command, "rrr") == 0))
		{
			ft_list_clear(cmd);
			return (0);
		}
		ft_list_push(cmd, command);
		command = NULL;
	}
	if (*cmd)
		return (1);
	return (0);
}
