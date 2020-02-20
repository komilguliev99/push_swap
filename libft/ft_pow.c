/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 14:27:40 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/01 12:53:17 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int		ft_pow(long long int nbr, int p)
{
	long long int	res;

	res = 1;
	while (p--)
		res *= nbr;
	return (res);
}
