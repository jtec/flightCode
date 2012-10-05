/*
 * \file clMPU6000.h
 * \brief The Device driver uses a SPI interface to get inertial data from the IMU chip MPU6000 by Invensense.
 * \author Jan
 */

#ifndef DEVICEDRIVER_CLMPU6000_H_
#define DEVICEDRIVER_CLMPU6000_H_


#include "../../hardwareAccessLayer/CMSIS/ST/STM32F4xx/Include/stm32f4xx.h"
#include "../inc/clLED.h"

struct mpu6000Output
{
	float rawGyro[3];	// [rad/s]
	float rawAcc[3];	// [m/s�]
	float temp;			// [�C]
};

//Class declaration
class clMPU6000{
public:
	clMPU6000();
	~clMPU6000();
	void read(mpu6000Output* o);
	static void initStructure(mpu6000Output* s);
	void sendOneByte();
private:
	void spiWrite(uint8_t reg, uint8_t data);
	uint8_t spiRead(uint8_t reg);
	void configMPU();

	SPI_TypeDef* spi;
	GPIO_TypeDef* mosi_port;
	uint16_t mosi_pin;
	GPIO_TypeDef* miso_port;
	uint16_t miso_pin;
	GPIO_TypeDef* sclk_port;
	uint16_t sclk_pin;
	GPIO_TypeDef* cs_port;
	uint16_t cs_pin;
	LED* csPin;
};

// MPU 6000 registers
#define MPUREG_WHOAMI 0x75 //
#define	MPUREG_SMPLRT_DIV 0x19 //
#define MPUREG_CONFIG 0x1A //
#define MPUREG_GYRO_CONFIG 0x1B
#define MPUREG_ACCEL_CONFIG 0x1C
#define MPUREG_INT_PIN_CFG 0x37
#define	MPUREG_INT_ENABLE 0x38
#define MPUREG_ACCEL_XOUT_H 0x3B //
#define MPUREG_ACCEL_XOUT_L 0x3C //
#define MPUREG_ACCEL_YOUT_H 0x3D //
#define MPUREG_ACCEL_YOUT_L 0x3E //
#define MPUREG_ACCEL_ZOUT_H 0x3F //
#define MPUREG_ACCEL_ZOUT_L 0x40 //
#define MPUREG_TEMP_OUT_H 0x41//
#define MPUREG_TEMP_OUT_L 0x42//
#define MPUREG_GYRO_XOUT_H 0x43 //
#define	MPUREG_GYRO_XOUT_L 0x44 //
#define MPUREG_GYRO_YOUT_H 0x45 //
#define	MPUREG_GYRO_YOUT_L 0x46 //
#define MPUREG_GYRO_ZOUT_H 0x47 //
#define	MPUREG_GYRO_ZOUT_L 0x48 //
#define MPUREG_USER_CTRL 0x6A //
#define	MPUREG_PWR_MGMT_1 0x6B //
#define	MPUREG_PWR_MGMT_2 0x6C //
// Configuration bits MPU 3000 and MPU 6000 (not revised)?
#define BIT_SLEEP                   0x40
#define BIT_H_RESET                 0x80
#define BITS_CLKSEL                 0x07
#define MPU_CLK_SEL_PLLGYROX        0x01
#define MPU_CLK_SEL_PLLGYROZ        0x03
#define MPU_EXT_SYNC_GYROX          0x02
#define BITS_FS_250DPS              0x00
#define BITS_FS_500DPS              0x08
#define BITS_FS_1000DPS             0x10
#define BITS_FS_2000DPS             0x18
#define BITS_FS_MASK                0x18
#define BITS_DLPF_CFG_256HZ_NOLPF2  0x00
#define BITS_DLPF_CFG_188HZ         0x01
#define BITS_DLPF_CFG_98HZ          0x02
#define BITS_DLPF_CFG_42HZ          0x03
#define BITS_DLPF_CFG_20HZ          0x04
#define BITS_DLPF_CFG_10HZ          0x05
#define BITS_DLPF_CFG_5HZ           0x06
#define BITS_DLPF_CFG_2100HZ_NOLPF  0x07
#define BITS_DLPF_CFG_MASK          0x07
#define	BIT_INT_ANYRD_2CLEAR	    0x10
#define	BIT_RAW_RDY_EN		    0x01
#define	BIT_I2C_IF_DIS              0x10



#endif /* DEVICEDRIVER_CLMPU6000_H_ */
