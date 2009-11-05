begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//== AnalysisManager.h - Path sensitive analysis data manager ------*- C++ -*-//
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
comment|// This file defines the AnalysisManager class that manages the data and policy
end_comment

begin_comment
comment|// for path sensitive analysis.
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
name|LLVM_CLANG_ANALYSIS_ANALYSISMANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ANALYSIS_ANALYSISMANAGER_H
end_define

begin_include
include|#
directive|include
file|"clang/Analysis/PathSensitive/BugReporter.h"
end_include

begin_include
include|#
directive|include
file|"clang/Analysis/PathSensitive/AnalysisContext.h"
end_include

begin_include
include|#
directive|include
file|"clang/Analysis/PathDiagnostic.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|AnalysisManager
range|:
name|public
name|BugReporterData
block|{
name|AnalysisContextManager
name|AnaCtxMgr
block|;
name|LocationContextManager
name|LocCtxMgr
block|;
name|ASTContext
operator|&
name|Ctx
block|;
name|Diagnostic
operator|&
name|Diags
block|;
specifier|const
name|LangOptions
operator|&
name|LangInfo
block|;
name|llvm
operator|::
name|OwningPtr
operator|<
name|PathDiagnosticClient
operator|>
name|PD
block|;
comment|// Configurable components creators.
name|StoreManagerCreator
name|CreateStoreMgr
block|;
name|ConstraintManagerCreator
name|CreateConstraintMgr
block|;    enum
name|AnalysisScope
block|{
name|ScopeTU
block|,
name|ScopeDecl
block|}
name|AScope
block|;
name|bool
name|DisplayedFunction
block|;
name|bool
name|VisualizeEGDot
block|;
name|bool
name|VisualizeEGUbi
block|;
name|bool
name|PurgeDead
block|;
comment|/// EargerlyAssume - A flag indicating how the engine should handle
comment|//   expressions such as: 'x = (y != 0)'.  When this flag is true then
comment|//   the subexpression 'y != 0' will be eagerly assumed to be true or false,
comment|//   thus evaluating it to the integers 0 or 1 respectively.  The upside
comment|//   is that this can increase analysis precision until we have a better way
comment|//   to lazily evaluate such logic.  The downside is that it eagerly
comment|//   bifurcates paths.
name|bool
name|EagerlyAssume
block|;
name|bool
name|TrimGraph
block|;
name|public
operator|:
name|AnalysisManager
argument_list|(
argument|ASTContext&ctx
argument_list|,
argument|Diagnostic&diags
argument_list|,
argument|const LangOptions&lang
argument_list|,
argument|PathDiagnosticClient *pd
argument_list|,
argument|StoreManagerCreator storemgr
argument_list|,
argument|ConstraintManagerCreator constraintmgr
argument_list|,
argument|bool displayProgress
argument_list|,
argument|bool vizdot
argument_list|,
argument|bool vizubi
argument_list|,
argument|bool purge
argument_list|,
argument|bool eager
argument_list|,
argument|bool trim
argument_list|)
operator|:
name|Ctx
argument_list|(
name|ctx
argument_list|)
block|,
name|Diags
argument_list|(
name|diags
argument_list|)
block|,
name|LangInfo
argument_list|(
name|lang
argument_list|)
block|,
name|PD
argument_list|(
name|pd
argument_list|)
block|,
name|CreateStoreMgr
argument_list|(
name|storemgr
argument_list|)
block|,
name|CreateConstraintMgr
argument_list|(
name|constraintmgr
argument_list|)
block|,
name|AScope
argument_list|(
name|ScopeDecl
argument_list|)
block|,
name|DisplayedFunction
argument_list|(
operator|!
name|displayProgress
argument_list|)
block|,
name|VisualizeEGDot
argument_list|(
name|vizdot
argument_list|)
block|,
name|VisualizeEGUbi
argument_list|(
name|vizubi
argument_list|)
block|,
name|PurgeDead
argument_list|(
name|purge
argument_list|)
block|,
name|EagerlyAssume
argument_list|(
name|eager
argument_list|)
block|,
name|TrimGraph
argument_list|(
argument|trim
argument_list|)
block|{}
operator|~
name|AnalysisManager
argument_list|()
block|{
name|FlushDiagnostics
argument_list|()
block|; }
name|void
name|ClearContexts
argument_list|()
block|{
name|LocCtxMgr
operator|.
name|clear
argument_list|()
block|;
name|AnaCtxMgr
operator|.
name|clear
argument_list|()
block|;   }
name|StoreManagerCreator
name|getStoreManagerCreator
argument_list|()
block|{
return|return
name|CreateStoreMgr
return|;
block|}
block|;
name|ConstraintManagerCreator
name|getConstraintManagerCreator
argument_list|()
block|{
return|return
name|CreateConstraintMgr
return|;
block|}
name|virtual
name|ASTContext
operator|&
name|getASTContext
argument_list|()
block|{
return|return
name|Ctx
return|;
block|}
name|virtual
name|SourceManager
operator|&
name|getSourceManager
argument_list|()
block|{
return|return
name|getASTContext
argument_list|()
operator|.
name|getSourceManager
argument_list|()
return|;
block|}
name|virtual
name|Diagnostic
operator|&
name|getDiagnostic
argument_list|()
block|{
return|return
name|Diags
return|;
block|}
specifier|const
name|LangOptions
operator|&
name|getLangOptions
argument_list|()
specifier|const
block|{
return|return
name|LangInfo
return|;
block|}
name|virtual
name|PathDiagnosticClient
operator|*
name|getPathDiagnosticClient
argument_list|()
block|{
return|return
name|PD
operator|.
name|get
argument_list|()
return|;
block|}
name|void
name|FlushDiagnostics
argument_list|()
block|{
if|if
condition|(
name|PD
operator|.
name|get
argument_list|()
condition|)
name|PD
operator|->
name|FlushDiagnostics
argument_list|()
expr_stmt|;
block|}
name|bool
name|shouldVisualizeGraphviz
argument_list|()
specifier|const
block|{
return|return
name|VisualizeEGDot
return|;
block|}
name|bool
name|shouldVisualizeUbigraph
argument_list|()
specifier|const
block|{
return|return
name|VisualizeEGUbi
return|;
block|}
name|bool
name|shouldVisualize
argument_list|()
specifier|const
block|{
return|return
name|VisualizeEGDot
operator|||
name|VisualizeEGUbi
return|;
block|}
name|bool
name|shouldTrimGraph
argument_list|()
specifier|const
block|{
return|return
name|TrimGraph
return|;
block|}
name|bool
name|shouldPurgeDead
argument_list|()
specifier|const
block|{
return|return
name|PurgeDead
return|;
block|}
name|bool
name|shouldEagerlyAssume
argument_list|()
specifier|const
block|{
return|return
name|EagerlyAssume
return|;
block|}
name|void
name|DisplayFunction
argument_list|(
name|Decl
operator|*
name|D
argument_list|)
block|;
name|CFG
operator|*
name|getCFG
argument_list|(
argument|Decl const *D
argument_list|)
block|{
return|return
name|AnaCtxMgr
operator|.
name|getContext
argument_list|(
name|D
argument_list|)
operator|->
name|getCFG
argument_list|()
return|;
block|}
name|LiveVariables
operator|*
name|getLiveVariables
argument_list|(
argument|Decl const *D
argument_list|)
block|{
return|return
name|AnaCtxMgr
operator|.
name|getContext
argument_list|(
name|D
argument_list|)
operator|->
name|getLiveVariables
argument_list|()
return|;
block|}
name|ParentMap
operator|&
name|getParentMap
argument_list|(
argument|Decl const *D
argument_list|)
block|{
return|return
name|AnaCtxMgr
operator|.
name|getContext
argument_list|(
name|D
argument_list|)
operator|->
name|getParentMap
argument_list|()
return|;
block|}
comment|// Get the top level stack frame.
name|StackFrameContext
operator|*
name|getStackFrame
argument_list|(
argument|Decl const *D
argument_list|)
block|{
return|return
name|LocCtxMgr
operator|.
name|getStackFrame
argument_list|(
name|AnaCtxMgr
operator|.
name|getContext
argument_list|(
name|D
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
return|;
block|}
comment|// Get a stack frame with parent.
name|StackFrameContext
specifier|const
operator|*
name|getStackFrame
argument_list|(
argument|Decl const *D
argument_list|,
argument|LocationContext const *Parent
argument_list|,
argument|Stmt const *S
argument_list|)
block|{
return|return
name|LocCtxMgr
operator|.
name|getStackFrame
argument_list|(
name|AnaCtxMgr
operator|.
name|getContext
argument_list|(
name|D
argument_list|)
argument_list|,
name|Parent
argument_list|,
name|S
argument_list|)
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

