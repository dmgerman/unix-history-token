begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- DiagnosticLex.h - Diagnostics for liblex ---------------*- C++ -*-===//
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
name|LLVM_CLANG_DIAGNOSTICLEX_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_DIAGNOSTICLEX_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/Diagnostic.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|diag
block|{
enum|enum
block|{
define|#
directive|define
name|DIAG
parameter_list|(
name|ENUM
parameter_list|,
name|FLAGS
parameter_list|,
name|DEFAULT_MAPPING
parameter_list|,
name|DESC
parameter_list|,
name|GROUP
parameter_list|,\
name|SFINAE
parameter_list|,
name|NOWERROR
parameter_list|,
name|SHOWINSYSHEADER
parameter_list|,
name|CATEGORY
parameter_list|)
value|ENUM,
define|#
directive|define
name|LEXSTART
include|#
directive|include
file|"clang/Basic/DiagnosticLexKinds.inc"
undef|#
directive|undef
name|DIAG
name|NUM_BUILTIN_LEX_DIAGNOSTICS
block|}
enum|;
block|}
comment|// end namespace diag
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

