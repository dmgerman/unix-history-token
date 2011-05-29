begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//== TransferFuncs.h - Path-Sens. Transfer Functions Interface ---*- C++ -*--=//
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
comment|//  This file defines TransferFuncs, which provides a base-class that
end_comment

begin_comment
comment|//  defines an interface for transfer functions used by ExprEngine.
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
name|LLVM_CLANG_GR_TRANSFERFUNCS
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_GR_TRANSFERFUNCS
end_define

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/GRState.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/SVals.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/ObjCMessage.h"
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
name|ObjCMessageExpr
decl_stmt|;
name|namespace
name|ento
block|{
name|class
name|ExplodedNode
decl_stmt|;
name|class
name|ExplodedNodeSet
decl_stmt|;
name|class
name|EndOfFunctionNodeBuilder
decl_stmt|;
name|class
name|ExprEngine
decl_stmt|;
name|class
name|StmtNodeBuilder
decl_stmt|;
name|class
name|StmtNodeBuilderRef
decl_stmt|;
name|class
name|TransferFuncs
block|{
name|public
label|:
name|TransferFuncs
argument_list|()
block|{}
name|virtual
operator|~
name|TransferFuncs
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
argument|ExprEngine& Eng
argument_list|)
block|{}
comment|// Calls.
name|virtual
name|void
name|evalCall
argument_list|(
argument|ExplodedNodeSet& Dst
argument_list|,
argument|ExprEngine& Engine
argument_list|,
argument|StmtNodeBuilder& Builder
argument_list|,
argument|const CallExpr* CE
argument_list|,
argument|SVal L
argument_list|,
argument|ExplodedNode* Pred
argument_list|)
block|{}
name|virtual
name|void
name|evalObjCMessage
argument_list|(
argument|ExplodedNodeSet& Dst
argument_list|,
argument|ExprEngine& Engine
argument_list|,
argument|StmtNodeBuilder& Builder
argument_list|,
argument|ObjCMessage msg
argument_list|,
argument|ExplodedNode* Pred
argument_list|,
argument|const GRState *state
argument_list|)
block|{}
comment|// Stores.
name|virtual
name|void
name|evalBind
argument_list|(
argument|StmtNodeBuilderRef& B
argument_list|,
argument|SVal location
argument_list|,
argument|SVal val
argument_list|)
block|{}
comment|// End-of-path and dead symbol notification.
name|virtual
name|void
name|evalEndPath
argument_list|(
argument|ExprEngine& Engine
argument_list|,
argument|EndOfFunctionNodeBuilder& Builder
argument_list|)
block|{}
name|virtual
name|void
name|evalDeadSymbols
argument_list|(
argument|ExplodedNodeSet& Dst
argument_list|,
argument|ExprEngine& Engine
argument_list|,
argument|StmtNodeBuilder& Builder
argument_list|,
argument|ExplodedNode* Pred
argument_list|,
argument|const GRState* state
argument_list|,
argument|SymbolReaper& SymReaper
argument_list|)
block|{}
comment|// Return statements.
name|virtual
name|void
name|evalReturn
argument_list|(
argument|ExplodedNodeSet& Dst
argument_list|,
argument|ExprEngine& Engine
argument_list|,
argument|StmtNodeBuilder& Builder
argument_list|,
argument|const ReturnStmt* S
argument_list|,
argument|ExplodedNode* Pred
argument_list|)
block|{}
comment|// Assumptions.
name|virtual
specifier|const
name|GRState
operator|*
name|evalAssume
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
block|}
comment|// end GR namespace
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

