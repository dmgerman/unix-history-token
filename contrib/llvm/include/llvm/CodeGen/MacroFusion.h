begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MacroFusion.h - Macro Fusion -----------------------------*- C++ -*-===//
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
comment|/// \file This file contains the definition of the DAG scheduling mutation to
end_comment

begin_comment
comment|/// pair instructions back to back.
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
name|LLVM_CODEGEN_MACROFUSION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MACROFUSION_H
end_define

begin_include
include|#
directive|include
file|<functional>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineInstr
decl_stmt|;
name|class
name|ScheduleDAGMutation
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
name|class
name|TargetSubtargetInfo
decl_stmt|;
comment|/// \brief Check if the instr pair, FirstMI and SecondMI, should be fused
comment|/// together. Given SecondMI, when FirstMI is unspecified, then check if
comment|/// SecondMI may be part of a fused pair at all.
name|using
name|ShouldSchedulePredTy
init|=
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
specifier|const
name|TargetInstrInfo
operator|&
name|TII
argument_list|,
specifier|const
name|TargetSubtargetInfo
operator|&
name|TSI
argument_list|,
specifier|const
name|MachineInstr
operator|*
name|FirstMI
argument_list|,
specifier|const
name|MachineInstr
operator|&
name|SecondMI
argument_list|)
operator|>
decl_stmt|;
comment|/// \brief Create a DAG scheduling mutation to pair instructions back to back
comment|/// for instructions that benefit according to the target-specific
comment|/// shouldScheduleAdjacent predicate function.
name|std
operator|::
name|unique_ptr
operator|<
name|ScheduleDAGMutation
operator|>
name|createMacroFusionDAGMutation
argument_list|(
argument|ShouldSchedulePredTy shouldScheduleAdjacent
argument_list|)
expr_stmt|;
comment|/// \brief Create a DAG scheduling mutation to pair branch instructions with one
comment|/// of their predecessors back to back for instructions that benefit according
comment|/// to the target-specific shouldScheduleAdjacent predicate function.
name|std
operator|::
name|unique_ptr
operator|<
name|ScheduleDAGMutation
operator|>
name|createBranchMacroFusionDAGMutation
argument_list|(
argument|ShouldSchedulePredTy shouldScheduleAdjacent
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CODEGEN_MACROFUSION_H
end_comment

end_unit

