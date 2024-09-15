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

#ifndef SERIALPORT_HPP
#define SERIALPORT_HPP

#include <QObject>

class QSerialPort;

class SerialPort : public QObject
{
    Q_OBJECT
public:
    enum OpenMode
    {
        ReadOnly,
        WriteOnly
    };

    SerialPort(QObject *pParent = nullptr);

    void closePort();
    bool openPort(const OpenMode &openMode);

    void setPortName(const QString &sPortName);
    qint64 write(const QByteArray &data);

signals:
    void dataRead(const QByteArray &data);

private:
    QSerialPort *_pSerialPort;
};

#endif
