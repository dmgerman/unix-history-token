begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARM_AT91_AT91_PIO_RM9200_H
end_ifndef

begin_define
define|#
directive|define
name|ARM_AT91_AT91_PIO_RM9200_H
end_define

begin_include
include|#
directive|include
file|<arm/at91/at91_pioreg.h>
end_include

begin_comment
comment|/*  * These defines come from an atmel file that says specifically that it  * has no copyright.  */
end_comment

begin_comment
comment|//*****************************************************************************
end_comment

begin_comment
comment|//               PIO DEFINITIONS FOR AT91RM9200
end_comment

begin_comment
comment|//*****************************************************************************
end_comment

begin_define
define|#
directive|define
name|AT91C_PA0_MISO
value|(AT91C_PIO_PA0)
end_define

begin_comment
comment|//  SPI Master In Slave
end_comment

begin_define
define|#
directive|define
name|AT91C_PA0_PCK3
value|(AT91C_PIO_PA0)
end_define

begin_comment
comment|//  PMC Programmable Clock Output 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PA1_MOSI
value|(AT91C_PIO_PA1)
end_define

begin_comment
comment|//  SPI Master Out Slave
end_comment

begin_define
define|#
directive|define
name|AT91C_PA1_PCK0
value|(AT91C_PIO_PA1)
end_define

begin_comment
comment|//  PMC Programmable Clock Output 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PA10_ETX1
value|(AT91C_PIO_PA10)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Data 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PA10_MCDB1
value|(AT91C_PIO_PA10)
end_define

begin_comment
comment|//  Multimedia Card B Data 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PA11_ECRS_ECRSDV
value|(AT91C_PIO_PA11)
end_define

begin_comment
comment|//  Ethernet MAC Carrier Sense/Carrier Sense and Data Valid
end_comment

begin_define
define|#
directive|define
name|AT91C_PA11_MCDB2
value|(AT91C_PIO_PA11)
end_define

begin_comment
comment|//  Multimedia Card B Data 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PA12_ERX0
value|(AT91C_PIO_PA12)
end_define

begin_comment
comment|//  Ethernet MAC Receive Data 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PA12_MCDB3
value|(AT91C_PIO_PA12)
end_define

begin_comment
comment|//  Multimedia Card B Data 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PA13_ERX1
value|(AT91C_PIO_PA13)
end_define

begin_comment
comment|//  Ethernet MAC Receive Data 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PA13_TCLK0
value|(AT91C_PIO_PA13)
end_define

begin_comment
comment|//  Timer Counter 0 external clock input
end_comment

begin_define
define|#
directive|define
name|AT91C_PA14_ERXER
value|(AT91C_PIO_PA14)
end_define

begin_comment
comment|//  Ethernet MAC Receive Error
end_comment

begin_define
define|#
directive|define
name|AT91C_PA14_TCLK1
value|(AT91C_PIO_PA14)
end_define

begin_comment
comment|//  Timer Counter 1 external clock input
end_comment

begin_define
define|#
directive|define
name|AT91C_PA15_EMDC
value|(AT91C_PIO_PA15)
end_define

begin_comment
comment|//  Ethernet MAC Management Data Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PA15_TCLK2
value|(AT91C_PIO_PA15)
end_define

begin_comment
comment|//  Timer Counter 2 external clock input
end_comment

begin_define
define|#
directive|define
name|AT91C_PA16_EMDIO
value|(AT91C_PIO_PA16)
end_define

begin_comment
comment|//  Ethernet MAC Management Data Input/Output
end_comment

begin_define
define|#
directive|define
name|AT91C_PA16_IRQ6
value|(AT91C_PIO_PA16)
end_define

begin_comment
comment|//  AIC Interrupt input 6
end_comment

begin_define
define|#
directive|define
name|AT91C_PA17_TXD0
value|(AT91C_PIO_PA17)
end_define

begin_comment
comment|//  USART 0 Transmit Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PA17_TIOA0
value|(AT91C_PIO_PA17)
end_define

begin_comment
comment|//  Timer Counter 0 Multipurpose Timer I/O Pin A
end_comment

begin_define
define|#
directive|define
name|AT91C_PA18_RXD0
value|(AT91C_PIO_PA18)
end_define

begin_comment
comment|//  USART 0 Receive Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PA18_TIOB0
value|(AT91C_PIO_PA18)
end_define

begin_comment
comment|//  Timer Counter 0 Multipurpose Timer I/O Pin B
end_comment

begin_define
define|#
directive|define
name|AT91C_PA19_SCK0
value|(AT91C_PIO_PA19)
end_define

begin_comment
comment|//  USART 0 Serial Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PA19_TIOA1
value|(AT91C_PIO_PA19)
end_define

begin_comment
comment|//  Timer Counter 1 Multipurpose Timer I/O Pin A
end_comment

begin_define
define|#
directive|define
name|AT91C_PA2_SPCK
value|(AT91C_PIO_PA2)
end_define

begin_comment
comment|//  SPI Serial Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PA2_IRQ4
value|(AT91C_PIO_PA2)
end_define

begin_comment
comment|//  AIC Interrupt Input 4
end_comment

begin_define
define|#
directive|define
name|AT91C_PA20_CTS0
value|(AT91C_PIO_PA20)
end_define

begin_comment
comment|//  USART 0 Clear To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PA20_TIOB1
value|(AT91C_PIO_PA20)
end_define

begin_comment
comment|//  Timer Counter 1 Multipurpose Timer I/O Pin B
end_comment

begin_define
define|#
directive|define
name|AT91C_PA21_RTS0
value|(AT91C_PIO_PA21)
end_define

begin_comment
comment|//  Usart 0 Ready To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PA21_TIOA2
value|(AT91C_PIO_PA21)
end_define

begin_comment
comment|//  Timer Counter 2 Multipurpose Timer I/O Pin A
end_comment

begin_define
define|#
directive|define
name|AT91C_PA22_RXD2
value|(AT91C_PIO_PA22)
end_define

begin_comment
comment|//  USART 2 Receive Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PA22_TIOB2
value|(AT91C_PIO_PA22)
end_define

begin_comment
comment|//  Timer Counter 2 Multipurpose Timer I/O Pin B
end_comment

begin_define
define|#
directive|define
name|AT91C_PA23_TXD2
value|(AT91C_PIO_PA23)
end_define

begin_comment
comment|//  USART 2 Transmit Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PA23_IRQ3
value|(AT91C_PIO_PA23)
end_define

begin_comment
comment|//  Interrupt input 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PA24_SCK2
value|(AT91C_PIO_PA24)
end_define

begin_comment
comment|//  USART2 Serial Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PA24_PCK1
value|(AT91C_PIO_PA24)
end_define

begin_comment
comment|//  PMC Programmable Clock Output 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PA25_TWD
value|(AT91C_PIO_PA25)
end_define

begin_comment
comment|//  TWI Two-wire Serial Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PA25_IRQ2
value|(AT91C_PIO_PA25)
end_define

begin_comment
comment|//  Interrupt input 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PA26_TWCK
value|(AT91C_PIO_PA26)
end_define

begin_comment
comment|//  TWI Two-wire Serial Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PA26_IRQ1
value|(AT91C_PIO_PA26)
end_define

begin_comment
comment|//  Interrupt input 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PA27_MCCK
value|(AT91C_PIO_PA27)
end_define

begin_comment
comment|//  Multimedia Card Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PA27_TCLK3
value|(AT91C_PIO_PA27)
end_define

begin_comment
comment|//  Timer Counter 3 External Clock Input
end_comment

begin_define
define|#
directive|define
name|AT91C_PA28_MCCDA
value|(AT91C_PIO_PA28)
end_define

begin_comment
comment|//  Multimedia Card A Command
end_comment

begin_define
define|#
directive|define
name|AT91C_PA28_TCLK4
value|(AT91C_PIO_PA28)
end_define

begin_comment
comment|//  Timer Counter 4 external Clock Input
end_comment

begin_define
define|#
directive|define
name|AT91C_PA29_MCDA0
value|(AT91C_PIO_PA29)
end_define

begin_comment
comment|//  Multimedia Card A Data 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PA29_TCLK5
value|(AT91C_PIO_PA29)
end_define

begin_comment
comment|//  Timer Counter 5 external clock input
end_comment

begin_define
define|#
directive|define
name|AT91C_PA3_NPCS0
value|(AT91C_PIO_PA3)
end_define

begin_comment
comment|//  SPI Peripheral Chip Select 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PA3_IRQ5
value|(AT91C_PIO_PA3)
end_define

begin_comment
comment|//  AIC Interrupt Input 5
end_comment

begin_define
define|#
directive|define
name|AT91C_PA30_DRXD
value|(AT91C_PIO_PA30)
end_define

begin_comment
comment|//  DBGU Debug Receive Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PA30_CTS2
value|(AT91C_PIO_PA30)
end_define

begin_comment
comment|//  Usart 2 Clear To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PA31_DTXD
value|(AT91C_PIO_PA31)
end_define

begin_comment
comment|//  DBGU Debug Transmit Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PA31_RTS2
value|(AT91C_PIO_PA31)
end_define

begin_comment
comment|//  USART 2 Ready To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PA4_NPCS1
value|(AT91C_PIO_PA4)
end_define

begin_comment
comment|//  SPI Peripheral Chip Select 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PA4_PCK1
value|(AT91C_PIO_PA4)
end_define

begin_comment
comment|//  PMC Programmable Clock Output 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PA5_NPCS2
value|(AT91C_PIO_PA5)
end_define

begin_comment
comment|//  SPI Peripheral Chip Select 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PA5_TXD3
value|(AT91C_PIO_PA5)
end_define

begin_comment
comment|//  USART 3 Transmit Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PA6_NPCS3
value|(AT91C_PIO_PA6)
end_define

begin_comment
comment|//  SPI Peripheral Chip Select 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PA6_RXD3
value|(AT91C_PIO_PA6)
end_define

begin_comment
comment|//  USART 3 Receive Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PA7_ETXCK_EREFCK
value|(AT91C_PIO_PA7)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Clock/Reference Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PA7_PCK2
value|(AT91C_PIO_PA7)
end_define

begin_comment
comment|//  PMC Programmable Clock 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PA8_ETXEN
value|(AT91C_PIO_PA8)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_PA8_MCCDB
value|(AT91C_PIO_PA8)
end_define

begin_comment
comment|//  Multimedia Card B Command
end_comment

begin_define
define|#
directive|define
name|AT91C_PA9_ETX0
value|(AT91C_PIO_PA9)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Data 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PA9_MCDB0
value|(AT91C_PIO_PA9)
end_define

begin_comment
comment|//  Multimedia Card B Data 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PB0_TF0
value|(AT91C_PIO_PB0)
end_define

begin_comment
comment|//  SSC Transmit Frame Sync 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PB0_TIOB3
value|(AT91C_PIO_PB0)
end_define

begin_comment
comment|//  Timer Counter 3 Multipurpose Timer I/O Pin B
end_comment

begin_define
define|#
directive|define
name|AT91C_PB1_TK0
value|(AT91C_PIO_PB1)
end_define

begin_comment
comment|//  SSC Transmit Clock 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PB1_CTS3
value|(AT91C_PIO_PB1)
end_define

begin_comment
comment|//  USART 3 Clear To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PB10_RK1
value|(AT91C_PIO_PB10)
end_define

begin_comment
comment|//  SSC Receive Clock 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PB10_TIOA5
value|(AT91C_PIO_PB10)
end_define

begin_comment
comment|//  Timer Counter 5 Multipurpose Timer I/O Pin A
end_comment

begin_define
define|#
directive|define
name|AT91C_PB11_RF1
value|(AT91C_PIO_PB11)
end_define

begin_comment
comment|//  SSC Receive Frame Sync 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PB11_TIOB5
value|(AT91C_PIO_PB11)
end_define

begin_comment
comment|//  Timer Counter 5 Multipurpose Timer I/O Pin B
end_comment

begin_define
define|#
directive|define
name|AT91C_PB12_TF2
value|(AT91C_PIO_PB12)
end_define

begin_comment
comment|//  SSC Transmit Frame Sync 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PB12_ETX2
value|(AT91C_PIO_PB12)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Data 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PB13_TK2
value|(AT91C_PIO_PB13)
end_define

begin_comment
comment|//  SSC Transmit Clock 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PB13_ETX3
value|(AT91C_PIO_PB13)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Data 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PB14_TD2
value|(AT91C_PIO_PB14)
end_define

begin_comment
comment|//  SSC Transmit Data 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PB14_ETXER
value|(AT91C_PIO_PB14)
end_define

begin_comment
comment|//  Ethernet MAC Transmikt Coding Error
end_comment

begin_define
define|#
directive|define
name|AT91C_PB15_RD2
value|(AT91C_PIO_PB15)
end_define

begin_comment
comment|//  SSC Receive Data 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PB15_ERX2
value|(AT91C_PIO_PB15)
end_define

begin_comment
comment|//  Ethernet MAC Receive Data 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PB16_RK2
value|(AT91C_PIO_PB16)
end_define

begin_comment
comment|//  SSC Receive Clock 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PB16_ERX3
value|(AT91C_PIO_PB16)
end_define

begin_comment
comment|//  Ethernet MAC Receive Data 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PB17_RF2
value|(AT91C_PIO_PB17)
end_define

begin_comment
comment|//  SSC Receive Frame Sync 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PB17_ERXDV
value|(AT91C_PIO_PB17)
end_define

begin_comment
comment|//  Ethernet MAC Receive Data Valid
end_comment

begin_define
define|#
directive|define
name|AT91C_PB18_RI1
value|(AT91C_PIO_PB18)
end_define

begin_comment
comment|//  USART 1 Ring Indicator
end_comment

begin_define
define|#
directive|define
name|AT91C_PB18_ECOL
value|(AT91C_PIO_PB18)
end_define

begin_comment
comment|//  Ethernet MAC Collision Detected
end_comment

begin_define
define|#
directive|define
name|AT91C_PB19_DTR1
value|(AT91C_PIO_PB19)
end_define

begin_comment
comment|//  USART 1 Data Terminal ready
end_comment

begin_define
define|#
directive|define
name|AT91C_PB19_ERXCK
value|(AT91C_PIO_PB19)
end_define

begin_comment
comment|//  Ethernet MAC Receive Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PB2_TD0
value|(AT91C_PIO_PB2)
end_define

begin_comment
comment|//  SSC Transmit data
end_comment

begin_define
define|#
directive|define
name|AT91C_PB2_SCK3
value|(AT91C_PIO_PB2)
end_define

begin_comment
comment|//  USART 3 Serial Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PB20_TXD1
value|(AT91C_PIO_PB20)
end_define

begin_comment
comment|//  USART 1 Transmit Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PB21_RXD1
value|(AT91C_PIO_PB21)
end_define

begin_comment
comment|//  USART 1 Receive Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PB22_SCK1
value|(AT91C_PIO_PB22)
end_define

begin_comment
comment|//  USART1 Serial Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PB23_DCD1
value|(AT91C_PIO_PB23)
end_define

begin_comment
comment|//  USART 1 Data Carrier Detect
end_comment

begin_define
define|#
directive|define
name|AT91C_PB24_CTS1
value|(AT91C_PIO_PB24)
end_define

begin_comment
comment|//  USART 1 Clear To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PB25_DSR1
value|(AT91C_PIO_PB25)
end_define

begin_comment
comment|//  USART 1 Data Set ready
end_comment

begin_define
define|#
directive|define
name|AT91C_PB25_EF100
value|(AT91C_PIO_PB25)
end_define

begin_comment
comment|//  Ethernet MAC Force 100 Mbits/sec
end_comment

begin_define
define|#
directive|define
name|AT91C_PB26_RTS1
value|(AT91C_PIO_PB26)
end_define

begin_comment
comment|//  Usart 0 Ready To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PB27_PCK0
value|(AT91C_PIO_PB27)
end_define

begin_comment
comment|//  PMC Programmable Clock Output 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PB28_FIQ
value|(AT91C_PIO_PB28)
end_define

begin_comment
comment|//  AIC Fast Interrupt Input
end_comment

begin_define
define|#
directive|define
name|AT91C_PB29_IRQ0
value|(AT91C_PIO_PB29)
end_define

begin_comment
comment|//  Interrupt input 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PB3_RD0
value|(AT91C_PIO_PB3)
end_define

begin_comment
comment|//  SSC Receive Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PB3_MCDA1
value|(AT91C_PIO_PB3)
end_define

begin_comment
comment|//  Multimedia Card A Data 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PB4_RK0
value|(AT91C_PIO_PB4)
end_define

begin_comment
comment|//  SSC Receive Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PB4_MCDA2
value|(AT91C_PIO_PB4)
end_define

begin_comment
comment|//  Multimedia Card A Data 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PB5_RF0
value|(AT91C_PIO_PB5)
end_define

begin_comment
comment|//  SSC Receive Frame Sync 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PB5_MCDA3
value|(AT91C_PIO_PB5)
end_define

begin_comment
comment|//  Multimedia Card A Data 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PB6_TF1
value|(AT91C_PIO_PB6)
end_define

begin_comment
comment|//  SSC Transmit Frame Sync 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PB6_TIOA3
value|(AT91C_PIO_PB6)
end_define

begin_comment
comment|//  Timer Counter 4 Multipurpose Timer I/O Pin A
end_comment

begin_define
define|#
directive|define
name|AT91C_PB7_TK1
value|(AT91C_PIO_PB7)
end_define

begin_comment
comment|//  SSC Transmit Clock 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PB7_TIOB3
value|(AT91C_PIO_PB7)
end_define

begin_comment
comment|//  Timer Counter 3 Multipurpose Timer I/O Pin B
end_comment

begin_define
define|#
directive|define
name|AT91C_PB8_TD1
value|(AT91C_PIO_PB8)
end_define

begin_comment
comment|//  SSC Transmit Data 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PB8_TIOA4
value|(AT91C_PIO_PB8)
end_define

begin_comment
comment|//  Timer Counter 4 Multipurpose Timer I/O Pin A
end_comment

begin_define
define|#
directive|define
name|AT91C_PB9_RD1
value|(AT91C_PIO_PB9)
end_define

begin_comment
comment|//  SSC Receive Data 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PB9_TIOB4
value|(AT91C_PIO_PB9)
end_define

begin_comment
comment|//  Timer Counter 4 Multipurpose Timer I/O Pin B
end_comment

begin_define
define|#
directive|define
name|AT91C_PC0_BFCK
value|(AT91C_PIO_PC0)
end_define

begin_comment
comment|//  Burst Flash Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PC1_BFRDY_SMOE
value|(AT91C_PIO_PC1)
end_define

begin_comment
comment|//  Burst Flash Ready
end_comment

begin_define
define|#
directive|define
name|AT91C_PC10_NCS4_CFCS
value|(AT91C_PIO_PC10)
end_define

begin_comment
comment|//  Compact Flash Chip Select
end_comment

begin_define
define|#
directive|define
name|AT91C_PC11_NCS5_CFCE1
value|(AT91C_PIO_PC11)
end_define

begin_comment
comment|//  Chip Select 5 / Compact Flash Chip Enable 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PC12_NCS6_CFCE2
value|(AT91C_PIO_PC12)
end_define

begin_comment
comment|//  Chip Select 6 / Compact Flash Chip Enable 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PC13_NCS7
value|(AT91C_PIO_PC13)
end_define

begin_comment
comment|//  Chip Select 7
end_comment

begin_define
define|#
directive|define
name|AT91C_PC16_D16
value|(AT91C_PIO_PC16)
end_define

begin_comment
comment|//  Data Bus [16]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC17_D17
value|(AT91C_PIO_PC17)
end_define

begin_comment
comment|//  Data Bus [17]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC18_D18
value|(AT91C_PIO_PC18)
end_define

begin_comment
comment|//  Data Bus [18]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC19_D19
value|(AT91C_PIO_PC19)
end_define

begin_comment
comment|//  Data Bus [19]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC2_BFAVD
value|(AT91C_PIO_PC2)u
end_define

begin_comment
comment|//  Burst Flash Address Valid
end_comment

begin_define
define|#
directive|define
name|AT91C_PC20_D20
value|(AT91C_PIO_PC20)
end_define

begin_comment
comment|//  Data Bus [20]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC21_D21
value|(AT91C_PIO_PC21)
end_define

begin_comment
comment|//  Data Bus [21]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC22_D22
value|(AT91C_PIO_PC22)
end_define

begin_comment
comment|//  Data Bus [22]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC23_D23
value|(AT91C_PIO_PC23)
end_define

begin_comment
comment|//  Data Bus [23]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC24_D24
value|(AT91C_PIO_PC24)
end_define

begin_comment
comment|//  Data Bus [24]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC25_D25
value|(AT91C_PIO_PC25)
end_define

begin_comment
comment|//  Data Bus [25]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC26_D26
value|(AT91C_PIO_PC26)
end_define

begin_comment
comment|//  Data Bus [26]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC27_D27
value|(AT91C_PIO_PC27)
end_define

begin_comment
comment|//  Data Bus [27]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC28_D28
value|(AT91C_PIO_PC28)
end_define

begin_comment
comment|//  Data Bus [28]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC29_D29
value|(AT91C_PIO_PC29)
end_define

begin_comment
comment|//  Data Bus [29]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC3_BFBAA_SMWE
value|(AT91C_PIO_PC3)
end_define

begin_comment
comment|//  Burst Flash Address Advance / SmartMedia Write Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_PC30_D30
value|(AT91C_PIO_PC30)
end_define

begin_comment
comment|//  Data Bus [30]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC31_D31
value|(AT91C_PIO_PC31)
end_define

begin_comment
comment|//  Data Bus [31]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC4_BFOE
value|(AT91C_PIO_PC4)
end_define

begin_comment
comment|//  Burst Flash Output Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_PC5_BFWE
value|(AT91C_PIO_PC5)
end_define

begin_comment
comment|//  Burst Flash Write Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_PC6_NWAIT
value|(AT91C_PIO_PC6)
end_define

begin_comment
comment|//  NWAIT
end_comment

begin_define
define|#
directive|define
name|AT91C_PC7_A23
value|(AT91C_PIO_PC7)
end_define

begin_comment
comment|//  Address Bus[23]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC8_A24
value|(AT91C_PIO_PC8)
end_define

begin_comment
comment|//  Address Bus[24]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC9_A25_CFRNW
value|(AT91C_PIO_PC9)
end_define

begin_comment
comment|//  Address Bus[25] /  Compact Flash Read Not Write
end_comment

begin_define
define|#
directive|define
name|AT91C_PD0_ETX0
value|(AT91C_PIO_PD0)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Data 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PD1_ETX1
value|(AT91C_PIO_PD1)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Data 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PD10_PCK3
value|(AT91C_PIO_PD10)
end_define

begin_comment
comment|//  PMC Programmable Clock Output 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PD10_TPS1
value|(AT91C_PIO_PD10)
end_define

begin_comment
comment|//  ETM ARM9 pipeline status 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PD11_
value|(AT91C_PIO_PD11)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD11_TPS2
value|(AT91C_PIO_PD11)
end_define

begin_comment
comment|//  ETM ARM9 pipeline status 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PD12_
value|(AT91C_PIO_PD12)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD12_TPK0
value|(AT91C_PIO_PD12)
end_define

begin_comment
comment|//  ETM Trace Packet 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PD13_
value|(AT91C_PIO_PD13)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD13_TPK1
value|(AT91C_PIO_PD13)
end_define

begin_comment
comment|//  ETM Trace Packet 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PD14_
value|(AT91C_PIO_PD14)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD14_TPK2
value|(AT91C_PIO_PD14)
end_define

begin_comment
comment|//  ETM Trace Packet 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PD15_TD0
value|(AT91C_PIO_PD15)
end_define

begin_comment
comment|//  SSC Transmit data
end_comment

begin_define
define|#
directive|define
name|AT91C_PD15_TPK3
value|(AT91C_PIO_PD15)
end_define

begin_comment
comment|//  ETM Trace Packet 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PD16_TD1
value|(AT91C_PIO_PD16)
end_define

begin_comment
comment|//  SSC Transmit Data 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PD16_TPK4
value|(AT91C_PIO_PD16)
end_define

begin_comment
comment|//  ETM Trace Packet 4
end_comment

begin_define
define|#
directive|define
name|AT91C_PD17_TD2
value|(AT91C_PIO_PD17)
end_define

begin_comment
comment|//  SSC Transmit Data 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PD17_TPK5
value|(AT91C_PIO_PD17)
end_define

begin_comment
comment|//  ETM Trace Packet 5
end_comment

begin_define
define|#
directive|define
name|AT91C_PD18_NPCS1
value|(AT91C_PIO_PD18)
end_define

begin_comment
comment|//  SPI Peripheral Chip Select 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PD18_TPK6
value|(AT91C_PIO_PD18)
end_define

begin_comment
comment|//  ETM Trace Packet 6
end_comment

begin_define
define|#
directive|define
name|AT91C_PD19_NPCS2
value|(AT91C_PIO_PD19)
end_define

begin_comment
comment|//  SPI Peripheral Chip Select 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PD19_TPK7
value|(AT91C_PIO_PD19)
end_define

begin_comment
comment|//  ETM Trace Packet 7
end_comment

begin_define
define|#
directive|define
name|AT91C_PD2_ETX2
value|(AT91C_PIO_PD2)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Data 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PD20_NPCS3
value|(AT91C_PIO_PD20)
end_define

begin_comment
comment|//  SPI Peripheral Chip Select 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PD20_TPK8
value|(AT91C_PIO_PD20)
end_define

begin_comment
comment|//  ETM Trace Packet 8
end_comment

begin_define
define|#
directive|define
name|AT91C_PD21_RTS0
value|(AT91C_PIO_PD21)
end_define

begin_comment
comment|//  Usart 0 Ready To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PD21_TPK9
value|(AT91C_PIO_PD21)
end_define

begin_comment
comment|//  ETM Trace Packet 9
end_comment

begin_define
define|#
directive|define
name|AT91C_PD22_RTS1
value|(AT91C_PIO_PD22)
end_define

begin_comment
comment|//  Usart 0 Ready To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PD22_TPK10
value|(AT91C_PIO_PD22)
end_define

begin_comment
comment|//  ETM Trace Packet 10
end_comment

begin_define
define|#
directive|define
name|AT91C_PD23_RTS2
value|(AT91C_PIO_PD23)
end_define

begin_comment
comment|//  USART 2 Ready To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PD23_TPK11
value|(AT91C_PIO_PD23)
end_define

begin_comment
comment|//  ETM Trace Packet 11
end_comment

begin_define
define|#
directive|define
name|AT91C_PD24_RTS3
value|(AT91C_PIO_PD24)
end_define

begin_comment
comment|//  USART 3 Ready To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PD24_TPK12
value|(AT91C_PIO_PD24)
end_define

begin_comment
comment|//  ETM Trace Packet 12
end_comment

begin_define
define|#
directive|define
name|AT91C_PD25_DTR1
value|(AT91C_PIO_PD25)
end_define

begin_comment
comment|//  USART 1 Data Terminal ready
end_comment

begin_define
define|#
directive|define
name|AT91C_PD25_TPK13
value|(AT91C_PIO_PD25)
end_define

begin_comment
comment|//  ETM Trace Packet 13
end_comment

begin_define
define|#
directive|define
name|AT91C_PD26_TPK14
value|(AT91C_PIO_PD26)
end_define

begin_comment
comment|//  ETM Trace Packet 14
end_comment

begin_define
define|#
directive|define
name|AT91C_PD27_TPK15
value|(AT91C_PIO_PD27)
end_define

begin_comment
comment|//  ETM Trace Packet 15
end_comment

begin_define
define|#
directive|define
name|AT91C_PD3_ETX3
value|(AT91C_PIO_PD3)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Data 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PD4_ETXEN
value|(AT91C_PIO_PD4)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_PD5_ETXER
value|(AT91C_PIO_PD5)
end_define

begin_comment
comment|//  Ethernet MAC Transmikt Coding Error
end_comment

begin_define
define|#
directive|define
name|AT91C_PD6_DTXD
value|(AT91C_PIO_PD6)
end_define

begin_comment
comment|//  DBGU Debug Transmit Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PD7_PCK0
value|(AT91C_PIO_PD7)
end_define

begin_comment
comment|//  PMC Programmable Clock Output 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PD7_TSYNC
value|(AT91C_PIO_PD7)
end_define

begin_comment
comment|//  ETM Synchronization signal
end_comment

begin_define
define|#
directive|define
name|AT91C_PD8_PCK1
value|(AT91C_PIO_PD8)
end_define

begin_comment
comment|//  PMC Programmable Clock Output 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PD8_TCLK
value|(AT91C_PIO_PD8)
end_define

begin_comment
comment|//  ETM Trace Clock signal
end_comment

begin_define
define|#
directive|define
name|AT91C_PD9_PCK2
value|(AT91C_PIO_PD9)
end_define

begin_comment
comment|//  PMC Programmable Clock 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PD9_TPS0
value|(AT91C_PIO_PD9)
end_define

begin_comment
comment|//  ETM ARM9 pipeline status 0
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARM_AT91_AT91_PIO_RM9200_H */
end_comment

end_unit

