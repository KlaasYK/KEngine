#include <QGuiApplication>
#include <QScreen>
#include <QRect>

#include <QDebug>

#include "window.h"

#define WIDTH 800
#define HEIGHT 600

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // Set OpenGL Version information
    // Note: This format must be set before show() is called.
    QSurfaceFormat format;
    format.setRenderableType(QSurfaceFormat::OpenGL);
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setVersion(3,3);

    // Set the window up
    Window window;
    window.setFormat(format);
    // Center the window on the screen
    QScreen *screen = app.primaryScreen();
    QRect size(screen->geometry());
    window.setGeometry(size.width()/2-(WIDTH/2),size.height()/2-(HEIGHT/2),WIDTH,HEIGHT);
    window.show();

    return app.exec();
}

