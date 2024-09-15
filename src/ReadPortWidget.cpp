

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

ReadPortWidget::ReadPortWidget(QWidget *pParent) : PortWidget(pParent)
{
    configGUI();

    connect(&serialPort(), SIGNAL(dataRead(const QByteArray &)), this, SLOT(dataRead(const QByteArray &)));
}

void ReadPortWidget::dataRead(const QByteArray &data)
{
    _pTextEdit->append(QString(data).trimmed());
}

void ReadPortWidget::configGUI()
{
    QBoxLayout *pLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);

    QLabel *pTitleLabel = new QLabel("<h2>Leer</h2>", this);
    _pTextEdit = new QTextEdit(this);

    QWidget *pPortPathWidget = new QWidget(this);
    {
        QBoxLayout *pLayout = new QBoxLayout(QBoxLayout::LeftToRight, pPortPathWidget);

        QLabel *pPortLabel = new QLabel("Puerto:", pPortPathWidget);
        _pSerialPortLineEdit = new QLineEdit("/dev/pts/5", pPortPathWidget);

        pLayout->addWidget(pPortLabel);
        pLayout->addWidget(_pSerialPortLineEdit);
    }

    _pOpenPortButton = new QPushButton("&Conectar", this);

    _pTextEdit->setReadOnly(true);

    auto openSlot = [&]()
    {
        _pOpenPortButton->setEnabled(false);
        _pSerialPortLineEdit->setEnabled(false);

        if (openPort(_pSerialPortLineEdit->text(), SerialPort::OpenMode::ReadOnly))
        {
            _pOpenPortButton->setEnabled(true);
            _pOpenPortButton->setText("&Desconectar");
        }
        else
        {
            _pOpenPortButton->setEnabled(true);
            _pSerialPortLineEdit->setEnabled(true);
        }
    };

    connect(_pOpenPortButton, &QPushButton::clicked, openSlot);

    pLayout->addWidget(pTitleLabel);
    pLayout->addWidget(_pTextEdit);
    pLayout->addWidget(pPortPathWidget);
    pLayout->addWidget(_pOpenPortButton);
}
