#ifndef _MPU6050_H_
#define _MPU6050_H_

#define MPU6050_ADDR 0xD0

#define CONFIG 0x1A
#define SMPLRT_DIV_REG 0x19
#define GYRO_CONFIG_REG 0x1B
#define ACCEL_CONFIG_REG 0x1C
#define ACCEL_XOUT_H_REG 0x3B
#define TEMP_OUT_H_REG 0x41
#define GYRO_XOUT_H_REG 0x43
#define PWR_MGMT_1_REG 0x6B
#define WHO_AM_I_REG 0x75


struct gyro_val
{
	float Gx,Gy,Gz;
};

struct accel_val
{
	float Ax,Ay,Az;
};

extern struct accel_val accel;
extern struct gyro_val gyro;
extern float gyro_offsetx, gyro_offsety, gyro_offsetz, accel_offsetx, accel_offsety, accel_offsetz;


void mpu6050_read_accel_raw(void);
void mpu6050_read_gyro_raw(void);
void mpu6050_read_accel(void);
void mpu6050_read_gyro(void);
void mpu6050_init(void);

#endif
