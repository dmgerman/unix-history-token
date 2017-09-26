begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//== llvm/CodeGen/GlobalISel/Localizer.h - Localizer -------------*- C++ -*-==//
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
comment|/// \file This file describes the interface of the Localizer pass.
end_comment

begin_comment
comment|/// This pass moves/duplicates constant-like instructions close to their uses.
end_comment

begin_comment
comment|/// Its primarily goal is to workaround the deficiencies of the fast register
end_comment

begin_comment
comment|/// allocator.
end_comment

begin_comment
comment|/// With GlobalISel constants are all materialized in the entry block of
end_comment

begin_comment
comment|/// a function. However, the fast allocator cannot rematerialize constants and
end_comment

begin_comment
comment|/// has a lot more live-ranges to deal with and will most likely end up
end_comment

begin_comment
comment|/// spilling a lot.
end_comment

begin_comment
comment|/// By pushing the constants close to their use, we only create small
end_comment

begin_comment
comment|/// live-ranges.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CODEGEN_GLOBALISEL_LOCALIZER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_GLOBALISEL_LOCALIZER_H
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
comment|// Forward declarations.
name|class
name|MachineRegisterInfo
decl_stmt|;
comment|/// This pass implements the localization mechanism described at the
comment|/// top of this file. One specificity of the implementation is that
comment|/// it will materialize one and only one instance of a constant per
comment|/// basic block, thus enabling reuse of that constant within that block.
comment|/// Moreover, it only materializes constants in blocks where they
comment|/// are used. PHI uses are considered happening at the end of the
comment|/// related predecessor.
name|class
name|Localizer
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
comment|/// MRI contains all the register class/bank information that this
comment|/// pass uses and updates.
name|MachineRegisterInfo
operator|*
name|MRI
block|;
comment|/// Check whether or not \p MI needs to be moved close to its uses.
specifier|static
name|bool
name|shouldLocalize
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|MI
argument_list|)
block|;
comment|/// Check if \p MOUse is used in the same basic block as \p Def.
comment|/// If the use is in the same block, we say it is local.
comment|/// When the use is not local, \p InsertMBB will contain the basic
comment|/// block when to insert \p Def to have a local use.
specifier|static
name|bool
name|isLocalUse
argument_list|(
name|MachineOperand
operator|&
name|MOUse
argument_list|,
specifier|const
name|MachineInstr
operator|&
name|Def
argument_list|,
name|MachineBasicBlock
operator|*
operator|&
name|InsertMBB
argument_list|)
block|;
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
name|Localizer
argument_list|()
block|;
name|StringRef
name|getPassName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|"Localizer"
return|;
block|}
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

