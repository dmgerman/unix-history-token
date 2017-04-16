begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- IdentifierTable.h - Hash table for identifier lookup ---*- C++ -*-===//
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
comment|/// \brief Defines the clang::IdentifierInfo, clang::IdentifierTable, and
end_comment

begin_comment
comment|/// clang::Selector interfaces.
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
name|LLVM_CLANG_BASIC_IDENTIFIERTABLE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_IDENTIFIERTABLE_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/TokenKinds.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallString.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<cstring>
end_include

begin_include
include|#
directive|include
file|<new>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|DenseMapInfo
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|LangOptions
decl_stmt|;
name|class
name|IdentifierInfo
decl_stmt|;
name|class
name|IdentifierTable
decl_stmt|;
name|class
name|SourceLocation
decl_stmt|;
name|class
name|MultiKeywordSelector
decl_stmt|;
comment|// private class used by Selector
name|class
name|DeclarationName
decl_stmt|;
comment|// AST class that stores declaration names
comment|/// \brief A simple pair of identifier info and location.
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|IdentifierInfo
operator|*
operator|,
name|SourceLocation
operator|>
name|IdentifierLocPair
expr_stmt|;
comment|/// One of these records is kept for each identifier that
comment|/// is lexed.  This contains information about whether the token was \#define'd,
comment|/// is a language keyword, or if it is a front-end token of some sort (e.g. a
comment|/// variable or function name).  The preprocessor keeps this information in a
comment|/// set, and all tok::identifier tokens have a pointer to one of these.
name|class
name|IdentifierInfo
block|{
name|friend
name|class
name|IdentifierTable
decl_stmt|;
name|unsigned
name|TokenID
range|:
literal|9
decl_stmt|;
comment|// Front-end token ID or tok::identifier.
comment|// Objective-C keyword ('protocol' in '@protocol') or builtin (__builtin_inf).
comment|// First NUM_OBJC_KEYWORDS values are for Objective-C, the remaining values
comment|// are for builtins.
name|unsigned
name|ObjCOrBuiltinID
range|:
literal|13
decl_stmt|;
name|bool
name|HasMacro
range|:
literal|1
decl_stmt|;
comment|// True if there is a #define for this.
name|bool
name|HadMacro
range|:
literal|1
decl_stmt|;
comment|// True if there was a #define for this.
name|bool
name|IsExtension
range|:
literal|1
decl_stmt|;
comment|// True if identifier is a lang extension.
name|bool
name|IsFutureCompatKeyword
range|:
literal|1
decl_stmt|;
comment|// True if identifier is a keyword in a
comment|// newer Standard or proposed Standard.
name|bool
name|IsPoisoned
range|:
literal|1
decl_stmt|;
comment|// True if identifier is poisoned.
name|bool
name|IsCPPOperatorKeyword
range|:
literal|1
decl_stmt|;
comment|// True if ident is a C++ operator keyword.
name|bool
name|NeedsHandleIdentifier
range|:
literal|1
decl_stmt|;
comment|// See "RecomputeNeedsHandleIdentifier".
name|bool
name|IsFromAST
range|:
literal|1
decl_stmt|;
comment|// True if identifier was loaded (at least
comment|// partially) from an AST file.
name|bool
name|ChangedAfterLoad
range|:
literal|1
decl_stmt|;
comment|// True if identifier has changed from the
comment|// definition loaded from an AST file.
name|bool
name|FEChangedAfterLoad
range|:
literal|1
decl_stmt|;
comment|// True if identifier's frontend information
comment|// has changed from the definition loaded
comment|// from an AST file.
name|bool
name|RevertedTokenID
range|:
literal|1
decl_stmt|;
comment|// True if revertTokenIDToIdentifier was
comment|// called.
name|bool
name|OutOfDate
range|:
literal|1
decl_stmt|;
comment|// True if there may be additional
comment|// information about this identifier
comment|// stored externally.
name|bool
name|IsModulesImport
range|:
literal|1
decl_stmt|;
comment|// True if this is the 'import' contextual
comment|// keyword.
comment|// 29 bit left in 64-bit word.
name|void
modifier|*
name|FETokenInfo
decl_stmt|;
comment|// Managed by the language front-end.
name|llvm
operator|::
name|StringMapEntry
operator|<
name|IdentifierInfo
operator|*
operator|>
operator|*
name|Entry
expr_stmt|;
name|public
label|:
name|IdentifierInfo
argument_list|()
expr_stmt|;
name|IdentifierInfo
argument_list|(
specifier|const
name|IdentifierInfo
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|IdentifierInfo
modifier|&
name|operator
init|=
operator|(
specifier|const
name|IdentifierInfo
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
comment|/// \brief Return true if this is the identifier for the specified string.
comment|///
comment|/// This is intended to be used for string literals only: II->isStr("foo").
name|template
operator|<
name|std
operator|::
name|size_t
name|StrLen
operator|>
name|bool
name|isStr
argument_list|(
argument|const char (&Str)[StrLen]
argument_list|)
specifier|const
block|{
return|return
name|getLength
argument_list|()
operator|==
name|StrLen
operator|-
literal|1
operator|&&
name|memcmp
argument_list|(
name|getNameStart
argument_list|()
argument_list|,
name|Str
argument_list|,
name|StrLen
operator|-
literal|1
argument_list|)
operator|==
literal|0
return|;
block|}
comment|/// \brief Return the beginning of the actual null-terminated string for this
comment|/// identifier.
comment|///
specifier|const
name|char
operator|*
name|getNameStart
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Entry
condition|)
return|return
name|Entry
operator|->
name|getKeyData
argument_list|()
return|;
comment|// FIXME: This is gross. It would be best not to embed specific details
comment|// of the PTH file format here.
comment|// The 'this' pointer really points to a
comment|// std::pair<IdentifierInfo, const char*>, where internal pointer
comment|// points to the external string data.
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|IdentifierInfo
operator|,
specifier|const
name|char
operator|*
operator|>
name|actualtype
expr_stmt|;
return|return
operator|(
operator|(
specifier|const
name|actualtype
operator|*
operator|)
name|this
operator|)
operator|->
name|second
return|;
block|}
comment|/// \brief Efficiently return the length of this identifier info.
comment|///
name|unsigned
name|getLength
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Entry
condition|)
return|return
name|Entry
operator|->
name|getKeyLength
argument_list|()
return|;
comment|// FIXME: This is gross. It would be best not to embed specific details
comment|// of the PTH file format here.
comment|// The 'this' pointer really points to a
comment|// std::pair<IdentifierInfo, const char*>, where internal pointer
comment|// points to the external string data.
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|IdentifierInfo
operator|,
specifier|const
name|char
operator|*
operator|>
name|actualtype
expr_stmt|;
specifier|const
name|char
modifier|*
name|p
init|=
operator|(
operator|(
specifier|const
name|actualtype
operator|*
operator|)
name|this
operator|)
operator|->
name|second
operator|-
literal|2
decl_stmt|;
return|return
operator|(
operator|(
operator|(
name|unsigned
operator|)
name|p
index|[
literal|0
index|]
operator|)
operator||
operator|(
operator|(
operator|(
name|unsigned
operator|)
name|p
index|[
literal|1
index|]
operator|)
operator|<<
literal|8
operator|)
operator|)
operator|-
literal|1
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Return the actual identifier string.
end_comment

begin_expr_stmt
name|StringRef
name|getName
argument_list|()
specifier|const
block|{
return|return
name|StringRef
argument_list|(
name|getNameStart
argument_list|()
argument_list|,
name|getLength
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Return true if this identifier is \#defined to some other value.
end_comment

begin_comment
comment|/// \note The current definition may be in a module and not currently visible.
end_comment

begin_expr_stmt
name|bool
name|hasMacroDefinition
argument_list|()
specifier|const
block|{
return|return
name|HasMacro
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setHasMacroDefinition
parameter_list|(
name|bool
name|Val
parameter_list|)
block|{
if|if
condition|(
name|HasMacro
operator|==
name|Val
condition|)
return|return;
name|HasMacro
operator|=
name|Val
expr_stmt|;
if|if
condition|(
name|Val
condition|)
block|{
name|NeedsHandleIdentifier
operator|=
name|true
expr_stmt|;
name|HadMacro
operator|=
name|true
expr_stmt|;
block|}
else|else
block|{
name|RecomputeNeedsHandleIdentifier
argument_list|()
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/// \brief Returns true if this identifier was \#defined to some value at any
end_comment

begin_comment
comment|/// moment. In this case there should be an entry for the identifier in the
end_comment

begin_comment
comment|/// macro history table in Preprocessor.
end_comment

begin_expr_stmt
name|bool
name|hadMacroDefinition
argument_list|()
specifier|const
block|{
return|return
name|HadMacro
return|;
block|}
end_expr_stmt

begin_comment
comment|/// If this is a source-language token (e.g. 'for'), this API
end_comment

begin_comment
comment|/// can be used to cause the lexer to map identifiers to source-language
end_comment

begin_comment
comment|/// tokens.
end_comment

begin_expr_stmt
name|tok
operator|::
name|TokenKind
name|getTokenID
argument_list|()
specifier|const
block|{
return|return
operator|(
name|tok
operator|::
name|TokenKind
operator|)
name|TokenID
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief True if revertTokenIDToIdentifier() was called.
end_comment

begin_expr_stmt
name|bool
name|hasRevertedTokenIDToIdentifier
argument_list|()
specifier|const
block|{
return|return
name|RevertedTokenID
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Revert TokenID to tok::identifier; used for GNU libstdc++ 4.2
end_comment

begin_comment
comment|/// compatibility.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// TokenID is normally read-only but there are 2 instances where we revert it
end_comment

begin_comment
comment|/// to tok::identifier for libstdc++ 4.2. Keep track of when this happens
end_comment

begin_comment
comment|/// using this method so we can inform serialization about it.
end_comment

begin_function
name|void
name|revertTokenIDToIdentifier
parameter_list|()
block|{
name|assert
argument_list|(
name|TokenID
operator|!=
name|tok
operator|::
name|identifier
operator|&&
literal|"Already at tok::identifier"
argument_list|)
expr_stmt|;
name|TokenID
operator|=
name|tok
operator|::
name|identifier
expr_stmt|;
name|RevertedTokenID
operator|=
name|true
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|void
name|revertIdentifierToTokenID
argument_list|(
name|tok
operator|::
name|TokenKind
name|TK
argument_list|)
block|{
name|assert
argument_list|(
name|TokenID
operator|==
name|tok
operator|::
name|identifier
operator|&&
literal|"Should be at tok::identifier"
argument_list|)
expr_stmt|;
name|TokenID
operator|=
name|TK
expr_stmt|;
name|RevertedTokenID
operator|=
name|false
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Return the preprocessor keyword ID for this identifier.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For example, "define" will return tok::pp_define.
end_comment

begin_expr_stmt
name|tok
operator|::
name|PPKeywordKind
name|getPPKeywordID
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Return the Objective-C keyword ID for the this identifier.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For example, 'class' will return tok::objc_class if ObjC is enabled.
end_comment

begin_expr_stmt
name|tok
operator|::
name|ObjCKeywordKind
name|getObjCKeywordID
argument_list|()
specifier|const
block|{
if|if
condition|(
name|ObjCOrBuiltinID
operator|<
name|tok
operator|::
name|NUM_OBJC_KEYWORDS
condition|)
return|return
name|tok
operator|::
name|ObjCKeywordKind
argument_list|(
name|ObjCOrBuiltinID
argument_list|)
return|;
else|else
return|return
name|tok
operator|::
name|objc_not_keyword
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|setObjCKeywordID
argument_list|(
name|tok
operator|::
name|ObjCKeywordKind
name|ID
argument_list|)
block|{
name|ObjCOrBuiltinID
operator|=
name|ID
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief True if setNotBuiltin() was called.
end_comment

begin_expr_stmt
name|bool
name|hasRevertedBuiltin
argument_list|()
specifier|const
block|{
return|return
name|ObjCOrBuiltinID
operator|==
name|tok
operator|::
name|NUM_OBJC_KEYWORDS
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Revert the identifier to a non-builtin identifier. We do this if
end_comment

begin_comment
comment|/// the name of a known builtin library function is used to declare that
end_comment

begin_comment
comment|/// function, but an unexpected type is specified.
end_comment

begin_function
name|void
name|revertBuiltin
parameter_list|()
block|{
name|setBuiltinID
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Return a value indicating whether this is a builtin function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// 0 is not-built-in. 1+ are specific builtin functions.
end_comment

begin_expr_stmt
name|unsigned
name|getBuiltinID
argument_list|()
specifier|const
block|{
if|if
condition|(
name|ObjCOrBuiltinID
operator|>=
name|tok
operator|::
name|NUM_OBJC_KEYWORDS
condition|)
return|return
name|ObjCOrBuiltinID
operator|-
name|tok
operator|::
name|NUM_OBJC_KEYWORDS
return|;
else|else
return|return
literal|0
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setBuiltinID
parameter_list|(
name|unsigned
name|ID
parameter_list|)
block|{
name|ObjCOrBuiltinID
operator|=
name|ID
operator|+
name|tok
operator|::
name|NUM_OBJC_KEYWORDS
expr_stmt|;
name|assert
argument_list|(
name|ObjCOrBuiltinID
operator|-
name|unsigned
argument_list|(
name|tok
operator|::
name|NUM_OBJC_KEYWORDS
argument_list|)
operator|==
name|ID
operator|&&
literal|"ID too large for field!"
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|unsigned
name|getObjCOrBuiltinID
argument_list|()
specifier|const
block|{
return|return
name|ObjCOrBuiltinID
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setObjCOrBuiltinID
parameter_list|(
name|unsigned
name|ID
parameter_list|)
block|{
name|ObjCOrBuiltinID
operator|=
name|ID
expr_stmt|;
block|}
end_function

begin_comment
comment|/// get/setExtension - Initialize information about whether or not this
end_comment

begin_comment
comment|/// language token is an extension.  This controls extension warnings, and is
end_comment

begin_comment
comment|/// only valid if a custom token ID is set.
end_comment

begin_expr_stmt
name|bool
name|isExtensionToken
argument_list|()
specifier|const
block|{
return|return
name|IsExtension
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setIsExtensionToken
parameter_list|(
name|bool
name|Val
parameter_list|)
block|{
name|IsExtension
operator|=
name|Val
expr_stmt|;
if|if
condition|(
name|Val
condition|)
name|NeedsHandleIdentifier
operator|=
name|true
expr_stmt|;
else|else
name|RecomputeNeedsHandleIdentifier
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/// is/setIsFutureCompatKeyword - Initialize information about whether or not
end_comment

begin_comment
comment|/// this language token is a keyword in a newer or proposed Standard. This
end_comment

begin_comment
comment|/// controls compatibility warnings, and is only true when not parsing the
end_comment

begin_comment
comment|/// corresponding Standard. Once a compatibility problem has been diagnosed
end_comment

begin_comment
comment|/// with this keyword, the flag will be cleared.
end_comment

begin_expr_stmt
name|bool
name|isFutureCompatKeyword
argument_list|()
specifier|const
block|{
return|return
name|IsFutureCompatKeyword
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setIsFutureCompatKeyword
parameter_list|(
name|bool
name|Val
parameter_list|)
block|{
name|IsFutureCompatKeyword
operator|=
name|Val
expr_stmt|;
if|if
condition|(
name|Val
condition|)
name|NeedsHandleIdentifier
operator|=
name|true
expr_stmt|;
else|else
name|RecomputeNeedsHandleIdentifier
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/// setIsPoisoned - Mark this identifier as poisoned.  After poisoning, the
end_comment

begin_comment
comment|/// Preprocessor will emit an error every time this token is used.
end_comment

begin_function
name|void
name|setIsPoisoned
parameter_list|(
name|bool
name|Value
init|=
name|true
parameter_list|)
block|{
name|IsPoisoned
operator|=
name|Value
expr_stmt|;
if|if
condition|(
name|Value
condition|)
name|NeedsHandleIdentifier
operator|=
name|true
expr_stmt|;
else|else
name|RecomputeNeedsHandleIdentifier
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Return true if this token has been poisoned.
end_comment

begin_expr_stmt
name|bool
name|isPoisoned
argument_list|()
specifier|const
block|{
return|return
name|IsPoisoned
return|;
block|}
end_expr_stmt

begin_comment
comment|/// isCPlusPlusOperatorKeyword/setIsCPlusPlusOperatorKeyword controls whether
end_comment

begin_comment
comment|/// this identifier is a C++ alternate representation of an operator.
end_comment

begin_function
name|void
name|setIsCPlusPlusOperatorKeyword
parameter_list|(
name|bool
name|Val
init|=
name|true
parameter_list|)
block|{
name|IsCPPOperatorKeyword
operator|=
name|Val
expr_stmt|;
if|if
condition|(
name|Val
condition|)
name|NeedsHandleIdentifier
operator|=
name|true
expr_stmt|;
else|else
name|RecomputeNeedsHandleIdentifier
argument_list|()
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|bool
name|isCPlusPlusOperatorKeyword
argument_list|()
specifier|const
block|{
return|return
name|IsCPPOperatorKeyword
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Return true if this token is a keyword in the specified language.
end_comment

begin_decl_stmt
name|bool
name|isKeyword
argument_list|(
specifier|const
name|LangOptions
operator|&
name|LangOpts
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Return true if this token is a C++ keyword in the specified
end_comment

begin_comment
comment|/// language.
end_comment

begin_decl_stmt
name|bool
name|isCPlusPlusKeyword
argument_list|(
specifier|const
name|LangOptions
operator|&
name|LangOpts
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getFETokenInfo/setFETokenInfo - The language front-end is allowed to
end_comment

begin_comment
comment|/// associate arbitrary metadata with this token.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|T
operator|*
name|getFETokenInfo
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|FETokenInfo
operator|)
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setFETokenInfo
parameter_list|(
name|void
modifier|*
name|T
parameter_list|)
block|{
name|FETokenInfo
operator|=
name|T
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Return true if the Preprocessor::HandleIdentifier must be called
end_comment

begin_comment
comment|/// on a token of this identifier.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If this returns false, we know that HandleIdentifier will not affect
end_comment

begin_comment
comment|/// the token.
end_comment

begin_expr_stmt
name|bool
name|isHandleIdentifierCase
argument_list|()
specifier|const
block|{
return|return
name|NeedsHandleIdentifier
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Return true if the identifier in its current state was loaded
end_comment

begin_comment
comment|/// from an AST file.
end_comment

begin_expr_stmt
name|bool
name|isFromAST
argument_list|()
specifier|const
block|{
return|return
name|IsFromAST
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setIsFromAST
parameter_list|()
block|{
name|IsFromAST
operator|=
name|true
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Determine whether this identifier has changed since it was loaded
end_comment

begin_comment
comment|/// from an AST file.
end_comment

begin_expr_stmt
name|bool
name|hasChangedSinceDeserialization
argument_list|()
specifier|const
block|{
return|return
name|ChangedAfterLoad
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Note that this identifier has changed since it was loaded from
end_comment

begin_comment
comment|/// an AST file.
end_comment

begin_function
name|void
name|setChangedSinceDeserialization
parameter_list|()
block|{
name|ChangedAfterLoad
operator|=
name|true
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Determine whether the frontend token information for this
end_comment

begin_comment
comment|/// identifier has changed since it was loaded from an AST file.
end_comment

begin_expr_stmt
name|bool
name|hasFETokenInfoChangedSinceDeserialization
argument_list|()
specifier|const
block|{
return|return
name|FEChangedAfterLoad
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Note that the frontend token information for this identifier has
end_comment

begin_comment
comment|/// changed since it was loaded from an AST file.
end_comment

begin_function
name|void
name|setFETokenInfoChangedSinceDeserialization
parameter_list|()
block|{
name|FEChangedAfterLoad
operator|=
name|true
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Determine whether the information for this identifier is out of
end_comment

begin_comment
comment|/// date with respect to the external source.
end_comment

begin_expr_stmt
name|bool
name|isOutOfDate
argument_list|()
specifier|const
block|{
return|return
name|OutOfDate
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Set whether the information for this identifier is out of
end_comment

begin_comment
comment|/// date with respect to the external source.
end_comment

begin_function
name|void
name|setOutOfDate
parameter_list|(
name|bool
name|OOD
parameter_list|)
block|{
name|OutOfDate
operator|=
name|OOD
expr_stmt|;
if|if
condition|(
name|OOD
condition|)
name|NeedsHandleIdentifier
operator|=
name|true
expr_stmt|;
else|else
name|RecomputeNeedsHandleIdentifier
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Determine whether this is the contextual keyword \c import.
end_comment

begin_expr_stmt
name|bool
name|isModulesImport
argument_list|()
specifier|const
block|{
return|return
name|IsModulesImport
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Set whether this identifier is the contextual keyword \c import.
end_comment

begin_function
name|void
name|setModulesImport
parameter_list|(
name|bool
name|I
parameter_list|)
block|{
name|IsModulesImport
operator|=
name|I
expr_stmt|;
if|if
condition|(
name|I
condition|)
name|NeedsHandleIdentifier
operator|=
name|true
expr_stmt|;
else|else
name|RecomputeNeedsHandleIdentifier
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Provide less than operator for lexicographical sorting.
end_comment

begin_expr_stmt
name|bool
name|operator
operator|<
operator|(
specifier|const
name|IdentifierInfo
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|getName
argument_list|()
operator|<
name|RHS
operator|.
name|getName
argument_list|()
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|/// The Preprocessor::HandleIdentifier does several special (but rare)
end_comment

begin_comment
comment|/// things to identifiers of various sorts.  For example, it changes the
end_comment

begin_comment
comment|/// \c for keyword token from tok::identifier to tok::for.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This method is very tied to the definition of HandleIdentifier.  Any
end_comment

begin_comment
comment|/// change to it should be reflected here.
end_comment

begin_function
name|void
name|RecomputeNeedsHandleIdentifier
parameter_list|()
block|{
name|NeedsHandleIdentifier
operator|=
operator|(
name|isPoisoned
argument_list|()
operator||
name|hasMacroDefinition
argument_list|()
operator||
name|isCPlusPlusOperatorKeyword
argument_list|()
operator||
name|isExtensionToken
argument_list|()
operator||
name|isFutureCompatKeyword
argument_list|()
operator|||
name|isOutOfDate
argument_list|()
operator|||
name|isModulesImport
argument_list|()
operator|)
expr_stmt|;
block|}
end_function

begin_comment
unit|};
comment|/// \brief An RAII object for [un]poisoning an identifier within a scope.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \p II is allowed to be null, in which case objects of this type have
end_comment

begin_comment
comment|/// no effect.
end_comment

begin_decl_stmt
name|class
name|PoisonIdentifierRAIIObject
block|{
name|IdentifierInfo
modifier|*
specifier|const
name|II
decl_stmt|;
specifier|const
name|bool
name|OldValue
decl_stmt|;
name|public
label|:
name|PoisonIdentifierRAIIObject
argument_list|(
argument|IdentifierInfo *II
argument_list|,
argument|bool NewValue
argument_list|)
block|:
name|II
argument_list|(
name|II
argument_list|)
operator|,
name|OldValue
argument_list|(
argument|II ? II->isPoisoned() : false
argument_list|)
block|{
if|if
condition|(
name|II
condition|)
name|II
operator|->
name|setIsPoisoned
argument_list|(
name|NewValue
argument_list|)
expr_stmt|;
block|}
operator|~
name|PoisonIdentifierRAIIObject
argument_list|()
block|{
if|if
condition|(
name|II
condition|)
name|II
operator|->
name|setIsPoisoned
argument_list|(
name|OldValue
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief An iterator that walks over all of the known identifiers
end_comment

begin_comment
comment|/// in the lookup table.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Since this iterator uses an abstract interface via virtual
end_comment

begin_comment
comment|/// functions, it uses an object-oriented interface rather than the
end_comment

begin_comment
comment|/// more standard C++ STL iterator interface. In this OO-style
end_comment

begin_comment
comment|/// iteration, the single function \c Next() provides dereference,
end_comment

begin_comment
comment|/// advance, and end-of-sequence checking in a single
end_comment

begin_comment
comment|/// operation. Subclasses of this iterator type will provide the
end_comment

begin_comment
comment|/// actual functionality.
end_comment

begin_decl_stmt
name|class
name|IdentifierIterator
block|{
name|protected
label|:
name|IdentifierIterator
argument_list|()
operator|=
expr|default
expr_stmt|;
name|public
label|:
name|IdentifierIterator
argument_list|(
specifier|const
name|IdentifierIterator
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|IdentifierIterator
modifier|&
name|operator
init|=
operator|(
specifier|const
name|IdentifierIterator
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|virtual
operator|~
name|IdentifierIterator
argument_list|()
expr_stmt|;
comment|/// \brief Retrieve the next string in the identifier table and
comment|/// advances the iterator for the following string.
comment|///
comment|/// \returns The next string in the identifier table. If there is
comment|/// no such string, returns an empty \c StringRef.
name|virtual
name|StringRef
name|Next
parameter_list|()
init|=
literal|0
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Provides lookups to, and iteration over, IdentiferInfo objects.
end_comment

begin_decl_stmt
name|class
name|IdentifierInfoLookup
block|{
name|public
label|:
name|virtual
operator|~
name|IdentifierInfoLookup
argument_list|()
expr_stmt|;
comment|/// \brief Return the IdentifierInfo for the specified named identifier.
comment|///
comment|/// Unlike the version in IdentifierTable, this returns a pointer instead
comment|/// of a reference.  If the pointer is null then the IdentifierInfo cannot
comment|/// be found.
name|virtual
name|IdentifierInfo
modifier|*
name|get
parameter_list|(
name|StringRef
name|Name
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// \brief Retrieve an iterator into the set of all identifiers
comment|/// known to this identifier lookup source.
comment|///
comment|/// This routine provides access to all of the identifiers known to
comment|/// the identifier lookup, allowing access to the contents of the
comment|/// identifiers without introducing the overhead of constructing
comment|/// IdentifierInfo objects for each.
comment|///
comment|/// \returns A new iterator into the set of known identifiers. The
comment|/// caller is responsible for deleting this iterator.
name|virtual
name|IdentifierIterator
modifier|*
name|getIdentifiers
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Implements an efficient mapping from strings to IdentifierInfo nodes.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This has no other purpose, but this is an extremely performance-critical
end_comment

begin_comment
comment|/// piece of the code, as each occurrence of every identifier goes through
end_comment

begin_comment
comment|/// here when lexed.
end_comment

begin_decl_stmt
name|class
name|IdentifierTable
block|{
comment|// Shark shows that using MallocAllocator is *much* slower than using this
comment|// BumpPtrAllocator!
typedef|typedef
name|llvm
operator|::
name|StringMap
operator|<
name|IdentifierInfo
operator|*
operator|,
name|llvm
operator|::
name|BumpPtrAllocator
operator|>
name|HashTableTy
expr_stmt|;
name|HashTableTy
name|HashTable
decl_stmt|;
name|IdentifierInfoLookup
modifier|*
name|ExternalLookup
decl_stmt|;
name|public
label|:
comment|/// \brief Create the identifier table, populating it with info about the
comment|/// language keywords for the language specified by \p LangOpts.
name|IdentifierTable
argument_list|(
specifier|const
name|LangOptions
operator|&
name|LangOpts
argument_list|,
name|IdentifierInfoLookup
operator|*
name|externalLookup
operator|=
name|nullptr
argument_list|)
expr_stmt|;
comment|/// \brief Set the external identifier lookup mechanism.
name|void
name|setExternalIdentifierLookup
parameter_list|(
name|IdentifierInfoLookup
modifier|*
name|IILookup
parameter_list|)
block|{
name|ExternalLookup
operator|=
name|IILookup
expr_stmt|;
block|}
comment|/// \brief Retrieve the external identifier lookup object, if any.
name|IdentifierInfoLookup
operator|*
name|getExternalIdentifierLookup
argument_list|()
specifier|const
block|{
return|return
name|ExternalLookup
return|;
block|}
name|llvm
operator|::
name|BumpPtrAllocator
operator|&
name|getAllocator
argument_list|()
block|{
return|return
name|HashTable
operator|.
name|getAllocator
argument_list|()
return|;
block|}
comment|/// \brief Return the identifier token info for the specified named
comment|/// identifier.
name|IdentifierInfo
modifier|&
name|get
parameter_list|(
name|StringRef
name|Name
parameter_list|)
block|{
name|auto
operator|&
name|Entry
operator|=
operator|*
name|HashTable
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|Name
argument_list|,
name|nullptr
argument_list|)
argument_list|)
operator|.
name|first
expr_stmt|;
name|IdentifierInfo
modifier|*
modifier|&
name|II
init|=
name|Entry
operator|.
name|second
decl_stmt|;
if|if
condition|(
name|II
condition|)
return|return
operator|*
name|II
return|;
comment|// No entry; if we have an external lookup, look there first.
if|if
condition|(
name|ExternalLookup
condition|)
block|{
name|II
operator|=
name|ExternalLookup
operator|->
name|get
argument_list|(
name|Name
argument_list|)
expr_stmt|;
if|if
condition|(
name|II
condition|)
return|return
operator|*
name|II
return|;
block|}
comment|// Lookups failed, make a new IdentifierInfo.
name|void
modifier|*
name|Mem
init|=
name|getAllocator
argument_list|()
operator|.
name|Allocate
operator|<
name|IdentifierInfo
operator|>
operator|(
operator|)
decl_stmt|;
name|II
operator|=
name|new
argument_list|(
argument|Mem
argument_list|)
name|IdentifierInfo
argument_list|()
expr_stmt|;
comment|// Make sure getName() knows how to find the IdentifierInfo
comment|// contents.
name|II
operator|->
name|Entry
operator|=
operator|&
name|Entry
expr_stmt|;
return|return
operator|*
name|II
return|;
block|}
name|IdentifierInfo
modifier|&
name|get
argument_list|(
name|StringRef
name|Name
argument_list|,
name|tok
operator|::
name|TokenKind
name|TokenCode
argument_list|)
block|{
name|IdentifierInfo
modifier|&
name|II
init|=
name|get
argument_list|(
name|Name
argument_list|)
decl_stmt|;
name|II
operator|.
name|TokenID
operator|=
name|TokenCode
expr_stmt|;
name|assert
argument_list|(
name|II
operator|.
name|TokenID
operator|==
operator|(
name|unsigned
operator|)
name|TokenCode
operator|&&
literal|"TokenCode too large"
argument_list|)
expr_stmt|;
return|return
name|II
return|;
block|}
comment|/// \brief Gets an IdentifierInfo for the given name without consulting
comment|///        external sources.
comment|///
comment|/// This is a version of get() meant for external sources that want to
comment|/// introduce or modify an identifier. If they called get(), they would
comment|/// likely end up in a recursion.
name|IdentifierInfo
modifier|&
name|getOwn
parameter_list|(
name|StringRef
name|Name
parameter_list|)
block|{
name|auto
operator|&
name|Entry
operator|=
operator|*
name|HashTable
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|Name
argument_list|,
name|nullptr
argument_list|)
argument_list|)
operator|.
name|first
expr_stmt|;
name|IdentifierInfo
modifier|*
modifier|&
name|II
init|=
name|Entry
operator|.
name|second
decl_stmt|;
if|if
condition|(
name|II
condition|)
return|return
operator|*
name|II
return|;
comment|// Lookups failed, make a new IdentifierInfo.
name|void
modifier|*
name|Mem
init|=
name|getAllocator
argument_list|()
operator|.
name|Allocate
operator|<
name|IdentifierInfo
operator|>
operator|(
operator|)
decl_stmt|;
name|II
operator|=
name|new
argument_list|(
argument|Mem
argument_list|)
name|IdentifierInfo
argument_list|()
expr_stmt|;
comment|// Make sure getName() knows how to find the IdentifierInfo
comment|// contents.
name|II
operator|->
name|Entry
operator|=
operator|&
name|Entry
expr_stmt|;
comment|// If this is the 'import' contextual keyword, mark it as such.
if|if
condition|(
name|Name
operator|.
name|equals
argument_list|(
literal|"import"
argument_list|)
condition|)
name|II
operator|->
name|setModulesImport
argument_list|(
name|true
argument_list|)
expr_stmt|;
return|return
operator|*
name|II
return|;
block|}
typedef|typedef
name|HashTableTy
operator|::
name|const_iterator
name|iterator
expr_stmt|;
typedef|typedef
name|HashTableTy
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|HashTable
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|HashTable
operator|.
name|end
argument_list|()
return|;
block|}
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
name|HashTable
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// \brief Print some statistics to stderr that indicate how well the
comment|/// hashing is doing.
name|void
name|PrintStats
argument_list|()
specifier|const
expr_stmt|;
name|void
name|AddKeywords
parameter_list|(
specifier|const
name|LangOptions
modifier|&
name|LangOpts
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief A family of Objective-C methods.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// These families have no inherent meaning in the language, but are
end_comment

begin_comment
comment|/// nonetheless central enough in the existing implementations to
end_comment

begin_comment
comment|/// merit direct AST support.  While, in theory, arbitrary methods can
end_comment

begin_comment
comment|/// be considered to form families, we focus here on the methods
end_comment

begin_comment
comment|/// involving allocation and retain-count management, as these are the
end_comment

begin_comment
comment|/// most "core" and the most likely to be useful to diverse clients
end_comment

begin_comment
comment|/// without extra information.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Both selectors and actual method declarations may be classified
end_comment

begin_comment
comment|/// into families.  Method families may impose additional restrictions
end_comment

begin_comment
comment|/// beyond their selector name; for example, a method called '_init'
end_comment

begin_comment
comment|/// that returns void is not considered to be in the 'init' family
end_comment

begin_comment
comment|/// (but would be if it returned 'id').  It is also possible to
end_comment

begin_comment
comment|/// explicitly change or remove a method's family.  Therefore the
end_comment

begin_comment
comment|/// method's family should be considered the single source of truth.
end_comment

begin_enum
enum|enum
name|ObjCMethodFamily
block|{
comment|/// \brief No particular method family.
name|OMF_None
block|,
comment|// Selectors in these families may have arbitrary arity, may be
comment|// written with arbitrary leading underscores, and may have
comment|// additional CamelCase "words" in their first selector chunk
comment|// following the family name.
name|OMF_alloc
block|,
name|OMF_copy
block|,
name|OMF_init
block|,
name|OMF_mutableCopy
block|,
name|OMF_new
block|,
comment|// These families are singletons consisting only of the nullary
comment|// selector with the given name.
name|OMF_autorelease
block|,
name|OMF_dealloc
block|,
name|OMF_finalize
block|,
name|OMF_release
block|,
name|OMF_retain
block|,
name|OMF_retainCount
block|,
name|OMF_self
block|,
name|OMF_initialize
block|,
comment|// performSelector families
name|OMF_performSelector
block|}
enum|;
end_enum

begin_comment
comment|/// Enough bits to store any enumerator in ObjCMethodFamily or
end_comment

begin_comment
comment|/// InvalidObjCMethodFamily.
end_comment

begin_enum
enum|enum
block|{
name|ObjCMethodFamilyBitWidth
init|=
literal|4
block|}
enum|;
end_enum

begin_comment
comment|/// \brief An invalid value of ObjCMethodFamily.
end_comment

begin_enum
enum|enum
block|{
name|InvalidObjCMethodFamily
init|=
operator|(
literal|1
operator|<<
name|ObjCMethodFamilyBitWidth
operator|)
operator|-
literal|1
block|}
enum|;
end_enum

begin_comment
comment|/// \brief A family of Objective-C methods.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// These are family of methods whose result type is initially 'id', but
end_comment

begin_comment
comment|/// but are candidate for the result type to be changed to 'instancetype'.
end_comment

begin_enum
enum|enum
name|ObjCInstanceTypeFamily
block|{
name|OIT_None
block|,
name|OIT_Array
block|,
name|OIT_Dictionary
block|,
name|OIT_Singleton
block|,
name|OIT_Init
block|,
name|OIT_ReturnsSelf
block|}
enum|;
end_enum

begin_enum
enum|enum
name|ObjCStringFormatFamily
block|{
name|SFF_None
block|,
name|SFF_NSString
block|,
name|SFF_CFString
block|}
enum|;
end_enum

begin_comment
comment|/// \brief Smart pointer class that efficiently represents Objective-C method
end_comment

begin_comment
comment|/// names.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This class will either point to an IdentifierInfo or a
end_comment

begin_comment
comment|/// MultiKeywordSelector (which is private). This enables us to optimize
end_comment

begin_comment
comment|/// selectors that take no arguments and selectors that take 1 argument, which
end_comment

begin_comment
comment|/// accounts for 78% of all selectors in Cocoa.h.
end_comment

begin_decl_stmt
name|class
name|Selector
block|{
name|friend
name|class
name|Diagnostic
decl_stmt|;
enum|enum
name|IdentifierInfoFlag
block|{
comment|// Empty selector = 0.
name|ZeroArg
init|=
literal|0x1
block|,
name|OneArg
init|=
literal|0x2
block|,
name|MultiArg
init|=
literal|0x3
block|,
name|ArgFlags
init|=
name|ZeroArg
operator||
name|OneArg
block|}
enum|;
name|uintptr_t
name|InfoPtr
decl_stmt|;
comment|// a pointer to the MultiKeywordSelector or IdentifierInfo.
name|Selector
argument_list|(
argument|IdentifierInfo *II
argument_list|,
argument|unsigned nArgs
argument_list|)
block|{
name|InfoPtr
operator|=
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|II
operator|)
expr_stmt|;
name|assert
argument_list|(
operator|(
name|InfoPtr
operator|&
name|ArgFlags
operator|)
operator|==
literal|0
operator|&&
literal|"Insufficiently aligned IdentifierInfo"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|nArgs
operator|<
literal|2
operator|&&
literal|"nArgs not equal to 0/1"
argument_list|)
expr_stmt|;
name|InfoPtr
operator||=
name|nArgs
operator|+
literal|1
expr_stmt|;
block|}
name|Selector
argument_list|(
argument|MultiKeywordSelector *SI
argument_list|)
block|{
name|InfoPtr
operator|=
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|SI
operator|)
expr_stmt|;
name|assert
argument_list|(
operator|(
name|InfoPtr
operator|&
name|ArgFlags
operator|)
operator|==
literal|0
operator|&&
literal|"Insufficiently aligned IdentifierInfo"
argument_list|)
expr_stmt|;
name|InfoPtr
operator||=
name|MultiArg
expr_stmt|;
block|}
name|IdentifierInfo
operator|*
name|getAsIdentifierInfo
argument_list|()
specifier|const
block|{
if|if
condition|(
name|getIdentifierInfoFlag
argument_list|()
operator|<
name|MultiArg
condition|)
return|return
name|reinterpret_cast
operator|<
name|IdentifierInfo
operator|*
operator|>
operator|(
name|InfoPtr
operator|&
operator|~
name|ArgFlags
operator|)
return|;
return|return
name|nullptr
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|MultiKeywordSelector
operator|*
name|getMultiKeywordSelector
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
name|MultiKeywordSelector
operator|*
operator|>
operator|(
name|InfoPtr
operator|&
operator|~
name|ArgFlags
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|unsigned
name|getIdentifierInfoFlag
argument_list|()
specifier|const
block|{
return|return
name|InfoPtr
operator|&
name|ArgFlags
return|;
block|}
end_expr_stmt

begin_function_decl
specifier|static
name|ObjCMethodFamily
name|getMethodFamilyImpl
parameter_list|(
name|Selector
name|sel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|ObjCStringFormatFamily
name|getStringFormatFamilyImpl
parameter_list|(
name|Selector
name|sel
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|public
label|:
end_label

begin_decl_stmt
name|friend
name|class
name|SelectorTable
decl_stmt|;
end_decl_stmt

begin_comment
comment|// only the SelectorTable can create these
end_comment

begin_decl_stmt
name|friend
name|class
name|DeclarationName
decl_stmt|;
end_decl_stmt

begin_comment
comment|// and the AST's DeclarationName.
end_comment

begin_comment
comment|/// The default ctor should only be used when creating data structures that
end_comment

begin_comment
comment|///  will contain selectors.
end_comment

begin_expr_stmt
name|Selector
argument_list|()
operator|:
name|InfoPtr
argument_list|(
literal|0
argument_list|)
block|{}
name|Selector
argument_list|(
argument|uintptr_t V
argument_list|)
operator|:
name|InfoPtr
argument_list|(
argument|V
argument_list|)
block|{}
comment|/// operator==/!= - Indicate whether the specified selectors are identical.
name|bool
name|operator
operator|==
operator|(
name|Selector
name|RHS
operator|)
specifier|const
block|{
return|return
name|InfoPtr
operator|==
name|RHS
operator|.
name|InfoPtr
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
name|Selector
name|RHS
operator|)
specifier|const
block|{
return|return
name|InfoPtr
operator|!=
name|RHS
operator|.
name|InfoPtr
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|void
operator|*
name|getAsOpaquePtr
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
name|void
operator|*
operator|>
operator|(
name|InfoPtr
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this is the empty selector.
end_comment

begin_expr_stmt
name|bool
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|InfoPtr
operator|==
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|// Predicates to identify the selector type.
end_comment

begin_expr_stmt
name|bool
name|isKeywordSelector
argument_list|()
specifier|const
block|{
return|return
name|getIdentifierInfoFlag
argument_list|()
operator|!=
name|ZeroArg
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|isUnarySelector
argument_list|()
specifier|const
block|{
return|return
name|getIdentifierInfoFlag
argument_list|()
operator|==
name|ZeroArg
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|unsigned
name|getNumArgs
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the identifier at a given position in the selector.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that the identifier pointer returned may be NULL. Clients that only
end_comment

begin_comment
comment|/// care about the text of the identifier string, and not the specific,
end_comment

begin_comment
comment|/// uniqued identifier pointer, should use \c getNameForSlot(), which returns
end_comment

begin_comment
comment|/// an empty string when the identifier pointer would be NULL.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param argIndex The index for which we want to retrieve the identifier.
end_comment

begin_comment
comment|/// This index shall be less than \c getNumArgs() unless this is a keyword
end_comment

begin_comment
comment|/// selector, in which case 0 is the only permissible value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns the uniqued identifier for this slot, or NULL if this slot has
end_comment

begin_comment
comment|/// no corresponding identifier.
end_comment

begin_decl_stmt
name|IdentifierInfo
modifier|*
name|getIdentifierInfoForSlot
argument_list|(
name|unsigned
name|argIndex
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Retrieve the name at a given position in the selector.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param argIndex The index for which we want to retrieve the name.
end_comment

begin_comment
comment|/// This index shall be less than \c getNumArgs() unless this is a keyword
end_comment

begin_comment
comment|/// selector, in which case 0 is the only permissible value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns the name for this slot, which may be the empty string if no
end_comment

begin_comment
comment|/// name was supplied.
end_comment

begin_decl_stmt
name|StringRef
name|getNameForSlot
argument_list|(
name|unsigned
name|argIndex
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Derive the full selector name (e.g. "foo:bar:") and return
end_comment

begin_comment
comment|/// it as an std::string.
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|getAsString
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Prints the full selector name (e.g. "foo:bar:").
end_comment

begin_decl_stmt
name|void
name|print
argument_list|(
name|llvm
operator|::
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Derive the conventional family of this method.
end_comment

begin_expr_stmt
name|ObjCMethodFamily
name|getMethodFamily
argument_list|()
specifier|const
block|{
return|return
name|getMethodFamilyImpl
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|ObjCStringFormatFamily
name|getStringFormatFamily
argument_list|()
specifier|const
block|{
return|return
name|getStringFormatFamilyImpl
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|Selector
name|getEmptyMarker
parameter_list|()
block|{
return|return
name|Selector
argument_list|(
name|uintptr_t
argument_list|(
operator|-
literal|1
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|Selector
name|getTombstoneMarker
parameter_list|()
block|{
return|return
name|Selector
argument_list|(
name|uintptr_t
argument_list|(
operator|-
literal|2
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function_decl
specifier|static
name|ObjCInstanceTypeFamily
name|getInstTypeMethodFamily
parameter_list|(
name|Selector
name|sel
parameter_list|)
function_decl|;
end_function_decl

begin_comment
unit|};
comment|/// \brief This table allows us to fully hide how we implement
end_comment

begin_comment
comment|/// multi-keyword caching.
end_comment

begin_decl_stmt
name|class
name|SelectorTable
block|{
name|void
modifier|*
name|Impl
decl_stmt|;
comment|// Actually a SelectorTableImpl
name|public
label|:
name|SelectorTable
argument_list|()
expr_stmt|;
name|SelectorTable
argument_list|(
specifier|const
name|SelectorTable
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|SelectorTable
modifier|&
name|operator
init|=
operator|(
specifier|const
name|SelectorTable
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
operator|~
name|SelectorTable
argument_list|()
expr_stmt|;
comment|/// \brief Can create any sort of selector.
comment|///
comment|/// \p NumArgs indicates whether this is a no argument selector "foo", a
comment|/// single argument selector "foo:" or multi-argument "foo:bar:".
name|Selector
name|getSelector
parameter_list|(
name|unsigned
name|NumArgs
parameter_list|,
name|IdentifierInfo
modifier|*
modifier|*
name|IIV
parameter_list|)
function_decl|;
name|Selector
name|getUnarySelector
parameter_list|(
name|IdentifierInfo
modifier|*
name|ID
parameter_list|)
block|{
return|return
name|Selector
argument_list|(
name|ID
argument_list|,
literal|1
argument_list|)
return|;
block|}
name|Selector
name|getNullarySelector
parameter_list|(
name|IdentifierInfo
modifier|*
name|ID
parameter_list|)
block|{
return|return
name|Selector
argument_list|(
name|ID
argument_list|,
literal|0
argument_list|)
return|;
block|}
comment|/// \brief Return the total amount of memory allocated for managing selectors.
name|size_t
name|getTotalMemory
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Return the default setter name for the given identifier.
comment|///
comment|/// This is "set" + \p Name where the initial character of \p Name
comment|/// has been capitalized.
specifier|static
name|SmallString
operator|<
literal|64
operator|>
name|constructSetterName
argument_list|(
argument|StringRef Name
argument_list|)
expr_stmt|;
comment|/// \brief Return the default setter selector for the given identifier.
comment|///
comment|/// This is "set" + \p Name where the initial character of \p Name
comment|/// has been capitalized.
specifier|static
name|Selector
name|constructSetterSelector
parameter_list|(
name|IdentifierTable
modifier|&
name|Idents
parameter_list|,
name|SelectorTable
modifier|&
name|SelTable
parameter_list|,
specifier|const
name|IdentifierInfo
modifier|*
name|Name
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// DeclarationNameExtra - Common base of the MultiKeywordSelector,
end_comment

begin_comment
comment|/// CXXSpecialName, and CXXOperatorIdName classes, all of which are
end_comment

begin_comment
comment|/// private classes that describe different kinds of names.
end_comment

begin_decl_stmt
name|class
name|DeclarationNameExtra
block|{
name|public
label|:
comment|/// ExtraKind - The kind of "extra" information stored in the
comment|/// DeclarationName. See @c ExtraKindOrNumArgs for an explanation of
comment|/// how these enumerator values are used.
enum|enum
name|ExtraKind
block|{
name|CXXConstructor
init|=
literal|0
block|,
name|CXXDestructor
block|,
name|CXXConversionFunction
block|,
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
value|CXXOperator##Name,
include|#
directive|include
file|"clang/Basic/OperatorKinds.def"
name|CXXDeductionGuide
block|,
name|CXXLiteralOperator
block|,
name|CXXUsingDirective
block|,
name|NUM_EXTRA_KINDS
block|}
enum|;
comment|/// ExtraKindOrNumArgs - Either the kind of C++ special name or
comment|/// operator-id (if the value is one of the CXX* enumerators of
comment|/// ExtraKind), in which case the DeclarationNameExtra is also a
comment|/// CXXSpecialName, (for CXXConstructor, CXXDestructor, or
comment|/// CXXConversionFunction) CXXOperatorIdName, or CXXLiteralOperatorName,
comment|/// it may be also name common to C++ using-directives (CXXUsingDirective),
comment|/// otherwise it is NUM_EXTRA_KINDS+NumArgs, where NumArgs is the number of
comment|/// arguments in the Objective-C selector, in which case the
comment|/// DeclarationNameExtra is also a MultiKeywordSelector.
name|unsigned
name|ExtraKindOrNumArgs
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

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
comment|/// Define DenseMapInfo so that Selectors can be used as keys in DenseMap and
comment|/// DenseSets.
name|template
operator|<
operator|>
expr|struct
name|DenseMapInfo
operator|<
name|clang
operator|::
name|Selector
operator|>
block|{
specifier|static
specifier|inline
name|clang
operator|::
name|Selector
name|getEmptyKey
argument_list|()
block|{
return|return
name|clang
operator|::
name|Selector
operator|::
name|getEmptyMarker
argument_list|()
return|;
block|}
specifier|static
specifier|inline
name|clang
operator|::
name|Selector
name|getTombstoneKey
argument_list|()
block|{
return|return
name|clang
operator|::
name|Selector
operator|::
name|getTombstoneMarker
argument_list|()
return|;
block|}
specifier|static
name|unsigned
name|getHashValue
argument_list|(
name|clang
operator|::
name|Selector
name|S
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|isEqual
argument_list|(
name|clang
operator|::
name|Selector
name|LHS
argument_list|,
name|clang
operator|::
name|Selector
name|RHS
argument_list|)
block|{
return|return
name|LHS
operator|==
name|RHS
return|;
block|}
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|isPodLike
operator|<
name|clang
operator|::
name|Selector
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
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|PointerLikeTypeTraits
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|PointerLikeTypeTraits
operator|<
name|clang
operator|::
name|Selector
operator|>
block|{
name|public
operator|:
specifier|static
specifier|inline
specifier|const
name|void
operator|*
name|getAsVoidPointer
argument_list|(
argument|clang::Selector P
argument_list|)
block|{
return|return
name|P
operator|.
name|getAsOpaquePtr
argument_list|()
return|;
block|}
specifier|static
specifier|inline
name|clang
operator|::
name|Selector
name|getFromVoidPointer
argument_list|(
argument|const void *P
argument_list|)
block|{
return|return
name|clang
operator|::
name|Selector
argument_list|(
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|P
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_enum
enum|enum
block|{
name|NumLowBitsAvailable
init|=
literal|0
block|}
enum|;
end_enum

begin_comment
unit|};
comment|// Provide PointerLikeTypeTraits for IdentifierInfo pointers, which
end_comment

begin_comment
comment|// are not guaranteed to be 8-byte aligned.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|PointerLikeTypeTraits
operator|<
name|clang
operator|::
name|IdentifierInfo
operator|*
operator|>
block|{
name|public
operator|:
specifier|static
specifier|inline
name|void
operator|*
name|getAsVoidPointer
argument_list|(
argument|clang::IdentifierInfo* P
argument_list|)
block|{
return|return
name|P
return|;
block|}
specifier|static
specifier|inline
name|clang
operator|::
name|IdentifierInfo
operator|*
name|getFromVoidPointer
argument_list|(
argument|void *P
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|clang
operator|::
name|IdentifierInfo
operator|*
operator|>
operator|(
name|P
operator|)
return|;
block|}
end_expr_stmt

begin_enum
enum|enum
block|{
name|NumLowBitsAvailable
init|=
literal|1
block|}
enum|;
end_enum

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
name|class
name|PointerLikeTypeTraits
operator|<
specifier|const
name|clang
operator|::
name|IdentifierInfo
operator|*
operator|>
block|{
name|public
operator|:
specifier|static
specifier|inline
specifier|const
name|void
operator|*
name|getAsVoidPointer
argument_list|(
argument|const clang::IdentifierInfo* P
argument_list|)
block|{
return|return
name|P
return|;
block|}
specifier|static
specifier|inline
specifier|const
name|clang
operator|::
name|IdentifierInfo
operator|*
name|getFromVoidPointer
argument_list|(
argument|const void *P
argument_list|)
block|{
return|return
name|static_cast
operator|<
specifier|const
name|clang
operator|::
name|IdentifierInfo
operator|*
operator|>
operator|(
name|P
operator|)
return|;
block|}
end_expr_stmt

begin_enum
enum|enum
block|{
name|NumLowBitsAvailable
init|=
literal|1
block|}
enum|;
end_enum

begin_comment
unit|};  }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_BASIC_IDENTIFIERTABLE_H
end_comment

end_unit

