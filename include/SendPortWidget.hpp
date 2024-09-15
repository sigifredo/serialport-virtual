

#ifndef SENDPORTWIDGET_HPP
#define SENDPORTWIDGET_HPP

#include <PortWidget.hpp>

class QLineEdit;
class QPushButton;
class QSerialPort;
class QSpinBox;
class QTextEdit;

class SendPortWidget : public PortWidget
{
    Q_OBJECT

public:
    SendPortWidget(QWidget *pParent = nullptr);

protected:
    void dataRead(const QString &sData) override;
    void timerEvent(QTimerEvent *pEvent) override;

private:
    int _iTimerID;
    QLineEdit *_pSerialPortLineEdit;
    QPushButton *_pOpenPortButton;
    QSpinBox *_pRangeLeft;
    QSpinBox *_pRangeRight;
    QTextEdit *_pTextEdit;
    QWidget *_pControlsWidget;

    void configGUI();
};

#endif
