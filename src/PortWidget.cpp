

// Own
#include <PortWidget.hpp>
#include <SerialPort.hpp>

// Qt
#include <QFile>
#include <QMessageBox>

PortWidget::PortWidget(QWidget *pParent) : QWidget(pParent)
{
    _pSerialPort = new SerialPort(this);
}

bool PortWidget::openPort(const QString &sPortName, const SerialPort::OpenMode &openMode)
{
    QString sPortPath = sPortName.trimmed();

    if (sPortPath.isEmpty())
    {
        QMessageBox::critical(this, "Error", "No se ha establecido el puerto serial.");
        return false;
    }
    else
    {
        if (QFile::exists(sPortPath))
        {
            _pSerialPort->setPortName(sPortPath);

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
}

SerialPort &PortWidget::serialPort()
{
    return *_pSerialPort;
}
