/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublefree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:02:36 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/11/08 12:04:59 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief attempts to free a double pointer pointed by str.
 * 
 * @param str the double pointer to free.
 * @return NULL.
 */
char	**ft_doublefree(char **str)
{
	int	i;

	if (str == NULL)
		return (str);
	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
	return (NULL);
}
