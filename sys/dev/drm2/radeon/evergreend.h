begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2010 Advanced Micro Devices, Inc.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * Authors: Alex Deucher  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|EVERGREEND_H
end_ifndef

begin_define
define|#
directive|define
name|EVERGREEND_H
end_define

begin_define
define|#
directive|define
name|EVERGREEN_MAX_SH_GPRS
value|256
end_define

begin_define
define|#
directive|define
name|EVERGREEN_MAX_TEMP_GPRS
value|16
end_define

begin_define
define|#
directive|define
name|EVERGREEN_MAX_SH_THREADS
value|256
end_define

begin_define
define|#
directive|define
name|EVERGREEN_MAX_SH_STACK_ENTRIES
value|4096
end_define

begin_define
define|#
directive|define
name|EVERGREEN_MAX_FRC_EOV_CNT
value|16384
end_define

begin_define
define|#
directive|define
name|EVERGREEN_MAX_BACKENDS
value|8
end_define

begin_define
define|#
directive|define
name|EVERGREEN_MAX_BACKENDS_MASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|EVERGREEN_MAX_SIMDS
value|16
end_define

begin_define
define|#
directive|define
name|EVERGREEN_MAX_SIMDS_MASK
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|EVERGREEN_MAX_PIPES
value|8
end_define

begin_define
define|#
directive|define
name|EVERGREEN_MAX_PIPES_MASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|EVERGREEN_MAX_LDS_NUM
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|CYPRESS_GB_ADDR_CONFIG_GOLDEN
value|0x02011003
end_define

begin_define
define|#
directive|define
name|BARTS_GB_ADDR_CONFIG_GOLDEN
value|0x02011003
end_define

begin_define
define|#
directive|define
name|CAYMAN_GB_ADDR_CONFIG_GOLDEN
value|0x02011003
end_define

begin_define
define|#
directive|define
name|JUNIPER_GB_ADDR_CONFIG_GOLDEN
value|0x02010002
end_define

begin_define
define|#
directive|define
name|REDWOOD_GB_ADDR_CONFIG_GOLDEN
value|0x02010002
end_define

begin_define
define|#
directive|define
name|TURKS_GB_ADDR_CONFIG_GOLDEN
value|0x02010002
end_define

begin_define
define|#
directive|define
name|CEDAR_GB_ADDR_CONFIG_GOLDEN
value|0x02010001
end_define

begin_define
define|#
directive|define
name|CAICOS_GB_ADDR_CONFIG_GOLDEN
value|0x02010001
end_define

begin_define
define|#
directive|define
name|SUMO_GB_ADDR_CONFIG_GOLDEN
value|0x02010002
end_define

begin_define
define|#
directive|define
name|SUMO2_GB_ADDR_CONFIG_GOLDEN
value|0x02010002
end_define

begin_comment
comment|/* Registers */
end_comment

begin_define
define|#
directive|define
name|RCU_IND_INDEX
value|0x100
end_define

begin_define
define|#
directive|define
name|RCU_IND_DATA
value|0x104
end_define

begin_define
define|#
directive|define
name|GRBM_GFX_INDEX
value|0x802C
end_define

begin_define
define|#
directive|define
name|INSTANCE_INDEX
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|SE_INDEX
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|INSTANCE_BROADCAST_WRITES
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|SE_BROADCAST_WRITES
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|RLC_GFX_INDEX
value|0x3fC4
end_define

begin_define
define|#
directive|define
name|CC_GC_SHADER_PIPE_CONFIG
value|0x8950
end_define

begin_define
define|#
directive|define
name|WRITE_DIS
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|CC_RB_BACKEND_DISABLE
value|0x98F4
end_define

begin_define
define|#
directive|define
name|BACKEND_DISABLE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|GB_ADDR_CONFIG
value|0x98F8
end_define

begin_define
define|#
directive|define
name|NUM_PIPES
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|NUM_PIPES_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|PIPE_INTERLEAVE_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 4)
end_define

begin_define
define|#
directive|define
name|BANK_INTERLEAVE_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|NUM_SHADER_ENGINES
parameter_list|(
name|x
parameter_list|)
value|((x)<< 12)
end_define

begin_define
define|#
directive|define
name|SHADER_ENGINE_TILE_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|NUM_GPUS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 20)
end_define

begin_define
define|#
directive|define
name|MULTI_GPU_TILE_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 24)
end_define

begin_define
define|#
directive|define
name|ROW_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 28)
end_define

begin_define
define|#
directive|define
name|GB_BACKEND_MAP
value|0x98FC
end_define

begin_define
define|#
directive|define
name|DMIF_ADDR_CONFIG
value|0xBD4
end_define

begin_define
define|#
directive|define
name|HDP_ADDR_CONFIG
value|0x2F48
end_define

begin_define
define|#
directive|define
name|HDP_MISC_CNTL
value|0x2F4C
end_define

begin_define
define|#
directive|define
name|HDP_FLUSH_INVALIDATE_CACHE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|CC_SYS_RB_BACKEND_DISABLE
value|0x3F88
end_define

begin_define
define|#
directive|define
name|GC_USER_RB_BACKEND_DISABLE
value|0x9B7C
end_define

begin_define
define|#
directive|define
name|CGTS_SYS_TCC_DISABLE
value|0x3F90
end_define

begin_define
define|#
directive|define
name|CGTS_TCC_DISABLE
value|0x9148
end_define

begin_define
define|#
directive|define
name|CGTS_USER_SYS_TCC_DISABLE
value|0x3F94
end_define

begin_define
define|#
directive|define
name|CGTS_USER_TCC_DISABLE
value|0x914C
end_define

begin_define
define|#
directive|define
name|CONFIG_MEMSIZE
value|0x5428
end_define

begin_define
define|#
directive|define
name|BIF_FB_EN
value|0x5490
end_define

begin_define
define|#
directive|define
name|FB_READ_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|FB_WRITE_EN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|CP_STRMOUT_CNTL
value|0x84FC
end_define

begin_define
define|#
directive|define
name|CP_COHER_CNTL
value|0x85F0
end_define

begin_define
define|#
directive|define
name|CP_COHER_SIZE
value|0x85F4
end_define

begin_define
define|#
directive|define
name|CP_COHER_BASE
value|0x85F8
end_define

begin_define
define|#
directive|define
name|CP_STALLED_STAT1
value|0x8674
end_define

begin_define
define|#
directive|define
name|CP_STALLED_STAT2
value|0x8678
end_define

begin_define
define|#
directive|define
name|CP_BUSY_STAT
value|0x867C
end_define

begin_define
define|#
directive|define
name|CP_STAT
value|0x8680
end_define

begin_define
define|#
directive|define
name|CP_ME_CNTL
value|0x86D8
end_define

begin_define
define|#
directive|define
name|CP_ME_HALT
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|CP_PFP_HALT
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|CP_ME_RAM_DATA
value|0xC160
end_define

begin_define
define|#
directive|define
name|CP_ME_RAM_RADDR
value|0xC158
end_define

begin_define
define|#
directive|define
name|CP_ME_RAM_WADDR
value|0xC15C
end_define

begin_define
define|#
directive|define
name|CP_MEQ_THRESHOLDS
value|0x8764
end_define

begin_define
define|#
directive|define
name|STQ_SPLIT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|CP_PERFMON_CNTL
value|0x87FC
end_define

begin_define
define|#
directive|define
name|CP_PFP_UCODE_ADDR
value|0xC150
end_define

begin_define
define|#
directive|define
name|CP_PFP_UCODE_DATA
value|0xC154
end_define

begin_define
define|#
directive|define
name|CP_QUEUE_THRESHOLDS
value|0x8760
end_define

begin_define
define|#
directive|define
name|ROQ_IB1_START
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|ROQ_IB2_START
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|CP_RB_BASE
value|0xC100
end_define

begin_define
define|#
directive|define
name|CP_RB_CNTL
value|0xC104
end_define

begin_define
define|#
directive|define
name|RB_BUFSZ
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|RB_BLKSZ
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|RB_NO_UPDATE
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|RB_RPTR_WR_ENA
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|BUF_SWAP_32BIT
value|(2<< 16)
end_define

begin_define
define|#
directive|define
name|CP_RB_RPTR
value|0x8700
end_define

begin_define
define|#
directive|define
name|CP_RB_RPTR_ADDR
value|0xC10C
end_define

begin_define
define|#
directive|define
name|RB_RPTR_SWAP
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|CP_RB_RPTR_ADDR_HI
value|0xC110
end_define

begin_define
define|#
directive|define
name|CP_RB_RPTR_WR
value|0xC108
end_define

begin_define
define|#
directive|define
name|CP_RB_WPTR
value|0xC114
end_define

begin_define
define|#
directive|define
name|CP_RB_WPTR_ADDR
value|0xC118
end_define

begin_define
define|#
directive|define
name|CP_RB_WPTR_ADDR_HI
value|0xC11C
end_define

begin_define
define|#
directive|define
name|CP_RB_WPTR_DELAY
value|0x8704
end_define

begin_define
define|#
directive|define
name|CP_SEM_WAIT_TIMER
value|0x85BC
end_define

begin_define
define|#
directive|define
name|CP_SEM_INCOMPLETE_TIMER_CNTL
value|0x85C8
end_define

begin_define
define|#
directive|define
name|CP_DEBUG
value|0xC1FC
end_define

begin_comment
comment|/* Audio clocks */
end_comment

begin_define
define|#
directive|define
name|DCCG_AUDIO_DTO_SOURCE
value|0x05ac
end_define

begin_define
define|#
directive|define
name|DCCG_AUDIO_DTO0_SOURCE_SEL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_comment
comment|/* crtc0 - crtc5 */
end_comment

begin_define
define|#
directive|define
name|DCCG_AUDIO_DTO_SEL
value|(1<< 4)
end_define

begin_comment
comment|/* 0=dto0 1=dto1 */
end_comment

begin_define
define|#
directive|define
name|DCCG_AUDIO_DTO0_PHASE
value|0x05b0
end_define

begin_define
define|#
directive|define
name|DCCG_AUDIO_DTO0_MODULE
value|0x05b4
end_define

begin_define
define|#
directive|define
name|DCCG_AUDIO_DTO0_LOAD
value|0x05b8
end_define

begin_define
define|#
directive|define
name|DCCG_AUDIO_DTO0_CNTL
value|0x05bc
end_define

begin_define
define|#
directive|define
name|DCCG_AUDIO_DTO1_PHASE
value|0x05c0
end_define

begin_define
define|#
directive|define
name|DCCG_AUDIO_DTO1_MODULE
value|0x05c4
end_define

begin_define
define|#
directive|define
name|DCCG_AUDIO_DTO1_LOAD
value|0x05c8
end_define

begin_define
define|#
directive|define
name|DCCG_AUDIO_DTO1_CNTL
value|0x05cc
end_define

begin_comment
comment|/* DCE 4.0 AFMT */
end_comment

begin_define
define|#
directive|define
name|HDMI_CONTROL
value|0x7030
end_define

begin_define
define|#
directive|define
name|HDMI_KEEPOUT_MODE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_PACKET_GEN_VERSION
value|(1<< 4)
end_define

begin_comment
comment|/* 0 = r6xx compat */
end_comment

begin_define
define|#
directive|define
name|HDMI_ERROR_ACK
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|HDMI_ERROR_MASK
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|HDMI_DEEP_COLOR_ENABLE
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|HDMI_DEEP_COLOR_DEPTH
value|(((x)& 3)<< 28)
end_define

begin_define
define|#
directive|define
name|HDMI_24BIT_DEEP_COLOR
value|0
end_define

begin_define
define|#
directive|define
name|HDMI_30BIT_DEEP_COLOR
value|1
end_define

begin_define
define|#
directive|define
name|HDMI_36BIT_DEEP_COLOR
value|2
end_define

begin_define
define|#
directive|define
name|HDMI_STATUS
value|0x7034
end_define

begin_define
define|#
directive|define
name|HDMI_ACTIVE_AVMUTE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_AUDIO_PACKET_ERROR
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|HDMI_VBI_PACKET_ERROR
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|HDMI_AUDIO_PACKET_CONTROL
value|0x7038
end_define

begin_define
define|#
directive|define
name|HDMI_AUDIO_DELAY_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 3)<< 4)
end_define

begin_define
define|#
directive|define
name|HDMI_AUDIO_PACKETS_PER_LINE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1f)<< 16)
end_define

begin_define
define|#
directive|define
name|HDMI_ACR_PACKET_CONTROL
value|0x703c
end_define

begin_define
define|#
directive|define
name|HDMI_ACR_SEND
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_ACR_CONT
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|HDMI_ACR_SELECT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 3)<< 4)
end_define

begin_define
define|#
directive|define
name|HDMI_ACR_HW
value|0
end_define

begin_define
define|#
directive|define
name|HDMI_ACR_32
value|1
end_define

begin_define
define|#
directive|define
name|HDMI_ACR_44
value|2
end_define

begin_define
define|#
directive|define
name|HDMI_ACR_48
value|3
end_define

begin_define
define|#
directive|define
name|HDMI_ACR_SOURCE
value|(1<< 8)
end_define

begin_comment
comment|/* 0 - hw; 1 - cts value */
end_comment

begin_define
define|#
directive|define
name|HDMI_ACR_AUTO_SEND
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|HDMI_ACR_N_MULTIPLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 7)<< 16)
end_define

begin_define
define|#
directive|define
name|HDMI_ACR_X1
value|1
end_define

begin_define
define|#
directive|define
name|HDMI_ACR_X2
value|2
end_define

begin_define
define|#
directive|define
name|HDMI_ACR_X4
value|4
end_define

begin_define
define|#
directive|define
name|HDMI_ACR_AUDIO_PRIORITY
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|HDMI_VBI_PACKET_CONTROL
value|0x7040
end_define

begin_define
define|#
directive|define
name|HDMI_NULL_SEND
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_GC_SEND
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|HDMI_GC_CONT
value|(1<< 5)
end_define

begin_comment
comment|/* 0 - once; 1 - every frame */
end_comment

begin_define
define|#
directive|define
name|HDMI_INFOFRAME_CONTROL0
value|0x7044
end_define

begin_define
define|#
directive|define
name|HDMI_AVI_INFO_SEND
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_AVI_INFO_CONT
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|HDMI_AUDIO_INFO_SEND
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|HDMI_AUDIO_INFO_CONT
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|HDMI_MPEG_INFO_SEND
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|HDMI_MPEG_INFO_CONT
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|HDMI_INFOFRAME_CONTROL1
value|0x7048
end_define

begin_define
define|#
directive|define
name|HDMI_AVI_INFO_LINE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3f)<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_AUDIO_INFO_LINE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3f)<< 8)
end_define

begin_define
define|#
directive|define
name|HDMI_MPEG_INFO_LINE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3f)<< 16)
end_define

begin_define
define|#
directive|define
name|HDMI_GENERIC_PACKET_CONTROL
value|0x704c
end_define

begin_define
define|#
directive|define
name|HDMI_GENERIC0_SEND
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_GENERIC0_CONT
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|HDMI_GENERIC1_SEND
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|HDMI_GENERIC1_CONT
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|HDMI_GENERIC0_LINE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3f)<< 16)
end_define

begin_define
define|#
directive|define
name|HDMI_GENERIC1_LINE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3f)<< 24)
end_define

begin_define
define|#
directive|define
name|HDMI_GC
value|0x7058
end_define

begin_define
define|#
directive|define
name|HDMI_GC_AVMUTE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_GC_AVMUTE_CONT
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AFMT_AUDIO_PACKET_CONTROL2
value|0x705c
end_define

begin_define
define|#
directive|define
name|AFMT_AUDIO_LAYOUT_OVRD
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AFMT_AUDIO_LAYOUT_SELECT
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AFMT_60958_CS_SOURCE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AFMT_AUDIO_CHANNEL_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 8)
end_define

begin_define
define|#
directive|define
name|AFMT_DP_AUDIO_STREAM_ID
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 16)
end_define

begin_define
define|#
directive|define
name|AFMT_AVI_INFO0
value|0x7084
end_define

begin_define
define|#
directive|define
name|AFMT_AVI_INFO_CHECKSUM
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 0)
end_define

begin_define
define|#
directive|define
name|AFMT_AVI_INFO_S
parameter_list|(
name|x
parameter_list|)
value|(((x)& 3)<< 8)
end_define

begin_define
define|#
directive|define
name|AFMT_AVI_INFO_B
parameter_list|(
name|x
parameter_list|)
value|(((x)& 3)<< 10)
end_define

begin_define
define|#
directive|define
name|AFMT_AVI_INFO_A
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 12)
end_define

begin_define
define|#
directive|define
name|AFMT_AVI_INFO_Y
parameter_list|(
name|x
parameter_list|)
value|(((x)& 3)<< 13)
end_define

begin_define
define|#
directive|define
name|AFMT_AVI_INFO_Y_RGB
value|0
end_define

begin_define
define|#
directive|define
name|AFMT_AVI_INFO_Y_YCBCR422
value|1
end_define

begin_define
define|#
directive|define
name|AFMT_AVI_INFO_Y_YCBCR444
value|2
end_define

begin_define
define|#
directive|define
name|AFMT_AVI_INFO_Y_A_B_S
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 8)
end_define

begin_define
define|#
directive|define
name|AFMT_AVI_INFO_R
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 16)
end_define

begin_define
define|#
directive|define
name|AFMT_AVI_INFO_M
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 20)
end_define

begin_define
define|#
directive|define
name|AFMT_AVI_INFO_C
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 22)
end_define

begin_define
define|#
directive|define
name|AFMT_AVI_INFO_C_M_R
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 16)
end_define

begin_define
define|#
directive|define
name|AFMT_AVI_INFO_SC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 24)
end_define

begin_define
define|#
directive|define
name|AFMT_AVI_INFO_Q
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 26)
end_define

begin_define
define|#
directive|define
name|AFMT_AVI_INFO_EC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 28)
end_define

begin_define
define|#
directive|define
name|AFMT_AVI_INFO_ITC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 31)
end_define

begin_define
define|#
directive|define
name|AFMT_AVI_INFO_ITC_EC_Q_SC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 24)
end_define

begin_define
define|#
directive|define
name|AFMT_AVI_INFO1
value|0x7088
end_define

begin_define
define|#
directive|define
name|AFMT_AVI_INFO_VIC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7f)<< 0)
end_define

begin_comment
comment|/* don't use avi infoframe v1 */
end_comment

begin_define
define|#
directive|define
name|AFMT_AVI_INFO_PR
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 8)
end_define

begin_comment
comment|/* don't use avi infoframe v1 */
end_comment

begin_define
define|#
directive|define
name|AFMT_AVI_INFO_CN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 12)
end_define

begin_define
define|#
directive|define
name|AFMT_AVI_INFO_YQ
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 14)
end_define

begin_define
define|#
directive|define
name|AFMT_AVI_INFO_TOP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xffff)<< 16)
end_define

begin_define
define|#
directive|define
name|AFMT_AVI_INFO2
value|0x708c
end_define

begin_define
define|#
directive|define
name|AFMT_AVI_INFO_BOTTOM
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xffff)<< 0)
end_define

begin_define
define|#
directive|define
name|AFMT_AVI_INFO_LEFT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xffff)<< 16)
end_define

begin_define
define|#
directive|define
name|AFMT_AVI_INFO3
value|0x7090
end_define

begin_define
define|#
directive|define
name|AFMT_AVI_INFO_RIGHT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xffff)<< 0)
end_define

begin_define
define|#
directive|define
name|AFMT_AVI_INFO_VERSION
parameter_list|(
name|x
parameter_list|)
value|(((x)& 3)<< 24)
end_define

begin_define
define|#
directive|define
name|AFMT_MPEG_INFO0
value|0x7094
end_define

begin_define
define|#
directive|define
name|AFMT_MPEG_INFO_CHECKSUM
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 0)
end_define

begin_define
define|#
directive|define
name|AFMT_MPEG_INFO_MB0
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 8)
end_define

begin_define
define|#
directive|define
name|AFMT_MPEG_INFO_MB1
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 16)
end_define

begin_define
define|#
directive|define
name|AFMT_MPEG_INFO_MB2
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 24)
end_define

begin_define
define|#
directive|define
name|AFMT_MPEG_INFO1
value|0x7098
end_define

begin_define
define|#
directive|define
name|AFMT_MPEG_INFO_MB3
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 0)
end_define

begin_define
define|#
directive|define
name|AFMT_MPEG_INFO_MF
parameter_list|(
name|x
parameter_list|)
value|(((x)& 3)<< 8)
end_define

begin_define
define|#
directive|define
name|AFMT_MPEG_INFO_FR
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 12)
end_define

begin_define
define|#
directive|define
name|AFMT_GENERIC0_HDR
value|0x709c
end_define

begin_define
define|#
directive|define
name|AFMT_GENERIC0_0
value|0x70a0
end_define

begin_define
define|#
directive|define
name|AFMT_GENERIC0_1
value|0x70a4
end_define

begin_define
define|#
directive|define
name|AFMT_GENERIC0_2
value|0x70a8
end_define

begin_define
define|#
directive|define
name|AFMT_GENERIC0_3
value|0x70ac
end_define

begin_define
define|#
directive|define
name|AFMT_GENERIC0_4
value|0x70b0
end_define

begin_define
define|#
directive|define
name|AFMT_GENERIC0_5
value|0x70b4
end_define

begin_define
define|#
directive|define
name|AFMT_GENERIC0_6
value|0x70b8
end_define

begin_define
define|#
directive|define
name|AFMT_GENERIC1_HDR
value|0x70bc
end_define

begin_define
define|#
directive|define
name|AFMT_GENERIC1_0
value|0x70c0
end_define

begin_define
define|#
directive|define
name|AFMT_GENERIC1_1
value|0x70c4
end_define

begin_define
define|#
directive|define
name|AFMT_GENERIC1_2
value|0x70c8
end_define

begin_define
define|#
directive|define
name|AFMT_GENERIC1_3
value|0x70cc
end_define

begin_define
define|#
directive|define
name|AFMT_GENERIC1_4
value|0x70d0
end_define

begin_define
define|#
directive|define
name|AFMT_GENERIC1_5
value|0x70d4
end_define

begin_define
define|#
directive|define
name|AFMT_GENERIC1_6
value|0x70d8
end_define

begin_define
define|#
directive|define
name|HDMI_ACR_32_0
value|0x70dc
end_define

begin_define
define|#
directive|define
name|HDMI_ACR_CTS_32
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xfffff)<< 12)
end_define

begin_define
define|#
directive|define
name|HDMI_ACR_32_1
value|0x70e0
end_define

begin_define
define|#
directive|define
name|HDMI_ACR_N_32
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xfffff)<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_ACR_44_0
value|0x70e4
end_define

begin_define
define|#
directive|define
name|HDMI_ACR_CTS_44
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xfffff)<< 12)
end_define

begin_define
define|#
directive|define
name|HDMI_ACR_44_1
value|0x70e8
end_define

begin_define
define|#
directive|define
name|HDMI_ACR_N_44
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xfffff)<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_ACR_48_0
value|0x70ec
end_define

begin_define
define|#
directive|define
name|HDMI_ACR_CTS_48
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xfffff)<< 12)
end_define

begin_define
define|#
directive|define
name|HDMI_ACR_48_1
value|0x70f0
end_define

begin_define
define|#
directive|define
name|HDMI_ACR_N_48
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xfffff)<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_ACR_STATUS_0
value|0x70f4
end_define

begin_define
define|#
directive|define
name|HDMI_ACR_STATUS_1
value|0x70f8
end_define

begin_define
define|#
directive|define
name|AFMT_AUDIO_INFO0
value|0x70fc
end_define

begin_define
define|#
directive|define
name|AFMT_AUDIO_INFO_CHECKSUM
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 0)
end_define

begin_define
define|#
directive|define
name|AFMT_AUDIO_INFO_CC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 7)<< 8)
end_define

begin_define
define|#
directive|define
name|AFMT_AUDIO_INFO_CT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 11)
end_define

begin_define
define|#
directive|define
name|AFMT_AUDIO_INFO_CHECKSUM_OFFSET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 16)
end_define

begin_define
define|#
directive|define
name|AFMT_AUDIO_INFO_CXT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1f)<< 24)
end_define

begin_define
define|#
directive|define
name|AFMT_AUDIO_INFO1
value|0x7100
end_define

begin_define
define|#
directive|define
name|AFMT_AUDIO_INFO_CA
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 0)
end_define

begin_define
define|#
directive|define
name|AFMT_AUDIO_INFO_LSV
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 11)
end_define

begin_define
define|#
directive|define
name|AFMT_AUDIO_INFO_DM_INH
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 15)
end_define

begin_define
define|#
directive|define
name|AFMT_AUDIO_INFO_DM_INH_LSV
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 8)
end_define

begin_define
define|#
directive|define
name|AFMT_AUDIO_INFO_LFEBPL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 3)<< 16)
end_define

begin_define
define|#
directive|define
name|AFMT_60958_0
value|0x7104
end_define

begin_define
define|#
directive|define
name|AFMT_60958_CS_A
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 0)
end_define

begin_define
define|#
directive|define
name|AFMT_60958_CS_B
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 1)
end_define

begin_define
define|#
directive|define
name|AFMT_60958_CS_C
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 2)
end_define

begin_define
define|#
directive|define
name|AFMT_60958_CS_D
parameter_list|(
name|x
parameter_list|)
value|(((x)& 3)<< 3)
end_define

begin_define
define|#
directive|define
name|AFMT_60958_CS_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 3)<< 6)
end_define

begin_define
define|#
directive|define
name|AFMT_60958_CS_CATEGORY_CODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 8)
end_define

begin_define
define|#
directive|define
name|AFMT_60958_CS_SOURCE_NUMBER
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 16)
end_define

begin_define
define|#
directive|define
name|AFMT_60958_CS_CHANNEL_NUMBER_L
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 20)
end_define

begin_define
define|#
directive|define
name|AFMT_60958_CS_SAMPLING_FREQUENCY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 24)
end_define

begin_define
define|#
directive|define
name|AFMT_60958_CS_CLOCK_ACCURACY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 3)<< 28)
end_define

begin_define
define|#
directive|define
name|AFMT_60958_1
value|0x7108
end_define

begin_define
define|#
directive|define
name|AFMT_60958_CS_WORD_LENGTH
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 0)
end_define

begin_define
define|#
directive|define
name|AFMT_60958_CS_ORIGINAL_SAMPLING_FREQUENCY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 4)
end_define

begin_define
define|#
directive|define
name|AFMT_60958_CS_VALID_L
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 16)
end_define

begin_define
define|#
directive|define
name|AFMT_60958_CS_VALID_R
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 18)
end_define

begin_define
define|#
directive|define
name|AFMT_60958_CS_CHANNEL_NUMBER_R
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 20)
end_define

begin_define
define|#
directive|define
name|AFMT_AUDIO_CRC_CONTROL
value|0x710c
end_define

begin_define
define|#
directive|define
name|AFMT_AUDIO_CRC_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AFMT_RAMP_CONTROL0
value|0x7110
end_define

begin_define
define|#
directive|define
name|AFMT_RAMP_MAX_COUNT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xffffff)<< 0)
end_define

begin_define
define|#
directive|define
name|AFMT_RAMP_DATA_SIGN
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|AFMT_RAMP_CONTROL1
value|0x7114
end_define

begin_define
define|#
directive|define
name|AFMT_RAMP_MIN_COUNT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xffffff)<< 0)
end_define

begin_define
define|#
directive|define
name|AFMT_AUDIO_TEST_CH_DISABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 24)
end_define

begin_define
define|#
directive|define
name|AFMT_RAMP_CONTROL2
value|0x7118
end_define

begin_define
define|#
directive|define
name|AFMT_RAMP_INC_COUNT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xffffff)<< 0)
end_define

begin_define
define|#
directive|define
name|AFMT_RAMP_CONTROL3
value|0x711c
end_define

begin_define
define|#
directive|define
name|AFMT_RAMP_DEC_COUNT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xffffff)<< 0)
end_define

begin_define
define|#
directive|define
name|AFMT_60958_2
value|0x7120
end_define

begin_define
define|#
directive|define
name|AFMT_60958_CS_CHANNEL_NUMBER_2
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 0)
end_define

begin_define
define|#
directive|define
name|AFMT_60958_CS_CHANNEL_NUMBER_3
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 4)
end_define

begin_define
define|#
directive|define
name|AFMT_60958_CS_CHANNEL_NUMBER_4
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 8)
end_define

begin_define
define|#
directive|define
name|AFMT_60958_CS_CHANNEL_NUMBER_5
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 12)
end_define

begin_define
define|#
directive|define
name|AFMT_60958_CS_CHANNEL_NUMBER_6
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 16)
end_define

begin_define
define|#
directive|define
name|AFMT_60958_CS_CHANNEL_NUMBER_7
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 20)
end_define

begin_define
define|#
directive|define
name|AFMT_STATUS
value|0x7128
end_define

begin_define
define|#
directive|define
name|AFMT_AUDIO_ENABLE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AFMT_AUDIO_HBR_ENABLE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AFMT_AZ_FORMAT_WTRIG
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|AFMT_AZ_FORMAT_WTRIG_INT
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|AFMT_AZ_AUDIO_ENABLE_CHG
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|AFMT_AUDIO_PACKET_CONTROL
value|0x712c
end_define

begin_define
define|#
directive|define
name|AFMT_AUDIO_SAMPLE_SEND
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AFMT_RESET_FIFO_WHEN_AUDIO_DIS
value|(1<< 11)
end_define

begin_comment
comment|/* set to 1 */
end_comment

begin_define
define|#
directive|define
name|AFMT_AUDIO_TEST_EN
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|AFMT_AUDIO_CHANNEL_SWAP
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|AFMT_60958_CS_UPDATE
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|AFMT_AZ_AUDIO_ENABLE_CHG_MASK
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|AFMT_AZ_FORMAT_WTRIG_MASK
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|AFMT_AZ_FORMAT_WTRIG_ACK
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|AFMT_AZ_AUDIO_ENABLE_CHG_ACK
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|AFMT_VBI_PACKET_CONTROL
value|0x7130
end_define

begin_define
define|#
directive|define
name|AFMT_GENERIC0_UPDATE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AFMT_INFOFRAME_CONTROL0
value|0x7134
end_define

begin_define
define|#
directive|define
name|AFMT_AUDIO_INFO_SOURCE
value|(1<< 6)
end_define

begin_comment
comment|/* 0 - sound block; 1 - afmt regs */
end_comment

begin_define
define|#
directive|define
name|AFMT_AUDIO_INFO_UPDATE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AFMT_MPEG_INFO_UPDATE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|AFMT_GENERIC0_7
value|0x7138
end_define

begin_comment
comment|/* DCE4/5 ELD audio interface */
end_comment

begin_define
define|#
directive|define
name|AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR0
value|0x5f84
end_define

begin_comment
comment|/* LPCM */
end_comment

begin_define
define|#
directive|define
name|AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR1
value|0x5f88
end_define

begin_comment
comment|/* AC3 */
end_comment

begin_define
define|#
directive|define
name|AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR2
value|0x5f8c
end_define

begin_comment
comment|/* MPEG1 */
end_comment

begin_define
define|#
directive|define
name|AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR3
value|0x5f90
end_define

begin_comment
comment|/* MP3 */
end_comment

begin_define
define|#
directive|define
name|AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR4
value|0x5f94
end_define

begin_comment
comment|/* MPEG2 */
end_comment

begin_define
define|#
directive|define
name|AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR5
value|0x5f98
end_define

begin_comment
comment|/* AAC */
end_comment

begin_define
define|#
directive|define
name|AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR6
value|0x5f9c
end_define

begin_comment
comment|/* DTS */
end_comment

begin_define
define|#
directive|define
name|AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR7
value|0x5fa0
end_define

begin_comment
comment|/* ATRAC */
end_comment

begin_define
define|#
directive|define
name|AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR8
value|0x5fa4
end_define

begin_comment
comment|/* one bit audio - leave at 0 (default) */
end_comment

begin_define
define|#
directive|define
name|AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR9
value|0x5fa8
end_define

begin_comment
comment|/* Dolby Digital */
end_comment

begin_define
define|#
directive|define
name|AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR10
value|0x5fac
end_define

begin_comment
comment|/* DTS-HD */
end_comment

begin_define
define|#
directive|define
name|AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR11
value|0x5fb0
end_define

begin_comment
comment|/* MAT-MLP */
end_comment

begin_define
define|#
directive|define
name|AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR12
value|0x5fb4
end_define

begin_comment
comment|/* DTS */
end_comment

begin_define
define|#
directive|define
name|AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR13
value|0x5fb8
end_define

begin_comment
comment|/* WMA Pro */
end_comment

begin_define
define|#
directive|define
name|MAX_CHANNELS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 0)
end_define

begin_comment
comment|/* max channels minus one.  7 = 8 channels */
end_comment

begin_define
define|#
directive|define
name|SUPPORTED_FREQUENCIES
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 8)
end_define

begin_define
define|#
directive|define
name|DESCRIPTOR_BYTE_2
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 16)
end_define

begin_define
define|#
directive|define
name|SUPPORTED_FREQUENCIES_STEREO
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 24)
end_define

begin_comment
comment|/* LPCM only */
end_comment

begin_comment
comment|/* SUPPORTED_FREQUENCIES, SUPPORTED_FREQUENCIES_STEREO  * bit0 = 32 kHz  * bit1 = 44.1 kHz  * bit2 = 48 kHz  * bit3 = 88.2 kHz  * bit4 = 96 kHz  * bit5 = 176.4 kHz  * bit6 = 192 kHz  */
end_comment

begin_define
define|#
directive|define
name|AZ_HOT_PLUG_CONTROL
value|0x5e78
end_define

begin_define
define|#
directive|define
name|AZ_FORCE_CODEC_WAKE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|PIN0_JACK_DETECTION_ENABLE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|PIN1_JACK_DETECTION_ENABLE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|PIN2_JACK_DETECTION_ENABLE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|PIN3_JACK_DETECTION_ENABLE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|PIN0_UNSOLICITED_RESPONSE_ENABLE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|PIN1_UNSOLICITED_RESPONSE_ENABLE
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|PIN2_UNSOLICITED_RESPONSE_ENABLE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|PIN3_UNSOLICITED_RESPONSE_ENABLE
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|CODEC_HOT_PLUG_ENABLE
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|PIN0_AUDIO_ENABLED
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|PIN1_AUDIO_ENABLED
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|PIN2_AUDIO_ENABLED
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|PIN3_AUDIO_ENABLED
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|AUDIO_ENABLED
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|GC_USER_SHADER_PIPE_CONFIG
value|0x8954
end_define

begin_define
define|#
directive|define
name|INACTIVE_QD_PIPES
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|INACTIVE_QD_PIPES_MASK
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|INACTIVE_SIMDS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|INACTIVE_SIMDS_MASK
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|GRBM_CNTL
value|0x8000
end_define

begin_define
define|#
directive|define
name|GRBM_READ_TIMEOUT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|GRBM_SOFT_RESET
value|0x8020
end_define

begin_define
define|#
directive|define
name|SOFT_RESET_CP
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SOFT_RESET_CB
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SOFT_RESET_DB
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|SOFT_RESET_PA
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|SOFT_RESET_SC
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|SOFT_RESET_SPI
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|SOFT_RESET_SH
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|SOFT_RESET_SX
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|SOFT_RESET_TC
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|SOFT_RESET_TA
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|SOFT_RESET_VC
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|SOFT_RESET_VGT
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|GRBM_STATUS
value|0x8010
end_define

begin_define
define|#
directive|define
name|CMDFIFO_AVAIL_MASK
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|SRBM_RQ_PENDING
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|CF_RQ_PENDING
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|PF_RQ_PENDING
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|GRBM_EE_BUSY
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|SX_CLEAN
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|DB_CLEAN
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|CB_CLEAN
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|TA_BUSY
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|VGT_BUSY_NO_DMA
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|VGT_BUSY
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|SX_BUSY
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|SH_BUSY
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|SPI_BUSY
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|SC_BUSY
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|PA_BUSY
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|DB_BUSY
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|CP_COHERENCY_BUSY
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|CP_BUSY
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|CB_BUSY
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|GUI_ACTIVE
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|GRBM_STATUS_SE0
value|0x8014
end_define

begin_define
define|#
directive|define
name|GRBM_STATUS_SE1
value|0x8018
end_define

begin_define
define|#
directive|define
name|SE_SX_CLEAN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SE_DB_CLEAN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SE_CB_CLEAN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SE_TA_BUSY
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|SE_SX_BUSY
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|SE_SPI_BUSY
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|SE_SH_BUSY
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|SE_SC_BUSY
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|SE_DB_BUSY
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|SE_CB_BUSY
value|(1<< 31)
end_define

begin_comment
comment|/* evergreen */
end_comment

begin_define
define|#
directive|define
name|CG_THERMAL_CTRL
value|0x72c
end_define

begin_define
define|#
directive|define
name|TOFFSET_MASK
value|0x00003FE0
end_define

begin_define
define|#
directive|define
name|TOFFSET_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|CG_MULT_THERMAL_STATUS
value|0x740
end_define

begin_define
define|#
directive|define
name|ASIC_T
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|ASIC_T_MASK
value|0x07FF0000
end_define

begin_define
define|#
directive|define
name|ASIC_T_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|CG_TS0_STATUS
value|0x760
end_define

begin_define
define|#
directive|define
name|TS0_ADC_DOUT_MASK
value|0x000003FF
end_define

begin_define
define|#
directive|define
name|TS0_ADC_DOUT_SHIFT
value|0
end_define

begin_comment
comment|/* APU */
end_comment

begin_define
define|#
directive|define
name|CG_THERMAL_STATUS
value|0x678
end_define

begin_define
define|#
directive|define
name|HDP_HOST_PATH_CNTL
value|0x2C00
end_define

begin_define
define|#
directive|define
name|HDP_NONSURFACE_BASE
value|0x2C04
end_define

begin_define
define|#
directive|define
name|HDP_NONSURFACE_INFO
value|0x2C08
end_define

begin_define
define|#
directive|define
name|HDP_NONSURFACE_SIZE
value|0x2C0C
end_define

begin_define
define|#
directive|define
name|HDP_MEM_COHERENCY_FLUSH_CNTL
value|0x5480
end_define

begin_define
define|#
directive|define
name|HDP_REG_COHERENCY_FLUSH_CNTL
value|0x54A0
end_define

begin_define
define|#
directive|define
name|HDP_TILING_CONFIG
value|0x2F3C
end_define

begin_define
define|#
directive|define
name|MC_SHARED_CHMAP
value|0x2004
end_define

begin_define
define|#
directive|define
name|NOOFCHAN_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|NOOFCHAN_MASK
value|0x00003000
end_define

begin_define
define|#
directive|define
name|MC_SHARED_CHREMAP
value|0x2008
end_define

begin_define
define|#
directive|define
name|MC_SHARED_BLACKOUT_CNTL
value|0x20ac
end_define

begin_define
define|#
directive|define
name|BLACKOUT_MODE_MASK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|MC_ARB_RAMCFG
value|0x2760
end_define

begin_define
define|#
directive|define
name|NOOFBANK_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|NOOFBANK_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|NOOFRANK_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|NOOFRANK_MASK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NOOFROWS_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|NOOFROWS_MASK
value|0x00000038
end_define

begin_define
define|#
directive|define
name|NOOFCOLS_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|NOOFCOLS_MASK
value|0x000000C0
end_define

begin_define
define|#
directive|define
name|CHANSIZE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|CHANSIZE_MASK
value|0x00000100
end_define

begin_define
define|#
directive|define
name|BURSTLENGTH_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|BURSTLENGTH_MASK
value|0x00000200
end_define

begin_define
define|#
directive|define
name|CHANSIZE_OVERRIDE
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|FUS_MC_ARB_RAMCFG
value|0x2768
end_define

begin_define
define|#
directive|define
name|MC_VM_AGP_TOP
value|0x2028
end_define

begin_define
define|#
directive|define
name|MC_VM_AGP_BOT
value|0x202C
end_define

begin_define
define|#
directive|define
name|MC_VM_AGP_BASE
value|0x2030
end_define

begin_define
define|#
directive|define
name|MC_VM_FB_LOCATION
value|0x2024
end_define

begin_define
define|#
directive|define
name|MC_FUS_VM_FB_OFFSET
value|0x2898
end_define

begin_define
define|#
directive|define
name|MC_VM_MB_L1_TLB0_CNTL
value|0x2234
end_define

begin_define
define|#
directive|define
name|MC_VM_MB_L1_TLB1_CNTL
value|0x2238
end_define

begin_define
define|#
directive|define
name|MC_VM_MB_L1_TLB2_CNTL
value|0x223C
end_define

begin_define
define|#
directive|define
name|MC_VM_MB_L1_TLB3_CNTL
value|0x2240
end_define

begin_define
define|#
directive|define
name|ENABLE_L1_TLB
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|ENABLE_L1_FRAGMENT_PROCESSING
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SYSTEM_ACCESS_MODE_PA_ONLY
value|(0<< 3)
end_define

begin_define
define|#
directive|define
name|SYSTEM_ACCESS_MODE_USE_SYS_MAP
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|SYSTEM_ACCESS_MODE_IN_SYS
value|(2<< 3)
end_define

begin_define
define|#
directive|define
name|SYSTEM_ACCESS_MODE_NOT_IN_SYS
value|(3<< 3)
end_define

begin_define
define|#
directive|define
name|SYSTEM_APERTURE_UNMAPPED_ACCESS_PASS_THRU
value|(0<< 5)
end_define

begin_define
define|#
directive|define
name|EFFECTIVE_L1_TLB_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<<15)
end_define

begin_define
define|#
directive|define
name|EFFECTIVE_L1_QUEUE_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<<18)
end_define

begin_define
define|#
directive|define
name|MC_VM_MD_L1_TLB0_CNTL
value|0x2654
end_define

begin_define
define|#
directive|define
name|MC_VM_MD_L1_TLB1_CNTL
value|0x2658
end_define

begin_define
define|#
directive|define
name|MC_VM_MD_L1_TLB2_CNTL
value|0x265C
end_define

begin_define
define|#
directive|define
name|MC_VM_MD_L1_TLB3_CNTL
value|0x2698
end_define

begin_define
define|#
directive|define
name|FUS_MC_VM_MD_L1_TLB0_CNTL
value|0x265C
end_define

begin_define
define|#
directive|define
name|FUS_MC_VM_MD_L1_TLB1_CNTL
value|0x2660
end_define

begin_define
define|#
directive|define
name|FUS_MC_VM_MD_L1_TLB2_CNTL
value|0x2664
end_define

begin_define
define|#
directive|define
name|MC_VM_SYSTEM_APERTURE_DEFAULT_ADDR
value|0x203C
end_define

begin_define
define|#
directive|define
name|MC_VM_SYSTEM_APERTURE_HIGH_ADDR
value|0x2038
end_define

begin_define
define|#
directive|define
name|MC_VM_SYSTEM_APERTURE_LOW_ADDR
value|0x2034
end_define

begin_define
define|#
directive|define
name|PA_CL_ENHANCE
value|0x8A14
end_define

begin_define
define|#
directive|define
name|CLIP_VTX_REORDER_ENA
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|NUM_CLIP_SEQ
parameter_list|(
name|x
parameter_list|)
value|((x)<< 1)
end_define

begin_define
define|#
directive|define
name|PA_SC_ENHANCE
value|0x8BF0
end_define

begin_define
define|#
directive|define
name|PA_SC_AA_CONFIG
value|0x28C04
end_define

begin_define
define|#
directive|define
name|MSAA_NUM_SAMPLES_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|MSAA_NUM_SAMPLES_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|PA_SC_CLIPRECT_RULE
value|0x2820C
end_define

begin_define
define|#
directive|define
name|PA_SC_EDGERULE
value|0x28230
end_define

begin_define
define|#
directive|define
name|PA_SC_FIFO_SIZE
value|0x8BCC
end_define

begin_define
define|#
directive|define
name|SC_PRIM_FIFO_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|SC_HIZ_TILE_FIFO_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 12)
end_define

begin_define
define|#
directive|define
name|SC_EARLYZ_TILE_FIFO_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 20)
end_define

begin_define
define|#
directive|define
name|PA_SC_FORCE_EOV_MAX_CNTS
value|0x8B24
end_define

begin_define
define|#
directive|define
name|FORCE_EOV_MAX_CLK_CNT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|FORCE_EOV_MAX_REZ_CNT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|PA_SC_LINE_STIPPLE
value|0x28A0C
end_define

begin_define
define|#
directive|define
name|PA_SU_LINE_STIPPLE_VALUE
value|0x8A60
end_define

begin_define
define|#
directive|define
name|PA_SC_LINE_STIPPLE_STATE
value|0x8B10
end_define

begin_define
define|#
directive|define
name|SCRATCH_REG0
value|0x8500
end_define

begin_define
define|#
directive|define
name|SCRATCH_REG1
value|0x8504
end_define

begin_define
define|#
directive|define
name|SCRATCH_REG2
value|0x8508
end_define

begin_define
define|#
directive|define
name|SCRATCH_REG3
value|0x850C
end_define

begin_define
define|#
directive|define
name|SCRATCH_REG4
value|0x8510
end_define

begin_define
define|#
directive|define
name|SCRATCH_REG5
value|0x8514
end_define

begin_define
define|#
directive|define
name|SCRATCH_REG6
value|0x8518
end_define

begin_define
define|#
directive|define
name|SCRATCH_REG7
value|0x851C
end_define

begin_define
define|#
directive|define
name|SCRATCH_UMSK
value|0x8540
end_define

begin_define
define|#
directive|define
name|SCRATCH_ADDR
value|0x8544
end_define

begin_define
define|#
directive|define
name|SMX_SAR_CTL0
value|0xA008
end_define

begin_define
define|#
directive|define
name|SMX_DC_CTL0
value|0xA020
end_define

begin_define
define|#
directive|define
name|USE_HASH_FUNCTION
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|NUMBER_OF_SETS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 1)
end_define

begin_define
define|#
directive|define
name|FLUSH_ALL_ON_EVENT
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|STALL_ON_EVENT
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|SMX_EVENT_CTL
value|0xA02C
end_define

begin_define
define|#
directive|define
name|ES_FLUSH_CTL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|GS_FLUSH_CTL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 3)
end_define

begin_define
define|#
directive|define
name|ACK_FLUSH_CTL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 6)
end_define

begin_define
define|#
directive|define
name|SYNC_FLUSH_CTL
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|SPI_CONFIG_CNTL
value|0x9100
end_define

begin_define
define|#
directive|define
name|GPR_WRITE_PRIORITY
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|SPI_CONFIG_CNTL_1
value|0x913C
end_define

begin_define
define|#
directive|define
name|VTX_DONE_DELAY
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|INTERP_ONE_PRIM_PER_ROW
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|SPI_INPUT_Z
value|0x286D8
end_define

begin_define
define|#
directive|define
name|SPI_PS_IN_CONTROL_0
value|0x286CC
end_define

begin_define
define|#
directive|define
name|NUM_INTERP
parameter_list|(
name|x
parameter_list|)
value|((x)<<0)
end_define

begin_define
define|#
directive|define
name|POSITION_ENA
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|POSITION_CENTROID
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|POSITION_ADDR
parameter_list|(
name|x
parameter_list|)
value|((x)<<10)
end_define

begin_define
define|#
directive|define
name|PARAM_GEN
parameter_list|(
name|x
parameter_list|)
value|((x)<<15)
end_define

begin_define
define|#
directive|define
name|PARAM_GEN_ADDR
parameter_list|(
name|x
parameter_list|)
value|((x)<<19)
end_define

begin_define
define|#
directive|define
name|BARYC_SAMPLE_CNTL
parameter_list|(
name|x
parameter_list|)
value|((x)<<26)
end_define

begin_define
define|#
directive|define
name|PERSP_GRADIENT_ENA
value|(1<<28)
end_define

begin_define
define|#
directive|define
name|LINEAR_GRADIENT_ENA
value|(1<<29)
end_define

begin_define
define|#
directive|define
name|POSITION_SAMPLE
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|BARYC_AT_SAMPLE_ENA
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|SQ_CONFIG
value|0x8C00
end_define

begin_define
define|#
directive|define
name|VC_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|EXPORT_SRC_C
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|CS_PRIO
parameter_list|(
name|x
parameter_list|)
value|((x)<< 18)
end_define

begin_define
define|#
directive|define
name|LS_PRIO
parameter_list|(
name|x
parameter_list|)
value|((x)<< 20)
end_define

begin_define
define|#
directive|define
name|HS_PRIO
parameter_list|(
name|x
parameter_list|)
value|((x)<< 22)
end_define

begin_define
define|#
directive|define
name|PS_PRIO
parameter_list|(
name|x
parameter_list|)
value|((x)<< 24)
end_define

begin_define
define|#
directive|define
name|VS_PRIO
parameter_list|(
name|x
parameter_list|)
value|((x)<< 26)
end_define

begin_define
define|#
directive|define
name|GS_PRIO
parameter_list|(
name|x
parameter_list|)
value|((x)<< 28)
end_define

begin_define
define|#
directive|define
name|ES_PRIO
parameter_list|(
name|x
parameter_list|)
value|((x)<< 30)
end_define

begin_define
define|#
directive|define
name|SQ_GPR_RESOURCE_MGMT_1
value|0x8C04
end_define

begin_define
define|#
directive|define
name|NUM_PS_GPRS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|NUM_VS_GPRS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|NUM_CLAUSE_TEMP_GPRS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 28)
end_define

begin_define
define|#
directive|define
name|SQ_GPR_RESOURCE_MGMT_2
value|0x8C08
end_define

begin_define
define|#
directive|define
name|NUM_GS_GPRS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|NUM_ES_GPRS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|SQ_GPR_RESOURCE_MGMT_3
value|0x8C0C
end_define

begin_define
define|#
directive|define
name|NUM_HS_GPRS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|NUM_LS_GPRS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|SQ_GLOBAL_GPR_RESOURCE_MGMT_1
value|0x8C10
end_define

begin_define
define|#
directive|define
name|SQ_GLOBAL_GPR_RESOURCE_MGMT_2
value|0x8C14
end_define

begin_define
define|#
directive|define
name|SQ_THREAD_RESOURCE_MGMT
value|0x8C18
end_define

begin_define
define|#
directive|define
name|NUM_PS_THREADS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|NUM_VS_THREADS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|NUM_GS_THREADS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|NUM_ES_THREADS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 24)
end_define

begin_define
define|#
directive|define
name|SQ_THREAD_RESOURCE_MGMT_2
value|0x8C1C
end_define

begin_define
define|#
directive|define
name|NUM_HS_THREADS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|NUM_LS_THREADS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|SQ_STACK_RESOURCE_MGMT_1
value|0x8C20
end_define

begin_define
define|#
directive|define
name|NUM_PS_STACK_ENTRIES
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|NUM_VS_STACK_ENTRIES
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|SQ_STACK_RESOURCE_MGMT_2
value|0x8C24
end_define

begin_define
define|#
directive|define
name|NUM_GS_STACK_ENTRIES
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|NUM_ES_STACK_ENTRIES
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|SQ_STACK_RESOURCE_MGMT_3
value|0x8C28
end_define

begin_define
define|#
directive|define
name|NUM_HS_STACK_ENTRIES
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|NUM_LS_STACK_ENTRIES
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|SQ_DYN_GPR_CNTL_PS_FLUSH_REQ
value|0x8D8C
end_define

begin_define
define|#
directive|define
name|SQ_DYN_GPR_SIMD_LOCK_EN
value|0x8D94
end_define

begin_define
define|#
directive|define
name|SQ_STATIC_THREAD_MGMT_1
value|0x8E20
end_define

begin_define
define|#
directive|define
name|SQ_STATIC_THREAD_MGMT_2
value|0x8E24
end_define

begin_define
define|#
directive|define
name|SQ_STATIC_THREAD_MGMT_3
value|0x8E28
end_define

begin_define
define|#
directive|define
name|SQ_LDS_RESOURCE_MGMT
value|0x8E2C
end_define

begin_define
define|#
directive|define
name|SQ_MS_FIFO_SIZES
value|0x8CF0
end_define

begin_define
define|#
directive|define
name|CACHE_FIFO_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|FETCH_FIFO_HIWATER
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|DONE_FIFO_HIWATER
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|ALU_UPDATE_FIFO_HIWATER
parameter_list|(
name|x
parameter_list|)
value|((x)<< 24)
end_define

begin_define
define|#
directive|define
name|SX_DEBUG_1
value|0x9058
end_define

begin_define
define|#
directive|define
name|ENABLE_NEW_SMX_ADDRESS
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|SX_EXPORT_BUFFER_SIZES
value|0x900C
end_define

begin_define
define|#
directive|define
name|COLOR_BUFFER_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|POSITION_BUFFER_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|SMX_BUFFER_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|SX_MEMORY_EXPORT_BASE
value|0x9010
end_define

begin_define
define|#
directive|define
name|SX_MISC
value|0x28350
end_define

begin_define
define|#
directive|define
name|CB_PERF_CTR0_SEL_0
value|0x9A20
end_define

begin_define
define|#
directive|define
name|CB_PERF_CTR0_SEL_1
value|0x9A24
end_define

begin_define
define|#
directive|define
name|CB_PERF_CTR1_SEL_0
value|0x9A28
end_define

begin_define
define|#
directive|define
name|CB_PERF_CTR1_SEL_1
value|0x9A2C
end_define

begin_define
define|#
directive|define
name|CB_PERF_CTR2_SEL_0
value|0x9A30
end_define

begin_define
define|#
directive|define
name|CB_PERF_CTR2_SEL_1
value|0x9A34
end_define

begin_define
define|#
directive|define
name|CB_PERF_CTR3_SEL_0
value|0x9A38
end_define

begin_define
define|#
directive|define
name|CB_PERF_CTR3_SEL_1
value|0x9A3C
end_define

begin_define
define|#
directive|define
name|TA_CNTL_AUX
value|0x9508
end_define

begin_define
define|#
directive|define
name|DISABLE_CUBE_WRAP
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DISABLE_CUBE_ANISO
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SYNC_GRADIENT
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|SYNC_WALKER
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|SYNC_ALIGNER
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|TCP_CHAN_STEER_LO
value|0x960c
end_define

begin_define
define|#
directive|define
name|TCP_CHAN_STEER_HI
value|0x9610
end_define

begin_define
define|#
directive|define
name|VGT_CACHE_INVALIDATION
value|0x88C4
end_define

begin_define
define|#
directive|define
name|CACHE_INVALIDATION
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|VC_ONLY
value|0
end_define

begin_define
define|#
directive|define
name|TC_ONLY
value|1
end_define

begin_define
define|#
directive|define
name|VC_AND_TC
value|2
end_define

begin_define
define|#
directive|define
name|AUTO_INVLD_EN
parameter_list|(
name|x
parameter_list|)
value|((x)<< 6)
end_define

begin_define
define|#
directive|define
name|NO_AUTO
value|0
end_define

begin_define
define|#
directive|define
name|ES_AUTO
value|1
end_define

begin_define
define|#
directive|define
name|GS_AUTO
value|2
end_define

begin_define
define|#
directive|define
name|ES_AND_GS_AUTO
value|3
end_define

begin_define
define|#
directive|define
name|VGT_GS_VERTEX_REUSE
value|0x88D4
end_define

begin_define
define|#
directive|define
name|VGT_NUM_INSTANCES
value|0x8974
end_define

begin_define
define|#
directive|define
name|VGT_OUT_DEALLOC_CNTL
value|0x28C5C
end_define

begin_define
define|#
directive|define
name|DEALLOC_DIST_MASK
value|0x0000007F
end_define

begin_define
define|#
directive|define
name|VGT_VERTEX_REUSE_BLOCK_CNTL
value|0x28C58
end_define

begin_define
define|#
directive|define
name|VTX_REUSE_DEPTH_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|VM_CONTEXT0_CNTL
value|0x1410
end_define

begin_define
define|#
directive|define
name|ENABLE_CONTEXT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|PAGE_TABLE_DEPTH
parameter_list|(
name|x
parameter_list|)
value|(((x)& 3)<< 1)
end_define

begin_define
define|#
directive|define
name|RANGE_PROTECTION_FAULT_ENABLE_DEFAULT
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|VM_CONTEXT1_CNTL
value|0x1414
end_define

begin_define
define|#
directive|define
name|VM_CONTEXT1_CNTL2
value|0x1434
end_define

begin_define
define|#
directive|define
name|VM_CONTEXT0_PAGE_TABLE_BASE_ADDR
value|0x153C
end_define

begin_define
define|#
directive|define
name|VM_CONTEXT0_PAGE_TABLE_END_ADDR
value|0x157C
end_define

begin_define
define|#
directive|define
name|VM_CONTEXT0_PAGE_TABLE_START_ADDR
value|0x155C
end_define

begin_define
define|#
directive|define
name|VM_CONTEXT0_PROTECTION_FAULT_DEFAULT_ADDR
value|0x1518
end_define

begin_define
define|#
directive|define
name|VM_CONTEXT0_REQUEST_RESPONSE
value|0x1470
end_define

begin_define
define|#
directive|define
name|REQUEST_TYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 0)
end_define

begin_define
define|#
directive|define
name|RESPONSE_TYPE_MASK
value|0x000000F0
end_define

begin_define
define|#
directive|define
name|RESPONSE_TYPE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|VM_L2_CNTL
value|0x1400
end_define

begin_define
define|#
directive|define
name|ENABLE_L2_CACHE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|ENABLE_L2_FRAGMENT_PROCESSING
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|ENABLE_L2_PTE_CACHE_LRU_UPDATE_BY_WRITE
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|EFFECTIVE_L2_QUEUE_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 7)<< 14)
end_define

begin_define
define|#
directive|define
name|VM_L2_CNTL2
value|0x1404
end_define

begin_define
define|#
directive|define
name|INVALIDATE_ALL_L1_TLBS
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|INVALIDATE_L2_CACHE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|VM_L2_CNTL3
value|0x1408
end_define

begin_define
define|#
directive|define
name|BANK_SELECT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|CACHE_UPDATE_MODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 6)
end_define

begin_define
define|#
directive|define
name|VM_L2_STATUS
value|0x140C
end_define

begin_define
define|#
directive|define
name|L2_BUSY
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|VM_CONTEXT1_PROTECTION_FAULT_ADDR
value|0x14FC
end_define

begin_define
define|#
directive|define
name|VM_CONTEXT1_PROTECTION_FAULT_STATUS
value|0x14DC
end_define

begin_define
define|#
directive|define
name|WAIT_UNTIL
value|0x8040
end_define

begin_define
define|#
directive|define
name|SRBM_STATUS
value|0x0E50
end_define

begin_define
define|#
directive|define
name|SRBM_SOFT_RESET
value|0x0E60
end_define

begin_define
define|#
directive|define
name|SRBM_SOFT_RESET_ALL_MASK
value|0x00FEEFA6
end_define

begin_define
define|#
directive|define
name|SOFT_RESET_BIF
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SOFT_RESET_CG
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SOFT_RESET_DC
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|SOFT_RESET_GRBM
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|SOFT_RESET_HDP
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|SOFT_RESET_IH
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|SOFT_RESET_MC
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|SOFT_RESET_RLC
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|SOFT_RESET_ROM
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|SOFT_RESET_SEM
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|SOFT_RESET_VMC
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|SOFT_RESET_DMA
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|SOFT_RESET_TST
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|SOFT_RESET_REGBB
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|SOFT_RESET_ORB
value|(1<< 23)
end_define

begin_comment
comment|/* display watermarks */
end_comment

begin_define
define|#
directive|define
name|DC_LB_MEMORY_SPLIT
value|0x6b0c
end_define

begin_define
define|#
directive|define
name|PRIORITY_A_CNT
value|0x6b18
end_define

begin_define
define|#
directive|define
name|PRIORITY_MARK_MASK
value|0x7fff
end_define

begin_define
define|#
directive|define
name|PRIORITY_OFF
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|PRIORITY_ALWAYS_ON
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|PRIORITY_B_CNT
value|0x6b1c
end_define

begin_define
define|#
directive|define
name|PIPE0_ARBITRATION_CONTROL3
value|0x0bf0
end_define

begin_define
define|#
directive|define
name|LATENCY_WATERMARK_MASK
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|PIPE0_LATENCY_CONTROL
value|0x0bf4
end_define

begin_define
define|#
directive|define
name|LATENCY_LOW_WATERMARK
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|LATENCY_HIGH_WATERMARK
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|IH_RB_CNTL
value|0x3e00
end_define

begin_define
define|#
directive|define
name|IH_RB_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|IH_IB_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 1)
end_define

begin_comment
comment|/* log2 */
end_comment

begin_define
define|#
directive|define
name|IH_RB_FULL_DRAIN_ENABLE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|IH_WPTR_WRITEBACK_ENABLE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|IH_WPTR_WRITEBACK_TIMER
parameter_list|(
name|x
parameter_list|)
value|((x)<< 9)
end_define

begin_comment
comment|/* log2 */
end_comment

begin_define
define|#
directive|define
name|IH_WPTR_OVERFLOW_ENABLE
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|IH_WPTR_OVERFLOW_CLEAR
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|IH_RB_BASE
value|0x3e04
end_define

begin_define
define|#
directive|define
name|IH_RB_RPTR
value|0x3e08
end_define

begin_define
define|#
directive|define
name|IH_RB_WPTR
value|0x3e0c
end_define

begin_define
define|#
directive|define
name|RB_OVERFLOW
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|WPTR_OFFSET_MASK
value|0x3fffc
end_define

begin_define
define|#
directive|define
name|IH_RB_WPTR_ADDR_HI
value|0x3e10
end_define

begin_define
define|#
directive|define
name|IH_RB_WPTR_ADDR_LO
value|0x3e14
end_define

begin_define
define|#
directive|define
name|IH_CNTL
value|0x3e18
end_define

begin_define
define|#
directive|define
name|ENABLE_INTR
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|IH_MC_SWAP
parameter_list|(
name|x
parameter_list|)
value|((x)<< 1)
end_define

begin_define
define|#
directive|define
name|IH_MC_SWAP_NONE
value|0
end_define

begin_define
define|#
directive|define
name|IH_MC_SWAP_16BIT
value|1
end_define

begin_define
define|#
directive|define
name|IH_MC_SWAP_32BIT
value|2
end_define

begin_define
define|#
directive|define
name|IH_MC_SWAP_64BIT
value|3
end_define

begin_define
define|#
directive|define
name|RPTR_REARM
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|MC_WRREQ_CREDIT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 15)
end_define

begin_define
define|#
directive|define
name|MC_WR_CLEAN_CNT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 20)
end_define

begin_define
define|#
directive|define
name|CP_INT_CNTL
value|0xc124
end_define

begin_define
define|#
directive|define
name|CNTX_BUSY_INT_ENABLE
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|CNTX_EMPTY_INT_ENABLE
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|SCRATCH_INT_ENABLE
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|TIME_STAMP_INT_ENABLE
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|IB2_INT_ENABLE
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|IB1_INT_ENABLE
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|RB_INT_ENABLE
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|CP_INT_STATUS
value|0xc128
end_define

begin_define
define|#
directive|define
name|SCRATCH_INT_STAT
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|TIME_STAMP_INT_STAT
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|IB2_INT_STAT
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|IB1_INT_STAT
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|RB_INT_STAT
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|GRBM_INT_CNTL
value|0x8060
end_define

begin_define
define|#
directive|define
name|RDERR_INT_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|GUI_IDLE_INT_ENABLE
value|(1<< 19)
end_define

begin_comment
comment|/* 0x6e98, 0x7a98, 0x10698, 0x11298, 0x11e98, 0x12a98 */
end_comment

begin_define
define|#
directive|define
name|CRTC_STATUS_FRAME_COUNT
value|0x6e98
end_define

begin_comment
comment|/* 0x6bb8, 0x77b8, 0x103b8, 0x10fb8, 0x11bb8, 0x127b8 */
end_comment

begin_define
define|#
directive|define
name|VLINE_STATUS
value|0x6bb8
end_define

begin_define
define|#
directive|define
name|VLINE_OCCURRED
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|VLINE_ACK
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|VLINE_STAT
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|VLINE_INTERRUPT
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|VLINE_INTERRUPT_TYPE
value|(1<< 17)
end_define

begin_comment
comment|/* 0x6bbc, 0x77bc, 0x103bc, 0x10fbc, 0x11bbc, 0x127bc */
end_comment

begin_define
define|#
directive|define
name|VBLANK_STATUS
value|0x6bbc
end_define

begin_define
define|#
directive|define
name|VBLANK_OCCURRED
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|VBLANK_ACK
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|VBLANK_STAT
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|VBLANK_INTERRUPT
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|VBLANK_INTERRUPT_TYPE
value|(1<< 17)
end_define

begin_comment
comment|/* 0x6b40, 0x7740, 0x10340, 0x10f40, 0x11b40, 0x12740 */
end_comment

begin_define
define|#
directive|define
name|INT_MASK
value|0x6b40
end_define

begin_define
define|#
directive|define
name|VBLANK_INT_MASK
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|VLINE_INT_MASK
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|DISP_INTERRUPT_STATUS
value|0x60f4
end_define

begin_define
define|#
directive|define
name|LB_D1_VLINE_INTERRUPT
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|LB_D1_VBLANK_INTERRUPT
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|DC_HPD1_INTERRUPT
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|DC_HPD1_RX_INTERRUPT
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|DACA_AUTODETECT_INTERRUPT
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|DACB_AUTODETECT_INTERRUPT
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|DC_I2C_SW_DONE_INTERRUPT
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|DC_I2C_HW_DONE_INTERRUPT
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|DISP_INTERRUPT_STATUS_CONTINUE
value|0x60f8
end_define

begin_define
define|#
directive|define
name|LB_D2_VLINE_INTERRUPT
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|LB_D2_VBLANK_INTERRUPT
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|DC_HPD2_INTERRUPT
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|DC_HPD2_RX_INTERRUPT
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|DISP_TIMER_INTERRUPT
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|DISP_INTERRUPT_STATUS_CONTINUE2
value|0x60fc
end_define

begin_define
define|#
directive|define
name|LB_D3_VLINE_INTERRUPT
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|LB_D3_VBLANK_INTERRUPT
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|DC_HPD3_INTERRUPT
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|DC_HPD3_RX_INTERRUPT
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|DISP_INTERRUPT_STATUS_CONTINUE3
value|0x6100
end_define

begin_define
define|#
directive|define
name|LB_D4_VLINE_INTERRUPT
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|LB_D4_VBLANK_INTERRUPT
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|DC_HPD4_INTERRUPT
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|DC_HPD4_RX_INTERRUPT
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|DISP_INTERRUPT_STATUS_CONTINUE4
value|0x614c
end_define

begin_define
define|#
directive|define
name|LB_D5_VLINE_INTERRUPT
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|LB_D5_VBLANK_INTERRUPT
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|DC_HPD5_INTERRUPT
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|DC_HPD5_RX_INTERRUPT
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|DISP_INTERRUPT_STATUS_CONTINUE5
value|0x6150
end_define

begin_define
define|#
directive|define
name|LB_D6_VLINE_INTERRUPT
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|LB_D6_VBLANK_INTERRUPT
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|DC_HPD6_INTERRUPT
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|DC_HPD6_RX_INTERRUPT
value|(1<< 18)
end_define

begin_comment
comment|/* 0x6858, 0x7458, 0x10058, 0x10c58, 0x11858, 0x12458 */
end_comment

begin_define
define|#
directive|define
name|GRPH_INT_STATUS
value|0x6858
end_define

begin_define
define|#
directive|define
name|GRPH_PFLIP_INT_OCCURRED
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|GRPH_PFLIP_INT_CLEAR
value|(1<< 8)
end_define

begin_comment
comment|/* 0x685c, 0x745c, 0x1005c, 0x10c5c, 0x1185c, 0x1245c */
end_comment

begin_define
define|#
directive|define
name|GRPH_INT_CONTROL
value|0x685c
end_define

begin_define
define|#
directive|define
name|GRPH_PFLIP_INT_MASK
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|GRPH_PFLIP_INT_TYPE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|DACA_AUTODETECT_INT_CONTROL
value|0x66c8
end_define

begin_define
define|#
directive|define
name|DACB_AUTODETECT_INT_CONTROL
value|0x67c8
end_define

begin_define
define|#
directive|define
name|DC_HPD1_INT_STATUS
value|0x601c
end_define

begin_define
define|#
directive|define
name|DC_HPD2_INT_STATUS
value|0x6028
end_define

begin_define
define|#
directive|define
name|DC_HPD3_INT_STATUS
value|0x6034
end_define

begin_define
define|#
directive|define
name|DC_HPD4_INT_STATUS
value|0x6040
end_define

begin_define
define|#
directive|define
name|DC_HPD5_INT_STATUS
value|0x604c
end_define

begin_define
define|#
directive|define
name|DC_HPD6_INT_STATUS
value|0x6058
end_define

begin_define
define|#
directive|define
name|DC_HPDx_INT_STATUS
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DC_HPDx_SENSE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|DC_HPDx_RX_INT_STATUS
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|DC_HPD1_INT_CONTROL
value|0x6020
end_define

begin_define
define|#
directive|define
name|DC_HPD2_INT_CONTROL
value|0x602c
end_define

begin_define
define|#
directive|define
name|DC_HPD3_INT_CONTROL
value|0x6038
end_define

begin_define
define|#
directive|define
name|DC_HPD4_INT_CONTROL
value|0x6044
end_define

begin_define
define|#
directive|define
name|DC_HPD5_INT_CONTROL
value|0x6050
end_define

begin_define
define|#
directive|define
name|DC_HPD6_INT_CONTROL
value|0x605c
end_define

begin_define
define|#
directive|define
name|DC_HPDx_INT_ACK
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DC_HPDx_INT_POLARITY
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|DC_HPDx_INT_EN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|DC_HPDx_RX_INT_ACK
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|DC_HPDx_RX_INT_EN
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|DC_HPD1_CONTROL
value|0x6024
end_define

begin_define
define|#
directive|define
name|DC_HPD2_CONTROL
value|0x6030
end_define

begin_define
define|#
directive|define
name|DC_HPD3_CONTROL
value|0x603c
end_define

begin_define
define|#
directive|define
name|DC_HPD4_CONTROL
value|0x6048
end_define

begin_define
define|#
directive|define
name|DC_HPD5_CONTROL
value|0x6054
end_define

begin_define
define|#
directive|define
name|DC_HPD6_CONTROL
value|0x6060
end_define

begin_define
define|#
directive|define
name|DC_HPDx_CONNECTION_TIMER
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|DC_HPDx_RX_INT_TIMER
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|DC_HPDx_EN
value|(1<< 28)
end_define

begin_comment
comment|/* ASYNC DMA */
end_comment

begin_define
define|#
directive|define
name|DMA_RB_RPTR
value|0xd008
end_define

begin_define
define|#
directive|define
name|DMA_RB_WPTR
value|0xd00c
end_define

begin_define
define|#
directive|define
name|DMA_CNTL
value|0xd02c
end_define

begin_define
define|#
directive|define
name|TRAP_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SEM_INCOMPLETE_INT_ENABLE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SEM_WAIT_INT_ENABLE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|DATA_SWAP_ENABLE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|FENCE_SWAP_ENABLE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|CTXEMPTY_INT_ENABLE
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|DMA_TILING_CONFIG
value|0xD0B8
end_define

begin_define
define|#
directive|define
name|CAYMAN_DMA1_CNTL
value|0xd82c
end_define

begin_comment
comment|/* async DMA packets */
end_comment

begin_define
define|#
directive|define
name|DMA_PACKET
parameter_list|(
name|cmd
parameter_list|,
name|t
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|((((cmd)& 0xF)<< 28) |	\ 					 (((t)& 0x1)<< 23) |		\ 					 (((s)& 0x1)<< 22) |		\ 					 (((n)& 0xFFFFF)<< 0))
end_define

begin_comment
comment|/* async DMA Packet types */
end_comment

begin_define
define|#
directive|define
name|DMA_PACKET_WRITE
value|0x2
end_define

begin_define
define|#
directive|define
name|DMA_PACKET_COPY
value|0x3
end_define

begin_define
define|#
directive|define
name|DMA_PACKET_INDIRECT_BUFFER
value|0x4
end_define

begin_define
define|#
directive|define
name|DMA_PACKET_SEMAPHORE
value|0x5
end_define

begin_define
define|#
directive|define
name|DMA_PACKET_FENCE
value|0x6
end_define

begin_define
define|#
directive|define
name|DMA_PACKET_TRAP
value|0x7
end_define

begin_define
define|#
directive|define
name|DMA_PACKET_SRBM_WRITE
value|0x9
end_define

begin_define
define|#
directive|define
name|DMA_PACKET_CONSTANT_FILL
value|0xd
end_define

begin_define
define|#
directive|define
name|DMA_PACKET_NOP
value|0xf
end_define

begin_comment
comment|/* PCIE link stuff */
end_comment

begin_define
define|#
directive|define
name|PCIE_LC_TRAINING_CNTL
value|0xa1
end_define

begin_comment
comment|/* PCIE_P */
end_comment

begin_define
define|#
directive|define
name|PCIE_LC_LINK_WIDTH_CNTL
value|0xa2
end_define

begin_comment
comment|/* PCIE_P */
end_comment

begin_define
define|#
directive|define
name|LC_LINK_WIDTH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|LC_LINK_WIDTH_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|LC_LINK_WIDTH_X0
value|0
end_define

begin_define
define|#
directive|define
name|LC_LINK_WIDTH_X1
value|1
end_define

begin_define
define|#
directive|define
name|LC_LINK_WIDTH_X2
value|2
end_define

begin_define
define|#
directive|define
name|LC_LINK_WIDTH_X4
value|3
end_define

begin_define
define|#
directive|define
name|LC_LINK_WIDTH_X8
value|4
end_define

begin_define
define|#
directive|define
name|LC_LINK_WIDTH_X16
value|6
end_define

begin_define
define|#
directive|define
name|LC_LINK_WIDTH_RD_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|LC_LINK_WIDTH_RD_MASK
value|0x70
end_define

begin_define
define|#
directive|define
name|LC_RECONFIG_ARC_MISSING_ESCAPE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|LC_RECONFIG_NOW
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|LC_RENEGOTIATION_SUPPORT
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|LC_RENEGOTIATE_EN
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|LC_SHORT_RECONFIG_EN
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|LC_UPCONFIGURE_SUPPORT
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|LC_UPCONFIGURE_DIS
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|PCIE_LC_SPEED_CNTL
value|0xa4
end_define

begin_comment
comment|/* PCIE_P */
end_comment

begin_define
define|#
directive|define
name|LC_GEN2_EN_STRAP
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LC_TARGET_LINK_SPEED_OVERRIDE_EN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LC_FORCE_EN_HW_SPEED_CHANGE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|LC_FORCE_DIS_HW_SPEED_CHANGE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|LC_SPEED_CHANGE_ATTEMPTS_ALLOWED_MASK
value|(0x3<< 8)
end_define

begin_define
define|#
directive|define
name|LC_SPEED_CHANGE_ATTEMPTS_ALLOWED_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|LC_CURRENT_DATA_RATE
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|LC_VOLTAGE_TIMER_SEL_MASK
value|(0xf<< 14)
end_define

begin_define
define|#
directive|define
name|LC_CLR_FAILED_SPD_CHANGE_CNT
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|LC_OTHER_SIDE_EVER_SENT_GEN2
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|LC_OTHER_SIDE_SUPPORTS_GEN2
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|MM_CFGREGS_CNTL
value|0x544c
end_define

begin_define
define|#
directive|define
name|MM_WR_TO_CFG_EN
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|LINK_CNTL2
value|0x88
end_define

begin_comment
comment|/* F0 */
end_comment

begin_define
define|#
directive|define
name|TARGET_LINK_SPEED_MASK
value|(0xf<< 0)
end_define

begin_define
define|#
directive|define
name|SELECTABLE_DEEMPHASIS
value|(1<< 6)
end_define

begin_comment
comment|/*  * PM4  */
end_comment

begin_define
define|#
directive|define
name|PACKET_TYPE0
value|0
end_define

begin_define
define|#
directive|define
name|PACKET_TYPE1
value|1
end_define

begin_define
define|#
directive|define
name|PACKET_TYPE2
value|2
end_define

begin_define
define|#
directive|define
name|PACKET_TYPE3
value|3
end_define

begin_define
define|#
directive|define
name|CP_PACKET_GET_TYPE
parameter_list|(
name|h
parameter_list|)
value|(((h)>> 30)& 3)
end_define

begin_define
define|#
directive|define
name|CP_PACKET_GET_COUNT
parameter_list|(
name|h
parameter_list|)
value|(((h)>> 16)& 0x3FFF)
end_define

begin_define
define|#
directive|define
name|CP_PACKET0_GET_REG
parameter_list|(
name|h
parameter_list|)
value|(((h)& 0xFFFF)<< 2)
end_define

begin_define
define|#
directive|define
name|CP_PACKET3_GET_OPCODE
parameter_list|(
name|h
parameter_list|)
value|(((h)>> 8)& 0xFF)
end_define

begin_define
define|#
directive|define
name|PACKET0
parameter_list|(
name|reg
parameter_list|,
name|n
parameter_list|)
value|((PACKET_TYPE0<< 30) |				\ 			 (((reg)>> 2)& 0xFFFF) |			\ 			 ((n)& 0x3FFF)<< 16)
end_define

begin_define
define|#
directive|define
name|CP_PACKET2
value|0x80000000
end_define

begin_define
define|#
directive|define
name|PACKET2_PAD_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PACKET2_PAD_MASK
value|(0x3fffffff<< 0)
end_define

begin_define
define|#
directive|define
name|PACKET2
parameter_list|(
name|v
parameter_list|)
value|(CP_PACKET2 | REG_SET(PACKET2_PAD, (v)))
end_define

begin_define
define|#
directive|define
name|PACKET3
parameter_list|(
name|op
parameter_list|,
name|n
parameter_list|)
value|((PACKET_TYPE3<< 30) |				\ 			 (((op)& 0xFF)<< 8) |				\ 			 ((n)& 0x3FFF)<< 16)
end_define

begin_comment
comment|/* Packet 3 types */
end_comment

begin_define
define|#
directive|define
name|PACKET3_NOP
value|0x10
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_BASE
value|0x11
end_define

begin_define
define|#
directive|define
name|PACKET3_CLEAR_STATE
value|0x12
end_define

begin_define
define|#
directive|define
name|PACKET3_INDEX_BUFFER_SIZE
value|0x13
end_define

begin_define
define|#
directive|define
name|PACKET3_DISPATCH_DIRECT
value|0x15
end_define

begin_define
define|#
directive|define
name|PACKET3_DISPATCH_INDIRECT
value|0x16
end_define

begin_define
define|#
directive|define
name|PACKET3_INDIRECT_BUFFER_END
value|0x17
end_define

begin_define
define|#
directive|define
name|PACKET3_MODE_CONTROL
value|0x18
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_PREDICATION
value|0x20
end_define

begin_define
define|#
directive|define
name|PACKET3_REG_RMW
value|0x21
end_define

begin_define
define|#
directive|define
name|PACKET3_COND_EXEC
value|0x22
end_define

begin_define
define|#
directive|define
name|PACKET3_PRED_EXEC
value|0x23
end_define

begin_define
define|#
directive|define
name|PACKET3_DRAW_INDIRECT
value|0x24
end_define

begin_define
define|#
directive|define
name|PACKET3_DRAW_INDEX_INDIRECT
value|0x25
end_define

begin_define
define|#
directive|define
name|PACKET3_INDEX_BASE
value|0x26
end_define

begin_define
define|#
directive|define
name|PACKET3_DRAW_INDEX_2
value|0x27
end_define

begin_define
define|#
directive|define
name|PACKET3_CONTEXT_CONTROL
value|0x28
end_define

begin_define
define|#
directive|define
name|PACKET3_DRAW_INDEX_OFFSET
value|0x29
end_define

begin_define
define|#
directive|define
name|PACKET3_INDEX_TYPE
value|0x2A
end_define

begin_define
define|#
directive|define
name|PACKET3_DRAW_INDEX
value|0x2B
end_define

begin_define
define|#
directive|define
name|PACKET3_DRAW_INDEX_AUTO
value|0x2D
end_define

begin_define
define|#
directive|define
name|PACKET3_DRAW_INDEX_IMMD
value|0x2E
end_define

begin_define
define|#
directive|define
name|PACKET3_NUM_INSTANCES
value|0x2F
end_define

begin_define
define|#
directive|define
name|PACKET3_DRAW_INDEX_MULTI_AUTO
value|0x30
end_define

begin_define
define|#
directive|define
name|PACKET3_STRMOUT_BUFFER_UPDATE
value|0x34
end_define

begin_define
define|#
directive|define
name|PACKET3_DRAW_INDEX_OFFSET_2
value|0x35
end_define

begin_define
define|#
directive|define
name|PACKET3_DRAW_INDEX_MULTI_ELEMENT
value|0x36
end_define

begin_define
define|#
directive|define
name|PACKET3_MEM_SEMAPHORE
value|0x39
end_define

begin_define
define|#
directive|define
name|PACKET3_MPEG_INDEX
value|0x3A
end_define

begin_define
define|#
directive|define
name|PACKET3_COPY_DW
value|0x3B
end_define

begin_define
define|#
directive|define
name|PACKET3_WAIT_REG_MEM
value|0x3C
end_define

begin_define
define|#
directive|define
name|PACKET3_MEM_WRITE
value|0x3D
end_define

begin_define
define|#
directive|define
name|PACKET3_INDIRECT_BUFFER
value|0x32
end_define

begin_define
define|#
directive|define
name|PACKET3_CP_DMA
value|0x41
end_define

begin_comment
comment|/* 1. header  * 2. SRC_ADDR_LO or DATA [31:0]  * 3. CP_SYNC [31] | SRC_SEL [30:29] | ENGINE [27] | DST_SEL [21:20] |  *    SRC_ADDR_HI [7:0]  * 4. DST_ADDR_LO [31:0]  * 5. DST_ADDR_HI [7:0]  * 6. COMMAND [29:22] | BYTE_COUNT [20:0]  */
end_comment

begin_define
define|#
directive|define
name|PACKET3_CP_DMA_DST_SEL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 20)
end_define

begin_comment
comment|/* 0 - SRC_ADDR 		 * 1 - GDS 		 */
end_comment

begin_define
define|#
directive|define
name|PACKET3_CP_DMA_ENGINE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 27)
end_define

begin_comment
comment|/* 0 - ME 		 * 1 - PFP 		 */
end_comment

begin_define
define|#
directive|define
name|PACKET3_CP_DMA_SRC_SEL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 29)
end_define

begin_comment
comment|/* 0 - SRC_ADDR 		 * 1 - GDS 		 * 2 - DATA 		 */
end_comment

begin_define
define|#
directive|define
name|PACKET3_CP_DMA_CP_SYNC
value|(1<< 31)
end_define

begin_comment
comment|/* COMMAND */
end_comment

begin_define
define|#
directive|define
name|PACKET3_CP_DMA_DIS_WC
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|PACKET3_CP_DMA_CMD_SRC_SWAP
parameter_list|(
name|x
parameter_list|)
value|((x)<< 23)
end_define

begin_comment
comment|/* 0 - none 		 * 1 - 8 in 16 		 * 2 - 8 in 32 		 * 3 - 8 in 64 		 */
end_comment

begin_define
define|#
directive|define
name|PACKET3_CP_DMA_CMD_DST_SWAP
parameter_list|(
name|x
parameter_list|)
value|((x)<< 24)
end_define

begin_comment
comment|/* 0 - none 		 * 1 - 8 in 16 		 * 2 - 8 in 32 		 * 3 - 8 in 64 		 */
end_comment

begin_define
define|#
directive|define
name|PACKET3_CP_DMA_CMD_SAS
value|(1<< 26)
end_define

begin_comment
comment|/* 0 - memory 		 * 1 - register 		 */
end_comment

begin_define
define|#
directive|define
name|PACKET3_CP_DMA_CMD_DAS
value|(1<< 27)
end_define

begin_comment
comment|/* 0 - memory 		 * 1 - register 		 */
end_comment

begin_define
define|#
directive|define
name|PACKET3_CP_DMA_CMD_SAIC
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|PACKET3_CP_DMA_CMD_DAIC
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|PACKET3_SURFACE_SYNC
value|0x43
end_define

begin_define
define|#
directive|define
name|PACKET3_CB0_DEST_BASE_ENA
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|PACKET3_CB1_DEST_BASE_ENA
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|PACKET3_CB2_DEST_BASE_ENA
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|PACKET3_CB3_DEST_BASE_ENA
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|PACKET3_CB4_DEST_BASE_ENA
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|PACKET3_CB5_DEST_BASE_ENA
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|PACKET3_CB6_DEST_BASE_ENA
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|PACKET3_CB7_DEST_BASE_ENA
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|PACKET3_DB_DEST_BASE_ENA
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|PACKET3_CB8_DEST_BASE_ENA
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|PACKET3_CB9_DEST_BASE_ENA
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|PACKET3_CB10_DEST_BASE_ENA
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|PACKET3_CB11_DEST_BASE_ENA
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|PACKET3_FULL_CACHE_ENA
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|PACKET3_TC_ACTION_ENA
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|PACKET3_VC_ACTION_ENA
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|PACKET3_CB_ACTION_ENA
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|PACKET3_DB_ACTION_ENA
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|PACKET3_SH_ACTION_ENA
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|PACKET3_SX_ACTION_ENA
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|PACKET3_ME_INITIALIZE
value|0x44
end_define

begin_define
define|#
directive|define
name|PACKET3_ME_INITIALIZE_DEVICE_ID
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|PACKET3_COND_WRITE
value|0x45
end_define

begin_define
define|#
directive|define
name|PACKET3_EVENT_WRITE
value|0x46
end_define

begin_define
define|#
directive|define
name|PACKET3_EVENT_WRITE_EOP
value|0x47
end_define

begin_define
define|#
directive|define
name|PACKET3_EVENT_WRITE_EOS
value|0x48
end_define

begin_define
define|#
directive|define
name|PACKET3_PREAMBLE_CNTL
value|0x4A
end_define

begin_define
define|#
directive|define
name|PACKET3_PREAMBLE_BEGIN_CLEAR_STATE
value|(2<< 28)
end_define

begin_define
define|#
directive|define
name|PACKET3_PREAMBLE_END_CLEAR_STATE
value|(3<< 28)
end_define

begin_define
define|#
directive|define
name|PACKET3_RB_OFFSET
value|0x4B
end_define

begin_define
define|#
directive|define
name|PACKET3_ALU_PS_CONST_BUFFER_COPY
value|0x4C
end_define

begin_define
define|#
directive|define
name|PACKET3_ALU_VS_CONST_BUFFER_COPY
value|0x4D
end_define

begin_define
define|#
directive|define
name|PACKET3_ALU_PS_CONST_UPDATE
value|0x4E
end_define

begin_define
define|#
directive|define
name|PACKET3_ALU_VS_CONST_UPDATE
value|0x4F
end_define

begin_define
define|#
directive|define
name|PACKET3_ONE_REG_WRITE
value|0x57
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_CONFIG_REG
value|0x68
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_CONFIG_REG_START
value|0x00008000
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_CONFIG_REG_END
value|0x0000ac00
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_CONTEXT_REG
value|0x69
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_CONTEXT_REG_START
value|0x00028000
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_CONTEXT_REG_END
value|0x00029000
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_ALU_CONST
value|0x6A
end_define

begin_comment
comment|/* alu const buffers only; no reg file */
end_comment

begin_define
define|#
directive|define
name|PACKET3_SET_BOOL_CONST
value|0x6B
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_BOOL_CONST_START
value|0x0003a500
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_BOOL_CONST_END
value|0x0003a518
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_LOOP_CONST
value|0x6C
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_LOOP_CONST_START
value|0x0003a200
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_LOOP_CONST_END
value|0x0003a500
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_RESOURCE
value|0x6D
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_RESOURCE_START
value|0x00030000
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_RESOURCE_END
value|0x00038000
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_SAMPLER
value|0x6E
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_SAMPLER_START
value|0x0003c000
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_SAMPLER_END
value|0x0003c600
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_CTL_CONST
value|0x6F
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_CTL_CONST_START
value|0x0003cff0
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_CTL_CONST_END
value|0x0003ff0c
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_RESOURCE_OFFSET
value|0x70
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_ALU_CONST_VS
value|0x71
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_ALU_CONST_DI
value|0x72
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_CONTEXT_REG_INDIRECT
value|0x73
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_RESOURCE_INDIRECT
value|0x74
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_APPEND_CNT
value|0x75
end_define

begin_define
define|#
directive|define
name|SQ_RESOURCE_CONSTANT_WORD7_0
value|0x3001c
end_define

begin_define
define|#
directive|define
name|S__SQ_CONSTANT_TYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 3)<< 30)
end_define

begin_define
define|#
directive|define
name|G__SQ_CONSTANT_TYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 30)& 3)
end_define

begin_define
define|#
directive|define
name|SQ_TEX_VTX_INVALID_TEXTURE
value|0x0
end_define

begin_define
define|#
directive|define
name|SQ_TEX_VTX_INVALID_BUFFER
value|0x1
end_define

begin_define
define|#
directive|define
name|SQ_TEX_VTX_VALID_TEXTURE
value|0x2
end_define

begin_define
define|#
directive|define
name|SQ_TEX_VTX_VALID_BUFFER
value|0x3
end_define

begin_define
define|#
directive|define
name|VGT_VTX_VECT_EJECT_REG
value|0x88b0
end_define

begin_define
define|#
directive|define
name|SQ_CONST_MEM_BASE
value|0x8df8
end_define

begin_define
define|#
directive|define
name|SQ_ESGS_RING_BASE
value|0x8c40
end_define

begin_define
define|#
directive|define
name|SQ_ESGS_RING_SIZE
value|0x8c44
end_define

begin_define
define|#
directive|define
name|SQ_GSVS_RING_BASE
value|0x8c48
end_define

begin_define
define|#
directive|define
name|SQ_GSVS_RING_SIZE
value|0x8c4c
end_define

begin_define
define|#
directive|define
name|SQ_ESTMP_RING_BASE
value|0x8c50
end_define

begin_define
define|#
directive|define
name|SQ_ESTMP_RING_SIZE
value|0x8c54
end_define

begin_define
define|#
directive|define
name|SQ_GSTMP_RING_BASE
value|0x8c58
end_define

begin_define
define|#
directive|define
name|SQ_GSTMP_RING_SIZE
value|0x8c5c
end_define

begin_define
define|#
directive|define
name|SQ_VSTMP_RING_BASE
value|0x8c60
end_define

begin_define
define|#
directive|define
name|SQ_VSTMP_RING_SIZE
value|0x8c64
end_define

begin_define
define|#
directive|define
name|SQ_PSTMP_RING_BASE
value|0x8c68
end_define

begin_define
define|#
directive|define
name|SQ_PSTMP_RING_SIZE
value|0x8c6c
end_define

begin_define
define|#
directive|define
name|SQ_LSTMP_RING_BASE
value|0x8e10
end_define

begin_define
define|#
directive|define
name|SQ_LSTMP_RING_SIZE
value|0x8e14
end_define

begin_define
define|#
directive|define
name|SQ_HSTMP_RING_BASE
value|0x8e18
end_define

begin_define
define|#
directive|define
name|SQ_HSTMP_RING_SIZE
value|0x8e1c
end_define

begin_define
define|#
directive|define
name|VGT_TF_RING_SIZE
value|0x8988
end_define

begin_define
define|#
directive|define
name|SQ_ESGS_RING_ITEMSIZE
value|0x28900
end_define

begin_define
define|#
directive|define
name|SQ_GSVS_RING_ITEMSIZE
value|0x28904
end_define

begin_define
define|#
directive|define
name|SQ_ESTMP_RING_ITEMSIZE
value|0x28908
end_define

begin_define
define|#
directive|define
name|SQ_GSTMP_RING_ITEMSIZE
value|0x2890c
end_define

begin_define
define|#
directive|define
name|SQ_VSTMP_RING_ITEMSIZE
value|0x28910
end_define

begin_define
define|#
directive|define
name|SQ_PSTMP_RING_ITEMSIZE
value|0x28914
end_define

begin_define
define|#
directive|define
name|SQ_LSTMP_RING_ITEMSIZE
value|0x28830
end_define

begin_define
define|#
directive|define
name|SQ_HSTMP_RING_ITEMSIZE
value|0x28834
end_define

begin_define
define|#
directive|define
name|SQ_GS_VERT_ITEMSIZE
value|0x2891c
end_define

begin_define
define|#
directive|define
name|SQ_GS_VERT_ITEMSIZE_1
value|0x28920
end_define

begin_define
define|#
directive|define
name|SQ_GS_VERT_ITEMSIZE_2
value|0x28924
end_define

begin_define
define|#
directive|define
name|SQ_GS_VERT_ITEMSIZE_3
value|0x28928
end_define

begin_define
define|#
directive|define
name|SQ_GSVS_RING_OFFSET_1
value|0x2892c
end_define

begin_define
define|#
directive|define
name|SQ_GSVS_RING_OFFSET_2
value|0x28930
end_define

begin_define
define|#
directive|define
name|SQ_GSVS_RING_OFFSET_3
value|0x28934
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_BUFFER_SIZE_PS_0
value|0x28140
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_BUFFER_SIZE_HS_0
value|0x28f80
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_PS_0
value|0x28940
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_PS_1
value|0x28944
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_PS_2
value|0x28948
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_PS_3
value|0x2894c
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_PS_4
value|0x28950
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_PS_5
value|0x28954
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_PS_6
value|0x28958
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_PS_7
value|0x2895c
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_PS_8
value|0x28960
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_PS_9
value|0x28964
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_PS_10
value|0x28968
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_PS_11
value|0x2896c
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_PS_12
value|0x28970
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_PS_13
value|0x28974
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_PS_14
value|0x28978
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_PS_15
value|0x2897c
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_VS_0
value|0x28980
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_VS_1
value|0x28984
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_VS_2
value|0x28988
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_VS_3
value|0x2898c
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_VS_4
value|0x28990
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_VS_5
value|0x28994
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_VS_6
value|0x28998
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_VS_7
value|0x2899c
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_VS_8
value|0x289a0
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_VS_9
value|0x289a4
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_VS_10
value|0x289a8
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_VS_11
value|0x289ac
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_VS_12
value|0x289b0
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_VS_13
value|0x289b4
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_VS_14
value|0x289b8
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_VS_15
value|0x289bc
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_GS_0
value|0x289c0
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_GS_1
value|0x289c4
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_GS_2
value|0x289c8
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_GS_3
value|0x289cc
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_GS_4
value|0x289d0
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_GS_5
value|0x289d4
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_GS_6
value|0x289d8
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_GS_7
value|0x289dc
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_GS_8
value|0x289e0
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_GS_9
value|0x289e4
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_GS_10
value|0x289e8
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_GS_11
value|0x289ec
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_GS_12
value|0x289f0
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_GS_13
value|0x289f4
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_GS_14
value|0x289f8
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_GS_15
value|0x289fc
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_HS_0
value|0x28f00
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_HS_1
value|0x28f04
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_HS_2
value|0x28f08
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_HS_3
value|0x28f0c
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_HS_4
value|0x28f10
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_HS_5
value|0x28f14
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_HS_6
value|0x28f18
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_HS_7
value|0x28f1c
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_HS_8
value|0x28f20
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_HS_9
value|0x28f24
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_HS_10
value|0x28f28
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_HS_11
value|0x28f2c
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_HS_12
value|0x28f30
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_HS_13
value|0x28f34
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_HS_14
value|0x28f38
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_HS_15
value|0x28f3c
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_LS_0
value|0x28f40
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_LS_1
value|0x28f44
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_LS_2
value|0x28f48
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_LS_3
value|0x28f4c
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_LS_4
value|0x28f50
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_LS_5
value|0x28f54
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_LS_6
value|0x28f58
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_LS_7
value|0x28f5c
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_LS_8
value|0x28f60
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_LS_9
value|0x28f64
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_LS_10
value|0x28f68
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_LS_11
value|0x28f6c
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_LS_12
value|0x28f70
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_LS_13
value|0x28f74
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_LS_14
value|0x28f78
end_define

begin_define
define|#
directive|define
name|SQ_ALU_CONST_CACHE_LS_15
value|0x28f7c
end_define

begin_define
define|#
directive|define
name|PA_SC_SCREEN_SCISSOR_TL
value|0x28030
end_define

begin_define
define|#
directive|define
name|PA_SC_GENERIC_SCISSOR_TL
value|0x28240
end_define

begin_define
define|#
directive|define
name|PA_SC_WINDOW_SCISSOR_TL
value|0x28204
end_define

begin_define
define|#
directive|define
name|VGT_PRIMITIVE_TYPE
value|0x8958
end_define

begin_define
define|#
directive|define
name|VGT_INDEX_TYPE
value|0x895C
end_define

begin_define
define|#
directive|define
name|VGT_NUM_INDICES
value|0x8970
end_define

begin_define
define|#
directive|define
name|VGT_COMPUTE_DIM_X
value|0x8990
end_define

begin_define
define|#
directive|define
name|VGT_COMPUTE_DIM_Y
value|0x8994
end_define

begin_define
define|#
directive|define
name|VGT_COMPUTE_DIM_Z
value|0x8998
end_define

begin_define
define|#
directive|define
name|VGT_COMPUTE_START_X
value|0x899C
end_define

begin_define
define|#
directive|define
name|VGT_COMPUTE_START_Y
value|0x89A0
end_define

begin_define
define|#
directive|define
name|VGT_COMPUTE_START_Z
value|0x89A4
end_define

begin_define
define|#
directive|define
name|VGT_COMPUTE_INDEX
value|0x89A8
end_define

begin_define
define|#
directive|define
name|VGT_COMPUTE_THREAD_GROUP_SIZE
value|0x89AC
end_define

begin_define
define|#
directive|define
name|VGT_HS_OFFCHIP_PARAM
value|0x89B0
end_define

begin_define
define|#
directive|define
name|DB_DEBUG
value|0x9830
end_define

begin_define
define|#
directive|define
name|DB_DEBUG2
value|0x9834
end_define

begin_define
define|#
directive|define
name|DB_DEBUG3
value|0x9838
end_define

begin_define
define|#
directive|define
name|DB_DEBUG4
value|0x983C
end_define

begin_define
define|#
directive|define
name|DB_WATERMARKS
value|0x9854
end_define

begin_define
define|#
directive|define
name|DB_DEPTH_CONTROL
value|0x28800
end_define

begin_define
define|#
directive|define
name|R_028800_DB_DEPTH_CONTROL
value|0x028800
end_define

begin_define
define|#
directive|define
name|S_028800_STENCIL_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_028800_STENCIL_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_028800_STENCIL_ENABLE
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_028800_Z_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 1)
end_define

begin_define
define|#
directive|define
name|G_028800_Z_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_028800_Z_ENABLE
value|0xFFFFFFFD
end_define

begin_define
define|#
directive|define
name|S_028800_Z_WRITE_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 2)
end_define

begin_define
define|#
directive|define
name|G_028800_Z_WRITE_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 2)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_028800_Z_WRITE_ENABLE
value|0xFFFFFFFB
end_define

begin_define
define|#
directive|define
name|S_028800_ZFUNC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 4)
end_define

begin_define
define|#
directive|define
name|G_028800_ZFUNC
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_028800_ZFUNC
value|0xFFFFFF8F
end_define

begin_define
define|#
directive|define
name|S_028800_BACKFACE_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 7)
end_define

begin_define
define|#
directive|define
name|G_028800_BACKFACE_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 7)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_028800_BACKFACE_ENABLE
value|0xFFFFFF7F
end_define

begin_define
define|#
directive|define
name|S_028800_STENCILFUNC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 8)
end_define

begin_define
define|#
directive|define
name|G_028800_STENCILFUNC
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_028800_STENCILFUNC
value|0xFFFFF8FF
end_define

begin_define
define|#
directive|define
name|V_028800_STENCILFUNC_NEVER
value|0x00000000
end_define

begin_define
define|#
directive|define
name|V_028800_STENCILFUNC_LESS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|V_028800_STENCILFUNC_EQUAL
value|0x00000002
end_define

begin_define
define|#
directive|define
name|V_028800_STENCILFUNC_LEQUAL
value|0x00000003
end_define

begin_define
define|#
directive|define
name|V_028800_STENCILFUNC_GREATER
value|0x00000004
end_define

begin_define
define|#
directive|define
name|V_028800_STENCILFUNC_NOTEQUAL
value|0x00000005
end_define

begin_define
define|#
directive|define
name|V_028800_STENCILFUNC_GEQUAL
value|0x00000006
end_define

begin_define
define|#
directive|define
name|V_028800_STENCILFUNC_ALWAYS
value|0x00000007
end_define

begin_define
define|#
directive|define
name|S_028800_STENCILFAIL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 11)
end_define

begin_define
define|#
directive|define
name|G_028800_STENCILFAIL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 11)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_028800_STENCILFAIL
value|0xFFFFC7FF
end_define

begin_define
define|#
directive|define
name|V_028800_STENCIL_KEEP
value|0x00000000
end_define

begin_define
define|#
directive|define
name|V_028800_STENCIL_ZERO
value|0x00000001
end_define

begin_define
define|#
directive|define
name|V_028800_STENCIL_REPLACE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|V_028800_STENCIL_INCR
value|0x00000003
end_define

begin_define
define|#
directive|define
name|V_028800_STENCIL_DECR
value|0x00000004
end_define

begin_define
define|#
directive|define
name|V_028800_STENCIL_INVERT
value|0x00000005
end_define

begin_define
define|#
directive|define
name|V_028800_STENCIL_INCR_WRAP
value|0x00000006
end_define

begin_define
define|#
directive|define
name|V_028800_STENCIL_DECR_WRAP
value|0x00000007
end_define

begin_define
define|#
directive|define
name|S_028800_STENCILZPASS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 14)
end_define

begin_define
define|#
directive|define
name|G_028800_STENCILZPASS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 14)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_028800_STENCILZPASS
value|0xFFFE3FFF
end_define

begin_define
define|#
directive|define
name|S_028800_STENCILZFAIL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 17)
end_define

begin_define
define|#
directive|define
name|G_028800_STENCILZFAIL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 17)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_028800_STENCILZFAIL
value|0xFFF1FFFF
end_define

begin_define
define|#
directive|define
name|S_028800_STENCILFUNC_BF
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 20)
end_define

begin_define
define|#
directive|define
name|G_028800_STENCILFUNC_BF
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_028800_STENCILFUNC_BF
value|0xFF8FFFFF
end_define

begin_define
define|#
directive|define
name|S_028800_STENCILFAIL_BF
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 23)
end_define

begin_define
define|#
directive|define
name|G_028800_STENCILFAIL_BF
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 23)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_028800_STENCILFAIL_BF
value|0xFC7FFFFF
end_define

begin_define
define|#
directive|define
name|S_028800_STENCILZPASS_BF
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 26)
end_define

begin_define
define|#
directive|define
name|G_028800_STENCILZPASS_BF
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 26)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_028800_STENCILZPASS_BF
value|0xE3FFFFFF
end_define

begin_define
define|#
directive|define
name|S_028800_STENCILZFAIL_BF
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 29)
end_define

begin_define
define|#
directive|define
name|G_028800_STENCILZFAIL_BF
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 29)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_028800_STENCILZFAIL_BF
value|0x1FFFFFFF
end_define

begin_define
define|#
directive|define
name|DB_DEPTH_VIEW
value|0x28008
end_define

begin_define
define|#
directive|define
name|R_028008_DB_DEPTH_VIEW
value|0x00028008
end_define

begin_define
define|#
directive|define
name|S_028008_SLICE_START
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7FF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_028008_SLICE_START
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x7FF)
end_define

begin_define
define|#
directive|define
name|C_028008_SLICE_START
value|0xFFFFF800
end_define

begin_define
define|#
directive|define
name|S_028008_SLICE_MAX
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7FF)<< 13)
end_define

begin_define
define|#
directive|define
name|G_028008_SLICE_MAX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 13)& 0x7FF)
end_define

begin_define
define|#
directive|define
name|C_028008_SLICE_MAX
value|0xFF001FFF
end_define

begin_define
define|#
directive|define
name|DB_HTILE_DATA_BASE
value|0x28014
end_define

begin_define
define|#
directive|define
name|DB_HTILE_SURFACE
value|0x28abc
end_define

begin_define
define|#
directive|define
name|S_028ABC_HTILE_WIDTH
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_028ABC_HTILE_WIDTH
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_028ABC_HTILE_WIDTH
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_028ABC_HTILE_HEIGHT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 1)
end_define

begin_define
define|#
directive|define
name|G_028ABC_HTILE_HEIGHT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_028ABC_HTILE_HEIGHT
value|0xFFFFFFFD
end_define

begin_define
define|#
directive|define
name|G_028ABC_LINEAR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 2)& 0x1)
end_define

begin_define
define|#
directive|define
name|DB_Z_INFO
value|0x28040
end_define

begin_define
define|#
directive|define
name|Z_ARRAY_MODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 4)
end_define

begin_define
define|#
directive|define
name|DB_TILE_SPLIT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 8)
end_define

begin_define
define|#
directive|define
name|DB_NUM_BANKS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 12)
end_define

begin_define
define|#
directive|define
name|DB_BANK_WIDTH
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 16)
end_define

begin_define
define|#
directive|define
name|DB_BANK_HEIGHT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 20)
end_define

begin_define
define|#
directive|define
name|DB_MACRO_TILE_ASPECT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 24)
end_define

begin_define
define|#
directive|define
name|R_028040_DB_Z_INFO
value|0x028040
end_define

begin_define
define|#
directive|define
name|S_028040_FORMAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 0)
end_define

begin_define
define|#
directive|define
name|G_028040_FORMAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_028040_FORMAT
value|0xFFFFFFFC
end_define

begin_define
define|#
directive|define
name|V_028040_Z_INVALID
value|0x00000000
end_define

begin_define
define|#
directive|define
name|V_028040_Z_16
value|0x00000001
end_define

begin_define
define|#
directive|define
name|V_028040_Z_24
value|0x00000002
end_define

begin_define
define|#
directive|define
name|V_028040_Z_32_FLOAT
value|0x00000003
end_define

begin_define
define|#
directive|define
name|S_028040_ARRAY_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 4)
end_define

begin_define
define|#
directive|define
name|G_028040_ARRAY_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_028040_ARRAY_MODE
value|0xFFFFFF0F
end_define

begin_define
define|#
directive|define
name|S_028040_READ_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 28)
end_define

begin_define
define|#
directive|define
name|G_028040_READ_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 28)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_028040_READ_SIZE
value|0xEFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_028040_TILE_SURFACE_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 29)
end_define

begin_define
define|#
directive|define
name|G_028040_TILE_SURFACE_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 29)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_028040_TILE_SURFACE_ENABLE
value|0xDFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_028040_ZRANGE_PRECISION
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 31)
end_define

begin_define
define|#
directive|define
name|G_028040_ZRANGE_PRECISION
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 31)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_028040_ZRANGE_PRECISION
value|0x7FFFFFFF
end_define

begin_define
define|#
directive|define
name|S_028040_TILE_SPLIT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 8)
end_define

begin_define
define|#
directive|define
name|G_028040_TILE_SPLIT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x7)
end_define

begin_define
define|#
directive|define
name|S_028040_NUM_BANKS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 12)
end_define

begin_define
define|#
directive|define
name|G_028040_NUM_BANKS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0x3)
end_define

begin_define
define|#
directive|define
name|S_028040_BANK_WIDTH
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 16)
end_define

begin_define
define|#
directive|define
name|G_028040_BANK_WIDTH
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x3)
end_define

begin_define
define|#
directive|define
name|S_028040_BANK_HEIGHT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 20)
end_define

begin_define
define|#
directive|define
name|G_028040_BANK_HEIGHT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 0x3)
end_define

begin_define
define|#
directive|define
name|S_028040_MACRO_TILE_ASPECT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 24)
end_define

begin_define
define|#
directive|define
name|G_028040_MACRO_TILE_ASPECT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0x3)
end_define

begin_define
define|#
directive|define
name|DB_STENCIL_INFO
value|0x28044
end_define

begin_define
define|#
directive|define
name|R_028044_DB_STENCIL_INFO
value|0x028044
end_define

begin_define
define|#
directive|define
name|S_028044_FORMAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_028044_FORMAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_028044_FORMAT
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|V_028044_STENCIL_INVALID
value|0
end_define

begin_define
define|#
directive|define
name|V_028044_STENCIL_8
value|1
end_define

begin_define
define|#
directive|define
name|G_028044_TILE_SPLIT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x7)
end_define

begin_define
define|#
directive|define
name|DB_Z_READ_BASE
value|0x28048
end_define

begin_define
define|#
directive|define
name|DB_STENCIL_READ_BASE
value|0x2804c
end_define

begin_define
define|#
directive|define
name|DB_Z_WRITE_BASE
value|0x28050
end_define

begin_define
define|#
directive|define
name|DB_STENCIL_WRITE_BASE
value|0x28054
end_define

begin_define
define|#
directive|define
name|DB_DEPTH_SIZE
value|0x28058
end_define

begin_define
define|#
directive|define
name|R_028058_DB_DEPTH_SIZE
value|0x028058
end_define

begin_define
define|#
directive|define
name|S_028058_PITCH_TILE_MAX
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7FF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_028058_PITCH_TILE_MAX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x7FF)
end_define

begin_define
define|#
directive|define
name|C_028058_PITCH_TILE_MAX
value|0xFFFFF800
end_define

begin_define
define|#
directive|define
name|S_028058_HEIGHT_TILE_MAX
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7FF)<< 11)
end_define

begin_define
define|#
directive|define
name|G_028058_HEIGHT_TILE_MAX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 11)& 0x7FF)
end_define

begin_define
define|#
directive|define
name|C_028058_HEIGHT_TILE_MAX
value|0xFFC007FF
end_define

begin_define
define|#
directive|define
name|R_02805C_DB_DEPTH_SLICE
value|0x02805C
end_define

begin_define
define|#
directive|define
name|S_02805C_SLICE_TILE_MAX
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3FFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_02805C_SLICE_TILE_MAX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x3FFFFF)
end_define

begin_define
define|#
directive|define
name|C_02805C_SLICE_TILE_MAX
value|0xFFC00000
end_define

begin_define
define|#
directive|define
name|SQ_PGM_START_PS
value|0x28840
end_define

begin_define
define|#
directive|define
name|SQ_PGM_START_VS
value|0x2885c
end_define

begin_define
define|#
directive|define
name|SQ_PGM_START_GS
value|0x28874
end_define

begin_define
define|#
directive|define
name|SQ_PGM_START_ES
value|0x2888c
end_define

begin_define
define|#
directive|define
name|SQ_PGM_START_FS
value|0x288a4
end_define

begin_define
define|#
directive|define
name|SQ_PGM_START_HS
value|0x288b8
end_define

begin_define
define|#
directive|define
name|SQ_PGM_START_LS
value|0x288d0
end_define

begin_define
define|#
directive|define
name|VGT_STRMOUT_BUFFER_BASE_0
value|0x28AD8
end_define

begin_define
define|#
directive|define
name|VGT_STRMOUT_BUFFER_BASE_1
value|0x28AE8
end_define

begin_define
define|#
directive|define
name|VGT_STRMOUT_BUFFER_BASE_2
value|0x28AF8
end_define

begin_define
define|#
directive|define
name|VGT_STRMOUT_BUFFER_BASE_3
value|0x28B08
end_define

begin_define
define|#
directive|define
name|VGT_STRMOUT_BUFFER_SIZE_0
value|0x28AD0
end_define

begin_define
define|#
directive|define
name|VGT_STRMOUT_BUFFER_SIZE_1
value|0x28AE0
end_define

begin_define
define|#
directive|define
name|VGT_STRMOUT_BUFFER_SIZE_2
value|0x28AF0
end_define

begin_define
define|#
directive|define
name|VGT_STRMOUT_BUFFER_SIZE_3
value|0x28B00
end_define

begin_define
define|#
directive|define
name|VGT_STRMOUT_CONFIG
value|0x28b94
end_define

begin_define
define|#
directive|define
name|VGT_STRMOUT_BUFFER_CONFIG
value|0x28b98
end_define

begin_define
define|#
directive|define
name|CB_TARGET_MASK
value|0x28238
end_define

begin_define
define|#
directive|define
name|CB_SHADER_MASK
value|0x2823c
end_define

begin_define
define|#
directive|define
name|GDS_ADDR_BASE
value|0x28720
end_define

begin_define
define|#
directive|define
name|CB_IMMED0_BASE
value|0x28b9c
end_define

begin_define
define|#
directive|define
name|CB_IMMED1_BASE
value|0x28ba0
end_define

begin_define
define|#
directive|define
name|CB_IMMED2_BASE
value|0x28ba4
end_define

begin_define
define|#
directive|define
name|CB_IMMED3_BASE
value|0x28ba8
end_define

begin_define
define|#
directive|define
name|CB_IMMED4_BASE
value|0x28bac
end_define

begin_define
define|#
directive|define
name|CB_IMMED5_BASE
value|0x28bb0
end_define

begin_define
define|#
directive|define
name|CB_IMMED6_BASE
value|0x28bb4
end_define

begin_define
define|#
directive|define
name|CB_IMMED7_BASE
value|0x28bb8
end_define

begin_define
define|#
directive|define
name|CB_IMMED8_BASE
value|0x28bbc
end_define

begin_define
define|#
directive|define
name|CB_IMMED9_BASE
value|0x28bc0
end_define

begin_define
define|#
directive|define
name|CB_IMMED10_BASE
value|0x28bc4
end_define

begin_define
define|#
directive|define
name|CB_IMMED11_BASE
value|0x28bc8
end_define

begin_comment
comment|/* all 12 CB blocks have these regs */
end_comment

begin_define
define|#
directive|define
name|CB_COLOR0_BASE
value|0x28c60
end_define

begin_define
define|#
directive|define
name|CB_COLOR0_PITCH
value|0x28c64
end_define

begin_define
define|#
directive|define
name|CB_COLOR0_SLICE
value|0x28c68
end_define

begin_define
define|#
directive|define
name|CB_COLOR0_VIEW
value|0x28c6c
end_define

begin_define
define|#
directive|define
name|R_028C6C_CB_COLOR0_VIEW
value|0x00028C6C
end_define

begin_define
define|#
directive|define
name|S_028C6C_SLICE_START
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7FF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_028C6C_SLICE_START
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x7FF)
end_define

begin_define
define|#
directive|define
name|C_028C6C_SLICE_START
value|0xFFFFF800
end_define

begin_define
define|#
directive|define
name|S_028C6C_SLICE_MAX
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7FF)<< 13)
end_define

begin_define
define|#
directive|define
name|G_028C6C_SLICE_MAX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 13)& 0x7FF)
end_define

begin_define
define|#
directive|define
name|C_028C6C_SLICE_MAX
value|0xFF001FFF
end_define

begin_define
define|#
directive|define
name|R_028C70_CB_COLOR0_INFO
value|0x028C70
end_define

begin_define
define|#
directive|define
name|S_028C70_ENDIAN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 0)
end_define

begin_define
define|#
directive|define
name|G_028C70_ENDIAN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_028C70_ENDIAN
value|0xFFFFFFFC
end_define

begin_define
define|#
directive|define
name|S_028C70_FORMAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3F)<< 2)
end_define

begin_define
define|#
directive|define
name|G_028C70_FORMAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 2)& 0x3F)
end_define

begin_define
define|#
directive|define
name|C_028C70_FORMAT
value|0xFFFFFF03
end_define

begin_define
define|#
directive|define
name|V_028C70_COLOR_INVALID
value|0x00000000
end_define

begin_define
define|#
directive|define
name|V_028C70_COLOR_8
value|0x00000001
end_define

begin_define
define|#
directive|define
name|V_028C70_COLOR_4_4
value|0x00000002
end_define

begin_define
define|#
directive|define
name|V_028C70_COLOR_3_3_2
value|0x00000003
end_define

begin_define
define|#
directive|define
name|V_028C70_COLOR_16
value|0x00000005
end_define

begin_define
define|#
directive|define
name|V_028C70_COLOR_16_FLOAT
value|0x00000006
end_define

begin_define
define|#
directive|define
name|V_028C70_COLOR_8_8
value|0x00000007
end_define

begin_define
define|#
directive|define
name|V_028C70_COLOR_5_6_5
value|0x00000008
end_define

begin_define
define|#
directive|define
name|V_028C70_COLOR_6_5_5
value|0x00000009
end_define

begin_define
define|#
directive|define
name|V_028C70_COLOR_1_5_5_5
value|0x0000000A
end_define

begin_define
define|#
directive|define
name|V_028C70_COLOR_4_4_4_4
value|0x0000000B
end_define

begin_define
define|#
directive|define
name|V_028C70_COLOR_5_5_5_1
value|0x0000000C
end_define

begin_define
define|#
directive|define
name|V_028C70_COLOR_32
value|0x0000000D
end_define

begin_define
define|#
directive|define
name|V_028C70_COLOR_32_FLOAT
value|0x0000000E
end_define

begin_define
define|#
directive|define
name|V_028C70_COLOR_16_16
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|V_028C70_COLOR_16_16_FLOAT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|V_028C70_COLOR_8_24
value|0x00000011
end_define

begin_define
define|#
directive|define
name|V_028C70_COLOR_8_24_FLOAT
value|0x00000012
end_define

begin_define
define|#
directive|define
name|V_028C70_COLOR_24_8
value|0x00000013
end_define

begin_define
define|#
directive|define
name|V_028C70_COLOR_24_8_FLOAT
value|0x00000014
end_define

begin_define
define|#
directive|define
name|V_028C70_COLOR_10_11_11
value|0x00000015
end_define

begin_define
define|#
directive|define
name|V_028C70_COLOR_10_11_11_FLOAT
value|0x00000016
end_define

begin_define
define|#
directive|define
name|V_028C70_COLOR_11_11_10
value|0x00000017
end_define

begin_define
define|#
directive|define
name|V_028C70_COLOR_11_11_10_FLOAT
value|0x00000018
end_define

begin_define
define|#
directive|define
name|V_028C70_COLOR_2_10_10_10
value|0x00000019
end_define

begin_define
define|#
directive|define
name|V_028C70_COLOR_8_8_8_8
value|0x0000001A
end_define

begin_define
define|#
directive|define
name|V_028C70_COLOR_10_10_10_2
value|0x0000001B
end_define

begin_define
define|#
directive|define
name|V_028C70_COLOR_X24_8_32_FLOAT
value|0x0000001C
end_define

begin_define
define|#
directive|define
name|V_028C70_COLOR_32_32
value|0x0000001D
end_define

begin_define
define|#
directive|define
name|V_028C70_COLOR_32_32_FLOAT
value|0x0000001E
end_define

begin_define
define|#
directive|define
name|V_028C70_COLOR_16_16_16_16
value|0x0000001F
end_define

begin_define
define|#
directive|define
name|V_028C70_COLOR_16_16_16_16_FLOAT
value|0x00000020
end_define

begin_define
define|#
directive|define
name|V_028C70_COLOR_32_32_32_32
value|0x00000022
end_define

begin_define
define|#
directive|define
name|V_028C70_COLOR_32_32_32_32_FLOAT
value|0x00000023
end_define

begin_define
define|#
directive|define
name|V_028C70_COLOR_32_32_32_FLOAT
value|0x00000030
end_define

begin_define
define|#
directive|define
name|S_028C70_ARRAY_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 8)
end_define

begin_define
define|#
directive|define
name|G_028C70_ARRAY_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_028C70_ARRAY_MODE
value|0xFFFFF0FF
end_define

begin_define
define|#
directive|define
name|V_028C70_ARRAY_LINEAR_GENERAL
value|0x00000000
end_define

begin_define
define|#
directive|define
name|V_028C70_ARRAY_LINEAR_ALIGNED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|V_028C70_ARRAY_1D_TILED_THIN1
value|0x00000002
end_define

begin_define
define|#
directive|define
name|V_028C70_ARRAY_2D_TILED_THIN1
value|0x00000004
end_define

begin_define
define|#
directive|define
name|S_028C70_NUMBER_TYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 12)
end_define

begin_define
define|#
directive|define
name|G_028C70_NUMBER_TYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_028C70_NUMBER_TYPE
value|0xFFFF8FFF
end_define

begin_define
define|#
directive|define
name|V_028C70_NUMBER_UNORM
value|0x00000000
end_define

begin_define
define|#
directive|define
name|V_028C70_NUMBER_SNORM
value|0x00000001
end_define

begin_define
define|#
directive|define
name|V_028C70_NUMBER_USCALED
value|0x00000002
end_define

begin_define
define|#
directive|define
name|V_028C70_NUMBER_SSCALED
value|0x00000003
end_define

begin_define
define|#
directive|define
name|V_028C70_NUMBER_UINT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|V_028C70_NUMBER_SINT
value|0x00000005
end_define

begin_define
define|#
directive|define
name|V_028C70_NUMBER_SRGB
value|0x00000006
end_define

begin_define
define|#
directive|define
name|V_028C70_NUMBER_FLOAT
value|0x00000007
end_define

begin_define
define|#
directive|define
name|S_028C70_COMP_SWAP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 15)
end_define

begin_define
define|#
directive|define
name|G_028C70_COMP_SWAP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 15)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_028C70_COMP_SWAP
value|0xFFFE7FFF
end_define

begin_define
define|#
directive|define
name|V_028C70_SWAP_STD
value|0x00000000
end_define

begin_define
define|#
directive|define
name|V_028C70_SWAP_ALT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|V_028C70_SWAP_STD_REV
value|0x00000002
end_define

begin_define
define|#
directive|define
name|V_028C70_SWAP_ALT_REV
value|0x00000003
end_define

begin_define
define|#
directive|define
name|S_028C70_FAST_CLEAR
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 17)
end_define

begin_define
define|#
directive|define
name|G_028C70_FAST_CLEAR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 17)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_028C70_FAST_CLEAR
value|0xFFFDFFFF
end_define

begin_define
define|#
directive|define
name|S_028C70_COMPRESSION
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 18)
end_define

begin_define
define|#
directive|define
name|G_028C70_COMPRESSION
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 18)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_028C70_COMPRESSION
value|0xFFF3FFFF
end_define

begin_define
define|#
directive|define
name|S_028C70_BLEND_CLAMP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 19)
end_define

begin_define
define|#
directive|define
name|G_028C70_BLEND_CLAMP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 19)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_028C70_BLEND_CLAMP
value|0xFFF7FFFF
end_define

begin_define
define|#
directive|define
name|S_028C70_BLEND_BYPASS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 20)
end_define

begin_define
define|#
directive|define
name|G_028C70_BLEND_BYPASS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_028C70_BLEND_BYPASS
value|0xFFEFFFFF
end_define

begin_define
define|#
directive|define
name|S_028C70_SIMPLE_FLOAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 21)
end_define

begin_define
define|#
directive|define
name|G_028C70_SIMPLE_FLOAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 21)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_028C70_SIMPLE_FLOAT
value|0xFFDFFFFF
end_define

begin_define
define|#
directive|define
name|S_028C70_ROUND_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 22)
end_define

begin_define
define|#
directive|define
name|G_028C70_ROUND_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 22)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_028C70_ROUND_MODE
value|0xFFBFFFFF
end_define

begin_define
define|#
directive|define
name|S_028C70_TILE_COMPACT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 23)
end_define

begin_define
define|#
directive|define
name|G_028C70_TILE_COMPACT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 23)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_028C70_TILE_COMPACT
value|0xFF7FFFFF
end_define

begin_define
define|#
directive|define
name|S_028C70_SOURCE_FORMAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 24)
end_define

begin_define
define|#
directive|define
name|G_028C70_SOURCE_FORMAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_028C70_SOURCE_FORMAT
value|0xFCFFFFFF
end_define

begin_define
define|#
directive|define
name|V_028C70_EXPORT_4C_32BPC
value|0x0
end_define

begin_define
define|#
directive|define
name|V_028C70_EXPORT_4C_16BPC
value|0x1
end_define

begin_define
define|#
directive|define
name|V_028C70_EXPORT_2C_32BPC
value|0x2
end_define

begin_comment
comment|/* Do not use */
end_comment

begin_define
define|#
directive|define
name|S_028C70_RAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 26)
end_define

begin_define
define|#
directive|define
name|G_028C70_RAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 26)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_028C70_RAT
value|0xFBFFFFFF
end_define

begin_define
define|#
directive|define
name|S_028C70_RESOURCE_TYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 27)
end_define

begin_define
define|#
directive|define
name|G_028C70_RESOURCE_TYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 27)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_028C70_RESOURCE_TYPE
value|0xC7FFFFFF
end_define

begin_define
define|#
directive|define
name|CB_COLOR0_INFO
value|0x28c70
end_define

begin_define
define|#
directive|define
name|CB_FORMAT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 2)
end_define

begin_define
define|#
directive|define
name|CB_ARRAY_MODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|ARRAY_LINEAR_GENERAL
value|0
end_define

begin_define
define|#
directive|define
name|ARRAY_LINEAR_ALIGNED
value|1
end_define

begin_define
define|#
directive|define
name|ARRAY_1D_TILED_THIN1
value|2
end_define

begin_define
define|#
directive|define
name|ARRAY_2D_TILED_THIN1
value|4
end_define

begin_define
define|#
directive|define
name|CB_SOURCE_FORMAT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 24)
end_define

begin_define
define|#
directive|define
name|CB_SF_EXPORT_FULL
value|0
end_define

begin_define
define|#
directive|define
name|CB_SF_EXPORT_NORM
value|1
end_define

begin_define
define|#
directive|define
name|R_028C74_CB_COLOR0_ATTRIB
value|0x028C74
end_define

begin_define
define|#
directive|define
name|S_028C74_NON_DISP_TILING_ORDER
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 4)
end_define

begin_define
define|#
directive|define
name|G_028C74_NON_DISP_TILING_ORDER
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_028C74_NON_DISP_TILING_ORDER
value|0xFFFFFFEF
end_define

begin_define
define|#
directive|define
name|S_028C74_TILE_SPLIT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 5)
end_define

begin_define
define|#
directive|define
name|G_028C74_TILE_SPLIT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 5)& 0xf)
end_define

begin_define
define|#
directive|define
name|S_028C74_NUM_BANKS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 10)
end_define

begin_define
define|#
directive|define
name|G_028C74_NUM_BANKS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)& 0x3)
end_define

begin_define
define|#
directive|define
name|S_028C74_BANK_WIDTH
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 13)
end_define

begin_define
define|#
directive|define
name|G_028C74_BANK_WIDTH
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 13)& 0x3)
end_define

begin_define
define|#
directive|define
name|S_028C74_BANK_HEIGHT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 16)
end_define

begin_define
define|#
directive|define
name|G_028C74_BANK_HEIGHT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x3)
end_define

begin_define
define|#
directive|define
name|S_028C74_MACRO_TILE_ASPECT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 19)
end_define

begin_define
define|#
directive|define
name|G_028C74_MACRO_TILE_ASPECT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 19)& 0x3)
end_define

begin_define
define|#
directive|define
name|CB_COLOR0_ATTRIB
value|0x28c74
end_define

begin_define
define|#
directive|define
name|CB_TILE_SPLIT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 5)
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_TILE_SPLIT_64B
value|0
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_TILE_SPLIT_128B
value|1
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_TILE_SPLIT_256B
value|2
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_TILE_SPLIT_512B
value|3
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_TILE_SPLIT_1KB
value|4
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_TILE_SPLIT_2KB
value|5
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_TILE_SPLIT_4KB
value|6
end_define

begin_define
define|#
directive|define
name|CB_NUM_BANKS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 10)
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_2_BANK
value|0
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_4_BANK
value|1
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_8_BANK
value|2
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_16_BANK
value|3
end_define

begin_define
define|#
directive|define
name|CB_BANK_WIDTH
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 13)
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_BANK_WIDTH_1
value|0
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_BANK_WIDTH_2
value|1
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_BANK_WIDTH_4
value|2
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_BANK_WIDTH_8
value|3
end_define

begin_define
define|#
directive|define
name|CB_BANK_HEIGHT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 16)
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_BANK_HEIGHT_1
value|0
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_BANK_HEIGHT_2
value|1
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_BANK_HEIGHT_4
value|2
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_BANK_HEIGHT_8
value|3
end_define

begin_define
define|#
directive|define
name|CB_MACRO_TILE_ASPECT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 19)
end_define

begin_define
define|#
directive|define
name|CB_COLOR0_DIM
value|0x28c78
end_define

begin_comment
comment|/* only CB0-7 blocks have these regs */
end_comment

begin_define
define|#
directive|define
name|CB_COLOR0_CMASK
value|0x28c7c
end_define

begin_define
define|#
directive|define
name|CB_COLOR0_CMASK_SLICE
value|0x28c80
end_define

begin_define
define|#
directive|define
name|CB_COLOR0_FMASK
value|0x28c84
end_define

begin_define
define|#
directive|define
name|CB_COLOR0_FMASK_SLICE
value|0x28c88
end_define

begin_define
define|#
directive|define
name|CB_COLOR0_CLEAR_WORD0
value|0x28c8c
end_define

begin_define
define|#
directive|define
name|CB_COLOR0_CLEAR_WORD1
value|0x28c90
end_define

begin_define
define|#
directive|define
name|CB_COLOR0_CLEAR_WORD2
value|0x28c94
end_define

begin_define
define|#
directive|define
name|CB_COLOR0_CLEAR_WORD3
value|0x28c98
end_define

begin_define
define|#
directive|define
name|CB_COLOR1_BASE
value|0x28c9c
end_define

begin_define
define|#
directive|define
name|CB_COLOR2_BASE
value|0x28cd8
end_define

begin_define
define|#
directive|define
name|CB_COLOR3_BASE
value|0x28d14
end_define

begin_define
define|#
directive|define
name|CB_COLOR4_BASE
value|0x28d50
end_define

begin_define
define|#
directive|define
name|CB_COLOR5_BASE
value|0x28d8c
end_define

begin_define
define|#
directive|define
name|CB_COLOR6_BASE
value|0x28dc8
end_define

begin_define
define|#
directive|define
name|CB_COLOR7_BASE
value|0x28e04
end_define

begin_define
define|#
directive|define
name|CB_COLOR8_BASE
value|0x28e40
end_define

begin_define
define|#
directive|define
name|CB_COLOR9_BASE
value|0x28e5c
end_define

begin_define
define|#
directive|define
name|CB_COLOR10_BASE
value|0x28e78
end_define

begin_define
define|#
directive|define
name|CB_COLOR11_BASE
value|0x28e94
end_define

begin_define
define|#
directive|define
name|CB_COLOR1_PITCH
value|0x28ca0
end_define

begin_define
define|#
directive|define
name|CB_COLOR2_PITCH
value|0x28cdc
end_define

begin_define
define|#
directive|define
name|CB_COLOR3_PITCH
value|0x28d18
end_define

begin_define
define|#
directive|define
name|CB_COLOR4_PITCH
value|0x28d54
end_define

begin_define
define|#
directive|define
name|CB_COLOR5_PITCH
value|0x28d90
end_define

begin_define
define|#
directive|define
name|CB_COLOR6_PITCH
value|0x28dcc
end_define

begin_define
define|#
directive|define
name|CB_COLOR7_PITCH
value|0x28e08
end_define

begin_define
define|#
directive|define
name|CB_COLOR8_PITCH
value|0x28e44
end_define

begin_define
define|#
directive|define
name|CB_COLOR9_PITCH
value|0x28e60
end_define

begin_define
define|#
directive|define
name|CB_COLOR10_PITCH
value|0x28e7c
end_define

begin_define
define|#
directive|define
name|CB_COLOR11_PITCH
value|0x28e98
end_define

begin_define
define|#
directive|define
name|CB_COLOR1_SLICE
value|0x28ca4
end_define

begin_define
define|#
directive|define
name|CB_COLOR2_SLICE
value|0x28ce0
end_define

begin_define
define|#
directive|define
name|CB_COLOR3_SLICE
value|0x28d1c
end_define

begin_define
define|#
directive|define
name|CB_COLOR4_SLICE
value|0x28d58
end_define

begin_define
define|#
directive|define
name|CB_COLOR5_SLICE
value|0x28d94
end_define

begin_define
define|#
directive|define
name|CB_COLOR6_SLICE
value|0x28dd0
end_define

begin_define
define|#
directive|define
name|CB_COLOR7_SLICE
value|0x28e0c
end_define

begin_define
define|#
directive|define
name|CB_COLOR8_SLICE
value|0x28e48
end_define

begin_define
define|#
directive|define
name|CB_COLOR9_SLICE
value|0x28e64
end_define

begin_define
define|#
directive|define
name|CB_COLOR10_SLICE
value|0x28e80
end_define

begin_define
define|#
directive|define
name|CB_COLOR11_SLICE
value|0x28e9c
end_define

begin_define
define|#
directive|define
name|CB_COLOR1_VIEW
value|0x28ca8
end_define

begin_define
define|#
directive|define
name|CB_COLOR2_VIEW
value|0x28ce4
end_define

begin_define
define|#
directive|define
name|CB_COLOR3_VIEW
value|0x28d20
end_define

begin_define
define|#
directive|define
name|CB_COLOR4_VIEW
value|0x28d5c
end_define

begin_define
define|#
directive|define
name|CB_COLOR5_VIEW
value|0x28d98
end_define

begin_define
define|#
directive|define
name|CB_COLOR6_VIEW
value|0x28dd4
end_define

begin_define
define|#
directive|define
name|CB_COLOR7_VIEW
value|0x28e10
end_define

begin_define
define|#
directive|define
name|CB_COLOR8_VIEW
value|0x28e4c
end_define

begin_define
define|#
directive|define
name|CB_COLOR9_VIEW
value|0x28e68
end_define

begin_define
define|#
directive|define
name|CB_COLOR10_VIEW
value|0x28e84
end_define

begin_define
define|#
directive|define
name|CB_COLOR11_VIEW
value|0x28ea0
end_define

begin_define
define|#
directive|define
name|CB_COLOR1_INFO
value|0x28cac
end_define

begin_define
define|#
directive|define
name|CB_COLOR2_INFO
value|0x28ce8
end_define

begin_define
define|#
directive|define
name|CB_COLOR3_INFO
value|0x28d24
end_define

begin_define
define|#
directive|define
name|CB_COLOR4_INFO
value|0x28d60
end_define

begin_define
define|#
directive|define
name|CB_COLOR5_INFO
value|0x28d9c
end_define

begin_define
define|#
directive|define
name|CB_COLOR6_INFO
value|0x28dd8
end_define

begin_define
define|#
directive|define
name|CB_COLOR7_INFO
value|0x28e14
end_define

begin_define
define|#
directive|define
name|CB_COLOR8_INFO
value|0x28e50
end_define

begin_define
define|#
directive|define
name|CB_COLOR9_INFO
value|0x28e6c
end_define

begin_define
define|#
directive|define
name|CB_COLOR10_INFO
value|0x28e88
end_define

begin_define
define|#
directive|define
name|CB_COLOR11_INFO
value|0x28ea4
end_define

begin_define
define|#
directive|define
name|CB_COLOR1_ATTRIB
value|0x28cb0
end_define

begin_define
define|#
directive|define
name|CB_COLOR2_ATTRIB
value|0x28cec
end_define

begin_define
define|#
directive|define
name|CB_COLOR3_ATTRIB
value|0x28d28
end_define

begin_define
define|#
directive|define
name|CB_COLOR4_ATTRIB
value|0x28d64
end_define

begin_define
define|#
directive|define
name|CB_COLOR5_ATTRIB
value|0x28da0
end_define

begin_define
define|#
directive|define
name|CB_COLOR6_ATTRIB
value|0x28ddc
end_define

begin_define
define|#
directive|define
name|CB_COLOR7_ATTRIB
value|0x28e18
end_define

begin_define
define|#
directive|define
name|CB_COLOR8_ATTRIB
value|0x28e54
end_define

begin_define
define|#
directive|define
name|CB_COLOR9_ATTRIB
value|0x28e70
end_define

begin_define
define|#
directive|define
name|CB_COLOR10_ATTRIB
value|0x28e8c
end_define

begin_define
define|#
directive|define
name|CB_COLOR11_ATTRIB
value|0x28ea8
end_define

begin_define
define|#
directive|define
name|CB_COLOR1_DIM
value|0x28cb4
end_define

begin_define
define|#
directive|define
name|CB_COLOR2_DIM
value|0x28cf0
end_define

begin_define
define|#
directive|define
name|CB_COLOR3_DIM
value|0x28d2c
end_define

begin_define
define|#
directive|define
name|CB_COLOR4_DIM
value|0x28d68
end_define

begin_define
define|#
directive|define
name|CB_COLOR5_DIM
value|0x28da4
end_define

begin_define
define|#
directive|define
name|CB_COLOR6_DIM
value|0x28de0
end_define

begin_define
define|#
directive|define
name|CB_COLOR7_DIM
value|0x28e1c
end_define

begin_define
define|#
directive|define
name|CB_COLOR8_DIM
value|0x28e58
end_define

begin_define
define|#
directive|define
name|CB_COLOR9_DIM
value|0x28e74
end_define

begin_define
define|#
directive|define
name|CB_COLOR10_DIM
value|0x28e90
end_define

begin_define
define|#
directive|define
name|CB_COLOR11_DIM
value|0x28eac
end_define

begin_define
define|#
directive|define
name|CB_COLOR1_CMASK
value|0x28cb8
end_define

begin_define
define|#
directive|define
name|CB_COLOR2_CMASK
value|0x28cf4
end_define

begin_define
define|#
directive|define
name|CB_COLOR3_CMASK
value|0x28d30
end_define

begin_define
define|#
directive|define
name|CB_COLOR4_CMASK
value|0x28d6c
end_define

begin_define
define|#
directive|define
name|CB_COLOR5_CMASK
value|0x28da8
end_define

begin_define
define|#
directive|define
name|CB_COLOR6_CMASK
value|0x28de4
end_define

begin_define
define|#
directive|define
name|CB_COLOR7_CMASK
value|0x28e20
end_define

begin_define
define|#
directive|define
name|CB_COLOR1_CMASK_SLICE
value|0x28cbc
end_define

begin_define
define|#
directive|define
name|CB_COLOR2_CMASK_SLICE
value|0x28cf8
end_define

begin_define
define|#
directive|define
name|CB_COLOR3_CMASK_SLICE
value|0x28d34
end_define

begin_define
define|#
directive|define
name|CB_COLOR4_CMASK_SLICE
value|0x28d70
end_define

begin_define
define|#
directive|define
name|CB_COLOR5_CMASK_SLICE
value|0x28dac
end_define

begin_define
define|#
directive|define
name|CB_COLOR6_CMASK_SLICE
value|0x28de8
end_define

begin_define
define|#
directive|define
name|CB_COLOR7_CMASK_SLICE
value|0x28e24
end_define

begin_define
define|#
directive|define
name|CB_COLOR1_FMASK
value|0x28cc0
end_define

begin_define
define|#
directive|define
name|CB_COLOR2_FMASK
value|0x28cfc
end_define

begin_define
define|#
directive|define
name|CB_COLOR3_FMASK
value|0x28d38
end_define

begin_define
define|#
directive|define
name|CB_COLOR4_FMASK
value|0x28d74
end_define

begin_define
define|#
directive|define
name|CB_COLOR5_FMASK
value|0x28db0
end_define

begin_define
define|#
directive|define
name|CB_COLOR6_FMASK
value|0x28dec
end_define

begin_define
define|#
directive|define
name|CB_COLOR7_FMASK
value|0x28e28
end_define

begin_define
define|#
directive|define
name|CB_COLOR1_FMASK_SLICE
value|0x28cc4
end_define

begin_define
define|#
directive|define
name|CB_COLOR2_FMASK_SLICE
value|0x28d00
end_define

begin_define
define|#
directive|define
name|CB_COLOR3_FMASK_SLICE
value|0x28d3c
end_define

begin_define
define|#
directive|define
name|CB_COLOR4_FMASK_SLICE
value|0x28d78
end_define

begin_define
define|#
directive|define
name|CB_COLOR5_FMASK_SLICE
value|0x28db4
end_define

begin_define
define|#
directive|define
name|CB_COLOR6_FMASK_SLICE
value|0x28df0
end_define

begin_define
define|#
directive|define
name|CB_COLOR7_FMASK_SLICE
value|0x28e2c
end_define

begin_define
define|#
directive|define
name|CB_COLOR1_CLEAR_WORD0
value|0x28cc8
end_define

begin_define
define|#
directive|define
name|CB_COLOR2_CLEAR_WORD0
value|0x28d04
end_define

begin_define
define|#
directive|define
name|CB_COLOR3_CLEAR_WORD0
value|0x28d40
end_define

begin_define
define|#
directive|define
name|CB_COLOR4_CLEAR_WORD0
value|0x28d7c
end_define

begin_define
define|#
directive|define
name|CB_COLOR5_CLEAR_WORD0
value|0x28db8
end_define

begin_define
define|#
directive|define
name|CB_COLOR6_CLEAR_WORD0
value|0x28df4
end_define

begin_define
define|#
directive|define
name|CB_COLOR7_CLEAR_WORD0
value|0x28e30
end_define

begin_define
define|#
directive|define
name|CB_COLOR1_CLEAR_WORD1
value|0x28ccc
end_define

begin_define
define|#
directive|define
name|CB_COLOR2_CLEAR_WORD1
value|0x28d08
end_define

begin_define
define|#
directive|define
name|CB_COLOR3_CLEAR_WORD1
value|0x28d44
end_define

begin_define
define|#
directive|define
name|CB_COLOR4_CLEAR_WORD1
value|0x28d80
end_define

begin_define
define|#
directive|define
name|CB_COLOR5_CLEAR_WORD1
value|0x28dbc
end_define

begin_define
define|#
directive|define
name|CB_COLOR6_CLEAR_WORD1
value|0x28df8
end_define

begin_define
define|#
directive|define
name|CB_COLOR7_CLEAR_WORD1
value|0x28e34
end_define

begin_define
define|#
directive|define
name|CB_COLOR1_CLEAR_WORD2
value|0x28cd0
end_define

begin_define
define|#
directive|define
name|CB_COLOR2_CLEAR_WORD2
value|0x28d0c
end_define

begin_define
define|#
directive|define
name|CB_COLOR3_CLEAR_WORD2
value|0x28d48
end_define

begin_define
define|#
directive|define
name|CB_COLOR4_CLEAR_WORD2
value|0x28d84
end_define

begin_define
define|#
directive|define
name|CB_COLOR5_CLEAR_WORD2
value|0x28dc0
end_define

begin_define
define|#
directive|define
name|CB_COLOR6_CLEAR_WORD2
value|0x28dfc
end_define

begin_define
define|#
directive|define
name|CB_COLOR7_CLEAR_WORD2
value|0x28e38
end_define

begin_define
define|#
directive|define
name|CB_COLOR1_CLEAR_WORD3
value|0x28cd4
end_define

begin_define
define|#
directive|define
name|CB_COLOR2_CLEAR_WORD3
value|0x28d10
end_define

begin_define
define|#
directive|define
name|CB_COLOR3_CLEAR_WORD3
value|0x28d4c
end_define

begin_define
define|#
directive|define
name|CB_COLOR4_CLEAR_WORD3
value|0x28d88
end_define

begin_define
define|#
directive|define
name|CB_COLOR5_CLEAR_WORD3
value|0x28dc4
end_define

begin_define
define|#
directive|define
name|CB_COLOR6_CLEAR_WORD3
value|0x28e00
end_define

begin_define
define|#
directive|define
name|CB_COLOR7_CLEAR_WORD3
value|0x28e3c
end_define

begin_define
define|#
directive|define
name|SQ_TEX_RESOURCE_WORD0_0
value|0x30000
end_define

begin_define
define|#
directive|define
name|TEX_DIM
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|SQ_TEX_DIM_1D
value|0
end_define

begin_define
define|#
directive|define
name|SQ_TEX_DIM_2D
value|1
end_define

begin_define
define|#
directive|define
name|SQ_TEX_DIM_3D
value|2
end_define

begin_define
define|#
directive|define
name|SQ_TEX_DIM_CUBEMAP
value|3
end_define

begin_define
define|#
directive|define
name|SQ_TEX_DIM_1D_ARRAY
value|4
end_define

begin_define
define|#
directive|define
name|SQ_TEX_DIM_2D_ARRAY
value|5
end_define

begin_define
define|#
directive|define
name|SQ_TEX_DIM_2D_MSAA
value|6
end_define

begin_define
define|#
directive|define
name|SQ_TEX_DIM_2D_ARRAY_MSAA
value|7
end_define

begin_define
define|#
directive|define
name|SQ_TEX_RESOURCE_WORD1_0
value|0x30004
end_define

begin_define
define|#
directive|define
name|TEX_ARRAY_MODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 28)
end_define

begin_define
define|#
directive|define
name|SQ_TEX_RESOURCE_WORD2_0
value|0x30008
end_define

begin_define
define|#
directive|define
name|SQ_TEX_RESOURCE_WORD3_0
value|0x3000C
end_define

begin_define
define|#
directive|define
name|SQ_TEX_RESOURCE_WORD4_0
value|0x30010
end_define

begin_define
define|#
directive|define
name|TEX_DST_SEL_X
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|TEX_DST_SEL_Y
parameter_list|(
name|x
parameter_list|)
value|((x)<< 19)
end_define

begin_define
define|#
directive|define
name|TEX_DST_SEL_Z
parameter_list|(
name|x
parameter_list|)
value|((x)<< 22)
end_define

begin_define
define|#
directive|define
name|TEX_DST_SEL_W
parameter_list|(
name|x
parameter_list|)
value|((x)<< 25)
end_define

begin_define
define|#
directive|define
name|SQ_SEL_X
value|0
end_define

begin_define
define|#
directive|define
name|SQ_SEL_Y
value|1
end_define

begin_define
define|#
directive|define
name|SQ_SEL_Z
value|2
end_define

begin_define
define|#
directive|define
name|SQ_SEL_W
value|3
end_define

begin_define
define|#
directive|define
name|SQ_SEL_0
value|4
end_define

begin_define
define|#
directive|define
name|SQ_SEL_1
value|5
end_define

begin_define
define|#
directive|define
name|SQ_TEX_RESOURCE_WORD5_0
value|0x30014
end_define

begin_define
define|#
directive|define
name|SQ_TEX_RESOURCE_WORD6_0
value|0x30018
end_define

begin_define
define|#
directive|define
name|TEX_TILE_SPLIT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 29)
end_define

begin_define
define|#
directive|define
name|SQ_TEX_RESOURCE_WORD7_0
value|0x3001c
end_define

begin_define
define|#
directive|define
name|MACRO_TILE_ASPECT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 6)
end_define

begin_define
define|#
directive|define
name|TEX_BANK_WIDTH
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 8)
end_define

begin_define
define|#
directive|define
name|TEX_BANK_HEIGHT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 10)
end_define

begin_define
define|#
directive|define
name|TEX_NUM_BANKS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 16)
end_define

begin_define
define|#
directive|define
name|R_030000_SQ_TEX_RESOURCE_WORD0_0
value|0x030000
end_define

begin_define
define|#
directive|define
name|S_030000_DIM
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 0)
end_define

begin_define
define|#
directive|define
name|G_030000_DIM
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_030000_DIM
value|0xFFFFFFF8
end_define

begin_define
define|#
directive|define
name|V_030000_SQ_TEX_DIM_1D
value|0x00000000
end_define

begin_define
define|#
directive|define
name|V_030000_SQ_TEX_DIM_2D
value|0x00000001
end_define

begin_define
define|#
directive|define
name|V_030000_SQ_TEX_DIM_3D
value|0x00000002
end_define

begin_define
define|#
directive|define
name|V_030000_SQ_TEX_DIM_CUBEMAP
value|0x00000003
end_define

begin_define
define|#
directive|define
name|V_030000_SQ_TEX_DIM_1D_ARRAY
value|0x00000004
end_define

begin_define
define|#
directive|define
name|V_030000_SQ_TEX_DIM_2D_ARRAY
value|0x00000005
end_define

begin_define
define|#
directive|define
name|V_030000_SQ_TEX_DIM_2D_MSAA
value|0x00000006
end_define

begin_define
define|#
directive|define
name|V_030000_SQ_TEX_DIM_2D_ARRAY_MSAA
value|0x00000007
end_define

begin_define
define|#
directive|define
name|S_030000_NON_DISP_TILING_ORDER
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 5)
end_define

begin_define
define|#
directive|define
name|G_030000_NON_DISP_TILING_ORDER
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 5)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_030000_NON_DISP_TILING_ORDER
value|0xFFFFFFDF
end_define

begin_define
define|#
directive|define
name|S_030000_PITCH
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFF)<< 6)
end_define

begin_define
define|#
directive|define
name|G_030000_PITCH
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 6)& 0xFFF)
end_define

begin_define
define|#
directive|define
name|C_030000_PITCH
value|0xFFFC003F
end_define

begin_define
define|#
directive|define
name|S_030000_TEX_WIDTH
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3FFF)<< 18)
end_define

begin_define
define|#
directive|define
name|G_030000_TEX_WIDTH
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 18)& 0x3FFF)
end_define

begin_define
define|#
directive|define
name|C_030000_TEX_WIDTH
value|0x0003FFFF
end_define

begin_define
define|#
directive|define
name|R_030004_SQ_TEX_RESOURCE_WORD1_0
value|0x030004
end_define

begin_define
define|#
directive|define
name|S_030004_TEX_HEIGHT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3FFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_030004_TEX_HEIGHT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x3FFF)
end_define

begin_define
define|#
directive|define
name|C_030004_TEX_HEIGHT
value|0xFFFFC000
end_define

begin_define
define|#
directive|define
name|S_030004_TEX_DEPTH
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1FFF)<< 14)
end_define

begin_define
define|#
directive|define
name|G_030004_TEX_DEPTH
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 14)& 0x1FFF)
end_define

begin_define
define|#
directive|define
name|C_030004_TEX_DEPTH
value|0xF8003FFF
end_define

begin_define
define|#
directive|define
name|S_030004_ARRAY_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 28)
end_define

begin_define
define|#
directive|define
name|G_030004_ARRAY_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 28)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_030004_ARRAY_MODE
value|0x0FFFFFFF
end_define

begin_define
define|#
directive|define
name|R_030008_SQ_TEX_RESOURCE_WORD2_0
value|0x030008
end_define

begin_define
define|#
directive|define
name|S_030008_BASE_ADDRESS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFFFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_030008_BASE_ADDRESS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|C_030008_BASE_ADDRESS
value|0x00000000
end_define

begin_define
define|#
directive|define
name|R_03000C_SQ_TEX_RESOURCE_WORD3_0
value|0x03000C
end_define

begin_define
define|#
directive|define
name|S_03000C_MIP_ADDRESS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFFFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_03000C_MIP_ADDRESS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|C_03000C_MIP_ADDRESS
value|0x00000000
end_define

begin_define
define|#
directive|define
name|R_030010_SQ_TEX_RESOURCE_WORD4_0
value|0x030010
end_define

begin_define
define|#
directive|define
name|S_030010_FORMAT_COMP_X
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 0)
end_define

begin_define
define|#
directive|define
name|G_030010_FORMAT_COMP_X
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_030010_FORMAT_COMP_X
value|0xFFFFFFFC
end_define

begin_define
define|#
directive|define
name|V_030010_SQ_FORMAT_COMP_UNSIGNED
value|0x00000000
end_define

begin_define
define|#
directive|define
name|V_030010_SQ_FORMAT_COMP_SIGNED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|V_030010_SQ_FORMAT_COMP_UNSIGNED_BIASED
value|0x00000002
end_define

begin_define
define|#
directive|define
name|S_030010_FORMAT_COMP_Y
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 2)
end_define

begin_define
define|#
directive|define
name|G_030010_FORMAT_COMP_Y
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 2)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_030010_FORMAT_COMP_Y
value|0xFFFFFFF3
end_define

begin_define
define|#
directive|define
name|S_030010_FORMAT_COMP_Z
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 4)
end_define

begin_define
define|#
directive|define
name|G_030010_FORMAT_COMP_Z
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_030010_FORMAT_COMP_Z
value|0xFFFFFFCF
end_define

begin_define
define|#
directive|define
name|S_030010_FORMAT_COMP_W
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 6)
end_define

begin_define
define|#
directive|define
name|G_030010_FORMAT_COMP_W
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 6)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_030010_FORMAT_COMP_W
value|0xFFFFFF3F
end_define

begin_define
define|#
directive|define
name|S_030010_NUM_FORMAT_ALL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 8)
end_define

begin_define
define|#
directive|define
name|G_030010_NUM_FORMAT_ALL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_030010_NUM_FORMAT_ALL
value|0xFFFFFCFF
end_define

begin_define
define|#
directive|define
name|V_030010_SQ_NUM_FORMAT_NORM
value|0x00000000
end_define

begin_define
define|#
directive|define
name|V_030010_SQ_NUM_FORMAT_INT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|V_030010_SQ_NUM_FORMAT_SCALED
value|0x00000002
end_define

begin_define
define|#
directive|define
name|S_030010_SRF_MODE_ALL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 10)
end_define

begin_define
define|#
directive|define
name|G_030010_SRF_MODE_ALL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_030010_SRF_MODE_ALL
value|0xFFFFFBFF
end_define

begin_define
define|#
directive|define
name|V_030010_SRF_MODE_ZERO_CLAMP_MINUS_ONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|V_030010_SRF_MODE_NO_ZERO
value|0x00000001
end_define

begin_define
define|#
directive|define
name|S_030010_FORCE_DEGAMMA
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 11)
end_define

begin_define
define|#
directive|define
name|G_030010_FORCE_DEGAMMA
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 11)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_030010_FORCE_DEGAMMA
value|0xFFFFF7FF
end_define

begin_define
define|#
directive|define
name|S_030010_ENDIAN_SWAP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 12)
end_define

begin_define
define|#
directive|define
name|G_030010_ENDIAN_SWAP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_030010_ENDIAN_SWAP
value|0xFFFFCFFF
end_define

begin_define
define|#
directive|define
name|S_030010_DST_SEL_X
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 16)
end_define

begin_define
define|#
directive|define
name|G_030010_DST_SEL_X
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_030010_DST_SEL_X
value|0xFFF8FFFF
end_define

begin_define
define|#
directive|define
name|V_030010_SQ_SEL_X
value|0x00000000
end_define

begin_define
define|#
directive|define
name|V_030010_SQ_SEL_Y
value|0x00000001
end_define

begin_define
define|#
directive|define
name|V_030010_SQ_SEL_Z
value|0x00000002
end_define

begin_define
define|#
directive|define
name|V_030010_SQ_SEL_W
value|0x00000003
end_define

begin_define
define|#
directive|define
name|V_030010_SQ_SEL_0
value|0x00000004
end_define

begin_define
define|#
directive|define
name|V_030010_SQ_SEL_1
value|0x00000005
end_define

begin_define
define|#
directive|define
name|S_030010_DST_SEL_Y
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 19)
end_define

begin_define
define|#
directive|define
name|G_030010_DST_SEL_Y
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 19)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_030010_DST_SEL_Y
value|0xFFC7FFFF
end_define

begin_define
define|#
directive|define
name|S_030010_DST_SEL_Z
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 22)
end_define

begin_define
define|#
directive|define
name|G_030010_DST_SEL_Z
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 22)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_030010_DST_SEL_Z
value|0xFE3FFFFF
end_define

begin_define
define|#
directive|define
name|S_030010_DST_SEL_W
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 25)
end_define

begin_define
define|#
directive|define
name|G_030010_DST_SEL_W
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 25)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_030010_DST_SEL_W
value|0xF1FFFFFF
end_define

begin_define
define|#
directive|define
name|S_030010_BASE_LEVEL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 28)
end_define

begin_define
define|#
directive|define
name|G_030010_BASE_LEVEL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 28)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_030010_BASE_LEVEL
value|0x0FFFFFFF
end_define

begin_define
define|#
directive|define
name|R_030014_SQ_TEX_RESOURCE_WORD5_0
value|0x030014
end_define

begin_define
define|#
directive|define
name|S_030014_LAST_LEVEL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_030014_LAST_LEVEL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_030014_LAST_LEVEL
value|0xFFFFFFF0
end_define

begin_define
define|#
directive|define
name|S_030014_BASE_ARRAY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1FFF)<< 4)
end_define

begin_define
define|#
directive|define
name|G_030014_BASE_ARRAY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x1FFF)
end_define

begin_define
define|#
directive|define
name|C_030014_BASE_ARRAY
value|0xFFFE000F
end_define

begin_define
define|#
directive|define
name|S_030014_LAST_ARRAY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1FFF)<< 17)
end_define

begin_define
define|#
directive|define
name|G_030014_LAST_ARRAY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 17)& 0x1FFF)
end_define

begin_define
define|#
directive|define
name|C_030014_LAST_ARRAY
value|0xC001FFFF
end_define

begin_define
define|#
directive|define
name|R_030018_SQ_TEX_RESOURCE_WORD6_0
value|0x030018
end_define

begin_define
define|#
directive|define
name|S_030018_MAX_ANISO
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 0)
end_define

begin_define
define|#
directive|define
name|G_030018_MAX_ANISO
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_030018_MAX_ANISO
value|0xFFFFFFF8
end_define

begin_define
define|#
directive|define
name|S_030018_PERF_MODULATION
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 3)
end_define

begin_define
define|#
directive|define
name|G_030018_PERF_MODULATION
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 3)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_030018_PERF_MODULATION
value|0xFFFFFFC7
end_define

begin_define
define|#
directive|define
name|S_030018_INTERLACED
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 6)
end_define

begin_define
define|#
directive|define
name|G_030018_INTERLACED
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 6)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_030018_INTERLACED
value|0xFFFFFFBF
end_define

begin_define
define|#
directive|define
name|S_030018_TILE_SPLIT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 29)
end_define

begin_define
define|#
directive|define
name|G_030018_TILE_SPLIT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 29)& 0x7)
end_define

begin_define
define|#
directive|define
name|R_03001C_SQ_TEX_RESOURCE_WORD7_0
value|0x03001C
end_define

begin_define
define|#
directive|define
name|S_03001C_MACRO_TILE_ASPECT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 6)
end_define

begin_define
define|#
directive|define
name|G_03001C_MACRO_TILE_ASPECT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 6)& 0x3)
end_define

begin_define
define|#
directive|define
name|S_03001C_BANK_WIDTH
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 8)
end_define

begin_define
define|#
directive|define
name|G_03001C_BANK_WIDTH
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x3)
end_define

begin_define
define|#
directive|define
name|S_03001C_BANK_HEIGHT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 10)
end_define

begin_define
define|#
directive|define
name|G_03001C_BANK_HEIGHT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)& 0x3)
end_define

begin_define
define|#
directive|define
name|S_03001C_NUM_BANKS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 16)
end_define

begin_define
define|#
directive|define
name|G_03001C_NUM_BANKS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x3)
end_define

begin_define
define|#
directive|define
name|S_03001C_TYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 30)
end_define

begin_define
define|#
directive|define
name|G_03001C_TYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 30)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_03001C_TYPE
value|0x3FFFFFFF
end_define

begin_define
define|#
directive|define
name|V_03001C_SQ_TEX_VTX_INVALID_TEXTURE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|V_03001C_SQ_TEX_VTX_INVALID_BUFFER
value|0x00000001
end_define

begin_define
define|#
directive|define
name|V_03001C_SQ_TEX_VTX_VALID_TEXTURE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|V_03001C_SQ_TEX_VTX_VALID_BUFFER
value|0x00000003
end_define

begin_define
define|#
directive|define
name|S_03001C_DATA_FORMAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3F)<< 0)
end_define

begin_define
define|#
directive|define
name|G_03001C_DATA_FORMAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x3F)
end_define

begin_define
define|#
directive|define
name|C_03001C_DATA_FORMAT
value|0xFFFFFFC0
end_define

begin_define
define|#
directive|define
name|SQ_VTX_CONSTANT_WORD0_0
value|0x30000
end_define

begin_define
define|#
directive|define
name|SQ_VTX_CONSTANT_WORD1_0
value|0x30004
end_define

begin_define
define|#
directive|define
name|SQ_VTX_CONSTANT_WORD2_0
value|0x30008
end_define

begin_define
define|#
directive|define
name|SQ_VTXC_BASE_ADDR_HI
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|SQ_VTXC_STRIDE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|SQ_VTXC_ENDIAN_SWAP
parameter_list|(
name|x
parameter_list|)
value|((x)<< 30)
end_define

begin_define
define|#
directive|define
name|SQ_ENDIAN_NONE
value|0
end_define

begin_define
define|#
directive|define
name|SQ_ENDIAN_8IN16
value|1
end_define

begin_define
define|#
directive|define
name|SQ_ENDIAN_8IN32
value|2
end_define

begin_define
define|#
directive|define
name|SQ_VTX_CONSTANT_WORD3_0
value|0x3000C
end_define

begin_define
define|#
directive|define
name|SQ_VTCX_SEL_X
parameter_list|(
name|x
parameter_list|)
value|((x)<< 3)
end_define

begin_define
define|#
directive|define
name|SQ_VTCX_SEL_Y
parameter_list|(
name|x
parameter_list|)
value|((x)<< 6)
end_define

begin_define
define|#
directive|define
name|SQ_VTCX_SEL_Z
parameter_list|(
name|x
parameter_list|)
value|((x)<< 9)
end_define

begin_define
define|#
directive|define
name|SQ_VTCX_SEL_W
parameter_list|(
name|x
parameter_list|)
value|((x)<< 12)
end_define

begin_define
define|#
directive|define
name|SQ_VTX_CONSTANT_WORD4_0
value|0x30010
end_define

begin_define
define|#
directive|define
name|SQ_VTX_CONSTANT_WORD5_0
value|0x30014
end_define

begin_define
define|#
directive|define
name|SQ_VTX_CONSTANT_WORD6_0
value|0x30018
end_define

begin_define
define|#
directive|define
name|SQ_VTX_CONSTANT_WORD7_0
value|0x3001c
end_define

begin_define
define|#
directive|define
name|TD_PS_BORDER_COLOR_INDEX
value|0xA400
end_define

begin_define
define|#
directive|define
name|TD_PS_BORDER_COLOR_RED
value|0xA404
end_define

begin_define
define|#
directive|define
name|TD_PS_BORDER_COLOR_GREEN
value|0xA408
end_define

begin_define
define|#
directive|define
name|TD_PS_BORDER_COLOR_BLUE
value|0xA40C
end_define

begin_define
define|#
directive|define
name|TD_PS_BORDER_COLOR_ALPHA
value|0xA410
end_define

begin_define
define|#
directive|define
name|TD_VS_BORDER_COLOR_INDEX
value|0xA414
end_define

begin_define
define|#
directive|define
name|TD_VS_BORDER_COLOR_RED
value|0xA418
end_define

begin_define
define|#
directive|define
name|TD_VS_BORDER_COLOR_GREEN
value|0xA41C
end_define

begin_define
define|#
directive|define
name|TD_VS_BORDER_COLOR_BLUE
value|0xA420
end_define

begin_define
define|#
directive|define
name|TD_VS_BORDER_COLOR_ALPHA
value|0xA424
end_define

begin_define
define|#
directive|define
name|TD_GS_BORDER_COLOR_INDEX
value|0xA428
end_define

begin_define
define|#
directive|define
name|TD_GS_BORDER_COLOR_RED
value|0xA42C
end_define

begin_define
define|#
directive|define
name|TD_GS_BORDER_COLOR_GREEN
value|0xA430
end_define

begin_define
define|#
directive|define
name|TD_GS_BORDER_COLOR_BLUE
value|0xA434
end_define

begin_define
define|#
directive|define
name|TD_GS_BORDER_COLOR_ALPHA
value|0xA438
end_define

begin_define
define|#
directive|define
name|TD_HS_BORDER_COLOR_INDEX
value|0xA43C
end_define

begin_define
define|#
directive|define
name|TD_HS_BORDER_COLOR_RED
value|0xA440
end_define

begin_define
define|#
directive|define
name|TD_HS_BORDER_COLOR_GREEN
value|0xA444
end_define

begin_define
define|#
directive|define
name|TD_HS_BORDER_COLOR_BLUE
value|0xA448
end_define

begin_define
define|#
directive|define
name|TD_HS_BORDER_COLOR_ALPHA
value|0xA44C
end_define

begin_define
define|#
directive|define
name|TD_LS_BORDER_COLOR_INDEX
value|0xA450
end_define

begin_define
define|#
directive|define
name|TD_LS_BORDER_COLOR_RED
value|0xA454
end_define

begin_define
define|#
directive|define
name|TD_LS_BORDER_COLOR_GREEN
value|0xA458
end_define

begin_define
define|#
directive|define
name|TD_LS_BORDER_COLOR_BLUE
value|0xA45C
end_define

begin_define
define|#
directive|define
name|TD_LS_BORDER_COLOR_ALPHA
value|0xA460
end_define

begin_define
define|#
directive|define
name|TD_CS_BORDER_COLOR_INDEX
value|0xA464
end_define

begin_define
define|#
directive|define
name|TD_CS_BORDER_COLOR_RED
value|0xA468
end_define

begin_define
define|#
directive|define
name|TD_CS_BORDER_COLOR_GREEN
value|0xA46C
end_define

begin_define
define|#
directive|define
name|TD_CS_BORDER_COLOR_BLUE
value|0xA470
end_define

begin_define
define|#
directive|define
name|TD_CS_BORDER_COLOR_ALPHA
value|0xA474
end_define

begin_comment
comment|/* cayman 3D regs */
end_comment

begin_define
define|#
directive|define
name|CAYMAN_VGT_OFFCHIP_LDS_BASE
value|0x89B4
end_define

begin_define
define|#
directive|define
name|CAYMAN_SQ_EX_ALLOC_TABLE_SLOTS
value|0x8E48
end_define

begin_define
define|#
directive|define
name|CAYMAN_DB_EQAA
value|0x28804
end_define

begin_define
define|#
directive|define
name|CAYMAN_DB_DEPTH_INFO
value|0x2803C
end_define

begin_define
define|#
directive|define
name|CAYMAN_PA_SC_AA_CONFIG
value|0x28BE0
end_define

begin_define
define|#
directive|define
name|CAYMAN_MSAA_NUM_SAMPLES_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|CAYMAN_MSAA_NUM_SAMPLES_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|CAYMAN_SX_SCATTER_EXPORT_BASE
value|0x28358
end_define

begin_comment
comment|/* cayman packet3 addition */
end_comment

begin_define
define|#
directive|define
name|CAYMAN_PACKET3_DEALLOC_STATE
value|0x14
end_define

begin_comment
comment|/* DMA regs common on r6xx/r7xx/evergreen/ni */
end_comment

begin_define
define|#
directive|define
name|DMA_RB_CNTL
value|0xd000
end_define

begin_define
define|#
directive|define
name|DMA_RB_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DMA_RB_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 1)
end_define

begin_comment
comment|/* log2 */
end_comment

begin_define
define|#
directive|define
name|DMA_RB_SWAP_ENABLE
value|(1<< 9)
end_define

begin_comment
comment|/* 8IN32 */
end_comment

begin_define
define|#
directive|define
name|DMA_RPTR_WRITEBACK_ENABLE
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|DMA_RPTR_WRITEBACK_SWAP_ENABLE
value|(1<< 13)
end_define

begin_comment
comment|/* 8IN32 */
end_comment

begin_define
define|#
directive|define
name|DMA_RPTR_WRITEBACK_TIMER
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_comment
comment|/* log2 */
end_comment

begin_define
define|#
directive|define
name|DMA_STATUS_REG
value|0xd034
end_define

begin_define
define|#
directive|define
name|DMA_IDLE
value|(1<< 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

