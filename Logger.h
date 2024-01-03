//
//  Logger.h
//  Sentinel Logger
//
//  Created by Matoi on 01.01.2024.
//  https://github.com/MatoiDev/Sentinel-Logger
//

#include <SoftwareSerial.h>
#include <HardwareSerial.h>
#include <Arduino.h>

class Logger {
private:
    bool __use_software_serial;

    SoftwareSerial *__software_serial;
    HardwareSerial *__hardware_serial;

    void __send_packet();

public:
    Logger(SoftwareSerial *softSerial) : __use_software_serial(true), __software_serial(softSerial) {}
    Logger(SoftwareSerial &softSerial) : __use_software_serial(true), __software_serial(&softSerial) {}
    Logger(HardwareSerial *hardSerial) : __use_software_serial(false), __hardware_serial(hardSerial) {}
    Logger(HardwareSerial &hardSerial) : __use_software_serial(false), __hardware_serial(&hardSerial) {}

    void log(String data);
    void begin(int _baud);
    void skipLobby();
};
