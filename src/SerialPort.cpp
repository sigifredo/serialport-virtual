

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
    // QTextStream out(stdout);

    // Listar todos los puertos seriales disponibles
    // const auto serialPortInfos = QSerialPortInfo::availablePorts();
    // out << "Puertos seriales disponibles:" << endl;
    // for (const QSerialPortInfo &info : serialPortInfos)
    //     out << info.portName() << " " << info.description() << endl;

    // Configuración del puerto serial
    // pSerialPort->setPortName("COM3");                // Cambia por el nombre de tu puerto
    _pSerialPort->setBaudRate(QSerialPort::Baud9600); // Velocidad
    _pSerialPort->setDataBits(QSerialPort::Data8);
    _pSerialPort->setParity(QSerialPort::NoParity);
    _pSerialPort->setStopBits(QSerialPort::OneStop);
    _pSerialPort->setFlowControl(QSerialPort::NoFlowControl);

    /*
    // Abrir el puerto
    if (!pSerialPort->open(QIODevice::ReadOnly))
    {
        qCritical() << QObject::tr("No se puede abrir el puerto %1, error %2")
                           .arg(serialPort.portName())
                           .arg(serialPort.errorString());
        return 1;
    }

    // Leer los datos de manera asíncrona
    QObject::connect(&serialPort, &QSerialPort::readyRead, [&]()
                     {
        QByteArray data = serialPort.readAll();
        out << "Datos recibidos: " << data << endl; });
    */
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
