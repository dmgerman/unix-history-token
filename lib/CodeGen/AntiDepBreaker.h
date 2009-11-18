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
name|LLVM_CODEGEN_ANTIDEPBREAKER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_ANTIDEPBREAKER_H
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
file|"llvm/ADT/SmallSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// AntiDepBreaker - This class works into conjunction with the
comment|/// post-RA scheduler to rename registers to break register
comment|/// anti-dependencies.
name|class
name|AntiDepBreaker
block|{
name|public
label|:
typedef|typedef
name|SmallSet
operator|<
name|unsigned
operator|,
literal|4
operator|>
name|AntiDepRegSet
expr_stmt|;
typedef|typedef
name|SmallVector
operator|<
name|unsigned
operator|,
literal|4
operator|>
name|AntiDepRegVector
expr_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|SUnit
operator|*
operator|,
name|AntiDepRegVector
operator|>
name|CandidateMap
expr_stmt|;
name|virtual
operator|~
name|AntiDepBreaker
argument_list|()
expr_stmt|;
comment|/// GetMaxTrials - Return the maximum number of anti-dependence
comment|/// breaking attempts that will be made for a block.
name|virtual
name|unsigned
name|GetMaxTrials
parameter_list|()
init|=
literal|0
function_decl|;
comment|/// NeedCandidates - Return true if the schedule must provide
comment|/// candidates with BreakAntiDependencies().
name|virtual
name|bool
name|NeedCandidates
parameter_list|()
init|=
literal|0
function_decl|;
comment|/// Start - Initialize anti-dep breaking for a new basic block.
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
comment|/// BreakAntiDependencies - Identifiy anti-dependencies within a
comment|/// basic-block region and break them by renaming registers. Return
comment|/// the number of anti-dependencies broken.
comment|///
name|virtual
name|unsigned
name|BreakAntiDependencies
argument_list|(
name|std
operator|::
name|vector
operator|<
name|SUnit
operator|>
operator|&
name|SUnits
argument_list|,
name|CandidateMap
operator|&
name|Candidates
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
operator|&
name|Begin
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
operator|&
name|End
argument_list|,
name|unsigned
name|InsertPosIndex
argument_list|)
init|=
literal|0
decl_stmt|;
comment|/// Observe - Update liveness information to account for the current
comment|/// instruction, which will not be scheduled.
comment|///
name|virtual
name|void
name|Observe
parameter_list|(
name|MachineInstr
modifier|*
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
comment|/// Finish - Finish anti-dep breaking for a basic block.
name|virtual
name|void
name|FinishBlock
parameter_list|()
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

