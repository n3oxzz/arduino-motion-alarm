#include "Wire.h"
#include <MPU6050_light.h>

MPU6050 mpu(Wire);

bool isAlarmOn = false;
const float threshold = 5.0;
const int buzzerPin = 11;
const float weight = 0.96;

unsigned long prevTime = 0;
float gyroAngleX = 0; 

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  Wire.begin();
  mpu.begin();
  mpu.calcOffsets(); // calibration
  prevTime = millis();
}

void loop() {
  mpu.update();

  unsigned long currentTime = millis();
  float dt = (currentTime - prevTime) / 1000.0; 
  prevTime = currentTime;

  if (dt <= 0 || dt > 1) return; 

  float gyroX = mpu.getGyroX(); // deg/s
  float accY = mpu.getAccY();
  float accZ = mpu.getAccZ();

  // gyro angle
  gyroAngleX += gyroX * dt;

  // accel angle
  float phi = atan2(accY, accZ) * (180.0 / PI); 

  // complemetrary filter
  float finalAngle = weight * gyroAngleX + (1 - weight) * phi;

  Serial.print("Final Angle X: ");
  Serial.println(finalAngle);

  if (abs(finalAngle) < 1.0) {
  gyroAngleX *= 0.95; 
}

  // if (abs(finalAngle) > threshold) {
  //  if(!isAlarmOn){
  //   digitalWrite(buzzerPin, HIGH);
  //   isAlarmOn = true;
  //  }else{
  //   if(isAlarmOn){
  //     digitalWrite(buzzerPin, LOW);
  //     isAlarmOn = false;
  //   }
  //  }
  // }


  delay(10); 
}
