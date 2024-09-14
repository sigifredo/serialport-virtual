

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
    bool openPort();

    void setPortName(const QString &sPortName);

signals:
    void dataRead(const QByteArray &data);

private:
    QSerialPort *_pSerialPort;
};

#endif
