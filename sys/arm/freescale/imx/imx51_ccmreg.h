begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: imx51_ccmreg.h,v 1.1 2012/04/17 09:33:31 bsh Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2011, 2012  Genetec Corporation.  All rights reserved.  * Written by Hashimoto Kenichi for Genetec Corporation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY GENETEC CORPORATION ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL GENETEC CORPORATION  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2012, 2013 The FreeBSD Foundation  * All rights reserved.  *  * Portions of this software were developed by Oleksandr Rybalko  * under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1.	Redistributions of source code must retain the above copyright  *	notice, this list of conditions and the following disclaimer.  * 2.	Redistributions in binary form must reproduce the above copyright  *	notice, this list of conditions and the following disclaimer in the  *	documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IMX51_CCMREG_H
end_ifndef

begin_define
define|#
directive|define
name|_IMX51_CCMREG_H
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/* register offset address */
end_comment

begin_define
define|#
directive|define
name|CCMC_BASE
value|0x73fd4000
end_define

begin_define
define|#
directive|define
name|CCMC_CCR
value|0x0000
end_define

begin_define
define|#
directive|define
name|CCR_FPM_MULT
value|0x00001000
end_define

begin_define
define|#
directive|define
name|CCMC_CCDR
value|0x0004
end_define

begin_define
define|#
directive|define
name|CCMC_CSR
value|0x0008
end_define

begin_define
define|#
directive|define
name|CCMC_CCSR
value|0x000c
end_define

begin_define
define|#
directive|define
name|CCSR_LP_APM
value|0x00000200
end_define

begin_define
define|#
directive|define
name|CCSR_STEP_SEL_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|CCSR_STEP_SEL_MASK
value|0x00000180
end_define

begin_define
define|#
directive|define
name|CCSR_PLL2_DIV_PODF_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|CCSR_PLL2_DIV_PODF_MASK
value|0x00000060
end_define

begin_define
define|#
directive|define
name|CCSR_PLL3_DIV_PODF_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|CCSR_PLL3_DIV_PODF_MASK
value|0x00000030
end_define

begin_define
define|#
directive|define
name|CCSR_PLL1_SW_CLK_SEL
value|0x00000004
end_define

begin_define
define|#
directive|define
name|CCSR_PLL2_SW_CLK_SEL
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CCSR_PLL3_SW_CLK_SEL
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CCMC_CACRR
value|0x0010
end_define

begin_define
define|#
directive|define
name|CCMC_CBCDR
value|0x0014
end_define

begin_define
define|#
directive|define
name|CBCDR_DDR_HIGH_FREQ_CLK_SEL
value|0x40000000
end_define

begin_define
define|#
directive|define
name|CBCDR_DDR_CLK_PODF_SHIFT
value|27
end_define

begin_define
define|#
directive|define
name|CBCDR_DDR_CLK_PODF_MASK
value|0x38000000
end_define

begin_define
define|#
directive|define
name|CBCDR_EMI_CLK_SEL
value|0x04000000
end_define

begin_define
define|#
directive|define
name|CBCDR_PERIPH_CLK_SEL
value|0x02000000
end_define

begin_define
define|#
directive|define
name|CBCDR_EMI_SLOW_PODF_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|CBCDR_EMI_SLOW_PODF_MASK
value|0x01c00000
end_define

begin_define
define|#
directive|define
name|CBCDR_AXI_B_PODF_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|CBCDR_AXI_B_PODF_MASK
value|0x00380000
end_define

begin_define
define|#
directive|define
name|CBCDR_AXI_A_PODF_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|CBCDR_AXI_A_PODF_MASK
value|0x1fff0000
end_define

begin_define
define|#
directive|define
name|CBCDR_NFC_PODF_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|CBCDR_NFC_PODF_MASK
value|0x00018000
end_define

begin_define
define|#
directive|define
name|CBCDR_AHB_PODF_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|CBCDR_AHB_PODF_MASK
value|0x00001c00
end_define

begin_define
define|#
directive|define
name|CBCDR_IPG_PODF_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|CBCDR_IPG_PODF_MASK
value|0x00000300
end_define

begin_define
define|#
directive|define
name|CBCDR_PERCLK_PRED1_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|CBCDR_PERCLK_PRED1_MASK
value|0x000000c0
end_define

begin_define
define|#
directive|define
name|CBCDR_PERCLK_PRED2_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|CBCDR_PERCLK_PRED2_MASK
value|0x00000038
end_define

begin_define
define|#
directive|define
name|CBCDR_PERCLK_PODF_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|CBCDR_PERCLK_PODF_MASK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|CCMC_CBCMR
value|0x0018
end_define

begin_define
define|#
directive|define
name|CBCMR_PERIPH_APM_SEL_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|CBCMR_PERIPH_APM_SEL_MASK
value|0x00003000
end_define

begin_define
define|#
directive|define
name|CBCMR_IPU_HSP_CLK_SEL_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|CBCMR_IPU_HSP_CLK_SEL_MASK
value|0x000000c0
end_define

begin_define
define|#
directive|define
name|CBCMR_PERCLK_LP_APM_SEL
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CBCMR_PERCLK_IPG_SEL
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CCMC_CSCMR1
value|0x001c
end_define

begin_define
define|#
directive|define
name|CSCMR1_UART_CLK_SEL_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|CSCMR1_UART_CLK_SEL_MASK
value|0x03000000
end_define

begin_define
define|#
directive|define
name|CSCMR1_USBPHY_CLK_SEL_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|CSCMR1_USBPHY_CLK_SEL_MASK
value|0x04000000
end_define

begin_define
define|#
directive|define
name|CSCMR1_USBOH3_CLK_SEL_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|CSCMR1_USBOH3_CLK_SEL_MASK
value|0x00c00000
end_define

begin_define
define|#
directive|define
name|CCMC_CSCMR2
value|0x0020
end_define

begin_define
define|#
directive|define
name|CCMC_CSCDR1
value|0x0024
end_define

begin_define
define|#
directive|define
name|CSCDR1_UART_CLK_PRED_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|CSCDR1_UART_CLK_PRED_MASK
value|0x00000038
end_define

begin_define
define|#
directive|define
name|CSCDR1_UART_CLK_PODF_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|CSCDR1_UART_CLK_PODF_MASK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|CSCDR1_USBOH3_CLK_PRED_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|CSCDR1_USBOH3_CLK_PRED_MASK
value|0x00000700
end_define

begin_define
define|#
directive|define
name|CSCDR1_USBOH3_CLK_PODF_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|CSCDR1_USBOH3_CLK_PODF_MASK
value|0x000000c0
end_define

begin_define
define|#
directive|define
name|CCMC_CS1CDR
value|0x0028
end_define

begin_define
define|#
directive|define
name|CCMC_CS2CDR
value|0x002c
end_define

begin_define
define|#
directive|define
name|CCMC_CDCDR
value|0x0030
end_define

begin_define
define|#
directive|define
name|CCMC_CSCDR2
value|0x0038
end_define

begin_define
define|#
directive|define
name|CCMC_CSCDR3
value|0x003c
end_define

begin_define
define|#
directive|define
name|CCMC_CSCDR4
value|0x0040
end_define

begin_define
define|#
directive|define
name|CCMC_CWDR
value|0x0044
end_define

begin_define
define|#
directive|define
name|CCMC_CDHIPR
value|0x0048
end_define

begin_define
define|#
directive|define
name|CCMC_CDCR
value|0x004c
end_define

begin_define
define|#
directive|define
name|CDCR_PERIPH_CLK_DVFS_PODF_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|CDCR_PERIPH_CLK_DVFS_PODF_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|CCMC_CTOR
value|0x0050
end_define

begin_define
define|#
directive|define
name|CCMC_CLPCR
value|0x0054
end_define

begin_define
define|#
directive|define
name|CCMC_CISR
value|0x0058
end_define

begin_define
define|#
directive|define
name|CCMC_CIMR
value|0x005c
end_define

begin_define
define|#
directive|define
name|CCMC_CCOSR
value|0x0060
end_define

begin_define
define|#
directive|define
name|CCMC_CGPR
value|0x0064
end_define

begin_define
define|#
directive|define
name|CCMC_CCGR
parameter_list|(
name|n
parameter_list|)
value|(0x0068 + (n) * 4)
end_define

begin_define
define|#
directive|define
name|CCMC_CMEOR
value|0x0084
end_define

begin_define
define|#
directive|define
name|CCMC_SIZE
value|0x88
end_define

begin_comment
comment|/* CCGR Clock Gate Register */
end_comment

begin_define
define|#
directive|define
name|CCMR_CCGR_NSOURCE
value|16
end_define

begin_define
define|#
directive|define
name|CCMR_CCGR_NGROUPS
value|7
end_define

begin_define
define|#
directive|define
name|CCMR_CCGR_MODULE
parameter_list|(
name|clk
parameter_list|)
value|((clk) / CCMR_CCGR_NSOURCE)
end_define

begin_define
define|#
directive|define
name|__CCGR_NUM
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a) * 16 + (b))
end_define

begin_define
define|#
directive|define
name|CCGR_ARM_BUS_CLK
value|__CCGR_NUM(0, 0)
end_define

begin_define
define|#
directive|define
name|CCGR_ARM_AXI_CLK
value|__CCGR_NUM(0, 1)
end_define

begin_define
define|#
directive|define
name|CCGR_ARM_DEBUG_CLK
value|__CCGR_NUM(0, 2)
end_define

begin_define
define|#
directive|define
name|CCGR_TZIC_CLK
value|__CCGR_NUM(0, 3)
end_define

begin_define
define|#
directive|define
name|CCGR_DAP_CLK
value|__CCGR_NUM(0, 4)
end_define

begin_define
define|#
directive|define
name|CCGR_TPIU_CLK
value|__CCGR_NUM(0, 5)
end_define

begin_define
define|#
directive|define
name|CCGR_CTI2_CLK
value|__CCGR_NUM(0, 6)
end_define

begin_define
define|#
directive|define
name|CCGR_CTI3_CLK
value|__CCGR_NUM(0, 7)
end_define

begin_define
define|#
directive|define
name|CCGR_AHBMUX1_CLK
value|__CCGR_NUM(0, 8)
end_define

begin_define
define|#
directive|define
name|CCGR_AHBMUX2_CLK
value|__CCGR_NUM(0, 9)
end_define

begin_define
define|#
directive|define
name|CCGR_ROMCP_CLK
value|__CCGR_NUM(0, 10)
end_define

begin_define
define|#
directive|define
name|CCGR_ROM_CLK
value|__CCGR_NUM(0, 11)
end_define

begin_define
define|#
directive|define
name|CCGR_AIPS_TZ1_CLK
value|__CCGR_NUM(0, 12)
end_define

begin_define
define|#
directive|define
name|CCGR_AIPS_TZ2_CLK
value|__CCGR_NUM(0, 13)
end_define

begin_define
define|#
directive|define
name|CCGR_AHB_MAX_CLK
value|__CCGR_NUM(0, 14)
end_define

begin_define
define|#
directive|define
name|CCGR_IIM_CLK
value|__CCGR_NUM(0, 15)
end_define

begin_define
define|#
directive|define
name|CCGR_TMAX1_CLK
value|__CCGR_NUM(1, 0)
end_define

begin_define
define|#
directive|define
name|CCGR_TMAX2_CLK
value|__CCGR_NUM(1, 1)
end_define

begin_define
define|#
directive|define
name|CCGR_TMAX3_CLK
value|__CCGR_NUM(1, 2)
end_define

begin_define
define|#
directive|define
name|CCGR_UART1_CLK
value|__CCGR_NUM(1, 3)
end_define

begin_define
define|#
directive|define
name|CCGR_UART1_SERIAL_CLK
value|__CCGR_NUM(1, 4)
end_define

begin_define
define|#
directive|define
name|CCGR_UART2_CLK
value|__CCGR_NUM(1, 5)
end_define

begin_define
define|#
directive|define
name|CCGR_UART2_SERIAL_CLK
value|__CCGR_NUM(1, 6)
end_define

begin_define
define|#
directive|define
name|CCGR_UART3_CLK
value|__CCGR_NUM(1, 7)
end_define

begin_define
define|#
directive|define
name|CCGR_UART3_SERIAL_CLK
value|__CCGR_NUM(1, 8)
end_define

begin_define
define|#
directive|define
name|CCGR_I2C1_SERIAL_CLK
value|__CCGR_NUM(1, 9)
end_define

begin_define
define|#
directive|define
name|CCGR_I2C2_SERIAL_CLK
value|__CCGR_NUM(1, 10)
end_define

begin_define
define|#
directive|define
name|CCGR_HSI2C_CLK
value|__CCGR_NUM(1, 11)
end_define

begin_define
define|#
directive|define
name|CCGR_HSI2C_SERIAL_CLK
value|__CCGR_NUM(1, 12)
end_define

begin_define
define|#
directive|define
name|CCGR_FIRI_CLK
value|__CCGR_NUM(1, 13)
end_define

begin_define
define|#
directive|define
name|CCGR_FIRI_SERIAL_CLK
value|__CCGR_NUM(1, 14)
end_define

begin_define
define|#
directive|define
name|CCGR_SCC_CLK
value|__CCGR_NUM(1, 15)
end_define

begin_define
define|#
directive|define
name|CCGR_USB_PHY_CLK
value|__CCGR_NUM(2, 0)
end_define

begin_define
define|#
directive|define
name|CCGR_EPIT1_CLK
value|__CCGR_NUM(2, 1)
end_define

begin_define
define|#
directive|define
name|CCGR_EPIT1_SERIAL_CLK
value|__CCGR_NUM(2, 2)
end_define

begin_define
define|#
directive|define
name|CCGR_EPIT2_CLK
value|__CCGR_NUM(2, 3)
end_define

begin_define
define|#
directive|define
name|CCGR_EPIT2_SERIAL_CLK
value|__CCGR_NUM(2, 4)
end_define

begin_define
define|#
directive|define
name|CCGR_PWM1_CLK
value|__CCGR_NUM(2, 5)
end_define

begin_define
define|#
directive|define
name|CCGR_PWM1_SERIAL_CLK
value|__CCGR_NUM(2, 6)
end_define

begin_define
define|#
directive|define
name|CCGR_PWM2_CLK
value|__CCGR_NUM(2, 7)
end_define

begin_define
define|#
directive|define
name|CCGR_PWM2_SERIAL_CLK
value|__CCGR_NUM(2, 8)
end_define

begin_define
define|#
directive|define
name|CCGR_GPT_CLK
value|__CCGR_NUM(2, 9)
end_define

begin_define
define|#
directive|define
name|CCGR_GPT_SERIAL_CLK
value|__CCGR_NUM(2, 10)
end_define

begin_define
define|#
directive|define
name|CCGR_OWIRE_CLK
value|__CCGR_NUM(2, 11)
end_define

begin_define
define|#
directive|define
name|CCGR_FEC_CLK
value|__CCGR_NUM(2, 12)
end_define

begin_define
define|#
directive|define
name|CCGR_USBOH3_IPG_AHB_CLK
value|__CCGR_NUM(2, 13)
end_define

begin_define
define|#
directive|define
name|CCGR_USBOH3_60M_CLK
value|__CCGR_NUM(2, 14)
end_define

begin_define
define|#
directive|define
name|CCGR_TVE_CLK
value|__CCGR_NUM(2, 15)
end_define

begin_define
define|#
directive|define
name|CCGR_ESDHC1_CLK
value|__CCGR_NUM(3, 0)
end_define

begin_define
define|#
directive|define
name|CCGR_ESDHC1_SERIAL_CLK
value|__CCGR_NUM(3, 1)
end_define

begin_define
define|#
directive|define
name|CCGR_ESDHC2_CLK
value|__CCGR_NUM(3, 2)
end_define

begin_define
define|#
directive|define
name|CCGR_ESDHC2_SERIAL_CLK
value|__CCGR_NUM(3, 3)
end_define

begin_define
define|#
directive|define
name|CCGR_ESDHC3_CLK
value|__CCGR_NUM(3, 4)
end_define

begin_define
define|#
directive|define
name|CCGR_ESDHC3_SERIAL_CLK
value|__CCGR_NUM(3, 5)
end_define

begin_define
define|#
directive|define
name|CCGR_ESDHC4_CLK
value|__CCGR_NUM(3, 6)
end_define

begin_define
define|#
directive|define
name|CCGR_ESDHC4_SERIAL_CLK
value|__CCGR_NUM(3, 7)
end_define

begin_define
define|#
directive|define
name|CCGR_SSI1_CLK
value|__CCGR_NUM(3, 8)
end_define

begin_define
define|#
directive|define
name|CCGR_SSI1_SERIAL_CLK
value|__CCGR_NUM(3, 9)
end_define

begin_define
define|#
directive|define
name|CCGR_SSI2_CLK
value|__CCGR_NUM(3, 10)
end_define

begin_define
define|#
directive|define
name|CCGR_SSI2_SERIAL_CLK
value|__CCGR_NUM(3, 11)
end_define

begin_define
define|#
directive|define
name|CCGR_SSI3_CLK
value|__CCGR_NUM(3, 12)
end_define

begin_define
define|#
directive|define
name|CCGR_SSI3_SERIAL_CLK
value|__CCGR_NUM(3, 13)
end_define

begin_define
define|#
directive|define
name|CCGR_SSI_EXT1_CLK
value|__CCGR_NUM(3, 14)
end_define

begin_define
define|#
directive|define
name|CCGR_SSI_EXT2_CLK
value|__CCGR_NUM(3, 15)
end_define

begin_define
define|#
directive|define
name|CCGR_PATA_CLK
value|__CCGR_NUM(4, 0)
end_define

begin_define
define|#
directive|define
name|CCGR_SIM_CLK
value|__CCGR_NUM(4, 1)
end_define

begin_define
define|#
directive|define
name|CCGR_SIM_SERIAL_CLK
value|__CCGR_NUM(4, 2)
end_define

begin_define
define|#
directive|define
name|CCGR_SAHARA_CLK
value|__CCGR_NUM(4, 3)
end_define

begin_define
define|#
directive|define
name|CCGR_RTIC_CLK
value|__CCGR_NUM(4, 4)
end_define

begin_define
define|#
directive|define
name|CCGR_ECSPI1_CLK
value|__CCGR_NUM(4, 5)
end_define

begin_define
define|#
directive|define
name|CCGR_ECSPI1_SERIAL_CLK
value|__CCGR_NUM(4, 6)
end_define

begin_define
define|#
directive|define
name|CCGR_ECSPI2_CLK
value|__CCGR_NUM(4, 7)
end_define

begin_define
define|#
directive|define
name|CCGR_ECSPI2_SERIAL_CLK
value|__CCGR_NUM(4, 8)
end_define

begin_define
define|#
directive|define
name|CCGR_CSPI_CLK
value|__CCGR_NUM(4, 9)
end_define

begin_define
define|#
directive|define
name|CCGR_SRTC_CLK
value|__CCGR_NUM(4, 10)
end_define

begin_define
define|#
directive|define
name|CCGR_SDMA_CLK
value|__CCGR_NUM(4, 11)
end_define

begin_define
define|#
directive|define
name|CCGR_SPBA_CLK
value|__CCGR_NUM(5, 0)
end_define

begin_define
define|#
directive|define
name|CCGR_GPU_CLK
value|__CCGR_NUM(5, 1)
end_define

begin_define
define|#
directive|define
name|CCGR_GARB_CLK
value|__CCGR_NUM(5, 2)
end_define

begin_define
define|#
directive|define
name|CCGR_VPU_CLK
value|__CCGR_NUM(5, 3)
end_define

begin_define
define|#
directive|define
name|CCGR_VPU_SERIAL_CLK
value|__CCGR_NUM(5, 4)
end_define

begin_define
define|#
directive|define
name|CCGR_IPU_CLK
value|__CCGR_NUM(5, 5)
end_define

begin_define
define|#
directive|define
name|CCGR_EMI_GARB_CLK
value|__CCGR_NUM(6, 0)
end_define

begin_define
define|#
directive|define
name|CCGR_IPU_DI0_CLK
value|__CCGR_NUM(6, 1)
end_define

begin_define
define|#
directive|define
name|CCGR_IPU_DI1_CLK
value|__CCGR_NUM(6, 2)
end_define

begin_define
define|#
directive|define
name|CCGR_GPU2D_CLK
value|__CCGR_NUM(6, 3)
end_define

begin_define
define|#
directive|define
name|CCGR_SLIMBUS_CLK
value|__CCGR_NUM(6, 4)
end_define

begin_define
define|#
directive|define
name|CCGR_SLIMBUS_SERIAL_CLK
value|__CCGR_NUM(6, 5)
end_define

begin_define
define|#
directive|define
name|CCGR_CLK_MODE_OFF
value|0
end_define

begin_define
define|#
directive|define
name|CCGR_CLK_MODE_RUNMODE
value|1
end_define

begin_define
define|#
directive|define
name|CCGR_CLK_MODE_ALWAYS
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IMX51_CCMREG_H */
end_comment

end_unit

