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
name|DataLayout
decl_stmt|;
name|class
name|TargetRegisterClass
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|TargetFrameLowering
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
name|class
name|BitVector
decl_stmt|;
name|class
name|Value
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
comment|// StackObject - Represent a single object allocated on the stack.
struct|struct
name|StackObject
block|{
comment|// SPOffset - The offset of this object from the stack pointer on entry to
comment|// the function.  This field has no meaning for a variable sized element.
name|int64_t
name|SPOffset
decl_stmt|;
comment|// The size of this object on the stack. 0 means a variable sized object,
comment|// ~0ULL means a dead object.
name|uint64_t
name|Size
decl_stmt|;
comment|// Alignment - The required alignment of this stack slot.
name|unsigned
name|Alignment
decl_stmt|;
comment|// isImmutable - If true, the value of the stack object is set before
comment|// entering the function and is not modified inside the function. By
comment|// default, fixed objects are immutable unless marked otherwise.
name|bool
name|isImmutable
decl_stmt|;
comment|// isSpillSlot - If true the stack object is used as spill slot. It
comment|// cannot alias any other memory objects.
name|bool
name|isSpillSlot
decl_stmt|;
comment|// MayNeedSP - If true the stack object triggered the creation of the stack
comment|// protector. We should allocate this object right after the stack
comment|// protector.
name|bool
name|MayNeedSP
decl_stmt|;
comment|/// Alloca - If this stack object is originated from an Alloca instruction
comment|/// this value saves the original IR allocation. Can be NULL.
specifier|const
name|AllocaInst
modifier|*
name|Alloca
decl_stmt|;
comment|// PreAllocated - If true, the object was mapped into the local frame
comment|// block and doesn't need additional handling for allocation beyond that.
name|bool
name|PreAllocated
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
argument|bool NSP
argument_list|,
argument|const AllocaInst *Val
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
name|MayNeedSP
argument_list|(
name|NSP
argument_list|)
operator|,
name|Alloca
argument_list|(
name|Val
argument_list|)
operator|,
name|PreAllocated
argument_list|(
argument|false
argument_list|)
block|{}
block|}
struct|;
specifier|const
name|TargetMachine
modifier|&
name|TM
decl_stmt|;
comment|/// Objects - The list of stack objects allocated...
comment|///
name|std
operator|::
name|vector
operator|<
name|StackObject
operator|>
name|Objects
expr_stmt|;
comment|/// NumFixedObjects - This contains the number of fixed objects contained on
comment|/// the stack.  Because fixed objects are stored at a negative index in the
comment|/// Objects list, this is also the index to the 0th object in the list.
comment|///
name|unsigned
name|NumFixedObjects
decl_stmt|;
comment|/// HasVarSizedObjects - This boolean keeps track of whether any variable
comment|/// sized objects have been allocated yet.
comment|///
name|bool
name|HasVarSizedObjects
decl_stmt|;
comment|/// FrameAddressTaken - This boolean keeps track of whether there is a call
comment|/// to builtin \@llvm.frameaddress.
name|bool
name|FrameAddressTaken
decl_stmt|;
comment|/// ReturnAddressTaken - This boolean keeps track of whether there is a call
comment|/// to builtin \@llvm.returnaddress.
name|bool
name|ReturnAddressTaken
decl_stmt|;
comment|/// StackSize - The prolog/epilog code inserter calculates the final stack
comment|/// offsets for all of the fixed size objects, updating the Objects list
comment|/// above.  It then updates StackSize to contain the number of bytes that need
comment|/// to be allocated on entry to the function.
comment|///
name|uint64_t
name|StackSize
decl_stmt|;
comment|/// OffsetAdjustment - The amount that a frame offset needs to be adjusted to
comment|/// have the actual offset from the stack/frame pointer.  The exact usage of
comment|/// this is target-dependent, but it is typically used to adjust between
comment|/// SP-relative and FP-relative offsets.  E.G., if objects are accessed via
comment|/// SP then OffsetAdjustment is zero; if FP is used, OffsetAdjustment is set
comment|/// to the distance between the initial SP and the value in FP.  For many
comment|/// targets, this value is only used when generating debug info (via
comment|/// TargetRegisterInfo::getFrameIndexOffset); when generating code, the
comment|/// corresponding adjustments are performed directly.
name|int
name|OffsetAdjustment
decl_stmt|;
comment|/// MaxAlignment - The prolog/epilog code inserter may process objects
comment|/// that require greater alignment than the default alignment the target
comment|/// provides. To handle this, MaxAlignment is set to the maximum alignment
comment|/// needed by the objects on the current frame.  If this is greater than the
comment|/// native alignment maintained by the compiler, dynamic alignment code will
comment|/// be needed.
comment|///
name|unsigned
name|MaxAlignment
decl_stmt|;
comment|/// AdjustsStack - Set to true if this function adjusts the stack -- e.g.,
comment|/// when calling another function. This is only valid during and after
comment|/// prolog/epilog code insertion.
name|bool
name|AdjustsStack
decl_stmt|;
comment|/// HasCalls - Set to true if this function has any function calls.
name|bool
name|HasCalls
decl_stmt|;
comment|/// StackProtectorIdx - The frame index for the stack protector.
name|int
name|StackProtectorIdx
decl_stmt|;
comment|/// FunctionContextIdx - The frame index for the function context. Used for
comment|/// SjLj exceptions.
name|int
name|FunctionContextIdx
decl_stmt|;
comment|/// MaxCallFrameSize - This contains the size of the largest call frame if the
comment|/// target uses frame setup/destroy pseudo instructions (as defined in the
comment|/// TargetFrameInfo class).  This information is important for frame pointer
comment|/// elimination.  If is only valid during and after prolog/epilog code
comment|/// insertion.
comment|///
name|unsigned
name|MaxCallFrameSize
decl_stmt|;
comment|/// CSInfo - The prolog/epilog code inserter fills in this vector with each
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
comment|/// CSIValid - Has CSInfo been set yet?
name|bool
name|CSIValid
decl_stmt|;
comment|/// LocalFrameObjects - References to frame indices which are mapped
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
comment|/// LocalFrameSize - Size of the pre-allocated local frame block.
name|int64_t
name|LocalFrameSize
decl_stmt|;
comment|/// Required alignment of the local object blob, which is the strictest
comment|/// alignment of any object in it.
name|unsigned
name|LocalFrameMaxAlign
decl_stmt|;
comment|/// Whether the local object blob needs to be allocated together. If not,
comment|/// PEI should ignore the isPreAllocated flags on the stack objects and
comment|/// just allocate them normally.
name|bool
name|UseLocalStackAllocationBlock
decl_stmt|;
comment|/// Whether the "realign-stack" option is on.
name|bool
name|RealignOption
decl_stmt|;
specifier|const
name|TargetFrameLowering
operator|*
name|getFrameLowering
argument_list|()
specifier|const
expr_stmt|;
name|public
label|:
name|explicit
name|MachineFrameInfo
argument_list|(
argument|const TargetMachine&TM
argument_list|,
argument|bool RealignOpt
argument_list|)
block|:
name|TM
argument_list|(
name|TM
argument_list|)
operator|,
name|RealignOption
argument_list|(
argument|RealignOpt
argument_list|)
block|{
name|StackSize
operator|=
name|NumFixedObjects
operator|=
name|OffsetAdjustment
operator|=
name|MaxAlignment
operator|=
literal|0
block|;
name|HasVarSizedObjects
operator|=
name|false
block|;
name|FrameAddressTaken
operator|=
name|false
block|;
name|ReturnAddressTaken
operator|=
name|false
block|;
name|AdjustsStack
operator|=
name|false
block|;
name|HasCalls
operator|=
name|false
block|;
name|StackProtectorIdx
operator|=
operator|-
literal|1
block|;
name|FunctionContextIdx
operator|=
operator|-
literal|1
block|;
name|MaxCallFrameSize
operator|=
literal|0
block|;
name|CSIValid
operator|=
name|false
block|;
name|LocalFrameSize
operator|=
literal|0
block|;
name|LocalFrameMaxAlign
operator|=
literal|0
block|;
name|UseLocalStackAllocationBlock
operator|=
name|false
block|;   }
comment|/// hasStackObjects - Return true if there are any stack objects in this
comment|/// function.
comment|///
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
comment|/// hasVarSizedObjects - This method may be called any time after instruction
comment|/// selection is complete to determine if the stack frame for this function
comment|/// contains any variable sized objects.
comment|///
name|bool
name|hasVarSizedObjects
argument_list|()
specifier|const
block|{
return|return
name|HasVarSizedObjects
return|;
block|}
comment|/// getStackProtectorIndex/setStackProtectorIndex - Return the index for the
comment|/// stack protector object.
comment|///
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
comment|/// getFunctionContextIndex/setFunctionContextIndex - Return the index for the
comment|/// function context object. This object is used for SjLj exceptions.
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
comment|/// isFrameAddressTaken - This method may be called any time after instruction
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
comment|/// isReturnAddressTaken - This method may be called any time after
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
comment|/// getObjectIndexBegin - Return the minimum frame object index.
comment|///
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
comment|/// getObjectIndexEnd - Return one past the maximum frame object index.
comment|///
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
comment|/// getNumFixedObjects - Return the number of fixed objects.
name|unsigned
name|getNumFixedObjects
argument_list|()
specifier|const
block|{
return|return
name|NumFixedObjects
return|;
block|}
comment|/// getNumObjects - Return the number of objects.
comment|///
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
comment|/// mapLocalFrameObject - Map a frame index into the local object block
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
comment|/// getLocalFrameObjectMap - Get the local offset mapping for a for an object
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
comment|/// getLocalFrameObjectCount - Return the number of objects allocated into
comment|/// the local object block.
name|int64_t
name|getLocalFrameObjectCount
parameter_list|()
block|{
return|return
name|LocalFrameObjects
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// setLocalFrameSize - Set the size of the local object blob.
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
comment|/// getLocalFrameSize - Get the size of the local object blob.
name|int64_t
name|getLocalFrameSize
argument_list|()
specifier|const
block|{
return|return
name|LocalFrameSize
return|;
block|}
comment|/// setLocalFrameMaxAlign - Required alignment of the local object blob,
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
comment|/// getLocalFrameMaxAlign - Return the required alignment of the local
comment|/// object blob.
name|unsigned
name|getLocalFrameMaxAlign
argument_list|()
specifier|const
block|{
return|return
name|LocalFrameMaxAlign
return|;
block|}
comment|/// getUseLocalStackAllocationBlock - Get whether the local allocation blob
comment|/// should be allocated together or let PEI allocate the locals in it
comment|/// directly.
name|bool
name|getUseLocalStackAllocationBlock
parameter_list|()
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
comment|/// isObjectPreAllocated - Return true if the object was pre-allocated into
comment|/// the local block.
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
comment|/// getObjectSize - Return the size of the specified object.
comment|///
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
comment|/// setObjectSize - Change the size of the specified stack object.
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
comment|/// getObjectAlignment - Return the alignment of the specified stack object.
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
comment|/// getObjectAllocation - Return the underlying Alloca of the specified
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
comment|/// NeedsStackProtector - Returns true if the object may need stack
comment|/// protectors.
name|bool
name|MayNeedStackProtector
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
name|MayNeedSP
return|;
block|}
comment|/// getObjectOffset - Return the assigned stack offset of the specified object
comment|/// from the incoming stack pointer.
comment|///
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
comment|/// setObjectOffset - Set the stack frame offset of the specified object.  The
comment|/// offset is relative to the stack pointer on entry to the function.
comment|///
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
comment|/// getStackSize - Return the number of bytes that must be allocated to hold
comment|/// all of the fixed size frame objects.  This is only valid after
comment|/// Prolog/Epilog code insertion has finalized the stack frame layout.
comment|///
name|uint64_t
name|getStackSize
argument_list|()
specifier|const
block|{
return|return
name|StackSize
return|;
block|}
comment|/// setStackSize - Set the size of the stack...
comment|///
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
comment|/// getOffsetAdjustment - Return the correction for frame offsets.
comment|///
name|int
name|getOffsetAdjustment
argument_list|()
specifier|const
block|{
return|return
name|OffsetAdjustment
return|;
block|}
comment|/// setOffsetAdjustment - Set the correction for frame offsets.
comment|///
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
comment|/// getMaxAlignment - Return the alignment in bytes that this function must be
comment|/// aligned to, which is greater than the default stack alignment provided by
comment|/// the target.
comment|///
name|unsigned
name|getMaxAlignment
argument_list|()
specifier|const
block|{
return|return
name|MaxAlignment
return|;
block|}
comment|/// ensureMaxAlignment - Make sure the function is at least Align bytes
comment|/// aligned.
name|void
name|ensureMaxAlignment
parameter_list|(
name|unsigned
name|Align
parameter_list|)
function_decl|;
comment|/// AdjustsStack - Return true if this function adjusts the stack -- e.g.,
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
comment|/// hasCalls - Return true if the current function has any function calls.
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
comment|/// getMaxCallFrameSize - Return the maximum size of a call frame that must be
comment|/// allocated for an outgoing function call.  This is only available if
comment|/// CallFrameSetup/Destroy pseudo instructions are used by the target, and
comment|/// then only during or after prolog/epilog code insertion.
comment|///
name|unsigned
name|getMaxCallFrameSize
argument_list|()
specifier|const
block|{
return|return
name|MaxCallFrameSize
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
comment|/// CreateFixedObject - Create a new object at a fixed location on the stack.
comment|/// All fixed objects should be created before other objects are created for
comment|/// efficiency. By default, fixed objects are immutable. This returns an
comment|/// index with a negative value.
comment|///
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
parameter_list|)
function_decl|;
comment|/// isFixedObjectIndex - Returns true if the specified index corresponds to a
comment|/// fixed stack object.
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
comment|/// isImmutableObjectIndex - Returns true if the specified index corresponds
comment|/// to an immutable object.
name|bool
name|isImmutableObjectIndex
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
name|isImmutable
return|;
block|}
comment|/// isSpillSlotObjectIndex - Returns true if the specified index corresponds
comment|/// to a spill slot..
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
comment|/// isDeadObjectIndex - Returns true if the specified index corresponds to
comment|/// a dead object.
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
comment|/// CreateStackObject - Create a new statically sized stack object, returning
comment|/// a nonnegative identifier to represent it.
comment|///
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
name|bool
name|MayNeedSP
init|=
name|false
parameter_list|,
specifier|const
name|AllocaInst
modifier|*
name|Alloca
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// CreateSpillStackObject - Create a new statically sized stack object that
comment|/// represents a spill slot, returning a nonnegative identifier to represent
comment|/// it.
comment|///
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
comment|/// RemoveStackObject - Remove or mark dead a statically sized stack object.
comment|///
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
comment|/// CreateVariableSizedObject - Notify the MachineFrameInfo object that a
comment|/// variable sized object has been created.  This must be created whenever a
comment|/// variable sized object is created, whether or not the index returned is
comment|/// actually used.
comment|///
name|int
name|CreateVariableSizedObject
parameter_list|(
name|unsigned
name|Alignment
parameter_list|)
function_decl|;
comment|/// getCalleeSavedInfo - Returns a reference to call saved info vector for the
comment|/// current function.
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
comment|/// setCalleeSavedInfo - Used by prolog/epilog inserter to set the function's
comment|/// callee saved information.
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
comment|/// isCalleeSavedInfoValid - Has the callee saved info been calculated yet?
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
comment|/// getPristineRegs - Return a set of physical registers that are pristine on
comment|/// entry to the MBB.
comment|///
comment|/// Pristine registers hold a value that is useless to the current function,
comment|/// but that must be preserved - they are callee saved registers that have not
comment|/// been saved yet.
comment|///
comment|/// Before the PrologueEpilogueInserter has placed the CSR spill code, this
comment|/// method always returns an empty set.
name|BitVector
name|getPristineRegs
argument_list|(
specifier|const
name|MachineBasicBlock
operator|*
name|MBB
argument_list|)
decl|const
decl_stmt|;
comment|/// print - Used by the MachineFunction printer to print information about
comment|/// stack objects. Implemented in MachineFunction.cpp
comment|///
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
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

