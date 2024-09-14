

// Own
#include <ReadPortWidget.hpp>
#include <SerialPort.hpp>

// Qt
#include <QBoxLayout>
#include <QComboBox>
#include <QDebug>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QTimerEvent>

ReadPortWidget::ReadPortWidget(QWidget *pParent) : QWidget(pParent)
{
    configGUI();

    _pSerialPort = new SerialPort(this);

    startTimer(1000);
}

void ReadPortWidget::timerEvent(QTimerEvent *pEvent)
{
    killTimer(pEvent->timerId());

    auto ports = _pSerialPort->availablePorts();

    for (auto &portInfo : ports)
    {
        _pSerialsComboBox->addItem(portInfo.portName());
    }
}

void ReadPortWidget::openPort()
{
    _pOpenPortButton->setEnabled(false);
}

void ReadPortWidget::portFound(const QString &sPath)
{
    _pSerialsComboBox->addItem(sPath);
}

void ReadPortWidget::configGUI()
{
    QBoxLayout *pLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);

    QTextEdit *pTextEdit = new QTextEdit(this);

    QWidget *pPortPathWidget = new QWidget(this);
    {
        QBoxLayout *pLayout = new QBoxLayout(QBoxLayout::LeftToRight, pPortPathWidget);

        QLabel *pPortLabel = new QLabel("Port:", pPortPathWidget);
        _pSerialsComboBox = new QComboBox(pPortPathWidget);

        pLayout->addWidget(pPortLabel);
        pLayout->addWidget(_pSerialsComboBox);
    }

    _pOpenPortButton = new QPushButton("&Conectar", this);

    pTextEdit->setReadOnly(true);

    connect(_pOpenPortButton, SIGNAL(clicked()), this, SLOT(openPort()));

    pLayout->addWidget(pTextEdit);
    pLayout->addWidget(pPortPathWidget);
    pLayout->addWidget(_pOpenPortButton);
}
