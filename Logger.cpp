//
//  Logger.cpp
//  Sentinel Logger
//
//  Created by Matoi on 01.01.2024.
//  https://github.com/MatoiDev/Sentinel-Logger
//

#include "Arduino.h"
#include "Logger.h"

void Logger::log(String data) {
    data.trim();
    if (data.startsWith("page")) {
        if (__use_software_serial)
            this->__software_serial->print(data);
        else
            this->__hardware_serial->print(data);
        this->__send_packet();
    } else {
        String logData = String("lastLog.txt=") + "\"" + data + "\"";
        if (__use_software_serial)
            this->__software_serial->print(logData);
        else
            this->__hardware_serial->print(logData);

        this->__send_packet();
        if (__use_software_serial)
            this->__software_serial->print("tm0.en=1");
        else
            this->__hardware_serial->print("tm0.en=1");

        this->__send_packet();
    }
}

void Logger::__send_packet() {
    if (__use_software_serial) {
        this->__software_serial->write(0xFF);
        this->__software_serial->write(0xFF);
        this->__software_serial->write(0xFF);
    } else {
        this->__hardware_serial->write(0xFF);
        this->__hardware_serial->write(0xFF);
        this->__hardware_serial->write(0xFF);
    }
}

void Logger::begin(int _baud) {
    if (__use_software_serial)
        this->__software_serial->begin(_baud);
    else
        this->__hardware_serial->begin(_baud);

}

void Logger::skipLobby() {
    delay(4000);
    if (__use_software_serial)
        this->__software_serial->print("page Logger");
    else
        this->__hardware_serial->print("page Logger");
    this->__send_packet();
}