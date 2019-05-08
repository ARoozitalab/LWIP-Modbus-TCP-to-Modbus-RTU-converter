/*
  ******************************************************************************
  * @file    LoadcellBoard_Protocol_Config.c
  * @author  M.A
  * @version V0.0.1
  * @date    04-bahman-1391
  * @brief   For Config Spi AND I2C protocol 
	******************************************************************************
	*/
#include "stm32f4xx.h"
//#include <PCA9535D_Protocol_Config.h>
#include <LoadcellBoard_Protocol_Config.h>
#include <stm32f4xx_gpio.h>
#include <stm32f4xx_rcc.h>
#include <stm32f4xx_spi.h>
#include <spi_port.h>
#include <base.h>
//-----------------------------------------------------------------
void PCA_I2C_Configuration(void)
{
  I2C_InitTypeDef   I2C_InitStructure; 
	GPIO_InitTypeDef  GPIO_InitStructure;
  //-----------------------------------	
	RCC_AHB1PeriphClockCmd(PCA_I2Cx_SDA_GPIO_CLK | PCA_I2Cx_SCL_GPIO_CLK,ENABLE);
	RCC_APB1PeriphClockCmd(PCA_I2Cx_CLK,ENABLE);
	//-----------------------------------
	GPIO_PinAFConfig(PCA_I2Cx_SDA_GPIO_PORT, PCA_I2Cx_SDA_SOURCE, PCA_I2Cx_SDA_AF);
	GPIO_PinAFConfig(PCA_I2Cx_SCL_GPIO_PORT, PCA_I2Cx_SCL_SOURCE, PCA_I2Cx_SCL_AF);
	//-----------------------------------
	GPIO_InitStructure.GPIO_Pin    =    PCA_I2Cx_SDA_PIN;
	GPIO_InitStructure.GPIO_Mode   =    GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType  =    GPIO_OType_OD;
  GPIO_InitStructure.GPIO_Speed  =    GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd   =    GPIO_PuPd_NOPULL;
	GPIO_Init(PCA_I2Cx_SDA_GPIO_PORT, &GPIO_InitStructure);
  //-----------------------------------
	GPIO_InitStructure.GPIO_Pin =  PCA_I2Cx_SCL_PIN;
	GPIO_Init(PCA_I2Cx_SCL_GPIO_PORT, &GPIO_InitStructure);
	//-----------------------------------	
	I2C_DeInit(PCA_I2Cx);
	I2C_InitStructure.I2C_Mode                =    PCA_I2CX_Mode;
	I2C_InitStructure.I2C_DutyCycle           =    PCA_I2CX_DutyCycle;
	I2C_InitStructure.I2C_OwnAddress1         =    PCA_I2CX_OwnAddress1;
	I2C_InitStructure.I2C_Ack                 =    PCA_I2CX_Ack;
	I2C_InitStructure.I2C_AcknowledgedAddress =    PCA_I2CX_AcknowledgedAddress;
	I2C_InitStructure.I2C_ClockSpeed          =    PCA_I2CX_ClockSpeed;
	I2C_Cmd(PCA_I2Cx, ENABLE);
	I2C_Init(PCA_I2Cx, &I2C_InitStructure);
	//I2C_AcknowledgeConfig(PCA_I2Cx, ENABLE);
}


void ADS_SPI_Configuration(void)
{
		 
	GPIO_InitTypeDef GPIO_InitStructure;
	SPI_InitTypeDef SPI_InitStruct;
	//-----------------------------------------------
	RCC_AHB1PeriphClockCmd(ADS_SPIx_SCK_GPIO_CLK | ADS_SPIx_MISO_GPIO_CLK | ADS_SPIx_MOSI_GPIO_CLK,ENABLE);
	RCC_APB2PeriphClockCmd(ADS_RCC_APB2Periph_SPIx,ENABLE);//tik_test
  //------------------------------------------------	
	GPIO_PinAFConfig(ADS_SPIx_SCK_GPIO_PORT,  ADS_SPIx_SCK_SOURCE,  ADS_SPIx_MOSI_AF);
	GPIO_PinAFConfig(ADS_SPIx_MISO_GPIO_PORT, ADS_SPIx_MISO_SOURCE, ADS_SPIx_MOSI_AF);
	GPIO_PinAFConfig(ADS_SPIx_MOSI_GPIO_PORT, ADS_SPIx_MOSI_SOURCE, ADS_SPIx_MOSI_AF);
	//------------------------------------------------
	GPIO_InitStructure.GPIO_Pin      = ADS_SPIx_SCK_PIN;
	GPIO_InitStructure.GPIO_Mode     = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed    = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType    = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd     = GPIO_PuPd_DOWN;  
	GPIO_Init(ADS_SPIx_SCK_GPIO_PORT, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = ADS_SPIx_MISO_PIN;
	GPIO_Init(ADS_SPIx_MISO_GPIO_PORT, &GPIO_InitStructure);
  //-------------------------------------------------
	GPIO_InitStructure.GPIO_Pin = ADS_SPIx_MOSI_PIN;
	GPIO_Init(ADS_SPIx_MOSI_GPIO_PORT, &GPIO_InitStructure);
  //-------------------------------------------------
	SPI_I2S_DeInit(ADS_SPIx);
	SPI_InitStruct.SPI_Direction         = ADS_SPIX_Direction;
	SPI_InitStruct.SPI_DataSize          = ADS_SPIX_DataSize; 
	SPI_InitStruct.SPI_Mode              = ADS_SPIX_Mode;
	SPI_InitStruct.SPI_CPOL              = ADS_SPIX_CPOL ;
	SPI_InitStruct.SPI_CPHA              = ADS_SPIX_CPHA;
	SPI_InitStruct.SPI_NSS               = ADS_SPIX_NSS ;
	SPI_InitStruct.SPI_BaudRatePrescaler = ADS_SPIX_BaudRatePrescaler;
	SPI_InitStruct.SPI_FirstBit          = ADS_SPIX_FirstBit;
	SPI_InitStruct.SPI_CRCPolynomial     = ADS_SPIX_CRCPolynomial;
	SPI_Init(ADS_SPIx, &SPI_InitStruct);
	SPI_Cmd(ADS_SPIx, ENABLE);
  //--------------------------------------------------
}
//  void SPI_Send_byte(u16 data)
// {
// 	 while(SPI_I2S_GetFlagStatus(ADS_SPIx, SPI_I2S_FLAG_TXE)==RESET);
// 	 SPI_I2S_SendData(ADS_SPIx,data);
// }
// //-----------------------------------------------------
// u16 SPI_Receive_byte(void)
// {
// 	//while(SPI_I2S_GetFlagStatus(ADS_SPIx, SPI_I2S_FLAG_TXE)==RESET);
// 	//SPI_I2S_SendData(ADS_SPIx,0x00);
// 	
// 	while(SPI_I2S_GetFlagStatus(ADS_SPIx, SPI_I2S_FLAG_RXNE)==RESET);
// 	return SPI_I2S_ReceiveData(ADS_SPIx);
// }
