begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CodeGen/MachineFrameInfo.h - Abstract Stack Frame Rep. --*- C++ -*-===//
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
comment|// The file defines the MachineFrameInfo class.
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
name|LLVM_CODEGEN_MACHINEFRAMEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MACHINEFRAMEINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
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
name|raw_ostream
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|BitVector
decl_stmt|;
name|class
name|AllocaInst
decl_stmt|;
comment|/// The CalleeSavedInfo class tracks the information need to locate where a
comment|/// callee saved register is in the current frame.
name|class
name|CalleeSavedInfo
block|{
name|unsigned
name|Reg
decl_stmt|;
name|int
name|FrameIdx
decl_stmt|;
name|public
label|:
name|explicit
name|CalleeSavedInfo
argument_list|(
argument|unsigned R
argument_list|,
argument|int FI =
literal|0
argument_list|)
block|:
name|Reg
argument_list|(
name|R
argument_list|)
operator|,
name|FrameIdx
argument_list|(
argument|FI
argument_list|)
block|{}
comment|// Accessors.
name|unsigned
name|getReg
argument_list|()
specifier|const
block|{
return|return
name|Reg
return|;
block|}
name|int
name|getFrameIdx
argument_list|()
specifier|const
block|{
return|return
name|FrameIdx
return|;
block|}
name|void
name|setFrameIdx
parameter_list|(
name|int
name|FI
parameter_list|)
block|{
name|FrameIdx
operator|=
name|FI
expr_stmt|;
block|}
block|}
empty_stmt|;
comment|/// The MachineFrameInfo class represents an abstract stack frame until
comment|/// prolog/epilog code is inserted.  This class is key to allowing stack frame
comment|/// representation optimizations, such as frame pointer elimination.  It also
comment|/// allows more mundane (but still important) optimizations, such as reordering
comment|/// of abstract objects on the stack frame.
comment|///
comment|/// To support this, the class assigns unique integer identifiers to stack
comment|/// objects requested clients.  These identifiers are negative integers for
comment|/// fixed stack objects (such as arguments passed on the stack) or nonnegative
comment|/// for objects that may be reordered.  Instructions which refer to stack
comment|/// objects use a special MO_FrameIndex operand to represent these frame
comment|/// indexes.
comment|///
comment|/// Because this class keeps track of all references to the stack frame, it
comment|/// knows when a variable sized object is allocated on the stack.  This is the
comment|/// sole condition which prevents frame pointer elimination, which is an
comment|/// important optimization on register-poor architectures.  Because original
comment|/// variable sized alloca's in the source program are the only source of
comment|/// variable sized stack objects, it is safe to decide whether there will be
comment|/// any variable sized objects before all stack objects are known (for
comment|/// example, register allocator spill code never needs variable sized
comment|/// objects).
comment|///
comment|/// When prolog/epilog code emission is performed, the final stack frame is
comment|/// built and the machine instructions are modified to refer to the actual
comment|/// stack offsets of the object, eliminating all MO_FrameIndex operands from
comment|/// the program.
comment|///
comment|/// @brief Abstract Stack Frame Information
name|class
name|MachineFrameInfo
block|{
comment|// Represent a single object allocated on the stack.
struct|struct
name|StackObject
block|{
comment|// The offset of this object from the stack pointer on entry to
comment|// the function.  This field has no meaning for a variable sized element.
name|int64_t
name|SPOffset
decl_stmt|;
comment|// The size of this object on the stack. 0 means a variable sized object,
comment|// ~0ULL means a dead object.
name|uint64_t
name|Size
decl_stmt|;
comment|// The required alignment of this stack slot.
name|unsigned
name|Alignment
decl_stmt|;
comment|// If true, the value of the stack object is set before
comment|// entering the function and is not modified inside the function. By
comment|// default, fixed objects are immutable unless marked otherwise.
name|bool
name|isImmutable
decl_stmt|;
comment|// If true the stack object is used as spill slot. It
comment|// cannot alias any other memory objects.
name|bool
name|isSpillSlot
decl_stmt|;
comment|/// If true, this stack slot is used to spill a value (could be deopt
comment|/// and/or GC related) over a statepoint. We know that the address of the
comment|/// slot can't alias any LLVM IR value.  This is very similar to a Spill
comment|/// Slot, but is created by statepoint lowering is SelectionDAG, not the
comment|/// register allocator.
name|bool
name|isStatepointSpillSlot
decl_stmt|;
comment|/// If this stack object is originated from an Alloca instruction
comment|/// this value saves the original IR allocation. Can be NULL.
specifier|const
name|AllocaInst
modifier|*
name|Alloca
decl_stmt|;
comment|// If true, the object was mapped into the local frame
comment|// block and doesn't need additional handling for allocation beyond that.
name|bool
name|PreAllocated
decl_stmt|;
comment|// If true, an LLVM IR value might point to this object.
comment|// Normally, spill slots and fixed-offset objects don't alias IR-accessible
comment|// objects, but there are exceptions (on PowerPC, for example, some byval
comment|// arguments have ABI-prescribed offsets).
name|bool
name|isAliased
decl_stmt|;
comment|/// If true, the object has been zero-extended.
name|bool
name|isZExt
decl_stmt|;
comment|/// If true, the object has been zero-extended.
name|bool
name|isSExt
decl_stmt|;
name|StackObject
argument_list|(
argument|uint64_t Sz
argument_list|,
argument|unsigned Al
argument_list|,
argument|int64_t SP
argument_list|,
argument|bool IM
argument_list|,
argument|bool isSS
argument_list|,
argument|const AllocaInst *Val
argument_list|,
argument|bool A
argument_list|)
block|:
name|SPOffset
argument_list|(
name|SP
argument_list|)
operator|,
name|Size
argument_list|(
name|Sz
argument_list|)
operator|,
name|Alignment
argument_list|(
name|Al
argument_list|)
operator|,
name|isImmutable
argument_list|(
name|IM
argument_list|)
operator|,
name|isSpillSlot
argument_list|(
name|isSS
argument_list|)
operator|,
name|isStatepointSpillSlot
argument_list|(
name|false
argument_list|)
operator|,
name|Alloca
argument_list|(
name|Val
argument_list|)
operator|,
name|PreAllocated
argument_list|(
name|false
argument_list|)
operator|,
name|isAliased
argument_list|(
name|A
argument_list|)
operator|,
name|isZExt
argument_list|(
name|false
argument_list|)
operator|,
name|isSExt
argument_list|(
argument|false
argument_list|)
block|{}
block|}
struct|;
comment|/// The alignment of the stack.
name|unsigned
name|StackAlignment
decl_stmt|;
comment|/// Can the stack be realigned. This can be false if the target does not
comment|/// support stack realignment, or if the user asks us not to realign the
comment|/// stack. In this situation, overaligned allocas are all treated as dynamic
comment|/// allocations and the target must handle them as part of DYNAMIC_STACKALLOC
comment|/// lowering. All non-alloca stack objects have their alignment clamped to the
comment|/// base ABI stack alignment.
comment|/// FIXME: There is room for improvement in this case, in terms of
comment|/// grouping overaligned allocas into a "secondary stack frame" and
comment|/// then only use a single alloca to allocate this frame and only a
comment|/// single virtual register to access it. Currently, without such an
comment|/// optimization, each such alloca gets its own dynamic realignment.
name|bool
name|StackRealignable
decl_stmt|;
comment|/// Whether the function has the \c alignstack attribute.
name|bool
name|ForcedRealign
decl_stmt|;
comment|/// The list of stack objects allocated.
name|std
operator|::
name|vector
operator|<
name|StackObject
operator|>
name|Objects
expr_stmt|;
comment|/// This contains the number of fixed objects contained on
comment|/// the stack.  Because fixed objects are stored at a negative index in the
comment|/// Objects list, this is also the index to the 0th object in the list.
name|unsigned
name|NumFixedObjects
init|=
literal|0
decl_stmt|;
comment|/// This boolean keeps track of whether any variable
comment|/// sized objects have been allocated yet.
name|bool
name|HasVarSizedObjects
init|=
name|false
decl_stmt|;
comment|/// This boolean keeps track of whether there is a call
comment|/// to builtin \@llvm.frameaddress.
name|bool
name|FrameAddressTaken
init|=
name|false
decl_stmt|;
comment|/// This boolean keeps track of whether there is a call
comment|/// to builtin \@llvm.returnaddress.
name|bool
name|ReturnAddressTaken
init|=
name|false
decl_stmt|;
comment|/// This boolean keeps track of whether there is a call
comment|/// to builtin \@llvm.experimental.stackmap.
name|bool
name|HasStackMap
init|=
name|false
decl_stmt|;
comment|/// This boolean keeps track of whether there is a call
comment|/// to builtin \@llvm.experimental.patchpoint.
name|bool
name|HasPatchPoint
init|=
name|false
decl_stmt|;
comment|/// The prolog/epilog code inserter calculates the final stack
comment|/// offsets for all of the fixed size objects, updating the Objects list
comment|/// above.  It then updates StackSize to contain the number of bytes that need
comment|/// to be allocated on entry to the function.
name|uint64_t
name|StackSize
init|=
literal|0
decl_stmt|;
comment|/// The amount that a frame offset needs to be adjusted to
comment|/// have the actual offset from the stack/frame pointer.  The exact usage of
comment|/// this is target-dependent, but it is typically used to adjust between
comment|/// SP-relative and FP-relative offsets.  E.G., if objects are accessed via
comment|/// SP then OffsetAdjustment is zero; if FP is used, OffsetAdjustment is set
comment|/// to the distance between the initial SP and the value in FP.  For many
comment|/// targets, this value is only used when generating debug info (via
comment|/// TargetRegisterInfo::getFrameIndexReference); when generating code, the
comment|/// corresponding adjustments are performed directly.
name|int
name|OffsetAdjustment
init|=
literal|0
decl_stmt|;
comment|/// The prolog/epilog code inserter may process objects that require greater
comment|/// alignment than the default alignment the target provides.
comment|/// To handle this, MaxAlignment is set to the maximum alignment
comment|/// needed by the objects on the current frame.  If this is greater than the
comment|/// native alignment maintained by the compiler, dynamic alignment code will
comment|/// be needed.
comment|///
name|unsigned
name|MaxAlignment
init|=
literal|0
decl_stmt|;
comment|/// Set to true if this function adjusts the stack -- e.g.,
comment|/// when calling another function. This is only valid during and after
comment|/// prolog/epilog code insertion.
name|bool
name|AdjustsStack
init|=
name|false
decl_stmt|;
comment|/// Set to true if this function has any function calls.
name|bool
name|HasCalls
init|=
name|false
decl_stmt|;
comment|/// The frame index for the stack protector.
name|int
name|StackProtectorIdx
init|=
operator|-
literal|1
decl_stmt|;
comment|/// The frame index for the function context. Used for SjLj exceptions.
name|int
name|FunctionContextIdx
init|=
operator|-
literal|1
decl_stmt|;
comment|/// This contains the size of the largest call frame if the target uses frame
comment|/// setup/destroy pseudo instructions (as defined in the TargetFrameInfo
comment|/// class).  This information is important for frame pointer elimination.
comment|/// It is only valid during and after prolog/epilog code insertion.
name|unsigned
name|MaxCallFrameSize
init|=
operator|~
literal|0u
decl_stmt|;
comment|/// The prolog/epilog code inserter fills in this vector with each
comment|/// callee saved register saved in the frame.  Beyond its use by the prolog/
comment|/// epilog code inserter, this data used for debug info and exception
comment|/// handling.
name|std
operator|::
name|vector
operator|<
name|CalleeSavedInfo
operator|>
name|CSInfo
expr_stmt|;
comment|/// Has CSInfo been set yet?
name|bool
name|CSIValid
init|=
name|false
decl_stmt|;
comment|/// References to frame indices which are mapped
comment|/// into the local frame allocation block.<FrameIdx, LocalOffset>
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|int
operator|,
name|int64_t
operator|>
operator|,
literal|32
operator|>
name|LocalFrameObjects
expr_stmt|;
comment|/// Size of the pre-allocated local frame block.
name|int64_t
name|LocalFrameSize
init|=
literal|0
decl_stmt|;
comment|/// Required alignment of the local object blob, which is the strictest
comment|/// alignment of any object in it.
name|unsigned
name|LocalFrameMaxAlign
init|=
literal|0
decl_stmt|;
comment|/// Whether the local object blob needs to be allocated together. If not,
comment|/// PEI should ignore the isPreAllocated flags on the stack objects and
comment|/// just allocate them normally.
name|bool
name|UseLocalStackAllocationBlock
init|=
name|false
decl_stmt|;
comment|/// True if the function dynamically adjusts the stack pointer through some
comment|/// opaque mechanism like inline assembly or Win32 EH.
name|bool
name|HasOpaqueSPAdjustment
init|=
name|false
decl_stmt|;
comment|/// True if the function contains operations which will lower down to
comment|/// instructions which manipulate the stack pointer.
name|bool
name|HasCopyImplyingStackAdjustment
init|=
name|false
decl_stmt|;
comment|/// True if the function contains a call to the llvm.vastart intrinsic.
name|bool
name|HasVAStart
init|=
name|false
decl_stmt|;
comment|/// True if this is a varargs function that contains a musttail call.
name|bool
name|HasMustTailInVarArgFunc
init|=
name|false
decl_stmt|;
comment|/// True if this function contains a tail call. If so immutable objects like
comment|/// function arguments are no longer so. A tail call *can* override fixed
comment|/// stack objects like arguments so we can't treat them as immutable.
name|bool
name|HasTailCall
init|=
name|false
decl_stmt|;
comment|/// Not null, if shrink-wrapping found a better place for the prologue.
name|MachineBasicBlock
modifier|*
name|Save
init|=
name|nullptr
decl_stmt|;
comment|/// Not null, if shrink-wrapping found a better place for the epilogue.
name|MachineBasicBlock
modifier|*
name|Restore
init|=
name|nullptr
decl_stmt|;
name|public
label|:
name|explicit
name|MachineFrameInfo
argument_list|(
argument|unsigned StackAlignment
argument_list|,
argument|bool StackRealignable
argument_list|,
argument|bool ForcedRealign
argument_list|)
block|:
name|StackAlignment
argument_list|(
name|StackAlignment
argument_list|)
operator|,
name|StackRealignable
argument_list|(
name|StackRealignable
argument_list|)
operator|,
name|ForcedRealign
argument_list|(
argument|ForcedRealign
argument_list|)
block|{}
comment|/// Return true if there are any stack objects in this function.
name|bool
name|hasStackObjects
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Objects
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// This method may be called any time after instruction
comment|/// selection is complete to determine if the stack frame for this function
comment|/// contains any variable sized objects.
name|bool
name|hasVarSizedObjects
argument_list|()
specifier|const
block|{
return|return
name|HasVarSizedObjects
return|;
block|}
comment|/// Return the index for the stack protector object.
name|int
name|getStackProtectorIndex
argument_list|()
specifier|const
block|{
return|return
name|StackProtectorIdx
return|;
block|}
name|void
name|setStackProtectorIndex
parameter_list|(
name|int
name|I
parameter_list|)
block|{
name|StackProtectorIdx
operator|=
name|I
expr_stmt|;
block|}
name|bool
name|hasStackProtectorIndex
argument_list|()
specifier|const
block|{
return|return
name|StackProtectorIdx
operator|!=
operator|-
literal|1
return|;
block|}
comment|/// Return the index for the function context object.
comment|/// This object is used for SjLj exceptions.
name|int
name|getFunctionContextIndex
argument_list|()
specifier|const
block|{
return|return
name|FunctionContextIdx
return|;
block|}
name|void
name|setFunctionContextIndex
parameter_list|(
name|int
name|I
parameter_list|)
block|{
name|FunctionContextIdx
operator|=
name|I
expr_stmt|;
block|}
comment|/// This method may be called any time after instruction
comment|/// selection is complete to determine if there is a call to
comment|/// \@llvm.frameaddress in this function.
name|bool
name|isFrameAddressTaken
argument_list|()
specifier|const
block|{
return|return
name|FrameAddressTaken
return|;
block|}
name|void
name|setFrameAddressIsTaken
parameter_list|(
name|bool
name|T
parameter_list|)
block|{
name|FrameAddressTaken
operator|=
name|T
expr_stmt|;
block|}
comment|/// This method may be called any time after
comment|/// instruction selection is complete to determine if there is a call to
comment|/// \@llvm.returnaddress in this function.
name|bool
name|isReturnAddressTaken
argument_list|()
specifier|const
block|{
return|return
name|ReturnAddressTaken
return|;
block|}
name|void
name|setReturnAddressIsTaken
parameter_list|(
name|bool
name|s
parameter_list|)
block|{
name|ReturnAddressTaken
operator|=
name|s
expr_stmt|;
block|}
comment|/// This method may be called any time after instruction
comment|/// selection is complete to determine if there is a call to builtin
comment|/// \@llvm.experimental.stackmap.
name|bool
name|hasStackMap
argument_list|()
specifier|const
block|{
return|return
name|HasStackMap
return|;
block|}
name|void
name|setHasStackMap
parameter_list|(
name|bool
name|s
init|=
name|true
parameter_list|)
block|{
name|HasStackMap
operator|=
name|s
expr_stmt|;
block|}
comment|/// This method may be called any time after instruction
comment|/// selection is complete to determine if there is a call to builtin
comment|/// \@llvm.experimental.patchpoint.
name|bool
name|hasPatchPoint
argument_list|()
specifier|const
block|{
return|return
name|HasPatchPoint
return|;
block|}
name|void
name|setHasPatchPoint
parameter_list|(
name|bool
name|s
init|=
name|true
parameter_list|)
block|{
name|HasPatchPoint
operator|=
name|s
expr_stmt|;
block|}
comment|/// Return the minimum frame object index.
name|int
name|getObjectIndexBegin
argument_list|()
specifier|const
block|{
return|return
operator|-
name|NumFixedObjects
return|;
block|}
comment|/// Return one past the maximum frame object index.
name|int
name|getObjectIndexEnd
argument_list|()
specifier|const
block|{
return|return
operator|(
name|int
operator|)
name|Objects
operator|.
name|size
argument_list|()
operator|-
name|NumFixedObjects
return|;
block|}
comment|/// Return the number of fixed objects.
name|unsigned
name|getNumFixedObjects
argument_list|()
specifier|const
block|{
return|return
name|NumFixedObjects
return|;
block|}
comment|/// Return the number of objects.
name|unsigned
name|getNumObjects
argument_list|()
specifier|const
block|{
return|return
name|Objects
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// Map a frame index into the local object block
name|void
name|mapLocalFrameObject
parameter_list|(
name|int
name|ObjectIndex
parameter_list|,
name|int64_t
name|Offset
parameter_list|)
block|{
name|LocalFrameObjects
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|pair
operator|<
name|int
argument_list|,
name|int64_t
operator|>
operator|(
name|ObjectIndex
operator|,
name|Offset
operator|)
argument_list|)
expr_stmt|;
name|Objects
index|[
name|ObjectIndex
operator|+
name|NumFixedObjects
index|]
operator|.
name|PreAllocated
operator|=
name|true
expr_stmt|;
block|}
comment|/// Get the local offset mapping for a for an object.
name|std
operator|::
name|pair
operator|<
name|int
operator|,
name|int64_t
operator|>
name|getLocalFrameObjectMap
argument_list|(
argument|int i
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|i
operator|>=
literal|0
operator|&&
operator|(
name|unsigned
operator|)
name|i
operator|<
name|LocalFrameObjects
operator|.
name|size
argument_list|()
operator|&&
literal|"Invalid local object reference!"
argument_list|)
block|;
return|return
name|LocalFrameObjects
index|[
name|i
index|]
return|;
block|}
comment|/// Return the number of objects allocated into the local object block.
name|int64_t
name|getLocalFrameObjectCount
argument_list|()
specifier|const
block|{
return|return
name|LocalFrameObjects
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// Set the size of the local object blob.
name|void
name|setLocalFrameSize
parameter_list|(
name|int64_t
name|sz
parameter_list|)
block|{
name|LocalFrameSize
operator|=
name|sz
expr_stmt|;
block|}
comment|/// Get the size of the local object blob.
name|int64_t
name|getLocalFrameSize
argument_list|()
specifier|const
block|{
return|return
name|LocalFrameSize
return|;
block|}
comment|/// Required alignment of the local object blob,
comment|/// which is the strictest alignment of any object in it.
name|void
name|setLocalFrameMaxAlign
parameter_list|(
name|unsigned
name|Align
parameter_list|)
block|{
name|LocalFrameMaxAlign
operator|=
name|Align
expr_stmt|;
block|}
comment|/// Return the required alignment of the local object blob.
name|unsigned
name|getLocalFrameMaxAlign
argument_list|()
specifier|const
block|{
return|return
name|LocalFrameMaxAlign
return|;
block|}
comment|/// Get whether the local allocation blob should be allocated together or
comment|/// let PEI allocate the locals in it directly.
name|bool
name|getUseLocalStackAllocationBlock
argument_list|()
specifier|const
block|{
return|return
name|UseLocalStackAllocationBlock
return|;
block|}
comment|/// setUseLocalStackAllocationBlock - Set whether the local allocation blob
comment|/// should be allocated together or let PEI allocate the locals in it
comment|/// directly.
name|void
name|setUseLocalStackAllocationBlock
parameter_list|(
name|bool
name|v
parameter_list|)
block|{
name|UseLocalStackAllocationBlock
operator|=
name|v
expr_stmt|;
block|}
comment|/// Return true if the object was pre-allocated into the local block.
name|bool
name|isObjectPreAllocated
argument_list|(
name|int
name|ObjectIdx
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|unsigned
argument_list|(
name|ObjectIdx
operator|+
name|NumFixedObjects
argument_list|)
operator|<
name|Objects
operator|.
name|size
argument_list|()
operator|&&
literal|"Invalid Object Idx!"
argument_list|)
expr_stmt|;
return|return
name|Objects
index|[
name|ObjectIdx
operator|+
name|NumFixedObjects
index|]
operator|.
name|PreAllocated
return|;
block|}
comment|/// Return the size of the specified object.
name|int64_t
name|getObjectSize
argument_list|(
name|int
name|ObjectIdx
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|unsigned
argument_list|(
name|ObjectIdx
operator|+
name|NumFixedObjects
argument_list|)
operator|<
name|Objects
operator|.
name|size
argument_list|()
operator|&&
literal|"Invalid Object Idx!"
argument_list|)
expr_stmt|;
return|return
name|Objects
index|[
name|ObjectIdx
operator|+
name|NumFixedObjects
index|]
operator|.
name|Size
return|;
block|}
comment|/// Change the size of the specified stack object.
name|void
name|setObjectSize
parameter_list|(
name|int
name|ObjectIdx
parameter_list|,
name|int64_t
name|Size
parameter_list|)
block|{
name|assert
argument_list|(
name|unsigned
argument_list|(
name|ObjectIdx
operator|+
name|NumFixedObjects
argument_list|)
operator|<
name|Objects
operator|.
name|size
argument_list|()
operator|&&
literal|"Invalid Object Idx!"
argument_list|)
expr_stmt|;
name|Objects
index|[
name|ObjectIdx
operator|+
name|NumFixedObjects
index|]
operator|.
name|Size
operator|=
name|Size
expr_stmt|;
block|}
comment|/// Return the alignment of the specified stack object.
name|unsigned
name|getObjectAlignment
argument_list|(
name|int
name|ObjectIdx
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|unsigned
argument_list|(
name|ObjectIdx
operator|+
name|NumFixedObjects
argument_list|)
operator|<
name|Objects
operator|.
name|size
argument_list|()
operator|&&
literal|"Invalid Object Idx!"
argument_list|)
expr_stmt|;
return|return
name|Objects
index|[
name|ObjectIdx
operator|+
name|NumFixedObjects
index|]
operator|.
name|Alignment
return|;
block|}
comment|/// setObjectAlignment - Change the alignment of the specified stack object.
name|void
name|setObjectAlignment
parameter_list|(
name|int
name|ObjectIdx
parameter_list|,
name|unsigned
name|Align
parameter_list|)
block|{
name|assert
argument_list|(
name|unsigned
argument_list|(
name|ObjectIdx
operator|+
name|NumFixedObjects
argument_list|)
operator|<
name|Objects
operator|.
name|size
argument_list|()
operator|&&
literal|"Invalid Object Idx!"
argument_list|)
expr_stmt|;
name|Objects
index|[
name|ObjectIdx
operator|+
name|NumFixedObjects
index|]
operator|.
name|Alignment
operator|=
name|Align
expr_stmt|;
name|ensureMaxAlignment
argument_list|(
name|Align
argument_list|)
expr_stmt|;
block|}
comment|/// Return the underlying Alloca of the specified
comment|/// stack object if it exists. Returns 0 if none exists.
specifier|const
name|AllocaInst
modifier|*
name|getObjectAllocation
argument_list|(
name|int
name|ObjectIdx
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|unsigned
argument_list|(
name|ObjectIdx
operator|+
name|NumFixedObjects
argument_list|)
operator|<
name|Objects
operator|.
name|size
argument_list|()
operator|&&
literal|"Invalid Object Idx!"
argument_list|)
expr_stmt|;
return|return
name|Objects
index|[
name|ObjectIdx
operator|+
name|NumFixedObjects
index|]
operator|.
name|Alloca
return|;
block|}
comment|/// Return the assigned stack offset of the specified object
comment|/// from the incoming stack pointer.
name|int64_t
name|getObjectOffset
argument_list|(
name|int
name|ObjectIdx
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|unsigned
argument_list|(
name|ObjectIdx
operator|+
name|NumFixedObjects
argument_list|)
operator|<
name|Objects
operator|.
name|size
argument_list|()
operator|&&
literal|"Invalid Object Idx!"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|!
name|isDeadObjectIndex
argument_list|(
name|ObjectIdx
argument_list|)
operator|&&
literal|"Getting frame offset for a dead object?"
argument_list|)
expr_stmt|;
return|return
name|Objects
index|[
name|ObjectIdx
operator|+
name|NumFixedObjects
index|]
operator|.
name|SPOffset
return|;
block|}
name|bool
name|isObjectZExt
argument_list|(
name|int
name|ObjectIdx
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|unsigned
argument_list|(
name|ObjectIdx
operator|+
name|NumFixedObjects
argument_list|)
operator|<
name|Objects
operator|.
name|size
argument_list|()
operator|&&
literal|"Invalid Object Idx!"
argument_list|)
expr_stmt|;
return|return
name|Objects
index|[
name|ObjectIdx
operator|+
name|NumFixedObjects
index|]
operator|.
name|isZExt
return|;
block|}
name|void
name|setObjectZExt
parameter_list|(
name|int
name|ObjectIdx
parameter_list|,
name|bool
name|IsZExt
parameter_list|)
block|{
name|assert
argument_list|(
name|unsigned
argument_list|(
name|ObjectIdx
operator|+
name|NumFixedObjects
argument_list|)
operator|<
name|Objects
operator|.
name|size
argument_list|()
operator|&&
literal|"Invalid Object Idx!"
argument_list|)
expr_stmt|;
name|Objects
index|[
name|ObjectIdx
operator|+
name|NumFixedObjects
index|]
operator|.
name|isZExt
operator|=
name|IsZExt
expr_stmt|;
block|}
name|bool
name|isObjectSExt
argument_list|(
name|int
name|ObjectIdx
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|unsigned
argument_list|(
name|ObjectIdx
operator|+
name|NumFixedObjects
argument_list|)
operator|<
name|Objects
operator|.
name|size
argument_list|()
operator|&&
literal|"Invalid Object Idx!"
argument_list|)
expr_stmt|;
return|return
name|Objects
index|[
name|ObjectIdx
operator|+
name|NumFixedObjects
index|]
operator|.
name|isSExt
return|;
block|}
name|void
name|setObjectSExt
parameter_list|(
name|int
name|ObjectIdx
parameter_list|,
name|bool
name|IsSExt
parameter_list|)
block|{
name|assert
argument_list|(
name|unsigned
argument_list|(
name|ObjectIdx
operator|+
name|NumFixedObjects
argument_list|)
operator|<
name|Objects
operator|.
name|size
argument_list|()
operator|&&
literal|"Invalid Object Idx!"
argument_list|)
expr_stmt|;
name|Objects
index|[
name|ObjectIdx
operator|+
name|NumFixedObjects
index|]
operator|.
name|isSExt
operator|=
name|IsSExt
expr_stmt|;
block|}
comment|/// Set the stack frame offset of the specified object. The
comment|/// offset is relative to the stack pointer on entry to the function.
name|void
name|setObjectOffset
parameter_list|(
name|int
name|ObjectIdx
parameter_list|,
name|int64_t
name|SPOffset
parameter_list|)
block|{
name|assert
argument_list|(
name|unsigned
argument_list|(
name|ObjectIdx
operator|+
name|NumFixedObjects
argument_list|)
operator|<
name|Objects
operator|.
name|size
argument_list|()
operator|&&
literal|"Invalid Object Idx!"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|!
name|isDeadObjectIndex
argument_list|(
name|ObjectIdx
argument_list|)
operator|&&
literal|"Setting frame offset for a dead object?"
argument_list|)
expr_stmt|;
name|Objects
index|[
name|ObjectIdx
operator|+
name|NumFixedObjects
index|]
operator|.
name|SPOffset
operator|=
name|SPOffset
expr_stmt|;
block|}
comment|/// Return the number of bytes that must be allocated to hold
comment|/// all of the fixed size frame objects.  This is only valid after
comment|/// Prolog/Epilog code insertion has finalized the stack frame layout.
name|uint64_t
name|getStackSize
argument_list|()
specifier|const
block|{
return|return
name|StackSize
return|;
block|}
comment|/// Set the size of the stack.
name|void
name|setStackSize
parameter_list|(
name|uint64_t
name|Size
parameter_list|)
block|{
name|StackSize
operator|=
name|Size
expr_stmt|;
block|}
comment|/// Estimate and return the size of the stack frame.
name|unsigned
name|estimateStackSize
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
decl_stmt|;
comment|/// Return the correction for frame offsets.
name|int
name|getOffsetAdjustment
argument_list|()
specifier|const
block|{
return|return
name|OffsetAdjustment
return|;
block|}
comment|/// Set the correction for frame offsets.
name|void
name|setOffsetAdjustment
parameter_list|(
name|int
name|Adj
parameter_list|)
block|{
name|OffsetAdjustment
operator|=
name|Adj
expr_stmt|;
block|}
comment|/// Return the alignment in bytes that this function must be aligned to,
comment|/// which is greater than the default stack alignment provided by the target.
name|unsigned
name|getMaxAlignment
argument_list|()
specifier|const
block|{
return|return
name|MaxAlignment
return|;
block|}
comment|/// Make sure the function is at least Align bytes aligned.
name|void
name|ensureMaxAlignment
parameter_list|(
name|unsigned
name|Align
parameter_list|)
function_decl|;
comment|/// Return true if this function adjusts the stack -- e.g.,
comment|/// when calling another function. This is only valid during and after
comment|/// prolog/epilog code insertion.
name|bool
name|adjustsStack
argument_list|()
specifier|const
block|{
return|return
name|AdjustsStack
return|;
block|}
name|void
name|setAdjustsStack
parameter_list|(
name|bool
name|V
parameter_list|)
block|{
name|AdjustsStack
operator|=
name|V
expr_stmt|;
block|}
comment|/// Return true if the current function has any function calls.
name|bool
name|hasCalls
argument_list|()
specifier|const
block|{
return|return
name|HasCalls
return|;
block|}
name|void
name|setHasCalls
parameter_list|(
name|bool
name|V
parameter_list|)
block|{
name|HasCalls
operator|=
name|V
expr_stmt|;
block|}
comment|/// Returns true if the function contains opaque dynamic stack adjustments.
name|bool
name|hasOpaqueSPAdjustment
argument_list|()
specifier|const
block|{
return|return
name|HasOpaqueSPAdjustment
return|;
block|}
name|void
name|setHasOpaqueSPAdjustment
parameter_list|(
name|bool
name|B
parameter_list|)
block|{
name|HasOpaqueSPAdjustment
operator|=
name|B
expr_stmt|;
block|}
comment|/// Returns true if the function contains operations which will lower down to
comment|/// instructions which manipulate the stack pointer.
name|bool
name|hasCopyImplyingStackAdjustment
argument_list|()
specifier|const
block|{
return|return
name|HasCopyImplyingStackAdjustment
return|;
block|}
name|void
name|setHasCopyImplyingStackAdjustment
parameter_list|(
name|bool
name|B
parameter_list|)
block|{
name|HasCopyImplyingStackAdjustment
operator|=
name|B
expr_stmt|;
block|}
comment|/// Returns true if the function calls the llvm.va_start intrinsic.
name|bool
name|hasVAStart
argument_list|()
specifier|const
block|{
return|return
name|HasVAStart
return|;
block|}
name|void
name|setHasVAStart
parameter_list|(
name|bool
name|B
parameter_list|)
block|{
name|HasVAStart
operator|=
name|B
expr_stmt|;
block|}
comment|/// Returns true if the function is variadic and contains a musttail call.
name|bool
name|hasMustTailInVarArgFunc
argument_list|()
specifier|const
block|{
return|return
name|HasMustTailInVarArgFunc
return|;
block|}
name|void
name|setHasMustTailInVarArgFunc
parameter_list|(
name|bool
name|B
parameter_list|)
block|{
name|HasMustTailInVarArgFunc
operator|=
name|B
expr_stmt|;
block|}
comment|/// Returns true if the function contains a tail call.
name|bool
name|hasTailCall
argument_list|()
specifier|const
block|{
return|return
name|HasTailCall
return|;
block|}
name|void
name|setHasTailCall
parameter_list|()
block|{
name|HasTailCall
operator|=
name|true
expr_stmt|;
block|}
comment|/// Computes the maximum size of a callframe and the AdjustsStack property.
comment|/// This only works for targets defining
comment|/// TargetInstrInfo::getCallFrameSetupOpcode(), getCallFrameDestroyOpcode(),
comment|/// and getFrameSize().
comment|/// This is usually computed by the prologue epilogue inserter but some
comment|/// targets may call this to compute it earlier.
name|void
name|computeMaxCallFrameSize
parameter_list|(
specifier|const
name|MachineFunction
modifier|&
name|MF
parameter_list|)
function_decl|;
comment|/// Return the maximum size of a call frame that must be
comment|/// allocated for an outgoing function call.  This is only available if
comment|/// CallFrameSetup/Destroy pseudo instructions are used by the target, and
comment|/// then only during or after prolog/epilog code insertion.
comment|///
name|unsigned
name|getMaxCallFrameSize
argument_list|()
specifier|const
block|{
comment|// TODO: Enable this assert when targets are fixed.
comment|//assert(isMaxCallFrameSizeComputed()&& "MaxCallFrameSize not computed yet");
if|if
condition|(
operator|!
name|isMaxCallFrameSizeComputed
argument_list|()
condition|)
return|return
literal|0
return|;
return|return
name|MaxCallFrameSize
return|;
block|}
name|bool
name|isMaxCallFrameSizeComputed
argument_list|()
specifier|const
block|{
return|return
name|MaxCallFrameSize
operator|!=
operator|~
literal|0u
return|;
block|}
name|void
name|setMaxCallFrameSize
parameter_list|(
name|unsigned
name|S
parameter_list|)
block|{
name|MaxCallFrameSize
operator|=
name|S
expr_stmt|;
block|}
comment|/// Create a new object at a fixed location on the stack.
comment|/// All fixed objects should be created before other objects are created for
comment|/// efficiency. By default, fixed objects are not pointed to by LLVM IR
comment|/// values. This returns an index with a negative value.
name|int
name|CreateFixedObject
parameter_list|(
name|uint64_t
name|Size
parameter_list|,
name|int64_t
name|SPOffset
parameter_list|,
name|bool
name|Immutable
parameter_list|,
name|bool
name|isAliased
init|=
name|false
parameter_list|)
function_decl|;
comment|/// Create a spill slot at a fixed location on the stack.
comment|/// Returns an index with a negative value.
name|int
name|CreateFixedSpillStackObject
parameter_list|(
name|uint64_t
name|Size
parameter_list|,
name|int64_t
name|SPOffset
parameter_list|,
name|bool
name|Immutable
init|=
name|false
parameter_list|)
function_decl|;
comment|/// Returns true if the specified index corresponds to a fixed stack object.
name|bool
name|isFixedObjectIndex
argument_list|(
name|int
name|ObjectIdx
argument_list|)
decl|const
block|{
return|return
name|ObjectIdx
operator|<
literal|0
operator|&&
operator|(
name|ObjectIdx
operator|>=
operator|-
operator|(
name|int
operator|)
name|NumFixedObjects
operator|)
return|;
block|}
comment|/// Returns true if the specified index corresponds
comment|/// to an object that might be pointed to by an LLVM IR value.
name|bool
name|isAliasedObjectIndex
argument_list|(
name|int
name|ObjectIdx
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|unsigned
argument_list|(
name|ObjectIdx
operator|+
name|NumFixedObjects
argument_list|)
operator|<
name|Objects
operator|.
name|size
argument_list|()
operator|&&
literal|"Invalid Object Idx!"
argument_list|)
expr_stmt|;
return|return
name|Objects
index|[
name|ObjectIdx
operator|+
name|NumFixedObjects
index|]
operator|.
name|isAliased
return|;
block|}
comment|/// Returns true if the specified index corresponds to an immutable object.
name|bool
name|isImmutableObjectIndex
argument_list|(
name|int
name|ObjectIdx
argument_list|)
decl|const
block|{
comment|// Tail calling functions can clobber their function arguments.
if|if
condition|(
name|HasTailCall
condition|)
return|return
name|false
return|;
name|assert
argument_list|(
name|unsigned
argument_list|(
name|ObjectIdx
operator|+
name|NumFixedObjects
argument_list|)
operator|<
name|Objects
operator|.
name|size
argument_list|()
operator|&&
literal|"Invalid Object Idx!"
argument_list|)
expr_stmt|;
return|return
name|Objects
index|[
name|ObjectIdx
operator|+
name|NumFixedObjects
index|]
operator|.
name|isImmutable
return|;
block|}
comment|/// Marks the immutability of an object.
name|void
name|setIsImmutableObjectIndex
parameter_list|(
name|int
name|ObjectIdx
parameter_list|,
name|bool
name|Immutable
parameter_list|)
block|{
name|assert
argument_list|(
name|unsigned
argument_list|(
name|ObjectIdx
operator|+
name|NumFixedObjects
argument_list|)
operator|<
name|Objects
operator|.
name|size
argument_list|()
operator|&&
literal|"Invalid Object Idx!"
argument_list|)
expr_stmt|;
name|Objects
index|[
name|ObjectIdx
operator|+
name|NumFixedObjects
index|]
operator|.
name|isImmutable
operator|=
name|Immutable
expr_stmt|;
block|}
comment|/// Returns true if the specified index corresponds to a spill slot.
name|bool
name|isSpillSlotObjectIndex
argument_list|(
name|int
name|ObjectIdx
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|unsigned
argument_list|(
name|ObjectIdx
operator|+
name|NumFixedObjects
argument_list|)
operator|<
name|Objects
operator|.
name|size
argument_list|()
operator|&&
literal|"Invalid Object Idx!"
argument_list|)
expr_stmt|;
return|return
name|Objects
index|[
name|ObjectIdx
operator|+
name|NumFixedObjects
index|]
operator|.
name|isSpillSlot
return|;
block|}
name|bool
name|isStatepointSpillSlotObjectIndex
argument_list|(
name|int
name|ObjectIdx
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|unsigned
argument_list|(
name|ObjectIdx
operator|+
name|NumFixedObjects
argument_list|)
operator|<
name|Objects
operator|.
name|size
argument_list|()
operator|&&
literal|"Invalid Object Idx!"
argument_list|)
expr_stmt|;
return|return
name|Objects
index|[
name|ObjectIdx
operator|+
name|NumFixedObjects
index|]
operator|.
name|isStatepointSpillSlot
return|;
block|}
comment|/// Returns true if the specified index corresponds to a dead object.
name|bool
name|isDeadObjectIndex
argument_list|(
name|int
name|ObjectIdx
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|unsigned
argument_list|(
name|ObjectIdx
operator|+
name|NumFixedObjects
argument_list|)
operator|<
name|Objects
operator|.
name|size
argument_list|()
operator|&&
literal|"Invalid Object Idx!"
argument_list|)
expr_stmt|;
return|return
name|Objects
index|[
name|ObjectIdx
operator|+
name|NumFixedObjects
index|]
operator|.
name|Size
operator|==
operator|~
literal|0ULL
return|;
block|}
comment|/// Returns true if the specified index corresponds to a variable sized
comment|/// object.
name|bool
name|isVariableSizedObjectIndex
argument_list|(
name|int
name|ObjectIdx
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|unsigned
argument_list|(
name|ObjectIdx
operator|+
name|NumFixedObjects
argument_list|)
operator|<
name|Objects
operator|.
name|size
argument_list|()
operator|&&
literal|"Invalid Object Idx!"
argument_list|)
expr_stmt|;
return|return
name|Objects
index|[
name|ObjectIdx
operator|+
name|NumFixedObjects
index|]
operator|.
name|Size
operator|==
literal|0
return|;
block|}
name|void
name|markAsStatepointSpillSlotObjectIndex
parameter_list|(
name|int
name|ObjectIdx
parameter_list|)
block|{
name|assert
argument_list|(
name|unsigned
argument_list|(
name|ObjectIdx
operator|+
name|NumFixedObjects
argument_list|)
operator|<
name|Objects
operator|.
name|size
argument_list|()
operator|&&
literal|"Invalid Object Idx!"
argument_list|)
expr_stmt|;
name|Objects
index|[
name|ObjectIdx
operator|+
name|NumFixedObjects
index|]
operator|.
name|isStatepointSpillSlot
operator|=
name|true
expr_stmt|;
name|assert
argument_list|(
name|isStatepointSpillSlotObjectIndex
argument_list|(
name|ObjectIdx
argument_list|)
operator|&&
literal|"inconsistent"
argument_list|)
expr_stmt|;
block|}
comment|/// Create a new statically sized stack object, returning
comment|/// a nonnegative identifier to represent it.
name|int
name|CreateStackObject
parameter_list|(
name|uint64_t
name|Size
parameter_list|,
name|unsigned
name|Alignment
parameter_list|,
name|bool
name|isSS
parameter_list|,
specifier|const
name|AllocaInst
modifier|*
name|Alloca
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// Create a new statically sized stack object that represents a spill slot,
comment|/// returning a nonnegative identifier to represent it.
name|int
name|CreateSpillStackObject
parameter_list|(
name|uint64_t
name|Size
parameter_list|,
name|unsigned
name|Alignment
parameter_list|)
function_decl|;
comment|/// Remove or mark dead a statically sized stack object.
name|void
name|RemoveStackObject
parameter_list|(
name|int
name|ObjectIdx
parameter_list|)
block|{
comment|// Mark it dead.
name|Objects
index|[
name|ObjectIdx
operator|+
name|NumFixedObjects
index|]
operator|.
name|Size
operator|=
operator|~
literal|0ULL
expr_stmt|;
block|}
comment|/// Notify the MachineFrameInfo object that a variable sized object has been
comment|/// created.  This must be created whenever a variable sized object is
comment|/// created, whether or not the index returned is actually used.
name|int
name|CreateVariableSizedObject
parameter_list|(
name|unsigned
name|Alignment
parameter_list|,
specifier|const
name|AllocaInst
modifier|*
name|Alloca
parameter_list|)
function_decl|;
comment|/// Returns a reference to call saved info vector for the current function.
specifier|const
name|std
operator|::
name|vector
operator|<
name|CalleeSavedInfo
operator|>
operator|&
name|getCalleeSavedInfo
argument_list|()
specifier|const
block|{
return|return
name|CSInfo
return|;
block|}
comment|/// Used by prolog/epilog inserter to set the function's callee saved
comment|/// information.
name|void
name|setCalleeSavedInfo
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|CalleeSavedInfo
operator|>
operator|&
name|CSI
argument_list|)
block|{
name|CSInfo
operator|=
name|CSI
expr_stmt|;
block|}
comment|/// Has the callee saved info been calculated yet?
name|bool
name|isCalleeSavedInfoValid
argument_list|()
specifier|const
block|{
return|return
name|CSIValid
return|;
block|}
name|void
name|setCalleeSavedInfoValid
parameter_list|(
name|bool
name|v
parameter_list|)
block|{
name|CSIValid
operator|=
name|v
expr_stmt|;
block|}
name|MachineBasicBlock
operator|*
name|getSavePoint
argument_list|()
specifier|const
block|{
return|return
name|Save
return|;
block|}
name|void
name|setSavePoint
parameter_list|(
name|MachineBasicBlock
modifier|*
name|NewSave
parameter_list|)
block|{
name|Save
operator|=
name|NewSave
expr_stmt|;
block|}
name|MachineBasicBlock
operator|*
name|getRestorePoint
argument_list|()
specifier|const
block|{
return|return
name|Restore
return|;
block|}
name|void
name|setRestorePoint
parameter_list|(
name|MachineBasicBlock
modifier|*
name|NewRestore
parameter_list|)
block|{
name|Restore
operator|=
name|NewRestore
expr_stmt|;
block|}
comment|/// Return a set of physical registers that are pristine.
comment|///
comment|/// Pristine registers hold a value that is useless to the current function,
comment|/// but that must be preserved - they are callee saved registers that are not
comment|/// saved.
comment|///
comment|/// Before the PrologueEpilogueInserter has placed the CSR spill code, this
comment|/// method always returns an empty set.
name|BitVector
name|getPristineRegs
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
decl_stmt|;
comment|/// Used by the MachineFunction printer to print information about
comment|/// stack objects. Implemented in MachineFunction.cpp.
name|void
name|print
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|,
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
comment|/// dump - Print the function to stderr.
name|void
name|dump
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

