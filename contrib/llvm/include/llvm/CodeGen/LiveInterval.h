begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/LiveInterval.h - Interval representation ---*- C++ -*-===//
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
comment|// This file implements the LiveRange and LiveInterval classes.  Given some
end_comment

begin_comment
comment|// numbering of each the machine instructions an interval [i, j) is said to be a
end_comment

begin_comment
comment|// live interval for register v if there is no instruction with number j'>= j
end_comment

begin_comment
comment|// such that v is live at j' and there is no instruction with number i'< i such
end_comment

begin_comment
comment|// that v is live at i'. In this implementation intervals can have holes,
end_comment

begin_comment
comment|// i.e. an interval might look like [1,20), [50,65), [1000,1001).  Each
end_comment

begin_comment
comment|// individual range is represented as an instance of LiveRange, and the whole
end_comment

begin_comment
comment|// interval is represented as an instance of LiveInterval.
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
name|LLVM_CODEGEN_LIVEINTERVAL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_LIVEINTERVAL_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/IntEqClasses.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SlotIndexes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/AlignOf.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<climits>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|CoalescerPair
decl_stmt|;
name|class
name|LiveIntervals
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineRegisterInfo
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// VNInfo - Value Number Information.
comment|/// This class holds information about a machine level values, including
comment|/// definition and use points.
comment|///
name|class
name|VNInfo
block|{
name|public
label|:
typedef|typedef
name|BumpPtrAllocator
name|Allocator
typedef|;
comment|/// The ID number of this value.
name|unsigned
name|id
decl_stmt|;
comment|/// The index of the defining instruction.
name|SlotIndex
name|def
decl_stmt|;
comment|/// VNInfo constructor.
name|VNInfo
argument_list|(
argument|unsigned i
argument_list|,
argument|SlotIndex d
argument_list|)
block|:
name|id
argument_list|(
name|i
argument_list|)
operator|,
name|def
argument_list|(
argument|d
argument_list|)
block|{ }
comment|/// VNInfo construtor, copies values from orig, except for the value number.
name|VNInfo
argument_list|(
argument|unsigned i
argument_list|,
argument|const VNInfo&orig
argument_list|)
operator|:
name|id
argument_list|(
name|i
argument_list|)
operator|,
name|def
argument_list|(
argument|orig.def
argument_list|)
block|{ }
comment|/// Copy from the parameter into this VNInfo.
name|void
name|copyFrom
argument_list|(
argument|VNInfo&src
argument_list|)
block|{
name|def
operator|=
name|src
operator|.
name|def
block|;     }
comment|/// Returns true if this value is defined by a PHI instruction (or was,
comment|/// PHI instrucions may have been eliminated).
comment|/// PHI-defs begin at a block boundary, all other defs begin at register or
comment|/// EC slots.
name|bool
name|isPHIDef
argument_list|()
specifier|const
block|{
return|return
name|def
operator|.
name|isBlock
argument_list|()
return|;
block|}
comment|/// Returns true if this value is unused.
name|bool
name|isUnused
argument_list|()
specifier|const
block|{
return|return
operator|!
name|def
operator|.
name|isValid
argument_list|()
return|;
block|}
comment|/// Mark this value as unused.
name|void
name|markUnused
parameter_list|()
block|{
name|def
operator|=
name|SlotIndex
argument_list|()
expr_stmt|;
block|}
block|}
empty_stmt|;
comment|/// LiveRange structure - This represents a simple register range in the
comment|/// program, with an inclusive start point and an exclusive end point.
comment|/// These ranges are rendered as [start,end).
struct|struct
name|LiveRange
block|{
name|SlotIndex
name|start
decl_stmt|;
comment|// Start point of the interval (inclusive)
name|SlotIndex
name|end
decl_stmt|;
comment|// End point of the interval (exclusive)
name|VNInfo
modifier|*
name|valno
decl_stmt|;
comment|// identifier for the value contained in this interval.
name|LiveRange
argument_list|()
operator|:
name|valno
argument_list|(
literal|0
argument_list|)
block|{}
name|LiveRange
argument_list|(
argument|SlotIndex S
argument_list|,
argument|SlotIndex E
argument_list|,
argument|VNInfo *V
argument_list|)
operator|:
name|start
argument_list|(
name|S
argument_list|)
operator|,
name|end
argument_list|(
name|E
argument_list|)
operator|,
name|valno
argument_list|(
argument|V
argument_list|)
block|{
name|assert
argument_list|(
name|S
operator|<
name|E
operator|&&
literal|"Cannot create empty or backwards range"
argument_list|)
block|;     }
comment|/// contains - Return true if the index is covered by this range.
comment|///
name|bool
name|contains
argument_list|(
argument|SlotIndex I
argument_list|)
specifier|const
block|{
return|return
name|start
operator|<=
name|I
operator|&&
name|I
operator|<
name|end
return|;
block|}
comment|/// containsRange - Return true if the given range, [S, E), is covered by
comment|/// this range.
name|bool
name|containsRange
argument_list|(
name|SlotIndex
name|S
argument_list|,
name|SlotIndex
name|E
argument_list|)
decl|const
block|{
name|assert
argument_list|(
operator|(
name|S
operator|<
name|E
operator|)
operator|&&
literal|"Backwards interval?"
argument_list|)
expr_stmt|;
return|return
operator|(
name|start
operator|<=
name|S
operator|&&
name|S
operator|<
name|end
operator|)
operator|&&
operator|(
name|start
operator|<
name|E
operator|&&
name|E
operator|<=
name|end
operator|)
return|;
block|}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|LiveRange
operator|&
name|LR
operator|)
specifier|const
block|{
return|return
name|start
operator|<
name|LR
operator|.
name|start
operator|||
operator|(
name|start
operator|==
name|LR
operator|.
name|start
operator|&&
name|end
operator|<
name|LR
operator|.
name|end
operator|)
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|LiveRange
operator|&
name|LR
operator|)
specifier|const
block|{
return|return
name|start
operator|==
name|LR
operator|.
name|start
operator|&&
name|end
operator|==
name|LR
operator|.
name|end
return|;
block|}
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|os
argument_list|)
decl|const
decl_stmt|;
block|}
struct|;
name|template
operator|<
operator|>
expr|struct
name|isPodLike
operator|<
name|LiveRange
operator|>
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
name|true
block|; }
expr_stmt|;
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|os
operator|,
specifier|const
name|LiveRange
operator|&
name|LR
operator|)
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|<
operator|(
name|SlotIndex
name|V
operator|,
specifier|const
name|LiveRange
operator|&
name|LR
operator|)
block|{
return|return
name|V
operator|<
name|LR
operator|.
name|start
return|;
block|}
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|LiveRange
operator|&
name|LR
operator|,
name|SlotIndex
name|V
operator|)
block|{
return|return
name|LR
operator|.
name|start
operator|<
name|V
return|;
block|}
comment|/// LiveInterval - This class represents some number of live ranges for a
comment|/// register or value.  This class also contains a bit of register allocator
comment|/// state.
name|class
name|LiveInterval
block|{
name|public
label|:
typedef|typedef
name|SmallVector
operator|<
name|LiveRange
operator|,
literal|4
operator|>
name|Ranges
expr_stmt|;
typedef|typedef
name|SmallVector
operator|<
name|VNInfo
operator|*
operator|,
literal|4
operator|>
name|VNInfoList
expr_stmt|;
specifier|const
name|unsigned
name|reg
decl_stmt|;
comment|// the register or stack slot of this interval.
name|float
name|weight
decl_stmt|;
comment|// weight of this interval
name|Ranges
name|ranges
decl_stmt|;
comment|// the ranges in which this register is live
name|VNInfoList
name|valnos
decl_stmt|;
comment|// value#'s
struct|struct
name|InstrSlots
block|{
enum|enum
block|{
name|LOAD
init|=
literal|0
block|,
name|USE
init|=
literal|1
block|,
name|DEF
init|=
literal|2
block|,
name|STORE
init|=
literal|3
block|,
name|NUM
init|=
literal|4
block|}
enum|;
block|}
struct|;
name|LiveInterval
argument_list|(
argument|unsigned Reg
argument_list|,
argument|float Weight
argument_list|)
block|:
name|reg
argument_list|(
name|Reg
argument_list|)
operator|,
name|weight
argument_list|(
argument|Weight
argument_list|)
block|{}
typedef|typedef
name|Ranges
operator|::
name|iterator
name|iterator
expr_stmt|;
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|ranges
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
parameter_list|()
block|{
return|return
name|ranges
operator|.
name|end
argument_list|()
return|;
block|}
typedef|typedef
name|Ranges
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|ranges
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|ranges
operator|.
name|end
argument_list|()
return|;
block|}
typedef|typedef
name|VNInfoList
operator|::
name|iterator
name|vni_iterator
expr_stmt|;
name|vni_iterator
name|vni_begin
parameter_list|()
block|{
return|return
name|valnos
operator|.
name|begin
argument_list|()
return|;
block|}
name|vni_iterator
name|vni_end
parameter_list|()
block|{
return|return
name|valnos
operator|.
name|end
argument_list|()
return|;
block|}
typedef|typedef
name|VNInfoList
operator|::
name|const_iterator
name|const_vni_iterator
expr_stmt|;
name|const_vni_iterator
name|vni_begin
argument_list|()
specifier|const
block|{
return|return
name|valnos
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_vni_iterator
name|vni_end
argument_list|()
specifier|const
block|{
return|return
name|valnos
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// advanceTo - Advance the specified iterator to point to the LiveRange
comment|/// containing the specified position, or end() if the position is past the
comment|/// end of the interval.  If no LiveRange contains this position, but the
comment|/// position is in a hole, this method returns an iterator pointing to the
comment|/// LiveRange immediately after the hole.
name|iterator
name|advanceTo
parameter_list|(
name|iterator
name|I
parameter_list|,
name|SlotIndex
name|Pos
parameter_list|)
block|{
name|assert
argument_list|(
name|I
operator|!=
name|end
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|Pos
operator|>=
name|endIndex
argument_list|()
condition|)
return|return
name|end
argument_list|()
return|;
while|while
condition|(
name|I
operator|->
name|end
operator|<=
name|Pos
condition|)
operator|++
name|I
expr_stmt|;
return|return
name|I
return|;
block|}
comment|/// find - Return an iterator pointing to the first range that ends after
comment|/// Pos, or end(). This is the same as advanceTo(begin(), Pos), but faster
comment|/// when searching large intervals.
comment|///
comment|/// If Pos is contained in a LiveRange, that range is returned.
comment|/// If Pos is in a hole, the following LiveRange is returned.
comment|/// If Pos is beyond endIndex, end() is returned.
name|iterator
name|find
parameter_list|(
name|SlotIndex
name|Pos
parameter_list|)
function_decl|;
name|const_iterator
name|find
argument_list|(
name|SlotIndex
name|Pos
argument_list|)
decl|const
block|{
return|return
name|const_cast
operator|<
name|LiveInterval
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|find
argument_list|(
name|Pos
argument_list|)
return|;
block|}
name|void
name|clear
parameter_list|()
block|{
name|valnos
operator|.
name|clear
argument_list|()
expr_stmt|;
name|ranges
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|bool
name|hasAtLeastOneValue
argument_list|()
specifier|const
block|{
return|return
operator|!
name|valnos
operator|.
name|empty
argument_list|()
return|;
block|}
name|bool
name|containsOneValue
argument_list|()
specifier|const
block|{
return|return
name|valnos
operator|.
name|size
argument_list|()
operator|==
literal|1
return|;
block|}
name|unsigned
name|getNumValNums
argument_list|()
specifier|const
block|{
return|return
operator|(
name|unsigned
operator|)
name|valnos
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// getValNumInfo - Returns pointer to the specified val#.
comment|///
specifier|inline
name|VNInfo
modifier|*
name|getValNumInfo
parameter_list|(
name|unsigned
name|ValNo
parameter_list|)
block|{
return|return
name|valnos
index|[
name|ValNo
index|]
return|;
block|}
specifier|inline
specifier|const
name|VNInfo
modifier|*
name|getValNumInfo
argument_list|(
name|unsigned
name|ValNo
argument_list|)
decl|const
block|{
return|return
name|valnos
index|[
name|ValNo
index|]
return|;
block|}
comment|/// containsValue - Returns true if VNI belongs to this interval.
name|bool
name|containsValue
argument_list|(
specifier|const
name|VNInfo
operator|*
name|VNI
argument_list|)
decl|const
block|{
return|return
name|VNI
operator|&&
name|VNI
operator|->
name|id
operator|<
name|getNumValNums
argument_list|()
operator|&&
name|VNI
operator|==
name|getValNumInfo
argument_list|(
name|VNI
operator|->
name|id
argument_list|)
return|;
block|}
comment|/// getNextValue - Create a new value number and return it.  MIIdx specifies
comment|/// the instruction that defines the value number.
name|VNInfo
modifier|*
name|getNextValue
argument_list|(
name|SlotIndex
name|def
argument_list|,
name|VNInfo
operator|::
name|Allocator
operator|&
name|VNInfoAllocator
argument_list|)
block|{
name|VNInfo
modifier|*
name|VNI
init|=
name|new
argument_list|(
argument|VNInfoAllocator
argument_list|)
name|VNInfo
argument_list|(
operator|(
name|unsigned
operator|)
name|valnos
operator|.
name|size
argument_list|()
argument_list|,
name|def
argument_list|)
decl_stmt|;
name|valnos
operator|.
name|push_back
argument_list|(
name|VNI
argument_list|)
expr_stmt|;
return|return
name|VNI
return|;
block|}
comment|/// createDeadDef - Make sure the interval has a value defined at Def.
comment|/// If one already exists, return it. Otherwise allocate a new value and
comment|/// add liveness for a dead def.
name|VNInfo
modifier|*
name|createDeadDef
argument_list|(
name|SlotIndex
name|Def
argument_list|,
name|VNInfo
operator|::
name|Allocator
operator|&
name|VNInfoAllocator
argument_list|)
decl_stmt|;
comment|/// Create a copy of the given value. The new value will be identical except
comment|/// for the Value number.
name|VNInfo
modifier|*
name|createValueCopy
argument_list|(
specifier|const
name|VNInfo
operator|*
name|orig
argument_list|,
name|VNInfo
operator|::
name|Allocator
operator|&
name|VNInfoAllocator
argument_list|)
block|{
name|VNInfo
modifier|*
name|VNI
init|=
name|new
argument_list|(
argument|VNInfoAllocator
argument_list|)
name|VNInfo
argument_list|(
operator|(
name|unsigned
operator|)
name|valnos
operator|.
name|size
argument_list|()
argument_list|,
operator|*
name|orig
argument_list|)
decl_stmt|;
name|valnos
operator|.
name|push_back
argument_list|(
name|VNI
argument_list|)
expr_stmt|;
return|return
name|VNI
return|;
block|}
comment|/// RenumberValues - Renumber all values in order of appearance and remove
comment|/// unused values.
name|void
name|RenumberValues
parameter_list|(
name|LiveIntervals
modifier|&
name|lis
parameter_list|)
function_decl|;
comment|/// MergeValueNumberInto - This method is called when two value nubmers
comment|/// are found to be equivalent.  This eliminates V1, replacing all
comment|/// LiveRanges with the V1 value number with the V2 value number.  This can
comment|/// cause merging of V1/V2 values numbers and compaction of the value space.
name|VNInfo
modifier|*
name|MergeValueNumberInto
parameter_list|(
name|VNInfo
modifier|*
name|V1
parameter_list|,
name|VNInfo
modifier|*
name|V2
parameter_list|)
function_decl|;
comment|/// MergeValueInAsValue - Merge all of the live ranges of a specific val#
comment|/// in RHS into this live interval as the specified value number.
comment|/// The LiveRanges in RHS are allowed to overlap with LiveRanges in the
comment|/// current interval, it will replace the value numbers of the overlaped
comment|/// live ranges with the specified value number.
name|void
name|MergeRangesInAsValue
parameter_list|(
specifier|const
name|LiveInterval
modifier|&
name|RHS
parameter_list|,
name|VNInfo
modifier|*
name|LHSValNo
parameter_list|)
function_decl|;
comment|/// MergeValueInAsValue - Merge all of the live ranges of a specific val#
comment|/// in RHS into this live interval as the specified value number.
comment|/// The LiveRanges in RHS are allowed to overlap with LiveRanges in the
comment|/// current interval, but only if the overlapping LiveRanges have the
comment|/// specified value number.
name|void
name|MergeValueInAsValue
parameter_list|(
specifier|const
name|LiveInterval
modifier|&
name|RHS
parameter_list|,
specifier|const
name|VNInfo
modifier|*
name|RHSValNo
parameter_list|,
name|VNInfo
modifier|*
name|LHSValNo
parameter_list|)
function_decl|;
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|ranges
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// beginIndex - Return the lowest numbered slot covered by interval.
name|SlotIndex
name|beginIndex
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|empty
argument_list|()
operator|&&
literal|"Call to beginIndex() on empty interval."
argument_list|)
block|;
return|return
name|ranges
operator|.
name|front
argument_list|()
operator|.
name|start
return|;
block|}
comment|/// endNumber - return the maximum point of the interval of the whole,
comment|/// exclusive.
name|SlotIndex
name|endIndex
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|empty
argument_list|()
operator|&&
literal|"Call to endIndex() on empty interval."
argument_list|)
block|;
return|return
name|ranges
operator|.
name|back
argument_list|()
operator|.
name|end
return|;
block|}
name|bool
name|expiredAt
argument_list|(
name|SlotIndex
name|index
argument_list|)
decl|const
block|{
return|return
name|index
operator|>=
name|endIndex
argument_list|()
return|;
block|}
name|bool
name|liveAt
argument_list|(
name|SlotIndex
name|index
argument_list|)
decl|const
block|{
name|const_iterator
name|r
init|=
name|find
argument_list|(
name|index
argument_list|)
decl_stmt|;
return|return
name|r
operator|!=
name|end
argument_list|()
operator|&&
name|r
operator|->
name|start
operator|<=
name|index
return|;
block|}
comment|/// killedAt - Return true if a live range ends at index. Note that the kill
comment|/// point is not contained in the half-open live range. It is usually the
comment|/// getDefIndex() slot following its last use.
name|bool
name|killedAt
argument_list|(
name|SlotIndex
name|index
argument_list|)
decl|const
block|{
name|const_iterator
name|r
init|=
name|find
argument_list|(
name|index
operator|.
name|getRegSlot
argument_list|(
name|true
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|r
operator|!=
name|end
argument_list|()
operator|&&
name|r
operator|->
name|end
operator|==
name|index
return|;
block|}
comment|/// getLiveRangeContaining - Return the live range that contains the
comment|/// specified index, or null if there is none.
specifier|const
name|LiveRange
modifier|*
name|getLiveRangeContaining
argument_list|(
name|SlotIndex
name|Idx
argument_list|)
decl|const
block|{
name|const_iterator
name|I
init|=
name|FindLiveRangeContaining
argument_list|(
name|Idx
argument_list|)
decl_stmt|;
return|return
name|I
operator|==
name|end
argument_list|()
condition|?
literal|0
else|:
operator|&
operator|*
name|I
return|;
block|}
comment|/// getLiveRangeContaining - Return the live range that contains the
comment|/// specified index, or null if there is none.
name|LiveRange
modifier|*
name|getLiveRangeContaining
parameter_list|(
name|SlotIndex
name|Idx
parameter_list|)
block|{
name|iterator
name|I
init|=
name|FindLiveRangeContaining
argument_list|(
name|Idx
argument_list|)
decl_stmt|;
return|return
name|I
operator|==
name|end
argument_list|()
condition|?
literal|0
else|:
operator|&
operator|*
name|I
return|;
block|}
comment|/// getVNInfoAt - Return the VNInfo that is live at Idx, or NULL.
name|VNInfo
modifier|*
name|getVNInfoAt
argument_list|(
name|SlotIndex
name|Idx
argument_list|)
decl|const
block|{
name|const_iterator
name|I
init|=
name|FindLiveRangeContaining
argument_list|(
name|Idx
argument_list|)
decl_stmt|;
return|return
name|I
operator|==
name|end
argument_list|()
condition|?
literal|0
else|:
name|I
operator|->
name|valno
return|;
block|}
comment|/// getVNInfoBefore - Return the VNInfo that is live up to but not
comment|/// necessarilly including Idx, or NULL. Use this to find the reaching def
comment|/// used by an instruction at this SlotIndex position.
name|VNInfo
modifier|*
name|getVNInfoBefore
argument_list|(
name|SlotIndex
name|Idx
argument_list|)
decl|const
block|{
name|const_iterator
name|I
init|=
name|FindLiveRangeContaining
argument_list|(
name|Idx
operator|.
name|getPrevSlot
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|I
operator|==
name|end
argument_list|()
condition|?
literal|0
else|:
name|I
operator|->
name|valno
return|;
block|}
comment|/// FindLiveRangeContaining - Return an iterator to the live range that
comment|/// contains the specified index, or end() if there is none.
name|iterator
name|FindLiveRangeContaining
parameter_list|(
name|SlotIndex
name|Idx
parameter_list|)
block|{
name|iterator
name|I
init|=
name|find
argument_list|(
name|Idx
argument_list|)
decl_stmt|;
return|return
name|I
operator|!=
name|end
argument_list|()
operator|&&
name|I
operator|->
name|start
operator|<=
name|Idx
condition|?
name|I
else|:
name|end
argument_list|()
return|;
block|}
name|const_iterator
name|FindLiveRangeContaining
argument_list|(
name|SlotIndex
name|Idx
argument_list|)
decl|const
block|{
name|const_iterator
name|I
init|=
name|find
argument_list|(
name|Idx
argument_list|)
decl_stmt|;
return|return
name|I
operator|!=
name|end
argument_list|()
operator|&&
name|I
operator|->
name|start
operator|<=
name|Idx
condition|?
name|I
else|:
name|end
argument_list|()
return|;
block|}
comment|/// overlaps - Return true if the intersection of the two live intervals is
comment|/// not empty.
name|bool
name|overlaps
argument_list|(
specifier|const
name|LiveInterval
operator|&
name|other
argument_list|)
decl|const
block|{
if|if
condition|(
name|other
operator|.
name|empty
argument_list|()
condition|)
return|return
name|false
return|;
return|return
name|overlapsFrom
argument_list|(
name|other
argument_list|,
name|other
operator|.
name|begin
argument_list|()
argument_list|)
return|;
block|}
comment|/// overlaps - Return true if the two intervals have overlapping segments
comment|/// that are not coalescable according to CP.
comment|///
comment|/// Overlapping segments where one interval is defined by a coalescable
comment|/// copy are allowed.
name|bool
name|overlaps
argument_list|(
specifier|const
name|LiveInterval
operator|&
name|Other
argument_list|,
specifier|const
name|CoalescerPair
operator|&
name|CP
argument_list|,
specifier|const
name|SlotIndexes
operator|&
argument_list|)
decl|const
decl_stmt|;
comment|/// overlaps - Return true if the live interval overlaps a range specified
comment|/// by [Start, End).
name|bool
name|overlaps
argument_list|(
name|SlotIndex
name|Start
argument_list|,
name|SlotIndex
name|End
argument_list|)
decl|const
decl_stmt|;
comment|/// overlapsFrom - Return true if the intersection of the two live intervals
comment|/// is not empty.  The specified iterator is a hint that we can begin
comment|/// scanning the Other interval starting at I.
name|bool
name|overlapsFrom
argument_list|(
specifier|const
name|LiveInterval
operator|&
name|other
argument_list|,
name|const_iterator
name|I
argument_list|)
decl|const
decl_stmt|;
comment|/// addRange - Add the specified LiveRange to this interval, merging
comment|/// intervals as appropriate.  This returns an iterator to the inserted live
comment|/// range (which may have grown since it was inserted.
name|iterator
name|addRange
parameter_list|(
name|LiveRange
name|LR
parameter_list|)
block|{
return|return
name|addRangeFrom
argument_list|(
name|LR
argument_list|,
name|ranges
operator|.
name|begin
argument_list|()
argument_list|)
return|;
block|}
comment|/// extendInBlock - If this interval is live before Kill in the basic block
comment|/// that starts at StartIdx, extend it to be live up to Kill, and return
comment|/// the value. If there is no live range before Kill, return NULL.
name|VNInfo
modifier|*
name|extendInBlock
parameter_list|(
name|SlotIndex
name|StartIdx
parameter_list|,
name|SlotIndex
name|Kill
parameter_list|)
function_decl|;
comment|/// join - Join two live intervals (this, and other) together.  This applies
comment|/// mappings to the value numbers in the LHS/RHS intervals as specified.  If
comment|/// the intervals are not joinable, this aborts.
name|void
name|join
argument_list|(
name|LiveInterval
operator|&
name|Other
argument_list|,
specifier|const
name|int
operator|*
name|ValNoAssignments
argument_list|,
specifier|const
name|int
operator|*
name|RHSValNoAssignments
argument_list|,
name|SmallVector
operator|<
name|VNInfo
operator|*
argument_list|,
literal|16
operator|>
operator|&
name|NewVNInfo
argument_list|,
name|MachineRegisterInfo
operator|*
name|MRI
argument_list|)
decl_stmt|;
comment|/// isInOneLiveRange - Return true if the range specified is entirely in the
comment|/// a single LiveRange of the live interval.
name|bool
name|isInOneLiveRange
argument_list|(
name|SlotIndex
name|Start
argument_list|,
name|SlotIndex
name|End
argument_list|)
decl|const
block|{
name|const_iterator
name|r
init|=
name|find
argument_list|(
name|Start
argument_list|)
decl_stmt|;
return|return
name|r
operator|!=
name|end
argument_list|()
operator|&&
name|r
operator|->
name|containsRange
argument_list|(
name|Start
argument_list|,
name|End
argument_list|)
return|;
block|}
comment|/// True iff this live range is a single segment that lies between the
comment|/// specified boundaries, exclusively. Vregs live across a backedge are not
comment|/// considered local. The boundaries are expected to lie within an extended
comment|/// basic block, so vregs that are not live out should contain no holes.
name|bool
name|isLocal
argument_list|(
name|SlotIndex
name|Start
argument_list|,
name|SlotIndex
name|End
argument_list|)
decl|const
block|{
return|return
name|beginIndex
argument_list|()
operator|>
name|Start
operator|.
name|getBaseIndex
argument_list|()
operator|&&
name|endIndex
argument_list|()
operator|<
name|End
operator|.
name|getBoundaryIndex
argument_list|()
return|;
block|}
comment|/// removeRange - Remove the specified range from this interval.  Note that
comment|/// the range must be a single LiveRange in its entirety.
name|void
name|removeRange
parameter_list|(
name|SlotIndex
name|Start
parameter_list|,
name|SlotIndex
name|End
parameter_list|,
name|bool
name|RemoveDeadValNo
init|=
name|false
parameter_list|)
function_decl|;
name|void
name|removeRange
parameter_list|(
name|LiveRange
name|LR
parameter_list|,
name|bool
name|RemoveDeadValNo
init|=
name|false
parameter_list|)
block|{
name|removeRange
argument_list|(
name|LR
operator|.
name|start
argument_list|,
name|LR
operator|.
name|end
argument_list|,
name|RemoveDeadValNo
argument_list|)
expr_stmt|;
block|}
comment|/// removeValNo - Remove all the ranges defined by the specified value#.
comment|/// Also remove the value# from value# list.
name|void
name|removeValNo
parameter_list|(
name|VNInfo
modifier|*
name|ValNo
parameter_list|)
function_decl|;
comment|/// getSize - Returns the sum of sizes of all the LiveRange's.
comment|///
name|unsigned
name|getSize
argument_list|()
specifier|const
expr_stmt|;
comment|/// Returns true if the live interval is zero length, i.e. no live ranges
comment|/// span instructions. It doesn't pay to spill such an interval.
name|bool
name|isZeroLength
argument_list|(
name|SlotIndexes
operator|*
name|Indexes
argument_list|)
decl|const
block|{
for|for
control|(
name|const_iterator
name|i
init|=
name|begin
argument_list|()
init|,
name|e
init|=
name|end
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|Indexes
operator|->
name|getNextNonNullIndex
argument_list|(
name|i
operator|->
name|start
argument_list|)
operator|.
name|getBaseIndex
argument_list|()
operator|<
name|i
operator|->
name|end
operator|.
name|getBaseIndex
argument_list|()
condition|)
return|return
name|false
return|;
return|return
name|true
return|;
block|}
comment|/// isSpillable - Can this interval be spilled?
name|bool
name|isSpillable
argument_list|()
specifier|const
block|{
return|return
name|weight
operator|!=
name|HUGE_VALF
return|;
block|}
comment|/// markNotSpillable - Mark interval as not spillable
name|void
name|markNotSpillable
parameter_list|()
block|{
name|weight
operator|=
name|HUGE_VALF
expr_stmt|;
block|}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|LiveInterval
operator|&
name|other
operator|)
specifier|const
block|{
specifier|const
name|SlotIndex
operator|&
name|thisIndex
operator|=
name|beginIndex
argument_list|()
block|;
specifier|const
name|SlotIndex
operator|&
name|otherIndex
operator|=
name|other
operator|.
name|beginIndex
argument_list|()
block|;
return|return
operator|(
name|thisIndex
operator|<
name|otherIndex
operator|||
operator|(
name|thisIndex
operator|==
name|otherIndex
operator|&&
name|reg
operator|<
name|other
operator|.
name|reg
operator|)
operator|)
return|;
block|}
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Walk the interval and assert if any invariants fail to hold.
comment|///
comment|/// Note that this is a no-op when asserts are disabled.
ifdef|#
directive|ifdef
name|NDEBUG
name|void
name|verify
argument_list|()
specifier|const
block|{}
else|#
directive|else
name|void
name|verify
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
name|private
label|:
name|Ranges
operator|::
name|iterator
name|addRangeFrom
argument_list|(
argument|LiveRange LR
argument_list|,
argument|Ranges::iterator From
argument_list|)
expr_stmt|;
name|void
name|extendIntervalEndTo
argument_list|(
name|Ranges
operator|::
name|iterator
name|I
argument_list|,
name|SlotIndex
name|NewEnd
argument_list|)
decl_stmt|;
name|Ranges
operator|::
name|iterator
name|extendIntervalStartTo
argument_list|(
argument|Ranges::iterator I
argument_list|,
argument|SlotIndex NewStr
argument_list|)
expr_stmt|;
name|void
name|markValNoForDeletion
parameter_list|(
name|VNInfo
modifier|*
name|V
parameter_list|)
function_decl|;
name|LiveInterval
modifier|&
name|operator
init|=
operator|(
specifier|const
name|LiveInterval
operator|&
name|rhs
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
block|}
empty_stmt|;
specifier|inline
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|LiveInterval
operator|&
name|LI
operator|)
block|{
name|LI
operator|.
name|print
argument_list|(
name|OS
argument_list|)
block|;
return|return
name|OS
return|;
block|}
comment|/// Helper class for performant LiveInterval bulk updates.
comment|///
comment|/// Calling LiveInterval::addRange() repeatedly can be expensive on large
comment|/// live ranges because segments after the insertion point may need to be
comment|/// shifted. The LiveRangeUpdater class can defer the shifting when adding
comment|/// many segments in order.
comment|///
comment|/// The LiveInterval will be in an invalid state until flush() is called.
name|class
name|LiveRangeUpdater
block|{
name|LiveInterval
modifier|*
name|LI
decl_stmt|;
name|SlotIndex
name|LastStart
decl_stmt|;
name|LiveInterval
operator|::
name|iterator
name|WriteI
expr_stmt|;
name|LiveInterval
operator|::
name|iterator
name|ReadI
expr_stmt|;
name|SmallVector
operator|<
name|LiveRange
operator|,
literal|16
operator|>
name|Spills
expr_stmt|;
name|void
name|mergeSpills
parameter_list|()
function_decl|;
name|public
label|:
comment|/// Create a LiveRangeUpdater for adding segments to LI.
comment|/// LI will temporarily be in an invalid state until flush() is called.
name|LiveRangeUpdater
argument_list|(
name|LiveInterval
operator|*
name|li
operator|=
literal|0
argument_list|)
operator|:
name|LI
argument_list|(
argument|li
argument_list|)
block|{}
operator|~
name|LiveRangeUpdater
argument_list|()
block|{
name|flush
argument_list|()
block|; }
comment|/// Add a segment to LI and coalesce when possible, just like LI.addRange().
comment|/// Segments should be added in increasing start order for best performance.
name|void
name|add
argument_list|(
name|LiveRange
argument_list|)
expr_stmt|;
name|void
name|add
parameter_list|(
name|SlotIndex
name|Start
parameter_list|,
name|SlotIndex
name|End
parameter_list|,
name|VNInfo
modifier|*
name|VNI
parameter_list|)
block|{
name|add
argument_list|(
name|LiveRange
argument_list|(
name|Start
argument_list|,
name|End
argument_list|,
name|VNI
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// Return true if the LI is currently in an invalid state, and flush()
comment|/// needs to be called.
name|bool
name|isDirty
argument_list|()
specifier|const
block|{
return|return
name|LastStart
operator|.
name|isValid
argument_list|()
return|;
block|}
comment|/// Flush the updater state to LI so it is valid and contains all added
comment|/// segments.
name|void
name|flush
parameter_list|()
function_decl|;
comment|/// Select a different destination live range.
name|void
name|setDest
parameter_list|(
name|LiveInterval
modifier|*
name|li
parameter_list|)
block|{
if|if
condition|(
name|LI
operator|!=
name|li
operator|&&
name|isDirty
argument_list|()
condition|)
name|flush
argument_list|()
expr_stmt|;
name|LI
operator|=
name|li
expr_stmt|;
block|}
comment|/// Get the current destination live range.
name|LiveInterval
operator|*
name|getDest
argument_list|()
specifier|const
block|{
return|return
name|LI
return|;
block|}
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
specifier|inline
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|LiveRangeUpdater
operator|&
name|X
operator|)
block|{
name|X
operator|.
name|print
argument_list|(
name|OS
argument_list|)
block|;
return|return
name|OS
return|;
block|}
comment|/// LiveRangeQuery - Query information about a live range around a given
comment|/// instruction. This class hides the implementation details of live ranges,
comment|/// and it should be used as the primary interface for examining live ranges
comment|/// around instructions.
comment|///
name|class
name|LiveRangeQuery
block|{
name|VNInfo
modifier|*
name|EarlyVal
decl_stmt|;
name|VNInfo
modifier|*
name|LateVal
decl_stmt|;
name|SlotIndex
name|EndPoint
decl_stmt|;
name|bool
name|Kill
decl_stmt|;
name|public
label|:
comment|/// Create a LiveRangeQuery for the given live range and instruction index.
comment|/// The sub-instruction slot of Idx doesn't matter, only the instruction it
comment|/// refers to is considered.
name|LiveRangeQuery
argument_list|(
argument|const LiveInterval&LI
argument_list|,
argument|SlotIndex Idx
argument_list|)
block|:
name|EarlyVal
argument_list|(
literal|0
argument_list|)
operator|,
name|LateVal
argument_list|(
literal|0
argument_list|)
operator|,
name|Kill
argument_list|(
argument|false
argument_list|)
block|{
comment|// Find the segment that enters the instruction.
name|LiveInterval
operator|::
name|const_iterator
name|I
operator|=
name|LI
operator|.
name|find
argument_list|(
name|Idx
operator|.
name|getBaseIndex
argument_list|()
argument_list|)
block|;
name|LiveInterval
operator|::
name|const_iterator
name|E
operator|=
name|LI
operator|.
name|end
argument_list|()
block|;
if|if
condition|(
name|I
operator|==
name|E
condition|)
return|return;
comment|// Is this an instruction live-in segment?
comment|// If Idx is the start index of a basic block, include live-in segments
comment|// that start at Idx.getBaseIndex().
if|if
condition|(
name|I
operator|->
name|start
operator|<=
name|Idx
operator|.
name|getBaseIndex
argument_list|()
condition|)
block|{
name|EarlyVal
operator|=
name|I
operator|->
name|valno
expr_stmt|;
name|EndPoint
operator|=
name|I
operator|->
name|end
expr_stmt|;
comment|// Move to the potentially live-out segment.
if|if
condition|(
name|SlotIndex
operator|::
name|isSameInstr
argument_list|(
name|Idx
argument_list|,
name|I
operator|->
name|end
argument_list|)
condition|)
block|{
name|Kill
operator|=
name|true
expr_stmt|;
if|if
condition|(
operator|++
name|I
operator|==
name|E
condition|)
return|return;
block|}
comment|// Special case: A PHIDef value can have its def in the middle of a
comment|// segment if the value happens to be live out of the layout
comment|// predecessor.
comment|// Such a value is not live-in.
if|if
condition|(
name|EarlyVal
operator|->
name|def
operator|==
name|Idx
operator|.
name|getBaseIndex
argument_list|()
condition|)
name|EarlyVal
operator|=
literal|0
expr_stmt|;
block|}
comment|// I now points to the segment that may be live-through, or defined by
comment|// this instr. Ignore segments starting after the current instr.
if|if
condition|(
name|SlotIndex
operator|::
name|isEarlierInstr
argument_list|(
name|Idx
argument_list|,
name|I
operator|->
name|start
argument_list|)
condition|)
return|return;
name|LateVal
operator|=
name|I
operator|->
name|valno
expr_stmt|;
name|EndPoint
operator|=
name|I
operator|->
name|end
expr_stmt|;
block|}
comment|/// Return the value that is live-in to the instruction. This is the value
comment|/// that will be read by the instruction's use operands. Return NULL if no
comment|/// value is live-in.
name|VNInfo
operator|*
name|valueIn
argument_list|()
specifier|const
block|{
return|return
name|EarlyVal
return|;
block|}
comment|/// Return true if the live-in value is killed by this instruction. This
comment|/// means that either the live range ends at the instruction, or it changes
comment|/// value.
name|bool
name|isKill
argument_list|()
specifier|const
block|{
return|return
name|Kill
return|;
block|}
comment|/// Return true if this instruction has a dead def.
name|bool
name|isDeadDef
argument_list|()
specifier|const
block|{
return|return
name|EndPoint
operator|.
name|isDead
argument_list|()
return|;
block|}
comment|/// Return the value leaving the instruction, if any. This can be a
comment|/// live-through value, or a live def. A dead def returns NULL.
name|VNInfo
operator|*
name|valueOut
argument_list|()
specifier|const
block|{
return|return
name|isDeadDef
argument_list|()
operator|?
literal|0
operator|:
name|LateVal
return|;
block|}
comment|/// Return the value defined by this instruction, if any. This includes
comment|/// dead defs, it is the value created by the instruction's def operands.
name|VNInfo
operator|*
name|valueDefined
argument_list|()
specifier|const
block|{
return|return
name|EarlyVal
operator|==
name|LateVal
operator|?
literal|0
operator|:
name|LateVal
return|;
block|}
comment|/// Return the end point of the last live range segment to interact with
comment|/// the instruction, if any.
comment|///
comment|/// The end point is an invalid SlotIndex only if the live range doesn't
comment|/// intersect the instruction at all.
comment|///
comment|/// The end point may be at or past the end of the instruction's basic
comment|/// block. That means the value was live out of the block.
name|SlotIndex
name|endPoint
argument_list|()
specifier|const
block|{
return|return
name|EndPoint
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// ConnectedVNInfoEqClasses - Helper class that can divide VNInfos in a
end_comment

begin_comment
comment|/// LiveInterval into equivalence clases of connected components. A
end_comment

begin_comment
comment|/// LiveInterval that has multiple connected components can be broken into
end_comment

begin_comment
comment|/// multiple LiveIntervals.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Given a LiveInterval that may have multiple connected components, run:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   unsigned numComps = ConEQ.Classify(LI);
end_comment

begin_comment
comment|///   if (numComps> 1) {
end_comment

begin_comment
comment|///     // allocate numComps-1 new LiveIntervals into LIS[1..]
end_comment

begin_comment
comment|///     ConEQ.Distribute(LIS);
end_comment

begin_comment
comment|/// }
end_comment

begin_decl_stmt
name|class
name|ConnectedVNInfoEqClasses
block|{
name|LiveIntervals
modifier|&
name|LIS
decl_stmt|;
name|IntEqClasses
name|EqClass
decl_stmt|;
comment|// Note that values a and b are connected.
name|void
name|Connect
parameter_list|(
name|unsigned
name|a
parameter_list|,
name|unsigned
name|b
parameter_list|)
function_decl|;
name|unsigned
name|Renumber
parameter_list|()
function_decl|;
name|public
label|:
name|explicit
name|ConnectedVNInfoEqClasses
argument_list|(
name|LiveIntervals
operator|&
name|lis
argument_list|)
operator|:
name|LIS
argument_list|(
argument|lis
argument_list|)
block|{}
comment|/// Classify - Classify the values in LI into connected components.
comment|/// Return the number of connected components.
name|unsigned
name|Classify
argument_list|(
specifier|const
name|LiveInterval
operator|*
name|LI
argument_list|)
expr_stmt|;
comment|/// getEqClass - Classify creates equivalence classes numbered 0..N. Return
comment|/// the equivalence class assigned the VNI.
name|unsigned
name|getEqClass
argument_list|(
specifier|const
name|VNInfo
operator|*
name|VNI
argument_list|)
decl|const
block|{
return|return
name|EqClass
index|[
name|VNI
operator|->
name|id
index|]
return|;
block|}
comment|/// Distribute - Distribute values in LIV[0] into a separate LiveInterval
comment|/// for each connected component. LIV must have a LiveInterval for each
comment|/// connected component. The LiveIntervals in Liv[1..] must be empty.
comment|/// Instructions using LIV[0] are rewritten.
name|void
name|Distribute
parameter_list|(
name|LiveInterval
modifier|*
name|LIV
index|[]
parameter_list|,
name|MachineRegisterInfo
modifier|&
name|MRI
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

