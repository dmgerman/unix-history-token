begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CGBuilder.h - Choose IRBuilder implementation  ----------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|CLANG_CODEGEN_CGBUILDER_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_CODEGEN_CGBUILDER_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/IRBuilder.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|CodeGen
block|{
comment|// Don't preserve names on values in an optimized build.
ifdef|#
directive|ifdef
name|NDEBUG
typedef|typedef
name|llvm
operator|::
name|IRBuilder
operator|<
name|false
operator|>
name|CGBuilderTy
expr_stmt|;
else|#
directive|else
typedef|typedef
name|llvm
operator|::
name|IRBuilder
operator|<
operator|>
name|CGBuilderTy
expr_stmt|;
endif|#
directive|endif
block|}
comment|// end namespace CodeGen
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

