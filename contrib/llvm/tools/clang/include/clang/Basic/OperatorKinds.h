begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- OperatorKinds.h - C++ Overloaded Operators -------------*- C++ -*-===//
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
comment|// This file defines C++ overloaded operators.
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
name|LLVM_CLANG_BASIC_OPERATOR_KINDS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_OPERATOR_KINDS_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// OverloadedOperatorKind - Enumeration specifying the different kinds of
comment|/// C++ overloaded operators.
enum|enum
name|OverloadedOperatorKind
block|{
name|OO_None
block|,
comment|//< Not an overloaded operator
define|#
directive|define
name|OVERLOADED_OPERATOR
parameter_list|(
name|Name
parameter_list|,
name|Spelling
parameter_list|,
name|Token
parameter_list|,
name|Unary
parameter_list|,
name|Binary
parameter_list|,
name|MemberOnly
parameter_list|)
define|\
value|OO_##Name,
include|#
directive|include
file|"clang/Basic/OperatorKinds.def"
name|NUM_OVERLOADED_OPERATORS
block|}
enum|;
comment|/// \brief Retrieve the spelling of the given overloaded operator, without
comment|/// the preceding "operator" keyword.
specifier|const
name|char
modifier|*
name|getOperatorSpelling
parameter_list|(
name|OverloadedOperatorKind
name|Operator
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

