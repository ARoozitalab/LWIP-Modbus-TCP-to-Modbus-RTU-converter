/*********************************************************************************************************
*
* File                : main.c
* Hardware Environment: stm32f407 eval board "https://github.com/ARoozitalab/STM32F4-Eval-board"
* Version             : V1.0
* By                  : alireza roozitalab
* email               : alireza.roozitalab@gmail.com
* git user            : ARoozitalab
*                                                
*                                          All Rights Reserved
*
*********************************************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "stm32f4x7_eth.h"
#include "netconf.h"
#include "main.h"
#include "httpd.h"
#include "serial_debug.h"
#include "usart.h"
#include "modbus.h"
#include "SST25VF016B.h"
#include "FlashDriver.h"


#include <spi_port.h>
#include <base.h>
#include "stm32f4xx_rtc.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_it.h"

#define SYSTEMTICK_PERIOD_MS  10



__IO uint32_t AsynchPrediv = 0, SynchPrediv = 0;


__IO uint32_t LocalTime = 0;
uint32_t timingdelay;
char IP_ADDR0 ;
char IP_ADDR1 ;
char IP_ADDR2 ;
char IP_ADDR3;




void LCD_LED_Init(void);
long long num_save[5]={0};
 char mobus_rflag=0;
	char *mget;
/* delay functions ---------------------------------------------------------*/
void delay()
{
int j; 
for(j=0;j<1000000;j++)
for(j=0;j<1000000;j++);
	
}

/**
  * @brief  eth rtu task
  * @param  None
  * @retval None
  */
void ETH_Task(void * pvArg)
{
IP_ADDR0 =192;
IP_ADDR1 =168;
IP_ADDR2 =1;
IP_ADDR3 =10;




delay();
delay();
ETH_BSP_Config();

/* Initilaize the LwIP stack */
LwIP_Init();

/* Http webserver In it */
httpd_init();
	
	for(;;)
	{
	  if (ETH_CheckFrameReceived())
    { 
      /* process received ethernet packet */
     LwIP_Pkt_Handle();
  	}
    /* handle periodic timers for LwIP */
    LwIP_Periodic_Handle(LocalTime);

  	}
		
	}


/**
  * @brief  modbus rtu task
  * @param  None
  * @retval None
  */
void MODBUS_Task(void * pvArg)
{
	int i=0;
		df_read_open(0x10);	
	df_read((uint8_t *)&bud_rate,4); 
	if(bud_rate==0xffffffff)
		bud_rate=9600;
	
	df_read_open(0x20);		
	df_read((uint8_t *)&stp_bit,1); 
	if(stp_bit==0xff)
		stp_bit=1;
	
	
	df_read_open(0x21);	
	df_read((uint8_t *)&dta_bit,1); 
	if(dta_bit==0xff)
		dta_bit=8;	
		
	df_read_open(0x22);	
	df_read((uint8_t *)&prt_bit,1); 
	if(prt_bit==0xff)
		prt_bit=1;	
	
	
		df_write_close();	
init_modnus();
	 GPIO_SetBits(GPIOB,GPIO_Pin_15) ;
	for(;;)
	{
		if(mobus_rflag==1)
		{
					mb_count=0;
				for(i=0;i<100;i++)
				mb_buf[i]=0;
			
			if((mget[7]==0x6)||(mget[7]==0x3)||(mget[7]==0x4))
			 modbus_read_req(&mget[6],6);
			if(mget[7]==0x10)
		  	 modbus_write_req(&mget[6],7+(mget[12]));
			

		mobus_rflag=0;
  	}
	}

}




/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */

int main(void)
{

		SPI_FLASH_Init();
   SPI_FLASH_Test();
   LCD_LED_Init();

	


	xTaskCreate( ETH_Task , ( signed char * ) NULL , 1300 , NULL , 2 , NULL );
	xTaskCreate( MODBUS_Task , ( signed char * ) NULL , 1300 , NULL , 2 , NULL );
	vTaskStartScheduler();
  while (1);
		

}






/**
  * @brief  Updates the system local time
  * @param  None
  * @retval None
  */
void Time_Update(void)
{
  LocalTime += SYSTEMTICK_PERIOD_MS;
}

/**
  * @brief  Initializes the STM324xG-EVAL's LCD and LEDs resources.
  * @param  None
  * @retval None
  */

void LCD_LED_Init(void)
{
#ifdef USE_LCD
  /* Initialize the STM324xG-EVAL's LCD */
  STM324xG_LCD_Init();
#endif

  /* Initialize STM324xG-EVAL's LEDs */
  STM_EVAL_LEDInit(LED1);
  STM_EVAL_LEDInit(LED2);
  STM_EVAL_LEDInit(LED3);
  STM_EVAL_LEDInit(LED4);
  
#ifdef USE_LCD
  /* Clear the LCD */
  LCD_Clear(Black);

  /* Set the LCD Back Color */
  LCD_SetBackColor(Black);

  /* Set the LCD Text Color */
  LCD_SetTextColor(White);

  /* Display message on the LCD*/
  LCD_DisplayStringLine(Line0, (uint8_t*)MESSAGE1);
  LCD_DisplayStringLine(Line1, (uint8_t*)MESSAGE2);
  LCD_DisplayStringLine(Line2, (uint8_t*)MESSAGE3);
  LCD_DisplayStringLine(Line3, (uint8_t*)MESSAGE4);  
#endif
}
#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {}
}
#endif


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
