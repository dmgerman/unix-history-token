begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: pxa2x0reg.h,v 1.9 2006/04/10 04:13:58 simonb Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2002  Genetec Corporation.  All rights reserved.  * Written by Hiroyuki Bessho for Genetec Corporation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed for the NetBSD Project by  *	Genetec Corporation.  * 4. The name of Genetec Corporation may not be used to endorse or  *    promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY GENETEC CORPORATION ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL GENETEC CORPORATION  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Intel PXA2[15]0 processor is XScale based integrated CPU  *  * Reference:  *  Intel(r) PXA250 and PXA210 Application Processors  *   Developer's Manual  *  (278522-001.pdf)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARM_XSCALE_PXAREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_ARM_XSCALE_PXAREG_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_LOCORE
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* for uint32_t */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Chip select domains  */
end_comment

begin_define
define|#
directive|define
name|PXA2X0_CS0_START
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PXA2X0_CS1_START
value|0x04000000
end_define

begin_define
define|#
directive|define
name|PXA2X0_CS2_START
value|0x08000000
end_define

begin_define
define|#
directive|define
name|PXA2X0_CS3_START
value|0x0c000000
end_define

begin_define
define|#
directive|define
name|PXA2X0_CS4_START
value|0x10000000
end_define

begin_define
define|#
directive|define
name|PXA2X0_CS5_START
value|0x14000000
end_define

begin_define
define|#
directive|define
name|PXA2X0_CS_SIZE
value|0x04000000
end_define

begin_define
define|#
directive|define
name|PXA2X0_PCMCIA_SLOT0
value|0x20000000
end_define

begin_define
define|#
directive|define
name|PXA2X0_PCMCIA_SLOT1
value|0x30000000
end_define

begin_define
define|#
directive|define
name|PXA2X0_PERIPH_START
value|0x40000000
end_define

begin_comment
comment|/* #define PXA2X0_MEMCTL_START 0x48000000 */
end_comment

begin_define
define|#
directive|define
name|PXA270_PERIPH_END
value|0x530fffff
end_define

begin_define
define|#
directive|define
name|PXA250_PERIPH_END
value|0x480fffff
end_define

begin_define
define|#
directive|define
name|PXA2X0_PERIPH_OFFSET
value|0xa8000000
end_define

begin_define
define|#
directive|define
name|PXA2X0_SDRAM0_START
value|0xa0000000
end_define

begin_define
define|#
directive|define
name|PXA2X0_SDRAM1_START
value|0xa4000000
end_define

begin_define
define|#
directive|define
name|PXA2X0_SDRAM2_START
value|0xa8000000
end_define

begin_define
define|#
directive|define
name|PXA2X0_SDRAM3_START
value|0xac000000
end_define

begin_define
define|#
directive|define
name|PXA2X0_SDRAM_BANKS
value|4
end_define

begin_define
define|#
directive|define
name|PXA2X0_SDRAM_BANK_SIZE
value|0x04000000
end_define

begin_comment
comment|/*  * Physical address of integrated peripherals  */
end_comment

begin_define
define|#
directive|define
name|PXA2X0_DMAC_BASE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|PXA2X0_DMAC_SIZE
value|0x300
end_define

begin_define
define|#
directive|define
name|PXA2X0_FFUART_BASE
value|0x40100000
end_define

begin_comment
comment|/* Full Function UART */
end_comment

begin_define
define|#
directive|define
name|PXA2X0_FFUART_SIZE
value|0x20
end_define

begin_define
define|#
directive|define
name|PXA2X0_BTUART_BASE
value|0x40200000
end_define

begin_comment
comment|/* Bluetooth UART */
end_comment

begin_define
define|#
directive|define
name|PXA2X0_BTUART_SIZE
value|0x24
end_define

begin_define
define|#
directive|define
name|PXA2X0_I2C_BASE
value|0x40300000
end_define

begin_define
define|#
directive|define
name|PXA2X0_I2C_SIZE
value|0x000016a4
end_define

begin_define
define|#
directive|define
name|PXA2X0_I2S_BASE
value|0x40400000
end_define

begin_define
define|#
directive|define
name|PXA2X0_AC97_BASE
value|0x40500000
end_define

begin_define
define|#
directive|define
name|PXA2X0_AC97_SIZE
value|0x600
end_define

begin_define
define|#
directive|define
name|PXA2X0_USBDC_BASE
value|0x40600000
end_define

begin_comment
comment|/* USB Client */
end_comment

begin_define
define|#
directive|define
name|PXA2X0_USBDC_SIZE
value|0x0e04
end_define

begin_define
define|#
directive|define
name|PXA2X0_STUART_BASE
value|0x40700000
end_define

begin_comment
comment|/* Standard UART */
end_comment

begin_define
define|#
directive|define
name|PXA2X0_STUART_SIZE
value|0x24
end_define

begin_define
define|#
directive|define
name|PXA2X0_ICP_BASE
value|0x40800000
end_define

begin_define
define|#
directive|define
name|PXA2X0_RTC_BASE
value|0x40900000
end_define

begin_define
define|#
directive|define
name|PXA2X0_RTC_SIZE
value|0x10
end_define

begin_define
define|#
directive|define
name|PXA2X0_OST_BASE
value|0x40a00000
end_define

begin_comment
comment|/* OS Timer */
end_comment

begin_define
define|#
directive|define
name|PXA2X0_OST_SIZE
value|0x20
end_define

begin_define
define|#
directive|define
name|PXA2X0_PWM0_BASE
value|0x40b00000
end_define

begin_define
define|#
directive|define
name|PXA2X0_PWM1_BASE
value|0x40c00000
end_define

begin_define
define|#
directive|define
name|PXA2X0_INTCTL_BASE
value|0x40d00000
end_define

begin_comment
comment|/* Interrupt controller */
end_comment

begin_define
define|#
directive|define
name|PXA2X0_INTCTL_SIZE
value|0x20
end_define

begin_define
define|#
directive|define
name|PXA2X0_GPIO_BASE
value|0x40e00000
end_define

begin_define
define|#
directive|define
name|PXA270_GPIO_SIZE
value|0x150
end_define

begin_define
define|#
directive|define
name|PXA250_GPIO_SIZE
value|0x70
end_define

begin_define
define|#
directive|define
name|PXA2X0_POWMAN_BASE
value|0x40f00000
end_define

begin_comment
comment|/* Power management */
end_comment

begin_define
define|#
directive|define
name|PXA2X0_SSP_BASE
value|0x41000000
end_define

begin_define
define|#
directive|define
name|PXA2X0_MMC_BASE
value|0x41100000
end_define

begin_comment
comment|/* MultiMediaCard */
end_comment

begin_define
define|#
directive|define
name|PXA2X0_MMC_SIZE
value|0x48
end_define

begin_define
define|#
directive|define
name|PXA2X0_CLKMAN_BASE
value|0x41300000
end_define

begin_comment
comment|/* Clock Manager */
end_comment

begin_define
define|#
directive|define
name|PXA2X0_CLKMAN_SIZE
value|12
end_define

begin_define
define|#
directive|define
name|PXA2X0_HWUART_BASE
value|0x41600000
end_define

begin_comment
comment|/* Hardware UART */
end_comment

begin_define
define|#
directive|define
name|PXA2X0_HWUART_SIZE
value|0x30
end_define

begin_define
define|#
directive|define
name|PXA2X0_LCDC_BASE
value|0x44000000
end_define

begin_comment
comment|/* LCD Controller */
end_comment

begin_define
define|#
directive|define
name|PXA2X0_LCDC_SIZE
value|0x220
end_define

begin_define
define|#
directive|define
name|PXA2X0_MEMCTL_BASE
value|0x48000000
end_define

begin_comment
comment|/* Memory Controller */
end_comment

begin_define
define|#
directive|define
name|PXA2X0_MEMCTL_SIZE
value|0x48
end_define

begin_define
define|#
directive|define
name|PXA2X0_USBH_BASE
value|0x4c000000
end_define

begin_comment
comment|/* USB Host controller */
end_comment

begin_define
define|#
directive|define
name|PXA2X0_USBH_SIZE
value|0x70
end_define

begin_comment
comment|/* Internal SRAM storage. PXA27x only */
end_comment

begin_define
define|#
directive|define
name|PXA270_SRAM0_START
value|0x5c000000
end_define

begin_define
define|#
directive|define
name|PXA270_SRAM1_START
value|0x5c010000
end_define

begin_define
define|#
directive|define
name|PXA270_SRAM2_START
value|0x5c020000
end_define

begin_define
define|#
directive|define
name|PXA270_SRAM3_START
value|0x5c030000
end_define

begin_define
define|#
directive|define
name|PXA270_SRAM_BANKS
value|4
end_define

begin_define
define|#
directive|define
name|PXA270_SRAM_BANK_SIZE
value|0x00010000
end_define

begin_comment
comment|/* width of interrupt controller */
end_comment

begin_define
define|#
directive|define
name|ICU_LEN
value|32
end_define

begin_comment
comment|/* but [0..7,15,16] is not used */
end_comment

begin_define
define|#
directive|define
name|ICU_INT_HWMASK
value|0xffffff00
end_define

begin_define
define|#
directive|define
name|PXA250_IRQ_MIN
value|8
end_define

begin_comment
comment|/* 0..7 are not used by integrated 				   peripherals */
end_comment

begin_define
define|#
directive|define
name|PXA270_IRQ_MIN
value|0
end_define

begin_define
define|#
directive|define
name|PXA2X0_INT_USBH1
value|3
end_define

begin_comment
comment|/* USB host (OHCI) */
end_comment

begin_define
define|#
directive|define
name|PXA2X0_INT_HWUART
value|7
end_define

begin_define
define|#
directive|define
name|PXA2X0_INT_GPIO0
value|8
end_define

begin_define
define|#
directive|define
name|PXA2X0_INT_GPIO1
value|9
end_define

begin_define
define|#
directive|define
name|PXA2X0_INT_GPION
value|10
end_define

begin_comment
comment|/* irq from GPIO[2..80] */
end_comment

begin_define
define|#
directive|define
name|PXA2X0_INT_USB
value|11
end_define

begin_define
define|#
directive|define
name|PXA2X0_INT_PMU
value|12
end_define

begin_define
define|#
directive|define
name|PXA2X0_INT_I2S
value|13
end_define

begin_define
define|#
directive|define
name|PXA2X0_INT_AC97
value|14
end_define

begin_define
define|#
directive|define
name|PXA2X0_INT_LCD
value|17
end_define

begin_define
define|#
directive|define
name|PXA2X0_INT_I2C
value|18
end_define

begin_define
define|#
directive|define
name|PXA2X0_INT_ICP
value|19
end_define

begin_define
define|#
directive|define
name|PXA2X0_INT_STUART
value|20
end_define

begin_define
define|#
directive|define
name|PXA2X0_INT_BTUART
value|21
end_define

begin_define
define|#
directive|define
name|PXA2X0_INT_FFUART
value|22
end_define

begin_define
define|#
directive|define
name|PXA2X0_INT_MMC
value|23
end_define

begin_define
define|#
directive|define
name|PXA2X0_INT_SSP
value|24
end_define

begin_define
define|#
directive|define
name|PXA2X0_INT_DMA
value|25
end_define

begin_define
define|#
directive|define
name|PXA2X0_INT_OST0
value|26
end_define

begin_define
define|#
directive|define
name|PXA2X0_INT_OST1
value|27
end_define

begin_define
define|#
directive|define
name|PXA2X0_INT_OST2
value|28
end_define

begin_define
define|#
directive|define
name|PXA2X0_INT_OST3
value|29
end_define

begin_define
define|#
directive|define
name|PXA2X0_INT_RTCHZ
value|30
end_define

begin_define
define|#
directive|define
name|PXA2X0_INT_ALARM
value|31
end_define

begin_comment
comment|/* RTC Alarm interrupt */
end_comment

begin_comment
comment|/* DMAC */
end_comment

begin_define
define|#
directive|define
name|DMAC_N_CHANNELS
value|16
end_define

begin_define
define|#
directive|define
name|DMAC_N_PRIORITIES
value|3
end_define

begin_define
define|#
directive|define
name|DMAC_DCSR
parameter_list|(
name|n
parameter_list|)
value|((n)*4)
end_define

begin_define
define|#
directive|define
name|DCSR_BUSERRINTR
value|(1<<0)
end_define

begin_comment
comment|/* bus error interrupt */
end_comment

begin_define
define|#
directive|define
name|DCSR_STARTINTR
value|(1<<1)
end_define

begin_comment
comment|/* start interrupt */
end_comment

begin_define
define|#
directive|define
name|DCSR_ENDINTR
value|(1<<2)
end_define

begin_comment
comment|/* end interrupt */
end_comment

begin_define
define|#
directive|define
name|DCSR_STOPSTATE
value|(1<<3)
end_define

begin_comment
comment|/* channel is not running */
end_comment

begin_define
define|#
directive|define
name|DCSR_REQPEND
value|(1<<8)
end_define

begin_comment
comment|/* request pending */
end_comment

begin_define
define|#
directive|define
name|DCSR_STOPIRQEN
value|(1<<29)
end_define

begin_comment
comment|/* stop interrupt enable */
end_comment

begin_define
define|#
directive|define
name|DCSR_NODESCFETCH
value|(1<<30)
end_define

begin_comment
comment|/* no-descriptor fetch mode */
end_comment

begin_define
define|#
directive|define
name|DCSR_RUN
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|DMAC_DINT
value|0x00f0
end_define

begin_comment
comment|/* DAM interrupt */
end_comment

begin_define
define|#
directive|define
name|DMAC_DINT_MASK
value|0xffffu
end_define

begin_define
define|#
directive|define
name|DMAC_DRCMR
parameter_list|(
name|n
parameter_list|)
value|(0x100+(n)*4)
end_define

begin_comment
comment|/* Channel map register */
end_comment

begin_define
define|#
directive|define
name|DRCMR_CHLNUM
value|0x0f
end_define

begin_comment
comment|/* channel number */
end_comment

begin_define
define|#
directive|define
name|DRCMR_MAPVLD
value|(1<<7)
end_define

begin_comment
comment|/* map valid */
end_comment

begin_define
define|#
directive|define
name|DMAC_DDADR
parameter_list|(
name|n
parameter_list|)
value|(0x0200+(n)*16)
end_define

begin_define
define|#
directive|define
name|DDADR_STOP
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|DMAC_DSADR
parameter_list|(
name|n
parameter_list|)
value|(0x0204+(n)*16)
end_define

begin_define
define|#
directive|define
name|DMAC_DTADR
parameter_list|(
name|n
parameter_list|)
value|(0x0208+(n)*16)
end_define

begin_define
define|#
directive|define
name|DMAC_DCMD
parameter_list|(
name|n
parameter_list|)
value|(0x020c+(n)*16)
end_define

begin_define
define|#
directive|define
name|DCMD_LENGTH_MASK
value|0x1fff
end_define

begin_define
define|#
directive|define
name|DCMD_WIDTH_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|DCMD_WIDTH_0
value|(0<<DCMD_WIDTH_SHIFT)
end_define

begin_comment
comment|/* for mem-to-mem transfer*/
end_comment

begin_define
define|#
directive|define
name|DCMD_WIDTH_1
value|(1<<DCMD_WIDTH_SHIFT)
end_define

begin_define
define|#
directive|define
name|DCMD_WIDTH_2
value|(2<<DCMD_WIDTH_SHIFT)
end_define

begin_define
define|#
directive|define
name|DCMD_WIDTH_4
value|(3<<DCMD_WIDTH_SHIFT)
end_define

begin_define
define|#
directive|define
name|DCMD_SIZE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|DCMD_SIZE_8
value|(1<<DCMD_SIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|DCMD_SIZE_16
value|(2<<DCMD_SIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|DCMD_SIZE_32
value|(3<<DCMD_SIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|DCMD_LITTLE_ENDIEN
value|(0<<18)
end_define

begin_define
define|#
directive|define
name|DCMD_ENDIRQEN
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|DCMD_STARTIRQEN
value|(1<<22)
end_define

begin_define
define|#
directive|define
name|DCMD_FLOWTRG
value|(1<<28)
end_define

begin_comment
comment|/* flow control by target */
end_comment

begin_define
define|#
directive|define
name|DCMD_FLOWSRC
value|(1<<29)
end_define

begin_comment
comment|/* flow control by source */
end_comment

begin_define
define|#
directive|define
name|DCMD_INCTRGADDR
value|(1<<30)
end_define

begin_comment
comment|/* increment target address */
end_comment

begin_define
define|#
directive|define
name|DCMD_INCSRCADDR
value|(1<<31)
end_define

begin_comment
comment|/* increment source address */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLER__
end_ifndef

begin_comment
comment|/* DMA descriptor */
end_comment

begin_struct
struct|struct
name|pxa_dma_desc
block|{
specifier|volatile
name|uint32_t
name|dd_ddadr
decl_stmt|;
define|#
directive|define
name|DMAC_DESC_LAST
value|0x1
specifier|volatile
name|uint32_t
name|dd_dsadr
decl_stmt|;
specifier|volatile
name|uint32_t
name|dd_dtadr
decl_stmt|;
specifier|volatile
name|uint32_t
name|dd_dcmd
decl_stmt|;
comment|/* command and length */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UART */
end_comment

begin_define
define|#
directive|define
name|PXA2X0_COM_FREQ
value|14745600L
end_define

begin_comment
comment|/* I2C */
end_comment

begin_define
define|#
directive|define
name|I2C_IBMR
value|0x1680
end_define

begin_comment
comment|/* Bus monitor register */
end_comment

begin_define
define|#
directive|define
name|I2C_IDBR
value|0x1688
end_define

begin_comment
comment|/* Data buffer */
end_comment

begin_define
define|#
directive|define
name|I2C_ICR
value|0x1690
end_define

begin_comment
comment|/* Control register */
end_comment

begin_define
define|#
directive|define
name|ICR_START
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|ICR_STOP
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|ICR_ACKNAK
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|ICR_TB
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|ICR_MA
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|I2C_ISR
value|0x1698
end_define

begin_comment
comment|/* Status register */
end_comment

begin_define
define|#
directive|define
name|I2C_ISAR
value|0x16a0
end_define

begin_comment
comment|/* Slave address */
end_comment

begin_comment
comment|/* Clock Manager */
end_comment

begin_define
define|#
directive|define
name|CLKMAN_CCCR
value|0x00
end_define

begin_comment
comment|/* Core Clock Configuration */
end_comment

begin_define
define|#
directive|define
name|CCCR_TURBO_X1
value|(2<<7)
end_define

begin_define
define|#
directive|define
name|CCCR_TURBO_X15
value|(3<<7)
end_define

begin_comment
comment|/* x 1.5 */
end_comment

begin_define
define|#
directive|define
name|CCCR_TURBO_X2
value|(4<<7)
end_define

begin_define
define|#
directive|define
name|CCCR_TURBO_X25
value|(5<<7)
end_define

begin_comment
comment|/* x 2.5 */
end_comment

begin_define
define|#
directive|define
name|CCCR_TURBO_X3
value|(6<<7)
end_define

begin_comment
comment|/* x 3.0 */
end_comment

begin_define
define|#
directive|define
name|CCCR_RUN_X1
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|CCCR_RUN_X2
value|(2<<5)
end_define

begin_define
define|#
directive|define
name|CCCR_RUN_X4
value|(3<<5)
end_define

begin_define
define|#
directive|define
name|CCCR_MEM_X27
value|(1<<0)
end_define

begin_comment
comment|/* x27, 99.53MHz */
end_comment

begin_define
define|#
directive|define
name|CCCR_MEM_X32
value|(2<<0)
end_define

begin_comment
comment|/* x32, 117,96MHz */
end_comment

begin_define
define|#
directive|define
name|CCCR_MEM_X36
value|(3<<0)
end_define

begin_comment
comment|/* x26, 132.71MHz */
end_comment

begin_define
define|#
directive|define
name|CCCR_MEM_X40
value|(4<<0)
end_define

begin_comment
comment|/* x27, 99.53MHz */
end_comment

begin_define
define|#
directive|define
name|CCCR_MEM_X45
value|(5<<0)
end_define

begin_comment
comment|/* x27, 99.53MHz */
end_comment

begin_define
define|#
directive|define
name|CCCR_MEM_X9
value|(0x1f<<0)
end_define

begin_comment
comment|/* x9, 33.2MHz */
end_comment

begin_define
define|#
directive|define
name|CLKMAN_CKEN
value|0x04
end_define

begin_comment
comment|/* Clock Enable Register */
end_comment

begin_define
define|#
directive|define
name|CLKMAN_OSCC
value|0x08
end_define

begin_comment
comment|/* Osillcator Configuration Register */
end_comment

begin_define
define|#
directive|define
name|CCCR_N_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|CCCR_N_MASK
value|(0x07<<CCCR_N_SHIFT)
end_define

begin_define
define|#
directive|define
name|CCCR_M_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|CCCR_M_MASK
value|(0x03<<CCCR_M_SHIFT)
end_define

begin_define
define|#
directive|define
name|CCCR_L_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|CKEN_PWM0
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|CKEN_PWM1
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|CKEN_AC97
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|CKEN_SSP
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|CKEN_STUART
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|CKEN_FFUART
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|CKEN_BTUART
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|CKEN_I2S
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|CKEN_USBH
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|CKEN_USB
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|CKEN_MMC
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|CKEN_FICP
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|CKEN_I2C
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|CKEN_LCD
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|OSCC_OOK
value|(1<<0)
end_define

begin_comment
comment|/* 32.768 kHz oscillator status */
end_comment

begin_define
define|#
directive|define
name|OSCC_OON
value|(1<<1)
end_define

begin_comment
comment|/* 32.768 kHz oscillator */
end_comment

begin_comment
comment|/*  * RTC  */
end_comment

begin_define
define|#
directive|define
name|RTC_RCNR
value|0x0000
end_define

begin_comment
comment|/* count register */
end_comment

begin_define
define|#
directive|define
name|RTC_RTAR
value|0x0004
end_define

begin_comment
comment|/* alarm register */
end_comment

begin_define
define|#
directive|define
name|RTC_RTSR
value|0x0008
end_define

begin_comment
comment|/* status register */
end_comment

begin_define
define|#
directive|define
name|RTC_RTTR
value|0x000c
end_define

begin_comment
comment|/* trim register */
end_comment

begin_comment
comment|/*  * GPIO  */
end_comment

begin_define
define|#
directive|define
name|GPIO_GPLR0
value|0x00
end_define

begin_comment
comment|/* Level reg [31:0] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GPLR1
value|0x04
end_define

begin_comment
comment|/* Level reg [63:32] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GPLR2
value|0x08
end_define

begin_comment
comment|/* Level reg [80:64] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GPDR0
value|0x0c
end_define

begin_comment
comment|/* dir reg [31:0] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GPDR1
value|0x10
end_define

begin_comment
comment|/* dir reg [63:32] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GPDR2
value|0x14
end_define

begin_comment
comment|/* dir reg [80:64] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GPSR0
value|0x18
end_define

begin_comment
comment|/* set reg [31:0] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GPSR1
value|0x1c
end_define

begin_comment
comment|/* set reg [63:32] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GPSR2
value|0x20
end_define

begin_comment
comment|/* set reg [80:64] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GPCR0
value|0x24
end_define

begin_comment
comment|/* clear reg [31:0] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GPCR1
value|0x28
end_define

begin_comment
comment|/* clear reg [63:32] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GPCR2
value|0x2c
end_define

begin_comment
comment|/* clear reg [80:64] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GPER0
value|0x30
end_define

begin_comment
comment|/* rising edge [31:0] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GPER1
value|0x34
end_define

begin_comment
comment|/* rising edge [63:32] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GPER2
value|0x38
end_define

begin_comment
comment|/* rising edge [80:64] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GRER0
value|0x30
end_define

begin_comment
comment|/* rising edge [31:0] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GRER1
value|0x34
end_define

begin_comment
comment|/* rising edge [63:32] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GRER2
value|0x38
end_define

begin_comment
comment|/* rising edge [80:64] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GFER0
value|0x3c
end_define

begin_comment
comment|/* falling edge [31:0] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GFER1
value|0x40
end_define

begin_comment
comment|/* falling edge [63:32] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GFER2
value|0x44
end_define

begin_comment
comment|/* falling edge [80:64] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GEDR0
value|0x48
end_define

begin_comment
comment|/* edge detect [31:0] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GEDR1
value|0x4c
end_define

begin_comment
comment|/* edge detect [63:32] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GEDR2
value|0x50
end_define

begin_comment
comment|/* edge detect [80:64] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GAFR0_L
value|0x54
end_define

begin_comment
comment|/* alternate function [15:0] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GAFR0_U
value|0x58
end_define

begin_comment
comment|/* alternate function [31:16] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GAFR1_L
value|0x5c
end_define

begin_comment
comment|/* alternate function [47:32] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GAFR1_U
value|0x60
end_define

begin_comment
comment|/* alternate function [63:48] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GAFR2_L
value|0x64
end_define

begin_comment
comment|/* alternate function [79:64] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GAFR2_U
value|0x68
end_define

begin_comment
comment|/* alternate function [80] */
end_comment

begin_comment
comment|/* Only for PXA270 */
end_comment

begin_define
define|#
directive|define
name|GPIO_GAFR3_L
value|0x6c
end_define

begin_comment
comment|/* alternate function [111:96] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GAFR3_U
value|0x70
end_define

begin_comment
comment|/* alternate function [120:112] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GPLR3
value|0x100
end_define

begin_comment
comment|/* Level reg [120:96] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GPDR3
value|0x10c
end_define

begin_comment
comment|/* dir reg [120:96] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GPSR3
value|0x118
end_define

begin_comment
comment|/* set reg [120:96] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GPCR3
value|0x124
end_define

begin_comment
comment|/* clear reg [120:96] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GRER3
value|0x130
end_define

begin_comment
comment|/* rising edge [120:96] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GFER3
value|0x13c
end_define

begin_comment
comment|/* falling edge [120:96] */
end_comment

begin_define
define|#
directive|define
name|GPIO_GEDR3
value|0x148
end_define

begin_comment
comment|/* edge detect [120:96] */
end_comment

begin_comment
comment|/* a bit simpler if we don't support PXA270 */
end_comment

begin_define
define|#
directive|define
name|PXA250_GPIO_REG
parameter_list|(
name|r
parameter_list|,
name|pin
parameter_list|)
value|((r) + (((pin) / 32) * 4))
end_define

begin_define
define|#
directive|define
name|PXA250_GPIO_NPINS
value|85
end_define

begin_define
define|#
directive|define
name|PXA270_GPIO_REG
parameter_list|(
name|r
parameter_list|,
name|pin
parameter_list|)
define|\
value|(pin< 96 ? PXA250_GPIO_REG(r,pin) : ((r) + 0x100 + ((((pin)-96) / 32) * 4)))
end_define

begin_define
define|#
directive|define
name|PXA270_GPIO_NPINS
value|121
end_define

begin_define
define|#
directive|define
name|GPIO_BANK
parameter_list|(
name|pin
parameter_list|)
value|((pin) / 32)
end_define

begin_define
define|#
directive|define
name|GPIO_BIT
parameter_list|(
name|pin
parameter_list|)
value|(1u<< ((pin)& 0x1f))
end_define

begin_define
define|#
directive|define
name|GPIO_FN_REG
parameter_list|(
name|pin
parameter_list|)
value|(GPIO_GAFR0_L + (((pin) / 16) * 4))
end_define

begin_define
define|#
directive|define
name|GPIO_FN_SHIFT
parameter_list|(
name|pin
parameter_list|)
value|((pin& 0xf) * 2)
end_define

begin_define
define|#
directive|define
name|GPIO_IN
value|0x00
end_define

begin_comment
comment|/* Regular GPIO input pin */
end_comment

begin_define
define|#
directive|define
name|GPIO_OUT
value|0x10
end_define

begin_comment
comment|/* Regular GPIO output pin */
end_comment

begin_define
define|#
directive|define
name|GPIO_ALT_FN_1_IN
value|0x01
end_define

begin_comment
comment|/* Alternate function 1 input */
end_comment

begin_define
define|#
directive|define
name|GPIO_ALT_FN_1_OUT
value|0x11
end_define

begin_comment
comment|/* Alternate function 1 output */
end_comment

begin_define
define|#
directive|define
name|GPIO_ALT_FN_2_IN
value|0x02
end_define

begin_comment
comment|/* Alternate function 2 input */
end_comment

begin_define
define|#
directive|define
name|GPIO_ALT_FN_2_OUT
value|0x12
end_define

begin_comment
comment|/* Alternate function 2 output */
end_comment

begin_define
define|#
directive|define
name|GPIO_ALT_FN_3_IN
value|0x03
end_define

begin_comment
comment|/* Alternate function 3 input */
end_comment

begin_define
define|#
directive|define
name|GPIO_ALT_FN_3_OUT
value|0x13
end_define

begin_comment
comment|/* Alternate function 3 output */
end_comment

begin_define
define|#
directive|define
name|GPIO_SET
value|0x20
end_define

begin_comment
comment|/* Initial state is Set */
end_comment

begin_define
define|#
directive|define
name|GPIO_CLR
value|0x00
end_define

begin_comment
comment|/* Initial state is Clear */
end_comment

begin_define
define|#
directive|define
name|GPIO_FN_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|GPIO_FN_IS_OUT
parameter_list|(
name|n
parameter_list|)
value|((n)& GPIO_OUT)
end_define

begin_define
define|#
directive|define
name|GPIO_FN_IS_SET
parameter_list|(
name|n
parameter_list|)
value|((n)& GPIO_SET)
end_define

begin_define
define|#
directive|define
name|GPIO_FN
parameter_list|(
name|n
parameter_list|)
value|((n)& GPIO_FN_MASK)
end_define

begin_define
define|#
directive|define
name|GPIO_IS_GPIO
parameter_list|(
name|n
parameter_list|)
value|(GPIO_FN(n) == 0)
end_define

begin_define
define|#
directive|define
name|GPIO_IS_GPIO_IN
parameter_list|(
name|n
parameter_list|)
value|(((n)& (GPIO_FN_MASK|GPIO_OUT)) == GPIO_IN)
end_define

begin_define
define|#
directive|define
name|GPIO_IS_GPIO_OUT
parameter_list|(
name|n
parameter_list|)
value|(((n)& (GPIO_FN_MASK|GPIO_OUT)) == GPIO_OUT)
end_define

begin_define
define|#
directive|define
name|IRQ_GPIO0
value|64
end_define

begin_define
define|#
directive|define
name|IRQ_NGPIO
value|128
end_define

begin_define
define|#
directive|define
name|IRQ_GPIO_MAX
value|IRQ_GPIO0 + IRQ_NGPIO
end_define

begin_define
define|#
directive|define
name|IRQ_TO_GPIO
parameter_list|(
name|x
parameter_list|)
value|(x - IRQ_GPIO0)
end_define

begin_define
define|#
directive|define
name|GPIO_TO_IRQ
parameter_list|(
name|x
parameter_list|)
value|(x + IRQ_GPIO0)
end_define

begin_comment
comment|/*  * memory controller  */
end_comment

begin_define
define|#
directive|define
name|MEMCTL_MDCNFG
value|0x0000
end_define

begin_define
define|#
directive|define
name|MDCNFG_DE0
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|MDCNFG_DE1
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|MDCNFD_DWID01_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|MDCNFD_DCAC01_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|MDCNFD_DRAC01_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|MDCNFD_DNB01_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|MDCNFG_DE2
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|MDCNFG_DE3
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|MDCNFD_DWID23_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|MDCNFD_DCAC23_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|MDCNFD_DRAC23_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|MDCNFD_DNB23_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|MDCNFD_DWID_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|MDCNFD_DCAC_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|MDCNFD_DRAC_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|MDCNFD_DNB_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|MEMCTL_MDREFR
value|0x04
end_define

begin_comment
comment|/* refresh control register */
end_comment

begin_define
define|#
directive|define
name|MDREFR_DRI
value|0xfff
end_define

begin_define
define|#
directive|define
name|MDREFR_E0PIN
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|MDREFR_K0RUN
value|(1<<13)
end_define

begin_comment
comment|/* SDCLK0 enable */
end_comment

begin_define
define|#
directive|define
name|MDREFR_K0DB2
value|(1<<14)
end_define

begin_comment
comment|/* SDCLK0 1/2 freq */
end_comment

begin_define
define|#
directive|define
name|MDREFR_E1PIN
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|MDREFR_K1RUN
value|(1<<16)
end_define

begin_comment
comment|/* SDCLK1 enable */
end_comment

begin_define
define|#
directive|define
name|MDREFR_K1DB2
value|(1<<17)
end_define

begin_comment
comment|/* SDCLK1 1/2 freq */
end_comment

begin_define
define|#
directive|define
name|MDREFR_K2RUN
value|(1<<18)
end_define

begin_comment
comment|/* SDCLK2 enable */
end_comment

begin_define
define|#
directive|define
name|MDREFR_K2DB2
value|(1<<19)
end_define

begin_comment
comment|/* SDCLK2 1/2 freq */
end_comment

begin_define
define|#
directive|define
name|MDREFR_APD
value|(1<<20)
end_define

begin_comment
comment|/* Auto Power Down */
end_comment

begin_define
define|#
directive|define
name|MDREFR_SLFRSH
value|(1<<22)
end_define

begin_comment
comment|/* Self Refresh */
end_comment

begin_define
define|#
directive|define
name|MDREFR_K0FREE
value|(1<<23)
end_define

begin_comment
comment|/* SDCLK0 free run */
end_comment

begin_define
define|#
directive|define
name|MDREFR_K1FREE
value|(1<<24)
end_define

begin_comment
comment|/* SDCLK1 free run */
end_comment

begin_define
define|#
directive|define
name|MDREFR_K2FREE
value|(1<<25)
end_define

begin_comment
comment|/* SDCLK2 free run */
end_comment

begin_define
define|#
directive|define
name|MEMCTL_MSC0
value|0x08
end_define

begin_comment
comment|/* Asychronous Statis memory Control CS[01] */
end_comment

begin_define
define|#
directive|define
name|MEMCTL_MSC1
value|0x0c
end_define

begin_comment
comment|/* Asychronous Statis memory Control CS[23] */
end_comment

begin_define
define|#
directive|define
name|MEMCTL_MSC2
value|0x10
end_define

begin_comment
comment|/* Asychronous Statis memory Control CS[45] */
end_comment

begin_define
define|#
directive|define
name|MSC_RBUFF_SHIFT
value|15
end_define

begin_comment
comment|/* return data buffer */
end_comment

begin_define
define|#
directive|define
name|MSC_RBUFF
value|(1<<MSC_RBUFF_SHIFT)
end_define

begin_define
define|#
directive|define
name|MSC_RRR_SHIFT
value|12
end_define

begin_comment
comment|/* recovery time */
end_comment

begin_define
define|#
directive|define
name|MSC_RRR
value|(7<<MSC_RRR_SHIFT)
end_define

begin_define
define|#
directive|define
name|MSC_RDN_SHIFT
value|8
end_define

begin_comment
comment|/* ROM delay next access */
end_comment

begin_define
define|#
directive|define
name|MSC_RDN
value|(0x0f<<MSC_RDN_SHIFT)
end_define

begin_define
define|#
directive|define
name|MSC_RDF_SHIFT
value|4
end_define

begin_comment
comment|/*  ROM delay first access*/
end_comment

begin_define
define|#
directive|define
name|MSC_RDF
value|(0x0f<<MSC_RDF_SHIFT)
end_define

begin_define
define|#
directive|define
name|MSC_RBW_SHIFT
value|3
end_define

begin_comment
comment|/* 32/16 bit bus */
end_comment

begin_define
define|#
directive|define
name|MSC_RBW
value|(1<<MSC_RBW_SHIFT)
end_define

begin_define
define|#
directive|define
name|MSC_RT_SHIFT
value|0
end_define

begin_comment
comment|/* type */
end_comment

begin_define
define|#
directive|define
name|MSC_RT
value|(7<<MSC_RT_SHIFT)
end_define

begin_define
define|#
directive|define
name|MSC_RT_NONBURST
value|0
end_define

begin_define
define|#
directive|define
name|MSC_RT_SRAM
value|1
end_define

begin_define
define|#
directive|define
name|MSC_RT_BURST4
value|2
end_define

begin_define
define|#
directive|define
name|MSC_RT_BURST8
value|3
end_define

begin_define
define|#
directive|define
name|MSC_RT_VLIO
value|4
end_define

begin_comment
comment|/* expansion memory timing configuration */
end_comment

begin_define
define|#
directive|define
name|MEMCTL_MCMEM
parameter_list|(
name|n
parameter_list|)
value|(0x28+4*(n))
end_define

begin_define
define|#
directive|define
name|MEMCTL_MCATT
parameter_list|(
name|n
parameter_list|)
value|(0x30+4*(n))
end_define

begin_define
define|#
directive|define
name|MEMCTL_MCIO
parameter_list|(
name|n
parameter_list|)
value|(0x38+4*(n))
end_define

begin_define
define|#
directive|define
name|MC_HOLD_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|MC_ASST_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|MC_SET_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|MC_TIMING_VAL
parameter_list|(
name|hold
parameter_list|,
name|asst
parameter_list|,
name|set
parameter_list|)
value|(((hold)<<MC_HOLD_SHIFT)| \ 		((asst)<<MC_ASST_SHIFT)|((set)<<MC_SET_SHIFT))
end_define

begin_define
define|#
directive|define
name|MEMCTL_MECR
value|0x14
end_define

begin_comment
comment|/* Expansion memory configuration */
end_comment

begin_define
define|#
directive|define
name|MECR_NOS
value|(1<<0)
end_define

begin_comment
comment|/* Number of sockets */
end_comment

begin_define
define|#
directive|define
name|MECR_CIT
value|(1<<1)
end_define

begin_comment
comment|/* Card-is-there */
end_comment

begin_define
define|#
directive|define
name|MEMCTL_MDMRS
value|0x0040
end_define

begin_comment
comment|/*  * LCD Controller  */
end_comment

begin_define
define|#
directive|define
name|LCDC_LCCR0
value|0x000
end_define

begin_comment
comment|/* Controller Control Register 0 */
end_comment

begin_define
define|#
directive|define
name|LCCR0_ENB
value|(1U<<0)
end_define

begin_comment
comment|/* LCD Controller Enable */
end_comment

begin_define
define|#
directive|define
name|LCCR0_CMS
value|(1U<<1)
end_define

begin_comment
comment|/* Color/Mono select */
end_comment

begin_define
define|#
directive|define
name|LCCR0_SDS
value|(1U<<2)
end_define

begin_comment
comment|/* Single/Dual -panel */
end_comment

begin_define
define|#
directive|define
name|LCCR0_LDM
value|(1U<<3)
end_define

begin_comment
comment|/* LCD Disable Done Mask */
end_comment

begin_define
define|#
directive|define
name|LCCR0_SFM
value|(1U<<4)
end_define

begin_comment
comment|/* Start of Frame Mask */
end_comment

begin_define
define|#
directive|define
name|LCCR0_IUM
value|(1U<<5)
end_define

begin_comment
comment|/* Input FIFO Underrun Mask */
end_comment

begin_define
define|#
directive|define
name|LCCR0_EFM
value|(1U<<6)
end_define

begin_comment
comment|/* End of Frame Mask */
end_comment

begin_define
define|#
directive|define
name|LCCR0_PAS
value|(1U<<7)
end_define

begin_comment
comment|/* Passive/Active Display select */
end_comment

begin_define
define|#
directive|define
name|LCCR0_DPD
value|(1U<<9)
end_define

begin_comment
comment|/* Double-Pixel Data pin mode */
end_comment

begin_define
define|#
directive|define
name|LCCR0_DIS
value|(1U<<10)
end_define

begin_comment
comment|/* LCD Disable */
end_comment

begin_define
define|#
directive|define
name|LCCR0_QDM
value|(1U<<11)
end_define

begin_comment
comment|/* LCD Quick Disable Mask */
end_comment

begin_define
define|#
directive|define
name|LCCR0_BM
value|(1U<<20)
end_define

begin_comment
comment|/* Branch Mask */
end_comment

begin_define
define|#
directive|define
name|LCCR0_OUM
value|(1U<<21)
end_define

begin_comment
comment|/* Output FIFO Underrun Mask */
end_comment

begin_define
define|#
directive|define
name|LCCR0_IMASK
value|(LCCR0_LDM|LCCR0_SFM|LCCR0_IUM|LCCR0_EFM|LCCR0_QDM|LCCR0_BM|LCCR0_OUM)
end_define

begin_define
define|#
directive|define
name|LCDC_LCCR1
value|0x004
end_define

begin_comment
comment|/* Controller Control Register 1 */
end_comment

begin_define
define|#
directive|define
name|LCDC_LCCR2
value|0x008
end_define

begin_comment
comment|/* Controller Control Register 2 */
end_comment

begin_define
define|#
directive|define
name|LCDC_LCCR3
value|0x00c
end_define

begin_comment
comment|/* Controller Control Register 2 */
end_comment

begin_define
define|#
directive|define
name|LCCR3_BPP_SHIFT
value|24
end_define

begin_comment
comment|/* Bits per pixel */
end_comment

begin_define
define|#
directive|define
name|LCCR3_BPP
value|(0x07<<LCCR3_BPP_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDC_LCCR4
value|0x010
end_define

begin_comment
comment|/* Controller Control Register 4 */
end_comment

begin_define
define|#
directive|define
name|LCDC_LCCR5
value|0x014
end_define

begin_comment
comment|/* Controller Control Register 5 */
end_comment

begin_define
define|#
directive|define
name|LCDC_FBR0
value|0x020
end_define

begin_comment
comment|/* DMA ch0 frame branch register */
end_comment

begin_define
define|#
directive|define
name|LCDC_FBR1
value|0x024
end_define

begin_comment
comment|/* DMA ch1 frame branch register */
end_comment

begin_define
define|#
directive|define
name|LCDC_FBR2
value|0x028
end_define

begin_comment
comment|/* DMA ch2 frame branch register */
end_comment

begin_define
define|#
directive|define
name|LCDC_FBR3
value|0x02c
end_define

begin_comment
comment|/* DMA ch3 frame branch register */
end_comment

begin_define
define|#
directive|define
name|LCDC_FBR4
value|0x030
end_define

begin_comment
comment|/* DMA ch4 frame branch register */
end_comment

begin_define
define|#
directive|define
name|LCDC_LCSR1
value|0x034
end_define

begin_comment
comment|/* controller status register 1 PXA27x only */
end_comment

begin_define
define|#
directive|define
name|LCDC_LCSR
value|0x038
end_define

begin_comment
comment|/* controller status register */
end_comment

begin_define
define|#
directive|define
name|LCSR_LDD
value|(1U<<0)
end_define

begin_comment
comment|/* LCD disable done */
end_comment

begin_define
define|#
directive|define
name|LCSR_SOF
value|(1U<<1)
end_define

begin_comment
comment|/* Start of frame */
end_comment

begin_define
define|#
directive|define
name|LCDC_LIIDR
value|0x03c
end_define

begin_comment
comment|/* controller interrupt ID Register */
end_comment

begin_define
define|#
directive|define
name|LCDC_TRGBR
value|0x040
end_define

begin_comment
comment|/* TMED RGB Speed Register */
end_comment

begin_define
define|#
directive|define
name|LCDC_TCR
value|0x044
end_define

begin_comment
comment|/* TMED Control Register */
end_comment

begin_define
define|#
directive|define
name|LCDC_OVL1C1
value|0x050
end_define

begin_comment
comment|/* Overlay 1 control register 1 */
end_comment

begin_define
define|#
directive|define
name|LCDC_OVL1C2
value|0x060
end_define

begin_comment
comment|/* Overlay 1 control register 2 */
end_comment

begin_define
define|#
directive|define
name|LCDC_OVL2C1
value|0x070
end_define

begin_comment
comment|/* Overlay 1 control register 1 */
end_comment

begin_define
define|#
directive|define
name|LCDC_OVL2C2
value|0x080
end_define

begin_comment
comment|/* Overlay 1 control register 2 */
end_comment

begin_define
define|#
directive|define
name|LCDC_CCR
value|0x090
end_define

begin_comment
comment|/* Cursor control register */
end_comment

begin_define
define|#
directive|define
name|LCDC_CMDCR
value|0x100
end_define

begin_comment
comment|/* Command control register */
end_comment

begin_define
define|#
directive|define
name|LCDC_PRSR
value|0x104
end_define

begin_comment
comment|/* Panel read status register */
end_comment

begin_define
define|#
directive|define
name|LCDC_FBR5
value|0x110
end_define

begin_comment
comment|/* DMA ch5 frame branch register */
end_comment

begin_define
define|#
directive|define
name|LCDC_FBR6
value|0x114
end_define

begin_comment
comment|/* DMA ch6 frame branch register */
end_comment

begin_define
define|#
directive|define
name|LCDC_FDADR0
value|0x200
end_define

begin_comment
comment|/* DMA ch0 frame descriptor address */
end_comment

begin_define
define|#
directive|define
name|LCDC_FSADR0
value|0x204
end_define

begin_comment
comment|/* DMA ch0 frame source address */
end_comment

begin_define
define|#
directive|define
name|LCDC_FIDR0
value|0x208
end_define

begin_comment
comment|/* DMA ch0 frame ID register */
end_comment

begin_define
define|#
directive|define
name|LCDC_LDCMD0
value|0x20c
end_define

begin_comment
comment|/* DMA ch0 command register */
end_comment

begin_define
define|#
directive|define
name|LCDC_FDADR1
value|0x210
end_define

begin_comment
comment|/* DMA ch1 frame descriptor address */
end_comment

begin_define
define|#
directive|define
name|LCDC_FSADR1
value|0x214
end_define

begin_comment
comment|/* DMA ch1 frame source address */
end_comment

begin_define
define|#
directive|define
name|LCDC_FIDR1
value|0x218
end_define

begin_comment
comment|/* DMA ch1 frame ID register */
end_comment

begin_define
define|#
directive|define
name|LCDC_LDCMD1
value|0x21c
end_define

begin_comment
comment|/* DMA ch1 command register */
end_comment

begin_define
define|#
directive|define
name|LCDC_FDADR2
value|0x220
end_define

begin_comment
comment|/* DMA ch2 frame descriptor address */
end_comment

begin_define
define|#
directive|define
name|LCDC_FSADR2
value|0x224
end_define

begin_comment
comment|/* DMA ch2 frame source address */
end_comment

begin_define
define|#
directive|define
name|LCDC_FIDR2
value|0x228
end_define

begin_comment
comment|/* DMA ch2 frame ID register */
end_comment

begin_define
define|#
directive|define
name|LCDC_LDCMD2
value|0x22c
end_define

begin_comment
comment|/* DMA ch2 command register */
end_comment

begin_define
define|#
directive|define
name|LCDC_FDADR3
value|0x230
end_define

begin_comment
comment|/* DMA ch3 frame descriptor address */
end_comment

begin_define
define|#
directive|define
name|LCDC_FSADR3
value|0x234
end_define

begin_comment
comment|/* DMA ch3 frame source address */
end_comment

begin_define
define|#
directive|define
name|LCDC_FIDR3
value|0x238
end_define

begin_comment
comment|/* DMA ch3 frame ID register */
end_comment

begin_define
define|#
directive|define
name|LCDC_LDCMD3
value|0x23c
end_define

begin_comment
comment|/* DMA ch3 command register */
end_comment

begin_define
define|#
directive|define
name|LCDC_FDADR4
value|0x240
end_define

begin_comment
comment|/* DMA ch4 frame descriptor address */
end_comment

begin_define
define|#
directive|define
name|LCDC_FSADR4
value|0x244
end_define

begin_comment
comment|/* DMA ch4 frame source address */
end_comment

begin_define
define|#
directive|define
name|LCDC_FIDR4
value|0x248
end_define

begin_comment
comment|/* DMA ch4 frame ID register */
end_comment

begin_define
define|#
directive|define
name|LCDC_LDCMD4
value|0x24c
end_define

begin_comment
comment|/* DMA ch4 command register */
end_comment

begin_define
define|#
directive|define
name|LCDC_FDADR5
value|0x250
end_define

begin_comment
comment|/* DMA ch5 frame descriptor address */
end_comment

begin_define
define|#
directive|define
name|LCDC_FSADR5
value|0x254
end_define

begin_comment
comment|/* DMA ch5 frame source address */
end_comment

begin_define
define|#
directive|define
name|LCDC_FIDR5
value|0x258
end_define

begin_comment
comment|/* DMA ch5 frame ID register */
end_comment

begin_define
define|#
directive|define
name|LCDC_LDCMD5
value|0x25c
end_define

begin_comment
comment|/* DMA ch5 command register */
end_comment

begin_define
define|#
directive|define
name|LCDC_FDADR6
value|0x260
end_define

begin_comment
comment|/* DMA ch6 frame descriptor address */
end_comment

begin_define
define|#
directive|define
name|LCDC_FSADR6
value|0x264
end_define

begin_comment
comment|/* DMA ch6 frame source address */
end_comment

begin_define
define|#
directive|define
name|LCDC_FIDR6
value|0x268
end_define

begin_comment
comment|/* DMA ch6 frame ID register */
end_comment

begin_define
define|#
directive|define
name|LCDC_LDCMD6
value|0x26c
end_define

begin_comment
comment|/* DMA ch6 command register */
end_comment

begin_define
define|#
directive|define
name|LCDC_LCDBSCNTR
value|0x054
end_define

begin_comment
comment|/* LCD buffer strength control register */
end_comment

begin_comment
comment|/*  * MMC/SD controller  */
end_comment

begin_define
define|#
directive|define
name|MMC_STRPCL
value|0x00
end_define

begin_comment
comment|/* start/stop MMC clock */
end_comment

begin_define
define|#
directive|define
name|STRPCL_NOOP
value|0
end_define

begin_define
define|#
directive|define
name|STRPCL_STOP
value|1
end_define

begin_comment
comment|/* stop MMC clock */
end_comment

begin_define
define|#
directive|define
name|STRPCL_START
value|2
end_define

begin_comment
comment|/* start MMC clock */
end_comment

begin_define
define|#
directive|define
name|MMC_STAT
value|0x04
end_define

begin_comment
comment|/* status register */
end_comment

begin_define
define|#
directive|define
name|STAT_READ_TIME_OUT
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|STAT_TIMEOUT_RESPONSE
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|STAT_CRC_WRITE_ERROR
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|STAT_CRC_READ_ERROR
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|STAT_SPI_READ_ERROR_TOKEN
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|STAT_RES_CRC_ERR
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|STAT_XMIT_FIFO_EMPTY
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|STAT_RECV_FIFO_FULL
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|STAT_CLK_EN
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|STAT_DATA_TRAN_DONE
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|STAT_PRG_DONE
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|STAT_END_CMD_RES
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|MMC_CLKRT
value|0x08
end_define

begin_comment
comment|/* MMC clock rate */
end_comment

begin_define
define|#
directive|define
name|CLKRT_20M
value|0
end_define

begin_define
define|#
directive|define
name|CLKRT_10M
value|1
end_define

begin_define
define|#
directive|define
name|CLKRT_5M
value|2
end_define

begin_define
define|#
directive|define
name|CLKRT_2_5M
value|3
end_define

begin_define
define|#
directive|define
name|CLKRT_1_25M
value|4
end_define

begin_define
define|#
directive|define
name|CLKRT_625K
value|5
end_define

begin_define
define|#
directive|define
name|CLKRT_312K
value|6
end_define

begin_define
define|#
directive|define
name|MMC_SPI
value|0x0c
end_define

begin_comment
comment|/* SPI mode control */
end_comment

begin_define
define|#
directive|define
name|SPI_EN
value|(1<<0)
end_define

begin_comment
comment|/* enable SPI mode */
end_comment

begin_define
define|#
directive|define
name|SPI_CRC_ON
value|(1<<1)
end_define

begin_comment
comment|/* enable CRC generation */
end_comment

begin_define
define|#
directive|define
name|SPI_CS_EN
value|(1<<2)
end_define

begin_comment
comment|/* Enable CS[01] */
end_comment

begin_define
define|#
directive|define
name|SPI_CS_ADDRESS
value|(1<<3)
end_define

begin_comment
comment|/* CS0/CS1 */
end_comment

begin_define
define|#
directive|define
name|MMC_CMDAT
value|0x10
end_define

begin_comment
comment|/* command/response/data */
end_comment

begin_define
define|#
directive|define
name|CMDAT_RESPONSE_FORMAT
value|0x03
end_define

begin_define
define|#
directive|define
name|CMDAT_RESPONSE_FORMAT_NO
value|0
end_define

begin_comment
comment|/* no response */
end_comment

begin_define
define|#
directive|define
name|CMDAT_RESPONSE_FORMAT_R1
value|1
end_define

begin_comment
comment|/* R1, R1b, R4, R5 */
end_comment

begin_define
define|#
directive|define
name|CMDAT_RESPONSE_FORMAT_R2
value|2
end_define

begin_define
define|#
directive|define
name|CMDAT_RESPONSE_FORMAT_R3
value|3
end_define

begin_define
define|#
directive|define
name|CMDAT_DATA_EN
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|CMDAT_WRITE
value|(1<<3)
end_define

begin_comment
comment|/* 1=write 0=read operation */
end_comment

begin_define
define|#
directive|define
name|CMDAT_STREAM_BLOCK
value|(1<<4)
end_define

begin_comment
comment|/* stream mode */
end_comment

begin_define
define|#
directive|define
name|CMDAT_BUSY
value|(1<<5)
end_define

begin_comment
comment|/* busy signal is expected */
end_comment

begin_define
define|#
directive|define
name|CMDAT_INIT
value|(1<<6)
end_define

begin_comment
comment|/* preceede command with 80 clocks */
end_comment

begin_define
define|#
directive|define
name|CMDAT_MMC_DMA_EN
value|(1<<7)
end_define

begin_comment
comment|/* DMA enable */
end_comment

begin_define
define|#
directive|define
name|MMC_RESTO
value|0x14
end_define

begin_comment
comment|/* expected response time out */
end_comment

begin_define
define|#
directive|define
name|MMC_RDTO
value|0x18
end_define

begin_comment
comment|/* expected data read time out */
end_comment

begin_define
define|#
directive|define
name|MMC_BLKLEN
value|0x1c
end_define

begin_comment
comment|/* block length of data transaction */
end_comment

begin_define
define|#
directive|define
name|MMC_NOB
value|0x20
end_define

begin_comment
comment|/* number of blocks (block mode) */
end_comment

begin_define
define|#
directive|define
name|MMC_PRTBUF
value|0x24
end_define

begin_comment
comment|/* partial MMC_TXFIFO written */
end_comment

begin_define
define|#
directive|define
name|PRTBUF_BUF_PART_FULL
value|(1<<0)
end_define

begin_comment
comment|/* buffer partially full */
end_comment

begin_define
define|#
directive|define
name|MMC_I_MASK
value|0x28
end_define

begin_comment
comment|/* interrupt mask */
end_comment

begin_define
define|#
directive|define
name|MMC_I_REG
value|0x2c
end_define

begin_comment
comment|/* interrupt register */
end_comment

begin_define
define|#
directive|define
name|MMC_I_DATA_TRAN_DONE
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|MMC_I_PRG_DONE
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|MMC_I_END_CMD_RES
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|MMC_I_STOP_CMD
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|MMC_I_CLK_IS_OFF
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|MMC_I_RXFIFO_RD_REQ
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|MMC_I_TXFIFO_WR_REQ
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|MMC_CMD
value|0x30
end_define

begin_comment
comment|/* index of current command */
end_comment

begin_define
define|#
directive|define
name|MMC_ARGH
value|0x34
end_define

begin_comment
comment|/* MSW part of the current command arg */
end_comment

begin_define
define|#
directive|define
name|MMC_ARGL
value|0x38
end_define

begin_comment
comment|/* LSW part of the current command arg */
end_comment

begin_define
define|#
directive|define
name|MMC_RES
value|0x3c
end_define

begin_comment
comment|/* response FIFO */
end_comment

begin_define
define|#
directive|define
name|MMC_RXFIFO
value|0x40
end_define

begin_comment
comment|/* receive FIFO */
end_comment

begin_define
define|#
directive|define
name|MMC_TXFIFO
value|0x44
end_define

begin_comment
comment|/* transmit FIFO */
end_comment

begin_comment
comment|/*  * AC97  */
end_comment

begin_define
define|#
directive|define
name|AC97_N_CODECS
value|2
end_define

begin_define
define|#
directive|define
name|AC97_GCR
value|0x000c
end_define

begin_comment
comment|/* Global control register */
end_comment

begin_define
define|#
directive|define
name|GCR_GIE
value|(1<<0)
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|GCR_COLD_RST
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|GCR_WARM_RST
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|GCR_ACLINK_OFF
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|GCR_PRIRES_IEN
value|(1<<4)
end_define

begin_comment
comment|/* Primary resume interrupt enable */
end_comment

begin_define
define|#
directive|define
name|GCR_SECRES_IEN
value|(1<<5)
end_define

begin_comment
comment|/* Secondary resume interrupt enable */
end_comment

begin_define
define|#
directive|define
name|GCR_PRIRDY_IEN
value|(1<<8)
end_define

begin_comment
comment|/* Primary ready interrupt enable */
end_comment

begin_define
define|#
directive|define
name|GCR_SECRDY_IEN
value|(1<<9)
end_define

begin_comment
comment|/* Primary ready interrupt enable */
end_comment

begin_define
define|#
directive|define
name|GCR_SDONE_IE
value|(1<<18)
end_define

begin_comment
comment|/* Status done interrupt enable */
end_comment

begin_define
define|#
directive|define
name|GCR_CDONE_IE
value|(1<<19)
end_define

begin_comment
comment|/* Command done interrupt enable */
end_comment

begin_define
define|#
directive|define
name|AC97_GSR
value|0x001c
end_define

begin_comment
comment|/* Global status register */
end_comment

begin_define
define|#
directive|define
name|GSR_GSCI
value|(1<<0)
end_define

begin_comment
comment|/* codec GPI status change interrupt */
end_comment

begin_define
define|#
directive|define
name|GSR_MIINT
value|(1<<1)
end_define

begin_comment
comment|/* modem in interrupt */
end_comment

begin_define
define|#
directive|define
name|GSR_MOINT
value|(1<<2)
end_define

begin_comment
comment|/* modem out interrupt */
end_comment

begin_define
define|#
directive|define
name|GSR_PIINT
value|(1<<5)
end_define

begin_comment
comment|/* PCM in interrupt */
end_comment

begin_define
define|#
directive|define
name|GSR_POINT
value|(1<<6)
end_define

begin_comment
comment|/* PCM out interrupt */
end_comment

begin_define
define|#
directive|define
name|GSR_MINT
value|(1<<7)
end_define

begin_comment
comment|/* Mic in interrupt */
end_comment

begin_define
define|#
directive|define
name|GSR_PCR
value|(1<<8)
end_define

begin_comment
comment|/* primary code ready */
end_comment

begin_define
define|#
directive|define
name|GSR_SCR
value|(1<<9)
end_define

begin_comment
comment|/* secondary code ready */
end_comment

begin_define
define|#
directive|define
name|GSR_PRIRES
value|(1<<10)
end_define

begin_comment
comment|/* primary resume interrupt */
end_comment

begin_define
define|#
directive|define
name|GSR_SECRES
value|(1<<11)
end_define

begin_comment
comment|/* secondary resume interrupt */
end_comment

begin_define
define|#
directive|define
name|GSR_BIT1SLT12
value|(1<<12)
end_define

begin_comment
comment|/* Bit 1 of slot 12 */
end_comment

begin_define
define|#
directive|define
name|GSR_BIT2SLT12
value|(1<<13)
end_define

begin_comment
comment|/* Bit 2 of slot 12 */
end_comment

begin_define
define|#
directive|define
name|GSR_BIT3SLT12
value|(1<<14)
end_define

begin_comment
comment|/* Bit 3 of slot 12 */
end_comment

begin_define
define|#
directive|define
name|GSR_RDCS
value|(1<<15)
end_define

begin_comment
comment|/* Read completion status */
end_comment

begin_define
define|#
directive|define
name|GSR_SDONE
value|(1<<18)
end_define

begin_comment
comment|/* status done */
end_comment

begin_define
define|#
directive|define
name|GSR_CDONE
value|(1<<19)
end_define

begin_comment
comment|/* command done */
end_comment

begin_define
define|#
directive|define
name|AC97_POCR
value|0x0000
end_define

begin_comment
comment|/* PCM-out control */
end_comment

begin_define
define|#
directive|define
name|AC97_PICR
value|0x0004
end_define

begin_comment
comment|/* PCM-in control */
end_comment

begin_define
define|#
directive|define
name|AC97_POSR
value|0x0010
end_define

begin_comment
comment|/* PCM-out status */
end_comment

begin_define
define|#
directive|define
name|AC97_PISR
value|0x0014
end_define

begin_comment
comment|/* PCM-out status */
end_comment

begin_define
define|#
directive|define
name|AC97_MCCR
value|0x0008
end_define

begin_comment
comment|/* MIC-in control register */
end_comment

begin_define
define|#
directive|define
name|AC97_MCSR
value|0x0018
end_define

begin_comment
comment|/* MIC-in status register */
end_comment

begin_define
define|#
directive|define
name|AC97_MICR
value|0x0100
end_define

begin_comment
comment|/* Modem-in control register */
end_comment

begin_define
define|#
directive|define
name|AC97_MISR
value|0x0108
end_define

begin_comment
comment|/* Modem-in status register */
end_comment

begin_define
define|#
directive|define
name|AC97_MOCR
value|0x0110
end_define

begin_comment
comment|/* Modem-out control register */
end_comment

begin_define
define|#
directive|define
name|AC97_MOSR
value|0x0118
end_define

begin_comment
comment|/* Modem-out status register */
end_comment

begin_define
define|#
directive|define
name|AC97_FEFIE
value|(1<<3)
end_define

begin_comment
comment|/* fifo error interrupt enable */
end_comment

begin_define
define|#
directive|define
name|AC97_FIFOE
value|(1<<4)
end_define

begin_comment
comment|/* fifo error */
end_comment

begin_define
define|#
directive|define
name|AC97_CAR
value|0x0020
end_define

begin_comment
comment|/* Codec access register */
end_comment

begin_define
define|#
directive|define
name|CAR_CAIP
value|(1<<0)
end_define

begin_comment
comment|/* Codec access in progress */
end_comment

begin_define
define|#
directive|define
name|AC97_PCDR
value|0x0040
end_define

begin_comment
comment|/* PCM data register */
end_comment

begin_define
define|#
directive|define
name|AC97_MCDR
value|0x0060
end_define

begin_comment
comment|/* MIC-in data register */
end_comment

begin_define
define|#
directive|define
name|AC97_MODR
value|0x0140
end_define

begin_comment
comment|/* Modem data register */
end_comment

begin_comment
comment|/* address to access codec registers */
end_comment

begin_define
define|#
directive|define
name|AC97_PRIAUDIO
value|0x0200
end_define

begin_comment
comment|/* Primary audio codec */
end_comment

begin_define
define|#
directive|define
name|AC97_SECAUDIO
value|0x0300
end_define

begin_comment
comment|/* Secondary autio codec */
end_comment

begin_define
define|#
directive|define
name|AC97_PRIMODEM
value|0x0400
end_define

begin_comment
comment|/* Primary modem codec */
end_comment

begin_define
define|#
directive|define
name|AC97_SECMODEM
value|0x0500
end_define

begin_comment
comment|/* Secondary modem codec */
end_comment

begin_define
define|#
directive|define
name|AC97_CODEC_BASE
parameter_list|(
name|c
parameter_list|)
value|(AC97_PRIAUDIO + ((c) * 0x100))
end_define

begin_comment
comment|/*  * USB device controller  */
end_comment

begin_define
define|#
directive|define
name|USBDC_UDCCR
value|0x0000
end_define

begin_comment
comment|/* UDC control register    */
end_comment

begin_define
define|#
directive|define
name|USBDC_UDCCS
parameter_list|(
name|n
parameter_list|)
value|(0x0010+4*(n))
end_define

begin_comment
comment|/* Endpoint Control/Status Registers */
end_comment

begin_define
define|#
directive|define
name|USBDC_UICR0
value|0x0050
end_define

begin_comment
comment|/* UDC Interrupt Control Register 0  */
end_comment

begin_define
define|#
directive|define
name|USBDC_UICR1
value|0x0054
end_define

begin_comment
comment|/* UDC Interrupt Control Register 1  */
end_comment

begin_define
define|#
directive|define
name|USBDC_USIR0
value|0x0058
end_define

begin_comment
comment|/* UDC Status Interrupt Register 0  */
end_comment

begin_define
define|#
directive|define
name|USBDC_USIR1
value|0x005C
end_define

begin_comment
comment|/* UDC Status Interrupt Register 1  */
end_comment

begin_define
define|#
directive|define
name|USBDC_UFNHR
value|0x0060
end_define

begin_comment
comment|/* UDC Frame Number Register High  */
end_comment

begin_define
define|#
directive|define
name|USBDC_UFNLR
value|0x0064
end_define

begin_comment
comment|/* UDC Frame Number Register Low  */
end_comment

begin_define
define|#
directive|define
name|USBDC_UBCR2
value|0x0068
end_define

begin_comment
comment|/* UDC Byte Count Register 2  */
end_comment

begin_define
define|#
directive|define
name|USBDC_UBCR4
value|0x006C
end_define

begin_comment
comment|/* UDC Byte Count Register 4  */
end_comment

begin_define
define|#
directive|define
name|USBDC_UBCR7
value|0x0070
end_define

begin_comment
comment|/* UDC Byte Count Register 7  */
end_comment

begin_define
define|#
directive|define
name|USBDC_UBCR9
value|0x0074
end_define

begin_comment
comment|/* UDC Byte Count Register 9  */
end_comment

begin_define
define|#
directive|define
name|USBDC_UBCR12
value|0x0078
end_define

begin_comment
comment|/* UDC Byte Count Register 12  */
end_comment

begin_define
define|#
directive|define
name|USBDC_UBCR14
value|0x007C
end_define

begin_comment
comment|/* UDC Byte Count Register 14  */
end_comment

begin_define
define|#
directive|define
name|USBDC_UDDR0
value|0x0080
end_define

begin_comment
comment|/* UDC Endpoint 0 Data Register  */
end_comment

begin_define
define|#
directive|define
name|USBDC_UDDR1
value|0x0100
end_define

begin_comment
comment|/* UDC Endpoint 1 Data Register  */
end_comment

begin_define
define|#
directive|define
name|USBDC_UDDR2
value|0x0180
end_define

begin_comment
comment|/* UDC Endpoint 2 Data Register  */
end_comment

begin_define
define|#
directive|define
name|USBDC_UDDR3
value|0x0200
end_define

begin_comment
comment|/* UDC Endpoint 3 Data Register  */
end_comment

begin_define
define|#
directive|define
name|USBDC_UDDR4
value|0x0400
end_define

begin_comment
comment|/* UDC Endpoint 4 Data Register  */
end_comment

begin_define
define|#
directive|define
name|USBDC_UDDR5
value|0x00A0
end_define

begin_comment
comment|/* UDC Endpoint 5 Data Register  */
end_comment

begin_define
define|#
directive|define
name|USBDC_UDDR6
value|0x0600
end_define

begin_comment
comment|/* UDC Endpoint 6 Data Register  */
end_comment

begin_define
define|#
directive|define
name|USBDC_UDDR7
value|0x0680
end_define

begin_comment
comment|/* UDC Endpoint 7 Data Register  */
end_comment

begin_define
define|#
directive|define
name|USBDC_UDDR8
value|0x0700
end_define

begin_comment
comment|/* UDC Endpoint 8 Data Register  */
end_comment

begin_define
define|#
directive|define
name|USBDC_UDDR9
value|0x0900
end_define

begin_comment
comment|/* UDC Endpoint 9 Data Register  */
end_comment

begin_define
define|#
directive|define
name|USBDC_UDDR10
value|0x00C0
end_define

begin_comment
comment|/* UDC Endpoint 10 Data Register  */
end_comment

begin_define
define|#
directive|define
name|USBDC_UDDR11
value|0x0B00
end_define

begin_comment
comment|/* UDC Endpoint 11 Data Register  */
end_comment

begin_define
define|#
directive|define
name|USBDC_UDDR12
value|0x0B80
end_define

begin_comment
comment|/* UDC Endpoint 12 Data Register  */
end_comment

begin_define
define|#
directive|define
name|USBDC_UDDR13
value|0x0C00
end_define

begin_comment
comment|/* UDC Endpoint 13 Data Register  */
end_comment

begin_define
define|#
directive|define
name|USBDC_UDDR14
value|0x0E00
end_define

begin_comment
comment|/* UDC Endpoint 14 Data Register  */
end_comment

begin_define
define|#
directive|define
name|USBDC_UDDR15
value|0x00E0
end_define

begin_comment
comment|/* UDC Endpoint 15 Data Register  */
end_comment

begin_define
define|#
directive|define
name|USBHC_UHCRHDA
value|0x0048
end_define

begin_comment
comment|/* UHC Root Hub Descriptor A */
end_comment

begin_define
define|#
directive|define
name|UHCRHDA_POTPGT_SHIFT
value|24
end_define

begin_comment
comment|/* Power on to power good time */
end_comment

begin_define
define|#
directive|define
name|UHCRHDA_NOCP
value|(1<<12)
end_define

begin_comment
comment|/* No over current protection */
end_comment

begin_define
define|#
directive|define
name|UHCRHDA_OCPM
value|(1<<11)
end_define

begin_comment
comment|/* Over current protection mode */
end_comment

begin_define
define|#
directive|define
name|UHCRHDA_DT
value|(1<<10)
end_define

begin_comment
comment|/* Device type */
end_comment

begin_define
define|#
directive|define
name|UHCRHDA_NPS
value|(1<<9)
end_define

begin_comment
comment|/* No power switching */
end_comment

begin_define
define|#
directive|define
name|UHCRHDA_PSM
value|(1<<8)
end_define

begin_comment
comment|/* Power switching mode */
end_comment

begin_define
define|#
directive|define
name|UHCRHDA_NDP_MASK
value|0xff
end_define

begin_comment
comment|/* Number downstream ports */
end_comment

begin_define
define|#
directive|define
name|USBHC_UHCRHDB
value|0x004c
end_define

begin_comment
comment|/* UHC Root Hub Descriptor B */
end_comment

begin_define
define|#
directive|define
name|USBHC_UHCRHS
value|0x0050
end_define

begin_comment
comment|/* UHC Root Hub Stauts */
end_comment

begin_define
define|#
directive|define
name|USBHC_UHCHR
value|0x0064
end_define

begin_comment
comment|/* UHC Reset Register */
end_comment

begin_define
define|#
directive|define
name|UHCHR_SSEP3
value|(1<<11)
end_define

begin_comment
comment|/* Sleep standby enable for port3 */
end_comment

begin_define
define|#
directive|define
name|UHCHR_SSEP2
value|(1<<10)
end_define

begin_comment
comment|/* Sleep standby enable for port2 */
end_comment

begin_define
define|#
directive|define
name|UHCHR_SSEP1
value|(1<<9)
end_define

begin_comment
comment|/* Sleep standby enable for port1 */
end_comment

begin_define
define|#
directive|define
name|UHCHR_PCPL
value|(1<<7)
end_define

begin_comment
comment|/* Power control polarity low */
end_comment

begin_define
define|#
directive|define
name|UHCHR_PSPL
value|(1<<6)
end_define

begin_comment
comment|/* Power sense polarity low */
end_comment

begin_define
define|#
directive|define
name|UHCHR_SSE
value|(1<<5)
end_define

begin_comment
comment|/* Sleep standby enable */
end_comment

begin_define
define|#
directive|define
name|UHCHR_UIT
value|(1<<4)
end_define

begin_comment
comment|/* USB interrupt test */
end_comment

begin_define
define|#
directive|define
name|UHCHR_SSDC
value|(1<<3)
end_define

begin_comment
comment|/* Simulation scale down clock */
end_comment

begin_define
define|#
directive|define
name|UHCHR_CGR
value|(1<<2)
end_define

begin_comment
comment|/* Clock generation reset */
end_comment

begin_define
define|#
directive|define
name|UHCHR_FHR
value|(1<<1)
end_define

begin_comment
comment|/* Force host controller reset */
end_comment

begin_define
define|#
directive|define
name|UHCHR_FSBIR
value|(1<<0)
end_define

begin_comment
comment|/* Force system bus interface reset */
end_comment

begin_define
define|#
directive|define
name|UHCHR_MASK
value|0xeff
end_define

begin_comment
comment|/*  * PWM controller  */
end_comment

begin_define
define|#
directive|define
name|PWM_PWMCR
value|0x0000
end_define

begin_comment
comment|/* Control register */
end_comment

begin_define
define|#
directive|define
name|PWM_PWMDCR
value|0x0004
end_define

begin_comment
comment|/* Duty cycle register */
end_comment

begin_define
define|#
directive|define
name|PWM_FD
value|(1<<10)
end_define

begin_comment
comment|/* Full duty */
end_comment

begin_define
define|#
directive|define
name|PWM_PWMPCR
value|0x0008
end_define

begin_comment
comment|/* Period register */
end_comment

begin_comment
comment|/*  * OS timer  */
end_comment

begin_define
define|#
directive|define
name|OST_MR0
value|0x00
end_define

begin_comment
comment|/* Match register 0 */
end_comment

begin_define
define|#
directive|define
name|OST_MR1
value|0x04
end_define

begin_comment
comment|/* Match register 1 */
end_comment

begin_define
define|#
directive|define
name|OST_MR2
value|0x08
end_define

begin_comment
comment|/* Match register 2 */
end_comment

begin_define
define|#
directive|define
name|OST_MR3
value|0x0c
end_define

begin_comment
comment|/* Match register 3 */
end_comment

begin_define
define|#
directive|define
name|OST_CR
value|0x10
end_define

begin_comment
comment|/* Count register */
end_comment

begin_define
define|#
directive|define
name|OST_SR
value|0x14
end_define

begin_comment
comment|/* Status register */
end_comment

begin_define
define|#
directive|define
name|OST_SR_CH0
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|OST_SR_CH1
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|OST_SR_CH2
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|OST_SR_CH3
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|OST_WR
value|0x18
end_define

begin_comment
comment|/* Watchdog enable register */
end_comment

begin_define
define|#
directive|define
name|OST_IR
value|0x1c
end_define

begin_comment
comment|/* Interrupt enable register */
end_comment

begin_comment
comment|/*  * Interrupt controller  */
end_comment

begin_define
define|#
directive|define
name|ICU_IP
value|0x00
end_define

begin_comment
comment|/* IRQ pending register */
end_comment

begin_define
define|#
directive|define
name|ICU_MR
value|0x04
end_define

begin_comment
comment|/* Mask register */
end_comment

begin_define
define|#
directive|define
name|ICU_LR
value|0x08
end_define

begin_comment
comment|/* Level register */
end_comment

begin_define
define|#
directive|define
name|ICU_FP
value|0x0c
end_define

begin_comment
comment|/* FIQ pending register */
end_comment

begin_define
define|#
directive|define
name|ICU_PR
value|0x10
end_define

begin_comment
comment|/* Pending register */
end_comment

begin_define
define|#
directive|define
name|ICU_CR
value|0x14
end_define

begin_comment
comment|/* Control register */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ARM_XSCALE_PXAREG_H_ */
end_comment

end_unit

