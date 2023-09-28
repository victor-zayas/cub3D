
#include"../includes/cub3D.h"

void    ft_free_strcut(t_map *map)
{
    int i;

    i = 0;
    if (map->map)
    {
        while (map->map[i])
            free(map->map[i++]);
        free(map->map);
    }
    free(map);
}
