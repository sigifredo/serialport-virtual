

#ifndef SERIALPORT_HPP
#define SERIALPORT_HPP

#include <QObject>

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

    void closePort();
    bool openPort(const OpenMode &openMode);

    void setPortName(const QString &sPortName);
    qint64 write(const QByteArray &data);

signals:
    void dataRead(const QByteArray &data);

private:
    QSerialPort *_pSerialPort;
};

#endif
