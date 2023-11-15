/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:33:30 by lagonzal          #+#    #+#             */
/*   Updated: 2023/11/15 12:58:37 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void keyrelease(int keycode, t_all *all)
{
    if (keycode == RA)
        all->player.pa -= 0.01;
    else if (keycode == LA)
        all->player.pa += 0.1;
}