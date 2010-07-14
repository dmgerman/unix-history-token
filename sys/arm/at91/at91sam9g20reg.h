begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Sylvestre Gallon.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AT91SAM9G20REG_H_
end_ifndef

begin_define
define|#
directive|define
name|AT91SAM9G20REG_H_
end_define

begin_comment
comment|/*   * Memory map, from datasheet :  * 0x00000000 - 0x0ffffffff : Internal Memories  * 0x10000000 - 0x1ffffffff : Chip Select 0  * 0x20000000 - 0x2ffffffff : Chip Select 1  * 0x30000000 - 0x3ffffffff : Chip Select 2  * 0x40000000 - 0x4ffffffff : Chip Select 3  * 0x50000000 - 0x5ffffffff : Chip Select 4  * 0x60000000 - 0x6ffffffff : Chip Select 5  * 0x70000000 - 0x7ffffffff : Chip Select 6  * 0x80000000 - 0x8ffffffff : Chip Select 7  * 0x90000000 - 0xeffffffff : Undefined (Abort)  * 0xf0000000 - 0xfffffffff : Peripherals  */
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
name|AT91SAM9G20_BASE
value|0xd0000000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_IRQ_EMAC
value|21
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_EMAC_BASE
value|0xffc4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_EMAC_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_RSTC_BASE
value|0xffffd00
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
name|AT91SAM9G20_USART0_BASE
value|0xffb0000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_USART0_PDC
value|0xffb0100
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_USART1_BASE
value|0xffb4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_USART1_PDC
value|0xffb4100
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_USART2_BASE
value|0xffb8000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_USART2_PDC
value|0xffb8100
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_USART_SIZE
value|0x4000
end_define

begin_comment
comment|/*TC*/
end_comment

begin_define
define|#
directive|define
name|AT91SAM9G20_TC0_BASE
value|0xffa0000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_TC0_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_TC0C0_BASE
value|0xffa0000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_TC0C1_BASE
value|0xffa0040
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_TC0C2_BASE
value|0xffa0080
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_TC1_BASE
value|0xffdc000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_TC1_SIZE
value|0x4000
end_define

begin_comment
comment|/*SPI*/
end_comment

begin_define
define|#
directive|define
name|AT91SAM9G20_SPI0_BASE
value|0xffc8000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SPI0_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_IRQ_SPI0
value|12
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SPI1_BASE
value|0xffcc000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SPI1_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_IRQ_SPI1
value|13
end_define

begin_comment
comment|/* System Registers */
end_comment

begin_define
define|#
directive|define
name|AT91SAM9G20_SYS_BASE
value|0xfffe000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SYS_SIZE
value|0x2000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_MATRIX
value|(0xe00)
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_EBICSA
value|(AT91SAM9G20_MATRIX + 0x011C)
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

begin_comment
comment|/*  * PIO  */
end_comment

begin_define
define|#
directive|define
name|AT91SAM9G20_PIOA_BASE
value|0xffff400
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_PIO_SIZE
value|0x200
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_PIOB_BASE
value|0xffff600
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_PIOC_BASE
value|0xffff800
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
comment|/*  * 0: AIC   * 1: System peripheral (System timer, RTC, DBGU)  * 2: PIO Controller A  * 3: PIO Controller B  * 4: PIO Controller C  * 5: -  * 6: USART 0  * 7: USART 1  * 8: USART 2  * 9: MMC Interface  * 10: USB device port  * 11: Two-wirte interface  * 12: SPI  * 13: SPI  * 14: SSC  * 15: SSC  * 16: SSC  * 17: Timer Counter 0  * 18: Timer Counter 1  * 19: Timer Counter 2  * 20: USB Host port  * 21: EMAC  * 22-28: -  * 29: AIC  * 30: AIC  * 31: AIC  */
end_comment

begin_define
define|#
directive|define
name|AT91SAM9G20_IRQ_SYSTEM
value|1
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_IRQ_PIOA
value|2
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_IRQ_PIOB
value|3
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_IRQ_PIOC
value|4
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_IRQ_USART0
value|6
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_IRQ_USART1
value|7
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_IRQ_USART2
value|8
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_IRQ_MCI
value|9
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_IRQ_UDP
value|10
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_IRQ_TWI
value|11
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_IRQ_SPI0
value|12
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_IRQ_SPI1
value|13
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_IRQ_SSC0
value|14
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_IRQ_SSC1
value|15
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_IRQ_SSC2
value|16
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_IRQ_TC0
value|17
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_IRQ_TC1
value|18
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_IRQ_TC2
value|19
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_IRQ_UHP
value|20
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_IRQ_AICBASE
value|29
end_define

begin_comment
comment|/* Timer */
end_comment

begin_define
define|#
directive|define
name|AT91SAM9G20_DBGU_BASE
value|0xffff200
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_DBGU_SIZE
value|0x200
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_WDT_BASE
value|0xffffd40
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_WDT_SIZE
value|0x10
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_PIT_BASE
value|0xffffd30
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_PIT_SIZE
value|10
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SMC_BASE
value|0xfffec00
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SMC_SIZE
value|0x200
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_PMC_BASE
value|0xffffc00
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_PMC_SIZE
value|0x100
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_UDP_BASE
value|0xffa4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_UDP_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_OHCI_BASE
value|0xdfe00000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_OHCI_PA_BASE
value|0x00500000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_OHCI_SIZE
value|0x00100000
end_define

begin_comment
comment|//#define AT91SAM9G20_NAND_BASE 0xdf100000
end_comment

begin_comment
comment|//#define AT91SAM9G20_NAND_BASE 0x40000000
end_comment

begin_define
define|#
directive|define
name|AT91SAM9G20_NAND_BASE
value|0xe0000000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_NAND_PA_BASE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_NAND_SIZE
value|0x10000000
end_define

begin_comment
comment|//#define AT91SAM9G20_NAND_SIZE	0x00900000
end_comment

begin_comment
comment|//#define AT91SAM9G20_OHCI_SIZE	0x0004000
end_comment

begin_comment
comment|/* SDRAMC */
end_comment

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_BASE
value|0xfffea00
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_MR
value|0x00
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_MR_MODE_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_MR_MODE_NOP
value|1
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_MR_MODE_PRECHARGE
value|2
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_MR_MODE_LOAD_MODE_REGISTER
value|3
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_MR_MODE_REFRESH
value|4
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_TR
value|0x04
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_CR
value|0x08
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_CR_NC_8
value|0x0
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_CR_NC_9
value|0x1
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_CR_NC_10
value|0x2
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_CR_NC_11
value|0x3
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_CR_NC_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_CR_NR_11
value|0x0
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_CR_NR_12
value|0x4
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_CR_NR_13
value|0x8
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_CR_NR_RES
value|0xc
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_CR_NR_MASK
value|0x0000000c
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_CR_NB_2
value|0x00
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_CR_NB_4
value|0x10
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_CR_NB_MASK
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_CR_NCAS_MASK
value|0x00000060
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_CR_TWR_MASK
value|0x00000780
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_CR_TRC_MASK
value|0x00007800
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_CR_TRP_MASK
value|0x00078000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_CR_TRCD_MASK
value|0x00780000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_CR_TRAS_MASK
value|0x07800000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_CR_TXSR_MASK
value|0x78000000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_HSR
value|0x0c
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_LPR
value|0x10
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_IER
value|0x14
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_IDR
value|0x18
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_IMR
value|0x1c
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_ISR
value|0x20
end_define

begin_define
define|#
directive|define
name|AT91SAM9G20_SDRAMC_MDR
value|0x24
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AT91SAM9G20REG_H_*/
end_comment

end_unit

