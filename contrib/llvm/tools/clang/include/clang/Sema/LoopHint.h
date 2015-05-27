begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- LoopHint.h - Types for LoopHint ------------------------*- C++ -*-===//
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
name|LLVM_CLANG_SEMA_LOOPHINT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_LOOPHINT_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/IdentifierTable.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/AttributeList.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/Ownership.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief Loop optimization hint for loop and unroll pragmas.
struct|struct
name|LoopHint
block|{
comment|// Source range of the directive.
name|SourceRange
name|Range
decl_stmt|;
comment|// Identifier corresponding to the name of the pragma.  "loop" for
comment|// "#pragma clang loop" directives and "unroll" for "#pragma unroll"
comment|// hints.
name|IdentifierLoc
modifier|*
name|PragmaNameLoc
decl_stmt|;
comment|// Name of the loop hint.  Examples: "unroll", "vectorize".  In the
comment|// "#pragma unroll" and "#pragma nounroll" cases, this is identical to
comment|// PragmaNameLoc.
name|IdentifierLoc
modifier|*
name|OptionLoc
decl_stmt|;
comment|// Identifier for the hint state argument.  If null, then the state is
comment|// default value such as for "#pragma unroll".
name|IdentifierLoc
modifier|*
name|StateLoc
decl_stmt|;
comment|// Expression for the hint argument if it exists, null otherwise.
name|Expr
modifier|*
name|ValueExpr
decl_stmt|;
name|LoopHint
argument_list|()
operator|:
name|PragmaNameLoc
argument_list|(
name|nullptr
argument_list|)
operator|,
name|OptionLoc
argument_list|(
name|nullptr
argument_list|)
operator|,
name|StateLoc
argument_list|(
name|nullptr
argument_list|)
operator|,
name|ValueExpr
argument_list|(
argument|nullptr
argument_list|)
block|{}
block|}
struct|;
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
comment|// LLVM_CLANG_SEMA_LOOPHINT_H
end_comment

end_unit

