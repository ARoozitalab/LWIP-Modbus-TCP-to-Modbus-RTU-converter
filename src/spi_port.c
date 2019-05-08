/*********************************************************************************************************
*
* File                : spiport.c
* Hardware Environment: stm32f407 eval board "https://github.com/ARoozitalab/STM32F4-Eval-board"
* Version             : V1.0
* By                  : alireza roozitalab
* email               : alireza.roozitalab@gmail.com
* git user            : ARoozitalab
*                                                
*                                          All Rights Reserved
*
*********************************************************************************************************/
#include "spi_port.h"

void SPI_delay(void)
{
char i;
for(i=0;i<85;i++);	
	
	
}
void SPI_GPIO_INIT(void)
{ 
		GPIO_InitTypeDef GPIO_InitStructure;
#if (SPI_1)
	#if (REMAP1)
			RCC_AHB1PeriphClockCmd(MOSI_RCC1 ,ENABLE);
			RCC_AHB1PeriphClockCmd(MISO_RCC1 ,ENABLE);
			RCC_AHB1PeriphClockCmd(SCK_RCC1  ,ENABLE);
	    #if (MICRO) // for stm 407 only
					GPIO_PinAFConfig(MOSI_PORT1,MOSI_PINS1,  GPIO_AF_SPI1);
					GPIO_PinAFConfig(MISO_PORT1, MISO_PINS1,  GPIO_AF_SPI1);
					GPIO_PinAFConfig(SCK_PORT1, SCK_PINS1 , GPIO_AF_SPI1);
			#endif
			GPIO_InitStructure.GPIO_Pin   = MOSI_PIN1;
			GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
			GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;  
			GPIO_Init(MOSI_PORT1, &GPIO_InitStructure);

			GPIO_InitStructure.GPIO_Pin = MISO_PIN1;
			GPIO_Init(MISO_PORT1, &GPIO_InitStructure);

			GPIO_InitStructure.GPIO_Pin = SCK_PIN1;
			GPIO_Init(SCK_PORT1, &GPIO_InitStructure);

	#else
	
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
			#if  (MICRO)
			GPIO_PinAFConfig(GPIOA, GPIO_PinSource5,  GPIO_AF_SPI1);
			GPIO_PinAFConfig(GPIOA, GPIO_PinSource6,  GPIO_AF_SPI1);
			GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_SPI1);
			#endif
			GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
			GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
			GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;  
			GPIO_Init(GPIOA, &GPIO_InitStructure);
	#endif
	
	
	

#if (NSS1)
			RCC_AHB1PeriphClockCmd(NSS_RCC1  ,ENABLE);
			GPIO_InitStructure.GPIO_Pin = NSS_PIN1;
			GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_OUT;
			GPIO_Init(NSS_PORT1, &GPIO_InitStructure);
#else 
			RCC_AHB1PeriphClockCmd(NSS_RCC1  ,ENABLE);
			#if  (MICRO)
			  GPIO_PinAFConfig(GPIOA, GPIO_PinSource4,  GPIO_AF_SPI1);
			#endif
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
				GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
			  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		 	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
			  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;  
				GPIO_Init(GPIOA, &GPIO_InitStructure);

#endif


#endif


#if (SPI_2)
	#if (REMAP2)
			RCC_AHB1PeriphClockCmd(MOSI_RCC2 ,ENABLE);
			RCC_AHB1PeriphClockCmd(MISO_RCC2 ,ENABLE);
			RCC_AHB1PeriphClockCmd(SCK_RCC2  ,ENABLE);
			#if  (MICRO) // for stm 407 only
					GPIO_PinAFConfig(MOSI_PORT2 ,MOSI_PINS2, GPIO_AF_SPI1);
					GPIO_PinAFConfig(MISO_PORT2, MISO_PINS2, GPIO_AF_SPI1);
					GPIO_PinAFConfig(SCK_PORT2,  SCK_PINS2 ,GPIO_AF_SPI1);
			#endif
			GPIO_InitStructure.GPIO_Pin = MOSI_PIN2;
			GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
			GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;  
			GPIO_Init(MOSI_PORT2, &GPIO_InitStructure);

			GPIO_InitStructure.GPIO_Pin = MISO_PIN2;
			GPIO_Init(MISO_PORT2, &GPIO_InitStructure);

			GPIO_InitStructure.GPIO_Pin = SCK_PIN1;
			GPIO_Init(SCK_PORT2, &GPIO_InitStructure);
	
	#else
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);
			GPIO_PinAFConfig(GPIOB, GPIO_PinSource13,  GPIO_AF_SPI1);
			GPIO_PinAFConfig(GPIOB, GPIO_PinSource14,  GPIO_AF_SPI1);
			GPIO_PinAFConfig(GPIOB,  GPIO_PinSource15 , GPIO_AF_SPI1);
			
			GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
				GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
			  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		 	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
			  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;   
			GPIO_Init(GPIOB,&GPIO_InitStructure);
	#endif
	
	
	
	#if  (NSS2)
			RCC_AHB1PeriphClockCmd(NSS_RCC2  ,ENABLE);
			GPIO_InitStructure.GPIO_Pin = NSS_PIN2;
			GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_OUT;
			GPIO_Init(NSS_PORT2, &GPIO_InitStructure);
#else 
      RCC_AHB1PeriphClockCmd(NSS_RCC2  ,ENABLE);
			#if  (MICRO)
			  GPIO_PinAFConfig(GPIOB, GPIO_PinSource12,  GPIO_AF_SPI1);
			#endif
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
				GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
				GPIO_Init(GPIOB, &GPIO_InitStructure);

#endif


#endif

#if (SPI_3)
	#if (REMAP3)
			RCC_AHB1PeriphClockCmd(MOSI_RCC3 ,ENABLE);
			RCC_AHB1PeriphClockCmd(MISO_RCC3 ,ENABLE);
			RCC_AHB1PeriphClockCmd(SCK_RCC3  ,ENABLE);
			#if  (MICRO)// for stm 407 only
					GPIO_PinAFConfig(MOSI_PORT3 ,MOSI_PINS3, GPIO_AF_SPI1);
					GPIO_PinAFConfig(MISO_PORT3,MISO_PINS3, GPIO_AF_SPI1);
					GPIO_PinAFConfig(SCK_PORT3, SCK_PINS3 ,GPIO_AF_SPI1);
			#endif
			GPIO_InitStructure.GPIO_Pin = MOSI_PIN3;
			GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
			GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;  
			GPIO_Init(MOSI_PORT3, &GPIO_InitStructure);

			GPIO_InitStructure.GPIO_Pin = MISO_PIN3;
			GPIO_Init(MISO_PORT3, &GPIO_InitStructure);

			GPIO_InitStructure.GPIO_Pin = SCK_PIN3;
			GPIO_Init(SCK_PORT3, &GPIO_InitStructure);
	
	#else
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);
			GPIO_PinAFConfig(GPIOB, GPIO_PinSource3,  GPIO_AF_SPI1);
			GPIO_PinAFConfig(GPIOB, GPIO_PinSource4,  GPIO_AF_SPI1);
			GPIO_PinAFConfig(GPIOB,  GPIO_PinSource5 , GPIO_AF_SPI1);
			
			GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5;
			GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
			GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;  
			GPIO_Init(GPIOB ,&GPIO_InitStructure);
	#endif
	
	#if  (NSS3)
			RCC_AHB1PeriphClockCmd(NSS_RCC3  ,ENABLE);
			GPIO_InitStructure.GPIO_Pin = NSS_PIN3;
			GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_OUT;
			GPIO_Init(NSS_PORT3, &GPIO_InitStructure);
#else 
			#if  (MICRO)
			  GPIO_PinAFConfig(GPIOA, GPIO_PinSource15,  GPIO_AF_SPI1);
			#endif
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
				GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
			  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		 	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
			  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;  
				GPIO_Init(GPIOA, &GPIO_InitStructure);

#endif
#endif
}

void SPI_INIT()
{
  
	SPI_InitTypeDef SPI_InitStruct;
			SPI_DeInit(SPI1);
 SPI_GPIO_INIT();	
#if (SPI)
  #if (SPI_1)
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1,ENABLE);
			SPI_InitStruct.SPI_Direction= DIRECTION1;
			SPI_InitStruct.SPI_DataSize =SIZE1; 
			SPI_InitStruct.SPI_Mode =  MODE1;
			SPI_InitStruct.SPI_CPOL = CPOL1;
			SPI_InitStruct.SPI_CPHA = CPHA1;
			SPI_InitStruct.SPI_BaudRatePrescaler = BAUDRATE1 ;
			SPI_InitStruct.SPI_FirstBit = FIRSTBIT1;	
			#if (NSS1)
			SPI_InitStruct.SPI_NSS = SPI_NSS_Soft ;
			#else
			SPI_InitStruct.SPI_NSS = SPI_NSS_Hard ;
			#endif
			SPI_Init(SPI1, &SPI_InitStruct);
			SPI_Cmd(SPI1, ENABLE);	
			#if (NSS1==0)
		 SPI_SSOutputCmd(SPI1, ENABLE);
			#endif
			
		#endif


		#if (SPI_2)
			RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2,ENABLE);
			SPI_InitStruct.SPI_Direction= DIRECTION2;
			SPI_InitStruct.SPI_DataSize = SIZE2; 
			SPI_InitStruct.SPI_Mode = MODE2;
			SPI_InitStruct.SPI_CPOL = CPOL2;
			SPI_InitStruct.SPI_CPHA = CPHA2;
			SPI_InitStruct.SPI_BaudRatePrescaler = BAUDRATE2 ;
			SPI_InitStruct.SPI_FirstBit = FIRSTBIT2;	
			#if (NSS2)
			SPI_InitStruct.SPI_NSS = SPI_NSS_Soft ;
			#else
			SPI_InitStruct.SPI_NSS = SPI_NSS_Hard ;
			#endif
			SPI_Init(SPI2, &SPI_InitStruct);
			SPI_Cmd(SPI2, ENABLE);	
			#if (NSS2==0)
			SPI_SSOutputCmd(SPI2, ENABLE);
			#endif
		#endif


		#if (SPI_3)
			RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI3,ENABLE);
			SPI_InitStruct.SPI_Direction= DIRECTION3;
			SPI_InitStruct.SPI_DataSize = SIZE3; 
			SPI_InitStruct.SPI_Mode = MODE3;
			SPI_InitStruct.SPI_CPOL = CPOL3;
			SPI_InitStruct.SPI_CPHA = CPHA3;
			SPI_InitStruct.SPI_BaudRatePrescaler = BAUDRATE3 ;
			SPI_InitStruct.SPI_FirstBit = FIRSTBIT3;	
			#if (NSS3)
			SPI_InitStruct.SPI_NSS = SPI_NSS_Soft ;
			#else
			SPI_InitStruct.SPI_NSS = SPI_NSS_Hard ;
			#endif
			SPI_Init(SPI3, &SPI_InitStruct);
			SPI_Cmd(SPI3, ENABLE);	
			#if (NSS3==0)
			 SPI_SSOutputCmd(SPI3, ENABLE);
			#endif
		#endif
#endif
}


void SPI_SEND(SPI_TypeDef * SPIX,uint16_t DATA)
{
			
#if ((SPI_1) & (NSS1))
	GPIO_ResetBits(NSS_PORT1, NSS_PIN1);
#endif
#if ((SPI_2) & (NSS2))
	GPIO_ResetBits(NSS_PORT2, NSS_PIN1);
#endif
#if ((SPI_3) & (NSS3))
	GPIO_ResetBits(NSS_PORT3, NSS_PIN1);
#endif	
 	while(SPI_I2S_GetFlagStatus(SPIX, SPI_I2S_FLAG_TXE)==RESET);	
 SPI_I2S_SendData(SPIX,DATA);	
 	while(SPI_I2S_GetFlagStatus(SPIX, SPI_I2S_FLAG_TXE)==RESET);
  SPI_delay();
#if ((SPI_1) & (NSS1))
	GPIO_SetBits(NSS_PORT1, NSS_PIN1);
#endif
#if ((SPI_2) & (NSS2))
	GPIO_SetBits(NSS_PORT2, NSS_PIN1);
#endif
#if ((SPI_3) & (NSS3))
	GPIO_SetBits(NSS_PORT3, NSS_PIN1);
#endif
}


uint8_t SPI_Recive(SPI_TypeDef * SPIX)
{
#if ((SPI_1) & (NSS1))
	GPIO_ResetBits(NSS_PORT1, NSS_PIN1);
#endif
#if ((SPI_2) & (NSS2))
	GPIO_ResetBits(NSS_PORT2, NSS_PIN1);
#endif
#if ((SPI_3) & (NSS3))
	GPIO_ResetBits(NSS_PORT3, NSS_PIN1);
#endif	
	
//	while(SPI_I2S_GetFlagStatus(SPIX, SPI_I2S_FLAG_TXE)==RESET);
	SPI_I2S_SendData(SPIX,0);
	while(SPI_I2S_GetFlagStatus(SPIX, SPI_I2S_FLAG_RXNE)==RESET);	 
SPI_delay();
	SPI_delay();
#if ((SPI_1) & (NSS1))
	GPIO_SetBits(NSS_PORT1, NSS_PIN1);
#endif
#if ((SPI_2) & (NSS2))
	GPIO_SetBits(NSS_PORT2, NSS_PIN1);
#endif
#if ((SPI_3) & (NSS3))
	GPIO_SetBits(NSS_PORT3, NSS_PIN1);
#endif
	return SPI_I2S_ReceiveData(SPIX);	
	
}


 void SPI_Send_byte(u16 data)
{
	 while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE)==RESET);
	 SPI_I2S_SendData(SPI1,data);
}
//-----------------------------------------------------
u16 SPI_Receive_byte(void)
{
	//while(SPI_I2S_GetFlagStatus(ADS_SPIx, SPI_I2S_FLAG_TXE)==RESET);
	//SPI_I2S_SendData(ADS_SPIx,0x00);
	
	while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE)==RESET);
	return SPI_I2S_ReceiveData(SPI1);
}
