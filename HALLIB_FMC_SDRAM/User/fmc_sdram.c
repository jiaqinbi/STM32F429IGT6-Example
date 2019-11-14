
/******************************************************
 *  @brief  	sdram���á����ܺ����ļ�               *              
 *  @file   	fmc_sdram.c                           *
 *  @author 	�ϼ���                                *
 *  @version	v1.0                                  *
 *  @date  	    2019��11��14��                        *
 *  @note       ʵ��FMC����sdram��չоƬ���ڴ�ʵ��    *
 ******************************************************/

/*******************ͷ�ļ�����ʼ��*********************/
#include "fmc_sdram.h"
#include "stdio.h"
/*******************ͷ�ļ���������*********************/

/*******************������������ʼ��*********************/
SDRAM_HandleTypeDef hsdram1;
static uint32_t FMC_Initialized = 0;
static uint32_t FMC_DeInitialized = 0;
/*******************����������������*********************/

/*******************��������ʼ��*********************/
/**  
 * @brief         FMC������ʼ��
 * @retval        ��
 * @return		  ��
 * @note          ��
 */
 void MX_FMC_Init(void)
{
  FMC_SDRAM_TimingTypeDef SdramTiming;
    
  hsdram1.Instance = FMC_SDRAM_DEVICE;
  /* hsdram1.Init */
  hsdram1.Init.SDBank = FMC_SDRAM_BANK1;                                /**< sdram����Ϊ1 -- bank1 */
  hsdram1.Init.ColumnBitsNumber = FMC_SDRAM_COLUMN_BITS_NUM_9;          /**< �е�ַ 9λ */
  hsdram1.Init.RowBitsNumber = FMC_SDRAM_ROW_BITS_NUM_13;               /**< �е�ַ 13λ */
  hsdram1.Init.MemoryDataWidth = FMC_SDRAM_MEM_BUS_WIDTH_16;            /**< �����߿��16λ */
  hsdram1.Init.InternalBankNumber = FMC_SDRAM_INTERN_BANKS_NUM_4;       /**< SDRAM�ڲ�BANK���� */
  hsdram1.Init.CASLatency = FMC_SDRAM_CAS_LATENCY_3;                    /**< CAS��ʱ����3 */
  hsdram1.Init.WriteProtection = FMC_SDRAM_WRITE_PROTECTION_DISABLE;    /**< д�����ر� */
  hsdram1.Init.SDClockPeriod = FMC_SDRAM_CLOCK_PERIOD_2;                /**< hclk����Ƶ */
  hsdram1.Init.ReadBurst = FMC_SDRAM_RBURST_ENABLE;                     /**< ��ȡͻ��ģʽʹ�� */
  hsdram1.Init.ReadPipeDelay = FMC_SDRAM_RPIPE_DELAY_1;                 /**< ��ȡ��ʱ */
  /* SdramTiming */
  
  /// ��ʼ��ʱ��ṹ��
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
 * @brief         ��ʼ��FMC��SDRAMʹ�õ�GPIO 
 * @retval        ��
 * @return		  ��
 * @note          ��
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
 * @brief         ʹ�������ʼ��SDRAM 
 * @retval        ��
 * @return		  ��
 * @note          ��
 */
static void SDRAM_Init_Process(void)
{
    FMC_SDRAM_CommandTypeDef Command;
    /* 1.����SDCLK */
    Command.CommandMode = FMC_SDRAM_CMD_CLK_ENABLE;     /**< ʹ��ʱ�� */
    Command.CommandTarget = FMC_SDRAM_CMD_TARGET_BANK1; /**< �洢����1 */
    Command.ModeRegisterDefinition = 0;
    Command.AutoRefreshNumber = 0;
    HAL_SDRAM_SendCommand(&hsdram1, &Command, 0x0010);    
    while(HAL_SDRAM_GetState(&hsdram1) == HAL_SDRAM_STATE_BUSY);    /**< �ȴ��������� */
//    HAL_SDRAM_SendCommand(FMC_SDRAM_TypeDef *Device, FMC_SDRAM_CommandTypeDef *Command, uint32_t Timeout);
    HAL_Delay(201);
    
    /* 2.������bank���г�� */
    Command.CommandMode = FMC_SDRAM_CMD_PALL;     /**< ������bank���г�� */
    Command.CommandTarget = FMC_SDRAM_CMD_TARGET_BANK1; /**< �洢����1 */
    Command.ModeRegisterDefinition = 0;
    Command.AutoRefreshNumber = 0;
    HAL_SDRAM_SendCommand(&hsdram1, &Command, 0x0010);    
    while(HAL_SDRAM_GetState(&hsdram1) == HAL_SDRAM_STATE_BUSY);    /**< �ȴ��������� */
    
    /* 3.�����Զ�ˢ���������8�� */
    Command.CommandMode = FMC_SDRAM_CMD_PALL;     /**< �����Զ�ˢ������ */
    Command.CommandTarget = FMC_SDRAM_CMD_TARGET_BANK1; /**< �洢����1 */
    Command.ModeRegisterDefinition = 0;
    Command.AutoRefreshNumber = 8;                      /**< �Զ�ˢ��8�� */
    HAL_SDRAM_SendCommand(&hsdram1, &Command, 0x0010);    
    while(HAL_SDRAM_GetState(&hsdram1) == HAL_SDRAM_STATE_BUSY);    /**< �ȴ��������� */
    
    /* 4.����ģʽ�Ĵ��� */
    uint32_t temp=0;
    temp=(uint32_t)SDRAM_MODEREG_BURST_LENGTH_1     |	/**< ����ͻ������:1(������1/2/4/8) */
              SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL   |	/**< ����ͻ������:����(����������/����) */
              SDRAM_MODEREG_CAS_LATENCY_3           |	/**< ����CASֵ:3(������2/3) */
              SDRAM_MODEREG_OPERATING_MODE_STANDARD |   /**< ���ò���ģʽ:0,��׼ģʽ */
              SDRAM_MODEREG_WRITEBURST_MODE_SINGLE;     /**< ����ͻ��дģʽ:1,������� */
    
    Command.CommandMode = FMC_SDRAM_CMD_LOAD_MODE;      /**< �����Զ�ˢ������ */
    Command.CommandTarget = FMC_SDRAM_CMD_TARGET_BANK1; /**< �洢����1 */
    Command.ModeRegisterDefinition = temp;
    Command.AutoRefreshNumber = 0;                      /**< ����ˢ�� */
    HAL_SDRAM_SendCommand(&hsdram1, &Command, 0x0010);    
    while(HAL_SDRAM_GetState(&hsdram1) == HAL_SDRAM_STATE_BUSY);    /**< �ȴ��������� */
    
    /** 5.����SDRAM��ˢ������    ����ˢ��
          ˢ��Ƶ�ʼ�����(��SDCLKƵ�ʼ���),���㷽��:
	      COUNT=SDRAMˢ������/����-20=SDRAMˢ������(us)*SDCLKƵ��(Mhz)/����
          ����ʹ�õ�SDRAMˢ������Ϊ64ms,SDCLK=180/2=90Mhz,����Ϊ8192(2^13).
	      ����,COUNT=64*1000*90/8192-20=683
    */
	HAL_SDRAM_ProgramRefreshRate(&hsdram1,683);             /**< ����ˢ��Ƶ�� */
}

/**  
 * @brief         ��ʼ������ 
 * @retval        ��
 * @return		  ��
 * @note          ��
 */
void SDRAM_Init(void)
{
    printf("[   INFO] fmc.c : SDRAM_Init Loading...\r\n\r\n");
    MX_FMC_Init();
    
    SDRAM_Init_Process();
    printf("[   INFO] fmc.c : SDRAM_Init Done!\r\n");
}


/*******************������������*********************/