

#ifndef SERIALPORT_HPP
#define SERIALPORT_HPP

#include <QObject>
#include <QSerialPortInfo>

class QSerialPort;

class SerialPort : public QObject
{
    Q_OBJECT
public:
    SerialPort(QObject *pParent = nullptr);

    QList<QSerialPortInfo> availablePorts();
    void openPort();

    void setPortName(const QString &sPortName);

private:
    QSerialPort *_pSerialPort;
};

#endif
