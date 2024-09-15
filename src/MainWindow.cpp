

// Own
#include <MainWindow.hpp>
#include <ReadPortWidget.hpp>
#include <SendPortWidget.hpp>
#include <VersionWidget.hpp>

// Qt
#include <QBoxLayout>

MainWindow::MainWindow(QWidget *pParent)
    : QMainWindow(pParent)
{
    QWidget *pCentralWidget = new QWidget(this);
    QBoxLayout *pLayout = new QBoxLayout(QBoxLayout::TopToBottom, pCentralWidget);

    QWidget *pSerialWidget = new QWidget(pCentralWidget);
    {
        QBoxLayout *pLayout = new QBoxLayout(QBoxLayout::LeftToRight, pSerialWidget);

        SendPortWidget *pSendPortWidget = new SendPortWidget(pSerialWidget);
        ReadPortWidget *pReadPortWidget = new ReadPortWidget(pSerialWidget);

        pLayout->addWidget(pSendPortWidget);
        pLayout->addWidget(pReadPortWidget);
    }
    VersionWidget *pVersionWidget = new VersionWidget(pCentralWidget);

    pLayout->addWidget(pSerialWidget);
    pLayout->addWidget(pVersionWidget);

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
