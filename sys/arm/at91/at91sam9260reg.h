begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Greg Ansley.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AT91SAM9260REG_H_
end_ifndef

begin_define
define|#
directive|define
name|AT91SAM9260REG_H_
end_define

begin_comment
comment|/* Chip Specific limits */
end_comment

begin_define
define|#
directive|define
name|SAM9260_PLL_A_MIN_IN_FREQ
value|1000000
end_define

begin_comment
comment|/*   1 Mhz */
end_comment

begin_define
define|#
directive|define
name|SAM9260_PLL_A_MAX_IN_FREQ
value|32000000
end_define

begin_comment
comment|/*  32 Mhz */
end_comment

begin_define
define|#
directive|define
name|SAM9260_PLL_A_MIN_OUT_FREQ
value|80000000
end_define

begin_comment
comment|/*  80 Mhz */
end_comment

begin_define
define|#
directive|define
name|SAM9260_PLL_A_MAX_OUT_FREQ
value|240000000
end_define

begin_comment
comment|/* 240 Mhz */
end_comment

begin_define
define|#
directive|define
name|SAM9260_PLL_A_MUL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|SAM9260_PLL_A_MUL_MASK
value|0x3FF
end_define

begin_define
define|#
directive|define
name|SAM9260_PLL_A_DIV_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SAM9260_PLL_A_DIV_MASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|SAM9260_PLL_B_MIN_IN_FREQ
value|1000000
end_define

begin_comment
comment|/*   1 Mhz */
end_comment

begin_define
define|#
directive|define
name|SAM9260_PLL_B_MAX_IN_FREQ
value|5000000
end_define

begin_comment
comment|/*   5 Mhz */
end_comment

begin_define
define|#
directive|define
name|SAM9260_PLL_B_MIN_OUT_FREQ
value|70000000
end_define

begin_comment
comment|/*  70 Mhz */
end_comment

begin_define
define|#
directive|define
name|SAM9260_PLL_B_MAX_OUT_FREQ
value|130000000
end_define

begin_comment
comment|/* 130 Mhz */
end_comment

begin_define
define|#
directive|define
name|SAM9260_PLL_B_MUL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|SAM9260_PLL_B_MUL_MASK
value|0x3FF
end_define

begin_define
define|#
directive|define
name|SAM9260_PLL_B_DIV_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SAM9260_PLL_B_DIV_MASK
value|0xFF
end_define

begin_comment
comment|/*  * Memory map, from datasheet :  * 0x00000000 - 0x0ffffffff : Internal Memories  * 0x10000000 - 0x1ffffffff : Chip Select 0  * 0x20000000 - 0x2ffffffff : Chip Select 1  * 0x30000000 - 0x3ffffffff : Chip Select 2  * 0x40000000 - 0x4ffffffff : Chip Select 3  * 0x50000000 - 0x5ffffffff : Chip Select 4  * 0x60000000 - 0x6ffffffff : Chip Select 5  * 0x70000000 - 0x7ffffffff : Chip Select 6  * 0x80000000 - 0x8ffffffff : Chip Select 7  * 0x90000000 - 0xeffffffff : Undefined (Abort)  * 0xf0000000 - 0xfffffffff : Peripherals  */
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
name|AT91_CHIPSELECT_6
value|0x70000000
end_define

begin_define
define|#
directive|define
name|AT91_CHIPSELECT_7
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_EMAC_BASE
value|0xffc4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_EMAC_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_RSTC_BASE
value|0xffffd00
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_RSTC_SIZE
value|0x10
end_define

begin_define
define|#
directive|define
name|RSTC_CR
value|0
end_define

begin_define
define|#
directive|define
name|RSTC_PROCRST
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RSTC_PERRST
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RSTC_KEY
value|(0xa5<< 24)
end_define

begin_comment
comment|/* USART*/
end_comment

begin_define
define|#
directive|define
name|AT91SAM9260_USART_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_USART0_BASE
value|0xffb0000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_USART0_PDC
value|0xffb0100
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_USART0_SIZE
value|AT91SAM9260_USART_SIZE
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_USART1_BASE
value|0xffb4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_USART1_PDC
value|0xffb4100
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_USART1_SIZE
value|AT91SAM9260_USART_SIZE
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_USART2_BASE
value|0xffb8000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_USART2_PDC
value|0xffb8100
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_USART2_SIZE
value|AT91SAM9260_USART_SIZE
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_USART3_BASE
value|0xffd0000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_USART3_PDC
value|0xffd0100
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_USART3_SIZE
value|AT91SAM9260_USART_SIZE
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_USART4_BASE
value|0xffd4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_USART4_PDC
value|0xffd4100
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_USART4_SIZE
value|AT91SAM9260_USART_SIZE
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_USART5_BASE
value|0xffd8000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_USART5_PDC
value|0xffd8100
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_USART5_SIZE
value|AT91SAM9260_USART_SIZE
end_define

begin_comment
comment|/*TC*/
end_comment

begin_define
define|#
directive|define
name|AT91SAM9260_TC0_BASE
value|0xffa0000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_TC0_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_TC0C0_BASE
value|0xffa0000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_TC0C1_BASE
value|0xffa0040
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_TC0C2_BASE
value|0xffa0080
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_TC1_BASE
value|0xffdc000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_TC1_SIZE
value|0x4000
end_define

begin_comment
comment|/*SPI*/
end_comment

begin_define
define|#
directive|define
name|AT91SAM9260_SPI0_BASE
value|0xffc8000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SPI0_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_IRQ_SPI0
value|12
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SPI1_BASE
value|0xffcc000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SPI1_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_IRQ_SPI1
value|13
end_define

begin_comment
comment|/* System Registers */
end_comment

begin_define
define|#
directive|define
name|AT91SAM9260_SYS_BASE
value|0xffff000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SYS_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_MATRIX_BASE
value|0xfffee00
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_MATRIX_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_EBICSA
value|0x011C
end_define

begin_define
define|#
directive|define
name|AT91_MATRIX_EBI_CS3A_SMC_SMARTMEDIA
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_DBGU_BASE
value|0xffff200
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_DBGU_SIZE
value|0x200
end_define

begin_comment
comment|/*  * PIO  */
end_comment

begin_define
define|#
directive|define
name|AT91SAM9260_PIOA_BASE
value|0xffff400
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_PIOA_SIZE
value|0x200
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_PIOB_BASE
value|0xffff600
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_PIOB_SIZE
value|0x200
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_PIOC_BASE
value|0xffff800
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_PIOC_SIZE
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
comment|/* IRQs : */
end_comment

begin_comment
comment|/*  * 0: AIC  * 1: System peripheral (System timer, RTC, DBGU)  * 2: PIO Controller A  * 3: PIO Controller B  * 4: PIO Controller C  * 5: ADC  * 6: USART 0  * 7: USART 1  * 8: USART 2  * 9: MMC Interface  * 10: USB device port  * 11: Two-wire interface  * 12: SPI 0  * 13: SPI 1  * 14: SSC  * 15: - (reserved)  * 16: - (reserved)  * 17: Timer Counter 0  * 18: Timer Counter 1  * 19: Timer Counter 2  * 20: USB Host port  * 21: EMAC  * 22: ISI  * 23: USART 3  * 24: USART 4  * 25: USART 2  * 26: Timer Counter 3  * 27: Timer Counter 4  * 28: Timer Counter 5  * 29: AIC IRQ0  * 30: AIC IRQ1  * 31: AIC IRQ2  */
end_comment

begin_define
define|#
directive|define
name|AT91SAM9260_IRQ_SYSTEM
value|1
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_IRQ_PIOA
value|2
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_IRQ_PIOB
value|3
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_IRQ_PIOC
value|4
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_IRQ_USART0
value|6
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_IRQ_USART1
value|7
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_IRQ_USART2
value|8
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_IRQ_MCI
value|9
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_IRQ_UDP
value|10
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_IRQ_TWI
value|11
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_IRQ_SPI0
value|12
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_IRQ_SPI1
value|13
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_IRQ_SSC0
value|14
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_IRQ_SSC1
value|15
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_IRQ_SSC2
value|16
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_IRQ_TC0
value|17
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_IRQ_TC1
value|18
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_IRQ_TC2
value|19
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_IRQ_UHP
value|20
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_IRQ_EMAC
value|21
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_IRQ_USART3
value|23
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_IRQ_USART4
value|24
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_IRQ_USART5
value|25
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_IRQ_AICBASE
value|29
end_define

begin_comment
comment|/* Alias */
end_comment

begin_define
define|#
directive|define
name|AT91SAM9260_IRQ_DBGU
value|AT91SAM9260_IRQ_SYSTEM
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_IRQ_PMC
value|AT91SAM9260_IRQ_SYSTEM
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_IRQ_WDT
value|AT91SAM9260_IRQ_SYSTEM
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_IRQ_PIT
value|AT91SAM9260_IRQ_SYSTEM
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_IRQ_RSTC
value|AT91SAM9260_IRQ_SYSTEM
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_IRQ_OHCI
value|AT91SAM9260_IRQ_UHP
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_IRQ_NAND
value|(-1)
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_IRQ_AIC
value|(-1)
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_AIC_BASE
value|0xffff000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_AIC_SIZE
value|0x200
end_define

begin_comment
comment|/* Timer */
end_comment

begin_define
define|#
directive|define
name|AT91SAM9260_WDT_BASE
value|0xffffd40
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_WDT_SIZE
value|0x10
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_PIT_BASE
value|0xffffd30
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_PIT_SIZE
value|0x10
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SMC_BASE
value|0xfffec00
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SMC_SIZE
value|0x200
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_PMC_BASE
value|0xffffc00
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_PMC_SIZE
value|0x100
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_UDP_BASE
value|0xffa4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_UDP_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_MCI_BASE
value|0xffa8000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_MCI_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_TWI_BASE
value|0xffaC000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_TWI_SIZE
value|0x4000
end_define

begin_comment
comment|/* XXX Needs to be carfully coordinated with  * other * soc's so phyical and vm address  * mapping are unique. XXX  */
end_comment

begin_define
define|#
directive|define
name|AT91SAM9260_OHCI_VA_BASE
value|0xdfc00000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_OHCI_BASE
value|0x00500000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_OHCI_SIZE
value|0x00100000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_NAND_VA_BASE
value|0xe0000000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_NAND_BASE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_NAND_SIZE
value|0x10000000
end_define

begin_comment
comment|/* SDRAMC */
end_comment

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_BASE
value|0xfffea00
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_MR
value|0x00
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_MR_MODE_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_MR_MODE_NOP
value|1
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_MR_MODE_PRECHARGE
value|2
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_MR_MODE_LOAD_MODE_REGISTER
value|3
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_MR_MODE_REFRESH
value|4
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_TR
value|0x04
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_CR
value|0x08
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_CR_NC_8
value|0x0
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_CR_NC_9
value|0x1
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_CR_NC_10
value|0x2
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_CR_NC_11
value|0x3
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_CR_NC_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_CR_NR_11
value|0x0
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_CR_NR_12
value|0x4
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_CR_NR_13
value|0x8
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_CR_NR_RES
value|0xc
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_CR_NR_MASK
value|0x0000000c
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_CR_NB_2
value|0x00
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_CR_NB_4
value|0x10
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_CR_DBW_16
value|0x80
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_CR_NB_MASK
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_CR_NCAS_MASK
value|0x00000060
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_CR_TWR_MASK
value|0x00000780
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_CR_TRC_MASK
value|0x00007800
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_CR_TRP_MASK
value|0x00078000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_CR_TRCD_MASK
value|0x00780000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_CR_TRAS_MASK
value|0x07800000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_CR_TXSR_MASK
value|0x78000000
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_HSR
value|0x0c
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_LPR
value|0x10
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_IER
value|0x14
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_IDR
value|0x18
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_IMR
value|0x1c
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_ISR
value|0x20
end_define

begin_define
define|#
directive|define
name|AT91SAM9260_SDRAMC_MDR
value|0x24
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AT91SAM9260REG_H_*/
end_comment

end_unit

