
#ifndef CUB3D_H
#define CUB3D_H
#endif

// INCLUDES
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

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

// PROTOTIPES

