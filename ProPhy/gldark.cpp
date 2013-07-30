#include "gldark.h"

GLUquadricObj *quadratic;
GLfloat gg = 0;
const float V = 0;
dark::dark()
{

}

void dark::draw(GLfloat lenght, bool act)
{
    glTranslatef(0.0f,0.0f,-2.0f);
    float radius = 0.5;
    float hight = 2;
    float angle = 0.0;
    const float PI2 = 3.141593 * 2;
    quadratic = gluNewQuadric();
    gluQuadricNormals(quadratic, GLU_SMOOTH);
    gluQuadricTexture(quadratic, GL_TRUE);
    GLdouble equation[4] = {0.0,0.0,1.0,0.0};
    glClipPlane(GL_CLIP_PLANE0,equation);
    glDisable(GL_CLIP_PLANE0);
    glTranslatef(0,0,gg);
    glBegin(GL_LINES);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.0f,-gg);
    glEnd();
    gluSphere(quadratic,0.05,32,32);
    glTranslatef(0,0,-gg);
    if(true == act)
    gg+=0.1f;
    if(gg>10.0f)
        gg = 0;
    /*glBegin(GL_TRIANGLE_STRIP);
    for(float i = 0.0; i <= 512; i++)
    {
        angle = PI2 * (float)i / (float)512;
        glColor4f(1.0f,1.0f,0.f,1.0f);
        glVertex3f(radius*cos(angle), 0, radius*sin(angle));
        glColor4f(0.0f,1.0f,1.0f,0.1f);
        glVertex3f(radius*cos(angle), hight, radius*sin(angle));
    }
    glEnd();*/
    glColor4d(0.0f,0.5f,0.5f,0.4f);
    glTranslatef(0.0f,0.0f,2.0f);
    gluDisk(quadratic,0.1f,1.0f,128,128);//D
    glTranslatef(-0.5f,0.3f,1.0f);
    drawP(1.0f,0.05f,2.0f);//C
    glTranslatef(0.5f,-0.3f,-1.0f);
    glTranslatef(-0.5f,-0.35f,1.0f);
    drawP(1.0f,0.05f,2.0f);
    glTranslatef(0.5f,0.35f,-1.0f);
    glTranslatef(0.0f,0.0f,-2.0f);
    glColor4d(1.0f,0.0f,0.5f,1.0f);
    //gluCylinder(quadratic,0.1f,0.1f,7.0f,128,128);
    glColor4d(1.0f,0.5f,0.5f,0.4f);
    gluCylinder(quadratic,1.0f,1.0f,4.0f,128,128);
    glColor4f(1.0f,0.5f,0.0f,0.5f);
    gluSphere(quadratic,1.0f,32,32);
    glTranslatef(0.0f,0.0f,4.0f);
    gluCylinder(quadratic,1.0f,3.0f,lenght,128,128);//моп
    glTranslatef(0.0f,0.0f,lenght);
    glEnable(GL_CLIP_PLANE0);
    glColor4f(0.0f,0.5f,0.5f,0.5f);
    glClipPlane(GL_CLIP_PLANE0,equation);
    glTranslatef(0.0f,0.0f,-9.54f);
    gluSphere(quadratic,10,128,128);
    glDisable(GL_CLIP_PLANE0);
}


void dark::drawP(GLfloat width, GLfloat lenght, GLfloat height)
{
    glBegin(GL_POLYGON);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(width,0.0f,0.0f);
    glVertex3f(width,0.0f,height);
    glVertex3f(0.0f,0.0f,height);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,lenght,0.0f);
    glVertex3f(0.0f,lenght,height);
    glVertex3f(0.0f,0.0f,height);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,lenght,0.0f);
    glVertex3f(width,lenght,0.0f);
    glVertex3f(width,0.0f,0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(width,0.0f,0.0f);
    glVertex3f(width,0.0f,height);
    glVertex3f(width,lenght,height);
    glVertex3f(width,lenght,0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(width,lenght,0.0f);
    glVertex3f(width,lenght,height);
    glVertex3f(0.0f,lenght,height);
    glVertex3f(0.0f,lenght,0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.0f,lenght,height);
    glVertex3f(0.0f,0.0f,height);
    glVertex3f(width,0.0f,height);
    glVertex3f(width,lenght,height);
    glEnd();

    glFlush();
}

