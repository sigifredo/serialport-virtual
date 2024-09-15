

#ifndef PORTWIDGET_HPP
#define PORTWIDGET_HPP

// Qt
#include <QWidget>

// Own
#include <SerialPort.hpp>

class PortWidget : public QWidget
{
    Q_OBJECT

public:
    PortWidget(QWidget *pParent = nullptr);

    void openPort();
    SerialPort &serialPort();

protected:
    void closePort();
    virtual void dataRead(const QString &sData) = 0;
    bool openPort(const QString &sPortName, const SerialPort::OpenMode &openMode);

private:
    SerialPort *_pSerialPort;
};

#endif
