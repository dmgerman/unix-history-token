begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Theses defines come from an atmel file that says specifically that it  * has no copyright.  *  * These defines are also usable for the AT91SAM9260 which has pin multiplexing  * that is identical to the AT91SAM9G20.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARM_AT91_AT91_PIO_SAM9G20_H
end_ifndef

begin_define
define|#
directive|define
name|ARM_AT91_AT91_PIO_SAM9G20_H
end_define

begin_include
include|#
directive|include
file|<arm/at91/at91_pioreg.h>
end_include

begin_comment
comment|// *****************************************************************************
end_comment

begin_comment
comment|//               PIO DEFINITIONS FOR AT91SAM9G20
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_define
define|#
directive|define
name|AT91C_PA0_SPI0_MISO
value|(AT91C_PIO_PA0)
end_define

begin_comment
comment|//  SPI 0 Master In Slave
end_comment

begin_define
define|#
directive|define
name|AT91C_PA0_MCDB0
value|(AT91C_PIO_PA0)
end_define

begin_comment
comment|//  Multimedia Card B Data 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PA1_SPI0_MOSI
value|(AT91C_PIO_PA1)
end_define

begin_comment
comment|//  SPI 0 Master Out Slave
end_comment

begin_define
define|#
directive|define
name|AT91C_PA1_MCCDB
value|(AT91C_PIO_PA1)
end_define

begin_comment
comment|//  Multimedia Card B Command
end_comment

begin_define
define|#
directive|define
name|AT91C_PA10_MCDA2
value|(AT91C_PIO_PA10)
end_define

begin_comment
comment|//  Multimedia Card A Data 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PA10_ETX2_0
value|(AT91C_PIO_PA10)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Data 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PA11_MCDA3
value|(AT91C_PIO_PA11)
end_define

begin_comment
comment|//  Multimedia Card A Data 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PA11_ETX3_0
value|(AT91C_PIO_PA11)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Data 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PA12_ETX0
value|(AT91C_PIO_PA12)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Data 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PA13_ETX1
value|(AT91C_PIO_PA13)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Data 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PA14_ERX0
value|(AT91C_PIO_PA14)
end_define

begin_comment
comment|//  Ethernet MAC Receive Data 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PA15_ERX1
value|(AT91C_PIO_PA15)
end_define

begin_comment
comment|//  Ethernet MAC Receive Data 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PA16_ETXEN
value|(AT91C_PIO_PA16)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_PA17_ERXDV
value|(AT91C_PIO_PA17)
end_define

begin_comment
comment|//  Ethernet MAC Receive Data Valid
end_comment

begin_define
define|#
directive|define
name|AT91C_PA18_ERXER
value|(AT91C_PIO_PA18)
end_define

begin_comment
comment|//  Ethernet MAC Receive Error
end_comment

begin_define
define|#
directive|define
name|AT91C_PA19_ETXCK
value|(AT91C_PIO_PA19)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Clock/Reference Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PA2_SPI0_SPCK
value|(AT91C_PIO_PA2)
end_define

begin_comment
comment|//  SPI 0 Serial Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PA20_EMDC
value|(AT91C_PIO_PA20)
end_define

begin_comment
comment|//  Ethernet MAC Management Data Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PA21_EMDIO
value|(AT91C_PIO_PA21)
end_define

begin_comment
comment|//  Ethernet MAC Management Data Input/Output
end_comment

begin_define
define|#
directive|define
name|AT91C_PA22_ADTRG
value|(AT91C_PIO_PA22)
end_define

begin_comment
comment|//  ADC Trigger
end_comment

begin_define
define|#
directive|define
name|AT91C_PA22_ETXER
value|(AT91C_PIO_PA22)
end_define

begin_comment
comment|//  Ethernet MAC Transmikt Coding Error
end_comment

begin_define
define|#
directive|define
name|AT91C_PA23_TWD
value|(AT91C_PIO_PA23)
end_define

begin_comment
comment|//  TWI Two-wire Serial Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PA23_ETX2_1
value|(AT91C_PIO_PA23)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Data 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PA24_TWCK
value|(AT91C_PIO_PA24)
end_define

begin_comment
comment|//  TWI Two-wire Serial Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PA24_ETX3_1
value|(AT91C_PIO_PA24)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Data 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PA25_TCLK0
value|(AT91C_PIO_PA25)
end_define

begin_comment
comment|//  Timer Counter 0 external clock input
end_comment

begin_define
define|#
directive|define
name|AT91C_PA25_ERX2
value|(AT91C_PIO_PA25)
end_define

begin_comment
comment|//  Ethernet MAC Receive Data 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PA26_TIOA0
value|(AT91C_PIO_PA26)
end_define

begin_comment
comment|//  Timer Counter 0 Multipurpose Timer I/O Pin A
end_comment

begin_define
define|#
directive|define
name|AT91C_PA26_ERX3
value|(AT91C_PIO_PA26)
end_define

begin_comment
comment|//  Ethernet MAC Receive Data 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PA27_TIOA1
value|(AT91C_PIO_PA27)
end_define

begin_comment
comment|//  Timer Counter 1 Multipurpose Timer I/O Pin A
end_comment

begin_define
define|#
directive|define
name|AT91C_PA27_ERXCK
value|(AT91C_PIO_PA27)
end_define

begin_comment
comment|//  Ethernet MAC Receive Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PA28_TIOA2
value|(AT91C_PIO_PA28)
end_define

begin_comment
comment|//  Timer Counter 2 Multipurpose Timer I/O Pin A
end_comment

begin_define
define|#
directive|define
name|AT91C_PA28_ECRS
value|(AT91C_PIO_PA28)
end_define

begin_comment
comment|//  Ethernet MAC Carrier Sense/Carrier Sense and Data Valid
end_comment

begin_define
define|#
directive|define
name|AT91C_PA29_SCK1
value|(AT91C_PIO_PA29)
end_define

begin_comment
comment|//  USART 1 Serial Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PA29_ECOL
value|(AT91C_PIO_PA29)
end_define

begin_comment
comment|//  Ethernet MAC Collision Detected
end_comment

begin_define
define|#
directive|define
name|AT91C_PA3_SPI0_NPCS0
value|(AT91C_PIO_PA3)
end_define

begin_comment
comment|//  SPI 0 Peripheral Chip Select 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PA3_MCDB3
value|(AT91C_PIO_PA3)
end_define

begin_comment
comment|//  Multimedia Card B Data 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PA30_SCK2
value|(AT91C_PIO_PA30)
end_define

begin_comment
comment|//  USART 2 Serial Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PA30_RXD4
value|(AT91C_PIO_PA30)
end_define

begin_comment
comment|//  USART 4 Receive Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PA31_SCK0
value|(AT91C_PIO_PA31)
end_define

begin_comment
comment|//  USART 0 Serial Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PA31_TXD4
value|(AT91C_PIO_PA31)
end_define

begin_comment
comment|//  USART 4 Transmit Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PA4_RTS2
value|(AT91C_PIO_PA4)
end_define

begin_comment
comment|//  USART 2 Ready To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PA4_MCDB2
value|(AT91C_PIO_PA4)
end_define

begin_comment
comment|//  Multimedia Card B Data 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PA5_CTS2
value|(AT91C_PIO_PA5)
end_define

begin_comment
comment|//  USART 2 Clear To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PA5_MCDB1
value|(AT91C_PIO_PA5)
end_define

begin_comment
comment|//  Multimedia Card B Data 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PA6_MCDA0
value|(AT91C_PIO_PA6)
end_define

begin_comment
comment|//  Multimedia Card A Data 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PA7_MCCDA
value|(AT91C_PIO_PA7)
end_define

begin_comment
comment|//  Multimedia Card A Command
end_comment

begin_define
define|#
directive|define
name|AT91C_PA8_MCCK
value|(AT91C_PIO_PA8)
end_define

begin_comment
comment|//  Multimedia Card Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PA9_MCDA1
value|(AT91C_PIO_PA9)
end_define

begin_comment
comment|//  Multimedia Card A Data 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PB0_SPI1_MISO
value|(AT91C_PIO_PB0)
end_define

begin_comment
comment|//  SPI 1 Master In Slave
end_comment

begin_define
define|#
directive|define
name|AT91C_PB0_TIOA3
value|(AT91C_PIO_PB0)
end_define

begin_comment
comment|//  Timer Counter 3 Multipurpose Timer I/O Pin A
end_comment

begin_define
define|#
directive|define
name|AT91C_PB1_SPI1_MOSI
value|(AT91C_PIO_PB1)
end_define

begin_comment
comment|//  SPI 1 Master Out Slave
end_comment

begin_define
define|#
directive|define
name|AT91C_PB1_TIOB3
value|(AT91C_PIO_PB1)
end_define

begin_comment
comment|//  Timer Counter 3 Multipurpose Timer I/O Pin B
end_comment

begin_define
define|#
directive|define
name|AT91C_PB10_TXD3
value|(AT91C_PIO_PB10)
end_define

begin_comment
comment|//  USART 3 Transmit Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PB10_ISI_D8
value|(AT91C_PIO_PB10)
end_define

begin_comment
comment|//  Image Sensor Data 8
end_comment

begin_define
define|#
directive|define
name|AT91C_PB11_RXD3
value|(AT91C_PIO_PB11)
end_define

begin_comment
comment|//  USART 3 Receive Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PB11_ISI_D9
value|(AT91C_PIO_PB11)
end_define

begin_comment
comment|//  Image Sensor Data 9
end_comment

begin_define
define|#
directive|define
name|AT91C_PB12_TXD5
value|(AT91C_PIO_PB12)
end_define

begin_comment
comment|//  USART 5 Transmit Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PB12_ISI_D10
value|(AT91C_PIO_PB12)
end_define

begin_comment
comment|//  Image Sensor Data 10
end_comment

begin_define
define|#
directive|define
name|AT91C_PB13_RXD5
value|(AT91C_PIO_PB13)
end_define

begin_comment
comment|//  USART 5 Receive Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PB13_ISI_D11
value|(AT91C_PIO_PB13)
end_define

begin_comment
comment|//  Image Sensor Data 11
end_comment

begin_define
define|#
directive|define
name|AT91C_PB14_DRXD
value|(AT91C_PIO_PB14)
end_define

begin_comment
comment|//  DBGU Debug Receive Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PB15_DTXD
value|(AT91C_PIO_PB15)
end_define

begin_comment
comment|//  DBGU Debug Transmit Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PB16_TK0
value|(AT91C_PIO_PB16)
end_define

begin_comment
comment|//  SSC0 Transmit Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PB16_TCLK3
value|(AT91C_PIO_PB16)
end_define

begin_comment
comment|//  Timer Counter 3 external clock input
end_comment

begin_define
define|#
directive|define
name|AT91C_PB17_TF0
value|(AT91C_PIO_PB17)
end_define

begin_comment
comment|//  SSC0 Transmit Frame Sync
end_comment

begin_define
define|#
directive|define
name|AT91C_PB17_TCLK4
value|(AT91C_PIO_PB17)
end_define

begin_comment
comment|//  Timer Counter 4 external clock input
end_comment

begin_define
define|#
directive|define
name|AT91C_PB18_TD0
value|(AT91C_PIO_PB18)
end_define

begin_comment
comment|//  SSC0 Transmit data
end_comment

begin_define
define|#
directive|define
name|AT91C_PB18_TIOB4
value|(AT91C_PIO_PB18)
end_define

begin_comment
comment|//  Timer Counter 4 Multipurpose Timer I/O Pin B
end_comment

begin_define
define|#
directive|define
name|AT91C_PB19_RD0
value|(AT91C_PIO_PB19)
end_define

begin_comment
comment|//  SSC0 Receive Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PB19_TIOB5
value|(AT91C_PIO_PB19)
end_define

begin_comment
comment|//  Timer Counter 5 Multipurpose Timer I/O Pin B
end_comment

begin_define
define|#
directive|define
name|AT91C_PB2_SPI1_SPCK
value|(AT91C_PIO_PB2)
end_define

begin_comment
comment|//  SPI 1 Serial Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PB2_TIOA4
value|(AT91C_PIO_PB2)
end_define

begin_comment
comment|//  Timer Counter 4 Multipurpose Timer I/O Pin A
end_comment

begin_define
define|#
directive|define
name|AT91C_PB20_RK0
value|(AT91C_PIO_PB20)
end_define

begin_comment
comment|//  SSC0 Receive Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PB20_ISI_D0
value|(AT91C_PIO_PB20)
end_define

begin_comment
comment|//  Image Sensor Data 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PB21_RF0
value|(AT91C_PIO_PB21)
end_define

begin_comment
comment|//  SSC0 Receive Frame Sync
end_comment

begin_define
define|#
directive|define
name|AT91C_PB21_ISI_D1
value|(AT91C_PIO_PB21)
end_define

begin_comment
comment|//  Image Sensor Data 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PB22_DSR0
value|(AT91C_PIO_PB22)
end_define

begin_comment
comment|//  USART 0 Data Set ready
end_comment

begin_define
define|#
directive|define
name|AT91C_PB22_ISI_D2
value|(AT91C_PIO_PB22)
end_define

begin_comment
comment|//  Image Sensor Data 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PB23_DCD0
value|(AT91C_PIO_PB23)
end_define

begin_comment
comment|//  USART 0 Data Carrier Detect
end_comment

begin_define
define|#
directive|define
name|AT91C_PB23_ISI_D3
value|(AT91C_PIO_PB23)
end_define

begin_comment
comment|//  Image Sensor Data 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PB24_DTR0
value|(AT91C_PIO_PB24)
end_define

begin_comment
comment|//  USART 0 Data Terminal ready
end_comment

begin_define
define|#
directive|define
name|AT91C_PB24_ISI_D4
value|(AT91C_PIO_PB24)
end_define

begin_comment
comment|//  Image Sensor Data 4
end_comment

begin_define
define|#
directive|define
name|AT91C_PB25_RI0
value|(AT91C_PIO_PB25)
end_define

begin_comment
comment|//  USART 0 Ring Indicator
end_comment

begin_define
define|#
directive|define
name|AT91C_PB25_ISI_D5
value|(AT91C_PIO_PB25)
end_define

begin_comment
comment|//  Image Sensor Data 5
end_comment

begin_define
define|#
directive|define
name|AT91C_PB26_RTS0
value|(AT91C_PIO_PB26)
end_define

begin_comment
comment|//  USART 0 Ready To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PB26_ISI_D6
value|(AT91C_PIO_PB26)
end_define

begin_comment
comment|//  Image Sensor Data 6
end_comment

begin_define
define|#
directive|define
name|AT91C_PB27_CTS0
value|(AT91C_PIO_PB27)
end_define

begin_comment
comment|//  USART 0 Clear To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PB27_ISI_D7
value|(AT91C_PIO_PB27)
end_define

begin_comment
comment|//  Image Sensor Data 7
end_comment

begin_define
define|#
directive|define
name|AT91C_PB28_RTS1
value|(AT91C_PIO_PB28)
end_define

begin_comment
comment|//  USART 1 Ready To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PB28_ISI_PCK
value|(AT91C_PIO_PB28)
end_define

begin_comment
comment|//  Image Sensor Data Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PB29_CTS1
value|(AT91C_PIO_PB29)
end_define

begin_comment
comment|//  USART 1 Clear To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PB29_ISI_VSYNC
value|(AT91C_PIO_PB29)
end_define

begin_comment
comment|//  Image Sensor Vertical Synchro
end_comment

begin_define
define|#
directive|define
name|AT91C_PB3_SPI1_NPCS0
value|(AT91C_PIO_PB3)
end_define

begin_comment
comment|//  SPI 1 Peripheral Chip Select 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PB3_TIOA5
value|(AT91C_PIO_PB3)
end_define

begin_comment
comment|//  Timer Counter 5 Multipurpose Timer I/O Pin A
end_comment

begin_define
define|#
directive|define
name|AT91C_PB30_PCK0_0
value|(AT91C_PIO_PB30)
end_define

begin_comment
comment|//  PMC Programmable Clock Output 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PB30_ISI_HSYNC
value|(AT91C_PIO_PB30)
end_define

begin_comment
comment|//  Image Sensor Horizontal Synchro
end_comment

begin_define
define|#
directive|define
name|AT91C_PB31_PCK1_0
value|(AT91C_PIO_PB31)
end_define

begin_comment
comment|//  PMC Programmable Clock Output 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PB31_ISI_MCK
value|(AT91C_PIO_PB31)
end_define

begin_comment
comment|//  Image Sensor Reference Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PB4_TXD0
value|(AT91C_PIO_PB4)
end_define

begin_comment
comment|//  USART 0 Transmit Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PB5_RXD0
value|(AT91C_PIO_PB5)
end_define

begin_comment
comment|//  USART 0 Receive Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PB6_TXD1
value|(AT91C_PIO_PB6)
end_define

begin_comment
comment|//  USART 1 Transmit Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PB6_TCLK1
value|(AT91C_PIO_PB6)
end_define

begin_comment
comment|//  Timer Counter 1 external clock input
end_comment

begin_define
define|#
directive|define
name|AT91C_PB7_RXD1
value|(AT91C_PIO_PB7)
end_define

begin_comment
comment|//  USART 1 Receive Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PB7_TCLK2
value|(AT91C_PIO_PB7)
end_define

begin_comment
comment|//  Timer Counter 2 external clock input
end_comment

begin_define
define|#
directive|define
name|AT91C_PB8_TXD2
value|(AT91C_PIO_PB8)
end_define

begin_comment
comment|//  USART 2 Transmit Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PB9_RXD2
value|(AT91C_PIO_PB9)
end_define

begin_comment
comment|//  USART 2 Receive Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PC0_AD0
value|(AT91C_PIO_PC0)
end_define

begin_comment
comment|//  ADC Analog Input 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PC0_SCK3
value|(AT91C_PIO_PC0)
end_define

begin_comment
comment|//  USART 3 Serial Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PC1_AD1
value|(AT91C_PIO_PC1)
end_define

begin_comment
comment|//  ADC Analog Input 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PC1_PCK0_1
value|(AT91C_PIO_PC1)
end_define

begin_comment
comment|//  PMC Programmable Clock Output 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PC10_A25_CFR
value|NW (AT91C_PIO_PC10)
end_define

begin_comment
comment|//  Address Bus[25]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC10_CTS3
value|(AT91C_PIO_PC10)
end_define

begin_comment
comment|//  USART 3 Clear To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PC11_NCS2
value|(AT91C_PIO_PC11)
end_define

begin_comment
comment|//  Chip Select Line 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PC11_SPI0_NPCS1
value|(AT91C_PIO_PC11)
end_define

begin_comment
comment|//  SPI 0 Peripheral Chip Select 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PC12_IRQ0
value|(AT91C_PIO_PC12)
end_define

begin_comment
comment|//  External Interrupt 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PC12_NCS7
value|(AT91C_PIO_PC12)
end_define

begin_comment
comment|//  Chip Select Line 7
end_comment

begin_define
define|#
directive|define
name|AT91C_PC13_FIQ
value|(AT91C_PIO_PC13)
end_define

begin_comment
comment|//  AIC Fast Interrupt Input
end_comment

begin_define
define|#
directive|define
name|AT91C_PC13_NCS6
value|(AT91C_PIO_PC13)
end_define

begin_comment
comment|//  Chip Select Line 6
end_comment

begin_define
define|#
directive|define
name|AT91C_PC14_NCS3_NANDCS
value|(AT91C_PIO_PC14)
end_define

begin_comment
comment|//  Chip Select Line 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PC14_IRQ2
value|(AT91C_PIO_PC14)
end_define

begin_comment
comment|//  External Interrupt 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PC15_NWAIT
value|(AT91C_PIO_PC15)
end_define

begin_comment
comment|//  External Wait Signal
end_comment

begin_define
define|#
directive|define
name|AT91C_PC15_IRQ1
value|(AT91C_PIO_PC15)
end_define

begin_comment
comment|//  External Interrupt 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PC16_D16
value|(AT91C_PIO_PC16)
end_define

begin_comment
comment|//  Data Bus[16]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC16_SPI0_NPCS2
value|(AT91C_PIO_PC16)
end_define

begin_comment
comment|//  SPI 0 Peripheral Chip Select 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PC17_D17
value|(AT91C_PIO_PC17)
end_define

begin_comment
comment|//  Data Bus[17]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC17_SPI0_NPCS3
value|(AT91C_PIO_PC17)
end_define

begin_comment
comment|//  SPI 0 Peripheral Chip Select 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PC18_D18
value|(AT91C_PIO_PC18)
end_define

begin_comment
comment|//  Data Bus[18]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC18_SPI1_NPCS1_1
value|(AT91C_PIO_PC18)
end_define

begin_comment
comment|//  SPI 1 Peripheral Chip Select 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PC19_D19
value|(AT91C_PIO_PC19)
end_define

begin_comment
comment|//  Data Bus[19]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC19_SPI1_NPCS2_1
value|(AT91C_PIO_PC19)
end_define

begin_comment
comment|//  SPI 1 Peripheral Chip Select 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PC2_AD2
value|(AT91C_PIO_PC2)
end_define

begin_comment
comment|//  ADC Analog Input 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PC2_PCK1_1
value|(AT91C_PIO_PC2)
end_define

begin_comment
comment|//  PMC Programmable Clock Output 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PC20_D20
value|(AT91C_PIO_PC20)
end_define

begin_comment
comment|//  Data Bus[20]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC20_SPI1_NPCS3_1
value|(AT91C_PIO_PC20)
end_define

begin_comment
comment|//  SPI 1 Peripheral Chip Select 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PC21_D21
value|(AT91C_PIO_PC21)
end_define

begin_comment
comment|//  Data Bus[21]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC21_EF100
value|(AT91C_PIO_PC21)
end_define

begin_comment
comment|//  Ethernet MAC Force 100 Mbits/sec
end_comment

begin_define
define|#
directive|define
name|AT91C_PC22_D22
value|(AT91C_PIO_PC22)
end_define

begin_comment
comment|//  Data Bus[22]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC22_TCLK5
value|(AT91C_PIO_PC22)
end_define

begin_comment
comment|//  Timer Counter 5 external clock input
end_comment

begin_define
define|#
directive|define
name|AT91C_PC23_D23
value|(AT91C_PIO_PC23)
end_define

begin_comment
comment|//  Data Bus[23]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC24_D24
value|(AT91C_PIO_PC24)
end_define

begin_comment
comment|//  Data Bus[24]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC25_D25
value|(AT91C_PIO_PC25)
end_define

begin_comment
comment|//  Data Bus[25]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC26_D26
value|(AT91C_PIO_PC26)
end_define

begin_comment
comment|//  Data Bus[26]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC27_D27
value|(AT91C_PIO_PC27)
end_define

begin_comment
comment|//  Data Bus[27]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC28_D28
value|(AT91C_PIO_PC28)
end_define

begin_comment
comment|//  Data Bus[28]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC29_D29
value|(AT91C_PIO_PC29)
end_define

begin_comment
comment|//  Data Bus[29]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC3_AD3
value|(AT91C_PIO_PC3)
end_define

begin_comment
comment|//  ADC Analog Input 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PC3_SPI1_NPCS3_0
value|(AT91C_PIO_PC3)
end_define

begin_comment
comment|//  SPI 1 Peripheral Chip Select 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PC30_D30
value|(AT91C_PIO_PC30)
end_define

begin_comment
comment|//  Data Bus[30]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC31_D31
value|(AT91C_PIO_PC31)
end_define

begin_comment
comment|//  Data Bus[31]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC4_A23
value|(AT91C_PIO_PC4)
end_define

begin_comment
comment|//  Address Bus[23]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC4_SPI1_NPCS2_0
value|(AT91C_PIO_PC4)
end_define

begin_comment
comment|//  SPI 1 Peripheral Chip Select 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PC5_A24
value|(AT91C_PIO_PC5)
end_define

begin_comment
comment|//  Address Bus[24]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC5_SPI1_NPCS1_0
value|(AT91C_PIO_PC5)
end_define

begin_comment
comment|//  SPI 1 Peripheral Chip Select 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PC6_TIOB2
value|(AT91C_PIO_PC6)
end_define

begin_comment
comment|//  Timer Counter 2 Multipurpose Timer I/O Pin B
end_comment

begin_define
define|#
directive|define
name|AT91C_PC6_CFCE1
value|(AT91C_PIO_PC6)
end_define

begin_comment
comment|//  Compact Flash Enable 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PC7_TIOB1
value|(AT91C_PIO_PC7)
end_define

begin_comment
comment|//  Timer Counter 1 Multipurpose Timer I/O Pin B
end_comment

begin_define
define|#
directive|define
name|AT91C_PC7_CFCE2
value|(AT91C_PIO_PC7)
end_define

begin_comment
comment|//  Compact Flash Enable 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PC8_NCS4_CFCS0
value|(AT91C_PIO_PC8)
end_define

begin_comment
comment|//  Chip Select Line 4
end_comment

begin_define
define|#
directive|define
name|AT91C_PC8_RTS3
value|(AT91C_PIO_PC8)
end_define

begin_comment
comment|//  USART 3 Ready To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PC9_NCS5_CFCS1
value|(AT91C_PIO_PC9)
end_define

begin_comment
comment|//  Chip Select Line 5
end_comment

begin_define
define|#
directive|define
name|AT91C_PC9_TIOB0
value|(AT91C_PIO_PC9)
end_define

begin_comment
comment|//  Timer Counter 0 Multipurpose Timer I/O Pin B
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARM_AT91_AT91_PIO_SAM9G20_H */
end_comment

end_unit

