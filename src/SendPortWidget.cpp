

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

SendPortWidget::SendPortWidget(QWidget *pParent) : QWidget(pParent)
{
    configGUI();

    _pSerialPort = new SerialPort(this);

    connect(_pSerialPort, SIGNAL(dataRead(const QByteArray &)), this, SLOT(dataRead(const QByteArray &)));
}

void SendPortWidget::dataRead(const QByteArray &data)
{
    _pTextEdit->append(QString(data).trimmed());
}

void SendPortWidget::openPort()
{
    QString sPortPath = _pSerialPortLineEdit->text().trimmed();

    if (!sPortPath.isEmpty())
    {
        if (QFile::exists(sPortPath))
        {
            _pControlsWidget->setEnabled(false);
            _pOpenPortButton->setEnabled(false);

            _pSerialPort->setPortName(sPortPath);

            if (!_pSerialPort->openPort())
            {
                QMessageBox::critical(this, "Error", "No se ha podido abrir el puerto serial.");

                _pControlsWidget->setEnabled(true);
                _pOpenPortButton->setEnabled(true);
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
            QSpinBox *pRangeLeft = new QSpinBox(pRangeWidget);
            QSpinBox *pRangeRight = new QSpinBox(pRangeWidget);

            pRangeLeft->setMaximum(1000000);
            pRangeRight->setMaximum(1000000);

            pLayout->addWidget(pRangeLabel);
            pLayout->addWidget(pRangeLeft);
            pLayout->addWidget(pRangeRight);
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

    connect(_pOpenPortButton, SIGNAL(clicked()), this, SLOT(openPort()));

    pLayout->addWidget(pTitleLabel);
    pLayout->addWidget(_pTextEdit);
    pLayout->addWidget(_pControlsWidget);
    pLayout->addWidget(_pOpenPortButton);
}
