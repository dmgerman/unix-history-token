begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Oleksandr Tymoshenko<gonzo@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DWC_HDMIREG_H__
end_ifndef

begin_define
define|#
directive|define
name|__DWC_HDMIREG_H__
end_define

begin_define
define|#
directive|define
name|HDMI_DESIGN_ID
value|0x0000
end_define

begin_define
define|#
directive|define
name|HDMI_REVISION_ID
value|0x0001
end_define

begin_define
define|#
directive|define
name|HDMI_PRODUCT_ID0
value|0x0002
end_define

begin_define
define|#
directive|define
name|HDMI_PRODUCT_ID1
value|0x0003
end_define

begin_comment
comment|/* Interrupt Registers */
end_comment

begin_define
define|#
directive|define
name|HDMI_IH_FC_STAT0
value|0x0100
end_define

begin_define
define|#
directive|define
name|HDMI_IH_FC_STAT1
value|0x0101
end_define

begin_define
define|#
directive|define
name|HDMI_IH_FC_STAT2
value|0x0102
end_define

begin_define
define|#
directive|define
name|HDMI_IH_AS_STAT0
value|0x0103
end_define

begin_define
define|#
directive|define
name|HDMI_IH_PHY_STAT0
value|0x0104
end_define

begin_define
define|#
directive|define
name|HDMI_IH_PHY_STAT0_HPD
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_IH_I2CM_STAT0
value|0x0105
end_define

begin_define
define|#
directive|define
name|HDMI_IH_CEC_STAT0
value|0x0106
end_define

begin_define
define|#
directive|define
name|HDMI_IH_VP_STAT0
value|0x0107
end_define

begin_define
define|#
directive|define
name|HDMI_IH_I2CMPHY_STAT0
value|0x0108
end_define

begin_define
define|#
directive|define
name|HDMI_IH_I2CMPHY_STAT0_DONE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|HDMI_IH_I2CMPHY_STAT0_ERROR
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_IH_AHBDMAAUD_STAT0
value|0x0109
end_define

begin_define
define|#
directive|define
name|HDMI_IH_MUTE_FC_STAT0
value|0x0180
end_define

begin_define
define|#
directive|define
name|HDMI_IH_MUTE_FC_STAT1
value|0x0181
end_define

begin_define
define|#
directive|define
name|HDMI_IH_MUTE_FC_STAT2
value|0x0182
end_define

begin_define
define|#
directive|define
name|HDMI_IH_MUTE_FC_STAT2_OVERFLOW_MASK
value|(0x3)
end_define

begin_define
define|#
directive|define
name|HDMI_IH_MUTE_AS_STAT0
value|0x0183
end_define

begin_define
define|#
directive|define
name|HDMI_IH_MUTE_PHY_STAT0
value|0x0184
end_define

begin_define
define|#
directive|define
name|HDMI_IH_MUTE_I2CM_STAT0
value|0x0185
end_define

begin_define
define|#
directive|define
name|HDMI_IH_MUTE_CEC_STAT0
value|0x0186
end_define

begin_define
define|#
directive|define
name|HDMI_IH_MUTE_VP_STAT0
value|0x0187
end_define

begin_define
define|#
directive|define
name|HDMI_IH_MUTE_I2CMPHY_STAT0
value|0x0188
end_define

begin_define
define|#
directive|define
name|HDMI_IH_MUTE_AHBDMAAUD_STAT0
value|0x0189
end_define

begin_define
define|#
directive|define
name|HDMI_IH_MUTE
value|0x01FF
end_define

begin_define
define|#
directive|define
name|HDMI_IH_MUTE_MUTE_WAKEUP_INTERRUPT
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|HDMI_IH_MUTE_MUTE_ALL_INTERRUPT
value|(1<<0)
end_define

begin_comment
comment|/* Video Sample Registers */
end_comment

begin_define
define|#
directive|define
name|HDMI_TX_INVID0
value|0x0200
end_define

begin_define
define|#
directive|define
name|HDMI_TX_INVID0_INTERNAL_DE_GENERATOR_MASK
value|0x80
end_define

begin_define
define|#
directive|define
name|HDMI_TX_INVID0_INTERNAL_DE_GENERATOR_ENABLE
value|0x80
end_define

begin_define
define|#
directive|define
name|HDMI_TX_INVID0_INTERNAL_DE_GENERATOR_DISABLE
value|0x00
end_define

begin_define
define|#
directive|define
name|HDMI_TX_INVID0_VIDEO_MAPPING_MASK
value|0x1F
end_define

begin_define
define|#
directive|define
name|HDMI_TX_INVID0_VIDEO_MAPPING_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|HDMI_TX_INSTUFFING
value|0x0201
end_define

begin_define
define|#
directive|define
name|HDMI_TX_INSTUFFING_BDBDATA_STUFFING_MASK
value|0x4
end_define

begin_define
define|#
directive|define
name|HDMI_TX_INSTUFFING_BDBDATA_STUFFING_ENABLE
value|0x4
end_define

begin_define
define|#
directive|define
name|HDMI_TX_INSTUFFING_BDBDATA_STUFFING_DISABLE
value|0x0
end_define

begin_define
define|#
directive|define
name|HDMI_TX_INSTUFFING_RCRDATA_STUFFING_MASK
value|0x2
end_define

begin_define
define|#
directive|define
name|HDMI_TX_INSTUFFING_RCRDATA_STUFFING_ENABLE
value|0x2
end_define

begin_define
define|#
directive|define
name|HDMI_TX_INSTUFFING_RCRDATA_STUFFING_DISABLE
value|0x0
end_define

begin_define
define|#
directive|define
name|HDMI_TX_INSTUFFING_GYDATA_STUFFING_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|HDMI_TX_INSTUFFING_GYDATA_STUFFING_ENABLE
value|0x1
end_define

begin_define
define|#
directive|define
name|HDMI_TX_INSTUFFING_GYDATA_STUFFING_DISABLE
value|0x0
end_define

begin_define
define|#
directive|define
name|HDMI_TX_GYDATA0
value|0x0202
end_define

begin_define
define|#
directive|define
name|HDMI_TX_GYDATA1
value|0x0203
end_define

begin_define
define|#
directive|define
name|HDMI_TX_RCRDATA0
value|0x0204
end_define

begin_define
define|#
directive|define
name|HDMI_TX_RCRDATA1
value|0x0205
end_define

begin_define
define|#
directive|define
name|HDMI_TX_BCBDATA0
value|0x0206
end_define

begin_define
define|#
directive|define
name|HDMI_TX_BCBDATA1
value|0x0207
end_define

begin_comment
comment|/* Video Packetizer Registers */
end_comment

begin_define
define|#
directive|define
name|HDMI_VP_STATUS
value|0x0800
end_define

begin_define
define|#
directive|define
name|HDMI_VP_PR_CD
value|0x0801
end_define

begin_define
define|#
directive|define
name|HDMI_VP_PR_CD_COLOR_DEPTH_MASK
value|0xF0
end_define

begin_define
define|#
directive|define
name|HDMI_VP_PR_CD_COLOR_DEPTH_OFFSET
value|4
end_define

begin_define
define|#
directive|define
name|HDMI_VP_PR_CD_DESIRED_PR_FACTOR_MASK
value|0x0F
end_define

begin_define
define|#
directive|define
name|HDMI_VP_PR_CD_DESIRED_PR_FACTOR_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|HDMI_VP_STUFF
value|0x0802
end_define

begin_define
define|#
directive|define
name|HDMI_VP_STUFF_IDEFAULT_PHASE_MASK
value|0x20
end_define

begin_define
define|#
directive|define
name|HDMI_VP_STUFF_IDEFAULT_PHASE_OFFSET
value|5
end_define

begin_define
define|#
directive|define
name|HDMI_VP_STUFF_IFIX_PP_TO_LAST_MASK
value|0x10
end_define

begin_define
define|#
directive|define
name|HDMI_VP_STUFF_IFIX_PP_TO_LAST_OFFSET
value|4
end_define

begin_define
define|#
directive|define
name|HDMI_VP_STUFF_ICX_GOTO_P0_ST_MASK
value|0x8
end_define

begin_define
define|#
directive|define
name|HDMI_VP_STUFF_ICX_GOTO_P0_ST_OFFSET
value|3
end_define

begin_define
define|#
directive|define
name|HDMI_VP_STUFF_YCC422_STUFFING_MASK
value|0x4
end_define

begin_define
define|#
directive|define
name|HDMI_VP_STUFF_YCC422_STUFFING_STUFFING_MODE
value|0x4
end_define

begin_define
define|#
directive|define
name|HDMI_VP_STUFF_YCC422_STUFFING_DIRECT_MODE
value|0x0
end_define

begin_define
define|#
directive|define
name|HDMI_VP_STUFF_PP_STUFFING_MASK
value|0x2
end_define

begin_define
define|#
directive|define
name|HDMI_VP_STUFF_PP_STUFFING_STUFFING_MODE
value|0x2
end_define

begin_define
define|#
directive|define
name|HDMI_VP_STUFF_PP_STUFFING_DIRECT_MODE
value|0x0
end_define

begin_define
define|#
directive|define
name|HDMI_VP_STUFF_PR_STUFFING_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|HDMI_VP_STUFF_PR_STUFFING_STUFFING_MODE
value|0x1
end_define

begin_define
define|#
directive|define
name|HDMI_VP_STUFF_PR_STUFFING_DIRECT_MODE
value|0x0
end_define

begin_define
define|#
directive|define
name|HDMI_VP_REMAP
value|0x0803
end_define

begin_define
define|#
directive|define
name|HDMI_VP_REMAP_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|HDMI_VP_REMAP_YCC422_24BIT
value|0x2
end_define

begin_define
define|#
directive|define
name|HDMI_VP_REMAP_YCC422_20BIT
value|0x1
end_define

begin_define
define|#
directive|define
name|HDMI_VP_REMAP_YCC422_16BIT
value|0x0
end_define

begin_define
define|#
directive|define
name|HDMI_VP_CONF
value|0x0804
end_define

begin_define
define|#
directive|define
name|HDMI_VP_CONF_BYPASS_EN_MASK
value|0x40
end_define

begin_define
define|#
directive|define
name|HDMI_VP_CONF_BYPASS_EN_ENABLE
value|0x40
end_define

begin_define
define|#
directive|define
name|HDMI_VP_CONF_BYPASS_EN_DISABLE
value|0x00
end_define

begin_define
define|#
directive|define
name|HDMI_VP_CONF_PP_EN_ENMASK
value|0x20
end_define

begin_define
define|#
directive|define
name|HDMI_VP_CONF_PP_EN_ENABLE
value|0x20
end_define

begin_define
define|#
directive|define
name|HDMI_VP_CONF_PP_EN_DISABLE
value|0x00
end_define

begin_define
define|#
directive|define
name|HDMI_VP_CONF_PR_EN_MASK
value|0x10
end_define

begin_define
define|#
directive|define
name|HDMI_VP_CONF_PR_EN_ENABLE
value|0x10
end_define

begin_define
define|#
directive|define
name|HDMI_VP_CONF_PR_EN_DISABLE
value|0x00
end_define

begin_define
define|#
directive|define
name|HDMI_VP_CONF_YCC422_EN_MASK
value|0x8
end_define

begin_define
define|#
directive|define
name|HDMI_VP_CONF_YCC422_EN_ENABLE
value|0x8
end_define

begin_define
define|#
directive|define
name|HDMI_VP_CONF_YCC422_EN_DISABLE
value|0x0
end_define

begin_define
define|#
directive|define
name|HDMI_VP_CONF_BYPASS_SELECT_MASK
value|0x4
end_define

begin_define
define|#
directive|define
name|HDMI_VP_CONF_BYPASS_SELECT_VID_PACKETIZER
value|0x4
end_define

begin_define
define|#
directive|define
name|HDMI_VP_CONF_BYPASS_SELECT_PIX_REPEATER
value|0x0
end_define

begin_define
define|#
directive|define
name|HDMI_VP_CONF_OUTPUT_SELECTOR_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|HDMI_VP_CONF_OUTPUT_SELECTOR_BYPASS
value|0x3
end_define

begin_define
define|#
directive|define
name|HDMI_VP_CONF_OUTPUT_SELECTOR_YCC422
value|0x1
end_define

begin_define
define|#
directive|define
name|HDMI_VP_CONF_OUTPUT_SELECTOR_PP
value|0x0
end_define

begin_define
define|#
directive|define
name|HDMI_VP_STAT
value|0x0805
end_define

begin_define
define|#
directive|define
name|HDMI_VP_INT
value|0x0806
end_define

begin_define
define|#
directive|define
name|HDMI_VP_MASK
value|0x0807
end_define

begin_define
define|#
directive|define
name|HDMI_VP_POL
value|0x0808
end_define

begin_comment
comment|/* Frame Composer Registers */
end_comment

begin_define
define|#
directive|define
name|HDMI_FC_INVIDCONF
value|0x1000
end_define

begin_define
define|#
directive|define
name|HDMI_FC_INVIDCONF_VSYNC_IN_POLARITY_ACTIVE_HIGH
value|0x40
end_define

begin_define
define|#
directive|define
name|HDMI_FC_INVIDCONF_VSYNC_IN_POLARITY_ACTIVE_LOW
value|0x00
end_define

begin_define
define|#
directive|define
name|HDMI_FC_INVIDCONF_HSYNC_IN_POLARITY_ACTIVE_HIGH
value|0x20
end_define

begin_define
define|#
directive|define
name|HDMI_FC_INVIDCONF_HSYNC_IN_POLARITY_ACTIVE_LOW
value|0x00
end_define

begin_define
define|#
directive|define
name|HDMI_FC_INVIDCONF_DE_IN_POLARITY_ACTIVE_HIGH
value|0x10
end_define

begin_define
define|#
directive|define
name|HDMI_FC_INVIDCONF_DE_IN_POLARITY_ACTIVE_LOW
value|0x00
end_define

begin_define
define|#
directive|define
name|HDMI_FC_INVIDCONF_DVI_MODEZ_HDMI_MODE
value|0x8
end_define

begin_define
define|#
directive|define
name|HDMI_FC_INVIDCONF_DVI_MODEZ_DVI_MODE
value|0x0
end_define

begin_define
define|#
directive|define
name|HDMI_FC_INVIDCONF_R_V_BLANK_IN_OSC_ACTIVE_HIGH
value|0x2
end_define

begin_define
define|#
directive|define
name|HDMI_FC_INVIDCONF_R_V_BLANK_IN_OSC_ACTIVE_LOW
value|0x0
end_define

begin_define
define|#
directive|define
name|HDMI_FC_INVIDCONF_IN_I_P_INTERLACED
value|0x1
end_define

begin_define
define|#
directive|define
name|HDMI_FC_INVIDCONF_IN_I_P_PROGRESSIVE
value|0x0
end_define

begin_define
define|#
directive|define
name|HDMI_FC_INHACTV0
value|0x1001
end_define

begin_define
define|#
directive|define
name|HDMI_FC_INHACTV1
value|0x1002
end_define

begin_define
define|#
directive|define
name|HDMI_FC_INHBLANK0
value|0x1003
end_define

begin_define
define|#
directive|define
name|HDMI_FC_INHBLANK1
value|0x1004
end_define

begin_define
define|#
directive|define
name|HDMI_FC_INVACTV0
value|0x1005
end_define

begin_define
define|#
directive|define
name|HDMI_FC_INVACTV1
value|0x1006
end_define

begin_define
define|#
directive|define
name|HDMI_FC_INVBLANK
value|0x1007
end_define

begin_define
define|#
directive|define
name|HDMI_FC_HSYNCINDELAY0
value|0x1008
end_define

begin_define
define|#
directive|define
name|HDMI_FC_HSYNCINDELAY1
value|0x1009
end_define

begin_define
define|#
directive|define
name|HDMI_FC_HSYNCINWIDTH0
value|0x100A
end_define

begin_define
define|#
directive|define
name|HDMI_FC_HSYNCINWIDTH1
value|0x100B
end_define

begin_define
define|#
directive|define
name|HDMI_FC_VSYNCINDELAY
value|0x100C
end_define

begin_define
define|#
directive|define
name|HDMI_FC_VSYNCINWIDTH
value|0x100D
end_define

begin_define
define|#
directive|define
name|HDMI_FC_INFREQ0
value|0x100E
end_define

begin_define
define|#
directive|define
name|HDMI_FC_INFREQ1
value|0x100F
end_define

begin_define
define|#
directive|define
name|HDMI_FC_INFREQ2
value|0x1010
end_define

begin_define
define|#
directive|define
name|HDMI_FC_CTRLDUR
value|0x1011
end_define

begin_define
define|#
directive|define
name|HDMI_FC_EXCTRLDUR
value|0x1012
end_define

begin_define
define|#
directive|define
name|HDMI_FC_EXCTRLSPAC
value|0x1013
end_define

begin_define
define|#
directive|define
name|HDMI_FC_CH0PREAM
value|0x1014
end_define

begin_define
define|#
directive|define
name|HDMI_FC_CH1PREAM
value|0x1015
end_define

begin_define
define|#
directive|define
name|HDMI_FC_CH2PREAM
value|0x1016
end_define

begin_define
define|#
directive|define
name|HDMI_FC_AVICONF3
value|0x1017
end_define

begin_define
define|#
directive|define
name|HDMI_FC_GCP
value|0x1018
end_define

begin_define
define|#
directive|define
name|HDMI_FC_AVICONF0
value|0x1019
end_define

begin_define
define|#
directive|define
name|HDMI_FC_AVICONF1
value|0x101A
end_define

begin_define
define|#
directive|define
name|HDMI_FC_AVICONF2
value|0x101B
end_define

begin_define
define|#
directive|define
name|HDMI_FC_AVIVID
value|0x101C
end_define

begin_define
define|#
directive|define
name|HDMI_FC_AVIETB0
value|0x101D
end_define

begin_define
define|#
directive|define
name|HDMI_FC_AVIETB1
value|0x101E
end_define

begin_define
define|#
directive|define
name|HDMI_FC_AVISBB0
value|0x101F
end_define

begin_define
define|#
directive|define
name|HDMI_FC_AVISBB1
value|0x1020
end_define

begin_define
define|#
directive|define
name|HDMI_FC_AVIELB0
value|0x1021
end_define

begin_define
define|#
directive|define
name|HDMI_FC_AVIELB1
value|0x1022
end_define

begin_define
define|#
directive|define
name|HDMI_FC_AVISRB0
value|0x1023
end_define

begin_define
define|#
directive|define
name|HDMI_FC_AVISRB1
value|0x1024
end_define

begin_define
define|#
directive|define
name|HDMI_FC_AUDICONF0
value|0x1025
end_define

begin_define
define|#
directive|define
name|HDMI_FC_AUDICONF1
value|0x1026
end_define

begin_define
define|#
directive|define
name|HDMI_FC_AUDICONF2
value|0x1027
end_define

begin_define
define|#
directive|define
name|HDMI_FC_AUDICONF3
value|0x1028
end_define

begin_define
define|#
directive|define
name|HDMI_FC_VSDIEEEID0
value|0x1029
end_define

begin_define
define|#
directive|define
name|HDMI_FC_VSDSIZE
value|0x102A
end_define

begin_define
define|#
directive|define
name|HDMI_FC_VSDIEEEID1
value|0x1030
end_define

begin_define
define|#
directive|define
name|HDMI_FC_VSDIEEEID2
value|0x1031
end_define

begin_define
define|#
directive|define
name|HDMI_FC_VSDPAYLOAD0
value|0x1032
end_define

begin_define
define|#
directive|define
name|HDMI_FC_VSDPAYLOAD1
value|0x1033
end_define

begin_define
define|#
directive|define
name|HDMI_FC_VSDPAYLOAD2
value|0x1034
end_define

begin_define
define|#
directive|define
name|HDMI_FC_VSDPAYLOAD3
value|0x1035
end_define

begin_define
define|#
directive|define
name|HDMI_FC_VSDPAYLOAD4
value|0x1036
end_define

begin_define
define|#
directive|define
name|HDMI_FC_VSDPAYLOAD5
value|0x1037
end_define

begin_define
define|#
directive|define
name|HDMI_FC_VSDPAYLOAD6
value|0x1038
end_define

begin_define
define|#
directive|define
name|HDMI_FC_VSDPAYLOAD7
value|0x1039
end_define

begin_define
define|#
directive|define
name|HDMI_FC_VSDPAYLOAD8
value|0x103A
end_define

begin_define
define|#
directive|define
name|HDMI_FC_VSDPAYLOAD9
value|0x103B
end_define

begin_define
define|#
directive|define
name|HDMI_FC_VSDPAYLOAD10
value|0x103C
end_define

begin_define
define|#
directive|define
name|HDMI_FC_VSDPAYLOAD11
value|0x103D
end_define

begin_define
define|#
directive|define
name|HDMI_FC_VSDPAYLOAD12
value|0x103E
end_define

begin_define
define|#
directive|define
name|HDMI_FC_VSDPAYLOAD13
value|0x103F
end_define

begin_define
define|#
directive|define
name|HDMI_FC_VSDPAYLOAD14
value|0x1040
end_define

begin_define
define|#
directive|define
name|HDMI_FC_VSDPAYLOAD15
value|0x1041
end_define

begin_define
define|#
directive|define
name|HDMI_FC_VSDPAYLOAD16
value|0x1042
end_define

begin_define
define|#
directive|define
name|HDMI_FC_VSDPAYLOAD17
value|0x1043
end_define

begin_define
define|#
directive|define
name|HDMI_FC_VSDPAYLOAD18
value|0x1044
end_define

begin_define
define|#
directive|define
name|HDMI_FC_VSDPAYLOAD19
value|0x1045
end_define

begin_define
define|#
directive|define
name|HDMI_FC_VSDPAYLOAD20
value|0x1046
end_define

begin_define
define|#
directive|define
name|HDMI_FC_VSDPAYLOAD21
value|0x1047
end_define

begin_define
define|#
directive|define
name|HDMI_FC_VSDPAYLOAD22
value|0x1048
end_define

begin_define
define|#
directive|define
name|HDMI_FC_VSDPAYLOAD23
value|0x1049
end_define

begin_define
define|#
directive|define
name|HDMI_FC_SPDVENDORNAME0
value|0x104A
end_define

begin_define
define|#
directive|define
name|HDMI_FC_SPDVENDORNAME1
value|0x104B
end_define

begin_define
define|#
directive|define
name|HDMI_FC_SPDVENDORNAME2
value|0x104C
end_define

begin_define
define|#
directive|define
name|HDMI_FC_SPDVENDORNAME3
value|0x104D
end_define

begin_define
define|#
directive|define
name|HDMI_FC_SPDVENDORNAME4
value|0x104E
end_define

begin_define
define|#
directive|define
name|HDMI_FC_SPDVENDORNAME5
value|0x104F
end_define

begin_define
define|#
directive|define
name|HDMI_FC_SPDVENDORNAME6
value|0x1050
end_define

begin_define
define|#
directive|define
name|HDMI_FC_SPDVENDORNAME7
value|0x1051
end_define

begin_define
define|#
directive|define
name|HDMI_FC_SDPPRODUCTNAME0
value|0x1052
end_define

begin_define
define|#
directive|define
name|HDMI_FC_SDPPRODUCTNAME1
value|0x1053
end_define

begin_define
define|#
directive|define
name|HDMI_FC_SDPPRODUCTNAME2
value|0x1054
end_define

begin_define
define|#
directive|define
name|HDMI_FC_SDPPRODUCTNAME3
value|0x1055
end_define

begin_define
define|#
directive|define
name|HDMI_FC_SDPPRODUCTNAME4
value|0x1056
end_define

begin_define
define|#
directive|define
name|HDMI_FC_SDPPRODUCTNAME5
value|0x1057
end_define

begin_define
define|#
directive|define
name|HDMI_FC_SDPPRODUCTNAME6
value|0x1058
end_define

begin_define
define|#
directive|define
name|HDMI_FC_SDPPRODUCTNAME7
value|0x1059
end_define

begin_define
define|#
directive|define
name|HDMI_FC_SDPPRODUCTNAME8
value|0x105A
end_define

begin_define
define|#
directive|define
name|HDMI_FC_SDPPRODUCTNAME9
value|0x105B
end_define

begin_define
define|#
directive|define
name|HDMI_FC_SDPPRODUCTNAME10
value|0x105C
end_define

begin_define
define|#
directive|define
name|HDMI_FC_SDPPRODUCTNAME11
value|0x105D
end_define

begin_define
define|#
directive|define
name|HDMI_FC_SDPPRODUCTNAME12
value|0x105E
end_define

begin_define
define|#
directive|define
name|HDMI_FC_SDPPRODUCTNAME13
value|0x105F
end_define

begin_define
define|#
directive|define
name|HDMI_FC_SDPPRODUCTNAME14
value|0x1060
end_define

begin_define
define|#
directive|define
name|HDMI_FC_SPDPRODUCTNAME15
value|0x1061
end_define

begin_define
define|#
directive|define
name|HDMI_FC_SPDDEVICEINF
value|0x1062
end_define

begin_define
define|#
directive|define
name|HDMI_FC_AUDSCONF
value|0x1063
end_define

begin_define
define|#
directive|define
name|HDMI_FC_AUDSSTAT
value|0x1064
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DATACH0FILL
value|0x1070
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DATACH1FILL
value|0x1071
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DATACH2FILL
value|0x1072
end_define

begin_define
define|#
directive|define
name|HDMI_FC_CTRLQHIGH
value|0x1073
end_define

begin_define
define|#
directive|define
name|HDMI_FC_CTRLQLOW
value|0x1074
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ACP0
value|0x1075
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ACP28
value|0x1076
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ACP27
value|0x1077
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ACP26
value|0x1078
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ACP25
value|0x1079
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ACP24
value|0x107A
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ACP23
value|0x107B
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ACP22
value|0x107C
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ACP21
value|0x107D
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ACP20
value|0x107E
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ACP19
value|0x107F
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ACP18
value|0x1080
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ACP17
value|0x1081
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ACP16
value|0x1082
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ACP15
value|0x1083
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ACP14
value|0x1084
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ACP13
value|0x1085
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ACP12
value|0x1086
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ACP11
value|0x1087
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ACP10
value|0x1088
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ACP9
value|0x1089
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ACP8
value|0x108A
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ACP7
value|0x108B
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ACP6
value|0x108C
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ACP5
value|0x108D
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ACP4
value|0x108E
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ACP3
value|0x108F
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ACP2
value|0x1090
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ACP1
value|0x1091
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ISCR1_0
value|0x1092
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ISCR1_16
value|0x1093
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ISCR1_15
value|0x1094
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ISCR1_14
value|0x1095
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ISCR1_13
value|0x1096
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ISCR1_12
value|0x1097
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ISCR1_11
value|0x1098
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ISCR1_10
value|0x1099
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ISCR1_9
value|0x109A
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ISCR1_8
value|0x109B
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ISCR1_7
value|0x109C
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ISCR1_6
value|0x109D
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ISCR1_5
value|0x109E
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ISCR1_4
value|0x109F
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ISCR1_3
value|0x10A0
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ISCR1_2
value|0x10A1
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ISCR1_1
value|0x10A2
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ISCR2_15
value|0x10A3
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ISCR2_14
value|0x10A4
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ISCR2_13
value|0x10A5
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ISCR2_12
value|0x10A6
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ISCR2_11
value|0x10A7
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ISCR2_10
value|0x10A8
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ISCR2_9
value|0x10A9
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ISCR2_8
value|0x10AA
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ISCR2_7
value|0x10AB
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ISCR2_6
value|0x10AC
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ISCR2_5
value|0x10AD
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ISCR2_4
value|0x10AE
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ISCR2_3
value|0x10AF
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ISCR2_2
value|0x10B0
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ISCR2_1
value|0x10B1
end_define

begin_define
define|#
directive|define
name|HDMI_FC_ISCR2_0
value|0x10B2
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DATAUTO0
value|0x10B3
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DATAUTO1
value|0x10B4
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DATAUTO2
value|0x10B5
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DATMAN
value|0x10B6
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DATAUTO3
value|0x10B7
end_define

begin_define
define|#
directive|define
name|HDMI_FC_RDRB0
value|0x10B8
end_define

begin_define
define|#
directive|define
name|HDMI_FC_RDRB1
value|0x10B9
end_define

begin_define
define|#
directive|define
name|HDMI_FC_RDRB2
value|0x10BA
end_define

begin_define
define|#
directive|define
name|HDMI_FC_RDRB3
value|0x10BB
end_define

begin_define
define|#
directive|define
name|HDMI_FC_RDRB4
value|0x10BC
end_define

begin_define
define|#
directive|define
name|HDMI_FC_RDRB5
value|0x10BD
end_define

begin_define
define|#
directive|define
name|HDMI_FC_RDRB6
value|0x10BE
end_define

begin_define
define|#
directive|define
name|HDMI_FC_RDRB7
value|0x10BF
end_define

begin_define
define|#
directive|define
name|HDMI_FC_STAT0
value|0x10D0
end_define

begin_define
define|#
directive|define
name|HDMI_FC_INT0
value|0x10D1
end_define

begin_define
define|#
directive|define
name|HDMI_FC_MASK0
value|0x10D2
end_define

begin_define
define|#
directive|define
name|HDMI_FC_POL0
value|0x10D3
end_define

begin_define
define|#
directive|define
name|HDMI_FC_STAT1
value|0x10D4
end_define

begin_define
define|#
directive|define
name|HDMI_FC_INT1
value|0x10D5
end_define

begin_define
define|#
directive|define
name|HDMI_FC_MASK1
value|0x10D6
end_define

begin_define
define|#
directive|define
name|HDMI_FC_POL1
value|0x10D7
end_define

begin_define
define|#
directive|define
name|HDMI_FC_STAT2
value|0x10D8
end_define

begin_define
define|#
directive|define
name|HDMI_FC_INT2
value|0x10D9
end_define

begin_define
define|#
directive|define
name|HDMI_FC_MASK2
value|0x10DA
end_define

begin_define
define|#
directive|define
name|HDMI_FC_MASK2_LOW_PRI
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|HDMI_FC_MASK2_HIGH_PRI
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_FC_POL2
value|0x10DB
end_define

begin_define
define|#
directive|define
name|HDMI_FC_PRCONF
value|0x10E0
end_define

begin_define
define|#
directive|define
name|HDMI_FC_GMD_STAT
value|0x1100
end_define

begin_define
define|#
directive|define
name|HDMI_FC_GMD_EN
value|0x1101
end_define

begin_define
define|#
directive|define
name|HDMI_FC_GMD_UP
value|0x1102
end_define

begin_define
define|#
directive|define
name|HDMI_FC_GMD_CONF
value|0x1103
end_define

begin_define
define|#
directive|define
name|HDMI_FC_GMD_HB
value|0x1104
end_define

begin_define
define|#
directive|define
name|HDMI_FC_GMD_PB0
value|0x1105
end_define

begin_define
define|#
directive|define
name|HDMI_FC_GMD_PB1
value|0x1106
end_define

begin_define
define|#
directive|define
name|HDMI_FC_GMD_PB2
value|0x1107
end_define

begin_define
define|#
directive|define
name|HDMI_FC_GMD_PB3
value|0x1108
end_define

begin_define
define|#
directive|define
name|HDMI_FC_GMD_PB4
value|0x1109
end_define

begin_define
define|#
directive|define
name|HDMI_FC_GMD_PB5
value|0x110A
end_define

begin_define
define|#
directive|define
name|HDMI_FC_GMD_PB6
value|0x110B
end_define

begin_define
define|#
directive|define
name|HDMI_FC_GMD_PB7
value|0x110C
end_define

begin_define
define|#
directive|define
name|HDMI_FC_GMD_PB8
value|0x110D
end_define

begin_define
define|#
directive|define
name|HDMI_FC_GMD_PB9
value|0x110E
end_define

begin_define
define|#
directive|define
name|HDMI_FC_GMD_PB10
value|0x110F
end_define

begin_define
define|#
directive|define
name|HDMI_FC_GMD_PB11
value|0x1110
end_define

begin_define
define|#
directive|define
name|HDMI_FC_GMD_PB12
value|0x1111
end_define

begin_define
define|#
directive|define
name|HDMI_FC_GMD_PB13
value|0x1112
end_define

begin_define
define|#
directive|define
name|HDMI_FC_GMD_PB14
value|0x1113
end_define

begin_define
define|#
directive|define
name|HDMI_FC_GMD_PB15
value|0x1114
end_define

begin_define
define|#
directive|define
name|HDMI_FC_GMD_PB16
value|0x1115
end_define

begin_define
define|#
directive|define
name|HDMI_FC_GMD_PB17
value|0x1116
end_define

begin_define
define|#
directive|define
name|HDMI_FC_GMD_PB18
value|0x1117
end_define

begin_define
define|#
directive|define
name|HDMI_FC_GMD_PB19
value|0x1118
end_define

begin_define
define|#
directive|define
name|HDMI_FC_GMD_PB20
value|0x1119
end_define

begin_define
define|#
directive|define
name|HDMI_FC_GMD_PB21
value|0x111A
end_define

begin_define
define|#
directive|define
name|HDMI_FC_GMD_PB22
value|0x111B
end_define

begin_define
define|#
directive|define
name|HDMI_FC_GMD_PB23
value|0x111C
end_define

begin_define
define|#
directive|define
name|HDMI_FC_GMD_PB24
value|0x111D
end_define

begin_define
define|#
directive|define
name|HDMI_FC_GMD_PB25
value|0x111E
end_define

begin_define
define|#
directive|define
name|HDMI_FC_GMD_PB26
value|0x111F
end_define

begin_define
define|#
directive|define
name|HDMI_FC_GMD_PB27
value|0x1120
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DBGFORCE
value|0x1200
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DBGAUD0CH0
value|0x1201
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DBGAUD1CH0
value|0x1202
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DBGAUD2CH0
value|0x1203
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DBGAUD0CH1
value|0x1204
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DBGAUD1CH1
value|0x1205
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DBGAUD2CH1
value|0x1206
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DBGAUD0CH2
value|0x1207
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DBGAUD1CH2
value|0x1208
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DBGAUD2CH2
value|0x1209
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DBGAUD0CH3
value|0x120A
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DBGAUD1CH3
value|0x120B
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DBGAUD2CH3
value|0x120C
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DBGAUD0CH4
value|0x120D
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DBGAUD1CH4
value|0x120E
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DBGAUD2CH4
value|0x120F
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DBGAUD0CH5
value|0x1210
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DBGAUD1CH5
value|0x1211
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DBGAUD2CH5
value|0x1212
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DBGAUD0CH6
value|0x1213
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DBGAUD1CH6
value|0x1214
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DBGAUD2CH6
value|0x1215
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DBGAUD0CH7
value|0x1216
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DBGAUD1CH7
value|0x1217
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DBGAUD2CH7
value|0x1218
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DBGTMDS0
value|0x1219
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DBGTMDS1
value|0x121A
end_define

begin_define
define|#
directive|define
name|HDMI_FC_DBGTMDS2
value|0x121B
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_CONF0
value|0x3000
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_CONF0_PDZ_MASK
value|0x80
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_CONF0_PDZ_OFFSET
value|7
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_CONF0_ENTMDS_MASK
value|0x40
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_CONF0_ENTMDS_OFFSET
value|6
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_CONF0_SPARECTRL
value|0x20
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_CONF0_GEN2_PDDQ_MASK
value|0x10
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_CONF0_GEN2_PDDQ_OFFSET
value|4
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_CONF0_GEN2_TXPWRON_MASK
value|0x8
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_CONF0_GEN2_TXPWRON_OFFSET
value|3
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_CONF0_GEN2_ENHPDRXSENSE_MASK
value|0x4
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_CONF0_GEN2_ENHPDRXSENSE_OFFSET
value|2
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_CONF0_SELDATAENPOL_MASK
value|0x2
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_CONF0_SELDATAENPOL_OFFSET
value|1
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_CONF0_SELDIPIF_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_CONF0_SELDIPIF_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_TST0
value|0x3001
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_TST0_TSTCLR_MASK
value|0x20
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_TST0_TSTCLR_OFFSET
value|5
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_TST0_TSTEN_MASK
value|0x10
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_TST0_TSTEN_OFFSET
value|4
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_TST0_TSTCLK_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_TST0_TSTCLK_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_TST1
value|0x3002
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_TST2
value|0x3003
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_STAT0
value|0x3004
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_STAT0_RX_SENSE3
value|0x80
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_STAT0_RX_SENSE2
value|0x40
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_STAT0_RX_SENSE1
value|0x20
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_STAT0_RX_SENSE0
value|0x10
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_STAT0_RX_SENSE
value|0xf0
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_STAT0_HPD
value|0x02
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_TX_PHY_LOCK
value|0x01
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_INT0
value|0x3005
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_MASK0
value|0x3006
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_POL0
value|0x3007
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_POL0_HPD
value|0x02
end_define

begin_comment
comment|/* HDMI Master PHY Registers */
end_comment

begin_define
define|#
directive|define
name|HDMI_PHY_I2CM_SLAVE_ADDR
value|0x3020
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_I2CM_SLAVE_ADDR_PHY_GEN2
value|0x69
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_I2CM_SLAVE_ADDR_HEAC_PHY
value|0x49
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_I2CM_ADDRESS_ADDR
value|0x3021
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_I2CM_DATAO_1_ADDR
value|0x3022
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_I2CM_DATAO_0_ADDR
value|0x3023
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_I2CM_DATAI_1_ADDR
value|0x3024
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_I2CM_DATAI_0_ADDR
value|0x3025
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_I2CM_OPERATION_ADDR
value|0x3026
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_I2CM_INT_ADDR
value|0x3027
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_I2CM_CTLINT_ADDR
value|0x3028
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_I2CM_DIV_ADDR
value|0x3029
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_I2CM_SOFTRSTZ_ADDR
value|0x302a
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_I2CM_SS_SCL_HCNT_1_ADDR
value|0x302b
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_I2CM_SS_SCL_HCNT_0_ADDR
value|0x302c
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_I2CM_SS_SCL_LCNT_1_ADDR
value|0x302d
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_I2CM_SS_SCL_LCNT_0_ADDR
value|0x302e
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_I2CM_FS_SCL_HCNT_1_ADDR
value|0x302f
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_I2CM_FS_SCL_HCNT_0_ADDR
value|0x3030
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_I2CM_FS_SCL_LCNT_1_ADDR
value|0x3031
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_I2CM_FS_SCL_LCNT_0_ADDR
value|0x3032
end_define

begin_comment
comment|/* Audio Sampler Registers */
end_comment

begin_define
define|#
directive|define
name|HDMI_AUD_CONF0
value|0x3100
end_define

begin_define
define|#
directive|define
name|HDMI_AUD_CONF1
value|0x3101
end_define

begin_define
define|#
directive|define
name|HDMI_AUD_INT
value|0x3102
end_define

begin_define
define|#
directive|define
name|HDMI_AUD_CONF2
value|0x3103
end_define

begin_define
define|#
directive|define
name|HDMI_AUD_N1
value|0x3200
end_define

begin_define
define|#
directive|define
name|HDMI_AUD_N2
value|0x3201
end_define

begin_define
define|#
directive|define
name|HDMI_AUD_N3
value|0x3202
end_define

begin_define
define|#
directive|define
name|HDMI_AUD_CTS1
value|0x3203
end_define

begin_define
define|#
directive|define
name|HDMI_AUD_CTS2
value|0x3204
end_define

begin_define
define|#
directive|define
name|HDMI_AUD_CTS3
value|0x3205
end_define

begin_define
define|#
directive|define
name|HDMI_AUD_INPUTCLKFS
value|0x3206
end_define

begin_define
define|#
directive|define
name|HDMI_AUD_SPDIFINT
value|0x3302
end_define

begin_define
define|#
directive|define
name|HDMI_AUD_CONF0_HBR
value|0x3400
end_define

begin_define
define|#
directive|define
name|HDMI_AUD_HBR_STATUS
value|0x3401
end_define

begin_define
define|#
directive|define
name|HDMI_AUD_HBR_INT
value|0x3402
end_define

begin_define
define|#
directive|define
name|HDMI_AUD_HBR_POL
value|0x3403
end_define

begin_define
define|#
directive|define
name|HDMI_AUD_HBR_MASK
value|0x3404
end_define

begin_comment
comment|/*  * Generic Parallel Audio Interface Registers  * Not used as GPAUD interface is not enabled in hw  */
end_comment

begin_define
define|#
directive|define
name|HDMI_GP_CONF0
value|0x3500
end_define

begin_define
define|#
directive|define
name|HDMI_GP_CONF1
value|0x3501
end_define

begin_define
define|#
directive|define
name|HDMI_GP_CONF2
value|0x3502
end_define

begin_define
define|#
directive|define
name|HDMI_GP_STAT
value|0x3503
end_define

begin_define
define|#
directive|define
name|HDMI_GP_INT
value|0x3504
end_define

begin_define
define|#
directive|define
name|HDMI_GP_MASK
value|0x3505
end_define

begin_define
define|#
directive|define
name|HDMI_GP_POL
value|0x3506
end_define

begin_comment
comment|/* Main Controller Registers */
end_comment

begin_define
define|#
directive|define
name|HDMI_MC_SFRDIV
value|0x4000
end_define

begin_define
define|#
directive|define
name|HDMI_MC_CLKDIS
value|0x4001
end_define

begin_define
define|#
directive|define
name|HDMI_MC_CLKDIS_HDCPCLK_DISABLE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|HDMI_MC_CLKDIS_CECCLK_DISABLE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|HDMI_MC_CLKDIS_CSCCLK_DISABLE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|HDMI_MC_CLKDIS_AUDCLK_DISABLE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|HDMI_MC_CLKDIS_PREPCLK_DISABLE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|HDMI_MC_CLKDIS_TMDSCLK_DISABLE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|HDMI_MC_CLKDIS_PIXELCLK_DISABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_MC_SWRSTZ
value|0x4002
end_define

begin_define
define|#
directive|define
name|HDMI_MC_SWRSTZ_TMDSSWRST_REQ
value|0x02
end_define

begin_define
define|#
directive|define
name|HDMI_MC_OPCTRL
value|0x4003
end_define

begin_define
define|#
directive|define
name|HDMI_MC_FLOWCTRL
value|0x4004
end_define

begin_define
define|#
directive|define
name|HDMI_MC_FLOWCTRL_FEED_THROUGH_OFF_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|HDMI_MC_FLOWCTRL_FEED_THROUGH_OFF_CSC_IN_PATH
value|0x1
end_define

begin_define
define|#
directive|define
name|HDMI_MC_FLOWCTRL_FEED_THROUGH_OFF_CSC_BYPASS
value|0x0
end_define

begin_define
define|#
directive|define
name|HDMI_MC_PHYRSTZ
value|0x4005
end_define

begin_define
define|#
directive|define
name|HDMI_MC_PHYRSTZ_ASSERT
value|0x0
end_define

begin_define
define|#
directive|define
name|HDMI_MC_PHYRSTZ_DEASSERT
value|0x1
end_define

begin_define
define|#
directive|define
name|HDMI_MC_LOCKONCLOCK
value|0x4006
end_define

begin_define
define|#
directive|define
name|HDMI_MC_HEACPHY_RST
value|0x4007
end_define

begin_define
define|#
directive|define
name|HDMI_MC_HEACPHY_RST_ASSERT
value|0x1
end_define

begin_define
define|#
directive|define
name|HDMI_MC_HEACPHY_RST_DEASSERT
value|0x0
end_define

begin_comment
comment|/* HDCP Encryption Engine Registers */
end_comment

begin_define
define|#
directive|define
name|HDMI_A_HDCPCFG0
value|0x5000
end_define

begin_define
define|#
directive|define
name|HDMI_A_HDCPCFG0_RXDETECT_MASK
value|0x4
end_define

begin_define
define|#
directive|define
name|HDMI_A_HDCPCFG0_RXDETECT_ENABLE
value|0x4
end_define

begin_define
define|#
directive|define
name|HDMI_A_HDCPCFG0_RXDETECT_DISABLE
value|0x0
end_define

begin_define
define|#
directive|define
name|HDMI_A_HDCPCFG1
value|0x5001
end_define

begin_define
define|#
directive|define
name|HDMI_A_HDCPCFG1_ENCRYPTIONDISABLE_MASK
value|0x2
end_define

begin_define
define|#
directive|define
name|HDMI_A_HDCPCFG1_ENCRYPTIONDISABLE_DISABLE
value|0x2
end_define

begin_define
define|#
directive|define
name|HDMI_A_HDCPCFG1_ENCRYPTIONDISABLE_ENABLE
value|0x0
end_define

begin_define
define|#
directive|define
name|HDMI_A_HDCPOBS0
value|0x5002
end_define

begin_define
define|#
directive|define
name|HDMI_A_HDCPOBS1
value|0x5003
end_define

begin_define
define|#
directive|define
name|HDMI_A_HDCPOBS2
value|0x5004
end_define

begin_define
define|#
directive|define
name|HDMI_A_HDCPOBS3
value|0x5005
end_define

begin_define
define|#
directive|define
name|HDMI_A_APIINTCLR
value|0x5006
end_define

begin_define
define|#
directive|define
name|HDMI_A_APIINTSTAT
value|0x5007
end_define

begin_define
define|#
directive|define
name|HDMI_A_APIINTMSK
value|0x5008
end_define

begin_define
define|#
directive|define
name|HDMI_A_VIDPOLCFG
value|0x5009
end_define

begin_define
define|#
directive|define
name|HDMI_A_VIDPOLCFG_DATAENPOL_MASK
value|0x10
end_define

begin_define
define|#
directive|define
name|HDMI_A_VIDPOLCFG_DATAENPOL_ACTIVE_HIGH
value|0x10
end_define

begin_define
define|#
directive|define
name|HDMI_A_VIDPOLCFG_DATAENPOL_ACTIVE_LOW
value|0x0
end_define

begin_define
define|#
directive|define
name|HDMI_A_OESSWCFG
value|0x500A
end_define

begin_define
define|#
directive|define
name|HDMI_A_TIMER1SETUP0
value|0x500B
end_define

begin_define
define|#
directive|define
name|HDMI_A_TIMER1SETUP1
value|0x500C
end_define

begin_define
define|#
directive|define
name|HDMI_A_TIMER2SETUP0
value|0x500D
end_define

begin_define
define|#
directive|define
name|HDMI_A_TIMER2SETUP1
value|0x500E
end_define

begin_define
define|#
directive|define
name|HDMI_A_100MSCFG
value|0x500F
end_define

begin_define
define|#
directive|define
name|HDMI_A_2SCFG0
value|0x5010
end_define

begin_define
define|#
directive|define
name|HDMI_A_2SCFG1
value|0x5011
end_define

begin_define
define|#
directive|define
name|HDMI_A_5SCFG0
value|0x5012
end_define

begin_define
define|#
directive|define
name|HDMI_A_5SCFG1
value|0x5013
end_define

begin_define
define|#
directive|define
name|HDMI_A_SRMVERLSB
value|0x5014
end_define

begin_define
define|#
directive|define
name|HDMI_A_SRMVERMSB
value|0x5015
end_define

begin_define
define|#
directive|define
name|HDMI_A_SRMCTRL
value|0x5016
end_define

begin_define
define|#
directive|define
name|HDMI_A_SFRSETUP
value|0x5017
end_define

begin_define
define|#
directive|define
name|HDMI_A_I2CHSETUP
value|0x5018
end_define

begin_define
define|#
directive|define
name|HDMI_A_INTSETUP
value|0x5019
end_define

begin_define
define|#
directive|define
name|HDMI_A_PRESETUP
value|0x501A
end_define

begin_define
define|#
directive|define
name|HDMI_A_SRM_BASE
value|0x5020
end_define

begin_comment
comment|/* CEC Engine Registers */
end_comment

begin_define
define|#
directive|define
name|HDMI_CEC_CTRL
value|0x7D00
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_STAT
value|0x7D01
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_MASK
value|0x7D02
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_POLARITY
value|0x7D03
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_INT
value|0x7D04
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_ADDR_L
value|0x7D05
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_ADDR_H
value|0x7D06
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_TX_CNT
value|0x7D07
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_RX_CNT
value|0x7D08
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_TX_DATA0
value|0x7D10
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_TX_DATA1
value|0x7D11
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_TX_DATA2
value|0x7D12
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_TX_DATA3
value|0x7D13
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_TX_DATA4
value|0x7D14
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_TX_DATA5
value|0x7D15
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_TX_DATA6
value|0x7D16
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_TX_DATA7
value|0x7D17
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_TX_DATA8
value|0x7D18
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_TX_DATA9
value|0x7D19
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_TX_DATA10
value|0x7D1a
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_TX_DATA11
value|0x7D1b
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_TX_DATA12
value|0x7D1c
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_TX_DATA13
value|0x7D1d
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_TX_DATA14
value|0x7D1e
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_TX_DATA15
value|0x7D1f
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_RX_DATA0
value|0x7D20
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_RX_DATA1
value|0x7D21
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_RX_DATA2
value|0x7D22
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_RX_DATA3
value|0x7D23
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_RX_DATA4
value|0x7D24
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_RX_DATA5
value|0x7D25
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_RX_DATA6
value|0x7D26
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_RX_DATA7
value|0x7D27
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_RX_DATA8
value|0x7D28
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_RX_DATA9
value|0x7D29
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_RX_DATA10
value|0x7D2a
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_RX_DATA11
value|0x7D2b
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_RX_DATA12
value|0x7D2c
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_RX_DATA13
value|0x7D2d
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_RX_DATA14
value|0x7D2e
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_RX_DATA15
value|0x7D2f
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_LOCK
value|0x7D30
end_define

begin_define
define|#
directive|define
name|HDMI_CEC_WKUPCTRL
value|0x7D31
end_define

begin_comment
comment|/* I2C Master Registers (E-DDC) */
end_comment

begin_define
define|#
directive|define
name|HDMI_I2CM_SLAVE
value|0x7E00
end_define

begin_define
define|#
directive|define
name|HDMI_I2CMESS
value|0x7E01
end_define

begin_define
define|#
directive|define
name|HDMI_I2CM_DATAO
value|0x7E02
end_define

begin_define
define|#
directive|define
name|HDMI_I2CM_DATAI
value|0x7E03
end_define

begin_define
define|#
directive|define
name|HDMI_I2CM_OPERATION
value|0x7E04
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_I2CM_OPERATION_ADDR_WRITE
value|0x10
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_I2CM_OPERATION_ADDR_READ
value|0x1
end_define

begin_define
define|#
directive|define
name|HDMI_I2CM_INT
value|0x7E05
end_define

begin_define
define|#
directive|define
name|HDMI_I2CM_CTLINT
value|0x7E06
end_define

begin_define
define|#
directive|define
name|HDMI_I2CM_DIV
value|0x7E07
end_define

begin_define
define|#
directive|define
name|HDMI_I2CM_SEGADDR
value|0x7E08
end_define

begin_define
define|#
directive|define
name|HDMI_I2CM_SOFTRSTZ
value|0x7E09
end_define

begin_define
define|#
directive|define
name|HDMI_I2CM_SEGPTR
value|0x7E0A
end_define

begin_define
define|#
directive|define
name|HDMI_I2CM_SS_SCL_HCNT_1_ADDR
value|0x7E0B
end_define

begin_define
define|#
directive|define
name|HDMI_I2CM_SS_SCL_HCNT_0_ADDR
value|0x7E0C
end_define

begin_define
define|#
directive|define
name|HDMI_I2CM_SS_SCL_LCNT_1_ADDR
value|0x7E0D
end_define

begin_define
define|#
directive|define
name|HDMI_I2CM_SS_SCL_LCNT_0_ADDR
value|0x7E0E
end_define

begin_define
define|#
directive|define
name|HDMI_I2CM_FS_SCL_HCNT_1_ADDR
value|0x7E0F
end_define

begin_define
define|#
directive|define
name|HDMI_I2CM_FS_SCL_HCNT_0_ADDR
value|0x7E10
end_define

begin_define
define|#
directive|define
name|HDMI_I2CM_FS_SCL_LCNT_1_ADDR
value|0x7E11
end_define

begin_define
define|#
directive|define
name|HDMI_I2CM_FS_SCL_LCNT_0_ADDR
value|0x7E12
end_define

begin_comment
comment|/* HDMI PHY register with access through I2C */
end_comment

begin_define
define|#
directive|define
name|HDMI_PHY_I2C_CKCALCTRL
value|0x5
end_define

begin_define
define|#
directive|define
name|CKCALCTRL_OVERRIDE
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_I2C_CPCE_CTRL
value|0x6
end_define

begin_define
define|#
directive|define
name|CPCE_CTRL_45_25
value|((3<< 7) | (3<< 5))
end_define

begin_define
define|#
directive|define
name|CPCE_CTRL_92_50
value|((2<< 7) | (2<< 5))
end_define

begin_define
define|#
directive|define
name|CPCE_CTRL_185
value|((1<< 7) | (1<< 5))
end_define

begin_define
define|#
directive|define
name|CPCE_CTRL_370
value|((0<< 7) | (0<< 5))
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_I2C_CKSYMTXCTRL
value|0x9
end_define

begin_define
define|#
directive|define
name|CKSYMTXCTRL_OVERRIDE
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|CKSYMTXCTRL_TX_SYMON
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|CKSYMTXCTRL_TX_TRAON
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|CKSYMTXCTRL_TX_TRBON
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|CKSYMTXCTRL_TX_CK_SYMON
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_I2C_VLEVCTRL
value|0x0E
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_I2C_CURRCTRL
value|0x10
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_I2C_PLLPHBYCTRL
value|0x13
end_define

begin_define
define|#
directive|define
name|VLEVCTRL_TX_LVL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 5)
end_define

begin_define
define|#
directive|define
name|VLEVCTRL_CK_LVL
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_I2C_GMPCTRL
value|0x15
end_define

begin_define
define|#
directive|define
name|GMPCTRL_45_25
value|0x00
end_define

begin_define
define|#
directive|define
name|GMPCTRL_92_50
value|0x05
end_define

begin_define
define|#
directive|define
name|GMPCTRL_185
value|0x0a
end_define

begin_define
define|#
directive|define
name|GMPCTRL_370
value|0x0f
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_I2C_MSM_CTRL
value|0x17
end_define

begin_define
define|#
directive|define
name|MSM_CTRL_FB_CLK
value|(0x3<< 1)
end_define

begin_define
define|#
directive|define
name|HDMI_PHY_I2C_TXTERM
value|0x19
end_define

begin_define
define|#
directive|define
name|TXTERM_133
value|0x5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DWC_HDMIREG_H__ */
end_comment

end_unit

