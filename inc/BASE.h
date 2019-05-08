/*********************************************************************************************************
*
* File                : base.h
* Hardware Environment: 
* Build Environment   : RealView MDK-ARM  Version: 4.20
* Version             : V1.0(just spi protocol)
* By                  : alireza roozitalab
*
*                                              
*                                          All Rights Reserved
*
*********************************************************************************************************/




/*
//-------- <<< Use Configuration Wizard in Context Menu >>> ------------------
*/




//     <o>      MICRO: choose your micro
//                     <i> choise your micro.
//                   <1=>STM32F407
//                   <0=>STM32F107



#define MICRO           1

//      <e> USE_SPI 
//

#define SPI     1

/*            
//      <e> SPI1_ENABLE
//  
//                 
         
*/

#define SPI_1     1   

/*
//     <o>      Direction:choose the  Direction of spi
//                     <i>choose the  Direction of spi
//                   <0x0000=>2Lines FullDuplex          
//                   <0x0400=>2Lines RxOnly
//                   <0x8000=>1Line Rx          
//                   <0xC000=>1Line Tx 
*/
#define DIRECTION1      0

/*
//     <o>      MODE:choose the  mode of spi
//                     <i>choose the  mode of spi
//                   <0x0104=>MASTER          
//                   <0x0000=>SLAVE                  
*/
#define MODE1      260

/*
//     <o>      Data Size:choose the  size of data
//                     <i>choose the  size of data
//                   <0x0800=>16 Bit         
//                   <0x0000=>8 Bit                 
*/
#define SIZE1      0

/*
//     <o>      Clock Polarity:choose Clock Polarity
//                     <i>choose Clock Polarity
//                   <0x0002=>High        
//                   <0x0000=>Low                 
*/
#define CPOL1      0
/*
//     <o>      Clock Phase:choose Clock Phase
//                     <i>choose Clock Phase
//                   <0x0000=>1Edge        
//                   <0x0001=>2Edge                
*/
#define CPHA1      1

/*
//     <o>      FirstBit:choose FirstBit
//                     <i>choose Clock FirstBit
//                   <0x0000=>MSB        
//                   <0x0080=>LSB                
*/
#define FIRSTBIT1     0

/*
//     <o>      BaudRate Prescaler:choose the BaudRate Prescaler
//                     <i>choose the BaudRate Prescaler
//                   <0x0000=>2          
//                   <0x0008=>4
//                   <0x0010=>8        
//                   <0x0018=>16 
//                   <0x0020=>32        
//                   <0x0028=>64
//                   <0x0030=>128        
//                   <0x0038=>256 
*/
#define BAUDRATE1      32

/*
//<e> SOFT NSS
//
//     <o1>      NSS PIN
//      <i>choose the  NSS pin
//      <0=>PIN0          
//      <1=>PIN1 
//      <2=>PIN2
//      <3=>PIN3
//      <4=>PIN4
//      <5=>PIN5
//      <6=>PIN6
//      <7=>PIN7
//      <8=>PIN8
//      <9=>PIN9
//      <10=>PIN10
//      <11=>PIN11
//      <12=>PIN12
//      <13=>PIN13
//      <14=>PIN14
//      <15=>PIN15

//     <o2>      NSS PORT
//      <i>choose the  NSS PORT
//      <1=>A          
//      <2=>B
//      <3=>C
//      <4=>D
//      <5=>E
//      <6=>F
//      <7=>G          
//      <8=>H
//      <9=>I
//
//  </e> SOFT NSS
*/
 #define NSS1        1
 #define NSS_PINS1    13
 #define NSS_P1      4

	/* 
//<e> USE REMAP PIN

//     <o1>      MOSI PIN
//      <i>choose the  MOSI pin
//      <0=>PIN0          
//      <1=>PIN1 
//      <2=>PIN2
//      <3=>PIN3
//      <4=>PIN4
//      <5=>PIN5
//      <6=>PIN6
//      <7=>PIN7
//      <8=>PIN8
//      <9=>PIN9
//      <10=>PIN10
//      <11=>PIN11
//      <12=>PIN12
//      <13=>PIN13
//      <14=>PIN14
//      <15=>PIN15

//     <o2>      MOSI PORT
//      <i>choosee the  MOSI PORT
//      <1=>A          
//      <2=>B
//      <3=>C
//      <4=>D
//      <5=>E
//      <6=>F
//      <7=>G          
//      <8=>H
//      <9=>I



//     <o3>      MISO PIN
//      <i>choose the  MISO pin
//      <0=>PIN0          
//      <1=>PIN1 
//      <2=>PIN2
//      <3=>PIN3
//      <4=>PIN4
//      <5=>PIN5
//      <6=>PIN6
//      <7=>PIN7
//      <8=>PIN8
//      <9=>PIN9
//      <10=>PIN10
//      <11=>PIN11
//      <12=>PIN12
//      <13=>PIN13
//      <14=>PIN14
//      <15=>PIN15

//     <o4>      MISO PORT
//      <i>choose the  MISO PORT
//      <1=>A          
//      <2=>B
//      <3=>C
//      <4=>D
//      <5=>E
//      <6=>F
//      <7=>G          
//      <8=>H
//      <9=>I

 
//     <o5>      SCK PIN
//      <i>choose the  SCK pin
//      <0=>PIN0          
//      <1=>PIN1 
//      <2=>PIN2
//      <3=>PIN3
//      <4=>PIN4
//      <5=>PIN5
//      <6=>PIN6
//      <7=>PIN7
//      <8=>PIN8
//      <9=>PIN9
//      <10=>PIN10
//      <11=>PIN11
//      <12=>PIN12
//      <13=>PIN13
//      <14=>PIN14
//      <15=>PIN15

//     <o6>      SCK PORT
//      <i>choose the  SCK PORT
//      <1=>A          
//      <2=>B
//      <3=>C
//      <4=>D
//      <5=>E
//      <6=>F
//      <7=>G          
//      <8=>H
//      <9=>I

//

*/
 #define REMAP1			 1
 #define MOSI_PINS1   5
 #define MOSI_P1     1
 
 #define MISO_PINS1   6
 #define MISO_P1     1 
 
 #define SCK_PINS1    5
 #define SCK_P1      2
 
  

//</e>
//</e>
///----------------------------------------------------------------
/*            
//      <e> SPI2_ENABLE
//   
//                
         
*/

#define SPI_2     0   

/*
//     <o>      Direction:choose the  Direction of spi
//                     <i>choose the  Direction of spi
//                   <0x0000=>2Lines FullDuplex          
//                   <0x0400=>2Lines RxOnly
//                   <0x8000=>1Line Rx          
//                   <0xC000=>1Line Tx 
*/
#define DIRECTION2      0

/*
//     <o>      MODE:choose the  mode of spi
//                     <i>choose the  mode of spi
//                   <0x0104=>MASTER          
//                   <0x0000=>SLAVE                  
*/
#define MODE2      260

/*
//     <o>      Data Size:choose the  size of data
//                     <i>choose the  size of data
//                   <0x0800=>16 Bit         
//                   <0x0000=>8 Bit                 
*/
#define SIZE2      0

/*
//     <o>      Clock Polarity:choose Clock Polarity
//                     <i>choose Clock Polarity
//                   <0x0002=>High        
//                   <0x0000=>Low                 
*/
#define CPOL2      2
/*
//     <o>      Clock Phase:choose Clock Phase
//                     <i>choose Clock Phase
//                   <0x0000=>1Edge        
//                   <0x0001=>2Edge                
*/
#define CPHA2      0

/*
//     <o>      FirstBit:choose FirstBit
//                     <i>choose Clock FirstBit
//                   <0x0000=>MSB        
//                   <0x0080=>LSB                
*/
#define FIRSTBIT2     0

/*
//     <o>      BaudRate Prescaler:choose the BaudRate Prescaler
//                     <i>choose the BaudRate Prescaler
//                   <0x0000=>2          
//                   <0x0008=>4
//                   <0x0010=>8        
//                   <0x0018=>16 
//                   <0x0020=>32        
//                   <0x0028=>64
//                   <0x0030=>128        
//                   <0x0038=>256 
*/
#define BAUDRATE2      40

/*
//<e> SOFT NSS
//
//     <o1>      NSS PIN
//      <i>choose the  NSS pin
//      <0=>PIN0          
//      <1=>PIN1 
//      <2=>PIN2
//      <3=>PIN3
//      <4=>PIN4
//      <5=>PIN5
//      <6=>PIN6
//      <7=>PIN7
//      <8=>PIN8
//      <9=>PIN9
//      <10=>PIN10
//      <11=>PIN11
//      <12=>PIN12
//      <13=>PIN13
//      <14=>PIN14
//      <15=>PIN15

//     <o2>      NSS PORT
//      <i>choose the  NSS PORT
//      <1=>A          
//      <2=>B
//      <3=>C
//      <4=>D
//      <5=>E
//      <6=>F
//      <7=>G          
//      <8=>H
//      <9=>I
//
//  </e> SOFT NSS
*/
 #define NSS2        0
 #define NSS_PINS2    512
 #define NSS_P2      5
 
	/* 
//<e> USE REMAP PIN

//     <o1>      MOSI PIN
//      <i>choose the  MOSI pin
//      <0=>PIN0          
//      <1=>PIN1 
//      <2=>PIN2
//      <3=>PIN3
//      <4=>PIN4
//      <5=>PIN5
//      <6=>PIN6
//      <7=>PIN7
//      <8=>PIN8
//      <9=>PIN9
//      <10=>PIN10
//      <11=>PIN11
//      <12=>PIN12
//      <13=>PIN13
//      <14=>PIN14
//      <15=>PIN15

//     <o2>      MOSI PORT
//      <i>choosee the  MOSI PORT
//      <1=>A          
//      <2=>B
//      <3=>C
//      <4=>D
//      <5=>E
//      <6=>F
//      <7=>G          
//      <8=>H
//      <9=>I



//     <o3>      MISO PIN
//      <i>choose the  MISO pin
//      <0=>PIN0          
//      <1=>PIN1 
//      <2=>PIN2
//      <3=>PIN3
//      <4=>PIN4
//      <5=>PIN5
//      <6=>PIN6
//      <7=>PIN7
//      <8=>PIN8
//      <9=>PIN9
//      <10=>PIN10
//      <11=>PIN11
//      <12=>PIN12
//      <13=>PIN13
//      <14=>PIN14
//      <15=>PIN15

//     <o4>      MISO PORT
//      <i>choose the  MISO PORT
//      <1=>A          
//      <2=>B
//      <3=>C
//      <4=>D
//      <5=>E
//      <6=>F
//      <7=>G          
//      <8=>H
//      <9=>I

 
//     <o5>      SCK PIN
//      <i>choose the  SCK pin
//      <0=>PIN0          
//      <1=>PIN1 
//      <2=>PIN2
//      <3=>PIN3
//      <4=>PIN4
//      <5=>PIN5
//      <6=>PIN6
//      <7=>PIN7
//      <8=>PIN8
//      <9=>PIN9
//      <10=>PIN10
//      <11=>PIN11
//      <12=>PIN12
//      <13=>PIN13
//      <14=>PIN14
//      <15=>PIN15

//     <o6>      SCK PORT
//      <i>choose the  SCK PORT
//      <1=>A          
//      <2=>B
//      <3=>C
//      <4=>D
//      <5=>E
//      <6=>F
//      <7=>G          
//      <8=>H
//      <9=>I

//

*/
 #define REMAP2			  0
 #define MOSI_PINS2   1
 #define MOSI_P2      1
 
 #define MISO_PINS2   1
 #define MISO_P2      1 
 
 #define SCK_PINS2    1
 #define SCK_P2       1
 
 
//</e>
//</e>
///----------------------------------------------------------------
/*            
//      <e> SPI3_ENABLE
//     
//                  
         
*/

#define SPI_3     0   

/*
//     <o>      Direction:choose the  Direction of spi
//                     <i>choose the  Direction of spi
//                   <0x0000=>2Lines FullDuplex          
//                   <0x0400=>2Lines RxOnly
//                   <0x8000=>1Line Rx          
//                   <0xC000=>1Line Tx 
*/
#define DIRECTION3      0

/*
//     <o>      MODE:choose the  mode of spi
//                     <i>choose the  mode of spi
//                   <0x0104=>MASTER          
//                   <0x0000=>SLAVE                  
*/
#define MODE3      260

/*
//     <o>      Data Size:choose the  size of data
//                     <i>choose the  size of data
//                   <0x0800=>16 Bit         
//                   <0x0000=>8 Bit                 
*/
#define SIZE3      0

/*
//     <o>      Clock Polarity:choose Clock Polarity
//                     <i>choose Clock Polarity
//                   <0x0002=>High        
//                   <0x0000=>Low                 
*/
#define CPOL3      2
/*
//     <o>      Clock Phase:choose Clock Phase
//                     <i>choose Clock Phase
//                   <0x0000=>1Edge        
//                   <0x0001=>2Edge                
*/
#define CPHA3      0

/*
//     <o>      FirstBit:choose FirstBit
//                     <i>choose Clock FirstBit
//                   <0x0000=>MSB        
//                   <0x0080=>LSB                
*/
#define FIRSTBIT3     0

/*
//     <o>      BaudRate Prescaler:choose the BaudRate Prescaler
//                     <i>choose the BaudRate Prescaler
//                   <0x0000=>2          
//                   <0x0008=>4
//                   <0x0010=>8        
//                   <0x0018=>16 
//                   <0x0020=>32        
//                   <0x0028=>64
//                   <0x0030=>128        
//                   <0x0038=>256 
*/
#define BAUDRATE3      0

/*
//<e> SOFT NSS
//
//     <o1>      NSS PIN
//      <i>choose the  NSS pin
//      <0=>PIN0          
//      <1=>PIN1 
//      <2=>PIN2
//      <3=>PIN3
//      <4=>PIN4
//      <5=>PIN5
//      <6=>PIN6
//      <7=>PIN7
//      <8=>PIN8
//      <9=>PIN9
//      <10=>PIN10
//      <11=>PIN11
//      <12=>PIN12
//      <13=>PIN13
//      <14=>PIN14
//      <15=>PIN15

//     <o2>      NSS PORT
//      <i>choose the  NSS PORT
//      <1=>A          
//      <2=>B
//      <3=>C
//      <4=>D
//      <5=>E
//      <6=>F
//      <7=>G          
//      <8=>H
//      <9=>I
//
//  </e> SOFT NSS
*/
 #define NSS3        0
 #define NSS_PINS3    512
 #define NSS_P3      5
 
	/* 
//<e> USE REMAP PIN

//     <o1>      MOSI PIN
//      <i>choose the  MOSI pin
//      <0=>PIN0          
//      <1=>PIN1 
//      <2=>PIN2
//      <3=>PIN3
//      <4=>PIN4
//      <5=>PIN5
//      <6=>PIN6
//      <7=>PIN7
//      <8=>PIN8
//      <9=>PIN9
//      <10=>PIN10
//      <11=>PIN11
//      <12=>PIN12
//      <13=>PIN13
//      <14=>PIN14
//      <15=>PIN15

//     <o2>      MOSI PORT
//      <i>choosee the  MOSI PORT
//      <1=>A          
//      <2=>B
//      <3=>C
//      <4=>D
//      <5=>E
//      <6=>F
//      <7=>G          
//      <8=>H
//      <9=>I



//     <o3>      MISO PIN
//      <i>choose the  MISO pin
//      <0=>PIN0          
//      <1=>PIN1 
//      <2=>PIN2
//      <3=>PIN3
//      <4=>PIN4
//      <5=>PIN5
//      <6=>PIN6
//      <7=>PIN7
//      <8=>PIN8
//      <9=>PIN9
//      <10=>PIN10
//      <11=>PIN11
//      <12=>PIN12
//      <13=>PIN13
//      <14=>PIN14
//      <15=>PIN15

//     <o4>      MISO PORT
//      <i>choose the  MISO PORT
//      <1=>A          
//      <2=>B
//      <3=>C
//      <4=>D
//      <5=>E
//      <6=>F
//      <7=>G          
//      <8=>H
//      <9=>I

 
//     <o5>      SCK PIN
//      <i>choose the  SCK pin
//      <0=>PIN0          
//      <1=>PIN1 
//      <2=>PIN2
//      <3=>PIN3
//      <4=>PIN4
//      <5=>PIN5
//      <6=>PIN6
//      <7=>PIN7
//      <8=>PIN8
//      <9=>PIN9
//      <10=>PIN10
//      <11=>PIN11
//      <12=>PIN12
//      <13=>PIN13
//      <14=>PIN14
//      <15=>PIN15

//     <o6>      SCK PORT
//      <i>choose the  SCK PORT
//      <1=>A          
//      <2=>B
//      <3=>C
//      <4=>D
//      <5=>E
//      <6=>F
//      <7=>G          
//      <8=>H
//      <9=>I

//

*/
 #define REMAP3			 1
 #define MOSI_PINS3    1
 #define MOSI_P3      1
 
 #define MISO_PINS3    1
 #define MISO_P3      1 
 
 #define SCK_PINS3    1
 #define SCK_P3       1
 
  
//</e>
//</e>
//</e>

