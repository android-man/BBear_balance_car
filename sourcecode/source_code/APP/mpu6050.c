/*************************************HEAD FILES******************************/
#include"mpu6050.h"

/******************************************************************************
Name��InitMPU6050 
Function:	
		  	initialize the mpu6050 
Parameters��
		   	void
Returns��
			void 
Description:
			wake the sensor and configuration
******************************************************************************/
void InitMPU6050(void)
{
	int i = 0;
	for(i = 0;i < 10; i++){
	Single_Write(MPU6050_Addr, PWR_MGMT_1, 0x00);	//�������״̬
	Single_Write(MPU6050_Addr, SMPLRT_DIV, 0x07);	//���ò���Ƶ��
	Single_Write(MPU6050_Addr, CONFIG, 0x00);		//���õ�ͨ�˲�
	Single_Write(MPU6050_Addr, GYRO_CONFIG, 0x18);	//set the gyro range :+-2000'/s	 
	Single_Write(MPU6050_Addr, ACCEL_CONFIG, 0x28);	//0x09 = 00001000  +-4g
	}
}

void Cal_Init_angle(void)
{
	
}

/******************************************************************************
Name��READ_MPU6050 
Function:	
		  	read data from the mpu6050
Parameters��
		   	[in]	-	*p:the pointer point to the data array
Returns��
			void 
Description:
			null
******************************************************************************/
void READ_MPU6050(int16_t *p)
{
	uint8_t BUF[8];

   	BUF[0]=Single_Read(MPU6050_Addr,ACCEL_XOUT_L); 	//X AXIS ACC
   	BUF[1]=Single_Read(MPU6050_Addr,ACCEL_XOUT_H);
   	p[0] = (BUF[1]<<8)|BUF[0];

   	BUF[2]=Single_Read(MPU6050_Addr,ACCEL_YOUT_L);	//Y AXIS ACC
   	BUF[3]=Single_Read(MPU6050_Addr,ACCEL_YOUT_H);
   	p[1] = (BUF[3]<<8)|BUF[2];

   	BUF[4]=Single_Read(MPU6050_Addr,GYRO_YOUT_L);	//Y AXIS GYRO
   	BUF[5]=Single_Read(MPU6050_Addr,GYRO_YOUT_H);
   	p[2] = (BUF[5]<<8)|BUF[4];

	BUF[6]=Single_Read(MPU6050_Addr,GYRO_XOUT_L);	//X ASIX GYRO
	BUF[7]=Single_Read(MPU6050_Addr,GYRO_XOUT_H);
	p[3] = (BUF[7]<<8)|BUF[6];

}
