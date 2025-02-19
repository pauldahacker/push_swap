/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:49:39 by pde-masc          #+#    #+#             */
/*   Updated: 2023/10/02 12:39:48 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digits(int n)
{
	if (!n)
		return (0);
	return (1 + count_digits(n / 10));
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	len;

	len = count_digits(n) + (n < 0) + (n == 0);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (!n)
		res[0] = '0';
	if (n < 0)
	{
		res[--len] = -1 * (n % 10) + '0';
		res[0] = '-';
		n = n / 10 * -1;
	}
	while (n)
	{
		res[--len] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}
