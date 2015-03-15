begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Rewriters.h - Rewriter implementations     -------------*- C++ -*-===//
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
comment|//  This header contains miscellaneous utilities for various front-end actions.
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
name|LLVM_CLANG_REWRITE_FRONTEND_REWRITERS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_REWRITE_FRONTEND_REWRITERS_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Preprocessor
decl_stmt|;
name|class
name|PreprocessorOutputOptions
decl_stmt|;
comment|/// RewriteMacrosInInput - Implement -rewrite-macros mode.
name|void
name|RewriteMacrosInInput
parameter_list|(
name|Preprocessor
modifier|&
name|PP
parameter_list|,
name|raw_ostream
modifier|*
name|OS
parameter_list|)
function_decl|;
comment|/// DoRewriteTest - A simple test for the TokenRewriter class.
name|void
name|DoRewriteTest
parameter_list|(
name|Preprocessor
modifier|&
name|PP
parameter_list|,
name|raw_ostream
modifier|*
name|OS
parameter_list|)
function_decl|;
comment|/// RewriteIncludesInInput - Implement -frewrite-includes mode.
name|void
name|RewriteIncludesInInput
parameter_list|(
name|Preprocessor
modifier|&
name|PP
parameter_list|,
name|raw_ostream
modifier|*
name|OS
parameter_list|,
specifier|const
name|PreprocessorOutputOptions
modifier|&
name|Opts
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

