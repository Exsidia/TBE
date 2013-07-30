#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <QGLWidget>
#include <QtOpenGL>

class dark;
class GLWidget: public QGLWidget
{
    Q_OBJECT
public:
    GLWidget(GLfloat lenght);
    void setL(float l);
public slots:
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);
    void StartAn();
    void StopAn();
signals:
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);
    void timeout();
protected:
    void timerEvent(QTimerEvent *){update();}
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
private:
    int timeID;
    int xRot;
    int yRot;
    int zRot;
    float scale;
    GLfloat lenght;

    GLuint pbufferList;
    QGLFramebufferObject *fbo;
    QPoint lastPos;
    dark *templar;
    QTimer *timer;
};

#endif // GLWIDGET_H
