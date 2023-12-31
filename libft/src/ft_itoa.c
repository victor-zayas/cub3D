/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:06:31 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/11/28 19:30:57 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*p;
	long	nbr;

	len = ft_len(n);
	nbr = n;
	p = malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	if (nbr < 0)
	{
		p[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		p[0] = '0';
	p[len--] = '\0';
	while (nbr)
	{
		p[len] = nbr % 10 + '0';
		len--;
		nbr = nbr / 10;
	}
	return (p);
}
