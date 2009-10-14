begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// GRCheckAPI.h - Simple API checks based on GRAuditor ------------*- C++ -*--//
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
comment|//  This file defines the interface for building simple, path-sensitive checks
end_comment

begin_comment
comment|//  that are stateless and only emit warnings at errors that occur at
end_comment

begin_comment
comment|//  CallExpr or ObjCMessageExpr.
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
name|LLVM_CLANG_ANALYSIS_GRAPICHECKS
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ANALYSIS_GRAPICHECKS
end_define

begin_include
include|#
directive|include
file|"clang/Analysis/PathSensitive/GRAuditor.h"
end_include

begin_include
include|#
directive|include
file|"clang/Analysis/PathSensitive/GRState.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Diagnostic
decl_stmt|;
name|class
name|BugReporter
decl_stmt|;
name|class
name|ASTContext
decl_stmt|;
name|class
name|GRExprEngine
decl_stmt|;
name|class
name|PathDiagnosticClient
decl_stmt|;
name|class
name|ExplodedGraph
decl_stmt|;
name|class
name|GRSimpleAPICheck
range|:
name|public
name|GRAuditor
block|{
name|public
operator|:
name|GRSimpleAPICheck
argument_list|()
block|{}
name|virtual
operator|~
name|GRSimpleAPICheck
argument_list|()
block|{}
block|}
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

