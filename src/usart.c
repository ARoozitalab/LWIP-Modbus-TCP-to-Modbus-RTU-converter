#include "usart.h"

#ifdef __GNUC__
  /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

/*******************************************************************************
* Function Name  : USART_Configuration
* Description    : Configure Open_USART 
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void USART_Configuration(void)
{ 												
  GPIO_InitTypeDef GPIO_InitStructure;
  USART_InitTypeDef USART_InitStructure; 

  RCC_AHB1PeriphClockCmd(Open_USART_TX_GPIO_CLK,ENABLE);
  RCC_AHB1PeriphClockCmd(Open_USART_RX_GPIO_CLK,ENABLE);
 RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);
  #ifdef	USART1_OPEN
  	RCC_APB2PeriphClockCmd(Open_USART_CLK,ENABLE);
  #else
  	RCC_APB1PeriphClockCmd(Open_USART_CLK,ENABLE);
  #endif	


  GPIO_PinAFConfig(Open_USART_TX_GPIO_PORT, Open_USART_TX_SOURCE, Open_USART_TX_AF);
  GPIO_PinAFConfig(Open_USART_RX_GPIO_PORT, Open_USART_RX_SOURCE, Open_USART_RX_AF);

  /*
  *  Open_USART_TX -> PA9 , Open_USART_RX -PA10
  */
  GPIO_InitStructure.GPIO_Pin = Open_USART_TX_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;

  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(Open_USART_TX_GPIO_PORT, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = Open_USART_RX_PIN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(Open_USART_RX_GPIO_PORT, &GPIO_InitStructure);

/*
   		 USARTx configured as follow:
         - BaudRate = 115200 baud  
		 - Word Length = 8 Bits
         - One Stop Bit
         - No parity
         - Hardware flow control disabled (RTS and CTS signals)
         - Receive and transmit    
 */

  USART_InitStructure.USART_BaudRate = 9600;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  USART_Init(Open_USART, &USART_InitStructure);
  /* Enable the Open_USART Transmit interrupt: this interrupt is generated when the 
     Open_USART transmit data register is empty */
 // USART_ITConfig(Open_USART,USART_IT_RXNE,ENABLE);

  USART_Cmd(Open_USART, ENABLE);

}

void USART_NVIC_Config(void)
{
//   NVIC_InitTypeDef NVIC_InitStructure;

//   /* Enable the USARTx Interrupt */
//   NVIC_InitStructure.NVIC_IRQChannel = Open_USART_IRQn;
//   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 250;
//   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 250;
//   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//   NVIC_Init(&NVIC_InitStructure);
}

/* Use no semihosting */
//#if 1
//#pragma import(__use_no_semihosting)
//struct __FILE
//{  
//	int handle;
//};
//FILE __stdout;

//_sys_exit(int x)
//{
//	x = x;
//}
//#endif

/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART */
  USART_SendData(Open_USART, (uint8_t) ch);

  /* Loop until the end of transmission */
  while (USART_GetFlagStatus(Open_USART, USART_FLAG_TC) == RESET)
  {}

  return ch;
}
