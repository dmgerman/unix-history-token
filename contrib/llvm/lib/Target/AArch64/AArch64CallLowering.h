begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- AArch64CallLowering.h - Call lowering ------------------*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// This file describes how to lower LLVM calls to machine code calls.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_AARCH64_AARCH64CALLLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AARCH64_AARCH64CALLLOWERING_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/GlobalISel/CallLowering.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AArch64TargetLowering
decl_stmt|;
name|class
name|AArch64CallLowering
range|:
name|public
name|CallLowering
block|{
name|public
operator|:
name|AArch64CallLowering
argument_list|(
specifier|const
name|AArch64TargetLowering
operator|&
name|TLI
argument_list|)
block|;
name|bool
name|lowerReturn
argument_list|(
argument|MachineIRBuilder&MIRBuiler
argument_list|,
argument|const Value *Val
argument_list|,
argument|unsigned VReg
argument_list|)
specifier|const
name|override
block|;
name|bool
name|lowerFormalArguments
argument_list|(
argument|MachineIRBuilder&MIRBuilder
argument_list|,
argument|const Function&F
argument_list|,
argument|ArrayRef<unsigned> VRegs
argument_list|)
specifier|const
name|override
block|;
name|bool
name|lowerCall
argument_list|(
argument|MachineIRBuilder&MIRBuilder
argument_list|,
argument|CallingConv::ID CallConv
argument_list|,
argument|const MachineOperand&Callee
argument_list|,
argument|const ArgInfo&OrigRet
argument_list|,
argument|ArrayRef<ArgInfo> OrigArgs
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
typedef|typedef
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|MachineIRBuilder
operator|&
argument_list|,
name|Type
operator|*
argument_list|,
name|unsigned
argument_list|,
name|CCValAssign
operator|&
argument_list|)
operator|>
name|RegHandler
expr_stmt|;
typedef|typedef
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|MachineIRBuilder
operator|&
argument_list|,
name|int
argument_list|,
name|CCValAssign
operator|&
argument_list|)
operator|>
name|MemHandler
expr_stmt|;
typedef|typedef
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|unsigned
argument_list|,
name|uint64_t
argument_list|)
operator|>
name|SplitArgTy
expr_stmt|;
name|void
name|splitToValueTypes
argument_list|(
specifier|const
name|ArgInfo
operator|&
name|OrigArgInfo
argument_list|,
name|SmallVectorImpl
operator|<
name|ArgInfo
operator|>
operator|&
name|SplitArgs
argument_list|,
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|,
name|MachineRegisterInfo
operator|&
name|MRI
argument_list|,
specifier|const
name|SplitArgTy
operator|&
name|SplitArg
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
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_TARGET_AARCH64_AARCH64CALLLOWERING_H
end_comment

end_unit

