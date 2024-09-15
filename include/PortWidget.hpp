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

#ifndef PORTWIDGET_HPP
#define PORTWIDGET_HPP

// Qt
#include <QWidget>

// Own
#include <SerialPort.hpp>

class PortWidget : public QWidget
{
    Q_OBJECT

public:
    PortWidget(QWidget *pParent = nullptr);

    void openPort();
    SerialPort &serialPort();

protected:
    void closePort();
    virtual void dataRead(const QString &sData) = 0;
    bool openPort(const QString &sPortName, const SerialPort::OpenMode &openMode);

private:
    SerialPort *_pSerialPort;
};

#endif
