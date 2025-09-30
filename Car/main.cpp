#include<GL/glut.h>
#include<cmath>
void drawRec(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4,float red,float green,float blue){
    glColor3f(red,green,blue);
    glBegin(GL_POLYGON);
        glVertex2i(x1,y1);
        glVertex2i(x2,y2);
        glVertex2i(x3,y3);
        glVertex2i(x4,y4);
    glEnd();
}
void drawTriangle(int x1,int y1,int x2,int y2,int x3,int y3,float red,float green,float blue){
    glColor3f(red,green,blue);
    glBegin(GL_TRIANGLES);
        glVertex2i(x1,y1);
        glVertex2i(x2,y2);
        glVertex2i(x3,y3);
    glEnd();
}
void drawCircle(float x,float y,float r,float red,float green,float blue,int slice=80){
    glColor3f(red,green,blue);

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x,y);
        for(int i=0;i<=slice;i++){
            float angle = 2.0 * 3.1416 * i/slice;
            glVertex2f(x+r*cosf(angle),y+r*sinf(angle));
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
    glClearColor(0.53,0.81,0.92,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawRec(0,0,500,0,500,150,0,150,0.83, 0.83, 0.83);

    drawCircle(102.0,200.0,30.0,0.86, 0.08, 0.24);
    drawRec(100,170,400,170,400,230,100,230,0.86, 0.08, 0.24);

    drawTriangle(75,190,90,200,75,210,0.83, 0.83, 0.83);

    drawCircle(140.0,170.0,20.0,0.0,0.0,0.0);
    drawCircle(360.0,170.0,20.0,0.0,0.0,0.0);
    drawCircle(360.0,170.0,14.0,0.83, 0.83, 0.83);
    drawCircle(140.0,170.0,14.0,0.83, 0.83, 0.83);



    drawRec(160,230,360,230,340,280,180,280,0.86, 0.08, 0.24);

    drawRec(170,230,255,230,255,275,190,275,0.53,0.81,0.92);
    drawRec(265,230,350,230,330,275,265,275,0.53,0.81,0.92);


    glutSwapBuffers();
}
int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutInitWindowPosition(50,50);
    glutInitWindowSize(500,500);
    glutCreateWindow("CAR");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
}
