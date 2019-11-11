一、名称：SPI驱动0.96' oled显示实验
二、描述：在SPI读写W25Q256实验基础上加上oled屏幕显示的功能
三、引脚配置：
		=========FLASH==========
		PF6     ------> SPI5_SS
		PF7     ------> SPI5_SCK
        PF8     ------> SPI5_MISO
        PF9     ------> SPI5_MOSI 
		=========oled==========
		PA5     ------> SPI1_SCK
        PA6     ------> SPI1_MISO
        PA7     ------> SPI1_MOSI 
		PA4     ------> OLED_RES
		PE2     ------> OLED_DC
		PB2     ------> OLED_CS
四、相关函数：
	1、HAL_SPI_Init();
	2、HAL_SPI_MspInit();
	3、HAL_SPI_Transmit();
	4、HAL_SPI_Receive();
	5、HAL_SPI_TransmitReceive();
五、注意：在stm32f4xx_hal_conf.h文件中取消#define HAL_SPI_MODULE_ENABLED的注释
六、实验现象：OLED屏幕上显示 “0.96 oled show”