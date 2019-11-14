一、名称：fmc配置sdram扩展芯片存储容量实验
二、引脚配置：
 /** FMC GPIO Configuration  
  PF0    ------> FMC_A0
  PF1    ------> FMC_A1
  PF2    ------> FMC_A2
  PF3    ------> FMC_A3
  PF4    ------> FMC_A4
  PF5    ------> FMC_A5
  PC0    ------> FMC_SDNWE
  PC2    ------> FMC_SDNE0
  PC3    ------> FMC_SDCKE0
  PF11   ------> FMC_SDNRAS
  PF12   ------> FMC_A6
  PF13   ------> FMC_A7
  PF14   ------> FMC_A8
  PF15   ------> FMC_A9
  PG0    ------> FMC_A10
  PG1    ------> FMC_A11
  PE7    ------> FMC_D4
  PE8    ------> FMC_D5
  PE9    ------> FMC_D6
  PE10   ------> FMC_D7
  PE11   ------> FMC_D8
  PE12   ------> FMC_D9
  PE13   ------> FMC_D10
  PE14   ------> FMC_D11
  PE15   ------> FMC_D12
  PD8    ------> FMC_D13
  PD9    ------> FMC_D14
  PD10   ------> FMC_D15
  PD14   ------> FMC_D0
  PD15   ------> FMC_D1
  PG2    ------> FMC_A12
  PG4    ------> FMC_BA0
  PG5    ------> FMC_BA1
  PG8    ------> FMC_SDCLK
  PD0    ------> FMC_D2
  PD1    ------> FMC_D3
  PG15   ------> FMC_SDNCAS
  */
三、相关结构体及函数：
	1、FMC_SDRAM_TimingTypeDef	时序结构体
	2、FMC_SDRAM_CommandTypeDef 命令结构体	
	3、SDRAM_HandleTypeDef       句柄、初始化结构体
	4、HAL_SDRAM_Init();
	5、HAL_SDRAM_SendCommand();
四、实验现象：串口读取写入的数据