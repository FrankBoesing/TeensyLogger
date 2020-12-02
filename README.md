# Teensy_Logger

Tool for better handling of the serial monitor.


Teensy Logger is a macro-based library.

You can switch the log level via the Menu in Arduino.


---
Examples:


 LOGE("%d is too small", 0); //Log Level "Error"
 
 LOGW("%d may be small", 77); //Log Level "Warning"
 
 LOGI("value a is %d, b is 0x%x", 88, 10); //Log Level "Information"
 
 LOGD("debug: %s", "foo"); //Log Level "Information"
 
 LOGD("verbose: %s", "I am very verbose"); //Log Level "verbose"

---
Installation:
 1. Copy the library to your libraries directory
 
 2. Copy platform.local.txt to Arduino\hardware\teensy\avr or add its contents to the existing file
 
 3. Copy boards.local.txt to Arduino\hardware\teensy\avr  or add its contents to the existing file
 
