begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- AnalysisConsumer.h - Front-end Analysis Engine Hooks ---*- C++ -*-===//
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
comment|// This header contains the functions necessary for a front-end to run various
end_comment

begin_comment
comment|// analyses.
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
name|LLVM_CLANG_STATICANALYZER_FRONTEND_ANALYSISCONSUMER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_STATICANALYZER_FRONTEND_ANALYSISCONSUMER_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/ASTConsumer.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/AnalyzerOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/BugReporter/PathDiagnostic.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Preprocessor
decl_stmt|;
name|class
name|DiagnosticsEngine
decl_stmt|;
name|class
name|CodeInjector
decl_stmt|;
name|class
name|CompilerInstance
decl_stmt|;
name|namespace
name|ento
block|{
name|class
name|CheckerManager
decl_stmt|;
name|class
name|AnalysisASTConsumer
range|:
name|public
name|ASTConsumer
block|{
name|public
operator|:
name|virtual
name|void
name|AddDiagnosticConsumer
argument_list|(
name|PathDiagnosticConsumer
operator|*
name|Consumer
argument_list|)
operator|=
literal|0
block|; }
decl_stmt|;
comment|/// CreateAnalysisConsumer - Creates an ASTConsumer to run various code
comment|/// analysis passes.  (The set of analyses run is controlled by command-line
comment|/// options.)
name|std
operator|::
name|unique_ptr
operator|<
name|AnalysisASTConsumer
operator|>
name|CreateAnalysisConsumer
argument_list|(
name|CompilerInstance
operator|&
name|CI
argument_list|)
expr_stmt|;
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

