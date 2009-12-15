begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- TypeTraits.h - C++ Type Traits Support Enumerations ----*- C++ -*-===//
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
comment|//  This file defines enumerations for the type traits support.
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
name|LLVM_CLANG_TYPETRAITS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TYPETRAITS_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// UnaryTypeTrait - Names for the unary type traits.
enum|enum
name|UnaryTypeTrait
block|{
name|UTT_HasNothrowAssign
block|,
name|UTT_HasNothrowCopy
block|,
name|UTT_HasNothrowConstructor
block|,
name|UTT_HasTrivialAssign
block|,
name|UTT_HasTrivialCopy
block|,
name|UTT_HasTrivialConstructor
block|,
name|UTT_HasTrivialDestructor
block|,
name|UTT_HasVirtualDestructor
block|,
name|UTT_IsAbstract
block|,
name|UTT_IsClass
block|,
name|UTT_IsEmpty
block|,
name|UTT_IsEnum
block|,
name|UTT_IsPOD
block|,
name|UTT_IsPolymorphic
block|,
name|UTT_IsUnion
block|,
name|UTT_IsLiteral
block|}
enum|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

