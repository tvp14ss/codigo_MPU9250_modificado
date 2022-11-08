#include "freeram.h"

#include "mpu.h"
#include "I2Cdev.h"

#define DISPLAY_INTERVAL  20
void setup() {
    Fastwire::setup(400,0);
    Serial.begin(38400);
    mympu_open(200);
    //Serial.print("MPU init: "); Serial.println(ret);
    //Serial.print("Free mem: "); Serial.println(freeRam());
	
}

unsigned long lastDisplay = 0;

void loop() {
    unsigned long now = millis();
    mympu_update();

    if ((now - lastDisplay) >= DISPLAY_INTERVAL)
    {
	    Serial.print("#YPR=");
	    Serial.print(mympu.ypr[0], 2);
      Serial.print(",");
	    Serial.print(mympu.ypr[1], 2);
      Serial.print(",");
	    Serial.println(mympu.ypr[2], 2);
      lastDisplay = now;
    }
}
