#include "window.h"

#include <QDebug>
#include <QString>

Window::~Window()
{
    makeCurrent();
    teardownGL();
}

/*******************************************************************************
 * OpenGL Events
 ******************************************************************************/

void Window::initializeGL()
{
    // Initialize OpenGL Backend
    initializeOpenGLFunctions();
    printContextInformation();

    // Set global information
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Window::resizeGL(int width, int height)
{
    // Currently we are not handling width/height changes
    (void)width;
    (void)height;
    update();
}

void Window::paintGL()
{
    // Clear
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::teardownGL()
{
    // Currently we have no data to teardown
}

/*******************************************************************************
 * Private Helpers
 ******************************************************************************/

void Window::printContextInformation()
{
    QString glVersion;
    // Get Version Information
    glVersion = reinterpret_cast<const char*>(glGetString(GL_VERSION));
    qDebug() << "OpenGL version:" << qPrintable(glVersion);
}
