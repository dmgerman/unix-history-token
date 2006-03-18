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
comment|/*  * PIO  */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PIOA_BASE
value|0xffff400
end_define

begin_define
define|#
directive|define
name|AT91RM92_PIO_SIZE
value|0x200
end_define

begin_define
define|#
directive|define
name|AT91RM92_PIOB_BASE
value|0xffff600
end_define

begin_define
define|#
directive|define
name|AT91RM92_PIOC_BASE
value|0xffff800
end_define

begin_define
define|#
directive|define
name|AT91RM92_PIOD_BASE
value|0xffffa00
end_define

begin_comment
comment|/*  * PMC  */
end_comment

begin_define
define|#
directive|define
name|AT91RM92_PMC_BASE
value|0xffffc00
end_define

begin_define
define|#
directive|define
name|AT91RM92_PMC_SIZE
value|0x100
end_define

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
name|AT91RM92_AIC_BASE
value|0xffff000
end_define

begin_define
define|#
directive|define
name|AT91RM92_AIC_SIZE
value|0x200
end_define

begin_define
define|#
directive|define
name|AT91RM92_DBGU_BASE
value|0xffff200
end_define

begin_define
define|#
directive|define
name|AT91RM92_DBGU_SIZE
value|0x200
end_define

begin_define
define|#
directive|define
name|AT91RM92_RTC_BASE
value|0xffffe00
end_define

begin_define
define|#
directive|define
name|AT91RM92_RTC_SIZE
value|0x100
end_define

begin_define
define|#
directive|define
name|AT91RM92_MC_BASE
value|0xfffff00
end_define

begin_define
define|#
directive|define
name|AT91RM92_MC_SIZE
value|0x100
end_define

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
name|AT91RM92_TC_SIZE
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

