begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Transforms/Utils/LoopUtils.h - Loop utilities -*- C++ -*-=========//
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
comment|// This file defines some loop transformation utilities.
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
name|LLVM_TRANSFORMS_UTILS_LOOPUTILS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_LOOPUTILS_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AliasAnalysis
decl_stmt|;
name|class
name|AssumptionCache
decl_stmt|;
name|class
name|BasicBlock
decl_stmt|;
name|class
name|DataLayout
decl_stmt|;
name|class
name|DominatorTree
decl_stmt|;
name|class
name|Loop
decl_stmt|;
name|class
name|LoopInfo
decl_stmt|;
name|class
name|Pass
decl_stmt|;
name|class
name|ScalarEvolution
decl_stmt|;
name|BasicBlock
modifier|*
name|InsertPreheaderForLoop
parameter_list|(
name|Loop
modifier|*
name|L
parameter_list|,
name|Pass
modifier|*
name|P
parameter_list|)
function_decl|;
comment|/// \brief Simplify each loop in a loop nest recursively.
comment|///
comment|/// This takes a potentially un-simplified loop L (and its children) and turns
comment|/// it into a simplified loop nest with preheaders and single backedges. It
comment|/// will optionally update \c AliasAnalysis and \c ScalarEvolution analyses if
comment|/// passed into it.
name|bool
name|simplifyLoop
parameter_list|(
name|Loop
modifier|*
name|L
parameter_list|,
name|DominatorTree
modifier|*
name|DT
parameter_list|,
name|LoopInfo
modifier|*
name|LI
parameter_list|,
name|Pass
modifier|*
name|PP
parameter_list|,
name|AliasAnalysis
modifier|*
name|AA
init|=
name|nullptr
parameter_list|,
name|ScalarEvolution
modifier|*
name|SE
init|=
name|nullptr
parameter_list|,
specifier|const
name|DataLayout
modifier|*
name|DL
init|=
name|nullptr
parameter_list|,
name|AssumptionCache
modifier|*
name|AC
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// \brief Put loop into LCSSA form.
comment|///
comment|/// Looks at all instructions in the loop which have uses outside of the
comment|/// current loop. For each, an LCSSA PHI node is inserted and the uses outside
comment|/// the loop are rewritten to use this node.
comment|///
comment|/// LoopInfo and DominatorTree are required and preserved.
comment|///
comment|/// If ScalarEvolution is passed in, it will be preserved.
comment|///
comment|/// Returns true if any modifications are made to the loop.
name|bool
name|formLCSSA
parameter_list|(
name|Loop
modifier|&
name|L
parameter_list|,
name|DominatorTree
modifier|&
name|DT
parameter_list|,
name|LoopInfo
modifier|*
name|LI
parameter_list|,
name|ScalarEvolution
modifier|*
name|SE
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// \brief Put a loop nest into LCSSA form.
comment|///
comment|/// This recursively forms LCSSA for a loop nest.
comment|///
comment|/// LoopInfo and DominatorTree are required and preserved.
comment|///
comment|/// If ScalarEvolution is passed in, it will be preserved.
comment|///
comment|/// Returns true if any modifications are made to the loop.
name|bool
name|formLCSSARecursively
parameter_list|(
name|Loop
modifier|&
name|L
parameter_list|,
name|DominatorTree
modifier|&
name|DT
parameter_list|,
name|LoopInfo
modifier|*
name|LI
parameter_list|,
name|ScalarEvolution
modifier|*
name|SE
init|=
name|nullptr
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

