#include<GL/glut.h>
#include <cmath>

void drawCircle(float x,float y,float r,float red,float green,float blue,int slice=40){
    glColor3f(red,green,blue);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x,y);
        for(int i=0;i<=slice;i++){
            float angle = 2.0 * 3.1415926 * i/slice;
            glVertex2f(x+r*cosf(angle),y+r*sinf(angle));
        }
    glEnd();
}
void drawTriangle(float x1,float y1,float x2,float y2,float x3,float y3,float red,float green,float blue){
    glColor3f(red,green,blue);
    glBegin(GL_TRIANGLES);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
        glVertex2f(x3,y3);
    glEnd();
}
void drawRec(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4,float red,float green,float blue){
    glColor3f(red,green,blue);
    glBegin(GL_POLYGON);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
        glVertex2f(x3,y3);
        glVertex2f(x4,y4);
    glEnd();
}
void drawHome(){
    //Main body
    drawRec(150.0,150.0,350.0,150.0,350.0,250.0,150.0,250.0,0.80, 0.52, 0.25);

    //door
    drawRec(225.0,150.0,275.0,150.0,275.0,220.0,225.0,220.0,1.0, 0.0, 0.0);

    //door lock
    drawCircle(270.0,185.0,2.5,1.0,1.0,0.0);

    // Left window
    drawRec(160.0,170.0,205.0,170.0,205.0,215.0,160.0,215.0,1.0, 0.0, 0.0);
    drawRec(165.0,175.0,180.0,175.0,180.0,190.0,165.0,190.0,0.53,0.81,0.92);
    drawRec(185.0,175.0,200.0,175.0,200.0,190.0,185.0,190.0,0.53,0.81,0.92);
    drawRec(165.0,195.0,180.0,195.0,180.0,210.0,165.0,210.0,0.53,0.81,0.92);
    drawRec(185.0,195.0,200.0,195.0,200.0,210.0,185.0,210.0,0.53,0.81,0.92);
    
    // Right Window
    drawRec(295.0,170.0,340.0,170.0,340.0,215.0,295.0,215.0,1.0, 0.0, 0.0);
    drawRec(300.0,175.0,315.0,175.0,315.0,190.0,300.0,190.0,0.53,0.81,0.92);
    drawRec(320.0,175.0,335.0,175.0,335.0,190.0,320.0,190.0,0.53,0.81,0.92);
    drawRec(300.0,195.0,315.0,195.0,315.0,210.0,300.0,210.0,0.53,0.81,0.92);
    drawRec(320.0,195.0,335.0,195.0,335.0,210.0,320.0,210.0,0.53,0.81,0.92);

    // Roof
    drawTriangle(140.0,250.0,360.0,250.0,250.0,310.0,1.0, 0.0, 0.0);

    // Pipe
    drawRec(295.0,255.0,310.0,255.0,310.0,300.0,295.0,300.0,0.82, 0.41, 0.12);

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

    // Sun
    drawCircle(90.0,400.0,40.0,1.0,1.0,0.0);

    // cloud
    drawCircle(380.0,400.0,25,1.0,1.0,1.0);
    drawCircle(420.0,400.0,35,1.0,1.0,1.0);
    drawCircle(460.0,400.0,25,1.0,1.0,1.0);

    // green field
    drawRec(0.0,0.0,500.0,0.0,500.0,150.0,0.0,150.0,0.0,0.42,0.31);

    // Draw house
    drawHome();

    glutSwapBuffers();
}
int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutInitWindowPosition(50,50);
    glutInitWindowSize(500,500);
    glutCreateWindow("Simple Home");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
}