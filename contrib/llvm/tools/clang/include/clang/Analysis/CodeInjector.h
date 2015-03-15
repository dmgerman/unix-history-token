begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CodeInjector.h ------------------------------------------*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Defines the clang::CodeInjector interface which is responsible for
end_comment

begin_comment
comment|/// injecting AST of function definitions that may not be available in the
end_comment

begin_comment
comment|/// original source.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_ANALYSIS_CODEINJECTOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ANALYSIS_CODEINJECTOR_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Stmt
decl_stmt|;
name|class
name|FunctionDecl
decl_stmt|;
name|class
name|ObjCMethodDecl
decl_stmt|;
comment|/// \brief CodeInjector is an interface which is responsible for injecting AST
comment|/// of function definitions that may not be available in the original source.
comment|///
comment|/// The getBody function will be called each time the static analyzer examines a
comment|/// function call that has no definition available in the current translation
comment|/// unit. If the returned statement is not a null pointer, it is assumed to be
comment|/// the body of a function which will be used for the analysis. The source of
comment|/// the body can be arbitrary, but it is advised to use memoization to avoid
comment|/// unnecessary reparsing of the external source that provides the body of the
comment|/// functions.
name|class
name|CodeInjector
block|{
name|public
label|:
name|CodeInjector
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|CodeInjector
argument_list|()
expr_stmt|;
name|virtual
name|Stmt
modifier|*
name|getBody
parameter_list|(
specifier|const
name|FunctionDecl
modifier|*
name|D
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|Stmt
modifier|*
name|getBody
parameter_list|(
specifier|const
name|ObjCMethodDecl
modifier|*
name|D
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

