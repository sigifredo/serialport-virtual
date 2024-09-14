

// Own
#include <ReadPortWidget.hpp>
#include <SerialPort.hpp>

// Qt
#include <QBoxLayout>
#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QTimerEvent>

ReadPortWidget::ReadPortWidget(QWidget *pParent) : QWidget(pParent)
{
    configGUI();

    _pSerialPort = new SerialPort(this);
}

void ReadPortWidget::openPort()
{
    QString sPortPath = _pSerialPortLineEdit->text().trimmed();

    if (!sPortPath.isEmpty())
    {
        _pOpenPortButton->setEnabled(false);
        _pSerialPortLineEdit->setEnabled(false);

        _pSerialPort->setPortName(sPortPath);

        if (_pSerialPort->openPort())
        {
        }
        else
        {
            // TODO: mostrar mensaje de error
        }
    }
    else
    {
        // TODO: mostrar mensaje de que el nombre del puerto está vacío
    }
}

void ReadPortWidget::configGUI()
{
    QBoxLayout *pLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);

    QTextEdit *pTextEdit = new QTextEdit(this);

    QWidget *pPortPathWidget = new QWidget(this);
    {
        QBoxLayout *pLayout = new QBoxLayout(QBoxLayout::LeftToRight, pPortPathWidget);

        QLabel *pPortLabel = new QLabel("Puerto:", pPortPathWidget);
        _pSerialPortLineEdit = new QLineEdit(pPortPathWidget);

        pLayout->addWidget(pPortLabel);
        pLayout->addWidget(_pSerialPortLineEdit);
    }

    _pOpenPortButton = new QPushButton("&Conectar", this);

    pTextEdit->setReadOnly(true);

    connect(_pOpenPortButton, SIGNAL(clicked()), this, SLOT(openPort()));

    pLayout->addWidget(pTextEdit);
    pLayout->addWidget(pPortPathWidget);
    pLayout->addWidget(_pOpenPortButton);
}
