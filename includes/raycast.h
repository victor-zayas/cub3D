/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <larraingonzalez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:59:45 by lagonzal          #+#    #+#             */
/*   Updated: 2023/10/19 17:59:45 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# define PI  3.1415926
# define P2 PI / 2
# define P32 PI * 3 / 2
# define DEG 0.0174533

typedef struct s_txt
{
	void	*img;	//pointer to the img of the texture
	char	*addr;	//address pointer to the img
	int		bpp;	//bits per pixel of the mlx image
	int		size;	//size from mlx image
	int		endian;	//endian from mlx image
}	t_txt;

typedef struct s_ray
{
	float	ra;		//ray angle
	float	ry;		//ray first collision y coordinate
	float	rx;		//ray first collision x coordinate
	float	xo; 	//collision offset in x
	float	yo;		//collision offset in y
	int		mx;		//maps x position of the colision
	int		my; 	//maps y position of the colision
	float	cx;		//collision position y
	float	cy;		//collision position x
	char	tx;		//texture type
	t_txt	txt;	//a pointer to 
	int		end;	//signals the raycasting to end
}   t_ray;

typedef struct s_playerpos
{
	float	py;	//players y coordinate in map (take into account sprite size)
	float	px; //players x coordinate in map (take into account sprite size)
	float	pa;	//players angle in radians
}	t_playerpos;


//	RAYCAST
//	-RAYCASTER
t_ray	check_h_colision(t_playerpos *p_pos, t_map *map, float ra);
t_ray	check_v_colision(t_playerpos *p_pos, t_map *map, float ra);
//	-DISTACE
float	dist(float rx, float ry, t_playerpos *p_pos, int end);
float	fix_angle(float	angle);

#endif