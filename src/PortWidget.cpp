

// Own
#include <PortWidget.hpp>
#include <SerialPort.hpp>

// Qt
#include <QFile>
#include <QMessageBox>

#ifdef Q_OS_WIN
#define fileExist(X) true
#else
#define fileExist(X) QFile::exists(X)
#endif

PortWidget::PortWidget(QWidget *pParent) : QWidget(pParent)
{
    _pSerialPort = new SerialPort(this);

    auto dataReadSlot = [&](const QByteArray &data)
    {
        QString sData = QString(data)
                            .trimmed()
                            .replace("\n", " ");

        dataRead(sData);
    };

    connect(_pSerialPort, &SerialPort::dataRead, dataReadSlot);
}

void PortWidget::closePort()
{
    _pSerialPort->closePort();
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
        if (fileExist(sPortPath))
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
            QMessageBox::critical(this, "Error", "El puerto serial no existe.");
            return false;
        }
    }
}

SerialPort &PortWidget::serialPort()
{
    return *_pSerialPort;
}
