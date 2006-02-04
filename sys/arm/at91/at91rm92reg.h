begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Olivier Houchard.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AT91RM92REG_H_
end_ifndef

begin_define
define|#
directive|define
name|AT91RM92REG_H_
end_define

begin_comment
comment|/*   * Memory map, from datasheet :  * 0x00000000 - 0x0ffffffff : Internal Memories  * 0x10000000 - 0x1ffffffff : Chip Select 0  * 0x20000000 - 0x2ffffffff : Chip Select 1  * 0x30000000 - 0x3ffffffff : Chip Select 2  * 0x40000000 - 0x4ffffffff : Chip Select 3  * 0x50000000 - 0x5ffffffff : Chip Select 4  * 0x60000000 - 0x6ffffffff : Chip Select 5  * 0x70000000 - 0x7ffffffff : Chip Select 6  * 0x80000000 - 0x8ffffffff : Chip Select 7  * 0x90000000 - 0xeffffffff : Undefined (Abort)  * 0xf0000000 - 0xfffffffff : Peripherals  */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_BASE
value|0xf0000000
end_define

begin_comment
comment|/* Usart */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_USART0_BASE
value|0xffc0000
end_define

begin_define
define|#
directive|define
name|AT91RM92_USART0_PDC
value|0xffc0100
end_define

begin_define
define|#
directive|define
name|AT91RM92_USART1_BASE
value|0xffc4000
end_define

begin_define
define|#
directive|define
name|AT91RM92_USART1_PDC
value|0xffc4100
end_define

begin_define
define|#
directive|define
name|AT91RM92_USART2_BASE
value|0xffc8000
end_define

begin_define
define|#
directive|define
name|AT91RM92_USART2_PDC
value|0xffc8100
end_define

begin_define
define|#
directive|define
name|AT91RM92_USART3_BASE
value|0xffcc000
end_define

begin_define
define|#
directive|define
name|AT91RM92_USART3_PDC
value|0xffcc100
end_define

begin_define
define|#
directive|define
name|AT91RM92_USART_SIZE
value|0x4000
end_define

begin_comment
comment|/* System Registers */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_SYS_BASE
value|0xffff000
end_define

begin_define
define|#
directive|define
name|AT91RM92_SYS_SIZE
value|0x1000
end_define

begin_comment
comment|/* Interrupt Controller */
end_comment

begin_define
define|#
directive|define
name|IC_SMR
value|(0)
end_define

begin_comment
comment|/* Source mode register */
end_comment

begin_define
define|#
directive|define
name|IC_SVR
value|(128)
end_define

begin_comment
comment|/* Source vector register */
end_comment

begin_define
define|#
directive|define
name|IC_IVR
value|(256)
end_define

begin_comment
comment|/* IRQ vector register */
end_comment

begin_define
define|#
directive|define
name|IC_FVR
value|(260)
end_define

begin_comment
comment|/* FIQ vector register */
end_comment

begin_define
define|#
directive|define
name|IC_ISR
value|(264)
end_define

begin_comment
comment|/* Interrupt status register */
end_comment

begin_define
define|#
directive|define
name|IC_IPR
value|(268)
end_define

begin_comment
comment|/* Interrupt pending register */
end_comment

begin_define
define|#
directive|define
name|IC_IMR
value|(272)
end_define

begin_comment
comment|/* Interrupt status register */
end_comment

begin_define
define|#
directive|define
name|IC_CISR
value|(276)
end_define

begin_comment
comment|/* Core interrupt status register */
end_comment

begin_define
define|#
directive|define
name|IC_IECR
value|(288)
end_define

begin_comment
comment|/* Interrupt enable command register */
end_comment

begin_define
define|#
directive|define
name|IC_IDCR
value|(292)
end_define

begin_comment
comment|/* Interrupt disable command register */
end_comment

begin_define
define|#
directive|define
name|IC_ICCR
value|(296)
end_define

begin_comment
comment|/* Interrupt clear command register */
end_comment

begin_define
define|#
directive|define
name|IC_ISCR
value|(300)
end_define

begin_comment
comment|/* Interrupt set command register */
end_comment

begin_define
define|#
directive|define
name|IC_EOICR
value|(304)
end_define

begin_comment
comment|/* End of interrupt command register */
end_comment

begin_define
define|#
directive|define
name|IC_SPU
value|(308)
end_define

begin_comment
comment|/* Spurious vector register */
end_comment

begin_define
define|#
directive|define
name|IC_DCR
value|(312)
end_define

begin_comment
comment|/* Debug control register */
end_comment

begin_define
define|#
directive|define
name|IC_FFER
value|(320)
end_define

begin_comment
comment|/* Fast forcing enable register */
end_comment

begin_define
define|#
directive|define
name|IC_FFDR
value|(324)
end_define

begin_comment
comment|/* Fast forcing disable register */
end_comment

begin_define
define|#
directive|define
name|IC_FFSR
value|(328)
end_define

begin_comment
comment|/* Fast forcing status register */
end_comment

begin_comment
comment|/* DBGU */
end_comment

begin_define
define|#
directive|define
name|DBGU
value|0x200
end_define

begin_define
define|#
directive|define
name|DBGU_SIZE
value|0x200
end_define

begin_define
define|#
directive|define
name|DBGU_C1R
value|(0x200 + 64)
end_define

begin_comment
comment|/* Chip ID1 Register */
end_comment

begin_define
define|#
directive|define
name|DBGU_C2R
value|(0x200 + 68)
end_define

begin_comment
comment|/* Chip ID2 Register */
end_comment

begin_define
define|#
directive|define
name|DBGU_FNTR
value|(0x200 + 72)
end_define

begin_comment
comment|/* Force NTRST Register */
end_comment

begin_define
define|#
directive|define
name|PIOA_PER
value|(0x400)
end_define

begin_comment
comment|/* PIO Enable Register */
end_comment

begin_define
define|#
directive|define
name|PIOA_PDR
value|(0x400 + 4)
end_define

begin_comment
comment|/* PIO Disable Register */
end_comment

begin_define
define|#
directive|define
name|PIOA_PSR
value|(0x400 + 8)
end_define

begin_comment
comment|/* PIO status register */
end_comment

begin_define
define|#
directive|define
name|PIOA_OER
value|(0x400 + 16)
end_define

begin_comment
comment|/* Output enable register */
end_comment

begin_define
define|#
directive|define
name|PIOA_ODR
value|(0x400 + 20)
end_define

begin_comment
comment|/* Output disable register */
end_comment

begin_define
define|#
directive|define
name|PIOA_OSR
value|(0x400 + 24)
end_define

begin_comment
comment|/* Output status register */
end_comment

begin_define
define|#
directive|define
name|PIOA_IFER
value|(0x400 + 32)
end_define

begin_comment
comment|/* Input filter enable register */
end_comment

begin_define
define|#
directive|define
name|PIOA_IFDR
value|(0x400 + 36)
end_define

begin_comment
comment|/* Input filter disable register */
end_comment

begin_define
define|#
directive|define
name|PIOA_IFSR
value|(0x400 + 40)
end_define

begin_comment
comment|/* Input filter status register */
end_comment

begin_define
define|#
directive|define
name|PIOA_SODR
value|(0x400 + 48)
end_define

begin_comment
comment|/* Set output data register */
end_comment

begin_define
define|#
directive|define
name|PIOA_CODR
value|(0x400 + 52)
end_define

begin_comment
comment|/* Clear output data register */
end_comment

begin_define
define|#
directive|define
name|PIOA_ODSR
value|(0x400 + 56)
end_define

begin_comment
comment|/* Output data status register */
end_comment

begin_define
define|#
directive|define
name|PIOA_PDSR
value|(0x400 + 60)
end_define

begin_comment
comment|/* Pin data status register */
end_comment

begin_define
define|#
directive|define
name|PIOA_IER
value|(0x400 + 64)
end_define

begin_comment
comment|/* Interrupt enable register */
end_comment

begin_define
define|#
directive|define
name|PIOA_IDR
value|(0x400 + 68)
end_define

begin_comment
comment|/* Interrupt disable register */
end_comment

begin_define
define|#
directive|define
name|PIOA_IMR
value|(0x400 + 72)
end_define

begin_comment
comment|/* Interrupt mask register */
end_comment

begin_define
define|#
directive|define
name|PIOA_ISR
value|(0x400 + 76)
end_define

begin_comment
comment|/* Interrupt status register */
end_comment

begin_define
define|#
directive|define
name|PIOA_MDER
value|(0x400 + 80)
end_define

begin_comment
comment|/* Multi driver enable register */
end_comment

begin_define
define|#
directive|define
name|PIOA_MDDR
value|(0x400 + 84)
end_define

begin_comment
comment|/* Multi driver disable register */
end_comment

begin_define
define|#
directive|define
name|PIOA_MDSR
value|(0x400 + 88)
end_define

begin_comment
comment|/* Multi driver status register */
end_comment

begin_define
define|#
directive|define
name|PIOA_PPUDR
value|(0x400 + 96)
end_define

begin_comment
comment|/* Pull-up disable register */
end_comment

begin_define
define|#
directive|define
name|PIOA_PPUER
value|(0x400 + 100)
end_define

begin_comment
comment|/* Pull-up enable register */
end_comment

begin_define
define|#
directive|define
name|PIOA_PPUSR
value|(0x400 + 104)
end_define

begin_comment
comment|/* Pad pull-up status register */
end_comment

begin_define
define|#
directive|define
name|PIOA_ASR
value|(0x400 + 112)
end_define

begin_comment
comment|/* Select A register */
end_comment

begin_define
define|#
directive|define
name|PIOA_BSR
value|(0x400 + 116)
end_define

begin_comment
comment|/* Select B register */
end_comment

begin_define
define|#
directive|define
name|PIOA_ABSR
value|(0x400 + 120)
end_define

begin_comment
comment|/* AB Select status register */
end_comment

begin_define
define|#
directive|define
name|PIOA_OWER
value|(0x400 + 160)
end_define

begin_comment
comment|/* Output Write enable register */
end_comment

begin_define
define|#
directive|define
name|PIOA_OWDR
value|(0x400 + 164)
end_define

begin_comment
comment|/* Output write disable register */
end_comment

begin_define
define|#
directive|define
name|PIOA_OWSR
value|(0x400 + 168)
end_define

begin_comment
comment|/* Output write status register */
end_comment

begin_define
define|#
directive|define
name|PIOB_PER
value|(0x400)
end_define

begin_comment
comment|/* PIO Enable Register */
end_comment

begin_define
define|#
directive|define
name|PIOB_PDR
value|(0x600 + 4)
end_define

begin_comment
comment|/* PIO Disable Register */
end_comment

begin_define
define|#
directive|define
name|PIOB_PSR
value|(0x600 + 8)
end_define

begin_comment
comment|/* PIO status register */
end_comment

begin_define
define|#
directive|define
name|PIOB_OER
value|(0x600 + 16)
end_define

begin_comment
comment|/* Output enable register */
end_comment

begin_define
define|#
directive|define
name|PIOB_ODR
value|(0x600 + 20)
end_define

begin_comment
comment|/* Output disable register */
end_comment

begin_define
define|#
directive|define
name|PIOB_OSR
value|(0x600 + 24)
end_define

begin_comment
comment|/* Output status register */
end_comment

begin_define
define|#
directive|define
name|PIOB_IFER
value|(0x600 + 32)
end_define

begin_comment
comment|/* Input filter enable register */
end_comment

begin_define
define|#
directive|define
name|PIOB_IFDR
value|(0x600 + 36)
end_define

begin_comment
comment|/* Input filter disable register */
end_comment

begin_define
define|#
directive|define
name|PIOB_IFSR
value|(0x600 + 40)
end_define

begin_comment
comment|/* Input filter status register */
end_comment

begin_define
define|#
directive|define
name|PIOB_SODR
value|(0x600 + 48)
end_define

begin_comment
comment|/* Set output data register */
end_comment

begin_define
define|#
directive|define
name|PIOB_CODR
value|(0x600 + 52)
end_define

begin_comment
comment|/* Clear output data register */
end_comment

begin_define
define|#
directive|define
name|PIOB_ODSR
value|(0x600 + 56)
end_define

begin_comment
comment|/* Output data status register */
end_comment

begin_define
define|#
directive|define
name|PIOB_PDSR
value|(0x600 + 60)
end_define

begin_comment
comment|/* Pin data status register */
end_comment

begin_define
define|#
directive|define
name|PIOB_IER
value|(0x600 + 64)
end_define

begin_comment
comment|/* Interrupt enable register */
end_comment

begin_define
define|#
directive|define
name|PIOB_IDR
value|(0x600 + 68)
end_define

begin_comment
comment|/* Interrupt disable register */
end_comment

begin_define
define|#
directive|define
name|PIOB_IMR
value|(0x600 + 72)
end_define

begin_comment
comment|/* Interrupt mask register */
end_comment

begin_define
define|#
directive|define
name|PIOB_ISR
value|(0x600 + 76)
end_define

begin_comment
comment|/* Interrupt status register */
end_comment

begin_define
define|#
directive|define
name|PIOB_MDER
value|(0x600 + 80)
end_define

begin_comment
comment|/* Multi driver enable register */
end_comment

begin_define
define|#
directive|define
name|PIOB_MDDR
value|(0x600 + 84)
end_define

begin_comment
comment|/* Multi driver disable register */
end_comment

begin_define
define|#
directive|define
name|PIOB_MDSR
value|(0x600 + 88)
end_define

begin_comment
comment|/* Multi driver status register */
end_comment

begin_define
define|#
directive|define
name|PIOB_PPUDR
value|(0x600 + 96)
end_define

begin_comment
comment|/* Pull-up disable register */
end_comment

begin_define
define|#
directive|define
name|PIOB_PPUER
value|(0x600 + 100)
end_define

begin_comment
comment|/* Pull-up enable register */
end_comment

begin_define
define|#
directive|define
name|PIOB_PPUSR
value|(0x600 + 104)
end_define

begin_comment
comment|/* Pad pull-up status register */
end_comment

begin_define
define|#
directive|define
name|PIOB_ASR
value|(0x600 + 112)
end_define

begin_comment
comment|/* Select A register */
end_comment

begin_define
define|#
directive|define
name|PIOB_BSR
value|(0x600 + 116)
end_define

begin_comment
comment|/* Select B register */
end_comment

begin_define
define|#
directive|define
name|PIOB_ABSR
value|(0x600 + 120)
end_define

begin_comment
comment|/* AB Select status register */
end_comment

begin_define
define|#
directive|define
name|PIOB_OWER
value|(0x600 + 160)
end_define

begin_comment
comment|/* Output Write enable register */
end_comment

begin_define
define|#
directive|define
name|PIOB_OWDR
value|(0x600 + 164)
end_define

begin_comment
comment|/* Output write disable register */
end_comment

begin_define
define|#
directive|define
name|PIOB_OWSR
value|(0x600 + 168)
end_define

begin_comment
comment|/* Output write status register */
end_comment

begin_define
define|#
directive|define
name|PIOC_PER
value|(0x800)
end_define

begin_comment
comment|/* PIO Enable Register */
end_comment

begin_define
define|#
directive|define
name|PIOC_PDR
value|(0x800 + 4)
end_define

begin_comment
comment|/* PIO Disable Register */
end_comment

begin_define
define|#
directive|define
name|PIOC_PSR
value|(0x800 + 8)
end_define

begin_comment
comment|/* PIO status register */
end_comment

begin_define
define|#
directive|define
name|PIOC_OER
value|(0x800 + 16)
end_define

begin_comment
comment|/* Output enable register */
end_comment

begin_define
define|#
directive|define
name|PIOC_ODR
value|(0x800 + 20)
end_define

begin_comment
comment|/* Output disable register */
end_comment

begin_define
define|#
directive|define
name|PIOC_OSR
value|(0x800 + 24)
end_define

begin_comment
comment|/* Output status register */
end_comment

begin_define
define|#
directive|define
name|PIOC_IFER
value|(0x800 + 32)
end_define

begin_comment
comment|/* Input filter enable register */
end_comment

begin_define
define|#
directive|define
name|PIOC_IFDR
value|(0x800 + 36)
end_define

begin_comment
comment|/* Input filter disable register */
end_comment

begin_define
define|#
directive|define
name|PIOC_IFSR
value|(0x800 + 40)
end_define

begin_comment
comment|/* Input filter status register */
end_comment

begin_define
define|#
directive|define
name|PIOC_SODR
value|(0x800 + 48)
end_define

begin_comment
comment|/* Set output data register */
end_comment

begin_define
define|#
directive|define
name|PIOC_CODR
value|(0x800 + 52)
end_define

begin_comment
comment|/* Clear output data register */
end_comment

begin_define
define|#
directive|define
name|PIOC_ODSR
value|(0x800 + 56)
end_define

begin_comment
comment|/* Output data status register */
end_comment

begin_define
define|#
directive|define
name|PIOC_PDSR
value|(0x800 + 60)
end_define

begin_comment
comment|/* Pin data status register */
end_comment

begin_define
define|#
directive|define
name|PIOC_IER
value|(0x800 + 64)
end_define

begin_comment
comment|/* Interrupt enable register */
end_comment

begin_define
define|#
directive|define
name|PIOC_IDR
value|(0x800 + 68)
end_define

begin_comment
comment|/* Interrupt disable register */
end_comment

begin_define
define|#
directive|define
name|PIOC_IMR
value|(0x800 + 72)
end_define

begin_comment
comment|/* Interrupt mask register */
end_comment

begin_define
define|#
directive|define
name|PIOC_ISR
value|(0x800 + 76)
end_define

begin_comment
comment|/* Interrupt status register */
end_comment

begin_define
define|#
directive|define
name|PIOC_MDER
value|(0x800 + 80)
end_define

begin_comment
comment|/* Multi driver enable register */
end_comment

begin_define
define|#
directive|define
name|PIOC_MDDR
value|(0x800 + 84)
end_define

begin_comment
comment|/* Multi driver disable register */
end_comment

begin_define
define|#
directive|define
name|PIOC_MDSR
value|(0x800 + 88)
end_define

begin_comment
comment|/* Multi driver status register */
end_comment

begin_define
define|#
directive|define
name|PIOC_PPUDR
value|(0x800 + 96)
end_define

begin_comment
comment|/* Pull-up disable register */
end_comment

begin_define
define|#
directive|define
name|PIOC_PPUER
value|(0x800 + 100)
end_define

begin_comment
comment|/* Pull-up enable register */
end_comment

begin_define
define|#
directive|define
name|PIOC_PPUSR
value|(0x800 + 104)
end_define

begin_comment
comment|/* Pad pull-up status register */
end_comment

begin_define
define|#
directive|define
name|PIOC_ASR
value|(0x800 + 112)
end_define

begin_comment
comment|/* Select A register */
end_comment

begin_define
define|#
directive|define
name|PIOC_BSR
value|(0x800 + 116)
end_define

begin_comment
comment|/* Select B register */
end_comment

begin_define
define|#
directive|define
name|PIOC_ABSR
value|(0x800 + 120)
end_define

begin_comment
comment|/* AB Select status register */
end_comment

begin_define
define|#
directive|define
name|PIOC_OWER
value|(0x800 + 160)
end_define

begin_comment
comment|/* Output Write enable register */
end_comment

begin_define
define|#
directive|define
name|PIOC_OWDR
value|(0x800 + 164)
end_define

begin_comment
comment|/* Output write disable register */
end_comment

begin_define
define|#
directive|define
name|PIOC_OWSR
value|(0x800 + 168)
end_define

begin_comment
comment|/* Output write status register */
end_comment

begin_define
define|#
directive|define
name|PIOD_PER
value|(0xa00)
end_define

begin_comment
comment|/* PIO Enable Register */
end_comment

begin_define
define|#
directive|define
name|PIOD_PDR
value|(0xa00 + 4)
end_define

begin_comment
comment|/* PIO Disable Register */
end_comment

begin_define
define|#
directive|define
name|PIOD_PSR
value|(0xa00 + 8)
end_define

begin_comment
comment|/* PIO status register */
end_comment

begin_define
define|#
directive|define
name|PIOD_OER
value|(0xa00 + 16)
end_define

begin_comment
comment|/* Output enable register */
end_comment

begin_define
define|#
directive|define
name|PIOD_ODR
value|(0xa00 + 20)
end_define

begin_comment
comment|/* Output disable register */
end_comment

begin_define
define|#
directive|define
name|PIOD_OSR
value|(0xa00 + 24)
end_define

begin_comment
comment|/* Output status register */
end_comment

begin_define
define|#
directive|define
name|PIOD_IFER
value|(0xa00 + 32)
end_define

begin_comment
comment|/* Input filter enable register */
end_comment

begin_define
define|#
directive|define
name|PIOD_IFDR
value|(0xa00 + 36)
end_define

begin_comment
comment|/* Input filter disable register */
end_comment

begin_define
define|#
directive|define
name|PIOD_IFSR
value|(0xa00 + 40)
end_define

begin_comment
comment|/* Input filter status register */
end_comment

begin_define
define|#
directive|define
name|PIOD_SODR
value|(0xa00 + 48)
end_define

begin_comment
comment|/* Set output data register */
end_comment

begin_define
define|#
directive|define
name|PIOD_CODR
value|(0xa00 + 52)
end_define

begin_comment
comment|/* Clear output data register */
end_comment

begin_define
define|#
directive|define
name|PIOD_ODSR
value|(0xa00 + 56)
end_define

begin_comment
comment|/* Output data status register */
end_comment

begin_define
define|#
directive|define
name|PIOD_PDSR
value|(0xa00 + 60)
end_define

begin_comment
comment|/* Pin data status register */
end_comment

begin_define
define|#
directive|define
name|PIOD_IER
value|(0xa00 + 64)
end_define

begin_comment
comment|/* Interrupt enable register */
end_comment

begin_define
define|#
directive|define
name|PIOD_IDR
value|(0xa00 + 68)
end_define

begin_comment
comment|/* Interrupt disable register */
end_comment

begin_define
define|#
directive|define
name|PIOD_IMR
value|(0xa00 + 72)
end_define

begin_comment
comment|/* Interrupt mask register */
end_comment

begin_define
define|#
directive|define
name|PIOD_ISR
value|(0xa00 + 76)
end_define

begin_comment
comment|/* Interrupt status register */
end_comment

begin_define
define|#
directive|define
name|PIOD_MDER
value|(0xa00 + 80)
end_define

begin_comment
comment|/* Multi driver enable register */
end_comment

begin_define
define|#
directive|define
name|PIOD_MDDR
value|(0xa00 + 84)
end_define

begin_comment
comment|/* Multi driver disable register */
end_comment

begin_define
define|#
directive|define
name|PIOD_MDSR
value|(0xa00 + 88)
end_define

begin_comment
comment|/* Multi driver status register */
end_comment

begin_define
define|#
directive|define
name|PIOD_PPUDR
value|(0xa00 + 96)
end_define

begin_comment
comment|/* Pull-up disable register */
end_comment

begin_define
define|#
directive|define
name|PIOD_PPUER
value|(0xa00 + 100)
end_define

begin_comment
comment|/* Pull-up enable register */
end_comment

begin_define
define|#
directive|define
name|PIOD_PPUSR
value|(0xa00 + 104)
end_define

begin_comment
comment|/* Pad pull-up status register */
end_comment

begin_define
define|#
directive|define
name|PIOD_ASR
value|(0xa00 + 112)
end_define

begin_comment
comment|/* Select A register */
end_comment

begin_define
define|#
directive|define
name|PIOD_BSR
value|(0xa00 + 116)
end_define

begin_comment
comment|/* Select B register */
end_comment

begin_define
define|#
directive|define
name|PIOD_ABSR
value|(0xa00 + 120)
end_define

begin_comment
comment|/* AB Select status register */
end_comment

begin_define
define|#
directive|define
name|PIOD_OWER
value|(0xa00 + 160)
end_define

begin_comment
comment|/* Output Write enable register */
end_comment

begin_define
define|#
directive|define
name|PIOD_OWDR
value|(0xa00 + 164)
end_define

begin_comment
comment|/* Output write disable register */
end_comment

begin_define
define|#
directive|define
name|PIOD_OWSR
value|(0xa00 + 168)
end_define

begin_comment
comment|/* Output write status register */
end_comment

begin_comment
comment|/* IRQs : */
end_comment

begin_comment
comment|/*  * 0: AIC   * 1: System peripheral (System timer, RTC, DBGU)  * 2: PIO Controller A  * 3: PIO Controller B  * 4: PIO Controller C  * 5: PIO Controller D  * 6: USART 0  * 7: USART 1  * 8: USART 2  * 9: USART 3  * 10: MMC Interface  * 11: USB device port  * 12: Two-wirte interface  * 13: SPI  * 14: SSC  * 15: SSC  * 16: SSC  * 17: Timer Counter 0  * 18: Timer Counter 1  * 19: Timer Counter 2  * 20: Timer Counter 3  * 21: Timer Counter 4  * 22: Timer Counter 6  * 23: USB Host port  * 24: Ethernet  * 25: AIC  * 26: AIC  * 27: AIC  * 28: AIC  * 29: AIC  * 30: AIC  * 31: AIC  */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_IRQ_SYSTEM
value|1
end_define

begin_define
define|#
directive|define
name|AT91RM92_IRQ_PIOA
value|2
end_define

begin_define
define|#
directive|define
name|AT91RM92_IRQ_PIOB
value|3
end_define

begin_define
define|#
directive|define
name|AT91RM92_IRQ_PIOC
value|4
end_define

begin_define
define|#
directive|define
name|AT91RM92_IRQ_PIOD
value|5
end_define

begin_define
define|#
directive|define
name|AT91RM92_IRQ_USART0
value|6
end_define

begin_define
define|#
directive|define
name|AT91RM92_IRQ_USART1
value|7
end_define

begin_define
define|#
directive|define
name|AT91RM92_IRQ_USART2
value|8
end_define

begin_define
define|#
directive|define
name|AT91RM92_IRQ_USART3
value|9
end_define

begin_define
define|#
directive|define
name|AT91RM92_IRQ_MCI
value|10
end_define

begin_define
define|#
directive|define
name|AT91RM92_IRQ_UDP
value|11
end_define

begin_define
define|#
directive|define
name|AT91RM92_IRQ_TWI
value|12
end_define

begin_define
define|#
directive|define
name|AT91RM92_IRQ_SPI
value|13
end_define

begin_define
define|#
directive|define
name|AT91RM92_IRQ_SSC0
value|14
end_define

begin_define
define|#
directive|define
name|AT91RM92_IRQ_SSC1
value|15
end_define

begin_define
define|#
directive|define
name|AT91RM92_IRQ_SSC2
value|16
end_define

begin_define
define|#
directive|define
name|AT91RM92_IRQ_TC0
value|17
end_define

begin_define
define|#
directive|define
name|AT91RM92_IRQ_TC1
value|18
end_define

begin_define
define|#
directive|define
name|AT91RM92_IRQ_TC2
value|19
end_define

begin_define
define|#
directive|define
name|AT91RM92_IRQ_TC3
value|20
end_define

begin_define
define|#
directive|define
name|AT91RM92_IRQ_TC4
value|21
end_define

begin_define
define|#
directive|define
name|AT91RM92_IRQ_TC5
value|22
end_define

begin_define
define|#
directive|define
name|AT91RM92_IRQ_UHP
value|23
end_define

begin_define
define|#
directive|define
name|AT91RM92_IRQ_EMAC
value|24
end_define

begin_define
define|#
directive|define
name|AT91RM92_IRQ_AIC_BASE
value|25
end_define

begin_comment
comment|/* Timer */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_ST_BASE
value|0xffffd00
end_define

begin_define
define|#
directive|define
name|AT91RM92_ST_SIZE
value|0x100
end_define

begin_define
define|#
directive|define
name|AT91RM92_SPI_BASE
value|0xffe0000
end_define

begin_define
define|#
directive|define
name|AT91RM92_SPI_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AT91RM92_SPI_PDC
value|0xffe0100
end_define

begin_define
define|#
directive|define
name|AT91RM92_SSC0_BASE
value|0xffd0000
end_define

begin_define
define|#
directive|define
name|AT91RM92_SSC0_PDC
value|0xffd0100
end_define

begin_define
define|#
directive|define
name|AT91RM92_SSC1_BASE
value|0xffd4000
end_define

begin_define
define|#
directive|define
name|AT91RM92_SSC1_PDC
value|0xffd4100
end_define

begin_define
define|#
directive|define
name|AT91RM92_SSC2_BASE
value|0xffd8000
end_define

begin_define
define|#
directive|define
name|AT91RM92_SSC2_PDC
value|0xffd8100
end_define

begin_define
define|#
directive|define
name|AT91RM92_SSC_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AT91RM92_EMAC_BASE
value|0xffbc000
end_define

begin_define
define|#
directive|define
name|AT91RM92_EMAC_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AT91RM92_TWI_BASE
value|0xffb8000
end_define

begin_define
define|#
directive|define
name|AT91RM92_TWI_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AT91RM92_MCI_BASE
value|0xffb4000
end_define

begin_define
define|#
directive|define
name|AT91RM92_MCI_PDC
value|0xffb4100
end_define

begin_define
define|#
directive|define
name|AT91RM92_MCI_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AT91RM92_UDP_BASE
value|0xffb0000
end_define

begin_define
define|#
directive|define
name|AT91RM92_UDP_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AT91RM92_TC0_BASE
value|0xffa0000
end_define

begin_define
define|#
directive|define
name|AT91RM92_TC0_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AT91RM92_TC0C0_BASE
value|0xffa0000
end_define

begin_define
define|#
directive|define
name|AT91RM92_TC0C1_BASE
value|0xffa0040
end_define

begin_define
define|#
directive|define
name|AT91RM92_TC0C2_BASE
value|0xffa0080
end_define

begin_define
define|#
directive|define
name|AT91RM92_TC1_BASE
value|0xffa4000
end_define

begin_define
define|#
directive|define
name|AT91RM92_TC1_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AT91RM92_TC1C0_BASE
value|0xffa4000
end_define

begin_define
define|#
directive|define
name|AT91RM92_TC1C1_BASE
value|0xffa4040
end_define

begin_define
define|#
directive|define
name|AT91RM92_TC1C2_BASE
value|0xffa4080
end_define

begin_define
define|#
directive|define
name|AT91RM92_OHCI_BASE
value|0x00300000
end_define

begin_define
define|#
directive|define
name|AT91RM92_OHCI_SIZE
value|0x00100000
end_define

begin_comment
comment|/* Pio definitions */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PA0
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PA0_MISO
value|(AT91RM92_PIO_PA0)
end_define

begin_comment
comment|/* SPI Master In Slave */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PA0_PCK3
value|(AT91RM92_PIO_PA0)
end_define

begin_comment
comment|/* PMC Programmable Clock Output 3 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PA1
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PA1_MOSI
value|(AT91RM92_PIO_PA1)
end_define

begin_comment
comment|/* SPI Master Out Slave */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PA1_PCK0
value|(AT91RM92_PIO_PA1)
end_define

begin_comment
comment|/* PMC Programmable Clock Output 0 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PA2
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PA2_SPCK
value|(AT91RM92_PIO_PA2)
end_define

begin_comment
comment|/* SPI Serial Clock */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PA2_IRQ4
value|(AT91RM92_PIO_PA2)
end_define

begin_comment
comment|/* AIC Interrupt Input 4 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PA3
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PA3_NPCS0
value|(AT91RM92_PIO_PA3)
end_define

begin_comment
comment|/* SPI Peripheral Chip Select 0 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PA3_IRQ5
value|(AT91RM92_PIO_PA3)
end_define

begin_comment
comment|/* AIC Interrupt Input 5 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PA4
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PA4_NPCS1
value|(AT91RM92_PIO_PA4)
end_define

begin_comment
comment|/* SPI Peripheral Chip Select 1 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PA4_PCK1
value|(AT91RM92_PIO_PA4)
end_define

begin_comment
comment|/* PMC Programmable Clock Output 1 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PA5
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PA5_NPCS2
value|(AT91RM92_PIO_PA5)
end_define

begin_comment
comment|/* SPI Peripheral Chip Select 2 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PA5_TXD3
value|(AT91RM92_PIO_PA5)
end_define

begin_comment
comment|/* USART 3 Transmit Data */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PA6
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PA6_NPCS3
value|(AT91RM92_PIO_PA6)
end_define

begin_comment
comment|/* SPI Peripheral Chip Select 3 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PA6_RXD3
value|(AT91RM92_PIO_PA6)
end_define

begin_comment
comment|/* USART 3 Receive Data */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PA7
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PA7_ETXCK_EREFC
value|(AT91RM92_PIO_PA7)
end_define

begin_comment
comment|/* Ethernet MAC Transmit Clock/Reference Clock */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PA7_PCK2
value|(AT91RM92_PIO_PA7)
end_define

begin_comment
comment|/* PMC Programmable Clock 2 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PA8
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PA8_ETXEN
value|(AT91RM92_PIO_PA8)
end_define

begin_comment
comment|/* Ethernet MAC Transmit Enable */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PA8_MCCDB
value|(AT91RM92_PIO_PA8)
end_define

begin_comment
comment|/* Multimedia Card B Command */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PA9
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PA9_ETX0
value|(AT91RM92_PIO_PA9)
end_define

begin_comment
comment|/* Ethernet MAC Transmit Data 0 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PA9_MCDB0
value|(AT91RM92_PIO_PA9)
end_define

begin_comment
comment|/* Multimedia Card B Data 0 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PA10
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PA10_ETX1
value|(AT91RM92_PIO_PA10)
end_define

begin_comment
comment|/* Ethernet MAC Transmit Data 1 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PA10_MCDB1
value|(AT91RM92_PIO_PA10)
end_define

begin_comment
comment|/* Multimedia Card B Data 1 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PA11
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PA11_ECRS_ECRSDV
value|(AT91RM92_PIO_PA11)
end_define

begin_comment
comment|/* Ethernet MAC Carrier Sense/Carrier Sense and Data Valid */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PA11_MCDB2
value|(AT91RM92_PIO_PA11)
end_define

begin_comment
comment|/* Multimedia Card B Data 2 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PA12
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PA12_ERX0
value|(AT91RM92_PIO_PA12)
end_define

begin_comment
comment|/* Ethernet MAC Receive Data 0 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PA12_MCDB3
value|(AT91RM92_PIO_PA12)
end_define

begin_comment
comment|/* Multimedia Card B Data 3 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PA13
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PA13_ERX1
value|(AT91RM92_PIO_PA13)
end_define

begin_comment
comment|/* Ethernet MAC Receive Data 1 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PA13_TCLK0
value|(AT91RM92_PIO_PA13)
end_define

begin_comment
comment|/* Timer Counter 0 external clock input */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PA14
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PA14_ERXER
value|(AT91RM92_PIO_PA14)
end_define

begin_comment
comment|/* Ethernet MAC Receive Error */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PA14_TCLK1
value|(AT91RM92_PIO_PA14)
end_define

begin_comment
comment|/* Timer Counter 1 external clock input */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PA15
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PA15_EMDC
value|(AT91RM92_PIO_PA15)
end_define

begin_comment
comment|/* Ethernet MAC Management Data Clock */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PA15_TCLK2
value|(AT91RM92_PIO_PA15)
end_define

begin_comment
comment|/* Timer Counter 2 external clock input */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PA16
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PA16_EMDIO
value|(AT91RM92_PIO_PA16)
end_define

begin_comment
comment|/* Ethernet MAC Management Data Input/Output */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PA16_IRQ6
value|(AT91RM92_PIO_PA16)
end_define

begin_comment
comment|/* AIC Interrupt input 6 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PA17
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PA17_TXD0
value|(AT91RM92_PIO_PA17)
end_define

begin_comment
comment|/* USART 0 Transmit Data */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PA17_TIOA0
value|(AT91RM92_PIO_PA17)
end_define

begin_comment
comment|/* Timer Counter 0 Multipurpose Timer I/O Pin A */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PA18
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PA18_RXD0
value|(AT91RM92_PIO_PA18)
end_define

begin_comment
comment|/* USART 0 Receive Data */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PA18_TIOB0
value|(AT91RM92_PIO_PA18)
end_define

begin_comment
comment|/* Timer Counter 0 Multipurpose Timer I/O Pin B */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PA19
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PA19_SCK0
value|(AT91RM92_PIO_PA19)
end_define

begin_comment
comment|/* USART 0 Serial Clock */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PA19_TIOA1
value|(AT91RM92_PIO_PA19)
end_define

begin_comment
comment|/* Timer Counter 1 Multipurpose Timer I/O Pin A */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PA20
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PA20_CTS0
value|(AT91RM92_PIO_PA20)
end_define

begin_comment
comment|/* USART 0 Clear To Send */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PA20_TIOB1
value|(AT91RM92_PIO_PA20)
end_define

begin_comment
comment|/* Timer Counter 1 Multipurpose Timer I/O Pin B */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PA21
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PA21_RTS0
value|(AT91RM92_PIO_PA21)
end_define

begin_comment
comment|/* USART 0 Ready To Send */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PA21_TIOA2
value|(AT91RM92_PIO_PA21)
end_define

begin_comment
comment|/* Timer Counter 2 Multipurpose Timer I/O Pin A */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PA22
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PA22_RXD2
value|(AT91RM92_PIO_PA22)
end_define

begin_comment
comment|/* USART 2 Receive Data */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PA22_TIOB2
value|(AT91RM92_PIO_PA22)
end_define

begin_comment
comment|/* Timer Counter 2 Multipurpose Timer I/O Pin B */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PA23
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PA23_TXD2
value|(AT91RM92_PIO_PA23)
end_define

begin_comment
comment|/* USART 2 Transmit Data */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PA23_IRQ3
value|(AT91RM92_PIO_PA23)
end_define

begin_comment
comment|/* Interrupt input 3 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PA24
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PA24_SCK2
value|(AT91RM92_PIO_PA24)
end_define

begin_comment
comment|/* USART 2 Serial Clock */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PA24_PCK1
value|(AT91RM92_PIO_PA24)
end_define

begin_comment
comment|/* PMC Programmable Clock Output 1 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PA25
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PA25_TWD
value|(AT91RM92_PIO_PA25)
end_define

begin_comment
comment|/* TWI Two-wire Serial Data */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PA25_IRQ2
value|(AT91RM92_PIO_PA25)
end_define

begin_comment
comment|/* Interrupt input 2 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PA26
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PA26_TWCK
value|(AT91RM92_PIO_PA26)
end_define

begin_comment
comment|/* TWI Two-wire Serial Clock */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PA26_IRQ1
value|(AT91RM92_PIO_PA26)
end_define

begin_comment
comment|/* Interrupt input 1 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PA27
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PA27_MCCK
value|(AT91RM92_PIO_PA27)
end_define

begin_comment
comment|/* Multimedia Card Clock */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PA27_TCLK3
value|(AT91RM92_PIO_PA27)
end_define

begin_comment
comment|/* Timer Counter 3 External Clock Input */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PA28
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PA28_MCCDA
value|(AT91RM92_PIO_PA28)
end_define

begin_comment
comment|/* Multimedia Card A Command */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PA28_TCLK4
value|(AT91RM92_PIO_PA28)
end_define

begin_comment
comment|/* Timer Counter 4 external Clock Input */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PA29
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PA29_MCDA0
value|(AT91RM92_PIO_PA29)
end_define

begin_comment
comment|/* Multimedia Card A Data 0 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PA29_TCLK5
value|(AT91RM92_PIO_PA29)
end_define

begin_comment
comment|/* Timer Counter 5 external clock input */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PA30
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PA30_DRXD
value|(AT91RM92_PIO_PA30)
end_define

begin_comment
comment|/* DBGU Debug Receive Data */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PA30_CTS2
value|(AT91RM92_PIO_PA30)
end_define

begin_comment
comment|/* USART 2 Clear To Send */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PA31
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PA31_DTXD
value|(AT91RM92_PIO_PA31)
end_define

begin_comment
comment|/* DBGU Debug Transmit Data */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PA31_RTS2
value|(AT91RM92_PIO_PA31)
end_define

begin_comment
comment|/* USART 2 Ready To Send */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PB0
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PB0_TF0
value|(AT91RM92_PIO_PB0)
end_define

begin_comment
comment|/* SSC Transmit Frame Sync 0 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PB0_RTS3
value|(AT91RM92_PIO_PB0)
end_define

begin_comment
comment|/* USART 3 Ready To Send */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PB1
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PB1_TK0
value|(AT91RM92_PIO_PB1)
end_define

begin_comment
comment|/* SSC Transmit Clock 0 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PB1_CTS3
value|(AT91RM92_PIO_PB1)
end_define

begin_comment
comment|/* USART 3 Clear To Send */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PB2
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PB2_TD0
value|(AT91RM92_PIO_PB2)
end_define

begin_comment
comment|/* SSC Transmit data */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PB2_SCK3
value|(AT91RM92_PIO_PB2)
end_define

begin_comment
comment|/* USART 3 Serial Clock */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PB3
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PB3_RD0
value|(AT91RM92_PIO_PB3)
end_define

begin_comment
comment|/* SSC Receive Data */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PB3_MCDA1
value|(AT91RM92_PIO_PB3)
end_define

begin_comment
comment|/* Multimedia Card A Data 1 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PB4
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PB4_RK0
value|(AT91RM92_PIO_PB4)
end_define

begin_comment
comment|/* SSC Receive Clock */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PB4_MCDA2
value|(AT91RM92_PIO_PB4)
end_define

begin_comment
comment|/* Multimedia Card A Data 2 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PB5
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PB5_RF0
value|(AT91RM92_PIO_PB5)
end_define

begin_comment
comment|/* SSC Receive Frame Sync 0 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PB5_MCDA3
value|(AT91RM92_PIO_PB5)
end_define

begin_comment
comment|/* Multimedia Card A Data 3 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PB6
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PB6_TF1
value|(AT91RM92_PIO_PB6)
end_define

begin_comment
comment|/* SSC Transmit Frame Sync 1 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PB6_TIOA3
value|(AT91RM92_PIO_PB6)
end_define

begin_comment
comment|/* Timer Counter 4 Multipurpose Timer I/O Pin A */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PB7
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PB7_TK1
value|(AT91RM92_PIO_PB7)
end_define

begin_comment
comment|/* SSC Transmit Clock 1 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PB7_TIOB3
value|(AT91RM92_PIO_PB7)
end_define

begin_comment
comment|/* Timer Counter 3 Multipurpose Timer I/O Pin B */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PB8
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PB8_TD1
value|(AT91RM92_PIO_PB8)
end_define

begin_comment
comment|/* SSC Transmit Data 1 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PB8_TIOA4
value|(AT91RM92_PIO_PB8)
end_define

begin_comment
comment|/* Timer Counter 4 Multipurpose Timer I/O Pin A */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PB9
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PB9_RD1
value|(AT91RM92_PIO_PB9)
end_define

begin_comment
comment|/* SSC Receive Data 1 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PB9_TIOB4
value|(AT91RM92_PIO_PB9)
end_define

begin_comment
comment|/* Timer Counter 4 Multipurpose Timer I/O Pin B */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PB10
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PB10_RK1
value|(AT91RM92_PIO_PB10)
end_define

begin_comment
comment|/* SSC Receive Clock 1 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PB10_TIOA5
value|(AT91RM92_PIO_PB10)
end_define

begin_comment
comment|/* Timer Counter 5 Multipurpose Timer I/O Pin A */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PB11
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PB11_RF1
value|(AT91RM92_PIO_PB11)
end_define

begin_comment
comment|/* SSC Receive Frame Sync 1 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PB11_TIOB5
value|(AT91RM92_PIO_PB11)
end_define

begin_comment
comment|/* Timer Counter 5 Multipurpose Timer I/O Pin B */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PB12
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PB12_TF2
value|(AT91RM92_PIO_PB12)
end_define

begin_comment
comment|/* SSC Transmit Frame Sync 2 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PB12_ETX2
value|(AT91RM92_PIO_PB12)
end_define

begin_comment
comment|/* Ethernet MAC Transmit Data 2 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PB13
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PB13_TK2
value|(AT91RM92_PIO_PB13)
end_define

begin_comment
comment|/* SSC Transmit Clock 2 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PB13_ETX3
value|(AT91RM92_PIO_PB13)
end_define

begin_comment
comment|/* Ethernet MAC Transmit Data 3 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PB14
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PB14_TD2
value|(AT91RM92_PIO_PB14)
end_define

begin_comment
comment|/* SSC Transmit Data 2 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PB14_ETXER
value|(AT91RM92_PIO_PB14)
end_define

begin_comment
comment|/* Ethernet MAC Transmikt Coding Error */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PB15
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PB15_RD2
value|(AT91RM92_PIO_PB15)
end_define

begin_comment
comment|/* SSC Receive Data 2 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PB15_ERX2
value|(AT91RM92_PIO_PB15)
end_define

begin_comment
comment|/* Ethernet MAC Receive Data 2 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PB16
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PB16_RK2
value|(AT91RM92_PIO_PB16)
end_define

begin_comment
comment|/* SSC Receive Clock 2 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PB16_ERX3
value|(AT91RM92_PIO_PB16)
end_define

begin_comment
comment|/* Ethernet MAC Receive Data 3 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PB17
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PB17_RF2
value|(AT91RM92_PIO_PB17)
end_define

begin_comment
comment|/* SSC Receive Frame Sync 2 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PB17_ERXDV
value|(AT91RM92_PIO_PB17)
end_define

begin_comment
comment|/* Ethernet MAC Receive Data Valid */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PB18
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PB18_RI1
value|(AT91RM92_PIO_PB18)
end_define

begin_comment
comment|/* USART 1 Ring Indicator */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PB18_ECOL
value|(AT91RM92_PIO_PB18)
end_define

begin_comment
comment|/* Ethernet MAC Collision Detected */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PB19
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PB19_DTR1
value|(AT91RM92_PIO_PB19)
end_define

begin_comment
comment|/* USART 1 Data Terminal ready */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PB19_ERXCK
value|(AT91RM92_PIO_PB19)
end_define

begin_comment
comment|/* Ethernet MAC Receive Clock */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PB20
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PB20_TXD1
value|(AT91RM92_PIO_PB20)
end_define

begin_comment
comment|/* USART 1 Transmit Data */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PB21
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PB21_RXD1
value|(AT91RM92_PIO_PB21)
end_define

begin_comment
comment|/* USART 1 Receive Data */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PB22
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PB22_SCK1
value|(AT91RM92_PIO_PB22)
end_define

begin_comment
comment|/* USART 1 Serial Clock */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PB23
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PB23_DCD1
value|(AT91RM92_PIO_PB23)
end_define

begin_comment
comment|/* USART 1 Data Carrier Detect */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PB24
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PB24_CTS1
value|(AT91RM92_PIO_PB24)
end_define

begin_comment
comment|/* USART 1 Clear To Send */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PB25
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PB25_DSR1
value|(AT91RM92_PIO_PB25)
end_define

begin_comment
comment|/* USART 1 Data Set ready */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PB25_EF100
value|(AT91RM92_PIO_PB25)
end_define

begin_comment
comment|/* Ethernet MAC Force 100 Mbits/sec */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PB26
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PB26_RTS1
value|(AT91RM92_PIO_PB26)
end_define

begin_comment
comment|/* USART 1 Ready To Send */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PB27
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PB27_PCK0
value|(AT91RM92_PIO_PB27)
end_define

begin_comment
comment|/* PMC Programmable Clock Output 0 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PB28
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PB28_FIQ
value|(AT91RM92_PIO_PB28)
end_define

begin_comment
comment|/* AIC Fast Interrupt Input */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PB29
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PB29_IRQ0
value|(AT91RM92_PIO_PB29)
end_define

begin_comment
comment|/* Interrupt input 0 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PC0
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PC0_BFCK
value|(AT91RM92_PIO_PC0)
end_define

begin_comment
comment|/* Burst Flash Clock */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PC1
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PC1_BFRDY_SMOE
value|(AT91RM92_PIO_PC1)
end_define

begin_comment
comment|/* Burst Flash Ready */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PC2
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PC2_BFAVD
value|(AT91RM92_PIO_PC2)
end_define

begin_comment
comment|/* Burst Flash Address Valid */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PC3
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PC3_BFBAA_SMWE
value|(AT91RM92_PIO_PC3)
end_define

begin_comment
comment|/* Burst Flash Address Advance / SmartMedia Write Enable */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PC4
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PC4_BFOE
value|(AT91RM92_PIO_PC4)
end_define

begin_comment
comment|/* Burst Flash Output Enable */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PC5
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PC5_BFWE
value|(AT91RM92_PIO_PC5)
end_define

begin_comment
comment|/* Burst Flash Write Enable */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PC6
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PC6_NWAIT
value|(AT91RM92_PIO_PC6)
end_define

begin_comment
comment|/* NWAIT */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PC7
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PC7_A23
value|(AT91RM92_PIO_PC7)
end_define

begin_comment
comment|/* Address Bus[23] */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PC8
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PC8_A24
value|(AT91RM92_PIO_PC8)
end_define

begin_comment
comment|/* Address Bus[24] */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PC9
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PC9_A25_CFRNW
value|(AT91RM92_PIO_PC9)
end_define

begin_comment
comment|/* Address Bus[25] /  Compact Flash Read Not Write */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PC10
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PC10_NCS4_CFCS
value|(AT91RM92_PIO_PC10)
end_define

begin_comment
comment|/* Compact Flash Chip Select */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PC11
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PC11_NCS5_CFCE1
value|(AT91RM92_PIO_PC11)
end_define

begin_comment
comment|/* Chip Select 5 / Compact Flash Chip Enable 1 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PC12
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PC12_NCS6_CFCE2
parameter_list|(
name|AT91RM92_PIO_PC12
parameter_list|)
end_define

begin_comment
comment|/* Chip Select 6 / Compact Flash Chip Enable 2 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PC13
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PC13_NCS7
value|(AT91RM92_PIO_PC13)
end_define

begin_comment
comment|/* Chip Select 7 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PC14
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PIO_PC15
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PIO_PC16
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PC16_D16
value|(AT91RM92_PIO_PC16)
end_define

begin_comment
comment|/* Data Bus [16] */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PC17
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PC17_D17
value|(AT91RM92_PIO_PC17)
end_define

begin_comment
comment|/* Data Bus [17] */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PC18
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PC18_D18
value|(AT91RM92_PIO_PC18)
end_define

begin_comment
comment|/* Data Bus [18] */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PC19
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PC19_D19
value|(AT91RM92_PIO_PC19)
end_define

begin_comment
comment|/* Data Bus [19] */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PC20
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PC20_D20
value|(AT91RM92_PIO_PC20)
end_define

begin_comment
comment|/* Data Bus [20] */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PC21
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PC21_D21
value|(AT91RM92_PIO_PC21)
end_define

begin_comment
comment|/* Data Bus [21] */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PC22
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PC22_D22
value|(AT91RM92_PIO_PC22)
end_define

begin_comment
comment|/* Data Bus [22] */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PC23
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PC23_D23
value|(AT91RM92_PIO_PC23)
end_define

begin_comment
comment|/* Data Bus [23] */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PC24
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PC24_D24
value|(AT91RM92_PIO_PC24)
end_define

begin_comment
comment|/* Data Bus [24] */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PC25
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PC25_D25
value|(AT91RM92_PIO_PC25)
end_define

begin_comment
comment|/* Data Bus [25] */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PC26
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PC26_D26
value|(AT91RM92_PIO_PC26)
end_define

begin_comment
comment|/* Data Bus [26] */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PC27
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PC27_D27
value|(AT91RM92_PIO_PC27)
end_define

begin_comment
comment|/* Data Bus [27] */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PC28
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PC28_D28
value|(AT91RM92_PIO_PC28)
end_define

begin_comment
comment|/* Data Bus [28] */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PC29
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PC29_D29
value|(AT91RM92_PIO_PC29)
end_define

begin_comment
comment|/* Data Bus [29] */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PC30
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PC30_D30
value|(AT91RM92_PIO_PC30)
end_define

begin_comment
comment|/* Data Bus [30] */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PC31
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PC31_D31
value|(AT91RM92_PIO_PC31)
end_define

begin_comment
comment|/* Data Bus [31] */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PD0
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PD0_ETX0
value|(AT91RM92_PIO_PD0)
end_define

begin_comment
comment|/* Ethernet MAC Transmit Data 0 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PD1
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PD1_ETX1
value|(AT91RM92_PIO_PD1)
end_define

begin_comment
comment|/* Ethernet MAC Transmit Data 1 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PD2
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PD2_ETX2
value|(AT91RM92_PIO_PD2)
end_define

begin_comment
comment|/* Ethernet MAC Transmit Data 2 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PD3
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PD3_ETX3
value|(AT91RM92_PIO_PD3)
end_define

begin_comment
comment|/* Ethernet MAC Transmit Data 3 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PD4
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PD4_ETXEN
value|(AT91RM92_PIO_PD4)
end_define

begin_comment
comment|/* Ethernet MAC Transmit Enable */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PD5
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PD5_ETXER
value|(AT91RM92_PIO_PD5)
end_define

begin_comment
comment|/* Ethernet MAC Transmit Coding Error */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PD6
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PD6_DTXD
value|(AT91RM92_PIO_PD6)
end_define

begin_comment
comment|/* DBGU Debug Transmit Data */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PD7
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PD7_PCK0
value|(AT91RM92_PIO_PD7)
end_define

begin_comment
comment|/* PMC Programmable Clock Output 0 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PD7_TSYNC
value|(AT91RM92_PIO_PD7)
end_define

begin_comment
comment|/* ETM Synchronization signal */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PD8
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PD8_PCK1
value|(AT91RM92_PIO_PD8)
end_define

begin_comment
comment|/* PMC Programmable Clock Output 1 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PD8_TCLK
value|(AT91RM92_PIO_PD8)
end_define

begin_comment
comment|/* ETM Trace Clock signal */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PD9
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PD9_PCK2
value|(AT91RM92_PIO_PD9)
end_define

begin_comment
comment|/* PMC Programmable Clock 2 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PD9_TPS0
value|(AT91RM92_PIO_PD9)
end_define

begin_comment
comment|/* ETM ARM9 pipeline status 0 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PD10
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PD10_PCK3
value|(AT91RM92_PIO_PD10)
end_define

begin_comment
comment|/* PMC Programmable Clock Output 3 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PD10_TPS1
value|(AT91RM92_PIO_PD10)
end_define

begin_comment
comment|/* ETM ARM9 pipeline status 1 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PD11
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PD11_TPS2
value|(AT91RM92_PIO_PD11)
end_define

begin_comment
comment|/* ETM ARM9 pipeline status 2 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PD12
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PD12_TPK0
value|(AT91RM92_PIO_PD12)
end_define

begin_comment
comment|/* ETM Trace Packet 0 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PD13
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PD13_TPK1
value|(AT91RM92_PIO_PD13)
end_define

begin_comment
comment|/* ETM Trace Packet 1 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PD14
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PD14_TPK2
value|(AT91RM92_PIO_PD14)
end_define

begin_comment
comment|/* ETM Trace Packet 2 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PD15
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PD15_TD0
value|(AT91RM92_PIO_PD15)
end_define

begin_comment
comment|/* SSC Transmit data */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PD15_TPK3
value|(AT91RM92_PIO_PD15)
end_define

begin_comment
comment|/* ETM Trace Packet 3 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PD16
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PD16_TD1
value|(AT91RM92_PIO_PD16)
end_define

begin_comment
comment|/* SSC Transmit Data 1 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PD16_TPK4
value|(AT91RM92_PIO_PD16)
end_define

begin_comment
comment|/* ETM Trace Packet 4 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PD17
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PD17_TD2
value|(AT91RM92_PIO_PD17)
end_define

begin_comment
comment|/* SSC Transmit Data 2 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PD17_TPK5
value|(AT91RM92_PIO_PD17)
end_define

begin_comment
comment|/* ETM Trace Packet 5 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PD18
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PD18_NPCS1
value|(AT91RM92_PIO_PD18)
end_define

begin_comment
comment|/* SPI Peripheral Chip Select 1 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PD18_TPK6
value|(AT91RM92_PIO_PD18)
end_define

begin_comment
comment|/* ETM Trace Packet 6 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PD19
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PD19_NPCS2
value|(AT91RM92_PIO_PD19)
end_define

begin_comment
comment|/* SPI Peripheral Chip Select 2 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PD19_TPK7
value|(AT91RM92_PIO_PD19)
end_define

begin_comment
comment|/* ETM Trace Packet 7 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PD20
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PD20_NPCS3
value|(AT91RM92_PIO_PD20)
end_define

begin_comment
comment|/* SPI Peripheral Chip Select 3 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PD20_TPK8
value|(AT91RM92_PIO_PD20)
end_define

begin_comment
comment|/* ETM Trace Packet 8 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PD21
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PD21_RTS0
value|(AT91RM92_PIO_PD21)
end_define

begin_comment
comment|/* Usart 0 Ready To Send */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PD21_TPK9
value|(AT91RM92_PIO_PD21)
end_define

begin_comment
comment|/* ETM Trace Packet 9 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PD22
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PD22_RTS1
value|(AT91RM92_PIO_PD22)
end_define

begin_comment
comment|/* Usart 0 Ready To Send */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PD22_TPK10
value|(AT91RM92_PIO_PD22)
end_define

begin_comment
comment|/* ETM Trace Packet 10 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PD23
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PD23_RTS2
value|(AT91RM92_PIO_PD23)
end_define

begin_comment
comment|/* USART 2 Ready To Send */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PD23_TPK11
value|(AT91RM92_PIO_PD23)
end_define

begin_comment
comment|/* ETM Trace Packet 11 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PD24
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PD24_RTS3
value|(AT91RM92_PIO_PD24)
end_define

begin_comment
comment|/* USART 3 Ready To Send */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PD24_TPK12
value|(AT91RM92_PIO_PD24)
end_define

begin_comment
comment|/* ETM Trace Packet 12 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PD25
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PD25_DTR1
value|(AT91RM92_PIO_PD25)
end_define

begin_comment
comment|/* USART 1 Data Terminal ready */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PD25_TPK13
value|(AT91RM92_PIO_PD25)
end_define

begin_comment
comment|/* ETM Trace Packet 13 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PD26
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PD26_TPK14
value|(AT91RM92_PIO_PD26)
end_define

begin_comment
comment|/* ETM Trace Packet 14 */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIO_PD27
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|AT91RM92_PD27_TPK15
value|(AT91RM92_PIO_PD27)
end_define

begin_comment
comment|/* ETM Trace Packet 15 */
end_comment

begin_define
define|#
directive|define
name|AT91C_MASTER_CLOCK
value|60000000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AT91RM92REG_H_ */
end_comment

end_unit

