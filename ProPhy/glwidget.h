#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <QGLWidget>

class GLWidget: public QGLWidget
{
    Q_OBJECT
public:
    GLWidget();
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
};

#endif // GLWIDGET_H