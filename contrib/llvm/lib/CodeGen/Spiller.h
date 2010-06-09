begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/Spiller.h - Spiller -*- C++ -*------------------------===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CODEGEN_SPILLER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_SPILLER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
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
name|class
name|LiveInterval
decl_stmt|;
name|class
name|LiveIntervals
decl_stmt|;
name|class
name|LiveStacks
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineLoopInfo
decl_stmt|;
name|class
name|SlotIndex
decl_stmt|;
name|class
name|VirtRegMap
decl_stmt|;
name|class
name|VNInfo
decl_stmt|;
comment|/// Spiller interface.
comment|///
comment|/// Implementations are utility classes which insert spill or remat code on
comment|/// demand.
name|class
name|Spiller
block|{
name|public
label|:
name|virtual
operator|~
name|Spiller
argument_list|()
operator|=
literal|0
expr_stmt|;
comment|/// Spill the given live range. The method used will depend on the Spiller
comment|/// implementation selected.
name|virtual
name|std
operator|::
name|vector
operator|<
name|LiveInterval
operator|*
operator|>
name|spill
argument_list|(
name|LiveInterval
operator|*
name|li
argument_list|,
name|SmallVectorImpl
operator|<
name|LiveInterval
operator|*
operator|>
operator|&
name|spillIs
argument_list|,
name|SlotIndex
operator|*
name|earliestIndex
operator|=
literal|0
argument_list|)
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
comment|/// Create and return a spiller object, as specified on the command line.
name|Spiller
modifier|*
name|createSpiller
parameter_list|(
name|MachineFunction
modifier|*
name|mf
parameter_list|,
name|LiveIntervals
modifier|*
name|li
parameter_list|,
specifier|const
name|MachineLoopInfo
modifier|*
name|loopInfo
parameter_list|,
name|VirtRegMap
modifier|*
name|vrm
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

