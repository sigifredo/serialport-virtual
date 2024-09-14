

// Own
#include <MainWindow.hpp>
#include <Version.hpp>

// Qt
#include <QApplication>
#include <QFile>
#include <QScreen>

// std
#include <iostream>

QRect centerGeometry();

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QFile styleFile(":/styles.qss");

    if (styleFile.open(QFile::ReadOnly))
    {
        app.setStyleSheet(QLatin1String(styleFile.readAll()));
    }
    else
    {
        std::cerr << "[Error] Could not open style file." << std::endl;
    }

    MainWindow mw;
    mw.setGeometry(centerGeometry());
    mw.setWindowTitle("Teleprompter v" PROJECT_VERSION);
    mw.show();

    return app.exec();
}

QRect centerGeometry()
{
    QRect screenGeometry = QGuiApplication::primaryScreen()->geometry();

    int screenWidth = screenGeometry.width();
    int screenHeight = screenGeometry.height();

    int windowWidth = screenWidth * 0.3;
    int windowHeight = screenHeight * 0.5;

    int posX = (screenWidth - windowWidth) / 2;
    int posY = (screenHeight - windowHeight) / 2;

    return QRect(posX, posY, windowWidth, windowHeight);
}
