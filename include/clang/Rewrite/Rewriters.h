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
name|LLVM_CLANG_REWRITE_REWRITERS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_REWRITE_REWRITERS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Preprocessor
decl_stmt|;
comment|/// RewriteMacrosInInput - Implement -rewrite-macros mode.
name|void
name|RewriteMacrosInInput
argument_list|(
name|Preprocessor
operator|&
name|PP
argument_list|,
name|llvm
operator|::
name|raw_ostream
operator|*
name|OS
argument_list|)
decl_stmt|;
comment|/// DoRewriteTest - A simple test for the TokenRewriter class.
name|void
name|DoRewriteTest
argument_list|(
name|Preprocessor
operator|&
name|PP
argument_list|,
name|llvm
operator|::
name|raw_ostream
operator|*
name|OS
argument_list|)
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

