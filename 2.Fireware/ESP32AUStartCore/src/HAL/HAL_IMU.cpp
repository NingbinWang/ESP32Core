#include "HAL/HAL.h"
#include "Configs/Config.h"
#ifdef CONFIG_IMU_MPU9250
#include "MPU9250.h"
static MPU9250 mpu;
#endif
#ifdef CONFIG_IMU_MPU6050
#include "Adafruit_MPU6050.h"
static Adafruit_MPU6050 mpu;
#endif

static int mpu_enable = 1;

void HAL::IMU_Init()
{
#ifdef CONFIG_IMU_MPU9250
// Try to initialize!
  if (!mpu.setup(0x68)) {
    Serial.println("MPU connection failedp");
    mpu_enable = 0;
  }
#endif
#ifdef CONFIG_IMU_MPU6050
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
#endif
}
void HAL::IMU_Update()
{
    IMU_Info_t imuInfo;
    
    if(mpu_enable == 0){
        //Serial.println("MPU6050 no found");
        imuInfo.ax = 0;
        imuInfo.ay = 0;
        imuInfo.az = 0;
        imuInfo.gx = 0;
        imuInfo.gy = 0;
        imuInfo.gz = 0;
        imuInfo.mx = 0;
        imuInfo.my = 0;
        imuInfo.mz = 0;
        imuInfo.roll = 0;
        imuInfo.yaw = 0;
        imuInfo.pitch = 0;
    }else{ 
     #ifdef CONFIG_IMU_MPU9250   
       mpu.update();
       imuInfo.ax = mpu.getAccX();
       imuInfo.ay = mpu.getAccY();
       imuInfo.az = mpu.getAccZ();
       imuInfo.gx = mpu.getGyroX();
       imuInfo.gy = mpu.getGyroY();
       imuInfo.gz = mpu.getGyroZ();
       imuInfo.mx = mpu.getMagX();
       imuInfo.my = mpu.getMagY();
       imuInfo.mz = mpu.getMagZ();
       imuInfo.roll = mpu.getRoll();
       imuInfo.yaw = mpu.getYaw();
       imuInfo.pitch = mpu.getPitch();
       //Serial.printf("Acceleration X:%f,Y:%f,Z:%f\n",imuInfo.ax,imuInfo.ay,imuInfo.az);
       //Serial.printf("Rotation X:%f,Y:%f,Z:%f\n",imuInfo.gx,imuInfo.gy,imuInfo.gz);
       //Serial.printf("mag X:%f,Y:%f,Z:%f\n",imuInfo.mx,imuInfo.my,imuInfo.mz);
       //Serial.printf("roll:%f,yaw:%f,pitch:%f\n",imuInfo.roll,imuInfo.yaw,imuInfo.pitch);
     #endif
     #ifdef CONFIG_IMU_MPU6050
       sensors_event_t a, g, temp;
       mpu.getEvent(&a, &g, &temp);
       imuInfo.ax = a.acceleration.x;
       imuInfo.ay = a.acceleration.y;
       imuInfo.az = a.acceleration.z;
      // Serial.printf("Acceleration X:%f,Y:%f,Z:%f\n",imuInfo.ax,imuInfo.ay,imuInfo.az);
       imuInfo.gx = g.gyro.x;
       imuInfo.gy = g.gyro.y;
       imuInfo.gz = g.gyro.z;
       //Serial.printf("Rotation X:%f,Y:%f,Z:%f\n",imuInfo.gx,imuInfo.gy,imuInfo.gz);
       //Serial.printf("Temperature:%f \n", temp.temperature);
       imuInfo.mx = 0;
       imuInfo.my = 0;
       imuInfo.mz = 0;
       imuInfo.roll = 0;
       imuInfo.yaw = 0;
       imuInfo.pitch = 0;
     #endif


    }
}
