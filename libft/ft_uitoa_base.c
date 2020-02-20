/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 20:28:49 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/03 15:09:49 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		calc_length(unsigned long long int nbr, int base)
{
	int		len;

	len = 0;
	while (nbr /= base)
		len++;
	return (len);
}

char			*ft_uitoa_base(unsigned long long int nbr, int base, int flag)
{
	char		*res;
	int			len;

	len = calc_length(nbr, base) + 1;
	if (!(res = malloc(len + 1)))
		return (NULL);
	res[len] = '\0';
	while (len)
	{
		res[len - 1] = value_of(nbr % base, flag);
		len--;
		nbr /= base;
	}
	return (res);
}
