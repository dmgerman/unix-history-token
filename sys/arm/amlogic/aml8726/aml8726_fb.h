begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2013-2015 John Wehle<john@feith.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARM_AMLOGIC_AML8726_FB_H
end_ifndef

begin_define
define|#
directive|define
name|_ARM_AMLOGIC_AML8726_FB_H
end_define

begin_define
define|#
directive|define
name|AML_CAV_OSD1_INDEX
value|0x40
end_define

begin_define
define|#
directive|define
name|AML_CAV_LUT_DATAL_REG
value|0
end_define

begin_define
define|#
directive|define
name|AML_CAV_LUT_DATAL_WIDTH_MASK
value|(7<< 29)
end_define

begin_define
define|#
directive|define
name|AML_CAV_LUT_DATAL_WIDTH_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|AML_CAV_LUT_DATAL_WIDTH_WIDTH
value|3
end_define

begin_define
define|#
directive|define
name|AML_CAV_LUT_DATAL_ADDR_MASK
value|0x1fffffff
end_define

begin_define
define|#
directive|define
name|AML_CAV_LUT_DATAL_ADDR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|AML_CAV_LUT_DATAH_REG
value|4
end_define

begin_define
define|#
directive|define
name|AML_CAV_LUT_DATAH_BLKMODE_MASK
value|(3<< 24)
end_define

begin_define
define|#
directive|define
name|AML_CAV_LUT_DATAH_BLKMODE_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|AML_CAV_LUT_DATAH_BLKMODE_LINEAR
value|(0<< 24)
end_define

begin_define
define|#
directive|define
name|AML_CAV_LUT_DATAH_BLKMODE_32x32
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|AML_CAV_LUT_DATAH_BLKMODE_64x32
value|(2<< 24)
end_define

begin_define
define|#
directive|define
name|AML_CAV_LUT_DATAH_WRAP_X
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|AML_CAV_LUT_DATAH_WRAP_Y
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|AML_CAV_LUT_DATAH_HEIGHT_MASK
value|(0x1fff<< 9)
end_define

begin_define
define|#
directive|define
name|AML_CAV_LUT_DATAH_HEIGHT_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|AML_CAV_LUT_DATAH_WIDTH_MASK
value|0x1ff
end_define

begin_define
define|#
directive|define
name|AML_CAV_LUT_DATAH_WIDTH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|AML_CAV_LUT_ADDR_REG
value|8
end_define

begin_define
define|#
directive|define
name|AML_CAV_LUT_ADDR_WR_EN
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|AML_CAV_LUT_ADDR_RD_EN
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AML_CAV_LUT_ADDR_INDEX_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|AML_CAV_LUT_ADDR_INDEX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD1_CTRL_REG
value|64
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_CTRL_OSD_EN
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_CTRL_GLOBAL_ALPHA_MASK
value|(0x1ff<< 12)
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_CTRL_GLOBAL_ALPHA_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_CTRL_OSD_BLK_EN_MASK
value|(0xf<< 0)
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_CTRL_OSD_BLK_EN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD1_BLK0_CFG_W0_REG
value|108
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD1_BLK1_CFG_W0_REG
value|124
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD1_BLK2_CFG_W0_REG
value|140
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD1_BLK3_CFG_W0_REG
value|156
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_BLK_CFG_W0_INDEX_MASK
value|(0xff<< 16)
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_BLK_CFG_W0_INDEX_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_BLK_CFG_W0_LITTLE_ENDIAN
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_BLK_CFG_W0_BLKMODE_24
value|(7<< 8)
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_BLK_CFG_W0_RGB_EN
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_BLK_CFG_W0_CMATRIX_RGB
value|(0<< 2)
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD1_BLK0_CFG_W1_REG
value|112
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD1_BLK1_CFG_W1_REG
value|128
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD1_BLK2_CFG_W1_REG
value|144
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD1_BLK3_CFG_W1_REG
value|160
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_BLK_CFG_W1_X_END_MASK
value|(0x1fff<< 16)
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_BLK_CFG_W1_X_END_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_BLK_CFG_W1_X_START_MASK
value|0x1fff
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_BLK_CFG_W1_X_START_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD1_BLK0_CFG_W2_REG
value|116
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD1_BLK1_CFG_W2_REG
value|132
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD1_BLK2_CFG_W2_REG
value|148
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD1_BLK3_CFG_W2_REG
value|164
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_BLK_CFG_W2_Y_END_MASK
value|(0x1fff<< 16)
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_BLK_CFG_W2_Y_END_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_BLK_CFG_W2_Y_START_MASK
value|0x1fff
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_BLK_CFG_W2_Y_START_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD1_BLK0_CFG_W3_REG
value|120
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD1_BLK1_CFG_W3_REG
value|136
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD1_BLK2_CFG_W3_REG
value|152
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD1_BLK3_CFG_W3_REG
value|168
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_BLK_CFG_W3_H_END_MASK
value|(0xfff<< 16)
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_BLK_CFG_W3_H_END_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_BLK_CFG_W3_H_START_MASK
value|0xfff
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_BLK_CFG_W3_H_START_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD1_BLK0_CFG_W4_REG
value|76
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD1_BLK1_CFG_W4_REG
value|80
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD1_BLK2_CFG_W4_REG
value|84
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD1_BLK3_CFG_W4_REG
value|88
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_BLK_CFG_W4_V_END_MASK
value|(0xfff<< 16)
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_BLK_CFG_W4_V_END_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_BLK_CFG_W4_V_START_MASK
value|0xfff
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_BLK_CFG_W4_V_START_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD1_FIFO_CTRL_REG
value|172
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_FIFO_CTRL_DEPTH_MASK
value|(0x3f<< 12)
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_FIFO_CTRL_DEPTH_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_FIFO_CTRL_BURST_LEN_MASK
value|(3<< 10)
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_FIFO_CTRL_BURST_LEN_24
value|(0<< 10)
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_FIFO_CTRL_BURST_LEN_32
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_FIFO_CTRL_BURST_LEN_48
value|(2<< 10)
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_FIFO_CTRL_BURST_LEN_64
value|(3<< 10)
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_FIFO_CTRL_HOLD_LINES_MASK
value|(0x1f<< 5)
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_FIFO_CTRL_HOLD_LINES_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD_FIFO_CTRL_URGENT
value|(1<< 0)
end_define

begin_comment
comment|/* OSD2 field meanings are the same as OSD1 */
end_comment

begin_define
define|#
directive|define
name|AML_VIU_OSD2_CTRL_REG
value|192
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD2_BLK0_CFG_W0_REG
value|236
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD2_BLK1_CFG_W0_REG
value|252
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD2_BLK2_CFG_W0_REG
value|268
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD2_BLK3_CFG_W0_REG
value|284
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD2_BLK0_CFG_W1_REG
value|240
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD2_BLK1_CFG_W1_REG
value|256
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD2_BLK2_CFG_W1_REG
value|272
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD2_BLK3_CFG_W1_REG
value|288
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD2_BLK0_CFG_W2_REG
value|244
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD2_BLK1_CFG_W2_REG
value|260
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD2_BLK2_CFG_W2_REG
value|276
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD2_BLK3_CFG_W2_REG
value|292
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD2_BLK0_CFG_W3_REG
value|248
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD2_BLK1_CFG_W3_REG
value|264
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD2_BLK2_CFG_W3_REG
value|280
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD2_BLK3_CFG_W3_REG
value|296
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD2_BLK0_CFG_W4_REG
value|400
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD2_BLK1_CFG_W4_REG
value|404
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD2_BLK2_CFG_W4_REG
value|408
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD2_BLK3_CFG_W4_REG
value|412
end_define

begin_define
define|#
directive|define
name|AML_VIU_OSD2_FIFO_CTRL_REG
value|300
end_define

begin_define
define|#
directive|define
name|AML_VPP_MISC_REG
value|152
end_define

begin_define
define|#
directive|define
name|AML_VPP_MISC_OSD2_PREBLEND
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|AML_VPP_MISC_OSD1_PREBLEND
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AML_VPP_MISC_VD2_PREBLEND
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|AML_VPP_MISC_VD1_PREBLEND
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|AML_VPP_MISC_OSD2_POSTBLEND
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|AML_VPP_MISC_OSD1_POSTBLEND
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|AML_VPP_MISC_VD2_POSTBLEND
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|AML_VPP_MISC_VD1_POSTBLEND
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|AML_VPP_MISC_POSTBLEND_EN
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AML_VPP_MISC_PREBLEND_EN
value|(1<< 6)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ARM_AMLOGIC_AML8726_FB_H */
end_comment

end_unit

