#include "Arduino_BHY2Host.h"

SensorXYZ accelerometer(SENSOR_ID_ACC);

void setup() {
  Serial.begin(115200);
  BHY2Host.begin();
  accelerometer.begin();
}

void loop() {
  if (Serial.available()){
    String numberofReadingsString = Serial.readStringUntil('\n');
    int numberofReadings = numberofReadingsString.toInt();

    unsigned long dataTime = 0;
    unsigned long startTime = millis();

    for (int n = 0; n < numberofReadings; n++) {
      BHY2Host.update();

      dataTime = millis() - startTime;
      float dataX = accelerometer.x();
      float dataY = accelerometer.y();
      float dataZ = accelerometer.z();

      Serial.print(dataTime);
      Serial.print(',');
      Serial.print(dataX);
      Serial.print(',');
      Serial.print(dataY);
      Serial.print(',');
      Serial.print(dataZ);
      Serial.print('\n');
    }
  }
}
