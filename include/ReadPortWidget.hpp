

#ifndef READPORTWIDGET_HPP
#define READPORTWIDGET_HPP

#include <QWidget>

class QLineEdit;
class QPushButton;

class ReadPortWidget : public QWidget
{
    Q_OBJECT

public:
    ReadPortWidget(QWidget *pParent = nullptr);

protected slots:
    void openPort();

private:
    QLineEdit *_pSerialPath;
    QPushButton *_pOpenPortButton;
};

#endif