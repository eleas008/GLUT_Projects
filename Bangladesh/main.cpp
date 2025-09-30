#include<GL/glut.h>
#include <cmath>

void drawCircle(float x,float y,float r,float red,float green,float blue,int slice=40){
    glColor3f(red,green,blue);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x,y);
        for(int i=0;i<=slice;i++){
            float angel = 2.0 * 3.1415926 * i/slice;
            glVertex2f(x+r*cosf(angel),y+r*sinf(angel));
        }
    glEnd();
}

void reshape(int w,int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,w,0,h);
    glMatrixMode(GL_MODELVIEW);
}
void display(){
    glClearColor(0.0,0.42,0.31,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawCircle(350.0,300.0,170.0,1.0,0.0,0.0);

    glutSwapBuffers();
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutInitWindowPosition(20,20);
    glutInitWindowSize(1000,600);
    glutCreateWindow("Bangladesh");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
}
