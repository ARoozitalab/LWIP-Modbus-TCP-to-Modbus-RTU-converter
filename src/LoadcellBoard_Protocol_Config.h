/*
  ******************************************************************************
  * @file    LoadcellBoard_Protocol_Config.h
  * @author  M.A
  * @version V0.0.1
  * @date    04-bahman-1391
  * @brief   For Config Spi AND I2C protocol 
	******************************************************************************
	*/


#ifndef _LOADCELLBOARD_PROTOCOL_CONFIG_H
#define _LOADCELLBOARD_PROTOCOL_CONFIG_H

#include "stm32f4xx.h"
#include  <stdint.h>
#include  <stm32f4xx_spi.h> 
//------------------------------------------------------------------
//  user can define protocol for comunication witch ADS1234
//  in this hedar file "x" sign for user define perpherial
//------------------------------------------------------------------
#define ADS_RCC_APB2Periph_SPIx   	       RCC_APB2Periph_SPI1
//------------------------------------------------------------------
#define ADS_SPIx                           SPI1
#define ADS_SPIx_CLK                       RCC_APB2Periph_SPI1
#define ADS_SPIx_CLK_INIT                  RCC_APB2PeriphClockCmd
#define ADS_SPIx_IRQn                      SPI1_IRQn
#define ADS_SPIx_IRQHANDLER                SPI1_IRQHandler
//-------------------------------------------------------------------
#define ADS_SPIx_SCK_PIN                   GPIO_Pin_5
#define ADS_SPIx_SCK_GPIO_PORT             GPIOA
#define ADS_SPIx_SCK_GPIO_CLK              RCC_AHB1Periph_GPIOA
#define ADS_SPIx_SCK_SOURCE                GPIO_PinSource5
#define ADS_SPIx_SCK_AF                    GPIO_AF_SPI1
//-------------------------------------------------------------------
#define ADS_SPIx_MISO_PIN                  GPIO_Pin_6
#define ADS_SPIx_MISO_GPIO_PORT            GPIOA
#define ADS_SPIx_MISO_GPIO_CLK             RCC_AHB1Periph_GPIOA
#define ADS_SPIx_MISO_SOURCE               GPIO_PinSource6
#define ADS_SPIx_MISO_AF                   GPIO_AF_SPI1
//-------------------------------------------------------------------
#define ADS_SPIx_MOSI_PIN                  GPIO_Pin_5
#define ADS_SPIx_MOSI_GPIO_PORT            GPIOB
#define ADS_SPIx_MOSI_GPIO_CLK             RCC_AHB1Periph_GPIOB
#define ADS_SPIx_MOSI_SOURCE               GPIO_PinSource5
#define ADS_SPIx_MOSI_AF                   GPIO_AF_SPI1
//--------------------------------------------------------------------
#define ADS_SPIX_Direction                 SPI_Direction_2Lines_FullDuplex;
#define ADS_SPIX_DataSize                  SPI_DataSize_8b; 
#define ADS_SPIX_Mode                      SPI_Mode_Master;
#define ADS_SPIX_CPOL                      SPI_CPOL_Low;
#define ADS_SPIX_CPHA                      SPI_CPHA_2Edge;
#define ADS_SPIX_NSS                       SPI_NSS_Soft ;
#define ADS_SPIX_BaudRatePrescaler         SPI_BaudRatePrescaler_256;
#define ADS_SPIX_FirstBit                  SPI_FirstBit_MSB;
#define ADS_SPIX_CRCPolynomial              7;
//--------------------------------------------------------------------
//  user can define protocol for comunication witch PCA9535D
//  in this hedar file "x" sign for user define perpherial
//--------------------------------------------------------------------
#define PCA_I2Cx                          I2C2  // define by user
#define PCA_RCC_APB1Periph_I2CX  	        RCC_APB1Periph_I2C2
#define PCA_I2Cx_CLK                      RCC_APB1Periph_I2C2
//--------------------------------------------------------------------
#define PCA_I2Cx_SDA_PIN                 	GPIO_Pin_0
#define PCA_I2Cx_SDA_GPIO_PORT           	GPIOF
#define PCA_I2Cx_SDA_GPIO_CLK            	RCC_AHB1Periph_GPIOF
#define PCA_I2Cx_SDA_SOURCE              	GPIO_PinSource0
#define PCA_I2Cx_SDA_AF                  	GPIO_AF_I2C2
//---------------------------------------------------------------------
#define PCA_I2Cx_SCL_PIN                 	GPIO_Pin_1
#define PCA_I2Cx_SCL_GPIO_PORT           	GPIOF
#define PCA_I2Cx_SCL_GPIO_CLK            	RCC_AHB1Periph_GPIOF
#define PCA_I2Cx_SCL_SOURCE              	GPIO_PinSource1
#define PCA_I2Cx_SCL_AF                  	GPIO_AF_I2C2
//---------------------------------------------------------------------
//#define I2C_SPEED                    100000
//#define PCA_I2Cx_SLAVE_ADDRESS7      0x30
//---------------------------------------------------------------------
#define	PCA_I2CX_Mode                     I2C_Mode_I2C;
#define	PCA_I2CX_DutyCycle                I2C_DutyCycle_2;
#define	PCA_I2CX_OwnAddress1              0x30//I2C_SLAVE_ADDRESS7;
#define	PCA_I2CX_Ack                      I2C_Ack_Enable;
#define	PCA_I2CX_AcknowledgedAddress      I2C_AcknowledgedAddress_7bit;
#define	PCA_I2CX_ClockSpeed               100000   //I2C_SPEED;
//----------------------------------------------------------------------




/*

//----------------------------------------------------
// for DRDY Pin Of ADS1256 user can set this init
//----------------------------------------------------
#define ADS_RCC_AHB1Periph_DRDY   	       RCC_AHB1Periph_GPIOD  //     define by user
#define ADS_DRDY_Pin                       GPIO_Pin_11           //     define by user 
#define ADS_DRDY_Mode                      GPIO_Mode_IN          // NOT define by user 
#define ADS_DRDY_OType                     GPIO_OType_PP         // NOT define by user 
#define ADS_DRDY_Speed                     GPIO_Speed_50MHz      // NOT define by user 
#define ADS_DRDY_PuPd                      GPIO_PuPd_UP          // NOT define by user 
#define ADS_DRDY_GPIOx                     GPIOD                 //     define GPIO PORT FOR DRDY by user 
//----------------------------------------------------------
// for Chip Select(CS) Pin of ADS1256 user can set this init
//----------------------------------------------------------
#define ADS_RCC_AHB1Periph_CS              RCC_AHB1Periph_GPIOD  //     define by user
#define ADS_CS_Pin                         GPIO_Pin_14           //     define by user 
#define ADS_CS_Mode                        GPIO_Mode_OUT         // NOT define by user 
#define ADS_CS_OType                       GPIO_OType_PP         // NOT define by user 
#define ADS_CS_Speed                       GPIO_Speed_50MHz      // NOT define by user 
#define ADS_CS_PuPd                        GPIO_PuPd_UP          // NOT define by user 
#define ADS_CS_GPIOx                       GPIOD                 //     define GPIO PORT FOR CS by user
//----------------------------------------------------------
// for (SYNC) Pin of ADS1256 user can set this init
//----------------------------------------------------------
#define ADS_RCC_AHB1Periph_SYNC            RCC_AHB1Periph_GPIOG  //     define by user
#define ADS_SYNC_Pin                         GPIO_Pin_4           //     define by user 
#define ADS_SYNC_Mode                        GPIO_Mode_OUT         // NOT define by user 
#define ADS_SYNC_OType                       GPIO_OType_PP         // NOT define by user 
#define ADS_SYNC_Speed                       GPIO_Speed_50MHz      // NOT define by user 
#define ADS_SYNC_PuPd                        GPIO_PuPd_UP          // NOT define by user 
#define ADS_SYNC_GPIOx                       GPIOG                 //     define GPIO PORT FOR CS by user
//----------------------------------------------------------
// for (REST) Pin of ADS1256 user can set this init
//----------------------------------------------------------
#define ADS_RCC_AHB1Periph_REST            RCC_AHB1Periph_GPIOG  //       define by user
#define ADS_REST_Pin                         GPIO_Pin_6           //      define by user 
#define ADS_REST_Mode                        GPIO_Mode_OUT         // NOT define by user 
#define ADS_REST_OType                       GPIO_OType_PP         // NOT define by user 
#define ADS_REST_Speed                       GPIO_Speed_50MHz      // NOT define by user 
#define ADS_REST_PuPd                        GPIO_PuPd_UP          // NOT define by user 
#define ADS_REST_GPIOx                       GPIOG                 //     define GPIO PORT FOR CS by user
//-------------------------------------


*/



#endif
