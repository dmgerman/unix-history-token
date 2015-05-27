begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ParseAST.h - Define the ParseAST method ----------------*- C++ -*-===//
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
comment|//  This file defines the clang::ParseAST method.
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
name|LLVM_CLANG_PARSE_PARSEAST_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_PARSE_PARSEAST_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LangOptions.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Preprocessor
decl_stmt|;
name|class
name|ASTConsumer
decl_stmt|;
name|class
name|ASTContext
decl_stmt|;
name|class
name|CodeCompleteConsumer
decl_stmt|;
name|class
name|Sema
decl_stmt|;
comment|/// \brief Parse the entire file specified, notifying the ASTConsumer as
comment|/// the file is parsed.
comment|///
comment|/// This operation inserts the parsed decls into the translation
comment|/// unit held by Ctx.
comment|///
comment|/// \param TUKind The kind of translation unit being parsed.
comment|///
comment|/// \param CompletionConsumer If given, an object to consume code completion
comment|/// results.
name|void
name|ParseAST
parameter_list|(
name|Preprocessor
modifier|&
name|pp
parameter_list|,
name|ASTConsumer
modifier|*
name|C
parameter_list|,
name|ASTContext
modifier|&
name|Ctx
parameter_list|,
name|bool
name|PrintStats
init|=
name|false
parameter_list|,
name|TranslationUnitKind
name|TUKind
init|=
name|TU_Complete
parameter_list|,
name|CodeCompleteConsumer
modifier|*
name|CompletionConsumer
init|=
name|nullptr
parameter_list|,
name|bool
name|SkipFunctionBodies
init|=
name|false
parameter_list|)
function_decl|;
comment|/// \brief Parse the main file known to the preprocessor, producing an
comment|/// abstract syntax tree.
name|void
name|ParseAST
parameter_list|(
name|Sema
modifier|&
name|S
parameter_list|,
name|bool
name|PrintStats
init|=
name|false
parameter_list|,
name|bool
name|SkipFunctionBodies
init|=
name|false
parameter_list|)
function_decl|;
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

