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
name|LLVM_CLANG_GR_ANALYSISMANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_GR_ANALYSISMANAGER_H
end_define

begin_include
include|#
directive|include
file|"clang/Analysis/AnalysisContext.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/AnalyzerOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/BugReporter/BugReporter.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/BugReporter/PathDiagnostic.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathDiagnosticConsumers.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ento
block|{
name|class
name|CheckerManager
decl_stmt|;
name|class
name|AnalysisManager
range|:
name|public
name|BugReporterData
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|AnalysisDeclContextManager
name|AnaCtxMgr
block|;
name|ASTContext
operator|&
name|Ctx
block|;
name|DiagnosticsEngine
operator|&
name|Diags
block|;
specifier|const
name|LangOptions
operator|&
name|LangOpts
block|;
name|PathDiagnosticConsumers
name|PathConsumers
block|;
comment|// Configurable components creators.
name|StoreManagerCreator
name|CreateStoreMgr
block|;
name|ConstraintManagerCreator
name|CreateConstraintMgr
block|;
name|CheckerManager
operator|*
name|CheckerMgr
block|;
name|public
operator|:
name|AnalyzerOptions
operator|&
name|options
block|;
name|AnalysisManager
argument_list|(
argument|ASTContext&ctx
argument_list|,
argument|DiagnosticsEngine&diags
argument_list|,
argument|const LangOptions&lang
argument_list|,
argument|const PathDiagnosticConsumers&Consumers
argument_list|,
argument|StoreManagerCreator storemgr
argument_list|,
argument|ConstraintManagerCreator constraintmgr
argument_list|,
argument|CheckerManager *checkerMgr
argument_list|,
argument|AnalyzerOptions&Options
argument_list|)
block|;
operator|~
name|AnalysisManager
argument_list|()
block|;
name|void
name|ClearContexts
argument_list|()
block|{
name|AnaCtxMgr
operator|.
name|clear
argument_list|()
block|;   }
name|AnalysisDeclContextManager
operator|&
name|getAnalysisDeclContextManager
argument_list|()
block|{
return|return
name|AnaCtxMgr
return|;
block|}
name|StoreManagerCreator
name|getStoreManagerCreator
argument_list|()
block|{
return|return
name|CreateStoreMgr
return|;
block|}
name|AnalyzerOptions
operator|&
name|getAnalyzerOptions
argument_list|()
block|{
return|return
name|options
return|;
block|}
name|ConstraintManagerCreator
name|getConstraintManagerCreator
argument_list|()
block|{
return|return
name|CreateConstraintMgr
return|;
block|}
name|CheckerManager
operator|*
name|getCheckerManager
argument_list|()
specifier|const
block|{
return|return
name|CheckerMgr
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
name|DiagnosticsEngine
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
name|getLangOpts
argument_list|()
specifier|const
block|{
return|return
name|LangOpts
return|;
block|}
name|ArrayRef
operator|<
name|PathDiagnosticConsumer
operator|*
operator|>
name|getPathDiagnosticConsumers
argument_list|()
block|{
return|return
name|PathConsumers
return|;
block|}
name|void
name|FlushDiagnostics
argument_list|()
block|;
name|bool
name|shouldVisualize
argument_list|()
specifier|const
block|{
return|return
name|options
operator|.
name|visualizeExplodedGraphWithGraphViz
operator|||
name|options
operator|.
name|visualizeExplodedGraphWithUbiGraph
return|;
block|}
name|bool
name|shouldInlineCall
argument_list|()
specifier|const
block|{
return|return
name|options
operator|.
name|getIPAMode
argument_list|()
operator|!=
name|IPAK_None
return|;
block|}
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
name|template
operator|<
name|typename
name|T
operator|>
name|T
operator|*
name|getAnalysis
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
name|getAnalysis
operator|<
name|T
operator|>
operator|(
operator|)
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
name|AnalysisDeclContext
operator|*
name|getAnalysisDeclContext
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|AnaCtxMgr
operator|.
name|getContext
argument_list|(
name|D
argument_list|)
return|;
block|}
expr|}
block|;  }
comment|// enAnaCtxMgrspace
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

