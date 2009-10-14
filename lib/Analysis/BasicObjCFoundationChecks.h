begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//== BasicObjCFoundationChecks.h - Simple Apple-Foundation checks -*- C++ -*--//
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
comment|//  This file defines BasicObjCFoundationChecks, a class that encapsulates
end_comment

begin_comment
comment|//  a set of simple checks to run on Objective-C code using Apple's Foundation
end_comment

begin_comment
comment|//  classes.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_include
include|#
directive|include
file|"clang/Analysis/PathSensitive/ExplodedGraph.h"
end_include

begin_include
include|#
directive|include
file|"clang/Analysis/PathSensitive/GRSimpleAPICheck.h"
end_include

begin_include
include|#
directive|include
file|"clang/Analysis/PathSensitive/GRState.h"
end_include

begin_include
include|#
directive|include
file|"clang/Analysis/PathDiagnostic.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Expr.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/ASTContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_ANALYSIS_BASICOBJCFOUNDATIONCHECKS
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ANALYSIS_BASICOBJCFOUNDATIONCHECKS
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|GRSimpleAPICheck
decl_stmt|;
name|class
name|ASTContext
decl_stmt|;
name|class
name|GRStateManager
decl_stmt|;
name|class
name|BugReporter
decl_stmt|;
name|class
name|GRExprEngine
decl_stmt|;
name|GRSimpleAPICheck
modifier|*
name|CreateBasicObjCFoundationChecks
parameter_list|(
name|ASTContext
modifier|&
name|Ctx
parameter_list|,
name|BugReporter
modifier|&
name|BR
parameter_list|)
function_decl|;
name|GRSimpleAPICheck
modifier|*
name|CreateAuditCFNumberCreate
parameter_list|(
name|ASTContext
modifier|&
name|Ctx
parameter_list|,
name|BugReporter
modifier|&
name|BR
parameter_list|)
function_decl|;
name|GRSimpleAPICheck
modifier|*
name|CreateAuditCFRetainRelease
parameter_list|(
name|ASTContext
modifier|&
name|Ctx
parameter_list|,
name|BugReporter
modifier|&
name|BR
parameter_list|)
function_decl|;
name|void
name|RegisterNSErrorChecks
parameter_list|(
name|BugReporter
modifier|&
name|BR
parameter_list|,
name|GRExprEngine
modifier|&
name|Eng
parameter_list|,
specifier|const
name|Decl
modifier|&
name|D
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

