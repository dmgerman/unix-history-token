begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//== llvm/CodeGen/GlobalISel/LegalizePass.h ------------- -*- C++ -*-==//
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
comment|/// \file A pass to convert the target-illegal operations created by IR -> MIR
end_comment

begin_comment
comment|/// translation into ones the target expects to be able to select. This may
end_comment

begin_comment
comment|/// occur in multiple phases, for example G_ADD<2 x i8> -> G_ADD<2 x i16> ->
end_comment

begin_comment
comment|/// G_ADD<4 x i16>.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The LegalizeHelper class is where most of the work happens, and is designed
end_comment

begin_comment
comment|/// to be callable from other passes that find themselves with an illegal
end_comment

begin_comment
comment|/// instruction.
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
name|LLVM_CODEGEN_GLOBALISEL_LEGALIZEMACHINEIRPASS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_GLOBALISEL_LEGALIZEMACHINEIRPASS_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/GlobalISel/MachineIRBuilder.h"
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
name|class
name|MachineRegisterInfo
decl_stmt|;
name|class
name|Legalizer
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
name|private
operator|:
comment|/// Initialize the field members using \p MF.
name|void
name|init
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
block|;
name|public
operator|:
comment|// Ctor, nothing fancy.
name|Legalizer
argument_list|()
block|;
name|StringRef
name|getPassName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|"Legalizer"
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
name|Legalized
argument_list|)
return|;
block|}
name|bool
name|combineExtracts
argument_list|(
name|MachineInstr
operator|&
name|MI
argument_list|,
name|MachineRegisterInfo
operator|&
name|MRI
argument_list|,
specifier|const
name|TargetInstrInfo
operator|&
name|TII
argument_list|)
block|;
name|bool
name|combineMerges
argument_list|(
name|MachineInstr
operator|&
name|MI
argument_list|,
name|MachineRegisterInfo
operator|&
name|MRI
argument_list|,
specifier|const
name|TargetInstrInfo
operator|&
name|TII
argument_list|)
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

