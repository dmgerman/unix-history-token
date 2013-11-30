begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2010 Advanced Micro Devices, Inc.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * Authors: Alex Deucher  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NI_H
end_ifndef

begin_define
define|#
directive|define
name|NI_H
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
name|CAYMAN_MAX_SH_GPRS
value|256
end_define

begin_define
define|#
directive|define
name|CAYMAN_MAX_TEMP_GPRS
value|16
end_define

begin_define
define|#
directive|define
name|CAYMAN_MAX_SH_THREADS
value|256
end_define

begin_define
define|#
directive|define
name|CAYMAN_MAX_SH_STACK_ENTRIES
value|4096
end_define

begin_define
define|#
directive|define
name|CAYMAN_MAX_FRC_EOV_CNT
value|16384
end_define

begin_define
define|#
directive|define
name|CAYMAN_MAX_BACKENDS
value|8
end_define

begin_define
define|#
directive|define
name|CAYMAN_MAX_BACKENDS_MASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|CAYMAN_MAX_BACKENDS_PER_SE_MASK
value|0xF
end_define

begin_define
define|#
directive|define
name|CAYMAN_MAX_SIMDS
value|16
end_define

begin_define
define|#
directive|define
name|CAYMAN_MAX_SIMDS_MASK
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|CAYMAN_MAX_SIMDS_PER_SE_MASK
value|0xFFF
end_define

begin_define
define|#
directive|define
name|CAYMAN_MAX_PIPES
value|8
end_define

begin_define
define|#
directive|define
name|CAYMAN_MAX_PIPES_MASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|CAYMAN_MAX_LDS_NUM
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|CAYMAN_MAX_TCC
value|16
end_define

begin_define
define|#
directive|define
name|CAYMAN_MAX_TCC_MASK
value|0xFF
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
name|ARUBA_GB_ADDR_CONFIG_GOLDEN
value|0x12010001
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
name|SRBM_GFX_CNTL
value|0x0E44
end_define

begin_define
define|#
directive|define
name|RINGID
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 0)
end_define

begin_define
define|#
directive|define
name|VMID
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 0)
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
name|SOFT_RESET_DMA1
value|(1<< 6)
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
name|ENABLE_L2_PDE0_CACHE_LRU_UPDATE_BY_WRITE
value|(1<< 10)
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
name|CONTEXT1_IDENTITY_ACCESS_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 3)<< 18)
end_define

begin_comment
comment|/* CONTEXT1_IDENTITY_ACCESS_MODE  * 0 physical = logical  * 1 logical via context1 page table  * 2 inside identity aperture use translation, outside physical = logical  * 3 inside identity aperture physical = logical, outside use translation  */
end_comment

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
name|L2_CACHE_BIGK_ASSOCIATIVITY
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|L2_CACHE_BIGK_FRAGMENT_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 15)
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
name|RANGE_PROTECTION_FAULT_ENABLE_INTERRUPT
value|(1<< 3)
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
name|DUMMY_PAGE_PROTECTION_FAULT_ENABLE_INTERRUPT
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|DUMMY_PAGE_PROTECTION_FAULT_ENABLE_DEFAULT
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|PDE0_PROTECTION_FAULT_ENABLE_INTERRUPT
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|PDE0_PROTECTION_FAULT_ENABLE_DEFAULT
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|VALID_PROTECTION_FAULT_ENABLE_INTERRUPT
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|VALID_PROTECTION_FAULT_ENABLE_DEFAULT
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|READ_PROTECTION_FAULT_ENABLE_INTERRUPT
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|READ_PROTECTION_FAULT_ENABLE_DEFAULT
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|WRITE_PROTECTION_FAULT_ENABLE_INTERRUPT
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|WRITE_PROTECTION_FAULT_ENABLE_DEFAULT
value|(1<< 19)
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
name|VM_CONTEXT0_CNTL2
value|0x1430
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
name|VM_INVALIDATE_REQUEST
value|0x1478
end_define

begin_define
define|#
directive|define
name|VM_INVALIDATE_RESPONSE
value|0x147c
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
name|VM_CONTEXT1_PROTECTION_FAULT_DEFAULT_ADDR
value|0x151c
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
name|VM_CONTEXT0_PAGE_TABLE_START_ADDR
value|0x155C
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
name|MC_VM_SYSTEM_APERTURE_LOW_ADDR
value|0x2034
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
name|MC_VM_SYSTEM_APERTURE_DEFAULT_ADDR
value|0x203C
end_define

begin_define
define|#
directive|define
name|MC_VM_MX_L1_TLB_CNTL
value|0x2064
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
name|ENABLE_ADVANCED_DRIVER_MODEL
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|FUS_MC_VM_FB_OFFSET
value|0x2068
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
name|MC_SEQ_SUP_CNTL
value|0x28c8
end_define

begin_define
define|#
directive|define
name|RUN_MASK
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MC_SEQ_SUP_PGM
value|0x28cc
end_define

begin_define
define|#
directive|define
name|MC_IO_PAD_CNTL_D0
value|0x29d0
end_define

begin_define
define|#
directive|define
name|MEM_FALL_OUT_CMD
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|MC_SEQ_MISC0
value|0x2a00
end_define

begin_define
define|#
directive|define
name|MC_SEQ_MISC0_GDDR5_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|MC_SEQ_MISC0_GDDR5_MASK
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|MC_SEQ_MISC0_GDDR5_VALUE
value|5
end_define

begin_define
define|#
directive|define
name|MC_SEQ_IO_DEBUG_INDEX
value|0x2a44
end_define

begin_define
define|#
directive|define
name|MC_SEQ_IO_DEBUG_DATA
value|0x2a48
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
name|GC_USER_SYS_RB_BACKEND_DISABLE
value|0x3F8C
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
name|CGTS_USER_SYS_TCC_DISABLE
value|0x3F94
end_define

begin_define
define|#
directive|define
name|RLC_GFX_INDEX
value|0x3FC4
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
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|RING2_RQ_PENDING
value|(1<< 4)
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
name|RING1_RQ_PENDING
value|(1<< 6)
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
name|GDS_DMA_RQ_PENDING
value|(1<< 9)
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
name|GDS_BUSY
value|(1<< 15)
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
name|IA_BUSY_NO_DMA
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|IA_BUSY
value|(1<< 19)
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
value|(1U<< 31)
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
name|SE_VGT_BUSY
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|SE_PA_BUSY
value|(1<< 24)
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
value|(1U<< 31)
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
name|SOFT_RESET_GDS
value|(1<< 4)
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
name|SOFT_RESET_VGT
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|SOFT_RESET_IA
value|(1<< 15)
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
value|(1U<< 31)
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
name|CP_COHER_CNTL2
value|0x85E8
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
name|CP_RB2_RPTR
value|0x86f8
end_define

begin_define
define|#
directive|define
name|CP_RB1_RPTR
value|0x86fc
end_define

begin_define
define|#
directive|define
name|CP_RB0_RPTR
value|0x8700
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
name|CP_MEQ_THRESHOLDS
value|0x8764
end_define

begin_define
define|#
directive|define
name|MEQ1_START
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|MEQ2_START
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
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
name|CC_GC_SHADER_PIPE_CONFIG
value|0x8950
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
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|INACTIVE_SIMDS_SHIFT
value|16
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
name|VGT_TF_RING_SIZE
value|0x8988
end_define

begin_define
define|#
directive|define
name|VGT_OFFCHIP_LDS_BASE
value|0x89b4
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
name|GFX_PRIO
parameter_list|(
name|x
parameter_list|)
value|((x)<< 2)
end_define

begin_define
define|#
directive|define
name|CS1_PRIO
parameter_list|(
name|x
parameter_list|)
value|((x)<< 4)
end_define

begin_define
define|#
directive|define
name|CS2_PRIO
parameter_list|(
name|x
parameter_list|)
value|((x)<< 6)
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
name|SQ_ESGS_RING_SIZE
value|0x8c44
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
name|SQ_DYN_GPR_CNTL_PS_FLUSH_REQ
value|0x8D8C
end_define

begin_define
define|#
directive|define
name|DYN_GPR_ENABLE
value|(1<< 8)
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
name|CRC_SIMD_ID_WADDR_DISABLE
value|(1<< 8)
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
name|CGTS_USER_TCC_DISABLE
value|0x914C
end_define

begin_define
define|#
directive|define
name|TCC_DISABLE_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|TCC_DISABLE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|CGTS_SM_CTRL_REG
value|0x9150
end_define

begin_define
define|#
directive|define
name|OVERRIDE
value|(1<< 21)
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
value|0x00000007
end_define

begin_define
define|#
directive|define
name|NUM_PIPES_SHIFT
value|0
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
name|PIPE_INTERLEAVE_SIZE_MASK
value|0x00000070
end_define

begin_define
define|#
directive|define
name|PIPE_INTERLEAVE_SIZE_SHIFT
value|4
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
name|NUM_SHADER_ENGINES_MASK
value|0x00003000
end_define

begin_define
define|#
directive|define
name|NUM_SHADER_ENGINES_SHIFT
value|12
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
name|SHADER_ENGINE_TILE_SIZE_MASK
value|0x00070000
end_define

begin_define
define|#
directive|define
name|SHADER_ENGINE_TILE_SIZE_SHIFT
value|16
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
name|NUM_GPUS_MASK
value|0x00700000
end_define

begin_define
define|#
directive|define
name|NUM_GPUS_SHIFT
value|20
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
name|MULTI_GPU_TILE_SIZE_MASK
value|0x03000000
end_define

begin_define
define|#
directive|define
name|MULTI_GPU_TILE_SIZE_SHIFT
value|24
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
name|ROW_SIZE_MASK
value|0x30000000
end_define

begin_define
define|#
directive|define
name|ROW_SIZE_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|NUM_LOWER_PIPES
parameter_list|(
name|x
parameter_list|)
value|((x)<< 30)
end_define

begin_define
define|#
directive|define
name|NUM_LOWER_PIPES_MASK
value|0x40000000
end_define

begin_define
define|#
directive|define
name|NUM_LOWER_PIPES_SHIFT
value|30
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
name|GC_USER_RB_BACKEND_DISABLE
value|0x9B7C
end_define

begin_define
define|#
directive|define
name|BACKEND_DISABLE_MASK
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|BACKEND_DISABLE_SHIFT
value|16
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
name|CP_RB0_BASE
value|0xC100
end_define

begin_define
define|#
directive|define
name|CP_RB0_CNTL
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
name|CP_RB0_RPTR_ADDR
value|0xC10C
end_define

begin_define
define|#
directive|define
name|CP_RB0_RPTR_ADDR_HI
value|0xC110
end_define

begin_define
define|#
directive|define
name|CP_RB0_WPTR
value|0xC114
end_define

begin_define
define|#
directive|define
name|CP_INT_CNTL
value|0xC124
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
name|TIME_STAMP_INT_ENABLE
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|CP_RB1_BASE
value|0xC180
end_define

begin_define
define|#
directive|define
name|CP_RB1_CNTL
value|0xC184
end_define

begin_define
define|#
directive|define
name|CP_RB1_RPTR_ADDR
value|0xC188
end_define

begin_define
define|#
directive|define
name|CP_RB1_RPTR_ADDR_HI
value|0xC18C
end_define

begin_define
define|#
directive|define
name|CP_RB1_WPTR
value|0xC190
end_define

begin_define
define|#
directive|define
name|CP_RB2_BASE
value|0xC194
end_define

begin_define
define|#
directive|define
name|CP_RB2_CNTL
value|0xC198
end_define

begin_define
define|#
directive|define
name|CP_RB2_RPTR_ADDR
value|0xC19C
end_define

begin_define
define|#
directive|define
name|CP_RB2_RPTR_ADDR_HI
value|0xC1A0
end_define

begin_define
define|#
directive|define
name|CP_RB2_WPTR
value|0xC1A4
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
name|CP_ME_RAM_DATA
value|0xC160
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
name|PACKET3_DEALLOC_STATE
value|0x14
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
name|PACKET3_INDIRECT_BUFFER
value|0x32
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
name|PACKET3_WRITE_DATA
value|0x37
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
name|PACKET3_PFP_SYNC_ME
value|0x42
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
name|PACKET3_ME_WRITE
value|0x7A
end_define

begin_comment
comment|/* ASYNC DMA - first instance at 0xd000, second at 0xd800 */
end_comment

begin_define
define|#
directive|define
name|DMA0_REGISTER_OFFSET
value|0x0
end_define

begin_comment
comment|/* not a register */
end_comment

begin_define
define|#
directive|define
name|DMA1_REGISTER_OFFSET
value|0x800
end_define

begin_comment
comment|/* not a register */
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
name|CMD_VMID_FORCE
value|(1U<< 31)
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
name|DMA_TILING_CONFIG
value|0xd0b8
end_define

begin_define
define|#
directive|define
name|DMA_MODE
value|0xd0bc
end_define

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

begin_define
define|#
directive|define
name|DMA_IB_PACKET
parameter_list|(
name|cmd
parameter_list|,
name|vmid
parameter_list|,
name|n
parameter_list|)
value|((((cmd)& 0xF)<< 28) |	\ 					 (((vmid)& 0xF)<< 20) |	\ 					 (((n)& 0xFFFFF)<< 0))
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

