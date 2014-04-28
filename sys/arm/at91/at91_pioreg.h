begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 M. Warner Losh.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARM_AT91_AT91_PIOREG_H
end_ifndef

begin_define
define|#
directive|define
name|ARM_AT91_AT91_PIOREG_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ATMEL_ENV
end_ifndef

begin_comment
comment|/* Registers */
end_comment

begin_define
define|#
directive|define
name|PIO_PER
value|0x00
end_define

begin_comment
comment|/* PIO Enable Register */
end_comment

begin_define
define|#
directive|define
name|PIO_PDR
value|0x04
end_define

begin_comment
comment|/* PIO Disable Register */
end_comment

begin_define
define|#
directive|define
name|PIO_PSR
value|0x08
end_define

begin_comment
comment|/* PIO Status Register */
end_comment

begin_comment
comment|/*	0x0c		   reserved */
end_comment

begin_define
define|#
directive|define
name|PIO_OER
value|0x10
end_define

begin_comment
comment|/* PIO Output Enable Register */
end_comment

begin_define
define|#
directive|define
name|PIO_ODR
value|0x14
end_define

begin_comment
comment|/* PIO Output Disable Register */
end_comment

begin_define
define|#
directive|define
name|PIO_OSR
value|0x18
end_define

begin_comment
comment|/* PIO Output Status Register */
end_comment

begin_comment
comment|/*	0x1c		   reserved */
end_comment

begin_define
define|#
directive|define
name|PIO_IFER
value|0x20
end_define

begin_comment
comment|/* PIO Glitch Input Enable Register */
end_comment

begin_define
define|#
directive|define
name|PIO_IFDR
value|0x24
end_define

begin_comment
comment|/* PIO Glitch Input Disable Register */
end_comment

begin_define
define|#
directive|define
name|PIO_IFSR
value|0x28
end_define

begin_comment
comment|/* PIO Glitch Input Status Register */
end_comment

begin_comment
comment|/*	0x2c		   reserved */
end_comment

begin_define
define|#
directive|define
name|PIO_SODR
value|0x30
end_define

begin_comment
comment|/* PIO Set Output Data Register */
end_comment

begin_define
define|#
directive|define
name|PIO_CODR
value|0x34
end_define

begin_comment
comment|/* PIO Clear Output Data Register */
end_comment

begin_define
define|#
directive|define
name|PIO_ODSR
value|0x38
end_define

begin_comment
comment|/* PIO Output Data Status Register */
end_comment

begin_define
define|#
directive|define
name|PIO_PDSR
value|0x3c
end_define

begin_comment
comment|/* PIO Pin Data Status Register */
end_comment

begin_define
define|#
directive|define
name|PIO_IER
value|0x40
end_define

begin_comment
comment|/* PIO Interrupt Enable Register */
end_comment

begin_define
define|#
directive|define
name|PIO_IDR
value|0x44
end_define

begin_comment
comment|/* PIO Interrupt Disable Register */
end_comment

begin_define
define|#
directive|define
name|PIO_IMR
value|0x48
end_define

begin_comment
comment|/* PIO Interrupt Mask Register */
end_comment

begin_define
define|#
directive|define
name|PIO_ISR
value|0x4c
end_define

begin_comment
comment|/* PIO Interrupt Status Register */
end_comment

begin_define
define|#
directive|define
name|PIO_MDER
value|0x50
end_define

begin_comment
comment|/* PIO Multi-Driver Enable Register */
end_comment

begin_define
define|#
directive|define
name|PIO_MDDR
value|0x54
end_define

begin_comment
comment|/* PIO Multi-Driver Disable Register */
end_comment

begin_define
define|#
directive|define
name|PIO_MDSR
value|0x58
end_define

begin_comment
comment|/* PIO Multi-Driver Status Register */
end_comment

begin_comment
comment|/*	0x5c		   reserved */
end_comment

begin_define
define|#
directive|define
name|PIO_PUDR
value|0x60
end_define

begin_comment
comment|/* PIO Pull-up Disable Register */
end_comment

begin_define
define|#
directive|define
name|PIO_PUER
value|0x64
end_define

begin_comment
comment|/* PIO Pull-up Enable Register */
end_comment

begin_define
define|#
directive|define
name|PIO_PUSR
value|0x68
end_define

begin_comment
comment|/* PIO Pull-up Status Register */
end_comment

begin_comment
comment|/*	0x6c		   reserved */
end_comment

begin_define
define|#
directive|define
name|PIO_ASR
value|0x70
end_define

begin_comment
comment|/* PIO Peripheral A Select Register */
end_comment

begin_define
define|#
directive|define
name|PIO_BSR
value|0x74
end_define

begin_comment
comment|/* PIO Peripheral B Select Register */
end_comment

begin_define
define|#
directive|define
name|PIO_ABSR
value|0x78
end_define

begin_comment
comment|/* PIO AB Status Register */
end_comment

begin_comment
comment|/*	0x7c-0x9c	   reserved */
end_comment

begin_define
define|#
directive|define
name|PIO_OWER
value|0xa0
end_define

begin_comment
comment|/* PIO Output Write Enable Register */
end_comment

begin_define
define|#
directive|define
name|PIO_OWDR
value|0xa4
end_define

begin_comment
comment|/* PIO Output Write Disable Register */
end_comment

begin_define
define|#
directive|define
name|PIO_OWSR
value|0xa8
end_define

begin_comment
comment|/* PIO Output Write Status Register */
end_comment

begin_comment
comment|/*	0xac		   reserved */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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
name|AT91C_PIO_PA1
value|((unsigned int) 1<<  1)
end_define

begin_comment
comment|// Pin Controlled by PA1
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
name|AT91C_PIO_PA3
value|((unsigned int) 1<<  3)
end_define

begin_comment
comment|// Pin Controlled by PA3
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
name|AT91C_PIO_PA5
value|((unsigned int) 1<<  5)
end_define

begin_comment
comment|// Pin Controlled by PA5
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
name|AT91C_PIO_PA7
value|((unsigned int) 1<<  7)
end_define

begin_comment
comment|// Pin Controlled by PA7
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
name|AT91C_PIO_PA9
value|((unsigned int) 1<<  9)
end_define

begin_comment
comment|// Pin Controlled by PA9
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
name|AT91C_PIO_PA11
value|((unsigned int) 1<< 11)
end_define

begin_comment
comment|// Pin Controlled by PA11
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
name|AT91C_PIO_PA13
value|((unsigned int) 1<< 13)
end_define

begin_comment
comment|// Pin Controlled by PA13
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
name|AT91C_PIO_PA15
value|((unsigned int) 1<< 15)
end_define

begin_comment
comment|// Pin Controlled by PA15
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
name|AT91C_PIO_PA17
value|((unsigned int) 1<< 17)
end_define

begin_comment
comment|// Pin Controlled by PA17
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
name|AT91C_PIO_PA19
value|((unsigned int) 1<< 19)
end_define

begin_comment
comment|// Pin Controlled by PA19
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
name|AT91C_PIO_PA21
value|((unsigned int) 1<< 21)
end_define

begin_comment
comment|// Pin Controlled by PA21
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
name|AT91C_PIO_PA23
value|((unsigned int) 1<< 23)
end_define

begin_comment
comment|// Pin Controlled by PA23
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
name|AT91C_PIO_PA25
value|((unsigned int) 1<< 25)
end_define

begin_comment
comment|// Pin Controlled by PA25
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
name|AT91C_PIO_PA27
value|((unsigned int) 1<< 27)
end_define

begin_comment
comment|// Pin Controlled by PA27
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
name|AT91C_PIO_PA29
value|((unsigned int) 1<< 29)
end_define

begin_comment
comment|// Pin Controlled by PA29
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
name|AT91C_PIO_PA31
value|((unsigned int) 1<< 31)
end_define

begin_comment
comment|// Pin Controlled by PA31
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
name|AT91C_PIO_PB1
value|((unsigned int) 1<<  1)
end_define

begin_comment
comment|// Pin Controlled by PB1
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
name|AT91C_PIO_PB3
value|((unsigned int) 1<<  3)
end_define

begin_comment
comment|// Pin Controlled by PB3
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
name|AT91C_PIO_PB5
value|((unsigned int) 1<<  5)
end_define

begin_comment
comment|// Pin Controlled by PB5
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
name|AT91C_PIO_PB7
value|((unsigned int) 1<<  7)
end_define

begin_comment
comment|// Pin Controlled by PB7
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
name|AT91C_PIO_PB9
value|((unsigned int) 1<<  9)
end_define

begin_comment
comment|// Pin Controlled by PB9
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
name|AT91C_PIO_PB11
value|((unsigned int) 1<< 11)
end_define

begin_comment
comment|// Pin Controlled by PB11
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
name|AT91C_PIO_PB13
value|((unsigned int) 1<< 13)
end_define

begin_comment
comment|// Pin Controlled by PB13
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
name|AT91C_PIO_PB15
value|((unsigned int) 1<< 15)
end_define

begin_comment
comment|// Pin Controlled by PB15
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
name|AT91C_PIO_PB17
value|((unsigned int) 1<< 17)
end_define

begin_comment
comment|// Pin Controlled by PB17
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
name|AT91C_PIO_PB19
value|((unsigned int) 1<< 19)
end_define

begin_comment
comment|// Pin Controlled by PB19
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
name|AT91C_PIO_PB21
value|((unsigned int) 1<< 21)
end_define

begin_comment
comment|// Pin Controlled by PB21
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
name|AT91C_PIO_PB23
value|((unsigned int) 1<< 23)
end_define

begin_comment
comment|// Pin Controlled by PB23
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
name|AT91C_PIO_PB25
value|((unsigned int) 1<< 25)
end_define

begin_comment
comment|// Pin Controlled by PB25
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
name|AT91C_PIO_PB27
value|((unsigned int) 1<< 27)
end_define

begin_comment
comment|// Pin Controlled by PB27
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
name|AT91C_PIO_PB29
value|((unsigned int) 1<< 29)
end_define

begin_comment
comment|// Pin Controlled by PB29
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
name|AT91C_PIO_PB31
value|((unsigned int) 1<< 31)
end_define

begin_comment
comment|// Pin Controlled by PB31
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
name|AT91C_PIO_PC1
value|((unsigned int) 1<<  1)
end_define

begin_comment
comment|// Pin Controlled by PC1
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
name|AT91C_PIO_PC3
value|((unsigned int) 1<<  3)
end_define

begin_comment
comment|// Pin Controlled by PC3
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
name|AT91C_PIO_PC5
value|((unsigned int) 1<<  5)
end_define

begin_comment
comment|// Pin Controlled by PC5
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
name|AT91C_PIO_PC7
value|((unsigned int) 1<<  7)
end_define

begin_comment
comment|// Pin Controlled by PC7
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
name|AT91C_PIO_PC9
value|((unsigned int) 1<<  9)
end_define

begin_comment
comment|// Pin Controlled by PC9
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
name|AT91C_PIO_PC11
value|((unsigned int) 1<< 11)
end_define

begin_comment
comment|// Pin Controlled by PC11
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
name|AT91C_PIO_PC13
value|((unsigned int) 1<< 13)
end_define

begin_comment
comment|// Pin Controlled by PC13
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
name|AT91C_PIO_PC15
value|((unsigned int) 1<< 15)
end_define

begin_comment
comment|// Pin Controlled by PC15
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
name|AT91C_PIO_PC17
value|((unsigned int) 1<< 17)
end_define

begin_comment
comment|// Pin Controlled by PC17
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
name|AT91C_PIO_PC19
value|((unsigned int) 1<< 19)
end_define

begin_comment
comment|// Pin Controlled by PC19
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
name|AT91C_PIO_PC21
value|((unsigned int) 1<< 21)
end_define

begin_comment
comment|// Pin Controlled by PC21
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
name|AT91C_PIO_PC23
value|((unsigned int) 1<< 23)
end_define

begin_comment
comment|// Pin Controlled by PC23
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
name|AT91C_PIO_PC25
value|((unsigned int) 1<< 25)
end_define

begin_comment
comment|// Pin Controlled by PC25
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
name|AT91C_PIO_PC27
value|((unsigned int) 1<< 27)
end_define

begin_comment
comment|// Pin Controlled by PC27
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
name|AT91C_PIO_PC29
value|((unsigned int) 1<< 29)
end_define

begin_comment
comment|// Pin Controlled by PC29
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
name|AT91C_PIO_PC31
value|((unsigned int) 1<< 31)
end_define

begin_comment
comment|// Pin Controlled by PC31
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD0
value|((unsigned int) 1<<  0)
end_define

begin_comment
comment|// Pin Controlled by PD0
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD1
value|((unsigned int) 1<<  1)
end_define

begin_comment
comment|// Pin Controlled by PD1
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD2
value|((unsigned int) 1<<  2)
end_define

begin_comment
comment|// Pin Controlled by PD2
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD3
value|((unsigned int) 1<<  3)
end_define

begin_comment
comment|// Pin Controlled by PD3
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD4
value|((unsigned int) 1<<  4)
end_define

begin_comment
comment|// Pin Controlled by PD4
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD5
value|((unsigned int) 1<<  5)
end_define

begin_comment
comment|// Pin Controlled by PD5
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD6
value|((unsigned int) 1<<  6)
end_define

begin_comment
comment|// Pin Controlled by PD6
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD7
value|((unsigned int) 1<<  7)
end_define

begin_comment
comment|// Pin Controlled by PD7
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD8
value|((unsigned int) 1<<  8)
end_define

begin_comment
comment|// Pin Controlled by PD8
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD9
value|((unsigned int) 1<<  9)
end_define

begin_comment
comment|// Pin Controlled by PD9
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD10
value|((unsigned int) 1<< 10)
end_define

begin_comment
comment|// Pin Controlled by PD10
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD11
value|((unsigned int) 1<< 11)
end_define

begin_comment
comment|// Pin Controlled by PD11
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD12
value|((unsigned int) 1<< 12)
end_define

begin_comment
comment|// Pin Controlled by PD12
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD13
value|((unsigned int) 1<< 13)
end_define

begin_comment
comment|// Pin Controlled by PD13
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD14
value|((unsigned int) 1<< 14)
end_define

begin_comment
comment|// Pin Controlled by PD14
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD15
value|((unsigned int) 1<< 15)
end_define

begin_comment
comment|// Pin Controlled by PD15
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD16
value|((unsigned int) 1<< 16)
end_define

begin_comment
comment|// Pin Controlled by PD16
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD17
value|((unsigned int) 1<< 17)
end_define

begin_comment
comment|// Pin Controlled by PD17
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD18
value|((unsigned int) 1<< 18)
end_define

begin_comment
comment|// Pin Controlled by PD18
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD19
value|((unsigned int) 1<< 19)
end_define

begin_comment
comment|// Pin Controlled by PD19
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD20
value|((unsigned int) 1<< 20)
end_define

begin_comment
comment|// Pin Controlled by PD20
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD21
value|((unsigned int) 1<< 21)
end_define

begin_comment
comment|// Pin Controlled by PD21
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD22
value|((unsigned int) 1<< 22)
end_define

begin_comment
comment|// Pin Controlled by PD22
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD23
value|((unsigned int) 1<< 23)
end_define

begin_comment
comment|// Pin Controlled by PD23
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD24
value|((unsigned int) 1<< 24)
end_define

begin_comment
comment|// Pin Controlled by PD24
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD25
value|((unsigned int) 1<< 25)
end_define

begin_comment
comment|// Pin Controlled by PD25
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD26
value|((unsigned int) 1<< 26)
end_define

begin_comment
comment|// Pin Controlled by PD26
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD27
value|((unsigned int) 1<< 27)
end_define

begin_comment
comment|// Pin Controlled by PD27
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD28
value|((unsigned int) 1<< 28)
end_define

begin_comment
comment|// Pin Controlled by PD28
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD29
value|((unsigned int) 1<< 29)
end_define

begin_comment
comment|// Pin Controlled by PD29
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD30
value|((unsigned int) 1<< 30)
end_define

begin_comment
comment|// Pin Controlled by PD30
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PD31
value|((unsigned int) 1<< 31)
end_define

begin_comment
comment|// Pin Controlled by PD31
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PE0
value|((unsigned int) 1<<  0)
end_define

begin_comment
comment|// Pin Controlled by PE0
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PE1
value|((unsigned int) 1<<  1)
end_define

begin_comment
comment|// Pin Controlled by PE1
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PE2
value|((unsigned int) 1<<  2)
end_define

begin_comment
comment|// Pin Controlled by PE2
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PE3
value|((unsigned int) 1<<  3)
end_define

begin_comment
comment|// Pin Controlled by PE3
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PE4
value|((unsigned int) 1<<  4)
end_define

begin_comment
comment|// Pin Controlled by PE4
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PE5
value|((unsigned int) 1<<  5)
end_define

begin_comment
comment|// Pin Controlled by PE5
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PE6
value|((unsigned int) 1<<  6)
end_define

begin_comment
comment|// Pin Controlled by PE6
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PE7
value|((unsigned int) 1<<  7)
end_define

begin_comment
comment|// Pin Controlled by PE7
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PE8
value|((unsigned int) 1<<  8)
end_define

begin_comment
comment|// Pin Controlled by PE8
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PE9
value|((unsigned int) 1<<  9)
end_define

begin_comment
comment|// Pin Controlled by PE9
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PE10
value|((unsigned int) 1<< 10)
end_define

begin_comment
comment|// Pin Controlled by PE10
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PE11
value|((unsigned int) 1<< 11)
end_define

begin_comment
comment|// Pin Controlled by PE11
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PE12
value|((unsigned int) 1<< 12)
end_define

begin_comment
comment|// Pin Controlled by PE12
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PE13
value|((unsigned int) 1<< 13)
end_define

begin_comment
comment|// Pin Controlled by PE13
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PE14
value|((unsigned int) 1<< 14)
end_define

begin_comment
comment|// Pin Controlled by PE14
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PE15
value|((unsigned int) 1<< 15)
end_define

begin_comment
comment|// Pin Controlled by PE15
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PE16
value|((unsigned int) 1<< 16)
end_define

begin_comment
comment|// Pin Controlled by PE16
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PE17
value|((unsigned int) 1<< 17)
end_define

begin_comment
comment|// Pin Controlled by PE17
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PE18
value|((unsigned int) 1<< 18)
end_define

begin_comment
comment|// Pin Controlled by PE18
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PE19
value|((unsigned int) 1<< 19)
end_define

begin_comment
comment|// Pin Controlled by PE19
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PE20
value|((unsigned int) 1<< 20)
end_define

begin_comment
comment|// Pin Controlled by PE20
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PE21
value|((unsigned int) 1<< 21)
end_define

begin_comment
comment|// Pin Controlled by PE21
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PE22
value|((unsigned int) 1<< 22)
end_define

begin_comment
comment|// Pin Controlled by PE22
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PE23
value|((unsigned int) 1<< 23)
end_define

begin_comment
comment|// Pin Controlled by PE23
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PE24
value|((unsigned int) 1<< 24)
end_define

begin_comment
comment|// Pin Controlled by PE24
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PE25
value|((unsigned int) 1<< 25)
end_define

begin_comment
comment|// Pin Controlled by PE25
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PE26
value|((unsigned int) 1<< 26)
end_define

begin_comment
comment|// Pin Controlled by PE26
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PE27
value|((unsigned int) 1<< 27)
end_define

begin_comment
comment|// Pin Controlled by PE27
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PE28
value|((unsigned int) 1<< 28)
end_define

begin_comment
comment|// Pin Controlled by PE28
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PE29
value|((unsigned int) 1<< 29)
end_define

begin_comment
comment|// Pin Controlled by PE29
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PE30
value|((unsigned int) 1<< 30)
end_define

begin_comment
comment|// Pin Controlled by PE30
end_comment

begin_define
define|#
directive|define
name|AT91C_PIO_PE31
value|((unsigned int) 1<< 31)
end_define

begin_comment
comment|// Pin Controlled by PE31
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARM_AT91_AT91_PIOREG_H */
end_comment

end_unit

