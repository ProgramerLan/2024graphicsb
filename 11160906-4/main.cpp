#include <GL/glut.h>
#include <stdio.h>
int N = 0;
float teapotX[1000], teapotY[1000];
void display()
{
    glClearColor(1,1,0.9,1);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(0,1,0);
    for(int i=0;i<N;i++){
    glPushMatrix();
        glTranslatef(teapotX[i],teapotY[i],0);
        glutSolidTeapot(0.1);
    glPopMatrix();
    }
    glutSwapBuffers();
}
void keyboard(unsigned char key, int x, int y)
{
    printf("key: %c x:%d y:%d\n", key,x,y);
}
void mouse(int button,int state,int x, int y)
{
    teapotX[N]=(x-150)/150.0;
    teapotY[N]=-(y-150)/150.0;
    N++;
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE| GLUT_DEPTH);
    glutCreateWindow("week4 keyboard mouse motion");
    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMainLoop();
}
