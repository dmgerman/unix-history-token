begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  *  Copyright (c) 2003-2008 Cavium Networks (support@cavium.com). All rights  *  reserved.  *  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions are  *  met:  *  *      * Redistributions of source code must retain the above copyright  *        notice, this list of conditions and the following disclaimer.  *  *      * Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials provided  *        with the distribution.  *  *      * Neither the name of Cavium Networks nor the names of  *        its contributors may be used to endorse or promote products  *        derived from this software without specific prior written  *        permission.  *  *  TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  *  AND WITH ALL FAULTS AND CAVIUM NETWORKS MAKES NO PROMISES, REPRESENTATIONS  *  OR WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH  *  RESPECT TO THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY  *  REPRESENTATION OR DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT  *  DEFECTS, AND CAVIUM SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES  *  OF TITLE, MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR  *  PURPOSE, LACK OF VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET  *  POSSESSION OR CORRESPONDENCE TO DESCRIPTION.  THE ENTIRE RISK ARISING OUT  *  OF USE OR PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  *  *  *  For any questions regarding licensing please contact marketing@caviumnetworks.com  *  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * Interface to the Level 2 Cache (L2C) control, measurement, and debugging  * facilities.  *  *<hr>$Revision: 41586 $<hr>  *  */
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
name|CVMX_L2_ASSOC
value|cvmx_l2c_get_num_assoc()
end_define

begin_comment
comment|/* Deprecated macro, use function */
end_comment

begin_define
define|#
directive|define
name|CVMX_L2_SET_BITS
value|cvmx_l2c_get_set_bits()
end_define

begin_comment
comment|/* Deprecated macro, use function */
end_comment

begin_define
define|#
directive|define
name|CVMX_L2_SETS
value|cvmx_l2c_get_num_sets()
end_define

begin_comment
comment|/* Deprecated macro, use function */
end_comment

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

begin_comment
comment|/*------------*/
end_comment

begin_comment
comment|/*  TYPEDEFS  */
end_comment

begin_comment
comment|/*------------*/
end_comment

begin_typedef
typedef|typedef
union|union
block|{
comment|// L2C Tag/Data Store Debug Register
name|uint64_t
name|u64
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|reserved
range|:
literal|32
decl_stmt|,
name|lfb_enum
range|:
literal|4
decl_stmt|,
name|lfb_dmp
range|:
literal|1
decl_stmt|,
name|ppnum
range|:
literal|4
decl_stmt|,
name|set
range|:
literal|3
decl_stmt|,
name|finv
range|:
literal|1
decl_stmt|,
name|l2d
range|:
literal|1
decl_stmt|,
name|l2t
range|:
literal|1
decl_stmt|;
block|}
struct|;
block|}
name|cvmx_l2c_dbg
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|uint64_t
name|u64
decl_stmt|;
if|#
directive|if
name|__BYTE_ORDER
operator|==
name|__BIG_ENDIAN
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
comment|// Line valid
name|uint64_t
name|D
range|:
literal|1
decl_stmt|;
comment|// Line dirty
name|uint64_t
name|L
range|:
literal|1
decl_stmt|;
comment|// Line locked
name|uint64_t
name|U
range|:
literal|1
decl_stmt|;
comment|// Use, LRU eviction
name|uint64_t
name|addr
range|:
literal|32
decl_stmt|;
comment|// Phys mem (not all bits valid)
block|}
name|s
struct|;
endif|#
directive|endif
block|}
name|cvmx_l2c_tag_t
typedef|;
end_typedef

begin_comment
comment|/* L2C Performance Counter events. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CVMX_L2C_EVENT_CYCLES
init|=
literal|0
block|,
name|CVMX_L2C_EVENT_INSTRUCTION_MISS
init|=
literal|1
block|,
name|CVMX_L2C_EVENT_INSTRUCTION_HIT
init|=
literal|2
block|,
name|CVMX_L2C_EVENT_DATA_MISS
init|=
literal|3
block|,
name|CVMX_L2C_EVENT_DATA_HIT
init|=
literal|4
block|,
name|CVMX_L2C_EVENT_MISS
init|=
literal|5
block|,
name|CVMX_L2C_EVENT_HIT
init|=
literal|6
block|,
name|CVMX_L2C_EVENT_VICTIM_HIT
init|=
literal|7
block|,
name|CVMX_L2C_EVENT_INDEX_CONFLICT
init|=
literal|8
block|,
name|CVMX_L2C_EVENT_TAG_PROBE
init|=
literal|9
block|,
name|CVMX_L2C_EVENT_TAG_UPDATE
init|=
literal|10
block|,
name|CVMX_L2C_EVENT_TAG_COMPLETE
init|=
literal|11
block|,
name|CVMX_L2C_EVENT_TAG_DIRTY
init|=
literal|12
block|,
name|CVMX_L2C_EVENT_DATA_STORE_NOP
init|=
literal|13
block|,
name|CVMX_L2C_EVENT_DATA_STORE_READ
init|=
literal|14
block|,
name|CVMX_L2C_EVENT_DATA_STORE_WRITE
init|=
literal|15
block|,
name|CVMX_L2C_EVENT_FILL_DATA_VALID
init|=
literal|16
block|,
name|CVMX_L2C_EVENT_WRITE_REQUEST
init|=
literal|17
block|,
name|CVMX_L2C_EVENT_READ_REQUEST
init|=
literal|18
block|,
name|CVMX_L2C_EVENT_WRITE_DATA_VALID
init|=
literal|19
block|,
name|CVMX_L2C_EVENT_XMC_NOP
init|=
literal|20
block|,
name|CVMX_L2C_EVENT_XMC_LDT
init|=
literal|21
block|,
name|CVMX_L2C_EVENT_XMC_LDI
init|=
literal|22
block|,
name|CVMX_L2C_EVENT_XMC_LDD
init|=
literal|23
block|,
name|CVMX_L2C_EVENT_XMC_STF
init|=
literal|24
block|,
name|CVMX_L2C_EVENT_XMC_STT
init|=
literal|25
block|,
name|CVMX_L2C_EVENT_XMC_STP
init|=
literal|26
block|,
name|CVMX_L2C_EVENT_XMC_STC
init|=
literal|27
block|,
name|CVMX_L2C_EVENT_XMC_DWB
init|=
literal|28
block|,
name|CVMX_L2C_EVENT_XMC_PL2
init|=
literal|29
block|,
name|CVMX_L2C_EVENT_XMC_PSL1
init|=
literal|30
block|,
name|CVMX_L2C_EVENT_XMC_IOBLD
init|=
literal|31
block|,
name|CVMX_L2C_EVENT_XMC_IOBST
init|=
literal|32
block|,
name|CVMX_L2C_EVENT_XMC_IOBDMA
init|=
literal|33
block|,
name|CVMX_L2C_EVENT_XMC_IOBRSP
init|=
literal|34
block|,
name|CVMX_L2C_EVENT_XMC_BUS_VALID
init|=
literal|35
block|,
name|CVMX_L2C_EVENT_XMC_MEM_DATA
init|=
literal|36
block|,
name|CVMX_L2C_EVENT_XMC_REFL_DATA
init|=
literal|37
block|,
name|CVMX_L2C_EVENT_XMC_IOBRSP_DATA
init|=
literal|38
block|,
name|CVMX_L2C_EVENT_RSC_NOP
init|=
literal|39
block|,
name|CVMX_L2C_EVENT_RSC_STDN
init|=
literal|40
block|,
name|CVMX_L2C_EVENT_RSC_FILL
init|=
literal|41
block|,
name|CVMX_L2C_EVENT_RSC_REFL
init|=
literal|42
block|,
name|CVMX_L2C_EVENT_RSC_STIN
init|=
literal|43
block|,
name|CVMX_L2C_EVENT_RSC_SCIN
init|=
literal|44
block|,
name|CVMX_L2C_EVENT_RSC_SCFL
init|=
literal|45
block|,
name|CVMX_L2C_EVENT_RSC_SCDN
init|=
literal|46
block|,
name|CVMX_L2C_EVENT_RSC_DATA_VALID
init|=
literal|47
block|,
name|CVMX_L2C_EVENT_RSC_VALID_FILL
init|=
literal|48
block|,
name|CVMX_L2C_EVENT_RSC_VALID_STRSP
init|=
literal|49
block|,
name|CVMX_L2C_EVENT_RSC_VALID_REFL
init|=
literal|50
block|,
name|CVMX_L2C_EVENT_LRF_REQ
init|=
literal|51
block|,
name|CVMX_L2C_EVENT_DT_RD_ALLOC
init|=
literal|52
block|,
name|CVMX_L2C_EVENT_DT_WR_INVAL
init|=
literal|53
block|}
name|cvmx_l2c_event_t
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
comment|/**  * Partitions the L2 cache for a core  *  * @param core   The core that the partitioning applies to.  * @param mask The partitioning of the ways expressed as a binary mask. A 0 bit allows the core  *             to evict cache lines from a way, while a 1 bit blocks the core from evicting any lines  *             from that way. There must be at least one allowed way (0 bit) in the mask.  *  * @note  If any ways are blocked for all cores and the HW blocks, then those ways will never have  *        any cache lines evicted from them.  All cores and the hardware blocks are free to read from  *        all ways regardless of the partitioning.  */
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
comment|/**  * Partitions the L2 cache for the hardware blocks.  *  * @param mask The partitioning of the ways expressed as a binary mask. A 0 bit allows the core  *             to evict cache lines from a way, while a 1 bit blocks the core from evicting any lines  *             from that way. There must be at least one allowed way (0 bit) in the mask.  *  * @note  If any ways are blocked for all cores and the HW blocks, then those ways will never have  *        any cache lines evicted from them.  All cores and the hardware blocks are free to read from  *        all ways regardless of the partitioning.  */
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
comment|/**  * Read the L2 controller tag for a given location in L2  *  * @param association  *               Which association to read line from  * @param index  Which way to read from.  *  * @return l2c tag structure for line requested.  */
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
function_decl|;
end_function_decl

begin_comment
comment|/* Wrapper around deprecated old function name */
end_comment

begin_function
specifier|static
specifier|inline
name|cvmx_l2c_tag_t
name|cvmx_get_l2c_tag
parameter_list|(
name|uint32_t
name|association
parameter_list|,
name|uint32_t
name|index
parameter_list|)
block|{
return|return
name|cvmx_l2c_get_tag
argument_list|(
name|association
argument_list|,
name|index
argument_list|)
return|;
block|}
end_function

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CVMX_L2C_H__ */
end_comment

end_unit

