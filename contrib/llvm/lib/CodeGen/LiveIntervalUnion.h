begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- LiveIntervalUnion.h - Live interval union data struct --*- C++ -*--===//
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
comment|// LiveIntervalUnion is a union of live segments across multiple live virtual
end_comment

begin_comment
comment|// registers. This may be used during coalescing to represent a congruence
end_comment

begin_comment
comment|// class, or during register allocation to model liveness of a physical
end_comment

begin_comment
comment|// register.
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
name|LLVM_CODEGEN_LIVEINTERVALUNION
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_LIVEINTERVALUNION
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/IntervalMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/LiveInterval.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineLoopRange
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
ifndef|#
directive|ifndef
name|NDEBUG
comment|// forward declaration
name|template
operator|<
name|unsigned
name|Element
operator|>
name|class
name|SparseBitVector
expr_stmt|;
typedef|typedef
name|SparseBitVector
operator|<
literal|128
operator|>
name|LiveVirtRegBitSet
expr_stmt|;
endif|#
directive|endif
comment|/// Compare a live virtual register segment to a LiveIntervalUnion segment.
specifier|inline
name|bool
name|overlap
argument_list|(
specifier|const
name|LiveRange
operator|&
name|VRSeg
argument_list|,
specifier|const
name|IntervalMap
operator|<
name|SlotIndex
argument_list|,
name|LiveInterval
operator|*
operator|>
operator|::
name|const_iterator
operator|&
name|LUSeg
argument_list|)
block|{
return|return
name|VRSeg
operator|.
name|start
operator|<
name|LUSeg
operator|.
name|stop
argument_list|()
operator|&&
name|LUSeg
operator|.
name|start
argument_list|()
operator|<
name|VRSeg
operator|.
name|end
return|;
block|}
comment|/// Union of live intervals that are strong candidates for coalescing into a
comment|/// single register (either physical or virtual depending on the context).  We
comment|/// expect the constituent live intervals to be disjoint, although we may
comment|/// eventually make exceptions to handle value-based interference.
name|class
name|LiveIntervalUnion
block|{
comment|// A set of live virtual register segments that supports fast insertion,
comment|// intersection, and removal.
comment|// Mapping SlotIndex intervals to virtual register numbers.
typedef|typedef
name|IntervalMap
operator|<
name|SlotIndex
operator|,
name|LiveInterval
operator|*
operator|>
name|LiveSegments
expr_stmt|;
name|public
label|:
comment|// SegmentIter can advance to the next segment ordered by starting position
comment|// which may belong to a different live virtual register. We also must be able
comment|// to reach the current segment's containing virtual register.
typedef|typedef
name|LiveSegments
operator|::
name|iterator
name|SegmentIter
expr_stmt|;
comment|// LiveIntervalUnions share an external allocator.
typedef|typedef
name|LiveSegments
operator|::
name|Allocator
name|Allocator
expr_stmt|;
name|class
name|InterferenceResult
decl_stmt|;
name|class
name|Query
decl_stmt|;
name|private
label|:
specifier|const
name|unsigned
name|RepReg
decl_stmt|;
comment|// representative register number
name|unsigned
name|Tag
decl_stmt|;
comment|// unique tag for current contents.
name|LiveSegments
name|Segments
decl_stmt|;
comment|// union of virtual reg segments
name|public
label|:
name|LiveIntervalUnion
argument_list|(
argument|unsigned r
argument_list|,
argument|Allocator&a
argument_list|)
block|:
name|RepReg
argument_list|(
name|r
argument_list|)
operator|,
name|Tag
argument_list|(
literal|0
argument_list|)
operator|,
name|Segments
argument_list|(
argument|a
argument_list|)
block|{}
comment|// Iterate over all segments in the union of live virtual registers ordered
comment|// by their starting position.
name|SegmentIter
name|begin
argument_list|()
block|{
return|return
name|Segments
operator|.
name|begin
argument_list|()
return|;
block|}
name|SegmentIter
name|end
parameter_list|()
block|{
return|return
name|Segments
operator|.
name|end
argument_list|()
return|;
block|}
name|SegmentIter
name|find
parameter_list|(
name|SlotIndex
name|x
parameter_list|)
block|{
return|return
name|Segments
operator|.
name|find
argument_list|(
name|x
argument_list|)
return|;
block|}
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|Segments
operator|.
name|empty
argument_list|()
return|;
block|}
name|SlotIndex
name|startIndex
argument_list|()
specifier|const
block|{
return|return
name|Segments
operator|.
name|start
argument_list|()
return|;
block|}
comment|// Provide public access to the underlying map to allow overlap iteration.
typedef|typedef
name|LiveSegments
name|Map
typedef|;
specifier|const
name|Map
modifier|&
name|getMap
parameter_list|()
block|{
return|return
name|Segments
return|;
block|}
comment|/// getTag - Return an opaque tag representing the current state of the union.
name|unsigned
name|getTag
argument_list|()
specifier|const
block|{
return|return
name|Tag
return|;
block|}
comment|/// changedSince - Return true if the union change since getTag returned tag.
name|bool
name|changedSince
argument_list|(
name|unsigned
name|tag
argument_list|)
decl|const
block|{
return|return
name|tag
operator|!=
name|Tag
return|;
block|}
comment|// Add a live virtual register to this union and merge its segments.
name|void
name|unify
parameter_list|(
name|LiveInterval
modifier|&
name|VirtReg
parameter_list|)
function_decl|;
comment|// Remove a live virtual register's segments from this union.
name|void
name|extract
parameter_list|(
name|LiveInterval
modifier|&
name|VirtReg
parameter_list|)
function_decl|;
comment|// Remove all inserted virtual registers.
name|void
name|clear
parameter_list|()
block|{
name|Segments
operator|.
name|clear
argument_list|()
expr_stmt|;
operator|++
name|Tag
expr_stmt|;
block|}
comment|// Print union, using TRI to translate register names
name|void
name|print
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|,
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
parameter_list|)
function|const;
ifndef|#
directive|ifndef
name|NDEBUG
comment|// Verify the live intervals in this union and add them to the visited set.
name|void
name|verify
parameter_list|(
name|LiveVirtRegBitSet
modifier|&
name|VisitedVRegs
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/// Cache a single interference test result in the form of two intersecting
comment|/// segments. This allows efficiently iterating over the interferences. The
comment|/// iteration logic is handled by LiveIntervalUnion::Query which may
comment|/// filter interferences depending on the type of query.
name|class
name|InterferenceResult
block|{
name|friend
name|class
name|Query
decl_stmt|;
name|LiveInterval
operator|::
name|iterator
name|VirtRegI
expr_stmt|;
comment|// current position in VirtReg
name|SegmentIter
name|LiveUnionI
decl_stmt|;
comment|// current position in LiveUnion
comment|// Internal ctor.
name|InterferenceResult
argument_list|(
argument|LiveInterval::iterator VRegI
argument_list|,
argument|SegmentIter UnionI
argument_list|)
block|:
name|VirtRegI
argument_list|(
name|VRegI
argument_list|)
operator|,
name|LiveUnionI
argument_list|(
argument|UnionI
argument_list|)
block|{}
name|public
operator|:
comment|// Public default ctor.
name|InterferenceResult
argument_list|()
operator|:
name|VirtRegI
argument_list|()
operator|,
name|LiveUnionI
argument_list|()
block|{}
comment|/// start - Return the start of the current overlap.
name|SlotIndex
name|start
argument_list|()
specifier|const
block|{
return|return
name|std
operator|::
name|max
argument_list|(
name|VirtRegI
operator|->
name|start
argument_list|,
name|LiveUnionI
operator|.
name|start
argument_list|()
argument_list|)
return|;
block|}
comment|/// stop - Return the end of the current overlap.
name|SlotIndex
name|stop
argument_list|()
specifier|const
block|{
return|return
name|std
operator|::
name|min
argument_list|(
name|VirtRegI
operator|->
name|end
argument_list|,
name|LiveUnionI
operator|.
name|stop
argument_list|()
argument_list|)
return|;
block|}
comment|/// interference - Return the register that is interfering here.
name|LiveInterval
operator|*
name|interference
argument_list|()
specifier|const
block|{
return|return
name|LiveUnionI
operator|.
name|value
argument_list|()
return|;
block|}
comment|// Note: this interface provides raw access to the iterators because the
comment|// result has no way to tell if it's valid to dereference them.
comment|// Access the VirtReg segment.
name|LiveInterval
operator|::
name|iterator
name|virtRegPos
argument_list|()
specifier|const
block|{
return|return
name|VirtRegI
return|;
block|}
comment|// Access the LiveUnion segment.
specifier|const
name|SegmentIter
operator|&
name|liveUnionPos
argument_list|()
specifier|const
block|{
return|return
name|LiveUnionI
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|InterferenceResult
operator|&
name|IR
operator|)
specifier|const
block|{
return|return
name|VirtRegI
operator|==
name|IR
operator|.
name|VirtRegI
operator|&&
name|LiveUnionI
operator|==
name|IR
operator|.
name|LiveUnionI
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|InterferenceResult
operator|&
name|IR
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|IR
operator|)
return|;
block|}
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
comment|/// Query interferences between a single live virtual register and a live
comment|/// interval union.
name|class
name|Query
block|{
name|LiveIntervalUnion
modifier|*
name|LiveUnion
decl_stmt|;
name|LiveInterval
modifier|*
name|VirtReg
decl_stmt|;
name|InterferenceResult
name|FirstInterference
decl_stmt|;
name|SmallVector
operator|<
name|LiveInterval
operator|*
operator|,
literal|4
operator|>
name|InterferingVRegs
expr_stmt|;
name|bool
name|CheckedFirstInterference
decl_stmt|;
name|bool
name|SeenAllInterferences
decl_stmt|;
name|bool
name|SeenUnspillableVReg
decl_stmt|;
name|unsigned
name|Tag
decl_stmt|,
name|UserTag
decl_stmt|;
name|public
label|:
name|Query
argument_list|()
operator|:
name|LiveUnion
argument_list|()
operator|,
name|VirtReg
argument_list|()
operator|,
name|Tag
argument_list|(
literal|0
argument_list|)
operator|,
name|UserTag
argument_list|(
literal|0
argument_list|)
block|{}
name|Query
argument_list|(
name|LiveInterval
operator|*
name|VReg
argument_list|,
name|LiveIntervalUnion
operator|*
name|LIU
argument_list|)
operator|:
name|LiveUnion
argument_list|(
name|LIU
argument_list|)
operator|,
name|VirtReg
argument_list|(
name|VReg
argument_list|)
operator|,
name|CheckedFirstInterference
argument_list|(
name|false
argument_list|)
operator|,
name|SeenAllInterferences
argument_list|(
name|false
argument_list|)
operator|,
name|SeenUnspillableVReg
argument_list|(
argument|false
argument_list|)
block|{}
name|void
name|clear
argument_list|()
block|{
name|LiveUnion
operator|=
name|NULL
block|;
name|VirtReg
operator|=
name|NULL
block|;
name|InterferingVRegs
operator|.
name|clear
argument_list|()
block|;
name|CheckedFirstInterference
operator|=
name|false
block|;
name|SeenAllInterferences
operator|=
name|false
block|;
name|SeenUnspillableVReg
operator|=
name|false
block|;
name|Tag
operator|=
literal|0
block|;
name|UserTag
operator|=
literal|0
block|;     }
name|void
name|init
argument_list|(
argument|unsigned UTag
argument_list|,
argument|LiveInterval *VReg
argument_list|,
argument|LiveIntervalUnion *LIU
argument_list|)
block|{
name|assert
argument_list|(
name|VReg
operator|&&
name|LIU
operator|&&
literal|"Invalid arguments"
argument_list|)
block|;
if|if
condition|(
name|UserTag
operator|==
name|UTag
operator|&&
name|VirtReg
operator|==
name|VReg
operator|&&
name|LiveUnion
operator|==
name|LIU
operator|&&
operator|!
name|LIU
operator|->
name|changedSince
argument_list|(
name|Tag
argument_list|)
condition|)
block|{
comment|// Retain cached results, e.g. firstInterference.
return|return;
block|}
name|clear
argument_list|()
expr_stmt|;
name|LiveUnion
operator|=
name|LIU
expr_stmt|;
name|VirtReg
operator|=
name|VReg
expr_stmt|;
name|Tag
operator|=
name|LIU
operator|->
name|getTag
argument_list|()
expr_stmt|;
name|UserTag
operator|=
name|UTag
expr_stmt|;
block|}
name|LiveInterval
operator|&
name|virtReg
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|VirtReg
operator|&&
literal|"uninitialized"
argument_list|)
block|;
return|return
operator|*
name|VirtReg
return|;
block|}
name|bool
name|isInterference
argument_list|(
specifier|const
name|InterferenceResult
operator|&
name|IR
argument_list|)
decl|const
block|{
if|if
condition|(
name|IR
operator|.
name|VirtRegI
operator|!=
name|VirtReg
operator|->
name|end
argument_list|()
condition|)
block|{
name|assert
argument_list|(
name|overlap
argument_list|(
operator|*
name|IR
operator|.
name|VirtRegI
argument_list|,
name|IR
operator|.
name|LiveUnionI
argument_list|)
operator|&&
literal|"invalid segment iterators"
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
comment|// Does this live virtual register interfere with the union?
name|bool
name|checkInterference
parameter_list|()
block|{
return|return
name|isInterference
argument_list|(
name|firstInterference
argument_list|()
argument_list|)
return|;
block|}
comment|// Get the first pair of interfering segments, or a noninterfering result.
comment|// This initializes the firstInterference_ cache.
specifier|const
name|InterferenceResult
modifier|&
name|firstInterference
parameter_list|()
function_decl|;
comment|// Treat the result as an iterator and advance to the next interfering pair
comment|// of segments. Visiting each unique interfering pairs means that the same
comment|// VirtReg or LiveUnion segment may be visited multiple times.
name|bool
name|nextInterference
argument_list|(
name|InterferenceResult
operator|&
name|IR
argument_list|)
decl|const
decl_stmt|;
comment|// Count the virtual registers in this union that interfere with this
comment|// query's live virtual register, up to maxInterferingRegs.
name|unsigned
name|collectInterferingVRegs
parameter_list|(
name|unsigned
name|MaxInterferingRegs
init|=
name|UINT_MAX
parameter_list|,
name|float
name|MaxWeight
init|=
name|HUGE_VALF
parameter_list|)
function_decl|;
comment|// Was this virtual register visited during collectInterferingVRegs?
name|bool
name|isSeenInterference
argument_list|(
name|LiveInterval
operator|*
name|VReg
argument_list|)
decl|const
decl_stmt|;
comment|// Did collectInterferingVRegs collect all interferences?
name|bool
name|seenAllInterferences
argument_list|()
specifier|const
block|{
return|return
name|SeenAllInterferences
return|;
block|}
comment|// Did collectInterferingVRegs encounter an unspillable vreg?
name|bool
name|seenUnspillableVReg
argument_list|()
specifier|const
block|{
return|return
name|SeenUnspillableVReg
return|;
block|}
comment|// Vector generated by collectInterferingVRegs.
specifier|const
name|SmallVectorImpl
operator|<
name|LiveInterval
operator|*
operator|>
operator|&
name|interferingVRegs
argument_list|()
specifier|const
block|{
return|return
name|InterferingVRegs
return|;
block|}
comment|/// checkLoopInterference - Return true if there is interference overlapping
comment|/// Loop.
name|bool
name|checkLoopInterference
parameter_list|(
name|MachineLoopRange
modifier|*
parameter_list|)
function_decl|;
name|void
name|print
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|,
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
parameter_list|)
function_decl|;
name|private
label|:
name|Query
argument_list|(
specifier|const
name|Query
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|Query
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
comment|// Private interface for queries
name|void
name|findIntersection
argument_list|(
name|InterferenceResult
operator|&
name|IR
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
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
comment|// !defined(LLVM_CODEGEN_LIVEINTERVALUNION)
end_comment

end_unit

