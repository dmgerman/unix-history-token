begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- LocalCheckers.h - Intra-Procedural+Flow-Sensitive Checkers -*- C++ -*-==//
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
comment|//  This file defines the interface to call a set of intra-procedural (local)
end_comment

begin_comment
comment|//  checkers that use flow/path-sensitive analyses to find bugs.
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
name|LLVM_CLANG_GR_LOCALCHECKERS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_GR_LOCALCHECKERS_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|CFG
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|Diagnostic
decl_stmt|;
name|class
name|ASTContext
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
name|class
name|ParentMap
decl_stmt|;
name|class
name|LiveVariables
decl_stmt|;
name|class
name|ObjCImplementationDecl
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
name|class
name|TranslationUnitDecl
decl_stmt|;
name|namespace
name|ento
block|{
name|class
name|PathDiagnosticClient
decl_stmt|;
name|class
name|TransferFuncs
decl_stmt|;
name|class
name|BugType
decl_stmt|;
name|class
name|BugReporter
decl_stmt|;
name|class
name|ExprEngine
decl_stmt|;
name|TransferFuncs
modifier|*
name|MakeCFRefCountTF
parameter_list|(
name|ASTContext
modifier|&
name|Ctx
parameter_list|,
name|bool
name|GCEnabled
parameter_list|,
specifier|const
name|LangOptions
modifier|&
name|lopts
parameter_list|)
function_decl|;
name|void
name|RegisterExperimentalChecks
parameter_list|(
name|ExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
name|void
name|RegisterExperimentalInternalChecks
parameter_list|(
name|ExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
name|void
name|RegisterCallInliner
parameter_list|(
name|ExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
block|}
comment|// end GR namespace
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

