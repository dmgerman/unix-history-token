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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Defines the clang::TokenKind enum and support functions.
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
name|LLVM_CLANG_BASIC_TOKENKINDS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_TOKENKINDS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|tok
block|{
comment|/// \brief Provides a simple uniform namespace for tokens from all C languages.
enum|enum
name|TokenKind
enum|:
name|unsigned
name|short
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
comment|/// \brief Provides a namespace for preprocessor keywords which start with a
comment|/// '#' at the beginning of the line.
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
comment|/// \brief Provides a namespace for Objective-C keywords which start with
comment|/// an '@'.
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
comment|/// \brief Defines the possible values of an on-off-switch (C99 6.10.6p2).
enum|enum
name|OnOffSwitch
block|{
name|OOS_ON
block|,
name|OOS_OFF
block|,
name|OOS_DEFAULT
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
argument_list|(
name|TokenKind
name|Kind
argument_list|)
name|LLVM_READNONE
decl_stmt|;
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
name|getPunctuatorSpelling
argument_list|(
name|TokenKind
name|Kind
argument_list|)
name|LLVM_READNONE
decl_stmt|;
comment|/// \brief Determines the spelling of simple keyword and contextual keyword
comment|/// tokens like 'int' and 'dynamic_cast'. Returns NULL for other token kinds.
specifier|const
name|char
modifier|*
name|getKeywordSpelling
argument_list|(
name|TokenKind
name|Kind
argument_list|)
name|LLVM_READNONE
decl_stmt|;
comment|/// \brief Return true if this is a raw identifier or an identifier kind.
specifier|inline
name|bool
name|isAnyIdentifier
parameter_list|(
name|TokenKind
name|K
parameter_list|)
block|{
return|return
operator|(
name|K
operator|==
name|tok
operator|::
name|identifier
operator|)
operator|||
operator|(
name|K
operator|==
name|tok
operator|::
name|raw_identifier
operator|)
return|;
block|}
comment|/// \brief Return true if this is a C or C++ string-literal (or
comment|/// C++11 user-defined-string-literal) token.
specifier|inline
name|bool
name|isStringLiteral
parameter_list|(
name|TokenKind
name|K
parameter_list|)
block|{
return|return
name|K
operator|==
name|tok
operator|::
name|string_literal
operator|||
name|K
operator|==
name|tok
operator|::
name|wide_string_literal
operator|||
name|K
operator|==
name|tok
operator|::
name|utf8_string_literal
operator|||
name|K
operator|==
name|tok
operator|::
name|utf16_string_literal
operator|||
name|K
operator|==
name|tok
operator|::
name|utf32_string_literal
return|;
block|}
comment|/// \brief Return true if this is a "literal" kind, like a numeric
comment|/// constant, string, etc.
specifier|inline
name|bool
name|isLiteral
parameter_list|(
name|TokenKind
name|K
parameter_list|)
block|{
return|return
name|K
operator|==
name|tok
operator|::
name|numeric_constant
operator|||
name|K
operator|==
name|tok
operator|::
name|char_constant
operator|||
name|K
operator|==
name|tok
operator|::
name|wide_char_constant
operator|||
name|K
operator|==
name|tok
operator|::
name|utf8_char_constant
operator|||
name|K
operator|==
name|tok
operator|::
name|utf16_char_constant
operator|||
name|K
operator|==
name|tok
operator|::
name|utf32_char_constant
operator|||
name|isStringLiteral
argument_list|(
name|K
argument_list|)
operator|||
name|K
operator|==
name|tok
operator|::
name|angle_string_literal
return|;
block|}
comment|/// \brief Return true if this is any of tok::annot_* kinds.
specifier|inline
name|bool
name|isAnnotation
parameter_list|(
name|TokenKind
name|K
parameter_list|)
block|{
define|#
directive|define
name|ANNOTATION
parameter_list|(
name|NAME
parameter_list|)
define|\
value|if (K == tok::annot_##NAME) \     return true;
include|#
directive|include
file|"clang/Basic/TokenKinds.def"
return|return
name|false
return|;
block|}
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

