

// Own
#include <PortWidget.hpp>
#include <SerialPort.hpp>

// Qt
#include <QFile>
#include <QMessageBox>

PortWidget::PortWidget(QWidget *pParent) : QWidget(pParent)
{
    _pSerialPort = new SerialPort(this);

    // connect(_pSerialPort, SIGNAL(dataRead(const QByteArray &)), this, SLOT(dataRead(const QByteArray &)));
}

bool PortWidget::openPort(const QString &sPortName, const SerialPort::OpenMode &openMode)
{
    QString sPortPath = sPortName.trimmed();

    if (!sPortPath.isEmpty())
    {
        if (QFile::exists(sPortPath))
        {
            if (_pSerialPort->openPort(openMode))
            {
                return true;
            }
            else
            {
                QMessageBox::critical(this, "Error", "No se ha podido abrir el puerto serial.");

                return false;
            }
        }
        else
        {
            QMessageBox::critical(this, "Error", "El purto serial no existe.");
            return false;
        }
    }
    else
    {
        QMessageBox::critical(this, "Error", "No se ha establecido el puerto serial.");
        return false;
    }
}

SerialPort &PortWidget::serialPort()
{
    return *_pSerialPort;
}
