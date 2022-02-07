#include "HAL/HAL.h"
#include <Adafruit_MPU6050.h>
#include <Adafruit_HMC5883_U.h>

static Adafruit_MPU6050 mpu;
/* Assign a unique ID to this sensor at the same time */
static Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);

static int mpu_enable = 1;
static int mag_enable = 1;

void displaySensorDetails(void)
{
  sensor_t sensor;
  mag.getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" uT");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" uT");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" uT");  
  Serial.println("------------------------------------");
  Serial.println("");
}

void HAL::IMU_Init()
{
// Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    mpu_enable = 0;
  }else{
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
  if(!mag.begin())
  {
    Serial.println("Ooops, no HMC5883 detected ... Check your wiring!");
    mag_enable = 0;
  }else{
      displaySensorDetails();
  }


}

void HAL::IMU_Update()
{
    IMU_Info_t imuInfo;
     /* Get new sensor events with the readings */
    sensors_event_t a, g, temp,ecompass;

    if(mpu_enable == 0){
        Serial.println("MPU6050 no found");
        imuInfo.ax = 0;
        imuInfo.ay = 0;
        imuInfo.az = 0;
        imuInfo.gx = 0;
        imuInfo.gy = 0;
        imuInfo.gz = 0;
    }else{
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
    }
    if(mag_enable == 0){
        Serial.println("HMC5883L no found");
        imuInfo.mx = 0;
        imuInfo.my = 0;
        imuInfo.mz = 0;
    }else{
        //mag.getEvent(&ecompass);
        imuInfo.mx = ecompass.magnetic.x;
        imuInfo.my = ecompass.magnetic.y;
        imuInfo.mz = ecompass.magnetic.z;
        //Serial.printf("Ecompass X:%f,Y:%f,Z:%f\n",imuInfo.mx,imuInfo.my,imuInfo.mz);
    }
    imuInfo.roll = 0;
    imuInfo.yaw = 0;
    imuInfo.pitch = 0;

}
