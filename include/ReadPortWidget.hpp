

#ifndef READPORTWIDGET_HPP
#define READPORTWIDGET_HPP

#include <QWidget>

class QLineEdit;
class QPushButton;
class QSerialPort;
class QTextEdit;
class SerialPort;

class ReadPortWidget : public QWidget
{
    Q_OBJECT

public:
    ReadPortWidget(QWidget *pParent = nullptr);

protected slots:
    void dataRead(const QByteArray &data);
    void openPort();

private:
    QLineEdit *_pSerialPortLineEdit;
    QPushButton *_pOpenPortButton;
    QTextEdit *_pTextEdit;
    SerialPort *_pSerialPort;

    void configGUI();
};

#endif
