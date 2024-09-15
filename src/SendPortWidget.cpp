

// Own
#include <SendPortWidget.hpp>
#include <SerialPort.hpp>

// Qt
#include <QBoxLayout>
#include <QFile>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QSpinBox>
#include <QTextEdit>
#include <QTimerEvent>

// std
#include <random>

SendPortWidget::SendPortWidget(QWidget *pParent) : PortWidget(pParent)
{
    configGUI();

    _iTimerID = -1;
}

void SendPortWidget::dataRead(const QByteArray &data)
{
    _pTextEdit->append(QString(data).trimmed());
}

void SendPortWidget::timerEvent(QTimerEvent *pEvent)
{
    if (pEvent->timerId() == _iTimerID)
    {
        int iLeft = _pRangeLeft->value();
        int iRight = _pRangeRight->value();

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(iLeft, iRight);

        serialPort().write(QString::number(distrib(gen)).append("\n").toUtf8());
    }
}

void SendPortWidget::configGUI()
{
    QBoxLayout *pLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);

    QLabel *pTitleLabel = new QLabel("<h2>Enviar</h2>", this);
    _pTextEdit = new QTextEdit(this);

    _pControlsWidget = new QWidget(this);
    {
        QBoxLayout *pLayout = new QBoxLayout(QBoxLayout::TopToBottom, _pControlsWidget);

        QWidget *pRangeWidget = new QWidget(_pControlsWidget);
        {
            QBoxLayout *pLayout = new QBoxLayout(QBoxLayout::LeftToRight, pRangeWidget);

            QLabel *pRangeLabel = new QLabel("Rango", pRangeWidget);
            _pRangeLeft = new QSpinBox(pRangeWidget);
            _pRangeRight = new QSpinBox(pRangeWidget);

            _pRangeLeft->setMaximum(1000000);
            _pRangeRight->setMaximum(1000000);
            _pRangeRight->setValue(1000);

            pLayout->addWidget(pRangeLabel);
            pLayout->addWidget(_pRangeLeft);
            pLayout->addWidget(_pRangeRight);
        }

        QWidget *pPortPathWidget = new QWidget(_pControlsWidget);
        {
            QBoxLayout *pLayout = new QBoxLayout(QBoxLayout::LeftToRight, pPortPathWidget);

            QLabel *pPortLabel = new QLabel("Puerto:", pPortPathWidget);
            _pSerialPortLineEdit = new QLineEdit("/dev/pts/6", pPortPathWidget);

            pLayout->addWidget(pPortLabel);
            pLayout->addWidget(_pSerialPortLineEdit);
        }

        pLayout->addWidget(pRangeWidget);
        pLayout->addWidget(pPortPathWidget);
    }

    _pOpenPortButton = new QPushButton("&Conectar", _pControlsWidget);

    _pTextEdit->setReadOnly(true);

    auto openSlot = [&]()
    {
        _pControlsWidget->setEnabled(false);
        _pOpenPortButton->setEnabled(false);

        if (openPort(_pSerialPortLineEdit->text(), SerialPort::OpenMode::WriteOnly))
        {
            _pOpenPortButton->setEnabled(true);
            _pOpenPortButton->setText("&Desconectar");

            _iTimerID = startTimer(500);
        }
        else
        {
            _pOpenPortButton->setEnabled(true);
            _pControlsWidget->setEnabled(true);
        }
    };

    connect(_pOpenPortButton, &QPushButton::clicked, openSlot);

    pLayout->addWidget(pTitleLabel);
    pLayout->addWidget(_pTextEdit);
    pLayout->addWidget(_pControlsWidget);
    pLayout->addWidget(_pOpenPortButton);
}
