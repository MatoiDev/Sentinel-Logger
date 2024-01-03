//
//  SentinelLogging.ino
//  Sentinel Logger
//
//  Created by Matoi on 01.01.2024.
//  https://github.com/MatoiDev/Sentinel-Logger
//

#include "Logger.h"
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3);

Logger hardwareLogger(Serial2);
Logger softwareLogger(mySerial);

void setup() {

    Serial.begin(9600);
    hardwareLogger.begin(9600);
    softwareLogger.begin(9600);

    // hardwareLogger.skipLobby();
    // softwareLogger.skipLobby();
}

void loop() {
    if (Serial.available()) {
        String command = Serial.readStringUntil("\n");
        hardwareLogger.log(command);
        softwareLogger.log(command);
    }
}
