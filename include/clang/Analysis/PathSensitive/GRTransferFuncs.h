begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//== GRTransferFuncs.h - Path-Sens. Transfer Functions Interface -*- C++ -*--=//
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
comment|//  This file defines GRTransferFuncs, which provides a base-class that
end_comment

begin_comment
comment|//  defines an interface for transfer functions used by GRExprEngine.
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
name|LLVM_CLANG_ANALYSIS_GRTF
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ANALYSIS_GRTF
end_define

begin_include
include|#
directive|include
file|"clang/Analysis/PathSensitive/SVals.h"
end_include

begin_include
include|#
directive|include
file|"clang/Analysis/PathSensitive/GRCoreEngine.h"
end_include

begin_include
include|#
directive|include
file|"clang/Analysis/PathSensitive/GRState.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|GRExprEngine
decl_stmt|;
name|class
name|BugReporter
decl_stmt|;
name|class
name|ObjCMessageExpr
decl_stmt|;
name|class
name|GRStmtNodeBuilderRef
decl_stmt|;
name|class
name|GRTransferFuncs
block|{
name|public
label|:
name|GRTransferFuncs
argument_list|()
block|{}
name|virtual
operator|~
name|GRTransferFuncs
argument_list|()
block|{}
name|virtual
name|void
name|RegisterPrinters
argument_list|(
argument|std::vector<GRState::Printer*>& Printers
argument_list|)
block|{}
name|virtual
name|void
name|RegisterChecks
argument_list|(
argument|BugReporter& BR
argument_list|)
block|{}
comment|// Calls.
name|virtual
name|void
name|EvalCall
argument_list|(
argument|ExplodedNodeSet& Dst
argument_list|,
argument|GRExprEngine& Engine
argument_list|,
argument|GRStmtNodeBuilder& Builder
argument_list|,
argument|CallExpr* CE
argument_list|,
argument|SVal L
argument_list|,
argument|ExplodedNode* Pred
argument_list|)
block|{}
name|virtual
name|void
name|EvalObjCMessageExpr
argument_list|(
argument|ExplodedNodeSet& Dst
argument_list|,
argument|GRExprEngine& Engine
argument_list|,
argument|GRStmtNodeBuilder& Builder
argument_list|,
argument|ObjCMessageExpr* ME
argument_list|,
argument|ExplodedNode* Pred
argument_list|)
block|{}
comment|// Stores.
name|virtual
name|void
name|EvalBind
argument_list|(
argument|GRStmtNodeBuilderRef& B
argument_list|,
argument|SVal location
argument_list|,
argument|SVal val
argument_list|)
block|{}
comment|// End-of-path and dead symbol notification.
name|virtual
name|void
name|EvalEndPath
argument_list|(
argument|GRExprEngine& Engine
argument_list|,
argument|GREndPathNodeBuilder& Builder
argument_list|)
block|{}
name|virtual
name|void
name|EvalDeadSymbols
argument_list|(
argument|ExplodedNodeSet& Dst
argument_list|,
argument|GRExprEngine& Engine
argument_list|,
argument|GRStmtNodeBuilder& Builder
argument_list|,
argument|ExplodedNode* Pred
argument_list|,
argument|Stmt* S
argument_list|,
argument|const GRState* state
argument_list|,
argument|SymbolReaper& SymReaper
argument_list|)
block|{}
comment|// Return statements.
name|virtual
name|void
name|EvalReturn
argument_list|(
argument|ExplodedNodeSet& Dst
argument_list|,
argument|GRExprEngine& Engine
argument_list|,
argument|GRStmtNodeBuilder& Builder
argument_list|,
argument|ReturnStmt* S
argument_list|,
argument|ExplodedNode* Pred
argument_list|)
block|{}
comment|// Assumptions.
name|virtual
specifier|const
name|GRState
operator|*
name|EvalAssume
argument_list|(
argument|const GRState *state
argument_list|,
argument|SVal Cond
argument_list|,
argument|bool Assumption
argument_list|)
block|{
return|return
name|state
return|;
block|}
block|}
empty_stmt|;
name|GRTransferFuncs
modifier|*
name|CreateCallInliner
parameter_list|(
name|ASTContext
modifier|&
name|ctx
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// end clang namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

