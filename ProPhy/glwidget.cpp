#include <QtOpenGL>
#include <QtGui>
#include <gl/gl.h>
#include <gl/GLU.h>
#include "glwidget.h"

GLfloat rtri = 0.0f;
GLUquadricObj *quadratic;
GLWidget::GLWidget()
{
    timeID = startTimer(20);
    xRot = 0;
    yRot = 0;
    zRot = 0;
}

void GLWidget::initializeGL()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    quadratic = gluNewQuadric();
    gluQuadricNormals(quadratic, GLU_SMOOTH);
    gluQuadricTexture(quadratic, GL_TRUE);
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(-0.5f,0.0f,-6.0f);
    glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
    glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
    glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);
    glRotatef(rtri,0.0f,1.0f,0.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(0.0f,1.0f,0.0f);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(-1.0f,-1.0f,1.0f);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(1.0f,-1.0f,1.0f);

    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(0.0f,1.0f,0.0f);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(1.0f,-1.0f,1.0f);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(1.0f,-1.0f,-1.0f);

    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(0.0f,1.0f,0.0f);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(1.0f,-1.0f,-1.0f);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(-1.0f,-1.0f,-1.0f);

    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(0.0f,1.0f,0.0f);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(-1.0f,-1.0f,-1.0f);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(-1.0f,-1.0f,1.0f);
    glEnd();

    float radius = 0.5;
    float hight = 2;
    float angle = 0.0;
    const float PI2 = 3.141593 * 2;

    glBegin(GL_TRIANGLE_STRIP);
    for(float i = 0.0; i <= 50; i++)
    {
        angle = PI2 * (float)i / (float)50;
        glColor4f(1.0f,1.0f,0.f,1.0f);
        glVertex3f(radius*cos(angle), 0, radius*sin(angle));
        glColor4f(0.0f,1.0f,1.0f,0.1f);
        glVertex3f(radius*cos(angle), hight, radius*sin(angle));
    }
    glEnd();

    glColor4d(1.0f,0.0f,0.5f,0.4f);
    gluCylinder(quadratic,1.0f,1.0f,2.0f,512,512);
    rtri+=0.2f;
}

static void qNormalizeAngle(int &angle)
{
    while(angle < 0)
        angle += 360*16;
    while(angle > 360*16)
        angle -= 360*16;
}

void GLWidget::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if(angle != xRot)
    {
        xRot = angle;
        emit xRotationChanged(angle);
        updateGL();
    }
}

void GLWidget::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if(angle != yRot)
    {
        yRot = angle;
        emit yRotationChanged(angle);
        updateGL();
    }
}

void GLWidget::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if(angle != zRot)
    {
        zRot = angle;
        emit xRotationChanged(angle);
        updateGL();
    }
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();
    if(event->buttons()&Qt::LeftButton)
    {
        setXRotation(xRot+8*dy);
        setYRotation(yRot+8*dx);
    }
    else
        if(event->buttons()&Qt::RightButton)
        {
            setXRotation(zRot+8*dy);
            setZRotation(zRot+8*dx);
        }
    lastPos = event->pos();
}

void GLWidget::resizeGL(int width, int height)
{
    if(0 == height)
        height = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
