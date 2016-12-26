begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 1992-2015 Michal Meloun  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TEGRA_DC_REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_TEGRA_DC_REG_H_
end_define

begin_comment
comment|/*  * !!! WARNING !!!  * Tegra manual uses registers index (and not register addreses).  * We follow the TRM notation and index is converted to offset in  * WR4 / RD4 macros  */
end_comment

begin_comment
comment|/* --------------------------- DC CMD -------------------------------------- */
end_comment

begin_define
define|#
directive|define
name|DC_CMD_GENERAL_INCR_SYNCPT
value|0x000
end_define

begin_define
define|#
directive|define
name|DC_CMD_GENERAL_INCR_SYNCPT_CNTRL
value|0x001
end_define

begin_define
define|#
directive|define
name|SYNCPT_CNTRL_NO_STALL
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|SYNCPT_CNTRL_SOFT_RESET
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DC_CMD_GENERAL_INCR_SYNCPT_ERROR
value|0x002
end_define

begin_define
define|#
directive|define
name|DC_CMD_WIN_A_INCR_SYNCPT
value|0x008
end_define

begin_define
define|#
directive|define
name|DC_CMD_WIN_A_INCR_SYNCPT_CNTRL
value|0x009
end_define

begin_define
define|#
directive|define
name|DC_CMD_WIN_A_INCR_SYNCPT_ERROR
value|0x00a
end_define

begin_define
define|#
directive|define
name|DC_CMD_WIN_B_INCR_SYNCPT
value|0x010
end_define

begin_define
define|#
directive|define
name|DC_CMD_WIN_B_INCR_SYNCPT_CNTRL
value|0x011
end_define

begin_define
define|#
directive|define
name|DC_CMD_WIN_B_INCR_SYNCPT_ERROR
value|0x012
end_define

begin_define
define|#
directive|define
name|DC_CMD_WIN_C_INCR_SYNCPT
value|0x018
end_define

begin_define
define|#
directive|define
name|DC_CMD_WIN_C_INCR_SYNCPT_CNTRL
value|0x019
end_define

begin_define
define|#
directive|define
name|DC_CMD_WIN_C_INCR_SYNCPT_ERROR
value|0x01a
end_define

begin_define
define|#
directive|define
name|DC_CMD_CONT_SYNCPT_VSYNC
value|0x028
end_define

begin_define
define|#
directive|define
name|SYNCPT_VSYNC_ENABLE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|DC_CMD_CTXSW
value|0x030
end_define

begin_define
define|#
directive|define
name|DC_CMD_DISPLAY_COMMAND_OPTION0
value|0x031
end_define

begin_define
define|#
directive|define
name|DC_CMD_DISPLAY_COMMAND
value|0x032
end_define

begin_define
define|#
directive|define
name|DISPLAY_CTRL_MODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 5)
end_define

begin_define
define|#
directive|define
name|CTRL_MODE_STOP
value|0
end_define

begin_define
define|#
directive|define
name|CTRL_MODE_C_DISPLAY
value|1
end_define

begin_define
define|#
directive|define
name|CTRL_MODE_NC_DISPLAY
value|2
end_define

begin_define
define|#
directive|define
name|DC_CMD_SIGNAL_RAISE
value|0x033
end_define

begin_define
define|#
directive|define
name|DC_CMD_DISPLAY_POWER_CONTROL
value|0x036
end_define

begin_define
define|#
directive|define
name|PM1_ENABLE
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|PM0_ENABLE
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|PW4_ENABLE
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|PW3_ENABLE
value|(1<<  6)
end_define

begin_define
define|#
directive|define
name|PW2_ENABLE
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|PW1_ENABLE
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|PW0_ENABLE
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|DC_CMD_INT_STATUS
value|0x037
end_define

begin_define
define|#
directive|define
name|DC_CMD_INT_MASK
value|0x038
end_define

begin_define
define|#
directive|define
name|DC_CMD_INT_ENABLE
value|0x039
end_define

begin_define
define|#
directive|define
name|DC_CMD_INT_TYPE
value|0x03a
end_define

begin_define
define|#
directive|define
name|DC_CMD_INT_POLARITY
value|0x03b
end_define

begin_define
define|#
directive|define
name|WIN_T_UF_INT
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|WIN_D_UF_INT
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|HC_UF_INT
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|CMU_LUT_CONFLICT_INT
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|WIN_C_OF_INT
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|WIN_B_OF_INT
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|WIN_A_OF_INT
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|SSF_INT
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|MSF_INT
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|WIN_C_UF_INT
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|WIN_B_UF_INT
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|WIN_A_UF_INT
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|SPI_BUSY_INT
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|V_PULSE2_INT
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|V_PULSE3_INT
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|HBLANK_INT
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|VBLANK_INT
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|FRAME_END_INT
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|DC_CMD_STATE_ACCESS
value|0x040
end_define

begin_define
define|#
directive|define
name|WRITE_MUX
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|READ_MUX
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DC_CMD_STATE_CONTROL
value|0x041
end_define

begin_define
define|#
directive|define
name|NC_HOST_TRIG
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|CURSOR_UPDATE
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|WIN_C_UPDATE
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|WIN_B_UPDATE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|WIN_A_UPDATE
value|(1<<  9)
end_define

begin_define
define|#
directive|define
name|WIN_UPDATE
parameter_list|(
name|x
parameter_list|)
value|(1<<  (9 + (x)))
end_define

begin_define
define|#
directive|define
name|GENERAL_UPDATE
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|CURSOR_ACT_REQ
value|(1<<  7)
end_define

begin_define
define|#
directive|define
name|WIN_D_ACT_REQ
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|WIN_C_ACT_REQ
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|WIN_B_ACT_REQ
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|WIN_A_ACT_REQ
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|WIN_ACT_REQ
parameter_list|(
name|x
parameter_list|)
value|(1<<  (1 + (x)))
end_define

begin_define
define|#
directive|define
name|GENERAL_ACT_REQ
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|DC_CMD_DISPLAY_WINDOW_HEADER
value|0x042
end_define

begin_define
define|#
directive|define
name|WINDOW_D_SELECT
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|WINDOW_C_SELECT
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|WINDOW_B_SELECT
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|WINDOW_A_SELECT
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|WINDOW_SELECT
parameter_list|(
name|x
parameter_list|)
value|(1<< (4 + (x)))
end_define

begin_define
define|#
directive|define
name|DC_CMD_REG_ACT_CONTROL
value|0x043
end_define

begin_define
define|#
directive|define
name|DC_CMD_WIN_D_INCR_SYNCPT
value|0x04c
end_define

begin_define
define|#
directive|define
name|DC_CMD_WIN_D_INCR_SYNCPT_CNTRL
value|0x04d
end_define

begin_define
define|#
directive|define
name|DC_CMD_WIN_D_INCR_SYNCPT_ERROR
value|0x04e
end_define

begin_comment
comment|/* ---------------------------- DC COM ------------------------------------- */
end_comment

begin_comment
comment|/* --------------------------- DC DISP ------------------------------------- */
end_comment

begin_define
define|#
directive|define
name|DC_DISP_DISP_SIGNAL_OPTIONS0
value|0x400
end_define

begin_define
define|#
directive|define
name|M1_ENABLE
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|M0_ENABLE
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|V_PULSE2_ENABLE
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|V_PULSE1_ENABLE
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|V_PULSE0_ENABLE
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|H_PULSE2_ENABLE
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|H_PULSE1_ENABLE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|H_PULSE0_ENABLE
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|DC_DISP_DISP_SIGNAL_OPTIONS1
value|0x401
end_define

begin_define
define|#
directive|define
name|DC_DISP_DISP_WIN_OPTIONS
value|0x402
end_define

begin_define
define|#
directive|define
name|HDMI_ENABLE
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|DSI_ENABLE
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|SOR1_TIMING_CYA
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|SOR1_ENABLE
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|SOR_ENABLE
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|CURSOR_ENABLE
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|DC_DISP_DISP_TIMING_OPTIONS
value|0x405
end_define

begin_define
define|#
directive|define
name|VSYNC_H_POSITION
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xfff)<< 0)
end_define

begin_define
define|#
directive|define
name|DC_DISP_REF_TO_SYNC
value|0x406
end_define

begin_define
define|#
directive|define
name|DC_DISP_SYNC_WIDTH
value|0x407
end_define

begin_define
define|#
directive|define
name|DC_DISP_BACK_PORCH
value|0x408
end_define

begin_define
define|#
directive|define
name|DC_DISP_DISP_ACTIVE
value|0x409
end_define

begin_define
define|#
directive|define
name|DC_DISP_FRONT_PORCH
value|0x40a
end_define

begin_define
define|#
directive|define
name|DC_DISP_H_PULSE0_CONTROL
value|0x40b
end_define

begin_define
define|#
directive|define
name|DC_DISP_H_PULSE0_POSITION_A
value|0x40c
end_define

begin_define
define|#
directive|define
name|DC_DISP_H_PULSE0_POSITION_B
value|0x40d
end_define

begin_define
define|#
directive|define
name|DC_DISP_H_PULSE0_POSITION_C
value|0x40e
end_define

begin_define
define|#
directive|define
name|DC_DISP_H_PULSE0_POSITION_D
value|0x40f
end_define

begin_define
define|#
directive|define
name|DC_DISP_H_PULSE1_CONTROL
value|0x410
end_define

begin_define
define|#
directive|define
name|DC_DISP_H_PULSE1_POSITION_A
value|0x411
end_define

begin_define
define|#
directive|define
name|DC_DISP_H_PULSE1_POSITION_B
value|0x412
end_define

begin_define
define|#
directive|define
name|DC_DISP_H_PULSE1_POSITION_C
value|0x413
end_define

begin_define
define|#
directive|define
name|DC_DISP_H_PULSE1_POSITION_D
value|0x414
end_define

begin_define
define|#
directive|define
name|DC_DISP_H_PULSE2_CONTROL
value|0x415
end_define

begin_define
define|#
directive|define
name|DC_DISP_H_PULSE2_POSITION_A
value|0x416
end_define

begin_define
define|#
directive|define
name|DC_DISP_H_PULSE2_POSITION_B
value|0x417
end_define

begin_define
define|#
directive|define
name|DC_DISP_H_PULSE2_POSITION_C
value|0x418
end_define

begin_define
define|#
directive|define
name|DC_DISP_H_PULSE2_POSITION_D
value|0x419
end_define

begin_define
define|#
directive|define
name|DC_DISP_V_PULSE0_CONTROL
value|0x41a
end_define

begin_define
define|#
directive|define
name|DC_DISP_V_PULSE0_POSITION_A
value|0x41b
end_define

begin_define
define|#
directive|define
name|DC_DISP_V_PULSE0_POSITION_B
value|0x41c
end_define

begin_define
define|#
directive|define
name|DC_DISP_V_PULSE0_POSITION_C
value|0x41d
end_define

begin_define
define|#
directive|define
name|DC_DISP_V_PULSE1_CONTROL
value|0x41e
end_define

begin_define
define|#
directive|define
name|DC_DISP_V_PULSE1_POSITION_A
value|0x41f
end_define

begin_define
define|#
directive|define
name|DC_DISP_V_PULSE1_POSITION_B
value|0x420
end_define

begin_define
define|#
directive|define
name|DC_DISP_V_PULSE1_POSITION_C
value|0x421
end_define

begin_define
define|#
directive|define
name|DC_DISP_V_PULSE2_CONTROL
value|0x422
end_define

begin_define
define|#
directive|define
name|DC_DISP_V_PULSE2_POSITION_A
value|0x423
end_define

begin_define
define|#
directive|define
name|DC_DISP_V_PULSE3_CONTROL
value|0x424
end_define

begin_define
define|#
directive|define
name|PULSE_CONTROL_LAST
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7f)<< 8)
end_define

begin_define
define|#
directive|define
name|LAST_START_A
value|0
end_define

begin_define
define|#
directive|define
name|LAST_END_A
value|1
end_define

begin_define
define|#
directive|define
name|LAST_START_B
value|2
end_define

begin_define
define|#
directive|define
name|LAST_END_B
value|3
end_define

begin_define
define|#
directive|define
name|LAST_START_C
value|4
end_define

begin_define
define|#
directive|define
name|LAST_END_C
value|5
end_define

begin_define
define|#
directive|define
name|LAST_START_D
value|6
end_define

begin_define
define|#
directive|define
name|LAST_END_D
value|7
end_define

begin_define
define|#
directive|define
name|PULSE_CONTROL_QUAL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 8)
end_define

begin_define
define|#
directive|define
name|QUAL_ALWAYS
value|0
end_define

begin_define
define|#
directive|define
name|QUAL_VACTIVE
value|2
end_define

begin_define
define|#
directive|define
name|QUAL_VACTIVE1
value|3
end_define

begin_define
define|#
directive|define
name|PULSE_POLARITY
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|PULSE_MODE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|DC_DISP_V_PULSE3_POSITION_A
value|0x425
end_define

begin_define
define|#
directive|define
name|PULSE_END
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xfff)<< 16)
end_define

begin_define
define|#
directive|define
name|PULSE_START
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xfff)<<  0)
end_define

begin_define
define|#
directive|define
name|DC_DISP_DISP_CLOCK_CONTROL
value|0x42e
end_define

begin_define
define|#
directive|define
name|PIXEL_CLK_DIVIDER
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<<  8)
end_define

begin_define
define|#
directive|define
name|PCD1
value|0
end_define

begin_define
define|#
directive|define
name|PCD1H
value|1
end_define

begin_define
define|#
directive|define
name|PCD2
value|2
end_define

begin_define
define|#
directive|define
name|PCD3
value|3
end_define

begin_define
define|#
directive|define
name|PCD4
value|4
end_define

begin_define
define|#
directive|define
name|PCD6
value|5
end_define

begin_define
define|#
directive|define
name|PCD8
value|6
end_define

begin_define
define|#
directive|define
name|PCD9
value|7
end_define

begin_define
define|#
directive|define
name|PCD12
value|8
end_define

begin_define
define|#
directive|define
name|PCD16
value|9
end_define

begin_define
define|#
directive|define
name|PCD18
value|10
end_define

begin_define
define|#
directive|define
name|PCD24
value|11
end_define

begin_define
define|#
directive|define
name|PCD13
value|12
end_define

begin_define
define|#
directive|define
name|SHIFT_CLK_DIVIDER
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xff)
end_define

begin_define
define|#
directive|define
name|DC_DISP_DISP_INTERFACE_CONTROL
value|0x42f
end_define

begin_define
define|#
directive|define
name|DISP_ORDER_BLUE_RED
value|( 1<< 9)
end_define

begin_define
define|#
directive|define
name|DISP_ALIGNMENT_LSB
value|( 1<< 8)
end_define

begin_define
define|#
directive|define
name|DISP_DATA_FORMAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<<  8)
end_define

begin_define
define|#
directive|define
name|DF1P1C
value|0
end_define

begin_define
define|#
directive|define
name|DF1P2C24B
value|1
end_define

begin_define
define|#
directive|define
name|DF1P2C18B
value|2
end_define

begin_define
define|#
directive|define
name|DF1P2C16B
value|3
end_define

begin_define
define|#
directive|define
name|DF1S
value|4
end_define

begin_define
define|#
directive|define
name|DF2S
value|5
end_define

begin_define
define|#
directive|define
name|DF3S
value|6
end_define

begin_define
define|#
directive|define
name|DFSPI
value|7
end_define

begin_define
define|#
directive|define
name|DF1P3C24B
value|8
end_define

begin_define
define|#
directive|define
name|DF2P1C18B
value|9
end_define

begin_define
define|#
directive|define
name|DFDUAL1P1C18B
value|10
end_define

begin_define
define|#
directive|define
name|DC_DISP_DISP_COLOR_CONTROL
value|0x430
end_define

begin_define
define|#
directive|define
name|NON_BASE_COLOR
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|BLANK_COLOR
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|DISP_COLOR_SWAP
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|ORD_DITHER_ROTATION
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 12)
end_define

begin_define
define|#
directive|define
name|DITHER_CONTROL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<<  8)
end_define

begin_define
define|#
directive|define
name|DITHER_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|DITHER_ORDERED
value|2
end_define

begin_define
define|#
directive|define
name|DITHER_TEMPORAL
value|3
end_define

begin_define
define|#
directive|define
name|BASE_COLOR_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<<  0)
end_define

begin_define
define|#
directive|define
name|SIZE_BASE666
value|0
end_define

begin_define
define|#
directive|define
name|SIZE_BASE111
value|1
end_define

begin_define
define|#
directive|define
name|SIZE_BASE222
value|2
end_define

begin_define
define|#
directive|define
name|SIZE_BASE333
value|3
end_define

begin_define
define|#
directive|define
name|SIZE_BASE444
value|4
end_define

begin_define
define|#
directive|define
name|SIZE_BASE555
value|5
end_define

begin_define
define|#
directive|define
name|SIZE_BASE565
value|6
end_define

begin_define
define|#
directive|define
name|SIZE_BASE332
value|7
end_define

begin_define
define|#
directive|define
name|SIZE_BASE888
value|8
end_define

begin_define
define|#
directive|define
name|DC_DISP_CURSOR_START_ADDR
value|0x43e
end_define

begin_define
define|#
directive|define
name|CURSOR_CLIP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 28)
end_define

begin_define
define|#
directive|define
name|CC_DISPLAY
value|0
end_define

begin_define
define|#
directive|define
name|CC_WA
value|1
end_define

begin_define
define|#
directive|define
name|CC_WB
value|2
end_define

begin_define
define|#
directive|define
name|CC_WC
value|3
end_define

begin_define
define|#
directive|define
name|CURSOR_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 24)
end_define

begin_define
define|#
directive|define
name|C32x32
value|0
end_define

begin_define
define|#
directive|define
name|C64x64
value|1
end_define

begin_define
define|#
directive|define
name|C128x128
value|2
end_define

begin_define
define|#
directive|define
name|C256x256
value|3
end_define

begin_define
define|#
directive|define
name|CURSOR_START_ADDR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)& 0x3FFFFF)
end_define

begin_define
define|#
directive|define
name|DC_DISP_CURSOR_POSITION
value|0x440
end_define

begin_define
define|#
directive|define
name|CURSOR_POSITION
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((((h)& 0x3fff)<<  0) |	\ 					 (((v)& 0x3fff)<< 16))
end_define

begin_define
define|#
directive|define
name|DC_DISP_CURSOR_UNDERFLOW_CTRL
value|0x4eb
end_define

begin_define
define|#
directive|define
name|DC_DISP_BLEND_CURSOR_CONTROL
value|0x4f1
end_define

begin_define
define|#
directive|define
name|CURSOR_MODE_SELECT
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|CURSOR_DST_BLEND_FACTOR_SELECT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 16)
end_define

begin_define
define|#
directive|define
name|DST_BLEND_ZERO
value|0
end_define

begin_define
define|#
directive|define
name|DST_BLEND_K1
value|1
end_define

begin_define
define|#
directive|define
name|DST_NEG_K1_TIMES_SRC
value|2
end_define

begin_define
define|#
directive|define
name|CURSOR_SRC_BLEND_FACTOR_SELECT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<<  8)
end_define

begin_define
define|#
directive|define
name|SRC_BLEND_K1
value|0
end_define

begin_define
define|#
directive|define
name|SRC_BLEND_K1_TIMES_SRC
value|1
end_define

begin_define
define|#
directive|define
name|CURSOR_ALPHA
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFF)<< 0)
end_define

begin_define
define|#
directive|define
name|DC_DISP_CURSOR_UFLOW_DBG_PIXEL
value|0x4f3
end_define

begin_define
define|#
directive|define
name|CURSOR_UFLOW_CYA
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|CURSOR_UFLOW_CTRL_DBG_MODE
value|(1<< 0)
end_define

begin_comment
comment|/* --------------------------- DC WIN ------------------------------------- */
end_comment

begin_define
define|#
directive|define
name|DC_WINC_COLOR_PALETTE
value|0x500
end_define

begin_define
define|#
directive|define
name|DC_WINC_CSC_YOF
value|0x611
end_define

begin_define
define|#
directive|define
name|DC_WINC_CSC_KYRGB
value|0x612
end_define

begin_define
define|#
directive|define
name|DC_WINC_CSC_KUR
value|0x613
end_define

begin_define
define|#
directive|define
name|DC_WINC_CSC_KVR
value|0x614
end_define

begin_define
define|#
directive|define
name|DC_WINC_CSC_KUG
value|0x615
end_define

begin_define
define|#
directive|define
name|DC_WINC_CSC_KVG
value|0x616
end_define

begin_define
define|#
directive|define
name|DC_WINC_CSC_KUB
value|0x617
end_define

begin_define
define|#
directive|define
name|DC_WINC_CSC_KVB
value|0x618
end_define

begin_define
define|#
directive|define
name|DC_WINC_WIN_OPTIONS
value|0x700
end_define

begin_define
define|#
directive|define
name|H_FILTER_MODE
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|WIN_ENABLE
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|INTERLACE_ENABLE
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|YUV_RANGE_EXPAND
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|DV_ENABLE
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|CSC_ENABLE
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|CP_ENABLE
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|V_FILTER_UV_ALIGN
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|V_FILTER_OPTIMIZE
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|V_FILTER_ENABLE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|H_FILTER_ENABLE
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|COLOR_EXPAND
value|(1<<  6)
end_define

begin_define
define|#
directive|define
name|SCAN_COLUMN
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|V_DIRECTION
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|H_DIRECTION
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|DC_WIN_BYTE_SWAP
value|0x701
end_define

begin_define
define|#
directive|define
name|BYTE_SWAP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 0)
end_define

begin_define
define|#
directive|define
name|NOSWAP
value|0
end_define

begin_define
define|#
directive|define
name|SWAP2
value|1
end_define

begin_define
define|#
directive|define
name|SWAP4
value|2
end_define

begin_define
define|#
directive|define
name|SWAP4HW
value|3
end_define

begin_define
define|#
directive|define
name|SWAP02
value|4
end_define

begin_define
define|#
directive|define
name|SWAPLEFT
value|5
end_define

begin_define
define|#
directive|define
name|DC_WIN_COLOR_DEPTH
value|0x703
end_define

begin_define
define|#
directive|define
name|WIN_COLOR_DEPTH_P8
value|3
end_define

begin_define
define|#
directive|define
name|WIN_COLOR_DEPTH_B4G4R4A4
value|4
end_define

begin_define
define|#
directive|define
name|WIN_COLOR_DEPTH_B5G5R5A
value|5
end_define

begin_define
define|#
directive|define
name|WIN_COLOR_DEPTH_B5G6R5
value|6
end_define

begin_define
define|#
directive|define
name|WIN_COLOR_DEPTH_AB5G5R5
value|7
end_define

begin_define
define|#
directive|define
name|WIN_COLOR_DEPTH_B8G8R8A8
value|12
end_define

begin_define
define|#
directive|define
name|WIN_COLOR_DEPTH_R8G8B8A8
value|13
end_define

begin_define
define|#
directive|define
name|WIN_COLOR_DEPTH_YCbCr422
value|16
end_define

begin_define
define|#
directive|define
name|WIN_COLOR_DEPTH_YUV422
value|17
end_define

begin_define
define|#
directive|define
name|WIN_COLOR_DEPTH_YCbCr420P
value|18
end_define

begin_define
define|#
directive|define
name|WIN_COLOR_DEPTH_YUV420P
value|19
end_define

begin_define
define|#
directive|define
name|WIN_COLOR_DEPTH_YCbCr422P
value|20
end_define

begin_define
define|#
directive|define
name|WIN_COLOR_DEPTH_YUV422P
value|21
end_define

begin_define
define|#
directive|define
name|WIN_COLOR_DEPTH_YCbCr422R
value|22
end_define

begin_define
define|#
directive|define
name|WIN_COLOR_DEPTH_YUV422R
value|23
end_define

begin_define
define|#
directive|define
name|WIN_COLOR_DEPTH_YCbCr422RA
value|24
end_define

begin_define
define|#
directive|define
name|WIN_COLOR_DEPTH_YUV422RA
value|25
end_define

begin_define
define|#
directive|define
name|DC_WIN_POSITION
value|0x704
end_define

begin_define
define|#
directive|define
name|WIN_POSITION
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((((h)& 0x1fff)<<  0) |	\ 					 (((v)& 0x1fff)<< 16))
end_define

begin_define
define|#
directive|define
name|DC_WIN_SIZE
value|0x705
end_define

begin_define
define|#
directive|define
name|WIN_SIZE
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((((h)& 0x1fff)<<  0) |	\ 					 (((v)& 0x1fff)<< 16))
end_define

begin_define
define|#
directive|define
name|DC_WIN_PRESCALED_SIZE
value|0x706
end_define

begin_define
define|#
directive|define
name|WIN_PRESCALED_SIZE
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((((h)& 0x7fff)<<  0) |	\ 					 (((v)& 0x1fff)<< 16))
end_define

begin_define
define|#
directive|define
name|DC_WIN_H_INITIAL_DDA
value|0x707
end_define

begin_define
define|#
directive|define
name|DC_WIN_V_INITIAL_DDA
value|0x708
end_define

begin_define
define|#
directive|define
name|DC_WIN_DDA_INCREMENT
value|0x709
end_define

begin_define
define|#
directive|define
name|WIN_DDA_INCREMENT
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((((h)& 0xffff)<<  0) |	\ 					 (((v)& 0xffff)<< 16))
end_define

begin_define
define|#
directive|define
name|DC_WIN_LINE_STRIDE
value|0x70a
end_define

begin_comment
comment|/* -------------------------- DC WINBUF ------------------------------------ */
end_comment

begin_define
define|#
directive|define
name|DC_WINBUF_START_ADDR
value|0x800
end_define

begin_define
define|#
directive|define
name|DC_WINBUF_START_ADDR_NS
value|0x801
end_define

begin_define
define|#
directive|define
name|DC_WINBUF_START_ADDR_U
value|0x802
end_define

begin_define
define|#
directive|define
name|DC_WINBUF_START_ADDR_U_NS
value|0x803
end_define

begin_define
define|#
directive|define
name|DC_WINBUF_START_ADDR_V
value|0x804
end_define

begin_define
define|#
directive|define
name|DC_WINBUF_START_ADDR_V_NS
value|0x805
end_define

begin_define
define|#
directive|define
name|DC_WINBUF_ADDR_H_OFFSET
value|0x806
end_define

begin_define
define|#
directive|define
name|DC_WINBUF_ADDR_H_OFFSET_NS
value|0x807
end_define

begin_define
define|#
directive|define
name|DC_WINBUF_ADDR_V_OFFSET
value|0x808
end_define

begin_define
define|#
directive|define
name|DC_WINBUF_ADDR_V_OFFSET_NS
value|0x809
end_define

begin_define
define|#
directive|define
name|DC_WINBUF_UFLOW_STATUS
value|0x80a
end_define

begin_define
define|#
directive|define
name|DC_WINBUF_SURFACE_KIND
value|0x80b
end_define

begin_define
define|#
directive|define
name|SURFACE_KIND_BLOCK_HEIGHT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 4)
end_define

begin_define
define|#
directive|define
name|SURFACE_KIND_PITCH
value|0
end_define

begin_define
define|#
directive|define
name|SURFACE_KIND_TILED
value|1
end_define

begin_define
define|#
directive|define
name|SURFACE_KIND_BL_16B2
value|2
end_define

begin_define
define|#
directive|define
name|DC_WINBUF_SURFACE_WEIGHT
value|0x80c
end_define

begin_define
define|#
directive|define
name|DC_WINBUF_START_ADDR_HI
value|0x80d
end_define

begin_define
define|#
directive|define
name|DC_WINBUF_START_ADDR_HI_NS
value|0x80e
end_define

begin_define
define|#
directive|define
name|DC_WINBUF_START_ADDR_U_HI
value|0x80f
end_define

begin_define
define|#
directive|define
name|DC_WINBUF_START_ADDR_U_HI_NS
value|0x810
end_define

begin_define
define|#
directive|define
name|DC_WINBUF_START_ADDR_V_HI
value|0x811
end_define

begin_define
define|#
directive|define
name|DC_WINBUF_START_ADDR_V_HI_NS
value|0x812
end_define

begin_define
define|#
directive|define
name|DC_WINBUF_UFLOW_CTRL
value|0x824
end_define

begin_define
define|#
directive|define
name|UFLOW_CTR_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DC_WINBUF_UFLOW_DBG_PIXEL
value|0x825
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TEGRA_DC_REG_H_ */
end_comment

end_unit

