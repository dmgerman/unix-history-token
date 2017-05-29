begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/CodeGen/LiveInterval.h - Interval representation ----*- C++ -*-===//
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
comment|// live range for register v if there is no instruction with number j'>= j
end_comment

begin_comment
comment|// such that v is live at j' and there is no instruction with number i'< i such
end_comment

begin_comment
comment|// that v is live at i'. In this implementation ranges can have holes,
end_comment

begin_comment
comment|// i.e. a range might look like [1,20), [50,65), [1000,1001).  Each
end_comment

begin_comment
comment|// individual segment is represented as an instance of LiveRange::Segment,
end_comment

begin_comment
comment|// and the whole range is represented as an instance of LiveRange.
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
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IntEqClasses.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/iterator_range.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SlotIndexes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/LaneBitmask.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MathExtras.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_include
include|#
directive|include
file|<tuple>
end_include

begin_include
include|#
directive|include
file|<utility>
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
name|MachineRegisterInfo
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
name|using
name|Allocator
init|=
name|BumpPtrAllocator
decl_stmt|;
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
block|{}
comment|/// VNInfo constructor, copies values from orig, except for the value number.
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
block|{}
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
comment|/// PHI instructions may have been eliminated).
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
comment|/// Result of a LiveRange query. This class hides the implementation details
comment|/// of live ranges, and it should be used as the primary interface for
comment|/// examining live ranges around instructions.
name|class
name|LiveQueryResult
block|{
name|VNInfo
modifier|*
specifier|const
name|EarlyVal
decl_stmt|;
name|VNInfo
modifier|*
specifier|const
name|LateVal
decl_stmt|;
specifier|const
name|SlotIndex
name|EndPoint
decl_stmt|;
specifier|const
name|bool
name|Kill
decl_stmt|;
name|public
label|:
name|LiveQueryResult
argument_list|(
argument|VNInfo *EarlyVal
argument_list|,
argument|VNInfo *LateVal
argument_list|,
argument|SlotIndex EndPoint
argument_list|,
argument|bool Kill
argument_list|)
block|:
name|EarlyVal
argument_list|(
name|EarlyVal
argument_list|)
operator|,
name|LateVal
argument_list|(
name|LateVal
argument_list|)
operator|,
name|EndPoint
argument_list|(
name|EndPoint
argument_list|)
operator|,
name|Kill
argument_list|(
argument|Kill
argument_list|)
block|{}
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
name|nullptr
operator|:
name|LateVal
return|;
block|}
comment|/// Returns the value alive at the end of the instruction, if any. This can
comment|/// be a live-through value, a live def or a dead def.
name|VNInfo
operator|*
name|valueOutOrDead
argument_list|()
specifier|const
block|{
return|return
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
name|nullptr
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
empty_stmt|;
comment|/// This class represents the liveness of a register, stack slot, etc.
comment|/// It manages an ordered list of Segment objects.
comment|/// The Segments are organized in a static single assignment form: At places
comment|/// where a new value is defined or different values reach a CFG join a new
comment|/// segment with a new value number is used.
name|class
name|LiveRange
block|{
name|public
label|:
comment|/// This represents a simple continuous liveness interval for a value.
comment|/// The start point is inclusive, the end point exclusive. These intervals
comment|/// are rendered as [start,end).
struct|struct
name|Segment
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
init|=
name|nullptr
decl_stmt|;
comment|// identifier for the value contained in this
comment|// segment.
name|Segment
argument_list|()
operator|=
expr|default
expr_stmt|;
name|Segment
argument_list|(
argument|SlotIndex S
argument_list|,
argument|SlotIndex E
argument_list|,
argument|VNInfo *V
argument_list|)
block|:
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
literal|"Cannot create empty or backwards segment"
argument_list|)
block|;       }
comment|/// Return true if the index is covered by this segment.
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
comment|/// Return true if the given interval, [S, E), is covered by this segment.
name|bool
name|containsInterval
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
name|Segment
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|std
operator|::
name|tie
argument_list|(
name|start
argument_list|,
name|end
argument_list|)
operator|<
name|std
operator|::
name|tie
argument_list|(
name|Other
operator|.
name|start
argument_list|,
name|Other
operator|.
name|end
argument_list|)
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Segment
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|start
operator|==
name|Other
operator|.
name|start
operator|&&
name|end
operator|==
name|Other
operator|.
name|end
return|;
block|}
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
block|}
struct|;
name|using
name|Segments
init|=
name|SmallVector
operator|<
name|Segment
decl_stmt|, 2>;
name|using
name|VNInfoList
init|=
name|SmallVector
operator|<
name|VNInfo
operator|*
decl_stmt|, 2>;
name|Segments
name|segments
decl_stmt|;
comment|// the liveness segments
name|VNInfoList
name|valnos
decl_stmt|;
comment|// value#'s
comment|// The segment set is used temporarily to accelerate initial computation
comment|// of live ranges of physical registers in computeRegUnitRange.
comment|// After that the set is flushed to the segment vector and deleted.
name|using
name|SegmentSet
init|=
name|std
operator|::
name|set
operator|<
name|Segment
operator|>
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|SegmentSet
operator|>
name|segmentSet
expr_stmt|;
name|using
name|iterator
init|=
name|Segments
operator|::
name|iterator
decl_stmt|;
name|using
name|const_iterator
init|=
name|Segments
operator|::
name|const_iterator
decl_stmt|;
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|segments
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
name|segments
operator|.
name|end
argument_list|()
return|;
block|}
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|segments
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
name|segments
operator|.
name|end
argument_list|()
return|;
block|}
name|using
name|vni_iterator
init|=
name|VNInfoList
operator|::
name|iterator
decl_stmt|;
name|using
name|const_vni_iterator
init|=
name|VNInfoList
operator|::
name|const_iterator
decl_stmt|;
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
comment|/// Constructs a new LiveRange object.
name|LiveRange
argument_list|(
argument|bool UseSegmentSet = false
argument_list|)
block|:
name|segmentSet
argument_list|(
argument|UseSegmentSet ? llvm::make_unique<SegmentSet>()                                    : nullptr
argument_list|)
block|{}
comment|/// Constructs a new LiveRange object by copying segments and valnos from
comment|/// another LiveRange.
name|LiveRange
argument_list|(
argument|const LiveRange&Other
argument_list|,
argument|BumpPtrAllocator&Allocator
argument_list|)
block|{
name|assert
argument_list|(
name|Other
operator|.
name|segmentSet
operator|==
name|nullptr
operator|&&
literal|"Copying of LiveRanges with active SegmentSets is not supported"
argument_list|)
expr_stmt|;
name|assign
argument_list|(
name|Other
argument_list|,
name|Allocator
argument_list|)
expr_stmt|;
block|}
comment|/// Copies values numbers and live segments from \p Other into this range.
name|void
name|assign
parameter_list|(
specifier|const
name|LiveRange
modifier|&
name|Other
parameter_list|,
name|BumpPtrAllocator
modifier|&
name|Allocator
parameter_list|)
block|{
if|if
condition|(
name|this
operator|==
operator|&
name|Other
condition|)
return|return;
name|assert
argument_list|(
name|Other
operator|.
name|segmentSet
operator|==
name|nullptr
operator|&&
literal|"Copying of LiveRanges with active SegmentSets is not supported"
argument_list|)
expr_stmt|;
comment|// Duplicate valnos.
for|for
control|(
specifier|const
name|VNInfo
modifier|*
name|VNI
range|:
name|Other
operator|.
name|valnos
control|)
name|createValueCopy
argument_list|(
name|VNI
argument_list|,
name|Allocator
argument_list|)
expr_stmt|;
comment|// Now we can copy segments and remap their valnos.
for|for
control|(
specifier|const
name|Segment
modifier|&
name|S
range|:
name|Other
operator|.
name|segments
control|)
name|segments
operator|.
name|push_back
argument_list|(
name|Segment
argument_list|(
name|S
operator|.
name|start
argument_list|,
name|S
operator|.
name|end
argument_list|,
name|valnos
index|[
name|S
operator|.
name|valno
operator|->
name|id
index|]
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// advanceTo - Advance the specified iterator to point to the Segment
comment|/// containing the specified position, or end() if the position is past the
comment|/// end of the range.  If no Segment contains this position, but the
comment|/// position is in a hole, this method returns an iterator pointing to the
comment|/// Segment immediately after the hole.
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
name|const_iterator
name|advanceTo
argument_list|(
name|const_iterator
name|I
argument_list|,
name|SlotIndex
name|Pos
argument_list|)
decl|const
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
comment|/// find - Return an iterator pointing to the first segment that ends after
comment|/// Pos, or end(). This is the same as advanceTo(begin(), Pos), but faster
comment|/// when searching large ranges.
comment|///
comment|/// If Pos is contained in a Segment, that segment is returned.
comment|/// If Pos is in a hole, the following Segment is returned.
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
name|LiveRange
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
name|segments
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|size_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|segments
operator|.
name|size
argument_list|()
return|;
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
comment|/// containsValue - Returns true if VNI belongs to this range.
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
comment|/// createDeadDef - Make sure the range has a value defined at Def.
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
comment|/// Create a def of value @p VNI. Return @p VNI. If there already exists
comment|/// a definition at VNI->def, the value defined there must be @p VNI.
name|VNInfo
modifier|*
name|createDeadDef
parameter_list|(
name|VNInfo
modifier|*
name|VNI
parameter_list|)
function_decl|;
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
parameter_list|()
function_decl|;
comment|/// MergeValueNumberInto - This method is called when two value numbers
comment|/// are found to be equivalent.  This eliminates V1, replacing all
comment|/// segments with the V1 value number with the V2 value number.  This can
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
comment|/// Merge all of the live segments of a specific val# in RHS into this live
comment|/// range as the specified value number. The segments in RHS are allowed
comment|/// to overlap with segments in the current range, it will replace the
comment|/// value numbers of the overlaped live segments with the specified value
comment|/// number.
name|void
name|MergeSegmentsInAsValue
parameter_list|(
specifier|const
name|LiveRange
modifier|&
name|RHS
parameter_list|,
name|VNInfo
modifier|*
name|LHSValNo
parameter_list|)
function_decl|;
comment|/// MergeValueInAsValue - Merge all of the segments of a specific val#
comment|/// in RHS into this live range as the specified value number.
comment|/// The segments in RHS are allowed to overlap with segments in the
comment|/// current range, but only if the overlapping segments have the
comment|/// specified value number.
name|void
name|MergeValueInAsValue
parameter_list|(
specifier|const
name|LiveRange
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
name|segments
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// beginIndex - Return the lowest numbered slot covered.
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
literal|"Call to beginIndex() on empty range."
argument_list|)
block|;
return|return
name|segments
operator|.
name|front
argument_list|()
operator|.
name|start
return|;
block|}
comment|/// endNumber - return the maximum point of the range of the whole,
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
literal|"Call to endIndex() on empty range."
argument_list|)
block|;
return|return
name|segments
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
comment|/// Return the segment that contains the specified index, or null if there
comment|/// is none.
specifier|const
name|Segment
modifier|*
name|getSegmentContaining
argument_list|(
name|SlotIndex
name|Idx
argument_list|)
decl|const
block|{
name|const_iterator
name|I
init|=
name|FindSegmentContaining
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
name|nullptr
else|:
operator|&
operator|*
name|I
return|;
block|}
comment|/// Return the live segment that contains the specified index, or null if
comment|/// there is none.
name|Segment
modifier|*
name|getSegmentContaining
parameter_list|(
name|SlotIndex
name|Idx
parameter_list|)
block|{
name|iterator
name|I
init|=
name|FindSegmentContaining
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
name|nullptr
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
name|FindSegmentContaining
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
name|nullptr
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
name|FindSegmentContaining
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
name|nullptr
else|:
name|I
operator|->
name|valno
return|;
block|}
comment|/// Return an iterator to the segment that contains the specified index, or
comment|/// end() if there is none.
name|iterator
name|FindSegmentContaining
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
name|FindSegmentContaining
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
comment|/// overlaps - Return true if the intersection of the two live ranges is
comment|/// not empty.
name|bool
name|overlaps
argument_list|(
specifier|const
name|LiveRange
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
comment|/// overlaps - Return true if the two ranges have overlapping segments
comment|/// that are not coalescable according to CP.
comment|///
comment|/// Overlapping segments where one range is defined by a coalescable
comment|/// copy are allowed.
name|bool
name|overlaps
argument_list|(
specifier|const
name|LiveRange
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
comment|/// overlaps - Return true if the live range overlaps an interval specified
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
comment|/// overlapsFrom - Return true if the intersection of the two live ranges
comment|/// is not empty.  The specified iterator is a hint that we can begin
comment|/// scanning the Other range starting at I.
name|bool
name|overlapsFrom
argument_list|(
specifier|const
name|LiveRange
operator|&
name|Other
argument_list|,
name|const_iterator
name|I
argument_list|)
decl|const
decl_stmt|;
comment|/// Returns true if all segments of the @p Other live range are completely
comment|/// covered by this live range.
comment|/// Adjacent live ranges do not affect the covering:the liverange
comment|/// [1,5](5,10] covers (3,7].
name|bool
name|covers
argument_list|(
specifier|const
name|LiveRange
operator|&
name|Other
argument_list|)
decl|const
decl_stmt|;
comment|/// Add the specified Segment to this range, merging segments as
comment|/// appropriate.  This returns an iterator to the inserted segment (which
comment|/// may have grown since it was inserted).
name|iterator
name|addSegment
parameter_list|(
name|Segment
name|S
parameter_list|)
function_decl|;
comment|/// Attempt to extend a value defined after @p StartIdx to include @p Use.
comment|/// Both @p StartIdx and @p Use should be in the same basic block. In case
comment|/// of subranges, an extension could be prevented by an explicit "undef"
comment|/// caused by a<def,read-undef> on a non-overlapping lane. The list of
comment|/// location of such "undefs" should be provided in @p Undefs.
comment|/// The return value is a pair: the first element is VNInfo of the value
comment|/// that was extended (possibly nullptr), the second is a boolean value
comment|/// indicating whether an "undef" was encountered.
comment|/// If this range is live before @p Use in the basic block that starts at
comment|/// @p StartIdx, and there is no intervening "undef", extend it to be live
comment|/// up to @p Use, and return the pair {value, false}. If there is no
comment|/// segment before @p Use and there is no "undef" between @p StartIdx and
comment|/// @p Use, return {nullptr, false}. If there is an "undef" before @p Use,
comment|/// return {nullptr, true}.
name|std
operator|::
name|pair
operator|<
name|VNInfo
operator|*
operator|,
name|bool
operator|>
name|extendInBlock
argument_list|(
argument|ArrayRef<SlotIndex> Undefs
argument_list|,
argument|SlotIndex StartIdx
argument_list|,
argument|SlotIndex Use
argument_list|)
expr_stmt|;
comment|/// Simplified version of the above "extendInBlock", which assumes that
comment|/// no register lanes are undefined by<def,read-undef> operands.
comment|/// If this range is live before @p Use in the basic block that starts
comment|/// at @p StartIdx, extend it to be live up to @p Use, and return the
comment|/// value. If there is no segment before @p Use, return nullptr.
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
comment|/// join - Join two live ranges (this, and other) together.  This applies
comment|/// mappings to the value numbers in the LHS/RHS ranges as specified.  If
comment|/// the ranges are not joinable, this aborts.
name|void
name|join
argument_list|(
name|LiveRange
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
name|SmallVectorImpl
operator|<
name|VNInfo
operator|*
operator|>
operator|&
name|NewVNInfo
argument_list|)
decl_stmt|;
comment|/// True iff this segment is a single segment that lies between the
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
comment|/// Remove the specified segment from this range.  Note that the segment
comment|/// must be a single Segment in its entirety.
name|void
name|removeSegment
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
name|removeSegment
parameter_list|(
name|Segment
name|S
parameter_list|,
name|bool
name|RemoveDeadValNo
init|=
name|false
parameter_list|)
block|{
name|removeSegment
argument_list|(
name|S
operator|.
name|start
argument_list|,
name|S
operator|.
name|end
argument_list|,
name|RemoveDeadValNo
argument_list|)
expr_stmt|;
block|}
comment|/// Remove segment pointed to by iterator @p I from this range.  This does
comment|/// not remove dead value numbers.
name|iterator
name|removeSegment
parameter_list|(
name|iterator
name|I
parameter_list|)
block|{
return|return
name|segments
operator|.
name|erase
argument_list|(
name|I
argument_list|)
return|;
block|}
comment|/// Query Liveness at Idx.
comment|/// The sub-instruction slot of Idx doesn't matter, only the instruction
comment|/// it refers to is considered.
name|LiveQueryResult
name|Query
argument_list|(
name|SlotIndex
name|Idx
argument_list|)
decl|const
block|{
comment|// Find the segment that enters the instruction.
name|const_iterator
name|I
init|=
name|find
argument_list|(
name|Idx
operator|.
name|getBaseIndex
argument_list|()
argument_list|)
decl_stmt|;
name|const_iterator
name|E
init|=
name|end
argument_list|()
decl_stmt|;
if|if
condition|(
name|I
operator|==
name|E
condition|)
return|return
name|LiveQueryResult
argument_list|(
name|nullptr
argument_list|,
name|nullptr
argument_list|,
name|SlotIndex
argument_list|()
argument_list|,
name|false
argument_list|)
return|;
comment|// Is this an instruction live-in segment?
comment|// If Idx is the start index of a basic block, include live-in segments
comment|// that start at Idx.getBaseIndex().
name|VNInfo
modifier|*
name|EarlyVal
init|=
name|nullptr
decl_stmt|;
name|VNInfo
modifier|*
name|LateVal
init|=
name|nullptr
decl_stmt|;
name|SlotIndex
name|EndPoint
decl_stmt|;
name|bool
name|Kill
init|=
name|false
decl_stmt|;
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
return|return
name|LiveQueryResult
argument_list|(
name|EarlyVal
argument_list|,
name|LateVal
argument_list|,
name|EndPoint
argument_list|,
name|Kill
argument_list|)
return|;
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
name|nullptr
expr_stmt|;
block|}
comment|// I now points to the segment that may be live-through, or defined by
comment|// this instr. Ignore segments starting after the current instr.
if|if
condition|(
operator|!
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
block|{
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
return|return
name|LiveQueryResult
argument_list|(
name|EarlyVal
argument_list|,
name|LateVal
argument_list|,
name|EndPoint
argument_list|,
name|Kill
argument_list|)
return|;
block|}
comment|/// removeValNo - Remove all the segments defined by the specified value#.
comment|/// Also remove the value# from value# list.
name|void
name|removeValNo
parameter_list|(
name|VNInfo
modifier|*
name|ValNo
parameter_list|)
function_decl|;
comment|/// Returns true if the live range is zero length, i.e. no live segments
comment|/// span instructions. It doesn't pay to spill such a range.
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
specifier|const
name|Segment
modifier|&
name|S
range|:
name|segments
control|)
if|if
condition|(
name|Indexes
operator|->
name|getNextNonNullIndex
argument_list|(
name|S
operator|.
name|start
argument_list|)
operator|.
name|getBaseIndex
argument_list|()
operator|<
name|S
operator|.
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
comment|// Returns true if any segment in the live range contains any of the
comment|// provided slot indexes.  Slots which occur in holes between
comment|// segments will not cause the function to return true.
name|bool
name|isLiveAtIndexes
argument_list|(
name|ArrayRef
operator|<
name|SlotIndex
operator|>
name|Slots
argument_list|)
decl|const
decl_stmt|;
name|bool
name|operator
operator|<
operator|(
specifier|const
name|LiveRange
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
name|thisIndex
operator|<
name|otherIndex
return|;
block|}
comment|/// Returns true if there is an explicit "undef" between @p Begin
comment|/// @p End.
name|bool
name|isUndefIn
argument_list|(
name|ArrayRef
operator|<
name|SlotIndex
operator|>
name|Undefs
argument_list|,
name|SlotIndex
name|Begin
argument_list|,
name|SlotIndex
name|End
argument_list|)
decl|const
block|{
return|return
name|std
operator|::
name|any_of
argument_list|(
argument|Undefs.begin()
argument_list|,
argument|Undefs.end()
argument_list|,
argument|[Begin
argument_list|,
argument|End] (SlotIndex Idx) -> bool {                   return Begin<= Idx&& Idx< End;                 }
argument_list|)
return|;
block|}
comment|/// Flush segment set into the regular segment vector.
comment|/// The method is to be called after the live range
comment|/// has been created, if use of the segment set was
comment|/// activated in the constructor of the live range.
name|void
name|flushSegmentSet
parameter_list|()
function_decl|;
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
comment|/// \brief Walk the range and assert if any invariants fail to hold.
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
name|protected
label|:
comment|/// Append a segment to the list of segments.
name|void
name|append
argument_list|(
specifier|const
name|LiveRange
operator|::
name|Segment
name|S
argument_list|)
decl_stmt|;
name|private
label|:
name|friend
name|class
name|LiveRangeUpdater
decl_stmt|;
name|void
name|addSegmentToSet
parameter_list|(
name|Segment
name|S
parameter_list|)
function_decl|;
name|void
name|markValNoForDeletion
parameter_list|(
name|VNInfo
modifier|*
name|V
parameter_list|)
function_decl|;
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
name|LiveRange
operator|&
name|LR
operator|)
block|{
name|LR
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
comment|/// LiveInterval - This class represents the liveness of a register,
comment|/// or stack slot.
name|class
name|LiveInterval
range|:
name|public
name|LiveRange
block|{
name|public
operator|:
name|using
name|super
operator|=
name|LiveRange
block|;
comment|/// A live range for subregisters. The LaneMask specifies which parts of the
comment|/// super register are covered by the interval.
comment|/// (@sa TargetRegisterInfo::getSubRegIndexLaneMask()).
name|class
name|SubRange
operator|:
name|public
name|LiveRange
block|{
name|public
operator|:
name|SubRange
operator|*
name|Next
operator|=
name|nullptr
block|;
name|LaneBitmask
name|LaneMask
block|;
comment|/// Constructs a new SubRange object.
name|SubRange
argument_list|(
argument|LaneBitmask LaneMask
argument_list|)
operator|:
name|LaneMask
argument_list|(
argument|LaneMask
argument_list|)
block|{}
comment|/// Constructs a new SubRange object by copying liveness from @p Other.
name|SubRange
argument_list|(
argument|LaneBitmask LaneMask
argument_list|,
argument|const LiveRange&Other
argument_list|,
argument|BumpPtrAllocator&Allocator
argument_list|)
operator|:
name|LiveRange
argument_list|(
name|Other
argument_list|,
name|Allocator
argument_list|)
block|,
name|LaneMask
argument_list|(
argument|LaneMask
argument_list|)
block|{}
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
block|;
name|void
name|dump
argument_list|()
specifier|const
block|;     }
block|;
name|private
operator|:
name|SubRange
operator|*
name|SubRanges
operator|=
name|nullptr
block|;
comment|///< Single linked list of subregister live
comment|/// ranges.
name|public
operator|:
specifier|const
name|unsigned
name|reg
block|;
comment|// the register or stack slot of this interval.
name|float
name|weight
block|;
comment|// weight of this interval
name|LiveInterval
argument_list|(
argument|unsigned Reg
argument_list|,
argument|float Weight
argument_list|)
operator|:
name|reg
argument_list|(
name|Reg
argument_list|)
block|,
name|weight
argument_list|(
argument|Weight
argument_list|)
block|{}
operator|~
name|LiveInterval
argument_list|()
block|{
name|clearSubRanges
argument_list|()
block|;     }
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SingleLinkedListIterator
block|{
name|T
operator|*
name|P
block|;
name|public
operator|:
name|SingleLinkedListIterator
operator|<
name|T
operator|>
operator|(
name|T
operator|*
name|P
operator|)
operator|:
name|P
argument_list|(
argument|P
argument_list|)
block|{}
name|SingleLinkedListIterator
operator|<
name|T
operator|>
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
name|P
operator|=
name|P
operator|->
name|Next
block|;
return|return
operator|*
name|this
return|;
block|}
name|SingleLinkedListIterator
operator|<
name|T
operator|>
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|SingleLinkedListIterator
name|res
operator|=
operator|*
name|this
block|;
operator|++
operator|*
name|this
block|;
return|return
name|res
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|SingleLinkedListIterator
operator|<
name|T
operator|>
operator|&
name|Other
operator|)
block|{
return|return
name|P
operator|!=
name|Other
operator|.
name|operator
operator|->
expr|(
block|)
block|;       }
name|bool
name|operator
operator|==
operator|(
specifier|const
name|SingleLinkedListIterator
operator|<
name|T
operator|>
operator|&
name|Other
operator|)
block|{
return|return
name|P
operator|==
name|Other
operator|.
name|operator
operator|->
expr|(
block|)
block|;       }
name|T
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
operator|*
name|P
return|;
block|}
name|T
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
name|P
return|;
block|}
end_decl_stmt

begin_decl_stmt
unit|};
name|using
name|subrange_iterator
init|=
name|SingleLinkedListIterator
operator|<
name|SubRange
operator|>
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|using
name|const_subrange_iterator
init|=
name|SingleLinkedListIterator
operator|<
specifier|const
name|SubRange
operator|>
decl_stmt|;
end_decl_stmt

begin_function
name|subrange_iterator
name|subrange_begin
parameter_list|()
block|{
return|return
name|subrange_iterator
argument_list|(
name|SubRanges
argument_list|)
return|;
block|}
end_function

begin_function
name|subrange_iterator
name|subrange_end
parameter_list|()
block|{
return|return
name|subrange_iterator
argument_list|(
name|nullptr
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|const_subrange_iterator
name|subrange_begin
argument_list|()
specifier|const
block|{
return|return
name|const_subrange_iterator
argument_list|(
name|SubRanges
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|const_subrange_iterator
name|subrange_end
argument_list|()
specifier|const
block|{
return|return
name|const_subrange_iterator
argument_list|(
name|nullptr
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|iterator_range
operator|<
name|subrange_iterator
operator|>
name|subranges
argument_list|()
block|{
return|return
name|make_range
argument_list|(
name|subrange_begin
argument_list|()
argument_list|,
name|subrange_end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|iterator_range
operator|<
name|const_subrange_iterator
operator|>
name|subranges
argument_list|()
specifier|const
block|{
return|return
name|make_range
argument_list|(
name|subrange_begin
argument_list|()
argument_list|,
name|subrange_end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Creates a new empty subregister live range. The range is added at the
end_comment

begin_comment
comment|/// beginning of the subrange list; subrange iterators stay valid.
end_comment

begin_function
name|SubRange
modifier|*
name|createSubRange
parameter_list|(
name|BumpPtrAllocator
modifier|&
name|Allocator
parameter_list|,
name|LaneBitmask
name|LaneMask
parameter_list|)
block|{
name|SubRange
modifier|*
name|Range
init|=
name|new
argument_list|(
argument|Allocator
argument_list|)
name|SubRange
argument_list|(
name|LaneMask
argument_list|)
decl_stmt|;
name|appendSubRange
argument_list|(
name|Range
argument_list|)
expr_stmt|;
return|return
name|Range
return|;
block|}
end_function

begin_comment
comment|/// Like createSubRange() but the new range is filled with a copy of the
end_comment

begin_comment
comment|/// liveness information in @p CopyFrom.
end_comment

begin_function
name|SubRange
modifier|*
name|createSubRangeFrom
parameter_list|(
name|BumpPtrAllocator
modifier|&
name|Allocator
parameter_list|,
name|LaneBitmask
name|LaneMask
parameter_list|,
specifier|const
name|LiveRange
modifier|&
name|CopyFrom
parameter_list|)
block|{
name|SubRange
modifier|*
name|Range
init|=
name|new
argument_list|(
argument|Allocator
argument_list|)
name|SubRange
argument_list|(
name|LaneMask
argument_list|,
name|CopyFrom
argument_list|,
name|Allocator
argument_list|)
decl_stmt|;
name|appendSubRange
argument_list|(
name|Range
argument_list|)
expr_stmt|;
return|return
name|Range
return|;
block|}
end_function

begin_comment
comment|/// Returns true if subregister liveness information is available.
end_comment

begin_expr_stmt
name|bool
name|hasSubRanges
argument_list|()
specifier|const
block|{
return|return
name|SubRanges
operator|!=
name|nullptr
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Removes all subregister liveness information.
end_comment

begin_function_decl
name|void
name|clearSubRanges
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Removes all subranges without any segments (subranges without segments
end_comment

begin_comment
comment|/// are not considered valid and should only exist temporarily).
end_comment

begin_function_decl
name|void
name|removeEmptySubRanges
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// getSize - Returns the sum of sizes of all the LiveRange's.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|unsigned
name|getSize
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// isSpillable - Can this interval be spilled?
end_comment

begin_expr_stmt
name|bool
name|isSpillable
argument_list|()
specifier|const
block|{
return|return
name|weight
operator|!=
name|huge_valf
return|;
block|}
end_expr_stmt

begin_comment
comment|/// markNotSpillable - Mark interval as not spillable
end_comment

begin_function
name|void
name|markNotSpillable
parameter_list|()
block|{
name|weight
operator|=
name|huge_valf
expr_stmt|;
block|}
end_function

begin_comment
comment|/// For a given lane mask @p LaneMask, compute indexes at which the
end_comment

begin_comment
comment|/// lane is marked undefined by subregister<def,read-undef> definitions.
end_comment

begin_decl_stmt
name|void
name|computeSubRangeUndefs
argument_list|(
name|SmallVectorImpl
operator|<
name|SlotIndex
operator|>
operator|&
name|Undefs
argument_list|,
name|LaneBitmask
name|LaneMask
argument_list|,
specifier|const
name|MachineRegisterInfo
operator|&
name|MRI
argument_list|,
specifier|const
name|SlotIndexes
operator|&
name|Indexes
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Refines the subranges to support \p LaneMask. This may only be called
end_comment

begin_comment
comment|/// for LI.hasSubrange()==true. Subregister ranges are split or created
end_comment

begin_comment
comment|/// until \p LaneMask can be matched exactly. \p Mod is executed on the
end_comment

begin_comment
comment|/// matching subranges.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Example:
end_comment

begin_comment
comment|///    Given an interval with subranges with lanemasks L0F00, L00F0 and
end_comment

begin_comment
comment|///    L000F, refining for mask L0018. Will split the L00F0 lane into
end_comment

begin_comment
comment|///    L00E0 and L0010 and the L000F lane into L0007 and L0008. The Mod
end_comment

begin_comment
comment|///    function will be applied to the L0010 and L0008 subranges.
end_comment

begin_decl_stmt
name|void
name|refineSubRanges
argument_list|(
name|BumpPtrAllocator
operator|&
name|Allocator
argument_list|,
name|LaneBitmask
name|LaneMask
argument_list|,
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|LiveInterval
operator|::
name|SubRange
operator|&
argument_list|)
operator|>
name|Mod
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
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
name|std
operator|::
name|tie
argument_list|(
name|thisIndex
argument_list|,
name|reg
argument_list|)
operator|<
name|std
operator|::
name|tie
argument_list|(
name|otherIndex
argument_list|,
name|other
operator|.
name|reg
argument_list|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Walks the interval and assert if any invariants fail to hold.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that this is a no-op when asserts are disabled.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NDEBUG
end_ifdef

begin_decl_stmt
name|void
name|verify
argument_list|(
specifier|const
name|MachineRegisterInfo
operator|*
name|MRI
operator|=
name|nullptr
argument_list|)
decl|const
block|{}
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|void
name|verify
argument_list|(
specifier|const
name|MachineRegisterInfo
operator|*
name|MRI
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_label
name|private
label|:
end_label

begin_comment
comment|/// Appends @p Range to SubRanges list.
end_comment

begin_function
name|void
name|appendSubRange
parameter_list|(
name|SubRange
modifier|*
name|Range
parameter_list|)
block|{
name|Range
operator|->
name|Next
operator|=
name|SubRanges
expr_stmt|;
name|SubRanges
operator|=
name|Range
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Free memory held by SubRange.
end_comment

begin_function_decl
name|void
name|freeSubRange
parameter_list|(
name|SubRange
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
unit|};
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
operator|::
name|SubRange
operator|&
name|SR
operator|)
block|{
name|SR
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
name|LiveRange
operator|::
name|Segment
operator|&
name|S
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
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
operator|::
name|Segment
operator|&
name|S
operator|)
block|{
return|return
name|V
operator|<
name|S
operator|.
name|start
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|LiveRange
operator|::
name|Segment
operator|&
name|S
operator|,
name|SlotIndex
name|V
operator|)
block|{
return|return
name|S
operator|.
name|start
operator|<
name|V
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Helper class for performant LiveRange bulk updates.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Calling LiveRange::addSegment() repeatedly can be expensive on large
end_comment

begin_comment
comment|/// live ranges because segments after the insertion point may need to be
end_comment

begin_comment
comment|/// shifted. The LiveRangeUpdater class can defer the shifting when adding
end_comment

begin_comment
comment|/// many segments in order.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The LiveRange will be in an invalid state until flush() is called.
end_comment

begin_decl_stmt
name|class
name|LiveRangeUpdater
block|{
name|LiveRange
modifier|*
name|LR
decl_stmt|;
name|SlotIndex
name|LastStart
decl_stmt|;
name|LiveRange
operator|::
name|iterator
name|WriteI
expr_stmt|;
name|LiveRange
operator|::
name|iterator
name|ReadI
expr_stmt|;
name|SmallVector
operator|<
name|LiveRange
operator|::
name|Segment
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
comment|/// Create a LiveRangeUpdater for adding segments to LR.
comment|/// LR will temporarily be in an invalid state until flush() is called.
name|LiveRangeUpdater
argument_list|(
name|LiveRange
operator|*
name|lr
operator|=
name|nullptr
argument_list|)
operator|:
name|LR
argument_list|(
argument|lr
argument_list|)
block|{}
operator|~
name|LiveRangeUpdater
argument_list|()
block|{
name|flush
argument_list|()
block|; }
comment|/// Add a segment to LR and coalesce when possible, just like
comment|/// LR.addSegment(). Segments should be added in increasing start order for
comment|/// best performance.
name|void
name|add
argument_list|(
name|LiveRange
operator|::
name|Segment
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
operator|::
name|Segment
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
comment|/// Return true if the LR is currently in an invalid state, and flush()
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
comment|/// Flush the updater state to LR so it is valid and contains all added
comment|/// segments.
name|void
name|flush
parameter_list|()
function_decl|;
comment|/// Select a different destination live range.
name|void
name|setDest
parameter_list|(
name|LiveRange
modifier|*
name|lr
parameter_list|)
block|{
if|if
condition|(
name|LR
operator|!=
name|lr
operator|&&
name|isDirty
argument_list|()
condition|)
name|flush
argument_list|()
expr_stmt|;
name|LR
operator|=
name|lr
expr_stmt|;
block|}
comment|/// Get the current destination live range.
name|LiveRange
operator|*
name|getDest
argument_list|()
specifier|const
block|{
return|return
name|LR
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
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
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
end_expr_stmt

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
comment|/// Classify the values in \p LR into connected components.
comment|/// Returns the number of connected components.
name|unsigned
name|Classify
argument_list|(
specifier|const
name|LiveRange
operator|&
name|LR
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
comment|/// Distribute values in \p LI into a separate LiveIntervals
comment|/// for each connected component. LIV must have an empty LiveInterval for
comment|/// each additional connected component. The first connected component is
comment|/// left in \p LI.
name|void
name|Distribute
parameter_list|(
name|LiveInterval
modifier|&
name|LI
parameter_list|,
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

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CODEGEN_LIVEINTERVAL_H
end_comment

end_unit

