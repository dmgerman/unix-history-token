begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//== llvm/CodeGen/GlobalISel/InstructionSelect.h -----------------*- C++ -*-==//
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
comment|/// \file This file describes the interface of the MachineFunctionPass
end_comment

begin_comment
comment|/// responsible for selecting (possibly generic) machine instructions to
end_comment

begin_comment
comment|/// target-specific instructions.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CODEGEN_GLOBALISEL_INSTRUCTIONSELECT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_GLOBALISEL_INSTRUCTIONSELECT_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/GlobalISel/InstructionSelector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionPass.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// This pass is responsible for selecting generic machine instructions to
comment|/// target-specific instructions.  It relies on the InstructionSelector provided
comment|/// by the target.
comment|/// Selection is done by examining blocks in post-order, and instructions in
comment|/// reverse order.
comment|///
comment|/// \post for all inst in MF: not isPreISelGenericOpcode(inst.opcode)
name|class
name|InstructionSelect
range|:
name|public
name|MachineFunctionPass
block|{
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|StringRef
name|getPassName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|"InstructionSelect"
return|;
block|}
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|;
name|MachineFunctionProperties
name|getRequiredProperties
argument_list|()
specifier|const
name|override
block|{
return|return
name|MachineFunctionProperties
argument_list|()
operator|.
name|set
argument_list|(
name|MachineFunctionProperties
operator|::
name|Property
operator|::
name|IsSSA
argument_list|)
operator|.
name|set
argument_list|(
name|MachineFunctionProperties
operator|::
name|Property
operator|::
name|Legalized
argument_list|)
operator|.
name|set
argument_list|(
name|MachineFunctionProperties
operator|::
name|Property
operator|::
name|RegBankSelected
argument_list|)
return|;
block|}
name|MachineFunctionProperties
name|getSetProperties
argument_list|()
specifier|const
name|override
block|{
return|return
name|MachineFunctionProperties
argument_list|()
operator|.
name|set
argument_list|(
name|MachineFunctionProperties
operator|::
name|Property
operator|::
name|Selected
argument_list|)
return|;
block|}
name|InstructionSelect
argument_list|()
block|;
name|bool
name|runOnMachineFunction
argument_list|(
argument|MachineFunction&MF
argument_list|)
name|override
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End namespace llvm.
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

