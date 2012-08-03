begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  *  ----------------------------------------------------------------------------  *          ATMEL Microcontroller Software Support  -  ROUSSET  -  *  ----------------------------------------------------------------------------  *  Copyright (c) 2009, Atmel Corporation  *   *  All rights reserved.  *   *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions are met:  *   *  - Redistributions of source code must retain the above copyright notice,  *  this list of conditions and the disclaimer below.  *   *  Atmel's name may not be used to endorse or promote products derived from  *  this software without specific prior written permission.   *    *  DISCLAIMER:  THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR  *  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE  *  DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,  *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,  *  OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  *  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  *  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,  *  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  ----------------------------------------------------------------------------  *  * From AT91LIB version 1.9 boards/at91sam9g45-ek/at91sam9g45/AT91SAM9G45.h  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARM_AT91_AT91_PIO_SAM9G45_H
end_ifndef

begin_define
define|#
directive|define
name|ARM_AT91_AT91_PIO_SAM9G45_H
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
comment|//               PIO DEFINITIONS FOR AT91SAM9G45
end_comment

begin_comment
comment|// *****************************************************************************
end_comment

begin_define
define|#
directive|define
name|AT91C_PA0_MCI0_CK
value|(AT91C_PIO_PA0)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PA0_TCLK3
value|(AT91C_PIO_PA0)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PA1_MCI0_CDA
value|(AT91C_PIO_PA1)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PA1_TIOA3
value|(AT91C_PIO_PA1)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PA10_ETX0
value|(AT91C_PIO_PA10)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Data 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PA11_ETX1
value|(AT91C_PIO_PA11)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Data 1
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
name|AT91C_PA13_ERX1
value|(AT91C_PIO_PA13)
end_define

begin_comment
comment|//  Ethernet MAC Receive Data 1
end_comment

begin_define
define|#
directive|define
name|AT91C_PA14_ETXEN
value|(AT91C_PIO_PA14)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Enable
end_comment

begin_define
define|#
directive|define
name|AT91C_PA15_ERXDV
value|(AT91C_PIO_PA15)
end_define

begin_comment
comment|//  Ethernet MAC Receive Data Valid
end_comment

begin_define
define|#
directive|define
name|AT91C_PA16_ERXER
value|(AT91C_PIO_PA16)
end_define

begin_comment
comment|//  Ethernet MAC Receive Error
end_comment

begin_define
define|#
directive|define
name|AT91C_PA17_ETXCK_EREFCK
value|(AT91C_PIO_PA17)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Clock/Reference Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PA18_EMDC
value|(AT91C_PIO_PA18)
end_define

begin_comment
comment|//  Ethernet MAC Management Data Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PA19_EMDIO
value|(AT91C_PIO_PA19)
end_define

begin_comment
comment|//  Ethernet MAC Management Data Input/Output
end_comment

begin_define
define|#
directive|define
name|AT91C_PA2_MCI0_DA0
value|(AT91C_PIO_PA2)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PA2_TIOB3
value|(AT91C_PIO_PA2)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PA20_TWD0
value|(AT91C_PIO_PA20)
end_define

begin_comment
comment|//  TWI Two-wire Serial Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PA21_TWCK0
value|(AT91C_PIO_PA21)
end_define

begin_comment
comment|//  TWI Two-wire Serial Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PA22_MCI1_CDA
value|(AT91C_PIO_PA22)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PA22_SCK3
value|(AT91C_PIO_PA22)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PA23_MCI1_DA0
value|(AT91C_PIO_PA23)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PA23_RTS3
value|(AT91C_PIO_PA23)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PA24_MCI1_DA1
value|(AT91C_PIO_PA24)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PA24_CTS3
value|(AT91C_PIO_PA24)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PA25_MCI1_DA2
value|(AT91C_PIO_PA25)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PA25_PWM3
value|(AT91C_PIO_PA25)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PA26_MCI1_DA3
value|(AT91C_PIO_PA26)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PA26_TIOB2
value|(AT91C_PIO_PA26)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PA27_MCI1_DA4
value|(AT91C_PIO_PA27)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PA27_ETXER
value|(AT91C_PIO_PA27)
end_define

begin_comment
comment|//  Ethernet MAC Transmikt Coding Error
end_comment

begin_define
define|#
directive|define
name|AT91C_PA28_MCI1_DA5
value|(AT91C_PIO_PA28)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PA28_ERXCK
value|(AT91C_PIO_PA28)
end_define

begin_comment
comment|//  Ethernet MAC Receive Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PA29_MCI1_DA6
value|(AT91C_PIO_PA29)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PA29_ECRS
value|(AT91C_PIO_PA29)
end_define

begin_comment
comment|//  Ethernet MAC Carrier Sense/Carrier Sense and Data Valid
end_comment

begin_define
define|#
directive|define
name|AT91C_PA3_MCI0_DA1
value|(AT91C_PIO_PA3)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PA3_TCLK4
value|(AT91C_PIO_PA3)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PA30_MCI1_DA7
value|(AT91C_PIO_PA30)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PA30_ECOL
value|(AT91C_PIO_PA30)
end_define

begin_comment
comment|//  Ethernet MAC Collision Detected
end_comment

begin_define
define|#
directive|define
name|AT91C_PA31_MCI1_CK
value|(AT91C_PIO_PA31)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PA31_PCK0
value|(AT91C_PIO_PA31)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PA4_MCI0_DA2
value|(AT91C_PIO_PA4)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PA4_TIOA4
value|(AT91C_PIO_PA4)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PA5_MCI0_DA3
value|(AT91C_PIO_PA5)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PA5_TIOB4
value|(AT91C_PIO_PA5)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PA6_MCI0_DA4
value|(AT91C_PIO_PA6)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PA6_ETX2
value|(AT91C_PIO_PA6)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Data 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PA7_MCI0_DA5
value|(AT91C_PIO_PA7)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PA7_ETX3
value|(AT91C_PIO_PA7)
end_define

begin_comment
comment|//  Ethernet MAC Transmit Data 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PA8_MCI0_DA6
value|(AT91C_PIO_PA8)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PA8_ERX2
value|(AT91C_PIO_PA8)
end_define

begin_comment
comment|//  Ethernet MAC Receive Data 2
end_comment

begin_define
define|#
directive|define
name|AT91C_PA9_MCI0_DA7
value|(AT91C_PIO_PA9)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PA9_ERX3
value|(AT91C_PIO_PA9)
end_define

begin_comment
comment|//  Ethernet MAC Receive Data 3
end_comment

begin_define
define|#
directive|define
name|AT91C_PB0_SPI0_MISO
value|(AT91C_PIO_PB0)
end_define

begin_comment
comment|//  SPI 0 Master In Slave
end_comment

begin_define
define|#
directive|define
name|AT91C_PB1_SPI0_MOSI
value|(AT91C_PIO_PB1)
end_define

begin_comment
comment|//  SPI 0 Master Out Slave
end_comment

begin_define
define|#
directive|define
name|AT91C_PB10_TWD1
value|(AT91C_PIO_PB10)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PB10_ISI_D10
value|(AT91C_PIO_PB10)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PB11_TWCK1
value|(AT91C_PIO_PB11)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PB11_ISI_D11
value|(AT91C_PIO_PB11)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PB12_DRXD
value|(AT91C_PIO_PB12)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PB13_DTXD
value|(AT91C_PIO_PB13)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PB14_SPI1_MISO
value|(AT91C_PIO_PB14)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PB15_SPI1_MOSI
value|(AT91C_PIO_PB15)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PB15_CTS0
value|(AT91C_PIO_PB15)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PB16_SPI1_SPCK
value|(AT91C_PIO_PB16)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PB16_SCK0
value|(AT91C_PIO_PB16)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PB17_SPI1_NPCS0
value|(AT91C_PIO_PB17)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PB17_RTS0
value|(AT91C_PIO_PB17)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PB18_RXD0
value|(AT91C_PIO_PB18)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PB18_SPI0_NPCS1
value|(AT91C_PIO_PB18)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PB19_TXD0
value|(AT91C_PIO_PB19)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PB19_SPI0_NPCS2
value|(AT91C_PIO_PB19)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PB2_SPI0_SPCK
value|(AT91C_PIO_PB2)
end_define

begin_comment
comment|//  SPI 0 Serial Clock
end_comment

begin_define
define|#
directive|define
name|AT91C_PB20_ISI_D0
value|(AT91C_PIO_PB20)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PB21_ISI_D1
value|(AT91C_PIO_PB21)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PB22_ISI_D2
value|(AT91C_PIO_PB22)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PB23_ISI_D3
value|(AT91C_PIO_PB23)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PB24_ISI_D4
value|(AT91C_PIO_PB24)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PB25_ISI_D5
value|(AT91C_PIO_PB25)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PB26_ISI_D6
value|(AT91C_PIO_PB26)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PB27_ISI_D7
value|(AT91C_PIO_PB27)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PB28_ISI_PCK
value|(AT91C_PIO_PB28)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PB29_ISI_VSYNC
value|(AT91C_PIO_PB29)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PB3_SPI0_NPCS0
value|(AT91C_PIO_PB3)
end_define

begin_comment
comment|//  SPI 0 Peripheral Chip Select 0
end_comment

begin_define
define|#
directive|define
name|AT91C_PB30_ISI_HSYNC
value|(AT91C_PIO_PB30)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PB31_
value|(AT91C_PIO_PB31)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PB31_PCK1
value|(AT91C_PIO_PB31)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PB4_TXD1
value|(AT91C_PIO_PB4)
end_define

begin_comment
comment|//  USART 1 Transmit Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PB5_RXD1
value|(AT91C_PIO_PB5)
end_define

begin_comment
comment|//  USART 1 Receive Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PB6_TXD2
value|(AT91C_PIO_PB6)
end_define

begin_comment
comment|//  USART 2 Transmit Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PB7_RXD2
value|(AT91C_PIO_PB7)
end_define

begin_comment
comment|//  USART 2 Receive Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PB8_TXD3
value|(AT91C_PIO_PB8)
end_define

begin_comment
comment|//  USART 3 Transmit Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PB8_ISI_D8
value|(AT91C_PIO_PB8)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PB9_RXD3
value|(AT91C_PIO_PB9)
end_define

begin_comment
comment|//  USART 3 Receive Data
end_comment

begin_define
define|#
directive|define
name|AT91C_PB9_ISI_D9
value|(AT91C_PIO_PB9)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PC0_DQM2
value|(AT91C_PIO_PC0)
end_define

begin_comment
comment|//  DQM2
end_comment

begin_define
define|#
directive|define
name|AT91C_PC1_DQM3
value|(AT91C_PIO_PC1)
end_define

begin_comment
comment|//  DQM3
end_comment

begin_define
define|#
directive|define
name|AT91C_PC10_NCS4_CFCS0
value|(AT91C_PIO_PC10)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PC10_TCLK2
value|(AT91C_PIO_PC10)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PC11_NCS5_CFCS1
value|(AT91C_PIO_PC11)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PC11_CTS2
value|(AT91C_PIO_PC11)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PC12_A25_CFRNW
value|(AT91C_PIO_PC12)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PC13_NCS2
value|(AT91C_PIO_PC13)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PC14_NCS3_NANDCS
value|(AT91C_PIO_PC14)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PC15_NWAIT
value|(AT91C_PIO_PC15)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PC16_D16
value|(AT91C_PIO_PC16)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PC17_D17
value|(AT91C_PIO_PC17)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PC18_D18
value|(AT91C_PIO_PC18)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PC19_D19
value|(AT91C_PIO_PC19)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PC2_A19
value|(AT91C_PIO_PC2)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PC20_D20
value|(AT91C_PIO_PC20)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PC21_D21
value|(AT91C_PIO_PC21)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PC22_D22
value|(AT91C_PIO_PC22)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PC23_D23
value|(AT91C_PIO_PC23)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PC24_D24
value|(AT91C_PIO_PC24)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PC25_D25
value|(AT91C_PIO_PC25)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PC26_D26
value|(AT91C_PIO_PC26)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PC27_D27
value|(AT91C_PIO_PC27)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PC28_D28
value|(AT91C_PIO_PC28)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PC29_D29
value|(AT91C_PIO_PC29)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PC3_A20
value|(AT91C_PIO_PC3)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PC30_D30
value|(AT91C_PIO_PC30)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PC31_D31
value|(AT91C_PIO_PC31)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PC4_A21_NANDALE
value|(AT91C_PIO_PC4)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PC5_A22_NANDCLE
value|(AT91C_PIO_PC5)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PC6_A23
value|(AT91C_PIO_PC6)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PC7_A24
value|(AT91C_PIO_PC7)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PC8_CFCE1
value|(AT91C_PIO_PC8)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PC9_CFCE2
value|(AT91C_PIO_PC9)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PC9_RTS2
value|(AT91C_PIO_PC9)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD0_TK0
value|(AT91C_PIO_PD0)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD0_PWM3
value|(AT91C_PIO_PD0)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD1_TF0
value|(AT91C_PIO_PD1)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD10_TD1
value|(AT91C_PIO_PD10)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD11_RD1
value|(AT91C_PIO_PD11)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD12_TK1
value|(AT91C_PIO_PD12)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD12_PCK0
value|(AT91C_PIO_PD12)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD13_RK1
value|(AT91C_PIO_PD13)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD14_TF1
value|(AT91C_PIO_PD14)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD15_RF1
value|(AT91C_PIO_PD15)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD16_RTS1
value|(AT91C_PIO_PD16)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD17_CTS1
value|(AT91C_PIO_PD17)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD18_SPI1_NPCS2
value|(AT91C_PIO_PD18)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD18_IRQ
value|(AT91C_PIO_PD18)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD19_SPI1_NPCS3
value|(AT91C_PIO_PD19)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD19_FIQ
value|(AT91C_PIO_PD19)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD2_TD0
value|(AT91C_PIO_PD2)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD20_TIOA0
value|(AT91C_PIO_PD20)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD21_TIOA1
value|(AT91C_PIO_PD21)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD22_TIOA2
value|(AT91C_PIO_PD22)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD23_TCLK0
value|(AT91C_PIO_PD23)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD24_SPI0_NPCS1
value|(AT91C_PIO_PD24)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD24_PWM0
value|(AT91C_PIO_PD24)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD25_SPI0_NPCS2
value|(AT91C_PIO_PD25)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD25_PWM1
value|(AT91C_PIO_PD25)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD26_PCK0
value|(AT91C_PIO_PD26)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD26_PWM2
value|(AT91C_PIO_PD26)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD27_PCK1
value|(AT91C_PIO_PD27)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD27_SPI0_NPCS3
value|(AT91C_PIO_PD27)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD28_TSADTRG
value|(AT91C_PIO_PD28)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD28_SPI1_NPCS1
value|(AT91C_PIO_PD28)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD29_TCLK1
value|(AT91C_PIO_PD29)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD29_SCK1
value|(AT91C_PIO_PD29)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD3_RD0
value|(AT91C_PIO_PD3)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD30_TIOB0
value|(AT91C_PIO_PD30)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD30_SCK2
value|(AT91C_PIO_PD30)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD31_TIOB1
value|(AT91C_PIO_PD31)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD31_PWM1
value|(AT91C_PIO_PD31)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD4_RK0
value|(AT91C_PIO_PD4)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD5_RF0
value|(AT91C_PIO_PD5)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD6_AC97RX
value|(AT91C_PIO_PD6)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD7_AC97TX
value|(AT91C_PIO_PD7)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD7_TIOA5
value|(AT91C_PIO_PD7)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD8_AC97FS
value|(AT91C_PIO_PD8)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD8_TIOB5
value|(AT91C_PIO_PD8)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD9_AC97CK
value|(AT91C_PIO_PD9)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PD9_TCLK5
value|(AT91C_PIO_PD9)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE0_LCDPWR
value|(AT91C_PIO_PE0)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE0_PCK0
value|(AT91C_PIO_PE0)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE1_LCDMOD
value|(AT91C_PIO_PE1)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE10_LCDD3
value|(AT91C_PIO_PE10)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE10_LCDD5
value|(AT91C_PIO_PE10)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE11_LCDD4
value|(AT91C_PIO_PE11)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE11_LCDD6
value|(AT91C_PIO_PE11)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE12_LCDD5
value|(AT91C_PIO_PE12)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE12_LCDD7
value|(AT91C_PIO_PE12)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE13_LCDD6
value|(AT91C_PIO_PE13)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE13_LCDD10
value|(AT91C_PIO_PE13)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE14_LCDD7
value|(AT91C_PIO_PE14)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE14_LCDD11
value|(AT91C_PIO_PE14)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE15_LCDD8
value|(AT91C_PIO_PE15)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE15_LCDD12
value|(AT91C_PIO_PE15)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE16_LCDD9
value|(AT91C_PIO_PE16)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE16_LCDD13
value|(AT91C_PIO_PE16)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE17_LCDD10
value|(AT91C_PIO_PE17)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE17_LCDD14
value|(AT91C_PIO_PE17)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE18_LCDD11
value|(AT91C_PIO_PE18)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE18_LCDD15
value|(AT91C_PIO_PE18)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE19_LCDD12
value|(AT91C_PIO_PE19)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE19_LCDD18
value|(AT91C_PIO_PE19)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE2_LCDCC
value|(AT91C_PIO_PE2)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE20_LCDD13
value|(AT91C_PIO_PE20)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE20_LCDD19
value|(AT91C_PIO_PE20)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE21_LCDD14
value|(AT91C_PIO_PE21)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE21_LCDD20
value|(AT91C_PIO_PE21)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE22_LCDD15
value|(AT91C_PIO_PE22)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE22_LCDD21
value|(AT91C_PIO_PE22)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE23_LCDD16
value|(AT91C_PIO_PE23)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE23_LCDD22
value|(AT91C_PIO_PE23)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE24_LCDD17
value|(AT91C_PIO_PE24)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE24_LCDD23
value|(AT91C_PIO_PE24)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE25_LCDD18
value|(AT91C_PIO_PE25)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE26_LCDD19
value|(AT91C_PIO_PE26)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE27_LCDD20
value|(AT91C_PIO_PE27)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE28_LCDD21
value|(AT91C_PIO_PE28)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE29_LCDD22
value|(AT91C_PIO_PE29)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE3_LCDVSYNC
value|(AT91C_PIO_PE3)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE30_LCDD23
value|(AT91C_PIO_PE30)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE31_PWM2
value|(AT91C_PIO_PE31)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE31_PCK1
value|(AT91C_PIO_PE31)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE4_LCDHSYNC
value|(AT91C_PIO_PE4)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE5_LCDDOTCK
value|(AT91C_PIO_PE5)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE6_LCDDEN
value|(AT91C_PIO_PE6)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE7_LCDD0
value|(AT91C_PIO_PE7)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE7_LCDD2
value|(AT91C_PIO_PE7)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE8_LCDD1
value|(AT91C_PIO_PE8)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE8_LCDD3
value|(AT91C_PIO_PE8)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE9_LCDD2
value|(AT91C_PIO_PE9)
end_define

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AT91C_PE9_LCDD4
value|(AT91C_PIO_PE9)
end_define

begin_comment
comment|//
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARM_AT91_AT91_PIO_SAM9G45_H */
end_comment

end_unit

