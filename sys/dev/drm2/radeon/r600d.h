begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2009 Advanced Micro Devices, Inc.  * Copyright 2009 Red Hat Inc.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * Authors: Dave Airlie  *          Alex Deucher  *          Jerome Glisse  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|R600D_H
end_ifndef

begin_define
define|#
directive|define
name|R600D_H
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
name|R6XX_MAX_SH_GPRS
value|256
end_define

begin_define
define|#
directive|define
name|R6XX_MAX_TEMP_GPRS
value|16
end_define

begin_define
define|#
directive|define
name|R6XX_MAX_SH_THREADS
value|256
end_define

begin_define
define|#
directive|define
name|R6XX_MAX_SH_STACK_ENTRIES
value|4096
end_define

begin_define
define|#
directive|define
name|R6XX_MAX_BACKENDS
value|8
end_define

begin_define
define|#
directive|define
name|R6XX_MAX_BACKENDS_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|R6XX_MAX_SIMDS
value|8
end_define

begin_define
define|#
directive|define
name|R6XX_MAX_SIMDS_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|R6XX_MAX_PIPES
value|8
end_define

begin_define
define|#
directive|define
name|R6XX_MAX_PIPES_MASK
value|0xff
end_define

begin_comment
comment|/* PTE flags */
end_comment

begin_define
define|#
directive|define
name|PTE_VALID
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|PTE_SYSTEM
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|PTE_SNOOPED
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|PTE_READABLE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|PTE_WRITEABLE
value|(1<< 6)
end_define

begin_comment
comment|/* tiling bits */
end_comment

begin_define
define|#
directive|define
name|ARRAY_LINEAR_GENERAL
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ARRAY_LINEAR_ALIGNED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ARRAY_1D_TILED_THIN1
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ARRAY_2D_TILED_THIN1
value|0x00000004
end_define

begin_comment
comment|/* Registers */
end_comment

begin_define
define|#
directive|define
name|ARB_POP
value|0x2418
end_define

begin_define
define|#
directive|define
name|ENABLE_TC128
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|ARB_GDEC_RD_CNTL
value|0x246C
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
name|R_028808_CB_COLOR_CONTROL
value|0x28808
end_define

begin_define
define|#
directive|define
name|S_028808_SPECIAL_OP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 4)
end_define

begin_define
define|#
directive|define
name|G_028808_SPECIAL_OP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_028808_SPECIAL_OP
value|0xFFFFFF8F
end_define

begin_define
define|#
directive|define
name|V_028808_SPECIAL_NORMAL
value|0x00
end_define

begin_define
define|#
directive|define
name|V_028808_SPECIAL_DISABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|V_028808_SPECIAL_RESOLVE_BOX
value|0x07
end_define

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
name|CB_COLOR0_SIZE
value|0x28060
end_define

begin_define
define|#
directive|define
name|CB_COLOR0_VIEW
value|0x28080
end_define

begin_define
define|#
directive|define
name|R_028080_CB_COLOR0_VIEW
value|0x028080
end_define

begin_define
define|#
directive|define
name|S_028080_SLICE_START
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7FF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_028080_SLICE_START
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x7FF)
end_define

begin_define
define|#
directive|define
name|C_028080_SLICE_START
value|0xFFFFF800
end_define

begin_define
define|#
directive|define
name|S_028080_SLICE_MAX
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7FF)<< 13)
end_define

begin_define
define|#
directive|define
name|G_028080_SLICE_MAX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 13)& 0x7FF)
end_define

begin_define
define|#
directive|define
name|C_028080_SLICE_MAX
value|0xFF001FFF
end_define

begin_define
define|#
directive|define
name|R_028084_CB_COLOR1_VIEW
value|0x028084
end_define

begin_define
define|#
directive|define
name|R_028088_CB_COLOR2_VIEW
value|0x028088
end_define

begin_define
define|#
directive|define
name|R_02808C_CB_COLOR3_VIEW
value|0x02808C
end_define

begin_define
define|#
directive|define
name|R_028090_CB_COLOR4_VIEW
value|0x028090
end_define

begin_define
define|#
directive|define
name|R_028094_CB_COLOR5_VIEW
value|0x028094
end_define

begin_define
define|#
directive|define
name|R_028098_CB_COLOR6_VIEW
value|0x028098
end_define

begin_define
define|#
directive|define
name|R_02809C_CB_COLOR7_VIEW
value|0x02809C
end_define

begin_define
define|#
directive|define
name|R_028100_CB_COLOR0_MASK
value|0x028100
end_define

begin_define
define|#
directive|define
name|S_028100_CMASK_BLOCK_MAX
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_028100_CMASK_BLOCK_MAX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFF)
end_define

begin_define
define|#
directive|define
name|C_028100_CMASK_BLOCK_MAX
value|0xFFFFF000
end_define

begin_define
define|#
directive|define
name|S_028100_FMASK_TILE_MAX
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFFF)<< 12)
end_define

begin_define
define|#
directive|define
name|G_028100_FMASK_TILE_MAX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0xFFFFF)
end_define

begin_define
define|#
directive|define
name|C_028100_FMASK_TILE_MAX
value|0x00000FFF
end_define

begin_define
define|#
directive|define
name|R_028104_CB_COLOR1_MASK
value|0x028104
end_define

begin_define
define|#
directive|define
name|R_028108_CB_COLOR2_MASK
value|0x028108
end_define

begin_define
define|#
directive|define
name|R_02810C_CB_COLOR3_MASK
value|0x02810C
end_define

begin_define
define|#
directive|define
name|R_028110_CB_COLOR4_MASK
value|0x028110
end_define

begin_define
define|#
directive|define
name|R_028114_CB_COLOR5_MASK
value|0x028114
end_define

begin_define
define|#
directive|define
name|R_028118_CB_COLOR6_MASK
value|0x028118
end_define

begin_define
define|#
directive|define
name|R_02811C_CB_COLOR7_MASK
value|0x02811C
end_define

begin_define
define|#
directive|define
name|CB_COLOR0_INFO
value|0x280a0
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
name|CB_SOURCE_FORMAT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 27)
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
name|CB_COLOR0_TILE
value|0x280c0
end_define

begin_define
define|#
directive|define
name|CB_COLOR0_FRAG
value|0x280e0
end_define

begin_define
define|#
directive|define
name|CB_COLOR0_MASK
value|0x28100
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
name|CONFIG_MEMSIZE
value|0x5428
end_define

begin_define
define|#
directive|define
name|CONFIG_CNTL
value|0x5424
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
name|CP_COHER_BASE
value|0x85F8
end_define

begin_define
define|#
directive|define
name|CP_DEBUG
value|0xC1FC
end_define

begin_define
define|#
directive|define
name|R_0086D8_CP_ME_CNTL
value|0x86D8
end_define

begin_define
define|#
directive|define
name|S_0086D8_CP_ME_HALT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<<28)
end_define

begin_define
define|#
directive|define
name|C_0086D8_CP_ME_HALT
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xEFFFFFFF)
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
name|MEQ_END
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|ROQ_END
parameter_list|(
name|x
parameter_list|)
value|((x)<< 24)
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
name|CP_ROQ_IB1_STAT
value|0x8784
end_define

begin_define
define|#
directive|define
name|CP_ROQ_IB2_STAT
value|0x8788
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
name|DB_DEBUG
value|0x9830
end_define

begin_define
define|#
directive|define
name|PREZ_MUST_WAIT_FOR_POSTZ_DONE
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|DB_DEPTH_BASE
value|0x2800C
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
value|0x28D24
end_define

begin_define
define|#
directive|define
name|S_028D24_HTILE_WIDTH
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_028D24_HTILE_WIDTH
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_028D24_HTILE_WIDTH
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_028D24_HTILE_HEIGHT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 1)
end_define

begin_define
define|#
directive|define
name|G_028D24_HTILE_HEIGHT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_028D24_HTILE_HEIGHT
value|0xFFFFFFFD
end_define

begin_define
define|#
directive|define
name|G_028D24_LINEAR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 2)& 0x1)
end_define

begin_define
define|#
directive|define
name|DB_WATERMARKS
value|0x9838
end_define

begin_define
define|#
directive|define
name|DEPTH_FREE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|DEPTH_FLUSH
parameter_list|(
name|x
parameter_list|)
value|((x)<< 5)
end_define

begin_define
define|#
directive|define
name|DEPTH_PENDING_FREE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 15)
end_define

begin_define
define|#
directive|define
name|DEPTH_CACHELINE_FREE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 20)
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
name|SQ_CONFIG
value|0x8c00
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
value|0x8c04
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
value|0x8c08
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
name|SQ_THREAD_RESOURCE_MGMT
value|0x8c0c
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
name|SQ_STACK_RESOURCE_MGMT_1
value|0x8c10
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
value|0x8c14
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
name|SQ_ESGS_RING_BASE
value|0x8c40
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
name|SQ_ESTMP_RING_BASE
value|0x8c50
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
name|SQ_VSTMP_RING_BASE
value|0x8c60
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
name|SQ_FBUF_RING_BASE
value|0x8c70
end_define

begin_define
define|#
directive|define
name|SQ_REDUC_RING_BASE
value|0x8c78
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
name|GRBM_STATUS
value|0x8010
end_define

begin_define
define|#
directive|define
name|CMDFIFO_AVAIL_MASK
value|0x0000001F
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
name|CG_THERMAL_STATUS
value|0x7F4
end_define

begin_define
define|#
directive|define
name|ASIC_T
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|ASIC_T_MASK
value|0x1FF
end_define

begin_define
define|#
directive|define
name|ASIC_T_SHIFT
value|0
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
name|MC_VM_AGP_TOP
value|0x2184
end_define

begin_define
define|#
directive|define
name|MC_VM_AGP_BOT
value|0x2188
end_define

begin_define
define|#
directive|define
name|MC_VM_AGP_BASE
value|0x218C
end_define

begin_define
define|#
directive|define
name|MC_VM_FB_LOCATION
value|0x2180
end_define

begin_define
define|#
directive|define
name|MC_VM_L1_TLB_MCD_RD_A_CNTL
value|0x219C
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
name|ENABLE_L1_STRICT_ORDERING
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SYSTEM_ACCESS_MODE_MASK
value|0x000000C0
end_define

begin_define
define|#
directive|define
name|SYSTEM_ACCESS_MODE_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|SYSTEM_ACCESS_MODE_PA_ONLY
value|(0<< 6)
end_define

begin_define
define|#
directive|define
name|SYSTEM_ACCESS_MODE_USE_SYS_MAP
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|SYSTEM_ACCESS_MODE_IN_SYS
value|(2<< 6)
end_define

begin_define
define|#
directive|define
name|SYSTEM_ACCESS_MODE_NOT_IN_SYS
value|(3<< 6)
end_define

begin_define
define|#
directive|define
name|SYSTEM_APERTURE_UNMAPPED_ACCESS_PASS_THRU
value|(0<< 8)
end_define

begin_define
define|#
directive|define
name|SYSTEM_APERTURE_UNMAPPED_ACCESS_DEFAULT_PAGE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|ENABLE_SEMAPHORE_MODE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|ENABLE_WAIT_L2_QUERY
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|EFFECTIVE_L1_TLB_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 7)<< 12)
end_define

begin_define
define|#
directive|define
name|EFFECTIVE_L1_TLB_SIZE_MASK
value|0x00007000
end_define

begin_define
define|#
directive|define
name|EFFECTIVE_L1_TLB_SIZE_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|EFFECTIVE_L1_QUEUE_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 7)<< 15)
end_define

begin_define
define|#
directive|define
name|EFFECTIVE_L1_QUEUE_SIZE_MASK
value|0x00038000
end_define

begin_define
define|#
directive|define
name|EFFECTIVE_L1_QUEUE_SIZE_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|MC_VM_L1_TLB_MCD_RD_B_CNTL
value|0x21A0
end_define

begin_define
define|#
directive|define
name|MC_VM_L1_TLB_MCB_RD_GFX_CNTL
value|0x21FC
end_define

begin_define
define|#
directive|define
name|MC_VM_L1_TLB_MCB_RD_HDP_CNTL
value|0x2204
end_define

begin_define
define|#
directive|define
name|MC_VM_L1_TLB_MCB_RD_PDMA_CNTL
value|0x2208
end_define

begin_define
define|#
directive|define
name|MC_VM_L1_TLB_MCB_RD_SEM_CNTL
value|0x220C
end_define

begin_define
define|#
directive|define
name|MC_VM_L1_TLB_MCB_RD_SYS_CNTL
value|0x2200
end_define

begin_define
define|#
directive|define
name|MC_VM_L1_TLB_MCD_WR_A_CNTL
value|0x21A4
end_define

begin_define
define|#
directive|define
name|MC_VM_L1_TLB_MCD_WR_B_CNTL
value|0x21A8
end_define

begin_define
define|#
directive|define
name|MC_VM_L1_TLB_MCB_WR_GFX_CNTL
value|0x2210
end_define

begin_define
define|#
directive|define
name|MC_VM_L1_TLB_MCB_WR_HDP_CNTL
value|0x2218
end_define

begin_define
define|#
directive|define
name|MC_VM_L1_TLB_MCB_WR_PDMA_CNTL
value|0x221C
end_define

begin_define
define|#
directive|define
name|MC_VM_L1_TLB_MCB_WR_SEM_CNTL
value|0x2220
end_define

begin_define
define|#
directive|define
name|MC_VM_L1_TLB_MCB_WR_SYS_CNTL
value|0x2214
end_define

begin_define
define|#
directive|define
name|MC_VM_SYSTEM_APERTURE_LOW_ADDR
value|0x2190
end_define

begin_define
define|#
directive|define
name|LOGICAL_PAGE_NUMBER_MASK
value|0x000FFFFF
end_define

begin_define
define|#
directive|define
name|LOGICAL_PAGE_NUMBER_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|MC_VM_SYSTEM_APERTURE_HIGH_ADDR
value|0x2194
end_define

begin_define
define|#
directive|define
name|MC_VM_SYSTEM_APERTURE_DEFAULT_ADDR
value|0x2198
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
name|PA_SC_AA_SAMPLE_LOCS_2S
value|0x8B40
end_define

begin_define
define|#
directive|define
name|PA_SC_AA_SAMPLE_LOCS_4S
value|0x8B44
end_define

begin_define
define|#
directive|define
name|PA_SC_AA_SAMPLE_LOCS_8S_WD0
value|0x8B48
end_define

begin_define
define|#
directive|define
name|PA_SC_AA_SAMPLE_LOCS_8S_WD1
value|0x8B4C
end_define

begin_define
define|#
directive|define
name|S0_X
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|S0_Y
parameter_list|(
name|x
parameter_list|)
value|((x)<< 4)
end_define

begin_define
define|#
directive|define
name|S1_X
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|S1_Y
parameter_list|(
name|x
parameter_list|)
value|((x)<< 12)
end_define

begin_define
define|#
directive|define
name|S2_X
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|S2_Y
parameter_list|(
name|x
parameter_list|)
value|((x)<< 20)
end_define

begin_define
define|#
directive|define
name|S3_X
parameter_list|(
name|x
parameter_list|)
value|((x)<< 24)
end_define

begin_define
define|#
directive|define
name|S3_Y
parameter_list|(
name|x
parameter_list|)
value|((x)<< 28)
end_define

begin_define
define|#
directive|define
name|S4_X
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|S4_Y
parameter_list|(
name|x
parameter_list|)
value|((x)<< 4)
end_define

begin_define
define|#
directive|define
name|S5_X
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|S5_Y
parameter_list|(
name|x
parameter_list|)
value|((x)<< 12)
end_define

begin_define
define|#
directive|define
name|S6_X
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|S6_Y
parameter_list|(
name|x
parameter_list|)
value|((x)<< 20)
end_define

begin_define
define|#
directive|define
name|S7_X
parameter_list|(
name|x
parameter_list|)
value|((x)<< 24)
end_define

begin_define
define|#
directive|define
name|S7_Y
parameter_list|(
name|x
parameter_list|)
value|((x)<< 28)
end_define

begin_define
define|#
directive|define
name|PA_SC_CLIPRECT_RULE
value|0x2820c
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
name|FORCE_EOV_MAX_CLK_CNT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|FORCE_EOV_MAX_TILE_CNT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 12)
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
name|PCIE_PORT_INDEX
value|0x0038
end_define

begin_define
define|#
directive|define
name|PCIE_PORT_DATA
value|0x003C
end_define

begin_define
define|#
directive|define
name|CHMAP
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
name|RAMCFG
value|0x2408
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
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NOOFRANK_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|NOOFRANK_MASK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NOOFROWS_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|NOOFROWS_MASK
value|0x0000001C
end_define

begin_define
define|#
directive|define
name|NOOFCOLS_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|NOOFCOLS_MASK
value|0x00000060
end_define

begin_define
define|#
directive|define
name|CHANSIZE_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|CHANSIZE_MASK
value|0x00000080
end_define

begin_define
define|#
directive|define
name|BURSTLENGTH_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BURSTLENGTH_MASK
value|0x00000100
end_define

begin_define
define|#
directive|define
name|CHANSIZE_OVERRIDE
value|(1<< 10)
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
name|SPI_PS_IN_CONTROL_1
value|0x286D0
end_define

begin_define
define|#
directive|define
name|GEN_INDEX_PIX
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|GEN_INDEX_PIX_ADDR
parameter_list|(
name|x
parameter_list|)
value|((x)<<1)
end_define

begin_define
define|#
directive|define
name|FRONT_FACE_ENA
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|FRONT_FACE_CHAN
parameter_list|(
name|x
parameter_list|)
value|((x)<<9)
end_define

begin_define
define|#
directive|define
name|FRONT_FACE_ALL_BITS
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|FRONT_FACE_ADDR
parameter_list|(
name|x
parameter_list|)
value|((x)<<12)
end_define

begin_define
define|#
directive|define
name|FOG_ADDR
parameter_list|(
name|x
parameter_list|)
value|((x)<<17)
end_define

begin_define
define|#
directive|define
name|FIXED_PT_POSITION_ENA
value|(1<<24)
end_define

begin_define
define|#
directive|define
name|FIXED_PT_POSITION_ADDR
parameter_list|(
name|x
parameter_list|)
value|((x)<<25)
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
name|SQ_PGM_START_ES
value|0x28880
end_define

begin_define
define|#
directive|define
name|SQ_PGM_START_FS
value|0x28894
end_define

begin_define
define|#
directive|define
name|SQ_PGM_START_GS
value|0x2886C
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
name|SQ_PGM_RESOURCES_PS
value|0x28850
end_define

begin_define
define|#
directive|define
name|SQ_PGM_EXPORTS_PS
value|0x28854
end_define

begin_define
define|#
directive|define
name|SQ_PGM_CF_OFFSET_PS
value|0x288cc
end_define

begin_define
define|#
directive|define
name|SQ_PGM_START_VS
value|0x28858
end_define

begin_define
define|#
directive|define
name|SQ_PGM_RESOURCES_VS
value|0x28868
end_define

begin_define
define|#
directive|define
name|SQ_PGM_CF_OFFSET_VS
value|0x288d0
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
value|0x3000c
end_define

begin_define
define|#
directive|define
name|SQ_VTX_CONSTANT_WORD6_0
value|0x38018
end_define

begin_define
define|#
directive|define
name|S__SQ_VTX_CONSTANT_TYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 3)<< 30)
end_define

begin_define
define|#
directive|define
name|G__SQ_VTX_CONSTANT_TYPE
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
name|SX_MISC
value|0x28350
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
name|SX_DEBUG_1
value|0x9054
end_define

begin_define
define|#
directive|define
name|SMX_EVENT_RELEASE
value|(1<< 0)
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
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|TC_CNTL
value|0x9608
end_define

begin_define
define|#
directive|define
name|TC_L2_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<<5)
end_define

begin_define
define|#
directive|define
name|L2_DISABLE_LATE_HIT
value|(1<<9)
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
name|VGT_DMA_BASE
value|0x287E8
end_define

begin_define
define|#
directive|define
name|VGT_DMA_BASE_HI
value|0x287E4
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
name|VGT_PRIMITIVE_TYPE
value|0x8958
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
name|VGT_STRMOUT_BASE_OFFSET_0
value|0x28B10
end_define

begin_define
define|#
directive|define
name|VGT_STRMOUT_BASE_OFFSET_1
value|0x28B14
end_define

begin_define
define|#
directive|define
name|VGT_STRMOUT_BASE_OFFSET_2
value|0x28B18
end_define

begin_define
define|#
directive|define
name|VGT_STRMOUT_BASE_OFFSET_3
value|0x28B1c
end_define

begin_define
define|#
directive|define
name|VGT_STRMOUT_BASE_OFFSET_HI_0
value|0x28B44
end_define

begin_define
define|#
directive|define
name|VGT_STRMOUT_BASE_OFFSET_HI_1
value|0x28B48
end_define

begin_define
define|#
directive|define
name|VGT_STRMOUT_BASE_OFFSET_HI_2
value|0x28B4c
end_define

begin_define
define|#
directive|define
name|VGT_STRMOUT_BASE_OFFSET_HI_3
value|0x28B50
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
name|VGT_STRMOUT_BUFFER_OFFSET_0
value|0x28ADC
end_define

begin_define
define|#
directive|define
name|VGT_STRMOUT_BUFFER_OFFSET_1
value|0x28AEC
end_define

begin_define
define|#
directive|define
name|VGT_STRMOUT_BUFFER_OFFSET_2
value|0x28AFC
end_define

begin_define
define|#
directive|define
name|VGT_STRMOUT_BUFFER_OFFSET_3
value|0x28B0C
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
name|VGT_EVENT_INITIATOR
value|0x28a90
end_define

begin_define
define|#
directive|define
name|CACHE_FLUSH_AND_INV_EVENT_TS
value|(0x14<< 0)
end_define

begin_define
define|#
directive|define
name|CACHE_FLUSH_AND_INV_EVENT
value|(0x16<< 0)
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
name|VM_CONTEXT0_INVALIDATION_LOW_ADDR
value|0x1490
end_define

begin_define
define|#
directive|define
name|VM_CONTEXT0_INVALIDATION_HIGH_ADDR
value|0x14B0
end_define

begin_define
define|#
directive|define
name|VM_CONTEXT0_PAGE_TABLE_BASE_ADDR
value|0x1574
end_define

begin_define
define|#
directive|define
name|VM_CONTEXT0_PAGE_TABLE_START_ADDR
value|0x1594
end_define

begin_define
define|#
directive|define
name|VM_CONTEXT0_PAGE_TABLE_END_ADDR
value|0x15B4
end_define

begin_define
define|#
directive|define
name|VM_CONTEXT0_PROTECTION_FAULT_DEFAULT_ADDR
value|0x1554
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
value|(((x)& 7)<< 13)
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
name|BANK_SELECT_0
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1f)<< 0)
end_define

begin_define
define|#
directive|define
name|BANK_SELECT_1
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1f)<< 5)
end_define

begin_define
define|#
directive|define
name|L2_CACHE_UPDATE_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 3)<< 10)
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

begin_define
define|#
directive|define
name|WAIT_2D_IDLE_bit
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|WAIT_3D_IDLE_bit
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|WAIT_2D_IDLECLEAN_bit
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|WAIT_3D_IDLECLEAN_bit
value|(1<< 17)
end_define

begin_comment
comment|/* async DMA */
end_comment

begin_define
define|#
directive|define
name|DMA_TILING_CONFIG
value|0x3ec4
end_define

begin_define
define|#
directive|define
name|DMA_CONFIG
value|0x3e4c
end_define

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
name|DMA_RB_BASE
value|0xd004
end_define

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
name|DMA_RB_RPTR_ADDR_HI
value|0xd01c
end_define

begin_define
define|#
directive|define
name|DMA_RB_RPTR_ADDR_LO
value|0xd020
end_define

begin_define
define|#
directive|define
name|DMA_IB_CNTL
value|0xd024
end_define

begin_define
define|#
directive|define
name|DMA_IB_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DMA_IB_SWAP_ENABLE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|DMA_IB_RPTR
value|0xd028
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
name|DMA_STATUS_REG
value|0xd034
end_define

begin_define
define|#
directive|define
name|DMA_IDLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DMA_SEM_INCOMPLETE_TIMER_CNTL
value|0xd044
end_define

begin_define
define|#
directive|define
name|DMA_SEM_WAIT_FAIL_TIMER_CNTL
value|0xd048
end_define

begin_define
define|#
directive|define
name|DMA_MODE
value|0xd0bc
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

begin_comment
comment|/* 7xx only */
end_comment

begin_define
define|#
directive|define
name|DMA_PACKET_NOP
value|0xf
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
name|IH_RB_SIZE
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
name|RLC_CNTL
value|0x3f00
end_define

begin_define
define|#
directive|define
name|RLC_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RLC_HB_BASE
value|0x3f10
end_define

begin_define
define|#
directive|define
name|RLC_HB_CNTL
value|0x3f0c
end_define

begin_define
define|#
directive|define
name|RLC_HB_RPTR
value|0x3f20
end_define

begin_define
define|#
directive|define
name|RLC_HB_WPTR
value|0x3f1c
end_define

begin_define
define|#
directive|define
name|RLC_HB_WPTR_LSB_ADDR
value|0x3f14
end_define

begin_define
define|#
directive|define
name|RLC_HB_WPTR_MSB_ADDR
value|0x3f18
end_define

begin_define
define|#
directive|define
name|RLC_GPU_CLOCK_COUNT_LSB
value|0x3f38
end_define

begin_define
define|#
directive|define
name|RLC_GPU_CLOCK_COUNT_MSB
value|0x3f3c
end_define

begin_define
define|#
directive|define
name|RLC_CAPTURE_GPU_CLOCK_COUNT
value|0x3f40
end_define

begin_define
define|#
directive|define
name|RLC_MC_CNTL
value|0x3f44
end_define

begin_define
define|#
directive|define
name|RLC_UCODE_CNTL
value|0x3f48
end_define

begin_define
define|#
directive|define
name|RLC_UCODE_ADDR
value|0x3f2c
end_define

begin_define
define|#
directive|define
name|RLC_UCODE_DATA
value|0x3f30
end_define

begin_comment
comment|/* new for TN */
end_comment

begin_define
define|#
directive|define
name|TN_RLC_SAVE_AND_RESTORE_BASE
value|0x3f10
end_define

begin_define
define|#
directive|define
name|TN_RLC_CLEAR_STATE_RESTORE_BASE
value|0x3f20
end_define

begin_define
define|#
directive|define
name|SRBM_SOFT_RESET
value|0xe60
end_define

begin_define
define|#
directive|define
name|SOFT_RESET_DMA
value|(1<< 12)
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
name|RV770_SOFT_RESET_DMA
value|(1<< 20)
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
name|WAIT_COUNT_TIMEOUT_INT_ENABLE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|GUI_IDLE_INT_ENABLE
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|INTERRUPT_CNTL
value|0x5468
end_define

begin_define
define|#
directive|define
name|IH_DUMMY_RD_OVERRIDE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|IH_DUMMY_RD_EN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|IH_REQ_NONSNOOP_EN
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|GEN_IH_INT_EN
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|INTERRUPT_CNTL2
value|0x546c
end_define

begin_define
define|#
directive|define
name|D1MODE_VBLANK_STATUS
value|0x6534
end_define

begin_define
define|#
directive|define
name|D2MODE_VBLANK_STATUS
value|0x6d34
end_define

begin_define
define|#
directive|define
name|DxMODE_VBLANK_OCCURRED
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DxMODE_VBLANK_ACK
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|DxMODE_VBLANK_STAT
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|DxMODE_VBLANK_INTERRUPT
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|DxMODE_VBLANK_INTERRUPT_TYPE
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|D1MODE_VLINE_STATUS
value|0x653c
end_define

begin_define
define|#
directive|define
name|D2MODE_VLINE_STATUS
value|0x6d3c
end_define

begin_define
define|#
directive|define
name|DxMODE_VLINE_OCCURRED
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DxMODE_VLINE_ACK
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|DxMODE_VLINE_STAT
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|DxMODE_VLINE_INTERRUPT
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|DxMODE_VLINE_INTERRUPT_TYPE
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|DxMODE_INT_MASK
value|0x6540
end_define

begin_define
define|#
directive|define
name|D1MODE_VBLANK_INT_MASK
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|D1MODE_VLINE_INT_MASK
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|D2MODE_VBLANK_INT_MASK
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|D2MODE_VLINE_INT_MASK
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|DCE3_DISP_INTERRUPT_STATUS
value|0x7ddc
end_define

begin_define
define|#
directive|define
name|DC_HPD1_INTERRUPT
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|DC_HPD2_INTERRUPT
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|DISP_INTERRUPT_STATUS
value|0x7edc
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
name|LB_D2_VLINE_INTERRUPT
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|LB_D1_VBLANK_INTERRUPT
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|LB_D2_VBLANK_INTERRUPT
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|DACA_AUTODETECT_INTERRUPT
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|DACB_AUTODETECT_INTERRUPT
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|DC_HOT_PLUG_DETECT1_INTERRUPT
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|DC_HOT_PLUG_DETECT2_INTERRUPT
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|DC_I2C_SW_DONE_INTERRUPT
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|DC_I2C_HW_DONE_INTERRUPT
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|DISP_INTERRUPT_STATUS_CONTINUE
value|0x7ee8
end_define

begin_define
define|#
directive|define
name|DCE3_DISP_INTERRUPT_STATUS_CONTINUE
value|0x7de8
end_define

begin_define
define|#
directive|define
name|DC_HPD4_INTERRUPT
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|DC_HPD4_RX_INTERRUPT
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|DC_HPD3_INTERRUPT
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|DC_HPD1_RX_INTERRUPT
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|DC_HPD2_RX_INTERRUPT
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|DCE3_DISP_INTERRUPT_STATUS_CONTINUE2
value|0x7dec
end_define

begin_define
define|#
directive|define
name|DC_HPD3_RX_INTERRUPT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DIGA_DP_VID_STREAM_DISABLE_INTERRUPT
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|DIGA_DP_STEER_FIFO_OVERFLOW_INTERRUPT
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|DIGB_DP_VID_STREAM_DISABLE_INTERRUPT
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|DIGB_DP_STEER_FIFO_OVERFLOW_INTERRUPT
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AUX1_SW_DONE_INTERRUPT
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AUX1_LS_DONE_INTERRUPT
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AUX2_SW_DONE_INTERRUPT
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AUX2_LS_DONE_INTERRUPT
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AUX3_SW_DONE_INTERRUPT
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|AUX3_LS_DONE_INTERRUPT
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|AUX4_SW_DONE_INTERRUPT
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|AUX4_LS_DONE_INTERRUPT
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|DIGA_DP_FAST_TRAINING_COMPLETE_INTERRUPT
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|DIGB_DP_FAST_TRAINING_COMPLETE_INTERRUPT
value|(1<< 14)
end_define

begin_comment
comment|/* DCE 3.2 */
end_comment

begin_define
define|#
directive|define
name|AUX5_SW_DONE_INTERRUPT
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|AUX5_LS_DONE_INTERRUPT
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AUX6_SW_DONE_INTERRUPT
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|AUX6_LS_DONE_INTERRUPT
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|DC_HPD5_INTERRUPT
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|DC_HPD5_RX_INTERRUPT
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|DC_HPD6_INTERRUPT
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|DC_HPD6_RX_INTERRUPT
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|DACA_AUTO_DETECT_CONTROL
value|0x7828
end_define

begin_define
define|#
directive|define
name|DACB_AUTO_DETECT_CONTROL
value|0x7a28
end_define

begin_define
define|#
directive|define
name|DCE3_DACA_AUTO_DETECT_CONTROL
value|0x7028
end_define

begin_define
define|#
directive|define
name|DCE3_DACB_AUTO_DETECT_CONTROL
value|0x7128
end_define

begin_define
define|#
directive|define
name|DACx_AUTODETECT_MODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|DACx_AUTODETECT_MODE_NONE
value|0
end_define

begin_define
define|#
directive|define
name|DACx_AUTODETECT_MODE_CONNECT
value|1
end_define

begin_define
define|#
directive|define
name|DACx_AUTODETECT_MODE_DISCONNECT
value|2
end_define

begin_define
define|#
directive|define
name|DACx_AUTODETECT_FRAME_TIME_COUNTER
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_comment
comment|/* bit 18 = R/C, 17 = G/Y, 16 = B/Comp */
end_comment

begin_define
define|#
directive|define
name|DACx_AUTODETECT_CHECK_MASK
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|DCE3_DACA_AUTODETECT_INT_CONTROL
value|0x7038
end_define

begin_define
define|#
directive|define
name|DCE3_DACB_AUTODETECT_INT_CONTROL
value|0x7138
end_define

begin_define
define|#
directive|define
name|DACA_AUTODETECT_INT_CONTROL
value|0x7838
end_define

begin_define
define|#
directive|define
name|DACB_AUTODETECT_INT_CONTROL
value|0x7a38
end_define

begin_define
define|#
directive|define
name|DACx_AUTODETECT_ACK
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DACx_AUTODETECT_INT_ENABLE
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|DC_HOT_PLUG_DETECT1_CONTROL
value|0x7d00
end_define

begin_define
define|#
directive|define
name|DC_HOT_PLUG_DETECT2_CONTROL
value|0x7d10
end_define

begin_define
define|#
directive|define
name|DC_HOT_PLUG_DETECT3_CONTROL
value|0x7d24
end_define

begin_define
define|#
directive|define
name|DC_HOT_PLUG_DETECTx_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DC_HOT_PLUG_DETECT1_INT_STATUS
value|0x7d04
end_define

begin_define
define|#
directive|define
name|DC_HOT_PLUG_DETECT2_INT_STATUS
value|0x7d14
end_define

begin_define
define|#
directive|define
name|DC_HOT_PLUG_DETECT3_INT_STATUS
value|0x7d28
end_define

begin_define
define|#
directive|define
name|DC_HOT_PLUG_DETECTx_INT_STATUS
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DC_HOT_PLUG_DETECTx_SENSE
value|(1<< 1)
end_define

begin_comment
comment|/* DCE 3.0 */
end_comment

begin_define
define|#
directive|define
name|DC_HPD1_INT_STATUS
value|0x7d00
end_define

begin_define
define|#
directive|define
name|DC_HPD2_INT_STATUS
value|0x7d0c
end_define

begin_define
define|#
directive|define
name|DC_HPD3_INT_STATUS
value|0x7d18
end_define

begin_define
define|#
directive|define
name|DC_HPD4_INT_STATUS
value|0x7d24
end_define

begin_comment
comment|/* DCE 3.2 */
end_comment

begin_define
define|#
directive|define
name|DC_HPD5_INT_STATUS
value|0x7dc0
end_define

begin_define
define|#
directive|define
name|DC_HPD6_INT_STATUS
value|0x7df4
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
name|DC_HOT_PLUG_DETECT1_INT_CONTROL
value|0x7d08
end_define

begin_define
define|#
directive|define
name|DC_HOT_PLUG_DETECT2_INT_CONTROL
value|0x7d18
end_define

begin_define
define|#
directive|define
name|DC_HOT_PLUG_DETECT3_INT_CONTROL
value|0x7d2c
end_define

begin_define
define|#
directive|define
name|DC_HOT_PLUG_DETECTx_INT_ACK
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DC_HOT_PLUG_DETECTx_INT_POLARITY
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|DC_HOT_PLUG_DETECTx_INT_EN
value|(1<< 16)
end_define

begin_comment
comment|/* DCE 3.0 */
end_comment

begin_define
define|#
directive|define
name|DC_HPD1_INT_CONTROL
value|0x7d04
end_define

begin_define
define|#
directive|define
name|DC_HPD2_INT_CONTROL
value|0x7d10
end_define

begin_define
define|#
directive|define
name|DC_HPD3_INT_CONTROL
value|0x7d1c
end_define

begin_define
define|#
directive|define
name|DC_HPD4_INT_CONTROL
value|0x7d28
end_define

begin_comment
comment|/* DCE 3.2 */
end_comment

begin_define
define|#
directive|define
name|DC_HPD5_INT_CONTROL
value|0x7dc4
end_define

begin_define
define|#
directive|define
name|DC_HPD6_INT_CONTROL
value|0x7df8
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

begin_comment
comment|/* DCE 3.0 */
end_comment

begin_define
define|#
directive|define
name|DC_HPD1_CONTROL
value|0x7d08
end_define

begin_define
define|#
directive|define
name|DC_HPD2_CONTROL
value|0x7d14
end_define

begin_define
define|#
directive|define
name|DC_HPD3_CONTROL
value|0x7d20
end_define

begin_define
define|#
directive|define
name|DC_HPD4_CONTROL
value|0x7d2c
end_define

begin_comment
comment|/* DCE 3.2 */
end_comment

begin_define
define|#
directive|define
name|DC_HPD5_CONTROL
value|0x7dc8
end_define

begin_define
define|#
directive|define
name|DC_HPD6_CONTROL
value|0x7dfc
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

begin_comment
comment|/* DCE 3.2 */
end_comment

begin_define
define|#
directive|define
name|DC_HPDx_EN
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|D1GRPH_INTERRUPT_STATUS
value|0x6158
end_define

begin_define
define|#
directive|define
name|D2GRPH_INTERRUPT_STATUS
value|0x6958
end_define

begin_define
define|#
directive|define
name|DxGRPH_PFLIP_INT_OCCURRED
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DxGRPH_PFLIP_INT_CLEAR
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|D1GRPH_INTERRUPT_CONTROL
value|0x615c
end_define

begin_define
define|#
directive|define
name|D2GRPH_INTERRUPT_CONTROL
value|0x695c
end_define

begin_define
define|#
directive|define
name|DxGRPH_PFLIP_INT_MASK
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DxGRPH_PFLIP_INT_TYPE
value|(1<< 8)
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
name|LC_POINT_7_PLUS_EN
value|(1<< 6)
end_define

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
comment|/* Audio clocks */
end_comment

begin_define
define|#
directive|define
name|DCCG_AUDIO_DTO0_PHASE
value|0x0514
end_define

begin_define
define|#
directive|define
name|DCCG_AUDIO_DTO0_MODULE
value|0x0518
end_define

begin_define
define|#
directive|define
name|DCCG_AUDIO_DTO0_LOAD
value|0x051c
end_define

begin_define
define|#
directive|define
name|DTO_LOAD
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|DCCG_AUDIO_DTO0_CNTL
value|0x0520
end_define

begin_define
define|#
directive|define
name|DCCG_AUDIO_DTO1_PHASE
value|0x0524
end_define

begin_define
define|#
directive|define
name|DCCG_AUDIO_DTO1_MODULE
value|0x0528
end_define

begin_define
define|#
directive|define
name|DCCG_AUDIO_DTO1_LOAD
value|0x052c
end_define

begin_define
define|#
directive|define
name|DCCG_AUDIO_DTO1_CNTL
value|0x0530
end_define

begin_define
define|#
directive|define
name|DCCG_AUDIO_DTO_SELECT
value|0x0534
end_define

begin_comment
comment|/* digital blocks */
end_comment

begin_define
define|#
directive|define
name|TMDSA_CNTL
value|0x7880
end_define

begin_define
define|#
directive|define
name|TMDSA_HDMI_EN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|LVTMA_CNTL
value|0x7a80
end_define

begin_define
define|#
directive|define
name|LVTMA_HDMI_EN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|DDIA_CNTL
value|0x7200
end_define

begin_define
define|#
directive|define
name|DDIA_HDMI_EN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|DIG0_CNTL
value|0x75a0
end_define

begin_define
define|#
directive|define
name|DIG_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 7)<< 8)
end_define

begin_define
define|#
directive|define
name|DIG_MODE_DP
value|0
end_define

begin_define
define|#
directive|define
name|DIG_MODE_LVDS
value|1
end_define

begin_define
define|#
directive|define
name|DIG_MODE_TMDS_DVI
value|2
end_define

begin_define
define|#
directive|define
name|DIG_MODE_TMDS_HDMI
value|3
end_define

begin_define
define|#
directive|define
name|DIG_MODE_SDVO
value|4
end_define

begin_define
define|#
directive|define
name|DIG1_CNTL
value|0x79a0
end_define

begin_comment
comment|/* rs6xx/rs740 and r6xx share the same HDMI blocks, however, rs6xx has only one  * instance of the blocks while r6xx has 2.  DCE 3.0 cards are slightly  * different due to the new DIG blocks, but also have 2 instances.  * DCE 3.0 HDMI blocks are part of each DIG encoder.  */
end_comment

begin_comment
comment|/* rs6xx/rs740/r6xx/dce3 */
end_comment

begin_define
define|#
directive|define
name|HDMI0_CONTROL
value|0x7400
end_define

begin_comment
comment|/* rs6xx/rs740/r6xx */
end_comment

begin_define
define|#
directive|define
name|HDMI0_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI0_STREAM
parameter_list|(
name|x
parameter_list|)
value|(((x)& 3)<< 2)
end_define

begin_define
define|#
directive|define
name|HDMI0_STREAM_TMDSA
value|0
end_define

begin_define
define|#
directive|define
name|HDMI0_STREAM_LVTMA
value|1
end_define

begin_define
define|#
directive|define
name|HDMI0_STREAM_DVOA
value|2
end_define

begin_define
define|#
directive|define
name|HDMI0_STREAM_DDIA
value|3
end_define

begin_comment
comment|/* rs6xx/r6xx/dce3 */
end_comment

begin_define
define|#
directive|define
name|HDMI0_ERROR_ACK
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|HDMI0_ERROR_MASK
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|HDMI0_STATUS
value|0x7404
end_define

begin_define
define|#
directive|define
name|HDMI0_ACTIVE_AVMUTE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI0_AUDIO_ENABLE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|HDMI0_AZ_FORMAT_WTRIG
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|HDMI0_AZ_FORMAT_WTRIG_INT
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|HDMI0_AUDIO_PACKET_CONTROL
value|0x7408
end_define

begin_define
define|#
directive|define
name|HDMI0_AUDIO_SAMPLE_SEND
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI0_AUDIO_DELAY_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 3)<< 4)
end_define

begin_define
define|#
directive|define
name|HDMI0_AUDIO_SEND_MAX_PACKETS
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|HDMI0_AUDIO_TEST_EN
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|HDMI0_AUDIO_PACKETS_PER_LINE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1f)<< 16)
end_define

begin_define
define|#
directive|define
name|HDMI0_AUDIO_CHANNEL_SWAP
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|HDMI0_60958_CS_UPDATE
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|HDMI0_AZ_FORMAT_WTRIG_MASK
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|HDMI0_AZ_FORMAT_WTRIG_ACK
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|HDMI0_AUDIO_CRC_CONTROL
value|0x740c
end_define

begin_define
define|#
directive|define
name|HDMI0_AUDIO_CRC_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI0_VBI_PACKET_CONTROL
value|0x7410
end_define

begin_define
define|#
directive|define
name|HDMI0_NULL_SEND
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI0_GC_SEND
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|HDMI0_GC_CONT
value|(1<< 5)
end_define

begin_comment
comment|/* 0 - once; 1 - every frame */
end_comment

begin_define
define|#
directive|define
name|HDMI0_INFOFRAME_CONTROL0
value|0x7414
end_define

begin_define
define|#
directive|define
name|HDMI0_AVI_INFO_SEND
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI0_AVI_INFO_CONT
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|HDMI0_AUDIO_INFO_SEND
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|HDMI0_AUDIO_INFO_CONT
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|HDMI0_AUDIO_INFO_SOURCE
value|(1<< 6)
end_define

begin_comment
comment|/* 0 - sound block; 1 - hmdi regs */
end_comment

begin_define
define|#
directive|define
name|HDMI0_AUDIO_INFO_UPDATE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|HDMI0_MPEG_INFO_SEND
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|HDMI0_MPEG_INFO_CONT
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|HDMI0_MPEG_INFO_UPDATE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|HDMI0_INFOFRAME_CONTROL1
value|0x7418
end_define

begin_define
define|#
directive|define
name|HDMI0_AVI_INFO_LINE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3f)<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI0_AUDIO_INFO_LINE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3f)<< 8)
end_define

begin_define
define|#
directive|define
name|HDMI0_MPEG_INFO_LINE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3f)<< 16)
end_define

begin_define
define|#
directive|define
name|HDMI0_GENERIC_PACKET_CONTROL
value|0x741c
end_define

begin_define
define|#
directive|define
name|HDMI0_GENERIC0_SEND
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI0_GENERIC0_CONT
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|HDMI0_GENERIC0_UPDATE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|HDMI0_GENERIC1_SEND
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|HDMI0_GENERIC1_CONT
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|HDMI0_GENERIC0_LINE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3f)<< 16)
end_define

begin_define
define|#
directive|define
name|HDMI0_GENERIC1_LINE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3f)<< 24)
end_define

begin_define
define|#
directive|define
name|HDMI0_GC
value|0x7428
end_define

begin_define
define|#
directive|define
name|HDMI0_GC_AVMUTE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI0_AVI_INFO0
value|0x7454
end_define

begin_define
define|#
directive|define
name|HDMI0_AVI_INFO_CHECKSUM
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI0_AVI_INFO_S
parameter_list|(
name|x
parameter_list|)
value|(((x)& 3)<< 8)
end_define

begin_define
define|#
directive|define
name|HDMI0_AVI_INFO_B
parameter_list|(
name|x
parameter_list|)
value|(((x)& 3)<< 10)
end_define

begin_define
define|#
directive|define
name|HDMI0_AVI_INFO_A
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 12)
end_define

begin_define
define|#
directive|define
name|HDMI0_AVI_INFO_Y
parameter_list|(
name|x
parameter_list|)
value|(((x)& 3)<< 13)
end_define

begin_define
define|#
directive|define
name|HDMI0_AVI_INFO_Y_RGB
value|0
end_define

begin_define
define|#
directive|define
name|HDMI0_AVI_INFO_Y_YCBCR422
value|1
end_define

begin_define
define|#
directive|define
name|HDMI0_AVI_INFO_Y_YCBCR444
value|2
end_define

begin_define
define|#
directive|define
name|HDMI0_AVI_INFO_Y_A_B_S
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 8)
end_define

begin_define
define|#
directive|define
name|HDMI0_AVI_INFO_R
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 16)
end_define

begin_define
define|#
directive|define
name|HDMI0_AVI_INFO_M
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 20)
end_define

begin_define
define|#
directive|define
name|HDMI0_AVI_INFO_C
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 22)
end_define

begin_define
define|#
directive|define
name|HDMI0_AVI_INFO_C_M_R
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 16)
end_define

begin_define
define|#
directive|define
name|HDMI0_AVI_INFO_SC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 24)
end_define

begin_define
define|#
directive|define
name|HDMI0_AVI_INFO_ITC_EC_Q_SC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 24)
end_define

begin_define
define|#
directive|define
name|HDMI0_AVI_INFO1
value|0x7458
end_define

begin_define
define|#
directive|define
name|HDMI0_AVI_INFO_VIC
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
name|HDMI0_AVI_INFO_PR
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
name|HDMI0_AVI_INFO_TOP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xffff)<< 16)
end_define

begin_define
define|#
directive|define
name|HDMI0_AVI_INFO2
value|0x745c
end_define

begin_define
define|#
directive|define
name|HDMI0_AVI_INFO_BOTTOM
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xffff)<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI0_AVI_INFO_LEFT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xffff)<< 16)
end_define

begin_define
define|#
directive|define
name|HDMI0_AVI_INFO3
value|0x7460
end_define

begin_define
define|#
directive|define
name|HDMI0_AVI_INFO_RIGHT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xffff)<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI0_AVI_INFO_VERSION
parameter_list|(
name|x
parameter_list|)
value|(((x)& 3)<< 24)
end_define

begin_define
define|#
directive|define
name|HDMI0_MPEG_INFO0
value|0x7464
end_define

begin_define
define|#
directive|define
name|HDMI0_MPEG_INFO_CHECKSUM
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI0_MPEG_INFO_MB0
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 8)
end_define

begin_define
define|#
directive|define
name|HDMI0_MPEG_INFO_MB1
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 16)
end_define

begin_define
define|#
directive|define
name|HDMI0_MPEG_INFO_MB2
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 24)
end_define

begin_define
define|#
directive|define
name|HDMI0_MPEG_INFO1
value|0x7468
end_define

begin_define
define|#
directive|define
name|HDMI0_MPEG_INFO_MB3
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI0_MPEG_INFO_MF
parameter_list|(
name|x
parameter_list|)
value|(((x)& 3)<< 8)
end_define

begin_define
define|#
directive|define
name|HDMI0_MPEG_INFO_FR
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 12)
end_define

begin_define
define|#
directive|define
name|HDMI0_GENERIC0_HDR
value|0x746c
end_define

begin_define
define|#
directive|define
name|HDMI0_GENERIC0_0
value|0x7470
end_define

begin_define
define|#
directive|define
name|HDMI0_GENERIC0_1
value|0x7474
end_define

begin_define
define|#
directive|define
name|HDMI0_GENERIC0_2
value|0x7478
end_define

begin_define
define|#
directive|define
name|HDMI0_GENERIC0_3
value|0x747c
end_define

begin_define
define|#
directive|define
name|HDMI0_GENERIC0_4
value|0x7480
end_define

begin_define
define|#
directive|define
name|HDMI0_GENERIC0_5
value|0x7484
end_define

begin_define
define|#
directive|define
name|HDMI0_GENERIC0_6
value|0x7488
end_define

begin_define
define|#
directive|define
name|HDMI0_GENERIC1_HDR
value|0x748c
end_define

begin_define
define|#
directive|define
name|HDMI0_GENERIC1_0
value|0x7490
end_define

begin_define
define|#
directive|define
name|HDMI0_GENERIC1_1
value|0x7494
end_define

begin_define
define|#
directive|define
name|HDMI0_GENERIC1_2
value|0x7498
end_define

begin_define
define|#
directive|define
name|HDMI0_GENERIC1_3
value|0x749c
end_define

begin_define
define|#
directive|define
name|HDMI0_GENERIC1_4
value|0x74a0
end_define

begin_define
define|#
directive|define
name|HDMI0_GENERIC1_5
value|0x74a4
end_define

begin_define
define|#
directive|define
name|HDMI0_GENERIC1_6
value|0x74a8
end_define

begin_define
define|#
directive|define
name|HDMI0_ACR_32_0
value|0x74ac
end_define

begin_define
define|#
directive|define
name|HDMI0_ACR_CTS_32
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xfffff)<< 12)
end_define

begin_define
define|#
directive|define
name|HDMI0_ACR_32_1
value|0x74b0
end_define

begin_define
define|#
directive|define
name|HDMI0_ACR_N_32
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xfffff)<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI0_ACR_44_0
value|0x74b4
end_define

begin_define
define|#
directive|define
name|HDMI0_ACR_CTS_44
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xfffff)<< 12)
end_define

begin_define
define|#
directive|define
name|HDMI0_ACR_44_1
value|0x74b8
end_define

begin_define
define|#
directive|define
name|HDMI0_ACR_N_44
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xfffff)<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI0_ACR_48_0
value|0x74bc
end_define

begin_define
define|#
directive|define
name|HDMI0_ACR_CTS_48
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xfffff)<< 12)
end_define

begin_define
define|#
directive|define
name|HDMI0_ACR_48_1
value|0x74c0
end_define

begin_define
define|#
directive|define
name|HDMI0_ACR_N_48
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xfffff)<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI0_ACR_STATUS_0
value|0x74c4
end_define

begin_define
define|#
directive|define
name|HDMI0_ACR_STATUS_1
value|0x74c8
end_define

begin_define
define|#
directive|define
name|HDMI0_AUDIO_INFO0
value|0x74cc
end_define

begin_define
define|#
directive|define
name|HDMI0_AUDIO_INFO_CHECKSUM
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI0_AUDIO_INFO_CC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 7)<< 8)
end_define

begin_define
define|#
directive|define
name|HDMI0_AUDIO_INFO1
value|0x74d0
end_define

begin_define
define|#
directive|define
name|HDMI0_AUDIO_INFO_CA
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI0_AUDIO_INFO_LSV
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 11)
end_define

begin_define
define|#
directive|define
name|HDMI0_AUDIO_INFO_DM_INH
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 15)
end_define

begin_define
define|#
directive|define
name|HDMI0_AUDIO_INFO_DM_INH_LSV
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 8)
end_define

begin_define
define|#
directive|define
name|HDMI0_60958_0
value|0x74d4
end_define

begin_define
define|#
directive|define
name|HDMI0_60958_CS_A
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI0_60958_CS_B
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 1)
end_define

begin_define
define|#
directive|define
name|HDMI0_60958_CS_C
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 2)
end_define

begin_define
define|#
directive|define
name|HDMI0_60958_CS_D
parameter_list|(
name|x
parameter_list|)
value|(((x)& 3)<< 3)
end_define

begin_define
define|#
directive|define
name|HDMI0_60958_CS_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 3)<< 6)
end_define

begin_define
define|#
directive|define
name|HDMI0_60958_CS_CATEGORY_CODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 8)
end_define

begin_define
define|#
directive|define
name|HDMI0_60958_CS_SOURCE_NUMBER
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 16)
end_define

begin_define
define|#
directive|define
name|HDMI0_60958_CS_CHANNEL_NUMBER_L
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 20)
end_define

begin_define
define|#
directive|define
name|HDMI0_60958_CS_SAMPLING_FREQUENCY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 24)
end_define

begin_define
define|#
directive|define
name|HDMI0_60958_CS_CLOCK_ACCURACY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 3)<< 28)
end_define

begin_define
define|#
directive|define
name|HDMI0_60958_1
value|0x74d8
end_define

begin_define
define|#
directive|define
name|HDMI0_60958_CS_WORD_LENGTH
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI0_60958_CS_ORIGINAL_SAMPLING_FREQUENCY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 4)
end_define

begin_define
define|#
directive|define
name|HDMI0_60958_CS_VALID_L
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 16)
end_define

begin_define
define|#
directive|define
name|HDMI0_60958_CS_VALID_R
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 18)
end_define

begin_define
define|#
directive|define
name|HDMI0_60958_CS_CHANNEL_NUMBER_R
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 20)
end_define

begin_define
define|#
directive|define
name|HDMI0_ACR_PACKET_CONTROL
value|0x74dc
end_define

begin_define
define|#
directive|define
name|HDMI0_ACR_SEND
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI0_ACR_CONT
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|HDMI0_ACR_SELECT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 3)<< 4)
end_define

begin_define
define|#
directive|define
name|HDMI0_ACR_HW
value|0
end_define

begin_define
define|#
directive|define
name|HDMI0_ACR_32
value|1
end_define

begin_define
define|#
directive|define
name|HDMI0_ACR_44
value|2
end_define

begin_define
define|#
directive|define
name|HDMI0_ACR_48
value|3
end_define

begin_define
define|#
directive|define
name|HDMI0_ACR_SOURCE
value|(1<< 8)
end_define

begin_comment
comment|/* 0 - hw; 1 - cts value */
end_comment

begin_define
define|#
directive|define
name|HDMI0_ACR_AUTO_SEND
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|HDMI0_RAMP_CONTROL0
value|0x74e0
end_define

begin_define
define|#
directive|define
name|HDMI0_RAMP_MAX_COUNT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xffffff)<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI0_RAMP_CONTROL1
value|0x74e4
end_define

begin_define
define|#
directive|define
name|HDMI0_RAMP_MIN_COUNT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xffffff)<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI0_RAMP_CONTROL2
value|0x74e8
end_define

begin_define
define|#
directive|define
name|HDMI0_RAMP_INC_COUNT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xffffff)<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI0_RAMP_CONTROL3
value|0x74ec
end_define

begin_define
define|#
directive|define
name|HDMI0_RAMP_DEC_COUNT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xffffff)<< 0)
end_define

begin_comment
comment|/* HDMI0_60958_2 is r7xx only */
end_comment

begin_define
define|#
directive|define
name|HDMI0_60958_2
value|0x74f0
end_define

begin_define
define|#
directive|define
name|HDMI0_60958_CS_CHANNEL_NUMBER_2
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI0_60958_CS_CHANNEL_NUMBER_3
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 4)
end_define

begin_define
define|#
directive|define
name|HDMI0_60958_CS_CHANNEL_NUMBER_4
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 8)
end_define

begin_define
define|#
directive|define
name|HDMI0_60958_CS_CHANNEL_NUMBER_5
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 12)
end_define

begin_define
define|#
directive|define
name|HDMI0_60958_CS_CHANNEL_NUMBER_6
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 16)
end_define

begin_define
define|#
directive|define
name|HDMI0_60958_CS_CHANNEL_NUMBER_7
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 20)
end_define

begin_comment
comment|/* r6xx only; second instance starts at 0x7700 */
end_comment

begin_define
define|#
directive|define
name|HDMI1_CONTROL
value|0x7700
end_define

begin_define
define|#
directive|define
name|HDMI1_STATUS
value|0x7704
end_define

begin_define
define|#
directive|define
name|HDMI1_AUDIO_PACKET_CONTROL
value|0x7708
end_define

begin_comment
comment|/* DCE3; second instance starts at 0x7800 NOT 0x7700 */
end_comment

begin_define
define|#
directive|define
name|DCE3_HDMI1_CONTROL
value|0x7800
end_define

begin_define
define|#
directive|define
name|DCE3_HDMI1_STATUS
value|0x7804
end_define

begin_define
define|#
directive|define
name|DCE3_HDMI1_AUDIO_PACKET_CONTROL
value|0x7808
end_define

begin_comment
comment|/* DCE3.2 (for interrupts) */
end_comment

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
name|PACKET3_INDIRECT_BUFFER_END
value|0x17
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
name|PACKET3_START_3D_CMDBUF
value|0x24
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
name|PACKET3_DRAW_INDEX_IMMD_BE
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
name|PACKET3_STRMOUT_BUFFER_UPDATE
value|0x34
end_define

begin_define
define|#
directive|define
name|PACKET3_INDIRECT_BUFFER_MP
value|0x38
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
name|PACKET3_SEM_WAIT_ON_SIGNAL
value|(0x1<< 12)
end_define

begin_define
define|#
directive|define
name|PACKET3_SEM_SEL_SIGNAL
value|(0x6<< 29)
end_define

begin_define
define|#
directive|define
name|PACKET3_SEM_SEL_WAIT
value|(0x7<< 29)
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
comment|/* 1. header  * 2. SRC_ADDR_LO [31:0]  * 3. CP_SYNC [31] | SRC_ADDR_HI [7:0]  * 4. DST_ADDR_LO [31:0]  * 5. DST_ADDR_HI [7:0]  * 6. COMMAND [29:22] | BYTE_COUNT [20:0]  */
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
name|PACKET3_SMX_ACTION_ENA
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
name|EVENT_TYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|EVENT_INDEX
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_comment
comment|/* 0 - any non-TS event 		 * 1 - ZPASS_DONE 		 * 2 - SAMPLE_PIPELINESTAT 		 * 3 - SAMPLE_STREAMOUTSTAT* 		 * 4 - *S_PARTIAL_FLUSH 		 * 5 - TS events 		 */
end_comment

begin_define
define|#
directive|define
name|PACKET3_EVENT_WRITE_EOP
value|0x47
end_define

begin_define
define|#
directive|define
name|DATA_SEL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 29)
end_define

begin_comment
comment|/* 0 - discard 		 * 1 - send low 32bit data 		 * 2 - send 64bit data 		 * 3 - send 64bit counter value 		 */
end_comment

begin_define
define|#
directive|define
name|INT_SEL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 24)
end_define

begin_comment
comment|/* 0 - none 		 * 1 - interrupt only (DATA_SEL = 0) 		 * 2 - interrupt when data write is confirmed 		 */
end_comment

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
name|PACKET3_SET_CONFIG_REG_OFFSET
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
name|PACKET3_SET_CONTEXT_REG_OFFSET
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

begin_define
define|#
directive|define
name|PACKET3_SET_ALU_CONST_OFFSET
value|0x00030000
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_ALU_CONST_END
value|0x00032000
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_BOOL_CONST
value|0x6B
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_BOOL_CONST_OFFSET
value|0x0003e380
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_BOOL_CONST_END
value|0x00040000
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
name|PACKET3_SET_LOOP_CONST_OFFSET
value|0x0003e200
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_LOOP_CONST_END
value|0x0003e380
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
name|PACKET3_SET_RESOURCE_OFFSET
value|0x00038000
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_RESOURCE_END
value|0x0003c000
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
name|PACKET3_SET_SAMPLER_OFFSET
value|0x0003c000
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_SAMPLER_END
value|0x0003cff0
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
name|PACKET3_SET_CTL_CONST_OFFSET
value|0x0003cff0
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_CTL_CONST_END
value|0x0003e200
end_define

begin_define
define|#
directive|define
name|PACKET3_STRMOUT_BASE_UPDATE
value|0x72
end_define

begin_comment
comment|/* r7xx */
end_comment

begin_define
define|#
directive|define
name|PACKET3_SURFACE_BASE_UPDATE
value|0x73
end_define

begin_define
define|#
directive|define
name|R_008020_GRBM_SOFT_RESET
value|0x8020
end_define

begin_define
define|#
directive|define
name|S_008020_SOFT_RESET_CP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 0)
end_define

begin_define
define|#
directive|define
name|S_008020_SOFT_RESET_CB
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 1)
end_define

begin_define
define|#
directive|define
name|S_008020_SOFT_RESET_CR
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 2)
end_define

begin_define
define|#
directive|define
name|S_008020_SOFT_RESET_DB
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 3)
end_define

begin_define
define|#
directive|define
name|S_008020_SOFT_RESET_PA
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 5)
end_define

begin_define
define|#
directive|define
name|S_008020_SOFT_RESET_SC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 6)
end_define

begin_define
define|#
directive|define
name|S_008020_SOFT_RESET_SMX
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 7)
end_define

begin_define
define|#
directive|define
name|S_008020_SOFT_RESET_SPI
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 8)
end_define

begin_define
define|#
directive|define
name|S_008020_SOFT_RESET_SH
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 9)
end_define

begin_define
define|#
directive|define
name|S_008020_SOFT_RESET_SX
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 10)
end_define

begin_define
define|#
directive|define
name|S_008020_SOFT_RESET_TC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 11)
end_define

begin_define
define|#
directive|define
name|S_008020_SOFT_RESET_TA
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 12)
end_define

begin_define
define|#
directive|define
name|S_008020_SOFT_RESET_VC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 13)
end_define

begin_define
define|#
directive|define
name|S_008020_SOFT_RESET_VGT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 14)
end_define

begin_define
define|#
directive|define
name|R_008010_GRBM_STATUS
value|0x8010
end_define

begin_define
define|#
directive|define
name|S_008010_CMDFIFO_AVAIL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1F)<< 0)
end_define

begin_define
define|#
directive|define
name|S_008010_CP_RQ_PENDING
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 6)
end_define

begin_define
define|#
directive|define
name|S_008010_CF_RQ_PENDING
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 7)
end_define

begin_define
define|#
directive|define
name|S_008010_PF_RQ_PENDING
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 8)
end_define

begin_define
define|#
directive|define
name|S_008010_GRBM_EE_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 10)
end_define

begin_define
define|#
directive|define
name|S_008010_VC_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 11)
end_define

begin_define
define|#
directive|define
name|S_008010_DB03_CLEAN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 12)
end_define

begin_define
define|#
directive|define
name|S_008010_CB03_CLEAN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 13)
end_define

begin_define
define|#
directive|define
name|S_008010_VGT_BUSY_NO_DMA
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 16)
end_define

begin_define
define|#
directive|define
name|S_008010_VGT_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 17)
end_define

begin_define
define|#
directive|define
name|S_008010_TA03_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 18)
end_define

begin_define
define|#
directive|define
name|S_008010_TC_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 19)
end_define

begin_define
define|#
directive|define
name|S_008010_SX_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 20)
end_define

begin_define
define|#
directive|define
name|S_008010_SH_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 21)
end_define

begin_define
define|#
directive|define
name|S_008010_SPI03_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 22)
end_define

begin_define
define|#
directive|define
name|S_008010_SMX_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 23)
end_define

begin_define
define|#
directive|define
name|S_008010_SC_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 24)
end_define

begin_define
define|#
directive|define
name|S_008010_PA_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 25)
end_define

begin_define
define|#
directive|define
name|S_008010_DB03_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 26)
end_define

begin_define
define|#
directive|define
name|S_008010_CR_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 27)
end_define

begin_define
define|#
directive|define
name|S_008010_CP_COHERENCY_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 28)
end_define

begin_define
define|#
directive|define
name|S_008010_CP_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 29)
end_define

begin_define
define|#
directive|define
name|S_008010_CB03_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 30)
end_define

begin_define
define|#
directive|define
name|S_008010_GUI_ACTIVE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 31)
end_define

begin_define
define|#
directive|define
name|G_008010_CMDFIFO_AVAIL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1F)
end_define

begin_define
define|#
directive|define
name|G_008010_CP_RQ_PENDING
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 6)& 1)
end_define

begin_define
define|#
directive|define
name|G_008010_CF_RQ_PENDING
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 7)& 1)
end_define

begin_define
define|#
directive|define
name|G_008010_PF_RQ_PENDING
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 1)
end_define

begin_define
define|#
directive|define
name|G_008010_GRBM_EE_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)& 1)
end_define

begin_define
define|#
directive|define
name|G_008010_VC_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 11)& 1)
end_define

begin_define
define|#
directive|define
name|G_008010_DB03_CLEAN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 1)
end_define

begin_define
define|#
directive|define
name|G_008010_CB03_CLEAN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 13)& 1)
end_define

begin_define
define|#
directive|define
name|G_008010_VGT_BUSY_NO_DMA
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 1)
end_define

begin_define
define|#
directive|define
name|G_008010_VGT_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 17)& 1)
end_define

begin_define
define|#
directive|define
name|G_008010_TA03_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 18)& 1)
end_define

begin_define
define|#
directive|define
name|G_008010_TC_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 19)& 1)
end_define

begin_define
define|#
directive|define
name|G_008010_SX_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 1)
end_define

begin_define
define|#
directive|define
name|G_008010_SH_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 21)& 1)
end_define

begin_define
define|#
directive|define
name|G_008010_SPI03_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 22)& 1)
end_define

begin_define
define|#
directive|define
name|G_008010_SMX_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 23)& 1)
end_define

begin_define
define|#
directive|define
name|G_008010_SC_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 1)
end_define

begin_define
define|#
directive|define
name|G_008010_PA_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 25)& 1)
end_define

begin_define
define|#
directive|define
name|G_008010_DB03_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 26)& 1)
end_define

begin_define
define|#
directive|define
name|G_008010_CR_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 27)& 1)
end_define

begin_define
define|#
directive|define
name|G_008010_CP_COHERENCY_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 28)& 1)
end_define

begin_define
define|#
directive|define
name|G_008010_CP_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 29)& 1)
end_define

begin_define
define|#
directive|define
name|G_008010_CB03_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 30)& 1)
end_define

begin_define
define|#
directive|define
name|G_008010_GUI_ACTIVE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 31)& 1)
end_define

begin_define
define|#
directive|define
name|R_008014_GRBM_STATUS2
value|0x8014
end_define

begin_define
define|#
directive|define
name|S_008014_CR_CLEAN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 0)
end_define

begin_define
define|#
directive|define
name|S_008014_SMX_CLEAN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 1)
end_define

begin_define
define|#
directive|define
name|S_008014_SPI0_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 8)
end_define

begin_define
define|#
directive|define
name|S_008014_SPI1_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 9)
end_define

begin_define
define|#
directive|define
name|S_008014_SPI2_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 10)
end_define

begin_define
define|#
directive|define
name|S_008014_SPI3_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 11)
end_define

begin_define
define|#
directive|define
name|S_008014_TA0_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 12)
end_define

begin_define
define|#
directive|define
name|S_008014_TA1_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 13)
end_define

begin_define
define|#
directive|define
name|S_008014_TA2_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 14)
end_define

begin_define
define|#
directive|define
name|S_008014_TA3_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 15)
end_define

begin_define
define|#
directive|define
name|S_008014_DB0_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 16)
end_define

begin_define
define|#
directive|define
name|S_008014_DB1_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 17)
end_define

begin_define
define|#
directive|define
name|S_008014_DB2_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 18)
end_define

begin_define
define|#
directive|define
name|S_008014_DB3_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 19)
end_define

begin_define
define|#
directive|define
name|S_008014_CB0_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 20)
end_define

begin_define
define|#
directive|define
name|S_008014_CB1_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 21)
end_define

begin_define
define|#
directive|define
name|S_008014_CB2_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 22)
end_define

begin_define
define|#
directive|define
name|S_008014_CB3_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 23)
end_define

begin_define
define|#
directive|define
name|G_008014_CR_CLEAN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 1)
end_define

begin_define
define|#
directive|define
name|G_008014_SMX_CLEAN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 1)
end_define

begin_define
define|#
directive|define
name|G_008014_SPI0_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 1)
end_define

begin_define
define|#
directive|define
name|G_008014_SPI1_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 9)& 1)
end_define

begin_define
define|#
directive|define
name|G_008014_SPI2_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)& 1)
end_define

begin_define
define|#
directive|define
name|G_008014_SPI3_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 11)& 1)
end_define

begin_define
define|#
directive|define
name|G_008014_TA0_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 1)
end_define

begin_define
define|#
directive|define
name|G_008014_TA1_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 13)& 1)
end_define

begin_define
define|#
directive|define
name|G_008014_TA2_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 14)& 1)
end_define

begin_define
define|#
directive|define
name|G_008014_TA3_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 15)& 1)
end_define

begin_define
define|#
directive|define
name|G_008014_DB0_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 1)
end_define

begin_define
define|#
directive|define
name|G_008014_DB1_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 17)& 1)
end_define

begin_define
define|#
directive|define
name|G_008014_DB2_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 18)& 1)
end_define

begin_define
define|#
directive|define
name|G_008014_DB3_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 19)& 1)
end_define

begin_define
define|#
directive|define
name|G_008014_CB0_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 1)
end_define

begin_define
define|#
directive|define
name|G_008014_CB1_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 21)& 1)
end_define

begin_define
define|#
directive|define
name|G_008014_CB2_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 22)& 1)
end_define

begin_define
define|#
directive|define
name|G_008014_CB3_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 23)& 1)
end_define

begin_define
define|#
directive|define
name|R_000E50_SRBM_STATUS
value|0x0E50
end_define

begin_define
define|#
directive|define
name|G_000E50_RLC_RQ_PENDING
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 3)& 1)
end_define

begin_define
define|#
directive|define
name|G_000E50_RCU_RQ_PENDING
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 1)
end_define

begin_define
define|#
directive|define
name|G_000E50_GRBM_RQ_PENDING
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 5)& 1)
end_define

begin_define
define|#
directive|define
name|G_000E50_HI_RQ_PENDING
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 6)& 1)
end_define

begin_define
define|#
directive|define
name|G_000E50_IO_EXTERN_SIGNAL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 7)& 1)
end_define

begin_define
define|#
directive|define
name|G_000E50_VMC_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 1)
end_define

begin_define
define|#
directive|define
name|G_000E50_MCB_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 9)& 1)
end_define

begin_define
define|#
directive|define
name|G_000E50_MCDZ_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)& 1)
end_define

begin_define
define|#
directive|define
name|G_000E50_MCDY_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 11)& 1)
end_define

begin_define
define|#
directive|define
name|G_000E50_MCDX_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 1)
end_define

begin_define
define|#
directive|define
name|G_000E50_MCDW_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 13)& 1)
end_define

begin_define
define|#
directive|define
name|G_000E50_SEM_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 14)& 1)
end_define

begin_define
define|#
directive|define
name|G_000E50_RLC_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 15)& 1)
end_define

begin_define
define|#
directive|define
name|G_000E50_BIF_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 29)& 1)
end_define

begin_define
define|#
directive|define
name|R_000E60_SRBM_SOFT_RESET
value|0x0E60
end_define

begin_define
define|#
directive|define
name|S_000E60_SOFT_RESET_BIF
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 1)
end_define

begin_define
define|#
directive|define
name|S_000E60_SOFT_RESET_CG
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 2)
end_define

begin_define
define|#
directive|define
name|S_000E60_SOFT_RESET_CMC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 3)
end_define

begin_define
define|#
directive|define
name|S_000E60_SOFT_RESET_CSC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 4)
end_define

begin_define
define|#
directive|define
name|S_000E60_SOFT_RESET_DC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 5)
end_define

begin_define
define|#
directive|define
name|S_000E60_SOFT_RESET_GRBM
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 8)
end_define

begin_define
define|#
directive|define
name|S_000E60_SOFT_RESET_HDP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 9)
end_define

begin_define
define|#
directive|define
name|S_000E60_SOFT_RESET_IH
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 10)
end_define

begin_define
define|#
directive|define
name|S_000E60_SOFT_RESET_MC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 11)
end_define

begin_define
define|#
directive|define
name|S_000E60_SOFT_RESET_RLC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 13)
end_define

begin_define
define|#
directive|define
name|S_000E60_SOFT_RESET_ROM
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 14)
end_define

begin_define
define|#
directive|define
name|S_000E60_SOFT_RESET_SEM
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 15)
end_define

begin_define
define|#
directive|define
name|S_000E60_SOFT_RESET_TSC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 16)
end_define

begin_define
define|#
directive|define
name|S_000E60_SOFT_RESET_VMC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)<< 17)
end_define

begin_define
define|#
directive|define
name|R_005480_HDP_MEM_COHERENCY_FLUSH_CNTL
value|0x5480
end_define

begin_define
define|#
directive|define
name|R_028C04_PA_SC_AA_CONFIG
value|0x028C04
end_define

begin_define
define|#
directive|define
name|S_028C04_MSAA_NUM_SAMPLES
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 0)
end_define

begin_define
define|#
directive|define
name|G_028C04_MSAA_NUM_SAMPLES
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_028C04_MSAA_NUM_SAMPLES
value|0xFFFFFFFC
end_define

begin_define
define|#
directive|define
name|S_028C04_AA_MASK_CENTROID_DTMN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 4)
end_define

begin_define
define|#
directive|define
name|G_028C04_AA_MASK_CENTROID_DTMN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_028C04_AA_MASK_CENTROID_DTMN
value|0xFFFFFFEF
end_define

begin_define
define|#
directive|define
name|S_028C04_MAX_SAMPLE_DIST
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 13)
end_define

begin_define
define|#
directive|define
name|G_028C04_MAX_SAMPLE_DIST
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 13)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_028C04_MAX_SAMPLE_DIST
value|0xFFFE1FFF
end_define

begin_define
define|#
directive|define
name|R_0280E0_CB_COLOR0_FRAG
value|0x0280E0
end_define

begin_define
define|#
directive|define
name|S_0280E0_BASE_256B
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFFFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_0280E0_BASE_256B
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|C_0280E0_BASE_256B
value|0x00000000
end_define

begin_define
define|#
directive|define
name|R_0280E4_CB_COLOR1_FRAG
value|0x0280E4
end_define

begin_define
define|#
directive|define
name|R_0280E8_CB_COLOR2_FRAG
value|0x0280E8
end_define

begin_define
define|#
directive|define
name|R_0280EC_CB_COLOR3_FRAG
value|0x0280EC
end_define

begin_define
define|#
directive|define
name|R_0280F0_CB_COLOR4_FRAG
value|0x0280F0
end_define

begin_define
define|#
directive|define
name|R_0280F4_CB_COLOR5_FRAG
value|0x0280F4
end_define

begin_define
define|#
directive|define
name|R_0280F8_CB_COLOR6_FRAG
value|0x0280F8
end_define

begin_define
define|#
directive|define
name|R_0280FC_CB_COLOR7_FRAG
value|0x0280FC
end_define

begin_define
define|#
directive|define
name|R_0280C0_CB_COLOR0_TILE
value|0x0280C0
end_define

begin_define
define|#
directive|define
name|S_0280C0_BASE_256B
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFFFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_0280C0_BASE_256B
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|C_0280C0_BASE_256B
value|0x00000000
end_define

begin_define
define|#
directive|define
name|R_0280C4_CB_COLOR1_TILE
value|0x0280C4
end_define

begin_define
define|#
directive|define
name|R_0280C8_CB_COLOR2_TILE
value|0x0280C8
end_define

begin_define
define|#
directive|define
name|R_0280CC_CB_COLOR3_TILE
value|0x0280CC
end_define

begin_define
define|#
directive|define
name|R_0280D0_CB_COLOR4_TILE
value|0x0280D0
end_define

begin_define
define|#
directive|define
name|R_0280D4_CB_COLOR5_TILE
value|0x0280D4
end_define

begin_define
define|#
directive|define
name|R_0280D8_CB_COLOR6_TILE
value|0x0280D8
end_define

begin_define
define|#
directive|define
name|R_0280DC_CB_COLOR7_TILE
value|0x0280DC
end_define

begin_define
define|#
directive|define
name|R_0280A0_CB_COLOR0_INFO
value|0x0280A0
end_define

begin_define
define|#
directive|define
name|S_0280A0_ENDIAN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 0)
end_define

begin_define
define|#
directive|define
name|G_0280A0_ENDIAN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_0280A0_ENDIAN
value|0xFFFFFFFC
end_define

begin_define
define|#
directive|define
name|S_0280A0_FORMAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3F)<< 2)
end_define

begin_define
define|#
directive|define
name|G_0280A0_FORMAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 2)& 0x3F)
end_define

begin_define
define|#
directive|define
name|C_0280A0_FORMAT
value|0xFFFFFF03
end_define

begin_define
define|#
directive|define
name|V_0280A0_COLOR_INVALID
value|0x00000000
end_define

begin_define
define|#
directive|define
name|V_0280A0_COLOR_8
value|0x00000001
end_define

begin_define
define|#
directive|define
name|V_0280A0_COLOR_4_4
value|0x00000002
end_define

begin_define
define|#
directive|define
name|V_0280A0_COLOR_3_3_2
value|0x00000003
end_define

begin_define
define|#
directive|define
name|V_0280A0_COLOR_16
value|0x00000005
end_define

begin_define
define|#
directive|define
name|V_0280A0_COLOR_16_FLOAT
value|0x00000006
end_define

begin_define
define|#
directive|define
name|V_0280A0_COLOR_8_8
value|0x00000007
end_define

begin_define
define|#
directive|define
name|V_0280A0_COLOR_5_6_5
value|0x00000008
end_define

begin_define
define|#
directive|define
name|V_0280A0_COLOR_6_5_5
value|0x00000009
end_define

begin_define
define|#
directive|define
name|V_0280A0_COLOR_1_5_5_5
value|0x0000000A
end_define

begin_define
define|#
directive|define
name|V_0280A0_COLOR_4_4_4_4
value|0x0000000B
end_define

begin_define
define|#
directive|define
name|V_0280A0_COLOR_5_5_5_1
value|0x0000000C
end_define

begin_define
define|#
directive|define
name|V_0280A0_COLOR_32
value|0x0000000D
end_define

begin_define
define|#
directive|define
name|V_0280A0_COLOR_32_FLOAT
value|0x0000000E
end_define

begin_define
define|#
directive|define
name|V_0280A0_COLOR_16_16
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|V_0280A0_COLOR_16_16_FLOAT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|V_0280A0_COLOR_8_24
value|0x00000011
end_define

begin_define
define|#
directive|define
name|V_0280A0_COLOR_8_24_FLOAT
value|0x00000012
end_define

begin_define
define|#
directive|define
name|V_0280A0_COLOR_24_8
value|0x00000013
end_define

begin_define
define|#
directive|define
name|V_0280A0_COLOR_24_8_FLOAT
value|0x00000014
end_define

begin_define
define|#
directive|define
name|V_0280A0_COLOR_10_11_11
value|0x00000015
end_define

begin_define
define|#
directive|define
name|V_0280A0_COLOR_10_11_11_FLOAT
value|0x00000016
end_define

begin_define
define|#
directive|define
name|V_0280A0_COLOR_11_11_10
value|0x00000017
end_define

begin_define
define|#
directive|define
name|V_0280A0_COLOR_11_11_10_FLOAT
value|0x00000018
end_define

begin_define
define|#
directive|define
name|V_0280A0_COLOR_2_10_10_10
value|0x00000019
end_define

begin_define
define|#
directive|define
name|V_0280A0_COLOR_8_8_8_8
value|0x0000001A
end_define

begin_define
define|#
directive|define
name|V_0280A0_COLOR_10_10_10_2
value|0x0000001B
end_define

begin_define
define|#
directive|define
name|V_0280A0_COLOR_X24_8_32_FLOAT
value|0x0000001C
end_define

begin_define
define|#
directive|define
name|V_0280A0_COLOR_32_32
value|0x0000001D
end_define

begin_define
define|#
directive|define
name|V_0280A0_COLOR_32_32_FLOAT
value|0x0000001E
end_define

begin_define
define|#
directive|define
name|V_0280A0_COLOR_16_16_16_16
value|0x0000001F
end_define

begin_define
define|#
directive|define
name|V_0280A0_COLOR_16_16_16_16_FLOAT
value|0x00000020
end_define

begin_define
define|#
directive|define
name|V_0280A0_COLOR_32_32_32_32
value|0x00000022
end_define

begin_define
define|#
directive|define
name|V_0280A0_COLOR_32_32_32_32_FLOAT
value|0x00000023
end_define

begin_define
define|#
directive|define
name|S_0280A0_ARRAY_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 8)
end_define

begin_define
define|#
directive|define
name|G_0280A0_ARRAY_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_0280A0_ARRAY_MODE
value|0xFFFFF0FF
end_define

begin_define
define|#
directive|define
name|V_0280A0_ARRAY_LINEAR_GENERAL
value|0x00000000
end_define

begin_define
define|#
directive|define
name|V_0280A0_ARRAY_LINEAR_ALIGNED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|V_0280A0_ARRAY_1D_TILED_THIN1
value|0x00000002
end_define

begin_define
define|#
directive|define
name|V_0280A0_ARRAY_2D_TILED_THIN1
value|0x00000004
end_define

begin_define
define|#
directive|define
name|S_0280A0_NUMBER_TYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 12)
end_define

begin_define
define|#
directive|define
name|G_0280A0_NUMBER_TYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_0280A0_NUMBER_TYPE
value|0xFFFF8FFF
end_define

begin_define
define|#
directive|define
name|S_0280A0_READ_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 15)
end_define

begin_define
define|#
directive|define
name|G_0280A0_READ_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 15)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0280A0_READ_SIZE
value|0xFFFF7FFF
end_define

begin_define
define|#
directive|define
name|S_0280A0_COMP_SWAP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 16)
end_define

begin_define
define|#
directive|define
name|G_0280A0_COMP_SWAP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_0280A0_COMP_SWAP
value|0xFFFCFFFF
end_define

begin_define
define|#
directive|define
name|S_0280A0_TILE_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 18)
end_define

begin_define
define|#
directive|define
name|G_0280A0_TILE_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 18)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_0280A0_TILE_MODE
value|0xFFF3FFFF
end_define

begin_define
define|#
directive|define
name|V_0280A0_TILE_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|V_0280A0_CLEAR_ENABLE
value|1
end_define

begin_define
define|#
directive|define
name|V_0280A0_FRAG_ENABLE
value|2
end_define

begin_define
define|#
directive|define
name|S_0280A0_BLEND_CLAMP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 20)
end_define

begin_define
define|#
directive|define
name|G_0280A0_BLEND_CLAMP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0280A0_BLEND_CLAMP
value|0xFFEFFFFF
end_define

begin_define
define|#
directive|define
name|S_0280A0_CLEAR_COLOR
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 21)
end_define

begin_define
define|#
directive|define
name|G_0280A0_CLEAR_COLOR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 21)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0280A0_CLEAR_COLOR
value|0xFFDFFFFF
end_define

begin_define
define|#
directive|define
name|S_0280A0_BLEND_BYPASS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 22)
end_define

begin_define
define|#
directive|define
name|G_0280A0_BLEND_BYPASS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 22)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0280A0_BLEND_BYPASS
value|0xFFBFFFFF
end_define

begin_define
define|#
directive|define
name|S_0280A0_BLEND_FLOAT32
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 23)
end_define

begin_define
define|#
directive|define
name|G_0280A0_BLEND_FLOAT32
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 23)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0280A0_BLEND_FLOAT32
value|0xFF7FFFFF
end_define

begin_define
define|#
directive|define
name|S_0280A0_SIMPLE_FLOAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 24)
end_define

begin_define
define|#
directive|define
name|G_0280A0_SIMPLE_FLOAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0280A0_SIMPLE_FLOAT
value|0xFEFFFFFF
end_define

begin_define
define|#
directive|define
name|S_0280A0_ROUND_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 25)
end_define

begin_define
define|#
directive|define
name|G_0280A0_ROUND_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 25)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0280A0_ROUND_MODE
value|0xFDFFFFFF
end_define

begin_define
define|#
directive|define
name|S_0280A0_TILE_COMPACT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 26)
end_define

begin_define
define|#
directive|define
name|G_0280A0_TILE_COMPACT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 26)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0280A0_TILE_COMPACT
value|0xFBFFFFFF
end_define

begin_define
define|#
directive|define
name|S_0280A0_SOURCE_FORMAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 27)
end_define

begin_define
define|#
directive|define
name|G_0280A0_SOURCE_FORMAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 27)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0280A0_SOURCE_FORMAT
value|0xF7FFFFFF
end_define

begin_define
define|#
directive|define
name|R_0280A4_CB_COLOR1_INFO
value|0x0280A4
end_define

begin_define
define|#
directive|define
name|R_0280A8_CB_COLOR2_INFO
value|0x0280A8
end_define

begin_define
define|#
directive|define
name|R_0280AC_CB_COLOR3_INFO
value|0x0280AC
end_define

begin_define
define|#
directive|define
name|R_0280B0_CB_COLOR4_INFO
value|0x0280B0
end_define

begin_define
define|#
directive|define
name|R_0280B4_CB_COLOR5_INFO
value|0x0280B4
end_define

begin_define
define|#
directive|define
name|R_0280B8_CB_COLOR6_INFO
value|0x0280B8
end_define

begin_define
define|#
directive|define
name|R_0280BC_CB_COLOR7_INFO
value|0x0280BC
end_define

begin_define
define|#
directive|define
name|R_028060_CB_COLOR0_SIZE
value|0x028060
end_define

begin_define
define|#
directive|define
name|S_028060_PITCH_TILE_MAX
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3FF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_028060_PITCH_TILE_MAX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x3FF)
end_define

begin_define
define|#
directive|define
name|C_028060_PITCH_TILE_MAX
value|0xFFFFFC00
end_define

begin_define
define|#
directive|define
name|S_028060_SLICE_TILE_MAX
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFFF)<< 10)
end_define

begin_define
define|#
directive|define
name|G_028060_SLICE_TILE_MAX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)& 0xFFFFF)
end_define

begin_define
define|#
directive|define
name|C_028060_SLICE_TILE_MAX
value|0xC00003FF
end_define

begin_define
define|#
directive|define
name|R_028064_CB_COLOR1_SIZE
value|0x028064
end_define

begin_define
define|#
directive|define
name|R_028068_CB_COLOR2_SIZE
value|0x028068
end_define

begin_define
define|#
directive|define
name|R_02806C_CB_COLOR3_SIZE
value|0x02806C
end_define

begin_define
define|#
directive|define
name|R_028070_CB_COLOR4_SIZE
value|0x028070
end_define

begin_define
define|#
directive|define
name|R_028074_CB_COLOR5_SIZE
value|0x028074
end_define

begin_define
define|#
directive|define
name|R_028078_CB_COLOR6_SIZE
value|0x028078
end_define

begin_define
define|#
directive|define
name|R_02807C_CB_COLOR7_SIZE
value|0x02807C
end_define

begin_define
define|#
directive|define
name|R_028238_CB_TARGET_MASK
value|0x028238
end_define

begin_define
define|#
directive|define
name|S_028238_TARGET0_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_028238_TARGET0_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_028238_TARGET0_ENABLE
value|0xFFFFFFF0
end_define

begin_define
define|#
directive|define
name|S_028238_TARGET1_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 4)
end_define

begin_define
define|#
directive|define
name|G_028238_TARGET1_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_028238_TARGET1_ENABLE
value|0xFFFFFF0F
end_define

begin_define
define|#
directive|define
name|S_028238_TARGET2_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 8)
end_define

begin_define
define|#
directive|define
name|G_028238_TARGET2_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_028238_TARGET2_ENABLE
value|0xFFFFF0FF
end_define

begin_define
define|#
directive|define
name|S_028238_TARGET3_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 12)
end_define

begin_define
define|#
directive|define
name|G_028238_TARGET3_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_028238_TARGET3_ENABLE
value|0xFFFF0FFF
end_define

begin_define
define|#
directive|define
name|S_028238_TARGET4_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 16)
end_define

begin_define
define|#
directive|define
name|G_028238_TARGET4_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_028238_TARGET4_ENABLE
value|0xFFF0FFFF
end_define

begin_define
define|#
directive|define
name|S_028238_TARGET5_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 20)
end_define

begin_define
define|#
directive|define
name|G_028238_TARGET5_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_028238_TARGET5_ENABLE
value|0xFF0FFFFF
end_define

begin_define
define|#
directive|define
name|S_028238_TARGET6_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 24)
end_define

begin_define
define|#
directive|define
name|G_028238_TARGET6_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_028238_TARGET6_ENABLE
value|0xF0FFFFFF
end_define

begin_define
define|#
directive|define
name|S_028238_TARGET7_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 28)
end_define

begin_define
define|#
directive|define
name|G_028238_TARGET7_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 28)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_028238_TARGET7_ENABLE
value|0x0FFFFFFF
end_define

begin_define
define|#
directive|define
name|R_02823C_CB_SHADER_MASK
value|0x02823C
end_define

begin_define
define|#
directive|define
name|S_02823C_OUTPUT0_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_02823C_OUTPUT0_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_02823C_OUTPUT0_ENABLE
value|0xFFFFFFF0
end_define

begin_define
define|#
directive|define
name|S_02823C_OUTPUT1_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 4)
end_define

begin_define
define|#
directive|define
name|G_02823C_OUTPUT1_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_02823C_OUTPUT1_ENABLE
value|0xFFFFFF0F
end_define

begin_define
define|#
directive|define
name|S_02823C_OUTPUT2_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 8)
end_define

begin_define
define|#
directive|define
name|G_02823C_OUTPUT2_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_02823C_OUTPUT2_ENABLE
value|0xFFFFF0FF
end_define

begin_define
define|#
directive|define
name|S_02823C_OUTPUT3_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 12)
end_define

begin_define
define|#
directive|define
name|G_02823C_OUTPUT3_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_02823C_OUTPUT3_ENABLE
value|0xFFFF0FFF
end_define

begin_define
define|#
directive|define
name|S_02823C_OUTPUT4_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 16)
end_define

begin_define
define|#
directive|define
name|G_02823C_OUTPUT4_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_02823C_OUTPUT4_ENABLE
value|0xFFF0FFFF
end_define

begin_define
define|#
directive|define
name|S_02823C_OUTPUT5_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 20)
end_define

begin_define
define|#
directive|define
name|G_02823C_OUTPUT5_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_02823C_OUTPUT5_ENABLE
value|0xFF0FFFFF
end_define

begin_define
define|#
directive|define
name|S_02823C_OUTPUT6_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 24)
end_define

begin_define
define|#
directive|define
name|G_02823C_OUTPUT6_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_02823C_OUTPUT6_ENABLE
value|0xF0FFFFFF
end_define

begin_define
define|#
directive|define
name|S_02823C_OUTPUT7_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 28)
end_define

begin_define
define|#
directive|define
name|G_02823C_OUTPUT7_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 28)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_02823C_OUTPUT7_ENABLE
value|0x0FFFFFFF
end_define

begin_define
define|#
directive|define
name|R_028AB0_VGT_STRMOUT_EN
value|0x028AB0
end_define

begin_define
define|#
directive|define
name|S_028AB0_STREAMOUT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_028AB0_STREAMOUT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_028AB0_STREAMOUT
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|R_028B20_VGT_STRMOUT_BUFFER_EN
value|0x028B20
end_define

begin_define
define|#
directive|define
name|S_028B20_BUFFER_0_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_028B20_BUFFER_0_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_028B20_BUFFER_0_EN
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_028B20_BUFFER_1_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 1)
end_define

begin_define
define|#
directive|define
name|G_028B20_BUFFER_1_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_028B20_BUFFER_1_EN
value|0xFFFFFFFD
end_define

begin_define
define|#
directive|define
name|S_028B20_BUFFER_2_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 2)
end_define

begin_define
define|#
directive|define
name|G_028B20_BUFFER_2_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 2)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_028B20_BUFFER_2_EN
value|0xFFFFFFFB
end_define

begin_define
define|#
directive|define
name|S_028B20_BUFFER_3_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 3)
end_define

begin_define
define|#
directive|define
name|G_028B20_BUFFER_3_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 3)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_028B20_BUFFER_3_EN
value|0xFFFFFFF7
end_define

begin_define
define|#
directive|define
name|S_028B20_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFFFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_028B20_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|C_028B20_SIZE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|R_038000_SQ_TEX_RESOURCE_WORD0_0
value|0x038000
end_define

begin_define
define|#
directive|define
name|S_038000_DIM
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 0)
end_define

begin_define
define|#
directive|define
name|G_038000_DIM
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_038000_DIM
value|0xFFFFFFF8
end_define

begin_define
define|#
directive|define
name|V_038000_SQ_TEX_DIM_1D
value|0x00000000
end_define

begin_define
define|#
directive|define
name|V_038000_SQ_TEX_DIM_2D
value|0x00000001
end_define

begin_define
define|#
directive|define
name|V_038000_SQ_TEX_DIM_3D
value|0x00000002
end_define

begin_define
define|#
directive|define
name|V_038000_SQ_TEX_DIM_CUBEMAP
value|0x00000003
end_define

begin_define
define|#
directive|define
name|V_038000_SQ_TEX_DIM_1D_ARRAY
value|0x00000004
end_define

begin_define
define|#
directive|define
name|V_038000_SQ_TEX_DIM_2D_ARRAY
value|0x00000005
end_define

begin_define
define|#
directive|define
name|V_038000_SQ_TEX_DIM_2D_MSAA
value|0x00000006
end_define

begin_define
define|#
directive|define
name|V_038000_SQ_TEX_DIM_2D_ARRAY_MSAA
value|0x00000007
end_define

begin_define
define|#
directive|define
name|S_038000_TILE_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 3)
end_define

begin_define
define|#
directive|define
name|G_038000_TILE_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 3)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_038000_TILE_MODE
value|0xFFFFFF87
end_define

begin_define
define|#
directive|define
name|V_038000_ARRAY_LINEAR_GENERAL
value|0x00000000
end_define

begin_define
define|#
directive|define
name|V_038000_ARRAY_LINEAR_ALIGNED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|V_038000_ARRAY_1D_TILED_THIN1
value|0x00000002
end_define

begin_define
define|#
directive|define
name|V_038000_ARRAY_2D_TILED_THIN1
value|0x00000004
end_define

begin_define
define|#
directive|define
name|S_038000_TILE_TYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 7)
end_define

begin_define
define|#
directive|define
name|G_038000_TILE_TYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 7)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_038000_TILE_TYPE
value|0xFFFFFF7F
end_define

begin_define
define|#
directive|define
name|S_038000_PITCH
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7FF)<< 8)
end_define

begin_define
define|#
directive|define
name|G_038000_PITCH
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x7FF)
end_define

begin_define
define|#
directive|define
name|C_038000_PITCH
value|0xFFF800FF
end_define

begin_define
define|#
directive|define
name|S_038000_TEX_WIDTH
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1FFF)<< 19)
end_define

begin_define
define|#
directive|define
name|G_038000_TEX_WIDTH
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 19)& 0x1FFF)
end_define

begin_define
define|#
directive|define
name|C_038000_TEX_WIDTH
value|0x0007FFFF
end_define

begin_define
define|#
directive|define
name|R_038004_SQ_TEX_RESOURCE_WORD1_0
value|0x038004
end_define

begin_define
define|#
directive|define
name|S_038004_TEX_HEIGHT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1FFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_038004_TEX_HEIGHT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1FFF)
end_define

begin_define
define|#
directive|define
name|C_038004_TEX_HEIGHT
value|0xFFFFE000
end_define

begin_define
define|#
directive|define
name|S_038004_TEX_DEPTH
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1FFF)<< 13)
end_define

begin_define
define|#
directive|define
name|G_038004_TEX_DEPTH
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 13)& 0x1FFF)
end_define

begin_define
define|#
directive|define
name|C_038004_TEX_DEPTH
value|0xFC001FFF
end_define

begin_define
define|#
directive|define
name|S_038004_DATA_FORMAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3F)<< 26)
end_define

begin_define
define|#
directive|define
name|G_038004_DATA_FORMAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 26)& 0x3F)
end_define

begin_define
define|#
directive|define
name|C_038004_DATA_FORMAT
value|0x03FFFFFF
end_define

begin_define
define|#
directive|define
name|V_038004_COLOR_INVALID
value|0x00000000
end_define

begin_define
define|#
directive|define
name|V_038004_COLOR_8
value|0x00000001
end_define

begin_define
define|#
directive|define
name|V_038004_COLOR_4_4
value|0x00000002
end_define

begin_define
define|#
directive|define
name|V_038004_COLOR_3_3_2
value|0x00000003
end_define

begin_define
define|#
directive|define
name|V_038004_COLOR_16
value|0x00000005
end_define

begin_define
define|#
directive|define
name|V_038004_COLOR_16_FLOAT
value|0x00000006
end_define

begin_define
define|#
directive|define
name|V_038004_COLOR_8_8
value|0x00000007
end_define

begin_define
define|#
directive|define
name|V_038004_COLOR_5_6_5
value|0x00000008
end_define

begin_define
define|#
directive|define
name|V_038004_COLOR_6_5_5
value|0x00000009
end_define

begin_define
define|#
directive|define
name|V_038004_COLOR_1_5_5_5
value|0x0000000A
end_define

begin_define
define|#
directive|define
name|V_038004_COLOR_4_4_4_4
value|0x0000000B
end_define

begin_define
define|#
directive|define
name|V_038004_COLOR_5_5_5_1
value|0x0000000C
end_define

begin_define
define|#
directive|define
name|V_038004_COLOR_32
value|0x0000000D
end_define

begin_define
define|#
directive|define
name|V_038004_COLOR_32_FLOAT
value|0x0000000E
end_define

begin_define
define|#
directive|define
name|V_038004_COLOR_16_16
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|V_038004_COLOR_16_16_FLOAT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|V_038004_COLOR_8_24
value|0x00000011
end_define

begin_define
define|#
directive|define
name|V_038004_COLOR_8_24_FLOAT
value|0x00000012
end_define

begin_define
define|#
directive|define
name|V_038004_COLOR_24_8
value|0x00000013
end_define

begin_define
define|#
directive|define
name|V_038004_COLOR_24_8_FLOAT
value|0x00000014
end_define

begin_define
define|#
directive|define
name|V_038004_COLOR_10_11_11
value|0x00000015
end_define

begin_define
define|#
directive|define
name|V_038004_COLOR_10_11_11_FLOAT
value|0x00000016
end_define

begin_define
define|#
directive|define
name|V_038004_COLOR_11_11_10
value|0x00000017
end_define

begin_define
define|#
directive|define
name|V_038004_COLOR_11_11_10_FLOAT
value|0x00000018
end_define

begin_define
define|#
directive|define
name|V_038004_COLOR_2_10_10_10
value|0x00000019
end_define

begin_define
define|#
directive|define
name|V_038004_COLOR_8_8_8_8
value|0x0000001A
end_define

begin_define
define|#
directive|define
name|V_038004_COLOR_10_10_10_2
value|0x0000001B
end_define

begin_define
define|#
directive|define
name|V_038004_COLOR_X24_8_32_FLOAT
value|0x0000001C
end_define

begin_define
define|#
directive|define
name|V_038004_COLOR_32_32
value|0x0000001D
end_define

begin_define
define|#
directive|define
name|V_038004_COLOR_32_32_FLOAT
value|0x0000001E
end_define

begin_define
define|#
directive|define
name|V_038004_COLOR_16_16_16_16
value|0x0000001F
end_define

begin_define
define|#
directive|define
name|V_038004_COLOR_16_16_16_16_FLOAT
value|0x00000020
end_define

begin_define
define|#
directive|define
name|V_038004_COLOR_32_32_32_32
value|0x00000022
end_define

begin_define
define|#
directive|define
name|V_038004_COLOR_32_32_32_32_FLOAT
value|0x00000023
end_define

begin_define
define|#
directive|define
name|V_038004_FMT_1
value|0x00000025
end_define

begin_define
define|#
directive|define
name|V_038004_FMT_GB_GR
value|0x00000027
end_define

begin_define
define|#
directive|define
name|V_038004_FMT_BG_RG
value|0x00000028
end_define

begin_define
define|#
directive|define
name|V_038004_FMT_32_AS_8
value|0x00000029
end_define

begin_define
define|#
directive|define
name|V_038004_FMT_32_AS_8_8
value|0x0000002A
end_define

begin_define
define|#
directive|define
name|V_038004_FMT_5_9_9_9_SHAREDEXP
value|0x0000002B
end_define

begin_define
define|#
directive|define
name|V_038004_FMT_8_8_8
value|0x0000002C
end_define

begin_define
define|#
directive|define
name|V_038004_FMT_16_16_16
value|0x0000002D
end_define

begin_define
define|#
directive|define
name|V_038004_FMT_16_16_16_FLOAT
value|0x0000002E
end_define

begin_define
define|#
directive|define
name|V_038004_FMT_32_32_32
value|0x0000002F
end_define

begin_define
define|#
directive|define
name|V_038004_FMT_32_32_32_FLOAT
value|0x00000030
end_define

begin_define
define|#
directive|define
name|V_038004_FMT_BC1
value|0x00000031
end_define

begin_define
define|#
directive|define
name|V_038004_FMT_BC2
value|0x00000032
end_define

begin_define
define|#
directive|define
name|V_038004_FMT_BC3
value|0x00000033
end_define

begin_define
define|#
directive|define
name|V_038004_FMT_BC4
value|0x00000034
end_define

begin_define
define|#
directive|define
name|V_038004_FMT_BC5
value|0x00000035
end_define

begin_define
define|#
directive|define
name|V_038004_FMT_BC6
value|0x00000036
end_define

begin_define
define|#
directive|define
name|V_038004_FMT_BC7
value|0x00000037
end_define

begin_define
define|#
directive|define
name|V_038004_FMT_32_AS_32_32_32_32
value|0x00000038
end_define

begin_define
define|#
directive|define
name|R_038010_SQ_TEX_RESOURCE_WORD4_0
value|0x038010
end_define

begin_define
define|#
directive|define
name|S_038010_FORMAT_COMP_X
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 0)
end_define

begin_define
define|#
directive|define
name|G_038010_FORMAT_COMP_X
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_038010_FORMAT_COMP_X
value|0xFFFFFFFC
end_define

begin_define
define|#
directive|define
name|S_038010_FORMAT_COMP_Y
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 2)
end_define

begin_define
define|#
directive|define
name|G_038010_FORMAT_COMP_Y
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 2)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_038010_FORMAT_COMP_Y
value|0xFFFFFFF3
end_define

begin_define
define|#
directive|define
name|S_038010_FORMAT_COMP_Z
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 4)
end_define

begin_define
define|#
directive|define
name|G_038010_FORMAT_COMP_Z
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_038010_FORMAT_COMP_Z
value|0xFFFFFFCF
end_define

begin_define
define|#
directive|define
name|S_038010_FORMAT_COMP_W
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 6)
end_define

begin_define
define|#
directive|define
name|G_038010_FORMAT_COMP_W
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 6)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_038010_FORMAT_COMP_W
value|0xFFFFFF3F
end_define

begin_define
define|#
directive|define
name|S_038010_NUM_FORMAT_ALL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 8)
end_define

begin_define
define|#
directive|define
name|G_038010_NUM_FORMAT_ALL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_038010_NUM_FORMAT_ALL
value|0xFFFFFCFF
end_define

begin_define
define|#
directive|define
name|S_038010_SRF_MODE_ALL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 10)
end_define

begin_define
define|#
directive|define
name|G_038010_SRF_MODE_ALL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_038010_SRF_MODE_ALL
value|0xFFFFFBFF
end_define

begin_define
define|#
directive|define
name|S_038010_FORCE_DEGAMMA
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 11)
end_define

begin_define
define|#
directive|define
name|G_038010_FORCE_DEGAMMA
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 11)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_038010_FORCE_DEGAMMA
value|0xFFFFF7FF
end_define

begin_define
define|#
directive|define
name|S_038010_ENDIAN_SWAP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 12)
end_define

begin_define
define|#
directive|define
name|G_038010_ENDIAN_SWAP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_038010_ENDIAN_SWAP
value|0xFFFFCFFF
end_define

begin_define
define|#
directive|define
name|S_038010_REQUEST_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 14)
end_define

begin_define
define|#
directive|define
name|G_038010_REQUEST_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 14)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_038010_REQUEST_SIZE
value|0xFFFF3FFF
end_define

begin_define
define|#
directive|define
name|S_038010_DST_SEL_X
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 16)
end_define

begin_define
define|#
directive|define
name|G_038010_DST_SEL_X
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_038010_DST_SEL_X
value|0xFFF8FFFF
end_define

begin_define
define|#
directive|define
name|S_038010_DST_SEL_Y
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 19)
end_define

begin_define
define|#
directive|define
name|G_038010_DST_SEL_Y
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 19)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_038010_DST_SEL_Y
value|0xFFC7FFFF
end_define

begin_define
define|#
directive|define
name|S_038010_DST_SEL_Z
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 22)
end_define

begin_define
define|#
directive|define
name|G_038010_DST_SEL_Z
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 22)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_038010_DST_SEL_Z
value|0xFE3FFFFF
end_define

begin_define
define|#
directive|define
name|S_038010_DST_SEL_W
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 25)
end_define

begin_define
define|#
directive|define
name|G_038010_DST_SEL_W
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 25)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_038010_DST_SEL_W
value|0xF1FFFFFF
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
name|S_038010_BASE_LEVEL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 28)
end_define

begin_define
define|#
directive|define
name|G_038010_BASE_LEVEL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 28)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_038010_BASE_LEVEL
value|0x0FFFFFFF
end_define

begin_define
define|#
directive|define
name|R_038014_SQ_TEX_RESOURCE_WORD5_0
value|0x038014
end_define

begin_define
define|#
directive|define
name|S_038014_LAST_LEVEL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_038014_LAST_LEVEL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_038014_LAST_LEVEL
value|0xFFFFFFF0
end_define

begin_define
define|#
directive|define
name|S_038014_BASE_ARRAY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1FFF)<< 4)
end_define

begin_define
define|#
directive|define
name|G_038014_BASE_ARRAY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x1FFF)
end_define

begin_define
define|#
directive|define
name|C_038014_BASE_ARRAY
value|0xFFFE000F
end_define

begin_define
define|#
directive|define
name|S_038014_LAST_ARRAY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1FFF)<< 17)
end_define

begin_define
define|#
directive|define
name|G_038014_LAST_ARRAY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 17)& 0x1FFF)
end_define

begin_define
define|#
directive|define
name|C_038014_LAST_ARRAY
value|0xC001FFFF
end_define

begin_define
define|#
directive|define
name|R_0288A8_SQ_ESGS_RING_ITEMSIZE
value|0x0288A8
end_define

begin_define
define|#
directive|define
name|S_0288A8_ITEMSIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7FFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_0288A8_ITEMSIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x7FFF)
end_define

begin_define
define|#
directive|define
name|C_0288A8_ITEMSIZE
value|0xFFFF8000
end_define

begin_define
define|#
directive|define
name|R_008C44_SQ_ESGS_RING_SIZE
value|0x008C44
end_define

begin_define
define|#
directive|define
name|S_008C44_MEM_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFFFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_008C44_MEM_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|C_008C44_MEM_SIZE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|R_0288B0_SQ_ESTMP_RING_ITEMSIZE
value|0x0288B0
end_define

begin_define
define|#
directive|define
name|S_0288B0_ITEMSIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7FFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_0288B0_ITEMSIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x7FFF)
end_define

begin_define
define|#
directive|define
name|C_0288B0_ITEMSIZE
value|0xFFFF8000
end_define

begin_define
define|#
directive|define
name|R_008C54_SQ_ESTMP_RING_SIZE
value|0x008C54
end_define

begin_define
define|#
directive|define
name|S_008C54_MEM_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFFFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_008C54_MEM_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|C_008C54_MEM_SIZE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|R_0288C0_SQ_FBUF_RING_ITEMSIZE
value|0x0288C0
end_define

begin_define
define|#
directive|define
name|S_0288C0_ITEMSIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7FFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_0288C0_ITEMSIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x7FFF)
end_define

begin_define
define|#
directive|define
name|C_0288C0_ITEMSIZE
value|0xFFFF8000
end_define

begin_define
define|#
directive|define
name|R_008C74_SQ_FBUF_RING_SIZE
value|0x008C74
end_define

begin_define
define|#
directive|define
name|S_008C74_MEM_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFFFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_008C74_MEM_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|C_008C74_MEM_SIZE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|R_0288B4_SQ_GSTMP_RING_ITEMSIZE
value|0x0288B4
end_define

begin_define
define|#
directive|define
name|S_0288B4_ITEMSIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7FFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_0288B4_ITEMSIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x7FFF)
end_define

begin_define
define|#
directive|define
name|C_0288B4_ITEMSIZE
value|0xFFFF8000
end_define

begin_define
define|#
directive|define
name|R_008C5C_SQ_GSTMP_RING_SIZE
value|0x008C5C
end_define

begin_define
define|#
directive|define
name|S_008C5C_MEM_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFFFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_008C5C_MEM_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|C_008C5C_MEM_SIZE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|R_0288AC_SQ_GSVS_RING_ITEMSIZE
value|0x0288AC
end_define

begin_define
define|#
directive|define
name|S_0288AC_ITEMSIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7FFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_0288AC_ITEMSIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x7FFF)
end_define

begin_define
define|#
directive|define
name|C_0288AC_ITEMSIZE
value|0xFFFF8000
end_define

begin_define
define|#
directive|define
name|R_008C4C_SQ_GSVS_RING_SIZE
value|0x008C4C
end_define

begin_define
define|#
directive|define
name|S_008C4C_MEM_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFFFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_008C4C_MEM_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|C_008C4C_MEM_SIZE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|R_0288BC_SQ_PSTMP_RING_ITEMSIZE
value|0x0288BC
end_define

begin_define
define|#
directive|define
name|S_0288BC_ITEMSIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7FFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_0288BC_ITEMSIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x7FFF)
end_define

begin_define
define|#
directive|define
name|C_0288BC_ITEMSIZE
value|0xFFFF8000
end_define

begin_define
define|#
directive|define
name|R_008C6C_SQ_PSTMP_RING_SIZE
value|0x008C6C
end_define

begin_define
define|#
directive|define
name|S_008C6C_MEM_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFFFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_008C6C_MEM_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|C_008C6C_MEM_SIZE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|R_0288C4_SQ_REDUC_RING_ITEMSIZE
value|0x0288C4
end_define

begin_define
define|#
directive|define
name|S_0288C4_ITEMSIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7FFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_0288C4_ITEMSIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x7FFF)
end_define

begin_define
define|#
directive|define
name|C_0288C4_ITEMSIZE
value|0xFFFF8000
end_define

begin_define
define|#
directive|define
name|R_008C7C_SQ_REDUC_RING_SIZE
value|0x008C7C
end_define

begin_define
define|#
directive|define
name|S_008C7C_MEM_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFFFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_008C7C_MEM_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|C_008C7C_MEM_SIZE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|R_0288B8_SQ_VSTMP_RING_ITEMSIZE
value|0x0288B8
end_define

begin_define
define|#
directive|define
name|S_0288B8_ITEMSIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7FFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_0288B8_ITEMSIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x7FFF)
end_define

begin_define
define|#
directive|define
name|C_0288B8_ITEMSIZE
value|0xFFFF8000
end_define

begin_define
define|#
directive|define
name|R_008C64_SQ_VSTMP_RING_SIZE
value|0x008C64
end_define

begin_define
define|#
directive|define
name|S_008C64_MEM_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFFFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_008C64_MEM_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|C_008C64_MEM_SIZE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|R_0288C8_SQ_GS_VERT_ITEMSIZE
value|0x0288C8
end_define

begin_define
define|#
directive|define
name|S_0288C8_ITEMSIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7FFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_0288C8_ITEMSIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x7FFF)
end_define

begin_define
define|#
directive|define
name|C_0288C8_ITEMSIZE
value|0xFFFF8000
end_define

begin_define
define|#
directive|define
name|R_028010_DB_DEPTH_INFO
value|0x028010
end_define

begin_define
define|#
directive|define
name|S_028010_FORMAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 0)
end_define

begin_define
define|#
directive|define
name|G_028010_FORMAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_028010_FORMAT
value|0xFFFFFFF8
end_define

begin_define
define|#
directive|define
name|V_028010_DEPTH_INVALID
value|0x00000000
end_define

begin_define
define|#
directive|define
name|V_028010_DEPTH_16
value|0x00000001
end_define

begin_define
define|#
directive|define
name|V_028010_DEPTH_X8_24
value|0x00000002
end_define

begin_define
define|#
directive|define
name|V_028010_DEPTH_8_24
value|0x00000003
end_define

begin_define
define|#
directive|define
name|V_028010_DEPTH_X8_24_FLOAT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|V_028010_DEPTH_8_24_FLOAT
value|0x00000005
end_define

begin_define
define|#
directive|define
name|V_028010_DEPTH_32_FLOAT
value|0x00000006
end_define

begin_define
define|#
directive|define
name|V_028010_DEPTH_X24_8_32_FLOAT
value|0x00000007
end_define

begin_define
define|#
directive|define
name|S_028010_READ_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 3)
end_define

begin_define
define|#
directive|define
name|G_028010_READ_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 3)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_028010_READ_SIZE
value|0xFFFFFFF7
end_define

begin_define
define|#
directive|define
name|S_028010_ARRAY_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 15)
end_define

begin_define
define|#
directive|define
name|G_028010_ARRAY_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 15)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_028010_ARRAY_MODE
value|0xFFF87FFF
end_define

begin_define
define|#
directive|define
name|V_028010_ARRAY_1D_TILED_THIN1
value|0x00000002
end_define

begin_define
define|#
directive|define
name|V_028010_ARRAY_2D_TILED_THIN1
value|0x00000004
end_define

begin_define
define|#
directive|define
name|S_028010_TILE_SURFACE_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 25)
end_define

begin_define
define|#
directive|define
name|G_028010_TILE_SURFACE_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 25)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_028010_TILE_SURFACE_ENABLE
value|0xFDFFFFFF
end_define

begin_define
define|#
directive|define
name|S_028010_TILE_COMPACT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 26)
end_define

begin_define
define|#
directive|define
name|G_028010_TILE_COMPACT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 26)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_028010_TILE_COMPACT
value|0xFBFFFFFF
end_define

begin_define
define|#
directive|define
name|S_028010_ZRANGE_PRECISION
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 31)
end_define

begin_define
define|#
directive|define
name|G_028010_ZRANGE_PRECISION
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 31)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_028010_ZRANGE_PRECISION
value|0x7FFFFFFF
end_define

begin_define
define|#
directive|define
name|R_028000_DB_DEPTH_SIZE
value|0x028000
end_define

begin_define
define|#
directive|define
name|S_028000_PITCH_TILE_MAX
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3FF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_028000_PITCH_TILE_MAX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x3FF)
end_define

begin_define
define|#
directive|define
name|C_028000_PITCH_TILE_MAX
value|0xFFFFFC00
end_define

begin_define
define|#
directive|define
name|S_028000_SLICE_TILE_MAX
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFFF)<< 10)
end_define

begin_define
define|#
directive|define
name|G_028000_SLICE_TILE_MAX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)& 0xFFFFF)
end_define

begin_define
define|#
directive|define
name|C_028000_SLICE_TILE_MAX
value|0xC00003FF
end_define

begin_define
define|#
directive|define
name|R_028004_DB_DEPTH_VIEW
value|0x028004
end_define

begin_define
define|#
directive|define
name|S_028004_SLICE_START
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7FF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_028004_SLICE_START
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x7FF)
end_define

begin_define
define|#
directive|define
name|C_028004_SLICE_START
value|0xFFFFF800
end_define

begin_define
define|#
directive|define
name|S_028004_SLICE_MAX
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7FF)<< 13)
end_define

begin_define
define|#
directive|define
name|G_028004_SLICE_MAX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 13)& 0x7FF)
end_define

begin_define
define|#
directive|define
name|C_028004_SLICE_MAX
value|0xFF001FFF
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

