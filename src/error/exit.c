/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:05:24 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/11/21 16:05:36 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/cub3D.h"

/**
 * @brief put an error message and exit program
 * 
 * @param str string received
 */
void	ft_exit(char *str)
{
	printf("Error\n%s\n", str);
	exit(1);
}
