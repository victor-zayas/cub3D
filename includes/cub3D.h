/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:10:29 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/10/26 17:26:05 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// MACROS
# define PI  3.1415926
# define P2 PI / 2
# define P32 PI * 3 / 2
# define DEG 0.0174533
# define HEIGHT 520
# define WIDTH 1080

// INCLUDES
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"

// STRUCTS
typedef struct s_map
{
    char    **raw;	// raw data from .cub file
    char    **map;	// map of game
    char    *name;	// name of .cub
    int     fd; 	// fd of .cub
    int     height;
    int     width;
} t_map;

typedef struct s_attrb
{
    int n; // North start possition
    int s; // South start possition
    int e; // East start possition
    int w; // West start possition
} t_attrb;

typedef struct s_texture
{
    char    *NO; // North texture path
    char    *SO; // South texture path
    char    *WE; // East texture path
    char    *EA; // West texture path
    int    *C;	// RGB color code for ceiling
    int    *F;	// RGB color code for floor
} t_texture;

typedef struct s_playerpos
{
	float	py;	//players y coordinate in map (take into account sprite size)
	float	px; //players x coordinate in map (take into account sprite size)
	float	pa;	//players angle in radians
}	t_playerpos;

typedef struct s_img
{
	// North
	void	*img_NO;	//pointer to the img of the texture
	char	*addr_NO;	//address pointer to the img
	int		bpp_NO;		//bits per pixel of the mlx image
	int		size_NO;	//size from mlx image
	int		end_NO;		//endian from mlx image
	// South
	void	*img_SO;
	char	*addr_SO;
	int		bpp_SO;
	int		size_SO;
	int		end_SO;
	// East
	void	*img_EA;
	char	*addr_EA;
	int		bpp_EA;
	int		size_EA;
	int		end_EA;
	// West
	void	*img_WE;
	char	*addr_WE;
	int		bpp_WE;
	int		size_WE;
	int		end_WE;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		size;
	int		endian;
}	t_mlx;

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
	float	dist;	//distance to the collision point
	int		end;	//signals the raycasting to end
}   t_ray;

typedef struct s_all
{
    t_map       map;
    t_attrb     attrb;
    t_texture   texture;
    t_playerpos player;
	t_img		img;
	t_mlx		mlx;
	t_ray		ray;
} t_all;

// PROTOTIPES
// MAIN
// -INITIAL
void	ft_init_struct(t_all *all, char *name);

// MAP
// -GET MAP
int     ft_read_map(t_map *map);
void	ft_get_data(t_map *map);
void	ft_get_map(t_map *map, t_attrb *attrb);
void	ft_parse(t_all *all);
// -CHECK MAP
void	ft_check_map(t_map *map, t_attrb *attrb);
// -CHECK_ATTRB
void	ft_check_attrb(t_map *map, t_attrb *attrb);

// TEXTURE
// -GE TEXTURE
void	ft_get_texture(t_map *map, t_texture *texture);
void	ft_check_texture(t_texture *texture);
void	ft_get_color(t_map *map, t_texture *texture);
// -CHECK COLOR
void	ft_check_texture(t_texture *texture);
int     *ft_check_color(char *str);

// -ERROR
void	ft_check_fd(int fd);
void	ft_check_read(int rd);
void	ft_check_extension(char *str);
void	ft_check_ext_texture(char *str);
void	ft_empty_map(t_map *map);

//	RAYCAST
//	-RAYCASTER
void	raycaster(t_playerpos *p_pos, t_all *all, t_mlx *mlx);

//	-DISTACE
float	dist(t_ray *ray, t_playerpos *p_pos);
float	fix_angle(float	angle);
//	-LINE FIXER
void	fix_fisheye(t_ray *ray, t_playerpos *p_pos);
//	DRAW
//	-DRAW_COLUMNS
void	draw_column(t_ray *col, t_all *all, t_mlx *mlx, int i);
void	get_mlx(t_mlx *mlx);
void    search_playerpos(char **map, t_playerpos *p_pos);

#endif
