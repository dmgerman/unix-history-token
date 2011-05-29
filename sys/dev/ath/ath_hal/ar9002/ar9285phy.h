begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2008-2010 Atheros Communications Inc.  * Copyright (c) 2010-2011 Adrian Chadd, Xenion Pty Ltd.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ATH_AR9285PHY_H__
end_ifndef

begin_define
define|#
directive|define
name|__ATH_AR9285PHY_H__
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G1
value|0x7820
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G1_ENPACAL
value|0x00000800
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G1_ENPACAL_S
value|11
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G1_PDPADRV1
value|0x02000000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G1_PDPADRV1_S
value|25
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G1_PDPADRV2
value|0x01000000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G1_PDPADRV2_S
value|24
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G1_PDPAOUT
value|0x00800000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G1_PDPAOUT_S
value|23
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G2
value|0x7824
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G2_OFFCAL
value|0x00001000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G2_OFFCAL_S
value|12
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3
value|0x7828
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_PDVCCOMP
value|0x02000000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_PDVCCOMP_S
value|25
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_0
value|0x00E00000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_0_S
value|21
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_1
value|0x001C0000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_1_S
value|18
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_2
value|0x00038000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_2_S
value|15
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_3
value|0x00007000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_3_S
value|12
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_4
value|0x00000E00
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_4_S
value|9
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_DB1_0
value|0x000001C0
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_DB1_0_S
value|6
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_DB1_1
value|0x00000038
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_DB1_1_S
value|3
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_DB1_2
value|0x00000007
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_DB1_2_S
value|0
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4
value|0x782C
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB1_3
value|0xE0000000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB1_3_S
value|29
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB1_4
value|0x1C000000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB1_4_S
value|26
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_0
value|0x03800000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_0_S
value|23
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_1
value|0x00700000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_1_S
value|20
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_2
value|0x000E0000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_2_S
value|17
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_3
value|0x0001C000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_3_S
value|14
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_4
value|0x00003800
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_4_S
value|11
end_define

begin_define
define|#
directive|define
name|AR9285_RF2G5
value|0x7830
end_define

begin_define
define|#
directive|define
name|AR9285_RF2G5_IC50TX
value|0xfffff8ff
end_define

begin_define
define|#
directive|define
name|AR9285_RF2G5_IC50TX_SET
value|0x00000400
end_define

begin_define
define|#
directive|define
name|AR9285_RF2G5_IC50TX_XE_SET
value|0x00000500
end_define

begin_define
define|#
directive|define
name|AR9285_RF2G5_IC50TX_CLEAR
value|0x00000700
end_define

begin_define
define|#
directive|define
name|AR9285_RF2G5_IC50TX_CLEAR_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_PWRCTRL_TX_GAIN_TAB_MAX
value|0x0007E000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_PWRCTRL_TX_GAIN_TAB_MAX_S
value|13
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_GAIN_CLC
value|0x0000001E
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_GAIN_CLC_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_GAIN
value|0x0007F000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_GAIN_S
value|12
end_define

begin_define
define|#
directive|define
name|AR_PHY_CLC_TBL1
value|0xa35c
end_define

begin_define
define|#
directive|define
name|AR_PHY_CLC_I0
value|0x07ff0000
end_define

begin_define
define|#
directive|define
name|AR_PHY_CLC_I0_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_PHY_CLC_Q0
value|0x0000ffd0
end_define

begin_define
define|#
directive|define
name|AR_PHY_CLC_Q0_S
value|5
end_define

begin_define
define|#
directive|define
name|AR_PHY_MULTICHAIN_GAIN_CTL
value|0x99ac
end_define

begin_define
define|#
directive|define
name|AR_PHY_9285_FAST_DIV_BIAS
value|0x00007E00
end_define

begin_define
define|#
directive|define
name|AR_PHY_9285_FAST_DIV_BIAS_S
value|9
end_define

begin_define
define|#
directive|define
name|AR_PHY_9285_ANT_DIV_CTL_ALL
value|0x7f000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_9285_ANT_DIV_CTL
value|0x01000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_9285_ANT_DIV_CTL_S
value|24
end_define

begin_define
define|#
directive|define
name|AR_PHY_9285_ANT_DIV_ALT_LNACONF
value|0x06000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_9285_ANT_DIV_ALT_LNACONF_S
value|25
end_define

begin_define
define|#
directive|define
name|AR_PHY_9285_ANT_DIV_MAIN_LNACONF
value|0x18000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_9285_ANT_DIV_MAIN_LNACONF_S
value|27
end_define

begin_define
define|#
directive|define
name|AR_PHY_9285_ANT_DIV_ALT_GAINTB
value|0x20000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_9285_ANT_DIV_ALT_GAINTB_S
value|29
end_define

begin_define
define|#
directive|define
name|AR_PHY_9285_ANT_DIV_MAIN_GAINTB
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_9285_ANT_DIV_MAIN_GAINTB_S
value|30
end_define

begin_define
define|#
directive|define
name|AR_PHY_9285_ANT_DIV_LNA1
value|2
end_define

begin_define
define|#
directive|define
name|AR_PHY_9285_ANT_DIV_LNA2
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_9285_ANT_DIV_LNA1_PLUS_LNA2
value|3
end_define

begin_define
define|#
directive|define
name|AR_PHY_9285_ANT_DIV_LNA1_MINUS_LNA2
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_9285_ANT_DIV_GAINTB_0
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_9285_ANT_DIV_GAINTB_1
value|1
end_define

begin_comment
comment|/* for AR_PHY_CCK_DETECT */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_CCK_DETECT_ANT_SWITCH_TIME
value|0x00001FC0
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCK_DETECT_ANT_SWITCH_TIME_S
value|6
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCK_DETECT_BB_ENABLE_ANT_FAST_DIV
value|0x2000
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCK_DETECT_BB_ENABLE_ANT_FAST_DIV_S
value|13
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

