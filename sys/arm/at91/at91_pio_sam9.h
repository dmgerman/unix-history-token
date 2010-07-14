begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Theses defines come from an atmel file that says specifically that it  * has no copyright.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_comment
comment|//               PIO DEFINITIONS FOR AT91SAM9261
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA0
value|((unsigned int) 1<<  0)
end_define

begin_comment
comment|// Pin Controlled by PA0
end_comment

begin_define
define|#
directive|define
name|AT91C_PA0_MISO0
value|((unsigned int) AT91C_PIO_PA0)
end_define

begin_comment
comment|//  SPI0 Master In Slave
end_comment

begin_define
define|#
directive|define
name|AT91C_PA0_MCDA0
value|((unsigned int) AT91C_PIO_PA0)
end_define

begin_comment
comment|//  Multimedia Card A Data 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA1
value|((unsigned int) 1<<  1)
end_define

begin_comment
comment|// Pin Controlled by PA1
end_comment

begin_define
define|#
directive|define
name|AT91C_PA1_MOSI0
value|((unsigned int) AT91C_PIO_PA1)
end_define

begin_comment
comment|//  SPI0 Master Out Slave
end_comment

begin_define
define|#
directive|define
name|AT91C_PA1_MCCDA
value|((unsigned int) AT91C_PIO_PA1)
end_define

begin_comment
comment|//  Multimedia Card A Command
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA10
value|((unsigned int) 1<< 10)
end_define

begin_comment
comment|// Pin Controlled by PA10
end_comment

begin_define
define|#
directive|define
name|AT91C_PA10_DTXD
value|((unsigned int) AT91C_PIO_PA10)
end_define

begin_comment
comment|//  DBGU Debug Transmit Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PA10_PCK3
value|((unsigned int) AT91C_PIO_PA10)
end_define

begin_comment
comment|//  PMC Programmable clock Output 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA11
value|((unsigned int) 1<< 11)
end_define

begin_comment
comment|// Pin Controlled by PA11
end_comment

begin_define
define|#
directive|define
name|AT91C_PA11_TSYNC
value|((unsigned int) AT91C_PIO_PA11)
end_define

begin_comment
comment|//  Trace Synchronization Signal
end_comment

begin_define
define|#
directive|define
name|AT91C_PA11_SCK1
value|((unsigned int) AT91C_PIO_PA11)
end_define

begin_comment
comment|//  USART1 Serial Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA12
value|((unsigned int) 1<< 12)
end_define

begin_comment
comment|// Pin Controlled by PA12
end_comment

begin_define
define|#
directive|define
name|AT91C_PA12_TCLK
value|((unsigned int) AT91C_PIO_PA12)
end_define

begin_comment
comment|//  Trace Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PA12_RTS1
value|((unsigned int) AT91C_PIO_PA12)
end_define

begin_comment
comment|//  USART1 Ready To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA13
value|((unsigned int) 1<< 13)
end_define

begin_comment
comment|// Pin Controlled by PA13
end_comment

begin_define
define|#
directive|define
name|AT91C_PA13_TPS0
value|((unsigned int) AT91C_PIO_PA13)
end_define

begin_comment
comment|//  Trace ARM Pipeline Status 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PA13_CTS1
value|((unsigned int) AT91C_PIO_PA13)
end_define

begin_comment
comment|//  USART1 Clear To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA14
value|((unsigned int) 1<< 14)
end_define

begin_comment
comment|// Pin Controlled by PA14
end_comment

begin_define
define|#
directive|define
name|AT91C_PA14_TPS1
value|((unsigned int) AT91C_PIO_PA14)
end_define

begin_comment
comment|//  Trace ARM Pipeline Status 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PA14_SCK2
value|((unsigned int) AT91C_PIO_PA14)
end_define

begin_comment
comment|//  USART2 Serial Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA15
value|((unsigned int) 1<< 15)
end_define

begin_comment
comment|// Pin Controlled by PA15
end_comment

begin_define
define|#
directive|define
name|AT91C_PA15_TPS2
value|((unsigned int) AT91C_PIO_PA15)
end_define

begin_comment
comment|//  Trace ARM Pipeline Status 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PA15_RTS2
value|((unsigned int) AT91C_PIO_PA15)
end_define

begin_comment
comment|//  USART2 Ready To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA16
value|((unsigned int) 1<< 16)
end_define

begin_comment
comment|// Pin Controlled by PA16
end_comment

begin_define
define|#
directive|define
name|AT91C_PA16_TPK0
value|((unsigned int) AT91C_PIO_PA16)
end_define

begin_comment
comment|//  Trace Packet Port 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PA16_CTS2
value|((unsigned int) AT91C_PIO_PA16)
end_define

begin_comment
comment|//  USART2 Clear To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA17
value|((unsigned int) 1<< 17)
end_define

begin_comment
comment|// Pin Controlled by PA17
end_comment

begin_define
define|#
directive|define
name|AT91C_PA17_TPK1
value|((unsigned int) AT91C_PIO_PA17)
end_define

begin_comment
comment|//  Trace Packet Port 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PA17_TF1
value|((unsigned int) AT91C_PIO_PA17)
end_define

begin_comment
comment|//  SSC1 Transmit Frame Sync
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA18
value|((unsigned int) 1<< 18)
end_define

begin_comment
comment|// Pin Controlled by PA18
end_comment

begin_define
define|#
directive|define
name|AT91C_PA18_TPK2
value|((unsigned int) AT91C_PIO_PA18)
end_define

begin_comment
comment|//  Trace Packet Port 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PA18_TK1
value|((unsigned int) AT91C_PIO_PA18)
end_define

begin_comment
comment|//  SSC1 Transmit Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA19
value|((unsigned int) 1<< 19)
end_define

begin_comment
comment|// Pin Controlled by PA19
end_comment

begin_define
define|#
directive|define
name|AT91C_PA19_TPK3
value|((unsigned int) AT91C_PIO_PA19)
end_define

begin_comment
comment|//  Trace Packet Port 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PA19_TD1
value|((unsigned int) AT91C_PIO_PA19)
end_define

begin_comment
comment|//  SSC1 Transmit Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA2
value|((unsigned int) 1<<  2)
end_define

begin_comment
comment|// Pin Controlled by PA2
end_comment

begin_define
define|#
directive|define
name|AT91C_PA2_SPCK0
value|((unsigned int) AT91C_PIO_PA2)
end_define

begin_comment
comment|//  SPI0 Serial Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PA2_MCCK
value|((unsigned int) AT91C_PIO_PA2)
end_define

begin_comment
comment|//  Multimedia Card Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA20
value|((unsigned int) 1<< 20)
end_define

begin_comment
comment|// Pin Controlled by PA20
end_comment

begin_define
define|#
directive|define
name|AT91C_PA20_TPK4
value|((unsigned int) AT91C_PIO_PA20)
end_define

begin_comment
comment|//  Trace Packet Port 4
end_comment

begin_define
define|#
directive|define
name|AT91C_PA20_RD1
value|((unsigned int) AT91C_PIO_PA20)
end_define

begin_comment
comment|//  SSC1 Receive Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA21
value|((unsigned int) 1<< 21)
end_define

begin_comment
comment|// Pin Controlled by PA21
end_comment

begin_define
define|#
directive|define
name|AT91C_PA21_TPK5
value|((unsigned int) AT91C_PIO_PA21)
end_define

begin_comment
comment|//  Trace Packet Port 5
end_comment

begin_define
define|#
directive|define
name|AT91C_PA21_RK1
value|((unsigned int) AT91C_PIO_PA21)
end_define

begin_comment
comment|//  SSC1 Receive Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA22
value|((unsigned int) 1<< 22)
end_define

begin_comment
comment|// Pin Controlled by PA22
end_comment

begin_define
define|#
directive|define
name|AT91C_PA22_TPK6
value|((unsigned int) AT91C_PIO_PA22)
end_define

begin_comment
comment|//  Trace Packet Port 6
end_comment

begin_define
define|#
directive|define
name|AT91C_PA22_RF1
value|((unsigned int) AT91C_PIO_PA22)
end_define

begin_comment
comment|//  SSC1 Receive Frame Sync
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA23
value|((unsigned int) 1<< 23)
end_define

begin_comment
comment|// Pin Controlled by PA23
end_comment

begin_define
define|#
directive|define
name|AT91C_PA23_TPK7
value|((unsigned int) AT91C_PIO_PA23)
end_define

begin_comment
comment|//  Trace Packet Port 7
end_comment

begin_define
define|#
directive|define
name|AT91C_PA23_RTS0
value|((unsigned int) AT91C_PIO_PA23)
end_define

begin_comment
comment|//  USART0 Ready To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA24
value|((unsigned int) 1<< 24)
end_define

begin_comment
comment|// Pin Controlled by PA24
end_comment

begin_define
define|#
directive|define
name|AT91C_PA24_TPK8
value|((unsigned int) AT91C_PIO_PA24)
end_define

begin_comment
comment|//  Trace Packet Port 8
end_comment

begin_define
define|#
directive|define
name|AT91C_PA24_NPCS11
value|((unsigned int) AT91C_PIO_PA24)
end_define

begin_comment
comment|//  SPI1 Peripheral Chip Select 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA25
value|((unsigned int) 1<< 25)
end_define

begin_comment
comment|// Pin Controlled by PA25
end_comment

begin_define
define|#
directive|define
name|AT91C_PA25_TPK9
value|((unsigned int) AT91C_PIO_PA25)
end_define

begin_comment
comment|//  Trace Packet Port 9
end_comment

begin_define
define|#
directive|define
name|AT91C_PA25_NPCS12
value|((unsigned int) AT91C_PIO_PA25)
end_define

begin_comment
comment|//  SPI1 Peripheral Chip Select 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA26
value|((unsigned int) 1<< 26)
end_define

begin_comment
comment|// Pin Controlled by PA26
end_comment

begin_define
define|#
directive|define
name|AT91C_PA26_TPK10
value|((unsigned int) AT91C_PIO_PA26)
end_define

begin_comment
comment|//  Trace Packet Port 10
end_comment

begin_define
define|#
directive|define
name|AT91C_PA26_NPCS13
value|((unsigned int) AT91C_PIO_PA26)
end_define

begin_comment
comment|//  SPI1 Peripheral Chip Select 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA27
value|((unsigned int) 1<< 27)
end_define

begin_comment
comment|// Pin Controlled by PA27
end_comment

begin_define
define|#
directive|define
name|AT91C_PA27_TPK11
value|((unsigned int) AT91C_PIO_PA27)
end_define

begin_comment
comment|//  Trace Packet Port 11
end_comment

begin_define
define|#
directive|define
name|AT91C_PA27_NPCS01
value|((unsigned int) AT91C_PIO_PA27)
end_define

begin_comment
comment|//  SPI0 Peripheral Chip Select 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA28
value|((unsigned int) 1<< 28)
end_define

begin_comment
comment|// Pin Controlled by PA28
end_comment

begin_define
define|#
directive|define
name|AT91C_PA28_TPK12
value|((unsigned int) AT91C_PIO_PA28)
end_define

begin_comment
comment|//  Trace Packet Port 12
end_comment

begin_define
define|#
directive|define
name|AT91C_PA28_NPCS02
value|((unsigned int) AT91C_PIO_PA28)
end_define

begin_comment
comment|//  SPI0 Peripheral Chip Select 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA29
value|((unsigned int) 1<< 29)
end_define

begin_comment
comment|// Pin Controlled by PA29
end_comment

begin_define
define|#
directive|define
name|AT91C_PA29_TPK13
value|((unsigned int) AT91C_PIO_PA29)
end_define

begin_comment
comment|//  Trace Packet Port 13
end_comment

begin_define
define|#
directive|define
name|AT91C_PA29_NPCS03
value|((unsigned int) AT91C_PIO_PA29)
end_define

begin_comment
comment|//  SPI0 Peripheral Chip Select 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA3
value|((unsigned int) 1<<  3)
end_define

begin_comment
comment|// Pin Controlled by PA3
end_comment

begin_define
define|#
directive|define
name|AT91C_PA3_NPCS00
value|((unsigned int) AT91C_PIO_PA3)
end_define

begin_comment
comment|//  SPI0 Peripheral Chip Select 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA30
value|((unsigned int) 1<< 30)
end_define

begin_comment
comment|// Pin Controlled by PA30
end_comment

begin_define
define|#
directive|define
name|AT91C_PA30_TPK14
value|((unsigned int) AT91C_PIO_PA30)
end_define

begin_comment
comment|//  Trace Packet Port 14
end_comment

begin_define
define|#
directive|define
name|AT91C_PA30_A23
value|((unsigned int) AT91C_PIO_PA30)
end_define

begin_comment
comment|//  Address Bus bit 23
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA31
value|((unsigned int) 1<< 31)
end_define

begin_comment
comment|// Pin Controlled by PA31
end_comment

begin_define
define|#
directive|define
name|AT91C_PA31_TPK15
value|((unsigned int) AT91C_PIO_PA31)
end_define

begin_comment
comment|//  Trace Packet Port 15
end_comment

begin_define
define|#
directive|define
name|AT91C_PA31_A24
value|((unsigned int) AT91C_PIO_PA31)
end_define

begin_comment
comment|//  Address Bus bit 24
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA4
value|((unsigned int) 1<<  4)
end_define

begin_comment
comment|// Pin Controlled by PA4
end_comment

begin_define
define|#
directive|define
name|AT91C_PA4_NPCS01
value|((unsigned int) AT91C_PIO_PA4)
end_define

begin_comment
comment|//  SPI0 Peripheral Chip Select 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PA4_MCDA1
value|((unsigned int) AT91C_PIO_PA4)
end_define

begin_comment
comment|//  Multimedia Card A Data 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA5
value|((unsigned int) 1<<  5)
end_define

begin_comment
comment|// Pin Controlled by PA5
end_comment

begin_define
define|#
directive|define
name|AT91C_PA5_NPCS02
value|((unsigned int) AT91C_PIO_PA5)
end_define

begin_comment
comment|//  SPI0 Peripheral Chip Select 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PA5_MCDA2
value|((unsigned int) AT91C_PIO_PA5)
end_define

begin_comment
comment|//  Multimedia Card A Data 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA6
value|((unsigned int) 1<<  6)
end_define

begin_comment
comment|// Pin Controlled by PA6
end_comment

begin_define
define|#
directive|define
name|AT91C_PA6_NPCS03
value|((unsigned int) AT91C_PIO_PA6)
end_define

begin_comment
comment|//  SPI0 Peripheral Chip Select 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PA6_MCDA3
value|((unsigned int) AT91C_PIO_PA6)
end_define

begin_comment
comment|//  Multimedia Card A Data 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA7
value|((unsigned int) 1<<  7)
end_define

begin_comment
comment|// Pin Controlled by PA7
end_comment

begin_define
define|#
directive|define
name|AT91C_PA7_TWD
value|((unsigned int) AT91C_PIO_PA7)
end_define

begin_comment
comment|//  TWI Two-wire Serial Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PA7_PCK0
value|((unsigned int) AT91C_PIO_PA7)
end_define

begin_comment
comment|//  PMC Programmable clock Output 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA8
value|((unsigned int) 1<<  8)
end_define

begin_comment
comment|// Pin Controlled by PA8
end_comment

begin_define
define|#
directive|define
name|AT91C_PA8_TWCK
value|((unsigned int) AT91C_PIO_PA8)
end_define

begin_comment
comment|//  TWI Two-wire Serial Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PA8_PCK1
value|((unsigned int) AT91C_PIO_PA8)
end_define

begin_comment
comment|//  PMC Programmable clock Output 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PA9
value|((unsigned int) 1<<  9)
end_define

begin_comment
comment|// Pin Controlled by PA9
end_comment

begin_define
define|#
directive|define
name|AT91C_PA9_DRXD
value|((unsigned int) AT91C_PIO_PA9)
end_define

begin_comment
comment|//  DBGU Debug Receive Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PA9_PCK2
value|((unsigned int) AT91C_PIO_PA9)
end_define

begin_comment
comment|//  PMC Programmable clock Output 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB0
value|((unsigned int) 1<<  0)
end_define

begin_comment
comment|// Pin Controlled by PB0
end_comment

begin_define
define|#
directive|define
name|AT91C_PB0_LCDVSYNC
value|((unsigned int) AT91C_PIO_PB0)
end_define

begin_comment
comment|//  LCD Vertical Synchronization
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB1
value|((unsigned int) 1<<  1)
end_define

begin_comment
comment|// Pin Controlled by PB1
end_comment

begin_define
define|#
directive|define
name|AT91C_PB1_LCDHSYNC
value|((unsigned int) AT91C_PIO_PB1)
end_define

begin_comment
comment|//  LCD Horizontal Synchronization
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB10
value|((unsigned int) 1<< 10)
end_define

begin_comment
comment|// Pin Controlled by PB10
end_comment

begin_define
define|#
directive|define
name|AT91C_PB10_LCDD5
value|((unsigned int) AT91C_PIO_PB10)
end_define

begin_comment
comment|//  LCD Data Bus Bit 5
end_comment

begin_define
define|#
directive|define
name|AT91C_PB10_LCDD10
value|((unsigned int) AT91C_PIO_PB10)
end_define

begin_comment
comment|//  LCD Data Bus Bit 10
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB11
value|((unsigned int) 1<< 11)
end_define

begin_comment
comment|// Pin Controlled by PB11
end_comment

begin_define
define|#
directive|define
name|AT91C_PB11_LCDD6
value|((unsigned int) AT91C_PIO_PB11)
end_define

begin_comment
comment|//  LCD Data Bus Bit 6
end_comment

begin_define
define|#
directive|define
name|AT91C_PB11_LCDD11
value|((unsigned int) AT91C_PIO_PB11)
end_define

begin_comment
comment|//  LCD Data Bus Bit 11
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB12
value|((unsigned int) 1<< 12)
end_define

begin_comment
comment|// Pin Controlled by PB12
end_comment

begin_define
define|#
directive|define
name|AT91C_PB12_LCDD7
value|((unsigned int) AT91C_PIO_PB12)
end_define

begin_comment
comment|//  LCD Data Bus Bit 7
end_comment

begin_define
define|#
directive|define
name|AT91C_PB12_LCDD12
value|((unsigned int) AT91C_PIO_PB12)
end_define

begin_comment
comment|//  LCD Data Bus Bit 12
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB13
value|((unsigned int) 1<< 13)
end_define

begin_comment
comment|// Pin Controlled by PB13
end_comment

begin_define
define|#
directive|define
name|AT91C_PB13_LCDD8
value|((unsigned int) AT91C_PIO_PB13)
end_define

begin_comment
comment|//  LCD Data Bus Bit 8
end_comment

begin_define
define|#
directive|define
name|AT91C_PB13_LCDD13
value|((unsigned int) AT91C_PIO_PB13)
end_define

begin_comment
comment|//  LCD Data Bus Bit 13
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB14
value|((unsigned int) 1<< 14)
end_define

begin_comment
comment|// Pin Controlled by PB14
end_comment

begin_define
define|#
directive|define
name|AT91C_PB14_LCDD9
value|((unsigned int) AT91C_PIO_PB14)
end_define

begin_comment
comment|//  LCD Data Bus Bit 9
end_comment

begin_define
define|#
directive|define
name|AT91C_PB14_LCDD14
value|((unsigned int) AT91C_PIO_PB14)
end_define

begin_comment
comment|//  LCD Data Bus Bit 14
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB15
value|((unsigned int) 1<< 15)
end_define

begin_comment
comment|// Pin Controlled by PB15
end_comment

begin_define
define|#
directive|define
name|AT91C_PB15_LCDD10
value|((unsigned int) AT91C_PIO_PB15)
end_define

begin_comment
comment|//  LCD Data Bus Bit 10
end_comment

begin_define
define|#
directive|define
name|AT91C_PB15_LCDD15
value|((unsigned int) AT91C_PIO_PB15)
end_define

begin_comment
comment|//  LCD Data Bus Bit 15
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB16
value|((unsigned int) 1<< 16)
end_define

begin_comment
comment|// Pin Controlled by PB16
end_comment

begin_define
define|#
directive|define
name|AT91C_PB16_LCDD11
value|((unsigned int) AT91C_PIO_PB16)
end_define

begin_comment
comment|//  LCD Data Bus Bit 11
end_comment

begin_define
define|#
directive|define
name|AT91C_PB16_LCDD19
value|((unsigned int) AT91C_PIO_PB16)
end_define

begin_comment
comment|//  LCD Data Bus Bit 19
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB17
value|((unsigned int) 1<< 17)
end_define

begin_comment
comment|// Pin Controlled by PB17
end_comment

begin_define
define|#
directive|define
name|AT91C_PB17_LCDD12
value|((unsigned int) AT91C_PIO_PB17)
end_define

begin_comment
comment|//  LCD Data Bus Bit 12
end_comment

begin_define
define|#
directive|define
name|AT91C_PB17_LCDD20
value|((unsigned int) AT91C_PIO_PB17)
end_define

begin_comment
comment|//  LCD Data Bus Bit 20
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB18
value|((unsigned int) 1<< 18)
end_define

begin_comment
comment|// Pin Controlled by PB18
end_comment

begin_define
define|#
directive|define
name|AT91C_PB18_LCDD13
value|((unsigned int) AT91C_PIO_PB18)
end_define

begin_comment
comment|//  LCD Data Bus Bit 13
end_comment

begin_define
define|#
directive|define
name|AT91C_PB18_LCDD21
value|((unsigned int) AT91C_PIO_PB18)
end_define

begin_comment
comment|//  LCD Data Bus Bit 21
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB19
value|((unsigned int) 1<< 19)
end_define

begin_comment
comment|// Pin Controlled by PB19
end_comment

begin_define
define|#
directive|define
name|AT91C_PB19_LCDD14
value|((unsigned int) AT91C_PIO_PB19)
end_define

begin_comment
comment|//  LCD Data Bus Bit 14
end_comment

begin_define
define|#
directive|define
name|AT91C_PB19_LCDD22
value|((unsigned int) AT91C_PIO_PB19)
end_define

begin_comment
comment|//  LCD Data Bus Bit 22
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB2
value|((unsigned int) 1<<  2)
end_define

begin_comment
comment|// Pin Controlled by PB2
end_comment

begin_define
define|#
directive|define
name|AT91C_PB2_LCDDOTCK
value|((unsigned int) AT91C_PIO_PB2)
end_define

begin_comment
comment|//  LCD Dot Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PB2_PCK0
value|((unsigned int) AT91C_PIO_PB2)
end_define

begin_comment
comment|//  PMC Programmable clock Output 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB20
value|((unsigned int) 1<< 20)
end_define

begin_comment
comment|// Pin Controlled by PB20
end_comment

begin_define
define|#
directive|define
name|AT91C_PB20_LCDD15
value|((unsigned int) AT91C_PIO_PB20)
end_define

begin_comment
comment|//  LCD Data Bus Bit 15
end_comment

begin_define
define|#
directive|define
name|AT91C_PB20_LCDD23
value|((unsigned int) AT91C_PIO_PB20)
end_define

begin_comment
comment|//  LCD Data Bus Bit 23
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB21
value|((unsigned int) 1<< 21)
end_define

begin_comment
comment|// Pin Controlled by PB21
end_comment

begin_define
define|#
directive|define
name|AT91C_PB21_TF0
value|((unsigned int) AT91C_PIO_PB21)
end_define

begin_comment
comment|//  SSC0 Transmit Frame Sync
end_comment

begin_define
define|#
directive|define
name|AT91C_PB21_LCDD16
value|((unsigned int) AT91C_PIO_PB21)
end_define

begin_comment
comment|//  LCD Data Bus Bit 16
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB22
value|((unsigned int) 1<< 22)
end_define

begin_comment
comment|// Pin Controlled by PB22
end_comment

begin_define
define|#
directive|define
name|AT91C_PB22_TK0
value|((unsigned int) AT91C_PIO_PB22)
end_define

begin_comment
comment|//  SSC0 Transmit Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PB22_LCDD17
value|((unsigned int) AT91C_PIO_PB22)
end_define

begin_comment
comment|//  LCD Data Bus Bit 17
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB23
value|((unsigned int) 1<< 23)
end_define

begin_comment
comment|// Pin Controlled by PB23
end_comment

begin_define
define|#
directive|define
name|AT91C_PB23_TD0
value|((unsigned int) AT91C_PIO_PB23)
end_define

begin_comment
comment|//  SSC0 Transmit Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PB23_LCDD18
value|((unsigned int) AT91C_PIO_PB23)
end_define

begin_comment
comment|//  LCD Data Bus Bit 18
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB24
value|((unsigned int) 1<< 24)
end_define

begin_comment
comment|// Pin Controlled by PB24
end_comment

begin_define
define|#
directive|define
name|AT91C_PB24_RD0
value|((unsigned int) AT91C_PIO_PB24)
end_define

begin_comment
comment|//  SSC0 Receive Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PB24_LCDD19
value|((unsigned int) AT91C_PIO_PB24)
end_define

begin_comment
comment|//  LCD Data Bus Bit 19
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB25
value|((unsigned int) 1<< 25)
end_define

begin_comment
comment|// Pin Controlled by PB25
end_comment

begin_define
define|#
directive|define
name|AT91C_PB25_RK0
value|((unsigned int) AT91C_PIO_PB25)
end_define

begin_comment
comment|//  SSC0 Receive Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PB25_LCDD20
value|((unsigned int) AT91C_PIO_PB25)
end_define

begin_comment
comment|//  LCD Data Bus Bit 20
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB26
value|((unsigned int) 1<< 26)
end_define

begin_comment
comment|// Pin Controlled by PB26
end_comment

begin_define
define|#
directive|define
name|AT91C_PB26_RF0
value|((unsigned int) AT91C_PIO_PB26)
end_define

begin_comment
comment|//  SSC0 Receive Frame Sync
end_comment

begin_define
define|#
directive|define
name|AT91C_PB26_LCDD21
value|((unsigned int) AT91C_PIO_PB26)
end_define

begin_comment
comment|//  LCD Data Bus Bit 21
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB27
value|((unsigned int) 1<< 27)
end_define

begin_comment
comment|// Pin Controlled by PB27
end_comment

begin_define
define|#
directive|define
name|AT91C_PB27_NPCS11
value|((unsigned int) AT91C_PIO_PB27)
end_define

begin_comment
comment|//  SPI1 Peripheral Chip Select 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PB27_LCDD22
value|((unsigned int) AT91C_PIO_PB27)
end_define

begin_comment
comment|//  LCD Data Bus Bit 22
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB28
value|((unsigned int) 1<< 28)
end_define

begin_comment
comment|// Pin Controlled by PB28
end_comment

begin_define
define|#
directive|define
name|AT91C_PB28_NPCS10
value|((unsigned int) AT91C_PIO_PB28)
end_define

begin_comment
comment|//  SPI1 Peripheral Chip Select 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PB28_LCDD23
value|((unsigned int) AT91C_PIO_PB28)
end_define

begin_comment
comment|//  LCD Data Bus Bit 23
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB29
value|((unsigned int) 1<< 29)
end_define

begin_comment
comment|// Pin Controlled by PB29
end_comment

begin_define
define|#
directive|define
name|AT91C_PB29_SPCK1
value|((unsigned int) AT91C_PIO_PB29)
end_define

begin_comment
comment|//  SPI1 Serial Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PB29_IRQ2
value|((unsigned int) AT91C_PIO_PB29)
end_define

begin_comment
comment|//  Interrupt input 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB3
value|((unsigned int) 1<<  3)
end_define

begin_comment
comment|// Pin Controlled by PB3
end_comment

begin_define
define|#
directive|define
name|AT91C_PB3_LCDDEN
value|((unsigned int) AT91C_PIO_PB3)
end_define

begin_comment
comment|//  LCD Data Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB30
value|((unsigned int) 1<< 30)
end_define

begin_comment
comment|// Pin Controlled by PB30
end_comment

begin_define
define|#
directive|define
name|AT91C_PB30_MISO1
value|((unsigned int) AT91C_PIO_PB30)
end_define

begin_comment
comment|//  SPI1 Master In Slave
end_comment

begin_define
define|#
directive|define
name|AT91C_PB30_IRQ1
value|((unsigned int) AT91C_PIO_PB30)
end_define

begin_comment
comment|//  Interrupt input 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB31
value|((unsigned int) 1<< 31)
end_define

begin_comment
comment|// Pin Controlled by PB31
end_comment

begin_define
define|#
directive|define
name|AT91C_PB31_MOSI1
value|((unsigned int) AT91C_PIO_PB31)
end_define

begin_comment
comment|//  SPI1 Master Out Slave
end_comment

begin_define
define|#
directive|define
name|AT91C_PB31_PCK2
value|((unsigned int) AT91C_PIO_PB31)
end_define

begin_comment
comment|//  PMC Programmable clock Output 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB4
value|((unsigned int) 1<<  4)
end_define

begin_comment
comment|// Pin Controlled by PB4
end_comment

begin_define
define|#
directive|define
name|AT91C_PB4_LCDCC
value|((unsigned int) AT91C_PIO_PB4)
end_define

begin_comment
comment|//  LCD Contrast Control
end_comment

begin_define
define|#
directive|define
name|AT91C_PB4_LCDD2
value|((unsigned int) AT91C_PIO_PB4)
end_define

begin_comment
comment|//  LCD Data Bus Bit 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB5
value|((unsigned int) 1<<  5)
end_define

begin_comment
comment|// Pin Controlled by PB5
end_comment

begin_define
define|#
directive|define
name|AT91C_PB5_LCDD0
value|((unsigned int) AT91C_PIO_PB5)
end_define

begin_comment
comment|//  LCD Data Bus Bit 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PB5_LCDD3
value|((unsigned int) AT91C_PIO_PB5)
end_define

begin_comment
comment|//  LCD Data Bus Bit 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB6
value|((unsigned int) 1<<  6)
end_define

begin_comment
comment|// Pin Controlled by PB6
end_comment

begin_define
define|#
directive|define
name|AT91C_PB6_LCDD1
value|((unsigned int) AT91C_PIO_PB6)
end_define

begin_comment
comment|//  LCD Data Bus Bit 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PB6_LCDD4
value|((unsigned int) AT91C_PIO_PB6)
end_define

begin_comment
comment|//  LCD Data Bus Bit 4
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB7
value|((unsigned int) 1<<  7)
end_define

begin_comment
comment|// Pin Controlled by PB7
end_comment

begin_define
define|#
directive|define
name|AT91C_PB7_LCDD2
value|((unsigned int) AT91C_PIO_PB7)
end_define

begin_comment
comment|//  LCD Data Bus Bit 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PB7_LCDD5
value|((unsigned int) AT91C_PIO_PB7)
end_define

begin_comment
comment|//  LCD Data Bus Bit 5
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB8
value|((unsigned int) 1<<  8)
end_define

begin_comment
comment|// Pin Controlled by PB8
end_comment

begin_define
define|#
directive|define
name|AT91C_PB8_LCDD3
value|((unsigned int) AT91C_PIO_PB8)
end_define

begin_comment
comment|//  LCD Data Bus Bit 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PB8_LCDD6
value|((unsigned int) AT91C_PIO_PB8)
end_define

begin_comment
comment|//  LCD Data Bus Bit 6
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PB9
value|((unsigned int) 1<<  9)
end_define

begin_comment
comment|// Pin Controlled by PB9
end_comment

begin_define
define|#
directive|define
name|AT91C_PB9_LCDD4
value|((unsigned int) AT91C_PIO_PB9)
end_define

begin_comment
comment|//  LCD Data Bus Bit 4
end_comment

begin_define
define|#
directive|define
name|AT91C_PB9_LCDD7
value|((unsigned int) AT91C_PIO_PB9)
end_define

begin_comment
comment|//  LCD Data Bus Bit 7
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC0
value|((unsigned int) 1<<  0)
end_define

begin_comment
comment|// Pin Controlled by PC0
end_comment

begin_define
define|#
directive|define
name|AT91C_PC0_SMOE
value|((unsigned int) AT91C_PIO_PC0)
end_define

begin_comment
comment|//  SmartMedia Output Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_PC0_NCS6
value|((unsigned int) AT91C_PIO_PC0)
end_define

begin_comment
comment|//  Chip Select 6
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC1
value|((unsigned int) 1<<  1)
end_define

begin_comment
comment|// Pin Controlled by PC1
end_comment

begin_define
define|#
directive|define
name|AT91C_PC1_SMWE
value|((unsigned int) AT91C_PIO_PC1)
end_define

begin_comment
comment|//  SmartMedia Write Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_PC1_NCS7
value|((unsigned int) AT91C_PIO_PC1)
end_define

begin_comment
comment|//  Chip Select 7
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC10
value|((unsigned int) 1<< 10)
end_define

begin_comment
comment|// Pin Controlled by PC10
end_comment

begin_define
define|#
directive|define
name|AT91C_PC10_RTS0
value|((unsigned int) AT91C_PIO_PC10)
end_define

begin_comment
comment|//  USART0 Ready To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PC10_SCK0
value|((unsigned int) AT91C_PIO_PC10)
end_define

begin_comment
comment|//  USART0 Serial Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC11
value|((unsigned int) 1<< 11)
end_define

begin_comment
comment|// Pin Controlled by PC11
end_comment

begin_define
define|#
directive|define
name|AT91C_PC11_CTS0
value|((unsigned int) AT91C_PIO_PC11)
end_define

begin_comment
comment|//  USART0 Clear To Send
end_comment

begin_define
define|#
directive|define
name|AT91C_PC11_FIQ
value|((unsigned int) AT91C_PIO_PC11)
end_define

begin_comment
comment|//  AIC Fast Interrupt Input
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC12
value|((unsigned int) 1<< 12)
end_define

begin_comment
comment|// Pin Controlled by PC12
end_comment

begin_define
define|#
directive|define
name|AT91C_PC12_TXD1
value|((unsigned int) AT91C_PIO_PC12)
end_define

begin_comment
comment|//  USART1 Transmit Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PC12_NCS6
value|((unsigned int) AT91C_PIO_PC12)
end_define

begin_comment
comment|//  Chip Select 6
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC13
value|((unsigned int) 1<< 13)
end_define

begin_comment
comment|// Pin Controlled by PC13
end_comment

begin_define
define|#
directive|define
name|AT91C_PC13_RXD1
value|((unsigned int) AT91C_PIO_PC13)
end_define

begin_comment
comment|//  USART1 Receive Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PC13_NCS7
value|((unsigned int) AT91C_PIO_PC13)
end_define

begin_comment
comment|//  Chip Select 7
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC14
value|((unsigned int) 1<< 14)
end_define

begin_comment
comment|// Pin Controlled by PC14
end_comment

begin_define
define|#
directive|define
name|AT91C_PC14_TXD2
value|((unsigned int) AT91C_PIO_PC14)
end_define

begin_comment
comment|//  USART2 Transmit Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PC14_NPCS12
value|((unsigned int) AT91C_PIO_PC14)
end_define

begin_comment
comment|//  SPI1 Peripheral Chip Select 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC15
value|((unsigned int) 1<< 15)
end_define

begin_comment
comment|// Pin Controlled by PC15
end_comment

begin_define
define|#
directive|define
name|AT91C_PC15_RXD2
value|((unsigned int) AT91C_PIO_PC15)
end_define

begin_comment
comment|//  USART2 Receive Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PC15_NPCS13
value|((unsigned int) AT91C_PIO_PC15)
end_define

begin_comment
comment|//  SPI1 Peripheral Chip Select 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC16
value|((unsigned int) 1<< 16)
end_define

begin_comment
comment|// Pin Controlled by PC16
end_comment

begin_define
define|#
directive|define
name|AT91C_PC16_D16
value|((unsigned int) AT91C_PIO_PC16)
end_define

begin_comment
comment|//  Data Bus [16]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC16_TCLK0
value|((unsigned int) AT91C_PIO_PC16)
end_define

begin_comment
comment|//  Timer Counter 0 external clock input
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC17
value|((unsigned int) 1<< 17)
end_define

begin_comment
comment|// Pin Controlled by PC17
end_comment

begin_define
define|#
directive|define
name|AT91C_PC17_D17
value|((unsigned int) AT91C_PIO_PC17)
end_define

begin_comment
comment|//  Data Bus [17]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC17_TCLK1
value|((unsigned int) AT91C_PIO_PC17)
end_define

begin_comment
comment|//  Timer Counter 1 external clock input
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC18
value|((unsigned int) 1<< 18)
end_define

begin_comment
comment|// Pin Controlled by PC18
end_comment

begin_define
define|#
directive|define
name|AT91C_PC18_D18
value|((unsigned int) AT91C_PIO_PC18)
end_define

begin_comment
comment|//  Data Bus [18]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC18_TCLK2
value|((unsigned int) AT91C_PIO_PC18)
end_define

begin_comment
comment|//  Timer Counter 2 external clock input
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC19
value|((unsigned int) 1<< 19)
end_define

begin_comment
comment|// Pin Controlled by PC19
end_comment

begin_define
define|#
directive|define
name|AT91C_PC19_D19
value|((unsigned int) AT91C_PIO_PC19)
end_define

begin_comment
comment|//  Data Bus [19]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC19_TIOA0
value|((unsigned int) AT91C_PIO_PC19)
end_define

begin_comment
comment|//  Timer Counter 0 Multipurpose Timer I/O Pin A
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC2
value|((unsigned int) 1<<  2)
end_define

begin_comment
comment|// Pin Controlled by PC2
end_comment

begin_define
define|#
directive|define
name|AT91C_PC2_NWAIT
value|((unsigned int) AT91C_PIO_PC2)
end_define

begin_comment
comment|//  NWAIT
end_comment

begin_define
define|#
directive|define
name|AT91C_PC2_IRQ0
value|((unsigned int) AT91C_PIO_PC2)
end_define

begin_comment
comment|//  Interrupt input 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC20
value|((unsigned int) 1<< 20)
end_define

begin_comment
comment|// Pin Controlled by PC20
end_comment

begin_define
define|#
directive|define
name|AT91C_PC20_D20
value|((unsigned int) AT91C_PIO_PC20)
end_define

begin_comment
comment|//  Data Bus [20]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC20_TIOB0
value|((unsigned int) AT91C_PIO_PC20)
end_define

begin_comment
comment|//  Timer Counter 0 Multipurpose Timer I/O Pin B
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC21
value|((unsigned int) 1<< 21)
end_define

begin_comment
comment|// Pin Controlled by PC21
end_comment

begin_define
define|#
directive|define
name|AT91C_PC21_D21
value|((unsigned int) AT91C_PIO_PC21)
end_define

begin_comment
comment|//  Data Bus [21]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC21_TIOA1
value|((unsigned int) AT91C_PIO_PC21)
end_define

begin_comment
comment|//  Timer Counter 1 Multipurpose Timer I/O Pin A
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC22
value|((unsigned int) 1<< 22)
end_define

begin_comment
comment|// Pin Controlled by PC22
end_comment

begin_define
define|#
directive|define
name|AT91C_PC22_D22
value|((unsigned int) AT91C_PIO_PC22)
end_define

begin_comment
comment|//  Data Bus [22]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC22_TIOB1
value|((unsigned int) AT91C_PIO_PC22)
end_define

begin_comment
comment|//  Timer Counter 1 Multipurpose Timer I/O Pin B
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC23
value|((unsigned int) 1<< 23)
end_define

begin_comment
comment|// Pin Controlled by PC23
end_comment

begin_define
define|#
directive|define
name|AT91C_PC23_D23
value|((unsigned int) AT91C_PIO_PC23)
end_define

begin_comment
comment|//  Data Bus [23]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC23_TIOA2
value|((unsigned int) AT91C_PIO_PC23)
end_define

begin_comment
comment|//  Timer Counter 2 Multipurpose Timer I/O Pin A
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC24
value|((unsigned int) 1<< 24)
end_define

begin_comment
comment|// Pin Controlled by PC24
end_comment

begin_define
define|#
directive|define
name|AT91C_PC24_D24
value|((unsigned int) AT91C_PIO_PC24)
end_define

begin_comment
comment|//  Data Bus [24]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC24_TIOB2
value|((unsigned int) AT91C_PIO_PC24)
end_define

begin_comment
comment|//  Timer Counter 2 Multipurpose Timer I/O Pin B
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC25
value|((unsigned int) 1<< 25)
end_define

begin_comment
comment|// Pin Controlled by PC25
end_comment

begin_define
define|#
directive|define
name|AT91C_PC25_D25
value|((unsigned int) AT91C_PIO_PC25)
end_define

begin_comment
comment|//  Data Bus [25]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC25_TF2
value|((unsigned int) AT91C_PIO_PC25)
end_define

begin_comment
comment|//  SSC2 Transmit Frame Sync
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC26
value|((unsigned int) 1<< 26)
end_define

begin_comment
comment|// Pin Controlled by PC26
end_comment

begin_define
define|#
directive|define
name|AT91C_PC26_D26
value|((unsigned int) AT91C_PIO_PC26)
end_define

begin_comment
comment|//  Data Bus [26]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC26_TK2
value|((unsigned int) AT91C_PIO_PC26)
end_define

begin_comment
comment|//  SSC2 Transmit Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC27
value|((unsigned int) 1<< 27)
end_define

begin_comment
comment|// Pin Controlled by PC27
end_comment

begin_define
define|#
directive|define
name|AT91C_PC27_D27
value|((unsigned int) AT91C_PIO_PC27)
end_define

begin_comment
comment|//  Data Bus [27]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC27_TD2
value|((unsigned int) AT91C_PIO_PC27)
end_define

begin_comment
comment|//  SSC2 Transmit Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC28
value|((unsigned int) 1<< 28)
end_define

begin_comment
comment|// Pin Controlled by PC28
end_comment

begin_define
define|#
directive|define
name|AT91C_PC28_D28
value|((unsigned int) AT91C_PIO_PC28)
end_define

begin_comment
comment|//  Data Bus [28]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC28_RD2
value|((unsigned int) AT91C_PIO_PC28)
end_define

begin_comment
comment|//  SSC2 Receive Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC29
value|((unsigned int) 1<< 29)
end_define

begin_comment
comment|// Pin Controlled by PC29
end_comment

begin_define
define|#
directive|define
name|AT91C_PC29_D29
value|((unsigned int) AT91C_PIO_PC29)
end_define

begin_comment
comment|//  Data Bus [29]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC29_RK2
value|((unsigned int) AT91C_PIO_PC29)
end_define

begin_comment
comment|//  SSC2 Receive Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC3
value|((unsigned int) 1<<  3)
end_define

begin_comment
comment|// Pin Controlled by PC3
end_comment

begin_define
define|#
directive|define
name|AT91C_PC3_A25_CFRNW
value|((unsigned int) AT91C_PIO_PC3)
end_define

begin_comment
comment|//  Address Bus[25] / Compact Flash Read Not Write
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC30
value|((unsigned int) 1<< 30)
end_define

begin_comment
comment|// Pin Controlled by PC30
end_comment

begin_define
define|#
directive|define
name|AT91C_PC30_D30
value|((unsigned int) AT91C_PIO_PC30)
end_define

begin_comment
comment|//  Data Bus [30]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC30_RF2
value|((unsigned int) AT91C_PIO_PC30)
end_define

begin_comment
comment|//  SSC2 Receive Frame Sync
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC31
value|((unsigned int) 1<< 31)
end_define

begin_comment
comment|// Pin Controlled by PC31
end_comment

begin_define
define|#
directive|define
name|AT91C_PC31_D31
value|((unsigned int) AT91C_PIO_PC31)
end_define

begin_comment
comment|//  Data Bus [31]
end_comment

begin_define
define|#
directive|define
name|AT91C_PC31_PCK1
value|((unsigned int) AT91C_PIO_PC31)
end_define

begin_comment
comment|//  PMC Programmable clock Output 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC4
value|((unsigned int) 1<<  4)
end_define

begin_comment
comment|// Pin Controlled by PC4
end_comment

begin_define
define|#
directive|define
name|AT91C_PC4_NCS4_CFCS0
value|((unsigned int) AT91C_PIO_PC4)
end_define

begin_comment
comment|//  Chip Select 4 / CompactFlash Chip Select 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC5
value|((unsigned int) 1<<  5)
end_define

begin_comment
comment|// Pin Controlled by PC5
end_comment

begin_define
define|#
directive|define
name|AT91C_PC5_NCS5_CFCS1
value|((unsigned int) AT91C_PIO_PC5)
end_define

begin_comment
comment|//  Chip Select 5 / CompactFlash Chip Select 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC6
value|((unsigned int) 1<<  6)
end_define

begin_comment
comment|// Pin Controlled by PC6
end_comment

begin_define
define|#
directive|define
name|AT91C_PC6_CFCE1
value|((unsigned int) AT91C_PIO_PC6)
end_define

begin_comment
comment|//  CompactFlash Chip Enable 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC7
value|((unsigned int) 1<<  7)
end_define

begin_comment
comment|// Pin Controlled by PC7
end_comment

begin_define
define|#
directive|define
name|AT91C_PC7_CFCE2
value|((unsigned int) AT91C_PIO_PC7)
end_define

begin_comment
comment|//  CompactFlash Chip Enable 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC8
value|((unsigned int) 1<<  8)
end_define

begin_comment
comment|// Pin Controlled by PC8
end_comment

begin_define
define|#
directive|define
name|AT91C_PC8_TXD0
value|((unsigned int) AT91C_PIO_PC8)
end_define

begin_comment
comment|//  USART0 Transmit Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PC8_PCK2
value|((unsigned int) AT91C_PIO_PC8)
end_define

begin_comment
comment|//  PMC Programmable clock Output 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PC9
value|((unsigned int) 1<<  9)
end_define

begin_comment
comment|// Pin Controlled by PC9
end_comment

begin_define
define|#
directive|define
name|AT91C_PC9_RXD0
value|((unsigned int) AT91C_PIO_PC9)
end_define

begin_comment
comment|//  USART0 Receive Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PC9_PCK3
value|((unsigned int) AT91C_PIO_PC9)
end_define

begin_comment
comment|//  PMC Programmable clock Output 3
end_comment

end_unit

