

#ifndef SENDPORTWIDGET_HPP
#define SENDPORTWIDGET_HPP

#include <QWidget>

class QLineEdit;
class QPushButton;
class QSerialPort;
class QTextEdit;
class SerialPort;

class SendPortWidget : public QWidget
{
    Q_OBJECT

public:
    SendPortWidget(QWidget *pParent = nullptr);

protected slots:
    void dataRead(const QByteArray &data);
    void openPort();

private:
    QLineEdit *_pSerialPortLineEdit;
    QPushButton *_pOpenPortButton;
    QTextEdit *_pTextEdit;
    QWidget *_pControlsWidget;
    SerialPort *_pSerialPort;

    void configGUI();
};

#endif
