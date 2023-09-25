
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

void    ft_init_map(t_map **map)
{
    *map = malloc(sizeof(t_map));
    if (*map == NULL)
        return ;
    (*map)->name = NULL;
    (*map)->fd = -1;
}

void	ft_check_fd(int fd)
{
	if (fd < 0 || fd == 2)
	{
		close(fd);
		printf("Error: Invalid fd\n");
		exit(1);
	}
}

int main(int argc, char **argv)
{
    t_map *map;
    int i = 0;

    if (argc > 1)
    {
        map = NULL;
        ft_init_map(&map);
        map->fd = open(argv[1], O_RDONLY);
        ft_check_fd(map->fd);
        map->name = argv[1];
        map->map = ft_split_map(map);
        while (map->map[i])
            printf("%s\n", map->map[i++]);
        ft_free_strcut(map);
    }
    else
        printf("map not selectet\n");
}
