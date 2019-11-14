
/******************************************************
 *  @brief  	sdram配置、功能函数文件               *              
 *  @file   	fmc_sdram.c                           *
 *  @author 	毕家钦                                *
 *  @version	v1.0                                  *
 *  @date  	    2019年11月14日                        *
 *  @note       实现FMC配置sdram扩展芯片的内存实验    *
 ******************************************************/

/*******************头文件【开始】*********************/
#include "fmc_sdram.h"
#include "stdio.h"
/*******************头文件【结束】*********************/

/*******************变量声明【开始】*********************/
SDRAM_HandleTypeDef hsdram1;
static uint32_t FMC_Initialized = 0;
static uint32_t FMC_DeInitialized = 0;
/*******************变量声明【结束】*********************/

/*******************函数【开始】*********************/
/**  
 * @brief         FMC抽象层初始化
 * @retval        无
 * @return		  无
 * @note          无
 */
 void MX_FMC_Init(void)
{
  FMC_SDRAM_TimingTypeDef SdramTiming;
    
  hsdram1.Instance = FMC_SDRAM_DEVICE;
  /* hsdram1.Init */
  hsdram1.Init.SDBank = FMC_SDRAM_BANK1;                                /**< sdram区域为1 -- bank1 */
  hsdram1.Init.ColumnBitsNumber = FMC_SDRAM_COLUMN_BITS_NUM_9;          /**< 列地址 9位 */
  hsdram1.Init.RowBitsNumber = FMC_SDRAM_ROW_BITS_NUM_13;               /**< 行地址 13位 */
  hsdram1.Init.MemoryDataWidth = FMC_SDRAM_MEM_BUS_WIDTH_16;            /**< 数据线宽度16位 */
  hsdram1.Init.InternalBankNumber = FMC_SDRAM_INTERN_BANKS_NUM_4;       /**< SDRAM内部BANK个数 */
  hsdram1.Init.CASLatency = FMC_SDRAM_CAS_LATENCY_3;                    /**< CAS延时周期3 */
  hsdram1.Init.WriteProtection = FMC_SDRAM_WRITE_PROTECTION_DISABLE;    /**< 写保护关闭 */
  hsdram1.Init.SDClockPeriod = FMC_SDRAM_CLOCK_PERIOD_2;                /**< hclk二分频 */
  hsdram1.Init.ReadBurst = FMC_SDRAM_RBURST_ENABLE;                     /**< 读取突发模式使能 */
  hsdram1.Init.ReadPipeDelay = FMC_SDRAM_RPIPE_DELAY_1;                 /**< 读取延时 */
  /* SdramTiming */
  
  /// 初始化时序结构体
  SdramTiming.LoadToActiveDelay = 2;                                    /**<  */
  SdramTiming.ExitSelfRefreshDelay = 8;
  SdramTiming.SelfRefreshTime = 6;
  SdramTiming.RowCycleDelay = 6;
  SdramTiming.WriteRecoveryTime = 4;
  SdramTiming.RPDelay = 2;
  SdramTiming.RCDDelay = 2;

  if (HAL_SDRAM_Init(&hsdram1, &SdramTiming) != HAL_OK)
  {
    
  }

}

/**  
 * @brief         初始化FMC及SDRAM使用的GPIO 
 * @retval        无
 * @return		  无
 * @note          无
 */
static void HAL_FMC_MspInit(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;
  if (FMC_Initialized) {
    return;
  }
  FMC_Initialized = 1;
  __HAL_RCC_FMC_CLK_ENABLE();
  
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
  /* GPIO_InitStruct */
  GPIO_InitStruct.Pin = SDRAM_A0_Pin|SDRAM_A1_Pin|SDRAM_A2_Pin|SDRAM_A3_Pin 
                          |SDRAM_A4_Pin|SDRAM_A5_Pin|SDRAM_SDNRAS_Pin|SDRAM_A6_Pin 
                          |SDRAM_A7_Pin|SDRAM_A8_Pin|SDRAM_A9_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF12_FMC;

  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /* GPIO_InitStruct */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_2|GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF12_FMC;

  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /* GPIO_InitStruct */
  GPIO_InitStruct.Pin = SDRAM_A10_Pin|SDRAM_A11_Pin|SDRAM_A12_Pin|SDRAM_BA0_Pin 
                          |SDRAM_BA1_Pin|SDRAM_SDCLK_Pin|SDRAM_SDNCAS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF12_FMC;

  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /* GPIO_InitStruct */
  GPIO_InitStruct.Pin = SDRAM_D4_Pin|SDRAM_D5_Pin|SDRAM_D6_Pin|SDRAM_D7_Pin 
                          |SDRAM_D8_Pin|SDRAM_D9_Pin|SDRAM_D10_Pin|SDRAM_D11_Pin 
                          |SDRAM_D12_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF12_FMC;

  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /* GPIO_InitStruct */
  GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|SDRAM_D0_Pin 
                          |SDRAM_D1_Pin|GPIO_PIN_0|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF12_FMC;

  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
}

void HAL_SDRAM_MspInit(SDRAM_HandleTypeDef* sdramHandle)
{
  /* USER CODE BEGIN SDRAM_MspInit 0 */

  /* USER CODE END SDRAM_MspInit 0 */
  HAL_FMC_MspInit();
  /* USER CODE BEGIN SDRAM_MspInit 1 */

  /* USER CODE END SDRAM_MspInit 1 */
}

/**  
 * @brief         使用命令初始化SDRAM 
 * @retval        无
 * @return		  无
 * @note          无
 */
static void SDRAM_Init_Process(void)
{
    FMC_SDRAM_CommandTypeDef Command;
    /* 1.开启SDCLK */
    Command.CommandMode = FMC_SDRAM_CMD_CLK_ENABLE;     /**< 使能时钟 */
    Command.CommandTarget = FMC_SDRAM_CMD_TARGET_BANK1; /**< 存储区域1 */
    Command.ModeRegisterDefinition = 0;
    Command.AutoRefreshNumber = 0;
    HAL_SDRAM_SendCommand(&hsdram1, &Command, 0x0010);    
    while(HAL_SDRAM_GetState(&hsdram1) == HAL_SDRAM_STATE_BUSY);    /**< 等待命令发送完毕 */
//    HAL_SDRAM_SendCommand(FMC_SDRAM_TypeDef *Device, FMC_SDRAM_CommandTypeDef *Command, uint32_t Timeout);
    HAL_Delay(201);
    
    /* 2.对所有bank进行充电 */
    Command.CommandMode = FMC_SDRAM_CMD_PALL;     /**< 对所有bank进行充电 */
    Command.CommandTarget = FMC_SDRAM_CMD_TARGET_BANK1; /**< 存储区域1 */
    Command.ModeRegisterDefinition = 0;
    Command.AutoRefreshNumber = 0;
    HAL_SDRAM_SendCommand(&hsdram1, &Command, 0x0010);    
    while(HAL_SDRAM_GetState(&hsdram1) == HAL_SDRAM_STATE_BUSY);    /**< 等待命令发送完毕 */
    
    /* 3.发送自动刷新命令，至少8次 */
    Command.CommandMode = FMC_SDRAM_CMD_PALL;     /**< 发送自动刷新命令 */
    Command.CommandTarget = FMC_SDRAM_CMD_TARGET_BANK1; /**< 存储区域1 */
    Command.ModeRegisterDefinition = 0;
    Command.AutoRefreshNumber = 8;                      /**< 自动刷新8次 */
    HAL_SDRAM_SendCommand(&hsdram1, &Command, 0x0010);    
    while(HAL_SDRAM_GetState(&hsdram1) == HAL_SDRAM_STATE_BUSY);    /**< 等待命令发送完毕 */
    
    /* 4.设置模式寄存器 */
    uint32_t temp=0;
    temp=(uint32_t)SDRAM_MODEREG_BURST_LENGTH_1     |	/**< 设置突发长度:1(可以是1/2/4/8) */
              SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL   |	/**< 设置突发类型:连续(可以是连续/交错) */
              SDRAM_MODEREG_CAS_LATENCY_3           |	/**< 设置CAS值:3(可以是2/3) */
              SDRAM_MODEREG_OPERATING_MODE_STANDARD |   /**< 设置操作模式:0,标准模式 */
              SDRAM_MODEREG_WRITEBURST_MODE_SINGLE;     /**< 设置突发写模式:1,单点访问 */
    
    Command.CommandMode = FMC_SDRAM_CMD_LOAD_MODE;      /**< 发送自动刷新命令 */
    Command.CommandTarget = FMC_SDRAM_CMD_TARGET_BANK1; /**< 存储区域1 */
    Command.ModeRegisterDefinition = temp;
    Command.AutoRefreshNumber = 0;                      /**< 无需刷新 */
    HAL_SDRAM_SendCommand(&hsdram1, &Command, 0x0010);    
    while(HAL_SDRAM_GetState(&hsdram1) == HAL_SDRAM_STATE_BUSY);    /**< 等待命令发送完毕 */
    
    /** 5.设置SDRAM的刷新周期    按行刷新
          刷新频率计数器(以SDCLK频率计数),计算方法:
	      COUNT=SDRAM刷新周期/行数-20=SDRAM刷新周期(us)*SDCLK频率(Mhz)/行数
          我们使用的SDRAM刷新周期为64ms,SDCLK=180/2=90Mhz,行数为8192(2^13).
	      所以,COUNT=64*1000*90/8192-20=683
    */
	HAL_SDRAM_ProgramRefreshRate(&hsdram1,683);             /**< 设置刷新频率 */
}

/**  
 * @brief         初始化流程 
 * @retval        无
 * @return		  无
 * @note          无
 */
void SDRAM_Init(void)
{
    printf("[   INFO] fmc.c : SDRAM_Init Loading...\r\n\r\n");
    MX_FMC_Init();
    
    SDRAM_Init_Process();
    printf("[   INFO] fmc.c : SDRAM_Init Done!\r\n");
}


/*******************函数【结束】*********************/