begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ASTDiagnostic.h - Diagnostics for the AST library ------*- C++ -*-===//
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
name|LLVM_CLANG_DIAGNOSTICAST_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_DIAGNOSTICAST_H
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
name|ASTSTART
include|#
directive|include
file|"clang/Basic/DiagnosticASTKinds.inc"
undef|#
directive|undef
name|DIAG
name|NUM_BUILTIN_AST_DIAGNOSTICS
block|}
enum|;
block|}
comment|// end namespace diag
comment|/// \brief DiagnosticsEngine argument formatting function for diagnostics that
comment|/// involve AST nodes.
comment|///
comment|/// This function formats diagnostic arguments for various AST nodes,
comment|/// including types, declaration names, nested name specifiers, and
comment|/// declaration contexts, into strings that can be printed as part of
comment|/// diagnostics. It is meant to be used as the argument to
comment|/// \c DiagnosticsEngine::SetArgToStringFn(), where the cookie is an \c
comment|/// ASTContext pointer.
name|void
name|FormatASTNodeDiagnosticArgument
argument_list|(
name|DiagnosticsEngine
operator|::
name|ArgumentKind
name|Kind
argument_list|,
name|intptr_t
name|Val
argument_list|,
specifier|const
name|char
operator|*
name|Modifier
argument_list|,
name|unsigned
name|ModLen
argument_list|,
specifier|const
name|char
operator|*
name|Argument
argument_list|,
name|unsigned
name|ArgLen
argument_list|,
specifier|const
name|DiagnosticsEngine
operator|::
name|ArgumentValue
operator|*
name|PrevArgs
argument_list|,
name|unsigned
name|NumPrevArgs
argument_list|,
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|Output
argument_list|,
name|void
operator|*
name|Cookie
argument_list|,
name|ArrayRef
operator|<
name|intptr_t
operator|>
name|QualTypeVals
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

