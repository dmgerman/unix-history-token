begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/lib/Target/AArch64/AArch64CallLowering.h - Call lowering -----===//
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
name|LLVM_LIB_TARGET_AARCH64_AARCH64CALLLOWERING
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AARCH64_AARCH64CALLLOWERING
end_define

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
argument|const Function::ArgumentListType&Args
argument_list|,
argument|const SmallVectorImpl<unsigned>&VRegs
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End of namespace llvm;
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

