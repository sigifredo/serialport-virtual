

// Own
#include <SerialPort.hpp>

// Qt
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTextStream>

SerialPort::SerialPort(QObject *pParent)
    : QObject(pParent)
{
    _pSerialPort = new QSerialPort(this);

    _pSerialPort->setBaudRate(QSerialPort::Baud9600); // Velocidad
    _pSerialPort->setDataBits(QSerialPort::Data8);
    _pSerialPort->setParity(QSerialPort::NoParity);
    _pSerialPort->setStopBits(QSerialPort::OneStop);
    _pSerialPort->setFlowControl(QSerialPort::NoFlowControl);

    auto slot = [&]()
    {
        auto data = _pSerialPort->readAll();
        emit dataRead(data);
        qDebug() << "Datos recibidos: " << data;
    };

    connect(_pSerialPort, &QSerialPort::readyRead, slot);
}

QList<QSerialPortInfo> SerialPort::availablePorts()
{
    return QSerialPortInfo::availablePorts();
}

void SerialPort::openPort()
{
    if (_pSerialPort->open(QIODevice::ReadOnly))
    {
        qDebug() << QObject::tr("Se abre el puerto %1").arg(_pSerialPort->portName());
    }
    else
    {
        qCritical() << QObject::tr("No se puede abrir el puerto %1, error %2")
                           .arg(_pSerialPort->portName())
                           .arg(_pSerialPort->errorString());
    }
}

void SerialPort::setPortName(const QString &sPortName)
{
    _pSerialPort->setPortName(sPortName);
}
