

#ifndef READPORTWIDGET_HPP
#define READPORTWIDGET_HPP

#include <QWidget>

class QComboBox;
class QPushButton;
class QSerialPort;
class SerialPort;

class ReadPortWidget : public QWidget
{
    Q_OBJECT

public:
    ReadPortWidget(QWidget *pParent = nullptr);

protected:
    void timerEvent(QTimerEvent *pEvent) override;

protected slots:
    void openPort();
    void portFound(const QString &sPath);

private:
    QComboBox *_pSerialsComboBox;
    QPushButton *_pOpenPortButton;
    SerialPort *_pSerialPort;

    void configGUI();
};

#endif
