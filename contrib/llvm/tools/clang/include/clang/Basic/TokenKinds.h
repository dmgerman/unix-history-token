begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- TokenKinds.h - Enum values for C Token Kinds -----------*- C++ -*-===//
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
comment|//  This file defines the TokenKind enum and support functions.
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
name|LLVM_CLANG_TOKENKINDS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TOKENKINDS_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|tok
block|{
comment|/// TokenKind - This provides a simple uniform namespace for tokens from all C
comment|/// languages.
enum|enum
name|TokenKind
block|{
define|#
directive|define
name|TOK
parameter_list|(
name|X
parameter_list|)
value|X,
include|#
directive|include
file|"clang/Basic/TokenKinds.def"
name|NUM_TOKENS
block|}
enum|;
comment|/// PPKeywordKind - This provides a namespace for preprocessor keywords which
comment|/// start with a '#' at the beginning of the line.
enum|enum
name|PPKeywordKind
block|{
define|#
directive|define
name|PPKEYWORD
parameter_list|(
name|X
parameter_list|)
value|pp_##X,
include|#
directive|include
file|"clang/Basic/TokenKinds.def"
name|NUM_PP_KEYWORDS
block|}
enum|;
comment|/// ObjCKeywordKind - This provides a namespace for Objective-C keywords which
comment|/// start with an '@'.
enum|enum
name|ObjCKeywordKind
block|{
define|#
directive|define
name|OBJC1_AT_KEYWORD
parameter_list|(
name|X
parameter_list|)
value|objc_##X,
define|#
directive|define
name|OBJC2_AT_KEYWORD
parameter_list|(
name|X
parameter_list|)
value|objc_##X,
include|#
directive|include
file|"clang/Basic/TokenKinds.def"
name|NUM_OBJC_KEYWORDS
block|}
enum|;
comment|/// \brief Determines the name of a token as used within the front end.
comment|///
comment|/// The name of a token will be an internal name (such as "l_square")
comment|/// and should not be used as part of diagnostic messages.
specifier|const
name|char
modifier|*
name|getTokenName
parameter_list|(
name|enum
name|TokenKind
name|Kind
parameter_list|)
function_decl|;
comment|/// \brief Determines the spelling of simple punctuation tokens like
comment|/// '!' or '%', and returns NULL for literal and annotation tokens.
comment|///
comment|/// This routine only retrieves the "simple" spelling of the token,
comment|/// and will not produce any alternative spellings (e.g., a
comment|/// digraph). For the actual spelling of a given Token, use
comment|/// Preprocessor::getSpelling().
specifier|const
name|char
modifier|*
name|getTokenSimpleSpelling
parameter_list|(
name|enum
name|TokenKind
name|Kind
parameter_list|)
function_decl|;
block|}
comment|// end namespace tok
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

