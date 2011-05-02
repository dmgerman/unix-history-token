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
comment|// InterferenceCache remembers per-block interference in LiveIntervalUnions.
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
file|"LiveIntervalUnion.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
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
name|SlotIndexes
modifier|*
name|Indexes
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
comment|/// PrevPos - The previous position the iterators were moved to.
name|SlotIndex
name|PrevPos
decl_stmt|;
comment|/// AliasTags - A LiveIntervalUnion pointer and tag for each alias of
comment|/// PhysReg.
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|LiveIntervalUnion
operator|*
operator|,
name|unsigned
operator|>
operator|,
literal|8
operator|>
name|Aliases
expr_stmt|;
typedef|typedef
name|LiveIntervalUnion
operator|::
name|SegmentIter
name|Iter
expr_stmt|;
comment|/// Iters - an iterator for each alias
name|SmallVector
operator|<
name|Iter
operator|,
literal|8
operator|>
name|Iters
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
name|Indexes
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
argument_list|)
block|{
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
name|revalidate
parameter_list|()
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
name|Indexes
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
specifier|const
name|TargetRegisterInfo
operator|*
argument_list|)
expr_stmt|;
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
name|public
label|:
comment|/// Cursor - Create a cursor for the interference allocated to PhysReg and
comment|/// all its aliases.
name|Cursor
argument_list|(
argument|InterferenceCache&Cache
argument_list|,
argument|unsigned PhysReg
argument_list|)
block|:
name|CacheEntry
argument_list|(
name|Cache
operator|.
name|get
argument_list|(
name|PhysReg
argument_list|)
argument_list|)
operator|,
name|Current
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// moveTo - Move cursor to basic block MBBNum.
name|void
name|moveToBlock
argument_list|(
argument|unsigned MBBNum
argument_list|)
block|{
name|Current
operator|=
name|CacheEntry
operator|->
name|get
argument_list|(
name|MBBNum
argument_list|)
block|;     }
comment|/// hasInterference - Return true if the current block has any interference.
name|bool
name|hasInterference
argument_list|()
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

