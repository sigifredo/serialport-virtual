/**
 * SerialPort GUI: is a tool for reading and writing data via a serial port.
 * Copyright (C) 2024 Sigifredo Escobar Gómez
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

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
