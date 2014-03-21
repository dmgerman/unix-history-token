begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- InterferenceCache.h - Caching per-block interference ---*- C++ -*--===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// InterferenceCache remembers per-block interference from LiveIntervalUnions,
end_comment

begin_comment
comment|// fixed RegUnit interference, and register masks.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CODEGEN_INTERFERENCECACHE
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_INTERFERENCECACHE
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/LiveIntervalUnion.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LiveIntervals
decl_stmt|;
name|class
name|InterferenceCache
block|{
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
decl_stmt|;
name|LiveIntervalUnion
modifier|*
name|LIUArray
decl_stmt|;
name|MachineFunction
modifier|*
name|MF
decl_stmt|;
comment|/// BlockInterference - information about the interference in a single basic
comment|/// block.
struct|struct
name|BlockInterference
block|{
name|BlockInterference
argument_list|()
operator|:
name|Tag
argument_list|(
literal|0
argument_list|)
block|{}
name|unsigned
name|Tag
expr_stmt|;
name|SlotIndex
name|First
decl_stmt|;
name|SlotIndex
name|Last
decl_stmt|;
block|}
struct|;
comment|/// Entry - A cache entry containing interference information for all aliases
comment|/// of PhysReg in all basic blocks.
name|class
name|Entry
block|{
comment|/// PhysReg - The register currently represented.
name|unsigned
name|PhysReg
decl_stmt|;
comment|/// Tag - Cache tag is changed when any of the underlying LiveIntervalUnions
comment|/// change.
name|unsigned
name|Tag
decl_stmt|;
comment|/// RefCount - The total number of Cursor instances referring to this Entry.
name|unsigned
name|RefCount
decl_stmt|;
comment|/// MF - The current function.
name|MachineFunction
modifier|*
name|MF
decl_stmt|;
comment|/// Indexes - Mapping block numbers to SlotIndex ranges.
name|SlotIndexes
modifier|*
name|Indexes
decl_stmt|;
comment|/// LIS - Used for accessing register mask interference maps.
name|LiveIntervals
modifier|*
name|LIS
decl_stmt|;
comment|/// PrevPos - The previous position the iterators were moved to.
name|SlotIndex
name|PrevPos
decl_stmt|;
comment|/// RegUnitInfo - Information tracked about each RegUnit in PhysReg.
comment|/// When PrevPos is set, the iterators are valid as if advanceTo(PrevPos)
comment|/// had just been called.
struct|struct
name|RegUnitInfo
block|{
comment|/// Iterator pointing into the LiveIntervalUnion containing virtual
comment|/// register interference.
name|LiveIntervalUnion
operator|::
name|SegmentIter
name|VirtI
expr_stmt|;
comment|/// Tag of the LIU last time we looked.
name|unsigned
name|VirtTag
decl_stmt|;
comment|/// Fixed interference in RegUnit.
name|LiveRange
modifier|*
name|Fixed
decl_stmt|;
comment|/// Iterator pointing into the fixed RegUnit interference.
name|LiveInterval
operator|::
name|iterator
name|FixedI
expr_stmt|;
name|RegUnitInfo
argument_list|(
name|LiveIntervalUnion
operator|&
name|LIU
argument_list|)
operator|:
name|VirtTag
argument_list|(
name|LIU
operator|.
name|getTag
argument_list|()
argument_list|)
operator|,
name|Fixed
argument_list|(
literal|0
argument_list|)
block|{
name|VirtI
operator|.
name|setMap
argument_list|(
name|LIU
operator|.
name|getMap
argument_list|()
argument_list|)
block|;       }
block|}
struct|;
comment|/// Info for each RegUnit in PhysReg. It is very rare ofr a PHysReg to have
comment|/// more than 4 RegUnits.
name|SmallVector
operator|<
name|RegUnitInfo
operator|,
literal|4
operator|>
name|RegUnits
expr_stmt|;
comment|/// Blocks - Interference for each block in the function.
name|SmallVector
operator|<
name|BlockInterference
operator|,
literal|8
operator|>
name|Blocks
expr_stmt|;
comment|/// update - Recompute Blocks[MBBNum]
name|void
name|update
parameter_list|(
name|unsigned
name|MBBNum
parameter_list|)
function_decl|;
name|public
label|:
name|Entry
argument_list|()
operator|:
name|PhysReg
argument_list|(
literal|0
argument_list|)
operator|,
name|Tag
argument_list|(
literal|0
argument_list|)
operator|,
name|RefCount
argument_list|(
literal|0
argument_list|)
operator|,
name|Indexes
argument_list|(
literal|0
argument_list|)
operator|,
name|LIS
argument_list|(
literal|0
argument_list|)
block|{}
name|void
name|clear
argument_list|(
argument|MachineFunction *mf
argument_list|,
argument|SlotIndexes *indexes
argument_list|,
argument|LiveIntervals *lis
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|hasRefs
argument_list|()
operator|&&
literal|"Cannot clear cache entry with references"
argument_list|)
block|;
name|PhysReg
operator|=
literal|0
block|;
name|MF
operator|=
name|mf
block|;
name|Indexes
operator|=
name|indexes
block|;
name|LIS
operator|=
name|lis
block|;     }
name|unsigned
name|getPhysReg
argument_list|()
specifier|const
block|{
return|return
name|PhysReg
return|;
block|}
name|void
name|addRef
parameter_list|(
name|int
name|Delta
parameter_list|)
block|{
name|RefCount
operator|+=
name|Delta
expr_stmt|;
block|}
name|bool
name|hasRefs
argument_list|()
specifier|const
block|{
return|return
name|RefCount
operator|>
literal|0
return|;
block|}
name|void
name|revalidate
parameter_list|(
name|LiveIntervalUnion
modifier|*
name|LIUArray
parameter_list|,
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
parameter_list|)
function_decl|;
comment|/// valid - Return true if this is a valid entry for physReg.
name|bool
name|valid
parameter_list|(
name|LiveIntervalUnion
modifier|*
name|LIUArray
parameter_list|,
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
parameter_list|)
function_decl|;
comment|/// reset - Initialize entry to represent physReg's aliases.
name|void
name|reset
parameter_list|(
name|unsigned
name|physReg
parameter_list|,
name|LiveIntervalUnion
modifier|*
name|LIUArray
parameter_list|,
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
parameter_list|,
specifier|const
name|MachineFunction
modifier|*
name|MF
parameter_list|)
function_decl|;
comment|/// get - Return an up to date BlockInterference.
name|BlockInterference
modifier|*
name|get
parameter_list|(
name|unsigned
name|MBBNum
parameter_list|)
block|{
if|if
condition|(
name|Blocks
index|[
name|MBBNum
index|]
operator|.
name|Tag
operator|!=
name|Tag
condition|)
name|update
argument_list|(
name|MBBNum
argument_list|)
expr_stmt|;
return|return
operator|&
name|Blocks
index|[
name|MBBNum
index|]
return|;
block|}
block|}
empty_stmt|;
comment|// We don't keep a cache entry for every physical register, that would use too
comment|// much memory. Instead, a fixed number of cache entries are used in a round-
comment|// robin manner.
enum|enum
block|{
name|CacheEntries
init|=
literal|32
block|}
enum|;
comment|// Point to an entry for each physreg. The entry pointed to may not be up to
comment|// date, and it may have been reused for a different physreg.
name|SmallVector
operator|<
name|unsigned
name|char
operator|,
literal|2
operator|>
name|PhysRegEntries
expr_stmt|;
comment|// Next round-robin entry to be picked.
name|unsigned
name|RoundRobin
decl_stmt|;
comment|// The actual cache entries.
name|Entry
name|Entries
index|[
name|CacheEntries
index|]
decl_stmt|;
comment|// get - Get a valid entry for PhysReg.
name|Entry
modifier|*
name|get
parameter_list|(
name|unsigned
name|PhysReg
parameter_list|)
function_decl|;
name|public
label|:
name|InterferenceCache
argument_list|()
operator|:
name|TRI
argument_list|(
literal|0
argument_list|)
operator|,
name|LIUArray
argument_list|(
literal|0
argument_list|)
operator|,
name|MF
argument_list|(
literal|0
argument_list|)
operator|,
name|RoundRobin
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// init - Prepare cache for a new function.
name|void
name|init
argument_list|(
name|MachineFunction
operator|*
argument_list|,
name|LiveIntervalUnion
operator|*
argument_list|,
name|SlotIndexes
operator|*
argument_list|,
name|LiveIntervals
operator|*
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|*
argument_list|)
expr_stmt|;
comment|/// getMaxCursors - Return the maximum number of concurrent cursors that can
comment|/// be supported.
name|unsigned
name|getMaxCursors
argument_list|()
specifier|const
block|{
return|return
name|CacheEntries
return|;
block|}
comment|/// Cursor - The primary query interface for the block interference cache.
name|class
name|Cursor
block|{
name|Entry
modifier|*
name|CacheEntry
decl_stmt|;
name|BlockInterference
modifier|*
name|Current
decl_stmt|;
specifier|static
name|BlockInterference
name|NoInterference
decl_stmt|;
name|void
name|setEntry
parameter_list|(
name|Entry
modifier|*
name|E
parameter_list|)
block|{
name|Current
operator|=
literal|0
expr_stmt|;
comment|// Update reference counts. Nothing happens when RefCount reaches 0, so
comment|// we don't have to check for E == CacheEntry etc.
if|if
condition|(
name|CacheEntry
condition|)
name|CacheEntry
operator|->
name|addRef
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
name|CacheEntry
operator|=
name|E
expr_stmt|;
if|if
condition|(
name|CacheEntry
condition|)
name|CacheEntry
operator|->
name|addRef
argument_list|(
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
name|public
label|:
comment|/// Cursor - Create a dangling cursor.
name|Cursor
argument_list|()
operator|:
name|CacheEntry
argument_list|(
literal|0
argument_list|)
operator|,
name|Current
argument_list|(
literal|0
argument_list|)
block|{}
operator|~
name|Cursor
argument_list|()
block|{
name|setEntry
argument_list|(
literal|0
argument_list|)
block|; }
name|Cursor
argument_list|(
specifier|const
name|Cursor
operator|&
name|O
argument_list|)
operator|:
name|CacheEntry
argument_list|(
literal|0
argument_list|)
operator|,
name|Current
argument_list|(
literal|0
argument_list|)
block|{
name|setEntry
argument_list|(
name|O
operator|.
name|CacheEntry
argument_list|)
block|;     }
name|Cursor
operator|&
name|operator
operator|=
operator|(
specifier|const
name|Cursor
operator|&
name|O
operator|)
block|{
name|setEntry
argument_list|(
name|O
operator|.
name|CacheEntry
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// setPhysReg - Point this cursor to PhysReg's interference.
name|void
name|setPhysReg
parameter_list|(
name|InterferenceCache
modifier|&
name|Cache
parameter_list|,
name|unsigned
name|PhysReg
parameter_list|)
block|{
comment|// Release reference before getting a new one. That guarantees we can
comment|// actually have CacheEntries live cursors.
name|setEntry
argument_list|(
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|PhysReg
condition|)
name|setEntry
argument_list|(
name|Cache
operator|.
name|get
argument_list|(
name|PhysReg
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// moveTo - Move cursor to basic block MBBNum.
name|void
name|moveToBlock
parameter_list|(
name|unsigned
name|MBBNum
parameter_list|)
block|{
name|Current
operator|=
name|CacheEntry
condition|?
name|CacheEntry
operator|->
name|get
argument_list|(
name|MBBNum
argument_list|)
else|:
operator|&
name|NoInterference
expr_stmt|;
block|}
comment|/// hasInterference - Return true if the current block has any interference.
name|bool
name|hasInterference
parameter_list|()
block|{
return|return
name|Current
operator|->
name|First
operator|.
name|isValid
argument_list|()
return|;
block|}
comment|/// first - Return the starting index of the first interfering range in the
comment|/// current block.
name|SlotIndex
name|first
parameter_list|()
block|{
return|return
name|Current
operator|->
name|First
return|;
block|}
comment|/// last - Return the ending index of the last interfering range in the
comment|/// current block.
name|SlotIndex
name|last
parameter_list|()
block|{
return|return
name|Current
operator|->
name|Last
return|;
block|}
block|}
empty_stmt|;
name|friend
name|class
name|Cursor
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

