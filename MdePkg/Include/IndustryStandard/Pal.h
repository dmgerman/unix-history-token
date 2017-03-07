begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Main PAL API's defined in Intel Itanium Architecture Software Developer's Manual.    Copyright (c) 2006 - 2012, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAL_API_H__
end_ifndef

begin_define
define|#
directive|define
name|__PAL_API_H__
end_define

begin_define
define|#
directive|define
name|PAL_SUCCESS
value|0x0
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// CacheType of PAL_CACHE_FLUSH.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PAL_CACHE_FLUSH_INSTRUCTION_ALL
value|1
end_define

begin_define
define|#
directive|define
name|PAL_CACHE_FLUSH_DATA_ALL
value|2
end_define

begin_define
define|#
directive|define
name|PAL_CACHE_FLUSH_ALL
value|3
end_define

begin_define
define|#
directive|define
name|PAL_CACHE_FLUSH_SYNC_TO_DATA
value|4
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Bitmask of Opearation of PAL_CACHE_FLUSH.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PAL_CACHE_FLUSH_INVALIDATE_LINES
value|BIT0
end_define

begin_define
define|#
directive|define
name|PAL_CACHE_FLUSH_NO_INVALIDATE_LINES
value|0
end_define

begin_define
define|#
directive|define
name|PAL_CACHE_FLUSH_POLL_INTERRUPT
value|BIT1
end_define

begin_define
define|#
directive|define
name|PAL_CACHE_FLUSH_NO_INTERRUPT
value|0
end_define

begin_comment
comment|/**   PAL Procedure - PAL_CACHE_FLUSH.    Flush the instruction or data caches. It is required by Itanium processors.   The PAL procedure supports the Static Registers calling   convention. It could be called at virtual mode and physical   mode.    @param Index              Index of PAL_CACHE_FLUSH within the                             list of PAL procedures.   @param CacheType          Unsigned 64-bit integer indicating                             which cache to flush.   @param Operation          Formatted bit vector indicating the                             operation of this call.   @param ProgressIndicator  Unsigned 64-bit integer specifying                             the starting position of the flush                             operation.    @retval 2                 Call completed without error, but a PMI                             was taken during the execution of this                             procedure.   @retval 1                 Call has not completed flushing due to                             a pending interrupt.   @retval 0                 Call completed without error   @retval -2                Invalid argument   @retval -3                Call completed with error    @return R9                Unsigned 64-bit integer specifying the vector                             number of the pending interrupt.   @return R10               Unsigned 64-bit integer specifying the                             starting position of the flush operation.   @return R11               Unsigned 64-bit integer specifying the vector                             number of the pending interrupt.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_CACHE_FLUSH
value|1
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Attributes of PAL_CACHE_CONFIG_INFO1
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PAL_CACHE_ATTR_WT
value|0
end_define

begin_define
define|#
directive|define
name|PAL_CACHE_ATTR_WB
value|1
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// PAL_CACHE_CONFIG_INFO1.StoreHint
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PAL_CACHE_STORE_TEMPORAL
value|0
end_define

begin_define
define|#
directive|define
name|PAL_CACHE_STORE_NONE_TEMPORAL
value|3
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// PAL_CACHE_CONFIG_INFO1.StoreHint
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PAL_CACHE_STORE_TEMPORAL_LVL_1
value|0
end_define

begin_define
define|#
directive|define
name|PAL_CACHE_STORE_NONE_TEMPORAL_LVL_ALL
value|3
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// PAL_CACHE_CONFIG_INFO1.StoreHint
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PAL_CACHE_LOAD_TEMPORAL_LVL_1
value|0
end_define

begin_define
define|#
directive|define
name|PAL_CACHE_LOAD_NONE_TEMPORAL_LVL_1
value|1
end_define

begin_define
define|#
directive|define
name|PAL_CACHE_LOAD_NONE_TEMPORAL_LVL_ALL
value|3
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Detail the characteristics of a given processor controlled
end_comment

begin_comment
comment|/// cache in the cache hierarchy.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|IsUnified
range|:
literal|1
decl_stmt|;
name|UINT64
name|Attributes
range|:
literal|2
decl_stmt|;
name|UINT64
name|Associativity
range|:
literal|8
decl_stmt|;
name|UINT64
name|LineSize
range|:
literal|8
decl_stmt|;
name|UINT64
name|Stride
range|:
literal|8
decl_stmt|;
name|UINT64
name|StoreLatency
range|:
literal|8
decl_stmt|;
name|UINT64
name|StoreHint
range|:
literal|8
decl_stmt|;
name|UINT64
name|LoadHint
range|:
literal|8
decl_stmt|;
block|}
name|PAL_CACHE_INFO_RETURN1
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Detail the characteristics of a given processor controlled
end_comment

begin_comment
comment|/// cache in the cache hierarchy.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|CacheSize
range|:
literal|32
decl_stmt|;
name|UINT64
name|AliasBoundary
range|:
literal|8
decl_stmt|;
name|UINT64
name|TagLsBits
range|:
literal|8
decl_stmt|;
name|UINT64
name|TagMsBits
range|:
literal|8
decl_stmt|;
block|}
name|PAL_CACHE_INFO_RETURN2
typedef|;
end_typedef

begin_comment
comment|/**   PAL Procedure - PAL_CACHE_INFO.    Return detailed instruction or data cache information. It is   required by Itanium processors. The PAL procedure supports the Static   Registers calling convention. It could be called at virtual   mode and physical mode.    @param Index        Index of PAL_CACHE_INFO within the list of                       PAL procedures.   @param CacheLevel   Unsigned 64-bit integer specifying the                       level in the cache hierarchy for which                       information is requested. This value must                       be between 0 and one less than the value                       returned in the cache_levels return value                       from PAL_CACHE_SUMMARY.   @param CacheType    Unsigned 64-bit integer with a value of 1                       for instruction cache and 2 for data or                       unified cache. All other values are                       reserved.   @param Reserved     Should be 0.    @retval 0           Call completed without error   @retval -2          Invalid argument   @retval -3          Call completed with error    @return R9          Detail the characteristics of a given                       processor controlled cache in the cache                       hierarchy. See PAL_CACHE_INFO_RETURN1.   @return R10         Detail the characteristics of a given                       processor controlled cache in the cache                       hierarchy. See PAL_CACHE_INFO_RETURN2.   @return R11         Reserved with 0.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_CACHE_INFO
value|2
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Level of PAL_CACHE_INIT.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PAL_CACHE_INIT_ALL
value|0xffffffffffffffffULL
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// CacheType
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PAL_CACHE_INIT_TYPE_INSTRUCTION
value|0x1
end_define

begin_define
define|#
directive|define
name|PAL_CACHE_INIT_TYPE_DATA
value|0x2
end_define

begin_define
define|#
directive|define
name|PAL_CACHE_INIT_TYPE_INSTRUCTION_AND_DATA
value|0x3
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Restrict of PAL_CACHE_INIT.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PAL_CACHE_INIT_NO_RESTRICT
value|0
end_define

begin_define
define|#
directive|define
name|PAL_CACHE_INIT_RESTRICTED
value|1
end_define

begin_comment
comment|/**   PAL Procedure - PAL_CACHE_INIT.    Initialize the instruction or data caches. It is required by   Itanium processors. The PAL procedure supports the Static Registers calling   convention. It could be called at physical mode.    @param Index      Index of PAL_CACHE_INIT within the list of PAL                     procedures.   @param Level      Unsigned 64-bit integer containing the level of                     cache to initialize. If the cache level can be                     initialized independently, only that level will                     be initialized. Otherwise                     implementation-dependent side-effects will                     occur.   @param CacheType  Unsigned 64-bit integer with a value of 1 to                     initialize the instruction cache, 2 to                     initialize the data cache, or 3 to                     initialize both. All other values are                     reserved.   @param Restrict   Unsigned 64-bit integer with a value of 0 or                     1. All other values are reserved. If                     restrict is 1 and initializing the specified                     level and cache_type of the cache would                     cause side-effects, PAL_CACHE_INIT will                     return -4 instead of initializing the cache.    @retval 0         Call completed without error   @retval -2        Invalid argument   @retval -3        Call completed with error.   @retval -4        Call could not initialize the specified                     level and cache_type of the cache without                     side-effects and restrict was 1.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_CACHE_INIT
value|3
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// PAL_CACHE_PROTECTION.Method.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PAL_CACHE_PROTECTION_NONE_PROTECT
value|0
end_define

begin_define
define|#
directive|define
name|PAL_CACHE_PROTECTION_ODD_PROTECT
value|1
end_define

begin_define
define|#
directive|define
name|PAL_CACHE_PROTECTION_EVEN_PROTECT
value|2
end_define

begin_define
define|#
directive|define
name|PAL_CACHE_PROTECTION_ECC_PROTECT
value|3
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// PAL_CACHE_PROTECTION.TagOrData.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PAL_CACHE_PROTECTION_PROTECT_DATA
value|0
end_define

begin_define
define|#
directive|define
name|PAL_CACHE_PROTECTION_PROTECT_TAG
value|1
end_define

begin_define
define|#
directive|define
name|PAL_CACHE_PROTECTION_PROTECT_TAG_ANDTHEN_DATA
value|2
end_define

begin_define
define|#
directive|define
name|PAL_CACHE_PROTECTION_PROTECT_DATA_ANDTHEN_TAG
value|3
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// 32-bit protection information structures.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|DataBits
range|:
literal|8
decl_stmt|;
name|UINT32
name|TagProtLsb
range|:
literal|6
decl_stmt|;
name|UINT32
name|TagProtMsb
range|:
literal|6
decl_stmt|;
name|UINT32
name|ProtBits
range|:
literal|6
decl_stmt|;
name|UINT32
name|Method
range|:
literal|4
decl_stmt|;
name|UINT32
name|TagOrData
range|:
literal|2
decl_stmt|;
block|}
name|PAL_CACHE_PROTECTION
typedef|;
end_typedef

begin_comment
comment|/**   PAL Procedure - PAL_CACHE_PROT_INFO.    Return instruction or data cache protection information. It is   required by Itanium processors. The PAL procedure supports the Static   Registers calling convention. It could be called at physical   mode and Virtual mode.    @param Index      Index of PAL_CACHE_PROT_INFO within the list of                     PAL procedures.   @param CacheLevel Unsigned 64-bit integer specifying the level                     in the cache hierarchy for which information                     is requested. This value must be between 0                     and one less than the value returned in the                     cache_levels return value from                     PAL_CACHE_SUMMARY.   @param CacheType  Unsigned 64-bit integer with a value of 1                     for instruction cache and 2 for data or                     unified cache. All other values are                     reserved.    @retval 0         Call completed without error   @retval -2        Invalid argument   @retval -3        Call completed with error.    @return R9        Detail the characteristics of a given                     processor controlled cache in the cache                     hierarchy. See PAL_CACHE_PROTECTION[0..1].   @return R10       Detail the characteristics of a given                     processor controlled cache in the cache                     hierarchy. See PAL_CACHE_PROTECTION[2..3].   @return R11       Detail the characteristics of a given                     processor controlled cache in the cache                     hierarchy. See PAL_CACHE_PROTECTION[4..5].  **/
end_comment

begin_define
define|#
directive|define
name|PAL_CACHE_PROT_INFO
value|38
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|ThreadId
range|:
literal|16
decl_stmt|;
comment|///< The thread identifier of the logical
comment|///< processor for which information is being
comment|///< returned. This value will be unique on a per core basis.
name|UINT64
name|Reserved1
range|:
literal|16
decl_stmt|;
name|UINT64
name|CoreId
range|:
literal|16
decl_stmt|;
comment|///< The core identifier of the logical processor
comment|///< for which information is being returned.
comment|///< This value will be unique on a per physical
comment|///< processor package basis.
name|UINT64
name|Reserved2
range|:
literal|16
decl_stmt|;
block|}
name|PAL_PCOC_N_CACHE_INFO1
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|LogicalAddress
range|:
literal|16
decl_stmt|;
comment|///< Logical address: geographical address
comment|///< of the logical processor for which
comment|///< information is being returned. This is
comment|///< the same value that is returned by the
comment|///< PAL_FIXED_ADDR procedure when it is
comment|///< called on the logical processor.
name|UINT64
name|Reserved1
range|:
literal|16
decl_stmt|;
name|UINT64
name|Reserved2
range|:
literal|32
decl_stmt|;
block|}
name|PAL_PCOC_N_CACHE_INFO2
typedef|;
end_typedef

begin_comment
comment|/**   PAL Procedure - PAL_CACHE_SHARED_INFO.    Returns information on which logical processors share caches.   It is optional. The PAL procedure supports the Static   Registers calling convention. It could be called at physical   mode and Virtual mode.    @param Index       Index of PAL_CACHE_SHARED_INFO within the list                      of PAL procedures.   @param CacheLevel  Unsigned 64-bit integer specifying the                      level in the cache hierarchy for which                      information is requested. This value must                      be between 0 and one less than the value                      returned in the cache_levels return value                      from PAL_CACHE_SUMMARY.   @param CacheType   Unsigned 64-bit integer with a value of 1                      for instruction cache and 2 for data or                      unified cache. All other values are                      reserved.   @param ProcNumber  Unsigned 64-bit integer that specifies for                      which logical processor information is                      being requested. This input argument must                      be zero for the first call to this                      procedure and can be a maximum value of                      one less than the number of logical                      processors sharing this cache, which is                      returned by the num_shared return value.    @retval 0          Call completed without error   @retval -1         Unimplemented procedure   @retval -2         Invalid argument   @retval -3         Call completed with error.    @return R9         Unsigned integer that returns the number of                      logical processors that share the processor                      cache level and type, for which information was                      requested.   @return R10        The format of PAL_PCOC_N_CACHE_INFO1.   @return R11        The format of PAL_PCOC_N_CACHE_INFO2.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_CACHE_SHARED_INFO
value|43
end_define

begin_comment
comment|/**   PAL Procedure - PAL_CACHE_SUMMARY.    Return a summary of the cache hierarchy. It is required by   Itanium processors. The PAL procedure supports the Static Registers calling   convention. It could be called at physical mode and Virtual   mode.    @param Index  Index of PAL_CACHE_SUMMARY within the list of                 PAL procedures.    @retval 0     Call completed without error   @retval -2    Invalid argument   @retval -3    Call completed with error.    @return R9    CacheLevels   Unsigned 64-bit integer denoting the                               number of levels of cache                               implemented by the processor.                               Strictly, this is the number of                               levels for which the cache                               controller is integrated into the                               processor (the cache SRAMs may be                               external to the processor).   @return R10   UniqueCaches  Unsigned 64-bit integer denoting the                               number of unique caches implemented                               by the processor. This has a maximum                               of 2*cache_levels, but may be less                               if any of the levels in the cache                               hierarchy are unified caches or do                               not have both instruction and data                               caches.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_CACHE_SUMMARY
value|4
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Virtual Memory Attributes implemented by processor.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|PAL_MEMORY_ATTR_WB
value|0
end_define

begin_define
define|#
directive|define
name|PAL_MEMORY_ATTR_WC
value|6
end_define

begin_define
define|#
directive|define
name|PAL_MEMORY_ATTR_UC
value|4
end_define

begin_define
define|#
directive|define
name|PAL_MEMORY_ATTR_UCE
value|5
end_define

begin_define
define|#
directive|define
name|PAL_MEMORY_ATTR_NATPAGE
value|7
end_define

begin_comment
comment|/**   PAL Procedure - PAL_MEM_ATTRIB.    Return a list of supported memory attributes.. It is required   by Itanium processors. The PAL procedure supports the Static Registers calling   convention. It could be called at physical mode and Virtual   mode.    @param Index  Index of PAL_MEM_ATTRIB within the list of PAL                 procedures.    @retval 0     Call completed without error   @retval -2    Invalid argument   @retval -3    Call completed with error.    @return R9    Attributes  8-bit vector of memory attributes                             implemented by processor. See Virtual                             Memory Attributes above.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_MEM_ATTRIB
value|5
end_define

begin_comment
comment|/**   PAL Procedure - PAL_PREFETCH_VISIBILITY.    Used in architected sequence to transition pages from a   cacheable, speculative attribute to an uncacheable attribute.   It is required by Itanium processors. The PAL procedure supports the Static   Registers calling convention. It could be called at physical   mode and Virtual mode.    @param Index          Index of PAL_PREFETCH_VISIBILITY within the list                         of PAL procedures.   @param TransitionType Unsigned integer specifying the type                         of memory attribute transition that is                         being performed.    @retval 1             Call completed without error; this                         call is not necessary on remote                         processors.   @retval 0             Call completed without error   @retval -2            Invalid argument   @retval -3            Call completed with error.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_PREFETCH_VISIBILITY
value|41
end_define

begin_comment
comment|/**   PAL Procedure - PAL_PTCE_INFO.    Return information needed for ptc.e instruction to purge   entire TC. It is required by Itanium processors. The PAL procedure supports   the Static Registers calling convention. It could be called at   physical mode and Virtual mode.    @param Index  Index of PAL_PTCE_INFO within the list                 of PAL procedures.    @retval 0     Call completed without error   @retval -2    Invalid argument   @retval -3    Call completed with error.    @return R9    Unsigned 64-bit integer denoting the beginning                 address to be used by the first PTCE instruction                 in the purge loop.   @return R10   Two unsigned 32-bit integers denoting the loop                 counts of the outer (loop 1) and inner (loop 2)                 purge loops. count1 (loop 1) is contained in bits                 63:32 of the parameter, and count2 (loop 2) is                 contained in bits 31:0 of the parameter.   @return R11   Two unsigned 32-bit integers denoting the loop                 strides of the outer (loop 1) and inner (loop 2)                 purge loops. stride1 (loop 1) is contained in bits                 63:32 of the parameter, and stride2 (loop 2) is                 contained in bits 31:0 of the parameter.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_PTCE_INFO
value|6
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|NumberSets
range|:
literal|8
decl_stmt|;
comment|///< Unsigned 8-bit integer denoting the number
comment|///< of hash sets for the specified level
comment|///< (1=fully associative)
name|UINT64
name|NumberWays
range|:
literal|8
decl_stmt|;
comment|///< Unsigned 8-bit integer denoting the
comment|///< associativity of the specified level
comment|///< (1=direct).
name|UINT64
name|NumberEntries
range|:
literal|16
decl_stmt|;
comment|///< Unsigned 16-bit integer denoting the
comment|///< number of entries in the specified TC.
name|UINT64
name|PageSizeIsOptimized
range|:
literal|1
decl_stmt|;
comment|///< Flag denoting whether the
comment|///< specified level is optimized for
comment|///< the region's preferred page size
comment|///< (1=optimized) tc_pages indicates
comment|///< which page sizes are usable by
comment|///< this translation cache.
name|UINT64
name|TcIsUnified
range|:
literal|1
decl_stmt|;
comment|///< Flag denoting whether the specified TC is
comment|///< unified (1=unified).
name|UINT64
name|EntriesReduction
range|:
literal|1
decl_stmt|;
comment|///< Flag denoting whether installed
comment|///< translation registers will reduce
comment|///< the number of entries within the
comment|///< specified TC.
block|}
name|PAL_TC_INFO
typedef|;
end_typedef

begin_comment
comment|/**   PAL Procedure - PAL_VM_INFO.    Return detailed information about virtual memory features   supported in the processor. It is required by Itanium processors. The PAL   procedure supports the Static Registers calling convention. It   could be called at physical mode and Virtual mode.    @param Index    Index of PAL_VM_INFO within the list                   of PAL procedures.   @param TcLevel  Unsigned 64-bit integer specifying the level                   in the TLB hierarchy for which information is                   required. This value must be between 0 and one                   less than the value returned in the                   vm_info_1.num_tc_levels return value from                   PAL_VM_SUMMARY.   @param TcType   Unsigned 64-bit integer with a value of 1 for                   instruction translation cache and 2 for data                   or unified translation cache. All other values                   are reserved.    @retval 0       Call completed without error   @retval -2      Invalid argument   @retval -3      Call completed with error.    @return R9      8-byte formatted value returning information                   about the specified TC. See PAL_TC_INFO above.   @return R10     64-bit vector containing a bit for each page                   size supported in the specified TC, where bit                   position n indicates a page size of 2**n.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_VM_INFO
value|7
end_define

begin_comment
comment|/**   PAL Procedure - PAL_VM_PAGE_SIZE.    Return virtual memory TC and hardware walker page sizes   supported in the processor. It is required by Itanium processors. The PAL   procedure supports the Static Registers calling convention. It   could be called at physical mode and Virtual mode.    @param Index  Index of PAL_VM_PAGE_SIZE within the list                 of PAL procedures.    @retval 0     Call completed without error   @retval -2    Invalid argument   @retval -3    Call completed with error.    @return R9    64-bit vector containing a bit for each                 architected page size that is supported for                 TLB insertions and region registers.   @return R10   64-bit vector containing a bit for each                 architected page size supported for TLB purge                 operations.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_VM_PAGE_SIZE
value|34
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|WalkerPresent
range|:
literal|1
decl_stmt|;
comment|///< 1-bit flag indicating whether a hardware
comment|///< TLB walker is implemented (1 = walker
comment|///< present).
name|UINT64
name|WidthOfPhysicalAddress
range|:
literal|7
decl_stmt|;
comment|///< Unsigned 7-bit integer
comment|///< denoting the number of bits of
comment|///< physical address implemented.
name|UINT64
name|WidthOfKey
range|:
literal|8
decl_stmt|;
comment|///< Unsigned 8-bit integer denoting the number
comment|///< of bits mplemented in the PKR.key field.
name|UINT64
name|MaxPkrIndex
range|:
literal|8
decl_stmt|;
comment|///< Unsigned 8-bit integer denoting the
comment|///< maximum PKR index (number of PKRs-1).
name|UINT64
name|HashTagId
range|:
literal|8
decl_stmt|;
comment|///< Unsigned 8-bit integer which uniquely
comment|///< identifies the processor hash and tag
comment|///< algorithm.
name|UINT64
name|MaxDtrIndex
range|:
literal|8
decl_stmt|;
comment|///< Unsigned 8 bit integer denoting the
comment|///< maximum data translation register index
comment|///< (number of dtr entries - 1).
name|UINT64
name|MaxItrIndex
range|:
literal|8
decl_stmt|;
comment|///< Unsigned 8 bit integer denoting the
comment|///< maximum instruction translation register
comment|///< index (number of itr entries - 1).
name|UINT64
name|NumberOfUniqueTc
range|:
literal|8
decl_stmt|;
comment|///< Unsigned 8-bit integer denoting the
comment|///< number of unique TCs implemented.
comment|///< This is a maximum of
comment|///< 2*num_tc_levels.
name|UINT64
name|NumberOfTcLevels
range|:
literal|8
decl_stmt|;
comment|///< Unsigned 8-bit integer denoting the
comment|///< number of TC levels.
block|}
name|PAL_VM_INFO1
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|WidthOfVirtualAddress
range|:
literal|8
decl_stmt|;
comment|///< Unsigned 8-bit integer denoting
comment|///< is the total number of virtual
comment|///< address bits - 1.
name|UINT64
name|WidthOfRid
range|:
literal|8
decl_stmt|;
comment|///< Unsigned 8-bit integer denoting the number
comment|///< of bits implemented in the RR.rid field.
name|UINT64
name|MaxPurgedTlbs
range|:
literal|16
decl_stmt|;
comment|///< Unsigned 16 bit integer denoting the
comment|///< maximum number of concurrent outstanding
comment|///< TLB purges allowed by the processor. A
comment|///< value of 0 indicates one outstanding
comment|///< purge allowed. A value of 216-1
comment|///< indicates no limit on outstanding
comment|///< purges. All other values indicate the
comment|///< actual number of concurrent outstanding
comment|///< purges allowed.
name|UINT64
name|Reserved
range|:
literal|32
decl_stmt|;
block|}
name|PAL_VM_INFO2
typedef|;
end_typedef

begin_comment
comment|/**   PAL Procedure - PAL_VM_SUMMARY.    Return summary information about virtual memory features   supported in the processor. It is required by Itanium processors. The PAL   procedure supports the Static Registers calling convention. It   could be called at physical mode and Virtual mode.    @param Index  Index of PAL_VM_SUMMARY within the list                 of PAL procedures.    @retval 0     Call completed without error   @retval -2    Invalid argument   @retval -3    Call completed with error.    @return R9    8-byte formatted value returning global virtual                 memory information. See PAL_VM_INFO1 above.   @return R10   8-byte formatted value returning global virtual                 memory information. See PAL_VM_INFO2 above.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_VM_SUMMARY
value|8
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Bit mask of TR_valid flag.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|PAL_TR_ACCESS_RIGHT_IS_VALID
value|BIT0
end_define

begin_define
define|#
directive|define
name|PAL_TR_PRIVILEGE_LEVEL_IS_VALID
value|BIT1
end_define

begin_define
define|#
directive|define
name|PAL_TR_DIRTY_IS_VALID
value|BIT2
end_define

begin_define
define|#
directive|define
name|PAL_TR_MEMORY_ATTR_IS_VALID
value|BIT3
end_define

begin_comment
comment|/**   PAL Procedure - PAL_VM_TR_READ.    Read contents of a translation register. It is required by   Itanium processors. The PAL procedure supports the Stacked Register calling   convention. It could be called at physical mode.    @param Index      Index of PAL_VM_TR_READ within the list                     of PAL procedures.   @param RegNumber  Unsigned 64-bit number denoting which TR to                     read.   @param TrType     Unsigned 64-bit number denoting whether to                     read an ITR (0) or DTR (1). All other values                     are reserved.   @param TrBuffer   64-bit pointer to the 32-byte memory buffer in                     which translation data is returned.    @retval 0         Call completed without error   @retval -2        Invalid argument   @retval -3        Call completed with error.    @return R9        Formatted bit vector denoting which fields are                     valid. See TR_valid above.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_VM_TR_READ
value|261
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Bit Mask of Processor Bus Fesatures .
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/**    When 0, bus data errors are detected and single bit errors are   corrected. When 1, no error detection or correction is done.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_BUS_DISABLE_DATA_ERROR_SIGNALLING
value|BIT63
end_define

begin_comment
comment|/**    When 0, bus address errors are signalled on the bus. When 1,   no bus errors are signalled on the bus. If Disable Bus Address   Error Checking is 1, this bit is ignored.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_BUS_DISABLE_ADDRESS_ERROR_SIGNALLING
value|BIT62
end_define

begin_comment
comment|/**    When 0, bus errors are detected, single bit errors are   corrected., and a CMCI or MCA is generated internally to the   processor. When 1, no bus address errors are detected or   corrected.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_BUS_DISABLE_ADDRESS_ERROR_CHECK
value|BIT61
end_define

begin_comment
comment|/**    When 0, bus protocol errors (BINIT#) are signaled by the   processor on the bus. When 1, bus protocol errors (BINIT#) are   not signaled on the bus. If Disable Bus Initialization Event   Checking is 1, this bit is ignored.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_BUS_DISABLE_INITIALIZATION_EVENT_SIGNALLING
value|BIT60
end_define

begin_comment
comment|/**    When 0, bus protocol errors (BINIT#) are detected and sampled   and an MCA is generated internally to the processor. When 1,   the processor will ignore bus protocol error conditions   (BINIT#).  **/
end_comment

begin_define
define|#
directive|define
name|PAL_BUS_DISABLE_INITIALIZATION_EVENT_CHECK
value|BIT59
end_define

begin_comment
comment|/**    When 0, BERR# is signalled if a bus error is detected. When 1,   bus errors are not signalled on the bus.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_BUS_DISABLE_ERROR_SIGNALLING
value|BIT58
end_define

begin_comment
comment|/**    When 0, BERR# is signalled when internal processor requestor   initiated bus errors are detected. When 1, internal requester   bus errors are not signalled on the bus.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_BUS_DISABLE__INTERNAL_ERROR_SIGNALLING
value|BIT57
end_define

begin_comment
comment|/**    When 0, the processor takes an MCA if BERR# is asserted. When   1, the processor ignores the BERR# signal.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_BUS_DISABLE_ERROR_CHECK
value|BIT56
end_define

begin_comment
comment|/**    When 0, the processor asserts BINIT# if it detects a parity   error on the signals which identify the transactions to which   this is a response. When 1, the processor ignores parity on   these signals.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_BUS_DISABLE_RSP_ERROR_CHECK
value|BIT55
end_define

begin_comment
comment|/**    When 0, the in-order transaction queue is limited only by the   number of hardware entries. When 1, the processor's in-order   transactions queue is limited to one entry.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_BUS_DISABLE_TRANSACTION_QUEUE
value|BIT54
end_define

begin_comment
comment|/**    Enable a bus cache line replacement transaction when a cache   line in the exclusive state is replaced from the highest level   processor cache and is not present in the lower level processor   caches. When 0, no bus cache line replacement transaction will   be seen on the bus. When 1, bus cache line replacement   transactions will be seen on the bus when the above condition is   detected.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_BUS_ENABLE_EXCLUSIVE_CACHE_LINE_REPLACEMENT
value|BIT53
end_define

begin_comment
comment|/**    Enable a bus cache line replacement transaction when a cache   line in the shared or exclusive state is replaced from the   highest level processor cache and is not present in the lower   level processor caches.   When 0, no bus cache line replacement transaction will be seen   on the bus. When 1, bus cache line replacement transactions   will be seen on the bus when the above condition is detected.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_BUS_ENABLE_SHARED_CACHE_LINE_REPLACEMENT
value|BIT52
end_define

begin_comment
comment|/**    When 0, the data bus is configured at the 2x data transfer   rate.When 1, the data bus is configured at the 1x data   transfer rate, 30 Opt. Req. Disable Bus Lock Mask. When 0, the   processor executes locked transactions atomically. When 1, the   processor masks the bus lock signal and executes locked   transactions as a non-atomic series of transactions.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_BUS_ENABLE_HALF_TRANSFER
value|BIT30
end_define

begin_comment
comment|/**    When 0, the processor will deassert bus request when finished   with each transaction. When 1, the processor will continue to   assert bus request after it has finished, if it was the last   agent to own the bus and if there are no other pending   requests.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_BUS_REQUEST_BUS_PARKING
value|BIT29
end_define

begin_comment
comment|/**   PAL Procedure - PAL_BUS_GET_FEATURES.    Return configurable processor bus interface features and their   current settings. It is required by Itanium processors. The PAL procedure   supports the Stacked Register calling convention. It could be   called at physical mode.    @param Index  Index of PAL_BUS_GET_FEATURES within the list                 of PAL procedures.    @retval 0     Call completed without error   @retval -2    Invalid argument   @retval -3    Call completed with error.    @return R9    64-bit vector of features implemented.                 (1=implemented, 0=not implemented)   @return R10   64-bit vector of current feature settings.   @return R11   64-bit vector of features controllable by                 software. (1=controllable, 0= not controllable)  **/
end_comment

begin_define
define|#
directive|define
name|PAL_BUS_GET_FEATURES
value|9
end_define

begin_comment
comment|/**   PAL Procedure - PAL_BUS_SET_FEATURES.    Enable or disable configurable features in processor bus   interface. It is required by Itanium processors. The PAL procedure   supports the Static Registers calling convention. It could be   called at physical mode.    @param Index          Index of PAL_BUS_SET_FEATURES within the list                         of PAL procedures.   @param FeatureSelect  64-bit vector denoting desired state of                         each feature (1=select, 0=non-select).    @retval 0             Call completed without error   @retval -2            Invalid argument   @retval -3            Call completed with error.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_BUS_SET_FEATURES
value|10
end_define

begin_comment
comment|/**   PAL Procedure - PAL_DEBUG_INFO.    Return the number of instruction and data breakpoint   registers. It is required by Itanium processors. The   PAL procedure supports the Static Registers calling   convention. It could be called at physical mode and virtual   mode.    @param Index  Index of PAL_DEBUG_INFO within the list of PAL                 procedures.    @retval 0     Call completed without error   @retval -2    Invalid argument   @retval -3    Call completed with error.    @return R9    Unsigned 64-bit integer denoting the number of                 pairs of instruction debug registers implemented                 by the processor.   @return R10   Unsigned 64-bit integer denoting the number of                 pairs of data debug registers implemented by the                 processor.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_DEBUG_INFO
value|11
end_define

begin_comment
comment|/**   PAL Procedure - PAL_FIXED_ADDR.    Return the fixed component of a processor's directed address.   It is required by Itanium processors. The PAL   procedure supports the Static Registers calling convention. It   could be called at physical mode and virtual mode.    @param Index  Index of PAL_FIXED_ADDR within the list of PAL                 procedures.    @retval 0     Call completed without error   @retval -2    Invalid argument   @retval -3    Call completed with error.    @return R9    Fixed geographical address of this processor.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_FIXED_ADDR
value|12
end_define

begin_comment
comment|/**   PAL Procedure - PAL_FREQ_BASE.    Return the frequency of the output clock for use by the   platform, if generated by the processor. It is optinal. The   PAL procedure supports the Static Registers calling   convention. It could be called at physical mode and virtual   mode.    @param Index  Index of PAL_FREQ_BASE within the list of PAL                 procedures.    @retval 0     Call completed without error   @retval -1    Unimplemented procedure   @retval -2    Invalid argument   @retval -3    Call completed with error.    @return R9    Base frequency of the platform if generated by the                 processor chip.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_FREQ_BASE
value|13
end_define

begin_comment
comment|/**   PAL Procedure - PAL_FREQ_RATIOS.    Return ratio of processor, bus, and interval time counter to   processor input clock or output clock for platform use, if   generated by the processor. It is required by Itanium processors. The PAL   procedure supports the Static Registers calling convention. It   could be called at physical mode and virtual mode.    @param Index  Index of PAL_FREQ_RATIOS within the list of PAL                 procedures.    @retval 0     Call completed without error   @retval -2    Invalid argument   @retval -3    Call completed with error.    @return R9    Ratio of the processor frequency to the input                 clock of the processor, if the platform clock is                 generated externally or to the output clock to the                 platform, if the platform clock is generated by                 the processor.   @return R10   Ratio of the bus frequency to the input clock of                 the processor, if the platform clock is generated                 externally or to the output clock to the platform,                 if the platform clock is generated by the                 processor.   @return R11   Ratio of the interval timer counter rate to input                 clock of the processor, if the platform clock is                 generated externally or to the output clock to the                 platform, if the platform clock is generated by                 the processor.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_FREQ_RATIOS
value|14
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|NumberOfLogicalProcessors
range|:
literal|16
decl_stmt|;
comment|///< Total number of logical
comment|///< processors on this physical
comment|///< processor package that are
comment|///< enabled.
name|UINT64
name|ThreadsPerCore
range|:
literal|8
decl_stmt|;
comment|///< Number of threads per core.
name|UINT64
name|Reserved1
range|:
literal|8
decl_stmt|;
name|UINT64
name|CoresPerProcessor
range|:
literal|8
decl_stmt|;
comment|///< Total number of cores on this
comment|///< physical processor package.
name|UINT64
name|Reserved2
range|:
literal|8
decl_stmt|;
name|UINT64
name|PhysicalProcessorPackageId
range|:
literal|8
decl_stmt|;
comment|///< Physical processor package
comment|///< identifier which was
comment|///< assigned at reset by the
comment|///< platform or bus
comment|///< controller. This value may
comment|///< or may not be unique
comment|///< across the entire platform
comment|///< since it depends on the
comment|///< platform vendor's policy.
name|UINT64
name|Reserved3
range|:
literal|8
decl_stmt|;
block|}
name|PAL_LOGICAL_PROCESSPR_OVERVIEW
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|ThreadId
range|:
literal|16
decl_stmt|;
comment|///< The thread identifier of the logical
comment|///< processor for which information is being
comment|///< returned. This value will be unique on a per
comment|///< core basis.
name|UINT64
name|Reserved1
range|:
literal|16
decl_stmt|;
name|UINT64
name|CoreId
range|:
literal|16
decl_stmt|;
comment|///< The core identifier of the logical processor
comment|///< for which information is being returned.
comment|///< This value will be unique on a per physical
comment|///< processor package basis.
name|UINT64
name|Reserved2
range|:
literal|16
decl_stmt|;
block|}
name|PAL_LOGICAL_PROCESSORN_INFO1
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|LogicalAddress
range|:
literal|16
decl_stmt|;
comment|///< Geographical address of the logical
comment|///< processor for which information is being
comment|///< returned. This is the same value that is
comment|///< returned by the PAL_FIXED_ADDR procedure
comment|///< when it is called on the logical processor.
name|UINT64
name|Reserved
range|:
literal|48
decl_stmt|;
block|}
name|PAL_LOGICAL_PROCESSORN_INFO2
typedef|;
end_typedef

begin_comment
comment|/**   PAL Procedure - PAL_LOGICAL_TO_PHYSICAL.    Return information on which logical processors map to a   physical processor die. It is optinal. The PAL procedure   supports the Static Registers calling convention. It could be   called at physical mode and virtual mode.    @param Index            Index of PAL_LOGICAL_TO_PHYSICAL within the list of PAL                           procedures.   @param ProcessorNumber  Signed 64-bit integer that specifies                           for which logical processor                           information is being requested. When                           this input argument is -1, information                           is returned about the logical                           processor on which the procedure call                           is made. This input argument must be                           in the range of 1 up to one less than                           the number of logical processors                           returned by num_log in the                           log_overview return value.    @retval 0               Call completed without error   @retval -1              Unimplemented procedure   @retval -2              Invalid argument   @retval -3              Call completed with error.    @return R9              The format of PAL_LOGICAL_PROCESSPR_OVERVIEW.   @return R10             The format of PAL_LOGICAL_PROCESSORN_INFO1.   @return R11             The format of PAL_LOGICAL_PROCESSORN_INFO2.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_LOGICAL_TO_PHYSICAL
value|42
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|NumberOfPmcPairs
range|:
literal|8
decl_stmt|;
comment|///< Unsigned 8-bit number defining the
comment|///< number of generic PMC/PMD pairs.
name|UINT64
name|WidthOfCounter
range|:
literal|8
decl_stmt|;
comment|///< Unsigned 8-bit number in the range
comment|///< 0:60 defining the number of
comment|///< implemented counter bits.
name|UINT64
name|TypeOfCycleCounting
range|:
literal|8
decl_stmt|;
comment|///< Unsigned 8-bit number defining the
comment|///< event type for counting processor cycles.
name|UINT64
name|TypeOfRetiredInstructionBundle
range|:
literal|8
decl_stmt|;
comment|///< Retired Unsigned 8-bit
comment|///< number defining the
comment|///< event type for retired
comment|///< instruction bundles.
name|UINT64
name|Reserved
range|:
literal|32
decl_stmt|;
block|}
name|PAL_PERFORMANCE_INFO
typedef|;
end_typedef

begin_comment
comment|/**   PAL Procedure - PAL_PERF_MON_INFO.    Return the number and type of performance monitors. It is   required by Itanium processors. The PAL procedure supports the Static   Registers calling convention. It could be called at physical   mode and virtual mode.    @param Index              Index of PAL_PERF_MON_INFO within the list of                             PAL procedures.   @param PerformanceBuffer  An address to an 8-byte aligned                             128-byte memory buffer.    @retval 0                 Call completed without error   @retval -2                Invalid argument   @retval -3                Call completed with error.    @return R9                Information about the performance monitors                             implemented. See PAL_PERFORMANCE_INFO;  **/
end_comment

begin_define
define|#
directive|define
name|PAL_PERF_MON_INFO
value|15
end_define

begin_define
define|#
directive|define
name|PAL_PLATFORM_ADDR_INTERRUPT_BLOCK_TOKEN
value|0x0
end_define

begin_define
define|#
directive|define
name|PAL_PLATFORM_ADDR_IO_BLOCK_TOKEN
value|0x1
end_define

begin_comment
comment|/**   PAL Procedure - PAL_PLATFORM_ADDR.    Specify processor interrupt block address and I/O port space   address. It is required by Itanium processors. The PAL procedure supports the   Static Registers calling convention. It could be called at   physical mode and virtual mode.    @param Index    Index of PAL_PLATFORM_ADDR within the list of                   PAL procedures.   @param Type     Unsigned 64-bit integer specifying the type of                   block. 0 indicates that the processor interrupt                   block pointer should be initialized. 1 indicates                   that the processor I/O block pointer should be                   initialized.   @param Address  Unsigned 64-bit integer specifying the address                   to which the processor I/O block or interrupt                   block shall be set. The address must specify                   an implemented physical address on the                   processor model, bit 63 is ignored.    @retval 0       Call completed without error   @retval -1      Unimplemented procedure.   @retval -2      Invalid argument   @retval -3      Call completed with error.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_PLATFORM_ADDR
value|16
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|Reserved1
range|:
literal|36
decl_stmt|;
name|UINT64
name|FaultInUndefinedIns
range|:
literal|1
decl_stmt|;
comment|///< Bit36, No Unimplemented
comment|///< instruction address reported as
comment|///< fault. Denotes how the processor
comment|///< reports the detection of
comment|///< unimplemented instruction
comment|///< addresses. When 1, the processor
comment|///< reports an Unimplemented
comment|///< Instruction Address fault on the
comment|///< unimplemented address; when 0, it
comment|///< reports an Unimplemented
comment|///< Instruction Address trap on the
comment|///< previous instruction in program
comment|///< order. This feature may only be
comment|///< interrogated by
comment|///< PAL_PROC_GET_FEATURES. It may not
comment|///< be enabled or disabled by
comment|///< PAL_PROC_SET_FEATURES. The
comment|///< corresponding argument is ignored.
name|UINT64
name|NoPresentPmi
range|:
literal|1
decl_stmt|;
comment|///< Bit37, No INIT, PMI, and LINT pins
comment|///< present. Denotes the absence of INIT,
comment|///< PMI, LINT0 and LINT1 pins on the
comment|///< processor. When 1, the pins are absent.
comment|///< When 0, the pins are present. This
comment|///< feature may only be interrogated by
comment|///< PAL_PROC_GET_FEATURES. It may not be
comment|///< enabled or disabled by
comment|///< PAL_PROC_SET_FEATURES. The corresponding
comment|///< argument is ignored.
name|UINT64
name|NoSimpleImpInUndefinedIns
range|:
literal|1
decl_stmt|;
comment|///< Bit38, No Simple
comment|///< implementation of
comment|///< unimplemented instruction
comment|///< addresses. Denotes how an
comment|///< unimplemented instruction
comment|///< address is recorded in IIP
comment|///< on an Unimplemented
comment|///< Instruction Address trap or
comment|///< fault. When 1, the full
comment|///< unimplemented address is
comment|///< recorded in IIP; when 0, the
comment|///< address is sign extended
comment|///< (virtual addresses) or zero
comment|///< extended (physical
comment|///< addresses). This feature may
comment|///< only be interrogated by
comment|///< PAL_PROC_GET_FEATURES. It
comment|///< may not be enabled or
comment|///< disabled by
comment|///< PAL_PROC_SET_FEATURES. The
comment|///< corresponding argument is
comment|///< ignored.
name|UINT64
name|NoVariablePState
range|:
literal|1
decl_stmt|;
comment|///< Bit39, No Variable P-state
comment|///< performance: A value of 1, indicates
comment|///< that a processor implements
comment|///< techniques to optimize performance
comment|///< for the given P-state power budget
comment|///< by dynamically varying the
comment|///< frequency, such that maximum
comment|///< performance is achieved for the
comment|///< power budget. A value of 0,
comment|///< indicates that P-states have no
comment|///< frequency variation or very small
comment|///< frequency variations for their given
comment|///< power budget. This feature may only
comment|///< be interrogated by
comment|///< PAL_PROC_GET_FEATURES. it may not be
comment|///< enabled or disabled by
comment|///< PAL_PROC_SET_FEATURES. The
comment|///< corresponding argument is ignored.
name|UINT64
name|NoVM
range|:
literal|1
decl_stmt|;
comment|///< Bit40, No Virtual Machine features implemented.
comment|///< Denotes whether PSR.vm is implemented. This
comment|///< feature may only be interrogated by
comment|///< PAL_PROC_GET_FEATURES. It may not be enabled or
comment|///< disabled by PAL_PROC_SET_FEATURES. The
comment|///< corresponding argument is ignored.
name|UINT64
name|NoXipXpsrXfs
range|:
literal|1
decl_stmt|;
comment|///< Bit41, No XIP, XPSR, and XFS
comment|///< implemented. Denotes whether XIP, XPSR,
comment|///< and XFS are implemented for machine
comment|///< check recovery. This feature may only be
comment|///< interrogated by PAL_PROC_GET_FEATURES.
comment|///< It may not be enabled or disabled by
comment|///< PAL_PROC_SET_FEATURES. The corresponding
comment|///< argument is ignored.
name|UINT64
name|NoXr1ThroughXr3
range|:
literal|1
decl_stmt|;
comment|///< Bit42, No XR1 through XR3 implemented.
comment|///<   Denotes whether XR1 XR3 are
comment|///<   implemented for machine check
comment|///<   recovery. This feature may only be
comment|///<   interrogated by PAL_PROC_GET_FEATURES.
comment|///<   It may not be enabled or disabled by
comment|///<   PAL_PROC_SET_FEATURES. The
comment|///<   corresponding argument is ignored.
name|UINT64
name|DisableDynamicPrediction
range|:
literal|1
decl_stmt|;
comment|///< Bit43, Disable Dynamic
comment|///< Predicate Prediction. When
comment|///< 0, the processor may predict
comment|///< predicate results and
comment|///< execute speculatively, but
comment|///< may not commit results until
comment|///< the actual predicates are
comment|///< known. When 1, the processor
comment|///< shall not execute predicated
comment|///< instructions until the
comment|///< actual predicates are known.
name|UINT64
name|DisableSpontaneousDeferral
range|:
literal|1
decl_stmt|;
comment|///< Bit44, Disable Spontaneous
comment|///<   Deferral. When 1, the
comment|///<   processor may optionally
comment|///<   defer speculative loads
comment|///<   that do not encounter any
comment|///<   exception conditions, but
comment|///<   that trigger other
comment|///<   implementation-dependent
comment|///<   conditions (e.g., cache
comment|///<   miss). When 0, spontaneous
comment|///<   deferral is disabled.
name|UINT64
name|DisableDynamicDataCachePrefetch
range|:
literal|1
decl_stmt|;
comment|///< Bit45, Disable Dynamic
comment|///<   Data Cache Prefetch.
comment|///<   When 0, the processor
comment|///<   may prefetch into the
comment|///<   caches any data which
comment|///<   has not been accessed
comment|///<   by instruction
comment|///<   execution, but which
comment|///<   is likely to be
comment|///<   accessed. When 1, no
comment|///<   data may be fetched
comment|///<   until it is needed for
comment|///<   instruction execution
comment|///<   or is fetched by an
comment|///<   lfetch instruction.
name|UINT64
name|DisableDynamicInsCachePrefetch
range|:
literal|1
decl_stmt|;
comment|///< Bit46, Disable
comment|///< DynamicInstruction Cache
comment|///< Prefetch. When 0, the
comment|///< processor may prefetch
comment|///< into the caches any
comment|///< instruction which has
comment|///< not been executed, but
comment|///< whose execution is
comment|///< likely. When 1,
comment|///< instructions may not be
comment|///< fetched until needed or
comment|///< hinted for execution.
comment|///< (Prefetch for a hinted
comment|///< branch is allowed even
comment|///< when dynamic instruction
comment|///< cache prefetch is
comment|///< disabled.)
name|UINT64
name|DisableBranchPrediction
range|:
literal|1
decl_stmt|;
comment|///< Bit47, Disable Dynamic branch
comment|///<   prediction. When 0, the
comment|///<   processor may predict branch
comment|///<   targets and speculatively
comment|///<   execute, but may not commit
comment|///<   results. When 1, the processor
comment|///<   must wait until branch targets
comment|///<   are known to execute.
name|UINT64
name|Reserved2
range|:
literal|4
decl_stmt|;
name|UINT64
name|DisablePState
range|:
literal|1
decl_stmt|;
comment|///< Bit52, Disable P-states. When 1, the PAL
comment|///< P-state procedures (PAL_PSTATE_INFO,
comment|///< PAL_SET_PSTATE, PAL_GET_PSTATE) will
comment|///< return with a status of -1
comment|///< (Unimplemented procedure).
name|UINT64
name|EnableMcaOnDataPoisoning
range|:
literal|1
decl_stmt|;
comment|///< Bit53, Enable MCA signaling
comment|///< on data-poisoning event
comment|///< detection. When 0, a CMCI
comment|///< will be signaled on error
comment|///< detection. When 1, an MCA
comment|///< will be signaled on error
comment|///< detection. If this feature
comment|///< is not supported, then the
comment|///< corresponding argument is
comment|///< ignored when calling
comment|///< PAL_PROC_SET_FEATURES. Note
comment|///< that the functionality of
comment|///< this bit is independent of
comment|///< the setting in bit 60
comment|///< (Enable CMCI promotion), and
comment|///< that the bit 60 setting does
comment|///< not affect CMCI signaling
comment|///< for data-poisoning related
comment|///< events. Volume 2: Processor
comment|///< Abstraction Layer 2:431
comment|///< PAL_PROC_GET_FEATURES
name|UINT64
name|EnableVmsw
range|:
literal|1
decl_stmt|;
comment|///< Bit54, Enable the use of the vmsw
comment|///<   instruction. When 0, the vmsw instruction
comment|///<   causes a Virtualization fault when
comment|///<   executed at the most privileged level.
comment|///<   When 1, this bit will enable normal
comment|///<   operation of the vmsw instruction.
name|UINT64
name|EnableEnvNotification
range|:
literal|1
decl_stmt|;
comment|///< Bit55, Enable external
comment|///< notification when the processor
comment|///< detects hardware errors caused
comment|///< by environmental factors that
comment|///< could cause loss of
comment|///< deterministic behavior of the
comment|///< processor. When 1, this bit will
comment|///< enable external notification,
comment|///< when 0 external notification is
comment|///< not provided. The type of
comment|///< external notification of these
comment|///< errors is processor-dependent. A
comment|///< loss of processor deterministic
comment|///< behavior is considered to have
comment|///< occurred if these
comment|///< environmentally induced errors
comment|///< cause the processor to deviate
comment|///< from its normal execution and
comment|///< eventually causes different
comment|///< behavior which can be observed
comment|///<  at the processor bus pins.
comment|///< Processor errors that do not
comment|///< have this effects (i.e.,
comment|///< software induced machine checks)
comment|///< may or may not be promoted
comment|///< depending on the processor
comment|///< implementation.
name|UINT64
name|DisableBinitWithTimeout
range|:
literal|1
decl_stmt|;
comment|///< Bit56, Disable a BINIT on
comment|///<   internal processor time-out.
comment|///<   When 0, the processor may
comment|///<   generate a BINIT on an
comment|///<   internal processor time-out.
comment|///<   When 1, the processor will not
comment|///<   generate a BINIT on an
comment|///<   internal processor time-out.
comment|///<   The event is silently ignored.
name|UINT64
name|DisableDPM
range|:
literal|1
decl_stmt|;
comment|///< Bit57, Disable Dynamic Power Management
comment|///<   (DPM). When 0, the hardware may reduce
comment|///<   power consumption by removing the clock
comment|///<   input from idle functional units. When 1,
comment|///<   all functional units will receive clock
comment|///<   input, even when idle.
name|UINT64
name|DisableCoherency
range|:
literal|1
decl_stmt|;
comment|///< Bit58, Disable Coherency. When 0,
comment|///< the processor uses normal coherency
comment|///< requests and responses. When 1, the
comment|///< processor answers all requests as if
comment|///< the line were not present.
name|UINT64
name|DisableCache
range|:
literal|1
decl_stmt|;
comment|///< Bit59, Disable Cache. When 0, the
comment|///< processor performs cast outs on
comment|///< cacheable pages and issues and responds
comment|///< to coherency requests normally. When 1,
comment|///< the processor performs a memory access
comment|///< for each reference regardless of cache
comment|///< contents and issues no coherence
comment|///< requests and responds as if the line
comment|///< were not present. Cache contents cannot
comment|///< be relied upon when the cache is
comment|///< disabled. WARNING: Semaphore
comment|///< instructions may not be atomic or may
comment|///< cause Unsupported Data Reference faults
comment|///< if caches are disabled.
name|UINT64
name|EnableCmciPromotion
range|:
literal|1
decl_stmt|;
comment|///< Bit60, Enable CMCI promotion When
comment|///<   1, Corrected Machine Check
comment|///<   Interrupts (CMCI) are promoted to
comment|///<   MCAs. They are also further
comment|///<   promoted to BERR if bit 39, Enable
comment|///<   MCA promotion, is also set and
comment|///<   they are promoted to BINIT if bit
comment|///<   38, Enable MCA to BINIT promotion,
comment|///<   is also set. This bit has no
comment|///<   effect if MCA signalling is
comment|///<   disabled (see
comment|///<   PAL_BUS_GET/SET_FEATURES)
name|UINT64
name|EnableMcaToBinitPromotion
range|:
literal|1
decl_stmt|;
comment|///< Bit61, Enable MCA to BINIT
comment|///< promotion. When 1, machine
comment|///< check aborts (MCAs) are
comment|///< promoted to the Bus
comment|///< Initialization signal, and
comment|///< the BINIT pin is assert on
comment|///< each occurrence of an MCA.
comment|///< Setting this bit has no
comment|///< effect if BINIT signalling
comment|///< is disabled. (See
comment|///< PAL_BUS_GET/SET_FEATURES)
name|UINT64
name|EnableMcaPromotion
range|:
literal|1
decl_stmt|;
comment|///< Bit62, Enable MCA promotion. When
comment|///<   1, machine check aborts (MCAs) are
comment|///<   promoted to the Bus Error signal,
comment|///<   and the BERR pin is assert on each
comment|///<   occurrence of an MCA. Setting this
comment|///<   bit has no effect if BERR
comment|///<   signalling is disabled. (See
comment|///<   PAL_BUS_GET/SET_FEATURES)
name|UINT64
name|EnableBerrPromotion
range|:
literal|1
decl_stmt|;
comment|///< Bit63. Enable BERR promotion. When
comment|///<   1, the Bus Error (BERR) signal is
comment|///<   promoted to the Bus Initialization
comment|///<   (BINIT) signal, and the BINIT pin
comment|///<   is asserted on the occurrence of
comment|///<   each Bus Error. Setting this bit
comment|///<   has no effect if BINIT signalling
comment|///<   is disabled. (See
comment|///<   PAL_BUS_GET/SET_FEATURES)
block|}
name|PAL_PROCESSOR_FEATURES
typedef|;
end_typedef

begin_comment
comment|/**   PAL Procedure - PAL_PROC_GET_FEATURES.    Return configurable processor features and their current   setting. It is required by Itanium processors. The PAL procedure supports the   Static Registers calling convention. It could be called at   physical mode and virtual mode.    @param Index      Index of PAL_PROC_GET_FEATURES within the list of                     PAL procedures.   @param Reserved   Reserved parameter.   @param FeatureSet Feature set information is being requested                     for.    @retval 1         Call completed without error; The                     feature_set passed is not supported but a                     feature_set of a larger value is supported.   @retval 0         Call completed without error   @retval -2        Invalid argument   @retval -3        Call completed with error.   @retval -8        feature_set passed is beyond the maximum                     feature_set supported    @return R9        64-bit vector of features implemented. See                     PAL_PROCESSOR_FEATURES.   @return R10       64-bit vector of current feature settings. See                     PAL_PROCESSOR_FEATURES.   @return R11       64-bit vector of features controllable by                     software.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_PROC_GET_FEATURES
value|17
end_define

begin_comment
comment|/**   PAL Procedure - PAL_PROC_SET_FEATURES.    Enable or disable configurable processor features. It is   required by Itanium processors. The PAL procedure supports the Static   Registers calling convention. It could be called at physical   mode.    @param Index          Index of PAL_PROC_SET_FEATURES within the list of                         PAL procedures.   @param FeatureSelect  64-bit vector denoting desired state of                         each feature (1=select, 0=non-select).   @param FeatureSet     Feature set to apply changes to. See                         PAL_PROC_GET_FEATURES for more information                         on feature sets.    @retval 1             Call completed without error; The                         feature_set passed is not supported but a                         feature_set of a larger value is supported   @retval 0             Call completed without error   @retval -2            Invalid argument   @retval -3            Call completed with error.   @retval -8            feature_set passed is beyond the maximum                         feature_set supported  **/
end_comment

begin_define
define|#
directive|define
name|PAL_PROC_SET_FEATURES
value|18
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Value of PAL_REGISTER_INFO.InfoRequest.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|PAL_APPLICATION_REGISTER_IMPLEMENTED
value|0
end_define

begin_define
define|#
directive|define
name|PAL_APPLICATION_REGISTER_READABLE
value|1
end_define

begin_define
define|#
directive|define
name|PAL_CONTROL_REGISTER_IMPLEMENTED
value|2
end_define

begin_define
define|#
directive|define
name|PAL_CONTROL_REGISTER_READABLE
value|3
end_define

begin_comment
comment|/**   PAL Procedure - PAL_REGISTER_INFO.    Return AR and CR register information. It is required by Itanium processors.   The PAL procedure supports the Static Registers calling   convention. It could be called at physical mode and virtual   mode.    @param Index        Index of PAL_REGISTER_INFO within the list of                       PAL procedures.   @param InfoRequest  Unsigned 64-bit integer denoting what                       register information is requested. See                       PAL_REGISTER_INFO.InfoRequest above.    @retval 0           Call completed without error   @retval -2          Invalid argument   @retval -3          Call completed with error.    @return R9          64-bit vector denoting information for registers                       0-63. Bit 0 is register 0, bit 63 is register 63.   @return R10         64-bit vector denoting information for registers                       64-127. Bit 0 is register 64, bit 63 is register                       127.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_REGISTER_INFO
value|39
end_define

begin_comment
comment|/**   PAL Procedure - PAL_RSE_INFO.    Return RSE information. It is required by Itanium processors. The PAL   procedure supports the Static Registers calling convention. It   could be called at physical mode and virtual mode.    @param Index        Index of PAL_RSE_INFO within the list of                       PAL procedures.   @param InfoRequest  Unsigned 64-bit integer denoting what                       register information is requested. See                       PAL_REGISTER_INFO.InfoRequest above.    @retval 0           Call completed without error   @retval -2          Invalid argument   @retval -3          Call completed with error.    @return R9          Number of physical stacked general registers.   @return R10         RSE hints supported by processor.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_RSE_INFO
value|19
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|VersionOfPalB
range|:
literal|16
decl_stmt|;
comment|///< Is a 16-bit binary coded decimal (BCD)
comment|///< number that provides identification
comment|///< information about the PAL_B firmware.
name|UINT64
name|Reserved1
range|:
literal|8
decl_stmt|;
name|UINT64
name|PalVendor
range|:
literal|8
decl_stmt|;
comment|///< Is an unsigned 8-bit integer indicating the
comment|///< vendor of the PAL code.
name|UINT64
name|VersionOfPalA
range|:
literal|16
decl_stmt|;
comment|///< Is a 16-bit binary coded decimal (BCD)
comment|///< number that provides identification
comment|///< information about the PAL_A firmware. In
comment|///< the split PAL_A model, this return value
comment|///< is the version number of the
comment|///< processor-specific PAL_A. The generic
comment|///< PAL_A version is not returned by this
comment|///< procedure in the split PAL_A model.
name|UINT64
name|Reserved2
range|:
literal|16
decl_stmt|;
block|}
name|PAL_VERSION_INFO
typedef|;
end_typedef

begin_comment
comment|/**   PAL Procedure - PAL_VERSION.    Return version of PAL code. It is required by Itanium processors. The PAL   procedure supports the Static Registers calling convention. It   could be called at physical mode and virtual mode.    @param Index        Index of PAL_VERSION within the list of                       PAL procedures.   @param InfoRequest  Unsigned 64-bit integer denoting what                       register information is requested. See                       PAL_REGISTER_INFO.InfoRequest above.    @retval 0           Call completed without error   @retval -2          Invalid argument   @retval -3          Call completed with error.    @return R9          8-byte formatted value returning the minimum PAL                       version needed for proper operation of the                       processor. See PAL_VERSION_INFO above.   @return R10         8-byte formatted value returning the current PAL                       version running on the processor. See                       PAL_VERSION_INFO above.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_VERSION
value|20
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Vectors of PAL_MC_CLEAR_LOG.pending
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|PAL_MC_PENDING
value|BIT0
end_define

begin_define
define|#
directive|define
name|PAL_INIT_PENDING
value|BIT1
end_define

begin_comment
comment|/**   PAL Procedure - PAL_MC_CLEAR_LOG.    Clear all error information from processor error logging   registers. It is required by Itanium processors. The PAL procedure supports   the Static Registers calling convention. It could be called at   physical mode and virtual mode.    @param Index  Index of PAL_MC_CLEAR_LOG within the list of                 PAL procedures.    @retval 0     Call completed without error   @retval -2    Invalid argument   @retval -3    Call completed with error.    @return R9    64-bit vector denoting whether an event is                 pending. See PAL_MC_CLEAR_LOG.pending above.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_MC_CLEAR_LOG
value|21
end_define

begin_comment
comment|/**   PAL Procedure - PAL_MC_DRAIN.    Ensure that all operations that could cause an MCA have   completed. It is required by Itanium processors. The PAL procedure supports   the Static Registers calling convention. It could be called at   physical mode and virtual mode.    @param Index  Index of PAL_MC_DRAIN within the list of PAL                 procedures.    @retval 0     Call completed without error   @retval -2    Invalid argument   @retval -3    Call completed with error.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_MC_DRAIN
value|22
end_define

begin_comment
comment|/**   PAL Procedure - PAL_MC_DYNAMIC_STATE.    Return Processor Dynamic State for logging by SAL. It is   optional. The PAL procedure supports the Static Registers   calling convention. It could be called at physical mode.    @param Index  Index of PAL_MC_DYNAMIC_STATE within the list of PAL                 procedures.   @param Offset Offset of the next 8 bytes of Dynamic Processor                 State to return. (multiple of 8).    @retval 0     Call completed without error   @retval -1    Unimplemented procedure.   @retval -2    Invalid argument   @retval -3    Call completed with error.    @return R9    Unsigned 64-bit integer denoting bytes of Dynamic                 Processor State returned.   @return R10   Next 8 bytes of Dynamic Processor State.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_MC_DYNAMIC_STATE
value|24
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Values of PAL_MC_ERROR_INFO.InfoIndex.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|PAL_PROCESSOR_ERROR_MAP
value|0
end_define

begin_define
define|#
directive|define
name|PAL_PROCESSOR_STATE_PARAM
value|1
end_define

begin_define
define|#
directive|define
name|PAL_STRUCTURE_SPECIFIC_ERROR
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|CoreId
range|:
literal|4
decl_stmt|;
comment|///< Bit3:0,  Processor core ID (default is 0 for
comment|///< processors with a single core)
name|UINT64
name|ThreadId
range|:
literal|4
decl_stmt|;
comment|///< Bit7:4, Logical thread ID (default is 0 for
comment|///< processors that execute a single thread)
name|UINT64
name|InfoOfInsCache
range|:
literal|4
decl_stmt|;
comment|///< Bit11:8, Error information is
comment|///< available for 1st, 2nd, 3rd, and 4th
comment|///< level instruction caches.
name|UINT64
name|InfoOfDataCache
range|:
literal|4
decl_stmt|;
comment|///< Bit15:12, Error information is
comment|///<   available for 1st, 2nd, 3rd, and 4th
comment|///<   level data/unified caches.
name|UINT64
name|InfoOfInsTlb
range|:
literal|4
decl_stmt|;
comment|///< Bit19:16 Error information is available
comment|///< for 1st, 2nd, 3rd, and 4th level
comment|///< instruction TLB.
name|UINT64
name|InfoOfDataTlb
range|:
literal|4
decl_stmt|;
comment|///< Bit23:20, Error information is available
comment|///< for 1st, 2nd, 3rd, and 4th level
comment|///< data/unified TLB
name|UINT64
name|InfoOfProcessorBus
range|:
literal|4
decl_stmt|;
comment|///< Bit27:24 Error information is
comment|///<   available for the 1st, 2nd, 3rd,
comment|///<   and 4th level processor bus
comment|///<   hierarchy.
name|UINT64
name|InfoOfRegisterFile
range|:
literal|4
decl_stmt|;
comment|///< Bit31:28 Error information is
comment|///<   available on register file
comment|///<   structures.
name|UINT64
name|InfoOfMicroArch
range|:
literal|4
decl_stmt|;
comment|///< Bit47:32, Error information is
comment|///<   available on micro-architectural
comment|///<   structures.
name|UINT64
name|Reserved
range|:
literal|16
decl_stmt|;
block|}
name|PAL_MC_ERROR_INFO_LEVEL_INDEX
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Value of PAL_MC_ERROR_INFO.ErrorTypeIndex
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|PAL_ERR_INFO_BY_LEVEL_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|PAL_ERR_INFO_TARGET_ADDRESS
value|1
end_define

begin_define
define|#
directive|define
name|PAL_ERR_INFO_REQUESTER_IDENTIFIER
value|2
end_define

begin_define
define|#
directive|define
name|PAL_ERR_INFO_REPONSER_INDENTIFIER
value|3
end_define

begin_define
define|#
directive|define
name|PAL_ERR_INFO_PRECISE_INSTRUCTION_POINTER
value|4
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|Operation
range|:
literal|4
decl_stmt|;
comment|///< Bit3:0, Type of cache operation that caused
comment|///< the machine check: 0 - unknown or internal
comment|///< error 1 - load 2 - store 3 - instruction
comment|///< fetch or instruction prefetch 4 - data
comment|///< prefetch (both hardware and software) 5 -
comment|///< snoop (coherency check) 6 - cast out
comment|///< (explicit or implicit write-back of a cache
comment|///< line) 7 - move in (cache line fill)
name|UINT64
name|FailedCacheLevel
range|:
literal|2
decl_stmt|;
comment|///< Bit5:4 Level of cache where the
comment|///< error occurred. A value of 0
comment|///< indicates the first level of cache.
name|UINT64
name|Reserved1
range|:
literal|2
decl_stmt|;
name|UINT64
name|FailedInDataPart
range|:
literal|1
decl_stmt|;
comment|///< Bit8, Failure located in the data part of the cache line.
name|UINT64
name|FailedInTagPart
range|:
literal|1
decl_stmt|;
comment|///< Bit9, Failure located in the tag part of the cache line.
name|UINT64
name|FailedInDataCache
range|:
literal|1
decl_stmt|;
comment|///< Bit10, Failure located in the data cache
name|UINT64
name|FailedInInsCache
range|:
literal|1
decl_stmt|;
comment|///< Bit11, Failure located in the
comment|///< instruction cache.
name|UINT64
name|Mesi
range|:
literal|3
decl_stmt|;
comment|///< Bit14:12,  0 - cache line is invalid. 1 - cache
comment|///< line is held shared. 2 - cache line is held
comment|///< exclusive. 3 - cache line is modified. All other
comment|///< values are reserved.
name|UINT64
name|MesiIsValid
range|:
literal|1
decl_stmt|;
comment|///< Bit15, The mesi field in the cache_check
comment|///< parameter is valid.
name|UINT64
name|FailedWay
range|:
literal|5
decl_stmt|;
comment|///< Bit20:16, Failure located in the way of
comment|///< the cache indicated by this value.
name|UINT64
name|WayIndexIsValid
range|:
literal|1
decl_stmt|;
comment|///< Bit21, The way and index field in the
comment|///< cache_check parameter is valid.
name|UINT64
name|Reserved2
range|:
literal|1
decl_stmt|;
name|UINT64
name|MultipleBitsError
range|:
literal|1
decl_stmt|;
comment|///< Bit23, A multiple-bit error was
comment|///< detected, and data was poisoned for
comment|///< the corresponding cache line during
comment|///< castout.
name|UINT64
name|Reserved3
range|:
literal|8
decl_stmt|;
name|UINT64
name|IndexOfCacheLineError
range|:
literal|20
decl_stmt|;
comment|///< Bit51:32, Index of the cache
comment|///< line where the error occurred.
name|UINT64
name|Reserved4
range|:
literal|2
decl_stmt|;
name|UINT64
name|InstructionSet
range|:
literal|1
decl_stmt|;
comment|///< Bit54, Instruction set. If this value
comment|///<   is set to zero, the instruction that
comment|///<   generated the machine check was an
comment|///<   Intel Itanium instruction. If this bit
comment|///<   is set to one, the instruction that
comment|///<   generated the machine check was IA-32
comment|///<   instruction.
name|UINT64
name|InstructionSetIsValid
range|:
literal|1
decl_stmt|;
comment|///< Bit55, The is field in the
comment|///< cache_check parameter is valid.
name|UINT64
name|PrivilegeLevel
range|:
literal|2
decl_stmt|;
comment|///< Bit57:56, Privilege level. The
comment|///<   privilege level of the instruction
comment|///<   bundle responsible for generating the
comment|///<   machine check.
name|UINT64
name|PrivilegeLevelIsValide
range|:
literal|1
decl_stmt|;
comment|///< Bit58, The pl field of the
comment|///<   cache_check parameter is
comment|///<   valid.
name|UINT64
name|McCorrected
range|:
literal|1
decl_stmt|;
comment|///< Bit59, Machine check corrected: This bit
comment|///<   is set to one to indicate that the machine
comment|///<   check has been corrected.
name|UINT64
name|TargetAddressIsValid
range|:
literal|1
decl_stmt|;
comment|///< Bit60, Target address is valid:
comment|///< This bit is set to one to
comment|///< indicate that a valid target
comment|///< address has been logged.
name|UINT64
name|RequesterIdentifier
range|:
literal|1
decl_stmt|;
comment|///< Bit61, Requester identifier: This
comment|///<   bit is set to one to indicate that
comment|///<   a valid requester identifier has
comment|///<   been logged.
name|UINT64
name|ResponserIdentifier
range|:
literal|1
decl_stmt|;
comment|///< Bit62, Responder identifier: This
comment|///<   bit is set to one to indicate that
comment|///<   a valid responder identifier has
comment|///<   been logged.
name|UINT64
name|PreciseInsPointer
range|:
literal|1
decl_stmt|;
comment|///< Bit63,  Precise instruction pointer.
comment|///< This bit is set to one to indicate
comment|///< that a valid precise instruction
comment|///< pointer has been logged.
block|}
name|PAL_CACHE_CHECK_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|FailedSlot
range|:
literal|8
decl_stmt|;
comment|///< Bit7:0, Slot number of the translation
comment|///< register where the failure occurred.
name|UINT64
name|FailedSlotIsValid
range|:
literal|1
decl_stmt|;
comment|///< Bit8, The tr_slot field in the
comment|///< TLB_check parameter is valid.
name|UINT64
name|Reserved1
range|:
literal|1
decl_stmt|;
name|UINT64
name|TlbLevel
range|:
literal|2
decl_stmt|;
comment|///< Bit11:10,  The level of the TLB where the
comment|///< error occurred. A value of 0 indicates the
comment|///< first level of TLB
name|UINT64
name|Reserved2
range|:
literal|4
decl_stmt|;
name|UINT64
name|FailedInDataTr
range|:
literal|1
decl_stmt|;
comment|///< Bit16, Error occurred in the data
comment|///< translation registers.
name|UINT64
name|FailedInInsTr
range|:
literal|1
decl_stmt|;
comment|///< Bit17, Error occurred in the instruction
comment|///< translation registers
name|UINT64
name|FailedInDataTc
range|:
literal|1
decl_stmt|;
comment|///< Bit18, Error occurred in data
comment|///< translation cache.
name|UINT64
name|FailedInInsTc
range|:
literal|1
decl_stmt|;
comment|///< Bit19, Error occurred in the instruction
comment|///< translation cache.
name|UINT64
name|FailedOperation
range|:
literal|4
decl_stmt|;
comment|///< Bit23:20, Type of cache operation that
comment|///<   caused the machine check: 0 - unknown
comment|///<   1 - TLB access due to load instruction
comment|///<   2 - TLB access due to store
comment|///<   instruction 3 - TLB access due to
comment|///<   instruction fetch or instruction
comment|///<   prefetch 4 - TLB access due to data
comment|///<   prefetch (both hardware and software)
comment|///<   5 - TLB shoot down access 6 - TLB
comment|///<   probe instruction (probe, tpa) 7 -
comment|///<   move in (VHPT fill) 8 - purge (insert
comment|///<   operation that purges entries or a TLB
comment|///<   purge instruction) All other values
comment|///<   are reserved.
name|UINT64
name|Reserved3
range|:
literal|30
decl_stmt|;
name|UINT64
name|InstructionSet
range|:
literal|1
decl_stmt|;
comment|///< Bit54, Instruction set. If this value
comment|///<   is set to zero, the instruction that
comment|///<   generated the machine check was an
comment|///<   Intel Itanium instruction. If this bit
comment|///<   is set to one, the instruction that
comment|///<   generated the machine check was IA-32
comment|///<   instruction.
name|UINT64
name|InstructionSetIsValid
range|:
literal|1
decl_stmt|;
comment|///< Bit55, The is field in the
comment|///< TLB_check parameter is valid.
name|UINT64
name|PrivelegeLevel
range|:
literal|2
decl_stmt|;
comment|///< Bit57:56, Privilege level. The
comment|///<   privilege level of the instruction
comment|///<   bundle responsible for generating the
comment|///<   machine check.
name|UINT64
name|PrivelegeLevelIsValid
range|:
literal|1
decl_stmt|;
comment|///< Bit58,  The pl field of the
comment|///< TLB_check parameter is valid.
name|UINT64
name|McCorrected
range|:
literal|1
decl_stmt|;
comment|///< Bit59, Machine check corrected: This bit
comment|///<   is set to one to indicate that the machine
comment|///<   check has been corrected.
name|UINT64
name|TargetAddressIsValid
range|:
literal|1
decl_stmt|;
comment|///< Bit60, Target address is valid:
comment|///< This bit is set to one to
comment|///< indicate that a valid target
comment|///< address has been logged.
name|UINT64
name|RequesterIdentifier
range|:
literal|1
decl_stmt|;
comment|///< Bit61 Requester identifier: This
comment|///<   bit is set to one to indicate that
comment|///<   a valid requester identifier has
comment|///<   been logged.
name|UINT64
name|ResponserIdentifier
range|:
literal|1
decl_stmt|;
comment|///< Bit62, Responder identifier:  This
comment|///<   bit is set to one to indicate that
comment|///<   a valid responder identifier has
comment|///<   been logged.
name|UINT64
name|PreciseInsPointer
range|:
literal|1
decl_stmt|;
comment|///< Bit63 Precise instruction pointer.
comment|///<   This bit is set to one to indicate
comment|///<   that a valid precise instruction
comment|///<   pointer has been logged.
block|}
name|PAL_TLB_CHECK_INFO
typedef|;
end_typedef

begin_comment
comment|/**   PAL Procedure - PAL_MC_ERROR_INFO.    Return Processor Machine Check Information and Processor   Static State for logging by SAL. It is required by Itanium processors. The   PAL procedure supports the Static Registers calling   convention. It could be called at physical and virtual mode.    @param Index            Index of PAL_MC_ERROR_INFO within the list of PAL                           procedures.   @param InfoIndex        Unsigned 64-bit integer identifying the                           error information that is being requested.                           See PAL_MC_ERROR_INFO.InfoIndex.   @param LevelIndex       8-byte formatted value identifying the                           structure to return error information                           on. See PAL_MC_ERROR_INFO_LEVEL_INDEX.   @param ErrorTypeIndex   Unsigned 64-bit integer denoting the                           type of error information that is                           being requested for the structure                           identified in LevelIndex.    @retval 0               Call completed without error   @retval -2              Invalid argument   @retval -3              Call completed with error.   @retval -6              Argument was valid, but no error                           information was available    @return R9              Error information returned. The format of this                           value is dependant on the input values passed.   @return R10             If this value is zero, all the error information                           specified by err_type_index has been returned. If                           this value is one, more structure-specific error                           information is available and the caller needs to                           make this procedure call again with level_index                           unchanged and err_type_index, incremented.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_MC_ERROR_INFO
value|25
end_define

begin_comment
comment|/**   PAL Procedure - PAL_MC_EXPECTED.    Set/Reset Expected Machine Check Indicator. It is required by   Itanium processors. The PAL procedure supports the Static Registers calling   convention. It could be called at physical mode.    @param Index      Index of PAL_MC_EXPECTED within the list of PAL                     procedures.   @param Expected   Unsigned integer with a value of 0 or 1 to                     set or reset the hardware resource                     PALE_CHECK examines for expected machine                     checks.    @retval 0         Call completed without error   @retval -2        Invalid argument   @retval -3        Call completed with error.    @return R9        Unsigned integer denoting whether a machine check                     was previously expected.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_MC_EXPECTED
value|23
end_define

begin_comment
comment|/**   PAL Procedure - PAL_MC_REGISTER_MEM.    Register min-state save area with PAL for machine checks and   inits. It is required by Itanium processors. The PAL procedure supports the   Static Registers calling convention. It could be called at   physical mode.    @param Index    Index of PAL_MC_REGISTER_MEM within the list of PAL                   procedures.   @param Address  Physical address of the buffer to be                   registered with PAL.    @retval 0       Call completed without error   @retval -2      Invalid argument   @retval -3      Call completed with error.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_MC_REGISTER_MEM
value|27
end_define

begin_comment
comment|/**   PAL Procedure - PAL_MC_RESUME.    Restore minimal architected state and return to interrupted   process. It is required by Itanium processors. The PAL procedure supports the   Static Registers calling convention. It could be called at   physical mode.    @param Index        Index of PAL_MC_RESUME within the list of PAL                       procedures.   @param SetCmci      Unsigned 64 bit integer denoting whether to                       set the CMC interrupt. A value of 0 indicates                       not to set the interrupt, a value of 1                       indicated to set the interrupt, and all other                       values are reserved.   @param SavePtr      Physical address of min-state save area used                       to used to restore processor state.   @param NewContext   Unsigned 64-bit integer denoting whether                       the caller is returning to a new context.                       A value of 0 indicates the caller is                       returning to the interrupted context, a                       value of 1 indicates that the caller is                       returning to a new context.    @retval -2          Invalid argument   @retval -3          Call completed with error.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_MC_RESUME
value|26
end_define

begin_comment
comment|/**   PAL Procedure - PAL_HALT.    Enter the low-power HALT state or an implementation-dependent   low-power state. It is optinal. The PAL procedure supports the   Static Registers calling convention. It could be called at   physical mode.    @param Index        Index of PAL_HALT within the list of PAL                       procedures.   @param HaltState    Unsigned 64-bit integer denoting low power                       state requested.   @param IoDetailPtr  8-byte aligned physical address pointer to                       information on the type of I/O                       (load/store) requested.    @retval 0           Call completed without error   @retval -1          Unimplemented procedure   @retval -2          Invalid argument   @retval -3          Call completed with error.    @return R9          Value returned if a load instruction is requested                       in the io_detail_ptr  **/
end_comment

begin_define
define|#
directive|define
name|PAL_HALT
value|28
end_define

begin_comment
comment|/**   PAL Procedure - PAL_HALT_INFO.    Return the low power capabilities of the processor. It is   required by Itanium processors. The PAL procedure supports the   Stacked Registers calling convention. It could be called at   physical and virtual mode.    @param Index        Index of PAL_HALT_INFO within the list of PAL                       procedures.   @param PowerBuffer  64-bit pointer to a 64-byte buffer aligned                       on an 8-byte boundary.    @retval 0           Call completed without error   @retval -2          Invalid argument   @retval -3          Call completed with error.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_HALT_INFO
value|257
end_define

begin_comment
comment|/**   PAL Procedure - PAL_HALT_LIGHT.    Enter the low power LIGHT HALT state. It is required by   Itanium processors. The PAL procedure supports the Static Registers calling   convention. It could be called at physical and virtual mode.    @param Index  Index of PAL_HALT_LIGHT within the list of PAL                 procedures.    @retval 0     Call completed without error   @retval -2    Invalid argument   @retval -3    Call completed with error.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_HALT_LIGHT
value|29
end_define

begin_comment
comment|/**   PAL Procedure - PAL_CACHE_LINE_INIT.    Initialize tags and data of a cache line for processor   testing. It is required by Itanium processors. The PAL procedure supports the   Static Registers calling convention. It could be called at   physical and virtual mode.    @param Index      Index of PAL_CACHE_LINE_INIT within the list of PAL                     procedures.   @param Address    Unsigned 64-bit integer value denoting the                     physical address from which the physical page                     number is to be generated. The address must be                     an implemented physical address, bit 63 must                     be zero.   @param DataValue  64-bit data value which is used to                     initialize the cache line.    @retval 0         Call completed without error   @retval -2        Invalid argument   @retval -3        Call completed with error.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_CACHE_LINE_INIT
value|31
end_define

begin_comment
comment|/**   PAL Procedure - PAL_CACHE_READ.    Read tag and data of a cache line for diagnostic testing. It   is optional. The PAL procedure supports the   Satcked Registers calling convention. It could be called at   physical mode.    @param Index    Index of PAL_CACHE_READ within the list of PAL                   procedures.   @param LineId   8-byte formatted value describing where in the                   cache to read the data.   @param Address  64-bit 8-byte aligned physical address from                   which to read the data. The address must be an                   implemented physical address on the processor                   model with bit 63 set to zero.    @retval 1       The word at address was found in the                   cache, but the line was invalid.   @retval 0       Call completed without error   @retval -2      Invalid argument   @retval -3      Call completed with error.   @retval -5      The word at address was not found in the                   cache.   @retval -7      The operation requested is not supported                   for this cache_type and level.    @return R9      Right-justified value returned from the cache                   line.   @return R10     The number of bits returned in data.   @return R11     The status of the cache line.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_CACHE_READ
value|259
end_define

begin_comment
comment|/**   PAL Procedure - PAL_CACHE_WRITE.    Write tag and data of a cache for diagnostic testing. It is   optional. The PAL procedure supports the Satcked Registers   calling convention. It could be called at physical mode.    @param Index    Index of PAL_CACHE_WRITE within the list of PAL                   procedures.   @param LineId   8-byte formatted value describing where in the                   cache to write the data.   @param Address  64-bit 8-byte aligned physical address at                   which the data should be written. The address                   must be an implemented physical address on the                   processor model with bit 63 set to 0.   @param Data     Unsigned 64-bit integer value to write into                   the specified part of the cache.    @retval 0       Call completed without error   @retval -2      Invalid argument   @retval -3      Call completed with error.   @retval -7      The operation requested is not supported                   for this cache_type and level.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_CACHE_WRITE
value|260
end_define

begin_comment
comment|/**   PAL Procedure - PAL_TEST_INFO.    Returns alignment and size requirements needed for the memory   buffer passed to the PAL_TEST_PROC procedure as well as   information on self-test control words for the processor self   tests. It is required by Itanium processors. The PAL procedure supports the   Static Registers calling convention. It could be called at   physical mode.    @param Index      Index of PAL_TEST_INFO within the list of PAL                     procedures.   @param TestPhase  Unsigned integer that specifies which phase                     of the processor self-test information is                     being requested on. A value of 0 indicates                     the phase two of the processor self-test and                     a value of 1 indicates phase one of the                     processor self-test. All other values are                     reserved.    @retval 0         Call completed without error   @retval -2        Invalid argument   @retval -3        Call completed with error.    @return R9        Unsigned 64-bit integer denoting the number of                     bytes of main memory needed to perform the second                     phase of processor self-test.   @return R10       Unsigned 64-bit integer denoting the alignment                     required for the memory buffer.   @return R11       48-bit wide bit-field indicating if control of                     the processor self-tests is supported and which                     bits of the test_control field are defined for                     use.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_TEST_INFO
value|37
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|BufferSize
range|:
literal|56
decl_stmt|;
comment|///< Indicates the size in bytes of the memory
comment|///< buffer that is passed to this procedure.
comment|///< BufferSize must be greater than or equal in
comment|///< size to the bytes_needed return value from
comment|///< PAL_TEST_INFO, otherwise this procedure will
comment|///< return with an invalid argument return
comment|///< value.
name|UINT64
name|TestPhase
range|:
literal|8
decl_stmt|;
comment|///< Defines which phase of the processor
comment|///< self-tests are requested to be run. A value
comment|///< of zero indicates to run phase two of the
comment|///< processor self-tests. Phase two of the
comment|///< processor self-tests are ones that require
comment|///< external memory to execute correctly. A
comment|///< value of one indicates to run phase one of
comment|///< the processor self-tests. Phase one of the
comment|///< processor self-tests are tests run during
comment|///< PALE_RESET and do not depend on external
comment|///< memory to run correctly. When the caller
comment|///< requests to have phase one of the processor
comment|///< self-test run via this procedure call, a
comment|///< memory buffer may be needed to save and
comment|///< restore state as required by the PAL calling
comment|///< conventions. The procedure PAL_TEST_INFO
comment|///< informs the caller about the requirements of
comment|///< the memory buffer.
block|}
name|PAL_TEST_INFO_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|TestControl
range|:
literal|47
decl_stmt|;
comment|///< This is an ordered implementation-specific
comment|///<   control word that allows the user control
comment|///<   over the length and runtime of the
comment|///<   processor self-tests. This control word is
comment|///<   ordered from the longest running tests up
comment|///<   to the shortest running tests with bit 0
comment|///<   controlling the longest running test. PAL
comment|///<   may not implement all 47-bits of the
comment|///<   test_control word. PAL communicates if a
comment|///<   bit provides control by placing a zero in
comment|///<   that bit. If a bit provides no control,
comment|///<   PAL will place a one in it. PAL will have
comment|///<   two sets of test_control bits for the two
comment|///<   phases of the processor self-test. PAL
comment|///<   provides information about implemented
comment|///<   test_control bits at the hand-off from PAL
comment|///<   to SAL for the firmware recovery check.
comment|///<   These test_control bits provide control
comment|///<   for phase one of processor self-test. It
comment|///<   also provides this information via the PAL
comment|///<   procedure call PAL_TEST_INFO for both the
comment|///<   phase one and phase two processor tests
comment|///<   depending on which information the caller
comment|///<   is requesting. PAL interprets these bits
comment|///<   as input parameters on two occasions. The
comment|///<   first time is when SAL passes control back
comment|///<   to PAL after the firmware recovery check.
comment|///<   The second time is when a call to
comment|///<   PAL_TEST_PROC is made. When PAL interprets
comment|///<   these bits it will only interpret
comment|///<   implemented test_control bits and will
comment|///<   ignore the values located in the
comment|///<   unimplemented test_control bits. PAL
comment|///<   interprets the implemented bits such that
comment|///<   if a bit contains a zero, this indicates
comment|///<   to run the test. If a bit contains a one,
comment|///<   this indicates to PAL to skip the test. If
comment|///<   the cs bit indicates that control is not
comment|///<    available, the test_control bits will be
comment|///<   ignored or generate an illegal argument in
comment|///<   procedure calls if the caller sets these
comment|///<   bits.
name|UINT64
name|ControlSupport
range|:
literal|1
decl_stmt|;
comment|///< This bit defines if an implementation
comment|///<  supports control of the PAL self-tests
comment|///<  via the self-test control word. If
comment|///<  this bit is 0, the implementation does
comment|///<  not support control of the processor
comment|///<  self-tests via the self-test control
comment|///<  word. If this bit is 1, the
comment|///<  implementation does support control of
comment|///<  the processor self-tests via the
comment|///<  self-test control word. If control is
comment|///<  not supported, GR37 will be ignored at
comment|///<  the hand-off between SAL and PAL after
comment|///<  the firmware recovery check and the
comment|///<  PAL procedures related to the
comment|///<  processor self-tests may return
comment|///<  illegal arguments if a user tries to
comment|///<  use the self-test control features.
name|UINT64
name|Reserved
range|:
literal|16
decl_stmt|;
block|}
name|PAL_SELF_TEST_CONTROL
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|Attributes
range|:
literal|8
decl_stmt|;
comment|///< Specifies the memory attributes that are
comment|///<  allowed to be used with the memory buffer
comment|///<  passed to this procedure. The attributes
comment|///<  parameter is a vector where each bit
comment|///<  represents one of the virtual memory
comment|///<  attributes defined by the architecture.See
comment|///<  MEMORY_AATRIBUTES. The caller is required
comment|///<  to support the cacheable attribute for the
comment|///<  memory buffer, otherwise an invalid
comment|///<  argument will be returned.
name|UINT64
name|Reserved
range|:
literal|8
decl_stmt|;
name|UINT64
name|TestControl
range|:
literal|48
decl_stmt|;
comment|///< Is the self-test control word
comment|///<  corresponding to the test_phase passed.
comment|///<  This test_control directs the coverage and
comment|///<  runtime of the processor self-tests
comment|///<  specified by the test_phase input
comment|///<  argument. Information on if this
comment|///<  feature is implemented and the number of
comment|///<  bits supported can be obtained by the
comment|///<  PAL_TEST_INFO procedure call. If this
comment|///<  feature is implemented by the processor,
comment|///<  the caller can selectively skip parts of
comment|///<  the processor self-test by setting
comment|///<  test_control bits to a one. If a bit has a
comment|///<  zero, this test will be run. The values in
comment|///<  the unimplemented bits are ignored. If
comment|///<  PAL_TEST_INFO indicated that the self-test
comment|///<  control word is not implemented, this
comment|///<  procedure will return with an invalid
comment|///<  argument status if the caller sets any of
comment|///<  the test_control bits. See
comment|///<  PAL_SELF_TEST_CONTROL.
block|}
name|PAL_TEST_CONTROL
typedef|;
end_typedef

begin_comment
comment|/**   PAL Procedure - PAL_TEST_PROC.    Perform late processor self test. It is required by Itanium processors. The   PAL procedure supports the Static Registers calling   convention. It could be called at physical mode.    @param Index        Index of PAL_TEST_PROC within the list of PAL                       procedures.   @param TestAddress  64-bit physical address of main memory                       area to be used by processor self-test.                       The memory region passed must be                       cacheable, bit 63 must be zero.   @param TestInfo     Input argument specifying the size of the                       memory buffer passed and the phase of the                       processor self-test that should be run. See                       PAL_TEST_INFO.   @param TestParam    Input argument specifying the self-test                       control word and the allowable memory                       attributes that can be used with the memory                       buffer. See PAL_TEST_CONTROL.    @retval 1           Call completed without error, but hardware                       failures occurred during self-test.   @retval 0           Call completed without error   @retval -2          Invalid argument   @retval -3          Call completed with error.    @return R9          Formatted 8-byte value denoting the state of the                       processor after self-test  **/
end_comment

begin_define
define|#
directive|define
name|PAL_TEST_PROC
value|258
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|NumberOfInterruptControllers
decl_stmt|;
comment|///< Number of interrupt
comment|///< controllers currently
comment|///< enabled on the system.
name|UINT32
name|NumberOfProcessors
decl_stmt|;
comment|///< Number of processors currently
comment|///< enabled on the system.
block|}
name|PAL_PLATFORM_INFO
typedef|;
end_typedef

begin_comment
comment|/**   PAL Procedure - PAL_COPY_INFO.    Return information needed to relocate PAL procedures and PAL   PMI code to memory. It is required by Itanium processors. The PAL procedure   supports the Static Registers calling convention. It could be   called at physical mode.    @param Index              Index of PAL_COPY_INFO within the list of PAL                             procedures.   @param CopyType           Unsigned integer denoting type of procedures                             for which copy information is requested.   @param PlatformInfo       8-byte formatted value describing the                             number of processors and the number of                             interrupt controllers currently enabled                             on the system. See PAL_PLATFORM_INFO.   @param McaProcStateInfo   Unsigned integer denoting the number                             of bytes that SAL needs for the                             min-state save area for each                             processor.    @retval 0                 Call completed without error   @retval -2                Invalid argument   @retval -3                Call completed with error.    @return R9                Unsigned integer denoting the number of bytes of                             PAL information that must be copied to main                             memory.   @return R10               Unsigned integer denoting the starting alignment                             of the data to be copied.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_COPY_INFO
value|30
end_define

begin_comment
comment|/**   PAL Procedure - PAL_COPY_PAL.    Relocate PAL procedures and PAL PMI code to memory. It is   required by Itanium processors. The PAL procedure supports the Stacked   Registers calling convention. It could be called at physical   mode.    @param Index          Index of PAL_COPY_PAL within the list of PAL                         procedures.   @param TargetAddress  Physical address of a memory buffer to                         copy relocatable PAL procedures and PAL                         PMI code.   @param AllocSize      Unsigned integer denoting the size of the                         buffer passed by SAL for the copy operation.   @param CopyOption     Unsigned integer indicating whether                         relocatable PAL code and PAL PMI code                         should be copied from firmware address                         space to main memory.    @retval 0             Call completed without error   @retval -2            Invalid argument   @retval -3            Call completed with error.    @return R9            Unsigned integer denoting the offset of PAL_PROC                         in the relocatable segment copied.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_COPY_PAL
value|256
end_define

begin_comment
comment|/**   PAL Procedure - PAL_ENTER_IA_32_ENV.    Enter IA-32 System environment. It is optional. The PAL   procedure supports the Static Registers calling convention.   It could be called at physical mode.    Note: Since this is a special call, it does not follow the PAL   static register calling convention. GR28 contains the index of   PAL_ENTER_IA_32_ENV within the list of PAL procedures. All other   input arguments including GR29-GR31 are setup by SAL to values   as required by the IA-32 operating system defined in Table   11-67. The registers that are designated as preserved, scratch,   input arguments and procedure return values by the static   procedure calling convention are not followed by this call. For   instance, GR5 and GR6 need not be preserved since these are   regarded as scratch by the IA-32 operating system. Note: In an   MP system, this call must be COMPLETED on the first CPU to enter   the IA-32 System Environment (may or may not be the BSP) prior   to being called on the remaining processors in the MP system.    @param Index  GR28 contains the index of the                 PAL_ENTER_IA_32_ENV call within the list of PAL                 procedures.     @retval  The status is returned in GR4.                   -1 - Un-implemented procedure 0 JMPE detected                   at privilege level                    0 - 1 SAL allocated buffer for IA-32 System                   Environment operation is too small                    2 - IA-32 Firmware Checksum Error                    3 -  SAL allocated buffer for IA-32 System                   Environment operation is not properly aligned                    4 - Error in SAL MP Info Table                    5 - Error in SAL Memory Descriptor Table                    6 - Error in SAL System Table                    7 - Inconsistent IA-32 state                    8 - IA-32 Firmware Internal Error                    9 - IA-32 Soft Reset (Note: remaining register                   state is undefined for this termination                   reason)                    10 - Machine Check Error                    11 - Error in SAL I/O Intercept Table                    12 - Processor exit due to other processor in                   MP system terminating the IA32 system                   environment. (Note: remaining register state                   is undefined for this termination reason.)                    13 - Itanium architecture-based state                   corruption by either SAL PMI handler or I/O                   Intercept callback function.   **/
end_comment

begin_define
define|#
directive|define
name|PAL_ENTER_IA_32_ENV
value|33
end_define

begin_comment
comment|/**   PAL Procedure - PAL_PMI_ENTRYPOINT.    Register PMI memory entrypoints with processor. It is required   by Itanium processors. The PAL procedure supports the Stacked Registers   calling convention. It could be called at physical mode.    @param Index        Index of PAL_PMI_ENTRYPOINT within the list of                       PAL procedures.   @param SalPmiEntry  256-byte aligned physical address of SAL                       PMI entrypoint in memory.    @retval 0           Call completed without error   @retval -2          Invalid argument   @retval -3          Call completed with error.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_PMI_ENTRYPOINT
value|32
end_define

begin_comment
comment|/**    The ASCII brand identification string will be copied to the   address specified in the address input argument. The processor   brand identification string is defined to be a maximum of 128   characters long; 127 bytes will contain characters and the 128th   byte is defined to be NULL (0). A processor may return less than   the 127 ASCII characters as long as the string is null   terminated. The string length will be placed in the brand_info   return argument.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_BRAND_INFO_ID_REQUEST
value|0
end_define

begin_comment
comment|/**   PAL Procedure - PAL_BRAND_INFO.    Provides processor branding information. It is optional by   Itanium processors. The PAL procedure supports the Stacked Registers calling   convention. It could be called at physical and Virtual mode.    @param Index        Index of PAL_BRAND_INFO within the list of PAL                       procedures.   @param InfoRequest  Unsigned 64-bit integer specifying the                       information that is being requested. (See                       PAL_BRAND_INFO_ID_REQUEST)   @param Address      Unsigned 64-bit integer specifying the                       address of the 128-byte block to which the                       processor brand string shall be written.    @retval 0           Call completed without error   @retval -1          Unimplemented procedure   @retval -2          Invalid argument   @retval -3          Call completed with error.   @retval -6          Input argument is not implemented.    @return R9          Brand information returned. The format of this                       value is dependent on the input values passed.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_BRAND_INFO
value|274
end_define

begin_comment
comment|/**   PAL Procedure - PAL_GET_HW_POLICY.    Returns the current hardware resource sharing policy of the   processor. It is optional by Itanium processors. The PAL procedure supports   the Static Registers calling convention. It could be called at   physical and Virtual mode.     @param Index            Index of PAL_GET_HW_POLICY within the list of PAL                           procedures.   @param ProcessorNumber  Unsigned 64-bit integer that specifies                           for which logical processor                           information is being requested. This                           input argument must be zero for the                           first call to this procedure and can                           be a maximum value of one less than                           the number of logical processors                           impacted by the hardware resource                           sharing policy, which is returned by                           the R10 return value.    @retval 0               Call completed without error   @retval -1              Unimplemented procedure   @retval -2              Invalid argument   @retval -3              Call completed with error.   @retval -9              Call requires PAL memory buffer.    @return R9              Unsigned 64-bit integer representing the current                           hardware resource sharing policy.   @return R10             Unsigned 64-bit integer that returns the number                           of logical processors impacted by the policy                           input argument.   @return R11             Unsigned 64-bit integer containing the logical                           address of one of the logical processors                           impacted by policy modification.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_GET_HW_POLICY
value|48
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Value of PAL_SET_HW_POLICY.Policy
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|PAL_SET_HW_POLICY_PERFORMANCE
value|0
end_define

begin_define
define|#
directive|define
name|PAL_SET_HW_POLICY_FAIRNESS
value|1
end_define

begin_define
define|#
directive|define
name|PAL_SET_HW_POLICY_HIGH_PRIORITY
value|2
end_define

begin_define
define|#
directive|define
name|PAL_SET_HW_POLICY_EXCLUSIVE_HIGH_PRIORITY
value|3
end_define

begin_comment
comment|/**   PAL Procedure - PAL_SET_HW_POLICY.    Sets the current hardware resource sharing policy of the   processor. It is optional by Itanium processors. The PAL procedure supports   the Static Registers calling convention. It could be called at   physical and Virtual mode.    @param Index    Index of PAL_SET_HW_POLICY within the list of PAL                   procedures.   @param Policy   Unsigned 64-bit integer specifying the hardware                   resource sharing policy the caller is setting.                   See Value of PAL_SET_HW_POLICY.Policy above.    @retval 1       Call completed successfully but could not                   change the hardware policy since a                   competing logical processor is set in                   exclusive high priority.   @retval 0       Call completed without error   @retval -1      Unimplemented procedure   @retval -2      Invalid argument   @retval -3      Call completed with error.   @retval -9      Call requires PAL memory buffer.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_SET_HW_POLICY
value|49
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|Mode
range|:
literal|3
decl_stmt|;
comment|///< Bit2:0, Indicates the mode of operation for this
comment|///<    procedure: 0 - Query mode 1 - Error inject mode
comment|///<    (err_inj should also be specified) 2 - Cancel
comment|///<    outstanding trigger. All other fields in
comment|///<    PAL_MC_ERROR_TYPE_INFO,
comment|///<    PAL_MC_ERROR_STRUCTURE_INFO and
comment|///<    PAL_MC_ERROR_DATA_BUFFER are ignored. All other
comment|///<    values are reserved.
name|UINT64
name|ErrorInjection
range|:
literal|3
decl_stmt|;
comment|///< Bit5:3, indicates the mode of error
comment|///<  injection: 0 - Error inject only (no
comment|///<  error consumption) 1 - Error inject
comment|///<  and consume All other values are
comment|///<  reserved.
name|UINT64
name|ErrorSeverity
range|:
literal|2
decl_stmt|;
comment|///< Bit7:6, indicates the severity desired
comment|///<  for error injection/query. Definitions
comment|///<  of the different error severity types
comment|///<  0 - Corrected error 1 - Recoverable
comment|///<  error 2 - Fatal error 3 - Reserved
name|UINT64
name|ErrorStructure
range|:
literal|5
decl_stmt|;
comment|///< Bit12:8, Indicates the structure
comment|///<  identification for error
comment|///<  injection/query: 0 - Any structure
comment|///<  (cannot be used during query mode).
comment|///<  When selected, the structure type used
comment|///<  for error injection is determined by
comment|///<  PAL. 1 - Cache 2 - TLB 3 - Register
comment|///<  file 4 - Bus/System interconnect 5-15
comment|///<  - Reserved 16-31 - Processor
comment|///<  specific error injection
comment|///<  capabilities.ErrorDataBuffer is used
comment|///<  to specify error types. Please refer
comment|///<  to the processor specific
comment|///<  documentation for additional details.
name|UINT64
name|StructureHierarchy
range|:
literal|3
decl_stmt|;
comment|///< Bit15:13, Indicates the structure
comment|///<  hierarchy for error
comment|///<  injection/query: 0 - Any level of
comment|///<  hierarchy (cannot be used during
comment|///<  query mode). When selected, the
comment|///<  structure hierarchy used for error
comment|///<  injection is determined by PAL. 1
comment|///<  - Error structure hierarchy
comment|///<  level-1 2 - Error structure
comment|///<  hierarchy level-2 3 - Error
comment|///<  structure hierarchy level-3 4 -
comment|///<  Error structure hierarchy level-4
comment|///<  All other values are reserved.
name|UINT64
name|Reserved
range|:
literal|32
decl_stmt|;
comment|///< Reserved 47:16 Reserved
name|UINT64
name|ImplSpec
range|:
literal|16
decl_stmt|;
comment|///< Bit63:48, Processor specific error injection capabilities.
block|}
name|PAL_MC_ERROR_TYPE_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|StructInfoIsValid
range|:
literal|1
decl_stmt|;
comment|///< Bit0 When 1, indicates that the
comment|///< structure information fields
comment|///< (c_t,cl_p,cl_id) are valid and
comment|///< should be used for error injection.
comment|///< When 0, the structure information
comment|///< fields are ignored, and the values
comment|///< of these fields used for error
comment|///< injection are
comment|///< implementation-specific.
name|UINT64
name|CacheType
range|:
literal|2
decl_stmt|;
comment|///< Bit2:1  Indicates which cache should be used
comment|///< for error injection: 0 - Reserved 1 -
comment|///< Instruction cache 2 - Data or unified cache
comment|///< 3 - Reserved
name|UINT64
name|PortionOfCacheLine
range|:
literal|3
decl_stmt|;
comment|///< Bit5:3 Indicates the portion of the
comment|///<   cache line where the error should
comment|///<   be injected: 0 - Reserved 1 - Tag
comment|///<   2 - Data 3 - mesi All other
comment|///<   values are reserved.
name|UINT64
name|Mechanism
range|:
literal|3
decl_stmt|;
comment|///< Bit8:6 Indicates which mechanism is used to
comment|///< identify the cache line to be used for error
comment|///< injection: 0 - Reserved 1 - Virtual address
comment|///< provided in the inj_addr field of the buffer
comment|///< pointed to by err_data_buffer should be used
comment|///< to identify the cache line for error
comment|///< injection. 2 - Physical address provided in
comment|///< the inj_addr field of the buffer pointed to
comment|///< by err_data_buffershould be used to identify
comment|///< the cache line for error injection. 3 - way
comment|///< and index fields provided in err_data_buffer
comment|///< should be used to identify the cache line
comment|///< for error injection. All other values are
comment|///< reserved.
name|UINT64
name|DataPoisonOfCacheLine
range|:
literal|1
decl_stmt|;
comment|///< Bit9 When 1, indicates that a
comment|///< multiple bit, non-correctable
comment|///< error should be injected in the
comment|///< cache line specified by cl_id.
comment|///< If this injected error is not
comment|///< consumed, it may eventually
comment|///< cause a data-poisoning event
comment|///< resulting in a corrected error
comment|///< signal, when the associated
comment|///< cache line is cast out (implicit
comment|///< or explicit write-back of the
comment|///< cache line). The error severity
comment|///< specified by err_sev in
comment|///< err_type_info must be set to 0
comment|///< (corrected error) when this bit
comment|///< is set.
name|UINT64
name|Reserved1
range|:
literal|22
decl_stmt|;
name|UINT64
name|TrigerInfoIsValid
range|:
literal|1
decl_stmt|;
comment|///< Bit32 When 1, indicates that the
comment|///< trigger information fields (trigger,
comment|///< trigger_pl) are valid and should be
comment|///< used for error injection. When 0,
comment|///< the trigger information fields are
comment|///< ignored and error injection is
comment|///< performed immediately.
name|UINT64
name|Triger
range|:
literal|4
decl_stmt|;
comment|///< Bit36:33 Indicates the operation type to be
comment|///<   used as the error trigger condition. The
comment|///<   address corresponding to the trigger is
comment|///<   specified in the trigger_addr field of the
comment|///<   buffer pointed to by err_data_buffer: 0 -
comment|///<   Instruction memory access. The trigger match
comment|///<   conditions for this operation type are similar
comment|///<   to the IBR address breakpoint match conditions
comment|///<   1 - Data memory access. The trigger match
comment|///<   conditions for this operation type are similar
comment|///<   to the DBR address breakpoint match conditions
comment|///<   All other values are reserved.
name|UINT64
name|PrivilegeOfTriger
range|:
literal|3
decl_stmt|;
comment|///< Bit39:37  Indicates the privilege
comment|///< level of the context during which
comment|///< the error should be injected: 0 -
comment|///< privilege level 0 1 - privilege
comment|///< level 1 2 - privilege level 2 3 -
comment|///< privilege level 3 All other values
comment|///< are reserved. If the implementation
comment|///< does not support privilege level
comment|///< qualifier for triggers (i.e. if
comment|///< trigger_pl is 0 in the capabilities
comment|///< vector), this field is ignored and
comment|///< triggers can be taken at any
comment|///< privilege level.
name|UINT64
name|Reserved2
range|:
literal|24
decl_stmt|;
block|}
name|PAL_MC_ERROR_STRUCT_INFO
typedef|;
end_typedef

begin_comment
comment|/**     Buffer Pointed to by err_data_buffer - TLB  **/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|TrigerAddress
decl_stmt|;
name|UINT64
name|VirtualPageNumber
range|:
literal|52
decl_stmt|;
name|UINT64
name|Reserved1
range|:
literal|8
decl_stmt|;
name|UINT64
name|RegionId
range|:
literal|24
decl_stmt|;
name|UINT64
name|Reserved2
range|:
literal|40
decl_stmt|;
block|}
name|PAL_MC_ERROR_DATA_BUFFER_TLB
typedef|;
end_typedef

begin_comment
comment|/**   PAL Procedure - PAL_MC_ERROR_INJECT.    Injects the requested processor error or returns information   on the supported injection capabilities for this particular   processor implementation. It is optional by Itanium processors. The PAL   procedure supports the Stacked Registers calling convention.   It could be called at physical and Virtual mode.    @param Index            Index of PAL_MC_ERROR_INJECT within the list of PAL                           procedures.   @param ErrorTypeInfo    Unsigned 64-bit integer specifying the                           first level error information which                           identifies the error structure and                           corresponding structure hierarchy, and                           the error severity.   @param ErrorStructInfo  Unsigned 64-bit integer identifying                           the optional structure specific                           information that provides the  second                           level details for the requested error.   @param ErrorDataBuffer  64-bit physical address of a buffer                           providing additional parameters for                           the requested error. The address of                           this buffer must be 8-byte aligned.    @retval 0               Call completed without error   @retval -1              Unimplemented procedure   @retval -2              Invalid argument   @retval -3              Call completed with error.   @retval -4              Call completed with error; the requested                           error could not be injected due to failure in                           locating the target location in the specified                           structure.   @retval -5              Argument was valid, but requested error                           injection capability is not supported.   @retval -9              Call requires PAL memory buffer.    @return R9              64-bit vector specifying the supported error                           injection capabilities for the input argument                           combination of struct_hier, err_struct and                           err_sev fields in ErrorTypeInfo.   @return R10             64-bit vector specifying the architectural                           resources that are used by the procedure.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_MC_ERROR_INJECT
value|276
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Types of PAL_GET_PSTATE.Type
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|PAL_GET_PSTATE_RECENT
value|0
end_define

begin_define
define|#
directive|define
name|PAL_GET_PSTATE_AVERAGE_NEW_START
value|1
end_define

begin_define
define|#
directive|define
name|PAL_GET_PSTATE_AVERAGE
value|2
end_define

begin_define
define|#
directive|define
name|PAL_GET_PSTATE_NOW
value|3
end_define

begin_comment
comment|/**   PAL Procedure - PAL_GET_PSTATE.    Returns the performance index of the processor. It is optional   by Itanium processors. The PAL procedure supports the Stacked Registers   calling convention. It could be called at physical and Virtual   mode.    @param Index  Index of PAL_GET_PSTATE within the list of PAL                 procedures.   @param Type   Type of performance_index value to be returned                 by this procedure.See PAL_GET_PSTATE.Type above.    @retval 1     Call completed without error, but accuracy                 of performance index has been impacted by a                 thermal throttling event, or a                 hardware-initiated event.   @retval 0     Call completed without error   @retval -1    Unimplemented procedure   @retval -2    Invalid argument   @retval -3    Call completed with error.   @retval -9    Call requires PAL memory buffer.    @return R9    Unsigned integer denoting the processor                 performance for the time duration since the last                 PAL_GET_PSTATE procedure call was made. The                 value returned is between 0 and 100, and is                 relative to the performance index of the highest                 available P-state.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_GET_PSTATE
value|262
end_define

begin_comment
comment|/**    Layout of PAL_PSTATE_INFO.PStateBuffer  **/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|PerformanceIndex
range|:
literal|7
decl_stmt|;
name|UINT32
name|Reserved1
range|:
literal|5
decl_stmt|;
name|UINT32
name|TypicalPowerDissipation
range|:
literal|20
decl_stmt|;
name|UINT32
name|TransitionLatency1
decl_stmt|;
name|UINT32
name|TransitionLatency2
decl_stmt|;
name|UINT32
name|Reserved2
decl_stmt|;
block|}
name|PAL_PSTATE_INFO_BUFFER
typedef|;
end_typedef

begin_comment
comment|/**   PAL Procedure - PAL_PSTATE_INFO.    Returns information about the P-states supported by the   processor. It is optional by Itanium processors. The PAL procedure supports   the Static Registers calling convention. It could be called   at physical and Virtual mode.    @param Index          Index of PAL_PSTATE_INFO within the list of PAL                         procedures.   @param PStateBuffer   64-bit pointer to a 256-byte buffer                         aligned on an 8-byte boundary. See                         PAL_PSTATE_INFO_BUFFER above.    @retval 0             Call completed without error   @retval -1            Unimplemented procedure   @retval -2            Invalid argument   @retval -3            Call completed with error.    @return R9            Unsigned integer denoting the number of P-states                         supported. The maximum value of this field is 16.   @return R10           Dependency domain information  **/
end_comment

begin_define
define|#
directive|define
name|PAL_PSTATE_INFO
value|44
end_define

begin_comment
comment|/**   PAL Procedure - PAL_SET_PSTATE.    To request a processor transition to a given P-state. It is   optional by Itanium processors. The PAL procedure supports the Stacked   Registers calling convention. It could be called at physical   and Virtual mode.    @param Index        Index of PAL_SET_PSTATE within the list of PAL                       procedures.   @param PState       Unsigned integer denoting the processor                       P-state being requested.   @param ForcePState  Unsigned integer denoting whether the                       P-state change should be forced for the                       logical processor.    @retval 1           Call completed without error, but                       transition request was not accepted   @retval 0           Call completed without error   @retval -1          Unimplemented procedure   @retval -2          Invalid argument   @retval -3          Call completed with error.   @retval -9          Call requires PAL memory buffer.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_SET_PSTATE
value|263
end_define

begin_comment
comment|/**   PAL Procedure - PAL_SHUTDOWN.    Put the logical processor into a low power state which can be   exited only by a reset event. It is optional by Itanium processors. The PAL   procedure supports the Static Registers calling convention. It   could be called at physical mode.    @param Index            Index of PAL_SHUTDOWN within the list of PAL                           procedures.   @param NotifyPlatform   8-byte aligned physical address                           pointer providing details on how to                           optionally notify the platform that                           the processor is entering a shutdown                           state.    @retval -1              Unimplemented procedure   @retval -2              Invalid argument   @retval -3              Call completed with error.   @retval -9              Call requires PAL memory buffer.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_SHUTDOWN
value|45
end_define

begin_comment
comment|/**    Layout of PAL_MEMORY_BUFFER.ControlWord  **/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|Registration
range|:
literal|1
decl_stmt|;
name|UINT64
name|ProbeInterrupt
range|:
literal|1
decl_stmt|;
name|UINT64
name|Reserved
range|:
literal|62
decl_stmt|;
block|}
name|PAL_MEMORY_CONTROL_WORD
typedef|;
end_typedef

begin_comment
comment|/**   PAL Procedure - PAL_MEMORY_BUFFER.    Provides cacheable memory to PAL for exclusive use during   runtime. It is optional by Itanium processors. The PAL procedure supports the   Static Registers calling convention. It could be called at   physical mode.    @param Index        Index of PAL_MEMORY_BUFFER within the list of PAL                       procedures.   @param BaseAddress  Physical address of the memory buffer                       allocated for PAL use.   @param AllocSize    Unsigned integer denoting the size of the                       memory buffer.   @param ControlWord  Formatted bit vector that provides control                       options for this procedure. See                       PAL_MEMORY_CONTROL_WORD above.    @retval 1           Call has not completed a buffer relocation                       due to a pending interrupt   @retval 0           Call completed without error   @retval -1          Unimplemented procedure   @retval -2          Invalid argument   @retval -3          Call completed with error.   @retval -9          Call requires PAL memory buffer.    @return R9          Returns the minimum size of the memory buffer                       required if the alloc_size input argument was                       not large enough.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_MEMORY_BUFFER
value|277
end_define

begin_comment
comment|/**   PAL Procedure - PAL_VP_CREATE.    Initializes a new vpd for the operation of a new virtual   processor in the virtual environment. It is optional by Itanium processors.   The PAL procedure supports the Stacked Registers calling   convention. It could be called at Virtual mode.    @param Index            Index of PAL_VP_CREATE within the list of PAL                           procedures.   @param Vpd              64-bit host virtual pointer to the Virtual                           Processor Descriptor (VPD).   @param HostIva          64-bit host virtual pointer to the host IVT                           for the virtual processor   @param OptionalHandler  64-bit non-zero host-virtual pointer                           to an optional handler for                           virtualization intercepts.    @retval 0               Call completed without error   @retval -1              Unimplemented procedure   @retval -2              Invalid argument   @retval -3              Call completed with error.   @retval -9              Call requires PAL memory buffer.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_VP_CREATE
value|265
end_define

begin_comment
comment|/**    Virtual Environment Information Parameter  **/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|Reserved1
range|:
literal|8
decl_stmt|;
name|UINT64
name|Opcode
range|:
literal|1
decl_stmt|;
name|UINT64
name|Reserved
range|:
literal|53
decl_stmt|;
block|}
name|PAL_VP_ENV_INFO_RETURN
typedef|;
end_typedef

begin_comment
comment|/**   PAL Procedure - PAL_VP_ENV_INFO.    Returns the parameters needed to enter a virtual environment.   It is optional by Itanium processors. The PAL procedure supports the Stacked   Registers calling convention. It could be called at Virtual   mode.    @param Index            Index of PAL_VP_ENV_INFO within the list of PAL                           procedures.   @param Vpd              64-bit host virtual pointer to the Virtual                           Processor Descriptor (VPD).   @param HostIva          64-bit host virtual pointer to the host IVT                           for the virtual processor   @param OptionalHandler  64-bit non-zero host-virtual pointer                           to an optional handler for                           virtualization intercepts.    @retval 0               Call completed without error   @retval -1              Unimplemented procedure   @retval -2              Invalid argument   @retval -3              Call completed with error.   @retval -9              Call requires PAL memory buffer.    @return R9              Unsigned integer denoting the number of bytes                           required by the PAL virtual environment buffer                           during PAL_VP_INIT_ENV   @return R10             64-bit vector of virtual environment                           information. See PAL_VP_ENV_INFO_RETURN.   **/
end_comment

begin_define
define|#
directive|define
name|PAL_VP_ENV_INFO
value|266
end_define

begin_comment
comment|/**   PAL Procedure - PAL_VP_EXIT_ENV.    Allows a logical processor to exit a virtual environment.   It is optional by Itanium processors. The PAL procedure supports the Stacked   Registers calling convention. It could be called at Virtual   mode.    @param Index  Index of PAL_VP_EXIT_ENV within the list of PAL                 procedures.   @param Iva    Optional 64-bit host virtual pointer to the IVT                 when this procedure is done    @retval 0     Call completed without error   @retval -1    Unimplemented procedure   @retval -2    Invalid argument   @retval -3    Call completed with error.   @retval -9    Call requires PAL memory buffer.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_VP_EXIT_ENV
value|267
end_define

begin_comment
comment|/**   PAL Procedure - PAL_VP_INIT_ENV.    Allows a logical processor to enter a virtual environment. It   is optional by Itanium processors. The PAL procedure supports the Stacked   Registers calling convention. It could be called at Virtual   mode.    @param Index          Index of PAL_VP_INIT_ENV within the list of PAL                         procedures.   @param ConfigOptions  64-bit vector of global configuration                         settings.   @param PhysicalBase   Host physical base address of a block of                         contiguous physical memory for the PAL                         virtual environment buffer 1) This                         memory area must be allocated by the VMM                         and be 4K aligned. The first logical                         processor to enter the environment will                         initialize the physical block for                         virtualization operations.   @param VirtualBase    Host virtual base address of the                         corresponding physical memory block for                         the PAL virtual environment buffer : The                         VMM must maintain the host virtual to host                         physical data and instruction translations                         in TRs for addresses within the allocated                         address space. Logical processors in this                         virtual environment will use this address                         when transitioning to virtual mode                         operations.    @retval 0             Call completed without error   @retval -1            Unimplemented procedure   @retval -2            Invalid argument   @retval -3            Call completed with error.   @retval -9            Call requires PAL memory buffer.    @return R9            Virtualization Service Address - VSA specifies                         the virtual base address of the PAL                         virtualization services in this virtual                         environment.   **/
end_comment

begin_define
define|#
directive|define
name|PAL_VP_INIT_ENV
value|268
end_define

begin_comment
comment|/**   PAL Procedure - PAL_VP_REGISTER.    Register a different host IVT and/or a different optional   virtualization intercept handler for the virtual processor   specified by vpd. It is optional by Itanium processors. The PAL procedure   supports the Stacked Registers calling convention. It could be   called at Virtual mode.    @param Index            Index of PAL_VP_REGISTER within the list of PAL                           procedures.   @param Vpd              64-bit host virtual pointer to the Virtual                           Processor Descriptor (VPD) host_iva 64-bit host                           virtual pointer to the host IVT for the virtual                           processor   @param OptionalHandler  64-bit non-zero host-virtual pointer                           to an optional handler for                           virtualization intercepts.    @retval 0               Call completed without error   @retval -1              Unimplemented procedure   @retval -2              Invalid argument   @retval -3              Call completed with error.   @retval -9              Call requires PAL memory buffer.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_VP_REGISTER
value|269
end_define

begin_comment
comment|/**   PAL Procedure - PAL_VP_RESTORE.    Restores virtual processor state for the specified vpd on the   logical processor. It is optional by Itanium processors. The PAL procedure   supports the Stacked Registers calling convention. It could be   called at Virtual mode.    @param Index      Index of PAL_VP_RESTORE within the list of PAL                     procedures.   @param Vpd        64-bit host virtual pointer to the Virtual                     Processor Descriptor (VPD) host_iva 64-bit host                     virtual pointer to the host IVT for the virtual                     processor   @param PalVector  Vector specifies PAL procedure                     implementation-specific state to be                     restored.    @retval 0         Call completed without error   @retval -1        Unimplemented procedure   @retval -2        Invalid argument   @retval -3        Call completed with error.   @retval -9        Call requires PAL memory buffer.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_VP_RESTORE
value|270
end_define

begin_comment
comment|/**   PAL Procedure - PAL_VP_SAVE.    Saves virtual processor state for the specified vpd on the   logical processor. It is optional by Itanium processors. The PAL procedure   supports the Stacked Registers calling convention. It could be   called at Virtual mode.    @param Index      Index of PAL_VP_SAVE within the list of PAL                     procedures.   @param Vpd        64-bit host virtual pointer to the Virtual                     Processor Descriptor (VPD) host_iva 64-bit host                     virtual pointer to the host IVT for the virtual                     processor   @param PalVector  Vector specifies PAL procedure                     implementation-specific state to be                     restored.    @retval 0         Call completed without error   @retval -1        Unimplemented procedure   @retval -2        Invalid argument   @retval -3        Call completed with error.   @retval -9        Call requires PAL memory buffer.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_VP_SAVE
value|271
end_define

begin_comment
comment|/**   PAL Procedure - PAL_VP_TERMINATE.    Terminates operation for the specified virtual processor. It   is optional by Itanium processors. The PAL procedure supports the Stacked   Registers calling convention. It could be called at Virtual   mode.    @param Index  Index of PAL_VP_TERMINATE within the list of PAL                 procedures.   @param Vpd    64-bit host virtual pointer to the Virtual                 Processor Descriptor (VPD)   @param Iva    Optional 64-bit host virtual pointer to the IVT                 when this procedure is done.    @retval 0     Call completed without error   @retval -1    Unimplemented procedure   @retval -2    Invalid argument   @retval -3    Call completed with error.   @retval -9    Call requires PAL memory buffer.  **/
end_comment

begin_define
define|#
directive|define
name|PAL_VP_TERMINATE
value|272
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

