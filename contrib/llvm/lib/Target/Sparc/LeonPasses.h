begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===------- LeonPasses.h - Define passes specific to LEON ----------------===//
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
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_SPARC_LEON_PASSES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_SPARC_LEON_PASSES_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionPass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/Passes.h"
end_include

begin_include
include|#
directive|include
file|"Sparc.h"
end_include

begin_include
include|#
directive|include
file|"SparcSubtarget.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LLVM_LIBRARY_VISIBILITY
name|LEONMachineFunctionPass
range|:
name|public
name|MachineFunctionPass
block|{
name|protected
operator|:
specifier|const
name|SparcSubtarget
operator|*
name|Subtarget
block|;
specifier|const
name|int
name|LAST_OPERAND
operator|=
operator|-
literal|1
block|;
comment|// this vector holds free registers that we allocate in groups for some of the
comment|// LEON passes
name|std
operator|::
name|vector
operator|<
name|int
operator|>
name|UsedRegisters
block|;
name|protected
operator|:
name|LEONMachineFunctionPass
argument_list|(
name|char
operator|&
name|ID
argument_list|)
block|;
name|int
name|GetRegIndexForOperand
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|int OperandIndex
argument_list|)
block|;
name|void
name|clearUsedRegisterList
argument_list|()
block|{
name|UsedRegisters
operator|.
name|clear
argument_list|()
block|; }
name|void
name|markRegisterUsed
argument_list|(
argument|int registerIndex
argument_list|)
block|{
name|UsedRegisters
operator|.
name|push_back
argument_list|(
name|registerIndex
argument_list|)
block|;   }
name|int
name|getUnusedFPRegister
argument_list|(
name|MachineRegisterInfo
operator|&
name|MRI
argument_list|)
block|; }
decl_stmt|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|InsertNOPLoad
range|:
name|public
name|LEONMachineFunctionPass
block|{
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|InsertNOPLoad
argument_list|()
block|;
name|bool
name|runOnMachineFunction
argument_list|(
argument|MachineFunction&MF
argument_list|)
name|override
block|;
name|StringRef
name|getPassName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|"InsertNOPLoad: Erratum Fix LBR35: insert a NOP instruction after "
literal|"every single-cycle load instruction when the next instruction is "
literal|"another load/store instruction"
return|;
block|}
expr|}
block|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|FixFSMULD
operator|:
name|public
name|LEONMachineFunctionPass
block|{
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|FixFSMULD
argument_list|()
block|;
name|bool
name|runOnMachineFunction
argument_list|(
argument|MachineFunction&MF
argument_list|)
name|override
block|;
name|StringRef
name|getPassName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|"FixFSMULD: Erratum Fix LBR31: do not select FSMULD"
return|;
block|}
expr|}
block|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|ReplaceFMULS
operator|:
name|public
name|LEONMachineFunctionPass
block|{
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|ReplaceFMULS
argument_list|()
block|;
name|bool
name|runOnMachineFunction
argument_list|(
argument|MachineFunction&MF
argument_list|)
name|override
block|;
name|StringRef
name|getPassName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|"ReplaceFMULS: Erratum Fix LBR32: replace FMULS instruction with a "
literal|"routine using conversions/double precision operations to replace "
literal|"FMULS"
return|;
block|}
expr|}
block|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|DetectRoundChange
operator|:
name|public
name|LEONMachineFunctionPass
block|{
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|DetectRoundChange
argument_list|()
block|;
name|bool
name|runOnMachineFunction
argument_list|(
argument|MachineFunction&MF
argument_list|)
name|override
block|;
name|StringRef
name|getPassName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|"DetectRoundChange: Leon erratum detection: detect any rounding "
literal|"mode change request: use only the round-to-nearest rounding mode"
return|;
block|}
expr|}
block|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|FixAllFDIVSQRT
operator|:
name|public
name|LEONMachineFunctionPass
block|{
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|FixAllFDIVSQRT
argument_list|()
block|;
name|bool
name|runOnMachineFunction
argument_list|(
argument|MachineFunction&MF
argument_list|)
name|override
block|;
name|StringRef
name|getPassName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|"FixAllFDIVSQRT: Erratum Fix LBR34: fix FDIVS/FDIVD/FSQRTS/FSQRTD "
literal|"instructions with NOPs and floating-point store"
return|;
block|}
expr|}
block|; }
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_TARGET_SPARC_LEON_PASSES_H
end_comment

end_unit

