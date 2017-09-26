begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/Target/AMDGPU/AMDGPUCallLowering.h - Call lowering -*- C++ -*---===//
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
name|LLVM_LIB_TARGET_AMDGPU_AMDGPUCALLLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AMDGPU_AMDGPUCALLLOWERING_H
end_define

begin_include
include|#
directive|include
file|"AMDGPU.h"
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
name|AMDGPUTargetLowering
decl_stmt|;
name|class
name|AMDGPUCallLowering
range|:
name|public
name|CallLowering
block|{
name|AMDGPUAS
name|AMDGPUASI
block|;
name|unsigned
name|lowerParameterPtr
argument_list|(
argument|MachineIRBuilder&MIRBuilder
argument_list|,
argument|Type *ParamTy
argument_list|,
argument|unsigned Offset
argument_list|)
specifier|const
block|;
name|void
name|lowerParameter
argument_list|(
argument|MachineIRBuilder&MIRBuilder
argument_list|,
argument|Type *ParamTy
argument_list|,
argument|unsigned Offset
argument_list|,
argument|unsigned DstReg
argument_list|)
specifier|const
block|;
name|public
operator|:
name|AMDGPUCallLowering
argument_list|(
specifier|const
name|AMDGPUTargetLowering
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
specifier|static
name|CCAssignFn
operator|*
name|CCAssignFnForCall
argument_list|(
argument|CallingConv::ID CC
argument_list|,
argument|bool IsVarArg
argument_list|)
block|;
specifier|static
name|CCAssignFn
operator|*
name|CCAssignFnForReturn
argument_list|(
argument|CallingConv::ID CC
argument_list|,
argument|bool IsVarArg
argument_list|)
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

