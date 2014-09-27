begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Sylvestre Gallon.  All rights reserved.  * Copyright (c) 2010 Greg Ansley.  All rights reserved.  * Copyright (c) 2012 M. Warener Losh.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AT91SAM9X5REG_H_
end_ifndef

begin_define
define|#
directive|define
name|AT91SAM9X5REG_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|AT91SAM9X25_MASTER_CLOCK
end_ifndef

begin_define
define|#
directive|define
name|AT91SAM9X25_MASTER_CLOCK
value|((18432000 * 43)/6)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Chip Specific limits */
end_comment

begin_define
define|#
directive|define
name|SAM9X25_PLL_A_MIN_IN_FREQ
value|2000000
end_define

begin_comment
comment|/*   2 Mhz */
end_comment

begin_define
define|#
directive|define
name|SAM9X25_PLL_A_MAX_IN_FREQ
value|32000000
end_define

begin_comment
comment|/*  32 Mhz */
end_comment

begin_define
define|#
directive|define
name|SAM9X25_PLL_A_MIN_OUT_FREQ
value|400000000
end_define

begin_comment
comment|/* 400 Mhz */
end_comment

begin_define
define|#
directive|define
name|SAM9X25_PLL_A_MAX_OUT_FREQ
value|800000000
end_define

begin_comment
comment|/* 800 Mhz */
end_comment

begin_define
define|#
directive|define
name|SAM9X25_PLL_A_MUL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|SAM9X25_PLL_A_MUL_MASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|SAM9X25_PLL_A_DIV_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SAM9X25_PLL_A_DIV_MASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|SAM9X25_PLL_B_MIN_IN_FREQ
value|2000000
end_define

begin_comment
comment|/*   2 Mhz */
end_comment

begin_define
define|#
directive|define
name|SAM9X25_PLL_B_MAX_IN_FREQ
value|32000000
end_define

begin_comment
comment|/*  32 Mhz */
end_comment

begin_define
define|#
directive|define
name|SAM9X25_PLL_B_MIN_OUT_FREQ
value|30000000
end_define

begin_comment
comment|/*  30 Mhz */
end_comment

begin_define
define|#
directive|define
name|SAM9X25_PLL_B_MAX_OUT_FREQ
value|100000000
end_define

begin_comment
comment|/* 100 Mhz */
end_comment

begin_define
define|#
directive|define
name|SAM9X25_PLL_B_MUL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|SAM9X25_PLL_B_MUL_MASK
value|0x3F
end_define

begin_define
define|#
directive|define
name|SAM9X25_PLL_B_DIV_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SAM9X25_PLL_B_DIV_MASK
value|0xFF
end_define

begin_comment
comment|/*   * Memory map, from datasheet :  * 0x00000000 - 0x0ffffffff : Internal Memories  * 0x10000000 - 0x1ffffffff : Chip Select 0  * 0x20000000 - 0x2ffffffff : Chip Select 1 DDR2/LPDDR/SDR/LPSDR  * 0x30000000 - 0x3ffffffff : Chip Select 2   * 0x40000000 - 0x4ffffffff : Chip Select 3 NAND Flash  * 0x50000000 - 0x5ffffffff : Chip Select 4  * 0x60000000 - 0x6ffffffff : Chip Select 5  * 0x70000000 - 0xeffffffff : Undefined (Abort)  * 0xf0000000 - 0xfffffffff : Peripherals  */
end_comment

begin_define
define|#
directive|define
name|AT91_CHIPSELECT_0
value|0x10000000
end_define

begin_define
define|#
directive|define
name|AT91_CHIPSELECT_1
value|0x20000000
end_define

begin_define
define|#
directive|define
name|AT91_CHIPSELECT_2
value|0x30000000
end_define

begin_define
define|#
directive|define
name|AT91_CHIPSELECT_3
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AT91_CHIPSELECT_4
value|0x50000000
end_define

begin_define
define|#
directive|define
name|AT91_CHIPSELECT_5
value|0x60000000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_EMAC_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_EMAC0_BASE
value|0x802c000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_EMAC0_SIZE
value|AT91SAM9X25_EMAC_SIZE
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_EMAC1_BASE
value|0x8030000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_EMAC1_SIZE
value|AT91SAM9X25_EMAC_SIZE
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_RSTC_BASE
value|0xffffe00
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_RSTC_SIZE
value|0x10
end_define

begin_comment
comment|/* USART*/
end_comment

begin_define
define|#
directive|define
name|AT91SAM9X25_USART_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_USART0_BASE
value|0x801c000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_USART0_PDC
value|0x801c100
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_USART0_SIZE
value|AT91SAM9X25_USART_SIZE
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_USART1_BASE
value|0x8020000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_USART1_PDC
value|0x8020100
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_USART1_SIZE
value|AT91SAM9X25_USART_SIZE
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_USART2_BASE
value|0x8024000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_USART2_PDC
value|0x8024100
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_USART2_SIZE
value|AT91SAM9X25_USART_SIZE
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_USART3_BASE
value|0x8028000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_USART3_PDC
value|0x8028100
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_USART3_SIZE
value|AT91SAM9X25_USART_SIZE
end_define

begin_comment
comment|/*TC*/
end_comment

begin_define
define|#
directive|define
name|AT91SAM9X25_TC0_BASE
value|0x8008000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_TC0_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_TC0C0_BASE
value|0x8008000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_TC0C1_BASE
value|0x8008040
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_TC0C2_BASE
value|0x8008080
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_TC1_BASE
value|0x800c000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_TC1_SIZE
value|0x4000
end_define

begin_comment
comment|/*SPI*/
end_comment

begin_define
define|#
directive|define
name|AT91SAM9X25_SPI0_BASE
value|0x0000000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SPI0_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SPI1_BASE
value|0x0004000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SPI1_SIZE
value|0x4000
end_define

begin_comment
comment|/* System Registers */
end_comment

begin_define
define|#
directive|define
name|AT91SAM9X25_SYS_BASE
value|0xffff000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SYS_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_MATRIX_BASE
value|0xfffde00
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_MATRIX_SIZE
value|0x200
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_DBGU_BASE
value|0xffff200
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_DBGU_SIZE
value|0x200
end_define

begin_comment
comment|/*  * PIO  */
end_comment

begin_define
define|#
directive|define
name|AT91SAM9X25_PIOA_BASE
value|0xffff400
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_PIOA_SIZE
value|0x200
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_PIOB_BASE
value|0xffff600
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_PIOB_SIZE
value|0x200
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_PIOC_BASE
value|0xffff800
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_PIOC_SIZE
value|0x200
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_PIOD_BASE
value|0xffffa00
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_PIOD_SIZE
value|0x200
end_define

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
comment|/* IRQs :  * 0: AIC   * 1: System peripheral (System timer, RTC, DBGU)  * 2: PIO Controller A,B  * 3: PIO Controller C,D  * 4: SMD Soft Modem  * 5: USART 0  * 6: USART 1  * 7: USART 2  * 8: USART 3  * 9: Two-wire interface  * 10: Two-wire interface  * 11: Two-wire interface  * 12: HSMCI Interface  * 13: SPI 0  * 14: SPI 1  * 15: UART0  * 16: UART1  * 17: Timer Counter 0,1  * 18: PWM  * 19: ADC  * 20: DMAC 0  * 21: DMAC 1  * 22: UHPHS - USB Host controller  * 23: UDPHS - USB Device Controller  * 24: EMAC0  * 25: LCD controller or Image Sensor Interface  * 26: HSMCI1  * 27: EMAC1  * 28: SSC  * 29: CAN0  * 30: CAN1  * 31: AIC IRQ0  */
end_comment

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_AIC
value|0
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_SYSTEM
value|1
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_PIOAB
value|2
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_PIOCD
value|3
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_SMD
value|4
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_USART0
value|5
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_USART1
value|6
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_USART2
value|7
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_USART3
value|8
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_TWI0
value|9
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_TWI1
value|10
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_TWI2
value|11
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_HSMCI0
value|12
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_SPI0
value|13
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_SPI1
value|14
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_UART0
value|15
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_UART1
value|16
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_TC01
value|17
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_PWM
value|18
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_ADC
value|19
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_DMAC0
value|20
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_DMAC1
value|21
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_UHPHS
value|22
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_UDPHS
value|23
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_EMAC0
value|24
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_HSMCI1
value|26
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_EMAC1
value|27
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_SSC
value|28
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_CAN0
value|29
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_CAN1
value|30
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_AICBASE
value|31
end_define

begin_comment
comment|/* Alias */
end_comment

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_DBGU
value|AT91SAM9X25_IRQ_SYSTEM
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_PMC
value|AT91SAM9X25_IRQ_SYSTEM
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_WDT
value|AT91SAM9X25_IRQ_SYSTEM
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_PIT
value|AT91SAM9X25_IRQ_SYSTEM
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_RSTC
value|AT91SAM9X25_IRQ_SYSTEM
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_OHCI
value|AT91SAM9X25_IRQ_UHPHS
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_EHCI
value|AT91SAM9X25_IRQ_UHPHS
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_PIOA
value|AT91SAM9X25_IRQ_PIOAB
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_PIOB
value|AT91SAM9X25_IRQ_PIOAB
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_PIOC
value|AT91SAM9X25_IRQ_PIOCD
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_PIOD
value|AT91SAM9X25_IRQ_PIOCD
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_IRQ_NAND
value|(-1)
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_AIC_BASE
value|0xffff000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_AIC_SIZE
value|0x200
end_define

begin_comment
comment|/* Timer */
end_comment

begin_define
define|#
directive|define
name|AT91SAM9X25_WDT_BASE
value|0xffffd40
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_WDT_SIZE
value|0x10
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_PIT_BASE
value|0xffffd30
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_PIT_SIZE
value|0x10
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SMC_BASE
value|0xfffea00
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SMC_SIZE
value|0x200
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_PMC_BASE
value|0xffffc00
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_PMC_SIZE
value|0x100
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_UDPHS_BASE
value|0x803c000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_UDPHS_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_HSMCI_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_HSMCI0_BASE
value|0x0008000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_HSMCI0_SIZE
value|AT91SAM9X25_HSMCI_SIZE
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_HSMCI1_BASE
value|0x000c000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_HSMCI1_SIZE
value|AT91SAM9X25_HSMCI_SIZE
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_TWI_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_TWI0_BASE
value|0xffaC000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_TWI0_SIZE
value|AT91SAM9X25_TWI_SIZE
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_TWI1_BASE
value|0xffaC000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_TWI1_SIZE
value|AT91SAM9X25_TWI_SIZE
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_TWI2_BASE
value|0xffaC000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_TWI2_SIZE
value|AT91SAM9X25_TWI_SIZE
end_define

begin_comment
comment|/* XXX Needs to be carfully coordinated with  * other * soc's so phyical and vm address  * mapping are unique. XXX  */
end_comment

begin_define
define|#
directive|define
name|AT91SAM9X25_OHCI_BASE
value|0xdfc00000
end_define

begin_comment
comment|/* SAME as 9c40 */
end_comment

begin_define
define|#
directive|define
name|AT91SAM9X25_OHCI_PA_BASE
value|0x00600000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_OHCI_SIZE
value|0x00100000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_EHCI_BASE
value|0xdfd00000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_EHCI_PA_BASE
value|0x00700000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_EHCI_SIZE
value|0x00100000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_NAND_BASE
value|0xe0000000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_NAND_PA_BASE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_NAND_SIZE
value|0x10000000
end_define

begin_comment
comment|/* SDRAMC */
end_comment

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_BASE
value|0xfffea00
end_define

begin_comment
comment|/* SAME as SMC? */
end_comment

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_MR
value|0x00
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_MR_MODE_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_MR_MODE_NOP
value|1
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_MR_MODE_PRECHARGE
value|2
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_MR_MODE_LOAD_MODE_REGISTER
value|3
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_MR_MODE_REFRESH
value|4
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_TR
value|0x04
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_CR
value|0x08
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_CR_NC_8
value|0x0
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_CR_NC_9
value|0x1
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_CR_NC_10
value|0x2
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_CR_NC_11
value|0x3
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_CR_NC_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_CR_NR_11
value|0x0
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_CR_NR_12
value|0x4
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_CR_NR_13
value|0x8
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_CR_NR_RES
value|0xc
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_CR_NR_MASK
value|0x0000000c
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_CR_NB_2
value|0x00
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_CR_NB_4
value|0x10
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_CR_DBW_16
value|0x80
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_CR_NB_MASK
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_CR_NCAS_MASK
value|0x00000060
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_CR_TWR_MASK
value|0x00000780
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_CR_TRC_MASK
value|0x00007800
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_CR_TRP_MASK
value|0x00078000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_CR_TRCD_MASK
value|0x00780000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_CR_TRAS_MASK
value|0x07800000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_CR_TXSR_MASK
value|0x78000000
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_HSR
value|0x0c
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_LPR
value|0x10
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_IER
value|0x14
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_IDR
value|0x18
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_IMR
value|0x1c
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_ISR
value|0x20
end_define

begin_define
define|#
directive|define
name|AT91SAM9X25_SDRAMC_MDR
value|0x24
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AT91SAM9X5REG_H_*/
end_comment

end_unit

