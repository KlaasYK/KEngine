#include "window.h"

#include <QDebug>
#include <QString>

#include <QTimer>
#include <QDateTime>

Window::Window()
{
    engine = new Engine();
}

Window::~Window()
{
    makeCurrent();
    teardownGL();
    delete engine;
    delete fpstimer;
}

void Window::initializeGL()
{
    // Initialize OpenGL Backend
    initializeOpenGLFunctions();
    printContextInformation();

    engine->initialize();

    // Set global information
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    fpstimer = new QTimer(this);
    connect(fpstimer, SIGNAL(timeout()), this, SLOT(calcFPS()));
    fpstimer->start(1000);

    frameCounter = 0;
    stepCounter = 0;

    QTimer::singleShot(0,this,SLOT(gameStep()));

}

void Window::resizeGL(int width, int height)
{
    // Currently we are not handling width/height changes
    (void)width;
    (void)height;
    update();
}

void Window::calcFPS()
{
    setTitle("FPS: " + QString::number(frameCounter) + " Steps: " + QString::number(stepCounter));
    frameCounter = 0;
    stepCounter = 0;
}

void Window::gameStep()
{
    engine->update();
    ++stepCounter;

    // test if calling paintGL works better, instead of scheduling?
    update();

    QTimer::singleShot(0,this,SLOT(gameStep()));
}

void Window::paintGL()
{
    // Clear
    glClear(GL_COLOR_BUFFER_BIT);

    engine->render();
    ++frameCounter;

}

void Window::teardownGL()
{
    engine->finalize();
    // TODO: other clean up?
}

void Window::printContextInformation()
{
    QString glVersion;
    // Get Version Information
    glVersion = reinterpret_cast<const char*>(glGetString(GL_VERSION));
    qDebug() << "OpenGL version:" << qPrintable(glVersion);
}
