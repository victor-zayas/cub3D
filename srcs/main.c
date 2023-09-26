
#include"../includes/cub3D.h"

int main(int argc, char **argv)
{
    t_map *map;
    t_attrb attrb;
    int i = 0;

    if (argc > 1)
    {
        map = NULL;
        ft_init_map(&map);
        ft_init_attrb(&attrb);
        map->name = argv[1];
        ft_check_format(map->name);
        map->fd = open(argv[1], O_RDONLY);
        ft_check_fd(map->fd);
        ft_split_map(map);
        // ft_empty_map(map);
        ft_check(map, &attrb);
        while (map->map[i])
            printf("%s\n", map->map[i++]);
        ft_free_strcut(map);
    }
    else
        printf("map not selectet\n");
}
