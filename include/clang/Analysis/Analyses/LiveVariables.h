begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LiveVariables.h - Live Variable Analysis for Source CFGs -*- C++ --*-//
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
comment|// This file implements Live Variables analysis for source-level CFGs.
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
name|LLVM_CLANG_LIVEVARIABLES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIVEVARIABLES_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Decl.h"
end_include

begin_include
include|#
directive|include
file|"clang/Analysis/AnalysisContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ImmutableSet.h"
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
name|class
name|Stmt
decl_stmt|;
name|class
name|DeclRefExpr
decl_stmt|;
name|class
name|SourceManager
decl_stmt|;
name|class
name|LiveVariables
range|:
name|public
name|ManagedAnalysis
block|{
name|public
operator|:
name|class
name|LivenessValues
block|{
name|public
operator|:
name|llvm
operator|::
name|ImmutableSet
operator|<
specifier|const
name|Stmt
operator|*
operator|>
name|liveStmts
block|;
name|llvm
operator|::
name|ImmutableSet
operator|<
specifier|const
name|VarDecl
operator|*
operator|>
name|liveDecls
block|;
name|bool
name|equals
argument_list|(
argument|const LivenessValues&V
argument_list|)
specifier|const
block|;
name|LivenessValues
argument_list|()
operator|:
name|liveStmts
argument_list|(
name|nullptr
argument_list|)
block|,
name|liveDecls
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|LivenessValues
argument_list|(
name|llvm
operator|::
name|ImmutableSet
operator|<
specifier|const
name|Stmt
operator|*
operator|>
name|LiveStmts
argument_list|,
name|llvm
operator|::
name|ImmutableSet
operator|<
specifier|const
name|VarDecl
operator|*
operator|>
name|LiveDecls
argument_list|)
operator|:
name|liveStmts
argument_list|(
name|LiveStmts
argument_list|)
block|,
name|liveDecls
argument_list|(
argument|LiveDecls
argument_list|)
block|{}
operator|~
name|LivenessValues
argument_list|()
block|{}
name|bool
name|isLive
argument_list|(
argument|const Stmt *S
argument_list|)
specifier|const
block|;
name|bool
name|isLive
argument_list|(
argument|const VarDecl *D
argument_list|)
specifier|const
block|;
name|friend
name|class
name|LiveVariables
block|;       }
block|;
name|class
name|Observer
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|virtual
operator|~
name|Observer
argument_list|()
block|{}
comment|/// A callback invoked right before invoking the
comment|///  liveness transfer function on the given statement.
name|virtual
name|void
name|observeStmt
argument_list|(
argument|const Stmt *S
argument_list|,
argument|const CFGBlock *currentBlock
argument_list|,
argument|const LivenessValues& V
argument_list|)
block|{}
comment|/// Called when the live variables analysis registers
comment|/// that a variable is killed.
name|virtual
name|void
name|observerKill
argument_list|(
argument|const DeclRefExpr *DR
argument_list|)
block|{}
block|}
block|;
name|virtual
operator|~
name|LiveVariables
argument_list|()
block|;
comment|/// Compute the liveness information for a given CFG.
specifier|static
name|LiveVariables
operator|*
name|computeLiveness
argument_list|(
argument|AnalysisDeclContext&analysisContext
argument_list|,
argument|bool killAtAssign
argument_list|)
block|;
comment|/// Return true if a variable is live at the end of a
comment|/// specified block.
name|bool
name|isLive
argument_list|(
specifier|const
name|CFGBlock
operator|*
name|B
argument_list|,
specifier|const
name|VarDecl
operator|*
name|D
argument_list|)
block|;
comment|/// Returns true if a variable is live at the beginning of the
comment|///  the statement.  This query only works if liveness information
comment|///  has been recorded at the statement level (see runOnAllBlocks), and
comment|///  only returns liveness information for block-level expressions.
name|bool
name|isLive
argument_list|(
specifier|const
name|Stmt
operator|*
name|S
argument_list|,
specifier|const
name|VarDecl
operator|*
name|D
argument_list|)
block|;
comment|/// Returns true the block-level expression "value" is live
comment|///  before the given block-level expression (see runOnAllBlocks).
name|bool
name|isLive
argument_list|(
specifier|const
name|Stmt
operator|*
name|Loc
argument_list|,
specifier|const
name|Stmt
operator|*
name|StmtVal
argument_list|)
block|;
comment|/// Print to stderr the liveness information associated with
comment|/// each basic block.
name|void
name|dumpBlockLiveness
argument_list|(
specifier|const
name|SourceManager
operator|&
name|M
argument_list|)
block|;
name|void
name|runOnAllBlocks
argument_list|(
name|Observer
operator|&
name|obs
argument_list|)
block|;
specifier|static
name|LiveVariables
operator|*
name|create
argument_list|(
argument|AnalysisDeclContext&analysisContext
argument_list|)
block|{
return|return
name|computeLiveness
argument_list|(
name|analysisContext
argument_list|,
name|true
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|void
operator|*
name|getTag
argument_list|()
block|;
name|private
operator|:
name|LiveVariables
argument_list|(
name|void
operator|*
name|impl
argument_list|)
block|;
name|void
operator|*
name|impl
block|; }
decl_stmt|;
name|class
name|RelaxedLiveVariables
range|:
name|public
name|LiveVariables
block|{
name|public
operator|:
specifier|static
name|LiveVariables
operator|*
name|create
argument_list|(
argument|AnalysisDeclContext&analysisContext
argument_list|)
block|{
return|return
name|computeLiveness
argument_list|(
name|analysisContext
argument_list|,
name|false
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|void
operator|*
name|getTag
argument_list|()
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

