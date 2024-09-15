

#ifndef SENDPORTWIDGET_HPP
#define SENDPORTWIDGET_HPP

#include <PortWidget.hpp>

class QLineEdit;
class QPushButton;
class QSerialPort;
class QTextEdit;

class SendPortWidget : public PortWidget
{
    Q_OBJECT

public:
    SendPortWidget(QWidget *pParent = nullptr);

protected slots:
    void dataRead(const QByteArray &data);

private:
    QLineEdit *_pSerialPortLineEdit;
    QPushButton *_pOpenPortButton;
    QTextEdit *_pTextEdit;
    QWidget *_pControlsWidget;

    void configGUI();
};

#endif
