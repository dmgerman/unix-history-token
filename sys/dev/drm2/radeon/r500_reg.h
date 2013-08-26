begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008 Advanced Micro Devices, Inc.  * Copyright 2008 Red Hat Inc.  * Copyright 2009 Jerome Glisse.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * Authors: Dave Airlie  *          Alex Deucher  *          Jerome Glisse  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__R500_REG_H__
end_ifndef

begin_define
define|#
directive|define
name|__R500_REG_H__
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
comment|/* pipe config regs */
end_comment

begin_define
define|#
directive|define
name|R300_GA_POLY_MODE
value|0x4288
end_define

begin_define
define|#
directive|define
name|R300_FRONT_PTYPE_POINT
value|(0<< 4)
end_define

begin_define
define|#
directive|define
name|R300_FRONT_PTYPE_LINE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|R300_FRONT_PTYPE_TRIANGE
value|(2<< 4)
end_define

begin_define
define|#
directive|define
name|R300_BACK_PTYPE_POINT
value|(0<< 7)
end_define

begin_define
define|#
directive|define
name|R300_BACK_PTYPE_LINE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|R300_BACK_PTYPE_TRIANGE
value|(2<< 7)
end_define

begin_define
define|#
directive|define
name|R300_GA_ROUND_MODE
value|0x428c
end_define

begin_define
define|#
directive|define
name|R300_GEOMETRY_ROUND_TRUNC
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|R300_GEOMETRY_ROUND_NEAREST
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R300_COLOR_ROUND_TRUNC
value|(0<< 2)
end_define

begin_define
define|#
directive|define
name|R300_COLOR_ROUND_NEAREST
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|R300_GB_MSPOS0
value|0x4010
end_define

begin_define
define|#
directive|define
name|R300_MS_X0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R300_MS_Y0_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|R300_MS_X1_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|R300_MS_Y1_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|R300_MS_X2_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|R300_MS_Y2_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|R300_MSBD0_Y_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|R300_MSBD0_X_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|R300_GB_MSPOS1
value|0x4014
end_define

begin_define
define|#
directive|define
name|R300_MS_X3_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R300_MS_Y3_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|R300_MS_X4_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|R300_MS_Y4_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|R300_MS_X5_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|R300_MS_Y5_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|R300_MSBD1_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|R300_GA_ENHANCE
value|0x4274
end_define

begin_define
define|#
directive|define
name|R300_GA_DEADLOCK_CNTL
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R300_GA_FASTSYNC_CNTL
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|R300_RB3D_DSTCACHE_CTLSTAT
value|0x4e4c
end_define

begin_define
define|#
directive|define
name|R300_RB3D_DC_FLUSH
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|R300_RB3D_DC_FREE
value|(2<< 2)
end_define

begin_define
define|#
directive|define
name|R300_RB3D_DC_FINISH
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|R300_RB3D_ZCACHE_CTLSTAT
value|0x4f18
end_define

begin_define
define|#
directive|define
name|R300_ZC_FLUSH
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R300_ZC_FREE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|R300_ZC_FLUSH_ALL
value|0x3
end_define

begin_define
define|#
directive|define
name|R400_GB_PIPE_SELECT
value|0x402c
end_define

begin_define
define|#
directive|define
name|R500_DYN_SCLK_PWMEM_PIPE
value|0x000d
end_define

begin_comment
comment|/* PLL */
end_comment

begin_define
define|#
directive|define
name|R500_SU_REG_DEST
value|0x42c8
end_define

begin_define
define|#
directive|define
name|R300_GB_TILE_CONFIG
value|0x4018
end_define

begin_define
define|#
directive|define
name|R300_ENABLE_TILING
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R300_PIPE_COUNT_RV350
value|(0<< 1)
end_define

begin_define
define|#
directive|define
name|R300_PIPE_COUNT_R300
value|(3<< 1)
end_define

begin_define
define|#
directive|define
name|R300_PIPE_COUNT_R420_3P
value|(6<< 1)
end_define

begin_define
define|#
directive|define
name|R300_PIPE_COUNT_R420
value|(7<< 1)
end_define

begin_define
define|#
directive|define
name|R300_TILE_SIZE_8
value|(0<< 4)
end_define

begin_define
define|#
directive|define
name|R300_TILE_SIZE_16
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|R300_TILE_SIZE_32
value|(2<< 4)
end_define

begin_define
define|#
directive|define
name|R300_SUBPIXEL_1_12
value|(0<< 16)
end_define

begin_define
define|#
directive|define
name|R300_SUBPIXEL_1_16
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|R300_DST_PIPE_CONFIG
value|0x170c
end_define

begin_define
define|#
directive|define
name|R300_PIPE_AUTO_CONFIG
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|R300_RB2D_DSTCACHE_MODE
value|0x3428
end_define

begin_define
define|#
directive|define
name|R300_DC_AUTOFLUSH_ENABLE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|R300_DC_DC_DISABLE_IGNORE_PE
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RADEON_CP_STAT
value|0x7C0
end_define

begin_define
define|#
directive|define
name|RADEON_RBBM_CMDFIFO_ADDR
value|0xE70
end_define

begin_define
define|#
directive|define
name|RADEON_RBBM_CMDFIFO_DATA
value|0xE74
end_define

begin_define
define|#
directive|define
name|RADEON_ISYNC_CNTL
value|0x1724
end_define

begin_define
define|#
directive|define
name|RADEON_ISYNC_ANY2D_IDLE3D
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_ISYNC_ANY3D_IDLE2D
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RADEON_ISYNC_TRIG2D_IDLE3D
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RADEON_ISYNC_TRIG3D_IDLE2D
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RADEON_ISYNC_WAIT_IDLEGUI
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_ISYNC_CPSCRATCH_IDLEGUI
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|RS480_NB_MC_INDEX
value|0x168
end_define

begin_define
define|#
directive|define
name|RS480_NB_MC_IND_WR_EN
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|RS480_NB_MC_DATA
value|0x16c
end_define

begin_comment
comment|/*  * RS690  */
end_comment

begin_define
define|#
directive|define
name|RS690_MCCFG_FB_LOCATION
value|0x100
end_define

begin_define
define|#
directive|define
name|RS690_MC_FB_START_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|RS690_MC_FB_START_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RS690_MC_FB_TOP_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|RS690_MC_FB_TOP_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RS690_MCCFG_AGP_LOCATION
value|0x101
end_define

begin_define
define|#
directive|define
name|RS690_MC_AGP_START_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|RS690_MC_AGP_START_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RS690_MC_AGP_TOP_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|RS690_MC_AGP_TOP_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RS690_MCCFG_AGP_BASE
value|0x102
end_define

begin_define
define|#
directive|define
name|RS690_MCCFG_AGP_BASE_2
value|0x103
end_define

begin_define
define|#
directive|define
name|RS690_MC_INIT_MISC_LAT_TIMER
value|0x104
end_define

begin_define
define|#
directive|define
name|RS690_HDP_FB_LOCATION
value|0x0134
end_define

begin_define
define|#
directive|define
name|RS690_MC_INDEX
value|0x78
end_define

begin_define
define|#
directive|define
name|RS690_MC_INDEX_MASK
value|0x1ff
end_define

begin_define
define|#
directive|define
name|RS690_MC_INDEX_WR_EN
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|RS690_MC_INDEX_WR_ACK
value|0x7f
end_define

begin_define
define|#
directive|define
name|RS690_MC_NB_CNTL
value|0x0
end_define

begin_define
define|#
directive|define
name|RS690_HIDE_MMCFG_BAR
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RS690_AGPMODE30
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|RS690_AGP30ENHANCED
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|RS690_MC_DATA
value|0x7c
end_define

begin_define
define|#
directive|define
name|RS690_MC_STATUS
value|0x90
end_define

begin_define
define|#
directive|define
name|RS690_MC_STATUS_IDLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RS480_AGP_BASE_2
value|0x0164
end_define

begin_define
define|#
directive|define
name|RS480_MC_MISC_CNTL
value|0x18
end_define

begin_define
define|#
directive|define
name|RS480_DISABLE_GTW
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RS480_GART_INDEX_REG_EN
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|RS690_BLOCK_GFX_D3_EN
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|RS480_GART_FEATURE_ID
value|0x2b
end_define

begin_define
define|#
directive|define
name|RS480_HANG_EN
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|RS480_TLB_ENABLE
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RS480_P2P_ENABLE
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|RS480_GTW_LAC_EN
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|RS480_2LEVEL_GART
value|(0<< 30)
end_define

begin_define
define|#
directive|define
name|RS480_1LEVEL_GART
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|RS480_PDC_EN
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|RS480_GART_BASE
value|0x2c
end_define

begin_define
define|#
directive|define
name|RS480_GART_CACHE_CNTRL
value|0x2e
end_define

begin_define
define|#
directive|define
name|RS480_GART_CACHE_INVALIDATE
value|(1<< 0)
end_define

begin_comment
comment|/* wait for it to clear */
end_comment

begin_define
define|#
directive|define
name|RS480_AGP_ADDRESS_SPACE_SIZE
value|0x38
end_define

begin_define
define|#
directive|define
name|RS480_GART_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RS480_VA_SIZE_32MB
value|(0<< 1)
end_define

begin_define
define|#
directive|define
name|RS480_VA_SIZE_64MB
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RS480_VA_SIZE_128MB
value|(2<< 1)
end_define

begin_define
define|#
directive|define
name|RS480_VA_SIZE_256MB
value|(3<< 1)
end_define

begin_define
define|#
directive|define
name|RS480_VA_SIZE_512MB
value|(4<< 1)
end_define

begin_define
define|#
directive|define
name|RS480_VA_SIZE_1GB
value|(5<< 1)
end_define

begin_define
define|#
directive|define
name|RS480_VA_SIZE_2GB
value|(6<< 1)
end_define

begin_define
define|#
directive|define
name|RS480_AGP_MODE_CNTL
value|0x39
end_define

begin_define
define|#
directive|define
name|RS480_POST_GART_Q_SIZE
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RS480_NONGART_SNOOP
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|RS480_AGP_RD_BUF_SIZE
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|RS480_REQ_TYPE_SNOOP_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|RS480_REQ_TYPE_SNOOP_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|RS480_REQ_TYPE_SNOOP_DIS
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|RS690_AIC_CTRL_SCRATCH
value|0x3A
end_define

begin_define
define|#
directive|define
name|RS690_DIS_OUT_OF_PCI_GART_ACCESS
value|(1<< 1)
end_define

begin_comment
comment|/*  * RS600  */
end_comment

begin_define
define|#
directive|define
name|RS600_MC_STATUS
value|0x0
end_define

begin_define
define|#
directive|define
name|RS600_MC_STATUS_IDLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RS600_MC_INDEX
value|0x70
end_define

begin_define
define|#
directive|define
name|RS600_MC_ADDR_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|RS600_MC_IND_SEQ_RBS_0
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RS600_MC_IND_SEQ_RBS_1
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RS600_MC_IND_SEQ_RBS_2
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RS600_MC_IND_SEQ_RBS_3
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|RS600_MC_IND_AIC_RBS
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|RS600_MC_IND_CITF_ARB0
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|RS600_MC_IND_CITF_ARB1
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|RS600_MC_IND_WR_EN
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|RS600_MC_DATA
value|0x74
end_define

begin_define
define|#
directive|define
name|RS600_MC_STATUS
value|0x0
end_define

begin_define
define|#
directive|define
name|RS600_MC_IDLE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RS600_MC_FB_LOCATION
value|0x4
end_define

begin_define
define|#
directive|define
name|RS600_MC_FB_START_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|RS600_MC_FB_START_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RS600_MC_FB_TOP_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|RS600_MC_FB_TOP_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RS600_MC_AGP_LOCATION
value|0x5
end_define

begin_define
define|#
directive|define
name|RS600_MC_AGP_START_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|RS600_MC_AGP_START_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RS600_MC_AGP_TOP_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|RS600_MC_AGP_TOP_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RS600_MC_AGP_BASE
value|0x6
end_define

begin_define
define|#
directive|define
name|RS600_MC_AGP_BASE_2
value|0x7
end_define

begin_define
define|#
directive|define
name|RS600_MC_CNTL1
value|0x9
end_define

begin_define
define|#
directive|define
name|RS600_ENABLE_PAGE_TABLES
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|RS600_MC_PT0_CNTL
value|0x100
end_define

begin_define
define|#
directive|define
name|RS600_ENABLE_PT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RS600_EFFECTIVE_L2_CACHE_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 15)
end_define

begin_define
define|#
directive|define
name|RS600_EFFECTIVE_L2_QUEUE_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 21)
end_define

begin_define
define|#
directive|define
name|RS600_INVALIDATE_ALL_L1_TLBS
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|RS600_INVALIDATE_L2_CACHE
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|RS600_MC_PT0_CONTEXT0_CNTL
value|0x102
end_define

begin_define
define|#
directive|define
name|RS600_ENABLE_PAGE_TABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RS600_PAGE_TABLE_TYPE_FLAT
value|(0<< 1)
end_define

begin_define
define|#
directive|define
name|RS600_MC_PT0_SYSTEM_APERTURE_LOW_ADDR
value|0x112
end_define

begin_define
define|#
directive|define
name|RS600_MC_PT0_SYSTEM_APERTURE_HIGH_ADDR
value|0x114
end_define

begin_define
define|#
directive|define
name|RS600_MC_PT0_CONTEXT0_DEFAULT_READ_ADDR
value|0x11c
end_define

begin_define
define|#
directive|define
name|RS600_MC_PT0_CONTEXT0_FLAT_BASE_ADDR
value|0x12c
end_define

begin_define
define|#
directive|define
name|RS600_MC_PT0_CONTEXT0_FLAT_START_ADDR
value|0x13c
end_define

begin_define
define|#
directive|define
name|RS600_MC_PT0_CONTEXT0_FLAT_END_ADDR
value|0x14c
end_define

begin_define
define|#
directive|define
name|RS600_MC_PT0_CLIENT0_CNTL
value|0x16c
end_define

begin_define
define|#
directive|define
name|RS600_ENABLE_TRANSLATION_MODE_OVERRIDE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RS600_TRANSLATION_MODE_OVERRIDE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RS600_SYSTEM_ACCESS_MODE_MASK
value|(3<< 8)
end_define

begin_define
define|#
directive|define
name|RS600_SYSTEM_ACCESS_MODE_PA_ONLY
value|(0<< 8)
end_define

begin_define
define|#
directive|define
name|RS600_SYSTEM_ACCESS_MODE_USE_SYS_MAP
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|RS600_SYSTEM_ACCESS_MODE_IN_SYS
value|(2<< 8)
end_define

begin_define
define|#
directive|define
name|RS600_SYSTEM_ACCESS_MODE_NOT_IN_SYS
value|(3<< 8)
end_define

begin_define
define|#
directive|define
name|RS600_SYSTEM_APERTURE_UNMAPPED_ACCESS_PASSTHROUGH
value|(0<< 10)
end_define

begin_define
define|#
directive|define
name|RS600_SYSTEM_APERTURE_UNMAPPED_ACCESS_DEFAULT_PAGE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|RS600_EFFECTIVE_L1_CACHE_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 11)
end_define

begin_define
define|#
directive|define
name|RS600_ENABLE_FRAGMENT_PROCESSING
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|RS600_EFFECTIVE_L1_QUEUE_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 15)
end_define

begin_define
define|#
directive|define
name|RS600_INVALIDATE_L1_TLB
value|(1<< 20)
end_define

begin_comment
comment|/* rs600/rs690/rs740 */
end_comment

begin_define
define|#
directive|define
name|RS600_BUS_MASTER_DIS
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|RS600_MSI_REARM
value|(1<< 20)
end_define

begin_comment
comment|/* see RS400_MSI_REARM in AIC_CNTL for rs480 */
end_comment

begin_define
define|#
directive|define
name|RV515_MC_FB_LOCATION
value|0x01
end_define

begin_define
define|#
directive|define
name|RV515_MC_FB_START_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|RV515_MC_FB_START_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RV515_MC_FB_TOP_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|RV515_MC_FB_TOP_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RV515_MC_AGP_LOCATION
value|0x02
end_define

begin_define
define|#
directive|define
name|RV515_MC_AGP_START_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|RV515_MC_AGP_START_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RV515_MC_AGP_TOP_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|RV515_MC_AGP_TOP_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RV515_MC_AGP_BASE
value|0x03
end_define

begin_define
define|#
directive|define
name|RV515_MC_AGP_BASE_2
value|0x04
end_define

begin_define
define|#
directive|define
name|R520_MC_FB_LOCATION
value|0x04
end_define

begin_define
define|#
directive|define
name|R520_MC_FB_START_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|R520_MC_FB_START_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R520_MC_FB_TOP_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|R520_MC_FB_TOP_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|R520_MC_AGP_LOCATION
value|0x05
end_define

begin_define
define|#
directive|define
name|R520_MC_AGP_START_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|R520_MC_AGP_START_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R520_MC_AGP_TOP_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|R520_MC_AGP_TOP_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|R520_MC_AGP_BASE
value|0x06
end_define

begin_define
define|#
directive|define
name|R520_MC_AGP_BASE_2
value|0x07
end_define

begin_define
define|#
directive|define
name|AVIVO_MC_INDEX
value|0x0070
end_define

begin_define
define|#
directive|define
name|R520_MC_STATUS
value|0x00
end_define

begin_define
define|#
directive|define
name|R520_MC_STATUS_IDLE
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|RV515_MC_STATUS
value|0x08
end_define

begin_define
define|#
directive|define
name|RV515_MC_STATUS_IDLE
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|RV515_MC_INIT_MISC_LAT_TIMER
value|0x09
end_define

begin_define
define|#
directive|define
name|AVIVO_MC_DATA
value|0x0074
end_define

begin_define
define|#
directive|define
name|R520_MC_IND_INDEX
value|0x70
end_define

begin_define
define|#
directive|define
name|R520_MC_IND_WR_EN
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|R520_MC_IND_DATA
value|0x74
end_define

begin_define
define|#
directive|define
name|RV515_MC_CNTL
value|0x5
end_define

begin_define
define|#
directive|define
name|RV515_MEM_NUM_CHANNELS_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|R520_MC_CNTL0
value|0x8
end_define

begin_define
define|#
directive|define
name|R520_MEM_NUM_CHANNELS_MASK
value|(0x3<< 24)
end_define

begin_define
define|#
directive|define
name|R520_MEM_NUM_CHANNELS_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|R520_MC_CHANNEL_SIZE
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|AVIVO_CP_DYN_CNTL
value|0x000f
end_define

begin_comment
comment|/* PLL */
end_comment

begin_define
define|#
directive|define
name|AVIVO_CP_FORCEON
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_E2_DYN_CNTL
value|0x0011
end_define

begin_comment
comment|/* PLL */
end_comment

begin_define
define|#
directive|define
name|AVIVO_E2_FORCEON
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_IDCT_DYN_CNTL
value|0x0013
end_define

begin_comment
comment|/* PLL */
end_comment

begin_define
define|#
directive|define
name|AVIVO_IDCT_FORCEON
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_HDP_FB_LOCATION
value|0x134
end_define

begin_define
define|#
directive|define
name|AVIVO_VGA_RENDER_CONTROL
value|0x0300
end_define

begin_define
define|#
directive|define
name|AVIVO_VGA_VSTATUS_CNTL_MASK
value|(3<< 16)
end_define

begin_define
define|#
directive|define
name|AVIVO_D1VGA_CONTROL
value|0x0330
end_define

begin_define
define|#
directive|define
name|AVIVO_DVGA_CONTROL_MODE_ENABLE
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|AVIVO_DVGA_CONTROL_TIMING_SELECT
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|AVIVO_DVGA_CONTROL_SYNC_POLARITY_SELECT
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|AVIVO_DVGA_CONTROL_OVERSCAN_TIMING_SELECT
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|AVIVO_DVGA_CONTROL_OVERSCAN_COLOR_EN
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|AVIVO_DVGA_CONTROL_ROTATE
value|(1<<24)
end_define

begin_define
define|#
directive|define
name|AVIVO_D2VGA_CONTROL
value|0x0338
end_define

begin_define
define|#
directive|define
name|AVIVO_EXT1_PPLL_REF_DIV_SRC
value|0x400
end_define

begin_define
define|#
directive|define
name|AVIVO_EXT1_PPLL_REF_DIV
value|0x404
end_define

begin_define
define|#
directive|define
name|AVIVO_EXT1_PPLL_UPDATE_LOCK
value|0x408
end_define

begin_define
define|#
directive|define
name|AVIVO_EXT1_PPLL_UPDATE_CNTL
value|0x40c
end_define

begin_define
define|#
directive|define
name|AVIVO_EXT2_PPLL_REF_DIV_SRC
value|0x410
end_define

begin_define
define|#
directive|define
name|AVIVO_EXT2_PPLL_REF_DIV
value|0x414
end_define

begin_define
define|#
directive|define
name|AVIVO_EXT2_PPLL_UPDATE_LOCK
value|0x418
end_define

begin_define
define|#
directive|define
name|AVIVO_EXT2_PPLL_UPDATE_CNTL
value|0x41c
end_define

begin_define
define|#
directive|define
name|AVIVO_EXT1_PPLL_FB_DIV
value|0x430
end_define

begin_define
define|#
directive|define
name|AVIVO_EXT2_PPLL_FB_DIV
value|0x434
end_define

begin_define
define|#
directive|define
name|AVIVO_EXT1_PPLL_POST_DIV_SRC
value|0x438
end_define

begin_define
define|#
directive|define
name|AVIVO_EXT1_PPLL_POST_DIV
value|0x43c
end_define

begin_define
define|#
directive|define
name|AVIVO_EXT2_PPLL_POST_DIV_SRC
value|0x440
end_define

begin_define
define|#
directive|define
name|AVIVO_EXT2_PPLL_POST_DIV
value|0x444
end_define

begin_define
define|#
directive|define
name|AVIVO_EXT1_PPLL_CNTL
value|0x448
end_define

begin_define
define|#
directive|define
name|AVIVO_EXT2_PPLL_CNTL
value|0x44c
end_define

begin_define
define|#
directive|define
name|AVIVO_P1PLL_CNTL
value|0x450
end_define

begin_define
define|#
directive|define
name|AVIVO_P2PLL_CNTL
value|0x454
end_define

begin_define
define|#
directive|define
name|AVIVO_P1PLL_INT_SS_CNTL
value|0x458
end_define

begin_define
define|#
directive|define
name|AVIVO_P2PLL_INT_SS_CNTL
value|0x45c
end_define

begin_define
define|#
directive|define
name|AVIVO_P1PLL_TMDSA_CNTL
value|0x460
end_define

begin_define
define|#
directive|define
name|AVIVO_P2PLL_LVTMA_CNTL
value|0x464
end_define

begin_define
define|#
directive|define
name|AVIVO_PCLK_CRTC1_CNTL
value|0x480
end_define

begin_define
define|#
directive|define
name|AVIVO_PCLK_CRTC2_CNTL
value|0x484
end_define

begin_define
define|#
directive|define
name|AVIVO_D1CRTC_H_TOTAL
value|0x6000
end_define

begin_define
define|#
directive|define
name|AVIVO_D1CRTC_H_BLANK_START_END
value|0x6004
end_define

begin_define
define|#
directive|define
name|AVIVO_D1CRTC_H_SYNC_A
value|0x6008
end_define

begin_define
define|#
directive|define
name|AVIVO_D1CRTC_H_SYNC_A_CNTL
value|0x600c
end_define

begin_define
define|#
directive|define
name|AVIVO_D1CRTC_H_SYNC_B
value|0x6010
end_define

begin_define
define|#
directive|define
name|AVIVO_D1CRTC_H_SYNC_B_CNTL
value|0x6014
end_define

begin_define
define|#
directive|define
name|AVIVO_D1CRTC_V_TOTAL
value|0x6020
end_define

begin_define
define|#
directive|define
name|AVIVO_D1CRTC_V_BLANK_START_END
value|0x6024
end_define

begin_define
define|#
directive|define
name|AVIVO_D1CRTC_V_SYNC_A
value|0x6028
end_define

begin_define
define|#
directive|define
name|AVIVO_D1CRTC_V_SYNC_A_CNTL
value|0x602c
end_define

begin_define
define|#
directive|define
name|AVIVO_D1CRTC_V_SYNC_B
value|0x6030
end_define

begin_define
define|#
directive|define
name|AVIVO_D1CRTC_V_SYNC_B_CNTL
value|0x6034
end_define

begin_define
define|#
directive|define
name|AVIVO_D1CRTC_CONTROL
value|0x6080
end_define

begin_define
define|#
directive|define
name|AVIVO_CRTC_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_CRTC_DISP_READ_REQUEST_DISABLE
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|AVIVO_D1CRTC_BLANK_CONTROL
value|0x6084
end_define

begin_define
define|#
directive|define
name|AVIVO_D1CRTC_INTERLACE_CONTROL
value|0x6088
end_define

begin_define
define|#
directive|define
name|AVIVO_D1CRTC_INTERLACE_STATUS
value|0x608c
end_define

begin_define
define|#
directive|define
name|AVIVO_D1CRTC_STATUS
value|0x609c
end_define

begin_define
define|#
directive|define
name|AVIVO_D1CRTC_V_BLANK
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_D1CRTC_STATUS_POSITION
value|0x60a0
end_define

begin_define
define|#
directive|define
name|AVIVO_D1CRTC_FRAME_COUNT
value|0x60a4
end_define

begin_define
define|#
directive|define
name|AVIVO_D1CRTC_STEREO_CONTROL
value|0x60c4
end_define

begin_define
define|#
directive|define
name|AVIVO_D1MODE_MASTER_UPDATE_MODE
value|0x60e4
end_define

begin_comment
comment|/* master controls */
end_comment

begin_define
define|#
directive|define
name|AVIVO_DC_CRTC_MASTER_EN
value|0x60f8
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_CRTC_TV_CONTROL
value|0x60fc
end_define

begin_define
define|#
directive|define
name|AVIVO_D1GRPH_ENABLE
value|0x6100
end_define

begin_define
define|#
directive|define
name|AVIVO_D1GRPH_CONTROL
value|0x6104
end_define

begin_define
define|#
directive|define
name|AVIVO_D1GRPH_CONTROL_DEPTH_8BPP
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_D1GRPH_CONTROL_DEPTH_16BPP
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_D1GRPH_CONTROL_DEPTH_32BPP
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_D1GRPH_CONTROL_DEPTH_64BPP
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_D1GRPH_CONTROL_8BPP_INDEXED
value|(0<< 8)
end_define

begin_define
define|#
directive|define
name|AVIVO_D1GRPH_CONTROL_16BPP_ARGB1555
value|(0<< 8)
end_define

begin_define
define|#
directive|define
name|AVIVO_D1GRPH_CONTROL_16BPP_RGB565
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AVIVO_D1GRPH_CONTROL_16BPP_ARGB4444
value|(2<< 8)
end_define

begin_define
define|#
directive|define
name|AVIVO_D1GRPH_CONTROL_16BPP_AI88
value|(3<< 8)
end_define

begin_define
define|#
directive|define
name|AVIVO_D1GRPH_CONTROL_16BPP_MONO16
value|(4<< 8)
end_define

begin_define
define|#
directive|define
name|AVIVO_D1GRPH_CONTROL_32BPP_ARGB8888
value|(0<< 8)
end_define

begin_define
define|#
directive|define
name|AVIVO_D1GRPH_CONTROL_32BPP_ARGB2101010
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AVIVO_D1GRPH_CONTROL_32BPP_DIGITAL
value|(2<< 8)
end_define

begin_define
define|#
directive|define
name|AVIVO_D1GRPH_CONTROL_32BPP_8B_ARGB2101010
value|(3<< 8)
end_define

begin_define
define|#
directive|define
name|AVIVO_D1GRPH_CONTROL_64BPP_ARGB16161616
value|(0<< 8)
end_define

begin_define
define|#
directive|define
name|AVIVO_D1GRPH_SWAP_RB
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AVIVO_D1GRPH_TILED
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|AVIVO_D1GRPH_MACRO_ADDRESS_MODE
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|R600_D1GRPH_ARRAY_MODE_LINEAR_GENERAL
value|(0<< 20)
end_define

begin_define
define|#
directive|define
name|R600_D1GRPH_ARRAY_MODE_LINEAR_ALIGNED
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|R600_D1GRPH_ARRAY_MODE_1D_TILED_THIN1
value|(2<< 20)
end_define

begin_define
define|#
directive|define
name|R600_D1GRPH_ARRAY_MODE_2D_TILED_THIN1
value|(4<< 20)
end_define

begin_comment
comment|/* The R7xx *_HIGH surface regs are backwards; the D1 regs are in the D2  * block and vice versa.  This applies to GRPH, CUR, etc.  */
end_comment

begin_define
define|#
directive|define
name|AVIVO_D1GRPH_LUT_SEL
value|0x6108
end_define

begin_define
define|#
directive|define
name|AVIVO_D1GRPH_PRIMARY_SURFACE_ADDRESS
value|0x6110
end_define

begin_define
define|#
directive|define
name|R700_D1GRPH_PRIMARY_SURFACE_ADDRESS_HIGH
value|0x6914
end_define

begin_define
define|#
directive|define
name|R700_D2GRPH_PRIMARY_SURFACE_ADDRESS_HIGH
value|0x6114
end_define

begin_define
define|#
directive|define
name|AVIVO_D1GRPH_SECONDARY_SURFACE_ADDRESS
value|0x6118
end_define

begin_define
define|#
directive|define
name|R700_D1GRPH_SECONDARY_SURFACE_ADDRESS_HIGH
value|0x691c
end_define

begin_define
define|#
directive|define
name|R700_D2GRPH_SECONDARY_SURFACE_ADDRESS_HIGH
value|0x611c
end_define

begin_define
define|#
directive|define
name|AVIVO_D1GRPH_PITCH
value|0x6120
end_define

begin_define
define|#
directive|define
name|AVIVO_D1GRPH_SURFACE_OFFSET_X
value|0x6124
end_define

begin_define
define|#
directive|define
name|AVIVO_D1GRPH_SURFACE_OFFSET_Y
value|0x6128
end_define

begin_define
define|#
directive|define
name|AVIVO_D1GRPH_X_START
value|0x612c
end_define

begin_define
define|#
directive|define
name|AVIVO_D1GRPH_Y_START
value|0x6130
end_define

begin_define
define|#
directive|define
name|AVIVO_D1GRPH_X_END
value|0x6134
end_define

begin_define
define|#
directive|define
name|AVIVO_D1GRPH_Y_END
value|0x6138
end_define

begin_define
define|#
directive|define
name|AVIVO_D1GRPH_UPDATE
value|0x6144
end_define

begin_define
define|#
directive|define
name|AVIVO_D1GRPH_SURFACE_UPDATE_PENDING
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AVIVO_D1GRPH_UPDATE_LOCK
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AVIVO_D1GRPH_FLIP_CONTROL
value|0x6148
end_define

begin_define
define|#
directive|define
name|AVIVO_D1GRPH_SURFACE_UPDATE_H_RETRACE_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_D1CUR_CONTROL
value|0x6400
end_define

begin_define
define|#
directive|define
name|AVIVO_D1CURSOR_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_D1CURSOR_MODE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|AVIVO_D1CURSOR_MODE_MASK
value|(3<< 8)
end_define

begin_define
define|#
directive|define
name|AVIVO_D1CURSOR_MODE_24BPP
value|2
end_define

begin_define
define|#
directive|define
name|AVIVO_D1CUR_SURFACE_ADDRESS
value|0x6408
end_define

begin_define
define|#
directive|define
name|R700_D1CUR_SURFACE_ADDRESS_HIGH
value|0x6c0c
end_define

begin_define
define|#
directive|define
name|R700_D2CUR_SURFACE_ADDRESS_HIGH
value|0x640c
end_define

begin_define
define|#
directive|define
name|AVIVO_D1CUR_SIZE
value|0x6410
end_define

begin_define
define|#
directive|define
name|AVIVO_D1CUR_POSITION
value|0x6414
end_define

begin_define
define|#
directive|define
name|AVIVO_D1CUR_HOT_SPOT
value|0x6418
end_define

begin_define
define|#
directive|define
name|AVIVO_D1CUR_UPDATE
value|0x6424
end_define

begin_define
define|#
directive|define
name|AVIVO_D1CURSOR_UPDATE_LOCK
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_LUT_RW_SELECT
value|0x6480
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_LUT_RW_MODE
value|0x6484
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_LUT_RW_INDEX
value|0x6488
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_LUT_SEQ_COLOR
value|0x648c
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_LUT_PWL_DATA
value|0x6490
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_LUT_30_COLOR
value|0x6494
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_LUT_READ_PIPE_SELECT
value|0x6498
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_LUT_WRITE_EN_MASK
value|0x649c
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_LUT_AUTOFILL
value|0x64a0
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_LUTA_CONTROL
value|0x64c0
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_LUTA_BLACK_OFFSET_BLUE
value|0x64c4
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_LUTA_BLACK_OFFSET_GREEN
value|0x64c8
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_LUTA_BLACK_OFFSET_RED
value|0x64cc
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_LUTA_WHITE_OFFSET_BLUE
value|0x64d0
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_LUTA_WHITE_OFFSET_GREEN
value|0x64d4
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_LUTA_WHITE_OFFSET_RED
value|0x64d8
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_LB_MEMORY_SPLIT
value|0x6520
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_LB_MEMORY_SPLIT_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_LB_MEMORY_SPLIT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_LB_MEMORY_SPLIT_D1HALF_D2HALF
value|0
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_LB_MEMORY_SPLIT_D1_3Q_D2_1Q
value|1
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_LB_MEMORY_SPLIT_D1_ONLY
value|2
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_LB_MEMORY_SPLIT_D1_1Q_D2_3Q
value|3
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_LB_MEMORY_SPLIT_SHIFT_MODE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_LB_DISP1_END_ADR_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_LB_DISP1_END_ADR_MASK
value|0x7ff
end_define

begin_define
define|#
directive|define
name|AVIVO_D1MODE_DATA_FORMAT
value|0x6528
end_define

begin_define
define|#
directive|define
name|AVIVO_D1MODE_INTERLEAVE_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_D1MODE_DESKTOP_HEIGHT
value|0x652C
end_define

begin_define
define|#
directive|define
name|AVIVO_D1MODE_VBLANK_STATUS
value|0x6534
end_define

begin_define
define|#
directive|define
name|AVIVO_VBLANK_ACK
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AVIVO_D1MODE_VLINE_START_END
value|0x6538
end_define

begin_define
define|#
directive|define
name|AVIVO_D1MODE_VLINE_STATUS
value|0x653c
end_define

begin_define
define|#
directive|define
name|AVIVO_D1MODE_VLINE_STAT
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|AVIVO_DxMODE_INT_MASK
value|0x6540
end_define

begin_define
define|#
directive|define
name|AVIVO_D1MODE_INT_MASK
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_D2MODE_INT_MASK
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AVIVO_D1MODE_VIEWPORT_START
value|0x6580
end_define

begin_define
define|#
directive|define
name|AVIVO_D1MODE_VIEWPORT_SIZE
value|0x6584
end_define

begin_define
define|#
directive|define
name|AVIVO_D1MODE_EXT_OVERSCAN_LEFT_RIGHT
value|0x6588
end_define

begin_define
define|#
directive|define
name|AVIVO_D1MODE_EXT_OVERSCAN_TOP_BOTTOM
value|0x658c
end_define

begin_define
define|#
directive|define
name|AVIVO_D1SCL_SCALER_ENABLE
value|0x6590
end_define

begin_define
define|#
directive|define
name|AVIVO_D1SCL_SCALER_TAP_CONTROL
value|0x6594
end_define

begin_define
define|#
directive|define
name|AVIVO_D1SCL_UPDATE
value|0x65cc
end_define

begin_define
define|#
directive|define
name|AVIVO_D1SCL_UPDATE_LOCK
value|(1<< 16)
end_define

begin_comment
comment|/* second crtc */
end_comment

begin_define
define|#
directive|define
name|AVIVO_D2CRTC_H_TOTAL
value|0x6800
end_define

begin_define
define|#
directive|define
name|AVIVO_D2CRTC_H_BLANK_START_END
value|0x6804
end_define

begin_define
define|#
directive|define
name|AVIVO_D2CRTC_H_SYNC_A
value|0x6808
end_define

begin_define
define|#
directive|define
name|AVIVO_D2CRTC_H_SYNC_A_CNTL
value|0x680c
end_define

begin_define
define|#
directive|define
name|AVIVO_D2CRTC_H_SYNC_B
value|0x6810
end_define

begin_define
define|#
directive|define
name|AVIVO_D2CRTC_H_SYNC_B_CNTL
value|0x6814
end_define

begin_define
define|#
directive|define
name|AVIVO_D2CRTC_V_TOTAL
value|0x6820
end_define

begin_define
define|#
directive|define
name|AVIVO_D2CRTC_V_BLANK_START_END
value|0x6824
end_define

begin_define
define|#
directive|define
name|AVIVO_D2CRTC_V_SYNC_A
value|0x6828
end_define

begin_define
define|#
directive|define
name|AVIVO_D2CRTC_V_SYNC_A_CNTL
value|0x682c
end_define

begin_define
define|#
directive|define
name|AVIVO_D2CRTC_V_SYNC_B
value|0x6830
end_define

begin_define
define|#
directive|define
name|AVIVO_D2CRTC_V_SYNC_B_CNTL
value|0x6834
end_define

begin_define
define|#
directive|define
name|AVIVO_D2CRTC_CONTROL
value|0x6880
end_define

begin_define
define|#
directive|define
name|AVIVO_D2CRTC_BLANK_CONTROL
value|0x6884
end_define

begin_define
define|#
directive|define
name|AVIVO_D2CRTC_INTERLACE_CONTROL
value|0x6888
end_define

begin_define
define|#
directive|define
name|AVIVO_D2CRTC_INTERLACE_STATUS
value|0x688c
end_define

begin_define
define|#
directive|define
name|AVIVO_D2CRTC_STATUS_POSITION
value|0x68a0
end_define

begin_define
define|#
directive|define
name|AVIVO_D2CRTC_FRAME_COUNT
value|0x68a4
end_define

begin_define
define|#
directive|define
name|AVIVO_D2CRTC_STEREO_CONTROL
value|0x68c4
end_define

begin_define
define|#
directive|define
name|AVIVO_D2GRPH_ENABLE
value|0x6900
end_define

begin_define
define|#
directive|define
name|AVIVO_D2GRPH_CONTROL
value|0x6904
end_define

begin_define
define|#
directive|define
name|AVIVO_D2GRPH_LUT_SEL
value|0x6908
end_define

begin_define
define|#
directive|define
name|AVIVO_D2GRPH_PRIMARY_SURFACE_ADDRESS
value|0x6910
end_define

begin_define
define|#
directive|define
name|AVIVO_D2GRPH_SECONDARY_SURFACE_ADDRESS
value|0x6918
end_define

begin_define
define|#
directive|define
name|AVIVO_D2GRPH_PITCH
value|0x6920
end_define

begin_define
define|#
directive|define
name|AVIVO_D2GRPH_SURFACE_OFFSET_X
value|0x6924
end_define

begin_define
define|#
directive|define
name|AVIVO_D2GRPH_SURFACE_OFFSET_Y
value|0x6928
end_define

begin_define
define|#
directive|define
name|AVIVO_D2GRPH_X_START
value|0x692c
end_define

begin_define
define|#
directive|define
name|AVIVO_D2GRPH_Y_START
value|0x6930
end_define

begin_define
define|#
directive|define
name|AVIVO_D2GRPH_X_END
value|0x6934
end_define

begin_define
define|#
directive|define
name|AVIVO_D2GRPH_Y_END
value|0x6938
end_define

begin_define
define|#
directive|define
name|AVIVO_D2GRPH_UPDATE
value|0x6944
end_define

begin_define
define|#
directive|define
name|AVIVO_D2GRPH_FLIP_CONTROL
value|0x6948
end_define

begin_define
define|#
directive|define
name|AVIVO_D2CUR_CONTROL
value|0x6c00
end_define

begin_define
define|#
directive|define
name|AVIVO_D2CUR_SURFACE_ADDRESS
value|0x6c08
end_define

begin_define
define|#
directive|define
name|AVIVO_D2CUR_SIZE
value|0x6c10
end_define

begin_define
define|#
directive|define
name|AVIVO_D2CUR_POSITION
value|0x6c14
end_define

begin_define
define|#
directive|define
name|AVIVO_D2MODE_VBLANK_STATUS
value|0x6d34
end_define

begin_define
define|#
directive|define
name|AVIVO_D2MODE_VLINE_START_END
value|0x6d38
end_define

begin_define
define|#
directive|define
name|AVIVO_D2MODE_VLINE_STATUS
value|0x6d3c
end_define

begin_define
define|#
directive|define
name|AVIVO_D2MODE_VIEWPORT_START
value|0x6d80
end_define

begin_define
define|#
directive|define
name|AVIVO_D2MODE_VIEWPORT_SIZE
value|0x6d84
end_define

begin_define
define|#
directive|define
name|AVIVO_D2MODE_EXT_OVERSCAN_LEFT_RIGHT
value|0x6d88
end_define

begin_define
define|#
directive|define
name|AVIVO_D2MODE_EXT_OVERSCAN_TOP_BOTTOM
value|0x6d8c
end_define

begin_define
define|#
directive|define
name|AVIVO_D2SCL_SCALER_ENABLE
value|0x6d90
end_define

begin_define
define|#
directive|define
name|AVIVO_D2SCL_SCALER_TAP_CONTROL
value|0x6d94
end_define

begin_define
define|#
directive|define
name|AVIVO_DDIA_BIT_DEPTH_CONTROL
value|0x7214
end_define

begin_define
define|#
directive|define
name|AVIVO_DACA_ENABLE
value|0x7800
end_define

begin_define
define|#
directive|define
name|AVIVO_DAC_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_DACA_SOURCE_SELECT
value|0x7804
end_define

begin_define
define|#
directive|define
name|AVIVO_DAC_SOURCE_CRTC1
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_DAC_SOURCE_CRTC2
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_DAC_SOURCE_TV
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_DACA_FORCE_OUTPUT_CNTL
value|0x783c
end_define

begin_define
define|#
directive|define
name|AVIVO_DACA_FORCE_OUTPUT_CNTL_FORCE_DATA_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_DACA_FORCE_OUTPUT_CNTL_DATA_SEL_SHIFT
value|(8)
end_define

begin_define
define|#
directive|define
name|AVIVO_DACA_FORCE_OUTPUT_CNTL_DATA_SEL_BLUE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_DACA_FORCE_OUTPUT_CNTL_DATA_SEL_GREEN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AVIVO_DACA_FORCE_OUTPUT_CNTL_DATA_SEL_RED
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AVIVO_DACA_FORCE_OUTPUT_CNTL_DATA_ON_BLANKB_ONLY
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|AVIVO_DACA_POWERDOWN
value|0x7850
end_define

begin_define
define|#
directive|define
name|AVIVO_DACA_POWERDOWN_POWERDOWN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_DACA_POWERDOWN_BLUE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AVIVO_DACA_POWERDOWN_GREEN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AVIVO_DACA_POWERDOWN_RED
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|AVIVO_DACB_ENABLE
value|0x7a00
end_define

begin_define
define|#
directive|define
name|AVIVO_DACB_SOURCE_SELECT
value|0x7a04
end_define

begin_define
define|#
directive|define
name|AVIVO_DACB_FORCE_OUTPUT_CNTL
value|0x7a3c
end_define

begin_define
define|#
directive|define
name|AVIVO_DACB_FORCE_OUTPUT_CNTL_FORCE_DATA_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_DACB_FORCE_OUTPUT_CNTL_DATA_SEL_SHIFT
value|(8)
end_define

begin_define
define|#
directive|define
name|AVIVO_DACB_FORCE_OUTPUT_CNTL_DATA_SEL_BLUE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_DACB_FORCE_OUTPUT_CNTL_DATA_SEL_GREEN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AVIVO_DACB_FORCE_OUTPUT_CNTL_DATA_SEL_RED
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AVIVO_DACB_FORCE_OUTPUT_CNTL_DATA_ON_BLANKB_ONLY
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|AVIVO_DACB_POWERDOWN
value|0x7a50
end_define

begin_define
define|#
directive|define
name|AVIVO_DACB_POWERDOWN_POWERDOWN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_DACB_POWERDOWN_BLUE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AVIVO_DACB_POWERDOWN_GREEN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AVIVO_DACB_POWERDOWN_RED
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_CNTL
value|0x7880
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_CNTL_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_CNTL_HDMI_EN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_CNTL_HPD_MASK
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_CNTL_HPD_SELECT
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_CNTL_SYNC_PHASE
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_CNTL_PIXEL_ENCODING
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_CNTL_DUAL_LINK_ENABLE
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_CNTL_SWAP
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_SOURCE_SELECT
value|0x7884
end_define

begin_comment
comment|/* 78a8 appears to be some kind of (reasonably tolerant) clock?  * 78d0 definitely hits the transmitter, definitely clock. */
end_comment

begin_comment
comment|/* MYSTERY1 This appears to control dithering? */
end_comment

begin_define
define|#
directive|define
name|AVIVO_TMDSA_BIT_DEPTH_CONTROL
value|0x7894
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDS_BIT_DEPTH_CONTROL_TRUNCATE_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDS_BIT_DEPTH_CONTROL_TRUNCATE_DEPTH
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDS_BIT_DEPTH_CONTROL_SPATIAL_DITHER_EN
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDS_BIT_DEPTH_CONTROL_SPATIAL_DITHER_DEPTH
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDS_BIT_DEPTH_CONTROL_TEMPORAL_DITHER_EN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDS_BIT_DEPTH_CONTROL_TEMPORAL_DITHER_DEPTH
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDS_BIT_DEPTH_CONTROL_TEMPORAL_LEVEL
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDS_BIT_DEPTH_CONTROL_TEMPORAL_DITHER_RESET
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_DCBALANCER_CONTROL
value|0x78d0
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_DCBALANCER_CONTROL_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_DCBALANCER_CONTROL_TEST_EN
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_DCBALANCER_CONTROL_TEST_IN_SHIFT
value|(16)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_DCBALANCER_CONTROL_FORCE
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_DATA_SYNCHRONIZATION
value|0x78d8
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_DATA_SYNCHRONIZATION_DSYNSEL
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_DATA_SYNCHRONIZATION_PFREQCHG
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_CLOCK_ENABLE
value|0x7900
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_TRANSMITTER_ENABLE
value|0x7904
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_TRANSMITTER_ENABLE_TX0_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_TRANSMITTER_ENABLE_LNKC0EN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_TRANSMITTER_ENABLE_LNKD00EN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_TRANSMITTER_ENABLE_LNKD01EN
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_TRANSMITTER_ENABLE_LNKD02EN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_TRANSMITTER_ENABLE_TX1_ENABLE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_TRANSMITTER_ENABLE_LNKD10EN
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_TRANSMITTER_ENABLE_LNKD11EN
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_TRANSMITTER_ENABLE_LNKD12EN
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_TRANSMITTER_ENABLE_TX_ENABLE_HPD_MASK
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_TRANSMITTER_ENABLE_LNKCEN_HPD_MASK
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_TRANSMITTER_ENABLE_LNKDEN_HPD_MASK
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_TRANSMITTER_CONTROL
value|0x7910
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_TRANSMITTER_CONTROL_PLL_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_TRANSMITTER_CONTROL_PLL_RESET
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_TRANSMITTER_CONTROL_PLL_HPD_MASK_SHIFT
value|(2)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_TRANSMITTER_CONTROL_IDSCKSEL
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_TRANSMITTER_CONTROL_BGSLEEP
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_TRANSMITTER_CONTROL_PLL_PWRUP_SEQ_EN
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_TRANSMITTER_CONTROL_TMCLK
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_TRANSMITTER_CONTROL_TMCLK_FROM_PADS
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_TRANSMITTER_CONTROL_TDCLK
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_TRANSMITTER_CONTROL_TDCLK_FROM_PADS
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_TRANSMITTER_CONTROL_CLK_PATTERN_SHIFT
value|(16)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_TRANSMITTER_CONTROL_BYPASS_PLL
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_TRANSMITTER_CONTROL_USE_CLK_DATA
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|AVIVO_TMDSA_TRANSMITTER_CONTROL_INPUT_TEST_CLK_SEL
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_CNTL
value|0x7a80
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_CNTL_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_CNTL_HDMI_EN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_CNTL_HPD_MASK
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_CNTL_HPD_SELECT
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_CNTL_SYNC_PHASE
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_CNTL_PIXEL_ENCODING
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_CNTL_DUAL_LINK_ENABLE
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_CNTL_SWAP
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_SOURCE_SELECT
value|0x7a84
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_COLOR_FORMAT
value|0x7a88
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_BIT_DEPTH_CONTROL
value|0x7a94
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_BIT_DEPTH_CONTROL_TRUNCATE_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_BIT_DEPTH_CONTROL_TRUNCATE_DEPTH
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_BIT_DEPTH_CONTROL_SPATIAL_DITHER_EN
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_BIT_DEPTH_CONTROL_SPATIAL_DITHER_DEPTH
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_BIT_DEPTH_CONTROL_TEMPORAL_DITHER_EN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_BIT_DEPTH_CONTROL_TEMPORAL_DITHER_DEPTH
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_BIT_DEPTH_CONTROL_TEMPORAL_LEVEL
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_BIT_DEPTH_CONTROL_TEMPORAL_DITHER_RESET
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_DCBALANCER_CONTROL
value|0x7ad0
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_DCBALANCER_CONTROL_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_DCBALANCER_CONTROL_TEST_EN
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_DCBALANCER_CONTROL_TEST_IN_SHIFT
value|(16)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_DCBALANCER_CONTROL_FORCE
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_DATA_SYNCHRONIZATION
value|0x78d8
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_DATA_SYNCHRONIZATION_DSYNSEL
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_DATA_SYNCHRONIZATION_PFREQCHG
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|R500_LVTMA_CLOCK_ENABLE
value|0x7b00
end_define

begin_define
define|#
directive|define
name|R600_LVTMA_CLOCK_ENABLE
value|0x7b04
end_define

begin_define
define|#
directive|define
name|R500_LVTMA_TRANSMITTER_ENABLE
value|0x7b04
end_define

begin_define
define|#
directive|define
name|R600_LVTMA_TRANSMITTER_ENABLE
value|0x7b08
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_TRANSMITTER_ENABLE_LNKC0EN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_TRANSMITTER_ENABLE_LNKD00EN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_TRANSMITTER_ENABLE_LNKD01EN
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_TRANSMITTER_ENABLE_LNKD02EN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_TRANSMITTER_ENABLE_LNKD03EN
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_TRANSMITTER_ENABLE_LNKC1EN
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_TRANSMITTER_ENABLE_LNKD10EN
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_TRANSMITTER_ENABLE_LNKD11EN
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_TRANSMITTER_ENABLE_LNKD12EN
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_TRANSMITTER_ENABLE_LNKCEN_HPD_MASK
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_TRANSMITTER_ENABLE_LNKDEN_HPD_MASK
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|R500_LVTMA_TRANSMITTER_CONTROL
value|0x7b10
end_define

begin_define
define|#
directive|define
name|R600_LVTMA_TRANSMITTER_CONTROL
value|0x7b14
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_TRANSMITTER_CONTROL_PLL_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_TRANSMITTER_CONTROL_PLL_RESET
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_TRANSMITTER_CONTROL_PLL_HPD_MASK_SHIFT
value|(2)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_TRANSMITTER_CONTROL_IDSCKSEL
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_TRANSMITTER_CONTROL_BGSLEEP
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_TRANSMITTER_CONTROL_PLL_PWRUP_SEQ_EN
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_TRANSMITTER_CONTROL_TMCLK
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_TRANSMITTER_CONTROL_TMCLK_FROM_PADS
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_TRANSMITTER_CONTROL_TDCLK
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_TRANSMITTER_CONTROL_TDCLK_FROM_PADS
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_TRANSMITTER_CONTROL_CLK_PATTERN_SHIFT
value|(16)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_TRANSMITTER_CONTROL_BYPASS_PLL
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_TRANSMITTER_CONTROL_USE_CLK_DATA
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_TRANSMITTER_CONTROL_INPUT_TEST_CLK_SEL
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|R500_LVTMA_PWRSEQ_CNTL
value|0x7af0
end_define

begin_define
define|#
directive|define
name|R600_LVTMA_PWRSEQ_CNTL
value|0x7af4
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_PWRSEQ_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_PWRSEQ_PLL_ENABLE_MASK
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_PWRSEQ_PLL_RESET_MASK
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_PWRSEQ_TARGET_STATE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_SYNCEN
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_SYNCEN_OVRD
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_SYNCEN_POL
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_DIGON
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_DIGON_OVRD
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_DIGON_POL
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_BLON
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_BLON_OVRD
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_BLON_POL
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|R500_LVTMA_PWRSEQ_STATE
value|0x7af4
end_define

begin_define
define|#
directive|define
name|R600_LVTMA_PWRSEQ_STATE
value|0x7af8
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_PWRSEQ_STATE_TARGET_STATE_R
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_PWRSEQ_STATE_DIGON
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_PWRSEQ_STATE_SYNCEN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_PWRSEQ_STATE_BLON
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_PWRSEQ_STATE_DONE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVTMA_PWRSEQ_STATE_STATUS_SHIFT
value|(8)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVDS_BACKLIGHT_CNTL
value|0x7af8
end_define

begin_define
define|#
directive|define
name|AVIVO_LVDS_BACKLIGHT_CNTL_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_LVDS_BACKLIGHT_LEVEL_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|AVIVO_LVDS_BACKLIGHT_LEVEL_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|AVIVO_DVOA_BIT_DEPTH_CONTROL
value|0x7988
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_GPIO_HPD_A
value|0x7e94
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_GPIO_HPD_Y
value|0x7e9c
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_STATUS1
value|0x7d30
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_DONE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_NACK
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_HALT
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_GO
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_RESET
value|0x7d34
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_SOFT_RESET
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_ABORT
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_CONTROL1
value|0x7d38
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_START
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_STOP
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_RECEIVE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_EN
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_PIN_SELECT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|AVIVO_SEL_DDC1
value|0
end_define

begin_define
define|#
directive|define
name|AVIVO_SEL_DDC2
value|1
end_define

begin_define
define|#
directive|define
name|AVIVO_SEL_DDC3
value|2
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_CONTROL2
value|0x7d3c
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_ADDR_COUNT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_DATA_COUNT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_CONTROL3
value|0x7d40
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_DATA_DRIVE_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_DATA_DRIVE_SEL
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_CLK_DRIVE_EN
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_RD_INTRA_BYTE_DELAY
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_WR_INTRA_BYTE_DELAY
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_TIME_LIMIT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 24)
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_DATA
value|0x7d44
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_INTERRUPT_CONTROL
value|0x7d48
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_INTERRUPT_STATUS
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_INTERRUPT_AK
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_INTERRUPT_ENABLE
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_ARBITRATION
value|0x7d50
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_SW_WANTS_TO_USE_I2C
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_SW_CAN_USE_I2C
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_SW_DONE_USING_I2C
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_HW_NEEDS_I2C
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_ABORT_HDCP_I2C
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_I2C_HW_USING_I2C
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_GPIO_DDC1_MASK
value|0x7e40
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_GPIO_DDC1_A
value|0x7e44
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_GPIO_DDC1_EN
value|0x7e48
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_GPIO_DDC1_Y
value|0x7e4c
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_GPIO_DDC2_MASK
value|0x7e50
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_GPIO_DDC2_A
value|0x7e54
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_GPIO_DDC2_EN
value|0x7e58
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_GPIO_DDC2_Y
value|0x7e5c
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_GPIO_DDC3_MASK
value|0x7e60
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_GPIO_DDC3_A
value|0x7e64
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_GPIO_DDC3_EN
value|0x7e68
end_define

begin_define
define|#
directive|define
name|AVIVO_DC_GPIO_DDC3_Y
value|0x7e6c
end_define

begin_define
define|#
directive|define
name|AVIVO_DISP_INTERRUPT_STATUS
value|0x7edc
end_define

begin_define
define|#
directive|define
name|AVIVO_D1_VBLANK_INTERRUPT
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AVIVO_D2_VBLANK_INTERRUPT
value|(1<< 5)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

