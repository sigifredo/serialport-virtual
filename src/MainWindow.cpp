

// Own
#include <MainWindow.hpp>
#include <VersionWidget.hpp>

// Qt
#include <QBoxLayout>
#include <QFileInfo>
#include <QLabel>
#include <QMessageBox>
#include <QTextStream>

MainWindow::MainWindow(QWidget *pParent)
    : QMainWindow(pParent)
{
    /*
    #if defined(Q_OS_WIN)
        setWindowIcon(QIcon(":/app-icons/serialport-gui.ico"));
    #elif defined(Q_OS_MACOS)
        setWindowIcon(QIcon(":/app-icons/serialport-gui.icns"));
    #else
        setWindowIcon(QIcon(":/app-icons/serialport-gui.png"));
    #endif
    */
}
