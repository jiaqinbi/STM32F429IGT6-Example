#ifndef __FLASH_W25Q256_H
#define __FLASH_W25Q256_H

/*******************头文件包含【开始】*********************/
#include "stm32f4xx_hal.h"
/*******************头文件包含【结束】*********************/

/*******************宏定义【开始】*********************/

/*******************宏定义【结束】*********************/

/*******************函数声明【开始】*********************/
void FLASH_InitConfig(void);
uint8_t SPI5_ReadWriteByte(uint8_t TxData);
uint16_t W25Q256_READ_DeviceID(void);
uint32_t W25Q256_READ_JedecID(void);
/*******************函数声明【结束】*********************/

#endif
