/**
  ******************************************************************************
  * @file    stm324xg_eval_lcd.h
  * @author  MCD Application Team
  * @version V1.0.2
  * @date    05-March-2012
  * @brief   This file contains all the functions prototypes for the stm324xg_eval_lcd.c
  *          driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2012 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM324xG_EVAL_LCD_H
#define __STM324xG_EVAL_LCD_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
#include "stm324xg_eval.h"
#include "../Common/fonts.h"

/** @addtogroup Utilities
  * @{
  */

/** @addtogroup STM32_EVAL
  * @{
  */ 

/** @addtogroup STM324xG_EVAL
  * @{
  */
    
/** @addtogroup STM324xG_EVAL_LCD
  * @{
  */ 


/** @defgroup STM324xG_EVAL_LCD_Exported_Types
  * @{
  */
typedef struct 
{
  int16_t X;
  int16_t Y;
} Point, * pPoint;   
/**
  * @}
  */ 

/** @defgroup STM324xG_EVAL_LCD_Exported_Constants
  * @{
  */ 

/**
 * @brief Uncomment the line below if you want to use user defined Delay function
 *        (for precise timing), otherwise default _delay_ function defined within
 *         this driver is used (less precise timing).  
 */
/* #define USE_Delay */

#ifdef USE_Delay
#include "main.h" 
  #define _delay_     Delay  /* !< User can provide more timing precise _delay_ function
                                   (with 10ms time base), using SysTick for example */
#else
  #define _delay_     delay      /* !< Default _delay_ function with less precise timing */
#endif

// //#define DISP_HOR_RESOLUTION				320
// //#define DISP_VER_RESOLUTION				240

// #define DISP_ORIENTATION					0
// //#define DISP_ORIENTATION					90
// //#define DISP_ORIENTATION					180
// //#define DISP_ORIENTATION					270

// /* Private define ------------------------------------------------------------*/

// #if  ( DISP_ORIENTATION == 90 ) || ( DISP_ORIENTATION == 270 )

// #define  MAX_X  320
// #define  MAX_Y  240   

// #elif  ( DISP_ORIENTATION == 0 ) || ( DISP_ORIENTATION == 180 )

// #define  MAX_X  240
// #define  MAX_Y  320   

// #endif

// /** 
//   * @brief  LCD color  


// /** 
//   * @brief  LCD Lines depending on the chosen fonts.  
//   */
// #define LCD_LINE_0               LINE(0)
// #define LCD_LINE_1               LINE(1)
// #define LCD_LINE_2               LINE(2)
// #define LCD_LINE_3               LINE(3)
// #define LCD_LINE_4               LINE(4)
// #define LCD_LINE_5               LINE(5)
// #define LCD_LINE_6               LINE(6)
// #define LCD_LINE_7               LINE(7)
// #define LCD_LINE_8               LINE(8)
// #define LCD_LINE_9               LINE(9)
// #define LCD_LINE_10              LINE(10)
// #define LCD_LINE_11              LINE(11)
// #define LCD_LINE_12              LINE(12)
// #define LCD_LINE_13              LINE(13)
// #define LCD_LINE_14              LINE(14)
// #define LCD_LINE_15              LINE(15)
// #define LCD_LINE_16              LINE(16)
// #define LCD_LINE_17              LINE(17)
// #define LCD_LINE_18              LINE(18)
// #define LCD_LINE_19              LINE(19)
// #define LCD_LINE_20              LINE(20)
// #define LCD_LINE_21              LINE(21)
// #define LCD_LINE_22              LINE(22)
// #define LCD_LINE_23              LINE(23)
// #define LCD_LINE_24              LINE(24)
// #define LCD_LINE_25              LINE(25)
// #define LCD_LINE_26              LINE(26)
// #define LCD_LINE_27              LINE(27)
// #define LCD_LINE_28              LINE(28)
// #define LCD_LINE_29              LINE(29)

// /** 
//   * @brief LCD default font 
//   */ 
// #define LCD_DEFAULT_FONT         Font16x24

// /** 
//   * @brief  LCD Direction  
//   */ 
// #define LCD_DIR_HORIZONTAL       0x0000
// #define LCD_DIR_VERTICAL         0x0001

// /** 
//   * @brief  LCD Size (Width and Height)  
//   */ 
// #define LCD_PIXEL_WIDTH          0x0140
// #define LCD_PIXEL_HEIGHT         0x00F0

// /**
//   * @}
//   */ 

/** @defgroup STM324xG_EVAL_LCD_Exported_Macros
  * @{
  */
#define ASSEMBLE_RGB(R ,G, B)    ((((R)& 0xF8) << 8) | (((G) & 0xFC) << 3) | (((B) & 0xF8) >> 3)) 
/**
  * @}
  */ 

/** @defgroup STM324xG_EVAL_LCD_Exported_Functions
  * @{
  */ 
/** @defgroup  
  * @{
  */
// void LCD_DeInit(void);   
// void STM324xG_LCD_Init(void);
// void LCD_SetColors(__IO uint16_t _TextColor, __IO uint16_t _BackColor); 
// void LCD_GetColors(__IO uint16_t *_TextColor, __IO uint16_t *_BackColor);
// void LCD_SetTextColor(__IO uint16_t Color);
// void LCD_SetBackColor(__IO uint16_t Color);
// void LCD_ClearLine(uint16_t Line);
// void LCD_Clear(uint16_t Color);
// void LCD_SetCursor(uint16_t Xpos, uint16_t Ypos);
// void LCD_DrawChar(uint16_t Xpos, uint16_t Ypos, const uint16_t *c);
// void LCD_DisplayChar(uint16_t Line, uint16_t Column, uint8_t Ascii);
// void LCD_SetFont(sFONT *fonts);
// sFONT *LCD_GetFont(void);
// void LCD_DisplayStringLine(uint16_t Line, uint8_t *ptr);
// void LCD_DrawLine(uint16_t Xpos, uint16_t Ypos, uint16_t Length, uint8_t Direction);
// void LCD_DrawRect(uint16_t Xpos, uint16_t Ypos, uint8_t Height, uint16_t Width);
// void LCD_DrawCircle(uint16_t Xpos, uint16_t Ypos, uint16_t Radius);
// void LCD_DrawMonoPict(const uint32_t *Pict);
// void LCD_WriteBMP(uint32_t BmpAddress);
// void LCD_DrawUniLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
// void LCD_DrawFullRect(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height);
// void LCD_DrawFullCircle(uint16_t Xpos, uint16_t Ypos, uint16_t Radius);
// void LCD_PolyLine(pPoint Points, uint16_t PointCount);
// void LCD_PolyLineRelative(pPoint Points, uint16_t PointCount);
// void LCD_ClosedPolyLine(pPoint Points, uint16_t PointCount);
// void LCD_ClosedPolyLineRelative(pPoint Points, uint16_t PointCount);
// void LCD_FillPolyLine(pPoint Points, uint16_t PointCount);
// /**
//   * @}
//   */ 

// /** @defgroup  
//   * @{
//   */ 
// void LCD_WriteReg(uint8_t LCD_Reg, uint16_t LCD_RegValue);
// uint16_t LCD_ReadReg(uint8_t LCD_Reg);
// void LCD_WriteRAM_Prepare(void);
// void LCD_WriteRAM(uint16_t RGB_Code);
// uint16_t LCD_ReadRAM(void);
// /**
//   * @}
//   */ 

// /** @defgroup
//   * @{
//   */ 
// void LCD_CtrlLinesConfig(void);
// void LCD_FSMCConfig(void);
/**
  * @}
  */
/**
  * @}
  */    
#ifdef __cplusplus
}
#endif

#endif /* __STM324xG_EVAL_LCD_H */
/**
  * @}
  */ 

/**
  * @}
  */ 

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
