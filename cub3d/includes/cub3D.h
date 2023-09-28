/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:10:29 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/09/28 20:07:12 by vzayas-s         ###   ########.fr       */
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
    char    **map;
    char    *name;
    int     fd;

} t_map;

typedef struct s_attrb
{
    int n;
    int s;
    int e;
    int w;
} t_attrb;

typedef struct s_texture
{
    char    *NO;
    char    *SO;
    char    *WE;
    char    *EA;
} t_texture;

// PROTOTIPES
// MAIN
// INITIAL
void    ft_init_map(t_map *map, char *name);
void	ft_init_attrb(t_attrb *attrb);

// MAP
// GET MAP
int     ft_read_map(t_map *map);
void	ft_get_map(t_map *map);
void	ft_split_args(t_map *map, t_texture *texture);
// CHECK MAP
void	ft_check_map(t_map *map, t_attrb *attrb);
void	ft_get_textutes(t_map *map, t_texture *texture);

// ERROR
void	ft_check_fd(int fd);
void	ft_check_format(char *str);
void	ft_empty_map(t_map *map);
