begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- AllDiagnostics.h - Aggregate Diagnostic headers --------*- C++ -*-===//
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
comment|/// \brief Includes all the separate Diagnostic headers& some related helpers.
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
name|LLVM_CLANG_BASIC_ALLDIAGNOSTICS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_ALLDIAGNOSTICS_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/ASTDiagnostic.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/CommentDiagnostic.h"
end_include

begin_include
include|#
directive|include
file|"clang/Analysis/AnalysisDiagnostic.h"
end_include

begin_include
include|#
directive|include
file|"clang/Driver/DriverDiagnostic.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/FrontendDiagnostic.h"
end_include

begin_include
include|#
directive|include
file|"clang/Lex/LexDiagnostic.h"
end_include

begin_include
include|#
directive|include
file|"clang/Parse/ParseDiagnostic.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/SemaDiagnostic.h"
end_include

begin_include
include|#
directive|include
file|"clang/Serialization/SerializationDiagnostic.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|template
operator|<
name|size_t
name|SizeOfStr
operator|,
name|typename
name|FieldType
operator|>
name|class
name|StringSizerHelper
block|{
name|static_assert
argument_list|(
name|SizeOfStr
operator|<=
name|FieldType
argument_list|(
operator|~
literal|0U
argument_list|)
argument_list|,
literal|"Field too small!"
argument_list|)
block|;
name|public
operator|:
expr|enum
block|{
name|Size
operator|=
name|SizeOfStr
block|}
block|; }
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_define
define|#
directive|define
name|STR_SIZE
parameter_list|(
name|str
parameter_list|,
name|fieldTy
parameter_list|)
value|clang::StringSizerHelper<sizeof(str)-1, \                                                         fieldTy>::Size
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

