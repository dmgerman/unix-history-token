begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- StatepointLowering.h - SDAGBuilder's statepoint code -*- C++ -*---===//
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
comment|// This file includes support code use by SelectionDAGBuilder when lowering a
end_comment

begin_comment
comment|// statepoint sequence in SelectionDAG IR.
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
name|LLVM_LIB_CODEGEN_SELECTIONDAG_STATEPOINTLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_CODEGEN_SELECTIONDAG_STATEPOINTLOWERING_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAG.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAGNodes.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|SelectionDAGBuilder
decl_stmt|;
comment|/// This class tracks both per-statepoint and per-selectiondag information.
comment|/// For each statepoint it tracks locations of it's gc valuess (incoming and
comment|/// relocated) and list of gcreloc calls scheduled for visiting (this is
comment|/// used for a debug mode consistency check only).  The spill slot tracking
comment|/// works in concert with information in FunctionLoweringInfo.
name|class
name|StatepointLoweringState
block|{
name|public
label|:
name|StatepointLoweringState
argument_list|()
operator|:
name|NextSlotToAllocate
argument_list|(
literal|0
argument_list|)
block|{   }
comment|/// Reset all state tracking for a newly encountered safepoint.  Also
comment|/// performs some consistency checking.
name|void
name|startNewStatepoint
argument_list|(
name|SelectionDAGBuilder
operator|&
name|Builder
argument_list|)
expr_stmt|;
comment|/// Clear the memory usage of this object.  This is called from
comment|/// SelectionDAGBuilder::clear.  We require this is never called in the
comment|/// midst of processing a statepoint sequence.
name|void
name|clear
parameter_list|()
function_decl|;
comment|/// Returns the spill location of a value incoming to the current
comment|/// statepoint.  Will return SDValue() if this value hasn't been
comment|/// spilled.  Otherwise, the value has already been spilled and no
comment|/// further action is required by the caller.
name|SDValue
name|getLocation
parameter_list|(
name|SDValue
name|val
parameter_list|)
block|{
if|if
condition|(
operator|!
name|Locations
operator|.
name|count
argument_list|(
name|val
argument_list|)
condition|)
return|return
name|SDValue
argument_list|()
return|;
return|return
name|Locations
index|[
name|val
index|]
return|;
block|}
name|void
name|setLocation
parameter_list|(
name|SDValue
name|val
parameter_list|,
name|SDValue
name|Location
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|Locations
operator|.
name|count
argument_list|(
name|val
argument_list|)
operator|&&
literal|"Trying to allocate already allocated location"
argument_list|)
expr_stmt|;
name|Locations
index|[
name|val
index|]
operator|=
name|Location
expr_stmt|;
block|}
comment|/// Returns the relocated value for a given input pointer. Will
comment|/// return SDValue() if this value hasn't yet been reloaded from
comment|/// it's stack slot after the statepoint.  Otherwise, the value
comment|/// has already been reloaded and the SDValue of that reload will
comment|/// be returned. Note that VMState values are spilled but not
comment|/// reloaded (since they don't change at the safepoint unless
comment|/// also listed in the GC pointer section) and will thus never
comment|/// be in this map
name|SDValue
name|getRelocLocation
parameter_list|(
name|SDValue
name|val
parameter_list|)
block|{
if|if
condition|(
operator|!
name|RelocLocations
operator|.
name|count
argument_list|(
name|val
argument_list|)
condition|)
return|return
name|SDValue
argument_list|()
return|;
return|return
name|RelocLocations
index|[
name|val
index|]
return|;
block|}
name|void
name|setRelocLocation
parameter_list|(
name|SDValue
name|val
parameter_list|,
name|SDValue
name|Location
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|RelocLocations
operator|.
name|count
argument_list|(
name|val
argument_list|)
operator|&&
literal|"Trying to allocate already allocated location"
argument_list|)
expr_stmt|;
name|RelocLocations
index|[
name|val
index|]
operator|=
name|Location
expr_stmt|;
block|}
comment|/// Record the fact that we expect to encounter a given gc_relocate
comment|/// before the next statepoint.  If we don't see it, we'll report
comment|/// an assertion.
name|void
name|scheduleRelocCall
parameter_list|(
specifier|const
name|CallInst
modifier|&
name|RelocCall
parameter_list|)
block|{
name|PendingGCRelocateCalls
operator|.
name|push_back
argument_list|(
operator|&
name|RelocCall
argument_list|)
expr_stmt|;
block|}
comment|/// Remove this gc_relocate from the list we're expecting to see
comment|/// before the next statepoint.  If we weren't expecting to see
comment|/// it, we'll report an assertion.
name|void
name|relocCallVisited
parameter_list|(
specifier|const
name|CallInst
modifier|&
name|RelocCall
parameter_list|)
block|{
name|SmallVectorImpl
operator|<
specifier|const
name|CallInst
operator|*
operator|>
operator|::
name|iterator
name|itr
operator|=
name|std
operator|::
name|find
argument_list|(
name|PendingGCRelocateCalls
operator|.
name|begin
argument_list|()
argument_list|,
name|PendingGCRelocateCalls
operator|.
name|end
argument_list|()
argument_list|,
operator|&
name|RelocCall
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|itr
operator|!=
name|PendingGCRelocateCalls
operator|.
name|end
argument_list|()
operator|&&
literal|"Visited unexpected gcrelocate call"
argument_list|)
expr_stmt|;
name|PendingGCRelocateCalls
operator|.
name|erase
argument_list|(
name|itr
argument_list|)
expr_stmt|;
block|}
comment|// TODO: Should add consistency tracking to ensure we encounter
comment|// expected gc_result calls too.
comment|/// Get a stack slot we can use to store an value of type ValueType.  This
comment|/// will hopefully be a recylced slot from another statepoint.
name|SDValue
name|allocateStackSlot
parameter_list|(
name|EVT
name|ValueType
parameter_list|,
name|SelectionDAGBuilder
modifier|&
name|Builder
parameter_list|)
function_decl|;
name|void
name|reserveStackSlot
parameter_list|(
name|int
name|Offset
parameter_list|)
block|{
name|assert
argument_list|(
name|Offset
operator|>=
literal|0
operator|&&
name|Offset
operator|<
operator|(
name|int
operator|)
name|AllocatedStackSlots
operator|.
name|size
argument_list|()
operator|&&
literal|"out of bounds"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|!
name|AllocatedStackSlots
index|[
name|Offset
index|]
operator|&&
literal|"already reserved!"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|NextSlotToAllocate
operator|<=
operator|(
name|unsigned
operator|)
name|Offset
operator|&&
literal|"consistency!"
argument_list|)
expr_stmt|;
name|AllocatedStackSlots
index|[
name|Offset
index|]
operator|=
name|true
expr_stmt|;
block|}
name|bool
name|isStackSlotAllocated
parameter_list|(
name|int
name|Offset
parameter_list|)
block|{
name|assert
argument_list|(
name|Offset
operator|>=
literal|0
operator|&&
name|Offset
operator|<
operator|(
name|int
operator|)
name|AllocatedStackSlots
operator|.
name|size
argument_list|()
operator|&&
literal|"out of bounds"
argument_list|)
expr_stmt|;
return|return
name|AllocatedStackSlots
index|[
name|Offset
index|]
return|;
block|}
name|private
label|:
comment|/// Maps pre-relocation value (gc pointer directly incoming into statepoint)
comment|/// into it's location (currently only stack slots)
name|DenseMap
operator|<
name|SDValue
operator|,
name|SDValue
operator|>
name|Locations
expr_stmt|;
comment|/// Map pre-relocated value into it's new relocated location
name|DenseMap
operator|<
name|SDValue
operator|,
name|SDValue
operator|>
name|RelocLocations
expr_stmt|;
comment|/// A boolean indicator for each slot listed in the FunctionInfo as to
comment|/// whether it has been used in the current statepoint.  Since we try to
comment|/// preserve stack slots across safepoints, there can be gaps in which
comment|/// slots have been allocated.
name|SmallVector
operator|<
name|bool
operator|,
literal|50
operator|>
name|AllocatedStackSlots
expr_stmt|;
comment|/// Points just beyond the last slot known to have been allocated
name|unsigned
name|NextSlotToAllocate
decl_stmt|;
comment|/// Keep track of pending gcrelocate calls for consistency check
name|SmallVector
operator|<
specifier|const
name|CallInst
operator|*
operator|,
literal|10
operator|>
name|PendingGCRelocateCalls
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_CODEGEN_SELECTIONDAG_STATEPOINTLOWERING_H
end_comment

end_unit

