begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=- AArch64MachineFuctionInfo.h - AArch64 machine function info --*- C++ -*-=//
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
comment|// This file declares AArch64-specific per-machine-function information.
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
name|LLVM_LIB_TARGET_AARCH64_AARCH64MACHINEFUNCTIONINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AARCH64_AARCH64MACHINEFUNCTIONINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCLinkerOptimizationHint.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// AArch64FunctionInfo - This class is derived from MachineFunctionInfo and
comment|/// contains private AArch64-specific information for each MachineFunction.
name|class
name|AArch64FunctionInfo
range|:
name|public
name|MachineFunctionInfo
block|{
comment|/// Number of bytes of arguments this function has on the stack. If the callee
comment|/// is expected to restore the argument stack this should be a multiple of 16,
comment|/// all usable during a tail call.
comment|///
comment|/// The alternative would forbid tail call optimisation in some cases: if we
comment|/// want to transfer control from a function with 8-bytes of stack-argument
comment|/// space to a function with 16-bytes then misalignment of this value would
comment|/// make a stack adjustment necessary, which could not be undone by the
comment|/// callee.
name|unsigned
name|BytesInStackArgArea
block|;
comment|/// The number of bytes to restore to deallocate space for incoming
comment|/// arguments. Canonically 0 in the C calling convention, but non-zero when
comment|/// callee is expected to pop the args.
name|unsigned
name|ArgumentStackToRestore
block|;
comment|/// HasStackFrame - True if this function has a stack frame. Set by
comment|/// processFunctionBeforeCalleeSavedScan().
name|bool
name|HasStackFrame
block|;
comment|/// \brief Amount of stack frame size, not including callee-saved registers.
name|unsigned
name|LocalStackSize
block|;
comment|/// \brief Number of TLS accesses using the special (combinable)
comment|/// _TLS_MODULE_BASE_ symbol.
name|unsigned
name|NumLocalDynamicTLSAccesses
block|;
comment|/// \brief FrameIndex for start of varargs area for arguments passed on the
comment|/// stack.
name|int
name|VarArgsStackIndex
block|;
comment|/// \brief FrameIndex for start of varargs area for arguments passed in
comment|/// general purpose registers.
name|int
name|VarArgsGPRIndex
block|;
comment|/// \brief Size of the varargs area for arguments passed in general purpose
comment|/// registers.
name|unsigned
name|VarArgsGPRSize
block|;
comment|/// \brief FrameIndex for start of varargs area for arguments passed in
comment|/// floating-point registers.
name|int
name|VarArgsFPRIndex
block|;
comment|/// \brief Size of the varargs area for arguments passed in floating-point
comment|/// registers.
name|unsigned
name|VarArgsFPRSize
block|;
name|public
operator|:
name|AArch64FunctionInfo
argument_list|()
operator|:
name|BytesInStackArgArea
argument_list|(
literal|0
argument_list|)
block|,
name|ArgumentStackToRestore
argument_list|(
literal|0
argument_list|)
block|,
name|HasStackFrame
argument_list|(
name|false
argument_list|)
block|,
name|NumLocalDynamicTLSAccesses
argument_list|(
literal|0
argument_list|)
block|,
name|VarArgsStackIndex
argument_list|(
literal|0
argument_list|)
block|,
name|VarArgsGPRIndex
argument_list|(
literal|0
argument_list|)
block|,
name|VarArgsGPRSize
argument_list|(
literal|0
argument_list|)
block|,
name|VarArgsFPRIndex
argument_list|(
literal|0
argument_list|)
block|,
name|VarArgsFPRSize
argument_list|(
literal|0
argument_list|)
block|{}
name|explicit
name|AArch64FunctionInfo
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
operator|:
name|BytesInStackArgArea
argument_list|(
literal|0
argument_list|)
block|,
name|ArgumentStackToRestore
argument_list|(
literal|0
argument_list|)
block|,
name|HasStackFrame
argument_list|(
name|false
argument_list|)
block|,
name|NumLocalDynamicTLSAccesses
argument_list|(
literal|0
argument_list|)
block|,
name|VarArgsStackIndex
argument_list|(
literal|0
argument_list|)
block|,
name|VarArgsGPRIndex
argument_list|(
literal|0
argument_list|)
block|,
name|VarArgsGPRSize
argument_list|(
literal|0
argument_list|)
block|,
name|VarArgsFPRIndex
argument_list|(
literal|0
argument_list|)
block|,
name|VarArgsFPRSize
argument_list|(
literal|0
argument_list|)
block|{
operator|(
name|void
operator|)
name|MF
block|;   }
name|unsigned
name|getBytesInStackArgArea
argument_list|()
specifier|const
block|{
return|return
name|BytesInStackArgArea
return|;
block|}
name|void
name|setBytesInStackArgArea
argument_list|(
argument|unsigned bytes
argument_list|)
block|{
name|BytesInStackArgArea
operator|=
name|bytes
block|; }
name|unsigned
name|getArgumentStackToRestore
argument_list|()
specifier|const
block|{
return|return
name|ArgumentStackToRestore
return|;
block|}
name|void
name|setArgumentStackToRestore
argument_list|(
argument|unsigned bytes
argument_list|)
block|{
name|ArgumentStackToRestore
operator|=
name|bytes
block|;   }
name|bool
name|hasStackFrame
argument_list|()
specifier|const
block|{
return|return
name|HasStackFrame
return|;
block|}
name|void
name|setHasStackFrame
argument_list|(
argument|bool s
argument_list|)
block|{
name|HasStackFrame
operator|=
name|s
block|; }
name|void
name|setLocalStackSize
argument_list|(
argument|unsigned Size
argument_list|)
block|{
name|LocalStackSize
operator|=
name|Size
block|; }
name|unsigned
name|getLocalStackSize
argument_list|()
specifier|const
block|{
return|return
name|LocalStackSize
return|;
block|}
name|void
name|incNumLocalDynamicTLSAccesses
argument_list|()
block|{
operator|++
name|NumLocalDynamicTLSAccesses
block|; }
name|unsigned
name|getNumLocalDynamicTLSAccesses
argument_list|()
specifier|const
block|{
return|return
name|NumLocalDynamicTLSAccesses
return|;
block|}
name|int
name|getVarArgsStackIndex
argument_list|()
specifier|const
block|{
return|return
name|VarArgsStackIndex
return|;
block|}
name|void
name|setVarArgsStackIndex
argument_list|(
argument|int Index
argument_list|)
block|{
name|VarArgsStackIndex
operator|=
name|Index
block|; }
name|int
name|getVarArgsGPRIndex
argument_list|()
specifier|const
block|{
return|return
name|VarArgsGPRIndex
return|;
block|}
name|void
name|setVarArgsGPRIndex
argument_list|(
argument|int Index
argument_list|)
block|{
name|VarArgsGPRIndex
operator|=
name|Index
block|; }
name|unsigned
name|getVarArgsGPRSize
argument_list|()
specifier|const
block|{
return|return
name|VarArgsGPRSize
return|;
block|}
name|void
name|setVarArgsGPRSize
argument_list|(
argument|unsigned Size
argument_list|)
block|{
name|VarArgsGPRSize
operator|=
name|Size
block|; }
name|int
name|getVarArgsFPRIndex
argument_list|()
specifier|const
block|{
return|return
name|VarArgsFPRIndex
return|;
block|}
name|void
name|setVarArgsFPRIndex
argument_list|(
argument|int Index
argument_list|)
block|{
name|VarArgsFPRIndex
operator|=
name|Index
block|; }
name|unsigned
name|getVarArgsFPRSize
argument_list|()
specifier|const
block|{
return|return
name|VarArgsFPRSize
return|;
block|}
name|void
name|setVarArgsFPRSize
argument_list|(
argument|unsigned Size
argument_list|)
block|{
name|VarArgsFPRSize
operator|=
name|Size
block|; }
typedef|typedef
name|SmallPtrSet
operator|<
specifier|const
name|MachineInstr
operator|*
operator|,
literal|16
operator|>
name|SetOfInstructions
expr_stmt|;
specifier|const
name|SetOfInstructions
operator|&
name|getLOHRelated
argument_list|()
specifier|const
block|{
return|return
name|LOHRelated
return|;
block|}
comment|// Shortcuts for LOH related types.
name|class
name|MILOHDirective
block|{
name|MCLOHType
name|Kind
block|;
comment|/// Arguments of this directive. Order matters.
name|SmallVector
operator|<
specifier|const
name|MachineInstr
operator|*
block|,
literal|3
operator|>
name|Args
block|;
name|public
operator|:
typedef|typedef
name|SmallVectorImpl
operator|<
specifier|const
name|MachineInstr
operator|*
operator|>
name|LOHArgs
expr_stmt|;
name|MILOHDirective
argument_list|(
argument|MCLOHType Kind
argument_list|,
argument|const LOHArgs&Args
argument_list|)
operator|:
name|Kind
argument_list|(
name|Kind
argument_list|)
block|,
name|Args
argument_list|(
argument|Args.begin()
argument_list|,
argument|Args.end()
argument_list|)
block|{
name|assert
argument_list|(
name|isValidMCLOHType
argument_list|(
name|Kind
argument_list|)
operator|&&
literal|"Invalid LOH directive type!"
argument_list|)
block|;     }
name|MCLOHType
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
specifier|const
name|LOHArgs
operator|&
name|getArgs
argument_list|()
specifier|const
block|{
return|return
name|Args
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_typedef
typedef|typedef
name|MILOHDirective
operator|::
name|LOHArgs
name|MILOHArgs
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|SmallVector
operator|<
name|MILOHDirective
operator|,
literal|32
operator|>
name|MILOHContainer
expr_stmt|;
end_typedef

begin_expr_stmt
specifier|const
name|MILOHContainer
operator|&
name|getLOHContainer
argument_list|()
specifier|const
block|{
return|return
name|LOHContainerSet
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Add a LOH directive of this @p Kind and this @p Args.
end_comment

begin_function
name|void
name|addLOHDirective
parameter_list|(
name|MCLOHType
name|Kind
parameter_list|,
specifier|const
name|MILOHArgs
modifier|&
name|Args
parameter_list|)
block|{
name|LOHContainerSet
operator|.
name|push_back
argument_list|(
name|MILOHDirective
argument_list|(
name|Kind
argument_list|,
name|Args
argument_list|)
argument_list|)
expr_stmt|;
name|LOHRelated
operator|.
name|insert
argument_list|(
name|Args
operator|.
name|begin
argument_list|()
argument_list|,
name|Args
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_comment
comment|// Hold the lists of LOHs.
end_comment

begin_decl_stmt
name|MILOHContainer
name|LOHContainerSet
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SetOfInstructions
name|LOHRelated
decl_stmt|;
end_decl_stmt

begin_comment
unit|}; }
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

