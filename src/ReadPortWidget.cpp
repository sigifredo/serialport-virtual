

// Own
#include <ReadPortWidget.hpp>

// Qt
#include <QBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>

ReadPortWidget::ReadPortWidget(QWidget *pParent) : QWidget(pParent)
{
    QBoxLayout *pLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);

    QTextEdit *pTextEdit = new QTextEdit(this);
    _pSerialPath = new QLineEdit("/dev/pts/6", this);
    _pOpenPortButton = new QPushButton("&Conectar", this);

    pTextEdit->setReadOnly(true);

    connect(_pOpenPortButton, SIGNAL(clicked()), this, SLOT(openPort()));

    pLayout->addWidget(pTextEdit);
    pLayout->addWidget(_pSerialPath);
    pLayout->addWidget(_pOpenPortButton);
}

void ReadPortWidget::openPort()
{
    _pOpenPortButton->setEnabled(false);
    _pSerialPath->setEnabled(false);
}