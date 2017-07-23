begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Token.h - Token interface ------------------------------*- C++ -*-===//
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
comment|//  This file defines the Token interface.
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
name|LLVM_CLANG_LEX_TOKEN_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LEX_TOKEN_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/TokenKinds.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|IdentifierInfo
decl_stmt|;
comment|/// Token - This structure provides full information about a lexed token.
comment|/// It is not intended to be space efficient, it is intended to return as much
comment|/// information as possible about each returned token.  This is expected to be
comment|/// compressed into a smaller form if memory footprint is important.
comment|///
comment|/// The parser can create a special "annotation token" representing a stream of
comment|/// tokens that were parsed and semantically resolved, e.g.: "foo::MyClass<int>"
comment|/// can be represented by a single typename annotation token that carries
comment|/// information about the SourceRange of the tokens and the type object.
name|class
name|Token
block|{
comment|/// The location of the token. This is actually a SourceLocation.
name|unsigned
name|Loc
decl_stmt|;
comment|// Conceptually these next two fields could be in a union.  However, this
comment|// causes gcc 4.2 to pessimize LexTokenInternal, a very performance critical
comment|// routine. Keeping as separate members with casts until a more beautiful fix
comment|// presents itself.
comment|/// UintData - This holds either the length of the token text, when
comment|/// a normal token, or the end of the SourceRange when an annotation
comment|/// token.
name|unsigned
name|UintData
decl_stmt|;
comment|/// PtrData - This is a union of four different pointer types, which depends
comment|/// on what type of token this is:
comment|///  Identifiers, keywords, etc:
comment|///    This is an IdentifierInfo*, which contains the uniqued identifier
comment|///    spelling.
comment|///  Literals:  isLiteral() returns true.
comment|///    This is a pointer to the start of the token in a text buffer, which
comment|///    may be dirty (have trigraphs / escaped newlines).
comment|///  Annotations (resolved type names, C++ scopes, etc): isAnnotation().
comment|///    This is a pointer to sema-specific data for the annotation token.
comment|///  Eof:
comment|//     This is a pointer to a Decl.
comment|///  Other:
comment|///    This is null.
name|void
modifier|*
name|PtrData
decl_stmt|;
comment|/// Kind - The actual flavor of token this is.
name|tok
operator|::
name|TokenKind
name|Kind
expr_stmt|;
comment|/// Flags - Bits we track about this token, members of the TokenFlags enum.
name|unsigned
name|short
name|Flags
decl_stmt|;
name|public
label|:
comment|// Various flags set per token:
enum|enum
name|TokenFlags
block|{
name|StartOfLine
init|=
literal|0x01
block|,
comment|// At start of line or only after whitespace
comment|// (considering the line after macro expansion).
name|LeadingSpace
init|=
literal|0x02
block|,
comment|// Whitespace exists before this token (considering
comment|// whitespace after macro expansion).
name|DisableExpand
init|=
literal|0x04
block|,
comment|// This identifier may never be macro expanded.
name|NeedsCleaning
init|=
literal|0x08
block|,
comment|// Contained an escaped newline or trigraph.
name|LeadingEmptyMacro
init|=
literal|0x10
block|,
comment|// Empty macro exists before this token.
name|HasUDSuffix
init|=
literal|0x20
block|,
comment|// This string or character literal has a ud-suffix.
name|HasUCN
init|=
literal|0x40
block|,
comment|// This identifier contains a UCN.
name|IgnoredComma
init|=
literal|0x80
block|,
comment|// This comma is not a macro argument separator (MS).
name|StringifiedInMacro
init|=
literal|0x100
block|,
comment|// This string or character literal is formed by
comment|// macro stringizing or charizing operator.
name|CommaAfterElided
init|=
literal|0x200
block|,
comment|// The comma following this token was elided (MS).
name|IsEditorPlaceholder
init|=
literal|0x400
block|,
comment|// This identifier is a placeholder.
block|}
enum|;
name|tok
operator|::
name|TokenKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
name|void
name|setKind
argument_list|(
name|tok
operator|::
name|TokenKind
name|K
argument_list|)
block|{
name|Kind
operator|=
name|K
expr_stmt|;
block|}
comment|/// is/isNot - Predicates to check if this token is a specific kind, as in
comment|/// "if (Tok.is(tok::l_brace)) {...}".
name|bool
name|is
argument_list|(
name|tok
operator|::
name|TokenKind
name|K
argument_list|)
decl|const
block|{
return|return
name|Kind
operator|==
name|K
return|;
block|}
name|bool
name|isNot
argument_list|(
name|tok
operator|::
name|TokenKind
name|K
argument_list|)
decl|const
block|{
return|return
name|Kind
operator|!=
name|K
return|;
block|}
name|bool
name|isOneOf
argument_list|(
name|tok
operator|::
name|TokenKind
name|K1
argument_list|,
name|tok
operator|::
name|TokenKind
name|K2
argument_list|)
decl|const
block|{
return|return
name|is
argument_list|(
name|K1
argument_list|)
operator|||
name|is
argument_list|(
name|K2
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
operator|...
name|Ts
operator|>
name|bool
name|isOneOf
argument_list|(
argument|tok::TokenKind K1
argument_list|,
argument|tok::TokenKind K2
argument_list|,
argument|Ts... Ks
argument_list|)
specifier|const
block|{
return|return
name|is
argument_list|(
name|K1
argument_list|)
operator|||
name|isOneOf
argument_list|(
name|K2
argument_list|,
name|Ks
operator|...
argument_list|)
return|;
block|}
comment|/// \brief Return true if this is a raw identifier (when lexing
comment|/// in raw mode) or a non-keyword identifier (when lexing in non-raw mode).
name|bool
name|isAnyIdentifier
argument_list|()
specifier|const
block|{
return|return
name|tok
operator|::
name|isAnyIdentifier
argument_list|(
name|getKind
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Return true if this is a "literal", like a numeric
comment|/// constant, string, etc.
name|bool
name|isLiteral
argument_list|()
specifier|const
block|{
return|return
name|tok
operator|::
name|isLiteral
argument_list|(
name|getKind
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Return true if this is any of tok::annot_* kind tokens.
name|bool
name|isAnnotation
argument_list|()
specifier|const
block|{
return|return
name|tok
operator|::
name|isAnnotation
argument_list|(
name|getKind
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Return a source location identifier for the specified
comment|/// offset in the current file.
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|SourceLocation
operator|::
name|getFromRawEncoding
argument_list|(
name|Loc
argument_list|)
return|;
block|}
name|unsigned
name|getLength
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|isAnnotation
argument_list|()
operator|&&
literal|"Annotation tokens have no length field"
argument_list|)
block|;
return|return
name|UintData
return|;
block|}
name|void
name|setLocation
parameter_list|(
name|SourceLocation
name|L
parameter_list|)
block|{
name|Loc
operator|=
name|L
operator|.
name|getRawEncoding
argument_list|()
expr_stmt|;
block|}
name|void
name|setLength
parameter_list|(
name|unsigned
name|Len
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|isAnnotation
argument_list|()
operator|&&
literal|"Annotation tokens have no length field"
argument_list|)
expr_stmt|;
name|UintData
operator|=
name|Len
expr_stmt|;
block|}
name|SourceLocation
name|getAnnotationEndLoc
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isAnnotation
argument_list|()
operator|&&
literal|"Used AnnotEndLocID on non-annotation token"
argument_list|)
block|;
return|return
name|SourceLocation
operator|::
name|getFromRawEncoding
argument_list|(
name|UintData
condition|?
name|UintData
else|:
name|Loc
argument_list|)
return|;
block|}
name|void
name|setAnnotationEndLoc
parameter_list|(
name|SourceLocation
name|L
parameter_list|)
block|{
name|assert
argument_list|(
name|isAnnotation
argument_list|()
operator|&&
literal|"Used AnnotEndLocID on non-annotation token"
argument_list|)
expr_stmt|;
name|UintData
operator|=
name|L
operator|.
name|getRawEncoding
argument_list|()
expr_stmt|;
block|}
name|SourceLocation
name|getLastLoc
argument_list|()
specifier|const
block|{
return|return
name|isAnnotation
argument_list|()
operator|?
name|getAnnotationEndLoc
argument_list|()
operator|:
name|getLocation
argument_list|()
return|;
block|}
name|SourceLocation
name|getEndLoc
argument_list|()
specifier|const
block|{
return|return
name|isAnnotation
argument_list|()
operator|?
name|getAnnotationEndLoc
argument_list|()
operator|:
name|getLocation
argument_list|()
operator|.
name|getLocWithOffset
argument_list|(
name|getLength
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief SourceRange of the group of tokens that this annotation token
comment|/// represents.
name|SourceRange
name|getAnnotationRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|getLocation
argument_list|()
argument_list|,
name|getAnnotationEndLoc
argument_list|()
argument_list|)
return|;
block|}
name|void
name|setAnnotationRange
parameter_list|(
name|SourceRange
name|R
parameter_list|)
block|{
name|setLocation
argument_list|(
name|R
operator|.
name|getBegin
argument_list|()
argument_list|)
expr_stmt|;
name|setAnnotationEndLoc
argument_list|(
name|R
operator|.
name|getEnd
argument_list|()
argument_list|)
expr_stmt|;
block|}
specifier|const
name|char
operator|*
name|getName
argument_list|()
specifier|const
block|{
return|return
name|tok
operator|::
name|getTokenName
argument_list|(
name|Kind
argument_list|)
return|;
block|}
comment|/// \brief Reset all flags to cleared.
name|void
name|startToken
parameter_list|()
block|{
name|Kind
operator|=
name|tok
operator|::
name|unknown
expr_stmt|;
name|Flags
operator|=
literal|0
expr_stmt|;
name|PtrData
operator|=
name|nullptr
expr_stmt|;
name|UintData
operator|=
literal|0
expr_stmt|;
name|Loc
operator|=
name|SourceLocation
argument_list|()
operator|.
name|getRawEncoding
argument_list|()
expr_stmt|;
block|}
name|IdentifierInfo
operator|*
name|getIdentifierInfo
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isNot
argument_list|(
name|tok
operator|::
name|raw_identifier
argument_list|)
operator|&&
literal|"getIdentifierInfo() on a tok::raw_identifier token!"
argument_list|)
block|;
name|assert
argument_list|(
operator|!
name|isAnnotation
argument_list|()
operator|&&
literal|"getIdentifierInfo() on an annotation token!"
argument_list|)
block|;
if|if
condition|(
name|isLiteral
argument_list|()
condition|)
return|return
name|nullptr
return|;
if|if
condition|(
name|is
argument_list|(
name|tok
operator|::
name|eof
argument_list|)
condition|)
return|return
name|nullptr
return|;
return|return
operator|(
name|IdentifierInfo
operator|*
operator|)
name|PtrData
return|;
block|}
name|void
name|setIdentifierInfo
parameter_list|(
name|IdentifierInfo
modifier|*
name|II
parameter_list|)
block|{
name|PtrData
operator|=
operator|(
name|void
operator|*
operator|)
name|II
expr_stmt|;
block|}
specifier|const
name|void
operator|*
name|getEofData
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|is
argument_list|(
name|tok
operator|::
name|eof
argument_list|)
argument_list|)
block|;
return|return
name|reinterpret_cast
operator|<
specifier|const
name|void
operator|*
operator|>
operator|(
name|PtrData
operator|)
return|;
block|}
name|void
name|setEofData
parameter_list|(
specifier|const
name|void
modifier|*
name|D
parameter_list|)
block|{
name|assert
argument_list|(
name|is
argument_list|(
name|tok
operator|::
name|eof
argument_list|)
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|!
name|PtrData
argument_list|)
expr_stmt|;
name|PtrData
operator|=
name|const_cast
operator|<
name|void
operator|*
operator|>
operator|(
name|D
operator|)
expr_stmt|;
block|}
comment|/// getRawIdentifier - For a raw identifier token (i.e., an identifier
comment|/// lexed in raw mode), returns a reference to the text substring in the
comment|/// buffer if known.
name|StringRef
name|getRawIdentifier
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|is
argument_list|(
name|tok
operator|::
name|raw_identifier
argument_list|)
argument_list|)
block|;
return|return
name|StringRef
argument_list|(
name|reinterpret_cast
operator|<
specifier|const
name|char
operator|*
operator|>
operator|(
name|PtrData
operator|)
argument_list|,
name|getLength
argument_list|()
argument_list|)
return|;
block|}
name|void
name|setRawIdentifierData
parameter_list|(
specifier|const
name|char
modifier|*
name|Ptr
parameter_list|)
block|{
name|assert
argument_list|(
name|is
argument_list|(
name|tok
operator|::
name|raw_identifier
argument_list|)
argument_list|)
expr_stmt|;
name|PtrData
operator|=
name|const_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|Ptr
operator|)
expr_stmt|;
block|}
comment|/// getLiteralData - For a literal token (numeric constant, string, etc), this
comment|/// returns a pointer to the start of it in the text buffer if known, null
comment|/// otherwise.
specifier|const
name|char
operator|*
name|getLiteralData
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isLiteral
argument_list|()
operator|&&
literal|"Cannot get literal data of non-literal"
argument_list|)
block|;
return|return
name|reinterpret_cast
operator|<
specifier|const
name|char
operator|*
operator|>
operator|(
name|PtrData
operator|)
return|;
block|}
name|void
name|setLiteralData
parameter_list|(
specifier|const
name|char
modifier|*
name|Ptr
parameter_list|)
block|{
name|assert
argument_list|(
name|isLiteral
argument_list|()
operator|&&
literal|"Cannot set literal data of non-literal"
argument_list|)
expr_stmt|;
name|PtrData
operator|=
name|const_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|Ptr
operator|)
expr_stmt|;
block|}
name|void
operator|*
name|getAnnotationValue
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isAnnotation
argument_list|()
operator|&&
literal|"Used AnnotVal on non-annotation token"
argument_list|)
block|;
return|return
name|PtrData
return|;
block|}
name|void
name|setAnnotationValue
parameter_list|(
name|void
modifier|*
name|val
parameter_list|)
block|{
name|assert
argument_list|(
name|isAnnotation
argument_list|()
operator|&&
literal|"Used AnnotVal on non-annotation token"
argument_list|)
expr_stmt|;
name|PtrData
operator|=
name|val
expr_stmt|;
block|}
comment|/// \brief Set the specified flag.
name|void
name|setFlag
parameter_list|(
name|TokenFlags
name|Flag
parameter_list|)
block|{
name|Flags
operator||=
name|Flag
expr_stmt|;
block|}
comment|/// \brief Get the specified flag.
name|bool
name|getFlag
argument_list|(
name|TokenFlags
name|Flag
argument_list|)
decl|const
block|{
return|return
operator|(
name|Flags
operator|&
name|Flag
operator|)
operator|!=
literal|0
return|;
block|}
comment|/// \brief Unset the specified flag.
name|void
name|clearFlag
parameter_list|(
name|TokenFlags
name|Flag
parameter_list|)
block|{
name|Flags
operator|&=
operator|~
name|Flag
expr_stmt|;
block|}
comment|/// \brief Return the internal represtation of the flags.
comment|///
comment|/// This is only intended for low-level operations such as writing tokens to
comment|/// disk.
name|unsigned
name|getFlags
argument_list|()
specifier|const
block|{
return|return
name|Flags
return|;
block|}
comment|/// \brief Set a flag to either true or false.
name|void
name|setFlagValue
parameter_list|(
name|TokenFlags
name|Flag
parameter_list|,
name|bool
name|Val
parameter_list|)
block|{
if|if
condition|(
name|Val
condition|)
name|setFlag
argument_list|(
name|Flag
argument_list|)
expr_stmt|;
else|else
name|clearFlag
argument_list|(
name|Flag
argument_list|)
expr_stmt|;
block|}
comment|/// isAtStartOfLine - Return true if this token is at the start of a line.
comment|///
name|bool
name|isAtStartOfLine
argument_list|()
specifier|const
block|{
return|return
name|getFlag
argument_list|(
name|StartOfLine
argument_list|)
return|;
block|}
comment|/// \brief Return true if this token has whitespace before it.
comment|///
name|bool
name|hasLeadingSpace
argument_list|()
specifier|const
block|{
return|return
name|getFlag
argument_list|(
name|LeadingSpace
argument_list|)
return|;
block|}
comment|/// \brief Return true if this identifier token should never
comment|/// be expanded in the future, due to C99 6.10.3.4p2.
name|bool
name|isExpandDisabled
argument_list|()
specifier|const
block|{
return|return
name|getFlag
argument_list|(
name|DisableExpand
argument_list|)
return|;
block|}
comment|/// \brief Return true if we have an ObjC keyword identifier.
name|bool
name|isObjCAtKeyword
argument_list|(
name|tok
operator|::
name|ObjCKeywordKind
name|objcKey
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return the ObjC keyword kind.
name|tok
operator|::
name|ObjCKeywordKind
name|getObjCKeywordID
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Return true if this token has trigraphs or escaped newlines in it.
name|bool
name|needsCleaning
argument_list|()
specifier|const
block|{
return|return
name|getFlag
argument_list|(
name|NeedsCleaning
argument_list|)
return|;
block|}
comment|/// \brief Return true if this token has an empty macro before it.
comment|///
name|bool
name|hasLeadingEmptyMacro
argument_list|()
specifier|const
block|{
return|return
name|getFlag
argument_list|(
name|LeadingEmptyMacro
argument_list|)
return|;
block|}
comment|/// \brief Return true if this token is a string or character literal which
comment|/// has a ud-suffix.
name|bool
name|hasUDSuffix
argument_list|()
specifier|const
block|{
return|return
name|getFlag
argument_list|(
name|HasUDSuffix
argument_list|)
return|;
block|}
comment|/// Returns true if this token contains a universal character name.
name|bool
name|hasUCN
argument_list|()
specifier|const
block|{
return|return
name|getFlag
argument_list|(
name|HasUCN
argument_list|)
return|;
block|}
comment|/// Returns true if this token is formed by macro by stringizing or charizing
comment|/// operator.
name|bool
name|stringifiedInMacro
argument_list|()
specifier|const
block|{
return|return
name|getFlag
argument_list|(
name|StringifiedInMacro
argument_list|)
return|;
block|}
comment|/// Returns true if the comma after this token was elided.
name|bool
name|commaAfterElided
argument_list|()
specifier|const
block|{
return|return
name|getFlag
argument_list|(
name|CommaAfterElided
argument_list|)
return|;
block|}
comment|/// Returns true if this token is an editor placeholder.
comment|///
comment|/// Editor placeholders are produced by the code-completion engine and are
comment|/// represented as characters between '<#' and '#>' in the source code. The
comment|/// lexer uses identifier tokens to represent placeholders.
name|bool
name|isEditorPlaceholder
argument_list|()
specifier|const
block|{
return|return
name|getFlag
argument_list|(
name|IsEditorPlaceholder
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Information about the conditional stack (\#if directives)
end_comment

begin_comment
comment|/// currently active.
end_comment

begin_struct
struct|struct
name|PPConditionalInfo
block|{
comment|/// \brief Location where the conditional started.
name|SourceLocation
name|IfLoc
decl_stmt|;
comment|/// \brief True if this was contained in a skipping directive, e.g.,
comment|/// in a "\#if 0" block.
name|bool
name|WasSkipping
decl_stmt|;
comment|/// \brief True if we have emitted tokens already, and now we're in
comment|/// an \#else block or something.  Only useful in Skipping blocks.
name|bool
name|FoundNonSkip
decl_stmt|;
comment|/// \brief True if we've seen a \#else in this block.  If so,
comment|/// \#elif/\#else directives are not allowed.
name|bool
name|FoundElse
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_macro
unit|namespace
name|llvm
end_macro

begin_block
block|{
name|template
operator|<
operator|>
expr|struct
name|isPodLike
operator|<
name|clang
operator|::
name|Token
operator|>
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
name|true
block|; }
expr_stmt|;
block|}
end_block

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_LEX_TOKEN_H
end_comment

end_unit

