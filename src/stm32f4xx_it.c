/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    31-October-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_it.h"
#include "main.h"
#include "usart.h"
#include <stm32f4x7_eth.h>
#include "modbustcp.h"
#include <string.h>
#include "lwip/mem.h"
#include "netif/etharp.h"
#include "ethernetif.h"
#include "stm32f4x7_eth.h"

#include "modbus.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/
/* Ethernet Rx & Tx DMA Descriptors */
extern ETH_DMADESCTypeDef  DMARxDscrTab[ETH_RXBUFNB], DMATxDscrTab[ETH_TXBUFNB];
uint64_t count=0;

/* Ethernet Driver Receive buffers  */
extern uint8_t Rx_Buff[ETH_RXBUFNB][ETH_RX_BUF_SIZE]; 

/* Ethernet Driver Transmit buffers */
extern uint8_t Tx_Buff[ETH_TXBUFNB][ETH_TX_BUF_SIZE]; 

/* Global pointers to track current transmit and receive descriptors */
extern ETH_DMADESCTypeDef  *DMATxDescToSet;
extern ETH_DMADESCTypeDef  *DMARxDescToGet;

/* Global pointer for last received frame infos */
extern ETH_DMA_Rx_Frame_infos *DMA_RX_FRAME_infos;
uint64_t difs_count=0;
uint64_t difs_countmb=0;


char ready_flag=0;
/**
  * @brief   This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{

  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
//void SVC_Handler(void)
//{
//}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
//void PendSV_Handler(void)
//{
//}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */

void USARTx_IRQHANDLER(void)
{
  if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)
  { 
		mb_buf[mb_count]=USART_ReceiveData(USART3);
    mb_count++;
	  setms_timecountmb(3);
  }
	
}
//void SysTick_Handler(void)
//{
//  /* Update the LocalTime by adding SYSTEMTICK_PERIOD_MS each SysTick interrupt */
//  Time_Update();
//}




/**
  * @brief  This function handles External line 10 interrupt request.
  * @param  None
  * @retval None
  */
void EXTI15_10_IRQHandler(void)
{
  if(EXTI_GetITStatus(ETH_LINK_EXTI_LINE) != RESET)
  {
    Eth_Link_ITHandler(DP83848_PHY_ADDRESS);
    /* Clear interrupt pending bit */
    EXTI_ClearITPendingBit(ETH_LINK_EXTI_LINE);
  }
}




//////////////////////////////////////////////////

//---------------------set ms for reach------------------------//10֓
void setms_timecount(uint32_t set_count)
{
	difs_count=count +((set_count*ms_devider)/ms_multiple);
}
//---------------------set us for reach------------------------//10֓
void setus_timecount(uint32_t set_count)
{
	difs_count=count+((set_count*us_devider)/us_multiple);
}



uint8_t dif_count()
{
	if(difs_count>=count)
		return 0;
	
	return 1;
	
}





void setms_timecountmb(uint32_t set_count)
{
	difs_countmb=count +((set_count*ms_devider)/ms_multiple);
}

uint8_t dif_countmb()
{
	if(difs_countmb>=count)
		return 0;
	
	return 1;
	
}
////////////////////////////////////






/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f4xx.s).                                               */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
