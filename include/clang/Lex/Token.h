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
name|LLVM_CLANG_TOKEN_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TOKEN_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/TemplateKinds.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/TokenKinds.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/OperatorKinds.h"
end_include

begin_include
include|#
directive|include
file|<cstdlib>
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
comment|/// The location of the token.
name|SourceLocation
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
comment|///  Other:
comment|///    This is null.
name|void
modifier|*
name|PtrData
decl_stmt|;
comment|/// Kind - The actual flavor of token this is.
comment|///
name|unsigned
name|char
name|Kind
decl_stmt|;
comment|// DON'T make Kind a 'tok::TokenKind';
comment|// MSVC will treat it as a signed char and
comment|// TokenKinds> 127 won't be handled correctly.
comment|/// Flags - Bits we track about this token, members of the TokenFlags enum.
name|unsigned
name|char
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
comment|// At start of line or only after whitespace.
name|LeadingSpace
init|=
literal|0x02
block|,
comment|// Whitespace exists before this token.
name|DisableExpand
init|=
literal|0x04
block|,
comment|// This identifier may never be macro expanded.
name|NeedsCleaning
init|=
literal|0x08
comment|// Contained an escaped newline or trigraph.
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
operator|(
name|tok
operator|::
name|TokenKind
operator|)
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
operator|(
name|unsigned
operator|)
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
operator|(
name|unsigned
operator|)
name|K
return|;
block|}
comment|/// isLiteral - Return true if this is a "literal", like a numeric
comment|/// constant, string, etc.
name|bool
name|isLiteral
argument_list|()
specifier|const
block|{
return|return
name|is
argument_list|(
name|tok
operator|::
name|numeric_constant
argument_list|)
operator|||
name|is
argument_list|(
name|tok
operator|::
name|char_constant
argument_list|)
operator|||
name|is
argument_list|(
name|tok
operator|::
name|string_literal
argument_list|)
operator|||
name|is
argument_list|(
name|tok
operator|::
name|wide_string_literal
argument_list|)
operator|||
name|is
argument_list|(
name|tok
operator|::
name|angle_string_literal
argument_list|)
return|;
block|}
name|bool
name|isAnnotation
argument_list|()
specifier|const
block|{
return|return
name|is
argument_list|(
name|tok
operator|::
name|annot_typename
argument_list|)
operator|||
name|is
argument_list|(
name|tok
operator|::
name|annot_cxxscope
argument_list|)
operator|||
name|is
argument_list|(
name|tok
operator|::
name|annot_template_id
argument_list|)
return|;
block|}
comment|/// getLocation - Return a source location identifier for the specified
comment|/// offset in the current file.
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|Loc
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
comment|/// getAnnotationRange - SourceRange of the group of tokens that this
comment|/// annotation token represents.
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
operator|(
name|tok
operator|::
name|TokenKind
operator|)
name|Kind
argument_list|)
return|;
block|}
comment|/// startToken - Reset all flags to cleared.
comment|///
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
literal|0
expr_stmt|;
name|Loc
operator|=
name|SourceLocation
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
operator|!
name|isAnnotation
argument_list|()
operator|&&
literal|"Used IdentInfo on annotation token!"
argument_list|)
block|;
if|if
condition|(
name|isLiteral
argument_list|()
condition|)
return|return
literal|0
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
operator|(
name|void
operator|*
operator|)
name|Ptr
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
comment|/// setFlag - Set the specified flag.
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
comment|/// clearFlag - Unset the specified flag.
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
comment|/// getFlags - Return the internal represtation of the flags.
comment|///  Only intended for low-level operations such as writing tokens to
comment|//   disk.
name|unsigned
name|getFlags
argument_list|()
specifier|const
block|{
return|return
name|Flags
return|;
block|}
comment|/// setFlagValue - Set a flag to either true or false.
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
operator|(
name|Flags
operator|&
name|StartOfLine
operator|)
operator|?
name|true
operator|:
name|false
return|;
block|}
comment|/// hasLeadingSpace - Return true if this token has whitespace before it.
comment|///
name|bool
name|hasLeadingSpace
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Flags
operator|&
name|LeadingSpace
operator|)
operator|?
name|true
operator|:
name|false
return|;
block|}
comment|/// isExpandDisabled - Return true if this identifier token should never
comment|/// be expanded in the future, due to C99 6.10.3.4p2.
name|bool
name|isExpandDisabled
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Flags
operator|&
name|DisableExpand
operator|)
operator|?
name|true
operator|:
name|false
return|;
block|}
comment|/// isObjCAtKeyword - Return true if we have an ObjC keyword identifier.
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
comment|/// getObjCKeywordID - Return the ObjC keyword kind.
name|tok
operator|::
name|ObjCKeywordKind
name|getObjCKeywordID
argument_list|()
specifier|const
expr_stmt|;
comment|/// needsCleaning - Return true if this token has trigraphs or escaped
comment|/// newlines in it.
comment|///
name|bool
name|needsCleaning
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Flags
operator|&
name|NeedsCleaning
operator|)
operator|?
name|true
operator|:
name|false
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// PPConditionalInfo - Information about the conditional stack (#if directives)
end_comment

begin_comment
comment|/// currently active.
end_comment

begin_struct
struct|struct
name|PPConditionalInfo
block|{
comment|/// IfLoc - Location where the conditional started.
comment|///
name|SourceLocation
name|IfLoc
decl_stmt|;
comment|/// WasSkipping - True if this was contained in a skipping directive, e.g.
comment|/// in a "#if 0" block.
name|bool
name|WasSkipping
decl_stmt|;
comment|/// FoundNonSkip - True if we have emitted tokens already, and now we're in
comment|/// an #else block or something.  Only useful in Skipping blocks.
name|bool
name|FoundNonSkip
decl_stmt|;
comment|/// FoundElse - True if we've seen a #else in this block.  If so,
comment|/// #elif/#else directives are not allowed.
name|bool
name|FoundElse
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/// TemplateIdAnnotation - Information about a template-id annotation
end_comment

begin_comment
comment|/// token, which contains the template declaration, template
end_comment

begin_comment
comment|/// arguments, whether those template arguments were types or
end_comment

begin_comment
comment|/// expressions, and the source locations for important tokens. All of
end_comment

begin_comment
comment|/// the information about template arguments is allocated directly
end_comment

begin_comment
comment|/// after this structure.
end_comment

begin_struct
struct|struct
name|TemplateIdAnnotation
block|{
comment|/// TemplateNameLoc - The location of the template name within the
comment|/// source.
name|SourceLocation
name|TemplateNameLoc
decl_stmt|;
comment|/// FIXME: Temporarily stores the name of a specialization
name|IdentifierInfo
modifier|*
name|Name
decl_stmt|;
comment|/// FIXME: Temporarily stores the overloaded operator kind.
name|OverloadedOperatorKind
name|Operator
decl_stmt|;
comment|/// The declaration of the template corresponding to the
comment|/// template-name. This is an Action::DeclTy*.
name|void
modifier|*
name|Template
decl_stmt|;
comment|/// The kind of template that Template refers to.
name|TemplateNameKind
name|Kind
decl_stmt|;
comment|/// The location of the '<' before the template argument
comment|/// list.
name|SourceLocation
name|LAngleLoc
decl_stmt|;
comment|/// The location of the '>' after the template argument
comment|/// list.
name|SourceLocation
name|RAngleLoc
decl_stmt|;
comment|/// NumArgs - The number of template arguments.
name|unsigned
name|NumArgs
decl_stmt|;
comment|/// \brief Retrieves a pointer to the template arguments
name|void
modifier|*
modifier|*
name|getTemplateArgs
parameter_list|()
block|{
return|return
operator|(
name|void
operator|*
operator|*
operator|)
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
comment|/// \brief Retrieves a pointer to the array of template argument
comment|/// locations.
name|SourceLocation
modifier|*
name|getTemplateArgLocations
parameter_list|()
block|{
return|return
operator|(
name|SourceLocation
operator|*
operator|)
operator|(
name|getTemplateArgs
argument_list|()
operator|+
name|NumArgs
operator|)
return|;
block|}
comment|/// \brief Retrieves a pointer to the array of flags that states
comment|/// whether the template arguments are types.
name|bool
modifier|*
name|getTemplateArgIsType
parameter_list|()
block|{
return|return
operator|(
name|bool
operator|*
operator|)
operator|(
name|getTemplateArgLocations
argument_list|()
operator|+
name|NumArgs
operator|)
return|;
block|}
specifier|static
name|TemplateIdAnnotation
modifier|*
name|Allocate
parameter_list|(
name|unsigned
name|NumArgs
parameter_list|)
block|{
name|TemplateIdAnnotation
modifier|*
name|TemplateId
init|=
operator|(
name|TemplateIdAnnotation
operator|*
operator|)
name|std
operator|::
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|TemplateIdAnnotation
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
operator|*
name|NumArgs
operator|+
sizeof|sizeof
argument_list|(
name|SourceLocation
argument_list|)
operator|*
name|NumArgs
operator|+
sizeof|sizeof
argument_list|(
name|bool
argument_list|)
operator|*
name|NumArgs
argument_list|)
decl_stmt|;
name|TemplateId
operator|->
name|NumArgs
operator|=
name|NumArgs
expr_stmt|;
return|return
name|TemplateId
return|;
block|}
name|void
name|Destroy
parameter_list|()
block|{
name|free
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
block|}
struct|;
end_struct

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

