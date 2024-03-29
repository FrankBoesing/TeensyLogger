
//Set log flags
#define LOGDEVICE Serial
#define LOGTIMESTAMP
#define LOGPRINTLEVEL


#include "TeensyLogger.h"

void setup() {
  Serial.printf("Log Level: %d\n", LOG_LEVEL);
}

void loop() {  
  delay(1002);
  Serial.println("===");
  LOGE("%s", "Error");
  LOGW("%s", "This is a warning :)");
  LOGI("%s", "Information!");
  LOGD("%s", "Debug");
  LOGV("%s", "Verbose");  
}
