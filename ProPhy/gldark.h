#ifndef GLDARK_H
#define GLDARK_H

#include <QGLWidget>
#include <QtOpenGL>
#include <QtGui>
#include <gl/gl.h>
#include <gl/GLU.h>


class dark:public QGLWidget
{
    Q_OBJECT
public:
    void draw(GLfloat lenght,bool act);
    dark();
private:
    GLfloat x;
    GLfloat y;
    GLfloat z;
    void drawP(GLfloat width, GLfloat height, GLfloat lenght);
};


#endif // GLDARK_H
