/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_evolution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:57:10 by lagonzal          #+#    #+#             */
/*   Updated: 2023/11/22 12:33:18 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	change_color(t_all *all);

void	color_evo(void *param)
{
	t_all	*all;

	all = (t_all *)param;
	while (1)
	{
		change_color(all);
		usleep(5000000);
		printf("waited\n");
	}
}

void	change_color(t_all *all)
{
	static int	hour;
	float		r;

	printf("time is %d\n", hour);
	pthread_mutex_lock(&all->mut);
	if (hour >= 6 && hour < 10)
	{
		r = (hour - 6) / 4.0;
		all->texture.c = (((int)(255 * r)) << 16)
			| (((int)(255 * r)) << 8) | (((int)(255 * r)));
	}
	else if (hour >= 10 && hour < 16)
		all->texture.c = ((0) << 16) | ((150 & 255) << 8) | ((255));
	else if (hour >= 16 && hour < 20)
	{
		r = (hour - 16) / 4.0;
		all->texture.c = ((255 - (int)(255 * r)) << 16)
			| ((150 - (int)(50 * r)) << 8) | ((255 - (int)(155 * r)));
	}
	else
		all->texture.c = ((0) << 16) | ((0) << 8) | (50);
	pthread_mutex_unlock(&all->mut);
	hour++;
	if (hour > 23)
		hour = 0;
}
