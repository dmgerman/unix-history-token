begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Ian Lepore<ian@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IMX6_CCMREG_H
end_ifndef

begin_define
define|#
directive|define
name|IMX6_CCMREG_H
end_define

begin_define
define|#
directive|define
name|CCM_CACCR
value|0x010
end_define

begin_define
define|#
directive|define
name|CCM_CBCDR
value|0x014
end_define

begin_define
define|#
directive|define
name|CBCDR_MMDC_CH1_AXI_PODF_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|CBCDR_MMDC_CH1_AXI_PODF_MASK
value|(7<< 3)
end_define

begin_define
define|#
directive|define
name|CCM_CSCMR1
value|0x01C
end_define

begin_define
define|#
directive|define
name|SSI1_CLK_SEL_S
value|10
end_define

begin_define
define|#
directive|define
name|SSI2_CLK_SEL_S
value|12
end_define

begin_define
define|#
directive|define
name|SSI3_CLK_SEL_S
value|14
end_define

begin_define
define|#
directive|define
name|SSI_CLK_SEL_M
value|0x3
end_define

begin_define
define|#
directive|define
name|SSI_CLK_SEL_508_PFD
value|0
end_define

begin_define
define|#
directive|define
name|SSI_CLK_SEL_454_PFD
value|1
end_define

begin_define
define|#
directive|define
name|SSI_CLK_SEL_PLL4
value|2
end_define

begin_define
define|#
directive|define
name|CCM_CSCMR2
value|0x020
end_define

begin_define
define|#
directive|define
name|CSCMR2_LDB_DI0_IPU_DIV_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|CCM_CS1CDR
value|0x028
end_define

begin_define
define|#
directive|define
name|SSI1_CLK_PODF_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SSI1_CLK_PRED_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|SSI3_CLK_PODF_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|SSI3_CLK_PRED_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|SSI_CLK_PODF_MASK
value|0x3f
end_define

begin_define
define|#
directive|define
name|SSI_CLK_PRED_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|CCM_CS2CDR
value|0x02C
end_define

begin_define
define|#
directive|define
name|SSI2_CLK_PODF_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SSI2_CLK_PRED_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|LDB_DI0_CLK_SEL_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|LDB_DI0_CLK_SEL_MASK
value|(3<< LDB_DI0_CLK_SEL_SHIFT)
end_define

begin_define
define|#
directive|define
name|CCM_CHSCCDR
value|0x034
end_define

begin_define
define|#
directive|define
name|CHSCCDR_IPU1_DI0_PRE_CLK_SEL_MASK
value|(0x7<< 6)
end_define

begin_define
define|#
directive|define
name|CHSCCDR_IPU1_DI0_PRE_CLK_SEL_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|CHSCCDR_IPU1_DI0_PODF_MASK
value|(0x7<< 3)
end_define

begin_define
define|#
directive|define
name|CHSCCDR_IPU1_DI0_PODF_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|CHSCCDR_IPU1_DI0_CLK_SEL_MASK
value|(0x7)
end_define

begin_define
define|#
directive|define
name|CHSCCDR_IPU1_DI0_CLK_SEL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|CHSCCDR_CLK_SEL_LDB_DI0
value|3
end_define

begin_define
define|#
directive|define
name|CHSCCDR_PODF_DIVIDE_BY_3
value|2
end_define

begin_define
define|#
directive|define
name|CHSCCDR_IPU_PRE_CLK_540M_PFD
value|5
end_define

begin_define
define|#
directive|define
name|CCM_CSCDR2
value|0x038
end_define

begin_define
define|#
directive|define
name|CCM_CLPCR
value|0x054
end_define

begin_define
define|#
directive|define
name|CCM_CLPCR_LPM_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|CCM_CLPCR_LPM_RUN
value|0x00
end_define

begin_define
define|#
directive|define
name|CCM_CLPCR_LPM_WAIT
value|0x01
end_define

begin_define
define|#
directive|define
name|CCM_CLPCR_LPM_STOP
value|0x02
end_define

begin_define
define|#
directive|define
name|CCM_CGPR
value|0x064
end_define

begin_define
define|#
directive|define
name|CCM_CGPR_INT_MEM_CLK_LPM
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|CCM_CCGR0
value|0x068
end_define

begin_define
define|#
directive|define
name|CCGR0_AIPS_TZ1
value|(0x3<< 0)
end_define

begin_define
define|#
directive|define
name|CCGR0_AIPS_TZ2
value|(0x3<< 2)
end_define

begin_define
define|#
directive|define
name|CCGR0_ABPHDMA
value|(0x3<< 4)
end_define

begin_define
define|#
directive|define
name|CCM_CCGR1
value|0x06C
end_define

begin_define
define|#
directive|define
name|CCGR1_ENET
value|(0x3<< 10)
end_define

begin_define
define|#
directive|define
name|CCGR1_EPIT1
value|(0x3<< 12)
end_define

begin_define
define|#
directive|define
name|CCGR1_EPIT2
value|(0x3<< 14)
end_define

begin_define
define|#
directive|define
name|CCGR1_GPT
value|(0x3<< 20)
end_define

begin_define
define|#
directive|define
name|CCGR1_GPT_SERIAL
value|(0x3<< 22)
end_define

begin_define
define|#
directive|define
name|CCM_CCGR2
value|0x070
end_define

begin_define
define|#
directive|define
name|CCGR2_HDMI_TX
value|(0x3<< 0)
end_define

begin_define
define|#
directive|define
name|CCGR2_HDMI_TX_ISFR
value|(0x3<< 4)
end_define

begin_define
define|#
directive|define
name|CCGR2_I2C1
value|(0x3<< 6)
end_define

begin_define
define|#
directive|define
name|CCGR2_I2C2
value|(0x3<< 8)
end_define

begin_define
define|#
directive|define
name|CCGR2_I2C3
value|(0x3<< 10)
end_define

begin_define
define|#
directive|define
name|CCGR2_IIM
value|(0x3<< 12)
end_define

begin_define
define|#
directive|define
name|CCGR2_IOMUX_IPT
value|(0x3<< 14)
end_define

begin_define
define|#
directive|define
name|CCGR2_IPMUX1
value|(0x3<< 16)
end_define

begin_define
define|#
directive|define
name|CCGR2_IPMUX2
value|(0x3<< 18)
end_define

begin_define
define|#
directive|define
name|CCGR2_IPMUX3
value|(0x3<< 20)
end_define

begin_define
define|#
directive|define
name|CCGR2_IPSYNC_IP2APB_TZASC1
value|(0x3<< 22)
end_define

begin_define
define|#
directive|define
name|CCGR2_IPSYNC_IP2APB_TZASC2
value|(0x3<< 24)
end_define

begin_define
define|#
directive|define
name|CCGR2_IPSYNC_VDOA
value|(0x3<< 26)
end_define

begin_define
define|#
directive|define
name|CCM_CCGR3
value|0x074
end_define

begin_define
define|#
directive|define
name|CCGR3_IPU1_IPU
value|(0x3<< 0)
end_define

begin_define
define|#
directive|define
name|CCGR3_IPU1_DI0
value|(0x3<< 2)
end_define

begin_define
define|#
directive|define
name|CCGR3_IPU1_DI1
value|(0x3<< 4)
end_define

begin_define
define|#
directive|define
name|CCGR3_IPU2_IPU
value|(0x3<< 6)
end_define

begin_define
define|#
directive|define
name|CCGR3_IPU2_DI0
value|(0x3<< 8)
end_define

begin_define
define|#
directive|define
name|CCGR3_IPU2_DI1
value|(0x3<< 10)
end_define

begin_define
define|#
directive|define
name|CCGR3_LDB_DI0
value|(0x3<< 12)
end_define

begin_define
define|#
directive|define
name|CCGR3_LDB_DI1
value|(0x3<< 14)
end_define

begin_define
define|#
directive|define
name|CCGR3_MMDC_CORE_ACLK_FAST
value|(0x3<< 20)
end_define

begin_define
define|#
directive|define
name|CCGR3_CG11
value|(0x3<< 22)
end_define

begin_define
define|#
directive|define
name|CCGR3_MMDC_CORE_IPG
value|(0x3<< 24)
end_define

begin_define
define|#
directive|define
name|CCGR3_CG13
value|(0x3<< 26)
end_define

begin_define
define|#
directive|define
name|CCGR3_OCRAM
value|(0x3<< 28)
end_define

begin_define
define|#
directive|define
name|CCM_CCGR4
value|0x078
end_define

begin_define
define|#
directive|define
name|CCGR4_PL301_MX6QFAST1_S133
value|(0x3<< 8)
end_define

begin_define
define|#
directive|define
name|CCGR4_PL301_MX6QPER1_BCH
value|(0x3<< 12)
end_define

begin_define
define|#
directive|define
name|CCGR4_PL301_MX6QPER2_MAIN
value|(0x3<< 14)
end_define

begin_define
define|#
directive|define
name|CCM_CCGR5
value|0x07C
end_define

begin_define
define|#
directive|define
name|CCGR5_SATA
value|(0x3<< 4)
end_define

begin_define
define|#
directive|define
name|CCGR5_SDMA
value|(0x3<< 6)
end_define

begin_define
define|#
directive|define
name|CCGR5_SSI1
value|(0x3<< 18)
end_define

begin_define
define|#
directive|define
name|CCGR5_SSI2
value|(0x3<< 20)
end_define

begin_define
define|#
directive|define
name|CCGR5_SSI3
value|(0x3<< 22)
end_define

begin_define
define|#
directive|define
name|CCGR5_UART
value|(0x3<< 24)
end_define

begin_define
define|#
directive|define
name|CCGR5_UART_SERIAL
value|(0x3<< 26)
end_define

begin_define
define|#
directive|define
name|CCM_CCGR6
value|0x080
end_define

begin_define
define|#
directive|define
name|CCGR6_USBOH3
value|(0x3<< 0)
end_define

begin_define
define|#
directive|define
name|CCGR6_USDHC1
value|(0x3<< 2)
end_define

begin_define
define|#
directive|define
name|CCGR6_USDHC2
value|(0x3<< 4)
end_define

begin_define
define|#
directive|define
name|CCGR6_USDHC3
value|(0x3<< 6)
end_define

begin_define
define|#
directive|define
name|CCGR6_USDHC4
value|(0x3<< 8)
end_define

begin_define
define|#
directive|define
name|CCM_CMEOR
value|0x088
end_define

begin_define
define|#
directive|define
name|CCM_ANALOG_PLL_ENET
value|0x000040e0
end_define

begin_define
define|#
directive|define
name|CCM_ANALOG_PLL_ENET_LOCK
value|(1u<< 31)
end_define

begin_define
define|#
directive|define
name|CCM_ANALOG_PLL_ENET_ENABLE_100M
value|(1u<< 20)
end_define

begin_comment
comment|/* SATA */
end_comment

begin_define
define|#
directive|define
name|CCM_ANALOG_PLL_ENET_BYPASS
value|(1u<< 16)
end_define

begin_define
define|#
directive|define
name|CCM_ANALOG_PLL_ENET_ENABLE
value|(1u<< 13)
end_define

begin_comment
comment|/* Ether */
end_comment

begin_define
define|#
directive|define
name|CCM_ANALOG_PLL_ENET_POWERDOWN
value|(1u<< 12)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

