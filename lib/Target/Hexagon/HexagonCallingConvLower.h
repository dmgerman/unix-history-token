begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- HexagonCallingConvLower.h - Calling Conventions ---------*- C++ -*-===//
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
comment|// This file declares the Hexagon_CCState class, used for lowering
end_comment

begin_comment
comment|// and implementing calling conventions. Adapted from the target independent
end_comment

begin_comment
comment|// version but this handles calls to varargs functions
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
name|LLVM_Hexagon_CODEGEN_CALLINGCONVLOWER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_Hexagon_CODEGEN_CALLINGCONVLOWER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/CallingConvLower.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAGNodes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ValueTypes.h"
end_include

begin_comment
comment|//
end_comment

begin_comment
comment|// Need to handle varargs.
end_comment

begin_comment
comment|//
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|TargetRegisterInfo
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
name|class
name|Hexagon_CCState
decl_stmt|;
name|class
name|SDNode
decl_stmt|;
comment|/// Hexagon_CCAssignFn - This function assigns a location for Val, updating
comment|/// State to reflect the change.
typedef|typedef
name|bool
name|Hexagon_CCAssignFn
argument_list|(
name|unsigned
name|ValNo
argument_list|,
name|EVT
name|ValVT
argument_list|,
name|EVT
name|LocVT
argument_list|,
name|CCValAssign
operator|::
name|LocInfo
name|LocInfo
argument_list|,
name|ISD
operator|::
name|ArgFlagsTy
name|ArgFlags
argument_list|,
name|Hexagon_CCState
operator|&
name|State
argument_list|,
name|int
name|NonVarArgsParams
argument_list|,
name|int
name|CurrentParam
argument_list|,
name|bool
name|ForceMem
argument_list|)
typedef|;
comment|/// CCState - This class holds information needed while lowering arguments and
comment|/// return values.  It captures which registers are already assigned and which
comment|/// stack slots are used.  It provides accessors to allocate these values.
name|class
name|Hexagon_CCState
block|{
name|CallingConv
operator|::
name|ID
name|CallingConv
expr_stmt|;
name|bool
name|IsVarArg
decl_stmt|;
specifier|const
name|TargetMachine
modifier|&
name|TM
decl_stmt|;
name|SmallVectorImpl
operator|<
name|CCValAssign
operator|>
operator|&
name|Locs
expr_stmt|;
name|LLVMContext
modifier|&
name|Context
decl_stmt|;
name|unsigned
name|StackOffset
decl_stmt|;
name|SmallVector
operator|<
name|uint32_t
operator|,
literal|16
operator|>
name|UsedRegs
expr_stmt|;
name|public
label|:
name|Hexagon_CCState
argument_list|(
argument|CallingConv::ID CC
argument_list|,
argument|bool isVarArg
argument_list|,
argument|const TargetMachine&TM
argument_list|,
argument|SmallVectorImpl<CCValAssign>&locs
argument_list|,
argument|LLVMContext&c
argument_list|)
empty_stmt|;
name|void
name|addLoc
parameter_list|(
specifier|const
name|CCValAssign
modifier|&
name|V
parameter_list|)
block|{
name|Locs
operator|.
name|push_back
argument_list|(
name|V
argument_list|)
expr_stmt|;
block|}
name|LLVMContext
operator|&
name|getContext
argument_list|()
specifier|const
block|{
return|return
name|Context
return|;
block|}
specifier|const
name|TargetMachine
operator|&
name|getTarget
argument_list|()
specifier|const
block|{
return|return
name|TM
return|;
block|}
name|unsigned
name|getCallingConv
argument_list|()
specifier|const
block|{
return|return
name|CallingConv
return|;
block|}
name|bool
name|isVarArg
argument_list|()
specifier|const
block|{
return|return
name|IsVarArg
return|;
block|}
name|unsigned
name|getNextStackOffset
argument_list|()
specifier|const
block|{
return|return
name|StackOffset
return|;
block|}
comment|/// isAllocated - Return true if the specified register (or an alias) is
comment|/// allocated.
name|bool
name|isAllocated
argument_list|(
name|unsigned
name|Reg
argument_list|)
decl|const
block|{
return|return
name|UsedRegs
index|[
name|Reg
operator|/
literal|32
index|]
operator|&
operator|(
literal|1
operator|<<
operator|(
name|Reg
operator|&
literal|31
operator|)
operator|)
return|;
block|}
comment|/// AnalyzeFormalArguments - Analyze an ISD::FORMAL_ARGUMENTS node,
comment|/// incorporating info about the formals into this state.
name|void
name|AnalyzeFormalArguments
argument_list|(
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|InputArg
operator|>
operator|&
name|Ins
argument_list|,
name|Hexagon_CCAssignFn
name|Fn
argument_list|,
name|unsigned
name|SretValueInRegs
argument_list|)
decl_stmt|;
comment|/// AnalyzeReturn - Analyze the returned values of an ISD::RET node,
comment|/// incorporating info about the result values into this state.
name|void
name|AnalyzeReturn
argument_list|(
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|OutputArg
operator|>
operator|&
name|Outs
argument_list|,
name|Hexagon_CCAssignFn
name|Fn
argument_list|,
name|unsigned
name|SretValueInRegs
argument_list|)
decl_stmt|;
comment|/// AnalyzeCallOperands - Analyze an ISD::CALL node, incorporating info
comment|/// about the passed values into this state.
name|void
name|AnalyzeCallOperands
argument_list|(
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|OutputArg
operator|>
operator|&
name|Outs
argument_list|,
name|Hexagon_CCAssignFn
name|Fn
argument_list|,
name|int
name|NonVarArgsParams
argument_list|,
name|unsigned
name|SretValueSize
argument_list|)
decl_stmt|;
comment|/// AnalyzeCallOperands - Same as above except it takes vectors of types
comment|/// and argument flags.
name|void
name|AnalyzeCallOperands
argument_list|(
name|SmallVectorImpl
operator|<
name|EVT
operator|>
operator|&
name|ArgVTs
argument_list|,
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|ArgFlagsTy
operator|>
operator|&
name|Flags
argument_list|,
name|Hexagon_CCAssignFn
name|Fn
argument_list|)
decl_stmt|;
comment|/// AnalyzeCallResult - Analyze the return values of an ISD::CALL node,
comment|/// incorporating info about the passed values into this state.
name|void
name|AnalyzeCallResult
argument_list|(
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|InputArg
operator|>
operator|&
name|Ins
argument_list|,
name|Hexagon_CCAssignFn
name|Fn
argument_list|,
name|unsigned
name|SretValueInRegs
argument_list|)
decl_stmt|;
comment|/// AnalyzeCallResult - Same as above except it's specialized for calls which
comment|/// produce a single value.
name|void
name|AnalyzeCallResult
parameter_list|(
name|EVT
name|VT
parameter_list|,
name|Hexagon_CCAssignFn
name|Fn
parameter_list|)
function_decl|;
comment|/// getFirstUnallocated - Return the first unallocated register in the set, or
comment|/// NumRegs if they are all allocated.
name|unsigned
name|getFirstUnallocated
argument_list|(
specifier|const
name|unsigned
operator|*
name|Regs
argument_list|,
name|unsigned
name|NumRegs
argument_list|)
decl|const
block|{
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|NumRegs
condition|;
operator|++
name|i
control|)
if|if
condition|(
operator|!
name|isAllocated
argument_list|(
name|Regs
index|[
name|i
index|]
argument_list|)
condition|)
return|return
name|i
return|;
return|return
name|NumRegs
return|;
block|}
comment|/// AllocateReg - Attempt to allocate one register.  If it is not available,
comment|/// return zero.  Otherwise, return the register, marking it and any aliases
comment|/// as allocated.
name|unsigned
name|AllocateReg
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
block|{
if|if
condition|(
name|isAllocated
argument_list|(
name|Reg
argument_list|)
condition|)
return|return
literal|0
return|;
name|MarkAllocated
argument_list|(
name|Reg
argument_list|)
expr_stmt|;
return|return
name|Reg
return|;
block|}
comment|/// Version of AllocateReg with extra register to be shadowed.
name|unsigned
name|AllocateReg
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
name|unsigned
name|ShadowReg
parameter_list|)
block|{
if|if
condition|(
name|isAllocated
argument_list|(
name|Reg
argument_list|)
condition|)
return|return
literal|0
return|;
name|MarkAllocated
argument_list|(
name|Reg
argument_list|)
expr_stmt|;
name|MarkAllocated
argument_list|(
name|ShadowReg
argument_list|)
expr_stmt|;
return|return
name|Reg
return|;
block|}
comment|/// AllocateReg - Attempt to allocate one of the specified registers.  If none
comment|/// are available, return zero.  Otherwise, return the first one available,
comment|/// marking it and any aliases as allocated.
name|unsigned
name|AllocateReg
parameter_list|(
specifier|const
name|unsigned
modifier|*
name|Regs
parameter_list|,
name|unsigned
name|NumRegs
parameter_list|)
block|{
name|unsigned
name|FirstUnalloc
init|=
name|getFirstUnallocated
argument_list|(
name|Regs
argument_list|,
name|NumRegs
argument_list|)
decl_stmt|;
if|if
condition|(
name|FirstUnalloc
operator|==
name|NumRegs
condition|)
return|return
literal|0
return|;
comment|// Didn't find the reg.
comment|// Mark the register and any aliases as allocated.
name|unsigned
name|Reg
init|=
name|Regs
index|[
name|FirstUnalloc
index|]
decl_stmt|;
name|MarkAllocated
argument_list|(
name|Reg
argument_list|)
expr_stmt|;
return|return
name|Reg
return|;
block|}
comment|/// Version of AllocateReg with list of registers to be shadowed.
name|unsigned
name|AllocateReg
parameter_list|(
specifier|const
name|unsigned
modifier|*
name|Regs
parameter_list|,
specifier|const
name|unsigned
modifier|*
name|ShadowRegs
parameter_list|,
name|unsigned
name|NumRegs
parameter_list|)
block|{
name|unsigned
name|FirstUnalloc
init|=
name|getFirstUnallocated
argument_list|(
name|Regs
argument_list|,
name|NumRegs
argument_list|)
decl_stmt|;
if|if
condition|(
name|FirstUnalloc
operator|==
name|NumRegs
condition|)
return|return
literal|0
return|;
comment|// Didn't find the reg.
comment|// Mark the register and any aliases as allocated.
name|unsigned
name|Reg
init|=
name|Regs
index|[
name|FirstUnalloc
index|]
decl_stmt|,
name|ShadowReg
init|=
name|ShadowRegs
index|[
name|FirstUnalloc
index|]
decl_stmt|;
name|MarkAllocated
argument_list|(
name|Reg
argument_list|)
expr_stmt|;
name|MarkAllocated
argument_list|(
name|ShadowReg
argument_list|)
expr_stmt|;
return|return
name|Reg
return|;
block|}
comment|/// AllocateStack - Allocate a chunk of stack space with the specified size
comment|/// and alignment.
name|unsigned
name|AllocateStack
parameter_list|(
name|unsigned
name|Size
parameter_list|,
name|unsigned
name|Align
parameter_list|)
block|{
name|assert
argument_list|(
name|Align
operator|&&
operator|(
operator|(
name|Align
operator|-
literal|1
operator|)
operator|&
name|Align
operator|)
operator|==
literal|0
argument_list|)
expr_stmt|;
comment|// Align is power of 2.
name|StackOffset
operator|=
operator|(
operator|(
name|StackOffset
operator|+
name|Align
operator|-
literal|1
operator|)
operator|&
operator|~
operator|(
name|Align
operator|-
literal|1
operator|)
operator|)
expr_stmt|;
name|unsigned
name|Result
init|=
name|StackOffset
decl_stmt|;
name|StackOffset
operator|+=
name|Size
expr_stmt|;
return|return
name|Result
return|;
block|}
comment|// HandleByVal - Allocate a stack slot large enough to pass an argument by
comment|// value. The size and alignment information of the argument is encoded in its
comment|// parameter attribute.
name|void
name|HandleByVal
argument_list|(
name|unsigned
name|ValNo
argument_list|,
name|EVT
name|ValVT
argument_list|,
name|EVT
name|LocVT
argument_list|,
name|CCValAssign
operator|::
name|LocInfo
name|LocInfo
argument_list|,
name|int
name|MinSize
argument_list|,
name|int
name|MinAlign
argument_list|,
name|ISD
operator|::
name|ArgFlagsTy
name|ArgFlags
argument_list|)
decl_stmt|;
name|private
label|:
comment|/// MarkAllocated - Mark a register and all of its aliases as allocated.
name|void
name|MarkAllocated
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
function_decl|;
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

end_unit

