

#ifndef READPORTWIDGET_HPP
#define READPORTWIDGET_HPP

#include <PortWidget.hpp>

class QLineEdit;
class QPushButton;
class QTextEdit;

class ReadPortWidget : public PortWidget
{
    Q_OBJECT

public:
    ReadPortWidget(QWidget *pParent = nullptr);

protected:
    void dataRead(const QString &sData) override;

private:
    QWidget *_pControlsWidget;
    QPushButton *_pOpenPortButton;
    QLineEdit *_pSerialPortLineEdit;
    QTextEdit *_pTextEdit;

    void configGUI();
};

#endif
