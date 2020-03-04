/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:50:21 by dcapers           #+#    #+#             */
/*   Updated: 2020/03/04 13:39:10 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_list_push(t_list **list, char *data)
{
	t_list			*new;
	t_list			*lst;

	if (list == NULL)
		return ;
	if (!(new = ft_list_create(data)))
		return ;
	if (*list == NULL)
		*list = new;
	else
	{
		lst = *list;
		while (lst && lst->next)
			lst = lst->next;
		lst->next = new;
	}
}

t_list			*ft_list_create(char *data)
{
	t_list			*lst;

	if (!(lst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	lst->next = NULL;
	lst->content = data;
	return (lst);
}

void			ft_list_clear(t_list **lst)
{
	t_list		*del;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		del = *lst;
		*lst = (*lst)->next;
		if (del->content)
			free(del->content);
		free(del);
	}
}
