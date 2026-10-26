#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);
  mpu.begin();
  
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
}

void loop() {
  sensors_event_t accel, gyro, temp;
  mpu.getEvent(&accel, &gyro, &temp);

  // Calcolo di Rollio e Beccheggio in gradi
  float roll = atan2(accel.acceleration.y, accel.acceleration.z) * 180.0 / PI;
  float pitch = atan2(-accel.acceleration.x, sqrt(accel.acceleration.y * accel.acceleration.y + accel.acceleration.z * accel.acceleration.z)) * 180.0 / PI;

  // Output per Processing (formato: "Roll,Pitch")
  Serial.print(roll);
  Serial.print(",");
  Serial.println(pitch);

  delay(50);
}
