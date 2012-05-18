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
file|"clang/Frontend/AnalyzerOptions.h"
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
name|OwningPtr
operator|<
name|PathDiagnosticConsumer
operator|>
name|PD
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
block|;    enum
name|AnalysisScope
block|{
name|ScopeTU
block|,
name|ScopeDecl
block|}
name|AScope
block|;
comment|/// \brief The maximum number of exploded nodes the analyzer will generate.
name|unsigned
name|MaxNodes
block|;
comment|/// \brief The maximum number of times the analyzer visits a block.
name|unsigned
name|MaxVisit
block|;
name|bool
name|VisualizeEGDot
block|;
name|bool
name|VisualizeEGUbi
block|;
name|AnalysisPurgeMode
name|PurgeDead
block|;
comment|/// \brief The flag regulates if we should eagerly assume evaluations of
comment|/// conditionals, thus, bifurcating the path.
comment|///
comment|/// EagerlyAssume - A flag indicating how the engine should handle
comment|///   expressions such as: 'x = (y != 0)'.  When this flag is true then
comment|///   the subexpression 'y != 0' will be eagerly assumed to be true or false,
comment|///   thus evaluating it to the integers 0 or 1 respectively.  The upside
comment|///   is that this can increase analysis precision until we have a better way
comment|///   to lazily evaluate such logic.  The downside is that it eagerly
comment|///   bifurcates paths.
name|bool
name|EagerlyAssume
block|;
name|bool
name|TrimGraph
block|;
name|bool
name|EagerlyTrimEGraph
block|;
name|public
operator|:
comment|// \brief inter-procedural analysis mode.
name|AnalysisIPAMode
name|IPAMode
block|;
comment|// Settings for inlining tuning.
comment|/// \brief The inlining stack depth limit.
name|unsigned
name|InlineMaxStackDepth
block|;
comment|/// \brief The max number of basic blocks in a function being inlined.
name|unsigned
name|InlineMaxFunctionSize
block|;
comment|/// \brief The mode of function selection used during inlining.
name|AnalysisInliningMode
name|InliningMode
block|;
comment|/// \brief Do not re-analyze paths leading to exhausted nodes with a different
comment|/// strategy. We get better code coverage when retry is enabled.
name|bool
name|NoRetryExhausted
block|;
name|public
operator|:
name|AnalysisManager
argument_list|(
argument|ASTContext&ctx
argument_list|,
argument|DiagnosticsEngine&diags
argument_list|,
argument|const LangOptions&lang
argument_list|,
argument|PathDiagnosticConsumer *pd
argument_list|,
argument|StoreManagerCreator storemgr
argument_list|,
argument|ConstraintManagerCreator constraintmgr
argument_list|,
argument|CheckerManager *checkerMgr
argument_list|,
argument|unsigned maxnodes
argument_list|,
argument|unsigned maxvisit
argument_list|,
argument|bool vizdot
argument_list|,
argument|bool vizubi
argument_list|,
argument|AnalysisPurgeMode purge
argument_list|,
argument|bool eager
argument_list|,
argument|bool trim
argument_list|,
argument|bool useUnoptimizedCFG
argument_list|,
argument|bool addImplicitDtors
argument_list|,
argument|bool addInitializers
argument_list|,
argument|bool eagerlyTrimEGraph
argument_list|,
argument|AnalysisIPAMode ipa
argument_list|,
argument|unsigned inlineMaxStack
argument_list|,
argument|unsigned inlineMaxFunctionSize
argument_list|,
argument|AnalysisInliningMode inliningMode
argument_list|,
argument|bool NoRetry
argument_list|)
block|;
comment|/// Construct a clone of the given AnalysisManager with the given ASTContext
comment|/// and DiagnosticsEngine.
name|AnalysisManager
argument_list|(
name|ASTContext
operator|&
name|ctx
argument_list|,
name|DiagnosticsEngine
operator|&
name|diags
argument_list|,
name|AnalysisManager
operator|&
name|ParentAM
argument_list|)
block|;
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
name|virtual
name|PathDiagnosticConsumer
operator|*
name|getPathDiagnosticConsumer
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
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
name|unsigned
name|getMaxNodes
argument_list|()
specifier|const
block|{
return|return
name|MaxNodes
return|;
block|}
name|unsigned
name|getMaxVisit
argument_list|()
specifier|const
block|{
return|return
name|MaxVisit
return|;
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
name|shouldEagerlyTrimExplodedGraph
argument_list|()
specifier|const
block|{
return|return
name|EagerlyTrimEGraph
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
name|AnalysisPurgeMode
name|getPurgeMode
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
name|bool
name|shouldInlineCall
argument_list|()
specifier|const
block|{
return|return
operator|(
name|IPAMode
operator|==
name|Inlining
operator|)
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
name|AnalysisDeclContext
operator|*
name|getAnalysisDeclContext
argument_list|(
argument|const Decl *D
argument_list|,
argument|idx::TranslationUnit *TU
argument_list|)
block|{
return|return
name|AnaCtxMgr
operator|.
name|getContext
argument_list|(
name|D
argument_list|,
name|TU
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

