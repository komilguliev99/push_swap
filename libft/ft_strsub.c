/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:35:03 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/28 16:31:11 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s1, unsigned int st,
		size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s1 || !(sub = (char *)malloc(len + 1)))
		return (NULL);
	while (len-- && s1[st] != '\0')
	{
		sub[i] = s1[st];
		st++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
