#include "main.h"
#include "mpu6050.h"


struct accel_val accel = {0.0,0.0,0.0};
struct gyro_val gyro = {0.0,0.0,0.0};
float offsetx,offsety,offsetz = 0.0;

extern I2C_HandleTypeDef hi2c1;

void mpu6050_read_accel(void)
{
	uint8_t recv_accel[6];
	
	HAL_I2C_Mem_Read(&hi2c1 , MPU6050_ADDR, ACCEL_XOUT_H_REG, 1, recv_accel,6,1000);
	
	int16_t accel_x_raw = (int16_t)(recv_accel[0] << 8 | recv_accel[1]);
	int16_t accel_y_raw = (int16_t)(recv_accel[2] << 8 | recv_accel[3]);
	int16_t accel_z_raw = (int16_t)(recv_accel[4] << 8 | recv_accel[5]);
	
	accel.Ax = accel_x_raw/16384.0;
	accel.Ay = accel_y_raw/16384.0;
	accel.Az = accel_z_raw/16384.0;
}


void mpu6050_read_gyro(void)
{
	uint8_t recv_gyro[6];
	
	HAL_I2C_Mem_Read(&hi2c1 , MPU6050_ADDR, GYRO_XOUT_H_REG, 1, recv_gyro,6,1000);
	
	int16_t gyro_x_raw = (int16_t)(recv_gyro[0] << 8 | recv_gyro[1]);
	int16_t gyro_y_raw = (int16_t)(recv_gyro[2] << 8 | recv_gyro[3]);
	int16_t gyro_z_raw = (int16_t)(recv_gyro[4] << 8 | recv_gyro[5]);
	
	gyro.Gx = gyro_x_raw/131.0;
	gyro.Gy = gyro_y_raw/131.0;
	gyro.Gz = gyro_z_raw/131.0;
}

void mpu6050_init(void)
{
	uint8_t check, data;
	
	HAL_I2C_Mem_Read(&hi2c1, MPU6050_ADDR, WHO_AM_I_REG, 1, &check, 1, 1000) ;
	
	if(check == 104) //mpu6050 present
	{
		data=0;
		HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, PWR_MGMT_1_REG, 1, &data, 1, 1000);
		
		HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, SMPLRT_DIV_REG,1,&data,1,1000);
		
		//accel config -> self test x,y,z=0  , FS_SEL=0 for +/-2g full scale range
		HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, ACCEL_CONFIG_REG,1,&data,1,1000);
		
		//gyro config -> self test x,y,z =0 , FS_SEL=0 for +/-250 degree/s full scale range
		HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, GYRO_CONFIG_REG, 1,&data,1,1000);
		
		mpu6050_read_gyro();
		
		if(gyro.Gx!=0)
			offsetx=gyro.Gx;
		if(gyro.Gy!=0)
			offsety=gyro.Gy;
		if(gyro.Gz!=0)
			offsetz=gyro.Gz;
		
	}
}
