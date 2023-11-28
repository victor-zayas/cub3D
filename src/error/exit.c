/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:05:24 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/11/28 19:32:45 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

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

/**
 * @brief closes mlx window and frees resources
 * 
 * @param all 
 */

void	ft_close(void *all)
{
	t_all	*aux;

	aux = (t_all *)all;
	mlx_destroy_window(aux->mlx.mlx, aux->mlx.win);
	mlx_destroy_image(aux->mlx.mlx, aux->mlx.img);
	ft_free_img(aux);
	ft_doublefree(aux->map.map);
	exit(0);
}
