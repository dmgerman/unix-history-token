begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/lib/Target/X86/X86CallLowering.h - Call lowering -----===//
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
name|LLVM_LIB_TARGET_X86_X86CALLLOWERING
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_X86_X86CALLLOWERING
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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Function
decl_stmt|;
name|class
name|MachineIRBuilder
decl_stmt|;
name|class
name|X86TargetLowering
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|class
name|X86CallLowering
range|:
name|public
name|CallLowering
block|{
name|public
operator|:
name|X86CallLowering
argument_list|(
specifier|const
name|X86TargetLowering
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
name|private
operator|:
comment|/// A function of this type is used to perform value split action.
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
argument|const ArgInfo&OrigArgInfo
argument_list|,
argument|SmallVectorImpl<ArgInfo>&SplitArgs
argument_list|,
argument|const DataLayout&DL
argument_list|,
argument|MachineRegisterInfo&MRI
argument_list|,
argument|SplitArgTy SplitArg
argument_list|)
specifier|const
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// End of namespace llvm;
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

