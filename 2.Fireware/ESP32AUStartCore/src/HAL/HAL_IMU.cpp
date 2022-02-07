#include "HAL/HAL.h"
#include <Adafruit_MPU6050.h>

static Adafruit_MPU6050 mpu;
static int imu_enable = 1;

void HAL::IMU_Init()
{
// Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    imu_enable = 0;
  }
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  Serial.print("Accelerometer range set to: ");
  switch (mpu.getAccelerometerRange()) {
  case MPU6050_RANGE_2_G:
    Serial.println("+-2G");
    break;
  case MPU6050_RANGE_4_G:
    Serial.println("+-4G");
    break;
  case MPU6050_RANGE_8_G:
    Serial.println("+-8G");
    break;
  case MPU6050_RANGE_16_G:
    Serial.println("+-16G");
    break;
  }
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  Serial.print("Gyro range set to: ");
  switch (mpu.getGyroRange()) {
  case MPU6050_RANGE_250_DEG:
    Serial.println("+- 250 deg/s");
    break;
  case MPU6050_RANGE_500_DEG:
    Serial.println("+- 500 deg/s");
    break;
  case MPU6050_RANGE_1000_DEG:
    Serial.println("+- 1000 deg/s");
    break;
  case MPU6050_RANGE_2000_DEG:
    Serial.println("+- 2000 deg/s");
    break;
  }

  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  Serial.print("Filter bandwidth set to: ");
  switch (mpu.getFilterBandwidth()) {
  case MPU6050_BAND_260_HZ:
    Serial.println("260 Hz");
    break;
  case MPU6050_BAND_184_HZ:
    Serial.println("184 Hz");
    break;
  case MPU6050_BAND_94_HZ:
    Serial.println("94 Hz");
    break;
  case MPU6050_BAND_44_HZ:
    Serial.println("44 Hz");
    break;
  case MPU6050_BAND_21_HZ:
    Serial.println("21 Hz");
    break;
  case MPU6050_BAND_10_HZ:
    Serial.println("10 Hz");
    break;
  case MPU6050_BAND_5_HZ:
    Serial.println("5 Hz");
    break;
  }

}

void HAL::IMU_Update()
{
    IMU_Info_t imuInfo;
     /* Get new sensor events with the readings */
    sensors_event_t a, g, temp;
    if(imu_enable == 0){
        Serial.println("IMU error");
        return;
    }
    mpu.getEvent(&a, &g, &temp);
    imuInfo.ax = a.acceleration.x;
    imuInfo.ay = a.acceleration.y;
    imuInfo.az = a.acceleration.z;
    Serial.printf("Acceleration X:%f,Y:%f,Z:%f\n",imuInfo.ax,imuInfo.ay,imuInfo.az);
    imuInfo.gx = g.gyro.x;
    imuInfo.gy = g.gyro.y;
    imuInfo.gz = g.gyro.z;
    Serial.printf("Rotation X:%f,Y:%f,Z:%f\n",imuInfo.gx,imuInfo.gy,imuInfo.gz);
    Serial.printf("Temperature:%f \n", temp.temperature);
    imuInfo.mx = 0;
    imuInfo.my = 0;
    imuInfo.mz = 0;
    imuInfo.roll = 0;
    imuInfo.yaw = 0;
    imuInfo.pitch = 0;

}
