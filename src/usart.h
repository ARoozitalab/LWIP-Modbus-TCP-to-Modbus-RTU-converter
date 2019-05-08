#ifndef _USART_H
#define _USART_H

#include <stdio.h>
#include "stm32f4xx.h"

//#define	USART1_OPEN
//#define	USART2_OPEN
#define	USART3_OPEN
//#define UART5_OPEN


/**
 * @brief Definition for COM port1, connected to USART3
 */ 
#ifdef	USART1_OPEN  
	#define Open_USART                        USART1
	#define Open_USART_CLK                    RCC_APB2Periph_USART1
	
	#define Open_USART_TX_PIN                 GPIO_Pin_9
	#define Open_USART_TX_GPIO_PORT           GPIOA
	#define Open_USART_TX_GPIO_CLK            RCC_AHB1Periph_GPIOA
	#define Open_USART_TX_SOURCE              GPIO_PinSource9
	#define Open_USART_TX_AF                  GPIO_AF_USART1
	
	
	#define Open_USART_RX_PIN                 GPIO_Pin_10
	#define Open_USART_RX_GPIO_PORT           GPIOA
	#define Open_USART_RX_GPIO_CLK            RCC_AHB1Periph_GPIOA
	#define Open_USART_RX_SOURCE              GPIO_PinSource10
	#define Open_USART_RX_AF                  GPIO_AF_USART1
	
	#define Open_USART_IRQn                   USART1_IRQn
	#define USARTx_IRQHANDLER  				  USART1_IRQHandler

#elif	defined	USART2_OPEN
	#define Open_USART                        USART2
	#define Open_USART_CLK                    RCC_APB1Periph_USART2
	
	#define Open_USART_TX_PIN                 GPIO_Pin_2
	#define Open_USART_TX_GPIO_PORT           GPIOA
	#define Open_USART_TX_GPIO_CLK            RCC_AHB1Periph_GPIOA
	#define Open_USART_TX_SOURCE              GPIO_PinSource2
	#define Open_USART_TX_AF                  GPIO_AF_USART2
	
	
	#define Open_USART_RX_PIN                 GPIO_Pin_3
	#define Open_USART_RX_GPIO_PORT           GPIOA
	#define Open_USART_RX_GPIO_CLK            RCC_AHB1Periph_GPIOA
	#define Open_USART_RX_SOURCE              GPIO_PinSource3
	#define Open_USART_RX_AF                  GPIO_AF_USART2
	
	#define Open_USART_IRQn                   USART2_IRQn
	#define USARTx_IRQHANDLER  				  USART2_IRQHandler

#elif	defined	USART3_OPEN
	#define Open_USART                        USART3
	#define Open_USART_CLK                    RCC_APB1Periph_USART3
	
	#define Open_USART_TX_PIN                 GPIO_Pin_8
	#define Open_USART_TX_GPIO_PORT           GPIOD
	#define Open_USART_TX_GPIO_CLK            RCC_AHB1Periph_GPIOD
	#define Open_USART_TX_SOURCE              GPIO_PinSource8
	#define Open_USART_TX_AF                  GPIO_AF_USART3
	
	
	#define Open_USART_RX_PIN                 GPIO_Pin_9
	#define Open_USART_RX_GPIO_PORT           GPIOD
	#define Open_USART_RX_GPIO_CLK            RCC_AHB1Periph_GPIOD
	#define Open_USART_RX_SOURCE              GPIO_PinSource9
	#define Open_USART_RX_AF                  GPIO_AF_USART3
	
	#define Open_USART_IRQn                   USART3_IRQn
	#define USARTx_IRQHANDLER  				  USART3_IRQHandler
//----------------------------------------------------------	
#elif	defined	UART5_OPEN
	#define Open_USART                        UART5
	#define Open_USART_CLK                    RCC_APB1Periph_UART5
	
	#define Open_USART_TX_PIN                 GPIO_Pin_12
	#define Open_USART_TX_GPIO_PORT           GPIOC
	#define Open_USART_TX_GPIO_CLK            RCC_AHB1Periph_GPIOC
	#define Open_USART_TX_SOURCE              GPIO_PinSource12
	#define Open_USART_TX_AF                  GPIO_AF_UART5
	
	
	#define Open_USART_RX_PIN                 GPIO_Pin_2
	#define Open_USART_RX_GPIO_PORT           GPIOD
	#define Open_USART_RX_GPIO_CLK            RCC_AHB1Periph_GPIOD
	#define Open_USART_RX_SOURCE              GPIO_PinSource2
	#define Open_USART_RX_AF                  GPIO_AF_UART5
	
	#define Open_USART_IRQn                   UART5_IRQn
	#define USARTx_IRQHANDLER  				  UART5_IRQHandler	
//--------------------------------------------------------------	
#else
	#error "Please select The COM to be used (in usart.h)"
#endif 		 

void USART_Configuration(void);
void USART_NVIC_Config(void);

#endif /*_USART_H*/
