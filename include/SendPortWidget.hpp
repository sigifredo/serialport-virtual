

#ifndef SENDPORTWIDGET_HPP
#define SENDPORTWIDGET_HPP

#include <PortWidget.hpp>

class QLineEdit;
class QPushButton;
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
    QWidget *_pControlsWidget;
    QPushButton *_pOpenPortButton;
    QSpinBox *_pRangeLeft;
    QSpinBox *_pRangeRight;
    QLineEdit *_pSerialPortLineEdit;
    QTextEdit *_pTextEdit;

    void configGUI();
};

#endif
