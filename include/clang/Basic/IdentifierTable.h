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
comment|//
end_comment

begin_comment
comment|// This file defines the IdentifierInfo, IdentifierTable, and Selector
end_comment

begin_comment
comment|// interfaces.
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
file|"clang/Basic/OperatorKinds.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/TokenKinds.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallString.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/OwningPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/PointerLikeTypeTraits.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<cassert>
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
comment|/// IdentifierLocPair - A simple pair of identifier info and location.
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
comment|/// IdentifierInfo - One of these records is kept for each identifier that
comment|/// is lexed.  This contains information about whether the token was #define'd,
comment|/// is a language keyword, or if it is a front-end token of some sort (e.g. a
comment|/// variable or function name).  The preprocessor keeps this information in a
comment|/// set, and all tok::identifier tokens have a pointer to one of these.
name|class
name|IdentifierInfo
block|{
comment|// Note: DON'T make TokenID a 'tok::TokenKind'; MSVC will treat it as a
comment|//       signed char and TokenKinds> 127 won't be handled correctly.
name|unsigned
name|TokenID
range|:
literal|8
decl_stmt|;
comment|// Front-end token ID or tok::identifier.
comment|// Objective-C keyword ('protocol' in '@protocol') or builtin (__builtin_inf).
comment|// First NUM_OBJC_KEYWORDS values are for Objective-C, the remaining values
comment|// are for builtins.
name|unsigned
name|ObjCOrBuiltinID
range|:
literal|10
decl_stmt|;
name|bool
name|HasMacro
range|:
literal|1
decl_stmt|;
comment|// True if there is a #define for this.
name|bool
name|IsExtension
range|:
literal|1
decl_stmt|;
comment|// True if identifier is a lang extension.
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
comment|// 9 bits left in 32-bit word.
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
name|IdentifierInfo
argument_list|(
specifier|const
name|IdentifierInfo
operator|&
argument_list|)
expr_stmt|;
comment|// NONCOPYABLE.
name|void
name|operator
init|=
operator|(
specifier|const
name|IdentifierInfo
operator|&
operator|)
decl_stmt|;
comment|// NONASSIGNABLE.
name|friend
name|class
name|IdentifierTable
decl_stmt|;
name|public
label|:
name|IdentifierInfo
argument_list|()
expr_stmt|;
comment|/// isStr - Return true if this is the identifier for the specified string.
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
operator|!
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
return|;
block|}
comment|/// getNameStart - Return the beginning of the actual string for this
comment|/// identifier.  The returned string is properly null terminated.
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
return|return
operator|(
operator|(
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
operator|*
operator|)
name|this
operator|)
operator|->
name|second
return|;
block|}
comment|/// getLength - Efficiently return the length of this identifier info.
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
specifier|const
name|char
operator|*
name|p
operator|=
operator|(
operator|(
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
operator|*
operator|)
name|this
operator|)
operator|->
name|second
operator|-
literal|2
expr_stmt|;
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
comment|/// getName - Return the actual identifier string.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|StringRef
name|getName
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
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
comment|/// hasMacroDefinition - Return true if this identifier is #defined to some
end_comment

begin_comment
comment|/// other value.
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
name|NeedsHandleIdentifier
operator|=
literal|1
expr_stmt|;
else|else
name|RecomputeNeedsHandleIdentifier
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/// get/setTokenID - If this is a source-language token (e.g. 'for'), this API
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

begin_decl_stmt
name|void
name|setTokenID
argument_list|(
name|tok
operator|::
name|TokenKind
name|ID
argument_list|)
block|{
name|TokenID
operator|=
name|ID
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// getPPKeywordID - Return the preprocessor keyword ID for this identifier.
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
comment|/// getObjCKeywordID - Return the Objective-C keyword ID for the this
end_comment

begin_comment
comment|/// identifier.  For example, 'class' will return tok::objc_class if ObjC is
end_comment

begin_comment
comment|/// enabled.
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
comment|/// getBuiltinID - Return a value indicating whether this is a builtin
end_comment

begin_comment
comment|/// function.  0 is not-built-in.  1 is builtin-for-some-nonprimary-target.
end_comment

begin_comment
comment|/// 2+ are specific builtin functions.
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
literal|1
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
literal|1
expr_stmt|;
else|else
name|RecomputeNeedsHandleIdentifier
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/// isPoisoned - Return true if this token has been poisoned.
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
literal|1
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
comment|/// isHandleIdentifierCase - Return true if the Preprocessor::HandleIdentifier
end_comment

begin_comment
comment|/// must be called on a token of this identifier.  If this returns false, we
end_comment

begin_comment
comment|/// know that HandleIdentifier will not affect the token.
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

begin_label
name|private
label|:
end_label

begin_comment
comment|/// RecomputeNeedsHandleIdentifier - The Preprocessor::HandleIdentifier does
end_comment

begin_comment
comment|/// several special (but rare) things to identifiers of various sorts.  For
end_comment

begin_comment
comment|/// example, it changes the "for" keyword token from tok::identifier to
end_comment

begin_comment
comment|/// tok::for.
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
operator|)
expr_stmt|;
block|}
end_function

begin_comment
unit|};
comment|/// IdentifierInfoLookup - An abstract class used by IdentifierTable that
end_comment

begin_comment
comment|///  provides an interface for performing lookups from strings
end_comment

begin_comment
comment|/// (const char *) to IdentiferInfo objects.
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
comment|/// get - Return the identifier token info for the specified named identifier.
comment|///  Unlike the version in IdentifierTable, this returns a pointer instead
comment|///  of a reference.  If the pointer is NULL then the IdentifierInfo cannot
comment|///  be found.
comment|//
comment|// FIXME: Move to StringRef API.
name|virtual
name|IdentifierInfo
modifier|*
name|get
parameter_list|(
specifier|const
name|char
modifier|*
name|NameStart
parameter_list|,
specifier|const
name|char
modifier|*
name|NameEnd
parameter_list|)
init|=
literal|0
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief An abstract class used to resolve numerical identifier
end_comment

begin_comment
comment|/// references (meaningful only to some external source) into
end_comment

begin_comment
comment|/// IdentifierInfo pointers.
end_comment

begin_decl_stmt
name|class
name|ExternalIdentifierLookup
block|{
name|public
label|:
name|virtual
operator|~
name|ExternalIdentifierLookup
argument_list|()
expr_stmt|;
comment|/// \brief Return the identifier associated with the given ID number.
comment|///
comment|/// The ID 0 is associated with the NULL identifier.
name|virtual
name|IdentifierInfo
modifier|*
name|GetIdentifier
parameter_list|(
name|unsigned
name|ID
parameter_list|)
init|=
literal|0
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// IdentifierTable - This table implements an efficient mapping from strings to
end_comment

begin_comment
comment|/// IdentifierInfo nodes.  It has no other purpose, but this is an
end_comment

begin_comment
comment|/// extremely performance-critical piece of the code, as each occurrance of
end_comment

begin_comment
comment|/// every identifier goes through here when lexed.
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
comment|/// IdentifierTable ctor - Create the identifier table, populating it with
comment|/// info about the language keywords for the language specified by LangOpts.
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
literal|0
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
comment|/// get - Return the identifier token info for the specified named identifier.
comment|///
name|IdentifierInfo
modifier|&
name|get
parameter_list|(
specifier|const
name|char
modifier|*
name|NameStart
parameter_list|,
specifier|const
name|char
modifier|*
name|NameEnd
parameter_list|)
block|{
name|llvm
operator|::
name|StringMapEntry
operator|<
name|IdentifierInfo
operator|*
operator|>
operator|&
name|Entry
operator|=
name|HashTable
operator|.
name|GetOrCreateValue
argument_list|(
name|NameStart
argument_list|,
name|NameEnd
argument_list|)
expr_stmt|;
name|IdentifierInfo
modifier|*
name|II
init|=
name|Entry
operator|.
name|getValue
argument_list|()
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
name|NameStart
argument_list|,
name|NameEnd
argument_list|)
expr_stmt|;
if|if
condition|(
name|II
condition|)
block|{
comment|// Cache in the StringMap for subsequent lookups.
name|Entry
operator|.
name|setValue
argument_list|(
name|II
argument_list|)
expr_stmt|;
return|return
operator|*
name|II
return|;
block|}
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
name|Entry
operator|.
name|setValue
argument_list|(
name|II
argument_list|)
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
comment|/// \brief Creates a new IdentifierInfo from the given string.
comment|///
comment|/// This is a lower-level version of get() that requires that this
comment|/// identifier not be known previously and that does not consult an
comment|/// external source for identifiers. In particular, external
comment|/// identifier sources can use this routine to build IdentifierInfo
comment|/// nodes and then introduce additional information about those
comment|/// identifiers.
name|IdentifierInfo
modifier|&
name|CreateIdentifierInfo
parameter_list|(
specifier|const
name|char
modifier|*
name|NameStart
parameter_list|,
specifier|const
name|char
modifier|*
name|NameEnd
parameter_list|)
block|{
name|llvm
operator|::
name|StringMapEntry
operator|<
name|IdentifierInfo
operator|*
operator|>
operator|&
name|Entry
operator|=
name|HashTable
operator|.
name|GetOrCreateValue
argument_list|(
name|NameStart
argument_list|,
name|NameEnd
argument_list|)
expr_stmt|;
name|IdentifierInfo
modifier|*
name|II
init|=
name|Entry
operator|.
name|getValue
argument_list|()
decl_stmt|;
name|assert
argument_list|(
operator|!
name|II
operator|&&
literal|"IdentifierInfo already exists"
argument_list|)
expr_stmt|;
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
name|Entry
operator|.
name|setValue
argument_list|(
name|II
argument_list|)
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
name|CreateIdentifierInfo
argument_list|(
name|llvm
operator|::
name|StringRef
name|Name
argument_list|)
block|{
return|return
name|CreateIdentifierInfo
argument_list|(
name|Name
operator|.
name|begin
argument_list|()
argument_list|,
name|Name
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|IdentifierInfo
modifier|&
name|get
argument_list|(
name|llvm
operator|::
name|StringRef
name|Name
argument_list|)
block|{
return|return
name|get
argument_list|(
name|Name
operator|.
name|begin
argument_list|()
argument_list|,
name|Name
operator|.
name|end
argument_list|()
argument_list|)
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
comment|/// PrintStats - Print some statistics to stderr that indicate how well the
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
comment|/// Selector - This smart pointer class efficiently represents Objective-C
end_comment

begin_comment
comment|/// method names. This class will either point to an IdentifierInfo or a
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
name|DiagnosticInfo
decl_stmt|;
enum|enum
name|IdentifierInfoFlag
block|{
comment|// MultiKeywordSelector = 0.
name|ZeroArg
init|=
literal|0x1
block|,
name|OneArg
init|=
literal|0x2
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
literal|0
return|;
block|}
end_decl_stmt

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
comment|/// getAsString - Derive the full selector name (e.g. "foo:bar:") and return
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

begin_comment
unit|};
comment|/// SelectorTable - This table allows us to fully hide how we implement
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
name|SelectorTable
argument_list|(
specifier|const
name|SelectorTable
operator|&
argument_list|)
expr_stmt|;
comment|// DISABLED: DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|SelectorTable
operator|&
operator|)
decl_stmt|;
comment|// DISABLED: DO NOT IMPLEMENT
name|public
label|:
name|SelectorTable
argument_list|()
expr_stmt|;
operator|~
name|SelectorTable
argument_list|()
expr_stmt|;
comment|/// getSelector - This can create any sort of selector.  NumArgs indicates
comment|/// whether this is a no argument selector "foo", a single argument selector
comment|/// "foo:" or multi-argument "foo:bar:".
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
comment|/// constructSetterName - Return the setter name for the given
comment|/// identifier, i.e. "set" + Name where the initial character of Name
comment|/// has been capitalized.
specifier|static
name|Selector
name|constructSetterName
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
block|{
name|llvm
operator|::
name|SmallString
operator|<
literal|100
operator|>
name|SelectorName
expr_stmt|;
name|SelectorName
operator|=
literal|"set"
expr_stmt|;
name|SelectorName
operator|+=
name|Name
operator|->
name|getName
argument_list|()
expr_stmt|;
name|SelectorName
index|[
literal|3
index|]
operator|=
name|toupper
argument_list|(
name|SelectorName
index|[
literal|3
index|]
argument_list|)
expr_stmt|;
name|IdentifierInfo
modifier|*
name|SetterName
init|=
operator|&
name|Idents
operator|.
name|get
argument_list|(
name|SelectorName
operator|.
name|data
argument_list|()
argument_list|,
name|SelectorName
operator|.
name|data
argument_list|()
operator|+
name|SelectorName
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|SelTable
operator|.
name|getUnarySelector
argument_list|(
name|SetterName
argument_list|)
return|;
block|}
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
name|CXXUsingDirective
block|,
name|NUM_EXTRA_KINDS
block|}
enum|;
comment|/// ExtraKindOrNumArgs - Either the kind of C++ special name or
comment|/// operator-id (if the value is one of the CXX* enumerators of
comment|/// ExtraKind), in which case the DeclarationNameExtra is also a
comment|/// CXXSpecialName (for CXXConstructor, CXXDestructor, or
comment|/// CXXConversionFunction) or CXXOperatorIdName, it may be also
comment|/// name common to C++ using-directives (CXXUsingDirective), otherwise
comment|/// it is NUM_EXTRA_KINDS+NumArgs, where NumArgs is the number of
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
specifier|static
name|bool
name|isPod
parameter_list|()
block|{
return|return
name|true
return|;
block|}
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
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

end_unit

