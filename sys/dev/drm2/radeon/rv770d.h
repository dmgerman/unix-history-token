begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2009 Advanced Micro Devices, Inc.  * Copyright 2009 Red Hat Inc.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * Authors: Dave Airlie  *          Alex Deucher  *          Jerome Glisse  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RV770_H
end_ifndef

begin_define
define|#
directive|define
name|RV770_H
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

begin_define
define|#
directive|define
name|R7XX_MAX_SH_GPRS
value|256
end_define

begin_define
define|#
directive|define
name|R7XX_MAX_TEMP_GPRS
value|16
end_define

begin_define
define|#
directive|define
name|R7XX_MAX_SH_THREADS
value|256
end_define

begin_define
define|#
directive|define
name|R7XX_MAX_SH_STACK_ENTRIES
value|4096
end_define

begin_define
define|#
directive|define
name|R7XX_MAX_BACKENDS
value|8
end_define

begin_define
define|#
directive|define
name|R7XX_MAX_BACKENDS_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|R7XX_MAX_SIMDS
value|16
end_define

begin_define
define|#
directive|define
name|R7XX_MAX_SIMDS_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|R7XX_MAX_PIPES
value|8
end_define

begin_define
define|#
directive|define
name|R7XX_MAX_PIPES_MASK
value|0xff
end_define

begin_comment
comment|/* Registers */
end_comment

begin_define
define|#
directive|define
name|CB_COLOR0_BASE
value|0x28040
end_define

begin_define
define|#
directive|define
name|CB_COLOR1_BASE
value|0x28044
end_define

begin_define
define|#
directive|define
name|CB_COLOR2_BASE
value|0x28048
end_define

begin_define
define|#
directive|define
name|CB_COLOR3_BASE
value|0x2804C
end_define

begin_define
define|#
directive|define
name|CB_COLOR4_BASE
value|0x28050
end_define

begin_define
define|#
directive|define
name|CB_COLOR5_BASE
value|0x28054
end_define

begin_define
define|#
directive|define
name|CB_COLOR6_BASE
value|0x28058
end_define

begin_define
define|#
directive|define
name|CB_COLOR7_BASE
value|0x2805C
end_define

begin_define
define|#
directive|define
name|CB_COLOR7_FRAG
value|0x280FC
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
name|CC_SYS_RB_BACKEND_DISABLE
value|0x3F88
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
name|CP_ME_CNTL
value|0x86D8
end_define

begin_define
define|#
directive|define
name|CP_ME_HALT
value|(1<<28)
end_define

begin_define
define|#
directive|define
name|CP_PFP_HALT
value|(1<<26)
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
value|(1U<< 31)
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
name|DB_DEBUG3
value|0x98B0
end_define

begin_define
define|#
directive|define
name|DB_CLK_OFF_DELAY
parameter_list|(
name|x
parameter_list|)
value|((x)<< 11)
end_define

begin_define
define|#
directive|define
name|DB_DEBUG4
value|0x9B8C
end_define

begin_define
define|#
directive|define
name|DISABLE_TILE_COVERED_FOR_PS_ITER
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|DCP_TILING_CONFIG
value|0x6CA0
end_define

begin_define
define|#
directive|define
name|PIPE_TILING
parameter_list|(
name|x
parameter_list|)
value|((x)<< 1)
end_define

begin_define
define|#
directive|define
name|BANK_TILING
parameter_list|(
name|x
parameter_list|)
value|((x)<< 4)
end_define

begin_define
define|#
directive|define
name|GROUP_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 6)
end_define

begin_define
define|#
directive|define
name|ROW_TILING
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|BANK_SWAPS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 11)
end_define

begin_define
define|#
directive|define
name|SAMPLE_SPLIT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 14)
end_define

begin_define
define|#
directive|define
name|BACKEND_MAP
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|GB_TILING_CONFIG
value|0x98F0
end_define

begin_define
define|#
directive|define
name|PIPE_TILING__SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|PIPE_TILING__MASK
value|0x0000000e
end_define

begin_define
define|#
directive|define
name|DMA_TILING_CONFIG
value|0x3ec8
end_define

begin_define
define|#
directive|define
name|DMA_TILING_CONFIG2
value|0xd0b8
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
name|INACTIVE_QD_PIPES_SHIFT
value|8
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
value|(1<<0)
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
name|GUI_ACTIVE
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|GRBM_STATUS2
value|0x8014
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
value|0x3FF0000
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
name|HDP_DEBUG1
value|0x2F34
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
name|PA_SC_AA_CONFIG
value|0x28C04
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
value|((x)<<0)
end_define

begin_define
define|#
directive|define
name|FORCE_EOV_MAX_REZ_CNT
parameter_list|(
name|x
parameter_list|)
value|((x)<<16)
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
name|PA_SC_LINE_STIPPLE_STATE
value|0x8B10
end_define

begin_define
define|#
directive|define
name|PA_SC_MODE_CNTL
value|0x28A4C
end_define

begin_define
define|#
directive|define
name|PA_SC_MULTI_CHIP_CNTL
value|0x8B20
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
name|CACHE_DEPTH
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
name|DISABLE_INTERP_1
value|(1<< 5)
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
name|DX9_CONSTS
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|ALU_INST_PREFER_VECTOR
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|DX10_CLAMP
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|CLAUSE_SEQ_PRIO
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
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
name|SQ_DYN_GPR_SIZE_SIMD_AB_0
value|0x8DB0
end_define

begin_define
define|#
directive|define
name|SIMDA_RING0
parameter_list|(
name|x
parameter_list|)
value|((x)<<0)
end_define

begin_define
define|#
directive|define
name|SIMDA_RING1
parameter_list|(
name|x
parameter_list|)
value|((x)<<8)
end_define

begin_define
define|#
directive|define
name|SIMDB_RING0
parameter_list|(
name|x
parameter_list|)
value|((x)<<16)
end_define

begin_define
define|#
directive|define
name|SIMDB_RING1
parameter_list|(
name|x
parameter_list|)
value|((x)<<24)
end_define

begin_define
define|#
directive|define
name|SQ_DYN_GPR_SIZE_SIMD_AB_1
value|0x8DB4
end_define

begin_define
define|#
directive|define
name|SQ_DYN_GPR_SIZE_SIMD_AB_2
value|0x8DB8
end_define

begin_define
define|#
directive|define
name|SQ_DYN_GPR_SIZE_SIMD_AB_3
value|0x8DBC
end_define

begin_define
define|#
directive|define
name|SQ_DYN_GPR_SIZE_SIMD_AB_4
value|0x8DC0
end_define

begin_define
define|#
directive|define
name|SQ_DYN_GPR_SIZE_SIMD_AB_5
value|0x8DC4
end_define

begin_define
define|#
directive|define
name|SQ_DYN_GPR_SIZE_SIMD_AB_6
value|0x8DC8
end_define

begin_define
define|#
directive|define
name|SQ_DYN_GPR_SIZE_SIMD_AB_7
value|0x8DCC
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
name|DYN_GPR_ENABLE
value|(1<< 27)
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
name|SQ_STACK_RESOURCE_MGMT_1
value|0x8C10
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
value|0x8C14
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
name|SQ_THREAD_RESOURCE_MGMT
value|0x8C0C
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
name|SX_MISC
value|0x28350
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
name|BILINEAR_PRECISION_6_BIT
value|(0<< 31)
end_define

begin_define
define|#
directive|define
name|BILINEAR_PRECISION_8_BIT
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|TCP_CNTL
value|0x9610
end_define

begin_define
define|#
directive|define
name|TCP_CHAN_STEER
value|0x9614
end_define

begin_define
define|#
directive|define
name|VC_ENHANCE
value|0x9714
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
value|((x)<<0)
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
name|VGT_ES_PER_GS
value|0x88CC
end_define

begin_define
define|#
directive|define
name|VGT_GS_PER_ES
value|0x88C8
end_define

begin_define
define|#
directive|define
name|VGT_GS_PER_VS
value|0x88E8
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
name|VGT_STRMOUT_EN
value|0x28AB0
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
name|WAIT_UNTIL
value|0x8040
end_define

begin_comment
comment|/* async DMA */
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
value|((((cmd)& 0xF)<< 28) |	\ 					 (((t)& 0x1)<< 23) |		\ 					 (((s)& 0x1)<< 22) |		\ 					 (((n)& 0xFFFF)<< 0))
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
name|DMA_PACKET_CONSTANT_FILL
value|0xd
end_define

begin_define
define|#
directive|define
name|DMA_PACKET_NOP
value|0xf
end_define

begin_define
define|#
directive|define
name|SRBM_STATUS
value|0x0E50
end_define

begin_comment
comment|/* DCE 3.2 HDMI */
end_comment

begin_define
define|#
directive|define
name|HDMI_CONTROL
value|0x7400
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
name|HDMI_STATUS
value|0x7404
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
value|0x7408
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
value|0x740c
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
name|HDMI_VBI_PACKET_CONTROL
value|0x7410
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
value|0x7414
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
value|0x7418
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
value|0x741c
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
value|0x7428
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
name|AFMT_AUDIO_PACKET_CONTROL2
value|0x742c
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
value|0x7454
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
value|0x7458
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
value|0x745c
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
value|0x7460
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
value|0x7464
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
value|0x7468
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
value|0x746c
end_define

begin_define
define|#
directive|define
name|AFMT_GENERIC0_0
value|0x7470
end_define

begin_define
define|#
directive|define
name|AFMT_GENERIC0_1
value|0x7474
end_define

begin_define
define|#
directive|define
name|AFMT_GENERIC0_2
value|0x7478
end_define

begin_define
define|#
directive|define
name|AFMT_GENERIC0_3
value|0x747c
end_define

begin_define
define|#
directive|define
name|AFMT_GENERIC0_4
value|0x7480
end_define

begin_define
define|#
directive|define
name|AFMT_GENERIC0_5
value|0x7484
end_define

begin_define
define|#
directive|define
name|AFMT_GENERIC0_6
value|0x7488
end_define

begin_define
define|#
directive|define
name|AFMT_GENERIC1_HDR
value|0x748c
end_define

begin_define
define|#
directive|define
name|AFMT_GENERIC1_0
value|0x7490
end_define

begin_define
define|#
directive|define
name|AFMT_GENERIC1_1
value|0x7494
end_define

begin_define
define|#
directive|define
name|AFMT_GENERIC1_2
value|0x7498
end_define

begin_define
define|#
directive|define
name|AFMT_GENERIC1_3
value|0x749c
end_define

begin_define
define|#
directive|define
name|AFMT_GENERIC1_4
value|0x74a0
end_define

begin_define
define|#
directive|define
name|AFMT_GENERIC1_5
value|0x74a4
end_define

begin_define
define|#
directive|define
name|AFMT_GENERIC1_6
value|0x74a8
end_define

begin_define
define|#
directive|define
name|HDMI_ACR_32_0
value|0x74ac
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
value|0x74b0
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
value|0x74b4
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
value|0x74b8
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
value|0x74bc
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
value|0x74c0
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
value|0x74c4
end_define

begin_define
define|#
directive|define
name|HDMI_ACR_STATUS_1
value|0x74c8
end_define

begin_define
define|#
directive|define
name|AFMT_AUDIO_INFO0
value|0x74cc
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
name|AFMT_AUDIO_INFO_CHECKSUM_OFFSET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 16)
end_define

begin_define
define|#
directive|define
name|AFMT_AUDIO_INFO1
value|0x74d0
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
name|AFMT_60958_0
value|0x74d4
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
value|0x74d8
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
value|0x74dc
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
value|0x74e0
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
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|AFMT_RAMP_CONTROL1
value|0x74e4
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
value|0x74e8
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
value|0x74ec
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
value|0x74f0
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
value|0x7600
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
value|0x7604
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
value|0x7608
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
value|0x760c
end_define

begin_define
define|#
directive|define
name|AFMT_AUDIO_INFO_SOURCE
value|(1<< 6)
end_define

begin_comment
comment|/* 0 - sound block; 1 - hmdi regs */
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
value|0x7610
end_define

begin_comment
comment|/* second instance starts at 0x7800 */
end_comment

begin_define
define|#
directive|define
name|HDMI_OFFSET0
value|(0x7400 - 0x7400)
end_define

begin_define
define|#
directive|define
name|HDMI_OFFSET1
value|(0x7800 - 0x7400)
end_define

begin_comment
comment|/* DCE3.2 ELD audio interface */
end_comment

begin_define
define|#
directive|define
name|AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR0
value|0x71c8
end_define

begin_comment
comment|/* LPCM */
end_comment

begin_define
define|#
directive|define
name|AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR1
value|0x71cc
end_define

begin_comment
comment|/* AC3 */
end_comment

begin_define
define|#
directive|define
name|AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR2
value|0x71d0
end_define

begin_comment
comment|/* MPEG1 */
end_comment

begin_define
define|#
directive|define
name|AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR3
value|0x71d4
end_define

begin_comment
comment|/* MP3 */
end_comment

begin_define
define|#
directive|define
name|AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR4
value|0x71d8
end_define

begin_comment
comment|/* MPEG2 */
end_comment

begin_define
define|#
directive|define
name|AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR5
value|0x71dc
end_define

begin_comment
comment|/* AAC */
end_comment

begin_define
define|#
directive|define
name|AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR6
value|0x71e0
end_define

begin_comment
comment|/* DTS */
end_comment

begin_define
define|#
directive|define
name|AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR7
value|0x71e4
end_define

begin_comment
comment|/* ATRAC */
end_comment

begin_define
define|#
directive|define
name|AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR8
value|0x71e8
end_define

begin_comment
comment|/* one bit audio - leave at 0 (default) */
end_comment

begin_define
define|#
directive|define
name|AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR9
value|0x71ec
end_define

begin_comment
comment|/* Dolby Digital */
end_comment

begin_define
define|#
directive|define
name|AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR10
value|0x71f0
end_define

begin_comment
comment|/* DTS-HD */
end_comment

begin_define
define|#
directive|define
name|AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR11
value|0x71f4
end_define

begin_comment
comment|/* MAT-MLP */
end_comment

begin_define
define|#
directive|define
name|AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR12
value|0x71f8
end_define

begin_comment
comment|/* DTS */
end_comment

begin_define
define|#
directive|define
name|AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR13
value|0x71fc
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
value|0x7300
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
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|D1GRPH_PRIMARY_SURFACE_ADDRESS
value|0x6110
end_define

begin_define
define|#
directive|define
name|D1GRPH_PRIMARY_SURFACE_ADDRESS_HIGH
value|0x6914
end_define

begin_define
define|#
directive|define
name|D2GRPH_PRIMARY_SURFACE_ADDRESS_HIGH
value|0x6114
end_define

begin_define
define|#
directive|define
name|D1GRPH_SECONDARY_SURFACE_ADDRESS
value|0x6118
end_define

begin_define
define|#
directive|define
name|D1GRPH_SECONDARY_SURFACE_ADDRESS_HIGH
value|0x691c
end_define

begin_define
define|#
directive|define
name|D2GRPH_SECONDARY_SURFACE_ADDRESS_HIGH
value|0x611c
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

