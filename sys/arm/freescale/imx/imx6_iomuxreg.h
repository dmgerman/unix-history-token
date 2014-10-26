begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Boris Samorodov<bsam@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Pad                            : pin ("pin" is used at electric schemes,  *                                  while at HW SOC it's named "pad").  * Drive strength                 : the current that can be drawn with  *                                  appropriate voltage (varies inversely with  *                                  the supply impedance of the output pin).  * Drive strength enable (DSE)    : The value of the current the pin uses.  * HiZ (HYZ)                      : high input impedance value.  * Daisy chain (DAISY)            : the one after another interconnection of  *                                  devices.  * On die termination (ODT)       : the termination resistor for impedance  *                                  matching.  * Software input on (SION)       : the value to force the pin to be an input  *                                  one (i.e. to force the pin state reading).  * Hysteresis (HYS)               : Controls if the value of the input pin  *                                  remains the same until a sufficient change  *                                  is applied.  * Slow rate enable (SRE)         : How slow the pin value changes (slow rate  *                                  saves power).  * Open drain enable (ODE)        : If the input pin drains on low input or  *                                  goes down.  * Pull/keep enable (PKE)         : Enables pull/keep functionality.  * PUll/keep select (PUE)         : Selects if the pin is pullup/pulldown one  *                                  or remains it's previous role.  *                                  A note: I'm not sure why it's not PKS...  * Pullup (Pic.1)/pulldown (Pic.2): the pin's resistor connected to VCC (GND)  *                                  to prevent random value drai.  * Pullup/pulldown select (PUS)   : Selects the value of pullup/pulldown  *                                  resistor.  * Open drain (Pic.3)             : the output signal is applied to the base  *                                  of a transistor whose collector is used  *                                  as a pin.  *  * VCC o                VCC o                                 Open drain  *     |                    |                             ---->  pin  *    +++                   o|                           /  *    | | R                  | Switch                   /  *    +++  pullup           o|                      .---.  *     |                    |                      / |/  \  *>---+------> Pin>---+------> Pin>---{--|    )  *     |                    |                      \ |\  /  *     o|                  +++                      `--v'  *      | Switch           | | R                        \  *     o|                  +++  pulldown                 |  *     |                    |                            |  *   -----                -----                        -----  *    ---                  ---                          ---  *     -                    -                            -  *  *   Pic.1                Pic.2                        Pic.3  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IMX6_IOMUXREG_H
end_ifndef

begin_define
define|#
directive|define
name|IMX6_IOMUXREG_H
end_define

begin_comment
comment|/*  * Multiplex control  */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_MUX_CTL
value|0x004c
end_define

begin_define
define|#
directive|define
name|IOMUX_CONFIG_SION
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|IOMUX_CONFIG_ALT0
value|0
end_define

begin_define
define|#
directive|define
name|IOMUX_CONFIG_ALT1
value|1
end_define

begin_define
define|#
directive|define
name|IOMUX_CONFIG_ALT2
value|2
end_define

begin_define
define|#
directive|define
name|IOMUX_CONFIG_ALT3
value|3
end_define

begin_define
define|#
directive|define
name|IOMUX_CONFIG_ALT4
value|4
end_define

begin_define
define|#
directive|define
name|IOMUX_CONFIG_ALT5
value|5
end_define

begin_define
define|#
directive|define
name|IOMUX_CONFIG_ALT6
value|6
end_define

begin_define
define|#
directive|define
name|IOMUX_CONFIG_ALT7
value|7
end_define

begin_comment
comment|/*  * Pad control  */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_PAD_CTL
value|0x0360
end_define

begin_comment
comment|/* DDR Select Field */
end_comment

begin_define
define|#
directive|define
name|PAD_CTL_DDR_SEL_0
value|(0x0<<18)
end_define

begin_define
define|#
directive|define
name|PAD_CTL_DDR_SEL_1
value|(0x1<<18)
end_define

begin_define
define|#
directive|define
name|PAD_CTL_DDR_SEL_2
value|(0x2<<18)
end_define

begin_define
define|#
directive|define
name|PAD_CTL_DDR_SEL_3
value|(0x3<<18)
end_define

begin_define
define|#
directive|define
name|PAD_CTL_DDR_INPUT
value|(0x1<<17)
end_define

begin_comment
comment|/* DDR/CMOS Input Mode Field */
end_comment

begin_define
define|#
directive|define
name|PAD_CTL_HYS
value|(1<<16)
end_define

begin_comment
comment|/* Hysteresis Enable Field */
end_comment

begin_comment
comment|/* PullUp/Down Config Field: */
end_comment

begin_define
define|#
directive|define
name|PAD_CTL_PUS_100K_PD
value|(0x0<<14)
end_define

begin_comment
comment|/*   100K Ohm Pull Down */
end_comment

begin_define
define|#
directive|define
name|PAD_CTL_PUS_47K_PU
value|(0x1<<14)
end_define

begin_comment
comment|/*   47K Ohn Pull Up */
end_comment

begin_define
define|#
directive|define
name|PAD_CTL_PUS_100K_PU
value|(0x2<<14)
end_define

begin_comment
comment|/*   100K Ohm Pull Up */
end_comment

begin_define
define|#
directive|define
name|PAD_CTL_PUS_22K_PU
value|(0x3<<14)
end_define

begin_comment
comment|/*   22K Ohm Pull Up */
end_comment

begin_define
define|#
directive|define
name|PAD_CTL_PUE
value|(1<<13)
end_define

begin_comment
comment|/* Pull/Keep Select Field */
end_comment

begin_define
define|#
directive|define
name|PAD_CTL_PKE
value|(1<<12)
end_define

begin_comment
comment|/* Pull/Keep Enable Field */
end_comment

begin_define
define|#
directive|define
name|PAD_CTL_ODE
value|(1<<11)
end_define

begin_comment
comment|/* Open Drain Enable Field */
end_comment

begin_comment
comment|/* On Die Termination Field: */
end_comment

begin_define
define|#
directive|define
name|PAD_CTL_ODT_DISABLED
value|(0x0<<8)
end_define

begin_comment
comment|/*   Disabled */
end_comment

begin_define
define|#
directive|define
name|PAD_CTL_ODT_1
value|(0x1<<8)
end_define

begin_define
define|#
directive|define
name|PAD_CTL_ODT_2
value|(0x2<<8)
end_define

begin_define
define|#
directive|define
name|PAD_CTL_ODT_3
value|(0x3<<8)
end_define

begin_define
define|#
directive|define
name|PAD_CTL_ODT_4
value|(0x4<<8)
end_define

begin_define
define|#
directive|define
name|PAD_CTL_ODT_5
value|(0x5<<8)
end_define

begin_define
define|#
directive|define
name|PAD_CTL_ODT_6
value|(0x6<<8)
end_define

begin_define
define|#
directive|define
name|PAD_CTL_ODT_7
value|(0x7<<8)
end_define

begin_comment
comment|/* Speed Field: */
end_comment

begin_define
define|#
directive|define
name|PAD_CTL_SPEED_RESERVED0
value|(0x0<<6)
end_define

begin_comment
comment|/*   RESERVED */
end_comment

begin_define
define|#
directive|define
name|PAD_CTL_SPEED_50_MHZ
value|(0x1<<6)
end_define

begin_comment
comment|/*   50 MHz */
end_comment

begin_define
define|#
directive|define
name|PAD_CTL_SPEED_100_MHZ
value|(0x2<<6)
end_define

begin_comment
comment|/*   100 MHz */
end_comment

begin_define
define|#
directive|define
name|PAD_CTL_SPEED_200_MHZ
value|(0x3<<6)
end_define

begin_comment
comment|/*   200 MHz */
end_comment

begin_comment
comment|/* Drive Strength Field */
end_comment

begin_define
define|#
directive|define
name|PAD_CTL_DSE_HIZ
value|(0x0<<3)
end_define

begin_comment
comment|/*   HI-Z */
end_comment

begin_define
define|#
directive|define
name|PAD_CTL_DSE_1
value|(0x1<<3)
end_define

begin_define
define|#
directive|define
name|PAD_CTL_DSE_2
value|(0x2<<3)
end_define

begin_define
define|#
directive|define
name|PAD_CTL_DSE_3
value|(0x3<<3)
end_define

begin_define
define|#
directive|define
name|PAD_CTL_DSE_4
value|(0x4<<3)
end_define

begin_define
define|#
directive|define
name|PAD_CTL_DSE_5
value|(0x5<<3)
end_define

begin_define
define|#
directive|define
name|PAD_CTL_DSE_6
value|(0x6<<3)
end_define

begin_define
define|#
directive|define
name|PAD_CTL_DSE_7
value|(0x7<<3)
end_define

begin_define
define|#
directive|define
name|PAD_CTL_SRE
value|(0x1<<0)
end_define

begin_comment
comment|/* Slew rate Field */
end_comment

begin_comment
comment|/*  * Input control  */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_INPUT_CTL
value|0x07b0
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
comment|/*  * MUX& PAD Control  */
end_comment

begin_define
define|#
directive|define
name|MUX_PIN
parameter_list|(
name|name
parameter_list|)
define|\
value|IOMUX_PIN(IOMUXC_SW_MUX_CTL_PAD_##name, \ 	    IOMUXC_SW_PAD_CTL_PAD_##name)
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
comment|/*  * INPUT Control  */
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

begin_comment
comment|/*  * Register names, offset addresses (and reset values for reference)  * from Chapter 36 IOMUX Controller (IOMUXC), IMX6DQRM, Rev.1, 04/2013  *  * General Purpose Registers  */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_GPR0
value|0x0000
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_GPR1
value|0x0004
end_define

begin_comment
comment|/* 0x48400005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_GPR2
value|0x0008
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_GPR3
value|0x000c
end_define

begin_comment
comment|/* 0x01e00000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_GPR4
value|0x0010
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_GPR5
value|0x0014
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_GPR6
value|0x0018
end_define

begin_comment
comment|/* 0x22222222 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_GPR7
value|0x001c
end_define

begin_comment
comment|/* 0x22222222 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_GPR8
value|0x0020
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_GPR9
value|0x0024
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_GPR10
value|0x0028
end_define

begin_comment
comment|/* 0x00003800 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_GPR11
value|0x002c
end_define

begin_comment
comment|/* 0x00003800 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_GPR12
value|0x0030
end_define

begin_comment
comment|/* 0x0f000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_GPR13
value|0x0034
end_define

begin_comment
comment|/* 0x059124c4 */
end_comment

begin_comment
comment|/*  * Pad Mux Registers  */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD2_DATA1
value|0x004c
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD2_DATA2
value|0x0050
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD2_DATA0
value|0x0054
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_RGMII_TXC
value|0x0058
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_RGMII_TD0
value|0x005c
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_RGMII_TD1
value|0x0060
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_RGMII_TD2
value|0x0064
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_RGMII_TD3
value|0x0068
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_RGMII_RX_CTL
value|0x006c
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_RGMII_RD0
value|0x0070
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_RGMII_TX_CTL
value|0x0074
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_RGMII_RD1
value|0x0078
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_RGMII_RD2
value|0x007c
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_RGMII_RD3
value|0x0080
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_RGMII_RXC
value|0x0084
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_ADDR25
value|0x0088
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_EB2_B
value|0x008c
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_DATA16
value|0x0090
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_DATA17
value|0x0094
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_DATA18
value|0x0098
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_DATA19
value|0x009c
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_DATA20
value|0x00a0
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_DATA21
value|0x00a4
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_DATA22
value|0x00a8
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_DATA23
value|0x00ac
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_EB3_B
value|0x00b0
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_DATA24
value|0x00b4
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_DATA25
value|0x00b8
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_DATA26
value|0x00bc
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_DATA27
value|0x00c0
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_DATA28
value|0x00c4
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_DATA29
value|0x00c8
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_DATA30
value|0x00cc
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_DATA31
value|0x00d0
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_ADDR24
value|0x00d4
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_ADDR23
value|0x00d8
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_ADDR22
value|0x00dc
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_ADDR21
value|0x00e0
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_ADDR20
value|0x00e4
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_ADDR19
value|0x00e8
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_ADDR18
value|0x00ec
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_ADDR17
value|0x00f0
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_ADDR16
value|0x00f4
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_CS0_B
value|0x00f8
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_CS1_B
value|0x00fc
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_OE_B
value|0x0100
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_RW
value|0x0104
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_LBA_B
value|0x0108
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_EB0_B
value|0x010c
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_EB1_B
value|0x0110
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_AD00
value|0x0114
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_AD01
value|0x0118
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_AD02
value|0x011c
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_AD03
value|0x0120
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_AD04
value|0x0124
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_AD05
value|0x0128
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_AD06
value|0x012c
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_AD07
value|0x0130
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_AD08
value|0x0134
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_AD09
value|0x0138
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_AD10
value|0x013c
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_AD11
value|0x0140
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_AD12
value|0x0144
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_AD13
value|0x0148
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_AD14
value|0x014c
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_AD15
value|0x0150
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_WAIT_B
value|0x0154
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_EIM_BCLK
value|0x0158
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DI0_DISP_CLK
value|0x015c
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DI0_PIN15
value|0x0160
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DI0_PIN02
value|0x0164
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DI0_PIN03
value|0x0168
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DI0_PIN04
value|0x016c
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA00
value|0x0170
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA01
value|0x0174
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA02
value|0x0178
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA03
value|0x017c
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA04
value|0x0180
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA05
value|0x0184
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA06
value|0x0188
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA07
value|0x018c
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA08
value|0x0190
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA09
value|0x0194
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA10
value|0x0198
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA11
value|0x019c
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA12
value|0x01a0
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA13
value|0x01a4
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA14
value|0x01a8
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA15
value|0x01ac
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA16
value|0x01b0
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA17
value|0x01b4
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA18
value|0x01b8
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA19
value|0x01bc
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA20
value|0x01c0
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA21
value|0x01c4
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA22
value|0x01c8
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA23
value|0x01cc
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_ENET_MDIO
value|0x01d0
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_ENET_REF_CLK
value|0x01d4
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_ENET_RX_ER
value|0x01d8
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_ENET_CRS_DV
value|0x01dc
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_ENET_RX_DATA1
value|0x01e0
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_ENET_RX_DATA0
value|0x01e4
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_ENET_TX_EN
value|0x01e8
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_ENET_TX_DATA1
value|0x01ec
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_ENET_TX_DATA0
value|0x01f0
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_ENET_MDC
value|0x01f4
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_KEY_COL0
value|0x01f8
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_KEY_ROW0
value|0x01fc
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_KEY_COL1
value|0x0200
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_KEY_ROW1
value|0x0204
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_KEY_COL2
value|0x0208
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_KEY_ROW2
value|0x020c
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_KEY_COL3
value|0x0210
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_KEY_ROW3
value|0x0214
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_KEY_COL4
value|0x0218
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_KEY_ROW4
value|0x021c
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_GPIO00
value|0x0220
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_GPIO01
value|0x0224
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_GPIO09
value|0x0228
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_GPIO03
value|0x022c
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_GPIO06
value|0x0230
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_GPIO02
value|0x0234
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_GPIO04
value|0x0238
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_GPIO05
value|0x023c
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_GPIO07
value|0x0240
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_GPIO08
value|0x0244
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_GPIO16
value|0x0248
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_GPIO17
value|0x024c
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_GPIO18
value|0x0250
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_GPIO19
value|0x0254
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI0_PIXCLK
value|0x0258
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI0_HSYNC
value|0x025c
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA_EN
value|0x0260
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI0_VSYNC
value|0x0264
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA04
value|0x0268
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA05
value|0x026c
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA06
value|0x0270
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA07
value|0x0274
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA08
value|0x0278
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA09
value|0x027c
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA10
value|0x0280
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA11
value|0x0284
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA12
value|0x0288
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA13
value|0x028c
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA14
value|0x0290
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA15
value|0x0294
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA16
value|0x0298
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA17
value|0x029c
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA18
value|0x02a0
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA19
value|0x02a4
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD3_DATA7
value|0x02a8
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD3_DATA6
value|0x02ac
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD3_DATA5
value|0x02b0
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD3_DATA4
value|0x02b4
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD3_CMD
value|0x02b8
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD3_CLK
value|0x02bc
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD3_DATA0
value|0x02c0
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD3_DATA1
value|0x02c4
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD3_DATA2
value|0x02c8
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD3_DATA3
value|0x02cc
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD3_RESET
value|0x02d0
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NAND_CLE
value|0x02d4
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NAND_ALE
value|0x02d8
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NAND_WP_B
value|0x02dc
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NAND_READY_B
value|0x02e0
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NAND_CS0_B
value|0x02e4
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NAND_CS1_B
value|0x02e8
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NAND_CS2_B
value|0x02ec
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NAND_CS3_B
value|0x02f0
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD4_CMD
value|0x02f4
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD4_CLK
value|0x02f8
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NAND_DATA00
value|0x02fc
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NAND_DATA01
value|0x0300
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NAND_DATA02
value|0x0304
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NAND_DATA03
value|0x0308
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NAND_DATA04
value|0x030c
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NAND_DATA05
value|0x0310
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NAND_DATA06
value|0x0314
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_NAND_DATA07
value|0x0318
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD4_DATA0
value|0x031c
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD4_DATA1
value|0x0320
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD4_DATA2
value|0x0324
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD4_DATA3
value|0x0328
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD4_DATA4
value|0x032c
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD4_DATA5
value|0x0330
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD4_DATA6
value|0x0334
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD4_DATA7
value|0x0338
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD1_DATA1
value|0x033c
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD1_DATA0
value|0x0340
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD1_DATA3
value|0x0344
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD1_CMD
value|0x0348
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD1_DATA2
value|0x034c
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD1_CLK
value|0x0350
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD2_CLK
value|0x0354
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD2_CMD
value|0x0358
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_MUX_CTL_PAD_SD2_DATA3
value|0x035c
end_define

begin_comment
comment|/* 0x00000005 */
end_comment

begin_comment
comment|/*  * Pad Control registers  */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD2_DATA1
value|0x0360
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD2_DATA2
value|0x0364
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD2_DATA0
value|0x0368
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_RGMII_TXC
value|0x036c
end_define

begin_comment
comment|/* 0x00013030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_RGMII_TD0
value|0x0370
end_define

begin_comment
comment|/* 0x0001b030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_RGMII_TD1
value|0x0374
end_define

begin_comment
comment|/* 0x0001b030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_RGMII_TD2
value|0x0378
end_define

begin_comment
comment|/* 0x0001b030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_RGMII_TD3
value|0x037c
end_define

begin_comment
comment|/* 0x0001b030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_RGMII_RX_CTL
value|0x0380
end_define

begin_comment
comment|/* 0x00013030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_RGMII_RD0
value|0x0384
end_define

begin_comment
comment|/* 0x0001b030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_RGMII_TX_CTL
value|0x0388
end_define

begin_comment
comment|/* 0x00013030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_RGMII_RD1
value|0x038c
end_define

begin_comment
comment|/* 0x0001b030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_RGMII_RD2
value|0x0390
end_define

begin_comment
comment|/* 0x0001b030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_RGMII_RD3
value|0x0394
end_define

begin_comment
comment|/* 0x0001b030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_RGMII_RXC
value|0x0398
end_define

begin_comment
comment|/* 0x00013030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_ADDR25
value|0x039c
end_define

begin_comment
comment|/* 0x0000b0b1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_EB2_B
value|0x03a0
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_DATA16
value|0x03a4
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_DATA17
value|0x03a8
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_DATA18
value|0x03ac
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_DATA19
value|0x03b0
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_DATA20
value|0x03b4
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_DATA21
value|0x03b8
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_DATA22
value|0x03bc
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_DATA23
value|0x03c0
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_EB3_B
value|0x03c4
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_DATA24
value|0x03c8
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_DATA25
value|0x03cc
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_DATA26
value|0x03d0
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_DATA27
value|0x03d4
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_DATA28
value|0x03d8
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_DATA29
value|0x03dc
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_DATA30
value|0x03e0
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_DATA31
value|0x03e4
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_ADDR24
value|0x03e8
end_define

begin_comment
comment|/* 0x0000b0b1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_ADDR23
value|0x03ec
end_define

begin_comment
comment|/* 0x0000b0b1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_ADDR22
value|0x03f0
end_define

begin_comment
comment|/* 0x0000b0b1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_ADDR21
value|0x03f4
end_define

begin_comment
comment|/* 0x0000b0b1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_ADDR20
value|0x03f8
end_define

begin_comment
comment|/* 0x0000b0b1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_ADDR19
value|0x03fc
end_define

begin_comment
comment|/* 0x0000b0b1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_ADDR18
value|0x0400
end_define

begin_comment
comment|/* 0x0000b0b1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_ADDR17
value|0x0404
end_define

begin_comment
comment|/* 0x0000b0b1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_ADDR16
value|0x0408
end_define

begin_comment
comment|/* 0x0000b0b1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_CS0_B
value|0x040c
end_define

begin_comment
comment|/* 0x0000b0b1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_CS1_B
value|0x0410
end_define

begin_comment
comment|/* 0x0000b0b1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_OE_B
value|0x0414
end_define

begin_comment
comment|/* 0x0000b0b1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_RW
value|0x0418
end_define

begin_comment
comment|/* 0x0000b0b1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_LBA_B
value|0x041c
end_define

begin_comment
comment|/* 0x0000b0b1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_EB0_B
value|0x0420
end_define

begin_comment
comment|/* 0x0000b0b1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_EB1_B
value|0x0424
end_define

begin_comment
comment|/* 0x0000b0b1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_AD00
value|0x0428
end_define

begin_comment
comment|/* 0x0000b0b1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_AD01
value|0x042c
end_define

begin_comment
comment|/* 0x0000b0b1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_AD02
value|0x0430
end_define

begin_comment
comment|/* 0x0000b0b1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_AD03
value|0x0434
end_define

begin_comment
comment|/* 0x0000b0b1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_AD04
value|0x0438
end_define

begin_comment
comment|/* 0x0000b0b1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_AD05
value|0x043c
end_define

begin_comment
comment|/* 0x0000b0b1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_AD06
value|0x0440
end_define

begin_comment
comment|/* 0x0000b0b1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_AD07
value|0x0444
end_define

begin_comment
comment|/* 0x0000b0b1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_AD08
value|0x0448
end_define

begin_comment
comment|/* 0x0000b0b1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_AD09
value|0x044c
end_define

begin_comment
comment|/* 0x0000b0b1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_AD10
value|0x0450
end_define

begin_comment
comment|/* 0x0000b0b1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_AD11
value|0x0454
end_define

begin_comment
comment|/* 0x0000b0b1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_AD12
value|0x0458
end_define

begin_comment
comment|/* 0x0000b0b1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_AD13
value|0x045c
end_define

begin_comment
comment|/* 0x0000b0b1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_AD14
value|0x0460
end_define

begin_comment
comment|/* 0x0000b0b1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_AD15
value|0x0464
end_define

begin_comment
comment|/* 0x0000b0b1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_WAIT_B
value|0x0468
end_define

begin_comment
comment|/* 0x0000b060 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_EIM_BCLK
value|0x046c
end_define

begin_comment
comment|/* 0x0000b0b1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DI0_DISP_CLK
value|0x0470
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DI0_PIN15
value|0x0474
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DI0_PIN02
value|0x0478
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DI0_PIN03
value|0x047c
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DI0_PIN04
value|0x0480
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA00
value|0x0484
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA01
value|0x0488
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA02
value|0x048c
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA03
value|0x0490
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA04
value|0x0494
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA05
value|0x0498
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA06
value|0x049c
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA07
value|0x04a0
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA08
value|0x04a4
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA09
value|0x04a8
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA10
value|0x04ac
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA11
value|0x04b0
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA12
value|0x04b4
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA13
value|0x04b8
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA14
value|0x04bc
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA15
value|0x04c0
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA16
value|0x04c4
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA17
value|0x04c8
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA18
value|0x04cc
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA19
value|0x04d0
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA20
value|0x04d4
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA21
value|0x04d8
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA22
value|0x04dc
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA23
value|0x04e0
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_ENET_MDIO
value|0x04e4
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_ENET_REF_CLK
value|0x04e8
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_ENET_RX_ER
value|0x04ec
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_ENET_CRS_DV
value|0x04f0
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_ENET_RX_DATA1
value|0x04f4
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_ENET_RX_DATA0
value|0x04f8
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_ENET_TX_EN
value|0x04fc
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_ENET_TX_DATA1
value|0x0500
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_ENET_TX_DATA0
value|0x0504
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_ENET_MDC
value|0x0508
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS5_P
value|0x050c
end_define

begin_comment
comment|/* 0x00002030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM5
value|0x0510
end_define

begin_comment
comment|/* 0x00008030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM4
value|0x0514
end_define

begin_comment
comment|/* 0x00008030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS4_P
value|0x0518
end_define

begin_comment
comment|/* 0x00002030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS3_P
value|0x051c
end_define

begin_comment
comment|/* 0x00002030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM3
value|0x0520
end_define

begin_comment
comment|/* 0x00008030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS2_P
value|0x0524
end_define

begin_comment
comment|/* 0x00002030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM2
value|0x0528
end_define

begin_comment
comment|/* 0x00008030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_ADDR00
value|0x052c
end_define

begin_comment
comment|/* 0x00008000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_ADDR01
value|0x0530
end_define

begin_comment
comment|/* 0x00008000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_ADDR02
value|0x0534
end_define

begin_comment
comment|/* 0x00008000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_ADDR03
value|0x0538
end_define

begin_comment
comment|/* 0x00008000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_ADDR04
value|0x053c
end_define

begin_comment
comment|/* 0x00008000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_ADDR05
value|0x0540
end_define

begin_comment
comment|/* 0x00008000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_ADDR06
value|0x0544
end_define

begin_comment
comment|/* 0x00008000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_ADDR07
value|0x0548
end_define

begin_comment
comment|/* 0x00008000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_ADDR08
value|0x054c
end_define

begin_comment
comment|/* 0x00008000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_ADDR09
value|0x0550
end_define

begin_comment
comment|/* 0x00008000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_ADDR10
value|0x0554
end_define

begin_comment
comment|/* 0x00008000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_ADDR11
value|0x0558
end_define

begin_comment
comment|/* 0x00008000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_ADDR12
value|0x055c
end_define

begin_comment
comment|/* 0x00008000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_ADDR13
value|0x0560
end_define

begin_comment
comment|/* 0x00008000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_ADDR14
value|0x0564
end_define

begin_comment
comment|/* 0x00008000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_ADDR15
value|0x0568
end_define

begin_comment
comment|/* 0x00008000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_CAS_B
value|0x056c
end_define

begin_comment
comment|/* 0x00008030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_CS0_B
value|0x0570
end_define

begin_comment
comment|/* 0x00008000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_CS1_B
value|0x0574
end_define

begin_comment
comment|/* 0x00008000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_RAS_B
value|0x0578
end_define

begin_comment
comment|/* 0x00008030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_RESET
value|0x057c
end_define

begin_comment
comment|/* 0x00083030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_SDBA0
value|0x0580
end_define

begin_comment
comment|/* 0x00008000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_SDBA1
value|0x0584
end_define

begin_comment
comment|/* 0x00008000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_SDCLK0_P
value|0x0588
end_define

begin_comment
comment|/* 0x00008030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_SDBA2
value|0x058c
end_define

begin_comment
comment|/* 0x0000b000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_SDCKE0
value|0x0590
end_define

begin_comment
comment|/* 0x00003000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_SDCLK1_P
value|0x0594
end_define

begin_comment
comment|/* 0x00008030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_SDCKE1
value|0x0598
end_define

begin_comment
comment|/* 0x00003000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_ODT0
value|0x059c
end_define

begin_comment
comment|/* 0x00003030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_ODT1
value|0x05a0
end_define

begin_comment
comment|/* 0x00003030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_SDWE_B
value|0x05a4
end_define

begin_comment
comment|/* 0x00008000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS0_P
value|0x05a8
end_define

begin_comment
comment|/* 0x00002030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM0
value|0x05ac
end_define

begin_comment
comment|/* 0x00008030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS1_P
value|0x05b0
end_define

begin_comment
comment|/* 0x00002030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM1
value|0x05b4
end_define

begin_comment
comment|/* 0x00008030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS6_P
value|0x05b8
end_define

begin_comment
comment|/* 0x00002030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM6
value|0x05bc
end_define

begin_comment
comment|/* 0x00008030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_SDQS7_P
value|0x05c0
end_define

begin_comment
comment|/* 0x00002030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_DRAM_DQM7
value|0x05c4
end_define

begin_comment
comment|/* 0x00008030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_KEY_COL0
value|0x05c8
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_KEY_ROW0
value|0x05cc
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_KEY_COL1
value|0x05d0
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_KEY_ROW1
value|0x05d4
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_KEY_COL2
value|0x05d8
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_KEY_ROW2
value|0x05dc
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_KEY_COL3
value|0x05e0
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_KEY_ROW3
value|0x05e4
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_KEY_COL4
value|0x05e8
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_KEY_ROW4
value|0x05ec
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_GPIO00
value|0x05f0
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_GPIO01
value|0x05f4
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_GPIO09
value|0x05f8
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_GPIO03
value|0x05fc
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_GPIO06
value|0x0600
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_GPIO02
value|0x0604
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_GPIO04
value|0x0608
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_GPIO05
value|0x060c
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_GPIO07
value|0x0610
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_GPIO08
value|0x0614
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_GPIO16
value|0x0618
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_GPIO17
value|0x061c
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_GPIO18
value|0x0620
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_GPIO19
value|0x0624
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI0_PIXCLK
value|0x0628
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI0_HSYNC
value|0x062c
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA_EN
value|0x0630
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI0_VSYNC
value|0x0634
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA04
value|0x0638
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA05
value|0x063c
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA06
value|0x0640
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA07
value|0x0644
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA08
value|0x0648
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA09
value|0x064c
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA10
value|0x0650
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA11
value|0x0654
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA12
value|0x0658
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA13
value|0x065c
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA14
value|0x0660
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA15
value|0x0664
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA16
value|0x0668
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA17
value|0x066c
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA18
value|0x0670
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA19
value|0x0674
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_JTAG_TMS
value|0x0678
end_define

begin_comment
comment|/* 0x00007060 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_JTAG_MOD
value|0x067c
end_define

begin_comment
comment|/* 0x0000b060 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_JTAG_TRSTB
value|0x0680
end_define

begin_comment
comment|/* 0x00007060 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_JTAG_TDI
value|0x0684
end_define

begin_comment
comment|/* 0x00007060 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_JTAG_TCK
value|0x0688
end_define

begin_comment
comment|/* 0x00007060 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_JTAG_TDO
value|0x068c
end_define

begin_comment
comment|/* 0x000090b1 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD3_DATA7
value|0x0690
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD3_DATA6
value|0x0694
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD3_DATA5
value|0x0698
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD3_DATA4
value|0x069c
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD3_CMD
value|0x06a0
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD3_CLK
value|0x06a4
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD3_DATA0
value|0x06a8
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD3_DATA1
value|0x06ac
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD3_DATA2
value|0x06b0
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD3_DATA3
value|0x06b4
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD3_RESET
value|0x06b8
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NAND_CLE
value|0x06bc
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NAND_ALE
value|0x06c0
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NAND_WP_B
value|0x06c4
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NAND_READY_B
value|0x06c8
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NAND_CS0_B
value|0x06cc
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NAND_CS1_B
value|0x06d0
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NAND_CS2_B
value|0x06d4
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NAND_CS3_B
value|0x06d8
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD4_CMD
value|0x06dc
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD4_CLK
value|0x06e0
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NAND_DATA00
value|0x06e4
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NAND_DATA01
value|0x06e8
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NAND_DATA02
value|0x06ec
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NAND_DATA03
value|0x06f0
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NAND_DATA04
value|0x06f4
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NAND_DATA05
value|0x06f8
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NAND_DATA06
value|0x06fc
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_NAND_DATA07
value|0x0700
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD4_DATA0
value|0x0704
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD4_DATA1
value|0x0708
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD4_DATA2
value|0x070c
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD4_DATA3
value|0x0710
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD4_DATA4
value|0x0714
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD4_DATA5
value|0x0718
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD4_DATA6
value|0x071c
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD4_DATA7
value|0x0720
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD1_DATA1
value|0x0724
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD1_DATA0
value|0x0728
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD1_DATA3
value|0x072c
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD1_CMD
value|0x0730
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD1_DATA2
value|0x0734
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD1_CLK
value|0x0738
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD2_CLK
value|0x073c
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD2_CMD
value|0x0740
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_PAD_SD2_DATA3
value|0x0744
end_define

begin_comment
comment|/* 0x0001b0b0 */
end_comment

begin_comment
comment|/*  * Pad Group Control Registers  */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_B7DS
value|0x0748
end_define

begin_comment
comment|/* 0x00000030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_ADDDS
value|0x074c
end_define

begin_comment
comment|/* 0x00000030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_DDRMODE_CTL
value|0x0750
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_TERM_CTL0
value|0x0754
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_DDRPKE
value|0x0758
end_define

begin_comment
comment|/* 0x00001000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_TERM_CTL1
value|0x075c
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_TERM_CTL2
value|0x0760
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_TERM_CTL3
value|0x0764
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_DDRPK
value|0x0768
end_define

begin_comment
comment|/* 0x00002000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_TERM_CTL4
value|0x076c
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_DDRHYS
value|0x0770
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_DDRMODE
value|0x0774
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_TERM_CTL5
value|0x0778
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_TERM_CTL6
value|0x077c
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_TERM_CTL7
value|0x0780
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_B0DS
value|0x0784
end_define

begin_comment
comment|/* 0x00000030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_B1DS
value|0x0788
end_define

begin_comment
comment|/* 0x00000030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_CTLDS
value|0x078c
end_define

begin_comment
comment|/* 0x00000030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII
value|0x0790
end_define

begin_comment
comment|/* 0x00080000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_B2DS
value|0x0794
end_define

begin_comment
comment|/* 0x00000030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE
value|0x0798
end_define

begin_comment
comment|/* 0x00080000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_B3DS
value|0x079c
end_define

begin_comment
comment|/* 0x00000030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_B4DS
value|0x07a0
end_define

begin_comment
comment|/* 0x00000030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_B5DS
value|0x07a4
end_define

begin_comment
comment|/* 0x00000030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_B6DS
value|0x07a8
end_define

begin_comment
comment|/* 0x00000030 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SW_PAD_CTL_GRP_RGMII_TERM
value|0x07ac
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_comment
comment|/*  * Select Input Registers  */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ASRC_ASRCK_CLOCK_6_SELECT_INPUT
value|0x07b0
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_AUD4_INPUT_DA_AMX_SELECT_INPUT
value|0x07b4
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_AUD4_INPUT_DB_AMX_SELECT_INPUT
value|0x07b8
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_AUD4_INPUT_RXCLK_AMX_SELECT_INPUT
value|0x07bc
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_AUD4_INPUT_RXFS_AMX_SELECT_INPUT
value|0x07c0
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_AUD4_INPUT_TXCLK_AMX_SELECT_INPUT
value|0x07c4
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_AUD4_INPUT_TXFS_AMX_SELECT_INPUT
value|0x07c8
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_AUD5_INPUT_DA_AMX_SELECT_INPUT
value|0x07cc
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_AUD5_INPUT_DB_AMX_SELECT_INPUT
value|0x07d0
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_AUD5_INPUT_RXCLK_AMX_SELECT_INPUT
value|0x07d4
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_AUD5_INPUT_RXFS_AMX_SELECT_INPUT
value|0x07d8
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_AUD5_INPUT_TXCLK_AMX_SELECT_INPUT
value|0x07dc
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_AUD5_INPUT_TXFS_AMX_SELECT_INPUT
value|0x07e0
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_FLEXCAN1_RX_SELECT_INPUT
value|0x07e4
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_FLEXCAN2_RX_SELECT_INPUT
value|0x07e8
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_CCM_PMIC_READY_SELECT_INPUT
value|0x07f0
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ECSPI1_CSPI_CLK_IN_SELECT_INPUT
value|0x07f4
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ECSPI1_MISO_SELECT_INPUT
value|0x07f8
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ECSPI1_MOSI_SELECT_INPUT
value|0x07fc
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ECSPI1_SS0_SELECT_INPUT
value|0x0800
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ECSPI1_SS1_SELECT_INPUT
value|0x0804
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ECSPI1_SS2_SELECT_INPUT
value|0x0808
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ECSPI1_SS3_SELECT_INPUT
value|0x080c
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ECSPI2_CSPI_CLK_IN_SELECT_INPUT
value|0x0810
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ECSPI2_MISO_SELECT_INPUT
value|0x0814
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ECSPI2_MOSI_SELECT_INPUT
value|0x0818
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ECSPI2_SS0_SELECT_INPUT
value|0x081c
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ECSPI2_SS1_SELECT_INPUT
value|0x0820
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ECSPI4_SS0_SELECT_INPUT
value|0x0824
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ECSPI5_CSPI_CLK_IN_SELECT_INPUT
value|0x0828
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ECSPI5_MISO_SELECT_INPUT
value|0x082c
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ECSPI5_MOSI_SELECT_INPUT
value|0x0830
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ECSPI5_SS0_SELECT_INPUT
value|0x0834
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ECSPI5_SS1_SELECT_INPUT
value|0x0838
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ENET_REF_CLK_SELECT_INPUT
value|0x083c
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ENET_MAC0_MDIO_SELECT_INPUT
value|0x0840
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ENET_MAC0_RX_CLK_SELECT_INPUT
value|0x0844
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ENET_MAC0_RX_DATA0_SELECT_INPUT
value|0x0848
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ENET_MAC0_RX_DATA1_SELECT_INPUT
value|0x084c
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ENET_MAC0_RX_DATA2_SELECT_INPUT
value|0x0850
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ENET_MAC0_RX_DATA3_SELECT_INPUT
value|0x0854
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ENET_MAC0_RX_EN_SELECT_INPUT
value|0x0858
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ESAI_RX_FS_SELECT_INPUT
value|0x085c
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ESAI_TX_FS_SELECT_INPUT
value|0x0860
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ESAI_RX_HF_CLK_SELECT_INPUT
value|0x0864
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ESAI_TX_HF_CLK_SELECT_INPUT
value|0x0868
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ESAI_RX_CLK_SELECT_INPUT
value|0x086c
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ESAI_TX_CLK_SELECT_INPUT
value|0x0870
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ESAI_SDO0_SELECT_INPUT
value|0x0874
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ESAI_SDO1_SELECT_INPUT
value|0x0878
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ESAI_SDO2_SDI3_SELECT_INPUT
value|0x087c
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ESAI_SDO3_SDI2_SELECT_INPUT
value|0x0880
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ESAI_SDO4_SDI1_SELECT_INPUT
value|0x0884
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_ESAI_SDO5_SDI0_SELECT_INPUT
value|0x0888
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_HDMI_ICECIN_SELECT_INPUT
value|0x088c
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_HDMI_II2C_CLKIN_SELECT_INPUT
value|0x0890
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_HDMI_II2C_DATAIN_SELECT_INPUT
value|0x0894
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_I2C1_SCL_IN_SELECT_INPUT
value|0x0898
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_I2C1_SDA_IN_SELECT_INPUT
value|0x089c
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_I2C2_SCL_IN_SELECT_INPUT
value|0x08a0
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_I2C2_SDA_IN_SELECT_INPUT
value|0x08a4
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_I2C3_SCL_IN_SELECT_INPUT
value|0x08a8
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_I2C3_SDA_IN_SELECT_INPUT
value|0x08ac
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_IPU2_SENS1_DATA10_SELECT_INPUT
value|0x08b0
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_IPU2_SENS1_DATA11_SELECT_INPUT
value|0x08b4
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_IPU2_SENS1_DATA12_SELECT_INPUT
value|0x08b8
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_IPU2_SENS1_DATA13_SELECT_INPUT
value|0x08bc
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_IPU2_SENS1_DATA14_SELECT_INPUT
value|0x08c0
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_IPU2_SENS1_DATA15_SELECT_INPUT
value|0x08c4
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_IPU2_SENS1_DATA16_SELECT_INPUT
value|0x08c8
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_IPU2_SENS1_DATA17_SELECT_INPUT
value|0x08cc
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_IPU2_SENS1_DATA18_SELECT_INPUT
value|0x08d0
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_IPU2_SENS1_DATA19_SELECT_INPUT
value|0x08d4
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_IPU2_SENS1_DATA_EN_SELECT_INPUT
value|0x08d8
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_IPU2_SENS1_HSYNC_SELECT_INPUT
value|0x08dc
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_IPU2_SENS1_PIX_CLK_SELECT_INPUT
value|0x08e0
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_IPU2_SENS1_VSYNC_SELECT_INPUT
value|0x08e4
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_KEY_COL5_SELECT_INPUT
value|0x08e8
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_KEY_COL6_SELECT_INPUT
value|0x08ec
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_KEY_COL7_SELECT_INPUT
value|0x08f0
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_KEY_ROW5_SELECT_INPUT
value|0x08f4
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_KEY_ROW6_SELECT_INPUT
value|0x08f8
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_KEY_ROW7_SELECT_INPUT
value|0x08fc
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_MLB_MLB_CLK_IN_SELECT_INPUT
value|0x0900
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_MLB_MLB_DATA_IN_SELECT_INPUT
value|0x0904
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_MLB_MLB_SIG_IN_SELECT_INPUT
value|0x0908
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SDMA_EVENTS14_SELECT_INPUT
value|0x090c
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SDMA_EVENTS15_SELECT_INPUT
value|0x0910
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SPDIF_SPDIF_IN1_SELECT_INPUT
value|0x0914
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_SPDIF_TX_CLK2_SELECT_INPUT
value|0x0918
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_UART1_UART_RTS_B_SELECT_INPUT
value|0x091c
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_UART1_UART_RX_DATA_SELECT_INPUT
value|0x0920
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_UART2_UART_RTS_B_SELECT_INPUT
value|0x0924
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_UART2_UART_RX_DATA_SELECT_INPUT
value|0x0928
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_UART3_UART_RTS_B_SELECT_INPUT
value|0x092c
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_UART3_UART_RX_DATA_SELECT_INPUT
value|0x0930
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_UART4_UART_RTS_B_SELECT_INPUT
value|0x0934
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_UART4_UART_RX_DATA_SELECT_INPUT
value|0x0938
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_UART5_UART_RTS_B_SELECT_INPUT
value|0x093c
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_UART5_UART_RX_DATA_SELECT_INPUT
value|0x0940
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_USB_OTG_OC_SELECT_INPUT
value|0x0944
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_USB_H1_OC_SELECT_INPUT
value|0x0948
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_define
define|#
directive|define
name|IOMUXC_USDHC1_WP_ON_SELECT_INPUT
value|0x094c
end_define

begin_comment
comment|/* 0x00000000 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IMX6_IOMUXREG_H */
end_comment

end_unit

