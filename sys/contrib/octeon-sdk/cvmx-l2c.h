begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2011  Cavium, Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * Interface to the Level 2 Cache (L2C) control, measurement, and debugging  * facilities.  *  *<hr>$Revision: 70030 $<hr>  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_L2C_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_L2C_H__
end_define

begin_define
define|#
directive|define
name|CVMX_L2C_IDX_ADDR_SHIFT
value|7
end_define

begin_comment
comment|/* based on 128 byte cache line size */
end_comment

begin_define
define|#
directive|define
name|CVMX_L2C_IDX_MASK
value|(cvmx_l2c_get_num_sets() - 1)
end_define

begin_comment
comment|/* Defines for index aliasing computations */
end_comment

begin_define
define|#
directive|define
name|CVMX_L2C_TAG_ADDR_ALIAS_SHIFT
value|(CVMX_L2C_IDX_ADDR_SHIFT + cvmx_l2c_get_set_bits())
end_define

begin_define
define|#
directive|define
name|CVMX_L2C_ALIAS_MASK
value|(CVMX_L2C_IDX_MASK<< CVMX_L2C_TAG_ADDR_ALIAS_SHIFT)
end_define

begin_define
define|#
directive|define
name|CVMX_L2C_MEMBANK_SELECT_SIZE
value|4096
end_define

begin_comment
comment|/* Defines for Virtualizations, valid only from Octeon II onwards. */
end_comment

begin_define
define|#
directive|define
name|CVMX_L2C_VRT_MAX_VIRTID_ALLOWED
value|((OCTEON_IS_MODEL(OCTEON_CN6XXX) || OCTEON_IS_MODEL(OCTEON_CNF7XXX)) ? 64 : 0)
end_define

begin_define
define|#
directive|define
name|CVMX_L2C_MAX_MEMSZ_ALLOWED
value|((OCTEON_IS_MODEL(OCTEON_CN6XXX) || OCTEON_IS_MODEL(OCTEON_CNF7XXX)) ? 32 : 0)
end_define

begin_comment
comment|/*------------*/
end_comment

begin_comment
comment|/*  TYPEDEFS  */
end_comment

begin_comment
comment|/*------------*/
end_comment

begin_union
union|union
name|cvmx_l2c_tag
block|{
name|uint64_t
name|u64
decl_stmt|;
ifdef|#
directive|ifdef
name|__BIG_ENDIAN_BITFIELD
struct|struct
block|{
name|uint64_t
name|reserved
range|:
literal|28
decl_stmt|;
name|uint64_t
name|V
range|:
literal|1
decl_stmt|;
comment|/* Line valid */
name|uint64_t
name|D
range|:
literal|1
decl_stmt|;
comment|/* Line dirty */
name|uint64_t
name|L
range|:
literal|1
decl_stmt|;
comment|/* Line locked */
name|uint64_t
name|U
range|:
literal|1
decl_stmt|;
comment|/* Use, LRU eviction */
name|uint64_t
name|addr
range|:
literal|32
decl_stmt|;
comment|/* Phys mem (not all bits valid) */
block|}
name|s
struct|;
else|#
directive|else
struct|struct
block|{
name|uint64_t
name|addr
range|:
literal|32
decl_stmt|;
comment|/* Phys mem (not all bits valid) */
name|uint64_t
name|U
range|:
literal|1
decl_stmt|;
comment|/* Use, LRU eviction */
name|uint64_t
name|L
range|:
literal|1
decl_stmt|;
comment|/* Line locked */
name|uint64_t
name|D
range|:
literal|1
decl_stmt|;
comment|/* Line dirty */
name|uint64_t
name|V
range|:
literal|1
decl_stmt|;
comment|/* Line valid */
name|uint64_t
name|reserved
range|:
literal|28
decl_stmt|;
block|}
name|s
struct|;
endif|#
directive|endif
block|}
union|;
end_union

begin_typedef
typedef|typedef
name|union
name|cvmx_l2c_tag
name|cvmx_l2c_tag_t
typedef|;
end_typedef

begin_comment
comment|/* Maximium number of TADs */
end_comment

begin_define
define|#
directive|define
name|CVMX_L2C_MAX_TADS
value|4
end_define

begin_comment
comment|/* Maximium number of L2C performance counters */
end_comment

begin_define
define|#
directive|define
name|CVMX_L2C_MAX_PCNT
value|4
end_define

begin_comment
comment|/* Number of L2C Tag-and-data sections (TADs) that are connected to LMC. */
end_comment

begin_define
define|#
directive|define
name|CVMX_L2C_TADS
value|((OCTEON_IS_MODEL(OCTEON_CN68XX)) ? 4 : 1)
end_define

begin_comment
comment|/* Number of L2C IOBs connected to LMC. */
end_comment

begin_define
define|#
directive|define
name|CVMX_L2C_IOBS
value|((OCTEON_IS_MODEL(OCTEON_CN68XX)) ? 2 : 1)
end_define

begin_comment
comment|/* L2C Performance Counter events. */
end_comment

begin_enum
enum|enum
name|cvmx_l2c_event
block|{
name|CVMX_L2C_EVENT_CYCLES
init|=
literal|0
block|,
comment|/**< Cycles */
name|CVMX_L2C_EVENT_INSTRUCTION_MISS
init|=
literal|1
block|,
comment|/**< L2 Instruction Miss */
name|CVMX_L2C_EVENT_INSTRUCTION_HIT
init|=
literal|2
block|,
comment|/**< L2 Instruction Hit */
name|CVMX_L2C_EVENT_DATA_MISS
init|=
literal|3
block|,
comment|/**< L2 Data Miss */
name|CVMX_L2C_EVENT_DATA_HIT
init|=
literal|4
block|,
comment|/**< L2 Data Hit */
name|CVMX_L2C_EVENT_MISS
init|=
literal|5
block|,
comment|/**< L2 Miss (I/D) */
name|CVMX_L2C_EVENT_HIT
init|=
literal|6
block|,
comment|/**< L2 Hit (I/D) */
name|CVMX_L2C_EVENT_VICTIM_HIT
init|=
literal|7
block|,
comment|/**< L2 Victim Buffer Hit (Retry Probe) */
name|CVMX_L2C_EVENT_INDEX_CONFLICT
init|=
literal|8
block|,
comment|/**< LFB-NQ Index Conflict */
name|CVMX_L2C_EVENT_TAG_PROBE
init|=
literal|9
block|,
comment|/**< L2 Tag Probe (issued - could be VB-Retried) */
name|CVMX_L2C_EVENT_TAG_UPDATE
init|=
literal|10
block|,
comment|/**< L2 Tag Update (completed). Note: Some CMD types do not update */
name|CVMX_L2C_EVENT_TAG_COMPLETE
init|=
literal|11
block|,
comment|/**< L2 Tag Probe Completed (beyond VB-RTY window) */
name|CVMX_L2C_EVENT_TAG_DIRTY
init|=
literal|12
block|,
comment|/**< L2 Tag Dirty Victim */
name|CVMX_L2C_EVENT_DATA_STORE_NOP
init|=
literal|13
block|,
comment|/**< L2 Data Store NOP */
name|CVMX_L2C_EVENT_DATA_STORE_READ
init|=
literal|14
block|,
comment|/**< L2 Data Store READ */
name|CVMX_L2C_EVENT_DATA_STORE_WRITE
init|=
literal|15
block|,
comment|/**< L2 Data Store WRITE */
name|CVMX_L2C_EVENT_FILL_DATA_VALID
init|=
literal|16
block|,
comment|/**< Memory Fill Data valid */
name|CVMX_L2C_EVENT_WRITE_REQUEST
init|=
literal|17
block|,
comment|/**< Memory Write Request */
name|CVMX_L2C_EVENT_READ_REQUEST
init|=
literal|18
block|,
comment|/**< Memory Read Request */
name|CVMX_L2C_EVENT_WRITE_DATA_VALID
init|=
literal|19
block|,
comment|/**< Memory Write Data valid */
name|CVMX_L2C_EVENT_XMC_NOP
init|=
literal|20
block|,
comment|/**< XMC NOP */
name|CVMX_L2C_EVENT_XMC_LDT
init|=
literal|21
block|,
comment|/**< XMC LDT */
name|CVMX_L2C_EVENT_XMC_LDI
init|=
literal|22
block|,
comment|/**< XMC LDI */
name|CVMX_L2C_EVENT_XMC_LDD
init|=
literal|23
block|,
comment|/**< XMC LDD */
name|CVMX_L2C_EVENT_XMC_STF
init|=
literal|24
block|,
comment|/**< XMC STF */
name|CVMX_L2C_EVENT_XMC_STT
init|=
literal|25
block|,
comment|/**< XMC STT */
name|CVMX_L2C_EVENT_XMC_STP
init|=
literal|26
block|,
comment|/**< XMC STP */
name|CVMX_L2C_EVENT_XMC_STC
init|=
literal|27
block|,
comment|/**< XMC STC */
name|CVMX_L2C_EVENT_XMC_DWB
init|=
literal|28
block|,
comment|/**< XMC DWB */
name|CVMX_L2C_EVENT_XMC_PL2
init|=
literal|29
block|,
comment|/**< XMC PL2 */
name|CVMX_L2C_EVENT_XMC_PSL1
init|=
literal|30
block|,
comment|/**< XMC PSL1 */
name|CVMX_L2C_EVENT_XMC_IOBLD
init|=
literal|31
block|,
comment|/**< XMC IOBLD */
name|CVMX_L2C_EVENT_XMC_IOBST
init|=
literal|32
block|,
comment|/**< XMC IOBST */
name|CVMX_L2C_EVENT_XMC_IOBDMA
init|=
literal|33
block|,
comment|/**< XMC IOBDMA */
name|CVMX_L2C_EVENT_XMC_IOBRSP
init|=
literal|34
block|,
comment|/**< XMC IOBRSP */
name|CVMX_L2C_EVENT_XMC_BUS_VALID
init|=
literal|35
block|,
comment|/**< XMC Bus valid (all) */
name|CVMX_L2C_EVENT_XMC_MEM_DATA
init|=
literal|36
block|,
comment|/**< XMC Bus valid (DST=L2C) Memory */
name|CVMX_L2C_EVENT_XMC_REFL_DATA
init|=
literal|37
block|,
comment|/**< XMC Bus valid (DST=IOB) REFL Data */
name|CVMX_L2C_EVENT_XMC_IOBRSP_DATA
init|=
literal|38
block|,
comment|/**< XMC Bus valid (DST=PP) IOBRSP Data */
name|CVMX_L2C_EVENT_RSC_NOP
init|=
literal|39
block|,
comment|/**< RSC NOP */
name|CVMX_L2C_EVENT_RSC_STDN
init|=
literal|40
block|,
comment|/**< RSC STDN */
name|CVMX_L2C_EVENT_RSC_FILL
init|=
literal|41
block|,
comment|/**< RSC FILL */
name|CVMX_L2C_EVENT_RSC_REFL
init|=
literal|42
block|,
comment|/**< RSC REFL */
name|CVMX_L2C_EVENT_RSC_STIN
init|=
literal|43
block|,
comment|/**< RSC STIN */
name|CVMX_L2C_EVENT_RSC_SCIN
init|=
literal|44
block|,
comment|/**< RSC SCIN */
name|CVMX_L2C_EVENT_RSC_SCFL
init|=
literal|45
block|,
comment|/**< RSC SCFL */
name|CVMX_L2C_EVENT_RSC_SCDN
init|=
literal|46
block|,
comment|/**< RSC SCDN */
name|CVMX_L2C_EVENT_RSC_DATA_VALID
init|=
literal|47
block|,
comment|/**< RSC Data Valid */
name|CVMX_L2C_EVENT_RSC_VALID_FILL
init|=
literal|48
block|,
comment|/**< RSC Data Valid (FILL) */
name|CVMX_L2C_EVENT_RSC_VALID_STRSP
init|=
literal|49
block|,
comment|/**< RSC Data Valid (STRSP) */
name|CVMX_L2C_EVENT_RSC_VALID_REFL
init|=
literal|50
block|,
comment|/**< RSC Data Valid (REFL) */
name|CVMX_L2C_EVENT_LRF_REQ
init|=
literal|51
block|,
comment|/**< LRF-REQ (LFB-NQ) */
name|CVMX_L2C_EVENT_DT_RD_ALLOC
init|=
literal|52
block|,
comment|/**< DT RD-ALLOC */
name|CVMX_L2C_EVENT_DT_WR_INVAL
init|=
literal|53
block|,
comment|/**< DT WR-INVAL */
name|CVMX_L2C_EVENT_MAX
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|cvmx_l2c_event
name|cvmx_l2c_event_t
typedef|;
end_typedef

begin_comment
comment|/* L2C Performance Counter events for Octeon2. */
end_comment

begin_enum
enum|enum
name|cvmx_l2c_tad_event
block|{
name|CVMX_L2C_TAD_EVENT_NONE
init|=
literal|0
block|,
comment|/* None */
name|CVMX_L2C_TAD_EVENT_TAG_HIT
init|=
literal|1
block|,
comment|/* L2 Tag Hit */
name|CVMX_L2C_TAD_EVENT_TAG_MISS
init|=
literal|2
block|,
comment|/* L2 Tag Miss */
name|CVMX_L2C_TAD_EVENT_TAG_NOALLOC
init|=
literal|3
block|,
comment|/* L2 Tag NoAlloc (forced no-allocate) */
name|CVMX_L2C_TAD_EVENT_TAG_VICTIM
init|=
literal|4
block|,
comment|/* L2 Tag Victim */
name|CVMX_L2C_TAD_EVENT_SC_FAIL
init|=
literal|5
block|,
comment|/* SC Fail */
name|CVMX_L2C_TAD_EVENT_SC_PASS
init|=
literal|6
block|,
comment|/* SC Pass */
name|CVMX_L2C_TAD_EVENT_LFB_VALID
init|=
literal|7
block|,
comment|/* LFB Occupancy (each cycle adds \# of LFBs valid) */
name|CVMX_L2C_TAD_EVENT_LFB_WAIT_LFB
init|=
literal|8
block|,
comment|/* LFB Wait LFB (each cycle adds \# LFBs waiting for other LFBs) */
name|CVMX_L2C_TAD_EVENT_LFB_WAIT_VAB
init|=
literal|9
block|,
comment|/* LFB Wait VAB (each cycle adds \# LFBs waiting for VAB) */
name|CVMX_L2C_TAD_EVENT_QUAD0_INDEX
init|=
literal|128
block|,
comment|/* Quad 0 index bus inuse */
name|CVMX_L2C_TAD_EVENT_QUAD0_READ
init|=
literal|129
block|,
comment|/* Quad 0 read data bus inuse */
name|CVMX_L2C_TAD_EVENT_QUAD0_BANK
init|=
literal|130
block|,
comment|/* Quad 0 \# banks inuse (0-4/cycle) */
name|CVMX_L2C_TAD_EVENT_QUAD0_WDAT
init|=
literal|131
block|,
comment|/* Quad 0 wdat flops inuse (0-4/cycle) */
name|CVMX_L2C_TAD_EVENT_QUAD1_INDEX
init|=
literal|144
block|,
comment|/* Quad 1 index bus inuse */
name|CVMX_L2C_TAD_EVENT_QUAD1_READ
init|=
literal|145
block|,
comment|/* Quad 1 read data bus inuse */
name|CVMX_L2C_TAD_EVENT_QUAD1_BANK
init|=
literal|146
block|,
comment|/* Quad 1 \# banks inuse (0-4/cycle) */
name|CVMX_L2C_TAD_EVENT_QUAD1_WDAT
init|=
literal|147
block|,
comment|/* Quad 1 wdat flops inuse (0-4/cycle) */
name|CVMX_L2C_TAD_EVENT_QUAD2_INDEX
init|=
literal|160
block|,
comment|/* Quad 2 index bus inuse */
name|CVMX_L2C_TAD_EVENT_QUAD2_READ
init|=
literal|161
block|,
comment|/* Quad 2 read data bus inuse */
name|CVMX_L2C_TAD_EVENT_QUAD2_BANK
init|=
literal|162
block|,
comment|/* Quad 2 \# banks inuse (0-4/cycle) */
name|CVMX_L2C_TAD_EVENT_QUAD2_WDAT
init|=
literal|163
block|,
comment|/* Quad 2 wdat flops inuse (0-4/cycle) */
name|CVMX_L2C_TAD_EVENT_QUAD3_INDEX
init|=
literal|176
block|,
comment|/* Quad 3 index bus inuse */
name|CVMX_L2C_TAD_EVENT_QUAD3_READ
init|=
literal|177
block|,
comment|/* Quad 3 read data bus inuse */
name|CVMX_L2C_TAD_EVENT_QUAD3_BANK
init|=
literal|178
block|,
comment|/* Quad 3 \# banks inuse (0-4/cycle) */
name|CVMX_L2C_TAD_EVENT_QUAD3_WDAT
init|=
literal|179
block|,
comment|/* Quad 3 wdat flops inuse (0-4/cycle) */
name|CVMX_L2C_TAD_EVENT_MAX
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|cvmx_l2c_tad_event
name|cvmx_l2c_tad_event_t
typedef|;
end_typedef

begin_comment
comment|/**  * Configure one of the four L2 Cache performance counters to capture event  * occurences.  *  * @param counter        The counter to configure. Range 0..3.  * @param event          The type of L2 Cache event occurrence to count.  * @param clear_on_read  When asserted, any read of the performance counter  *                       clears the counter.  *  * @note The routine does not clear the counter.  */
end_comment

begin_function_decl
name|void
name|cvmx_l2c_config_perf
parameter_list|(
name|uint32_t
name|counter
parameter_list|,
name|cvmx_l2c_event_t
name|event
parameter_list|,
name|uint32_t
name|clear_on_read
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Read the given L2 Cache performance counter. The counter must be configured  * before reading, but this routine does not enforce this requirement.  *  * @param counter  The counter to configure. Range 0..3.  *  * @return The current counter value.  */
end_comment

begin_function_decl
name|uint64_t
name|cvmx_l2c_read_perf
parameter_list|(
name|uint32_t
name|counter
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Return the L2 Cache way partitioning for a given core.  *  * @param core  The core processor of interest.  *  * @return    The mask specifying the partitioning. 0 bits in mask indicates  *              the cache 'ways' that a core can evict from.  *            -1 on error  */
end_comment

begin_function_decl
name|int
name|cvmx_l2c_get_core_way_partition
parameter_list|(
name|uint32_t
name|core
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Partitions the L2 cache for a core  *  * @param core The core that the partitioning applies to.  * @param mask The partitioning of the ways expressed as a binary  *             mask. A 0 bit allows the core to evict cache lines from  *             a way, while a 1 bit blocks the core from evicting any  *             lines from that way. There must be at least one allowed  *             way (0 bit) in the mask.  *   * @note If any ways are blocked for all cores and the HW blocks, then  *       those ways will never have any cache lines evicted from them.  *       All cores and the hardware blocks are free to read from all  *       ways regardless of the partitioning.  */
end_comment

begin_function_decl
name|int
name|cvmx_l2c_set_core_way_partition
parameter_list|(
name|uint32_t
name|core
parameter_list|,
name|uint32_t
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Return the L2 Cache way partitioning for the hw blocks.  *  * @return    The mask specifying the reserved way. 0 bits in mask indicates  *              the cache 'ways' that a core can evict from.  *            -1 on error  */
end_comment

begin_function_decl
name|int
name|cvmx_l2c_get_hw_way_partition
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Partitions the L2 cache for the hardware blocks.  *  * @param mask The partitioning of the ways expressed as a binary  *             mask. A 0 bit allows the core to evict cache lines from  *             a way, while a 1 bit blocks the core from evicting any  *             lines from that way. There must be at least one allowed  *             way (0 bit) in the mask.  *   * @note If any ways are blocked for all cores and the HW blocks, then  *       those ways will never have any cache lines evicted from them.  *       All cores and the hardware blocks are free to read from all  *       ways regardless of the partitioning.  */
end_comment

begin_function_decl
name|int
name|cvmx_l2c_set_hw_way_partition
parameter_list|(
name|uint32_t
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Return the L2 Cache way partitioning for the second set of hw blocks.  *  * @return    The mask specifying the reserved way. 0 bits in mask indicates  *              the cache 'ways' that a core can evict from.  *            -1 on error  */
end_comment

begin_function_decl
name|int
name|cvmx_l2c_get_hw_way_partition2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Partitions the L2 cache for the second set of  blocks.  *  * @param mask The partitioning of the ways expressed as a binary  *             mask. A 0 bit allows the core to evict cache lines from  *             a way, while a 1 bit blocks the core from evicting any  *             lines from that way. There must be at least one allowed  *             way (0 bit) in the mask.  *   * @note If any ways are blocked for all cores and the HW blocks, then  *       those ways will never have any cache lines evicted from them.  *       All cores and the hardware blocks are free to read from all  *       ways regardless of the partitioning.  */
end_comment

begin_function_decl
name|int
name|cvmx_l2c_set_hw_way_partition2
parameter_list|(
name|uint32_t
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Locks a line in the L2 cache at the specified physical address  *  * @param addr   physical address of line to lock  *  * @return 0 on success,  *         1 if line not locked.  */
end_comment

begin_function_decl
name|int
name|cvmx_l2c_lock_line
parameter_list|(
name|uint64_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Locks a specified memory region in the L2 cache.  *  * Note that if not all lines can be locked, that means that all  * but one of the ways (associations) available to the locking  * core are locked.  Having only 1 association available for  * normal caching may have a significant adverse affect on performance.  * Care should be taken to ensure that enough of the L2 cache is left  * unlocked to allow for normal caching of DRAM.  *  * @param start  Physical address of the start of the region to lock  * @param len    Length (in bytes) of region to lock  *  * @return Number of requested lines that where not locked.  *         0 on success (all locked)  */
end_comment

begin_function_decl
name|int
name|cvmx_l2c_lock_mem_region
parameter_list|(
name|uint64_t
name|start
parameter_list|,
name|uint64_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Unlock and flush a cache line from the L2 cache.  * IMPORTANT: Must only be run by one core at a time due to use  * of L2C debug features.  * Note that this function will flush a matching but unlocked cache line.  * (If address is not in L2, no lines are flushed.)  *  * @param address Physical address to unlock  *  * @return 0: line not unlocked  *         1: line unlocked  */
end_comment

begin_function_decl
name|int
name|cvmx_l2c_unlock_line
parameter_list|(
name|uint64_t
name|address
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Unlocks a region of memory that is locked in the L2 cache  *  * @param start  start physical address  * @param len    length (in bytes) to unlock  *  * @return Number of locked lines that the call unlocked  */
end_comment

begin_function_decl
name|int
name|cvmx_l2c_unlock_mem_region
parameter_list|(
name|uint64_t
name|start
parameter_list|,
name|uint64_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Read the L2 controller tag for a given location in L2  *  * @param association  *               Which association to read line from  * @param index  Which way to read from.  *  * @return l2c tag structure for line requested.  *   * NOTE: This function is deprecated and cannot be used on devices with   *       multiple L2C interfaces such as the OCTEON CN68XX.  *       Please use cvmx_l2c_get_tag_v2 instead.  */
end_comment

begin_function_decl
name|cvmx_l2c_tag_t
name|cvmx_l2c_get_tag
parameter_list|(
name|uint32_t
name|association
parameter_list|,
name|uint32_t
name|index
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(deprecated
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**  * Read the L2 controller tag for a given location in L2  *  * @param association  *               Which association to read line from  * @param index  Which way to read from.  *   * @param tad    Which TAD to read from, set to 0 except on OCTEON CN68XX.  *  * @return l2c tag structure for line requested.  */
end_comment

begin_function_decl
name|cvmx_l2c_tag_t
name|cvmx_l2c_get_tag_v2
parameter_list|(
name|uint32_t
name|association
parameter_list|,
name|uint32_t
name|index
parameter_list|,
name|uint32_t
name|tad
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Find the TAD for the specified address  *  * @param addr   physical address to get TAD for  *   * @return TAD number for address.  */
end_comment

begin_function_decl
name|int
name|cvmx_l2c_address_to_tad
parameter_list|(
name|uint64_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Returns the cache index for a given physical address  *  * @param addr   physical address  *  * @return L2 cache index  */
end_comment

begin_function_decl
name|uint32_t
name|cvmx_l2c_address_to_index
parameter_list|(
name|uint64_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Returns the L2 tag that will be used for the given physical address  *  * @param addr   physical address  * @return L2 cache tag. Addreses in the LMC hole are not valid.  * Returns 0xFFFFFFFF if the address specified is in the LMC hole.  */
end_comment

begin_function_decl
name|uint32_t
name|cvmx_l2c_v2_address_to_tag
parameter_list|(
name|uint64_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Flushes (and unlocks) the entire L2 cache.  * IMPORTANT: Must only be run by one core at a time due to use  * of L2C debug features.  */
end_comment

begin_function_decl
name|void
name|cvmx_l2c_flush
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  *  * @return Returns the size of the L2 cache in bytes,  * -1 on error (unrecognized model)  */
end_comment

begin_function_decl
name|int
name|cvmx_l2c_get_cache_size_bytes
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Return the number of sets in the L2 Cache  *  * @return  */
end_comment

begin_function_decl
name|int
name|cvmx_l2c_get_num_sets
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Return log base 2 of the number of sets in the L2 cache  * @return  */
end_comment

begin_function_decl
name|int
name|cvmx_l2c_get_set_bits
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Return the number of associations in the L2 Cache  *  * @return  */
end_comment

begin_function_decl
name|int
name|cvmx_l2c_get_num_assoc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Flush a line from the L2 cache  * This should only be called from one core at a time, as this routine  * sets the core to the 'debug' core in order to flush the line.  *  * @param assoc  Association (or way) to flush  * @param index  Index to flush  */
end_comment

begin_function_decl
name|void
name|cvmx_l2c_flush_line
parameter_list|(
name|uint32_t
name|assoc
parameter_list|,
name|uint32_t
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Initialize the BIG address in L2C+DRAM to generate proper error  * on reading/writing to an non-existant memory location.   *  * @param mem_size  Amount of DRAM configured in MB.  * @param mode      Allow/Disallow reporting errors L2C_INT_SUM[BIGRD,BIGWR].  */
end_comment

begin_function_decl
name|void
name|cvmx_l2c_set_big_size
parameter_list|(
name|uint64_t
name|mem_size
parameter_list|,
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CVMX_BUILD_FOR_LINUX_HOST
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|CVMX_BUILD_FOR_LINUX_KERNEL
argument_list|)
end_if

begin_comment
comment|/*  * Set maxium number of Virtual IDS allowed in a machine.  *  * @param nvid  Number of virtial ids allowed in a machine.  * @return      Return 0 on success or -1 on failure.  */
end_comment

begin_function_decl
name|int
name|cvmx_l2c_vrt_set_max_virtids
parameter_list|(
name|int
name|nvid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get maxium number of virtual IDs allowed in a machine.  *  * @return  Return number of virtual machine IDs. Return -1 on failure.  */
end_comment

begin_function_decl
name|int
name|cvmx_l2c_vrt_get_max_virtids
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Set the maxium size of memory space to be allocated for virtualization.  *  * @param memsz     Size of the virtual memory in GB  * @return          Return 0 on success or -1 on failure.  */
end_comment

begin_function_decl
name|int
name|cvmx_l2c_vrt_set_max_memsz
parameter_list|(
name|int
name|memsz
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Set a Virtual ID to a set of cores.  *  * @param virtid    Assign virtid to a set of cores.  * @param coremask  The group of cores to assign a unique virtual id.  * @return          Return 0 on success, otherwise -1.  */
end_comment

begin_function_decl
name|int
name|cvmx_l2c_vrt_assign_virtid
parameter_list|(
name|int
name|virtid
parameter_list|,
name|uint32_t
name|coremask
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Remove a virt id assigned to a set of cores. Update the virtid mask and  * virtid stored for each core.  *  * @param coremask  the group of cores whose virtual id is removed.  */
end_comment

begin_function_decl
name|void
name|cvmx_l2c_vrt_remove_virtid
parameter_list|(
name|int
name|virtid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Block a memory region to be updated by a set of virtids.  *  * @param start_addr   Starting address of memory region  * @param size         Size of the memory to protect  * @param virtid_mask  Virtual ID to use  * @param mode         Allow/Disallow write access  *                        = 0,  Allow write access by virtid  *                        = 1,  Disallow write access by virtid  */
end_comment

begin_function_decl
name|int
name|cvmx_l2c_vrt_memprotect
parameter_list|(
name|uint64_t
name|start_addr
parameter_list|,
name|int
name|size
parameter_list|,
name|int
name|virtid
parameter_list|,
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Enable virtualization.  */
end_comment

begin_function_decl
name|void
name|cvmx_l2c_vrt_enable
parameter_list|(
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Disable virtualization.  */
end_comment

begin_function_decl
name|void
name|cvmx_l2c_vrt_disable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CVMX_BUILD_FOR_LINUX_HOST */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CVMX_L2C_H__ */
end_comment

end_unit

