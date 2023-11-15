/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_fixer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <larraingonzalez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:45:40 by lagonzal          #+#    #+#             */
/*   Updated: 2023/10/25 18:45:40 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief fixes the fisheye effect caused by the ray distance calculation
 * 
 * @param ray 
 * @param player 
 */

void	fix_fisheye(t_ray *ray, t_playerpos *p_pos)
{
	ray->dist = ray->dist * cos(ray->ra - p_pos->pa);
	ray->dist = absolute(ray->dist);
}