

// Own
#include <VersionWidget.hpp>
#include <CreditsDialog.hpp>
#include <Version.hpp>

// Qt
#include <QBoxLayout>
#include <QPushButton>

VersionWidget::VersionWidget(QWidget *pParent)
    : QWidget(pParent)
{
    QBoxLayout *pLayout = new QBoxLayout(QBoxLayout::LeftToRight, this);
    QPushButton *pVersionButton = new QPushButton("Version v" PROJECT_VERSION, this);

    connect(pVersionButton, SIGNAL(clicked()), this, SLOT(showCredits()));

    pLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));
    pLayout->addWidget(pVersionButton);
    pLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));
}

void VersionWidget::showCredits()
{
    CreditsDialog().exec();
}
