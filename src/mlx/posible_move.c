/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   posible_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:57:14 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/11/28 19:08:41 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief It checks if the movements are possible before doing them
 * 
 * @param all game struct
 * @param direction the movement direction do be checked
 * @param rev a variable in order to be able to use W and S as the same case
 * to compliment the norm.
 * @return int 1 if movement is possible 0 if not
 */

int	p_m(t_all *all, int direction, int rev)
{
	float	new_x;
	float	new_y;

	if (!move_variant1(all, direction, rev)
		|| !move_variant2(all, direction, rev))
		return (0);
	if (direction == 2 || direction == 4)
	{
		new_y = all->player.py - (MS * 10 * rev * (sin(all->player.pa)));
		new_x = all->player.px + (MS * 10 * rev * (cos(all->player.pa)));
	}
	else if (direction == 3)
	{
		new_y = all->player.py - (MS * 10 * (sin(all->player.pa + P_2)));
		new_x = all->player.px + (MS * 10 * (cos(all->player.pa + P_2)));
	}
	else
	{
		new_y = all->player.py - (MS * 10 * (sin(all->player.pa - P_2)));
		new_x = all->player.px + (MS * 10 *(cos(all->player.pa - P_2)));
	}
	if (all->map.map[(int)(new_y) >> 6][(int)(new_x) >> 6] == '1')
		return (0);
	return (1);
}

int	move_variant1(t_all *all, int direction, int rev)
{
	float	new_x;
	float	new_y;

	if (direction == 2 || direction == 4)
	{
		new_y = all->player.py - (MS * 10 * rev * (sin(all->player.pa)));
	}
	else if (direction == 3)
	{
		new_y = all->player.py - (MS * 10 * (sin(all->player.pa + P_2)));
	}
	else
	{
		new_y = all->player.py - (MS * 10 * (sin(all->player.pa - P_2)));
	}
	new_x = all->player.px;
	if (all->map.map[(int)(new_y) >> 6][(int)(new_x) >> 6] == '1')
		return (0);
	return (1);
}

int	move_variant2(t_all *all, int direction, int rev)
{
	float	new_x;
	float	new_y;

	if (direction == 2 || direction == 4)
	{
		new_x = all->player.px + (MS * 10 * rev * (cos(all->player.pa)));
	}
	else if (direction == 3)
	{
		new_x = all->player.px + (MS * 10 * (cos(all->player.pa + P_2)));
	}
	else
	{
		new_x = all->player.px + (MS * 10 *(cos(all->player.pa - P_2)));
	}
	new_y = all->player.py;
	if (all->map.map[(int)(new_y) >> 6][(int)(new_x) >> 6] == '1')
		return (0);
	return (1);
}