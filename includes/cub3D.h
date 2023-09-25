
#ifndef CUB3D_H
#define CUB3D_H
#endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_map
{
    char    **map;
    char    *name;
    int     fd;

} t_map;

// CUB3D
int    ft_get_map(char *path);
char	**ft_split_map(t_map *map);

// LIBFT
char	*ft_substr(char const *s, int start, int len);
char	**ft_split(char const *s, char c);
int	    ft_strlen(const char *str);
void	*ft_memset(void *str, int c, size_t len);