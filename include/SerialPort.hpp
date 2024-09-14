

#ifndef SERIALPORT_HPP
#define SERIALPORT_HPP

#include <QObject>

class SerialPort : public QObject
{
    Q_OBJECT
public:
    SerialPort(QObject *pParent = nullptr);
};

#endif
