begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Sylvestre Gallon.  All rights reserved.  * Copyright (c) 2010 Greg Ansley.  All rights reserved.  * Copyright (c) 2012 Andrew Turner.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AT91SAM9G45REG_H_
end_ifndef

begin_define
define|#
directive|define
name|AT91SAM9G45REG_H_
end_define

begin_comment
comment|/* Chip Specific limits */
end_comment

begin_define
define|#
directive|define
name|SAM9G45_PLL_A_MIN_IN_FREQ
value|2000000
end_define

begin_comment
comment|/*   2 Mhz */
end_comment

begin_define
define|#
directive|define
name|SAM9G45_PLL_A_MAX_IN_FREQ
value|32000000
end_define

begin_comment
comment|/*  32 Mhz */
end_comment

begin_define
define|#
directive|define
name|SAM9G45_PLL_A_MIN_OUT_FREQ
value|400000000
end_define

begin_comment
comment|/* 400 Mhz */
end_comment

begin_define
define|#
directive|define
name|SAM9G45_PLL_A_MAX_OUT_FREQ
value|800000000
end_define

begin_comment
comment|/* 800 Mhz */
end_comment

begin_define
define|#
directive|define
name|SAM9G45_PLL_A_MUL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|SAM9G45_PLL_A_MUL_MASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|SAM9G45_PLL_A_DIV_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SAM9G45_PLL_A_DIV_MASK
value|0xFF
end_define

begin_comment
comment|/*  * Memory map, from datasheet :  * 0x00000000 - 0x0ffffffff : Internal Memories  * 0x10000000 - 0x1ffffffff : Chip Select 0  * 0x20000000 - 0x2ffffffff : Chip Select 1  * 0x30000000 - 0x3ffffffff : Chip Select 2  * 0x40000000 - 0x4ffffffff : Chip Select 3  * 0x50000000 - 0x5ffffffff : Chip Select 4  * 0x60000000 - 0x6ffffffff : Chip Select 5  * 0x70000000 - 0x7ffffffff : DDR SDRC 0  * 0x80000000 - 0xeffffffff : Undefined (Abort)  * 0xf0000000 - 0xfffffffff : Peripherals  */
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
name|AT91SAM9G45_EMAC_BASE
value|0xffbc000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_EMAC_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_RSTC_BASE
value|0xffffd00
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_RSTC_SIZE
value|0x10
end_define

begin_comment
comment|/* USART*/
end_comment

begin_define
define|#
directive|define
name|AT91SAM9G45_USART_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_USART0_BASE
value|0xff8c000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_USART0_SIZE
value|AT91SAM9G45_USART_SIZE
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_USART1_BASE
value|0xff90000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_USART1_SIZE
value|AT91SAM9G45_USART_SIZE
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_USART2_BASE
value|0xff94000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_USART2_SIZE
value|AT91SAM9G45_USART_SIZE
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_USART3_BASE
value|0xff98000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_USART3_SIZE
value|AT91SAM9G45_USART_SIZE
end_define

begin_comment
comment|/*TC*/
end_comment

begin_define
define|#
directive|define
name|AT91SAM9G45_TC0_BASE
value|0xff7c000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_TC0_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_TC0C0_BASE
value|0xff7c000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_TC0C1_BASE
value|0xff7c040
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_TC0C2_BASE
value|0xff7c080
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_TC1_BASE
value|0xffd4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_TC1_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_TC1C0_BASE
value|0xffd4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_TC1C1_BASE
value|0xffd4040
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_TC1C2_BASE
value|0xffd4080
end_define

begin_comment
comment|/*SPI*/
end_comment

begin_define
define|#
directive|define
name|AT91SAM9G45_SPI0_BASE
value|0xffa48000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_SPI0_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_SPI1_BASE
value|0xffa8000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_SPI1_SIZE
value|0x4000
end_define

begin_comment
comment|/* System Registers */
end_comment

begin_define
define|#
directive|define
name|AT91SAM9G45_SYS_BASE
value|0xffff000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_SYS_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_MATRIX_BASE
value|0xfffea00
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_MATRIX_SIZE
value|0x200
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_DBGU_BASE
value|0xfffee00
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_DBGU_SIZE
value|0x200
end_define

begin_comment
comment|/*  * PIO  */
end_comment

begin_define
define|#
directive|define
name|AT91SAM9G45_PIOA_BASE
value|0xffff200
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_PIOA_SIZE
value|0x200
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_PIOB_BASE
value|0xffff400
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_PIOB_SIZE
value|0x200
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_PIOC_BASE
value|0xffff600
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_PIOC_SIZE
value|0x200
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_PIOD_BASE
value|0xffff800
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_PIOD_SIZE
value|0x200
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_PIOE_BASE
value|0xffffa00
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_PIOE_SIZE
value|0x200
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_PMC_BASE
value|0xffffc00
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_PMC_SIZE
value|0x100
end_define

begin_comment
comment|/* IRQs : */
end_comment

begin_comment
comment|/*  * 0: AIC  * 1: System peripheral (System timer, RTC, DBGU)  * 2: PIO Controller A  * 3: PIO Controller B  * 4: PIO Controller C  * 5: PIO Controller D/E  * 6: TRNG  * 7: USART 0  * 8: USART 1  * 9: USART 2  * 10: USART 3  * 11: Multimedia Card interface 0  * 12: Two-wire interface 0  * 13: Two-wire interface 1  * 14: SPI 0  * 15: SPI 1  * 16: SSC 0  * 17: SSC 1  * 18: Timer Counter 0, 1, 2, 3, 4, 5  * 19: PWM  * 20: Touch Screen ADC  * 21: DMA  * 22: USB Host port  * 23: LCD  * 24: AC97  * 25: EMAC  * 26: Image Sensor Interface  * 27: USB Device High Speed  * 28: -  * 29: Multimedia Card interface 1  * 30: Reserved  * 31: AIC  */
end_comment

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_SYSTEM
value|1
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_PIOA
value|2
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_PIOB
value|3
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_PIOC
value|4
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_PIODE
value|5
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_TRNG
value|6
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_USART0
value|7
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_USART1
value|8
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_USART2
value|9
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_USART3
value|10
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_HSMCI0
value|11
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_TWI0
value|12
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_TWI1
value|13
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_SPI0
value|14
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_SPI1
value|15
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_SSC0
value|16
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_SSC1
value|17
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_TC0_TC5
value|18
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_PWM
value|19
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_TSADCC
value|20
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_DMA
value|21
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_UHP
value|22
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_LCDC
value|23
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_AC97C
value|24
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_EMAC
value|25
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_ISI
value|26
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_UDPHS
value|27
end_define

begin_comment
comment|/* Reserved 28 */
end_comment

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_HSMCI1
value|29
end_define

begin_comment
comment|/* Reserved 30 */
end_comment

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_AICBASE
value|31
end_define

begin_comment
comment|/* Alias */
end_comment

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_DBGU
value|AT91SAM9G45_IRQ_SYSTEM
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_PMC
value|AT91SAM9G45_IRQ_SYSTEM
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_WDT
value|AT91SAM9G45_IRQ_SYSTEM
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_PIT
value|AT91SAM9G45_IRQ_SYSTEM
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_RSTC
value|AT91SAM9G45_IRQ_SYSTEM
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_PIOD
value|AT91SAM9G45_IRQ_PIODE
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_PIOE
value|AT91SAM9G45_IRQ_PIODE
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_OHCI
value|AT91SAM9G45_IRQ_UHP
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_TC0
value|AT91SAM9G45_IRQ_TC0_TC5
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_TC1
value|AT91SAM9G45_IRQ_TC0_TC5
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_TC2
value|AT91SAM9G45_IRQ_TC0_TC5
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_TC3
value|AT91SAM9G45_IRQ_TC0_TC5
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_TC4
value|AT91SAM9G45_IRQ_TC0_TC5
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_TC5
value|AT91SAM9G45_IRQ_TC0_TC5
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_IRQ_NAND
value|(-1)
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_AIC_BASE
value|0xffff000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_AIC_SIZE
value|0x200
end_define

begin_comment
comment|/* Timer */
end_comment

begin_define
define|#
directive|define
name|AT91SAM9G45_WDT_BASE
value|0xffffd40
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_WDT_SIZE
value|0x10
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_PIT_BASE
value|0xffffd30
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_PIT_SIZE
value|0x10
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_SMC_BASE
value|0xfffe800
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_SMC_SIZE
value|0x200
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_HSMCI0_BASE
value|0xff80000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_HSMCI0_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_HSMCI1_BASE
value|0xffd0000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_HSMCI1_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_TWI0_BASE
value|0xff84000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_TWI0_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_TWI1_BASE
value|0xff88000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_TWI1_SIZE
value|0x4000
end_define

begin_comment
comment|/* XXX Needs to be carfully coordinated with  * other * soc's so phyical and vm address  * mapping are unique. XXX  */
end_comment

begin_define
define|#
directive|define
name|AT91SAM9G45_OHCI_VA_BASE
value|0xdfb00000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_OHCI_BASE
value|0x00700000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_OHCI_SIZE
value|0x00100000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_NAND_VA_BASE
value|0xe0000000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_NAND_BASE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_NAND_SIZE
value|0x10000000
end_define

begin_comment
comment|/* DDRSDRC */
end_comment

begin_define
define|#
directive|define
name|AT91SAM9G45_DDRSDRC1_BASE
value|0xfffea00
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_DDRSDRC0_BASE
value|0xfffe600
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_DDRSDRC_MR
value|0x00
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_DDRSDRC_TR
value|0x04
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_DDRSDRC_CR
value|0x08
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_DDRSDRC_CR_NC_8
value|0x0
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_DDRSDRC_CR_NC_9
value|0x1
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_DDRSDRC_CR_NC_10
value|0x2
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_DDRSDRC_CR_NC_11
value|0x3
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_DDRSDRC_CR_NC_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_DDRSDRC_CR_NR_11
value|0x0
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_DDRSDRC_CR_NR_12
value|0x4
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_DDRSDRC_CR_NR_13
value|0x8
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_DDRSDRC_CR_NR_14
value|0xc
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_DDRSDRC_CR_NR_MASK
value|0x0000000c
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_DDRSDRC_TPR0
value|0x0c
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_DDRSDRC_TPR1
value|0x10
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_DDRSDRC_TPR2
value|0x14
end_define

begin_comment
comment|/* Reserved 0x18 */
end_comment

begin_define
define|#
directive|define
name|AT91SAM9G45_DDRSDRC_LPR
value|0x1c
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_DDRSDRC_MDR
value|0x20
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_DDRSDRC_MDR_SDR
value|0x0
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_DDRSDRC_MDR_LPSDR
value|0x1
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_DDRSDRC_MDR_LPDDR1
value|0x3
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_DDRSDRC_MDR_DDR2
value|0x6
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_DDRSDRC_MDR_MASK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_DDRSDRC_MDR_DBW_16
value|0x10
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_DDRSDRC_DLL
value|0x24
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_DDRSDRC_HSR
value|0x2c
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_DDRSDRC_DELAY1R
value|0x40
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_DDRSDRC_DELAY2R
value|0x44
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_DDRSDRC_DELAY3R
value|0x48
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_DDRSDRC_DELAY4R
value|0x4c
end_define

begin_comment
comment|/* Reserved 0x50 - 0xe0 */
end_comment

begin_define
define|#
directive|define
name|AT91SAM9G45_DDRSDRC_WPMR
value|0xe4
end_define

begin_define
define|#
directive|define
name|AT91SAM9G45_DDRSDRC_WPSR
value|0xe8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AT91SAM9G45REG_H_*/
end_comment

end_unit

