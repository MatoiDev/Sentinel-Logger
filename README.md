# Sentinel Logger (for [Nextion](https://nextion.tech) displays)

> ###### Allows you to use your Nextion display as a serial terminal-style monitor

<img src="README ASSETS/Preview.gif">

## Features

- Using HardwareSerial for logging (for Arduino Mega/Due, etc.)
- Using SoftwareSerial for logging (for Arduino Uno/Nano/Mini, etc.)
- Using both at the same time.
- Scroll effect (When overloaded, the page is not cleared, but scrolls down 1 line)

## How to use

##### 1. Add [`Logger.h`](Logger.h) and [`Logger.cpp`](Logger.cpp) to your project

##### 2. Download [`Sentinel[v1.0].tft`](Firmware/Sentinel[v1.0].tft) to your display

#### **All Done!**

## Examples

- **Software serial**

```c++
#include "Logger.h"
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3);
Logger softwareLogger(mySerial); // 1. Initialize logger

void setup() {
    ...
    softwareLogger.begin(9600); // 2. Begin serial
    ...
}

void loop() {
    ...
    if (Serial.available()) {
        String command = Serial.readStringUntil("\n");
        softwareLogger.log(command); // 3. Log
    }
    ...
}
```

- **Hardware serial**

```c++
#include "Logger.h"

Logger hardwareLogger(Serial2); // 1. Initialize logger

void setup() {
    ...
    hardwareLogger.begin(9600); // 2. Begin serial
    ...
}

void loop() {
    ...
    if (Serial.available()) {
        String command = Serial.readStringUntil("\n");
        hardwareLogger.log(command); // 3. Log
    }
    ...
}
```

#### Commands

There is nothing easier than using them.

```c++
/* Somewhere in your code: */
...
myLogger.log("<command>")
...
```

There are 2 basic commands:

- `clear` - erase all logs in your session, **it doesn't create a new session**
- `page <PageID>` - go to a specific page:

    - **Logger** - Terminal Page, **creates a new session**
    - **Main** - Lobby, **closes an existing session**

#### Skipping Lobby

<img src="README ASSETS/LobbyScreen.png">

If you don't have to wait for your board to connect, you can skip this screen, just call `skipLobby()` in
your `setup()`:

```c++
void setup() {
    ...
    myLogger.skipLoading();
    ...
}
```

## Credits

> ##### I hope my work will save someone time.
> ##### If you'll use this stuff in your project, please leave a link to my GitHub in credits.

## Project support

> ##### I don't have much knowledge in this area, it's just my solution to this problem and it's far from ideal. I believe that you have much more knowledge than I do if you came here, so if you liked the project and you know how it can be improved, then feel free to make your pull request!