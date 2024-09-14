

// Own
#include <MainWindow.hpp>
#include <ReadPortWidget.hpp>
#include <VersionWidget.hpp>

// Qt
#include <QBoxLayout>

MainWindow::MainWindow(QWidget *pParent)
    : QMainWindow(pParent)
{
    QWidget *pCentralWidget = new QWidget(this);
    QBoxLayout *pLayout = new QBoxLayout(QBoxLayout::TopToBottom, pCentralWidget);

    ReadPortWidget *pReadPortWidget = new ReadPortWidget(pCentralWidget);

    pLayout->addWidget(pReadPortWidget);

    setCentralWidget(pCentralWidget);

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
