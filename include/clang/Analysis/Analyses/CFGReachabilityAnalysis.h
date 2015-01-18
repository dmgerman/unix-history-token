begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- CFGReachabilityAnalysis.h - Basic reachability analysis ----*- C++ -*-==//
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
comment|// This file defines a flow-sensitive, (mostly) path-insensitive reachability
end_comment

begin_comment
comment|// analysis based on Clang's CFGs.  Clients can query if a given basic block
end_comment

begin_comment
comment|// is reachable within the CFG.
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
name|LLVM_CLANG_ANALYSIS_ANALYSES_CFGREACHABILITYANALYSIS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ANALYSIS_ANALYSES_CFGREACHABILITYANALYSIS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/BitVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|CFG
decl_stmt|;
name|class
name|CFGBlock
decl_stmt|;
comment|// A class that performs reachability queries for CFGBlocks. Several internal
comment|// checks in this checker require reachability information. The requests all
comment|// tend to have a common destination, so we lazily do a predecessor search
comment|// from the destination node and cache the results to prevent work
comment|// duplication.
name|class
name|CFGReverseBlockReachabilityAnalysis
block|{
typedef|typedef
name|llvm
operator|::
name|BitVector
name|ReachableSet
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|unsigned
operator|,
name|ReachableSet
operator|>
name|ReachableMap
expr_stmt|;
name|ReachableSet
name|analyzed
decl_stmt|;
name|ReachableMap
name|reachable
decl_stmt|;
name|public
label|:
name|CFGReverseBlockReachabilityAnalysis
argument_list|(
specifier|const
name|CFG
operator|&
name|cfg
argument_list|)
expr_stmt|;
comment|/// Returns true if the block 'Dst' can be reached from block 'Src'.
name|bool
name|isReachable
parameter_list|(
specifier|const
name|CFGBlock
modifier|*
name|Src
parameter_list|,
specifier|const
name|CFGBlock
modifier|*
name|Dst
parameter_list|)
function_decl|;
name|private
label|:
name|void
name|mapReachability
parameter_list|(
specifier|const
name|CFGBlock
modifier|*
name|Dst
parameter_list|)
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

