begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- AArch64MacroFusion.h - AArch64 Macro Fusion ------------------------===//
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
comment|/// \file This file contains the AArch64 definition of the DAG scheduling
end_comment

begin_comment
comment|/// mutation to pair instructions back to back.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineScheduler.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Note that you have to add:
comment|///   DAG.addMutation(createAArch64MacroFusionDAGMutation());
comment|/// to AArch64PassConfig::createMachineScheduler() to have an effect.
name|std
operator|::
name|unique_ptr
operator|<
name|ScheduleDAGMutation
operator|>
name|createAArch64MacroFusionDAGMutation
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// llvm
end_comment

end_unit

