begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- MipsModuleISelDAGToDAG.h -  Change Subtarget             --------===//
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
comment|// This file defines a pass used to change the subtarget for the
end_comment

begin_comment
comment|// Mips Instruction selector.
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
name|MIPSMODULEISELDAGTODAG_H
end_ifndef

begin_define
define|#
directive|define
name|MIPSMODULEISELDAGTODAG_H
end_define

begin_include
include|#
directive|include
file|"Mips.h"
end_include

begin_include
include|#
directive|include
file|"MipsSubtarget.h"
end_include

begin_include
include|#
directive|include
file|"MipsTargetMachine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAGISel.h"
end_include

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Instruction Selector Implementation
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// MipsModuleDAGToDAGISel - MIPS specific code to select MIPS machine
end_comment

begin_comment
comment|// instructions for SelectionDAG operations.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MipsModuleDAGToDAGISel
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
name|explicit
name|MipsModuleDAGToDAGISel
argument_list|(
name|MipsTargetMachine
operator|&
name|TM_
argument_list|)
operator|:
name|MachineFunctionPass
argument_list|(
name|ID
argument_list|)
block|,
name|TM
argument_list|(
name|TM_
argument_list|)
block|,
name|Subtarget
argument_list|(
argument|TM.getSubtarget<MipsSubtarget>()
argument_list|)
block|{}
comment|// Pass Name
name|virtual
specifier|const
name|char
operator|*
name|getPassName
argument_list|()
specifier|const
block|{
return|return
literal|"MIPS DAG->DAG Pattern Instruction Selection"
return|;
block|}
name|virtual
name|bool
name|runOnMachineFunction
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
block|;
name|virtual
name|SDNode
operator|*
name|Select
argument_list|(
argument|SDNode *N
argument_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"unexpected"
argument_list|)
block|;   }
name|protected
operator|:
comment|/// Keep a pointer to the MipsSubtarget around so that we can make the right
comment|/// decision when generating code for different targets.
specifier|const
name|TargetMachine
operator|&
name|TM
block|;
specifier|const
name|MipsSubtarget
operator|&
name|Subtarget
block|; }
decl_stmt|;
comment|/// createMipsISelDag - This pass converts a legalized DAG into a
comment|/// MIPS-specific DAG, ready for instruction scheduling.
name|FunctionPass
modifier|*
name|createMipsModuleISelDag
parameter_list|(
name|MipsTargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

