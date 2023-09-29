/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:10:29 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/09/29 13:25:20 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H
#endif

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
// INITIAL
void	ft_init_struct(t_all *all, char *name);

// MAP
// GET MAP
int     ft_read_map(t_map *map);
void	ft_get_data(t_map *map);
void	ft_start(t_map *map, t_texture *texture);
// CHECK MAP
void	ft_check_map(t_map *map, t_attrb *attrb);
// CHECK TEXTURE
void	ft_get_texture(t_map *map, t_texture *texture);

// ERROR
void	ft_check_fd(int fd);
void	ft_check_read(int rd);
void	ft_check_format(char *str);
void	ft_empty_map(t_map *map);
