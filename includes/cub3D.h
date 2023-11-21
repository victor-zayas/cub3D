/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:10:29 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/11/21 17:01:57 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// MACROS
# define PI  3.1415926
# define P2  2 * PI
# define P_2 PI / 2
# define P3_2 PI * 3 / 2
# define P_4 PI / 4
# define P3_4 PI * 3 / 4
# define P5_4 PI * 5 / 4
# define P7_4 PI * 7 / 4
# define DEG 2 * PI / 360
# define ANGLE 90 * DEG
# define HEIGHT 540
# define WIDTH 1080
# define C_WIDTH 1080 / 90
# define HOP DEG * C_WIDTH
# define FOV_A 60
# define FOV_R FOV_A * DEG

// KEYCODES
# define W 13
# define S 1
# define D 2
# define A 0
# define RA 124
# define LA 123
# define ESC 53

// MOVE SPEED
# define MS 5
# define MF 10
# define RS 0.1

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
	char	**raw;
	char	**map;
	char	*name;
	int		fd;
	int		height;
	int		width;
}	t_map;

typedef struct s_attrb
{
	int	n;
	int	s;
	int	e;
	int	w;
}	t_attrb;

typedef struct s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		c;
	int		f;
}	t_texture;

typedef struct s_playerpos
{
	float	py;
	float	px;
	float	pa;
}	t_playerpos;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size;
	int		end;
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
	float	ra;
	float	ry;
	float	rx;
	float	xo;
	float	yo;
	int		mx;
	int		my;
	float	cx;
	float	cy;
	char	tx;
	float	dist;
	int		end;
	int		height;
}	t_ray;

typedef struct s_all
{
	t_img		north;
	t_img		south;
	t_img		east;
	t_img		west;
	t_map		map;
	t_attrb		attrb;
	t_texture	texture;
	t_playerpos	player;
	t_img		img;
	t_mlx		mlx;
	t_ray		ray;
}	t_all;

// PROTOTIPES
// -INITIAL
void	ft_init_struct(t_all *all, char *name);

// MAP
// -GET_MAP
int		ft_read_map(t_map *map);
void	ft_get_data(t_map *map);
void	ft_get_map(t_map *map, t_attrb *attrb);
void	ft_parse(t_all *all);
// -CHECK_MAP
void	ft_check_map(t_map *map, t_attrb *attrb);
void	ft_map_dimensions(t_map *map);
void	ft_check_wall(t_map *map);
// -CHECK_ATTRB
void	ft_check_attrb(t_map *map, t_attrb *attrb);

// MLX
// -KEYHOOKS
void	keyrelease(int keycode, t_all *all);
void	keypress(int keycode, t_all *all);
void	move(t_all *all);
void	move_manage(t_all *all);

// TEXTURE
// -GE_TEXTURE
void	ft_get_texture(t_map *map, t_texture *texture);
void	ft_check_texture(t_texture *texture);
void	ft_get_color(t_map *map, t_texture *texture);
// -CHECK_COLOR
void	ft_check_texture(t_texture *texture);
int		*ft_check_color(char *str);
// -MLX IMG
void	ft_get_img(t_all *all);
void	ft_free_img(t_all *all);

// ERROR
// -ERROR
void	ft_exit(char *str);
void	ft_check_fd(int fd);
void	ft_check_read(int rd);
void	ft_check_extension(char *str);
void	ft_check_ext_texture(char *str);
void	ft_empty_map(t_map *map);
void	ft_close(void *all);

//	RAYCAST
//	-RAYCASTER
void	raycaster(t_all *all);
//	-DISTACE
float	dist(t_ray *ray, t_playerpos *p_pos);
float	fix_angle(float angle);
float	absolute(float in);
//	-LINE FIXER
void	fix_fisheye(t_ray *ray, t_playerpos *p_pos);

//	DRAW
//	-DRAW_COLUMNS
void	draw_column(t_ray *col, t_all *all, t_mlx *mlx, int i);
void	floor_ceil(t_mlx *mlx, int *start, int color, int i);
int		calc_height(t_ray *ray);
void	draw_wall(t_ray *col, t_all *all, int *start_stop, int i);
void	get_mlx(t_mlx *mlx);
void	search_playerpos(char **map, t_playerpos *p_pos);

#endif
