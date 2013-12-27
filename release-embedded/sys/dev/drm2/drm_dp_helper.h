begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright Â© 2008 Keith Packard  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that copyright  * notice and this permission notice appear in supporting documentation, and  * that the name of the copyright holders not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  The copyright holders make no representations  * about the suitability of this software for any purpose.  It is provided "as  * is" without express or implied warranty.  *  * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,  * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO  * EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY SPECIAL, INDIRECT OR  * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,  * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER  * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE  * OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DRM_DP_HELPER_H_
end_ifndef

begin_define
define|#
directive|define
name|_DRM_DP_HELPER_H_
end_define

begin_comment
comment|/*  * Unless otherwise noted, all values are from the DP 1.1a spec.  Note that  * DP and DPCD versions are independent.  Differences from 1.0 are not noted,  * 1.0 devices basically don't exist in the wild.  *  * Abbreviations, in chronological order:  *  * eDP: Embedded DisplayPort version 1  * DPI: DisplayPort Interoperability Guideline v1.1a  * 1.2: DisplayPort 1.2  *  * 1.2 formally includes both eDP and DPI definitions.  */
end_comment

begin_define
define|#
directive|define
name|AUX_NATIVE_WRITE
value|0x8
end_define

begin_define
define|#
directive|define
name|AUX_NATIVE_READ
value|0x9
end_define

begin_define
define|#
directive|define
name|AUX_I2C_WRITE
value|0x0
end_define

begin_define
define|#
directive|define
name|AUX_I2C_READ
value|0x1
end_define

begin_define
define|#
directive|define
name|AUX_I2C_STATUS
value|0x2
end_define

begin_define
define|#
directive|define
name|AUX_I2C_MOT
value|0x4
end_define

begin_define
define|#
directive|define
name|AUX_NATIVE_REPLY_ACK
value|(0x0<< 4)
end_define

begin_define
define|#
directive|define
name|AUX_NATIVE_REPLY_NACK
value|(0x1<< 4)
end_define

begin_define
define|#
directive|define
name|AUX_NATIVE_REPLY_DEFER
value|(0x2<< 4)
end_define

begin_define
define|#
directive|define
name|AUX_NATIVE_REPLY_MASK
value|(0x3<< 4)
end_define

begin_define
define|#
directive|define
name|AUX_I2C_REPLY_ACK
value|(0x0<< 6)
end_define

begin_define
define|#
directive|define
name|AUX_I2C_REPLY_NACK
value|(0x1<< 6)
end_define

begin_define
define|#
directive|define
name|AUX_I2C_REPLY_DEFER
value|(0x2<< 6)
end_define

begin_define
define|#
directive|define
name|AUX_I2C_REPLY_MASK
value|(0x3<< 6)
end_define

begin_comment
comment|/* AUX CH addresses */
end_comment

begin_comment
comment|/* DPCD */
end_comment

begin_define
define|#
directive|define
name|DP_DPCD_REV
value|0x000
end_define

begin_define
define|#
directive|define
name|DP_MAX_LINK_RATE
value|0x001
end_define

begin_define
define|#
directive|define
name|DP_MAX_LANE_COUNT
value|0x002
end_define

begin_define
define|#
directive|define
name|DP_MAX_LANE_COUNT_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|DP_TPS3_SUPPORTED
value|(1<< 6)
end_define

begin_comment
comment|/* 1.2 */
end_comment

begin_define
define|#
directive|define
name|DP_ENHANCED_FRAME_CAP
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|DP_MAX_DOWNSPREAD
value|0x003
end_define

begin_define
define|#
directive|define
name|DP_NO_AUX_HANDSHAKE_LINK_TRAINING
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|DP_NORP
value|0x004
end_define

begin_define
define|#
directive|define
name|DP_DOWNSTREAMPORT_PRESENT
value|0x005
end_define

begin_define
define|#
directive|define
name|DP_DWN_STRM_PORT_PRESENT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DP_DWN_STRM_PORT_TYPE_MASK
value|0x06
end_define

begin_comment
comment|/* 00b = DisplayPort */
end_comment

begin_comment
comment|/* 01b = Analog */
end_comment

begin_comment
comment|/* 10b = TMDS or HDMI */
end_comment

begin_comment
comment|/* 11b = Other */
end_comment

begin_define
define|#
directive|define
name|DP_FORMAT_CONVERSION
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|DP_DETAILED_CAP_INFO_AVAILABLE
value|(1<< 4)
end_define

begin_comment
comment|/* DPI */
end_comment

begin_define
define|#
directive|define
name|DP_MAIN_LINK_CHANNEL_CODING
value|0x006
end_define

begin_define
define|#
directive|define
name|DP_DOWN_STREAM_PORT_COUNT
value|0x007
end_define

begin_define
define|#
directive|define
name|DP_PORT_COUNT_MASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|DP_MSA_TIMING_PAR_IGNORED
value|(1<< 6)
end_define

begin_comment
comment|/* eDP */
end_comment

begin_define
define|#
directive|define
name|DP_OUI_SUPPORT
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|DP_I2C_SPEED_CAP
value|0x00c
end_define

begin_comment
comment|/* DPI */
end_comment

begin_define
define|#
directive|define
name|DP_I2C_SPEED_1K
value|0x01
end_define

begin_define
define|#
directive|define
name|DP_I2C_SPEED_5K
value|0x02
end_define

begin_define
define|#
directive|define
name|DP_I2C_SPEED_10K
value|0x04
end_define

begin_define
define|#
directive|define
name|DP_I2C_SPEED_100K
value|0x08
end_define

begin_define
define|#
directive|define
name|DP_I2C_SPEED_400K
value|0x10
end_define

begin_define
define|#
directive|define
name|DP_I2C_SPEED_1M
value|0x20
end_define

begin_define
define|#
directive|define
name|DP_EDP_CONFIGURATION_CAP
value|0x00d
end_define

begin_comment
comment|/* XXX 1.2? */
end_comment

begin_define
define|#
directive|define
name|DP_TRAINING_AUX_RD_INTERVAL
value|0x00e
end_define

begin_comment
comment|/* XXX 1.2? */
end_comment

begin_comment
comment|/* Multiple stream transport */
end_comment

begin_define
define|#
directive|define
name|DP_MSTM_CAP
value|0x021
end_define

begin_comment
comment|/* 1.2 */
end_comment

begin_define
define|#
directive|define
name|DP_MST_CAP
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DP_PSR_SUPPORT
value|0x070
end_define

begin_comment
comment|/* XXX 1.2? */
end_comment

begin_define
define|#
directive|define
name|DP_PSR_IS_SUPPORTED
value|1
end_define

begin_define
define|#
directive|define
name|DP_PSR_CAPS
value|0x071
end_define

begin_comment
comment|/* XXX 1.2? */
end_comment

begin_define
define|#
directive|define
name|DP_PSR_NO_TRAIN_ON_EXIT
value|1
end_define

begin_define
define|#
directive|define
name|DP_PSR_SETUP_TIME_330
value|(0<< 1)
end_define

begin_define
define|#
directive|define
name|DP_PSR_SETUP_TIME_275
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|DP_PSR_SETUP_TIME_220
value|(2<< 1)
end_define

begin_define
define|#
directive|define
name|DP_PSR_SETUP_TIME_165
value|(3<< 1)
end_define

begin_define
define|#
directive|define
name|DP_PSR_SETUP_TIME_110
value|(4<< 1)
end_define

begin_define
define|#
directive|define
name|DP_PSR_SETUP_TIME_55
value|(5<< 1)
end_define

begin_define
define|#
directive|define
name|DP_PSR_SETUP_TIME_0
value|(6<< 1)
end_define

begin_define
define|#
directive|define
name|DP_PSR_SETUP_TIME_MASK
value|(7<< 1)
end_define

begin_define
define|#
directive|define
name|DP_PSR_SETUP_TIME_SHIFT
value|1
end_define

begin_comment
comment|/*  * 0x80-0x8f describe downstream port capabilities, but there are two layouts  * based on whether DP_DETAILED_CAP_INFO_AVAILABLE was set.  If it was not,  * each port's descriptor is one byte wide.  If it was set, each port's is  * four bytes wide, starting with the one byte from the base info.  As of  * DP interop v1.1a only VGA defines additional detail.  */
end_comment

begin_comment
comment|/* offset 0 */
end_comment

begin_define
define|#
directive|define
name|DP_DOWNSTREAM_PORT_0
value|0x80
end_define

begin_define
define|#
directive|define
name|DP_DS_PORT_TYPE_MASK
value|(7<< 0)
end_define

begin_define
define|#
directive|define
name|DP_DS_PORT_TYPE_DP
value|0
end_define

begin_define
define|#
directive|define
name|DP_DS_PORT_TYPE_VGA
value|1
end_define

begin_define
define|#
directive|define
name|DP_DS_PORT_TYPE_DVI
value|2
end_define

begin_define
define|#
directive|define
name|DP_DS_PORT_TYPE_HDMI
value|3
end_define

begin_define
define|#
directive|define
name|DP_DS_PORT_TYPE_NON_EDID
value|4
end_define

begin_define
define|#
directive|define
name|DP_DS_PORT_HPD
value|(1<< 3)
end_define

begin_comment
comment|/* offset 1 for VGA is maximum megapixels per second / 8 */
end_comment

begin_comment
comment|/* offset 2 */
end_comment

begin_define
define|#
directive|define
name|DP_DS_VGA_MAX_BPC_MASK
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|DP_DS_VGA_8BPC
value|0
end_define

begin_define
define|#
directive|define
name|DP_DS_VGA_10BPC
value|1
end_define

begin_define
define|#
directive|define
name|DP_DS_VGA_12BPC
value|2
end_define

begin_define
define|#
directive|define
name|DP_DS_VGA_16BPC
value|3
end_define

begin_comment
comment|/* link configuration */
end_comment

begin_define
define|#
directive|define
name|DP_LINK_BW_SET
value|0x100
end_define

begin_define
define|#
directive|define
name|DP_LINK_BW_1_62
value|0x06
end_define

begin_define
define|#
directive|define
name|DP_LINK_BW_2_7
value|0x0a
end_define

begin_define
define|#
directive|define
name|DP_LINK_BW_5_4
value|0x14
end_define

begin_comment
comment|/* 1.2 */
end_comment

begin_define
define|#
directive|define
name|DP_LANE_COUNT_SET
value|0x101
end_define

begin_define
define|#
directive|define
name|DP_LANE_COUNT_MASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|DP_LANE_COUNT_ENHANCED_FRAME_EN
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|DP_TRAINING_PATTERN_SET
value|0x102
end_define

begin_define
define|#
directive|define
name|DP_TRAINING_PATTERN_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|DP_TRAINING_PATTERN_1
value|1
end_define

begin_define
define|#
directive|define
name|DP_TRAINING_PATTERN_2
value|2
end_define

begin_define
define|#
directive|define
name|DP_TRAINING_PATTERN_3
value|3
end_define

begin_comment
comment|/* 1.2 */
end_comment

begin_define
define|#
directive|define
name|DP_TRAINING_PATTERN_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|DP_LINK_QUAL_PATTERN_DISABLE
value|(0<< 2)
end_define

begin_define
define|#
directive|define
name|DP_LINK_QUAL_PATTERN_D10_2
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|DP_LINK_QUAL_PATTERN_ERROR_RATE
value|(2<< 2)
end_define

begin_define
define|#
directive|define
name|DP_LINK_QUAL_PATTERN_PRBS7
value|(3<< 2)
end_define

begin_define
define|#
directive|define
name|DP_LINK_QUAL_PATTERN_MASK
value|(3<< 2)
end_define

begin_define
define|#
directive|define
name|DP_RECOVERED_CLOCK_OUT_EN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|DP_LINK_SCRAMBLING_DISABLE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|DP_SYMBOL_ERROR_COUNT_BOTH
value|(0<< 6)
end_define

begin_define
define|#
directive|define
name|DP_SYMBOL_ERROR_COUNT_DISPARITY
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|DP_SYMBOL_ERROR_COUNT_SYMBOL
value|(2<< 6)
end_define

begin_define
define|#
directive|define
name|DP_SYMBOL_ERROR_COUNT_MASK
value|(3<< 6)
end_define

begin_define
define|#
directive|define
name|DP_TRAINING_LANE0_SET
value|0x103
end_define

begin_define
define|#
directive|define
name|DP_TRAINING_LANE1_SET
value|0x104
end_define

begin_define
define|#
directive|define
name|DP_TRAINING_LANE2_SET
value|0x105
end_define

begin_define
define|#
directive|define
name|DP_TRAINING_LANE3_SET
value|0x106
end_define

begin_define
define|#
directive|define
name|DP_TRAIN_VOLTAGE_SWING_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|DP_TRAIN_VOLTAGE_SWING_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|DP_TRAIN_MAX_SWING_REACHED
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|DP_TRAIN_VOLTAGE_SWING_400
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|DP_TRAIN_VOLTAGE_SWING_600
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DP_TRAIN_VOLTAGE_SWING_800
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|DP_TRAIN_VOLTAGE_SWING_1200
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|DP_TRAIN_PRE_EMPHASIS_MASK
value|(3<< 3)
end_define

begin_define
define|#
directive|define
name|DP_TRAIN_PRE_EMPHASIS_0
value|(0<< 3)
end_define

begin_define
define|#
directive|define
name|DP_TRAIN_PRE_EMPHASIS_3_5
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|DP_TRAIN_PRE_EMPHASIS_6
value|(2<< 3)
end_define

begin_define
define|#
directive|define
name|DP_TRAIN_PRE_EMPHASIS_9_5
value|(3<< 3)
end_define

begin_define
define|#
directive|define
name|DP_TRAIN_PRE_EMPHASIS_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|DP_TRAIN_MAX_PRE_EMPHASIS_REACHED
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|DP_DOWNSPREAD_CTRL
value|0x107
end_define

begin_define
define|#
directive|define
name|DP_SPREAD_AMP_0_5
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|DP_MSA_TIMING_PAR_IGNORE_EN
value|(1<< 7)
end_define

begin_comment
comment|/* eDP */
end_comment

begin_define
define|#
directive|define
name|DP_MAIN_LINK_CHANNEL_CODING_SET
value|0x108
end_define

begin_define
define|#
directive|define
name|DP_SET_ANSI_8B10B
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DP_I2C_SPEED_CONTROL_STATUS
value|0x109
end_define

begin_comment
comment|/* DPI */
end_comment

begin_comment
comment|/* bitmask as for DP_I2C_SPEED_CAP */
end_comment

begin_define
define|#
directive|define
name|DP_EDP_CONFIGURATION_SET
value|0x10a
end_define

begin_comment
comment|/* XXX 1.2? */
end_comment

begin_define
define|#
directive|define
name|DP_MSTM_CTRL
value|0x111
end_define

begin_comment
comment|/* 1.2 */
end_comment

begin_define
define|#
directive|define
name|DP_MST_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DP_UP_REQ_EN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|DP_UPSTREAM_IS_SRC
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|DP_PSR_EN_CFG
value|0x170
end_define

begin_comment
comment|/* XXX 1.2? */
end_comment

begin_define
define|#
directive|define
name|DP_PSR_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DP_PSR_MAIN_LINK_ACTIVE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|DP_PSR_CRC_VERIFICATION
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|DP_PSR_FRAME_CAPTURE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|DP_SINK_COUNT
value|0x200
end_define

begin_comment
comment|/* prior to 1.2 bit 7 was reserved mbz */
end_comment

begin_define
define|#
directive|define
name|DP_GET_SINK_COUNT
parameter_list|(
name|x
parameter_list|)
value|((((x)& 0x80)>> 1) | ((x)& 0x3f))
end_define

begin_define
define|#
directive|define
name|DP_SINK_CP_READY
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|DP_DEVICE_SERVICE_IRQ_VECTOR
value|0x201
end_define

begin_define
define|#
directive|define
name|DP_REMOTE_CONTROL_COMMAND_PENDING
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DP_AUTOMATED_TEST_REQUEST
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|DP_CP_IRQ
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|DP_SINK_SPECIFIC_IRQ
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|DP_LANE0_1_STATUS
value|0x202
end_define

begin_define
define|#
directive|define
name|DP_LANE2_3_STATUS
value|0x203
end_define

begin_define
define|#
directive|define
name|DP_LANE_CR_DONE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DP_LANE_CHANNEL_EQ_DONE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|DP_LANE_SYMBOL_LOCKED
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|DP_CHANNEL_EQ_BITS
value|(DP_LANE_CR_DONE |		\ 			    DP_LANE_CHANNEL_EQ_DONE |	\ 			    DP_LANE_SYMBOL_LOCKED)
end_define

begin_define
define|#
directive|define
name|DP_LANE_ALIGN_STATUS_UPDATED
value|0x204
end_define

begin_define
define|#
directive|define
name|DP_INTERLANE_ALIGN_DONE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DP_DOWNSTREAM_PORT_STATUS_CHANGED
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|DP_LINK_STATUS_UPDATED
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|DP_SINK_STATUS
value|0x205
end_define

begin_define
define|#
directive|define
name|DP_RECEIVE_PORT_0_STATUS
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DP_RECEIVE_PORT_1_STATUS
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|DP_ADJUST_REQUEST_LANE0_1
value|0x206
end_define

begin_define
define|#
directive|define
name|DP_ADJUST_REQUEST_LANE2_3
value|0x207
end_define

begin_define
define|#
directive|define
name|DP_ADJUST_VOLTAGE_SWING_LANE0_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|DP_ADJUST_VOLTAGE_SWING_LANE0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|DP_ADJUST_PRE_EMPHASIS_LANE0_MASK
value|0x0c
end_define

begin_define
define|#
directive|define
name|DP_ADJUST_PRE_EMPHASIS_LANE0_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|DP_ADJUST_VOLTAGE_SWING_LANE1_MASK
value|0x30
end_define

begin_define
define|#
directive|define
name|DP_ADJUST_VOLTAGE_SWING_LANE1_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|DP_ADJUST_PRE_EMPHASIS_LANE1_MASK
value|0xc0
end_define

begin_define
define|#
directive|define
name|DP_ADJUST_PRE_EMPHASIS_LANE1_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|DP_TEST_REQUEST
value|0x218
end_define

begin_define
define|#
directive|define
name|DP_TEST_LINK_TRAINING
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DP_TEST_LINK_PATTERN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|DP_TEST_LINK_EDID_READ
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|DP_TEST_LINK_PHY_TEST_PATTERN
value|(1<< 3)
end_define

begin_comment
comment|/* DPCD>= 1.1 */
end_comment

begin_define
define|#
directive|define
name|DP_TEST_LINK_RATE
value|0x219
end_define

begin_define
define|#
directive|define
name|DP_LINK_RATE_162
value|(0x6)
end_define

begin_define
define|#
directive|define
name|DP_LINK_RATE_27
value|(0xa)
end_define

begin_define
define|#
directive|define
name|DP_TEST_LANE_COUNT
value|0x220
end_define

begin_define
define|#
directive|define
name|DP_TEST_PATTERN
value|0x221
end_define

begin_define
define|#
directive|define
name|DP_TEST_RESPONSE
value|0x260
end_define

begin_define
define|#
directive|define
name|DP_TEST_ACK
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DP_TEST_NAK
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|DP_TEST_EDID_CHECKSUM_WRITE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|DP_SOURCE_OUI
value|0x300
end_define

begin_define
define|#
directive|define
name|DP_SINK_OUI
value|0x400
end_define

begin_define
define|#
directive|define
name|DP_BRANCH_OUI
value|0x500
end_define

begin_define
define|#
directive|define
name|DP_SET_POWER
value|0x600
end_define

begin_define
define|#
directive|define
name|DP_SET_POWER_D0
value|0x1
end_define

begin_define
define|#
directive|define
name|DP_SET_POWER_D3
value|0x2
end_define

begin_define
define|#
directive|define
name|DP_PSR_ERROR_STATUS
value|0x2006
end_define

begin_comment
comment|/* XXX 1.2? */
end_comment

begin_define
define|#
directive|define
name|DP_PSR_LINK_CRC_ERROR
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DP_PSR_RFB_STORAGE_ERROR
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|DP_PSR_ESI
value|0x2007
end_define

begin_comment
comment|/* XXX 1.2? */
end_comment

begin_define
define|#
directive|define
name|DP_PSR_CAPS_CHANGE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DP_PSR_STATUS
value|0x2008
end_define

begin_comment
comment|/* XXX 1.2? */
end_comment

begin_define
define|#
directive|define
name|DP_PSR_SINK_INACTIVE
value|0
end_define

begin_define
define|#
directive|define
name|DP_PSR_SINK_ACTIVE_SRC_SYNCED
value|1
end_define

begin_define
define|#
directive|define
name|DP_PSR_SINK_ACTIVE_RFB
value|2
end_define

begin_define
define|#
directive|define
name|DP_PSR_SINK_ACTIVE_SINK_SYNCED
value|3
end_define

begin_define
define|#
directive|define
name|DP_PSR_SINK_ACTIVE_RESYNC
value|4
end_define

begin_define
define|#
directive|define
name|DP_PSR_SINK_INTERNAL_ERROR
value|7
end_define

begin_define
define|#
directive|define
name|DP_PSR_SINK_STATE_MASK
value|0x07
end_define

begin_define
define|#
directive|define
name|MODE_I2C_START
value|1
end_define

begin_define
define|#
directive|define
name|MODE_I2C_WRITE
value|2
end_define

begin_define
define|#
directive|define
name|MODE_I2C_READ
value|4
end_define

begin_define
define|#
directive|define
name|MODE_I2C_STOP
value|8
end_define

begin_struct
struct|struct
name|iic_dp_aux_data
block|{
name|bool
name|running
decl_stmt|;
name|u16
name|address
decl_stmt|;
name|void
modifier|*
name|priv
decl_stmt|;
name|int
function_decl|(
modifier|*
name|aux_ch
function_decl|)
parameter_list|(
name|device_t
name|adapter
parameter_list|,
name|int
name|mode
parameter_list|,
name|uint8_t
name|write_byte
parameter_list|,
name|uint8_t
modifier|*
name|read_byte
parameter_list|)
function_decl|;
name|device_t
name|port
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|iic_dp_aux_add_bus
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
function_decl|(
modifier|*
name|ch
function_decl|)
parameter_list|(
name|device_t
name|idev
parameter_list|,
name|int
name|mode
parameter_list|,
name|uint8_t
name|write_byte
parameter_list|,
name|uint8_t
modifier|*
name|read_byte
parameter_list|)
parameter_list|,
name|void
modifier|*
name|priv
parameter_list|,
name|device_t
modifier|*
name|bus
parameter_list|,
name|device_t
modifier|*
name|adapter
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|DP_LINK_STATUS_SIZE
value|6
end_define

begin_function_decl
name|bool
name|drm_dp_channel_eq_ok
parameter_list|(
name|u8
name|link_status
index|[
name|DP_LINK_STATUS_SIZE
index|]
parameter_list|,
name|int
name|lane_count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|drm_dp_clock_recovery_ok
parameter_list|(
name|u8
name|link_status
index|[
name|DP_LINK_STATUS_SIZE
index|]
parameter_list|,
name|int
name|lane_count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u8
name|drm_dp_get_adjust_request_voltage
parameter_list|(
name|u8
name|link_status
index|[
name|DP_LINK_STATUS_SIZE
index|]
parameter_list|,
name|int
name|lane
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u8
name|drm_dp_get_adjust_request_pre_emphasis
parameter_list|(
name|u8
name|link_status
index|[
name|DP_LINK_STATUS_SIZE
index|]
parameter_list|,
name|int
name|lane
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|DP_RECEIVER_CAP_SIZE
value|0xf
end_define

begin_function_decl
name|void
name|drm_dp_link_train_clock_recovery_delay
parameter_list|(
name|u8
name|dpcd
index|[
name|DP_RECEIVER_CAP_SIZE
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_dp_link_train_channel_eq_delay
parameter_list|(
name|u8
name|dpcd
index|[
name|DP_RECEIVER_CAP_SIZE
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u8
name|drm_dp_link_rate_to_bw_code
parameter_list|(
name|int
name|link_rate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_dp_bw_code_to_link_rate
parameter_list|(
name|u8
name|link_bw
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|int
name|drm_dp_max_link_rate
parameter_list|(
name|u8
name|dpcd
index|[
name|DP_RECEIVER_CAP_SIZE
index|]
parameter_list|)
block|{
return|return
name|drm_dp_bw_code_to_link_rate
argument_list|(
name|dpcd
index|[
name|DP_MAX_LINK_RATE
index|]
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|u8
name|drm_dp_max_lane_count
parameter_list|(
name|u8
name|dpcd
index|[
name|DP_RECEIVER_CAP_SIZE
index|]
parameter_list|)
block|{
return|return
name|dpcd
index|[
name|DP_MAX_LANE_COUNT
index|]
operator|&
name|DP_MAX_LANE_COUNT_MASK
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DRM_DP_HELPER_H_ */
end_comment

end_unit

