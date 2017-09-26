begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=- llvm/CodeGen/AntiDepBreaker.h - Anti-Dependence Breaking -*- C++ -*-=//
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
comment|// This file implements the AntiDepBreaker class, which implements
end_comment

begin_comment
comment|// anti-dependence breaking heuristics for post-register-allocation scheduling.
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
name|LLVM_LIB_CODEGEN_ANTIDEPBREAKER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_CODEGEN_ANTIDEPBREAKER_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFrameInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ScheduleDAG.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// This class works in conjunction with the post-RA scheduler to rename
comment|/// registers to break register anti-dependencies (WAR hazards).
name|class
name|LLVM_LIBRARY_VISIBILITY
name|AntiDepBreaker
block|{
name|public
label|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|MachineInstr
operator|*
operator|,
name|MachineInstr
operator|*
operator|>
expr|>
name|DbgValueVector
expr_stmt|;
name|virtual
operator|~
name|AntiDepBreaker
argument_list|()
expr_stmt|;
comment|/// Initialize anti-dep breaking for a new basic block.
name|virtual
name|void
name|StartBlock
parameter_list|(
name|MachineBasicBlock
modifier|*
name|BB
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Identifiy anti-dependencies within a basic-block region and break them by
comment|/// renaming registers. Return the number of anti-dependencies broken.
name|virtual
name|unsigned
name|BreakAntiDependencies
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|SUnit
operator|>
operator|&
name|SUnits
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|Begin
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|End
argument_list|,
name|unsigned
name|InsertPosIndex
argument_list|,
name|DbgValueVector
operator|&
name|DbgValues
argument_list|)
init|=
literal|0
decl_stmt|;
comment|/// Update liveness information to account for the current
comment|/// instruction, which will not be scheduled.
name|virtual
name|void
name|Observe
parameter_list|(
name|MachineInstr
modifier|&
name|MI
parameter_list|,
name|unsigned
name|Count
parameter_list|,
name|unsigned
name|InsertPosIndex
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Finish anti-dep breaking for a basic block.
name|virtual
name|void
name|FinishBlock
parameter_list|()
init|=
literal|0
function_decl|;
comment|/// Update DBG_VALUE if dependency breaker is updating
comment|/// other machine instruction to use NewReg.
name|void
name|UpdateDbgValue
parameter_list|(
name|MachineInstr
modifier|&
name|MI
parameter_list|,
name|unsigned
name|OldReg
parameter_list|,
name|unsigned
name|NewReg
parameter_list|)
block|{
name|assert
argument_list|(
name|MI
operator|.
name|isDebugValue
argument_list|()
operator|&&
literal|"MI is not DBG_VALUE!"
argument_list|)
expr_stmt|;
if|if
condition|(
name|MI
operator|.
name|getOperand
argument_list|(
literal|0
argument_list|)
operator|.
name|isReg
argument_list|()
operator|&&
name|MI
operator|.
name|getOperand
argument_list|(
literal|0
argument_list|)
operator|.
name|getReg
argument_list|()
operator|==
name|OldReg
condition|)
name|MI
operator|.
name|getOperand
argument_list|(
literal|0
argument_list|)
operator|.
name|setReg
argument_list|(
name|NewReg
argument_list|)
expr_stmt|;
block|}
comment|/// Update all DBG_VALUE instructions that may be affected by the dependency
comment|/// breaker's update of ParentMI to use NewReg.
name|void
name|UpdateDbgValues
parameter_list|(
specifier|const
name|DbgValueVector
modifier|&
name|DbgValues
parameter_list|,
name|MachineInstr
modifier|*
name|ParentMI
parameter_list|,
name|unsigned
name|OldReg
parameter_list|,
name|unsigned
name|NewReg
parameter_list|)
block|{
comment|// The following code is dependent on the order in which the DbgValues are
comment|// constructed in ScheduleDAGInstrs::buildSchedGraph.
name|MachineInstr
modifier|*
name|PrevDbgMI
init|=
name|nullptr
decl_stmt|;
for|for
control|(
specifier|const
specifier|auto
modifier|&
name|DV
range|:
name|make_range
argument_list|(
name|DbgValues
operator|.
name|crbegin
argument_list|()
argument_list|,
name|DbgValues
operator|.
name|crend
argument_list|()
argument_list|)
control|)
block|{
name|MachineInstr
modifier|*
name|PrevMI
init|=
name|DV
operator|.
name|second
decl_stmt|;
if|if
condition|(
operator|(
name|PrevMI
operator|==
name|ParentMI
operator|)
operator|||
operator|(
name|PrevMI
operator|==
name|PrevDbgMI
operator|)
condition|)
block|{
name|MachineInstr
modifier|*
name|DbgMI
init|=
name|DV
operator|.
name|first
decl_stmt|;
name|UpdateDbgValue
argument_list|(
operator|*
name|DbgMI
argument_list|,
name|OldReg
argument_list|,
name|NewReg
argument_list|)
expr_stmt|;
name|PrevDbgMI
operator|=
name|DbgMI
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|PrevDbgMI
condition|)
block|{
break|break;
comment|// If no match and already found a DBG_VALUE, we're done.
block|}
block|}
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

