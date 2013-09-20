begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008 Advanced Micro Devices, Inc.  * Copyright 2008 Red Hat Inc.  * Copyright 2009 Jerome Glisse.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * Authors: Dave Airlie  *          Alex Deucher  *          Jerome Glisse  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__RV515D_H__
end_ifndef

begin_define
define|#
directive|define
name|__RV515D_H__
end_define

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

begin_comment
comment|/*  * RV515 registers  */
end_comment

begin_define
define|#
directive|define
name|PCIE_INDEX
value|0x0030
end_define

begin_define
define|#
directive|define
name|PCIE_DATA
value|0x0034
end_define

begin_define
define|#
directive|define
name|MC_IND_INDEX
value|0x0070
end_define

begin_define
define|#
directive|define
name|MC_IND_WR_EN
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|MC_IND_DATA
value|0x0074
end_define

begin_define
define|#
directive|define
name|RBBM_SOFT_RESET
value|0x00F0
end_define

begin_define
define|#
directive|define
name|CONFIG_MEMSIZE
value|0x00F8
end_define

begin_define
define|#
directive|define
name|HDP_FB_LOCATION
value|0x0134
end_define

begin_define
define|#
directive|define
name|CP_CSQ_CNTL
value|0x0740
end_define

begin_define
define|#
directive|define
name|CP_CSQ_MODE
value|0x0744
end_define

begin_define
define|#
directive|define
name|CP_CSQ_ADDR
value|0x07F0
end_define

begin_define
define|#
directive|define
name|CP_CSQ_DATA
value|0x07F4
end_define

begin_define
define|#
directive|define
name|CP_CSQ_STAT
value|0x07F8
end_define

begin_define
define|#
directive|define
name|CP_CSQ2_STAT
value|0x07FC
end_define

begin_define
define|#
directive|define
name|RBBM_STATUS
value|0x0E40
end_define

begin_define
define|#
directive|define
name|DST_PIPE_CONFIG
value|0x170C
end_define

begin_define
define|#
directive|define
name|WAIT_UNTIL
value|0x1720
end_define

begin_define
define|#
directive|define
name|WAIT_2D_IDLE
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|WAIT_3D_IDLE
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|WAIT_2D_IDLECLEAN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|WAIT_3D_IDLECLEAN
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|ISYNC_CNTL
value|0x1724
end_define

begin_define
define|#
directive|define
name|ISYNC_ANY2D_IDLE3D
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|ISYNC_ANY3D_IDLE2D
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|ISYNC_TRIG2D_IDLE3D
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|ISYNC_TRIG3D_IDLE2D
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|ISYNC_WAIT_IDLEGUI
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|ISYNC_CPSCRATCH_IDLEGUI
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|VAP_INDEX_OFFSET
value|0x208C
end_define

begin_define
define|#
directive|define
name|VAP_PVS_STATE_FLUSH_REG
value|0x2284
end_define

begin_define
define|#
directive|define
name|GB_ENABLE
value|0x4008
end_define

begin_define
define|#
directive|define
name|GB_MSPOS0
value|0x4010
end_define

begin_define
define|#
directive|define
name|MS_X0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|MS_Y0_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|MS_X1_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|MS_Y1_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|MS_X2_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|MS_Y2_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|MSBD0_Y_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|MSBD0_X_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|GB_MSPOS1
value|0x4014
end_define

begin_define
define|#
directive|define
name|MS_X3_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|MS_Y3_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|MS_X4_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|MS_Y4_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|MS_X5_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|MS_Y5_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|MSBD1_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|GB_TILE_CONFIG
value|0x4018
end_define

begin_define
define|#
directive|define
name|ENABLE_TILING
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|PIPE_COUNT_MASK
value|0x0000000E
end_define

begin_define
define|#
directive|define
name|PIPE_COUNT_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|TILE_SIZE_8
value|(0<< 4)
end_define

begin_define
define|#
directive|define
name|TILE_SIZE_16
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|TILE_SIZE_32
value|(2<< 4)
end_define

begin_define
define|#
directive|define
name|SUBPIXEL_1_12
value|(0<< 16)
end_define

begin_define
define|#
directive|define
name|SUBPIXEL_1_16
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|GB_SELECT
value|0x401C
end_define

begin_define
define|#
directive|define
name|GB_AA_CONFIG
value|0x4020
end_define

begin_define
define|#
directive|define
name|GB_PIPE_SELECT
value|0x402C
end_define

begin_define
define|#
directive|define
name|GA_ENHANCE
value|0x4274
end_define

begin_define
define|#
directive|define
name|GA_DEADLOCK_CNTL
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|GA_FASTSYNC_CNTL
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|GA_POLY_MODE
value|0x4288
end_define

begin_define
define|#
directive|define
name|FRONT_PTYPE_POINT
value|(0<< 4)
end_define

begin_define
define|#
directive|define
name|FRONT_PTYPE_LINE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|FRONT_PTYPE_TRIANGE
value|(2<< 4)
end_define

begin_define
define|#
directive|define
name|BACK_PTYPE_POINT
value|(0<< 7)
end_define

begin_define
define|#
directive|define
name|BACK_PTYPE_LINE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|BACK_PTYPE_TRIANGE
value|(2<< 7)
end_define

begin_define
define|#
directive|define
name|GA_ROUND_MODE
value|0x428C
end_define

begin_define
define|#
directive|define
name|GEOMETRY_ROUND_TRUNC
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|GEOMETRY_ROUND_NEAREST
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|COLOR_ROUND_TRUNC
value|(0<< 2)
end_define

begin_define
define|#
directive|define
name|COLOR_ROUND_NEAREST
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SU_REG_DEST
value|0x42C8
end_define

begin_define
define|#
directive|define
name|RB3D_DSTCACHE_CTLSTAT
value|0x4E4C
end_define

begin_define
define|#
directive|define
name|RB3D_DC_FLUSH
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|RB3D_DC_FREE
value|(2<< 2)
end_define

begin_define
define|#
directive|define
name|RB3D_DC_FINISH
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|ZB_ZCACHE_CTLSTAT
value|0x4F18
end_define

begin_define
define|#
directive|define
name|ZC_FLUSH
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|ZC_FREE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|DC_LB_MEMORY_SPLIT
value|0x6520
end_define

begin_define
define|#
directive|define
name|DC_LB_MEMORY_SPLIT_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|DC_LB_MEMORY_SPLIT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|DC_LB_MEMORY_SPLIT_D1HALF_D2HALF
value|0
end_define

begin_define
define|#
directive|define
name|DC_LB_MEMORY_SPLIT_D1_3Q_D2_1Q
value|1
end_define

begin_define
define|#
directive|define
name|DC_LB_MEMORY_SPLIT_D1_ONLY
value|2
end_define

begin_define
define|#
directive|define
name|DC_LB_MEMORY_SPLIT_D1_1Q_D2_3Q
value|3
end_define

begin_define
define|#
directive|define
name|DC_LB_MEMORY_SPLIT_SHIFT_MODE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|DC_LB_DISP1_END_ADR_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|DC_LB_DISP1_END_ADR_MASK
value|0x00007FF0
end_define

begin_define
define|#
directive|define
name|D1MODE_PRIORITY_A_CNT
value|0x6548
end_define

begin_define
define|#
directive|define
name|MODE_PRIORITY_MARK_MASK
value|0x00007FFF
end_define

begin_define
define|#
directive|define
name|MODE_PRIORITY_OFF
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|MODE_PRIORITY_ALWAYS_ON
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|MODE_PRIORITY_FORCE_MASK
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|D1MODE_PRIORITY_B_CNT
value|0x654C
end_define

begin_define
define|#
directive|define
name|LB_MAX_REQ_OUTSTANDING
value|0x6D58
end_define

begin_define
define|#
directive|define
name|LB_D1_MAX_REQ_OUTSTANDING_MASK
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|LB_D1_MAX_REQ_OUTSTANDING_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|LB_D2_MAX_REQ_OUTSTANDING_MASK
value|0x000F0000
end_define

begin_define
define|#
directive|define
name|LB_D2_MAX_REQ_OUTSTANDING_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|D2MODE_PRIORITY_A_CNT
value|0x6D48
end_define

begin_define
define|#
directive|define
name|D2MODE_PRIORITY_B_CNT
value|0x6D4C
end_define

begin_comment
comment|/* ix[MC] registers */
end_comment

begin_define
define|#
directive|define
name|MC_FB_LOCATION
value|0x01
end_define

begin_define
define|#
directive|define
name|MC_FB_START_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|MC_FB_START_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|MC_FB_TOP_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|MC_FB_TOP_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|MC_AGP_LOCATION
value|0x02
end_define

begin_define
define|#
directive|define
name|MC_AGP_START_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|MC_AGP_START_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|MC_AGP_TOP_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|MC_AGP_TOP_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|MC_AGP_BASE
value|0x03
end_define

begin_define
define|#
directive|define
name|MC_AGP_BASE_2
value|0x04
end_define

begin_define
define|#
directive|define
name|MC_CNTL
value|0x5
end_define

begin_define
define|#
directive|define
name|MEM_NUM_CHANNELS_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|MC_STATUS
value|0x08
end_define

begin_define
define|#
directive|define
name|MC_STATUS_IDLE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|MC_MISC_LAT_TIMER
value|0x09
end_define

begin_define
define|#
directive|define
name|MC_CPR_INIT_LAT_MASK
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|MC_VF_INIT_LAT_MASK
value|0x000000F0
end_define

begin_define
define|#
directive|define
name|MC_DISP0R_INIT_LAT_MASK
value|0x00000F00
end_define

begin_define
define|#
directive|define
name|MC_DISP0R_INIT_LAT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|MC_DISP1R_INIT_LAT_MASK
value|0x0000F000
end_define

begin_define
define|#
directive|define
name|MC_DISP1R_INIT_LAT_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|MC_FIXED_INIT_LAT_MASK
value|0x000F0000
end_define

begin_define
define|#
directive|define
name|MC_E2R_INIT_LAT_MASK
value|0x00F00000
end_define

begin_define
define|#
directive|define
name|SAME_PAGE_PRIO_MASK
value|0x0F000000
end_define

begin_define
define|#
directive|define
name|MC_GLOBW_INIT_LAT_MASK
value|0xF0000000
end_define

begin_comment
comment|/*  * PM4 packet  */
end_comment

begin_define
define|#
directive|define
name|CP_PACKET0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PACKET0_BASE_INDEX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PACKET0_BASE_INDEX_MASK
value|(0x1ffff<< 0)
end_define

begin_define
define|#
directive|define
name|PACKET0_COUNT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|PACKET0_COUNT_MASK
value|(0x3fff<< 16)
end_define

begin_define
define|#
directive|define
name|CP_PACKET1
value|0x40000000
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
name|CP_PACKET3
value|0xC0000000
end_define

begin_define
define|#
directive|define
name|PACKET3_IT_OPCODE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|PACKET3_IT_OPCODE_MASK
value|(0xff<< 8)
end_define

begin_define
define|#
directive|define
name|PACKET3_COUNT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|PACKET3_COUNT_MASK
value|(0x3fff<< 16)
end_define

begin_comment
comment|/* PACKET3 op code */
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
name|PACKET3_3D_DRAW_VBUF
value|0x28
end_define

begin_define
define|#
directive|define
name|PACKET3_3D_DRAW_IMMD
value|0x29
end_define

begin_define
define|#
directive|define
name|PACKET3_3D_DRAW_INDX
value|0x2A
end_define

begin_define
define|#
directive|define
name|PACKET3_3D_LOAD_VBPNTR
value|0x2F
end_define

begin_define
define|#
directive|define
name|PACKET3_INDX_BUFFER
value|0x33
end_define

begin_define
define|#
directive|define
name|PACKET3_3D_DRAW_VBUF_2
value|0x34
end_define

begin_define
define|#
directive|define
name|PACKET3_3D_DRAW_IMMD_2
value|0x35
end_define

begin_define
define|#
directive|define
name|PACKET3_3D_DRAW_INDX_2
value|0x36
end_define

begin_define
define|#
directive|define
name|PACKET3_BITBLT_MULTI
value|0x9B
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
value|(CP_PACKET0 |					\ 			 REG_SET(PACKET0_BASE_INDEX, (reg)>> 2) |	\ 			 REG_SET(PACKET0_COUNT, (n)))
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
value|(CP_PACKET3 |					\ 			 REG_SET(PACKET3_IT_OPCODE, (op)) |		\ 			 REG_SET(PACKET3_COUNT, (n)))
end_define

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
value|(((h)& 0x1FFF)<< 2)
end_define

begin_define
define|#
directive|define
name|CP_PACKET0_GET_ONE_REG_WR
parameter_list|(
name|h
parameter_list|)
value|(((h)>> 15)& 1)
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

begin_comment
comment|/* Registers */
end_comment

begin_define
define|#
directive|define
name|R_0000F0_RBBM_SOFT_RESET
value|0x0000F0
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_CP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_CP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_CP
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_HI
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 1)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_HI
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_HI
value|0xFFFFFFFD
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_VAP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 2)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_VAP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 2)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_VAP
value|0xFFFFFFFB
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_RE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 3)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_RE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 3)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_RE
value|0xFFFFFFF7
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_PP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 4)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_PP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_PP
value|0xFFFFFFEF
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_E2
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 5)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_E2
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 5)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_E2
value|0xFFFFFFDF
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_RB
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 6)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_RB
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 6)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_RB
value|0xFFFFFFBF
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_HDP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 7)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_HDP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 7)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_HDP
value|0xFFFFFF7F
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_MC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 8)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_MC
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_MC
value|0xFFFFFEFF
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_AIC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 9)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_AIC
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 9)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_AIC
value|0xFFFFFDFF
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_VIP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 10)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_VIP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_VIP
value|0xFFFFFBFF
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_DISP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 11)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_DISP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 11)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_DISP
value|0xFFFFF7FF
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_CG
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 12)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_CG
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_CG
value|0xFFFFEFFF
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_GA
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 13)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_GA
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 13)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_GA
value|0xFFFFDFFF
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_IDCT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 14)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_IDCT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 14)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_IDCT
value|0xFFFFBFFF
end_define

begin_define
define|#
directive|define
name|R_0000F8_CONFIG_MEMSIZE
value|0x0000F8
end_define

begin_define
define|#
directive|define
name|S_0000F8_CONFIG_MEMSIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFFFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_0000F8_CONFIG_MEMSIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|C_0000F8_CONFIG_MEMSIZE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|R_000134_HDP_FB_LOCATION
value|0x000134
end_define

begin_define
define|#
directive|define
name|S_000134_HDP_FB_START
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000134_HDP_FB_START
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|C_000134_HDP_FB_START
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|R_000300_VGA_RENDER_CONTROL
value|0x000300
end_define

begin_define
define|#
directive|define
name|S_000300_VGA_BLINK_RATE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1F)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000300_VGA_BLINK_RATE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1F)
end_define

begin_define
define|#
directive|define
name|C_000300_VGA_BLINK_RATE
value|0xFFFFFFE0
end_define

begin_define
define|#
directive|define
name|S_000300_VGA_BLINK_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 5)
end_define

begin_define
define|#
directive|define
name|G_000300_VGA_BLINK_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 5)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_000300_VGA_BLINK_MODE
value|0xFFFFFF9F
end_define

begin_define
define|#
directive|define
name|S_000300_VGA_CURSOR_BLINK_INVERT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 7)
end_define

begin_define
define|#
directive|define
name|G_000300_VGA_CURSOR_BLINK_INVERT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 7)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000300_VGA_CURSOR_BLINK_INVERT
value|0xFFFFFF7F
end_define

begin_define
define|#
directive|define
name|S_000300_VGA_EXTD_ADDR_COUNT_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 8)
end_define

begin_define
define|#
directive|define
name|G_000300_VGA_EXTD_ADDR_COUNT_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000300_VGA_EXTD_ADDR_COUNT_ENABLE
value|0xFFFFFEFF
end_define

begin_define
define|#
directive|define
name|S_000300_VGA_VSTATUS_CNTL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 16)
end_define

begin_define
define|#
directive|define
name|G_000300_VGA_VSTATUS_CNTL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_000300_VGA_VSTATUS_CNTL
value|0xFFFCFFFF
end_define

begin_define
define|#
directive|define
name|S_000300_VGA_LOCK_8DOT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 24)
end_define

begin_define
define|#
directive|define
name|G_000300_VGA_LOCK_8DOT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000300_VGA_LOCK_8DOT
value|0xFEFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000300_VGAREG_LINECMP_COMPATIBILITY_SEL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 25)
end_define

begin_define
define|#
directive|define
name|G_000300_VGAREG_LINECMP_COMPATIBILITY_SEL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 25)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000300_VGAREG_LINECMP_COMPATIBILITY_SEL
value|0xFDFFFFFF
end_define

begin_define
define|#
directive|define
name|R_000310_VGA_MEMORY_BASE_ADDRESS
value|0x000310
end_define

begin_define
define|#
directive|define
name|S_000310_VGA_MEMORY_BASE_ADDRESS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFFFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000310_VGA_MEMORY_BASE_ADDRESS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|C_000310_VGA_MEMORY_BASE_ADDRESS
value|0x00000000
end_define

begin_define
define|#
directive|define
name|R_000328_VGA_HDP_CONTROL
value|0x000328
end_define

begin_define
define|#
directive|define
name|S_000328_VGA_MEM_PAGE_SELECT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000328_VGA_MEM_PAGE_SELECT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000328_VGA_MEM_PAGE_SELECT_EN
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_000328_VGA_RBBM_LOCK_DISABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 8)
end_define

begin_define
define|#
directive|define
name|G_000328_VGA_RBBM_LOCK_DISABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000328_VGA_RBBM_LOCK_DISABLE
value|0xFFFFFEFF
end_define

begin_define
define|#
directive|define
name|S_000328_VGA_SOFT_RESET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 16)
end_define

begin_define
define|#
directive|define
name|G_000328_VGA_SOFT_RESET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000328_VGA_SOFT_RESET
value|0xFFFEFFFF
end_define

begin_define
define|#
directive|define
name|S_000328_VGA_TEST_RESET_CONTROL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 24)
end_define

begin_define
define|#
directive|define
name|G_000328_VGA_TEST_RESET_CONTROL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000328_VGA_TEST_RESET_CONTROL
value|0xFEFFFFFF
end_define

begin_define
define|#
directive|define
name|R_000330_D1VGA_CONTROL
value|0x000330
end_define

begin_define
define|#
directive|define
name|S_000330_D1VGA_MODE_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000330_D1VGA_MODE_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000330_D1VGA_MODE_ENABLE
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_000330_D1VGA_TIMING_SELECT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 8)
end_define

begin_define
define|#
directive|define
name|G_000330_D1VGA_TIMING_SELECT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000330_D1VGA_TIMING_SELECT
value|0xFFFFFEFF
end_define

begin_define
define|#
directive|define
name|S_000330_D1VGA_SYNC_POLARITY_SELECT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 9)
end_define

begin_define
define|#
directive|define
name|G_000330_D1VGA_SYNC_POLARITY_SELECT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 9)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000330_D1VGA_SYNC_POLARITY_SELECT
value|0xFFFFFDFF
end_define

begin_define
define|#
directive|define
name|S_000330_D1VGA_OVERSCAN_TIMING_SELECT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 10)
end_define

begin_define
define|#
directive|define
name|G_000330_D1VGA_OVERSCAN_TIMING_SELECT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000330_D1VGA_OVERSCAN_TIMING_SELECT
value|0xFFFFFBFF
end_define

begin_define
define|#
directive|define
name|S_000330_D1VGA_OVERSCAN_COLOR_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 16)
end_define

begin_define
define|#
directive|define
name|G_000330_D1VGA_OVERSCAN_COLOR_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000330_D1VGA_OVERSCAN_COLOR_EN
value|0xFFFEFFFF
end_define

begin_define
define|#
directive|define
name|S_000330_D1VGA_ROTATE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 24)
end_define

begin_define
define|#
directive|define
name|G_000330_D1VGA_ROTATE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_000330_D1VGA_ROTATE
value|0xFCFFFFFF
end_define

begin_define
define|#
directive|define
name|R_000338_D2VGA_CONTROL
value|0x000338
end_define

begin_define
define|#
directive|define
name|S_000338_D2VGA_MODE_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000338_D2VGA_MODE_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000338_D2VGA_MODE_ENABLE
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_000338_D2VGA_TIMING_SELECT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 8)
end_define

begin_define
define|#
directive|define
name|G_000338_D2VGA_TIMING_SELECT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000338_D2VGA_TIMING_SELECT
value|0xFFFFFEFF
end_define

begin_define
define|#
directive|define
name|S_000338_D2VGA_SYNC_POLARITY_SELECT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 9)
end_define

begin_define
define|#
directive|define
name|G_000338_D2VGA_SYNC_POLARITY_SELECT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 9)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000338_D2VGA_SYNC_POLARITY_SELECT
value|0xFFFFFDFF
end_define

begin_define
define|#
directive|define
name|S_000338_D2VGA_OVERSCAN_TIMING_SELECT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 10)
end_define

begin_define
define|#
directive|define
name|G_000338_D2VGA_OVERSCAN_TIMING_SELECT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000338_D2VGA_OVERSCAN_TIMING_SELECT
value|0xFFFFFBFF
end_define

begin_define
define|#
directive|define
name|S_000338_D2VGA_OVERSCAN_COLOR_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 16)
end_define

begin_define
define|#
directive|define
name|G_000338_D2VGA_OVERSCAN_COLOR_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000338_D2VGA_OVERSCAN_COLOR_EN
value|0xFFFEFFFF
end_define

begin_define
define|#
directive|define
name|S_000338_D2VGA_ROTATE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 24)
end_define

begin_define
define|#
directive|define
name|G_000338_D2VGA_ROTATE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_000338_D2VGA_ROTATE
value|0xFCFFFFFF
end_define

begin_define
define|#
directive|define
name|R_0007C0_CP_STAT
value|0x0007C0
end_define

begin_define
define|#
directive|define
name|S_0007C0_MRU_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_0007C0_MRU_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_MRU_BUSY
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_0007C0_MWU_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 1)
end_define

begin_define
define|#
directive|define
name|G_0007C0_MWU_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_MWU_BUSY
value|0xFFFFFFFD
end_define

begin_define
define|#
directive|define
name|S_0007C0_RSIU_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 2)
end_define

begin_define
define|#
directive|define
name|G_0007C0_RSIU_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 2)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_RSIU_BUSY
value|0xFFFFFFFB
end_define

begin_define
define|#
directive|define
name|S_0007C0_RCIU_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 3)
end_define

begin_define
define|#
directive|define
name|G_0007C0_RCIU_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 3)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_RCIU_BUSY
value|0xFFFFFFF7
end_define

begin_define
define|#
directive|define
name|S_0007C0_CSF_PRIMARY_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 9)
end_define

begin_define
define|#
directive|define
name|G_0007C0_CSF_PRIMARY_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 9)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_CSF_PRIMARY_BUSY
value|0xFFFFFDFF
end_define

begin_define
define|#
directive|define
name|S_0007C0_CSF_INDIRECT_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 10)
end_define

begin_define
define|#
directive|define
name|G_0007C0_CSF_INDIRECT_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_CSF_INDIRECT_BUSY
value|0xFFFFFBFF
end_define

begin_define
define|#
directive|define
name|S_0007C0_CSQ_PRIMARY_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 11)
end_define

begin_define
define|#
directive|define
name|G_0007C0_CSQ_PRIMARY_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 11)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_CSQ_PRIMARY_BUSY
value|0xFFFFF7FF
end_define

begin_define
define|#
directive|define
name|S_0007C0_CSQ_INDIRECT_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 12)
end_define

begin_define
define|#
directive|define
name|G_0007C0_CSQ_INDIRECT_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_CSQ_INDIRECT_BUSY
value|0xFFFFEFFF
end_define

begin_define
define|#
directive|define
name|S_0007C0_CSI_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 13)
end_define

begin_define
define|#
directive|define
name|G_0007C0_CSI_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 13)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_CSI_BUSY
value|0xFFFFDFFF
end_define

begin_define
define|#
directive|define
name|S_0007C0_CSF_INDIRECT2_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 14)
end_define

begin_define
define|#
directive|define
name|G_0007C0_CSF_INDIRECT2_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 14)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_CSF_INDIRECT2_BUSY
value|0xFFFFBFFF
end_define

begin_define
define|#
directive|define
name|S_0007C0_CSQ_INDIRECT2_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 15)
end_define

begin_define
define|#
directive|define
name|G_0007C0_CSQ_INDIRECT2_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 15)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_CSQ_INDIRECT2_BUSY
value|0xFFFF7FFF
end_define

begin_define
define|#
directive|define
name|S_0007C0_GUIDMA_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 28)
end_define

begin_define
define|#
directive|define
name|G_0007C0_GUIDMA_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 28)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_GUIDMA_BUSY
value|0xEFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_0007C0_VIDDMA_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 29)
end_define

begin_define
define|#
directive|define
name|G_0007C0_VIDDMA_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 29)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_VIDDMA_BUSY
value|0xDFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_0007C0_CMDSTRM_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 30)
end_define

begin_define
define|#
directive|define
name|G_0007C0_CMDSTRM_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 30)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_CMDSTRM_BUSY
value|0xBFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_0007C0_CP_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 31)
end_define

begin_define
define|#
directive|define
name|G_0007C0_CP_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 31)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_CP_BUSY
value|0x7FFFFFFF
end_define

begin_define
define|#
directive|define
name|R_000E40_RBBM_STATUS
value|0x000E40
end_define

begin_define
define|#
directive|define
name|S_000E40_CMDFIFO_AVAIL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7F)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000E40_CMDFIFO_AVAIL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x7F)
end_define

begin_define
define|#
directive|define
name|C_000E40_CMDFIFO_AVAIL
value|0xFFFFFF80
end_define

begin_define
define|#
directive|define
name|S_000E40_HIRQ_ON_RBB
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 8)
end_define

begin_define
define|#
directive|define
name|G_000E40_HIRQ_ON_RBB
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_HIRQ_ON_RBB
value|0xFFFFFEFF
end_define

begin_define
define|#
directive|define
name|S_000E40_CPRQ_ON_RBB
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 9)
end_define

begin_define
define|#
directive|define
name|G_000E40_CPRQ_ON_RBB
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 9)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_CPRQ_ON_RBB
value|0xFFFFFDFF
end_define

begin_define
define|#
directive|define
name|S_000E40_CFRQ_ON_RBB
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 10)
end_define

begin_define
define|#
directive|define
name|G_000E40_CFRQ_ON_RBB
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_CFRQ_ON_RBB
value|0xFFFFFBFF
end_define

begin_define
define|#
directive|define
name|S_000E40_HIRQ_IN_RTBUF
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 11)
end_define

begin_define
define|#
directive|define
name|G_000E40_HIRQ_IN_RTBUF
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 11)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_HIRQ_IN_RTBUF
value|0xFFFFF7FF
end_define

begin_define
define|#
directive|define
name|S_000E40_CPRQ_IN_RTBUF
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 12)
end_define

begin_define
define|#
directive|define
name|G_000E40_CPRQ_IN_RTBUF
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_CPRQ_IN_RTBUF
value|0xFFFFEFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_CFRQ_IN_RTBUF
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 13)
end_define

begin_define
define|#
directive|define
name|G_000E40_CFRQ_IN_RTBUF
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 13)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_CFRQ_IN_RTBUF
value|0xFFFFDFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_CF_PIPE_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 14)
end_define

begin_define
define|#
directive|define
name|G_000E40_CF_PIPE_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 14)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_CF_PIPE_BUSY
value|0xFFFFBFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_ENG_EV_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 15)
end_define

begin_define
define|#
directive|define
name|G_000E40_ENG_EV_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 15)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_ENG_EV_BUSY
value|0xFFFF7FFF
end_define

begin_define
define|#
directive|define
name|S_000E40_CP_CMDSTRM_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 16)
end_define

begin_define
define|#
directive|define
name|G_000E40_CP_CMDSTRM_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_CP_CMDSTRM_BUSY
value|0xFFFEFFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_E2_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 17)
end_define

begin_define
define|#
directive|define
name|G_000E40_E2_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 17)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_E2_BUSY
value|0xFFFDFFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_RB2D_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 18)
end_define

begin_define
define|#
directive|define
name|G_000E40_RB2D_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 18)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_RB2D_BUSY
value|0xFFFBFFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_RB3D_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 19)
end_define

begin_define
define|#
directive|define
name|G_000E40_RB3D_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 19)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_RB3D_BUSY
value|0xFFF7FFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_VAP_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 20)
end_define

begin_define
define|#
directive|define
name|G_000E40_VAP_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_VAP_BUSY
value|0xFFEFFFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_RE_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 21)
end_define

begin_define
define|#
directive|define
name|G_000E40_RE_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 21)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_RE_BUSY
value|0xFFDFFFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_TAM_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 22)
end_define

begin_define
define|#
directive|define
name|G_000E40_TAM_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 22)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_TAM_BUSY
value|0xFFBFFFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_TDM_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 23)
end_define

begin_define
define|#
directive|define
name|G_000E40_TDM_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 23)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_TDM_BUSY
value|0xFF7FFFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_PB_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 24)
end_define

begin_define
define|#
directive|define
name|G_000E40_PB_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_PB_BUSY
value|0xFEFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_TIM_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 25)
end_define

begin_define
define|#
directive|define
name|G_000E40_TIM_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 25)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_TIM_BUSY
value|0xFDFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_GA_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 26)
end_define

begin_define
define|#
directive|define
name|G_000E40_GA_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 26)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_GA_BUSY
value|0xFBFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_CBA2D_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 27)
end_define

begin_define
define|#
directive|define
name|G_000E40_CBA2D_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 27)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_CBA2D_BUSY
value|0xF7FFFFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_RBBM_HIBUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 28)
end_define

begin_define
define|#
directive|define
name|G_000E40_RBBM_HIBUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 28)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_RBBM_HIBUSY
value|0xEFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_SKID_CFBUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 29)
end_define

begin_define
define|#
directive|define
name|G_000E40_SKID_CFBUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 29)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_SKID_CFBUSY
value|0xDFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_VAP_VF_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 30)
end_define

begin_define
define|#
directive|define
name|G_000E40_VAP_VF_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 30)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_VAP_VF_BUSY
value|0xBFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_GUI_ACTIVE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 31)
end_define

begin_define
define|#
directive|define
name|G_000E40_GUI_ACTIVE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 31)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_GUI_ACTIVE
value|0x7FFFFFFF
end_define

begin_define
define|#
directive|define
name|R_006080_D1CRTC_CONTROL
value|0x006080
end_define

begin_define
define|#
directive|define
name|S_006080_D1CRTC_MASTER_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_006080_D1CRTC_MASTER_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_006080_D1CRTC_MASTER_EN
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_006080_D1CRTC_SYNC_RESET_SEL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 4)
end_define

begin_define
define|#
directive|define
name|G_006080_D1CRTC_SYNC_RESET_SEL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_006080_D1CRTC_SYNC_RESET_SEL
value|0xFFFFFFEF
end_define

begin_define
define|#
directive|define
name|S_006080_D1CRTC_DISABLE_POINT_CNTL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 8)
end_define

begin_define
define|#
directive|define
name|G_006080_D1CRTC_DISABLE_POINT_CNTL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_006080_D1CRTC_DISABLE_POINT_CNTL
value|0xFFFFFCFF
end_define

begin_define
define|#
directive|define
name|S_006080_D1CRTC_CURRENT_MASTER_EN_STATE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 16)
end_define

begin_define
define|#
directive|define
name|G_006080_D1CRTC_CURRENT_MASTER_EN_STATE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_006080_D1CRTC_CURRENT_MASTER_EN_STATE
value|0xFFFEFFFF
end_define

begin_define
define|#
directive|define
name|S_006080_D1CRTC_DISP_READ_REQUEST_DISABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 24)
end_define

begin_define
define|#
directive|define
name|G_006080_D1CRTC_DISP_READ_REQUEST_DISABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_006080_D1CRTC_DISP_READ_REQUEST_DISABLE
value|0xFEFFFFFF
end_define

begin_define
define|#
directive|define
name|R_0060E8_D1CRTC_UPDATE_LOCK
value|0x0060E8
end_define

begin_define
define|#
directive|define
name|S_0060E8_D1CRTC_UPDATE_LOCK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_0060E8_D1CRTC_UPDATE_LOCK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0060E8_D1CRTC_UPDATE_LOCK
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|R_006110_D1GRPH_PRIMARY_SURFACE_ADDRESS
value|0x006110
end_define

begin_define
define|#
directive|define
name|S_006110_D1GRPH_PRIMARY_SURFACE_ADDRESS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFFFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_006110_D1GRPH_PRIMARY_SURFACE_ADDRESS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|C_006110_D1GRPH_PRIMARY_SURFACE_ADDRESS
value|0x00000000
end_define

begin_define
define|#
directive|define
name|R_006118_D1GRPH_SECONDARY_SURFACE_ADDRESS
value|0x006118
end_define

begin_define
define|#
directive|define
name|S_006118_D1GRPH_SECONDARY_SURFACE_ADDRESS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFFFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_006118_D1GRPH_SECONDARY_SURFACE_ADDRESS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|C_006118_D1GRPH_SECONDARY_SURFACE_ADDRESS
value|0x00000000
end_define

begin_define
define|#
directive|define
name|R_006880_D2CRTC_CONTROL
value|0x006880
end_define

begin_define
define|#
directive|define
name|S_006880_D2CRTC_MASTER_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_006880_D2CRTC_MASTER_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_006880_D2CRTC_MASTER_EN
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_006880_D2CRTC_SYNC_RESET_SEL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 4)
end_define

begin_define
define|#
directive|define
name|G_006880_D2CRTC_SYNC_RESET_SEL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_006880_D2CRTC_SYNC_RESET_SEL
value|0xFFFFFFEF
end_define

begin_define
define|#
directive|define
name|S_006880_D2CRTC_DISABLE_POINT_CNTL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 8)
end_define

begin_define
define|#
directive|define
name|G_006880_D2CRTC_DISABLE_POINT_CNTL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_006880_D2CRTC_DISABLE_POINT_CNTL
value|0xFFFFFCFF
end_define

begin_define
define|#
directive|define
name|S_006880_D2CRTC_CURRENT_MASTER_EN_STATE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 16)
end_define

begin_define
define|#
directive|define
name|G_006880_D2CRTC_CURRENT_MASTER_EN_STATE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_006880_D2CRTC_CURRENT_MASTER_EN_STATE
value|0xFFFEFFFF
end_define

begin_define
define|#
directive|define
name|S_006880_D2CRTC_DISP_READ_REQUEST_DISABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 24)
end_define

begin_define
define|#
directive|define
name|G_006880_D2CRTC_DISP_READ_REQUEST_DISABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_006880_D2CRTC_DISP_READ_REQUEST_DISABLE
value|0xFEFFFFFF
end_define

begin_define
define|#
directive|define
name|R_0068E8_D2CRTC_UPDATE_LOCK
value|0x0068E8
end_define

begin_define
define|#
directive|define
name|S_0068E8_D2CRTC_UPDATE_LOCK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_0068E8_D2CRTC_UPDATE_LOCK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0068E8_D2CRTC_UPDATE_LOCK
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|R_006910_D2GRPH_PRIMARY_SURFACE_ADDRESS
value|0x006910
end_define

begin_define
define|#
directive|define
name|S_006910_D2GRPH_PRIMARY_SURFACE_ADDRESS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFFFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_006910_D2GRPH_PRIMARY_SURFACE_ADDRESS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|C_006910_D2GRPH_PRIMARY_SURFACE_ADDRESS
value|0x00000000
end_define

begin_define
define|#
directive|define
name|R_006918_D2GRPH_SECONDARY_SURFACE_ADDRESS
value|0x006918
end_define

begin_define
define|#
directive|define
name|S_006918_D2GRPH_SECONDARY_SURFACE_ADDRESS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFFFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_006918_D2GRPH_SECONDARY_SURFACE_ADDRESS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|C_006918_D2GRPH_SECONDARY_SURFACE_ADDRESS
value|0x00000000
end_define

begin_define
define|#
directive|define
name|R_000001_MC_FB_LOCATION
value|0x000001
end_define

begin_define
define|#
directive|define
name|S_000001_MC_FB_START
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000001_MC_FB_START
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|C_000001_MC_FB_START
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|S_000001_MC_FB_TOP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFF)<< 16)
end_define

begin_define
define|#
directive|define
name|G_000001_MC_FB_TOP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|C_000001_MC_FB_TOP
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|R_000002_MC_AGP_LOCATION
value|0x000002
end_define

begin_define
define|#
directive|define
name|S_000002_MC_AGP_START
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000002_MC_AGP_START
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|C_000002_MC_AGP_START
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|S_000002_MC_AGP_TOP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFF)<< 16)
end_define

begin_define
define|#
directive|define
name|G_000002_MC_AGP_TOP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|C_000002_MC_AGP_TOP
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|R_000003_MC_AGP_BASE
value|0x000003
end_define

begin_define
define|#
directive|define
name|S_000003_AGP_BASE_ADDR
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFFFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000003_AGP_BASE_ADDR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|C_000003_AGP_BASE_ADDR
value|0x00000000
end_define

begin_define
define|#
directive|define
name|R_000004_MC_AGP_BASE_2
value|0x000004
end_define

begin_define
define|#
directive|define
name|S_000004_AGP_BASE_ADDR_2
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000004_AGP_BASE_ADDR_2
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_000004_AGP_BASE_ADDR_2
value|0xFFFFFFF0
end_define

begin_define
define|#
directive|define
name|R_00000F_CP_DYN_CNTL
value|0x00000F
end_define

begin_define
define|#
directive|define
name|S_00000F_CP_FORCEON
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_00000F_CP_FORCEON
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000F_CP_FORCEON
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_00000F_CP_MAX_DYN_STOP_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 1)
end_define

begin_define
define|#
directive|define
name|G_00000F_CP_MAX_DYN_STOP_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000F_CP_MAX_DYN_STOP_LAT
value|0xFFFFFFFD
end_define

begin_define
define|#
directive|define
name|S_00000F_CP_CLOCK_STATUS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 2)
end_define

begin_define
define|#
directive|define
name|G_00000F_CP_CLOCK_STATUS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 2)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000F_CP_CLOCK_STATUS
value|0xFFFFFFFB
end_define

begin_define
define|#
directive|define
name|S_00000F_CP_PROG_SHUTOFF
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 3)
end_define

begin_define
define|#
directive|define
name|G_00000F_CP_PROG_SHUTOFF
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 3)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000F_CP_PROG_SHUTOFF
value|0xFFFFFFF7
end_define

begin_define
define|#
directive|define
name|S_00000F_CP_PROG_DELAY_VALUE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFF)<< 4)
end_define

begin_define
define|#
directive|define
name|G_00000F_CP_PROG_DELAY_VALUE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0xFF)
end_define

begin_define
define|#
directive|define
name|C_00000F_CP_PROG_DELAY_VALUE
value|0xFFFFF00F
end_define

begin_define
define|#
directive|define
name|S_00000F_CP_LOWER_POWER_IDLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFF)<< 12)
end_define

begin_define
define|#
directive|define
name|G_00000F_CP_LOWER_POWER_IDLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0xFF)
end_define

begin_define
define|#
directive|define
name|C_00000F_CP_LOWER_POWER_IDLE
value|0xFFF00FFF
end_define

begin_define
define|#
directive|define
name|S_00000F_CP_LOWER_POWER_IGNORE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 20)
end_define

begin_define
define|#
directive|define
name|G_00000F_CP_LOWER_POWER_IGNORE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000F_CP_LOWER_POWER_IGNORE
value|0xFFEFFFFF
end_define

begin_define
define|#
directive|define
name|S_00000F_CP_NORMAL_POWER_IGNORE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 21)
end_define

begin_define
define|#
directive|define
name|G_00000F_CP_NORMAL_POWER_IGNORE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 21)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000F_CP_NORMAL_POWER_IGNORE
value|0xFFDFFFFF
end_define

begin_define
define|#
directive|define
name|S_00000F_SPARE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 22)
end_define

begin_define
define|#
directive|define
name|G_00000F_SPARE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 22)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_00000F_SPARE
value|0xFF3FFFFF
end_define

begin_define
define|#
directive|define
name|S_00000F_CP_NORMAL_POWER_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFF)<< 24)
end_define

begin_define
define|#
directive|define
name|G_00000F_CP_NORMAL_POWER_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0xFF)
end_define

begin_define
define|#
directive|define
name|C_00000F_CP_NORMAL_POWER_BUSY
value|0x00FFFFFF
end_define

begin_define
define|#
directive|define
name|R_000011_E2_DYN_CNTL
value|0x000011
end_define

begin_define
define|#
directive|define
name|S_000011_E2_FORCEON
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000011_E2_FORCEON
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000011_E2_FORCEON
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_000011_E2_MAX_DYN_STOP_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 1)
end_define

begin_define
define|#
directive|define
name|G_000011_E2_MAX_DYN_STOP_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000011_E2_MAX_DYN_STOP_LAT
value|0xFFFFFFFD
end_define

begin_define
define|#
directive|define
name|S_000011_E2_CLOCK_STATUS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 2)
end_define

begin_define
define|#
directive|define
name|G_000011_E2_CLOCK_STATUS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 2)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000011_E2_CLOCK_STATUS
value|0xFFFFFFFB
end_define

begin_define
define|#
directive|define
name|S_000011_E2_PROG_SHUTOFF
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 3)
end_define

begin_define
define|#
directive|define
name|G_000011_E2_PROG_SHUTOFF
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 3)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000011_E2_PROG_SHUTOFF
value|0xFFFFFFF7
end_define

begin_define
define|#
directive|define
name|S_000011_E2_PROG_DELAY_VALUE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFF)<< 4)
end_define

begin_define
define|#
directive|define
name|G_000011_E2_PROG_DELAY_VALUE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0xFF)
end_define

begin_define
define|#
directive|define
name|C_000011_E2_PROG_DELAY_VALUE
value|0xFFFFF00F
end_define

begin_define
define|#
directive|define
name|S_000011_E2_LOWER_POWER_IDLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFF)<< 12)
end_define

begin_define
define|#
directive|define
name|G_000011_E2_LOWER_POWER_IDLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0xFF)
end_define

begin_define
define|#
directive|define
name|C_000011_E2_LOWER_POWER_IDLE
value|0xFFF00FFF
end_define

begin_define
define|#
directive|define
name|S_000011_E2_LOWER_POWER_IGNORE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 20)
end_define

begin_define
define|#
directive|define
name|G_000011_E2_LOWER_POWER_IGNORE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000011_E2_LOWER_POWER_IGNORE
value|0xFFEFFFFF
end_define

begin_define
define|#
directive|define
name|S_000011_E2_NORMAL_POWER_IGNORE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 21)
end_define

begin_define
define|#
directive|define
name|G_000011_E2_NORMAL_POWER_IGNORE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 21)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000011_E2_NORMAL_POWER_IGNORE
value|0xFFDFFFFF
end_define

begin_define
define|#
directive|define
name|S_000011_SPARE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 22)
end_define

begin_define
define|#
directive|define
name|G_000011_SPARE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 22)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_000011_SPARE
value|0xFF3FFFFF
end_define

begin_define
define|#
directive|define
name|S_000011_E2_NORMAL_POWER_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFF)<< 24)
end_define

begin_define
define|#
directive|define
name|G_000011_E2_NORMAL_POWER_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0xFF)
end_define

begin_define
define|#
directive|define
name|C_000011_E2_NORMAL_POWER_BUSY
value|0x00FFFFFF
end_define

begin_define
define|#
directive|define
name|R_000013_IDCT_DYN_CNTL
value|0x000013
end_define

begin_define
define|#
directive|define
name|S_000013_IDCT_FORCEON
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000013_IDCT_FORCEON
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000013_IDCT_FORCEON
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_000013_IDCT_MAX_DYN_STOP_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 1)
end_define

begin_define
define|#
directive|define
name|G_000013_IDCT_MAX_DYN_STOP_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000013_IDCT_MAX_DYN_STOP_LAT
value|0xFFFFFFFD
end_define

begin_define
define|#
directive|define
name|S_000013_IDCT_CLOCK_STATUS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 2)
end_define

begin_define
define|#
directive|define
name|G_000013_IDCT_CLOCK_STATUS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 2)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000013_IDCT_CLOCK_STATUS
value|0xFFFFFFFB
end_define

begin_define
define|#
directive|define
name|S_000013_IDCT_PROG_SHUTOFF
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 3)
end_define

begin_define
define|#
directive|define
name|G_000013_IDCT_PROG_SHUTOFF
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 3)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000013_IDCT_PROG_SHUTOFF
value|0xFFFFFFF7
end_define

begin_define
define|#
directive|define
name|S_000013_IDCT_PROG_DELAY_VALUE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFF)<< 4)
end_define

begin_define
define|#
directive|define
name|G_000013_IDCT_PROG_DELAY_VALUE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0xFF)
end_define

begin_define
define|#
directive|define
name|C_000013_IDCT_PROG_DELAY_VALUE
value|0xFFFFF00F
end_define

begin_define
define|#
directive|define
name|S_000013_IDCT_LOWER_POWER_IDLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFF)<< 12)
end_define

begin_define
define|#
directive|define
name|G_000013_IDCT_LOWER_POWER_IDLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0xFF)
end_define

begin_define
define|#
directive|define
name|C_000013_IDCT_LOWER_POWER_IDLE
value|0xFFF00FFF
end_define

begin_define
define|#
directive|define
name|S_000013_IDCT_LOWER_POWER_IGNORE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 20)
end_define

begin_define
define|#
directive|define
name|G_000013_IDCT_LOWER_POWER_IGNORE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000013_IDCT_LOWER_POWER_IGNORE
value|0xFFEFFFFF
end_define

begin_define
define|#
directive|define
name|S_000013_IDCT_NORMAL_POWER_IGNORE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 21)
end_define

begin_define
define|#
directive|define
name|G_000013_IDCT_NORMAL_POWER_IGNORE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 21)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000013_IDCT_NORMAL_POWER_IGNORE
value|0xFFDFFFFF
end_define

begin_define
define|#
directive|define
name|S_000013_SPARE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 22)
end_define

begin_define
define|#
directive|define
name|G_000013_SPARE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 22)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_000013_SPARE
value|0xFF3FFFFF
end_define

begin_define
define|#
directive|define
name|S_000013_IDCT_NORMAL_POWER_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFF)<< 24)
end_define

begin_define
define|#
directive|define
name|G_000013_IDCT_NORMAL_POWER_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0xFF)
end_define

begin_define
define|#
directive|define
name|C_000013_IDCT_NORMAL_POWER_BUSY
value|0x00FFFFFF
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

