
// Own
#include <CreditsDialog.hpp>
#include <Version.hpp>

// Qt
#include <QGridLayout>
#include <QLabel>
#include <QTextEdit>
#include <QTabWidget>
#include <QDialogButtonBox>

CreditsDialog::CreditsDialog(QWidget *pParent)
    : QDialog(pParent)
{
    QBoxLayout *pLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);

    QWidget *pInfoWidget = new QWidget(this);
    {
        QBoxLayout *pLayout = new QBoxLayout(QBoxLayout::LeftToRight, pInfoWidget);
        QLabel *pIconLabel = new QLabel(pInfoWidget);
        QLabel *pAppInfoLabel = new QLabel(pInfoWidget);

        pLayout->setSpacing(10);
        pIconLabel->setPixmap(QPixmap(QString::fromUtf8(":/s9art.png")));
        pIconLabel->setAlignment(Qt::AlignCenter);
        pAppInfoLabel->setText("<h2>" PROJECT_NAME "</h2>" + QString::fromUtf8("Project version: ") + PROJECT_VERSION "<br>Qt version: " + qVersion());

        pLayout->addWidget(pIconLabel);
        pLayout->addWidget(pAppInfoLabel);
        pLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));
    }

    QTabWidget *pTabWidget = new QTabWidget(this);
    {
        QWidget *pAboutTabWidget = new QWidget(pTabWidget);
        {
            QBoxLayout *pLayout = new QBoxLayout(QBoxLayout::LeftToRight, pAboutTabWidget);
            QLabel *pDescriptionLabel = new QLabel(pAboutTabWidget);

            QString sDescription = QString::fromUtf8(PROJECT_NAME " is an application designed to... This software is distributed under the terms of the GNU\nGeneral Public License.");
            pDescriptionLabel->setText(sDescription);

            pLayout->addWidget(pDescriptionLabel);
        }

        QWidget *pAuthorTabWidget = new QWidget(pTabWidget);
        {
            QBoxLayout *pLayout = new QBoxLayout(QBoxLayout::TopToBottom, pAuthorTabWidget);
            QLabel *pAuthorLabel = new QLabel(pAuthorTabWidget);

            pAuthorLabel->setText("<strong>Sigifredo Escobar Gómez</strong><br><em>Developer</em><br><a href=\"https://s9art.com/links/\">https://s9art.com/links/</a>");

            pLayout->addWidget(pAuthorLabel);
        }

        QWidget *pLicenceTabWidget = new QWidget(pTabWidget);
        {
            QVBoxLayout *pLayout = new QVBoxLayout(pLicenceTabWidget);
            QTextEdit *pLicenceTextEdit = new QTextEdit(pLicenceTabWidget);

            pLicenceTextEdit->setReadOnly(true);
            pLicenceTextEdit->setHtml(QString::fromUtf8(
                "<strong>" PROJECT_NAME ":</strong> add short description here.<br>Copyright (C) 2024 Sigifredo Escobar Gómez<br><br>This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.<br><br>This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.<br><br>You should have received a copy of the GNU General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>."));

            pLayout->addWidget(pLicenceTextEdit);
        }

        pTabWidget->addTab(pAboutTabWidget, "About");
        pTabWidget->addTab(pAuthorTabWidget, "Author");
        pTabWidget->addTab(pLicenceTabWidget, "Licence");
    }

    QDialogButtonBox *pButtonBox = new QDialogButtonBox(this);
    pButtonBox->setOrientation(Qt::Horizontal);
    pButtonBox->setStandardButtons(QDialogButtonBox::Close);

    connect(pButtonBox, SIGNAL(rejected()), this, SLOT(reject()));

    pLayout->addWidget(pInfoWidget);
    pLayout->addWidget(pTabWidget);
    pLayout->addWidget(pButtonBox);

    setWindowTitle("About " PROJECT_NAME);
}
