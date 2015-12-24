#ifndef WINDOW_H
#define WINDOW_H

#include <QOpenGLWindow>
#include <QOpenGLFunctions>
#include <QTimer>

#include "engine.h"

class Window : public QOpenGLWindow,
                protected QOpenGLFunctions
{
    Q_OBJECT

// OpenGL Events
public:
    Window();
    ~Window();

    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void teardownGL();

private slots:
    void gameStep();
    void calcFPS();

private:
    Engine* engine;
    int frameCounter;
    int stepCounter;
    QTimer *fpstimer;

    // Private Helpers
    void printContextInformation();

};

#endif // WINDOW_H
