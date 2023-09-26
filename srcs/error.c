
#include"../includes/cub3D.h"

void	ft_check_fd(int fd)
{
	if (fd < 0 || fd == 2)
	{
		close(fd);
		printf("Error: Invalid fd\n");
		exit(1);
	}
}

void	ft_check_format(char *str)
{
	if (!ft_strnstr(str, ".cub", ft_strlen(str)))
	{
		printf("invalid format\n");
		exit(1);
	}
}

void	ft_empty_map(t_map *map)
{
	if (ft_get_map(map->name) == 1)
	{
		printf("empty map\n");
		exit (1);
	}
}