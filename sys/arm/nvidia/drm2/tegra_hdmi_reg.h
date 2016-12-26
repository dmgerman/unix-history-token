begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 1992-2016 Michal Meloun  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TEGRA_HDMI_REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_TEGRA_HDMI_REG_H_
end_define

begin_comment
comment|/*  * !!! WARNING !!!  * Tegra manual uses registers index (and not register addreses).  * We follow the TRM notation and index is converted to offset in  * WR4 / RD4 macros  */
end_comment

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_STATE0
value|0x001
end_define

begin_define
define|#
directive|define
name|SOR_STATE0_UPDATE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_STATE1
value|0x002
end_define

begin_define
define|#
directive|define
name|SOR_STATE1_ATTACHED
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|SOR_STATE1_ASY_ORMODE_NORMAL
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SOR_STATE1_ASY_HEAD_OPMODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 0)
end_define

begin_define
define|#
directive|define
name|ASY_HEAD_OPMODE_SLEEP
value|0
end_define

begin_define
define|#
directive|define
name|ASY_HEAD_OPMODE_SNOOZE
value|1
end_define

begin_define
define|#
directive|define
name|ASY_HEAD_OPMODE_AWAKE
value|2
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_STATE2
value|0x003
end_define

begin_define
define|#
directive|define
name|SOR_STATE2_ASY_DEPOL_NEG
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|SOR_STATE2_ASY_VSYNCPOL_NEG
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|SOR_STATE2_ASY_HSYNCPOL_NEG
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|SOR_STATE2_ASY_PROTOCOL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 8)
end_define

begin_define
define|#
directive|define
name|ASY_PROTOCOL_SINGLE_TMDS_A
value|1
end_define

begin_define
define|#
directive|define
name|ASY_PROTOCOL_CUSTOM
value|15
end_define

begin_define
define|#
directive|define
name|SOR_STATE2_ASY_CRCMODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<<  6)
end_define

begin_define
define|#
directive|define
name|ASY_CRCMODE_ACTIVE
value|0
end_define

begin_define
define|#
directive|define
name|ASY_CRCMODE_COMPLETE
value|1
end_define

begin_define
define|#
directive|define
name|ASY_CRCMODE_NON_ACTIVE
value|2
end_define

begin_define
define|#
directive|define
name|SOR_STATE2_ASY_SUBOWNER
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<<  4)
end_define

begin_define
define|#
directive|define
name|ASY_SUBOWNER_NONE
value|0
end_define

begin_define
define|#
directive|define
name|ASY_SUBOWNER_SUBHEAD0
value|1
end_define

begin_define
define|#
directive|define
name|ASY_SUBOWNER_SUBHEAD1
value|2
end_define

begin_define
define|#
directive|define
name|SUBOWNER_BOTH
value|3
end_define

begin_define
define|#
directive|define
name|SOR_STATE2_ASY_OWNER
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<<  0)
end_define

begin_define
define|#
directive|define
name|ASY_OWNER_NONE
value|0
end_define

begin_define
define|#
directive|define
name|ASY_OWNER_HEAD0
value|1
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_AUDIO_INFOFRAME_CTRL
value|0x01e
end_define

begin_define
define|#
directive|define
name|AUDIO_INFOFRAME_CTRL_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_AUDIO_INFOFRAME_STATUS
value|0x01f
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_AUDIO_INFOFRAME_HEADER
value|0x020
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_AUDIO_INFOFRAME_SUBPACK0_LOW
value|0x021
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_AUDIO_INFOFRAME_SUBPACK0_HIGH
value|0x022
end_define

begin_define
define|#
directive|define
name|INFOFRAME_HEADER_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x0f)<< 16)
end_define

begin_define
define|#
directive|define
name|INFOFRAME_HEADER_VERSION
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<<  8)
end_define

begin_define
define|#
directive|define
name|INFOFRAME_HEADER_TYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<<  0)
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_AVI_INFOFRAME_CTRL
value|0x023
end_define

begin_define
define|#
directive|define
name|AVI_INFOFRAME_CTRL_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_AVI_INFOFRAME_STATUS
value|0x024
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_AVI_INFOFRAME_HEADER
value|0x025
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_AVI_INFOFRAME_SUBPACK0_LOW
value|0x026
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_AVI_INFOFRAME_SUBPACK0_HIGH
value|0x027
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_AVI_INFOFRAME_SUBPACK1_LOW
value|0x028
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_AVI_INFOFRAME_SUBPACK1_HIGH
value|0x029
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_GENERIC_CTRL
value|0x02a
end_define

begin_define
define|#
directive|define
name|GENERIC_CTRL_AUDIO
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|GENERIC_CTRL_HBLANK
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|GENERIC_CTRL_SINGLE
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|GENERIC_CTRL_OTHER
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|GENERIC_CTRL_ENABLE
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_GENERIC_STATUS
value|0x02b
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_GENERIC_HEADER
value|0x02c
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_GENERIC_SUBPACK0_LOW
value|0x02d
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_GENERIC_SUBPACK0_HIGH
value|0x02e
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_GENERIC_SUBPACK1_LOW
value|0x02f
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_GENERIC_SUBPACK1_HIGH
value|0x030
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_GENERIC_SUBPACK2_LOW
value|0x031
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_GENERIC_SUBPACK2_HIGH
value|0x032
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_GENERIC_SUBPACK3_LOW
value|0x033
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_GENERIC_SUBPACK3_HIGH
value|0x034
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_ACR_CTRL
value|0x035
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_ACR_0320_SUBPACK_LOW
value|0x036
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_ACR_0320_SUBPACK_HIGH
value|0x037
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_ACR_0441_SUBPACK_LOW
value|0x038
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_ACR_0441_SUBPACK_HIGH
value|0x039
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_ACR_0882_SUBPACK_LOW
value|0x03a
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_ACR_0882_SUBPACK_HIGH
value|0x03b
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_ACR_1764_SUBPACK_LOW
value|0x03c
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_ACR_1764_SUBPACK_HIGH
value|0x03d
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_ACR_0480_SUBPACK_LOW
value|0x03e
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_ACR_0480_SUBPACK_HIGH
value|0x03f
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_ACR_0960_SUBPACK_LOW
value|0x040
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_ACR_0960_SUBPACK_HIGH
value|0x041
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_ACR_1920_SUBPACK_LOW
value|0x042
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_ACR_1920_SUBPACK_HIGH
value|0x043
end_define

begin_define
define|#
directive|define
name|ACR_ENABLE
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|ACR_SUBPACK_CTS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xffffff)<< 8)
end_define

begin_define
define|#
directive|define
name|ACR_SUBPACK_N
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xffffff)<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_CTRL
value|0x044
end_define

begin_define
define|#
directive|define
name|HDMI_CTRL_ENABLE
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|HDMI_CTRL_CA_SELECT
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|HDMI_CTRL_SS_SELECT
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|HDMI_CTRL_SF_SELECT
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|HDMI_CTRL_CC_SELECT
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|HDMI_CTRL_CT_SELECT
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|HDMI_CTRL_MAX_AC_PACKET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1f)<< 16)
end_define

begin_define
define|#
directive|define
name|HDMI_CTRL_SAMPLE_FLAT
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|HDMI_CTRL_AUDIO_LAYOUT_SELECT
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|HDMI_CTRL_AUDIO_LAYOUT
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|HDMI_CTRL_REKEY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7f)<<  0)
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_VSYNC_WINDOW
value|0x046
end_define

begin_define
define|#
directive|define
name|VSYNC_WINDOW_ENABLE
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|VSYNC_WINDOW_START
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3ff)<< 16)
end_define

begin_define
define|#
directive|define
name|VSYNC_WINDOW_END
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3ff)<<  0)
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_HDMI_SPARE
value|0x04f
end_define

begin_define
define|#
directive|define
name|SPARE_ACR_PRIORITY
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|SPARE_CTS_RESET_VAL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 16)
end_define

begin_define
define|#
directive|define
name|SPARE_SUPRESS_SP_B
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SPARE_FORCE_SW_CTS
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SPARE_HW_CTS
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_PWR
value|0x055
end_define

begin_define
define|#
directive|define
name|SOR_PWR_SETTING_NEW
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|SOR_PWR_SAFE_STATE_PU
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|SOR_PWR_NORMAL_START_ALT
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|SOR_PWR_NORMAL_STATE_PU
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_PLL0
value|0x057
end_define

begin_define
define|#
directive|define
name|SOR_PLL0_TX_REG_LOAD
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 28)
end_define

begin_define
define|#
directive|define
name|SOR_PLL0_ICHPMP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 24)
end_define

begin_define
define|#
directive|define
name|SOR_PLL0_FILTER
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 16)
end_define

begin_define
define|#
directive|define
name|SOR_PLL0_BG_V17_S
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 12)
end_define

begin_define
define|#
directive|define
name|SOR_PLL0_VCOCAP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<<  8)
end_define

begin_define
define|#
directive|define
name|SOR_PLL0_PULLDOWN
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|SOR_PLL0_RESISTORSEL
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|SOR_PLL0_PDPORT
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|SOR_PLL0_VCOPD
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SOR_PLL0_PDBG
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SOR_PLL0_PWR
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_PLL1
value|0x058
end_define

begin_define
define|#
directive|define
name|SOR_PLL1_S_D_PIN_PE
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|SOR_PLL1_HALF_FULL_PE
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|SOR_PLL1_PE_EN
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|SOR_PLL1_LOADADJ
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 20)
end_define

begin_define
define|#
directive|define
name|SOR_PLL1_TMDS_TERMADJ
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<<  9)
end_define

begin_define
define|#
directive|define
name|SOR_PLL1_TMDS_TERM
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_CSTM
value|0x05a
end_define

begin_define
define|#
directive|define
name|SOR_CSTM_ROTAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 28)
end_define

begin_define
define|#
directive|define
name|SOR_CSTM_ROTCLK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 24)
end_define

begin_define
define|#
directive|define
name|SOR_CSTM_PLLDIV
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|SOR_CSTM_BALANCED
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|SOR_CSTM_NEW_MODE
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|SOR_CSTM_DUP_SYNC
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|SOR_CSTM_LVDS_ENABLE
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|SOR_CSTM_LINKACTB
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|SOR_CSTM_LINKACTA
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|SOR_CSTM_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 12)
end_define

begin_define
define|#
directive|define
name|CSTM_MODE_LVDS
value|0
end_define

begin_define
define|#
directive|define
name|CSTM_MODE_TMDS
value|1
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_SEQ_CTL
value|0x05f
end_define

begin_define
define|#
directive|define
name|SOR_SEQ_SWITCH
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|SOR_SEQ_STATUS
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|SOR_SEQ_PC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 16)
end_define

begin_define
define|#
directive|define
name|SOR_SEQ_PD_PC_ALT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 12)
end_define

begin_define
define|#
directive|define
name|SOR_SEQ_PD_PC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<<  8)
end_define

begin_define
define|#
directive|define
name|SOR_SEQ_PU_PC_ALT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<<  4)
end_define

begin_define
define|#
directive|define
name|SOR_SEQ_PU_PC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<<  0)
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_SEQ_INST
parameter_list|(
name|x
parameter_list|)
value|(0x060 + (x))
end_define

begin_define
define|#
directive|define
name|SOR_SEQ_INST_PLL_PULLDOWN
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|SOR_SEQ_INST_POWERDOWN_MACRO
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|SOR_SEQ_INST_ASSERT_PLL_RESETV
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|SOR_SEQ_INST_BLANK_V
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|SOR_SEQ_INST_BLANK_H
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|SOR_SEQ_INST_BLANK_DE
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|SOR_SEQ_INST_BLACK_DATA
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|SOR_SEQ_INST_TRISTATE_IOS
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|SOR_SEQ_INST_DRIVE_PWM_OUT_LO
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|SOR_SEQ_INST_PIN_B_HIGH
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|SOR_SEQ_INST_PIN_A_HIGH
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|SOR_SEQ_INST_HALT
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|SOR_SEQ_INST_WAIT_UNITS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 12)
end_define

begin_define
define|#
directive|define
name|WAIT_UNITS_US
value|0
end_define

begin_define
define|#
directive|define
name|WAIT_UNITS_MS
value|1
end_define

begin_define
define|#
directive|define
name|WAIT_UNITS_VSYNC
value|2
end_define

begin_define
define|#
directive|define
name|SOR_SEQ_INST_WAIT_TIME
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3ff)<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_LANE_DRIVE_CURRENT
value|0x07e
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_AUDIO_N
value|0x08c
end_define

begin_define
define|#
directive|define
name|AUDIO_N_LOOKUP
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|AUDIO_N_GENERATE_ALTERNATE
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|AUDIO_N_RESETF
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|AUDIO_N_VALUE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xfffff)<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_REFCLK
value|0x095
end_define

begin_define
define|#
directive|define
name|SOR_REFCLK_DIV_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 8)
end_define

begin_define
define|#
directive|define
name|SOR_REFCLK_DIV_FRAC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x03)<< 6)
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_INPUT_CONTROL
value|0x097
end_define

begin_define
define|#
directive|define
name|ARM_VIDEO_RANGE_LIMITED
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|HDMI_SRC_DISPLAYB
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_PE_CURRENT
value|0x099
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_AUDIO_CNTRL0
value|0x0ac
end_define

begin_define
define|#
directive|define
name|SOR_AUDIO_CNTRL0_INJECT_NULLSMPL
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|SOR_AUDIO_CNTRL0_SOURCE_SELECT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x03)<< 20)
end_define

begin_define
define|#
directive|define
name|SOURCE_SELECT_AUTO
value|0
end_define

begin_define
define|#
directive|define
name|SOURCE_SELECT_SPDIF
value|1
end_define

begin_define
define|#
directive|define
name|SOURCE_SELECT_HDAL
value|2
end_define

begin_define
define|#
directive|define
name|SOR_AUDIO_CNTRL0_AFIFO_FLUSH
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_AUDIO_SPARE0
value|0x0ae
end_define

begin_define
define|#
directive|define
name|SOR_AUDIO_SPARE0_HBR_ENABLE
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_AUDIO_NVAL_0320
value|0x0af
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_AUDIO_NVAL_0441
value|0x0b0
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_AUDIO_NVAL_0882
value|0x0b1
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_AUDIO_NVAL_1764
value|0x0b2
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_AUDIO_NVAL_0480
value|0x0b3
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_AUDIO_NVAL_0960
value|0x0b4
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_AUDIO_NVAL_1920
value|0x0b5
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_AUDIO_HDA_SCRATCH0
value|0x0b6
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_AUDIO_HDA_SCRATCH1
value|0x0b7
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_AUDIO_HDA_SCRATCH2
value|0x0b8
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_AUDIO_HDA_SCRATCH3
value|0x0b9
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_AUDIO_HDA_CODEC_SCRATCH0
value|0x0ba
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_AUDIO_HDA_CODEC_SCRATCH1
value|0x0bb
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_AUDIO_HDA_ELD_BUFWR
value|0x0bc
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_AUDIO_HDA_PRESENSE
value|0x0bd
end_define

begin_define
define|#
directive|define
name|SOR_AUDIO_HDA_PRESENSE_VALID
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SOR_AUDIO_HDA_PRESENSE_PRESENT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_AUDIO_AVAL_0320
value|0x0bf
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_AUDIO_AVAL_0441
value|0x0c0
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_AUDIO_AVAL_0882
value|0x0c1
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_AUDIO_AVAL_1764
value|0x0c2
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_AUDIO_AVAL_0480
value|0x0c3
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_AUDIO_AVAL_0960
value|0x0c4
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_AUDIO_AVAL_1920
value|0x0c5
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_AUDIO_AVAL_DEFAULT
value|0x0c6
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_INT_STATUS
value|0x0cc
end_define

begin_define
define|#
directive|define
name|INT_SCRATCH
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|INT_CP_REQUEST
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|INT_CODEC_SCRATCH1
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|INT_CODEC_SCRATCH0
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_INT_MASK
value|0x0cd
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_INT_ENABLE
value|0x0ce
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_IO_PEAK_CURRENT
value|0x0d1
end_define

begin_define
define|#
directive|define
name|HDMI_NV_PDISP_SOR_PAD_CTLS0
value|0x0d2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TEGRA_HDMI_REG_H_ */
end_comment

end_unit

