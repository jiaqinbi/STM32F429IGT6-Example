һ�����ƣ�SPI����0.96' oled��ʾʵ��
������������SPI��дW25Q256ʵ������ϼ���oled��Ļ��ʾ�Ĺ���
�����������ã�
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
�ġ���غ�����
	1��HAL_SPI_Init();
	2��HAL_SPI_MspInit();
	3��HAL_SPI_Transmit();
	4��HAL_SPI_Receive();
	5��HAL_SPI_TransmitReceive();
�塢ע�⣺��stm32f4xx_hal_conf.h�ļ���ȡ��#define HAL_SPI_MODULE_ENABLED��ע��
����ʵ������OLED��Ļ����ʾ ��0.96 oled show��