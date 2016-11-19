begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: ingenic_regs.h,v 1.22 2015/10/08 17:54:30 macallan Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2014 Michael Lorenz  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|JZ4780_REGS_H
end_ifndef

begin_define
define|#
directive|define
name|JZ4780_REGS_H
end_define

begin_comment
comment|/* for mips_wbflush() */
end_comment

begin_include
include|#
directive|include
file|<machine/locore.h>
end_include

begin_comment
comment|/* UARTs, mostly 16550 compatible with 32bit spaced registers */
end_comment

begin_define
define|#
directive|define
name|JZ_UART0
value|0x10030000
end_define

begin_define
define|#
directive|define
name|JZ_UART1
value|0x10031000
end_define

begin_define
define|#
directive|define
name|JZ_UART2
value|0x10032000
end_define

begin_define
define|#
directive|define
name|JZ_UART3
value|0x10033000
end_define

begin_define
define|#
directive|define
name|JZ_UART4
value|0x10034000
end_define

begin_comment
comment|/* LCD controller base addresses, registers are in jzfb_regs.h */
end_comment

begin_define
define|#
directive|define
name|JZ_LCDC0_BASE
value|0x13050000
end_define

begin_define
define|#
directive|define
name|JZ_LCDC1_BASE
value|0x130a0000
end_define

begin_comment
comment|/* TCU unit base address */
end_comment

begin_define
define|#
directive|define
name|JZ_TCU_BASE
value|0x10002000
end_define

begin_comment
comment|/* Watchdog */
end_comment

begin_define
define|#
directive|define
name|JZ_WDOG_TDR
value|0x00000000
end_define

begin_comment
comment|/* compare */
end_comment

begin_define
define|#
directive|define
name|JZ_WDOG_TCER
value|0x00000004
end_define

begin_define
define|#
directive|define
name|TCER_ENABLE
value|0x01
end_define

begin_comment
comment|/* enable counter */
end_comment

begin_define
define|#
directive|define
name|JZ_WDOG_TCNT
value|0x00000008
end_define

begin_comment
comment|/* 16bit up count */
end_comment

begin_define
define|#
directive|define
name|JZ_WDOG_TCSR
value|0x0000000c
end_define

begin_define
define|#
directive|define
name|TCSR_PCK_EN
value|0x01
end_define

begin_comment
comment|/* PCLK */
end_comment

begin_define
define|#
directive|define
name|TCSR_RTC_EN
value|0x02
end_define

begin_comment
comment|/* RTCCLK - 32.768kHz */
end_comment

begin_define
define|#
directive|define
name|TCSR_EXT_EN
value|0x04
end_define

begin_comment
comment|/* EXTCLK - 48MHz */
end_comment

begin_define
define|#
directive|define
name|TCSR_PRESCALE_M
value|0x38
end_define

begin_define
define|#
directive|define
name|TCSR_DIV_1
value|0x00
end_define

begin_define
define|#
directive|define
name|TCSR_DIV_4
value|0x08
end_define

begin_define
define|#
directive|define
name|TCSR_DIV_16
value|0x10
end_define

begin_define
define|#
directive|define
name|TCSR_DIV_64
value|0x18
end_define

begin_define
define|#
directive|define
name|TCSR_DIV_256
value|0x20
end_define

begin_define
define|#
directive|define
name|TCSR_DIV_1024
value|0x28
end_define

begin_comment
comment|/* timers and PWMs */
end_comment

begin_define
define|#
directive|define
name|JZ_TC_TER
value|0x00000010
end_define

begin_comment
comment|/* TC enable reg, ro */
end_comment

begin_define
define|#
directive|define
name|JZ_TC_TESR
value|0x00000014
end_define

begin_comment
comment|/* TC enable set reg. */
end_comment

begin_define
define|#
directive|define
name|TESR_TCST0
value|0x0001
end_define

begin_comment
comment|/* enable counter 0 */
end_comment

begin_define
define|#
directive|define
name|TESR_TCST1
value|0x0002
end_define

begin_comment
comment|/* enable counter 1 */
end_comment

begin_define
define|#
directive|define
name|TESR_TCST2
value|0x0004
end_define

begin_comment
comment|/* enable counter 2 */
end_comment

begin_define
define|#
directive|define
name|TESR_TCST3
value|0x0008
end_define

begin_comment
comment|/* enable counter 3 */
end_comment

begin_define
define|#
directive|define
name|TESR_TCST4
value|0x0010
end_define

begin_comment
comment|/* enable counter 4 */
end_comment

begin_define
define|#
directive|define
name|TESR_TCST5
value|0x0020
end_define

begin_comment
comment|/* enable counter 5 */
end_comment

begin_define
define|#
directive|define
name|TESR_TCST6
value|0x0040
end_define

begin_comment
comment|/* enable counter 6 */
end_comment

begin_define
define|#
directive|define
name|TESR_TCST7
value|0x0080
end_define

begin_comment
comment|/* enable counter 7 */
end_comment

begin_define
define|#
directive|define
name|TESR_OST
value|0x8000
end_define

begin_comment
comment|/* enable OST */
end_comment

begin_define
define|#
directive|define
name|JZ_TC_TECR
value|0x00000018
end_define

begin_comment
comment|/* TC enable clear reg. */
end_comment

begin_define
define|#
directive|define
name|JZ_TC_TFR
value|0x00000020
end_define

begin_define
define|#
directive|define
name|TFR_FFLAG0
value|0x00000001
end_define

begin_comment
comment|/* channel 0 */
end_comment

begin_define
define|#
directive|define
name|TFR_FFLAG1
value|0x00000002
end_define

begin_comment
comment|/* channel 1 */
end_comment

begin_define
define|#
directive|define
name|TFR_FFLAG2
value|0x00000004
end_define

begin_comment
comment|/* channel 2 */
end_comment

begin_define
define|#
directive|define
name|TFR_FFLAG3
value|0x00000008
end_define

begin_comment
comment|/* channel 3 */
end_comment

begin_define
define|#
directive|define
name|TFR_FFLAG4
value|0x00000010
end_define

begin_comment
comment|/* channel 4 */
end_comment

begin_define
define|#
directive|define
name|TFR_FFLAG5
value|0x00000020
end_define

begin_comment
comment|/* channel 5 */
end_comment

begin_define
define|#
directive|define
name|TFR_FFLAG6
value|0x00000040
end_define

begin_comment
comment|/* channel 6 */
end_comment

begin_define
define|#
directive|define
name|TFR_FFLAG7
value|0x00000080
end_define

begin_comment
comment|/* channel 7 */
end_comment

begin_define
define|#
directive|define
name|TFR_OSTFLAG
value|0x00008000
end_define

begin_comment
comment|/* OS timer */
end_comment

begin_define
define|#
directive|define
name|JZ_TC_TFSR
value|0x00000024
end_define

begin_comment
comment|/* timer flag set */
end_comment

begin_define
define|#
directive|define
name|JZ_TC_TFCR
value|0x00000028
end_define

begin_comment
comment|/* timer flag clear */
end_comment

begin_define
define|#
directive|define
name|JZ_TC_TMR
value|0x00000030
end_define

begin_comment
comment|/* timer flag mask */
end_comment

begin_define
define|#
directive|define
name|TMR_FMASK
parameter_list|(
name|n
parameter_list|)
value|(1<< (n))
end_define

begin_define
define|#
directive|define
name|TMR_HMASK
parameter_list|(
name|n
parameter_list|)
value|(1<< ((n) + 16))
end_define

begin_define
define|#
directive|define
name|JZ_TC_TMSR
value|0x00000034
end_define

begin_comment
comment|/* timer flag mask set */
end_comment

begin_define
define|#
directive|define
name|JZ_TC_TMCR
value|0x00000038
end_define

begin_comment
comment|/* timer flag mask clear*/
end_comment

begin_define
define|#
directive|define
name|JZ_TC_TDFR
parameter_list|(
name|n
parameter_list|)
value|(0x00000040 + (n * 0x10))
end_define

begin_comment
comment|/* FULL compare */
end_comment

begin_define
define|#
directive|define
name|JZ_TC_TDHR
parameter_list|(
name|n
parameter_list|)
value|(0x00000044 + (n * 0x10))
end_define

begin_comment
comment|/* HALF compare */
end_comment

begin_define
define|#
directive|define
name|JZ_TC_TCNT
parameter_list|(
name|n
parameter_list|)
value|(0x00000048 + (n * 0x10))
end_define

begin_comment
comment|/* count */
end_comment

begin_define
define|#
directive|define
name|JZ_TC_TCSR
parameter_list|(
name|n
parameter_list|)
value|(0x0000004c + (n * 0x10))
end_define

begin_comment
comment|/* same bits as in JZ_WDOG_TCSR	*/
end_comment

begin_comment
comment|/* operating system timer */
end_comment

begin_define
define|#
directive|define
name|JZ_OST_DATA
value|0x000000e0
end_define

begin_comment
comment|/* compare */
end_comment

begin_define
define|#
directive|define
name|JZ_OST_CNT_LO
value|0x000000e4
end_define

begin_define
define|#
directive|define
name|JZ_OST_CNT_HI
value|0x000000e8
end_define

begin_define
define|#
directive|define
name|JZ_OST_CTRL
value|0x000000ec
end_define

begin_define
define|#
directive|define
name|OSTC_PCK_EN
value|0x0001
end_define

begin_comment
comment|/* use PCLK */
end_comment

begin_define
define|#
directive|define
name|OSTC_RTC_EN
value|0x0002
end_define

begin_comment
comment|/* use RTCCLK */
end_comment

begin_define
define|#
directive|define
name|OSTC_EXT_EN
value|0x0004
end_define

begin_comment
comment|/* use EXTCLK */
end_comment

begin_define
define|#
directive|define
name|OSTC_PRESCALE_M
value|0x0038
end_define

begin_define
define|#
directive|define
name|OSTC_DIV_1
value|0x0000
end_define

begin_define
define|#
directive|define
name|OSTC_DIV_4
value|0x0008
end_define

begin_define
define|#
directive|define
name|OSTC_DIV_16
value|0x0010
end_define

begin_define
define|#
directive|define
name|OSTC_DIV_64
value|0x0018
end_define

begin_define
define|#
directive|define
name|OSTC_DIV_256
value|0x0020
end_define

begin_define
define|#
directive|define
name|OSTC_DIV_1024
value|0x0028
end_define

begin_define
define|#
directive|define
name|OSTC_SHUTDOWN
value|0x0200
end_define

begin_define
define|#
directive|define
name|OSTC_MODE
value|0x8000
end_define

begin_comment
comment|/* 0 - reset to 0 when = OST_DATA */
end_comment

begin_define
define|#
directive|define
name|JZ_OST_CNT_U32
value|0x000000fc
end_define

begin_comment
comment|/* copy of CNT_HI when reading CNT_LO */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|writereg
parameter_list|(
name|uint32_t
name|reg
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
operator|*
operator|(
specifier|volatile
name|int32_t
operator|*
operator|)
name|MIPS_PHYS_TO_KSEG1
argument_list|(
name|reg
argument_list|)
operator|=
name|val
expr_stmt|;
name|mips_wbflush
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint32_t
name|readreg
parameter_list|(
name|uint32_t
name|reg
parameter_list|)
block|{
name|mips_wbflush
argument_list|()
expr_stmt|;
return|return
operator|*
operator|(
specifier|volatile
name|int32_t
operator|*
operator|)
name|MIPS_PHYS_TO_KSEG1
argument_list|(
name|reg
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Clock management */
end_comment

begin_define
define|#
directive|define
name|JZ_CGU_BASE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|JZ_CPCCR
value|0x00000000
end_define

begin_comment
comment|/* Clock Control Register */
end_comment

begin_define
define|#
directive|define
name|JZ_PDIV_M
value|0x000f0000
end_define

begin_comment
comment|/* PCLK divider mask */
end_comment

begin_define
define|#
directive|define
name|JZ_PDIV_S
value|16
end_define

begin_comment
comment|/* PCLK divider shift */
end_comment

begin_define
define|#
directive|define
name|JZ_CDIV_M
value|0x0000000f
end_define

begin_comment
comment|/* CPU clock divider mask */
end_comment

begin_define
define|#
directive|define
name|JZ_CDIV_S
value|0
end_define

begin_comment
comment|/* CPU clock divider shift */
end_comment

begin_define
define|#
directive|define
name|JZ_CPAPCR
value|0x00000010
end_define

begin_comment
comment|/* APLL */
end_comment

begin_define
define|#
directive|define
name|JZ_CPMPCR
value|0x00000014
end_define

begin_comment
comment|/* MPLL */
end_comment

begin_define
define|#
directive|define
name|JZ_CPEPCR
value|0x00000018
end_define

begin_comment
comment|/* EPLL */
end_comment

begin_define
define|#
directive|define
name|JZ_CPVPCR
value|0x0000001C
end_define

begin_comment
comment|/* VPLL */
end_comment

begin_define
define|#
directive|define
name|JZ_PLLM_S
value|19
end_define

begin_comment
comment|/* PLL multiplier shift */
end_comment

begin_define
define|#
directive|define
name|JZ_PLLM_M
value|0xfff80000
end_define

begin_comment
comment|/* PLL multiplier mask */
end_comment

begin_define
define|#
directive|define
name|JZ_PLLN_S
value|13
end_define

begin_comment
comment|/* PLL divider shift */
end_comment

begin_define
define|#
directive|define
name|JZ_PLLN_M
value|0x0007e000
end_define

begin_comment
comment|/* PLL divider mask */
end_comment

begin_define
define|#
directive|define
name|JZ_PLLP_S
value|9
end_define

begin_comment
comment|/* PLL postdivider shift */
end_comment

begin_define
define|#
directive|define
name|JZ_PLLP_M
value|0x00001700
end_define

begin_comment
comment|/* PLL postdivider mask */
end_comment

begin_define
define|#
directive|define
name|JZ_PLLON
value|0x00000010
end_define

begin_comment
comment|/* PLL is on and stable */
end_comment

begin_define
define|#
directive|define
name|JZ_PLLBP
value|0x00000002
end_define

begin_comment
comment|/* PLL bypass */
end_comment

begin_define
define|#
directive|define
name|JZ_PLLEN
value|0x00000001
end_define

begin_comment
comment|/* PLL enable */
end_comment

begin_define
define|#
directive|define
name|JZ_CLKGR0
value|0x00000020
end_define

begin_comment
comment|/* Clock Gating Registers */
end_comment

begin_define
define|#
directive|define
name|CLK_NEMC
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|CLK_BCH
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|CLK_OTG0
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|CLK_MSC0
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|CLK_SSI0
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|CLK_SMB0
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|CLK_SMB1
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|CLK_SCC
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|CLK_AIC
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|CLK_TSSI0
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|CLK_OWI
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|CLK_MSC1
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|CLK_MSC2
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|CLK_KBC
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|CLK_SADC
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|CLK_UART0
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|CLK_UART1
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|CLK_UART2
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|CLK_UART3
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|CLK_SSI1
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|CLK_SSI2
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|CLK_PDMA
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|CLK_GPS
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|CLK_MAC
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|CLK_UHC
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|CLK_SMB2
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|CLK_CIM
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|CLK_TVE
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|CLK_LCD
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|CLK_IPU
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|CLK_DDR0
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|CLK_DDR1
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|JZ_CLKGR1
value|0x00000028
end_define

begin_comment
comment|/* Clock Gating Registers */
end_comment

begin_define
define|#
directive|define
name|CLK_SMB3
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|CLK_TSSI1
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|CLK_VPU
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|CLK_PCM
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|CLK_GPU
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|CLK_COMPRESS
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|CLK_AIC1
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|CLK_GPVLC
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|CLK_OTG1
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|CLK_HDMI
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|CLK_UART4
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|CLK_AHB_MON
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|CLK_SMB4
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|CLK_DES
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|CLK_X2D
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|CLK_P1
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|JZ_DDCDR
value|0x0000002c
end_define

begin_comment
comment|/* DDR clock divider register */
end_comment

begin_define
define|#
directive|define
name|JZ_VPUCDR
value|0x00000030
end_define

begin_comment
comment|/* VPU clock divider register */
end_comment

begin_define
define|#
directive|define
name|JZ_I2SCDR
value|0x00000060
end_define

begin_comment
comment|/* I2S device clock divider register */
end_comment

begin_define
define|#
directive|define
name|JZ_I2S1CDR
value|0x000000a0
end_define

begin_comment
comment|/* I2S device clock divider register */
end_comment

begin_define
define|#
directive|define
name|JZ_USBCDR
value|0x00000050
end_define

begin_comment
comment|/* OTG PHY clock divider register */
end_comment

begin_define
define|#
directive|define
name|JZ_LP0CDR
value|0x00000054
end_define

begin_comment
comment|/* LCD0 pix clock divider register */
end_comment

begin_define
define|#
directive|define
name|JZ_LP1CDR
value|0x00000064
end_define

begin_comment
comment|/* LCD1 pix clock divider register */
end_comment

begin_define
define|#
directive|define
name|JZ_MSC0CDR
value|0x00000068
end_define

begin_comment
comment|/* MSC0 clock divider register */
end_comment

begin_define
define|#
directive|define
name|JZ_MSC1CDR
value|0x000000a4
end_define

begin_comment
comment|/* MSC1 clock divider register */
end_comment

begin_define
define|#
directive|define
name|JZ_MSC2CDR
value|0x000000a8
end_define

begin_comment
comment|/* MSC2 clock divider register */
end_comment

begin_define
define|#
directive|define
name|MSCCDR_SCLK_A
value|0x40000000
end_define

begin_define
define|#
directive|define
name|MSCCDR_MPLL
value|0x80000000
end_define

begin_define
define|#
directive|define
name|MSCCDR_CE
value|0x20000000
end_define

begin_define
define|#
directive|define
name|MSCCDR_BUSY
value|0x10000000
end_define

begin_define
define|#
directive|define
name|MSCCDR_STOP
value|0x08000000
end_define

begin_define
define|#
directive|define
name|MSCCDR_PHASE
value|0x00008000
end_define

begin_comment
comment|/* 0 - 90deg phase, 1 - 180 */
end_comment

begin_define
define|#
directive|define
name|MSCCDR_DIV_M
value|0x000000ff
end_define

begin_comment
comment|/* src / ((div + 1) * 2) */
end_comment

begin_define
define|#
directive|define
name|UHCCDR_DIV_M
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|JZ_UHCCDR
value|0x0000006c
end_define

begin_comment
comment|/* UHC 48M clock divider register */
end_comment

begin_define
define|#
directive|define
name|UHCCDR_SCLK_A
value|0x00000000
end_define

begin_define
define|#
directive|define
name|UHCCDR_MPLL
value|0x40000000
end_define

begin_define
define|#
directive|define
name|UHCCDR_EPLL
value|0x80000000
end_define

begin_define
define|#
directive|define
name|UHCCDR_OTG_PHY
value|0xc0000000
end_define

begin_define
define|#
directive|define
name|UHCCDR_CLK_MASK
value|0xc0000000
end_define

begin_define
define|#
directive|define
name|UHCCDR_CE
value|0x20000000
end_define

begin_define
define|#
directive|define
name|UHCCDR_BUSY
value|0x10000000
end_define

begin_define
define|#
directive|define
name|UHCCDR_STOP
value|0x08000000
end_define

begin_define
define|#
directive|define
name|UHCCDR_DIV_M
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|UHCCDR_DIV
parameter_list|(
name|d
parameter_list|)
value|(d)
end_define

begin_define
define|#
directive|define
name|JZ_SSICDR
value|0x00000074
end_define

begin_comment
comment|/* SSI clock divider register */
end_comment

begin_define
define|#
directive|define
name|JZ_CIMCDR
value|0x0000007c
end_define

begin_comment
comment|/* CIM MCLK clock divider register */
end_comment

begin_define
define|#
directive|define
name|JZ_PCMCDR
value|0x00000084
end_define

begin_comment
comment|/* PCM device clock divider register */
end_comment

begin_define
define|#
directive|define
name|JZ_GPUCDR
value|0x00000088
end_define

begin_comment
comment|/* GPU clock divider register */
end_comment

begin_define
define|#
directive|define
name|JZ_HDMICDR
value|0x0000008c
end_define

begin_comment
comment|/* HDMI clock divider register */
end_comment

begin_define
define|#
directive|define
name|JZ_BCHCDR
value|0x000000ac
end_define

begin_comment
comment|/* BCH clock divider register */
end_comment

begin_define
define|#
directive|define
name|JZ_CPM_INTR
value|0x000000b0
end_define

begin_comment
comment|/* CPM interrupt register */
end_comment

begin_define
define|#
directive|define
name|JZ_CPM_INTRE
value|0x000000b4
end_define

begin_comment
comment|/* CPM interrupt enable register */
end_comment

begin_define
define|#
directive|define
name|JZ_CPSPR
value|0x00000034
end_define

begin_comment
comment|/* CPM scratch register */
end_comment

begin_define
define|#
directive|define
name|JZ_CPSRPR
value|0x00000038
end_define

begin_comment
comment|/* CPM scratch protected register */
end_comment

begin_define
define|#
directive|define
name|JZ_USBPCR
value|0x0000003c
end_define

begin_comment
comment|/* USB parameter control register */
end_comment

begin_define
define|#
directive|define
name|PCR_USB_MODE
value|0x80000000
end_define

begin_comment
comment|/* 1 - otg */
end_comment

begin_define
define|#
directive|define
name|PCR_AVLD_REG
value|0x40000000
end_define

begin_define
define|#
directive|define
name|PCR_IDPULLUP_MASK
value|0x30000000
end_define

begin_define
define|#
directive|define
name|PCR_INCR_MASK
value|0x08000000
end_define

begin_define
define|#
directive|define
name|PCR_TCRISETUNE
value|0x04000000
end_define

begin_define
define|#
directive|define
name|PCR_COMMONONN
value|0x02000000
end_define

begin_define
define|#
directive|define
name|PCR_VBUSVLDEXT
value|0x01000000
end_define

begin_define
define|#
directive|define
name|PCR_VBUSVLDEXTSEL
value|0x00800000
end_define

begin_define
define|#
directive|define
name|PCR_POR
value|0x00400000
end_define

begin_define
define|#
directive|define
name|PCR_SIDDQ
value|0x00200000
end_define

begin_define
define|#
directive|define
name|PCR_OTG_DISABLE
value|0x00100000
end_define

begin_define
define|#
directive|define
name|PCR_COMPDISTN_M
value|0x000e0000
end_define

begin_define
define|#
directive|define
name|PCR_OTGTUNE
value|0x0001c000
end_define

begin_define
define|#
directive|define
name|PCR_SQRXTUNE
value|0x00003800
end_define

begin_define
define|#
directive|define
name|PCR_TXFSLSTUNE
value|0x00000780
end_define

begin_define
define|#
directive|define
name|PCR_TXPREEMPHTUNE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|PCR_TXHSXVTUNE
value|0x00000030
end_define

begin_define
define|#
directive|define
name|PCR_TXVREFTUNE
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|JZ_USBRDT
value|0x00000040
end_define

begin_comment
comment|/* Reset detect timer register */
end_comment

begin_define
define|#
directive|define
name|USBRDT_USBRDT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|USBRDT_USBRDT_WIDTH
value|23
end_define

begin_define
define|#
directive|define
name|USBRDT_VBFIL_LD_EN
value|0x01000000
end_define

begin_define
define|#
directive|define
name|JZ_USBVBFIL
value|0x00000044
end_define

begin_comment
comment|/* USB jitter filter register */
end_comment

begin_define
define|#
directive|define
name|USBVBFIL_IDDIGFIL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|USBVBFIL_IDDIGFIL_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|USBVBFIL_USBVBFIL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|USBVBFIL_USBVBFIL_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|JZ_USBPCR1
value|0x00000048
end_define

begin_comment
comment|/* USB parameter control register 1 */
end_comment

begin_define
define|#
directive|define
name|PCR_SYNOPSYS
value|0x10000000
end_define

begin_comment
comment|/* Mentor mode otherwise */
end_comment

begin_define
define|#
directive|define
name|PCR_REFCLK_CORE
value|0x08000000
end_define

begin_define
define|#
directive|define
name|PCR_REFCLK_XO25
value|0x04000000
end_define

begin_define
define|#
directive|define
name|PCR_REFCLK_CO
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PCR_REFCLK_M
value|0x0c000000
end_define

begin_define
define|#
directive|define
name|PCR_CLK_M
value|0x03000000
end_define

begin_comment
comment|/* clock */
end_comment

begin_define
define|#
directive|define
name|PCR_CLK_192
value|0x03000000
end_define

begin_comment
comment|/* 19.2MHz */
end_comment

begin_define
define|#
directive|define
name|PCR_CLK_48
value|0x02000000
end_define

begin_comment
comment|/* 48MHz */
end_comment

begin_define
define|#
directive|define
name|PCR_CLK_24
value|0x01000000
end_define

begin_comment
comment|/* 24MHz */
end_comment

begin_define
define|#
directive|define
name|PCR_CLK_12
value|0x00000000
end_define

begin_comment
comment|/* 12MHz */
end_comment

begin_define
define|#
directive|define
name|PCR_DMPD1
value|0x00800000
end_define

begin_comment
comment|/* pull down D- on port 1 */
end_comment

begin_define
define|#
directive|define
name|PCR_DPPD1
value|0x00400000
end_define

begin_comment
comment|/* pull down D+ on port 1 */
end_comment

begin_define
define|#
directive|define
name|PCR_PORT0_RST
value|0x00200000
end_define

begin_comment
comment|/* port 0 reset */
end_comment

begin_define
define|#
directive|define
name|PCR_PORT1_RST
value|0x00100000
end_define

begin_comment
comment|/* port 1 reset */
end_comment

begin_define
define|#
directive|define
name|PCR_WORD_I_F0
value|0x00080000
end_define

begin_comment
comment|/* 1: 16bit/30M, 8/60 otherw. */
end_comment

begin_define
define|#
directive|define
name|PCR_WORD_I_F1
value|0x00040000
end_define

begin_comment
comment|/* same for port 1 */
end_comment

begin_define
define|#
directive|define
name|PCR_COMPDISTUNE
value|0x00038000
end_define

begin_comment
comment|/* disconnect threshold */
end_comment

begin_define
define|#
directive|define
name|PCR_SQRXTUNE1
value|0x00007000
end_define

begin_comment
comment|/* squelch threshold */
end_comment

begin_define
define|#
directive|define
name|PCR_TXFSLSTUNE1
value|0x00000f00
end_define

begin_comment
comment|/* FS/LS impedance adj. */
end_comment

begin_define
define|#
directive|define
name|PCR_TXPREEMPH
value|0x00000080
end_define

begin_comment
comment|/* HS transm. pre-emphasis */
end_comment

begin_define
define|#
directive|define
name|PCR_TXHSXVTUNE1
value|0x00000060
end_define

begin_comment
comment|/* dp/dm voltage adj. */
end_comment

begin_define
define|#
directive|define
name|PCR_TXVREFTUNE1
value|0x00000017
end_define

begin_comment
comment|/* HS DC voltage adj. */
end_comment

begin_define
define|#
directive|define
name|PCR_TXRISETUNE1
value|0x00000001
end_define

begin_comment
comment|/* rise/fall wave adj. */
end_comment

begin_comment
comment|/* power manager */
end_comment

begin_define
define|#
directive|define
name|JZ_LPCR
value|0x00000004
end_define

begin_define
define|#
directive|define
name|LPCR_PD_SCPU
value|(1u<< 31)
end_define

begin_comment
comment|/* CPU1 power down */
end_comment

begin_define
define|#
directive|define
name|LPCR_PD_VPU
value|(1u<< 30)
end_define

begin_comment
comment|/* VPU power down */
end_comment

begin_define
define|#
directive|define
name|LPCR_PD_GPU
value|(1u<< 29)
end_define

begin_comment
comment|/* GPU power down */
end_comment

begin_define
define|#
directive|define
name|LPCR_PD_GPS
value|(1u<< 28)
end_define

begin_comment
comment|/* GPS power down */
end_comment

begin_define
define|#
directive|define
name|LPCR_SCPUS
value|(1u<< 27)
end_define

begin_comment
comment|/* CPU1 power down status */
end_comment

begin_define
define|#
directive|define
name|LPCR_VPUS
value|(1u<< 26)
end_define

begin_comment
comment|/* VPU power down status */
end_comment

begin_define
define|#
directive|define
name|LPCR_GPUS
value|(1u<< 25)
end_define

begin_comment
comment|/* GPU power down status */
end_comment

begin_define
define|#
directive|define
name|LPCR_GPSS
value|(1u<< 24)
end_define

begin_comment
comment|/* GPS power down status */
end_comment

begin_define
define|#
directive|define
name|LPCR_GPU_IDLE
value|(1u<< 20)
end_define

begin_comment
comment|/* GPU idle status */
end_comment

begin_define
define|#
directive|define
name|LPCR_PST_SHIFT
value|8
end_define

begin_comment
comment|/* Power stability time */
end_comment

begin_define
define|#
directive|define
name|LPCR_PST_MASK
value|(0xFFFu<< 8)
end_define

begin_define
define|#
directive|define
name|LPCR_DUTY_SHIFT
value|3
end_define

begin_comment
comment|/* CPU clock duty */
end_comment

begin_define
define|#
directive|define
name|LPCR_DUTY_MASK
value|(0x1Fu<< 3)
end_define

begin_define
define|#
directive|define
name|LPCR_DOZE
value|(1u<< 2)
end_define

begin_comment
comment|/* Doze mode */
end_comment

begin_define
define|#
directive|define
name|LPCR_LPM_SHIFT
value|0
end_define

begin_comment
comment|/* Low power mode */
end_comment

begin_define
define|#
directive|define
name|LPCR_LPM_MASK
value|(0x03u<< 0)
end_define

begin_define
define|#
directive|define
name|JZ_OPCR
value|0x00000024
end_define

begin_comment
comment|/* Oscillator Power Control Reg. */
end_comment

begin_define
define|#
directive|define
name|OPCR_IDLE_DIS
value|0x80000000
end_define

begin_comment
comment|/* don't stop CPU clk on idle */
end_comment

begin_define
define|#
directive|define
name|OPCR_GPU_CLK_ST
value|0x40000000
end_define

begin_comment
comment|/* stop GPU clock */
end_comment

begin_define
define|#
directive|define
name|OPCR_L2CM_M
value|0x0c000000
end_define

begin_define
define|#
directive|define
name|OPCR_L2CM_ON
value|0x00000000
end_define

begin_comment
comment|/* L2 stays on in sleep */
end_comment

begin_define
define|#
directive|define
name|OPCR_L2CM_RET
value|0x04000000
end_define

begin_comment
comment|/* L2 retention mode in sleep */
end_comment

begin_define
define|#
directive|define
name|OPCR_L2CM_OFF
value|0x08000000
end_define

begin_comment
comment|/* L2 powers down in sleep */
end_comment

begin_define
define|#
directive|define
name|OPCR_SPENDN0
value|0x00000080
end_define

begin_comment
comment|/* 0 - OTG port forced down */
end_comment

begin_define
define|#
directive|define
name|OPCR_SPENDN1
value|0x00000040
end_define

begin_comment
comment|/* 0 - UHC port forced down */
end_comment

begin_define
define|#
directive|define
name|OPCR_BUS_MODE
value|0x00000020
end_define

begin_comment
comment|/* 1 - bursts */
end_comment

begin_define
define|#
directive|define
name|OPCR_O1SE
value|0x00000010
end_define

begin_comment
comment|/* EXTCLK on in sleep */
end_comment

begin_define
define|#
directive|define
name|OPCR_PD
value|0x00000008
end_define

begin_comment
comment|/* P0 down in sleep */
end_comment

begin_define
define|#
directive|define
name|OPCR_ERCS
value|0x00000004
end_define

begin_comment
comment|/* 1 RTCCLK, 0 EXTCLK/512 */
end_comment

begin_define
define|#
directive|define
name|OPCR_CPU_MODE
value|0x00000002
end_define

begin_comment
comment|/* 1 access 'accelerated' */
end_comment

begin_define
define|#
directive|define
name|OPCR_OSE
value|0x00000001
end_define

begin_comment
comment|/* disable EXTCLK */
end_comment

begin_define
define|#
directive|define
name|JZ_SPCR0
value|0x000000b8
end_define

begin_comment
comment|/* SRAM Power Control Registers */
end_comment

begin_define
define|#
directive|define
name|JZ_SPCR1
value|0x000000bc
end_define

begin_define
define|#
directive|define
name|JZ_SRBC
value|0x000000c4
end_define

begin_comment
comment|/* Soft Reset& Bus Control */
end_comment

begin_define
define|#
directive|define
name|SRBC_UHC_SR
value|0x00004000
end_define

begin_comment
comment|/* UHC soft reset*/
end_comment

begin_comment
comment|/*  * random number generator  *  * Its function currently isn't documented by Ingenic.  * However, testing suggests that it works as expected.  */
end_comment

begin_define
define|#
directive|define
name|JZ_ERNG
value|0x000000d8
end_define

begin_define
define|#
directive|define
name|JZ_RNG
value|0x000000dc
end_define

begin_comment
comment|/* Interrupt controller */
end_comment

begin_define
define|#
directive|define
name|JZ_ICBASE
value|0x10001000
end_define

begin_comment
comment|/* IC base address */
end_comment

begin_define
define|#
directive|define
name|JZ_ICSR0
value|0x00000000
end_define

begin_comment
comment|/* raw IRQ line status */
end_comment

begin_define
define|#
directive|define
name|JZ_ICMR0
value|0x00000004
end_define

begin_comment
comment|/* IRQ mask, 1 masks IRQ */
end_comment

begin_define
define|#
directive|define
name|JZ_ICMSR0
value|0x00000008
end_define

begin_comment
comment|/* sets bits in mask register */
end_comment

begin_define
define|#
directive|define
name|JZ_ICMCR0
value|0x0000000c
end_define

begin_comment
comment|/* clears bits in mask register */
end_comment

begin_define
define|#
directive|define
name|JZ_ICPR0
value|0x00000010
end_define

begin_comment
comment|/* line status after masking */
end_comment

begin_define
define|#
directive|define
name|JZ_ICSR1
value|0x00000020
end_define

begin_comment
comment|/* raw IRQ line status */
end_comment

begin_define
define|#
directive|define
name|JZ_ICMR1
value|0x00000024
end_define

begin_comment
comment|/* IRQ mask, 1 masks IRQ */
end_comment

begin_define
define|#
directive|define
name|JZ_ICMSR1
value|0x00000028
end_define

begin_comment
comment|/* sets bits in mask register */
end_comment

begin_define
define|#
directive|define
name|JZ_ICMCR1
value|0x0000002c
end_define

begin_comment
comment|/* clears bits in maks register */
end_comment

begin_define
define|#
directive|define
name|JZ_ICPR1
value|0x00000030
end_define

begin_comment
comment|/* line status after masking */
end_comment

begin_define
define|#
directive|define
name|JZ_DSR0
value|0x00000034
end_define

begin_comment
comment|/* source for PDMA */
end_comment

begin_define
define|#
directive|define
name|JZ_DMR0
value|0x00000038
end_define

begin_comment
comment|/* mask for PDMA */
end_comment

begin_define
define|#
directive|define
name|JZ_DPR0
value|0x0000003c
end_define

begin_comment
comment|/* pending for PDMA */
end_comment

begin_define
define|#
directive|define
name|JZ_DSR1
value|0x00000040
end_define

begin_comment
comment|/* source for PDMA */
end_comment

begin_define
define|#
directive|define
name|JZ_DMR1
value|0x00000044
end_define

begin_comment
comment|/* mask for PDMA */
end_comment

begin_define
define|#
directive|define
name|JZ_DPR1
value|0x00000048
end_define

begin_comment
comment|/* pending for PDMA */
end_comment

begin_comment
comment|/* memory controller */
end_comment

begin_define
define|#
directive|define
name|JZ_DMMAP0
value|0x13010024
end_define

begin_define
define|#
directive|define
name|JZ_DMMAP1
value|0x13010028
end_define

begin_define
define|#
directive|define
name|DMMAP_BASE
value|0x0000ff00
end_define

begin_comment
comment|/* base PADDR of memory chunk */
end_comment

begin_define
define|#
directive|define
name|DMMAP_MASK
value|0x000000ff
end_define

begin_comment
comment|/* mask which bits of PADDR are 						 * constant */
end_comment

begin_comment
comment|/* USB controllers */
end_comment

begin_define
define|#
directive|define
name|JZ_EHCI_BASE
value|0x13490000
end_define

begin_define
define|#
directive|define
name|JZ_EHCI_REG_UTMI_BUS
value|0x000000b0
end_define

begin_define
define|#
directive|define
name|UTMI_BUS_WIDTH
value|0x00000040
end_define

begin_define
define|#
directive|define
name|JZ_OHCI_BASE
value|0x134a0000
end_define

begin_define
define|#
directive|define
name|JZ_DWC2_BASE
value|0x13500000
end_define

begin_define
define|#
directive|define
name|JZ_DWC2_GUSBCFG
value|0
end_define

begin_comment
comment|/* Ethernet */
end_comment

begin_define
define|#
directive|define
name|JZ_DME_BASE
value|0x16000000
end_define

begin_define
define|#
directive|define
name|JZ_DME_IO
value|0
end_define

begin_define
define|#
directive|define
name|JZ_DME_DATA
value|2
end_define

begin_comment
comment|/* GPIO */
end_comment

begin_define
define|#
directive|define
name|JZ_GPIO_A_BASE
value|0x10010000
end_define

begin_define
define|#
directive|define
name|JZ_GPIO_B_BASE
value|0x10010100
end_define

begin_define
define|#
directive|define
name|JZ_GPIO_C_BASE
value|0x10010200
end_define

begin_define
define|#
directive|define
name|JZ_GPIO_D_BASE
value|0x10010300
end_define

begin_define
define|#
directive|define
name|JZ_GPIO_E_BASE
value|0x10010400
end_define

begin_define
define|#
directive|define
name|JZ_GPIO_F_BASE
value|0x10010500
end_define

begin_comment
comment|/* GPIO registers per port */
end_comment

begin_define
define|#
directive|define
name|JZ_GPIO_PIN
value|0x00000000
end_define

begin_comment
comment|/* pin level register */
end_comment

begin_comment
comment|/* 0 - normal gpio, 1 - interrupt */
end_comment

begin_define
define|#
directive|define
name|JZ_GPIO_INT
value|0x00000010
end_define

begin_comment
comment|/* interrupt register */
end_comment

begin_define
define|#
directive|define
name|JZ_GPIO_INTS
value|0x00000014
end_define

begin_comment
comment|/* interrupt set register */
end_comment

begin_define
define|#
directive|define
name|JZ_GPIO_INTC
value|0x00000018
end_define

begin_comment
comment|/* interrupt clear register */
end_comment

begin_comment
comment|/*  * INT == 1: 1 disables interrupt  * INT == 0: device select, see below  */
end_comment

begin_define
define|#
directive|define
name|JZ_GPIO_MASK
value|0x00000020
end_define

begin_comment
comment|/* port mask register */
end_comment

begin_define
define|#
directive|define
name|JZ_GPIO_MASKS
value|0x00000024
end_define

begin_comment
comment|/* port mask set register */
end_comment

begin_define
define|#
directive|define
name|JZ_GPIO_MASKC
value|0x00000028
end_define

begin_comment
comment|/* port mask clear register */
end_comment

begin_comment
comment|/*  * INT == 1: 0 - level triggered, 1 - edge triggered  * INT == 0: 0 - device select, see below  */
end_comment

begin_define
define|#
directive|define
name|JZ_GPIO_PAT1
value|0x00000030
end_define

begin_comment
comment|/* pattern 1 register */
end_comment

begin_define
define|#
directive|define
name|JZ_GPIO_PAT1S
value|0x00000034
end_define

begin_comment
comment|/* pattern 1 set register */
end_comment

begin_define
define|#
directive|define
name|JZ_GPIO_PAT1C
value|0x00000038
end_define

begin_comment
comment|/* pattern 1 clear register */
end_comment

begin_comment
comment|/*  * INT == 1:  *   PAT1 == 0: 0 - trigger on low, 1 - trigger on high  *   PAT0 == 1: 0 - trigger on falling edge, 1 - trigger on rising edge  * INT == 0:  *   MASK == 0:  *     PAT1 == 0: 0 - device 0, 1 - device 1  *     PAT0 == 1: 0 - device 2, 1 - device 3  *   MASK == 1:  *     PAT1 == 0: set gpio output  *     PAT1 == 1: pin is input  */
end_comment

begin_define
define|#
directive|define
name|JZ_GPIO_PAT0
value|0x00000040
end_define

begin_comment
comment|/* pattern 0 register */
end_comment

begin_define
define|#
directive|define
name|JZ_GPIO_PAT0S
value|0x00000044
end_define

begin_comment
comment|/* pattern 0 set register */
end_comment

begin_define
define|#
directive|define
name|JZ_GPIO_PAT0C
value|0x00000048
end_define

begin_comment
comment|/* pattern 0 clear register */
end_comment

begin_comment
comment|/* 1 - interrupt happened */
end_comment

begin_define
define|#
directive|define
name|JZ_GPIO_FLAG
value|0x00000050
end_define

begin_comment
comment|/* flag register */
end_comment

begin_define
define|#
directive|define
name|JZ_GPIO_FLAGC
value|0x00000058
end_define

begin_comment
comment|/* flag clear register */
end_comment

begin_comment
comment|/* 1 - disable pull up/down resistors */
end_comment

begin_define
define|#
directive|define
name|JZ_GPIO_DPULL
value|0x00000070
end_define

begin_comment
comment|/* pull disable register */
end_comment

begin_define
define|#
directive|define
name|JZ_GPIO_DPULLS
value|0x00000074
end_define

begin_comment
comment|/* pull disable set register */
end_comment

begin_define
define|#
directive|define
name|JZ_GPIO_DPULLC
value|0x00000078
end_define

begin_comment
comment|/* pull disable clear register */
end_comment

begin_comment
comment|/* the following are uncommented in the manual */
end_comment

begin_define
define|#
directive|define
name|JZ_GPIO_DRVL
value|0x00000080
end_define

begin_comment
comment|/* drive low register */
end_comment

begin_define
define|#
directive|define
name|JZ_GPIO_DRVLS
value|0x00000084
end_define

begin_comment
comment|/* drive low set register */
end_comment

begin_define
define|#
directive|define
name|JZ_GPIO_DRVLC
value|0x00000088
end_define

begin_comment
comment|/* drive low clear register */
end_comment

begin_define
define|#
directive|define
name|JZ_GPIO_DIR
value|0x00000090
end_define

begin_comment
comment|/* direction register */
end_comment

begin_define
define|#
directive|define
name|JZ_GPIO_DIRS
value|0x00000094
end_define

begin_comment
comment|/* direction register */
end_comment

begin_define
define|#
directive|define
name|JZ_GPIO_DIRC
value|0x00000098
end_define

begin_comment
comment|/* direction register */
end_comment

begin_define
define|#
directive|define
name|JZ_GPIO_DRVH
value|0x000000a0
end_define

begin_comment
comment|/* drive high register */
end_comment

begin_define
define|#
directive|define
name|JZ_GPIO_DRVHS
value|0x000000a4
end_define

begin_comment
comment|/* drive high set register */
end_comment

begin_define
define|#
directive|define
name|JZ_GPIO_DRVHC
value|0x000000a8
end_define

begin_comment
comment|/* drive high clear register */
end_comment

begin_comment
comment|/* I2C / SMBus */
end_comment

begin_define
define|#
directive|define
name|JZ_SMB0_BASE
value|0x10050000
end_define

begin_define
define|#
directive|define
name|JZ_SMB1_BASE
value|0x10051000
end_define

begin_define
define|#
directive|define
name|JZ_SMB2_BASE
value|0x10052000
end_define

begin_define
define|#
directive|define
name|JZ_SMB3_BASE
value|0x10053000
end_define

begin_define
define|#
directive|define
name|JZ_SMB4_BASE
value|0x10054000
end_define

begin_comment
comment|/* SMBus register offsets, per port */
end_comment

begin_define
define|#
directive|define
name|JZ_SMBCON
value|0x00
end_define

begin_comment
comment|/* SMB control */
end_comment

begin_define
define|#
directive|define
name|JZ_STPHLD
value|0x80
end_define

begin_comment
comment|/* Stop Hold Enable bit */
end_comment

begin_define
define|#
directive|define
name|JZ_SLVDIS
value|0x40
end_define

begin_comment
comment|/* 1 - slave disabled */
end_comment

begin_define
define|#
directive|define
name|JZ_REST
value|0x20
end_define

begin_comment
comment|/* 1 - allow RESTART */
end_comment

begin_define
define|#
directive|define
name|JZ_MATP
value|0x10
end_define

begin_comment
comment|/* 1 - enable 10bit addr. for master */
end_comment

begin_define
define|#
directive|define
name|JZ_SATP
value|0x08
end_define

begin_comment
comment|/* 1 - enable 10bit addr. for slave */
end_comment

begin_define
define|#
directive|define
name|JZ_SPD_M
value|0x06
end_define

begin_comment
comment|/* bus speed control */
end_comment

begin_define
define|#
directive|define
name|JZ_SPD_100KB
value|0x02
end_define

begin_comment
comment|/* 100kBit/s mode */
end_comment

begin_define
define|#
directive|define
name|JZ_SPD_400KB
value|0x04
end_define

begin_comment
comment|/* 400kBit/s mode */
end_comment

begin_define
define|#
directive|define
name|JZ_MD
value|0x01
end_define

begin_comment
comment|/* enable master */
end_comment

begin_define
define|#
directive|define
name|JZ_SMBTAR
value|0x04
end_define

begin_comment
comment|/* SMB target address */
end_comment

begin_define
define|#
directive|define
name|JZ_SMATP
value|0x1000
end_define

begin_comment
comment|/* enable 10bit master addr */
end_comment

begin_define
define|#
directive|define
name|JZ_SPECIAL
value|0x0800
end_define

begin_comment
comment|/* 1 - special command */
end_comment

begin_define
define|#
directive|define
name|JZ_START
value|0x0400
end_define

begin_comment
comment|/* 1 - send START */
end_comment

begin_define
define|#
directive|define
name|JZ_SMBTAR_M
value|0x03ff
end_define

begin_comment
comment|/* target address */
end_comment

begin_define
define|#
directive|define
name|JZ_SMBSAR
value|0x08
end_define

begin_comment
comment|/* SMB slave address */
end_comment

begin_define
define|#
directive|define
name|JZ_SMBDC
value|0x10
end_define

begin_comment
comment|/* SMB data buffer and command */
end_comment

begin_define
define|#
directive|define
name|JZ_CMD
value|0x100
end_define

begin_comment
comment|/* 1 - read, 0 - write */
end_comment

begin_define
define|#
directive|define
name|JZ_DATA
value|0x0ff
end_define

begin_define
define|#
directive|define
name|JZ_SMBSHCNT
value|0x14
end_define

begin_comment
comment|/* Standard speed SMB SCL high count */
end_comment

begin_define
define|#
directive|define
name|JZ_SMBSLCNT
value|0x18
end_define

begin_comment
comment|/* Standard speed SMB SCL low count */
end_comment

begin_define
define|#
directive|define
name|JZ_SMBFHCNT
value|0x1C
end_define

begin_comment
comment|/* Fast speed SMB SCL high count */
end_comment

begin_define
define|#
directive|define
name|JZ_SMBFLCNT
value|0x20
end_define

begin_comment
comment|/* Fast speed SMB SCL low count */
end_comment

begin_define
define|#
directive|define
name|JZ_SMBINTST
value|0x2C
end_define

begin_comment
comment|/* SMB Interrupt Status */
end_comment

begin_define
define|#
directive|define
name|JZ_ISTT
value|0x400
end_define

begin_comment
comment|/* START or RESTART occured */
end_comment

begin_define
define|#
directive|define
name|JZ_ISTP
value|0x200
end_define

begin_comment
comment|/* STOP occured */
end_comment

begin_define
define|#
directive|define
name|JZ_TXABT
value|0x40
end_define

begin_comment
comment|/* ABORT occured */
end_comment

begin_define
define|#
directive|define
name|JZ_TXEMP
value|0x10
end_define

begin_comment
comment|/* TX FIFO is low */
end_comment

begin_define
define|#
directive|define
name|JZ_TXOF
value|0x08
end_define

begin_comment
comment|/* TX FIFO is high */
end_comment

begin_define
define|#
directive|define
name|JZ_RXFL
value|0x04
end_define

begin_comment
comment|/* RX FIFO is at  JZ_SMBRXTL*/
end_comment

begin_define
define|#
directive|define
name|JZ_RXOF
value|0x02
end_define

begin_comment
comment|/* RX FIFO is high */
end_comment

begin_define
define|#
directive|define
name|JZ_RXUF
value|0x01
end_define

begin_comment
comment|/* RX FIFO underflow */
end_comment

begin_define
define|#
directive|define
name|JZ_SMBINTM
value|0x30
end_define

begin_comment
comment|/* SMB Interrupt Mask */
end_comment

begin_define
define|#
directive|define
name|JZ_SMBRXTL
value|0x38
end_define

begin_comment
comment|/* SMB RxFIFO Threshold */
end_comment

begin_define
define|#
directive|define
name|JZ_SMBTXTL
value|0x3C
end_define

begin_comment
comment|/* SMB TxFIFO Threshold */
end_comment

begin_define
define|#
directive|define
name|JZ_SMBCINT
value|0x40
end_define

begin_comment
comment|/* Clear Interrupts */
end_comment

begin_define
define|#
directive|define
name|JZ_CLEARALL
value|0x01
end_define

begin_define
define|#
directive|define
name|JZ_SMBCRXUF
value|0x44
end_define

begin_comment
comment|/* Clear RXUF Interrupt */
end_comment

begin_define
define|#
directive|define
name|JZ_SMBCRXOF
value|0x48
end_define

begin_comment
comment|/* Clear RX_OVER Interrupt */
end_comment

begin_define
define|#
directive|define
name|JZ_SMBCTXOF
value|0x4C
end_define

begin_comment
comment|/* Clear TX_OVER Interrupt */
end_comment

begin_define
define|#
directive|define
name|JZ_SMBCRXREQ
value|0x50
end_define

begin_comment
comment|/* Clear RDREQ Interrupt */
end_comment

begin_define
define|#
directive|define
name|JZ_SMBCTXABT
value|0x54
end_define

begin_comment
comment|/* Clear TX_ABRT Interrupt */
end_comment

begin_define
define|#
directive|define
name|JZ_SMBCRXDN
value|0x58
end_define

begin_comment
comment|/* Clear RX_DONE Interrupt */
end_comment

begin_define
define|#
directive|define
name|JZ_SMBCACT
value|0x5c
end_define

begin_comment
comment|/* Clear ACTIVITY Interrupt */
end_comment

begin_define
define|#
directive|define
name|JZ_SMBCSTP
value|0x60
end_define

begin_comment
comment|/* Clear STOP Interrupt */
end_comment

begin_define
define|#
directive|define
name|JZ_SMBCSTT
value|0x64
end_define

begin_comment
comment|/* Clear START Interrupt */
end_comment

begin_define
define|#
directive|define
name|JZ_SMBCGC
value|0x68
end_define

begin_comment
comment|/* Clear GEN_CALL Interrupt */
end_comment

begin_define
define|#
directive|define
name|JZ_SMBENB
value|0x6C
end_define

begin_comment
comment|/* SMB Enable */
end_comment

begin_define
define|#
directive|define
name|JZ_ENABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|JZ_SMBST
value|0x70
end_define

begin_comment
comment|/* SMB Status register */
end_comment

begin_define
define|#
directive|define
name|JZ_SLVACT
value|0x40
end_define

begin_comment
comment|/* slave is active */
end_comment

begin_define
define|#
directive|define
name|JZ_MSTACT
value|0x20
end_define

begin_comment
comment|/* master is active */
end_comment

begin_define
define|#
directive|define
name|JZ_RFF
value|0x10
end_define

begin_comment
comment|/* RX FIFO is full */
end_comment

begin_define
define|#
directive|define
name|JZ_RFNE
value|0x08
end_define

begin_comment
comment|/* RX FIFO not empty */
end_comment

begin_define
define|#
directive|define
name|JZ_TFE
value|0x04
end_define

begin_comment
comment|/* TX FIFO is empty */
end_comment

begin_define
define|#
directive|define
name|JZ_TFNF
value|0x02
end_define

begin_comment
comment|/* TX FIFO is not full */
end_comment

begin_define
define|#
directive|define
name|JZ_ACT
value|0x01
end_define

begin_comment
comment|/* JZ_SLVACT | JZ_MSTACT */
end_comment

begin_define
define|#
directive|define
name|JZ_SMBABTSRC
value|0x80
end_define

begin_comment
comment|/* SMB Transmit Abort Status Register */
end_comment

begin_define
define|#
directive|define
name|JZ_SMBDMACR
value|0x88
end_define

begin_comment
comment|/* DMA Control Register */
end_comment

begin_define
define|#
directive|define
name|JZ_SMBDMATDL
value|0x8c
end_define

begin_comment
comment|/* DMA Transmit Data Level */
end_comment

begin_define
define|#
directive|define
name|JZ_SMBDMARDL
value|0x90
end_define

begin_comment
comment|/* DMA Receive Data Level */
end_comment

begin_define
define|#
directive|define
name|JZ_SMBSDASU
value|0x94
end_define

begin_comment
comment|/* SMB SDA Setup Register */
end_comment

begin_define
define|#
directive|define
name|JZ_SMBACKGC
value|0x98
end_define

begin_comment
comment|/* SMB ACK General Call Register */
end_comment

begin_define
define|#
directive|define
name|JZ_SMBENBST
value|0x9C
end_define

begin_comment
comment|/* SMB Enable Status Register */
end_comment

begin_define
define|#
directive|define
name|JZ_SMBSDAHD
value|0xD0
end_define

begin_comment
comment|/* SMB SDA HolD time Register */
end_comment

begin_define
define|#
directive|define
name|JZ_HDENB
value|0x100
end_define

begin_comment
comment|/* enable hold time */
end_comment

begin_comment
comment|/* SD/MMC hosts */
end_comment

begin_define
define|#
directive|define
name|JZ_MSC0_BASE
value|0x13450000
end_define

begin_define
define|#
directive|define
name|JZ_MSC1_BASE
value|0x13460000
end_define

begin_define
define|#
directive|define
name|JZ_MSC2_BASE
value|0x13470000
end_define

begin_define
define|#
directive|define
name|JZ_MSC_CTRL
value|0x00
end_define

begin_define
define|#
directive|define
name|JZ_SEND_CCSD
value|0x8000
end_define

begin_define
define|#
directive|define
name|JZ_SEND_AS_CCSD
value|0x4000
end_define

begin_define
define|#
directive|define
name|JZ_EXIT_MULTIPLE
value|0x0080
end_define

begin_define
define|#
directive|define
name|JZ_EXIT_TRANSFER
value|0x0040
end_define

begin_define
define|#
directive|define
name|JZ_START_READWAIT
value|0x0020
end_define

begin_define
define|#
directive|define
name|JZ_STOP_READWAIT
value|0x0010
end_define

begin_define
define|#
directive|define
name|JZ_RESET
value|0x0008
end_define

begin_define
define|#
directive|define
name|JZ_START_OP
value|0x0004
end_define

begin_define
define|#
directive|define
name|JZ_CLOCK_CTRL_M
value|0x0003
end_define

begin_define
define|#
directive|define
name|JZ_CLOCK_START
value|0x0002
end_define

begin_define
define|#
directive|define
name|JZ_CLOCK_STOP
value|0x0001
end_define

begin_define
define|#
directive|define
name|JZ_MSC_STAT
value|0x04
end_define

begin_define
define|#
directive|define
name|JZ_AUTO_CMD12_DONE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|JZ_AUTO_CMD23_DONE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|JZ_SVS
value|0x20000000
end_define

begin_define
define|#
directive|define
name|JZ_PIN_LEVEL_M
value|0x1f000000
end_define

begin_define
define|#
directive|define
name|JZ_BCE
value|0x00100000
end_define

begin_comment
comment|/* boot CRC error */
end_comment

begin_define
define|#
directive|define
name|JZ_BDE
value|0x00080000
end_define

begin_comment
comment|/* boot data end */
end_comment

begin_define
define|#
directive|define
name|JZ_BAE
value|0x00040000
end_define

begin_comment
comment|/* boot acknowledge error */
end_comment

begin_define
define|#
directive|define
name|JZ_BAR
value|0x00020000
end_define

begin_comment
comment|/* boot ack. received */
end_comment

begin_define
define|#
directive|define
name|JZ_DMAEND
value|0x00010000
end_define

begin_define
define|#
directive|define
name|JZ_IS_RESETTING
value|0x00008000
end_define

begin_define
define|#
directive|define
name|JZ_SDIO_INT_ACTIVE
value|0x00004000
end_define

begin_define
define|#
directive|define
name|JZ_PRG_DONE
value|0x00002000
end_define

begin_define
define|#
directive|define
name|JZ_DATA_TRAN_DONE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|JZ_END_CMD_RES
value|0x00000800
end_define

begin_define
define|#
directive|define
name|JZ_DATA_FIFO_AFULL
value|0x00000400
end_define

begin_define
define|#
directive|define
name|JZ_IS_READWAIT
value|0x00000200
end_define

begin_define
define|#
directive|define
name|JZ_CLK_EN
value|0x00000100
end_define

begin_define
define|#
directive|define
name|JZ_DATA_FIFO_FULL
value|0x00000080
end_define

begin_define
define|#
directive|define
name|JZ_DATA_FIFO_EMPTY
value|0x00000040
end_define

begin_define
define|#
directive|define
name|JZ_CRC_RES_ERR
value|0x00000020
end_define

begin_define
define|#
directive|define
name|JZ_CRC_READ_ERR
value|0x00000010
end_define

begin_define
define|#
directive|define
name|JZ_CRC_WRITE_ERR_M
value|0x0000000c
end_define

begin_define
define|#
directive|define
name|JZ_CRC_WRITE_OK
value|0x00000000
end_define

begin_define
define|#
directive|define
name|JZ_CRC_CARD_ERR
value|0x00000004
end_define

begin_define
define|#
directive|define
name|JZ_CRC_NO_STATUS
value|0x00000008
end_define

begin_define
define|#
directive|define
name|JZ_TIME_OUT_RES
value|0x00000002
end_define

begin_define
define|#
directive|define
name|JZ_TIME_OUT_READ
value|0x00000001
end_define

begin_define
define|#
directive|define
name|JZ_MSC_CLKRT
value|0x08
end_define

begin_define
define|#
directive|define
name|JZ_DEV_CLK
value|0x0
end_define

begin_define
define|#
directive|define
name|JZ_DEV_CLK_2
value|0x1
end_define

begin_comment
comment|/* DEV_CLK / 2 */
end_comment

begin_define
define|#
directive|define
name|JZ_DEV_CLK_4
value|0x2
end_define

begin_comment
comment|/* DEV_CLK / 4 */
end_comment

begin_define
define|#
directive|define
name|JZ_DEV_CLK_8
value|0x3
end_define

begin_comment
comment|/* DEV_CLK / 8 */
end_comment

begin_define
define|#
directive|define
name|JZ_DEV_CLK_16
value|0x4
end_define

begin_comment
comment|/* DEV_CLK / 16 */
end_comment

begin_define
define|#
directive|define
name|JZ_DEV_CLK_32
value|0x5
end_define

begin_comment
comment|/* DEV_CLK / 32 */
end_comment

begin_define
define|#
directive|define
name|JZ_DEV_CLK_64
value|0x6
end_define

begin_comment
comment|/* DEV_CLK / 64 */
end_comment

begin_define
define|#
directive|define
name|JZ_DEV_CLK_128
value|0x7
end_define

begin_comment
comment|/* DEV_CLK / 128 */
end_comment

begin_define
define|#
directive|define
name|JZ_MSC_CMDAT
value|0x0c
end_define

begin_define
define|#
directive|define
name|JZ_CCS_EXPECTED
value|0x80000000
end_define

begin_define
define|#
directive|define
name|JZ_READ_CEATA
value|0x40000000
end_define

begin_define
define|#
directive|define
name|JZ_DIS_BOOT
value|0x08000000
end_define

begin_define
define|#
directive|define
name|JZ_ENA_BOOT
value|0x04000000
end_define

begin_define
define|#
directive|define
name|JZ_EXP_BOOT_ACK
value|0x02000000
end_define

begin_define
define|#
directive|define
name|JZ_BOOT_MODE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|JZ_AUTO_CMD23
value|0x00040000
end_define

begin_define
define|#
directive|define
name|JZ_SDIO_PRDT
value|0x00020000
end_define

begin_define
define|#
directive|define
name|JZ_AUTO_CMD12
value|0x00010000
end_define

begin_define
define|#
directive|define
name|JZ_RTRG_M
value|0x0000c000
end_define

begin_comment
comment|/* receive FIFO trigger */
end_comment

begin_define
define|#
directive|define
name|JZ_RTRG_16
value|0x00000000
end_define

begin_comment
comment|/*>= 16 */
end_comment

begin_define
define|#
directive|define
name|JZ_RTRG_32
value|0x00004000
end_define

begin_comment
comment|/*>= 32 */
end_comment

begin_define
define|#
directive|define
name|JZ_RTRG_64
value|0x00008000
end_define

begin_comment
comment|/*>= 64 */
end_comment

begin_define
define|#
directive|define
name|JZ_RTRG_96
value|0x0000c000
end_define

begin_comment
comment|/*>= 96 */
end_comment

begin_define
define|#
directive|define
name|JZ_TTRG_M
value|0x00003000
end_define

begin_comment
comment|/* transmit FIFO trigger */
end_comment

begin_define
define|#
directive|define
name|JZ_TTRG_16
value|0x00000000
end_define

begin_comment
comment|/*>= 16 */
end_comment

begin_define
define|#
directive|define
name|JZ_TTRG_32
value|0x00001000
end_define

begin_comment
comment|/*>= 32 */
end_comment

begin_define
define|#
directive|define
name|JZ_TTRG_64
value|0x00002000
end_define

begin_comment
comment|/*>= 64 */
end_comment

begin_define
define|#
directive|define
name|JZ_TTRG_96
value|0x00003000
end_define

begin_comment
comment|/*>= 96 */
end_comment

begin_define
define|#
directive|define
name|JZ_IO_ABORT
value|0x00000800
end_define

begin_define
define|#
directive|define
name|JZ_BUS_WIDTH_M
value|0x00000600
end_define

begin_define
define|#
directive|define
name|JZ_BUS_1BIT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|JZ_BUS_4BIT
value|0x00000400
end_define

begin_define
define|#
directive|define
name|JZ_BUS_8BIT
value|0x00000600
end_define

begin_define
define|#
directive|define
name|JZ_INIT
value|0x00000080
end_define

begin_comment
comment|/* send 80 clk init before cmd */
end_comment

begin_define
define|#
directive|define
name|JZ_BUSY
value|0x00000040
end_define

begin_define
define|#
directive|define
name|JZ_STREAM
value|0x00000020
end_define

begin_define
define|#
directive|define
name|JZ_WRITE
value|0x00000010
end_define

begin_comment
comment|/* read otherwise */
end_comment

begin_define
define|#
directive|define
name|JZ_DATA_EN
value|0x00000008
end_define

begin_define
define|#
directive|define
name|JZ_RESPONSE_M
value|0x00000007
end_define

begin_comment
comment|/* response format */
end_comment

begin_define
define|#
directive|define
name|JZ_RES_NONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|JZ_RES_R1
value|0x00000001
end_define

begin_comment
comment|/* R1 and R1b */
end_comment

begin_define
define|#
directive|define
name|JZ_RES_R2
value|0x00000002
end_define

begin_define
define|#
directive|define
name|JZ_RES_R3
value|0x00000003
end_define

begin_define
define|#
directive|define
name|JZ_RES_R4
value|0x00000004
end_define

begin_define
define|#
directive|define
name|JZ_RES_R5
value|0x00000005
end_define

begin_define
define|#
directive|define
name|JZ_RES_R6
value|0x00000006
end_define

begin_define
define|#
directive|define
name|JZ_RES_R7
value|0x00000007
end_define

begin_define
define|#
directive|define
name|JZ_MSC_RESTO
value|0x10
end_define

begin_comment
comment|/* 16bit response timeout in MSC_CLK */
end_comment

begin_define
define|#
directive|define
name|JZ_MSC_RDTO
value|0x14
end_define

begin_comment
comment|/* 32bit read timeout in MSC_CLK */
end_comment

begin_define
define|#
directive|define
name|JZ_MSC_BLKLEN
value|0x18
end_define

begin_comment
comment|/* 16bit block length */
end_comment

begin_define
define|#
directive|define
name|JZ_MSC_NOB
value|0x1c
end_define

begin_comment
comment|/* 16bit block counter */
end_comment

begin_define
define|#
directive|define
name|JZ_MSC_SNOB
value|0x20
end_define

begin_comment
comment|/* 16bit successful block counter */
end_comment

begin_define
define|#
directive|define
name|JZ_MSC_IMASK
value|0x24
end_define

begin_comment
comment|/* interrupt mask */
end_comment

begin_define
define|#
directive|define
name|JZ_INT_AUTO_CMD23_DONE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|JZ_INT_SVS
value|0x20000000
end_define

begin_define
define|#
directive|define
name|JZ_INT_PIN_LEVEL_M
value|0x1f000000
end_define

begin_define
define|#
directive|define
name|JZ_INT_BCE
value|0x00100000
end_define

begin_define
define|#
directive|define
name|JZ_INT_BDE
value|0x00080000
end_define

begin_define
define|#
directive|define
name|JZ_INT_BAE
value|0x00040000
end_define

begin_define
define|#
directive|define
name|JZ_INT_BAR
value|0x00020000
end_define

begin_define
define|#
directive|define
name|JZ_INT_DMAEND
value|0x00010000
end_define

begin_define
define|#
directive|define
name|JZ_INT_AUTO_CMD12_DONE
value|0x00008000
end_define

begin_define
define|#
directive|define
name|JZ_INT_DATA_FIFO_FULL
value|0x00004000
end_define

begin_define
define|#
directive|define
name|JZ_INT_DATA_FIFO_EMPTY
value|0x00002000
end_define

begin_define
define|#
directive|define
name|JZ_INT_CRC_RES_ERR
value|0x00001000
end_define

begin_define
define|#
directive|define
name|JZ_INT_CRC_READ_ERR
value|0x00000800
end_define

begin_define
define|#
directive|define
name|JZ_INT_CRC_WRITE_ERR
value|0x00000400
end_define

begin_define
define|#
directive|define
name|JZ_INT_TIMEOUT_RES
value|0x00000200
end_define

begin_define
define|#
directive|define
name|JZ_INT_TIMEOUT_READ
value|0x00000100
end_define

begin_define
define|#
directive|define
name|JZ_INT_SDIO
value|0x00000080
end_define

begin_define
define|#
directive|define
name|JZ_INT_TXFIFO_WR_REQ
value|0x00000040
end_define

begin_define
define|#
directive|define
name|JZ_INT_RXFIFO_RD_REQ
value|0x00000020
end_define

begin_define
define|#
directive|define
name|JZ_INT_END_CMD_RES
value|0x00000004
end_define

begin_define
define|#
directive|define
name|JZ_INT_PRG_DONE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|JZ_INT_DATA_TRAN_DONE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|JZ_MSC_IFLG
value|0x28
end_define

begin_comment
comment|/* interrupt flags */
end_comment

begin_define
define|#
directive|define
name|JZ_MSC_CMD
value|0x2c
end_define

begin_comment
comment|/* 6bit CMD index */
end_comment

begin_define
define|#
directive|define
name|JZ_MSC_ARG
value|0x30
end_define

begin_comment
comment|/* 32bit argument */
end_comment

begin_define
define|#
directive|define
name|JZ_MSC_RES
value|0x34
end_define

begin_comment
comment|/* 8x16bit response data FIFO */
end_comment

begin_define
define|#
directive|define
name|JZ_MSC_RXFIFO
value|0x38
end_define

begin_define
define|#
directive|define
name|JZ_MSC_TXFIFO
value|0x3c
end_define

begin_define
define|#
directive|define
name|JZ_MSC_LPM
value|0x40
end_define

begin_define
define|#
directive|define
name|JZ_DRV_SEL_M
value|0xc0000000
end_define

begin_define
define|#
directive|define
name|JZ_FALLING_EDGE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|JZ_RISING_1NS
value|0x40000000
end_define

begin_comment
comment|/* 1ns delay */
end_comment

begin_define
define|#
directive|define
name|JZ_RISING_4
value|0x80000000
end_define

begin_comment
comment|/* 1/4 MSC_CLK delay */
end_comment

begin_define
define|#
directive|define
name|JZ_SMP_SEL
value|0x20000000
end_define

begin_comment
comment|/* 1 - rising edge */
end_comment

begin_define
define|#
directive|define
name|JZ_LPM
value|0x00000001
end_define

begin_comment
comment|/* low power mode */
end_comment

begin_define
define|#
directive|define
name|JZ_MSC_DMAC
value|0x44
end_define

begin_define
define|#
directive|define
name|JZ_MODE_SEL
value|0x80
end_define

begin_comment
comment|/* 1 - specify transfer length */
end_comment

begin_define
define|#
directive|define
name|JZ_AOFST_M
value|0x60
end_define

begin_comment
comment|/* address offset in bytes */
end_comment

begin_define
define|#
directive|define
name|JZ_AOFST_S
value|6
end_define

begin_comment
comment|/* addrress offset shift */
end_comment

begin_define
define|#
directive|define
name|JZ_ALIGNEN
value|0x10
end_define

begin_comment
comment|/* allow non-32bit-aligned transfers */
end_comment

begin_define
define|#
directive|define
name|JZ_INCR_M
value|0x0c
end_define

begin_comment
comment|/* burst type */
end_comment

begin_define
define|#
directive|define
name|JZ_INCR_16
value|0x00
end_define

begin_define
define|#
directive|define
name|JZ_INCR_32
value|0x04
end_define

begin_define
define|#
directive|define
name|JZ_INCR_64
value|0x08
end_define

begin_define
define|#
directive|define
name|JZ_DMASEL
value|0x02
end_define

begin_comment
comment|/* 1 - SoC DMAC, 0 - MSC built-in */
end_comment

begin_define
define|#
directive|define
name|JZ_DMAEN
value|0x01
end_define

begin_comment
comment|/* enable DMA */
end_comment

begin_define
define|#
directive|define
name|JZ_MSC_DMANDA
value|0x48
end_define

begin_comment
comment|/* next descriptor paddr */
end_comment

begin_define
define|#
directive|define
name|JZ_MSC_DMADA
value|0x4c
end_define

begin_comment
comment|/* current descriptor */
end_comment

begin_define
define|#
directive|define
name|JZ_MSC_DMALEN
value|0x50
end_define

begin_comment
comment|/* transfer tength */
end_comment

begin_define
define|#
directive|define
name|JZ_MSC_DMACMD
value|0x54
end_define

begin_define
define|#
directive|define
name|JZ_DMA_IDI_M
value|0xff000000
end_define

begin_define
define|#
directive|define
name|JZ_DMA_ID_M
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|JZ_DMA_AOFST_M
value|0x00000600
end_define

begin_define
define|#
directive|define
name|JZ_DMA_ALIGN
value|0x00000100
end_define

begin_define
define|#
directive|define
name|JZ_DMA_ENDI
value|0x00000002
end_define

begin_define
define|#
directive|define
name|JZ_DMA_LINK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|JZ_MSC_CTRL2
value|0x58
end_define

begin_define
define|#
directive|define
name|JZ_PIP
value|0x1f000000
end_define

begin_comment
comment|/* 1 - intr trigger on high */
end_comment

begin_define
define|#
directive|define
name|JZ_RST_EN
value|0x00800000
end_define

begin_define
define|#
directive|define
name|JZ_STPRM
value|0x00000010
end_define

begin_define
define|#
directive|define
name|JZ_SVC
value|0x00000008
end_define

begin_define
define|#
directive|define
name|JZ_SMS_M
value|0x00000007
end_define

begin_define
define|#
directive|define
name|JZ_SMS_DEF
value|0x00000000
end_define

begin_comment
comment|/* default speed */
end_comment

begin_define
define|#
directive|define
name|JZ_SMS_HIGH
value|0x00000001
end_define

begin_comment
comment|/* high speed */
end_comment

begin_define
define|#
directive|define
name|JZ_SMS_SDR12
value|0x00000002
end_define

begin_define
define|#
directive|define
name|JZ_SMS_SDR25
value|0x00000003
end_define

begin_define
define|#
directive|define
name|JZ_SMS_SDR50
value|0x00000004
end_define

begin_define
define|#
directive|define
name|JZ_MSC_RTCNT
value|0x5c
end_define

begin_comment
comment|/* RT FIFO count */
end_comment

begin_comment
comment|/* EFUSE Slave Interface */
end_comment

begin_define
define|#
directive|define
name|JZ_EFUSE
value|0x134100D0
end_define

begin_define
define|#
directive|define
name|JZ_EFUCTRL
value|0x00
end_define

begin_define
define|#
directive|define
name|JZ_EFUSE_BANK
value|0x40000000
end_define

begin_comment
comment|/* select upper 4KBit */
end_comment

begin_define
define|#
directive|define
name|JZ_EFUSE_ADDR_M
value|0x3fe00000
end_define

begin_comment
comment|/* in bytes */
end_comment

begin_define
define|#
directive|define
name|JZ_EFUSE_ADDR_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|JZ_EFUSE_SIZE_M
value|0x001f0000
end_define

begin_comment
comment|/* in bytes */
end_comment

begin_define
define|#
directive|define
name|JZ_EFUSE_SIZE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|JZ_EFUSE_PROG
value|0x00008000
end_define

begin_comment
comment|/* enable programming */
end_comment

begin_define
define|#
directive|define
name|JZ_EFUSE_WRITE
value|0x00000002
end_define

begin_comment
comment|/* write enable */
end_comment

begin_define
define|#
directive|define
name|JZ_EFUSE_READ
value|0x00000001
end_define

begin_comment
comment|/* read enable */
end_comment

begin_define
define|#
directive|define
name|JZ_EFUCFG
value|0x04
end_define

begin_define
define|#
directive|define
name|JZ_EFUSE_INT_E
value|0x80000000
end_define

begin_comment
comment|/* which IRQ? */
end_comment

begin_define
define|#
directive|define
name|JZ_EFUSE_RD_ADJ_M
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|JZ_EFUSE_RD_STROBE
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|JZ_EFUSE_WR_ADJUST
value|0x0000f000
end_define

begin_define
define|#
directive|define
name|JZ_EFUSE_WR_STROBE
value|0x00000fff
end_define

begin_define
define|#
directive|define
name|JZ_EFUSTATE
value|0x08
end_define

begin_define
define|#
directive|define
name|JZ_EFUSE_GLOBAL_P
value|0x00008000
end_define

begin_comment
comment|/* wr protect bits */
end_comment

begin_define
define|#
directive|define
name|JZ_EFUSE_CHIPID_P
value|0x00004000
end_define

begin_define
define|#
directive|define
name|JZ_EFUSE_CUSTID_P
value|0x00002000
end_define

begin_define
define|#
directive|define
name|JZ_EFUSE_SECWR_EN
value|0x00001000
end_define

begin_define
define|#
directive|define
name|JZ_EFUSE_PC_P
value|0x00000800
end_define

begin_define
define|#
directive|define
name|JZ_EFUSE_HDMIKEY_P
value|0x00000400
end_define

begin_define
define|#
directive|define
name|JZ_EFUSE_SECKEY_P
value|0x00000200
end_define

begin_define
define|#
directive|define
name|JZ_EFUSE_SECBOOT_EN
value|0x00000100
end_define

begin_define
define|#
directive|define
name|JZ_EFUSE_HDMI_BUSY
value|0x00000004
end_define

begin_define
define|#
directive|define
name|JZ_EFUSE_WR_DONE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|JZ_EFUSE_RD_DONE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|JZ_EFUDATA0
value|0x0C
end_define

begin_define
define|#
directive|define
name|JZ_EFUDATA1
value|0x10
end_define

begin_define
define|#
directive|define
name|JZ_EFUDATA2
value|0x14
end_define

begin_define
define|#
directive|define
name|JZ_EFUDATA3
value|0x18
end_define

begin_define
define|#
directive|define
name|JZ_EFUDATA4
value|0x1C
end_define

begin_define
define|#
directive|define
name|JZ_EFUDATA5
value|0x20
end_define

begin_define
define|#
directive|define
name|JZ_EFUDATA6
value|0x24
end_define

begin_define
define|#
directive|define
name|JZ_EFUDATA7
value|0x28
end_define

begin_comment
comment|/* NEMC */
end_comment

begin_define
define|#
directive|define
name|JZ_NEMC_BASE
value|0x13410000
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SMCR
parameter_list|(
name|n
parameter_list|)
value|(0x10 + (n) * 4)
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SMCR_SMT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SMCR_SMT_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SMCR_SMT_MASK
value|(((1<< JZ_NEMC_SMCR_SMT_WIDTH) - 1)<< JZ_NEMC_SMCR_SMT_SHIFT)
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SMCR_SMT_NORMAL
value|(0<< JZ_NEMC_SMCR_SMT_SHIFT)
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SMCR_SMT_BROM
value|(1<< JZ_NEMC_SMCR_SMT_SHIFT)
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SMCR_BL_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SMCR_BL_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SMCR_BL_MASK
value|(((1<< JZ_NEMC_SMCR_BL_WIDTH) - 1)<< JZ_NEMC_SMCR_BL_SHIFT)
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SMCR_BL
parameter_list|(
name|n
parameter_list|)
value|(((n)<< JZ_NEMC_SMCR_BL_SHIFT)
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SMCR_BW_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SMCR_BW_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SMCR_BW_MASK
value|(((1<< JZ_NEMC_SMCR_BW_WIDTH) - 1)<< JZ_NEMC_SMCR_BW_SHIFT)
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SMCR_BW_8
value|(0<< JZ_NEMC_SMCR_BW_SHIFT)
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SMCR_TAS_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SMCR_TAS_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SMCR_TAS_MASK
value|(((1<< JZ_NEMC_SMCR_TAS_WIDTH) - 1)<< JZ_NEMC_SMCR_TAS_SHIFT)
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SMCR_TAH_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SMCR_TAH_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SMCR_TAH_MASK
value|(((1<< JZ_NEMC_SMCR_TAH_WIDTH) - 1)<< JZ_NEMC_SMCR_TAH_SHIFT)
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SMCR_TBP_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SMCR_TBP_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SMCR_TBP_MASK
value|(((1<< JZ_NEMC_SMCR_TBP_WIDTH) - 1)<< JZ_NEMC_SMCR_TBP_SHIFT)
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SMCR_TAW_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SMCR_TAW_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SMCR_TAW_MASK
value|(((1<< JZ_NEMC_SMCR_TAW_WIDTH) - 1)<< JZ_NEMC_SMCR_TAW_SHIFT)
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SMCR_STRV_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SMCR_STRV_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SMCR_STRV_MASK
value|(((1<< JZ_NEMC_SMCR_STRV_WIDTH) - 1)<< JZ_NEMC_SMCR_STRV_SHIFT)
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SACR
parameter_list|(
name|n
parameter_list|)
value|(0x30 + (n) * 4)
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SACR_MASK_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SACR_MASK_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SACR_MASK_MASK
value|(((1<< JZ_NEMC_SACR_MASK_WIDTH) - 1)<< JZ_NEMC_SACR_MASK_SHIFT)
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SACR_ADDR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SACR_ADDR_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|JZ_NEMC_SACR_ADDR_MASK
value|(((1<< JZ_NEMC_SACR_ADDR_WIDTH) - 1)<< JZ_NEMC_SACR_ADDR_SHIFT)
end_define

begin_define
define|#
directive|define
name|JC_NEMC_NFSCR
value|0x50
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JZ4780_REGS_H */
end_comment

end_unit

