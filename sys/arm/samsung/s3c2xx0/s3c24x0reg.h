begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: s3c24x0reg.h,v 1.7 2004/02/12 03:52:46 bsh Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2003  Genetec corporation  All rights reserved.  * Written by Hiroyuki Bessho for Genetec corporation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of Genetec corporation may not be used to endorse  *    or promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY GENETEC CORP. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL GENETEC CORP.  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Samsung S3C2410X/2400 processor is ARM920T based integrated CPU  *  * Reference:  *  S3C2410X User's Manual  *  S3C2400 User's Manual  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARM_S3C2XX0_S3C24X0REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_ARM_S3C2XX0_S3C24X0REG_H_
end_define

begin_comment
comment|/* common definitions for S3C2800, S3C2410 and S3C2440 */
end_comment

begin_include
include|#
directive|include
file|<arm/samsung/s3c2xx0/s3c2xx0reg.h>
end_include

begin_comment
comment|/*  * Map the device registers into kernel space.  *  * As most devices use less than 1 page of memory reduce  * the distance between allocations by right shifting  * S3C24X0_DEV_SHIFT bits. Because the UART takes 3*0x4000  * bytes the upper limit on S3C24X0_DEV_SHIFT is 4.  * TODO: Fix the UART code so we can increase this value.  */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_DEV_START
value|0x48000000
end_define

begin_define
define|#
directive|define
name|S3C24X0_DEV_STOP
value|0x60000000
end_define

begin_define
define|#
directive|define
name|S3C24X0_DEV_VA_OFFSET
value|0xD8000000
end_define

begin_define
define|#
directive|define
name|S3C24X0_DEV_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|S3C24X0_DEV_PA_SIZE
value|(S3C24X0_DEV_STOP - S3C24X0_DEV_START)
end_define

begin_define
define|#
directive|define
name|S3C24X0_DEV_VA_SIZE
value|(S3C24X0_DEV_PA_SIZE>> S3C24X0_DEV_SHIFT)
end_define

begin_define
define|#
directive|define
name|S3C24X0_DEV_PA_TO_VA
parameter_list|(
name|x
parameter_list|)
value|((x>> S3C24X0_DEV_SHIFT) - S3C24X0_DEV_START + S3C24X0_DEV_VA_OFFSET)
end_define

begin_comment
comment|/*  * Physical address of integrated peripherals  */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_MEMCTL_PA_BASE
value|0x48000000
end_define

begin_comment
comment|/* memory controller */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_MEMCTL_BASE
value|S3C24X0_DEV_PA_TO_VA(S3C24X0_MEMCTL_PA_BASE)
end_define

begin_define
define|#
directive|define
name|S3C24X0_USBHC_PA_BASE
value|0x49000000
end_define

begin_comment
comment|/* USB Host controller */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_USBHC_BASE
value|S3C24X0_DEV_PA_TO_VA(S3C24X0_USBHC_PA_BASE)
end_define

begin_define
define|#
directive|define
name|S3C24X0_INTCTL_PA_BASE
value|0x4a000000
end_define

begin_comment
comment|/* Interrupt controller */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_INTCTL_BASE
value|S3C24X0_DEV_PA_TO_VA(S3C24X0_INTCTL_PA_BASE)
end_define

begin_define
define|#
directive|define
name|S3C24X0_INTCTL_SIZE
value|0x20
end_define

begin_define
define|#
directive|define
name|S3C24X0_DMAC_PA_BASE
value|0x4b000000
end_define

begin_define
define|#
directive|define
name|S3C24X0_DMAC_BASE
value|S3C24X0_DEV_PA_TO_VA(S3C24X0_DMAC_PA_BASE)
end_define

begin_define
define|#
directive|define
name|S3C24X0_DMAC_SIZE
value|0xe4
end_define

begin_define
define|#
directive|define
name|S3C24X0_CLKMAN_PA_BASE
value|0x4c000000
end_define

begin_comment
comment|/* clock& power management */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_CLKMAN_BASE
value|S3C24X0_DEV_PA_TO_VA(S3C24X0_CLKMAN_PA_BASE)
end_define

begin_define
define|#
directive|define
name|S3C24X0_LCDC_PA_BASE
value|0x4d000000
end_define

begin_comment
comment|/* LCD controller */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_LCDC_BASE
value|S3C24X0_DEV_PA_TO_VA(S3C24X0_LCDC_PA_BASE)
end_define

begin_define
define|#
directive|define
name|S3C24X0_LCDC_SIZE
value|0x64
end_define

begin_define
define|#
directive|define
name|S3C24X0_NANDFC_PA_BASE
value|0x4e000000
end_define

begin_comment
comment|/* NAND Flash controller */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_NANDFC_BASE
value|S3C24X0_DEV_PA_TO_VA(S3C24X0_NANDFC_PA_BASE)
end_define

begin_define
define|#
directive|define
name|S3C24X0_UART0_PA_BASE
value|0x50000000
end_define

begin_define
define|#
directive|define
name|S3C24X0_UART0_BASE
value|S3C24X0_DEV_PA_TO_VA(S3C24X0_UART0_PA_BASE)
end_define

begin_define
define|#
directive|define
name|S3C24X0_UART_PA_BASE
parameter_list|(
name|n
parameter_list|)
value|(S3C24X0_UART0_PA_BASE+0x4000*(n))
end_define

begin_define
define|#
directive|define
name|S3C24X0_UART_BASE
parameter_list|(
name|n
parameter_list|)
value|(S3C24X0_UART0_BASE+0x4000*(n))
end_define

begin_define
define|#
directive|define
name|S3C24X0_TIMER_PA_BASE
value|0x51000000
end_define

begin_define
define|#
directive|define
name|S3C24X0_TIMER_BASE
value|S3C24X0_DEV_PA_TO_VA(S3C24X0_TIMER_PA_BASE)
end_define

begin_define
define|#
directive|define
name|S3C24X0_USBDC_PA_BASE
value|0x5200140
end_define

begin_define
define|#
directive|define
name|S3C24X0_USBDC_BASE
value|S3C24X0_DEV_PA_TO_VA(S3C24X0_USBDC_PA_BASE)
end_define

begin_define
define|#
directive|define
name|S3C24X0_USBDC_SIZE
value|0x130
end_define

begin_define
define|#
directive|define
name|S3C24X0_WDT_PA_BASE
value|0x53000000
end_define

begin_define
define|#
directive|define
name|S3C24X0_WDT_BASE
value|S3C24X0_DEV_PA_TO_VA(S3C24X0_WDT_PA_BASE)
end_define

begin_define
define|#
directive|define
name|S3C24X0_IIC_PA_BASE
value|0x54000000
end_define

begin_define
define|#
directive|define
name|S3C24X0_IIC_BASE
value|S3C24X0_DEV_PA_TO_VA(S3C24X0_IIC_PA_BASE)
end_define

begin_define
define|#
directive|define
name|S3C24X0_IIS_PA_BASE
value|0x55000000
end_define

begin_define
define|#
directive|define
name|S3C24X0_IIS_BASE
value|S3C24X0_DEV_PA_TO_VA(S3C24X0_IIS_PA_BASE)
end_define

begin_define
define|#
directive|define
name|S3C24X0_GPIO_PA_BASE
value|0x56000000
end_define

begin_define
define|#
directive|define
name|S3C24X0_GPIO_BASE
value|S3C24X0_DEV_PA_TO_VA(S3C24X0_GPIO_PA_BASE)
end_define

begin_define
define|#
directive|define
name|S3C24X0_RTC_PA_BASE
value|0x57000000
end_define

begin_define
define|#
directive|define
name|S3C24X0_RTC_BASE
value|S3C24X0_DEV_PA_TO_VA(S3C24X0_RTC_PA_BASE)
end_define

begin_define
define|#
directive|define
name|S3C24X0_RTC_SIZE
value|0x8C
end_define

begin_define
define|#
directive|define
name|S3C24X0_ADC_PA_BASE
value|0x58000000
end_define

begin_define
define|#
directive|define
name|S3C24X0_ADC_BASE
value|S3C24X0_DEV_PA_TO_VA(S3C24X0_ADC_PA_BASE)
end_define

begin_define
define|#
directive|define
name|S3C24X0_SPI0_PA_BASE
value|0x59000000
end_define

begin_define
define|#
directive|define
name|S3C24X0_SPI0_BASE
value|S3C24X0_DEV_PA_TO_VA(S3C24X0_SPI0_PA_BASE)
end_define

begin_define
define|#
directive|define
name|S3C24X0_SPI1_PA_BASE
value|0x59000020
end_define

begin_define
define|#
directive|define
name|S3C24X0_SPI1_BASE
value|S3C24X0_DEV_PA_TO_VA(S3C24X0_SPI1_PA_BASE)
end_define

begin_define
define|#
directive|define
name|S3C24X0_SDI_PA_BASE
value|0x5a000000
end_define

begin_comment
comment|/* SD Interface */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_SDI_BASE
value|S3C24X0_DEV_PA_TO_VA(S3C24X0_SDI_PA_BASE)
end_define

begin_define
define|#
directive|define
name|S3C24X0_REG_BASE
value|0x48000000
end_define

begin_define
define|#
directive|define
name|S3C24X0_REG_SIZE
value|0x13000000
end_define

begin_comment
comment|/* Memory controller */
end_comment

begin_define
define|#
directive|define
name|MEMCTL_BWSCON
value|0x00
end_define

begin_comment
comment|/* Bus width and wait status */
end_comment

begin_define
define|#
directive|define
name|BWSCON_DW0_SHIFT
value|1
end_define

begin_comment
comment|/* bank0 is odd */
end_comment

begin_define
define|#
directive|define
name|BWSCON_BANK_SHIFT
parameter_list|(
name|n
parameter_list|)
value|(4*(n))
end_define

begin_comment
comment|/* for bank 1..7 */
end_comment

begin_define
define|#
directive|define
name|BWSCON_DW_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|BWSCON_DW_8
value|0
end_define

begin_define
define|#
directive|define
name|BWSCON_DW_16
value|1
end_define

begin_define
define|#
directive|define
name|BWSCON_DW_32
value|2
end_define

begin_define
define|#
directive|define
name|BWSCON_WS
value|0x04
end_define

begin_comment
comment|/* WAIT enable for the bank */
end_comment

begin_define
define|#
directive|define
name|BWSCON_ST
value|0x08
end_define

begin_comment
comment|/* SRAM use UB/LB for the bank */
end_comment

begin_define
define|#
directive|define
name|MEMCTL_BANKCON0
value|0x04
end_define

begin_comment
comment|/* Boot ROM control */
end_comment

begin_define
define|#
directive|define
name|MEMCTL_BANKCON
parameter_list|(
name|n
parameter_list|)
value|(0x04+4*(n))
end_define

begin_comment
comment|/* BANKn control */
end_comment

begin_define
define|#
directive|define
name|BANKCON_MT_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|BANKCON_MT_ROM
value|(0<<BANKCON_MT_SHIFT)
end_define

begin_define
define|#
directive|define
name|BANKCON_MT_DRAM
value|(3<<BANKCON_MT_SHIFT)
end_define

begin_define
define|#
directive|define
name|BANKCON_TACS_SHIFT
value|13
end_define

begin_comment
comment|/* address set-up time to nGCS */
end_comment

begin_define
define|#
directive|define
name|BANKCON_TCOS_SHIFT
value|11
end_define

begin_comment
comment|/* CS set-up to nOE */
end_comment

begin_define
define|#
directive|define
name|BANKCON_TACC_SHIFT
value|8
end_define

begin_comment
comment|/* CS set-up to nOE */
end_comment

begin_define
define|#
directive|define
name|BANKCON_TOCH_SHIFT
value|6
end_define

begin_comment
comment|/* CS hold time from OE */
end_comment

begin_define
define|#
directive|define
name|BANKCON_TCAH_SHIFT
value|4
end_define

begin_comment
comment|/* address hold time from OE */
end_comment

begin_define
define|#
directive|define
name|BANKCON_TACP_SHIFT
value|2
end_define

begin_comment
comment|/* page mode access cycle */
end_comment

begin_define
define|#
directive|define
name|BANKCON_TACP_2
value|(0<<BANKCON_TACP_SHIFT)
end_define

begin_define
define|#
directive|define
name|BANKCON_TACP_3
value|(1<<BANKCON_TACP_SHIFT)
end_define

begin_define
define|#
directive|define
name|BANKCON_TACP_4
value|(2<<BANKCON_TACP_SHIFT)
end_define

begin_define
define|#
directive|define
name|BANKCON_TACP_6
value|(3<<BANKCON_TACP_SHIFT)
end_define

begin_define
define|#
directive|define
name|BANKCON_PMC_4
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|BANKCON_PMC_8
value|(2<<0)
end_define

begin_define
define|#
directive|define
name|BANKCON_PMC_16
value|(3<<0)
end_define

begin_define
define|#
directive|define
name|BANKCON_TRCD_SHIFT
value|2
end_define

begin_comment
comment|/* RAS to CAS delay */
end_comment

begin_define
define|#
directive|define
name|BANKCON_TRCD_2
value|(0<<2)
end_define

begin_define
define|#
directive|define
name|BANKCON_TRCD_3
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|BANKCON_TRCD_4
value|(2<<2)
end_define

begin_define
define|#
directive|define
name|BANKCON_SCAN_8
value|(0<<0)
end_define

begin_comment
comment|/* Column address number */
end_comment

begin_define
define|#
directive|define
name|BANKCON_SCAN_9
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|BANKCON_SCAN_10
value|(2<<0)
end_define

begin_define
define|#
directive|define
name|MEMCTL_REFRESH
value|0x24
end_define

begin_comment
comment|/* DRAM?SDRAM Refresh */
end_comment

begin_define
define|#
directive|define
name|REFRESH_REFEN
value|(1<<23)
end_define

begin_define
define|#
directive|define
name|REFRESH_TREFMD
value|(1<<22)
end_define

begin_comment
comment|/* 1=self refresh */
end_comment

begin_define
define|#
directive|define
name|REFRESH_TRP_2
value|(0<<20)
end_define

begin_define
define|#
directive|define
name|REFRESH_TRP_3
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|REFRESH_TRP_4
value|(2<<20)
end_define

begin_define
define|#
directive|define
name|REFRESH_TRC_4
value|(0<<18)
end_define

begin_define
define|#
directive|define
name|REFRESH_TRC_5
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|REFRESH_TRC_6
value|(2<<18)
end_define

begin_define
define|#
directive|define
name|REFRESH_TRC_7
value|(3<<18)
end_define

begin_define
define|#
directive|define
name|REFRESH_COUNTER_MASK
value|0x3ff
end_define

begin_define
define|#
directive|define
name|MEMCTL_BANKSIZE
value|0x28
end_define

begin_comment
comment|/* Flexible Bank size */
end_comment

begin_define
define|#
directive|define
name|MEMCTL_MRSRB6
value|0x2c
end_define

begin_comment
comment|/* SDRAM Mode register */
end_comment

begin_define
define|#
directive|define
name|MEMCTL_MRSRB7
value|0x30
end_define

begin_define
define|#
directive|define
name|MRSR_CL_SHIFT
value|4
end_define

begin_comment
comment|/* CAS Latency */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_MEMCTL_SIZE
value|0x34
end_define

begin_comment
comment|/* USB Host controller */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_USBHC_SIZE
value|0x5c
end_define

begin_comment
comment|/* Interrupt controller */
end_comment

begin_define
define|#
directive|define
name|INTCTL_PRIORITY
value|0x0c
end_define

begin_comment
comment|/* IRQ Priority control */
end_comment

begin_define
define|#
directive|define
name|INTCTL_INTPND
value|0x10
end_define

begin_comment
comment|/* Interrupt request status */
end_comment

begin_define
define|#
directive|define
name|INTCTL_INTOFFSET
value|0x14
end_define

begin_comment
comment|/* Interrupt request source */
end_comment

begin_define
define|#
directive|define
name|INTCTL_SUBSRCPND
value|0x18
end_define

begin_comment
comment|/* sub source pending */
end_comment

begin_define
define|#
directive|define
name|INTCTL_INTSUBMSK
value|0x1c
end_define

begin_comment
comment|/* sub mask */
end_comment

begin_comment
comment|/* Interrupt source */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_INT_ADCTC
value|31
end_define

begin_comment
comment|/* ADC (and TC for 2410) */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_INT_RTC
value|30
end_define

begin_comment
comment|/* RTC alarm */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_INT_SPI1
value|29
end_define

begin_comment
comment|/* SPI 1 */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_INT_UART0
value|28
end_define

begin_comment
comment|/* UART0 */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_INT_IIC
value|27
end_define

begin_define
define|#
directive|define
name|S3C24X0_INT_USBH
value|26
end_define

begin_comment
comment|/* USB Host */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_INT_USBD
value|25
end_define

begin_comment
comment|/* USB Device */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_INT_UART1
value|23
end_define

begin_comment
comment|/* UART0  (2410 only) */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_INT_SPI0
value|22
end_define

begin_comment
comment|/* SPI 0 */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_INT_SDI
value|21
end_define

begin_define
define|#
directive|define
name|S3C24X0_INT_DMA3
value|20
end_define

begin_define
define|#
directive|define
name|S3C24X0_INT_DMA2
value|19
end_define

begin_define
define|#
directive|define
name|S3C24X0_INT_DMA1
value|18
end_define

begin_define
define|#
directive|define
name|S3C24X0_INT_DMA0
value|17
end_define

begin_define
define|#
directive|define
name|S3C24X0_INT_LCD
value|16
end_define

begin_define
define|#
directive|define
name|S3C24X0_INT_UART2
value|15
end_define

begin_comment
comment|/* UART2 int (2410) */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_INT_TIMER4
value|14
end_define

begin_define
define|#
directive|define
name|S3C24X0_INT_TIMER3
value|13
end_define

begin_define
define|#
directive|define
name|S3C24X0_INT_TIMER2
value|12
end_define

begin_define
define|#
directive|define
name|S3C24X0_INT_TIMER1
value|11
end_define

begin_define
define|#
directive|define
name|S3C24X0_INT_TIMER0
value|10
end_define

begin_define
define|#
directive|define
name|S3C24X0_INT_TIMER
parameter_list|(
name|n
parameter_list|)
value|(10+(n))
end_define

begin_comment
comment|/* timer interrupt [4:0] */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_INT_WDT
value|9
end_define

begin_comment
comment|/* Watch dog timer */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_INT_TICK
value|8
end_define

begin_define
define|#
directive|define
name|S3C24X0_INT_BFLT
value|7
end_define

begin_comment
comment|/* Battery fault */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_INT_8_23
value|5
end_define

begin_comment
comment|/* Ext int 8..23 */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_INT_4_7
value|4
end_define

begin_comment
comment|/* Ext int 4..7 */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_INT_3
value|3
end_define

begin_define
define|#
directive|define
name|S3C24X0_INT_2
value|2
end_define

begin_define
define|#
directive|define
name|S3C24X0_INT_1
value|1
end_define

begin_define
define|#
directive|define
name|S3C24X0_INT_0
value|0
end_define

begin_comment
comment|/* 24{1,4}0 has more than 32 interrupt sources.  These are sub-sources  * that are OR-ed into main interrupt sources, and controlled via  * SUBSRCPND and  SUBSRCMSK registers */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_SUBIRQ_MIN
value|32
end_define

begin_comment
comment|/* cascaded to INT_ADCTC */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_INT_ADC
value|(S3C24X0_SUBIRQ_MIN+10)
end_define

begin_comment
comment|/* AD converter */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_INT_TC
value|(S3C24X0_SUBIRQ_MIN+9)
end_define

begin_comment
comment|/* Touch screen */
end_comment

begin_comment
comment|/* cascaded to INT_UART2 */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_INT_ERR2
value|(S3C24X0_SUBIRQ_MIN+8)
end_define

begin_comment
comment|/* UART2 Error */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_INT_TXD2
value|(S3C24X0_SUBIRQ_MIN+7)
end_define

begin_comment
comment|/* UART2 Tx */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_INT_RXD2
value|(S3C24X0_SUBIRQ_MIN+6)
end_define

begin_comment
comment|/* UART2 Rx */
end_comment

begin_comment
comment|/* cascaded to INT_UART1 */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_INT_ERR1
value|(S3C24X0_SUBIRQ_MIN+5)
end_define

begin_comment
comment|/* UART1 Error */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_INT_TXD1
value|(S3C24X0_SUBIRQ_MIN+4)
end_define

begin_comment
comment|/* UART1 Tx */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_INT_RXD1
value|(S3C24X0_SUBIRQ_MIN+3)
end_define

begin_comment
comment|/* UART1 Rx */
end_comment

begin_comment
comment|/* cascaded to INT_UART0 */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_INT_ERR0
value|(S3C24X0_SUBIRQ_MIN+2)
end_define

begin_comment
comment|/* UART0 Error */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_INT_TXD0
value|(S3C24X0_SUBIRQ_MIN+1)
end_define

begin_comment
comment|/* UART0 Tx */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_INT_RXD0
value|(S3C24X0_SUBIRQ_MIN+0)
end_define

begin_comment
comment|/* UART0 Rx */
end_comment

begin_comment
comment|/*  * Support for external interrupts. We use values from 48  * to allow new CPU's to allocate new subirq's.  */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_EXTIRQ_MIN
value|48
end_define

begin_define
define|#
directive|define
name|S3C24X0_EXTIRQ_COUNT
value|24
end_define

begin_define
define|#
directive|define
name|S3C24X0_EXTIRQ_MAX
value|(S3C24X0_EXTIRQ_MIN + S3C24X0_EXTIRQ_COUNT - 1)
end_define

begin_define
define|#
directive|define
name|S3C24X0_INT_EXT
parameter_list|(
name|n
parameter_list|)
value|(S3C24X0_EXTIRQ_MIN + (n))
end_define

begin_comment
comment|/* DMA controller */
end_comment

begin_comment
comment|/* XXX */
end_comment

begin_comment
comment|/* Clock& power manager */
end_comment

begin_define
define|#
directive|define
name|CLKMAN_LOCKTIME
value|0x00
end_define

begin_comment
comment|/* PLL lock time */
end_comment

begin_define
define|#
directive|define
name|CLKMAN_MPLLCON
value|0x04
end_define

begin_comment
comment|/* MPLL control */
end_comment

begin_define
define|#
directive|define
name|CLKMAN_UPLLCON
value|0x08
end_define

begin_comment
comment|/* UPLL control */
end_comment

begin_define
define|#
directive|define
name|PLLCON_MDIV_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|PLLCON_MDIV_MASK
value|(0xff<<PLLCON_MDIV_SHIFT)
end_define

begin_define
define|#
directive|define
name|PLLCON_PDIV_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|PLLCON_PDIV_MASK
value|(0x3f<<PLLCON_PDIV_SHIFT)
end_define

begin_define
define|#
directive|define
name|PLLCON_SDIV_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PLLCON_SDIV_MASK
value|(0x03<<PLLCON_SDIV_SHIFT)
end_define

begin_define
define|#
directive|define
name|CLKMAN_CLKCON
value|0x0c
end_define

begin_define
define|#
directive|define
name|CLKCON_SPI
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|CLKCON_IIS
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|CLKCON_IIC
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|CLKCON_ADC
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|CLKCON_RTC
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|CLKCON_GPIO
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|CLKCON_UART2
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|CLKCON_UART1
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|CLKCON_UART0
value|(1<<10)
end_define

begin_comment
comment|/* PCLK to UART0 */
end_comment

begin_define
define|#
directive|define
name|CLKCON_SDI
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|CLKCON_TIMER
value|(1<<8)
end_define

begin_comment
comment|/* PCLK to TIMER */
end_comment

begin_define
define|#
directive|define
name|CLKCON_USBD
value|(1<<7)
end_define

begin_comment
comment|/* PCLK to USB device controller */
end_comment

begin_define
define|#
directive|define
name|CLKCON_USBH
value|(1<<6)
end_define

begin_comment
comment|/* PCLK to USB host controller */
end_comment

begin_define
define|#
directive|define
name|CLKCON_LCDC
value|(1<<5)
end_define

begin_comment
comment|/* PCLK to LCD controller */
end_comment

begin_define
define|#
directive|define
name|CLKCON_NANDFC
value|(1<<4)
end_define

begin_comment
comment|/* PCLK to NAND Flash controller */
end_comment

begin_define
define|#
directive|define
name|CLKCON_IDLE
value|(1<<2)
end_define

begin_comment
comment|/* 1=transition to IDLE mode */
end_comment

begin_define
define|#
directive|define
name|CLKMAN_CLKSLOW
value|0x10
end_define

begin_define
define|#
directive|define
name|CLKMAN_CLKDIVN
value|0x14
end_define

begin_define
define|#
directive|define
name|CLKDIVN_PDIVN
value|(1<<0)
end_define

begin_comment
comment|/* pclk=hclk/2 */
end_comment

begin_define
define|#
directive|define
name|CLKMAN_CLKSLOW
value|0x10
end_define

begin_comment
comment|/* slow clock controll */
end_comment

begin_define
define|#
directive|define
name|CLKSLOW_UCLK
value|(1<<7)
end_define

begin_comment
comment|/* 1=UPLL off */
end_comment

begin_define
define|#
directive|define
name|CLKSLOW_MPLL
value|(1<<5)
end_define

begin_comment
comment|/* 1=PLL off */
end_comment

begin_define
define|#
directive|define
name|CLKSLOW_SLOW
value|(1<<4)
end_define

begin_comment
comment|/* 1: Enable SLOW mode */
end_comment

begin_define
define|#
directive|define
name|CLKSLOW_VAL_MASK
value|0x0f
end_define

begin_comment
comment|/* divider value for slow clock */
end_comment

begin_define
define|#
directive|define
name|CLKMAN_CLKDIVN
value|0x14
end_define

begin_comment
comment|/* Software reset control */
end_comment

begin_define
define|#
directive|define
name|CLKDIVN_PDIVN
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|S3C24X0_CLKMAN_SIZE
value|0x18
end_define

begin_comment
comment|/* LCD controller */
end_comment

begin_define
define|#
directive|define
name|LCDC_LCDCON1
value|0x00
end_define

begin_comment
comment|/* control 1 */
end_comment

begin_define
define|#
directive|define
name|LCDCON1_ENVID
value|(1<<0)
end_define

begin_comment
comment|/* enable video */
end_comment

begin_define
define|#
directive|define
name|LCDCON1_BPPMODE_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|LCDCON1_BPPMODE_MASK
value|(0x0f<<LCDCON1_BPPMODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON1_BPPMODE_STN1
value|(0x0<<LCDCON1_BPPMODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON1_BPPMODE_STN2
value|(0x1<<LCDCON1_BPPMODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON1_BPPMODE_STN4
value|(0x2<<LCDCON1_BPPMODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON1_BPPMODE_STN8
value|(0x3<<LCDCON1_BPPMODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON1_BPPMODE_STN12
value|(0x4<<LCDCON1_BPPMODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON1_BPPMODE_TFT1
value|(0x8<<LCDCON1_BPPMODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON1_BPPMODE_TFT2
value|(0x9<<LCDCON1_BPPMODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON1_BPPMODE_TFT4
value|(0xa<<LCDCON1_BPPMODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON1_BPPMODE_TFT8
value|(0xb<<LCDCON1_BPPMODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON1_BPPMODE_TFT16
value|(0xc<<LCDCON1_BPPMODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON1_BPPMODE_TFT24
value|(0xd<<LCDCON1_BPPMODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON1_BPPMODE_TFTX
value|(0x8<<LCDCON1_BPPMODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON1_PNRMODE_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|LCDCON1_PNRMODE_MASK
value|(0x3<<LCDCON1_PNRMODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON1_PNRMODE_DUALSTN4
value|(0x0<<LCDCON1_PNRMODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON1_PNRMODE_SINGLESTN4
value|(0x1<<LCDCON1_PNRMODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON1_PNRMODE_SINGLESTN8
value|(0x2<<LCDCON1_PNRMODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON1_PNRMODE_TFT
value|(0x3<<LCDCON1_PNRMODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON1_MMODE
value|(1<<7)
end_define

begin_comment
comment|/* VM toggle rate */
end_comment

begin_define
define|#
directive|define
name|LCDCON1_CLKVAL_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|LCDCON1_CLKVAL_MASK
value|(0x3ff<<LCDCON1_CLKVAL_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON1_LINCNT_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|LCDCON1_LINCNT_MASK
value|(0x3ff<<LCDCON1_LINCNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDC_LCDCON2
value|0x04
end_define

begin_comment
comment|/* control 2 */
end_comment

begin_define
define|#
directive|define
name|LCDCON2_VPSW_SHIFT
value|0
end_define

begin_comment
comment|/* TFT Vsync pulse width */
end_comment

begin_define
define|#
directive|define
name|LCDCON2_VPSW_MASK
value|(0x3f<<LCDCON2_VPSW_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON2_VFPD_SHIFT
value|6
end_define

begin_comment
comment|/* TFT V front porch */
end_comment

begin_define
define|#
directive|define
name|LCDCON2_VFPD_MASK
value|(0xff<<LCDCON2_VFPD_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON2_LINEVAL_SHIFT
value|14
end_define

begin_comment
comment|/* Vertical size */
end_comment

begin_define
define|#
directive|define
name|LCDCON2_LINEVAL_MASK
value|(0x3ff<<LCDCON2_LINEVAL_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON2_VBPD_SHIFT
value|24
end_define

begin_comment
comment|/* TFT V back porch */
end_comment

begin_define
define|#
directive|define
name|LCDCON2_VBPD_MASK
value|(0xff<<LCDCON2_VBPD_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDC_LCDCON3
value|0x08
end_define

begin_comment
comment|/* control 2 */
end_comment

begin_define
define|#
directive|define
name|LCDCON3_HFPD_SHIFT
value|0
end_define

begin_comment
comment|/* TFT H front porch */
end_comment

begin_define
define|#
directive|define
name|LCDCON3_HFPD_MASK
value|(0xff<<LCDCON3_VPFD_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON3_LINEBLANK_SHIFT
value|0
end_define

begin_comment
comment|/* STN H blank time */
end_comment

begin_define
define|#
directive|define
name|LCDCON3_LINEBLANK_MASK
value|(0xff<<LCDCON3_LINEBLANK_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON3_HOZVAL_SHIFT
value|8
end_define

begin_comment
comment|/* Horizontal size */
end_comment

begin_define
define|#
directive|define
name|LCDCON3_HOZVAL_MASK
value|(0x7ff<<LCDCON3_HOZVAL_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON3_HBPD_SHIFT
value|19
end_define

begin_comment
comment|/* TFT H back porch */
end_comment

begin_define
define|#
directive|define
name|LCDCON3_HBPD_MASK
value|(0x7f<<LCDCON3_HPBD_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON3_WDLY_SHIFT
value|19
end_define

begin_comment
comment|/* STN vline delay */
end_comment

begin_define
define|#
directive|define
name|LCDCON3_WDLY_MASK
value|(0x03<<LCDCON3_WDLY_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON3_WDLY_16
value|(0x00<<LCDCON3_WDLY_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON3_WDLY_32
value|(0x01<<LCDCON3_WDLY_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON3_WDLY_64
value|(0x02<<LCDCON3_WDLY_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON3_WDLY_128
value|(0x03<<LCDCON3_WDLY_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDC_LCDCON4
value|0x0c
end_define

begin_comment
comment|/* control 4 */
end_comment

begin_define
define|#
directive|define
name|LCDCON4_HPSW_SHIFT
value|0
end_define

begin_comment
comment|/* TFT Hsync pulse width */
end_comment

begin_define
define|#
directive|define
name|LCDCON4_HPSW_MASK
value|(0xff<<LCDCON4_HPSW_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON4_WLH_SHIFT
value|0
end_define

begin_comment
comment|/* STN VLINE high width */
end_comment

begin_define
define|#
directive|define
name|LCDCON4_WLH_MASK
value|(0x03<<LCDCON4_WLH_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON4_WLH_16
value|(0x00<<LCDCON4_WLH_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON4_WLH_32
value|(0x01<<LCDCON4_WLH_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON4_WLH_64
value|(0x02<<LCDCON4_WLH_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON4_WLH_128
value|(0x03<<LCDCON4_WLH_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON4_MVAL_SHIFT
value|8
end_define

begin_comment
comment|/* STN VM toggle rate */
end_comment

begin_define
define|#
directive|define
name|LCDCON4_MVAL_MASK
value|(0xff<<LCDCON4_MVAL_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDC_LCDCON5
value|0x10
end_define

begin_comment
comment|/* control 5 */
end_comment

begin_define
define|#
directive|define
name|LCDCON5_HWSWP
value|(1<<0)
end_define

begin_comment
comment|/* half-word swap */
end_comment

begin_define
define|#
directive|define
name|LCDCON5_BSWP
value|(1<<1)
end_define

begin_comment
comment|/* byte swap */
end_comment

begin_define
define|#
directive|define
name|LCDCON5_ENLEND
value|(1<<2)
end_define

begin_comment
comment|/* TFT: enable LEND signal */
end_comment

begin_define
define|#
directive|define
name|LCDCON5_PWREN
value|(1<<3)
end_define

begin_comment
comment|/* enable PWREN signale */
end_comment

begin_define
define|#
directive|define
name|LCDCON5_INVLEND
value|(1<<4)
end_define

begin_comment
comment|/* TFT: LEND signal polarity */
end_comment

begin_define
define|#
directive|define
name|LCDCON5_INVPWREN
value|(1<<5)
end_define

begin_comment
comment|/* PWREN signal polarity */
end_comment

begin_define
define|#
directive|define
name|LCDCON5_INVVDEN
value|(1<<6)
end_define

begin_comment
comment|/* VDEN signal polarity */
end_comment

begin_define
define|#
directive|define
name|LCDCON5_INVVD
value|(1<<7)
end_define

begin_comment
comment|/* video data signal polarity */
end_comment

begin_define
define|#
directive|define
name|LCDCON5_INVVFRAME
value|(1<<8)
end_define

begin_comment
comment|/* VFRAME/VSYNC signal polarity */
end_comment

begin_define
define|#
directive|define
name|LCDCON5_INVVLINE
value|(1<<9)
end_define

begin_comment
comment|/* VLINE/HSYNC signal polarity */
end_comment

begin_define
define|#
directive|define
name|LCDCON5_INVVCLK
value|(1<<10)
end_define

begin_comment
comment|/* VCLK signal polarity */
end_comment

begin_define
define|#
directive|define
name|LCDCON5_INVVCLK_RISING
value|LCDCON5_INVVCLK
end_define

begin_define
define|#
directive|define
name|LCDCON5_INVVCLK_FALLING
value|0
end_define

begin_define
define|#
directive|define
name|LCDCON5_FRM565
value|(1<<11)
end_define

begin_comment
comment|/* RGB:565 format*/
end_comment

begin_define
define|#
directive|define
name|LCDCON5_FRM555I
value|0
end_define

begin_comment
comment|/* RGBI:5551 format */
end_comment

begin_define
define|#
directive|define
name|LCDCON5_BPP24BL
value|(1<<12)
end_define

begin_comment
comment|/* bit order for bpp24 */
end_comment

begin_define
define|#
directive|define
name|LCDCON5_HSTATUS_SHIFT
value|17
end_define

begin_comment
comment|/* TFT: horizontal status */
end_comment

begin_define
define|#
directive|define
name|LCDCON5_HSTATUS_MASK
value|(0x03<<LCDCON5_HSTATUS_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON5_HSTATUS_HSYNC
value|(0x00<<LCDCON5_HSTATUS_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON5_HSTATUS_BACKP
value|(0x01<<LCDCON5_HSTATUS_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON5_HSTATUS_ACTIVE
value|(0x02<<LCDCON5_HSTATUS_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON5_HSTATUS_FRONTP
value|(0x03<<LCDCON5_HSTATUS_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON5_VSTATUS_SHIFT
value|19
end_define

begin_comment
comment|/* TFT: vertical status */
end_comment

begin_define
define|#
directive|define
name|LCDCON5_VSTATUS_MASK
value|(0x03<<LCDCON5_VSTATUS_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON5_VSTATUS_HSYNC
value|(0x00<<LCDCON5_VSTATUS_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON5_VSTATUS_BACKP
value|(0x01<<LCDCON5_VSTATUS_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON5_VSTATUS_ACTIVE
value|(0x02<<LCDCON5_VSTATUS_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDCON5_VSTATUS_FRONTP
value|(0x03<<LCDCON5_VSTATUS_SHIFT)
end_define

begin_define
define|#
directive|define
name|LCDC_LCDSADDR1
value|0x14
end_define

begin_comment
comment|/* frame buffer start address */
end_comment

begin_define
define|#
directive|define
name|LCDC_LCDSADDR2
value|0x18
end_define

begin_define
define|#
directive|define
name|LCDC_LCDSADDR3
value|0x1c
end_define

begin_define
define|#
directive|define
name|LCDSADDR3_OFFSIZE_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|LCDSADDR3_PAGEWIDTH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|LCDC_REDLUT
value|0x20
end_define

begin_comment
comment|/* STN: red lookup table */
end_comment

begin_define
define|#
directive|define
name|LCDC_GREENLUT
value|0x24
end_define

begin_comment
comment|/* STN: green lookup table */
end_comment

begin_define
define|#
directive|define
name|LCDC_BLUELUT
value|0x28
end_define

begin_comment
comment|/* STN: blue lookup table */
end_comment

begin_define
define|#
directive|define
name|LCDC_DITHMODE
value|0x4c
end_define

begin_comment
comment|/* STN: dithering mode */
end_comment

begin_define
define|#
directive|define
name|LCDC_TPAL
value|0x50
end_define

begin_comment
comment|/* TFT: temporary palette */
end_comment

begin_define
define|#
directive|define
name|TPAL_TPALEN
value|(1<<24)
end_define

begin_define
define|#
directive|define
name|TPAL_RED_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|TPAL_GREEN_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|TPAL_BLUE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|LCDC_LCDINTPND
value|0x54
end_define

begin_define
define|#
directive|define
name|LCDC_LCDSRCPND
value|0x58
end_define

begin_define
define|#
directive|define
name|LCDC_LCDINTMSK
value|0x5c
end_define

begin_define
define|#
directive|define
name|LCDINT_FICNT
value|(1<<0)
end_define

begin_comment
comment|/* FIFO trigger interrupt pending */
end_comment

begin_define
define|#
directive|define
name|LCDINT_FRSYN
value|(1<<1)
end_define

begin_comment
comment|/* frame sync interrupt pending */
end_comment

begin_define
define|#
directive|define
name|LCDINT_FIWSEL
value|(1<<2)
end_define

begin_comment
comment|/* FIFO trigger level: 1=8 words, 0=4 words*/
end_comment

begin_define
define|#
directive|define
name|LCDC_LPCSEL
value|0x60
end_define

begin_comment
comment|/* LPC3600 mode  */
end_comment

begin_define
define|#
directive|define
name|LPCSEL_LPC_EN
value|(1<<0)
end_define

begin_comment
comment|/* enable LPC3600 mode */
end_comment

begin_define
define|#
directive|define
name|LPCSEL_RES_SEL
value|(1<<1)
end_define

begin_comment
comment|/* 1=240x320 0=320x240 */
end_comment

begin_define
define|#
directive|define
name|LPCSEL_MODE_SEL
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|LPCSEL_CPV_SEL
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|LCDC_PALETTE
value|0x0400
end_define

begin_define
define|#
directive|define
name|LCDC_PALETTE_SIZE
value|0x0400
end_define

begin_comment
comment|/* NAND Flash controller */
end_comment

begin_define
define|#
directive|define
name|NANDFC_NFCONF
value|0x00
end_define

begin_comment
comment|/* Configuration */
end_comment

begin_comment
comment|/* NANDFC_NFSTAT */
end_comment

begin_define
define|#
directive|define
name|NFSTAT_READY
value|(1<<0)
end_define

begin_comment
comment|/* NAND flash memory ready/busy status */
end_comment

begin_comment
comment|/* MMC/SD */
end_comment

begin_define
define|#
directive|define
name|SDI_CON
value|0x00
end_define

begin_define
define|#
directive|define
name|CON_BYTEORDER
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|CON_SDIO_INTR
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|CON_READWAIT_EN
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|CON_CLOCK_EN
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|SDI_PRE
value|0x04
end_define

begin_define
define|#
directive|define
name|SDI_CARG
value|0x08
end_define

begin_define
define|#
directive|define
name|SDI_CCON
value|0x0c
end_define

begin_define
define|#
directive|define
name|CCON_ABORDCMD
value|(1<<12)
end_define

begin_comment
comment|/* Abort SDIO CMD12/52 */
end_comment

begin_define
define|#
directive|define
name|CCON_WITHDATA
value|(1<<11)
end_define

begin_comment
comment|/* CMD with data */
end_comment

begin_define
define|#
directive|define
name|CCON_LONGRSP
value|(1<<10)
end_define

begin_comment
comment|/* 136 bit response */
end_comment

begin_define
define|#
directive|define
name|CCON_WAITRSP
value|(1<<9)
end_define

begin_comment
comment|/* Host waits for response */
end_comment

begin_define
define|#
directive|define
name|CCON_CMD_START
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|CCON_CMDINDEX_MASK
value|(0x7F)
end_define

begin_comment
comment|/* Command number index */
end_comment

begin_define
define|#
directive|define
name|SDI_CSTA
value|0x10
end_define

begin_define
define|#
directive|define
name|CSTA_RSPCRCFAIL
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|CSTA_CMDSENT
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|CSTA_CMDTOUT
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|CSTA_RSPFIN
value|(1<<9)
end_define

begin_comment
comment|/* All the bits to be cleared */
end_comment

begin_define
define|#
directive|define
name|CSTA_ALL_CLEAR
value|(CSTA_RSPCRCFAIL | CSTA_CMDSENT | \ 				 CSTA_CMDTOUT | CSTA_RSPFIN)
end_define

begin_define
define|#
directive|define
name|CSTA_ERROR
value|(CSTA_RSPCRCFAIL | CSTA_CMDTOUT)
end_define

begin_define
define|#
directive|define
name|CSTA_CMDON
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|SDI_RSP0
value|0x14
end_define

begin_define
define|#
directive|define
name|SDI_RSP1
value|0x18
end_define

begin_define
define|#
directive|define
name|SDI_RSP2
value|0x1c
end_define

begin_define
define|#
directive|define
name|SDI_RSP3
value|0x20
end_define

begin_define
define|#
directive|define
name|SDI_DTIMER
value|0x24
end_define

begin_define
define|#
directive|define
name|SDI_BSIZE
value|0x28
end_define

begin_define
define|#
directive|define
name|SDI_DCON
value|0x2c
end_define

begin_define
define|#
directive|define
name|DCON_PRDTYPE
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|DCON_TARSP
value|(1<<20)
end_define

begin_comment
comment|/* Transmit after response */
end_comment

begin_define
define|#
directive|define
name|DCON_RACMD
value|(1<<19)
end_define

begin_comment
comment|/* Receive after command */
end_comment

begin_define
define|#
directive|define
name|DCON_BACMD
value|(1<<18)
end_define

begin_comment
comment|/* Busy after command */
end_comment

begin_define
define|#
directive|define
name|DCON_BLKMODE
value|(1<<17)
end_define

begin_comment
comment|/* Stream/Block mode */
end_comment

begin_define
define|#
directive|define
name|DCON_WIDEBUS
value|(1<<16)
end_define

begin_comment
comment|/* Standard/Wide bus */
end_comment

begin_define
define|#
directive|define
name|DCON_ENDMA
value|(1<<15)
end_define

begin_comment
comment|/* DMA Enable */
end_comment

begin_comment
comment|/* Determine the direction of the data transfer */
end_comment

begin_define
define|#
directive|define
name|DCON_DATA_READY
value|(0<<12)
end_define

begin_comment
comment|/* No transfer */
end_comment

begin_define
define|#
directive|define
name|DCON_ONLYBUST
value|(1<<12)
end_define

begin_comment
comment|/* Check if busy */
end_comment

begin_define
define|#
directive|define
name|DCON_DATA_RECEIVE
value|(2<<12)
end_define

begin_comment
comment|/* Receive data from SD */
end_comment

begin_define
define|#
directive|define
name|DCON_DATA_TRANSMIT
value|(3<<12)
end_define

begin_comment
comment|/* Send data to SD */
end_comment

begin_define
define|#
directive|define
name|DCON_BLKNUM_MASK
value|(0x7FF)
end_define

begin_comment
comment|/* Block number */
end_comment

begin_define
define|#
directive|define
name|SDI_DCNT
value|0x30
end_define

begin_define
define|#
directive|define
name|SDI_DSTA
value|0x34
end_define

begin_define
define|#
directive|define
name|SDI_FSTA
value|0x38
end_define

begin_define
define|#
directive|define
name|FSTA_TX_AVAIL
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|FSTA_RX_AVAIL
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|FSTA_TX_FIFO_HALF_FULL
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|FSTA_TX_FIFO_EMPTY
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|FSTA_RX_FIFO_LAST_DATA
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|FSTA_RX_FIFO_FULL
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|FSTA_RX_FIFO_HALF_FULL
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|FSTA_FIFO_COUNT_MSK
value|(0x7F)
end_define

begin_comment
comment|/* Timer */
end_comment

begin_define
define|#
directive|define
name|TIMER_TCFG0
value|0x00
end_define

begin_comment
comment|/* Timer configuration */
end_comment

begin_define
define|#
directive|define
name|TIMER_TCFG1
value|0x04
end_define

begin_define
define|#
directive|define
name|TCFG1_MUX_SHIFT
parameter_list|(
name|n
parameter_list|)
value|(4*(n))
end_define

begin_define
define|#
directive|define
name|TCFG1_MUX_MASK
parameter_list|(
name|n
parameter_list|)
value|(0x0f<< TCFG1_MUX_SHIFT(n))
end_define

begin_define
define|#
directive|define
name|TCFG1_MUX_DIV2
value|0
end_define

begin_define
define|#
directive|define
name|TCFG1_MUX_DIV4
value|1
end_define

begin_define
define|#
directive|define
name|TCFG1_MUX_DIV8
value|2
end_define

begin_define
define|#
directive|define
name|TCFG1_MUX_DIV16
value|3
end_define

begin_define
define|#
directive|define
name|TCFG1_MUX_EXT
value|4
end_define

begin_define
define|#
directive|define
name|TIMER_TCON
value|0x08
end_define

begin_comment
comment|/* control */
end_comment

begin_define
define|#
directive|define
name|TCON_SHIFT
parameter_list|(
name|n
parameter_list|)
value|(4 * ((n)==0 ? 0 : (n)+1))
end_define

begin_define
define|#
directive|define
name|TCON_START
parameter_list|(
name|n
parameter_list|)
value|(1<< TCON_SHIFT(n))
end_define

begin_define
define|#
directive|define
name|TCON_MANUALUPDATE
parameter_list|(
name|n
parameter_list|)
value|(1<< (TCON_SHIFT(n) + 1))
end_define

begin_define
define|#
directive|define
name|TCON_INVERTER
parameter_list|(
name|n
parameter_list|)
value|(1<< (TCON_SHIFT(n) + 2))
end_define

begin_define
define|#
directive|define
name|__TCON_AUTORELOAD
parameter_list|(
name|n
parameter_list|)
value|(1<< (TCON_SHIFT(n) + 3))
end_define

begin_comment
comment|/* n=0..3 */
end_comment

begin_define
define|#
directive|define
name|TCON_AUTORELOAD4
value|(1<<22)
end_define

begin_comment
comment|/* stupid hardware design */
end_comment

begin_define
define|#
directive|define
name|TCON_AUTORELOAD
parameter_list|(
name|n
parameter_list|)
define|\
value|((n)==4 ? TCON_AUTORELOAD4 : __TCON_AUTORELOAD(n))
end_define

begin_define
define|#
directive|define
name|TCON_MASK
parameter_list|(
name|n
parameter_list|)
value|(0x0f<< TCON_SHIFT(n))
end_define

begin_define
define|#
directive|define
name|TIMER_TCNTB
parameter_list|(
name|n
parameter_list|)
value|(0x0c+0x0c*(n))
end_define

begin_comment
comment|/* count buffer */
end_comment

begin_define
define|#
directive|define
name|TIMER_TCMPB
parameter_list|(
name|n
parameter_list|)
value|(0x10+0x0c*(n))
end_define

begin_comment
comment|/* compare buffer */
end_comment

begin_define
define|#
directive|define
name|__TIMER_TCNTO
parameter_list|(
name|n
parameter_list|)
value|(0x14+0x0c*(n))
end_define

begin_comment
comment|/* count observation */
end_comment

begin_define
define|#
directive|define
name|TIMER_TCNTO4
value|0x40
end_define

begin_define
define|#
directive|define
name|TIMER_TCNTO
parameter_list|(
name|n
parameter_list|)
value|((n)==4 ? TIMER_TCNTO4 : __TIMER_TCNTO(n))
end_define

begin_define
define|#
directive|define
name|S3C24X0_TIMER_SIZE
value|0x44
end_define

begin_comment
comment|/* UART */
end_comment

begin_comment
comment|/* diffs to s3c2800 */
end_comment

begin_comment
comment|/* SSCOM_UMCON */
end_comment

begin_define
define|#
directive|define
name|UMCON_AFC
value|(1<<4)
end_define

begin_comment
comment|/* auto flow control */
end_comment

begin_comment
comment|/* SSCOM_UMSTAT */
end_comment

begin_define
define|#
directive|define
name|UMSTAT_DCTS
value|(1<<2)
end_define

begin_comment
comment|/* CTS change */
end_comment

begin_comment
comment|/* SSCOM_UMSTAT */
end_comment

begin_define
define|#
directive|define
name|ULCON_IR
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|ULCON_PARITY_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|S3C24X0_UART_SIZE
value|0x2c
end_define

begin_comment
comment|/* USB device */
end_comment

begin_comment
comment|/* XXX */
end_comment

begin_comment
comment|/* Watch dog timer */
end_comment

begin_define
define|#
directive|define
name|WDT_WTCON
value|0x00
end_define

begin_comment
comment|/* WDT mode */
end_comment

begin_define
define|#
directive|define
name|WTCON_PRESCALE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|WTCON_PRESCALE
value|(0xff<<WTCON_PRESCALE_SHIFT)
end_define

begin_define
define|#
directive|define
name|WTCON_ENABLE
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|WTCON_CLKSEL
value|(3<<3)
end_define

begin_define
define|#
directive|define
name|WTCON_CLKSEL_16
value|(0<<3)
end_define

begin_define
define|#
directive|define
name|WTCON_CLKSEL_32
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|WTCON_CLKSEL_64
value|(2<<3)
end_define

begin_define
define|#
directive|define
name|WTCON_CLKSEL_128
value|(3<<3)
end_define

begin_define
define|#
directive|define
name|WTCON_ENINT
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|WTCON_ENRST
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|WTCON_WDTSTOP
value|0
end_define

begin_define
define|#
directive|define
name|WDT_WTDAT
value|0x04
end_define

begin_comment
comment|/* timer data */
end_comment

begin_define
define|#
directive|define
name|WDT_WTCNT
value|0x08
end_define

begin_comment
comment|/* timer count */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_WDT_SIZE
value|0x0c
end_define

begin_comment
comment|/* IIC */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_IIC_SIZE
value|0x0c
end_define

begin_comment
comment|/* IIS */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_IIS_SIZE
value|0x14
end_define

begin_comment
comment|/* GPIO */
end_comment

begin_define
define|#
directive|define
name|GPIO_PACON
value|0x00
end_define

begin_comment
comment|/* port A configuration */
end_comment

begin_define
define|#
directive|define
name|GPIO_PADAT
value|0x04
end_define

begin_comment
comment|/* port A data */
end_comment

begin_define
define|#
directive|define
name|GPIO_PBCON
value|0x10
end_define

begin_comment
comment|/* These are only used on port B-H on 2410& B-H,J on 2440 */
end_comment

begin_define
define|#
directive|define
name|PCON_INPUT
value|0
end_define

begin_comment
comment|/* Input port */
end_comment

begin_define
define|#
directive|define
name|PCON_OUTPUT
value|1
end_define

begin_comment
comment|/* Output port */
end_comment

begin_define
define|#
directive|define
name|PCON_ALTFUN
value|2
end_define

begin_comment
comment|/* Alternate function */
end_comment

begin_define
define|#
directive|define
name|PCON_ALTFUN2
value|3
end_define

begin_comment
comment|/* Alternate function */
end_comment

begin_define
define|#
directive|define
name|GPIO_PBDAT
value|0x14
end_define

begin_comment
comment|/* This is different between 2440 and 2442 (pull up vs pull down): */
end_comment

begin_define
define|#
directive|define
name|GPIO_PBUP
value|0x18
end_define

begin_comment
comment|/* 2410& 2440 */
end_comment

begin_define
define|#
directive|define
name|GPIO_PBDOWN
value|0x18
end_define

begin_comment
comment|/* 2442 */
end_comment

begin_define
define|#
directive|define
name|GPIO_PCCON
value|0x20
end_define

begin_define
define|#
directive|define
name|GPIO_PCDAT
value|0x24
end_define

begin_define
define|#
directive|define
name|GPIO_PCUP
value|0x28
end_define

begin_comment
comment|/* 2410& 2440 */
end_comment

begin_define
define|#
directive|define
name|GPIO_PCDOWN
value|0x28
end_define

begin_comment
comment|/* 2442 */
end_comment

begin_define
define|#
directive|define
name|GPIO_PDCON
value|0x30
end_define

begin_define
define|#
directive|define
name|GPIO_PDDAT
value|0x34
end_define

begin_define
define|#
directive|define
name|GPIO_PDUP
value|0x38
end_define

begin_comment
comment|/* 2410& 2440 */
end_comment

begin_define
define|#
directive|define
name|GPIO_PDDOWN
value|0x38
end_define

begin_comment
comment|/* 2442 */
end_comment

begin_define
define|#
directive|define
name|GPIO_PECON
value|0x40
end_define

begin_define
define|#
directive|define
name|PECON_INPUT
parameter_list|(
name|x
parameter_list|)
value|(0<<((x)*2))
end_define

begin_comment
comment|/* Pin is used for input */
end_comment

begin_define
define|#
directive|define
name|PECON_OUTPUT
parameter_list|(
name|x
parameter_list|)
value|(1<<((x)*2))
end_define

begin_comment
comment|/* Pin is used for output */
end_comment

begin_define
define|#
directive|define
name|PECON_FUNC_A
parameter_list|(
name|x
parameter_list|)
value|(2<<((x)*2))
end_define

begin_comment
comment|/* Pin is used for function 'A' */
end_comment

begin_define
define|#
directive|define
name|PECON_FUNC_B
parameter_list|(
name|x
parameter_list|)
value|(3<<((x)*2))
end_define

begin_comment
comment|/* Pin is used for function 'B' */
end_comment

begin_define
define|#
directive|define
name|PECON_MASK
parameter_list|(
name|x
parameter_list|)
value|(3<<((x)*2))
end_define

begin_define
define|#
directive|define
name|GPIO_PEDAT
value|0x44
end_define

begin_define
define|#
directive|define
name|GPIO_PEUP
value|0x48
end_define

begin_comment
comment|/* 2410& 2440 */
end_comment

begin_define
define|#
directive|define
name|GPIO_PEDOWN
value|0x48
end_define

begin_comment
comment|/* 2442 */
end_comment

begin_define
define|#
directive|define
name|PEUD_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(~(1<<(x)))
end_define

begin_comment
comment|/* Enable the pull Up/Down */
end_comment

begin_define
define|#
directive|define
name|PEUD_DISABLE
parameter_list|(
name|x
parameter_list|)
value|(1<<(x))
end_define

begin_comment
comment|/* Disable the pull Up/Down */
end_comment

begin_define
define|#
directive|define
name|GPIO_PFCON
value|0x50
end_define

begin_define
define|#
directive|define
name|GPIO_PFDAT
value|0x54
end_define

begin_define
define|#
directive|define
name|GPIO_PFUP
value|0x58
end_define

begin_comment
comment|/* 2410& 2440 */
end_comment

begin_define
define|#
directive|define
name|GPIO_PFDOWN
value|0x58
end_define

begin_comment
comment|/* 2442 */
end_comment

begin_define
define|#
directive|define
name|GPIO_PGCON
value|0x60
end_define

begin_define
define|#
directive|define
name|GPIO_PGDAT
value|0x64
end_define

begin_define
define|#
directive|define
name|GPIO_PGUP
value|0x68
end_define

begin_comment
comment|/* 2410& 2440 */
end_comment

begin_define
define|#
directive|define
name|GPIO_PGDOWN
value|0x68
end_define

begin_comment
comment|/* 2442 */
end_comment

begin_define
define|#
directive|define
name|GPIO_PHCON
value|0x70
end_define

begin_define
define|#
directive|define
name|GPIO_PHDAT
value|0x74
end_define

begin_define
define|#
directive|define
name|GPIO_PHUP
value|0x78
end_define

begin_comment
comment|/* 2410& 2440 */
end_comment

begin_define
define|#
directive|define
name|GPIO_PHDOWN
value|0x78
end_define

begin_comment
comment|/* 2442 */
end_comment

begin_define
define|#
directive|define
name|GPIO_MISCCR
value|0x80
end_define

begin_comment
comment|/* miscellaneous control */
end_comment

begin_define
define|#
directive|define
name|GPIO_DCLKCON
value|0x84
end_define

begin_comment
comment|/* DCLK 0/1 */
end_comment

begin_define
define|#
directive|define
name|GPIO_EXTINT
parameter_list|(
name|n
parameter_list|)
value|(0x88+4*(n))
end_define

begin_comment
comment|/* external int control 0/1/2 */
end_comment

begin_define
define|#
directive|define
name|GPIO_EINTFLT
parameter_list|(
name|n
parameter_list|)
value|(0x94+4*(n))
end_define

begin_comment
comment|/* external int filter control 0..3 */
end_comment

begin_define
define|#
directive|define
name|EXTINTR_LOW
value|0x00
end_define

begin_define
define|#
directive|define
name|EXTINTR_HIGH
value|0x01
end_define

begin_define
define|#
directive|define
name|EXTINTR_FALLING
value|0x02
end_define

begin_define
define|#
directive|define
name|EXTINTR_RISING
value|0x04
end_define

begin_define
define|#
directive|define
name|EXTINTR_BOTH
value|0x06
end_define

begin_define
define|#
directive|define
name|GPIO_EINTMASK
value|0xa4
end_define

begin_define
define|#
directive|define
name|GPIO_EINTPEND
value|0xa8
end_define

begin_define
define|#
directive|define
name|GPIO_GSTATUS0
value|0xac
end_define

begin_comment
comment|/* external pin status */
end_comment

begin_define
define|#
directive|define
name|GPIO_GSTATUS1
value|0xb0
end_define

begin_comment
comment|/* Chip ID */
end_comment

begin_define
define|#
directive|define
name|CHIPID_S3C2410A
value|0x32410002
end_define

begin_define
define|#
directive|define
name|CHIPID_S3C2440A
value|0x32440001
end_define

begin_define
define|#
directive|define
name|CHIPID_S3C2442B
value|0x32440AAB
end_define

begin_define
define|#
directive|define
name|GPIO_GSTATUS2
value|0xb4
end_define

begin_comment
comment|/* Reset status */
end_comment

begin_define
define|#
directive|define
name|GPIO_GSTATUS3
value|0xb8
end_define

begin_define
define|#
directive|define
name|GPIO_GSTATUS4
value|0xbc
end_define

begin_define
define|#
directive|define
name|GPIO_SET_FUNC
parameter_list|(
name|v
parameter_list|,
name|port
parameter_list|,
name|func
parameter_list|)
define|\
value|(((v)& ~(3<<(2*(port))))|((func)<<(2*(port))))
end_define

begin_comment
comment|/* ADC */
end_comment

begin_define
define|#
directive|define
name|ADC_ADCCON
value|0x00
end_define

begin_define
define|#
directive|define
name|ADCCON_ENABLE_START
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|ADCCON_READ_START
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|ADCCON_STDBM
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|ADCCON_SEL_MUX_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|ADCCON_SEL_MUX_MASK
value|(0x7<<ADCCON_SEL_MUX_SHIFT)
end_define

begin_define
define|#
directive|define
name|ADCCON_PRSCVL_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|ADCCON_PRSCVL_MASK
value|(0xff<<ADCCON_PRSCVL_SHIFT)
end_define

begin_define
define|#
directive|define
name|ADCCON_PRSCEN
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|ADCCON_ECFLG
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|ADC_ADCTSC
value|0x04
end_define

begin_define
define|#
directive|define
name|ADCTSC_XY_PST
value|0x03
end_define

begin_define
define|#
directive|define
name|ADCTSC_AUTO_PST
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|ADCTSC_PULL_UP
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|ADCTSC_XP_SEN
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|ADCTSC_XM_SEN
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|ADCTSC_YP_SEN
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|ADCTSC_YM_SEN
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|ADC_ADCDLY
value|0x08
end_define

begin_define
define|#
directive|define
name|ADC_ADCDAT0
value|0x0c
end_define

begin_define
define|#
directive|define
name|ADC_ADCDAT1
value|0x10
end_define

begin_define
define|#
directive|define
name|ADCDAT_DATAMASK
value|0x3ff
end_define

begin_comment
comment|/* RTC */
end_comment

begin_define
define|#
directive|define
name|RTC_RTCCON
value|0x40
end_define

begin_define
define|#
directive|define
name|RTCCON_RTCEN
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|RTCCON_CLKSEL
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|RTCCON_CNTSEL
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|RTCCON_CLKRST
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|RTC_TICNT0
value|0x44
end_define

begin_comment
comment|/* TICNT1 on 2440 */
end_comment

begin_define
define|#
directive|define
name|RTC_RTCALM
value|0x50
end_define

begin_define
define|#
directive|define
name|RTC_ALMSEC
value|0x54
end_define

begin_define
define|#
directive|define
name|RTC_ALMMIN
value|0x58
end_define

begin_define
define|#
directive|define
name|RTC_ALMHOUR
value|0x5C
end_define

begin_define
define|#
directive|define
name|RTC_ALMDATE
value|0x60
end_define

begin_define
define|#
directive|define
name|RTC_ALMMON
value|0x64
end_define

begin_define
define|#
directive|define
name|RTC_ALMYEAR
value|0x68
end_define

begin_comment
comment|/* RTCRST on 2410 */
end_comment

begin_define
define|#
directive|define
name|RTC_BCDSEC
value|0x70
end_define

begin_define
define|#
directive|define
name|RTC_BCDMIN
value|0x74
end_define

begin_define
define|#
directive|define
name|RTC_BCDHOUR
value|0x78
end_define

begin_define
define|#
directive|define
name|RTC_BCDDATE
value|0x7C
end_define

begin_define
define|#
directive|define
name|RTC_BCDDAY
value|0x80
end_define

begin_define
define|#
directive|define
name|RTC_BCDMON
value|0x84
end_define

begin_define
define|#
directive|define
name|RTC_BCDYEAR
value|0x88
end_define

begin_comment
comment|/* SPI */
end_comment

begin_define
define|#
directive|define
name|S3C24X0_SPI_SIZE
value|0x20
end_define

begin_define
define|#
directive|define
name|SPI_SPCON
value|0x00
end_define

begin_define
define|#
directive|define
name|SPCON_TAGD
value|(1<<0)
end_define

begin_comment
comment|/* Tx auto garbage */
end_comment

begin_define
define|#
directive|define
name|SPCON_CPHA
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|SPCON_CPOL
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|SPCON_IDLELOW_RISING
value|(0|0)
end_define

begin_define
define|#
directive|define
name|SPCON_IDLELOW_FALLING
value|(0|SPCON_CPHA)
end_define

begin_define
define|#
directive|define
name|SPCON_IDLEHIGH_FALLING
value|(SPCON_CPOL|0)
end_define

begin_define
define|#
directive|define
name|SPCON_IDLEHIGH_RISING
value|(SPCON_CPOL|SPCON_CPHA)
end_define

begin_define
define|#
directive|define
name|SPCON_MSTR
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|SPCON_ENSCK
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|SPCON_SMOD_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|SPCON_SMOD_MASK
value|(0x03<<SPCON_SMOD_SHIFT)
end_define

begin_define
define|#
directive|define
name|SPCON_SMOD_POLL
value|(0x00<<SPCON_SMOD_SHIFT)
end_define

begin_define
define|#
directive|define
name|SPCON_SMOD_INT
value|(0x01<<SPCON_SMOD_SHIFT)
end_define

begin_define
define|#
directive|define
name|SPCON_SMOD_DMA
value|(0x02<<SPCON_SMOD_SHIFT)
end_define

begin_define
define|#
directive|define
name|SPI_SPSTA
value|0x04
end_define

begin_comment
comment|/* status register */
end_comment

begin_define
define|#
directive|define
name|SPSTA_REDY
value|(1<<0)
end_define

begin_comment
comment|/* ready */
end_comment

begin_define
define|#
directive|define
name|SPSTA_MULF
value|(1<<1)
end_define

begin_comment
comment|/* multi master error */
end_comment

begin_define
define|#
directive|define
name|SPSTA_DCOL
value|(1<<2)
end_define

begin_comment
comment|/* Data collision error */
end_comment

begin_define
define|#
directive|define
name|SPI_SPPIN
value|0x08
end_define

begin_define
define|#
directive|define
name|SPPIN_KEEP
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|SPPIN_ENMUL
value|(1<<2)
end_define

begin_comment
comment|/* multi master error detect */
end_comment

begin_define
define|#
directive|define
name|SPI_SPPRE
value|0x0c
end_define

begin_comment
comment|/* prescaler */
end_comment

begin_define
define|#
directive|define
name|SPI_SPTDAT
value|0x10
end_define

begin_comment
comment|/* tx data */
end_comment

begin_define
define|#
directive|define
name|SPI_SPRDAT
value|0x14
end_define

begin_comment
comment|/* rx data */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ARM_S3C2XX0_S3C24X0REG_H_ */
end_comment

end_unit

