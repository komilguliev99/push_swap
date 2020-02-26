/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:31:58 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/25 12:36:25 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t c_sz)
{
	t_list		*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	if (content == NULL)
	{
		lst->content = NULL;
		lst->content_size = 0;
	}
	else
	{
		if ((lst->content = malloc(sizeof(lst->content))) == NULL)
		{
			free(lst);
			return (NULL);
		}
		ft_memcpy(lst->content, content, c_sz);
		lst->content_size = c_sz;
	}
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}
