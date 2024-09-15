

// Own
#include <MainWindow.hpp>
#include <Version.hpp>

// Qt
#include <QApplication>
#include <QFile>

// std
#include <iostream>

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
    mw.setWindowTitle("Serialport GUI v" PROJECT_VERSION);
    mw.show();

    return app.exec();
}
