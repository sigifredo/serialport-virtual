

#ifndef READPORTWIDGET_HPP
#define READPORTWIDGET_HPP

#include <PortWidget.hpp>

class QLineEdit;
class QPushButton;
class QSerialPort;
class QTextEdit;

class ReadPortWidget : public PortWidget
{
    Q_OBJECT

public:
    ReadPortWidget(QWidget *pParent = nullptr);

protected:
    void dataRead(const QByteArray &data) override;

private:
    QLineEdit *_pSerialPortLineEdit;
    QPushButton *_pOpenPortButton;
    QTextEdit *_pTextEdit;

    void configGUI();
};

#endif
