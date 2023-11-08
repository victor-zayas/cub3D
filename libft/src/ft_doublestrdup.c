/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublestrdup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:03:50 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/11/08 12:04:53 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief attempts to duplicate the double pointer pointed by str to a new
 * allocated double pointer.
 * 
 * @param str the double pointer to be duplicated.
 * @return char** the allocated new double pointer or NULL if the allocation
 * failed or str was nonexisting.
 */
char	**ft_doublestrdup(const char **str)
{
	char	**result;
	int		i;

	if (!str)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (ft_doublestrlen(str) + 1));
	if (!result)
		return (NULL);
	i = -1;
	while (str[++i])
	{
		result[i] = ft_strdup(str[i]);
		if (result[i] == NULL)
		{
			ft_doublefree(result);
			errno = ENOMEM;
			return (NULL);
		}
	}
	result[i] = 0;
	return (result);
}
