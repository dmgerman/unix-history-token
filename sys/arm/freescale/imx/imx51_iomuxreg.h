begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This file was generated automatically from PDF file by mkiomuxreg_imx51.rb  *  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2012, 2013 The FreeBSD Foundation  * All rights reserved.  *  * Portions of this software were developed by Oleksandr Rybalko  * under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1.	Redistributions of source code must retain the above copyright  *	notice, this list of conditions and the following disclaimer.  * 2.	Redistributions in binary form must reproduce the above copyright  *	notice, this list of conditions and the following disclaimer in the  *	documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IMX51_IOMUXREG_H
end_ifndef

begin_define
define|#
directive|define
name|_IMX51_IOMUXREG_H
end_define

begin_define
define|#
directive|define
name|IOMUXC_MUX_CTL
value|0x001c
end_define

begin_comment
comment|/* multiplex control */
end_comment

begin_define
define|#
directive|define
name|IOMUX_CONFIG_SION
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|IOMUX_CONFIG_ALT0
value|(0)
end_define

begin_define
define|#
directive|define
name|IOMUX_CONFIG_ALT1
value|(1)
end_define

begin_define
define|#
directive|define
name|IOMUX_CONFIG_ALT2
value|(2)
end_define

begin_define
define|#
directive|define
name|IOMUX_CONFIG_ALT3
value|(3)
end_define

begin_define
define|#
directive|define
name|IOMUX_CONFIG_ALT4
value|(4)
end_define

begin_define
define|#
directive|define
name|IOMUX_CONFIG_ALT5
value|(5)
end_define

begin_define
define|#
directive|define
name|IOMUX_CONFIG_ALT6
value|(6)
end_define

begin_define
define|#
directive|define
name|IOMUX_CONFIG_ALT7
value|(7)
end_define

begin_define
define|#
directive|define
name|IOMUXC_PAD_CTL
value|0x03f0
end_define

begin_comment
comment|/* pad control */
end_comment

begin_define
define|#
directive|define
name|PAD_CTL_HVE
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|PAD_CTL_DDR_INPUT
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|PAD_CTL_HYS
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|PAD_CTL_PKE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|PAD_CTL_PUE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|PAD_CTL_PULL
value|(PAD_CTL_PKE|PAD_CTL_PUE)
end_define

begin_define
define|#
directive|define
name|PAD_CTL_KEEPER
value|(PAD_CTL_PKE|0)
end_define

begin_define
define|#
directive|define
name|PAD_CTL_PUS_100K_PD
value|(0x0<< 4)
end_define

begin_define
define|#
directive|define
name|PAD_CTL_PUS_47K_PU
value|(0x1<< 4)
end_define

begin_define
define|#
directive|define
name|PAD_CTL_PUS_100K_PU
value|(0x2<< 4)
end_define

begin_define
define|#
directive|define
name|PAD_CTL_PUS_22K_PU
value|(0x3<< 4)
end_define

begin_define
define|#
directive|define
name|PAD_CTL_ODE
value|(1<< 3)
end_define

begin_comment
comment|/* opendrain */
end_comment

begin_define
define|#
directive|define
name|PAD_CTL_DSE_LOW
value|(0x0<< 1)
end_define

begin_define
define|#
directive|define
name|PAD_CTL_DSE_MID
value|(0x1<< 1)
end_define

begin_define
define|#
directive|define
name|PAD_CTL_DSE_HIGH
value|(0x2<< 1)
end_define

begin_define
define|#
directive|define
name|PAD_CTL_DSE_MAX
value|(0x3<< 1)
end_define

begin_define
define|#
directive|define
name|PAD_CTL_SRE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|IOMUXC_INPUT_CTL
value|0x08c4
end_define

begin_comment
comment|/* input control */
end_comment

begin_define
define|#
directive|define
name|INPUT_DAISY_0
value|0
end_define

begin_define
define|#
directive|define
name|INPUT_DAISY_1
value|1
end_define

begin_define
define|#
directive|define
name|INPUT_DAISY_2
value|2
end_define

begin_define
define|#
directive|define
name|INPUT_DAISY_3
value|3
end_define

begin_define
define|#
directive|define
name|INPUT_DAISY_4
value|4
end_define

begin_define
define|#
directive|define
name|INPUT_DAISY_5
value|5
end_define

begin_define
define|#
directive|define
name|INPUT_DAISY_6
value|6
end_define

begin_define
define|#
directive|define
name|INPUT_DAISY_7
value|7
end_define

begin_comment
comment|/*  * IOMUX index  */
end_comment

begin_define
define|#
directive|define
name|IOMUX_PIN_TO_MUX_ADDRESS
parameter_list|(
name|pin
parameter_list|)
value|(((pin)>> 16)& 0xffff)
end_define

begin_define
define|#
directive|define
name|IOMUX_PIN_TO_PAD_ADDRESS
parameter_list|(
name|pin
parameter_list|)
value|(((pin)>>  0)& 0xffff)
end_define

begin_define
define|#
directive|define
name|IOMUX_PIN
parameter_list|(
name|mux_adr
parameter_list|,
name|pad_adr
parameter_list|)
define|\
value|(((mux_adr)<< 16) | (((pad_adr)<< 0)))
end_define

begin_define
define|#
directive|define
name|IOMUX_MUX_NONE
value|0xffff
end_define

begin_define
define|#
directive|define
name|IOMUX_PAD_NONE
value|0xffff
end_define

begin_comment
comment|/* register offset address */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_GPR0
value|0x0000
end_define

begin_define
define|#
directive|define
name|IOMUXC_GPR1
value|0x0004
end_define

begin_define
define|#
directive|define
name|IOMUXC_OBSERVE_MUX_0
value|0x0008
end_define

begin_define
define|#
directive|define
name|IOMUXC_OBSERVE_MUX_1
value|0x000c
end_define

begin_define
define|#
directive|define
name|IOMUXC_OBSERVE_MUX_2
value|0x0010
end_define

begin_define
define|#
directive|define
name|IOMUXC_OBSERVE_MUX_3
value|0x0014
end_define

begin_define
define|#
directive|define
name|IOMUXC_OBSERVE_MUX_4
value|0x0018
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_DA0
value|0x001c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_DA1
value|0x0020
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_DA2
value|0x0024
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_DA3
value|0x0028
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_DA4
value|0x002c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_DA5
value|0x0030
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_DA6
value|0x0034
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_DA7
value|0x0038
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_DA8
value|0x003c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_DA9
value|0x0040
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_DA10
value|0x0044
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_DA11
value|0x0048
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_DA12
value|0x004c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_DA13
value|0x0050
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_DA14
value|0x0054
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_DA15
value|0x0058
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_D16
value|0x005c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_D17
value|0x0060
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_D18
value|0x0064
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_D19
value|0x0068
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_D20
value|0x006c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_D21
value|0x0070
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_D22
value|0x0074
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_D23
value|0x0078
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_D24
value|0x007c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_D25
value|0x0080
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_D26
value|0x0084
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_D27
value|0x0088
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_D28
value|0x008c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_D29
value|0x0090
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_D30
value|0x0094
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_D31
value|0x0098
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_A16
value|0x009c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_A17
value|0x00a0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_A18
value|0x00a4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_A19
value|0x00a8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_A20
value|0x00ac
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_A21
value|0x00b0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_A22
value|0x00b4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_A23
value|0x00b8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_A24
value|0x00bc
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_A25
value|0x00c0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_A26
value|0x00c4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_A27
value|0x00c8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_EB0
value|0x00cc
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_EB1
value|0x00d0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_EB2
value|0x00d4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_EB3
value|0x00d8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_OE
value|0x00dc
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_CS0
value|0x00e0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_CS1
value|0x00e4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_CS2
value|0x00e8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_CS3
value|0x00ec
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_CS4
value|0x00f0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_CS5
value|0x00f4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_DTACK
value|0x00f8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_LBA
value|0x00fc
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_CRE
value|0x0100
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DRAM_CS1
value|0x0104
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NANDF_WE_B
value|0x0108
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NANDF_RE_B
value|0x010c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NANDF_ALE
value|0x0110
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NANDF_CLE
value|0x0114
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NANDF_WP_B
value|0x0118
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NANDF_RB0
value|0x011c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NANDF_RB1
value|0x0120
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NANDF_RB2
value|0x0124
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NANDF_RB3
value|0x0128
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_GPIO_NAND
value|0x012c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NANDF_CS0
value|0x0130
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NANDF_CS1
value|0x0134
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NANDF_CS2
value|0x0138
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NANDF_CS3
value|0x013c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NANDF_CS4
value|0x0140
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NANDF_CS5
value|0x0144
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NANDF_CS6
value|0x0148
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NANDF_CS7
value|0x014c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NANDF_RDY_INT
value|0x0150
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NANDF_D15
value|0x0154
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NANDF_D14
value|0x0158
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NANDF_D13
value|0x015c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NANDF_D12
value|0x0160
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NANDF_D11
value|0x0164
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NANDF_D10
value|0x0168
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NANDF_D9
value|0x016c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NANDF_D8
value|0x0170
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NANDF_D7
value|0x0174
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NANDF_D6
value|0x0178
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NANDF_D5
value|0x017c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NANDF_D4
value|0x0180
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NANDF_D3
value|0x0184
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NANDF_D2
value|0x0188
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NANDF_D1
value|0x018c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NANDF_D0
value|0x0190
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI1_D8
value|0x0194
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI1_D9
value|0x0198
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI1_D10
value|0x019c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI1_D11
value|0x01a0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI1_D12
value|0x01a4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI1_D13
value|0x01a8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI1_D14
value|0x01ac
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI1_D15
value|0x01b0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI1_D16
value|0x01b4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI1_D17
value|0x01b8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI1_D18
value|0x01bc
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI1_D19
value|0x01c0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI1_VSYNC
value|0x01c4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI1_HSYNC
value|0x01c8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI2_D12
value|0x01cc
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI2_D13
value|0x01d0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI2_D14
value|0x01d4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI2_D15
value|0x01d8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI2_D16
value|0x01dc
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI2_D17
value|0x01e0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI2_D18
value|0x01e4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI2_D19
value|0x01e8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI2_VSYNC
value|0x01ec
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI2_HSYNC
value|0x01f0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI2_PIXCLK
value|0x01f4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_I2C1_CLK
value|0x01f8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_I2C1_DAT
value|0x01fc
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_AUD3_BB_TXD
value|0x0200
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_AUD3_BB_RXD
value|0x0204
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_AUD3_BB_CK
value|0x0208
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_AUD3_BB_FS
value|0x020c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSPI1_MOSI
value|0x0210
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSPI1_MISO
value|0x0214
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSPI1_SS0
value|0x0218
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSPI1_SS1
value|0x021c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSPI1_RDY
value|0x0220
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSPI1_SCLK
value|0x0224
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_UART1_RXD
value|0x0228
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_UART1_TXD
value|0x022c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_UART1_RTS
value|0x0230
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_UART1_CTS
value|0x0234
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_UART2_RXD
value|0x0238
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_UART2_TXD
value|0x023c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_UART3_RXD
value|0x0240
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_UART3_TXD
value|0x0244
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_OWIRE_LINE
value|0x0248
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_KEY_ROW0
value|0x024c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_KEY_ROW1
value|0x0250
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_KEY_ROW2
value|0x0254
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_KEY_ROW3
value|0x0258
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_KEY_COL0
value|0x025c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_KEY_COL1
value|0x0260
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_KEY_COL2
value|0x0264
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_KEY_COL3
value|0x0268
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_KEY_COL4
value|0x026c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_KEY_COL5
value|0x0270
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_JTAG_DE_B
value|0x0274
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_USBH1_CLK
value|0x0278
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_USBH1_DIR
value|0x027c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_USBH1_STP
value|0x0280
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_USBH1_NXT
value|0x0284
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_USBH1_DATA0
value|0x0288
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_USBH1_DATA1
value|0x028c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_USBH1_DATA2
value|0x0290
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_USBH1_DATA3
value|0x0294
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_USBH1_DATA4
value|0x0298
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_USBH1_DATA5
value|0x029c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_USBH1_DATA6
value|0x02a0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_USBH1_DATA7
value|0x02a4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DI1_PIN11
value|0x02a8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DI1_PIN12
value|0x02ac
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DI1_PIN13
value|0x02b0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DI1_D0_CS
value|0x02b4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DI1_D1_CS
value|0x02b8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISPB2_SER_DIN
value|0x02bc
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISPB2_SER_DIO
value|0x02c0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISPB2_SER_CLK
value|0x02c4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISPB2_SER_RS
value|0x02c8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP1_DAT0
value|0x02cc
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP1_DAT1
value|0x02d0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP1_DAT2
value|0x02d4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP1_DAT3
value|0x02d8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP1_DAT4
value|0x02dc
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP1_DAT5
value|0x02e0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP1_DAT6
value|0x02e4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP1_DAT7
value|0x02e8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP1_DAT8
value|0x02ec
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP1_DAT9
value|0x02f0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP1_DAT10
value|0x02f4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP1_DAT11
value|0x02f8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP1_DAT12
value|0x02fc
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP1_DAT13
value|0x0300
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP1_DAT14
value|0x0304
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP1_DAT15
value|0x0308
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP1_DAT16
value|0x030c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP1_DAT17
value|0x0310
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP1_DAT18
value|0x0314
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP1_DAT19
value|0x0318
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP1_DAT20
value|0x031c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP1_DAT21
value|0x0320
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP1_DAT22
value|0x0324
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP1_DAT23
value|0x0328
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DI1_PIN3
value|0x032c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DI1_PIN2
value|0x0330
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DI_GP1
value|0x0334
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DI_GP2
value|0x0338
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DI_GP3
value|0x033c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DI2_PIN4
value|0x0340
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DI2_PIN2
value|0x0344
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DI2_PIN3
value|0x0348
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DI2_DISP_CLK
value|0x034c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DI_GP4
value|0x0350
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP2_DAT0
value|0x0354
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP2_DAT1
value|0x0358
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP2_DAT2
value|0x035c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP2_DAT3
value|0x0360
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP2_DAT4
value|0x0364
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP2_DAT5
value|0x0368
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP2_DAT6
value|0x036c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP2_DAT7
value|0x0370
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP2_DAT8
value|0x0374
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP2_DAT9
value|0x0378
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP2_DAT10
value|0x037c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP2_DAT11
value|0x0380
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP2_DAT12
value|0x0384
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP2_DAT13
value|0x0388
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP2_DAT14
value|0x038c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP2_DAT15
value|0x0390
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD1_CMD
value|0x0394
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD1_CLK
value|0x0398
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD1_DATA0
value|0x039c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD1_DATA1
value|0x03a0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD1_DATA2
value|0x03a4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD1_DATA3
value|0x03a8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_GPIO1_0
value|0x03ac
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_GPIO1_1
value|0x03b0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD2_CMD
value|0x03b4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD2_CLK
value|0x03b8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD2_DATA0
value|0x03bc
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD2_DATA1
value|0x03c0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD2_DATA2
value|0x03c4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD2_DATA3
value|0x03c8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_GPIO1_2
value|0x03cc
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_GPIO1_3
value|0x03d0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_PMIC_INT_REQ
value|0x03d4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_GPIO1_4
value|0x03d8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_GPIO1_5
value|0x03dc
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_GPIO1_6
value|0x03e0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_GPIO1_7
value|0x03e4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_GPIO1_8
value|0x03e8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_GPIO1_9
value|0x03ec
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_D16
value|0x03f0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_D17
value|0x03f4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_D18
value|0x03f8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_D19
value|0x03fc
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_D20
value|0x0400
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_D21
value|0x0404
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_D22
value|0x0408
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_D23
value|0x040c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_D24
value|0x0410
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_D25
value|0x0414
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_D26
value|0x0418
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_D27
value|0x041c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_D28
value|0x0420
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_D29
value|0x0424
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_D30
value|0x0428
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_D31
value|0x042c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_A16
value|0x0430
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_A17
value|0x0434
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_A18
value|0x0438
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_A19
value|0x043c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_A20
value|0x0440
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_A21
value|0x0444
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_A22
value|0x0448
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_A23
value|0x044c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_A24
value|0x0450
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_A25
value|0x0454
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_A26
value|0x0458
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_A27
value|0x045c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_EB0
value|0x0460
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_EB1
value|0x0464
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_EB2
value|0x0468
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_EB3
value|0x046c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_OE
value|0x0470
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_CS0
value|0x0474
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_CS1
value|0x0478
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_CS2
value|0x047c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_CS3
value|0x0480
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_CS4
value|0x0484
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_CS5
value|0x0488
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_DTACK
value|0x048c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_WAIT
value|0x0490
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_LBA
value|0x0494
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_BCLK
value|0x0498
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_RW
value|0x049c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_CRE
value|0x04a0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_RAS
value|0x04a4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_CAS
value|0x04a8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_SDWE
value|0x04ac
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_SDCKE0
value|0x04b0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_SDCKE1
value|0x04b4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_SDCLK
value|0x04b8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS0
value|0x04bc
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS1
value|0x04c0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS2
value|0x04c4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS3
value|0x04c8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_CS0
value|0x04cc
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_CS1
value|0x04d0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM0
value|0x04d4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM1
value|0x04d8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM2
value|0x04dc
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM3
value|0x04e0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NANDF_WE_B
value|0x04e4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NANDF_RE_B
value|0x04e8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NANDF_ALE
value|0x04ec
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NANDF_CLE
value|0x04f0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NANDF_WP_B
value|0x04f4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NANDF_RB0
value|0x04f8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NANDF_RB1
value|0x04fc
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NANDF_RB2
value|0x0500
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NANDF_RB3
value|0x0504
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_SDBA2
value|0x0508
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_SDODT1
value|0x050c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_SDODT0
value|0x0510
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_GPIO_NAND
value|0x0514
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NANDF_CS0
value|0x0518
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NANDF_CS1
value|0x051c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NANDF_CS2
value|0x0520
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NANDF_CS3
value|0x0524
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NANDF_CS4
value|0x0528
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NANDF_CS5
value|0x052c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NANDF_CS6
value|0x0530
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NANDF_CS7
value|0x0534
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NANDF_RDY_INT
value|0x0538
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NANDF_D15
value|0x053c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NANDF_D14
value|0x0540
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NANDF_D13
value|0x0544
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NANDF_D12
value|0x0548
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NANDF_D11
value|0x054c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NANDF_D10
value|0x0550
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NANDF_D9
value|0x0554
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NANDF_D8
value|0x0558
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NANDF_D7
value|0x055c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NANDF_D6
value|0x0560
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NANDF_D5
value|0x0564
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NANDF_D4
value|0x0568
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NANDF_D3
value|0x056c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NANDF_D2
value|0x0570
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NANDF_D1
value|0x0574
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NANDF_D0
value|0x0578
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI1_D8
value|0x057c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI1_D9
value|0x0580
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI1_D10
value|0x0584
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI1_D11
value|0x0588
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI1_D12
value|0x058c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI1_D13
value|0x0590
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI1_D14
value|0x0594
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI1_D15
value|0x0598
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI1_D16
value|0x059c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI1_D17
value|0x05a0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI1_D18
value|0x05a4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI1_D19
value|0x05a8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI1_VSYNC
value|0x05ac
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI1_HSYNC
value|0x05b0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI1_PIXCLK
value|0x05b4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI1_MCLK
value|0x05b8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI2_D12
value|0x05bc
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI2_D13
value|0x05c0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI2_D14
value|0x05c4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI2_D15
value|0x05c8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI2_D16
value|0x05cc
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI2_D17
value|0x05d0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI2_D18
value|0x05d4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI2_D19
value|0x05d8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI2_VSYNC
value|0x05dc
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI2_HSYNC
value|0x05e0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI2_PIXCLK
value|0x05e4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_I2C1_CLK
value|0x05e8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_I2C1_DAT
value|0x05ec
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_AUD3_BB_TXD
value|0x05f0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_AUD3_BB_RXD
value|0x05f4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_AUD3_BB_CK
value|0x05f8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_AUD3_BB_FS
value|0x05fc
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSPI1_MOSI
value|0x0600
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSPI1_MISO
value|0x0604
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSPI1_SS0
value|0x0608
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSPI1_SS1
value|0x060c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSPI1_RDY
value|0x0610
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSPI1_SCLK
value|0x0614
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_UART1_RXD
value|0x0618
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_UART1_TXD
value|0x061c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_UART1_RTS
value|0x0620
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_UART1_CTS
value|0x0624
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_UART2_RXD
value|0x0628
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_UART2_TXD
value|0x062c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_UART3_RXD
value|0x0630
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_UART3_TXD
value|0x0634
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_OWIRE_LINE
value|0x0638
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_KEY_ROW0
value|0x063c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_KEY_ROW1
value|0x0640
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_KEY_ROW2
value|0x0644
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_KEY_ROW3
value|0x0648
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_KEY_COL0
value|0x064c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_KEY_COL1
value|0x0650
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_KEY_COL2
value|0x0654
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_KEY_COL3
value|0x0658
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_KEY_COL4
value|0x065c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_KEY_COL5
value|0x0660
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_JTAG_TCK
value|0x0664
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_JTAG_TMS
value|0x0668
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_JTAG_TDI
value|0x066c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_JTAG_TRSTB
value|0x0670
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_JTAG_MOD
value|0x0674
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_USBH1_CLK
value|0x0678
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_USBH1_DIR
value|0x067c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_USBH1_STP
value|0x0680
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_USBH1_NXT
value|0x0684
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_USBH1_DATA0
value|0x0688
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_USBH1_DATA1
value|0x068c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_USBH1_DATA2
value|0x0690
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_USBH1_DATA3
value|0x0694
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_USBH1_DATA4
value|0x0698
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_USBH1_DATA5
value|0x069c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_USBH1_DATA6
value|0x06a0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_USBH1_DATA7
value|0x06a4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DI1_PIN11
value|0x06a8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DI1_PIN12
value|0x06ac
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DI1_PIN13
value|0x06b0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DI1_D0_CS
value|0x06b4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DI1_D1_CS
value|0x06b8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISPB2_SER_DIN
value|0x06bc
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISPB2_SER_DIO
value|0x06c0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISPB2_SER_CLK
value|0x06c4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISPB2_SER_RS
value|0x06c8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP1_DAT0
value|0x06cc
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP1_DAT1
value|0x06d0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP1_DAT2
value|0x06d4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP1_DAT3
value|0x06d8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP1_DAT4
value|0x06dc
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP1_DAT5
value|0x06e0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP1_DAT6
value|0x06e4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP1_DAT7
value|0x06e8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP1_DAT8
value|0x06ec
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP1_DAT9
value|0x06f0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP1_DAT10
value|0x06f4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP1_DAT11
value|0x06f8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP1_DAT12
value|0x06fc
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP1_DAT13
value|0x0700
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP1_DAT14
value|0x0704
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP1_DAT15
value|0x0708
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP1_DAT16
value|0x070c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP1_DAT17
value|0x0710
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP1_DAT18
value|0x0714
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP1_DAT19
value|0x0718
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP1_DAT20
value|0x071c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP1_DAT21
value|0x0720
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP1_DAT22
value|0x0724
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP1_DAT23
value|0x0728
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DI1_PIN3
value|0x072c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DI1_DISP_CLK
value|0x0730
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DI1_PIN2
value|0x0734
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DI1_PIN15
value|0x0738
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DI_GP1
value|0x073c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DI_GP2
value|0x0740
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DI_GP3
value|0x0744
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DI2_PIN4
value|0x0748
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DI2_PIN2
value|0x074c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DI2_PIN3
value|0x0750
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DI2_DISP_CLK
value|0x0754
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DI_GP4
value|0x0758
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP2_DAT0
value|0x075c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP2_DAT1
value|0x0760
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP2_DAT2
value|0x0764
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP2_DAT3
value|0x0768
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP2_DAT4
value|0x076c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP2_DAT5
value|0x0770
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP2_DAT6
value|0x0774
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP2_DAT7
value|0x0778
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP2_DAT8
value|0x077c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP2_DAT9
value|0x0780
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP2_DAT10
value|0x0784
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP2_DAT11
value|0x0788
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP2_DAT12
value|0x078c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP2_DAT13
value|0x0790
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP2_DAT14
value|0x0794
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP2_DAT15
value|0x0798
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD1_CMD
value|0x079c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD1_CLK
value|0x07a0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD1_DATA0
value|0x07a4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD1_DATA1
value|0x07a8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD1_DATA2
value|0x07ac
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD1_DATA3
value|0x07b0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_GPIO1_0
value|0x07b4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_GPIO1_1
value|0x07b8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD2_CMD
value|0x07bc
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD2_CLK
value|0x07c0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD2_DATA0
value|0x07c4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD2_DATA1
value|0x07c8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD2_DATA2
value|0x07cc
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD2_DATA3
value|0x07d0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_GPIO1_2
value|0x07d4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_GPIO1_3
value|0x07d8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_RESET_IN_B
value|0x07dc
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_POR_B
value|0x07e0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_BOOT_MODE1
value|0x07e4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_BOOT_MODE0
value|0x07e8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_PMIC_RDY
value|0x07ec
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CKIL
value|0x07f0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_PMIC_STBY_REQ
value|0x07f4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_PMIC_ON_REQ
value|0x07f8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_PMIC_INT_REQ
value|0x07fc
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CLK_SS
value|0x0800
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_GPIO1_4
value|0x0804
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_GPIO1_5
value|0x0808
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_GPIO1_6
value|0x080c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_GPIO1_7
value|0x0810
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_GPIO1_8
value|0x0814
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_GPIO1_9
value|0x0818
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_CSI2_PKE0
value|0x081c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_DDRPKS
value|0x0820
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_EIM_SR1
value|0x0824
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_DISP2_PKE0
value|0x0828
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_DRAM_B4
value|0x082c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_INDDR
value|0x0830
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_EIM_SR2
value|0x0834
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_PKEDDR
value|0x0838
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_DDR_A0
value|0x083c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_EMI_PKE0
value|0x0840
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_EIM_SR3
value|0x0844
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_DDR_A1
value|0x0848
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_DDRAPUS
value|0x084c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_EIM_SR4
value|0x0850
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_EMI_SR5
value|0x0854
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_EMI_SR6
value|0x0858
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_HYSDDR0
value|0x085c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_CSI1_PKE0
value|0x0860
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_HYSDDR1
value|0x0864
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_DISP1_PKE0
value|0x0868
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_HYSDDR2
value|0x086c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_HVDDR
value|0x0870
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_HYSDDR3
value|0x0874
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_DRAM_SR_B0
value|0x0878
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_DDRAPKS
value|0x087c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_DRAM_SR_B1
value|0x0880
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_DDRPUS
value|0x0884
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_EIM_DS1
value|0x0888
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_DRAM_SR_B2
value|0x088c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_PKEADDR
value|0x0890
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_EIM_DS2
value|0x0894
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_EIM_DS3
value|0x0898
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_DRAM_SR_B4
value|0x089c
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_INMODE1
value|0x08a0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_DRAM_B0
value|0x08a4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_EIM_DS4
value|0x08a8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_DRAM_B1
value|0x08ac
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_DDR_SR_A0
value|0x08b0
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_EMI_DS5
value|0x08b4
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_DRAM_B2
value|0x08b8
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_DDR_SR_A1
value|0x08bc
end_define

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_EMI_DS6
value|0x08c0
end_define

begin_define
define|#
directive|define
name|IOMUXC_AUDMUX_P4_INPUT_DA_AMX_SELECT_INPUT
value|0x08c4
end_define

begin_define
define|#
directive|define
name|IOMUXC_AUDMUX_P4_INPUT_DB_AMX_SELECT_INPUT
value|0x08c8
end_define

begin_define
define|#
directive|define
name|IOMUXC_AUDMUX_P4_INPUT_TXCLK_AMX_SELECT_INPUT
value|0x08cc
end_define

begin_define
define|#
directive|define
name|IOMUXC_AUDMUX_P4_INPUT_TXFS_AMX_SELECT_INPUT
value|0x08d0
end_define

begin_define
define|#
directive|define
name|IOMUXC_AUDMUX_P5_INPUT_DA_AMX_SELECT_INPUT
value|0x08d4
end_define

begin_define
define|#
directive|define
name|IOMUXC_AUDMUX_P5_INPUT_DB_AMX_SELECT_INPUT
value|0x08d8
end_define

begin_define
define|#
directive|define
name|IOMUXC_AUDMUX_P5_INPUT_RXCLK_AMX_SELECT_INPUT
value|0x08dc
end_define

begin_define
define|#
directive|define
name|IOMUXC_AUDMUX_P5_INPUT_RXFS_AMX_SELECT_INPUT
value|0x08e0
end_define

begin_define
define|#
directive|define
name|IOMUXC_AUDMUX_P5_INPUT_TXCLK_AMX_SELECT_INPUT
value|0x08e4
end_define

begin_define
define|#
directive|define
name|IOMUXC_AUDMUX_P5_INPUT_TXFS_AMX_SELECT_INPUT
value|0x08e8
end_define

begin_define
define|#
directive|define
name|IOMUXC_AUDMUX_P6_INPUT_DA_AMX_SELECT_INPUT
value|0x08ec
end_define

begin_define
define|#
directive|define
name|IOMUXC_AUDMUX_P6_INPUT_DB_AMX_SELECT_INPUT
value|0x08f0
end_define

begin_define
define|#
directive|define
name|IOMUXC_AUDMUX_P6_INPUT_RXCLK_AMX_SELECT_INPUT
value|0x08f4
end_define

begin_define
define|#
directive|define
name|IOMUXC_AUDMUX_P6_INPUT_RXFS_AMX_SELECT_INPUT
value|0x08f8
end_define

begin_define
define|#
directive|define
name|IOMUXC_AUDMUX_P6_INPUT_TXCLK_AMX_SELECT_INPUT
value|0x08fc
end_define

begin_define
define|#
directive|define
name|IOMUXC_AUDMUX_P6_INPUT_TXFS_AMX_SELECT_INPUT
value|0x0900
end_define

begin_define
define|#
directive|define
name|IOMUXC_CCM_IPP_DI0_CLK_SELECT_INPUT
value|0x0904
end_define

begin_define
define|#
directive|define
name|IOMUXC_CCM_IPP_DI1_CLK_SELECT_INPUT
value|0x0908
end_define

begin_define
define|#
directive|define
name|IOMUXC_CCM_PLL1_BYPASS_CLK_SELECT_INPUT
value|0x090c
end_define

begin_define
define|#
directive|define
name|IOMUXC_CCM_PLL2_BYPASS_CLK_SELECT_INPUT
value|0x0910
end_define

begin_define
define|#
directive|define
name|IOMUXC_CSPI_IPP_CSPI_CLK_IN_SELECT_INPUT
value|0x0914
end_define

begin_define
define|#
directive|define
name|IOMUXC_CSPI_IPP_IND_MISO_SELECT_INPUT
value|0x0918
end_define

begin_define
define|#
directive|define
name|IOMUXC_CSPI_IPP_IND_MOSI_SELECT_INPUT
value|0x091c
end_define

begin_define
define|#
directive|define
name|IOMUXC_CSPI_IPP_IND_SS1_B_SELECT_INPUT
value|0x0920
end_define

begin_define
define|#
directive|define
name|IOMUXC_CSPI_IPP_IND_SS2_B_SELECT_INPUT
value|0x0924
end_define

begin_define
define|#
directive|define
name|IOMUXC_CSPI_IPP_IND_SS3_B_SELECT_INPUT
value|0x0928
end_define

begin_define
define|#
directive|define
name|IOMUXC_DPLLIP1_L1T_TOG_EN_SELECT_INPUT
value|0x092c
end_define

begin_define
define|#
directive|define
name|IOMUXC_ECSPI2_IPP_IND_SS_B_1_SELECT_INPUT
value|0x0930
end_define

begin_define
define|#
directive|define
name|IOMUXC_ECSPI2_IPP_IND_SS_B_3_SELECT_INPUT
value|0x0934
end_define

begin_define
define|#
directive|define
name|IOMUXC_EMI_IPP_IND_RDY_INT_SELECT_INPUT
value|0x0938
end_define

begin_define
define|#
directive|define
name|IOMUXC_ESDHC3_IPP_DAT0_IN_SELECT_INPUT
value|0x093c
end_define

begin_define
define|#
directive|define
name|IOMUXC_ESDHC3_IPP_DAT1_IN_SELECT_INPUT
value|0x0940
end_define

begin_define
define|#
directive|define
name|IOMUXC_ESDHC3_IPP_DAT2_IN_SELECT_INPUT
value|0x0944
end_define

begin_define
define|#
directive|define
name|IOMUXC_ESDHC3_IPP_DAT3_IN_SELECT_INPUT
value|0x0948
end_define

begin_define
define|#
directive|define
name|IOMUXC_FEC_FEC_COL_SELECT_INPUT
value|0x094c
end_define

begin_define
define|#
directive|define
name|IOMUXC_FEC_FEC_CRS_SELECT_INPUT
value|0x0950
end_define

begin_define
define|#
directive|define
name|IOMUXC_FEC_FEC_MDI_SELECT_INPUT
value|0x0954
end_define

begin_define
define|#
directive|define
name|IOMUXC_FEC_FEC_RDATA_0_SELECT_INPUT
value|0x0958
end_define

begin_define
define|#
directive|define
name|IOMUXC_FEC_FEC_RDATA_1_SELECT_INPUT
value|0x095c
end_define

begin_define
define|#
directive|define
name|IOMUXC_FEC_FEC_RDATA_2_SELECT_INPUT
value|0x0960
end_define

begin_define
define|#
directive|define
name|IOMUXC_FEC_FEC_RDATA_3_SELECT_INPUT
value|0x0964
end_define

begin_define
define|#
directive|define
name|IOMUXC_FEC_FEC_RX_CLK_SELECT_INPUT
value|0x0968
end_define

begin_define
define|#
directive|define
name|IOMUXC_FEC_FEC_RX_DV_SELECT_INPUT
value|0x096c
end_define

begin_define
define|#
directive|define
name|IOMUXC_FEC_FEC_RX_ER_SELECT_INPUT
value|0x0970
end_define

begin_define
define|#
directive|define
name|IOMUXC_FEC_FEC_TX_CLK_SELECT_INPUT
value|0x0974
end_define

begin_define
define|#
directive|define
name|IOMUXC_GPIO3_IPP_IND_G_IN_1_SELECT_INPUT
value|0x0978
end_define

begin_define
define|#
directive|define
name|IOMUXC_GPIO3_IPP_IND_G_IN_2_SELECT_INPUT
value|0x097c
end_define

begin_define
define|#
directive|define
name|IOMUXC_GPIO3_IPP_IND_G_IN_3_SELECT_INPUT
value|0x0980
end_define

begin_define
define|#
directive|define
name|IOMUXC_GPIO3_IPP_IND_G_IN_4_SELECT_INPUT
value|0x0984
end_define

begin_define
define|#
directive|define
name|IOMUXC_GPIO3_IPP_IND_G_IN_5_SELECT_INPUT
value|0x0988
end_define

begin_define
define|#
directive|define
name|IOMUXC_GPIO3_IPP_IND_G_IN_6_SELECT_INPUT
value|0x098c
end_define

begin_define
define|#
directive|define
name|IOMUXC_GPIO3_IPP_IND_G_IN_7_SELECT_INPUT
value|0x0990
end_define

begin_define
define|#
directive|define
name|IOMUXC_GPIO3_IPP_IND_G_IN_8_SELECT_INPUT
value|0x0994
end_define

begin_define
define|#
directive|define
name|IOMUXC_GPIO3_IPP_IND_G_IN_12_SELECT_INPUT
value|0x0998
end_define

begin_define
define|#
directive|define
name|IOMUXC_HSC_MIPI_MIX_PAR0_VSYNC_SELECT_INPUT
value|0x09a4
end_define

begin_define
define|#
directive|define
name|IOMUXC_HSC_MIPI_MIX_PAR1_DI_WAIT_SELECT_INPUT
value|0x09a8
end_define

begin_define
define|#
directive|define
name|IOMUXC_HSC_MIPI_MIX_PAR_SISG_TRIG_SELECT_INPUT
value|0x09ac
end_define

begin_define
define|#
directive|define
name|IOMUXC_I2C1_IPP_SCL_IN_SELECT_INPUT
value|0x09b0
end_define

begin_define
define|#
directive|define
name|IOMUXC_I2C1_IPP_SDA_IN_SELECT_INPUT
value|0x09b4
end_define

begin_define
define|#
directive|define
name|IOMUXC_I2C2_IPP_SCL_IN_SELECT_INPUT
value|0x09b8
end_define

begin_define
define|#
directive|define
name|IOMUXC_I2C2_IPP_SDA_IN_SELECT_INPUT
value|0x09bc
end_define

begin_define
define|#
directive|define
name|IOMUXC_IPU_IPP_DI_0_IND_DISPB_SD_D_SELECT_INPUT
value|0x09c0
end_define

begin_define
define|#
directive|define
name|IOMUXC_IPU_IPP_DI_1_IND_DISPB_SD_D_SELECT_INPUT
value|0x09c4
end_define

begin_define
define|#
directive|define
name|IOMUXC_KPP_IPP_IND_COL_6_SELECT_INPUT
value|0x09c8
end_define

begin_define
define|#
directive|define
name|IOMUXC_KPP_IPP_IND_COL_7_SELECT_INPUT
value|0x09cc
end_define

begin_define
define|#
directive|define
name|IOMUXC_KPP_IPP_IND_ROW_4_SELECT_INPUT
value|0x09d0
end_define

begin_define
define|#
directive|define
name|IOMUXC_KPP_IPP_IND_ROW_5_SELECT_INPUT
value|0x09d4
end_define

begin_define
define|#
directive|define
name|IOMUXC_KPP_IPP_IND_ROW_6_SELECT_INPUT
value|0x09d8
end_define

begin_define
define|#
directive|define
name|IOMUXC_KPP_IPP_IND_ROW_7_SELECT_INPUT
value|0x09dc
end_define

begin_define
define|#
directive|define
name|IOMUXC_UART1_IPP_UART_RTS_B_SELECT_INPUT
value|0x09e0
end_define

begin_define
define|#
directive|define
name|IOMUXC_UART1_IPP_UART_RXD_MUX_SELECT_INPUT
value|0x09e4
end_define

begin_define
define|#
directive|define
name|IOMUXC_UART2_IPP_UART_RTS_B_SELECT_INPUT
value|0x09e8
end_define

begin_define
define|#
directive|define
name|IOMUXC_UART2_IPP_UART_RXD_MUX_SELECT_INPUT
value|0x09ec
end_define

begin_define
define|#
directive|define
name|IOMUXC_UART3_IPP_UART_RTS_B_SELECT_INPUT
value|0x09f0
end_define

begin_define
define|#
directive|define
name|IOMUXC_UART3_IPP_UART_RXD_MUX_SELECT_INPUT
value|0x09f4
end_define

begin_define
define|#
directive|define
name|IOMUXC_USBOH3_IPP_IND_UH3_CLK_SELECT_INPUT
value|0x09f8
end_define

begin_define
define|#
directive|define
name|IOMUXC_USBOH3_IPP_IND_UH3_DATA_0_SELECT_INPUT
value|0x09fc
end_define

begin_define
define|#
directive|define
name|IOMUXC_USBOH3_IPP_IND_UH3_DATA_1_SELECT_INPUT
value|0x0a00
end_define

begin_define
define|#
directive|define
name|IOMUXC_USBOH3_IPP_IND_UH3_DATA_2_SELECT_INPUT
value|0x0a04
end_define

begin_define
define|#
directive|define
name|IOMUXC_USBOH3_IPP_IND_UH3_DATA_3_SELECT_INPUT
value|0x0a08
end_define

begin_define
define|#
directive|define
name|IOMUXC_USBOH3_IPP_IND_UH3_DATA_4_SELECT_INPUT
value|0x0a0c
end_define

begin_define
define|#
directive|define
name|IOMUXC_USBOH3_IPP_IND_UH3_DATA_5_SELECT_INPUT
value|0x0a10
end_define

begin_define
define|#
directive|define
name|IOMUXC_USBOH3_IPP_IND_UH3_DATA_6_SELECT_INPUT
value|0x0a14
end_define

begin_define
define|#
directive|define
name|IOMUXC_USBOH3_IPP_IND_UH3_DATA_7_SELECT_INPUT
value|0x0a18
end_define

begin_define
define|#
directive|define
name|IOMUXC_USBOH3_IPP_IND_UH3_DIR_SELECT_INPUT
value|0x0a1c
end_define

begin_define
define|#
directive|define
name|IOMUXC_USBOH3_IPP_IND_UH3_NXT_SELECT_INPUT
value|0x0a20
end_define

begin_define
define|#
directive|define
name|IOMUXC_USBOH3_IPP_IND_UH3_STP_SELECT_INPUT
value|0x0a24
end_define

begin_comment
comment|/* MUX& PAD Control */
end_comment

begin_define
define|#
directive|define
name|MUX_PIN
parameter_list|(
name|name
parameter_list|)
define|\
value|IOMUX_PIN(IOMUXC_SW_MUX_CTL_PAD_##name,	\ 	    IOMUXC_SW_PAD_CTL_PAD_##name)
end_define

begin_define
define|#
directive|define
name|MUX_PIN_MUX
parameter_list|(
name|name
parameter_list|)
define|\
value|IOMUX_PIN(IOMUXC_SW_MUX_CTL_PAD_##name, IOMUX_PAD_NONE)
end_define

begin_define
define|#
directive|define
name|MUX_PIN_PAD
parameter_list|(
name|name
parameter_list|)
define|\
value|IOMUX_PIN(IOMUX_MUX_NONE, IOMUXC_SW_PAD_CTL_PAD_##name)
end_define

begin_define
define|#
directive|define
name|MUX_PIN_GRP
parameter_list|(
name|name
parameter_list|)
define|\
value|IOMUX_PIN(IOMUX_MUX_NONE, IOMUXC_SW_PAD_CTL_GRP_##name)
end_define

begin_define
define|#
directive|define
name|MUX_PIN_PATH
parameter_list|(
name|name
parameter_list|)
define|\
value|IOMUX_PIN(IOMUXC_##name##_SELECT_INPUT, IOMUX_MUX_NONE)
end_define

begin_comment
comment|/* INPUT Control */
end_comment

begin_define
define|#
directive|define
name|MUX_SELECT
parameter_list|(
name|name
parameter_list|)
value|(name##_SELECT_INPUT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IMX51_IOMUXREG_H */
end_comment

end_unit

