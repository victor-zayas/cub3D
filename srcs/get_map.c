
#include"../includes/cub3D.h"

int ft_get_map(char *path)
{
	int		rd;
	int		fd;
	int		i;
	char	c;

    i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0 || fd == 2)
		return (0);
	rd = 1;
	while ((rd = read(fd, &c, 1)) > 0)
        i++;
	close(fd);
    return (i);
}

void	ft_split_map(t_map *map)
{
	char	*aux;
	int		i;
	int		rd = 0;

	i = 0;
	aux = malloc(sizeof(char) * ft_get_map(map->name));
	map->fd = open(map->name, O_RDONLY);
	rd = read(map->fd, aux, ft_get_map(map->name));
	ft_empty_map(map);
	aux[rd - 1] = '\0';
	while (aux[i])
	{
		if (aux[i] == '\n')
		{
			if (aux[i + 1] && aux[i + 1] == '\n')
			{
				printf("Error: emptyline in map\n");
				exit(1);
			}
		}
		i++;
	}
	map->map = ft_split(aux, '\n');
	close(map->fd);
	free(aux);
}
