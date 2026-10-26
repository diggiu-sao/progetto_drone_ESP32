#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(115200);
  
  // Inizializza i pin I2C (SDA = 21, SCL = 22)
  Wire.begin(21, 22);
  
  if (!mpu.begin()) {
    Serial.println("Errore: MPU6050 non trovato.");
    while (1) { delay(10); }
  }
  
  // Calibrazione hardware per drone
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
}

void loop() {
  sensors_event_t accel, gyro, temp;
  mpu.getEvent(&accel, &gyro, &temp);

  // Stampa valori base Accelerometro
  Serial.print("AccelX:"); 
  Serial.print(accel.acceleration.x);
  Serial.print(" AccelY:"); 
  Serial.print(accel.acceleration.y);
  Serial.print(" AccelZ:"); 
  Serial.print(accel.acceleration.z);
  
  // Stampa valori base Giroscopio
  Serial.print(" | GyroX:"); 
  Serial.print(gyro.gyro.x);
  Serial.print(" GyroY:"); 
  Serial.print(gyro.gyro.y);
  Serial.print(" GyroZ:"); 
  Serial.println(gyro.gyro.z);
  
  delay(50);
}
