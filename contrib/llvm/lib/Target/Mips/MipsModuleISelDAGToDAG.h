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
argument|TM_
argument_list|)
block|{}
comment|// Pass Name
specifier|const
name|char
operator|*
name|getPassName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|"MIPS DAG->DAG Pattern Instruction Selection"
return|;
block|}
name|bool
name|runOnMachineFunction
argument_list|(
argument|MachineFunction&MF
argument_list|)
name|override
block|;
name|protected
operator|:
name|MipsTargetMachine
operator|&
name|TM
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

