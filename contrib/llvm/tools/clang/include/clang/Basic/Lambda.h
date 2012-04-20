begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Lambda.h - Types for C++ Lambdas -----------------------*- C++ -*-===//
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
comment|// This file defines several types used to describe C++ lambda
end_comment

begin_comment
comment|// expressions that are shared between the parser and AST.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_BASIC_LAMBDA_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_LAMBDA_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// LambdaCaptureDefault - The default, if any, capture method for a
comment|/// lambda expression.
enum|enum
name|LambdaCaptureDefault
block|{
name|LCD_None
block|,
name|LCD_ByCopy
block|,
name|LCD_ByRef
block|}
enum|;
comment|/// LambdaCaptureKind - The different capture forms in a lambda
comment|/// introducer: 'this' or a copied or referenced variable.
enum|enum
name|LambdaCaptureKind
block|{
name|LCK_This
block|,
name|LCK_ByCopy
block|,
name|LCK_ByRef
block|}
enum|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_BASIC_LAMBDA_H
end_comment

end_unit

