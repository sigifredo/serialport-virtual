

#ifndef SERIALPORT_HPP
#define SERIALPORT_HPP

#include <QObject>
#include <QSerialPortInfo>

class QSerialPort;

class SerialPort : public QObject
{
    Q_OBJECT
public:
    enum OpenMode
    {
        ReadOnly,
        WriteOnly
    };

    SerialPort(QObject *pParent = nullptr);

    QList<QSerialPortInfo> availablePorts();
    bool openPort(const OpenMode &openMode);

    void setPortName(const QString &sPortName);

signals:
    void dataRead(const QByteArray &data);

private:
    QSerialPort *_pSerialPort;
};

#endif
