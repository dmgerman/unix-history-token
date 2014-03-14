begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2011 Advanced Micro Devices, Inc.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * Authors: Alex Deucher  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SI_H
end_ifndef

begin_define
define|#
directive|define
name|SI_H
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
name|TAHITI_RB_BITMAP_WIDTH_PER_SH
value|2
end_define

begin_define
define|#
directive|define
name|TAHITI_GB_ADDR_CONFIG_GOLDEN
value|0x12011003
end_define

begin_define
define|#
directive|define
name|VERDE_GB_ADDR_CONFIG_GOLDEN
value|0x12010002
end_define

begin_define
define|#
directive|define
name|CG_MULT_THERMAL_STATUS
value|0x714
end_define

begin_define
define|#
directive|define
name|ASIC_MAX_TEMP
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|ASIC_MAX_TEMP_MASK
value|0x000001ff
end_define

begin_define
define|#
directive|define
name|ASIC_MAX_TEMP_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|CTF_TEMP
parameter_list|(
name|x
parameter_list|)
value|((x)<< 9)
end_define

begin_define
define|#
directive|define
name|CTF_TEMP_MASK
value|0x0003fe00
end_define

begin_define
define|#
directive|define
name|CTF_TEMP_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|SI_MAX_SH_GPRS
value|256
end_define

begin_define
define|#
directive|define
name|SI_MAX_TEMP_GPRS
value|16
end_define

begin_define
define|#
directive|define
name|SI_MAX_SH_THREADS
value|256
end_define

begin_define
define|#
directive|define
name|SI_MAX_SH_STACK_ENTRIES
value|4096
end_define

begin_define
define|#
directive|define
name|SI_MAX_FRC_EOV_CNT
value|16384
end_define

begin_define
define|#
directive|define
name|SI_MAX_BACKENDS
value|8
end_define

begin_define
define|#
directive|define
name|SI_MAX_BACKENDS_MASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|SI_MAX_BACKENDS_PER_SE_MASK
value|0x0F
end_define

begin_define
define|#
directive|define
name|SI_MAX_SIMDS
value|12
end_define

begin_define
define|#
directive|define
name|SI_MAX_SIMDS_MASK
value|0x0FFF
end_define

begin_define
define|#
directive|define
name|SI_MAX_SIMDS_PER_SE_MASK
value|0x00FF
end_define

begin_define
define|#
directive|define
name|SI_MAX_PIPES
value|8
end_define

begin_define
define|#
directive|define
name|SI_MAX_PIPES_MASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|SI_MAX_PIPES_PER_SIMD_MASK
value|0x3F
end_define

begin_define
define|#
directive|define
name|SI_MAX_LDS_NUM
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|SI_MAX_TCC
value|16
end_define

begin_define
define|#
directive|define
name|SI_MAX_TCC_MASK
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|VGA_HDP_CONTROL
value|0x328
end_define

begin_define
define|#
directive|define
name|VGA_MEMORY_DISABLE
value|(1<< 4)
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
name|SRBM_STATUS
value|0xE50
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
name|CC_SYS_RB_BACKEND_DISABLE
value|0xe80
end_define

begin_define
define|#
directive|define
name|GC_USER_SYS_RB_BACKEND_DISABLE
value|0xe84
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
name|L2_CACHE_PTE_ENDIAN_SWAP_MODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 2)
end_define

begin_define
define|#
directive|define
name|L2_CACHE_PDE_ENDIAN_SWAP_MODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 4)
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
value|(((x)& 7)<< 15)
end_define

begin_define
define|#
directive|define
name|CONTEXT1_IDENTITY_ACCESS_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 3)<< 19)
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
name|INVALIDATE_CACHE_MODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 26)
end_define

begin_define
define|#
directive|define
name|INVALIDATE_PTE_AND_PDE_CACHES
value|0
end_define

begin_define
define|#
directive|define
name|INVALIDATE_ONLY_PTE_CACHES
value|1
end_define

begin_define
define|#
directive|define
name|INVALIDATE_ONLY_PDE_CACHES
value|2
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
name|L2_CACHE_UPDATE_MODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 6)
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
name|L2_CACHE_BIGK_ASSOCIATIVITY
value|(1<< 20)
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
name|VM_CONTEXT8_PAGE_TABLE_BASE_ADDR
value|0x1438
end_define

begin_define
define|#
directive|define
name|VM_CONTEXT9_PAGE_TABLE_BASE_ADDR
value|0x143c
end_define

begin_define
define|#
directive|define
name|VM_CONTEXT10_PAGE_TABLE_BASE_ADDR
value|0x1440
end_define

begin_define
define|#
directive|define
name|VM_CONTEXT11_PAGE_TABLE_BASE_ADDR
value|0x1444
end_define

begin_define
define|#
directive|define
name|VM_CONTEXT12_PAGE_TABLE_BASE_ADDR
value|0x1448
end_define

begin_define
define|#
directive|define
name|VM_CONTEXT13_PAGE_TABLE_BASE_ADDR
value|0x144c
end_define

begin_define
define|#
directive|define
name|VM_CONTEXT14_PAGE_TABLE_BASE_ADDR
value|0x1450
end_define

begin_define
define|#
directive|define
name|VM_CONTEXT15_PAGE_TABLE_BASE_ADDR
value|0x1454
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
value|0x153c
end_define

begin_define
define|#
directive|define
name|VM_CONTEXT1_PAGE_TABLE_BASE_ADDR
value|0x1540
end_define

begin_define
define|#
directive|define
name|VM_CONTEXT2_PAGE_TABLE_BASE_ADDR
value|0x1544
end_define

begin_define
define|#
directive|define
name|VM_CONTEXT3_PAGE_TABLE_BASE_ADDR
value|0x1548
end_define

begin_define
define|#
directive|define
name|VM_CONTEXT4_PAGE_TABLE_BASE_ADDR
value|0x154c
end_define

begin_define
define|#
directive|define
name|VM_CONTEXT5_PAGE_TABLE_BASE_ADDR
value|0x1550
end_define

begin_define
define|#
directive|define
name|VM_CONTEXT6_PAGE_TABLE_BASE_ADDR
value|0x1554
end_define

begin_define
define|#
directive|define
name|VM_CONTEXT7_PAGE_TABLE_BASE_ADDR
value|0x1558
end_define

begin_define
define|#
directive|define
name|VM_CONTEXT0_PAGE_TABLE_START_ADDR
value|0x155c
end_define

begin_define
define|#
directive|define
name|VM_CONTEXT1_PAGE_TABLE_START_ADDR
value|0x1560
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
name|VM_CONTEXT1_PAGE_TABLE_END_ADDR
value|0x1580
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
value|0x0000f000
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
name|MC_VM_FB_LOCATION
value|0x2024
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
name|CHANSIZE_OVERRIDE
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|NOOFGROUPS_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|NOOFGROUPS_MASK
value|0x00001000
end_define

begin_define
define|#
directive|define
name|MC_SEQ_TRAIN_WAKEUP_CNTL
value|0x2808
end_define

begin_define
define|#
directive|define
name|TRAIN_DONE_D0
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|TRAIN_DONE_D1
value|(1<< 31)
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
name|MC_VMID
parameter_list|(
name|x
parameter_list|)
value|((x)<< 25)
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
name|HDP_MEM_COHERENCY_FLUSH_CNTL
value|0x5480
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
name|HDP_REG_COHERENCY_FLUSH_CNTL
value|0x54A0
end_define

begin_define
define|#
directive|define
name|DC_LB_MEMORY_SPLIT
value|0x6b0c
end_define

begin_define
define|#
directive|define
name|DC_LB_MEMORY_CONFIG
parameter_list|(
name|x
parameter_list|)
value|((x)<< 20)
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
name|DPG_PIPE_ARBITRATION_CONTROL3
value|0x6cc8
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
name|DPG_PIPE_LATENCY_CONTROL
value|0x6ccc
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
comment|/* 0x6e98, 0x7a98, 0x10698, 0x11298, 0x11e98, 0x12a98 */
end_comment

begin_define
define|#
directive|define
name|CRTC_STATUS_FRAME_COUNT
value|0x6e98
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
name|GRBM_STATUS2
value|0x8008
end_define

begin_define
define|#
directive|define
name|RLC_RQ_PENDING
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RLC_BUSY
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|TC_BUSY
value|(1<< 9)
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
name|SPI_BUSY
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|BCI_BUSY
value|(1<< 23)
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
name|SE_BCI_BUSY
value|(1<< 22)
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
name|SOFT_RESET_RLC
value|(1<< 2)
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
name|SOFT_RESET_BCI
value|(1<< 7)
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
name|SH_INDEX
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
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
name|SH_BROADCAST_WRITES
value|(1<< 29)
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

begin_define
define|#
directive|define
name|CP_STRMOUT_CNTL
value|0x84FC
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
name|CP_ME_CNTL
value|0x86D8
end_define

begin_define
define|#
directive|define
name|CP_CE_HALT
value|(1<< 24)
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
name|CP_ME_HALT
value|(1<< 28)
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
name|VGT_VTX_VECT_EJECT_REG
value|0x88B0
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
name|VGT_ESGS_RING_SIZE
value|0x88C8
end_define

begin_define
define|#
directive|define
name|VGT_GSVS_RING_SIZE
value|0x88CC
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
name|VGT_HS_OFFCHIP_PARAM
value|0x89B0
end_define

begin_define
define|#
directive|define
name|VGT_TF_MEMORY_BASE
value|0x89B8
end_define

begin_define
define|#
directive|define
name|CC_GC_SHADER_ARRAY_CONFIG
value|0x89bc
end_define

begin_define
define|#
directive|define
name|INACTIVE_CUS_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|INACTIVE_CUS_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|GC_USER_SHADER_ARRAY_CONFIG
value|0x89c0
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
name|PA_SC_FIFO_SIZE
value|0x8BCC
end_define

begin_define
define|#
directive|define
name|SC_FRONTEND_PRIM_FIFO_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|SC_BACKEND_PRIM_FIFO_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 6)
end_define

begin_define
define|#
directive|define
name|SC_HIZ_TILE_FIFO_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 15)
end_define

begin_define
define|#
directive|define
name|SC_EARLYZ_TILE_FIFO_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 23)
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
name|SQ_CONFIG
value|0x8C00
end_define

begin_define
define|#
directive|define
name|SQC_CACHES
value|0x8C08
end_define

begin_define
define|#
directive|define
name|SX_DEBUG_1
value|0x9060
end_define

begin_define
define|#
directive|define
name|SPI_STATIC_THREAD_MGMT_1
value|0x90E0
end_define

begin_define
define|#
directive|define
name|SPI_STATIC_THREAD_MGMT_2
value|0x90E4
end_define

begin_define
define|#
directive|define
name|SPI_STATIC_THREAD_MGMT_3
value|0x90E8
end_define

begin_define
define|#
directive|define
name|SPI_PS_MAX_WAVE_ID
value|0x90EC
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
name|TA_CNTL_AUX
value|0x9508
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
name|GB_TILE_MODE0
value|0x9910
end_define

begin_define
define|#
directive|define
name|MICRO_TILE_MODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_DISPLAY_MICRO_TILING
value|0
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_THIN_MICRO_TILING
value|1
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_DEPTH_MICRO_TILING
value|2
end_define

begin_define
define|#
directive|define
name|ARRAY_MODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 2)
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
name|PIPE_CONFIG
parameter_list|(
name|x
parameter_list|)
value|((x)<< 6)
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_P2
value|0
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_P4_8x16
value|4
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_P4_16x16
value|5
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_P4_16x32
value|6
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_P4_32x32
value|7
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_P8_16x16_8x16
value|8
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_P8_16x32_8x16
value|9
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_P8_32x32_8x16
value|10
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_P8_16x32_16x16
value|11
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_P8_32x32_16x16
value|12
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_P8_32x32_16x32
value|13
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_P8_32x64_32x32
value|14
end_define

begin_define
define|#
directive|define
name|TILE_SPLIT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 11)
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
name|BANK_WIDTH
parameter_list|(
name|x
parameter_list|)
value|((x)<< 14)
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
name|BANK_HEIGHT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
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
name|MACRO_TILE_ASPECT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 18)
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_MACRO_ASPECT_1
value|0
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_MACRO_ASPECT_2
value|1
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_MACRO_ASPECT_4
value|2
end_define

begin_define
define|#
directive|define
name|ADDR_SURF_MACRO_ASPECT_8
value|3
end_define

begin_define
define|#
directive|define
name|NUM_BANKS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 20)
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
name|CB_PERFCOUNTER0_SELECT0
value|0x9a20
end_define

begin_define
define|#
directive|define
name|CB_PERFCOUNTER0_SELECT1
value|0x9a24
end_define

begin_define
define|#
directive|define
name|CB_PERFCOUNTER1_SELECT0
value|0x9a28
end_define

begin_define
define|#
directive|define
name|CB_PERFCOUNTER1_SELECT1
value|0x9a2c
end_define

begin_define
define|#
directive|define
name|CB_PERFCOUNTER2_SELECT0
value|0x9a30
end_define

begin_define
define|#
directive|define
name|CB_PERFCOUNTER2_SELECT1
value|0x9a34
end_define

begin_define
define|#
directive|define
name|CB_PERFCOUNTER3_SELECT0
value|0x9a38
end_define

begin_define
define|#
directive|define
name|CB_PERFCOUNTER3_SELECT1
value|0x9a3c
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
name|TCP_CHAN_STEER_LO
value|0xac0c
end_define

begin_define
define|#
directive|define
name|TCP_CHAN_STEER_HI
value|0xac10
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
name|BUF_SWAP_32BIT
value|(2<< 16)
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
name|CP_CE_UCODE_ADDR
value|0xC168
end_define

begin_define
define|#
directive|define
name|CP_CE_UCODE_DATA
value|0xC16C
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
name|CP_INT_CNTL_RING0
value|0xC1A8
end_define

begin_define
define|#
directive|define
name|CP_INT_CNTL_RING1
value|0xC1AC
end_define

begin_define
define|#
directive|define
name|CP_INT_CNTL_RING2
value|0xC1B0
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
name|WAIT_MEM_SEM_INT_ENABLE
value|(1<< 21)
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
name|CP_RINGID2_INT_ENABLE
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|CP_RINGID1_INT_ENABLE
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|CP_RINGID0_INT_ENABLE
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|CP_INT_STATUS_RING0
value|0xC1B4
end_define

begin_define
define|#
directive|define
name|CP_INT_STATUS_RING1
value|0xC1B8
end_define

begin_define
define|#
directive|define
name|CP_INT_STATUS_RING2
value|0xC1BC
end_define

begin_define
define|#
directive|define
name|WAIT_MEM_SEM_INT_STAT
value|(1<< 21)
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
name|CP_RINGID2_INT_STAT
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|CP_RINGID1_INT_STAT
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|CP_RINGID0_INT_STAT
value|(1<< 31)
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
name|RLC_CNTL
value|0xC300
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
name|RLC_RL_BASE
value|0xC304
end_define

begin_define
define|#
directive|define
name|RLC_RL_SIZE
value|0xC308
end_define

begin_define
define|#
directive|define
name|RLC_LB_CNTL
value|0xC30C
end_define

begin_define
define|#
directive|define
name|RLC_SAVE_AND_RESTORE_BASE
value|0xC310
end_define

begin_define
define|#
directive|define
name|RLC_LB_CNTR_MAX
value|0xC314
end_define

begin_define
define|#
directive|define
name|RLC_LB_CNTR_INIT
value|0xC318
end_define

begin_define
define|#
directive|define
name|RLC_CLEAR_STATE_RESTORE_BASE
value|0xC320
end_define

begin_define
define|#
directive|define
name|RLC_UCODE_ADDR
value|0xC32C
end_define

begin_define
define|#
directive|define
name|RLC_UCODE_DATA
value|0xC330
end_define

begin_define
define|#
directive|define
name|RLC_GPU_CLOCK_COUNT_LSB
value|0xC338
end_define

begin_define
define|#
directive|define
name|RLC_GPU_CLOCK_COUNT_MSB
value|0xC33C
end_define

begin_define
define|#
directive|define
name|RLC_CAPTURE_GPU_CLOCK_COUNT
value|0xC340
end_define

begin_define
define|#
directive|define
name|RLC_MC_CNTL
value|0xC344
end_define

begin_define
define|#
directive|define
name|RLC_UCODE_CNTL
value|0xC348
end_define

begin_define
define|#
directive|define
name|PA_SC_RASTER_CONFIG
value|0x28350
end_define

begin_define
define|#
directive|define
name|RASTER_CONFIG_RB_MAP_0
value|0
end_define

begin_define
define|#
directive|define
name|RASTER_CONFIG_RB_MAP_1
value|1
end_define

begin_define
define|#
directive|define
name|RASTER_CONFIG_RB_MAP_2
value|2
end_define

begin_define
define|#
directive|define
name|RASTER_CONFIG_RB_MAP_3
value|3
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
name|SAMPLE_STREAMOUTSTATS1
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SAMPLE_STREAMOUTSTATS2
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|SAMPLE_STREAMOUTSTATS3
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|CACHE_FLUSH_TS
value|(4<< 0)
end_define

begin_define
define|#
directive|define
name|CACHE_FLUSH
value|(6<< 0)
end_define

begin_define
define|#
directive|define
name|CS_PARTIAL_FLUSH
value|(7<< 0)
end_define

begin_define
define|#
directive|define
name|VGT_STREAMOUT_RESET
value|(10<< 0)
end_define

begin_define
define|#
directive|define
name|END_OF_PIPE_INCR_DE
value|(11<< 0)
end_define

begin_define
define|#
directive|define
name|END_OF_PIPE_IB_END
value|(12<< 0)
end_define

begin_define
define|#
directive|define
name|RST_PIX_CNT
value|(13<< 0)
end_define

begin_define
define|#
directive|define
name|VS_PARTIAL_FLUSH
value|(15<< 0)
end_define

begin_define
define|#
directive|define
name|PS_PARTIAL_FLUSH
value|(16<< 0)
end_define

begin_define
define|#
directive|define
name|CACHE_FLUSH_AND_INV_TS_EVENT
value|(20<< 0)
end_define

begin_define
define|#
directive|define
name|ZPASS_DONE
value|(21<< 0)
end_define

begin_define
define|#
directive|define
name|CACHE_FLUSH_AND_INV_EVENT
value|(22<< 0)
end_define

begin_define
define|#
directive|define
name|PERFCOUNTER_START
value|(23<< 0)
end_define

begin_define
define|#
directive|define
name|PERFCOUNTER_STOP
value|(24<< 0)
end_define

begin_define
define|#
directive|define
name|PIPELINESTAT_START
value|(25<< 0)
end_define

begin_define
define|#
directive|define
name|PIPELINESTAT_STOP
value|(26<< 0)
end_define

begin_define
define|#
directive|define
name|PERFCOUNTER_SAMPLE
value|(27<< 0)
end_define

begin_define
define|#
directive|define
name|SAMPLE_PIPELINESTAT
value|(30<< 0)
end_define

begin_define
define|#
directive|define
name|SAMPLE_STREAMOUTSTATS
value|(32<< 0)
end_define

begin_define
define|#
directive|define
name|RESET_VTX_CNT
value|(33<< 0)
end_define

begin_define
define|#
directive|define
name|VGT_FLUSH
value|(36<< 0)
end_define

begin_define
define|#
directive|define
name|BOTTOM_OF_PIPE_TS
value|(40<< 0)
end_define

begin_define
define|#
directive|define
name|DB_CACHE_FLUSH_AND_INV
value|(42<< 0)
end_define

begin_define
define|#
directive|define
name|FLUSH_AND_INV_DB_DATA_TS
value|(43<< 0)
end_define

begin_define
define|#
directive|define
name|FLUSH_AND_INV_DB_META
value|(44<< 0)
end_define

begin_define
define|#
directive|define
name|FLUSH_AND_INV_CB_DATA_TS
value|(45<< 0)
end_define

begin_define
define|#
directive|define
name|FLUSH_AND_INV_CB_META
value|(46<< 0)
end_define

begin_define
define|#
directive|define
name|CS_DONE
value|(47<< 0)
end_define

begin_define
define|#
directive|define
name|PS_DONE
value|(48<< 0)
end_define

begin_define
define|#
directive|define
name|FLUSH_AND_INV_CB_PIXEL_DATA
value|(49<< 0)
end_define

begin_define
define|#
directive|define
name|THREAD_TRACE_START
value|(51<< 0)
end_define

begin_define
define|#
directive|define
name|THREAD_TRACE_STOP
value|(52<< 0)
end_define

begin_define
define|#
directive|define
name|THREAD_TRACE_FLUSH
value|(54<< 0)
end_define

begin_define
define|#
directive|define
name|THREAD_TRACE_FINISH
value|(55<< 0)
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

begin_define
define|#
directive|define
name|PACKET3_COMPUTE
parameter_list|(
name|op
parameter_list|,
name|n
parameter_list|)
value|(PACKET3(op, n) | 1<< 1)
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
name|PACKET3_BASE_INDEX
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|GDS_PARTITION_BASE
value|2
end_define

begin_define
define|#
directive|define
name|CE_PARTITION_BASE
value|3
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
name|PACKET3_ALLOC_GDS
value|0x1B
end_define

begin_define
define|#
directive|define
name|PACKET3_WRITE_GDS_RAM
value|0x1C
end_define

begin_define
define|#
directive|define
name|PACKET3_ATOMIC_GDS
value|0x1D
end_define

begin_define
define|#
directive|define
name|PACKET3_ATOMIC
value|0x1E
end_define

begin_define
define|#
directive|define
name|PACKET3_OCCLUSION_QUERY
value|0x1F
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
name|PACKET3_INDEX_TYPE
value|0x2A
end_define

begin_define
define|#
directive|define
name|PACKET3_DRAW_INDIRECT_MULTI
value|0x2C
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
name|PACKET3_INDIRECT_BUFFER_CONST
value|0x31
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
name|WRITE_DATA_DST_SEL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_comment
comment|/* 0 - register 		 * 1 - memory (sync - via GRBM) 		 * 2 - tc/l2 		 * 3 - gds 		 * 4 - reserved 		 * 5 - memory (async - direct) 		 */
end_comment

begin_define
define|#
directive|define
name|WR_ONE_ADDR
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|WR_CONFIRM
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|WRITE_DATA_ENGINE_SEL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 30)
end_define

begin_comment
comment|/* 0 - me 		 * 1 - pfp 		 * 2 - ce 		 */
end_comment

begin_define
define|#
directive|define
name|PACKET3_DRAW_INDEX_INDIRECT_MULTI
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
name|PACKET3_COPY_DATA
value|0x40
end_define

begin_define
define|#
directive|define
name|PACKET3_CP_DMA
value|0x41
end_define

begin_comment
comment|/* 1. header  * 2. SRC_ADDR_LO or DATA [31:0]  * 3. CP_SYNC [31] | SRC_SEL [30:29] | ENGINE [27] | DST_SEL [21:20] |  *    SRC_ADDR_HI [7:0]  * 4. DST_ADDR_LO [31:0]  * 5. DST_ADDR_HI [7:0]  * 6. COMMAND [30:21] | BYTE_COUNT [20:0]  */
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
name|PACKET3_CP_DMA_CMD_RAW_WAIT
value|(1<< 30)
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
name|PACKET3_DEST_BASE_0_ENA
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|PACKET3_DEST_BASE_1_ENA
value|(1<< 1)
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
name|PACKET3_DEST_BASE_2_ENA
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|PACKET3_DEST_BASE_3_ENA
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|PACKET3_TCL1_ACTION_ENA
value|(1<< 22)
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
name|PACKET3_SH_KCACHE_ACTION_ENA
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|PACKET3_SH_ICACHE_ACTION_ENA
value|(1<< 29)
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
comment|/* 0 - any non-TS event 		 * 1 - ZPASS_DONE 		 * 2 - SAMPLE_PIPELINESTAT 		 * 3 - SAMPLE_STREAMOUTSTAT* 		 * 4 - *S_PARTIAL_FLUSH 		 * 5 - EOP events 		 * 6 - EOS events 		 * 7 - CACHE_FLUSH, CACHE_FLUSH_AND_INV_EVENT 		 */
end_comment

begin_define
define|#
directive|define
name|INV_L2
value|(1<< 20)
end_define

begin_comment
comment|/* INV TC L2 cache when EVENT_INDEX = 7 */
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
name|PACKET3_ONE_REG_WRITE
value|0x57
end_define

begin_define
define|#
directive|define
name|PACKET3_LOAD_CONFIG_REG
value|0x5F
end_define

begin_define
define|#
directive|define
name|PACKET3_LOAD_CONTEXT_REG
value|0x60
end_define

begin_define
define|#
directive|define
name|PACKET3_LOAD_SH_REG
value|0x61
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
value|0x0000b000
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
name|PACKET3_SET_SH_REG
value|0x76
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_SH_REG_START
value|0x0000b000
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_SH_REG_END
value|0x0000c000
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_SH_REG_OFFSET
value|0x77
end_define

begin_define
define|#
directive|define
name|PACKET3_ME_WRITE
value|0x7A
end_define

begin_define
define|#
directive|define
name|PACKET3_SCRATCH_RAM_WRITE
value|0x7D
end_define

begin_define
define|#
directive|define
name|PACKET3_SCRATCH_RAM_READ
value|0x7E
end_define

begin_define
define|#
directive|define
name|PACKET3_CE_WRITE
value|0x7F
end_define

begin_define
define|#
directive|define
name|PACKET3_LOAD_CONST_RAM
value|0x80
end_define

begin_define
define|#
directive|define
name|PACKET3_WRITE_CONST_RAM
value|0x81
end_define

begin_define
define|#
directive|define
name|PACKET3_WRITE_CONST_RAM_OFFSET
value|0x82
end_define

begin_define
define|#
directive|define
name|PACKET3_DUMP_CONST_RAM
value|0x83
end_define

begin_define
define|#
directive|define
name|PACKET3_INCREMENT_CE_COUNTER
value|0x84
end_define

begin_define
define|#
directive|define
name|PACKET3_INCREMENT_DE_COUNTER
value|0x85
end_define

begin_define
define|#
directive|define
name|PACKET3_WAIT_ON_CE_COUNTER
value|0x86
end_define

begin_define
define|#
directive|define
name|PACKET3_WAIT_ON_DE_COUNTER
value|0x87
end_define

begin_define
define|#
directive|define
name|PACKET3_WAIT_ON_DE_COUNTER_DIFF
value|0x88
end_define

begin_define
define|#
directive|define
name|PACKET3_SET_CE_DE_COUNTERS
value|0x89
end_define

begin_define
define|#
directive|define
name|PACKET3_WAIT_ON_AVAIL_BUFFER
value|0x8A
end_define

begin_define
define|#
directive|define
name|PACKET3_SWITCH_BUFFER
value|0x8B
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
name|DMA_TILING_CONFIG
value|0xd0b8
end_define

begin_define
define|#
directive|define
name|DMA_PACKET
parameter_list|(
name|cmd
parameter_list|,
name|b
parameter_list|,
name|t
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|((((cmd)& 0xF)<< 28) |	\ 					 (((b)& 0x1)<< 26) |		\ 					 (((t)& 0x1)<< 23) |		\ 					 (((s)& 0x1)<< 22) |		\ 					 (((n)& 0xFFFFF)<< 0))
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

begin_define
define|#
directive|define
name|DMA_PTE_PDE_PACKET
parameter_list|(
name|n
parameter_list|)
value|((2<< 28) |			\ 					 (1<< 26) |			\ 					 (1<< 21) |			\ 					 (((n)& 0xFFFFF)<< 0))
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

