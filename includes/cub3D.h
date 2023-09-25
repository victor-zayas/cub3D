
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

typedef struct s_cub3D
{
    t_map s_map;
    t_attrb s_attbr;
} t_cub3D;

// PROTOTIPES
// CUB3D
int     ft_get_map(char *path);
char	**ft_split_map(t_map *map);
void	ft_init_attrb(t_attrb *attrb);
void	ft_check_init_poss(t_map *map, t_attrb *attrb);
void    ft_check_format(char *str);

// LIBFT
char	*ft_substr(char const *s, int start, int len);
char	**ft_split(char const *s, char c);
int	    ft_strlen(const char *str);
void	*ft_memset(void *str, int c, size_t len);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);