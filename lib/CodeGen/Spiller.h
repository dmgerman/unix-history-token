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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LiveInterval
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineFunctionPass
decl_stmt|;
name|class
name|SlotIndex
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
name|class
name|VirtRegMap
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
comment|/// spill - Spill the given live interval. The method used will depend on
comment|/// the Spiller implementation selected.
comment|///
comment|/// @param li            The live interval to be spilled.
comment|/// @param spillIs       A list of intervals that are about to be spilled,
comment|///                      and so cannot be used for remat etc.
comment|/// @param newIntervals  The newly created intervals will be appended here.
name|virtual
name|void
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
name|newIntervals
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|LiveInterval
operator|*
operator|>
operator|&
name|spillIs
argument_list|)
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
comment|/// Create and return a spiller object, as specified on the command line.
name|Spiller
modifier|*
name|createSpiller
parameter_list|(
name|MachineFunctionPass
modifier|&
name|pass
parameter_list|,
name|MachineFunction
modifier|&
name|mf
parameter_list|,
name|VirtRegMap
modifier|&
name|vrm
parameter_list|)
function_decl|;
comment|/// Create and return a spiller that will insert spill code directly instead
comment|/// of deferring though VirtRegMap.
name|Spiller
modifier|*
name|createInlineSpiller
parameter_list|(
name|MachineFunctionPass
modifier|&
name|pass
parameter_list|,
name|MachineFunction
modifier|&
name|mf
parameter_list|,
name|VirtRegMap
modifier|&
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

