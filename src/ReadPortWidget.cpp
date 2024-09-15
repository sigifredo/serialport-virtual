

// Own
#include <ReadPortWidget.hpp>
#include <SerialPort.hpp>

// Qt
#include <QBoxLayout>
#include <QDebug>
#include <QFile>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QTextEdit>

ReadPortWidget::ReadPortWidget(QWidget *pParent) : QWidget(pParent)
{
    configGUI();

    _pSerialPort = new SerialPort(this);

    connect(_pSerialPort, SIGNAL(dataRead(const QByteArray &)), this, SLOT(dataRead(const QByteArray &)));
}

void ReadPortWidget::dataRead(const QByteArray &data)
{
    _pTextEdit->append(QString(data).trimmed());
}

void ReadPortWidget::openPort()
{
    QString sPortPath = _pSerialPortLineEdit->text().trimmed();

    if (!sPortPath.isEmpty())
    {
        if (QFile::exists(sPortPath))
        {
            _pOpenPortButton->setEnabled(false);
            _pSerialPortLineEdit->setEnabled(false);
            _pSerialPort->setPortName(sPortPath);

            if (!_pSerialPort->openPort())
            {
                QMessageBox::critical(this, "Error", "No se ha podido abrir el puerto serial.");

                _pOpenPortButton->setEnabled(true);
                _pSerialPortLineEdit->setEnabled(true);
            }
        }
        else
        {
            QMessageBox::critical(this, "Error", "El purto serial no existe.");
        }
    }
    else
    {
        QMessageBox::critical(this, "Error", "No se ha establecido el puerto serial.");
    }
}

void ReadPortWidget::configGUI()
{
    QBoxLayout *pLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);

    _pTextEdit = new QTextEdit(this);

    QWidget *pPortPathWidget = new QWidget(this);
    {
        QBoxLayout *pLayout = new QBoxLayout(QBoxLayout::LeftToRight, pPortPathWidget);

        QLabel *pPortLabel = new QLabel("Puerto:", pPortPathWidget);
        _pSerialPortLineEdit = new QLineEdit("/dev/pts/6", pPortPathWidget);

        pLayout->addWidget(pPortLabel);
        pLayout->addWidget(_pSerialPortLineEdit);
    }

    _pOpenPortButton = new QPushButton("&Conectar", this);

    _pTextEdit->setReadOnly(true);

    connect(_pOpenPortButton, SIGNAL(clicked()), this, SLOT(openPort()));

    pLayout->addWidget(_pTextEdit);
    pLayout->addWidget(pPortPathWidget);
    pLayout->addWidget(_pOpenPortButton);
}
