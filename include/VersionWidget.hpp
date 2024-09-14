

#ifndef VERSIONWIDGET_HPP
#define VERSIONWIDGET_HPP

// Qt
#include <QWidget>

class VersionWidget : public QWidget
{
    Q_OBJECT

public:
    VersionWidget(QWidget *pParent = nullptr);

public slots:
    void showCredits();
};

#endif
