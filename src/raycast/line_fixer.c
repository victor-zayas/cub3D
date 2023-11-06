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

void	fix_fisheye(t_ray *ray/*, t_playerpos *p_pos*/)
{
	if ((ray->ra > P4/ 4 && ray->ra < P34) || (ray->ra > P54 && ray->ra < P74))
		ray->dist = sin(ray->ra) * ray->dist;
	else
		ray->dist = cos(ray->ra) * ray->dist;
	ray->dist = absolute(ray->dist);
}