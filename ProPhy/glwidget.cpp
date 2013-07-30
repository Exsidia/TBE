#include <QtOpenGL>
#include <QtGui>
#include <gl/gl.h>
#include <gl/GLU.h>
#include <stdio.h>
#include "glwidget.h"
#include "gldark.h"

GLfloat rtri = 0.0f;
GLfloat zxz = 0.0f;

GLuint texture[1];
void change();
GLWidget::GLWidget(GLfloat Lenght)
{
    timer = new QTimer();
    lenght = Lenght;
    connect(timer,SIGNAL(timeout()),this,SLOT(updateGL()));
    xRot = 0;
    yRot = 0;
    zRot = 0;
    scale = 1.0f;
}

void GLWidget::initializeGL()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glShadeModel(GL_SMOOTH);
    glClearColor(1.0f,1.0f,1.0f,0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_CLIP_PLANE0);
    glEnable(GL_BLEND);
    glEnable(GL_LINE_SMOOTH);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(-1.0f,0.0f,-15.0f);
    glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
    glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
    glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);
    glRotatef(rtri,0.0f,1.0f,0.0f);
    glScalef(scale,scale,scale);
    if(timer->isActive())
    {
        templar->draw(lenght, true);
        rtri+=0.2f;
    }
    else
        templar->draw(lenght, false);
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

void GLWidget::wheelEvent(QWheelEvent *event)
{
    event->delta() > 0 ? scale += scale*0.1f : scale -= scale*0.1f;
    updateGL();
}

void GLWidget::resizeGL(int width, int height)
{
    if(0 == height)
        height = 1;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void GLWidget::StartAn()
{
    timer->start(20);
}

void GLWidget::StopAn()
{
    timer->stop();
}

void GLWidget::setL(float l)
{
    lenght = l;
}

/*AUX_RGBImageRec *LoadBMP(char *filename)
{
    FILE *file = NULL;
    if(!filename)
    {
        return NULL;
    }
    file = fopen(filename, "r");
    if(file)
    {
        fclose(file);
        return auxDIBImageLoad(filename);
    }
    return NULL;
}

int LoadGLTextures()
{
    int status = FALSE;
    AUX_RGBImageRec *TextureImage[1];
    memset(TextureImage, 0, sizeof(void*)*1);
    if(TextureImage[0] = LoadBMP("LOAD.bmp"))
    {
        status = TRUE;
        glGenTextures(1,&texture[0]);
        glBindTexture(GL_TEXTURE_2D, texture[0]);
        glTexImage2D(GL_TEXTURE_2D,0,3,TextureImage[0]->sizeX,TextureImage[0]->sizeY,0,GL_RGB,
                     GL_UNSIGNED_BYTE,TextureImage[0]->data);
    }
}
*/
