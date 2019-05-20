/** ***************************************************************************
 * @file magMMC5883MA.h Magnetometer interface for the Memsic MMC5883MA
 * magnetometer Some features of interest for implementation:
 * @author
 * @date   September, 2018
 * @copyright (c) 2018. All Rights Reserved.
 * @section LICENSE
 * THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
 * KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
 * PARTICULAR PURPOSE.
 * @details
 * magnetometer.h. This file just provides the specifics, for use by the
 * associated C file only.
 *****************************************************************************/

#ifndef MMC5883MA_H
#define MMC5883MA_H
#include <stdint.h>

#define MMC5883MA_I2C_ADDR      0x60


#define MMC5883MA_X_LSB			  0
#define MMC5883MA_X_MSB			  1
#define MMC5883MA_Y_LSB			  2
#define MMC5883MA_Y_MSB			  3
#define MMC5883MA_Z_LSB			  4
#define MMC5883MA_Z_MSB			  5
#define MMC5883MA_TEMP			  6
#define MMC5883MA_STATUS		  7
#define MMC5883MA_CTRL_0          8
#define MMC5883MA_CTRL_1          9
#define MMC5883MA_CTRL_2          10
#define MMC5883MA_X_THRSH		  11
#define MMC5883MA_Y_THRSH		  12
#define MMC5883MA_Z_THRSH		  13
#define MMC5883MA_ID  			  47


#define MMC5883MA_STATUS_TEMP_RDY  0x02
#define MMC5883MA_STATUS_MAG_RDY   0x01
#define MMC5883MA_STATUS_OTP_RDY   0x10
#define MMC5883MA_STATUS_INT_RESET 0x07

#define MMC5883MA_CTRL0_MEAS_TEMP  0x02
#define MMC5883MA_CTRL0_MEAS_MAG   0x01
#define MMC5883MA_CTRL0_SET        0x08
#define MMC5883MA_CTRL0_RESET      0x10

#define MMC5883MA_CTRL1_SW_RST     0x80
#define MMC5883MA_CTRL1_ODR_10MS   0x00
#define MMC5883MA_CTRL1_ODR_5MS    0x01
#define MMC5883MA_CTRL1_ODR_2MS5   0x02
#define MMC5883MA_CTRL1_ODR_1MS6   0x03

#define MMC5883MA_CTRL2_INT_DONE_ENABLE   0x40
#define MMC5883MA_CTRL2_FREQ_NONE         0x00
#define MMC5883MA_CTRL2_FREQ_14HZ         0x01
#define MMC5883MA_CTRL2_FREQ_5HZ          0x02
#define MMC5883MA_CTRL2_FREQ_2HZ2         0x03
#define MMC5883MA_CTRL2_FREQ_1HZ          0x04
#define MMC5883MA_CTRL2_FREQ_0HZ5         0x05
#define MMC5883MA_CTRL2_FREQ_0HZ25        0x06
#define MMC5883MA_CTRL2_FREQ_0HZ125       0x07

#define MMC5883MA_CHIP_ID                 0x0C
#define MMC5883MA_NUM_DATA_CYCLES_PER_SET 500       // 5 seconds

uint8_t  magMMC5883MA_Init();
uint8_t  magMMC5883MA_Config(uint32_t *rangeInMilliGauss);
uint16_t magMMC5883MA_GetGain();
uint8_t  magMMC5883MA_WhoAmI(uint32_t *whoami);
uint8_t  magMMC5883MA_GetLastReading(int16_t *readings);
uint8_t  magMMC5883MA_StartReading();
void     magMMC5883MA_DataReadyIRQ(void);
uint8_t  magMMC5883MA_SelfTest();
uint8_t  magMMC5883MA_ClearInt();

#endif /* MMC5883MA_H */