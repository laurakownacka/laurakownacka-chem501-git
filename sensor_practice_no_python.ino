#include "Arduino_BHY2Host.h"

SensorXYZ accelerometer(SENSOR_ID_ACC);

float accelerometerValueX = 0;
float accelerometerValueY = 0;
float accelerometerValueZ = 0;
unsigned long timeValue = 0;

unsigned long startTime = millis();

void setup() {
  Serial.begin(115200);
  BHY2Host.begin();
  accelerometer.begin();
}

void loop() {
  BHY2Host.update();
timeValue = millis() - startTime;
accelerometerValueX = accelerometer.x();
accelerometerValueY = accelerometer.y();
accelerometerValueZ = accelerometer.z();
delay(1000);

Serial.print(timeValue);
Serial.print(',');
Serial.print(accelerometerValueX);
Serial.print(',');
Serial.print(accelerometerValueY);
Serial.print(',');
Serial.print(accelerometerValueZ);
Serial.print('\n');
}
