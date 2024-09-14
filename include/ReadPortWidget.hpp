

#ifndef READPORTWIDGET_HPP
#define READPORTWIDGET_HPP

#include <QWidget>

class QLineEdit;
class QPushButton;
class QSerialPort;
class SerialPort;

class ReadPortWidget : public QWidget
{
    Q_OBJECT

public:
    ReadPortWidget(QWidget *pParent = nullptr);

protected slots:
    void openPort();

private:
    QLineEdit *_pSerialPortLineEdit;
    QPushButton *_pOpenPortButton;
    SerialPort *_pSerialPort;

    void configGUI();
};

#endif
