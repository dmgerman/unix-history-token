begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008, Pyun YongHyeon  * All rights reserved.  *                * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:               * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.    * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_MII_JMPHYREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_MII_JMPHYREG_H_
end_define

begin_comment
comment|/*  * Registers for the JMicron JMC250 Gigabit PHY.  */
end_comment

begin_comment
comment|/* PHY specific status register. */
end_comment

begin_define
define|#
directive|define
name|JMPHY_SSR
value|0x11
end_define

begin_define
define|#
directive|define
name|JMPHY_SSR_SPEED_1000
value|0x8000
end_define

begin_define
define|#
directive|define
name|JMPHY_SSR_SPEED_100
value|0x4000
end_define

begin_define
define|#
directive|define
name|JMPHY_SSR_SPEED_10
value|0x0000
end_define

begin_define
define|#
directive|define
name|JMPHY_SSR_SPEED_MASK
value|0xC000
end_define

begin_define
define|#
directive|define
name|JMPHY_SSR_DUPLEX
value|0x2000
end_define

begin_define
define|#
directive|define
name|JMPHY_SSR_SPD_DPLX_RESOLVED
value|0x0800
end_define

begin_define
define|#
directive|define
name|JMPHY_SSR_LINK_UP
value|0x0400
end_define

begin_define
define|#
directive|define
name|JMPHY_SSR_MDI_XOVER
value|0x0040
end_define

begin_define
define|#
directive|define
name|JMPHY_SSR_INV_POLARITY
value|0x0002
end_define

begin_comment
comment|/* PHY specific cable length status register. */
end_comment

begin_define
define|#
directive|define
name|JMPHY_SCL
value|0x17
end_define

begin_define
define|#
directive|define
name|JMPHY_SCL_CHAN_D_MASK
value|0xF000
end_define

begin_define
define|#
directive|define
name|JMPHY_SCL_CHAN_C_MASK
value|0x0F00
end_define

begin_define
define|#
directive|define
name|JMPHY_SCL_CHAN_B_MASK
value|0x00F0
end_define

begin_define
define|#
directive|define
name|JMPHY_SCL_CHAN_A_MASK
value|0x000F
end_define

begin_define
define|#
directive|define
name|JMPHY_SCL_LEN_35
value|0
end_define

begin_define
define|#
directive|define
name|JMPHY_SCL_LEN_40
value|1
end_define

begin_define
define|#
directive|define
name|JMPHY_SCL_LEN_50
value|2
end_define

begin_define
define|#
directive|define
name|JMPHY_SCL_LEN_60
value|3
end_define

begin_define
define|#
directive|define
name|JMPHY_SCL_LEN_70
value|4
end_define

begin_define
define|#
directive|define
name|JMPHY_SCL_LEN_80
value|5
end_define

begin_define
define|#
directive|define
name|JMPHY_SCL_LEN_90
value|6
end_define

begin_define
define|#
directive|define
name|JMPHY_SCL_LEN_100
value|7
end_define

begin_define
define|#
directive|define
name|JMPHY_SCL_LEN_110
value|8
end_define

begin_define
define|#
directive|define
name|JMPHY_SCL_LEN_120
value|9
end_define

begin_define
define|#
directive|define
name|JMPHY_SCL_LEN_130
value|10
end_define

begin_define
define|#
directive|define
name|JMPHY_SCL_LEN_140
value|11
end_define

begin_define
define|#
directive|define
name|JMPHY_SCL_LEN_150
value|12
end_define

begin_define
define|#
directive|define
name|JMPHY_SCL_LEN_160
value|13
end_define

begin_define
define|#
directive|define
name|JMPHY_SCL_LEN_170
value|14
end_define

begin_define
define|#
directive|define
name|JMPHY_SCL_RSVD
value|15
end_define

begin_comment
comment|/* PHY specific LED control register 1. */
end_comment

begin_define
define|#
directive|define
name|JMPHY_LED_CTL1
value|0x18
end_define

begin_define
define|#
directive|define
name|JMPHY_LED_BLINK_42MS
value|0x0000
end_define

begin_define
define|#
directive|define
name|JMPHY_LED_BLINK_84MS
value|0x2000
end_define

begin_define
define|#
directive|define
name|JMPHY_LED_BLINK_170MS
value|0x4000
end_define

begin_define
define|#
directive|define
name|JMPHY_LED_BLINK_340MS
value|0x6000
end_define

begin_define
define|#
directive|define
name|JMPHY_LED_BLINK_670MS
value|0x8000
end_define

begin_define
define|#
directive|define
name|JMPHY_LED_BLINK_MASK
value|0xE000
end_define

begin_define
define|#
directive|define
name|JMPHY_LED_FLP_GAP_MASK
value|0x1F00
end_define

begin_define
define|#
directive|define
name|JMPHY_LED_FLP_GAP_DEFULT
value|0x1000
end_define

begin_define
define|#
directive|define
name|JMPHY_LED2_POLARITY_MASK
value|0x0030
end_define

begin_define
define|#
directive|define
name|JMPHY_LED1_POLARITY_MASK
value|0x000C
end_define

begin_define
define|#
directive|define
name|JMPHY_LED0_POLARITY_MASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|JMPHY_LED_ON_LO_OFF_HI
value|0
end_define

begin_define
define|#
directive|define
name|JMPHY_LED_ON_HI_OFF_HI
value|1
end_define

begin_define
define|#
directive|define
name|JMPHY_LED_ON_LO_OFF_TS
value|2
end_define

begin_define
define|#
directive|define
name|JMPHY_LED_ON_HI_OFF_TS
value|3
end_define

begin_comment
comment|/* PHY specific LED control register 2. */
end_comment

begin_define
define|#
directive|define
name|JMPHY_LED_CTL2
value|0x19
end_define

begin_define
define|#
directive|define
name|JMPHY_LED_NO_STRETCH
value|0x0000
end_define

begin_define
define|#
directive|define
name|JMPHY_LED_STRETCH_42MS
value|0x2000
end_define

begin_define
define|#
directive|define
name|JMPHY_LED_STRETCH_84MS
value|0x4000
end_define

begin_define
define|#
directive|define
name|JMPHY_LED_STRETCH_170MS
value|0x6000
end_define

begin_define
define|#
directive|define
name|JMPHY_LED_STRETCH_340MS
value|0x8000
end_define

begin_define
define|#
directive|define
name|JMPHY_LED_STRETCH_670MS
value|0xB000
end_define

begin_define
define|#
directive|define
name|JMPHY_LED_STRETCH_1300MS
value|0xC000
end_define

begin_define
define|#
directive|define
name|JMPHY_LED_STRETCH_2700MS
value|0xE000
end_define

begin_define
define|#
directive|define
name|JMPHY_LED2_MODE_MASK
value|0x0F00
end_define

begin_define
define|#
directive|define
name|JMPHY_LED1_MODE_MASK
value|0x00F0
end_define

begin_define
define|#
directive|define
name|JMPHY_LED0_MODE_MASK
value|0x000F
end_define

begin_comment
comment|/* PHY specific test mode control register. */
end_comment

begin_define
define|#
directive|define
name|JMPHY_TMCTL
value|0x1A
end_define

begin_define
define|#
directive|define
name|JMPHY_TMCTL_SLEEP_ENB
value|0x1000
end_define

begin_comment
comment|/* PHY specific configuration register. */
end_comment

begin_define
define|#
directive|define
name|JMPHY_SPEC_ADDR
value|0x1E
end_define

begin_define
define|#
directive|define
name|JMPHY_SPEC_ADDR_READ
value|0x4000
end_define

begin_define
define|#
directive|define
name|JMPHY_SPEC_ADDR_WRITE
value|0x8000
end_define

begin_define
define|#
directive|define
name|JMPHY_SPEC_DATA
value|0x1F
end_define

begin_define
define|#
directive|define
name|JMPHY_EXT_COMM_2
value|0x32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_MII_JMPHYREG_H_ */
end_comment

end_unit

