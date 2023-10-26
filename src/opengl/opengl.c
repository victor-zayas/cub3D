#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "cub3D.h"
#include "raycast.h"

t_playerpos *g_p_pos;

void    drawPlayer()
{
    glColor3f(1, 1, 0);
    glPointSize(8);
    glBegin(GL_POINTS);
    glVertex2i(g_p_pos->px, g_p_pos->py);
    glEnd();
}

void    display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawPlayer();
}

void    buttons(unsigned char key, int x, int y)
{
    if (key == 'a')
        g_p_pos->px -=5;
    if (key == 'd')
        g_p_pos->px +=5;
    if (key == 'w')
        g_p_pos->py -=5;
    if (key == 's')
        g_p_pos->py +=5;
    glutPostRedisplay();
}

void    search_playerpos(char **map, t_playerpos *p_pos)
{
    int n;
    int m;
    int found;

    n = 0;
    found = 0;
    while (map[n] && !found)
    {
        while (map[n][m] && !found)
        {
            if (map[n][m] == 'N')
            {
                p_pos->py = 64 * m + 32;
                p_pos->px = 64 * n + 32;
                p_pos->pa = P2;
                found = 1;
            }
            else if (map[n][m] == 'E')
            {
                p_pos->py = 64 * m + 32;
                p_pos->px = 64 * n + 32;
                p_pos->pa = 0;
                found = 1;

            }
            else if (map[n][m] == 'W')
            {
                p_pos->py = 64 * m + 32;
                p_pos->px = 64 * n + 32;
                p_pos->pa = PI;
                found = 1;
            }
            else if (map[n][m] == 'S')
            {
                p_pos->py = 64 * m + 32;
                p_pos->px = 64 * n + 32;
                p_pos->pa = P32;
                found = 1;
            }
        }
    }
}

void    init()
{
    glClearColor(0.3, 0.3, 0.3, 0);
    gluOrtho2D(0, 1024, 512, 0);
}

void    openGL(int argc, char **argv, t_all *all)
{  
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1024, 512);
    glutCreateWindow("RAYCASTING");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(buttons);
    glutMainLoop();
}

int	main(int argc, char **argv)
{
	t_all	all;
    t_playerpos p_pos;


	if (argc == 2)
	{
		ft_init_struct(&all, argv[1]);
		ft_parse(&all);
        search_playerpos(all.map.map, &p_pos);
        g_p_pos = &p_pos;
        openGL(argc, argv, &all);
	}
	else
		printf("Error\nExpected two arguments, have %d\n", argc);
}