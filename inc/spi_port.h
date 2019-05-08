/*********************************************************************************************************
*
* File                : spiport.h
* Hardware Environment: stm32f407 eval board "https://github.com/ARoozitalab/STM32F4-Eval-board"
* Version             : V1.0
* By                  : alireza roozitalab
* email               : alireza.roozitalab@gmail.com
* git user            : ARoozitalab
*                                                
*                                          All Rights Reserved
*
*********************************************************************************************************/



#ifndef __SPI_PORT_H
#define __SPI_PORT_H
#include "BASE.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_spi.h"
#ifdef SPI
#if ((SPI_1)|(SPI_2)|(SPI_3))
#ifdef __cplusplus
 extern "C" {
#endif
//************************************************************NSS1	 
	  #define NSS_PIN1  (1<<NSS_PINS1)
 	#if  (NSS_P1 ==  1)
			#define NSS_PORT1    GPIOA
			#define NSS_RCC1    RCC_AHB1Periph_GPIOA
 #elif (NSS_P1 == 2)
			#define NSS_PORT1    GPIOB
			#define NSS_RCC1    RCC_AHB1Periph_GPIOB
 #elif (NSS_P1 == 3)
			#define NSS_PORT1    GPIOC
			#define NSS_RCC1    RCC_AHB1Periph_GPIOC
 #elif (NSS_P1 == 4)
			#define NSS_PORT1   GPIOD
			#define NSS_RCC1    RCC_AHB1Periph_GPIOD
 #elif (NSS_P1 == 5)
			#define NSS_PORT1    GPIOE
			#define NSS_RCC1    RCC_AHB1Periph_GPIOE
 #elif (NSS_P1 == 6)
			#define NSS_PORT1    GPIOF
			#define NSS_RCC1    RCC_AHB1Periph_GPIOF
 #elif (NSS_P1 == 7)
			#define NSS_PORT1    GPIOG
			#define NSS_RCC1    RCC_AHB1Periph_GPIOG
 #elif (NSS_P1 == 8)
			#define NSS_PORT1    GPIOH
			#define NSS_RCC1    RCC_AHB1Periph_GPIOH
 #elif (NSS_P1 == 9)
			#define NSS_PORT1    GPIOI
			#define NSS_RCC1    RCC_AHB1Periph_GPIOI
  #endif
//************************************************************SPI1 PINS
#define MOSI_PIN1   (1<<MOSI_PINS1)
  #define MISO_PIN1   (1<<MISO_PINS1)
	#define SCK_PIN1   (1<<SCK_PINS1)
	
 #if  (MOSI_P1 ==  1)
			#define MOSI_PORT1    GPIOA
			#define MOSI_RCC1    RCC_AHB1Periph_GPIOA
 #elif (MOSI_P1 == 2)
			#define MOSI_PORT1    GPIOB
			#define MOSI_RCC1    RCC_AHB1Periph_GPIOB
 #elif (MOSI_P1 == 3)
			#define MOSI_PORT1    GPIOC
			#define MOSI_RCC1    RCC_AHB1Periph_GPIOC
 #elif (MOSI_P1 == 4)
			#define MOSI_PORT1    GPIOD
			#define MOSI_RCC1    RCC_AHB1Periph_GPIOD
 #elif (MOSI_P1 == 5)
			#define MOSI_PORT1    GPIOE
			#define MOSI_RCC1    RCC_AHB1Periph_GPIOE
 #elif (MOSI_P1 == 6)
			#define MOSI_PORT1    GPIOF
			#define MOSI_RCC1    RCC_AHB1Periph_GPIOF
 #elif (MOSI_P1 == 7)
			#define MOSI_PORT1    GPIOG
			#define MOSI_RCC1    RCC_AHB1Periph_GPIOG
 #elif (MOSI_P1 == 8)
			#define MOSI_PORT1    GPIOH
			#define MOSI_RCC1    RCC_AHB1Periph_GPIOH
 #elif (MOSI_P1 == 9)
			#define MOSI_PORT1    GPIOI
			#define MOSI_RCC1    RCC_AHB1Periph_GPIOI
  #endif
	
 #if  (MISO_P1 ==  1)
			#define MISO_PORT1    GPIOA
			#define MISO_RCC1    RCC_AHB1Periph_GPIOA
 #elif (MISO_P1 == 2)
			#define MISO_PORT1    GPIOB
			#define MISO_RCC1    RCC_AHB1Periph_GPIOB
 #elif (MISO_P1 == 3)
			#define MISO_PORT1    GPIOC
			#define MISO_RCC1    RCC_AHB1Periph_GPIOC
 #elif (MISO_P1 == 4)
			#define MISO_PORT1    GPIOD
			#define MISO_RCC1    RCC_AHB1Periph_GPIOD
 #elif (MISO_P1 == 5)
			#define MISO_PORT1    GPIOE
			#define MISO_RCC1    RCC_AHB1Periph_GPIOE
 #elif (MISO_P1== 6)
			#define MISO_PORT1    GPIOF
			#define MISO_RCC1    RCC_AHB1Periph_GPIOF
 #elif (MISO_P1 == 7)
			#define MISO_PORT1    GPIOG
			#define MISO_RCC1    RCC_AHB1Periph_GPIOG
 #elif (MISO_P1 == 8)
			#define MISO_PORT1    GPIOH
			#define MISO_RCC1    RCC_AHB1Periph_GPIOH
 #elif (MISO_P1 == 9)
			#define MISO_PORT1    GPIOI
			#define MISO_RCC1    RCC_AHB1Periph_GPIOI
  #endif
	
	 #if  (SCK_P1 ==  1)
			#define SCK_PORT1    GPIOA
			#define SCK_RCC1    RCC_AHB1Periph_GPIOA
 #elif (SCK_P1 == 2)
			#define SCK_PORT1    GPIOB
			#define SCK_RCC1    RCC_AHB1Periph_GPIOB
 #elif (SCK_P1== 3)
			#define SCK_PORT1    GPIOC
			#define SCK_RCC1    RCC_AHB1Periph_GPIOC
 #elif (SCK_P1 == 4)
			#define SCK_PORT1    GPIOD
			#define SCK_RCC1    RCC_AHB1Periph_GPIOD
 #elif (SCK_P1 == 5)
			#define SCK_PORT1    GPIOE
			#define SCK_RCC1    RCC_AHB1Periph_GPIOE
 #elif (SCK_P1 == 6)
			#define SCK_PORT1    GPIOF
			#define SCK_RCC1    RCC_AHB1Periph_GPIOF
 #elif (SCK_P1 == 7)
			#define SCK_PORT1    GPIOG
			#define SCK_RCC1    RCC_AHB1Periph_GPIOG
 #elif (SCK_P1 == 8)
			#define SCK_PORT1    GPIOH
			#define SCK_RCC1    RCC_AHB1Periph_GPIOH
 #elif (SCK_P1 == 9)
			#define SCK_PORT1    GPIOI
			#define SCK_RCC1    RCC_AHB1Periph_GPIOI
 #endif
//************************************************************NSS2 PIN
 #define NSS_PIN2   (1<<NSS_PINS2)
 
 	#if  (NSS_P2 ==  1)
			#define NSS_PORT2    GPIOA
			#define NSS_RCC2    RCC_AHB1Periph_GPIOA
 #elif (NSS_P2 == 2)
			#define NSS_PORT2    GPIOB
			#define NSS_RCC2    RCC_AHB1Periph_GPIOB
 #elif (NSS_P2 == 3)
			#define NSS_PORT2    GPIOC
			#define NSS_RCC2    RCC_AHB1Periph_GPIOC
 #elif (NSSP2 == 4)
			#define NSS_PORT2   GPIOD
			#define NSS_RCC2    RCC_AHB1Periph_GPIOD
 #elif (NSS_P2 == 5)
			#define NSS_PORT2    GPIOE
			#define NSS_RCC2    RCC_AHB1Periph_GPIOE
 #elif (NSS_P2 == 6)
			#define NSS_PORT2    GPIOF
			#define NSS_RCC2    RCC_AHB1Periph_GPIOF
 #elif (NSS_P2 == 7)
			#define NSS_PORT2    GPIOG
			#define NSS_RCC2    RCC_AHB1Periph_GPIOG
 #elif (NSS_P2 == 8)
			#define NSS_PORT2    GPIOH
			#define NSS_RCC2    RCC_AHB1Periph_GPIOH
 #elif (NSS_P2 == 9)
			#define NSS_PORT2    GPIOI
			#define NSS_RCC2    RCC_AHB1Periph_GPIOI
  #endif
//****************************************************************SPI2
	#define MOSI_PIN2   (1<<MOSI_PINS2)
 #define MISO_PIN2   (1<<MISO_PINS2)
 #define SCK_PIN2   (1<<SCK_PINS2)
 
 #if  (MOSI_P2 ==  1)
			#define MOSI_PORT2    GPIOA
			#define MOSI_RCC2    RCC_AHB1Periph_GPIOA
 #elif (MOSI_P2 == 2)
			#define MOSI_PORT2    GPIOB
			#define MOSI_RCC2    RCC_AHB1Periph_GPIOB
 #elif (MOSI_P2 == 3)
			#define MOSI_PORT2    GPIOC
			#define MOSI_RCC2    RCC_AHB1Periph_GPIOC
 #elif (MOSI_P2 == 4)
			#define MOSI_PORT2    GPIOD
			#define MOSI_RCC2    RCC_AHB1Periph_GPIOD
 #elif (MOSI_P2 == 5)
			#define MOSI_PORT2    GPIOE
			#define MOSI_RCC2    RCC_AHB1Periph_GPIOE
 #elif (MOSI_P2 == 6)
			#define MOSI_PORT2    GPIOF
			#define MOSI_RCC2    RCC_AHB1Periph_GPIOF
 #elif (MOSI_P2== 7)
			#define MOSI_PORT2    GPIOG
			#define MOSI_RCC2    RCC_AHB1Periph_GPIOG
 #elif (MOSI_P2 == 8)
			#define MOSI_PORT2    GPIOH
			#define MOSI_RCC2    RCC_AHB1Periph_GPIOH
 #elif (MOSI_P2 == 9)
			#define MOSI_PORT2    GPIOI
			#define MOSI_RCC2    RCC_AHB1Periph_GPIOI
  #endif
	
 #if  (MISO_P2 ==  1)
			#define MISO_PORT2    GPIOA
			#define MISO_RCC2    RCC_AHB1Periph_GPIOA
 #elif (MISO_P2 == 2)
			#define MISO_PORT2    GPIOB
			#define MISO_RCC2    RCC_AHB1Periph_GPIOB
 #elif (MISO_P2== 3)
			#define MISO_PORT2    GPIOC
			#define MISO_RCC2    RCC_AHB1Periph_GPIOC
 #elif (MISO_P2 == 4)
			#define MISO_PORT2    GPIOD
			#define MISO_RCC2    RCC_AHB1Periph_GPIOD
 #elif (MISO_P2 == 5)
			#define MISO_PORT2    GPIOE
			#define MISO_RCC2    RCC_AHB1Periph_GPIOE
 #elif (MISO_P2== 6)
			#define MISO_PORT2    GPIOF
			#define MISO_RCC2    RCC_AHB1Periph_GPIOF
 #elif (MISO_P2 == 7)
			#define MISO_PORT2    GPIOG
			#define MISO_RCC2    RCC_AHB1Periph_GPIOG
 #elif (MISO_P2 == 8)
			#define MISO_PORT2    GPIOH
			#define MISO_RCC2    RCC_AHB1Periph_GPIOH
 #elif (MISO_P2 == 9)
			#define MISO_PORT2    GPIOI
			#define MISO_RCC2    RCC_AHB1Periph_GPIOI
  #endif
	
	 #if  (SCK_P2 ==  1)
			#define SCK_PORT2    GPIOA
			#define SCK_RCC2    RCC_AHB1Periph_GPIOA
 #elif (SCK_P2 == 2)
			#define SCK_PORT2    GPIOB
			#define SCK_RCC2    RCC_AHB1Periph_GPIOB
 #elif (SCK_P2== 3)
			#define SCK_PORT2    GPIOC
			#define SCK_RCC2    RCC_AHB1Periph_GPIOC
 #elif (SCK_P2 == 4)
			#define SCK_PORT2    GPIOD
			#define SCK_RCC2    RCC_AHB1Periph_GPIOD
 #elif (SCK_P2 == 5)
			#define SCK_PORT2    GPIOE
			#define SCK_RCC2    RCC_AHB1Periph_GPIOE
 #elif (SCK_P2 == 6)
			#define SCK_PORT2    GPIOF
			#define SCK_RCC2    RCC_AHB1Periph_GPIOF
 #elif (SCK_P2 == 7)
			#define SCK_PORT2    GPIOG
			#define SCK_RCC2    RCC_AHB1Periph_GPIOG
 #elif (SCK_P2 == 8)
			#define SCK_PORT2    GPIOH
			#define SCK_RCC2    RCC_AHB1Periph_GPIOH
 #elif (SCK_P2 == 9)
			#define SCK_PORT2    GPIOI
			#define SCK_RCC2    RCC_AHB1Periph_GPIOI
  #endif
//**************************************************************NSS3
	#define NSS_PIN3    (1<<NSS_PINS3)
 
 	#if  (NSS_P3 ==  1)
			#define NSS_PORT3    GPIOA
			#define NSS_RCC3    RCC_AHB1Periph_GPIOA
 #elif (NSS_P3 == 2)
			#define NSS_PORT3    GPIOB
			#define NSS_RCC3    RCC_AHB1Periph_GPIOB
 #elif (NSS_P3 == 3)
			#define NSS_PORT3    GPIOC
			#define NSS_RCC3    RCC_AHB1Periph_GPIOC
 #elif (NSSP3 == 4)
			#define NSS_PORT3    GPIOD
			#define NSS_RCC3    RCC_AHB1Periph_GPIOD
 #elif (NSS_P3 == 5)
			#define NSS_PORT3    GPIOE
			#define NSS_RCC3    RCC_AHB1Periph_GPIOE
 #elif (NSS_P3 == 6)
			#define NSS_PORT3    GPIOF
			#define NSS_RCC3    RCC_AHB1Periph_GPIOF
 #elif (NSS_P3 == 7)
			#define NSS_PORT3    GPIOG
			#define NSS_RCC3    RCC_AHB1Periph_GPIOG
 #elif (NSS_P3 == 8)
			#define NSS_PORT3    GPIOH
			#define NSS_RCC3    RCC_AHB1Periph_GPIOH
 #elif (NSS_P3 == 9)
			#define NSS_PORT3    GPIOI
			#define NSS_RCC3    RCC_AHB1Periph_GPIOI
  #endif
//***********************************************************SPI3
#define MOSI_PIN2   (1<<MOSI_PINS2)
 #define MISO_PIN2   (1<<MISO_PINS2)
 #define SCK_PIN2   (1<<SCK_PINS2)
 
 #if  (MOSI_P3 ==  1)
			#define MOSI_PORT3    GPIOA
			#define MOSI_RCC3    RCC_AHB1Periph_GPIOA
 #elif (MOSI_P3 == 2)
			#define MOSI_PORT3    GPIOB
			#define MOSI_RCC3    RCC_AHB1Periph_GPIOB
 #elif (MOSI_P3 == 3)
			#define MOSI_PORT3    GPIOC
			#define MOSI_RCC3    RCC_AHB1Periph_GPIOC
 #elif (MOSI_P3 == 4)
			#define MOSI_PORT3    GPIOD
			#define MOSI_RCC3    RCC_AHB1Periph_GPIOD
 #elif (MOSI_P3 == 5)
			#define MOSI_PORT3    GPIOE
			#define MOSI_RCC3    RCC_AHB1Periph_GPIOE
 #elif (MOSI_P3 == 6)
			#define MOSI_PORT3    GPIOF
			#define MOSI_RCC3    RCC_AHB1Periph_GPIOF
 #elif (MOSI_P3== 7)
			#define MOSI_PORT3    GPIOG
			#define MOSI_RCC3    RCC_AHB1Periph_GPIOG
 #elif (MOSI_P3 == 8)
			#define MOSI_PORT3    GPIOH
			#define MOSI_RCC3    RCC_AHB1Periph_GPIOH
 #elif (MOSI_P3 == 9)
			#define MOSI_PORT3    GPIOI
			#define MOSI_RCC3    RCC_AHB1Periph_GPIOI
  #endif
	
 #if  (MISO_P3 ==  1)
			#define MISO_PORT3   GPIOA
			#define MISO_RCC3    RCC_AHB1Periph_GPIOA
 #elif (MISO_P3 == 2)
			#define MISO_PORT3    GPIOB
			#define MISO_RCC3    RCC_AHB1Periph_GPIOB
 #elif (MISO_P3== 3)
			#define MISO_PORT3    GPIOC
			#define MISO_RCC3    RCC_AHB1Periph_GPIOC
 #elif (MISO_P3 == 4)
			#define MISO_PORT3    GPIOD
			#define MISO_RCC3    RCC_AHB1Periph_GPIOD
 #elif (MISO_P3 == 5)
			#define MISO_PORT3    GPIOE
			#define MISO_RCC3    RCC_AHB1Periph_GPIOE
 #elif (MISO_P3== 6)
			#define MISO_PORT3    GPIOF
			#define MISO_RCC3    RCC_AHB1Periph_GPIOF
 #elif (MISO_P3 == 7)
			#define MISO_PORT3    GPIOG
			#define MISO_RCC3    RCC_AHB1Periph_GPIOG
 #elif (MISO_P3 == 8)
			#define MISO_PORT3    GPIOH
			#define MISO_RCC3    RCC_AHB1Periph_GPIOH
 #elif (MISO_P3 == 9)
			#define MISO_PORT3    GPIOI
			#define MISO_RCC3    RCC_AHB1Periph_GPIOI
  #endif
	
	 #if  (SCK_P3 ==  1)
			#define SCK_PORT3    GPIOA
			#define SCK_RCC3    RCC_AHB1Periph_GPIOA
 #elif (SCK_P3 == 2)
			#define SCK_PORT3    GPIOB
			#define SCK_RCC3    RCC_AHB1Periph_GPIOB
 #elif (SCK_P3== 3)
			#define SCK_PORT3    GPIOC
			#define SCK_RCC3    RCC_AHB1Periph_GPIOC
 #elif (SCK_P3 == 4)
			#define SCK_PORT3    GPIOD
			#define SCK_RCC3    RCC_AHB1Periph_GPIOD
 #elif (SCK_P3 == 5)
			#define SCK_PORT3    GPIOE
			#define SCK_RCC3    RCC_AHB1Periph_GPIOE
 #elif (SCK_P3 == 6)
			#define SCK_PORT3    GPIOF
			#define SCK_RCC3    RCC_AHB1Periph_GPIOF
 #elif (SCK_P3 == 7)
			#define SCK_PORT3    GPIOG
			#define SCK_RCC3    RCC_AHB1Periph_GPIOG
 #elif (SCK_P3 == 8)
			#define SCK_PORT3    GPIOH
			#define SCK_RCC3    RCC_AHB1Periph_GPIOH
 #elif (SCK_P3 == 9)
			#define SCK_PORT3    GPIOI
			#define SCK_RCC3    RCC_AHB1Periph_GPIOI
  #endif
//****************************************************FUNCTIONS
void SPI_GPIO_INIT(void); 
void SPI_INIT(void);
void SPI_delay(void);	 
 void SPI_Send_byte(u16 data);
 u16 SPI_Receive_byte(void);
void SPI_SEND(SPI_TypeDef * SPIX,uint16_t DATA); 	 
uint8_t SPI_Recive(SPI_TypeDef * SPIX);  
	 
	 
	 
	 
	 

	 
	 
	 
	 
#ifdef __cplusplus
}
#endif
#endif 
#endif 
#endif 
