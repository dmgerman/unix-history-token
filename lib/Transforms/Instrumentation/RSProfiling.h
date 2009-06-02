begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- RSProfiling.h - Various profiling using random sampling ----------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                      The LLVM Compiler Infrastructure
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
comment|// See notes in RSProfiling.cpp
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
file|"llvm/Transforms/RSProfiling.h"
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// RSProfilers_std - a simple support class for profilers that handles most
comment|/// of the work of chaining and tracking inserted code.
name|struct
name|RSProfilers_std
range|:
name|public
name|RSProfilers
block|{
specifier|static
name|char
name|ID
block|;
name|std
operator|::
name|set
operator|<
name|Value
operator|*
operator|>
name|profcode
block|;
comment|// Lookup up values in profcode
name|virtual
name|bool
name|isProfiling
argument_list|(
name|Value
operator|*
name|v
argument_list|)
block|;
comment|// handles required chaining
name|virtual
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
block|;
comment|// places counter updates in basic blocks and recordes added instructions in
comment|// profcode
name|void
name|IncrementCounterInBlock
argument_list|(
argument|BasicBlock *BB
argument_list|,
argument|unsigned CounterNum
argument_list|,
argument|GlobalValue *CounterArray
argument_list|)
block|;   }
decl_stmt|;
block|}
end_decl_stmt

end_unit

