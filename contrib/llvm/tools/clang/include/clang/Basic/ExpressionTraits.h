begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ExpressionTraits.h - C++ Expression Traits Support Enums -*- C++ -*-===//
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
comment|/// \brief Defines enumerations for expression traits intrinsics.
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
name|LLVM_CLANG_BASIC_EXPRESSIONTRAITS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_EXPRESSIONTRAITS_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
enum|enum
name|ExpressionTrait
block|{
name|ET_IsLValueExpr
block|,
name|ET_IsRValueExpr
block|}
enum|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

