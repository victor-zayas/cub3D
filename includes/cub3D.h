/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:10:29 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/10/12 01:52:56 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// INCLUDES
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

// STRUCTS
typedef struct s_map
{
    char    **raw; // raw data from .cub file
    char    **map; // map of game
    char    *name; // name of .cub
    int     fd; // fd of .cub
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
    char    *C; // RGB color code for ceiling
    char    *F; // RGB color code for floor
} t_texture;

typedef struct s_all
{
    t_map       map;
    t_attrb     attrb;
    t_texture   texture;
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
void	ft_start(t_all *all);

// -CHECK MAP
void	ft_check_map(t_map *map, t_attrb *attrb);

// TEXTURE
// -GE TEXTURE
void	ft_get_texture(t_map *map, t_texture *texture);
void	ft_check_texture(t_texture *texture);
void	ft_get_color(t_map *map, t_texture *texture);
// -CHECK COLOR
void	ft_check_texture(t_texture *texture);
void    ft_check_color(char *str);

// -ERROR
void	ft_check_fd(int fd);
void	ft_check_read(int rd);
void	ft_check_extension(char *str);
void	ft_check_ext_texture(char *str);
void	ft_empty_map(t_map *map);

#endif

// |**** EXTENSION ****|
// EX: Wrong extension. ✅

// |**** TEXTURES ****|
// TE1: One texture missing (EA) ✅
// TE2: Texture path (WE) does not exist 

// |**** FLOOR - CEILING ****|
// One parameter missing in ceiling color 
// Floor rgb metric out of range 0 - 255 (333) ✅
// invalid character (a) in floor ✅

// |**** MAP ****|
// Invalid character in map ✅
// map wall is 0 ✅
// new line in map ✅
// map not in last position ✅
// empty map ✅

// TODO LIST
// check mlx functions to use RGB color
// lean how to change textures depending on direction
// learn about raycasting

    // make mlx window
    // close mlx windows with red x & ESC case
    // use mlx to make movement with direction arrows
    // use mlx to rotate camera with WASD
    