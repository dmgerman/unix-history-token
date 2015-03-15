begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- OperatorPrecedence.h - Operator precedence levels ------*- C++ -*-===//
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
comment|/// \brief Defines and computes precedence levels for binary/ternary operators.
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
name|LLVM_CLANG_BASIC_OPERATORPRECEDENCE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_OPERATORPRECEDENCE_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/TokenKinds.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// PrecedenceLevels - These are precedences for the binary/ternary
comment|/// operators in the C99 grammar.  These have been named to relate
comment|/// with the C99 grammar productions.  Low precedences numbers bind
comment|/// more weakly than high numbers.
name|namespace
name|prec
block|{
enum|enum
name|Level
block|{
name|Unknown
init|=
literal|0
block|,
comment|// Not binary operator.
name|Comma
init|=
literal|1
block|,
comment|// ,
name|Assignment
init|=
literal|2
block|,
comment|// =, *=, /=, %=, +=, -=,<<=,>>=,&=, ^=, |=
name|Conditional
init|=
literal|3
block|,
comment|// ?
name|LogicalOr
init|=
literal|4
block|,
comment|// ||
name|LogicalAnd
init|=
literal|5
block|,
comment|//&&
name|InclusiveOr
init|=
literal|6
block|,
comment|// |
name|ExclusiveOr
init|=
literal|7
block|,
comment|// ^
name|And
init|=
literal|8
block|,
comment|//&
name|Equality
init|=
literal|9
block|,
comment|// ==, !=
name|Relational
init|=
literal|10
block|,
comment|//>=,<=,>,<
name|Shift
init|=
literal|11
block|,
comment|//<<,>>
name|Additive
init|=
literal|12
block|,
comment|// -, +
name|Multiplicative
init|=
literal|13
block|,
comment|// *, /, %
name|PointerToMember
init|=
literal|14
comment|// .*, ->*
block|}
enum|;
block|}
comment|/// \brief Return the precedence of the specified binary operator token.
name|prec
operator|::
name|Level
name|getBinOpPrecedence
argument_list|(
argument|tok::TokenKind Kind
argument_list|,
argument|bool GreaterThanIsOperator
argument_list|,
argument|bool CPlusPlus11
argument_list|)
expr_stmt|;
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
comment|// LLVM_CLANG_OPERATOR_PRECEDENCE_H
end_comment

end_unit

