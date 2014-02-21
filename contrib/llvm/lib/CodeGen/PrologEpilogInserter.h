begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PrologEpilogInserter.h - Prolog/Epilog code insertion -*- C++ -*---===//
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
comment|// This pass is responsible for finalizing the functions frame layout, saving
end_comment

begin_comment
comment|// callee saved registers, and for emitting prolog& epilog code for the
end_comment

begin_comment
comment|// function.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This pass must be run after register allocation.  After this pass is
end_comment

begin_comment
comment|// executed, it is illegal to construct MO_FrameIndex operands.
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
name|LLVM_CODEGEN_PEI_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_PEI_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SparseBitVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionPass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineLoopInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/Passes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetRegisterInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|RegScavenger
decl_stmt|;
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|PEI
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
name|PEI
argument_list|()
operator|:
name|MachineFunctionPass
argument_list|(
argument|ID
argument_list|)
block|{
name|initializePEIPass
argument_list|(
operator|*
name|PassRegistry
operator|::
name|getPassRegistry
argument_list|()
argument_list|)
block|;     }
name|virtual
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
block|;
comment|/// runOnMachineFunction - Insert prolog/epilog code and replace abstract
comment|/// frame indexes with appropriate references.
comment|///
name|bool
name|runOnMachineFunction
argument_list|(
name|MachineFunction
operator|&
name|Fn
argument_list|)
block|;
name|private
operator|:
name|RegScavenger
operator|*
name|RS
block|;
comment|// MinCSFrameIndex, MaxCSFrameIndex - Keeps the range of callee saved
comment|// stack frame indexes.
name|unsigned
name|MinCSFrameIndex
block|,
name|MaxCSFrameIndex
block|;
comment|// Entry and return blocks of the current function.
name|MachineBasicBlock
operator|*
name|EntryBlock
block|;
name|SmallVector
operator|<
name|MachineBasicBlock
operator|*
block|,
literal|4
operator|>
name|ReturnBlocks
block|;
comment|// Flag to control whether to use the register scavenger to resolve
comment|// frame index materialization registers. Set according to
comment|// TRI->requiresFrameIndexScavenging() for the curren function.
name|bool
name|FrameIndexVirtualScavenging
block|;
name|void
name|calculateSets
argument_list|(
name|MachineFunction
operator|&
name|Fn
argument_list|)
block|;
name|void
name|calculateCallsInformation
argument_list|(
name|MachineFunction
operator|&
name|Fn
argument_list|)
block|;
name|void
name|calculateCalleeSavedRegisters
argument_list|(
name|MachineFunction
operator|&
name|Fn
argument_list|)
block|;
name|void
name|insertCSRSpillsAndRestores
argument_list|(
name|MachineFunction
operator|&
name|Fn
argument_list|)
block|;
name|void
name|calculateFrameObjectOffsets
argument_list|(
name|MachineFunction
operator|&
name|Fn
argument_list|)
block|;
name|void
name|replaceFrameIndices
argument_list|(
name|MachineFunction
operator|&
name|Fn
argument_list|)
block|;
name|void
name|replaceFrameIndices
argument_list|(
name|MachineBasicBlock
operator|*
name|BB
argument_list|,
name|MachineFunction
operator|&
name|Fn
argument_list|,
name|int
operator|&
name|SPAdj
argument_list|)
block|;
name|void
name|scavengeFrameVirtualRegs
argument_list|(
name|MachineFunction
operator|&
name|Fn
argument_list|)
block|;
name|void
name|insertPrologEpilogCode
argument_list|(
name|MachineFunction
operator|&
name|Fn
argument_list|)
block|;
comment|// Convenience for recognizing return blocks.
name|bool
name|isReturnBlock
argument_list|(
name|MachineBasicBlock
operator|*
name|MBB
argument_list|)
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

