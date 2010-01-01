begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LiveVariables.h - Live Variable Analysis for Source CFGs -*- C++ --*-===//
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
file|"clang/Analysis/Support/BlkExprDeclBitVector.h"
end_include

begin_include
include|#
directive|include
file|"clang/Analysis/FlowSensitive/DataflowValues.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
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
name|AnalysisContext
decl_stmt|;
struct|struct
name|LiveVariables_ValueTypes
block|{
struct_decl|struct
name|ObserverTy
struct_decl|;
comment|// We keep dataflow state for declarations and block-level expressions;
typedef|typedef
name|StmtDeclBitVector_Types
operator|::
name|ValTy
name|ValTy
expr_stmt|;
comment|// We need to keep track of both declarations and CFGBlock-level expressions,
comment|// (so that we don't explore such expressions twice).  We also want
comment|// to compute liveness information for block-level expressions, since these
comment|// act as "temporary" values.
name|struct
name|AnalysisDataTy
range|:
name|public
name|StmtDeclBitVector_Types
operator|::
name|AnalysisDataTy
block|{
name|ObserverTy
operator|*
name|Observer
block|;
name|ValTy
name|AlwaysLive
block|;
name|AnalysisContext
operator|*
name|AC
block|;
name|AnalysisDataTy
argument_list|()
operator|:
name|Observer
argument_list|(
name|NULL
argument_list|)
block|,
name|AC
argument_list|(
argument|NULL
argument_list|)
block|{}
block|}
decl_stmt|;
comment|//===-----------------------------------------------------===//
comment|// ObserverTy - Observer for uninitialized values queries.
comment|//===-----------------------------------------------------===//
struct|struct
name|ObserverTy
block|{
name|virtual
operator|~
name|ObserverTy
argument_list|()
block|{}
comment|/// ObserveStmt - A callback invoked right before invoking the
comment|///  liveness transfer function on the given statement.
name|virtual
name|void
name|ObserveStmt
argument_list|(
argument|Stmt* S
argument_list|,
argument|const AnalysisDataTy& AD
argument_list|,
argument|const ValTy& V
argument_list|)
block|{}
name|virtual
name|void
name|ObserverKill
argument_list|(
argument|DeclRefExpr* DR
argument_list|)
block|{}
block|}
struct|;
block|}
struct|;
name|class
name|LiveVariables
range|:
name|public
name|DataflowValues
operator|<
name|LiveVariables_ValueTypes
decl_stmt|,
name|dataflow
decl|::
name|backward_analysis_tag
decl|>
block|{
name|public
label|:
typedef|typedef
name|LiveVariables_ValueTypes
operator|::
name|ObserverTy
name|ObserverTy
expr_stmt|;
name|LiveVariables
argument_list|(
name|AnalysisContext
operator|&
name|AC
argument_list|)
expr_stmt|;
comment|/// IsLive - Return true if a variable is live at the end of a
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
decl|const
decl_stmt|;
comment|/// IsLive - Returns true if a variable is live at the beginning of the
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
decl|const
decl_stmt|;
comment|/// IsLive - Returns true the block-level expression "value" is live
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
decl|const
decl_stmt|;
comment|/// IsLive - Return true if a variable is live according to the
comment|///  provided livness bitvector.
name|bool
name|isLive
argument_list|(
specifier|const
name|ValTy
operator|&
name|V
argument_list|,
specifier|const
name|VarDecl
operator|*
name|D
argument_list|)
decl|const
decl_stmt|;
comment|/// dumpLiveness - Print to stderr the liveness information encoded
comment|///  by a specified bitvector.
name|void
name|dumpLiveness
argument_list|(
specifier|const
name|ValTy
operator|&
name|V
argument_list|,
specifier|const
name|SourceManager
operator|&
name|M
argument_list|)
decl|const
decl_stmt|;
comment|/// dumpBlockLiveness - Print to stderr the liveness information
comment|///  associated with each basic block.
name|void
name|dumpBlockLiveness
argument_list|(
specifier|const
name|SourceManager
operator|&
name|M
argument_list|)
decl|const
decl_stmt|;
comment|/// getNumDecls - Return the number of variables (declarations) that
comment|///  whose liveness status is being tracked by the dataflow
comment|///  analysis.
name|unsigned
name|getNumDecls
argument_list|()
specifier|const
block|{
return|return
name|getAnalysisData
argument_list|()
operator|.
name|getNumDecls
argument_list|()
return|;
block|}
comment|/// IntializeValues - This routine can perform extra initialization, but
comment|///  for LiveVariables this does nothing since all that logic is in
comment|///  the constructor.
name|void
name|InitializeValues
parameter_list|(
specifier|const
name|CFG
modifier|&
name|cfg
parameter_list|)
block|{}
name|void
name|runOnCFG
parameter_list|(
name|CFG
modifier|&
name|cfg
parameter_list|)
function_decl|;
comment|/// runOnAllBlocks - Propagate the dataflow values once for each block,
comment|///  starting from the current dataflow values.  'recordStmtValues' indicates
comment|///  whether the method should store dataflow values per each individual
comment|///  block-level expression.
name|void
name|runOnAllBlocks
parameter_list|(
specifier|const
name|CFG
modifier|&
name|cfg
parameter_list|,
name|ObserverTy
modifier|*
name|Obs
parameter_list|,
name|bool
name|recordStmtValues
init|=
name|false
parameter_list|)
function_decl|;
block|}
empty_stmt|;
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

