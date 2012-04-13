begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * Module to support operations on core such as TLB config, etc.  *  *<hr>$Revision: 70030 $<hr>  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_CORE_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_CORE_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/**  * The types of performance counters supported per cpu  */
typedef|typedef
enum|enum
block|{
name|CVMX_CORE_PERF_NONE
init|=
literal|0
block|,
comment|/**< Turn off the performance counter */
name|CVMX_CORE_PERF_CLK
init|=
literal|1
block|,
comment|/**< Conditionally clocked cycles (as opposed to count/cvm_count which count even with no clocks) */
name|CVMX_CORE_PERF_ISSUE
init|=
literal|2
block|,
comment|/**< Instructions issued but not retired */
name|CVMX_CORE_PERF_RET
init|=
literal|3
block|,
comment|/**< Instructions retired */
name|CVMX_CORE_PERF_NISSUE
init|=
literal|4
block|,
comment|/**< Cycles no issue */
name|CVMX_CORE_PERF_SISSUE
init|=
literal|5
block|,
comment|/**< Cycles single issue */
name|CVMX_CORE_PERF_DISSUE
init|=
literal|6
block|,
comment|/**< Cycles dual issue */
name|CVMX_CORE_PERF_IFI
init|=
literal|7
block|,
comment|/**< Cycle ifetch issued (but not necessarily commit to pp_mem) */
name|CVMX_CORE_PERF_BR
init|=
literal|8
block|,
comment|/**< Branches retired */
name|CVMX_CORE_PERF_BRMIS
init|=
literal|9
block|,
comment|/**< Branch mispredicts */
name|CVMX_CORE_PERF_J
init|=
literal|10
block|,
comment|/**< Jumps retired */
name|CVMX_CORE_PERF_JMIS
init|=
literal|11
block|,
comment|/**< Jumps mispredicted */
name|CVMX_CORE_PERF_REPLAY
init|=
literal|12
block|,
comment|/**< Mem Replays */
name|CVMX_CORE_PERF_IUNA
init|=
literal|13
block|,
comment|/**< Cycles idle due to unaligned_replays */
name|CVMX_CORE_PERF_TRAP
init|=
literal|14
block|,
comment|/**< trap_6a signal */
name|CVMX_CORE_PERF_UULOAD
init|=
literal|16
block|,
comment|/**< Unexpected unaligned loads (REPUN=1) */
name|CVMX_CORE_PERF_UUSTORE
init|=
literal|17
block|,
comment|/**< Unexpected unaligned store (REPUN=1) */
name|CVMX_CORE_PERF_ULOAD
init|=
literal|18
block|,
comment|/**< Unaligned loads (REPUN=1 or USEUN=1) */
name|CVMX_CORE_PERF_USTORE
init|=
literal|19
block|,
comment|/**< Unaligned store (REPUN=1 or USEUN=1) */
name|CVMX_CORE_PERF_EC
init|=
literal|20
block|,
comment|/**< Exec clocks(must set CvmCtl[DISCE] for accurate timing) */
name|CVMX_CORE_PERF_MC
init|=
literal|21
block|,
comment|/**< Mul clocks(must set CvmCtl[DISCE] for accurate timing) */
name|CVMX_CORE_PERF_CC
init|=
literal|22
block|,
comment|/**< Crypto clocks(must set CvmCtl[DISCE] for accurate timing) */
name|CVMX_CORE_PERF_CSRC
init|=
literal|23
block|,
comment|/**< Issue_csr clocks(must set CvmCtl[DISCE] for accurate timing) */
name|CVMX_CORE_PERF_CFETCH
init|=
literal|24
block|,
comment|/**< Icache committed fetches (demand+prefetch) */
name|CVMX_CORE_PERF_CPREF
init|=
literal|25
block|,
comment|/**< Icache committed prefetches */
name|CVMX_CORE_PERF_ICA
init|=
literal|26
block|,
comment|/**< Icache aliases */
name|CVMX_CORE_PERF_II
init|=
literal|27
block|,
comment|/**< Icache invalidates */
name|CVMX_CORE_PERF_IP
init|=
literal|28
block|,
comment|/**< Icache parity error */
name|CVMX_CORE_PERF_CIMISS
init|=
literal|29
block|,
comment|/**< Cycles idle due to imiss (must set CvmCtl[DISCE] for accurate timing) */
name|CVMX_CORE_PERF_WBUF
init|=
literal|32
block|,
comment|/**< Number of write buffer entries created */
name|CVMX_CORE_PERF_WDAT
init|=
literal|33
block|,
comment|/**< Number of write buffer data cycles used (may need to set CvmCtl[DISCE] for accurate counts) */
name|CVMX_CORE_PERF_WBUFLD
init|=
literal|34
block|,
comment|/**< Number of write buffer entries forced out by loads */
name|CVMX_CORE_PERF_WBUFFL
init|=
literal|35
block|,
comment|/**< Number of cycles that there was no available write buffer entry (may need to set CvmCtl[DISCE] and CvmMemCtl[MCLK] for accurate counts) */
name|CVMX_CORE_PERF_WBUFTR
init|=
literal|36
block|,
comment|/**< Number of stores that found no available write buffer entries */
name|CVMX_CORE_PERF_BADD
init|=
literal|37
block|,
comment|/**< Number of address bus cycles used (may need to set CvmCtl[DISCE] for accurate counts) */
name|CVMX_CORE_PERF_BADDL2
init|=
literal|38
block|,
comment|/**< Number of address bus cycles not reflected (i.e. destined for L2) (may need to set CvmCtl[DISCE] for accurate counts) */
name|CVMX_CORE_PERF_BFILL
init|=
literal|39
block|,
comment|/**< Number of fill bus cycles used (may need to set CvmCtl[DISCE] for accurate counts) */
name|CVMX_CORE_PERF_DDIDS
init|=
literal|40
block|,
comment|/**< Number of Dstream DIDs created */
name|CVMX_CORE_PERF_IDIDS
init|=
literal|41
block|,
comment|/**< Number of Istream DIDs created */
name|CVMX_CORE_PERF_DIDNA
init|=
literal|42
block|,
comment|/**< Number of cycles that no DIDs were available (may need to set CvmCtl[DISCE] and CvmMemCtl[MCLK] for accurate counts) */
name|CVMX_CORE_PERF_LDS
init|=
literal|43
block|,
comment|/**< Number of load issues */
name|CVMX_CORE_PERF_LMLDS
init|=
literal|44
block|,
comment|/**< Number of local memory load */
name|CVMX_CORE_PERF_IOLDS
init|=
literal|45
block|,
comment|/**< Number of I/O load issues */
name|CVMX_CORE_PERF_DMLDS
init|=
literal|46
block|,
comment|/**< Number of loads that were not prefetches and missed in the cache */
name|CVMX_CORE_PERF_STS
init|=
literal|48
block|,
comment|/**< Number of store issues */
name|CVMX_CORE_PERF_LMSTS
init|=
literal|49
block|,
comment|/**< Number of local memory store issues */
name|CVMX_CORE_PERF_IOSTS
init|=
literal|50
block|,
comment|/**< Number of I/O store issues */
name|CVMX_CORE_PERF_IOBDMA
init|=
literal|51
block|,
comment|/**< Number of IOBDMAs */
name|CVMX_CORE_PERF_DTLB
init|=
literal|53
block|,
comment|/**< Number of dstream TLB refill, invalid, or modified exceptions */
name|CVMX_CORE_PERF_DTLBAD
init|=
literal|54
block|,
comment|/**< Number of dstream TLB address errors */
name|CVMX_CORE_PERF_ITLB
init|=
literal|55
block|,
comment|/**< Number of istream TLB refill, invalid, or address error exceptions */
name|CVMX_CORE_PERF_SYNC
init|=
literal|56
block|,
comment|/**< Number of SYNC stall cycles (may need to set CvmCtl[DISCE] for accurate counts) */
name|CVMX_CORE_PERF_SYNCIOB
init|=
literal|57
block|,
comment|/**< Number of SYNCIOBDMA stall cycles (may need to set CvmCtl[DISCE] for accurate counts) */
name|CVMX_CORE_PERF_SYNCW
init|=
literal|58
block|,
comment|/**< Number of SYNCWs */
comment|/* Added in CN63XX */
name|CVMX_CORE_PERF_ERETMIS
init|=
literal|64
block|,
comment|/**< D/eret mispredicts */
name|CVMX_CORE_PERF_LIKMIS
init|=
literal|65
block|,
comment|/**< Branch likely mispredicts */
name|CVMX_CORE_PERF_HAZTR
init|=
literal|66
block|,
comment|/**< Hazard traps due to *MTC0 to CvmCtl, Perf counter control, EntryHi, or CvmMemCtl registers */
name|CVMX_CORE_PERF_MAX
comment|/**< This not a counter, just a marker for the highest number */
block|}
name|cvmx_core_perf_t
typedef|;
comment|/**  * Bit description of the COP0 counter control register  */
typedef|typedef
union|union
block|{
name|uint32_t
name|u32
decl_stmt|;
struct|struct
block|{
ifdef|#
directive|ifdef
name|__BIG_ENDIAN_BITFIELD
name|uint32_t
name|m
range|:
literal|1
decl_stmt|;
comment|/**< Set to 1 for sel 0 and 0 for sel 2, indicating there are two performance counters */
name|uint32_t
name|w
range|:
literal|1
decl_stmt|;
comment|/**< Set to 1 indicating counters are 64 bit */
name|uint32_t
name|reserved_11_29
range|:
literal|15
decl_stmt|;
name|cvmx_core_perf_t
name|event
range|:
literal|10
decl_stmt|;
comment|/**< Selects the event to be counted by the corresponding Counter Register */
name|uint32_t
name|ie
range|:
literal|1
decl_stmt|;
comment|/**< Interrupt Enable */
name|uint32_t
name|u
range|:
literal|1
decl_stmt|;
comment|/**< Count in user mode */
name|uint32_t
name|s
range|:
literal|1
decl_stmt|;
comment|/**< Count in supervisor mode */
name|uint32_t
name|k
range|:
literal|1
decl_stmt|;
comment|/**< Count in kernel mode */
name|uint32_t
name|ex
range|:
literal|1
decl_stmt|;
comment|/**< Count in exception context */
else|#
directive|else
name|uint32_t
name|ex
range|:
literal|1
decl_stmt|;
name|uint32_t
name|k
range|:
literal|1
decl_stmt|;
name|uint32_t
name|s
range|:
literal|1
decl_stmt|;
name|uint32_t
name|u
range|:
literal|1
decl_stmt|;
name|uint32_t
name|ie
range|:
literal|1
decl_stmt|;
name|uint32_t
name|event
range|:
literal|10
decl_stmt|;
name|uint32_t
name|reserved_11_29
range|:
literal|15
decl_stmt|;
name|uint32_t
name|w
range|:
literal|1
decl_stmt|;
name|uint32_t
name|m
range|:
literal|1
decl_stmt|;
endif|#
directive|endif
block|}
name|s
struct|;
block|}
name|cvmx_core_perf_control_t
typedef|;
typedef|typedef
enum|enum
block|{
name|CVMX_TLB_PAGEMASK_4K
init|=
literal|0x3
operator|<<
literal|11
block|,
name|CVMX_TLB_PAGEMASK_16K
init|=
literal|0xF
operator|<<
literal|11
block|,
name|CVMX_TLB_PAGEMASK_64K
init|=
literal|0x3F
operator|<<
literal|11
block|,
name|CVMX_TLB_PAGEMASK_256K
init|=
literal|0xFF
operator|<<
literal|11
block|,
name|CVMX_TLB_PAGEMASK_1M
init|=
literal|0x3FF
operator|<<
literal|11
block|,
name|CVMX_TLB_PAGEMASK_4M
init|=
literal|0xFFF
operator|<<
literal|11
block|,
name|CVMX_TLB_PAGEMASK_16M
init|=
literal|0x3FFF
operator|<<
literal|11
block|,
name|CVMX_TLB_PAGEMASK_64M
init|=
literal|0xFFFF
operator|<<
literal|11
block|,
name|CVMX_TLB_PAGEMASK_256M
init|=
literal|0x3FFFF
operator|<<
literal|11
block|, }
name|cvmx_tlb_pagemask_t
typedef|;
name|int
name|cvmx_core_add_wired_tlb_entry
parameter_list|(
name|uint64_t
name|hi
parameter_list|,
name|uint64_t
name|lo0
parameter_list|,
name|uint64_t
name|lo1
parameter_list|,
name|cvmx_tlb_pagemask_t
name|page_mask
parameter_list|)
function_decl|;
name|int
name|cvmx_core_add_fixed_tlb_mapping
parameter_list|(
name|uint64_t
name|vaddr
parameter_list|,
name|uint64_t
name|page0_addr
parameter_list|,
name|uint64_t
name|page1_addr
parameter_list|,
name|cvmx_tlb_pagemask_t
name|page_mask
parameter_list|)
function_decl|;
name|int
name|cvmx_core_add_fixed_tlb_mapping_bits
parameter_list|(
name|uint64_t
name|vaddr
parameter_list|,
name|uint64_t
name|page0_addr
parameter_list|,
name|uint64_t
name|page1_addr
parameter_list|,
name|cvmx_tlb_pagemask_t
name|page_mask
parameter_list|)
function_decl|;
comment|/**  * Return number of TLB entries.  */
name|int
name|cvmx_core_get_tlb_entries
parameter_list|(
name|void
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CVMX_CORE_H__ */
end_comment

end_unit

