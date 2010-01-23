begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DeclBase.h - Base Classes for representing declarations -*- C++ -*-===//
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
comment|//  This file defines the Decl and DeclContext interfaces.
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
name|LLVM_CLANG_AST_DECLBASE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_DECLBASE_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Attr.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/Specifiers.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/PrettyStackTrace.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerUnion.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|DeclContext
decl_stmt|;
name|class
name|TranslationUnitDecl
decl_stmt|;
name|class
name|NamespaceDecl
decl_stmt|;
name|class
name|UsingDirectiveDecl
decl_stmt|;
name|class
name|NamedDecl
decl_stmt|;
name|class
name|FunctionDecl
decl_stmt|;
name|class
name|CXXRecordDecl
decl_stmt|;
name|class
name|EnumDecl
decl_stmt|;
name|class
name|ObjCMethodDecl
decl_stmt|;
name|class
name|ObjCContainerDecl
decl_stmt|;
name|class
name|ObjCInterfaceDecl
decl_stmt|;
name|class
name|ObjCCategoryDecl
decl_stmt|;
name|class
name|ObjCProtocolDecl
decl_stmt|;
name|class
name|ObjCImplementationDecl
decl_stmt|;
name|class
name|ObjCCategoryImplDecl
decl_stmt|;
name|class
name|ObjCImplDecl
decl_stmt|;
name|class
name|LinkageSpecDecl
decl_stmt|;
name|class
name|BlockDecl
decl_stmt|;
name|class
name|DeclarationName
decl_stmt|;
name|class
name|CompoundStmt
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// DeclContext* is only 4-byte aligned on 32-bit systems.
name|template
operator|<
operator|>
name|class
name|PointerLikeTypeTraits
operator|<
name|clang
operator|::
name|DeclContext
operator|*
operator|>
block|{
typedef|typedef
name|clang
operator|::
name|DeclContext
operator|*
name|PT
expr_stmt|;
name|public
operator|:
specifier|static
specifier|inline
name|void
operator|*
name|getAsVoidPointer
argument_list|(
argument|PT P
argument_list|)
block|{
return|return
name|P
return|;
block|}
specifier|static
specifier|inline
name|PT
name|getFromVoidPointer
argument_list|(
argument|void *P
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|PT
operator|>
operator|(
name|P
operator|)
return|;
block|}
block|enum
block|{
name|NumLowBitsAvailable
operator|=
literal|2
block|}
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
unit|}  namespace
name|clang
end_macro

begin_block
block|{
comment|/// Decl - This represents one declaration (or definition), e.g. a variable,
comment|/// typedef, function, struct, etc.
comment|///
name|class
name|Decl
block|{
name|public
label|:
comment|/// \brief Lists the kind of concrete classes of Decl.
enum|enum
name|Kind
block|{
define|#
directive|define
name|DECL
parameter_list|(
name|Derived
parameter_list|,
name|Base
parameter_list|)
value|Derived,
define|#
directive|define
name|DECL_RANGE
parameter_list|(
name|CommonBase
parameter_list|,
name|Start
parameter_list|,
name|End
parameter_list|)
define|\
value|CommonBase##First = Start, CommonBase##Last = End,
define|#
directive|define
name|LAST_DECL_RANGE
parameter_list|(
name|CommonBase
parameter_list|,
name|Start
parameter_list|,
name|End
parameter_list|)
define|\
value|CommonBase##First = Start, CommonBase##Last = End
include|#
directive|include
file|"clang/AST/DeclNodes.def"
block|}
enum|;
comment|/// IdentifierNamespace - According to C99 6.2.3, there are four
comment|/// namespaces, labels, tags, members and ordinary
comment|/// identifiers. These are meant as bitmasks, so that searches in
comment|/// C++ can look into the "tag" namespace during ordinary lookup. We
comment|/// use additional namespaces for Objective-C entities.  We also put
comment|/// C++ friend declarations (of previously-undeclared entities) in
comment|/// shadow namespaces, and 'using' declarations (as opposed to their
comment|/// implicit shadow declarations) can be found in their own
comment|/// namespace.
enum|enum
name|IdentifierNamespace
block|{
name|IDNS_Label
init|=
literal|0x1
block|,
name|IDNS_Tag
init|=
literal|0x2
block|,
name|IDNS_Member
init|=
literal|0x4
block|,
name|IDNS_Ordinary
init|=
literal|0x8
block|,
name|IDNS_ObjCProtocol
init|=
literal|0x10
block|,
name|IDNS_ObjCImplementation
init|=
literal|0x20
block|,
name|IDNS_ObjCCategoryName
init|=
literal|0x40
block|,
name|IDNS_OrdinaryFriend
init|=
literal|0x80
block|,
name|IDNS_TagFriend
init|=
literal|0x100
block|,
name|IDNS_Using
init|=
literal|0x200
block|}
enum|;
comment|/// ObjCDeclQualifier - Qualifier used on types in method declarations
comment|/// for remote messaging. They are meant for the arguments though and
comment|/// applied to the Decls (ObjCMethodDecl and ParmVarDecl).
enum|enum
name|ObjCDeclQualifier
block|{
name|OBJC_TQ_None
init|=
literal|0x0
block|,
name|OBJC_TQ_In
init|=
literal|0x1
block|,
name|OBJC_TQ_Inout
init|=
literal|0x2
block|,
name|OBJC_TQ_Out
init|=
literal|0x4
block|,
name|OBJC_TQ_Bycopy
init|=
literal|0x8
block|,
name|OBJC_TQ_Byref
init|=
literal|0x10
block|,
name|OBJC_TQ_Oneway
init|=
literal|0x20
block|}
enum|;
name|private
label|:
comment|/// NextDeclInContext - The next declaration within the same lexical
comment|/// DeclContext. These pointers form the linked list that is
comment|/// traversed via DeclContext's decls_begin()/decls_end().
name|Decl
modifier|*
name|NextDeclInContext
decl_stmt|;
name|friend
name|class
name|DeclContext
decl_stmt|;
struct|struct
name|MultipleDC
block|{
name|DeclContext
modifier|*
name|SemanticDC
decl_stmt|;
name|DeclContext
modifier|*
name|LexicalDC
decl_stmt|;
block|}
struct|;
comment|/// DeclCtx - Holds either a DeclContext* or a MultipleDC*.
comment|/// For declarations that don't contain C++ scope specifiers, it contains
comment|/// the DeclContext where the Decl was declared.
comment|/// For declarations with C++ scope specifiers, it contains a MultipleDC*
comment|/// with the context where it semantically belongs (SemanticDC) and the
comment|/// context where it was lexically declared (LexicalDC).
comment|/// e.g.:
comment|///
comment|///   namespace A {
comment|///      void f(); // SemanticDC == LexicalDC == 'namespace A'
comment|///   }
comment|///   void A::f(); // SemanticDC == namespace 'A'
comment|///                // LexicalDC == global namespace
name|llvm
operator|::
name|PointerUnion
operator|<
name|DeclContext
operator|*
operator|,
name|MultipleDC
operator|*
operator|>
name|DeclCtx
expr_stmt|;
specifier|inline
name|bool
name|isInSemaDC
argument_list|()
specifier|const
block|{
return|return
name|DeclCtx
operator|.
name|is
operator|<
name|DeclContext
operator|*
operator|>
operator|(
operator|)
return|;
block|}
specifier|inline
name|bool
name|isOutOfSemaDC
argument_list|()
specifier|const
block|{
return|return
name|DeclCtx
operator|.
name|is
operator|<
name|MultipleDC
operator|*
operator|>
operator|(
operator|)
return|;
block|}
specifier|inline
name|MultipleDC
operator|*
name|getMultipleDC
argument_list|()
specifier|const
block|{
return|return
name|DeclCtx
operator|.
name|get
operator|<
name|MultipleDC
operator|*
operator|>
operator|(
operator|)
return|;
block|}
specifier|inline
name|DeclContext
operator|*
name|getSemanticDC
argument_list|()
specifier|const
block|{
return|return
name|DeclCtx
operator|.
name|get
operator|<
name|DeclContext
operator|*
operator|>
operator|(
operator|)
return|;
block|}
comment|/// Loc - The location that this decl.
name|SourceLocation
name|Loc
decl_stmt|;
comment|/// DeclKind - This indicates which class this is.
name|Kind
name|DeclKind
range|:
literal|8
decl_stmt|;
comment|/// InvalidDecl - This indicates a semantic error occurred.
name|unsigned
name|int
name|InvalidDecl
range|:
literal|1
decl_stmt|;
comment|/// HasAttrs - This indicates whether the decl has attributes or not.
name|unsigned
name|int
name|HasAttrs
range|:
literal|1
decl_stmt|;
comment|/// Implicit - Whether this declaration was implicitly generated by
comment|/// the implementation rather than explicitly written by the user.
name|bool
name|Implicit
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether this declaration was "used", meaning that a definition is
comment|/// required.
name|bool
name|Used
range|:
literal|1
decl_stmt|;
name|protected
label|:
comment|/// Access - Used by C++ decls for the access specifier.
comment|// NOTE: VC++ treats enums as signed, avoid using the AccessSpecifier enum
name|unsigned
name|Access
range|:
literal|2
decl_stmt|;
name|friend
name|class
name|CXXClassMemberWrapper
decl_stmt|;
comment|// PCHLevel - the "level" of precompiled header/AST file from which this
comment|// declaration was built.
name|unsigned
name|PCHLevel
range|:
literal|2
decl_stmt|;
comment|/// IdentifierNamespace - This specifies what IDNS_* namespace this lives in.
name|unsigned
name|IdentifierNamespace
range|:
literal|16
decl_stmt|;
name|private
label|:
ifndef|#
directive|ifndef
name|NDEBUG
name|void
name|CheckAccessDeclContext
argument_list|()
specifier|const
expr_stmt|;
else|#
directive|else
name|void
name|CheckAccessDeclContext
argument_list|()
specifier|const
block|{ }
endif|#
directive|endif
name|protected
operator|:
name|Decl
argument_list|(
argument|Kind DK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|)
operator|:
name|NextDeclInContext
argument_list|(
literal|0
argument_list|)
operator|,
name|DeclCtx
argument_list|(
name|DC
argument_list|)
operator|,
name|Loc
argument_list|(
name|L
argument_list|)
operator|,
name|DeclKind
argument_list|(
name|DK
argument_list|)
operator|,
name|InvalidDecl
argument_list|(
literal|0
argument_list|)
operator|,
name|HasAttrs
argument_list|(
name|false
argument_list|)
operator|,
name|Implicit
argument_list|(
name|false
argument_list|)
operator|,
name|Used
argument_list|(
name|false
argument_list|)
operator|,
name|Access
argument_list|(
name|AS_none
argument_list|)
operator|,
name|PCHLevel
argument_list|(
literal|0
argument_list|)
operator|,
name|IdentifierNamespace
argument_list|(
argument|getIdentifierNamespaceForKind(DK)
argument_list|)
block|{
if|if
condition|(
name|Decl
operator|::
name|CollectingStats
argument_list|()
condition|)
name|addDeclKind
argument_list|(
name|DK
argument_list|)
expr_stmt|;
block|}
name|virtual
operator|~
name|Decl
argument_list|()
expr_stmt|;
name|public
label|:
comment|/// \brief Source range that this declaration covers.
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|getLocation
argument_list|()
argument_list|,
name|getLocation
argument_list|()
argument_list|)
return|;
block|}
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
block|{
return|return
name|getSourceRange
argument_list|()
operator|.
name|getBegin
argument_list|()
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
block|{
return|return
name|getSourceRange
argument_list|()
operator|.
name|getEnd
argument_list|()
return|;
block|}
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|Loc
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
name|Kind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|DeclKind
return|;
block|}
specifier|const
name|char
operator|*
name|getDeclKindName
argument_list|()
specifier|const
expr_stmt|;
name|Decl
modifier|*
name|getNextDeclInContext
parameter_list|()
block|{
return|return
name|NextDeclInContext
return|;
block|}
specifier|const
name|Decl
operator|*
name|getNextDeclInContext
argument_list|()
specifier|const
block|{
return|return
name|NextDeclInContext
return|;
block|}
name|DeclContext
modifier|*
name|getDeclContext
parameter_list|()
block|{
if|if
condition|(
name|isInSemaDC
argument_list|()
condition|)
return|return
name|getSemanticDC
argument_list|()
return|;
return|return
name|getMultipleDC
argument_list|()
operator|->
name|SemanticDC
return|;
block|}
specifier|const
name|DeclContext
operator|*
name|getDeclContext
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|Decl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getDeclContext
argument_list|()
return|;
block|}
name|TranslationUnitDecl
modifier|*
name|getTranslationUnitDecl
parameter_list|()
function_decl|;
specifier|const
name|TranslationUnitDecl
operator|*
name|getTranslationUnitDecl
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|Decl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getTranslationUnitDecl
argument_list|()
return|;
block|}
name|bool
name|isInAnonymousNamespace
argument_list|()
specifier|const
expr_stmt|;
name|ASTContext
operator|&
name|getASTContext
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setAccess
parameter_list|(
name|AccessSpecifier
name|AS
parameter_list|)
block|{
name|Access
operator|=
name|AS
expr_stmt|;
name|CheckAccessDeclContext
argument_list|()
expr_stmt|;
block|}
name|AccessSpecifier
name|getAccess
argument_list|()
specifier|const
block|{
name|CheckAccessDeclContext
argument_list|()
block|;
return|return
name|AccessSpecifier
argument_list|(
name|Access
argument_list|)
return|;
block|}
name|bool
name|hasAttrs
argument_list|()
specifier|const
block|{
return|return
name|HasAttrs
return|;
block|}
name|void
name|addAttr
parameter_list|(
name|Attr
modifier|*
name|attr
parameter_list|)
function_decl|;
specifier|const
name|Attr
operator|*
name|getAttrs
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|HasAttrs
condition|)
return|return
literal|0
return|;
comment|// common case, no attributes.
return|return
name|getAttrsImpl
argument_list|()
return|;
comment|// Uncommon case, out of line hash lookup.
block|}
name|void
name|swapAttrs
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
name|void
name|invalidateAttrs
parameter_list|()
function_decl|;
name|template
operator|<
name|typename
name|T
operator|>
specifier|const
name|T
operator|*
name|getAttr
argument_list|()
specifier|const
block|{
for|for
control|(
specifier|const
name|Attr
modifier|*
name|attr
init|=
name|getAttrs
argument_list|()
init|;
name|attr
condition|;
name|attr
operator|=
name|attr
operator|->
name|getNext
argument_list|()
control|)
if|if
condition|(
specifier|const
name|T
modifier|*
name|V
init|=
name|dyn_cast
operator|<
name|T
operator|>
operator|(
name|attr
operator|)
condition|)
return|return
name|V
return|;
return|return
literal|0
return|;
block|}
end_block

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|hasAttr
argument_list|()
specifier|const
block|{
return|return
name|getAttr
operator|<
name|T
operator|>
operator|(
operator|)
operator|!=
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|/// setInvalidDecl - Indicates the Decl had a semantic error. This
end_comment

begin_comment
comment|/// allows for graceful error recovery.
end_comment

begin_function
name|void
name|setInvalidDecl
parameter_list|(
name|bool
name|Invalid
init|=
name|true
parameter_list|)
block|{
name|InvalidDecl
operator|=
name|Invalid
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|bool
name|isInvalidDecl
argument_list|()
specifier|const
block|{
return|return
operator|(
name|bool
operator|)
name|InvalidDecl
return|;
block|}
end_expr_stmt

begin_comment
comment|/// isImplicit - Indicates whether the declaration was implicitly
end_comment

begin_comment
comment|/// generated by the implementation. If false, this declaration
end_comment

begin_comment
comment|/// was written explicitly in the source code.
end_comment

begin_expr_stmt
name|bool
name|isImplicit
argument_list|()
specifier|const
block|{
return|return
name|Implicit
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setImplicit
parameter_list|(
name|bool
name|I
init|=
name|true
parameter_list|)
block|{
name|Implicit
operator|=
name|I
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Whether this declaration was used, meaning that a definition
end_comment

begin_comment
comment|/// is required.
end_comment

begin_expr_stmt
name|bool
name|isUsed
argument_list|()
specifier|const
block|{
return|return
name|Used
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setUsed
parameter_list|(
name|bool
name|U
init|=
name|true
parameter_list|)
block|{
name|Used
operator|=
name|U
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Retrieve the level of precompiled header from which this
end_comment

begin_comment
comment|/// declaration was generated.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The PCH level of a declaration describes where the declaration originated
end_comment

begin_comment
comment|/// from. A PCH level of 0 indicates that the declaration was not from a
end_comment

begin_comment
comment|/// precompiled header. A PCH level of 1 indicates that the declaration was
end_comment

begin_comment
comment|/// from a top-level precompiled header; 2 indicates that the declaration
end_comment

begin_comment
comment|/// comes from a precompiled header on which the top-level precompiled header
end_comment

begin_comment
comment|/// depends, and so on.
end_comment

begin_expr_stmt
name|unsigned
name|getPCHLevel
argument_list|()
specifier|const
block|{
return|return
name|PCHLevel
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief The maximum PCH level that any declaration may have.
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|unsigned
name|MaxPCHLevel
init|=
literal|3
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Set the PCH level of this declaration.
end_comment

begin_function
name|void
name|setPCHLevel
parameter_list|(
name|unsigned
name|Level
parameter_list|)
block|{
name|assert
argument_list|(
name|Level
operator|<
name|MaxPCHLevel
operator|&&
literal|"PCH level exceeds the maximum"
argument_list|)
expr_stmt|;
name|PCHLevel
operator|=
name|Level
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|unsigned
name|getIdentifierNamespace
argument_list|()
specifier|const
block|{
return|return
name|IdentifierNamespace
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|bool
name|isInIdentifierNamespace
argument_list|(
name|unsigned
name|NS
argument_list|)
decl|const
block|{
return|return
name|getIdentifierNamespace
argument_list|()
operator|&
name|NS
return|;
block|}
end_decl_stmt

begin_function_decl
specifier|static
name|unsigned
name|getIdentifierNamespaceForKind
parameter_list|(
name|Kind
name|DK
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// getLexicalDeclContext - The declaration context where this Decl was
end_comment

begin_comment
comment|/// lexically declared (LexicalDC). May be different from
end_comment

begin_comment
comment|/// getDeclContext() (SemanticDC).
end_comment

begin_comment
comment|/// e.g.:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   namespace A {
end_comment

begin_comment
comment|///      void f(); // SemanticDC == LexicalDC == 'namespace A'
end_comment

begin_comment
comment|///   }
end_comment

begin_comment
comment|///   void A::f(); // SemanticDC == namespace 'A'
end_comment

begin_comment
comment|///                // LexicalDC == global namespace
end_comment

begin_function
name|DeclContext
modifier|*
name|getLexicalDeclContext
parameter_list|()
block|{
if|if
condition|(
name|isInSemaDC
argument_list|()
condition|)
return|return
name|getSemanticDC
argument_list|()
return|;
return|return
name|getMultipleDC
argument_list|()
operator|->
name|LexicalDC
return|;
block|}
end_function

begin_expr_stmt
specifier|const
name|DeclContext
operator|*
name|getLexicalDeclContext
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|Decl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getLexicalDeclContext
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|isOutOfLine
argument_list|()
specifier|const
block|{
return|return
name|getLexicalDeclContext
argument_list|()
operator|!=
name|getDeclContext
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// setDeclContext - Set both the semantic and lexical DeclContext
end_comment

begin_comment
comment|/// to DC.
end_comment

begin_function_decl
name|void
name|setDeclContext
parameter_list|(
name|DeclContext
modifier|*
name|DC
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setLexicalDeclContext
parameter_list|(
name|DeclContext
modifier|*
name|DC
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// isDefinedOutsideFunctionOrMethod - This predicate returns true if this
end_comment

begin_comment
comment|// scoped decl is defined outside the current function or method.  This is
end_comment

begin_comment
comment|// roughly global variables and functions, but also handles enums (which could
end_comment

begin_comment
comment|// be defined inside or outside a function etc).
end_comment

begin_expr_stmt
name|bool
name|isDefinedOutsideFunctionOrMethod
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Retrieves the "canonical" declaration of the given declaration.
end_comment

begin_function
name|virtual
name|Decl
modifier|*
name|getCanonicalDecl
parameter_list|()
block|{
return|return
name|this
return|;
block|}
end_function

begin_expr_stmt
specifier|const
name|Decl
operator|*
name|getCanonicalDecl
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|Decl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getCanonicalDecl
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Whether this particular Decl is a canonical one.
end_comment

begin_expr_stmt
name|bool
name|isCanonicalDecl
argument_list|()
specifier|const
block|{
return|return
name|getCanonicalDecl
argument_list|()
operator|==
name|this
return|;
block|}
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_comment
comment|/// \brief Returns the next redeclaration or itself if this is the only decl.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Decl subclasses that can be redeclared should override this method so that
end_comment

begin_comment
comment|/// Decl::redecl_iterator can iterate over them.
end_comment

begin_function
name|virtual
name|Decl
modifier|*
name|getNextRedeclaration
parameter_list|()
block|{
return|return
name|this
return|;
block|}
end_function

begin_label
name|public
label|:
end_label

begin_comment
comment|/// \brief Iterates through all the redeclarations of the same decl.
end_comment

begin_decl_stmt
name|class
name|redecl_iterator
block|{
comment|/// Current - The current declaration.
name|Decl
modifier|*
name|Current
decl_stmt|;
name|Decl
modifier|*
name|Starter
decl_stmt|;
name|public
label|:
typedef|typedef
name|Decl
modifier|*
name|value_type
typedef|;
typedef|typedef
name|Decl
modifier|*
name|reference
typedef|;
typedef|typedef
name|Decl
modifier|*
name|pointer
typedef|;
typedef|typedef
name|std
operator|::
name|forward_iterator_tag
name|iterator_category
expr_stmt|;
typedef|typedef
name|std
operator|::
name|ptrdiff_t
name|difference_type
expr_stmt|;
name|redecl_iterator
argument_list|()
operator|:
name|Current
argument_list|(
literal|0
argument_list|)
block|{ }
name|explicit
name|redecl_iterator
argument_list|(
name|Decl
operator|*
name|C
argument_list|)
operator|:
name|Current
argument_list|(
name|C
argument_list|)
operator|,
name|Starter
argument_list|(
argument|C
argument_list|)
block|{ }
name|reference
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|Current
return|;
block|}
name|pointer
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
name|Current
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|redecl_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
name|assert
argument_list|(
name|Current
operator|&&
literal|"Advancing while iterator has reached end"
argument_list|)
block|;
comment|// Get either previous decl or latest decl.
name|Decl
operator|*
name|Next
operator|=
name|Current
operator|->
name|getNextRedeclaration
argument_list|()
block|;
name|assert
argument_list|(
name|Next
operator|&&
literal|"Should return next redeclaration or itself, never null!"
argument_list|)
block|;
name|Current
operator|=
operator|(
name|Next
operator|!=
name|Starter
condition|?
name|Next
else|:
literal|0
operator|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|redecl_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|redecl_iterator
name|tmp
argument_list|(
operator|*
name|this
argument_list|)
block|;
operator|++
operator|(
operator|*
name|this
operator|)
block|;
return|return
name|tmp
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
name|bool
name|operator
operator|==
operator|(
name|redecl_iterator
name|x
operator|,
name|redecl_iterator
name|y
operator|)
block|{
return|return
name|x
operator|.
name|Current
operator|==
name|y
operator|.
name|Current
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
name|bool
name|operator
operator|!=
operator|(
name|redecl_iterator
name|x
operator|,
name|redecl_iterator
name|y
operator|)
block|{
return|return
name|x
operator|.
name|Current
operator|!=
name|y
operator|.
name|Current
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// \brief Returns iterator for all the redeclarations of the same decl.
end_comment

begin_comment
comment|/// It will iterate at least once (when this decl is the only one).
end_comment

begin_expr_stmt
name|redecl_iterator
name|redecls_begin
argument_list|()
specifier|const
block|{
return|return
name|redecl_iterator
argument_list|(
name|const_cast
operator|<
name|Decl
operator|*
operator|>
operator|(
name|this
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|redecl_iterator
name|redecls_end
argument_list|()
specifier|const
block|{
return|return
name|redecl_iterator
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getBody - If this Decl represents a declaration for a body of code,
end_comment

begin_comment
comment|///  such as a function or method definition, this method returns the
end_comment

begin_comment
comment|///  top-level Stmt* of that body.  Otherwise this method returns null.
end_comment

begin_expr_stmt
name|virtual
name|Stmt
operator|*
name|getBody
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getCompoundBody - Returns getBody(), dyn_casted to a CompoundStmt.
end_comment

begin_expr_stmt
name|CompoundStmt
operator|*
name|getCompoundBody
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// getBodyRBrace - Gets the right brace of the body, if a body exists.
end_comment

begin_comment
comment|/// This works whether the body is a CompoundStmt or a CXXTryStmt.
end_comment

begin_expr_stmt
name|SourceLocation
name|getBodyRBrace
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|// global temp stats (until we have a per-module visitor)
end_comment

begin_function_decl
specifier|static
name|void
name|addDeclKind
parameter_list|(
name|Kind
name|k
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|bool
name|CollectingStats
parameter_list|(
name|bool
name|Enable
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|PrintStats
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// isTemplateParameter - Determines whether this declaration is a
end_comment

begin_comment
comment|/// template parameter.
end_comment

begin_expr_stmt
name|bool
name|isTemplateParameter
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// isTemplateParameter - Determines whether this declaration is a
end_comment

begin_comment
comment|/// template parameter pack.
end_comment

begin_expr_stmt
name|bool
name|isTemplateParameterPack
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Whether this declaration is a function or function template.
end_comment

begin_expr_stmt
name|bool
name|isFunctionOrFunctionTemplate
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Changes the namespace of this declaration to reflect that it's
end_comment

begin_comment
comment|/// the object of a friend declaration.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// These declarations appear in the lexical context of the friending
end_comment

begin_comment
comment|/// class, but in the semantic context of the actual entity.  This property
end_comment

begin_comment
comment|/// applies only to a specific decl object;  other redeclarations of the
end_comment

begin_comment
comment|/// same entity may not (and probably don't) share this property.
end_comment

begin_function
name|void
name|setObjectOfFriendDecl
parameter_list|(
name|bool
name|PreviouslyDeclared
parameter_list|)
block|{
name|unsigned
name|OldNS
init|=
name|IdentifierNamespace
decl_stmt|;
name|assert
argument_list|(
operator|(
name|OldNS
operator|==
name|IDNS_Tag
operator|||
name|OldNS
operator|==
name|IDNS_Ordinary
operator|||
name|OldNS
operator|==
operator|(
name|IDNS_Tag
operator||
name|IDNS_Ordinary
operator|)
operator|)
operator|&&
literal|"unsupported namespace for undeclared friend"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|PreviouslyDeclared
condition|)
name|IdentifierNamespace
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|OldNS
operator|==
name|IDNS_Tag
condition|)
name|IdentifierNamespace
operator||=
name|IDNS_TagFriend
expr_stmt|;
else|else
name|IdentifierNamespace
operator||=
name|IDNS_OrdinaryFriend
expr_stmt|;
block|}
end_function

begin_enum
enum|enum
name|FriendObjectKind
block|{
name|FOK_None
block|,
comment|// not a friend object
name|FOK_Declared
block|,
comment|// a friend of a previously-declared entity
name|FOK_Undeclared
comment|// a friend of a previously-undeclared entity
block|}
enum|;
end_enum

begin_comment
comment|/// \brief Determines whether this declaration is the object of a
end_comment

begin_comment
comment|/// friend declaration and, if so, what kind.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// There is currently no direct way to find the associated FriendDecl.
end_comment

begin_expr_stmt
name|FriendObjectKind
name|getFriendObjectKind
argument_list|()
specifier|const
block|{
name|unsigned
name|mask
operator|=
operator|(
name|IdentifierNamespace
operator|&
operator|(
name|IDNS_TagFriend
operator||
name|IDNS_OrdinaryFriend
operator|)
operator|)
block|;
if|if
condition|(
operator|!
name|mask
condition|)
return|return
name|FOK_None
return|;
end_expr_stmt

begin_return
return|return
operator|(
name|IdentifierNamespace
operator|&
operator|(
name|IDNS_Tag
operator||
name|IDNS_Ordinary
operator|)
condition|?
name|FOK_Declared
else|:
name|FOK_Undeclared
operator|)
return|;
end_return

begin_comment
unit|}
comment|// Implement isa/cast/dyncast/etc.
end_comment

begin_function
unit|static
name|bool
name|classof
parameter_list|(
specifier|const
name|Decl
modifier|*
parameter_list|)
block|{
return|return
name|true
return|;
block|}
end_function

begin_function_decl
specifier|static
name|DeclContext
modifier|*
name|castToDeclContext
parameter_list|(
specifier|const
name|Decl
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|Decl
modifier|*
name|castFromDeclContext
parameter_list|(
specifier|const
name|DeclContext
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Destroy - Call destructors and release memory.
end_comment

begin_function_decl
name|virtual
name|void
name|Destroy
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|print
argument_list|(
name|llvm
operator|::
name|raw_ostream
operator|&
name|Out
argument_list|,
name|unsigned
name|Indentation
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print
argument_list|(
name|llvm
operator|::
name|raw_ostream
operator|&
name|Out
argument_list|,
specifier|const
name|PrintingPolicy
operator|&
name|Policy
argument_list|,
name|unsigned
name|Indentation
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|printGroup
argument_list|(
name|Decl
operator|*
operator|*
name|Begin
argument_list|,
name|unsigned
name|NumDecls
argument_list|,
name|llvm
operator|::
name|raw_ostream
operator|&
name|Out
argument_list|,
specifier|const
name|PrintingPolicy
operator|&
name|Policy
argument_list|,
name|unsigned
name|Indentation
operator|=
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
specifier|const
name|Attr
operator|*
name|getAttrsImpl
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// PrettyStackTraceDecl - If a crash occurs, indicate that it happened when
end_comment

begin_comment
comment|/// doing something to a specific decl.
end_comment

begin_decl_stmt
name|class
name|PrettyStackTraceDecl
range|:
name|public
name|llvm
operator|::
name|PrettyStackTraceEntry
block|{
specifier|const
name|Decl
operator|*
name|TheDecl
block|;
name|SourceLocation
name|Loc
block|;
name|SourceManager
operator|&
name|SM
block|;
specifier|const
name|char
operator|*
name|Message
block|;
name|public
operator|:
name|PrettyStackTraceDecl
argument_list|(
argument|const Decl *theDecl
argument_list|,
argument|SourceLocation L
argument_list|,
argument|SourceManager&sm
argument_list|,
argument|const char *Msg
argument_list|)
operator|:
name|TheDecl
argument_list|(
name|theDecl
argument_list|)
block|,
name|Loc
argument_list|(
name|L
argument_list|)
block|,
name|SM
argument_list|(
name|sm
argument_list|)
block|,
name|Message
argument_list|(
argument|Msg
argument_list|)
block|{}
name|virtual
name|void
name|print
argument_list|(
argument|llvm::raw_ostream&OS
argument_list|)
specifier|const
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// DeclContext - This is used only as base class of specific decl types that
end_comment

begin_comment
comment|/// can act as declaration contexts. These decls are (only the top classes
end_comment

begin_comment
comment|/// that directly derive from DeclContext are mentioned, not their subclasses):
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   TranslationUnitDecl
end_comment

begin_comment
comment|///   NamespaceDecl
end_comment

begin_comment
comment|///   FunctionDecl
end_comment

begin_comment
comment|///   TagDecl
end_comment

begin_comment
comment|///   ObjCMethodDecl
end_comment

begin_comment
comment|///   ObjCContainerDecl
end_comment

begin_comment
comment|///   LinkageSpecDecl
end_comment

begin_comment
comment|///   BlockDecl
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|DeclContext
block|{
comment|/// DeclKind - This indicates which class this is.
name|Decl
operator|::
name|Kind
name|DeclKind
operator|:
literal|8
expr_stmt|;
comment|/// \brief Whether this declaration context also has some external
comment|/// storage that contains additional declarations that are lexically
comment|/// part of this context.
name|mutable
name|bool
name|ExternalLexicalStorage
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether this declaration context also has some external
comment|/// storage that contains additional declarations that are visible
comment|/// in this context.
name|mutable
name|bool
name|ExternalVisibleStorage
range|:
literal|1
decl_stmt|;
comment|/// \brief Pointer to the data structure used to lookup declarations
comment|/// within this context, which is a DenseMap<DeclarationName,
comment|/// StoredDeclsList>.
name|mutable
name|void
modifier|*
name|LookupPtr
decl_stmt|;
comment|/// FirstDecl - The first declaration stored within this declaration
comment|/// context.
name|mutable
name|Decl
modifier|*
name|FirstDecl
decl_stmt|;
comment|/// LastDecl - The last declaration stored within this declaration
comment|/// context. FIXME: We could probably cache this value somewhere
comment|/// outside of the DeclContext, to reduce the size of DeclContext by
comment|/// another pointer.
name|mutable
name|Decl
modifier|*
name|LastDecl
decl_stmt|;
name|protected
label|:
name|DeclContext
argument_list|(
argument|Decl::Kind K
argument_list|)
block|:
name|DeclKind
argument_list|(
name|K
argument_list|)
operator|,
name|ExternalLexicalStorage
argument_list|(
name|false
argument_list|)
operator|,
name|ExternalVisibleStorage
argument_list|(
name|false
argument_list|)
operator|,
name|LookupPtr
argument_list|(
literal|0
argument_list|)
operator|,
name|FirstDecl
argument_list|(
literal|0
argument_list|)
operator|,
name|LastDecl
argument_list|(
literal|0
argument_list|)
block|{ }
name|void
name|DestroyDecls
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|)
expr_stmt|;
name|public
label|:
operator|~
name|DeclContext
argument_list|()
expr_stmt|;
name|Decl
operator|::
name|Kind
name|getDeclKind
argument_list|()
specifier|const
block|{
return|return
name|DeclKind
return|;
block|}
specifier|const
name|char
operator|*
name|getDeclKindName
argument_list|()
specifier|const
expr_stmt|;
comment|/// getParent - Returns the containing DeclContext.
name|DeclContext
modifier|*
name|getParent
parameter_list|()
block|{
return|return
name|cast
operator|<
name|Decl
operator|>
operator|(
name|this
operator|)
operator|->
name|getDeclContext
argument_list|()
return|;
block|}
specifier|const
name|DeclContext
operator|*
name|getParent
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|DeclContext
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getParent
argument_list|()
return|;
block|}
comment|/// getLexicalParent - Returns the containing lexical DeclContext. May be
comment|/// different from getParent, e.g.:
comment|///
comment|///   namespace A {
comment|///      struct S;
comment|///   }
comment|///   struct A::S {}; // getParent() == namespace 'A'
comment|///                   // getLexicalParent() == translation unit
comment|///
name|DeclContext
modifier|*
name|getLexicalParent
parameter_list|()
block|{
return|return
name|cast
operator|<
name|Decl
operator|>
operator|(
name|this
operator|)
operator|->
name|getLexicalDeclContext
argument_list|()
return|;
block|}
specifier|const
name|DeclContext
operator|*
name|getLexicalParent
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|DeclContext
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getLexicalParent
argument_list|()
return|;
block|}
name|DeclContext
modifier|*
name|getLookupParent
parameter_list|()
function_decl|;
specifier|const
name|DeclContext
operator|*
name|getLookupParent
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|DeclContext
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getLookupParent
argument_list|()
return|;
block|}
name|ASTContext
operator|&
name|getParentASTContext
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Decl
operator|>
operator|(
name|this
operator|)
operator|->
name|getASTContext
argument_list|()
return|;
block|}
name|bool
name|isFunctionOrMethod
argument_list|()
specifier|const
block|{
switch|switch
condition|(
name|DeclKind
condition|)
block|{
case|case
name|Decl
operator|::
name|Block
case|:
case|case
name|Decl
operator|::
name|ObjCMethod
case|:
return|return
name|true
return|;
default|default:
return|return
name|DeclKind
operator|>=
name|Decl
operator|::
name|FunctionFirst
operator|&&
name|DeclKind
operator|<=
name|Decl
operator|::
name|FunctionLast
return|;
block|}
block|}
name|bool
name|isFileContext
argument_list|()
specifier|const
block|{
return|return
name|DeclKind
operator|==
name|Decl
operator|::
name|TranslationUnit
operator|||
name|DeclKind
operator|==
name|Decl
operator|::
name|Namespace
return|;
block|}
name|bool
name|isTranslationUnit
argument_list|()
specifier|const
block|{
return|return
name|DeclKind
operator|==
name|Decl
operator|::
name|TranslationUnit
return|;
block|}
name|bool
name|isRecord
argument_list|()
specifier|const
block|{
return|return
name|DeclKind
operator|>=
name|Decl
operator|::
name|RecordFirst
operator|&&
name|DeclKind
operator|<=
name|Decl
operator|::
name|RecordLast
return|;
block|}
name|bool
name|isNamespace
argument_list|()
specifier|const
block|{
return|return
name|DeclKind
operator|==
name|Decl
operator|::
name|Namespace
return|;
block|}
comment|/// \brief Determines whether this context is dependent on a
comment|/// template parameter.
name|bool
name|isDependentContext
argument_list|()
specifier|const
expr_stmt|;
comment|/// isTransparentContext - Determines whether this context is a
comment|/// "transparent" context, meaning that the members declared in this
comment|/// context are semantically declared in the nearest enclosing
comment|/// non-transparent (opaque) context but are lexically declared in
comment|/// this context. For example, consider the enumerators of an
comment|/// enumeration type:
comment|/// @code
comment|/// enum E {
comment|///   Val1
comment|/// };
comment|/// @endcode
comment|/// Here, E is a transparent context, so its enumerator (Val1) will
comment|/// appear (semantically) that it is in the same context of E.
comment|/// Examples of transparent contexts include: enumerations (except for
comment|/// C++0x scoped enums), C++ linkage specifications, and C++0x
comment|/// inline namespaces.
name|bool
name|isTransparentContext
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determine whether this declaration context is equivalent
comment|/// to the declaration context DC.
name|bool
name|Equals
parameter_list|(
name|DeclContext
modifier|*
name|DC
parameter_list|)
block|{
return|return
name|this
operator|->
name|getPrimaryContext
argument_list|()
operator|==
name|DC
operator|->
name|getPrimaryContext
argument_list|()
return|;
block|}
comment|/// \brief Determine whether this declaration context encloses the
comment|/// declaration context DC.
name|bool
name|Encloses
parameter_list|(
name|DeclContext
modifier|*
name|DC
parameter_list|)
function_decl|;
comment|/// getPrimaryContext - There may be many different
comment|/// declarations of the same entity (including forward declarations
comment|/// of classes, multiple definitions of namespaces, etc.), each with
comment|/// a different set of declarations. This routine returns the
comment|/// "primary" DeclContext structure, which will contain the
comment|/// information needed to perform name lookup into this context.
name|DeclContext
modifier|*
name|getPrimaryContext
parameter_list|()
function_decl|;
comment|/// getLookupContext - Retrieve the innermost non-transparent
comment|/// context of this context, which corresponds to the innermost
comment|/// location from which name lookup can find the entities in this
comment|/// context.
name|DeclContext
modifier|*
name|getLookupContext
parameter_list|()
function_decl|;
specifier|const
name|DeclContext
operator|*
name|getLookupContext
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|DeclContext
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getLookupContext
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the nearest enclosing namespace context.
name|DeclContext
modifier|*
name|getEnclosingNamespaceContext
parameter_list|()
function_decl|;
specifier|const
name|DeclContext
operator|*
name|getEnclosingNamespaceContext
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|DeclContext
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getEnclosingNamespaceContext
argument_list|()
return|;
block|}
comment|/// getNextContext - If this is a DeclContext that may have other
comment|/// DeclContexts that are semantically connected but syntactically
comment|/// different, such as C++ namespaces, this routine retrieves the
comment|/// next DeclContext in the link. Iteration through the chain of
comment|/// DeclContexts should begin at the primary DeclContext and
comment|/// continue until this function returns NULL. For example, given:
comment|/// @code
comment|/// namespace N {
comment|///   int x;
comment|/// }
comment|/// namespace N {
comment|///   int y;
comment|/// }
comment|/// @endcode
comment|/// The first occurrence of namespace N will be the primary
comment|/// DeclContext. Its getNextContext will return the second
comment|/// occurrence of namespace N.
name|DeclContext
modifier|*
name|getNextContext
parameter_list|()
function_decl|;
comment|/// decl_iterator - Iterates through the declarations stored
comment|/// within this context.
name|class
name|decl_iterator
block|{
comment|/// Current - The current declaration.
name|Decl
modifier|*
name|Current
decl_stmt|;
name|public
label|:
typedef|typedef
name|Decl
modifier|*
name|value_type
typedef|;
typedef|typedef
name|Decl
modifier|*
name|reference
typedef|;
typedef|typedef
name|Decl
modifier|*
name|pointer
typedef|;
typedef|typedef
name|std
operator|::
name|forward_iterator_tag
name|iterator_category
expr_stmt|;
typedef|typedef
name|std
operator|::
name|ptrdiff_t
name|difference_type
expr_stmt|;
name|decl_iterator
argument_list|()
operator|:
name|Current
argument_list|(
literal|0
argument_list|)
block|{ }
name|explicit
name|decl_iterator
argument_list|(
name|Decl
operator|*
name|C
argument_list|)
operator|:
name|Current
argument_list|(
argument|C
argument_list|)
block|{ }
name|reference
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|Current
return|;
block|}
name|pointer
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
name|Current
return|;
block|}
name|decl_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
name|Current
operator|=
name|Current
operator|->
name|getNextDeclInContext
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
name|decl_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|decl_iterator
name|tmp
argument_list|(
operator|*
name|this
argument_list|)
block|;
operator|++
operator|(
operator|*
name|this
operator|)
block|;
return|return
name|tmp
return|;
block|}
name|friend
name|bool
name|operator
operator|==
operator|(
name|decl_iterator
name|x
operator|,
name|decl_iterator
name|y
operator|)
block|{
return|return
name|x
operator|.
name|Current
operator|==
name|y
operator|.
name|Current
return|;
block|}
name|friend
name|bool
name|operator
operator|!=
operator|(
name|decl_iterator
name|x
operator|,
name|decl_iterator
name|y
operator|)
block|{
return|return
name|x
operator|.
name|Current
operator|!=
name|y
operator|.
name|Current
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// decls_begin/decls_end - Iterate over the declarations stored in
end_comment

begin_comment
comment|/// this context.
end_comment

begin_expr_stmt
name|decl_iterator
name|decls_begin
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|decl_iterator
name|decls_end
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|decls_empty
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// specific_decl_iterator - Iterates over a subrange of
end_comment

begin_comment
comment|/// declarations stored in a DeclContext, providing only those that
end_comment

begin_comment
comment|/// are of type SpecificDecl (or a class derived from it). This
end_comment

begin_comment
comment|/// iterator is used, for example, to provide iteration over just
end_comment

begin_comment
comment|/// the fields within a RecordDecl (with SpecificDecl = FieldDecl).
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|SpecificDecl
operator|>
name|class
name|specific_decl_iterator
block|{
comment|/// Current - The current, underlying declaration iterator, which
comment|/// will either be NULL or will point to a declaration of
comment|/// type SpecificDecl.
name|DeclContext
operator|::
name|decl_iterator
name|Current
block|;
comment|/// SkipToNextDecl - Advances the current position up to the next
comment|/// declaration of type SpecificDecl that also meets the criteria
comment|/// required by Acceptable.
name|void
name|SkipToNextDecl
argument_list|()
block|{
while|while
condition|(
operator|*
name|Current
operator|&&
operator|!
name|isa
operator|<
name|SpecificDecl
operator|>
operator|(
operator|*
name|Current
operator|)
condition|)
operator|++
name|Current
expr_stmt|;
block|}
name|public
operator|:
end_expr_stmt

begin_typedef
typedef|typedef
name|SpecificDecl
modifier|*
name|value_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|SpecificDecl
modifier|*
name|reference
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|SpecificDecl
modifier|*
name|pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|iterator_traits
operator|<
name|DeclContext
operator|::
name|decl_iterator
operator|>
operator|::
name|difference_type
name|difference_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|forward_iterator_tag
name|iterator_category
expr_stmt|;
end_typedef

begin_expr_stmt
name|specific_decl_iterator
argument_list|()
operator|:
name|Current
argument_list|()
block|{ }
comment|/// specific_decl_iterator - Construct a new iterator over a
comment|/// subset of the declarations the range [C,
comment|/// end-of-declarations). If A is non-NULL, it is a pointer to a
comment|/// member function of SpecificDecl that should return true for
comment|/// all of the SpecificDecl instances that will be in the subset
comment|/// of iterators. For example, if you want Objective-C instance
comment|/// methods, SpecificDecl will be ObjCMethodDecl and A will be
comment|///&ObjCMethodDecl::isInstanceMethod.
name|explicit
name|specific_decl_iterator
argument_list|(
argument|DeclContext::decl_iterator C
argument_list|)
operator|:
name|Current
argument_list|(
argument|C
argument_list|)
block|{
name|SkipToNextDecl
argument_list|()
block|;     }
name|reference
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|cast
operator|<
name|SpecificDecl
operator|>
operator|(
operator|*
name|Current
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|pointer
name|operator
operator|->
expr|(
end_expr_stmt

begin_expr_stmt
unit|)
specifier|const
block|{
return|return
name|cast
operator|<
name|SpecificDecl
operator|>
operator|(
operator|*
name|Current
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|specific_decl_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
operator|++
name|Current
block|;
name|SkipToNextDecl
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|specific_decl_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|specific_decl_iterator
name|tmp
argument_list|(
operator|*
name|this
argument_list|)
block|;
operator|++
operator|(
operator|*
name|this
operator|)
block|;
return|return
name|tmp
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|specific_decl_iterator
operator|&
name|x
operator|,
specifier|const
name|specific_decl_iterator
operator|&
name|y
operator|)
block|{
return|return
name|x
operator|.
name|Current
operator|==
name|y
operator|.
name|Current
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|specific_decl_iterator
operator|&
name|x
operator|,
specifier|const
name|specific_decl_iterator
operator|&
name|y
operator|)
block|{
return|return
name|x
operator|.
name|Current
operator|!=
name|y
operator|.
name|Current
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// \brief Iterates over a filtered subrange of declarations stored
end_comment

begin_comment
comment|/// in a DeclContext.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This iterator visits only those declarations that are of type
end_comment

begin_comment
comment|/// SpecificDecl (or a class derived from it) and that meet some
end_comment

begin_comment
comment|/// additional run-time criteria. This iterator is used, for
end_comment

begin_comment
comment|/// example, to provide access to the instance methods within an
end_comment

begin_comment
comment|/// Objective-C interface (with SpecificDecl = ObjCMethodDecl and
end_comment

begin_comment
comment|/// Acceptable = ObjCMethodDecl::isInstanceMethod).
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|SpecificDecl
operator|,
name|bool
argument_list|(
argument|SpecificDecl::*Acceptable
argument_list|)
operator|(
operator|)
specifier|const
operator|>
name|class
name|filtered_decl_iterator
block|{
comment|/// Current - The current, underlying declaration iterator, which
comment|/// will either be NULL or will point to a declaration of
comment|/// type SpecificDecl.
name|DeclContext
operator|::
name|decl_iterator
name|Current
block|;
comment|/// SkipToNextDecl - Advances the current position up to the next
comment|/// declaration of type SpecificDecl that also meets the criteria
comment|/// required by Acceptable.
name|void
name|SkipToNextDecl
argument_list|()
block|{
while|while
condition|(
operator|*
name|Current
operator|&&
operator|(
operator|!
name|isa
operator|<
name|SpecificDecl
operator|>
operator|(
operator|*
name|Current
operator|)
operator|||
operator|(
name|Acceptable
operator|&&
operator|!
operator|(
name|cast
operator|<
name|SpecificDecl
operator|>
operator|(
operator|*
name|Current
operator|)
operator|->*
name|Acceptable
operator|)
operator|(
operator|)
operator|)
operator|)
condition|)
operator|++
name|Current
expr_stmt|;
block|}
name|public
operator|:
end_expr_stmt

begin_typedef
typedef|typedef
name|SpecificDecl
modifier|*
name|value_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|SpecificDecl
modifier|*
name|reference
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|SpecificDecl
modifier|*
name|pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|iterator_traits
operator|<
name|DeclContext
operator|::
name|decl_iterator
operator|>
operator|::
name|difference_type
name|difference_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|forward_iterator_tag
name|iterator_category
expr_stmt|;
end_typedef

begin_expr_stmt
name|filtered_decl_iterator
argument_list|()
operator|:
name|Current
argument_list|()
block|{ }
comment|/// specific_decl_iterator - Construct a new iterator over a
comment|/// subset of the declarations the range [C,
comment|/// end-of-declarations). If A is non-NULL, it is a pointer to a
comment|/// member function of SpecificDecl that should return true for
comment|/// all of the SpecificDecl instances that will be in the subset
comment|/// of iterators. For example, if you want Objective-C instance
comment|/// methods, SpecificDecl will be ObjCMethodDecl and A will be
comment|///&ObjCMethodDecl::isInstanceMethod.
name|explicit
name|filtered_decl_iterator
argument_list|(
argument|DeclContext::decl_iterator C
argument_list|)
operator|:
name|Current
argument_list|(
argument|C
argument_list|)
block|{
name|SkipToNextDecl
argument_list|()
block|;     }
name|reference
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|cast
operator|<
name|SpecificDecl
operator|>
operator|(
operator|*
name|Current
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|pointer
name|operator
operator|->
expr|(
end_expr_stmt

begin_expr_stmt
unit|)
specifier|const
block|{
return|return
name|cast
operator|<
name|SpecificDecl
operator|>
operator|(
operator|*
name|Current
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|filtered_decl_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
operator|++
name|Current
block|;
name|SkipToNextDecl
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|filtered_decl_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|filtered_decl_iterator
name|tmp
argument_list|(
operator|*
name|this
argument_list|)
block|;
operator|++
operator|(
operator|*
name|this
operator|)
block|;
return|return
name|tmp
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|filtered_decl_iterator
operator|&
name|x
operator|,
specifier|const
name|filtered_decl_iterator
operator|&
name|y
operator|)
block|{
return|return
name|x
operator|.
name|Current
operator|==
name|y
operator|.
name|Current
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|filtered_decl_iterator
operator|&
name|x
operator|,
specifier|const
name|filtered_decl_iterator
operator|&
name|y
operator|)
block|{
return|return
name|x
operator|.
name|Current
operator|!=
name|y
operator|.
name|Current
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// @brief Add the declaration D into this context.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine should be invoked when the declaration D has first
end_comment

begin_comment
comment|/// been declared, to place D into the context where it was
end_comment

begin_comment
comment|/// (lexically) defined. Every declaration must be added to one
end_comment

begin_comment
comment|/// (and only one!) context, where it can be visited via
end_comment

begin_comment
comment|/// [decls_begin(), decls_end()). Once a declaration has been added
end_comment

begin_comment
comment|/// to its lexical context, the corresponding DeclContext owns the
end_comment

begin_comment
comment|/// declaration.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If D is also a NamedDecl, it will be made visible within its
end_comment

begin_comment
comment|/// semantic context via makeDeclVisibleInContext.
end_comment

begin_function_decl
name|void
name|addDecl
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// @brief Add the declaration D to this context without modifying
end_comment

begin_comment
comment|/// any lookup tables.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is useful for some operations in dependent contexts where
end_comment

begin_comment
comment|/// the semantic context might not be dependent;  this basically
end_comment

begin_comment
comment|/// only happens with friends.
end_comment

begin_function_decl
name|void
name|addHiddenDecl
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// @brief Removes a declaration from this context.
end_comment

begin_function_decl
name|void
name|removeDecl
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// lookup_iterator - An iterator that provides access to the results
end_comment

begin_comment
comment|/// of looking up a name within this context.
end_comment

begin_typedef
typedef|typedef
name|NamedDecl
modifier|*
modifier|*
name|lookup_iterator
typedef|;
end_typedef

begin_comment
comment|/// lookup_const_iterator - An iterator that provides non-mutable
end_comment

begin_comment
comment|/// access to the results of lookup up a name within this context.
end_comment

begin_typedef
typedef|typedef
name|NamedDecl
modifier|*
specifier|const
modifier|*
name|lookup_const_iterator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|lookup_iterator
operator|,
name|lookup_iterator
operator|>
name|lookup_result
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|lookup_const_iterator
operator|,
name|lookup_const_iterator
operator|>
name|lookup_const_result
expr_stmt|;
end_typedef

begin_comment
comment|/// lookup - Find the declarations (if any) with the given Name in
end_comment

begin_comment
comment|/// this context. Returns a range of iterators that contains all of
end_comment

begin_comment
comment|/// the declarations with this name, with object, function, member,
end_comment

begin_comment
comment|/// and enumerator names preceding any tag name. Note that this
end_comment

begin_comment
comment|/// routine will not look into parent contexts.
end_comment

begin_function_decl
name|lookup_result
name|lookup
parameter_list|(
name|DeclarationName
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|lookup_const_result
name|lookup
argument_list|(
name|DeclarationName
name|Name
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// @brief Makes a declaration visible within this context.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine makes the declaration D visible to name lookup
end_comment

begin_comment
comment|/// within this context and, if this is a transparent context,
end_comment

begin_comment
comment|/// within its parent contexts up to the first enclosing
end_comment

begin_comment
comment|/// non-transparent context. Making a declaration visible within a
end_comment

begin_comment
comment|/// context does not transfer ownership of a declaration, and a
end_comment

begin_comment
comment|/// declaration can be visible in many contexts that aren't its
end_comment

begin_comment
comment|/// lexical context.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If D is a redeclaration of an existing declaration that is
end_comment

begin_comment
comment|/// visible from this context, as determined by
end_comment

begin_comment
comment|/// NamedDecl::declarationReplaces, the previous declaration will be
end_comment

begin_comment
comment|/// replaced with D.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param Recoverable true if it's okay to not add this decl to
end_comment

begin_comment
comment|/// the lookup tables because it can be easily recovered by walking
end_comment

begin_comment
comment|/// the declaration chains.
end_comment

begin_function_decl
name|void
name|makeDeclVisibleInContext
parameter_list|(
name|NamedDecl
modifier|*
name|D
parameter_list|,
name|bool
name|Recoverable
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// udir_iterator - Iterates through the using-directives stored
end_comment

begin_comment
comment|/// within this context.
end_comment

begin_typedef
typedef|typedef
name|UsingDirectiveDecl
modifier|*
specifier|const
modifier|*
name|udir_iterator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|udir_iterator
operator|,
name|udir_iterator
operator|>
name|udir_iterator_range
expr_stmt|;
end_typedef

begin_expr_stmt
name|udir_iterator_range
name|getUsingDirectives
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|udir_iterator
name|using_directives_begin
argument_list|()
specifier|const
block|{
return|return
name|getUsingDirectives
argument_list|()
operator|.
name|first
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|udir_iterator
name|using_directives_end
argument_list|()
specifier|const
block|{
return|return
name|getUsingDirectives
argument_list|()
operator|.
name|second
return|;
block|}
end_expr_stmt

begin_comment
comment|// Low-level accessors
end_comment

begin_comment
comment|/// \brief Retrieve the internal representation of the lookup structure.
end_comment

begin_expr_stmt
name|void
operator|*
name|getLookupPtr
argument_list|()
specifier|const
block|{
return|return
name|LookupPtr
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Whether this DeclContext has external storage containing
end_comment

begin_comment
comment|/// additional declarations that are lexically in this context.
end_comment

begin_expr_stmt
name|bool
name|hasExternalLexicalStorage
argument_list|()
specifier|const
block|{
return|return
name|ExternalLexicalStorage
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief State whether this DeclContext has external storage for
end_comment

begin_comment
comment|/// declarations lexically in this context.
end_comment

begin_function
name|void
name|setHasExternalLexicalStorage
parameter_list|(
name|bool
name|ES
init|=
name|true
parameter_list|)
block|{
name|ExternalLexicalStorage
operator|=
name|ES
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Whether this DeclContext has external storage containing
end_comment

begin_comment
comment|/// additional declarations that are visible in this context.
end_comment

begin_expr_stmt
name|bool
name|hasExternalVisibleStorage
argument_list|()
specifier|const
block|{
return|return
name|ExternalVisibleStorage
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief State whether this DeclContext has external storage for
end_comment

begin_comment
comment|/// declarations visible in this context.
end_comment

begin_function
name|void
name|setHasExternalVisibleStorage
parameter_list|(
name|bool
name|ES
init|=
name|true
parameter_list|)
block|{
name|ExternalVisibleStorage
operator|=
name|ES
expr_stmt|;
block|}
end_function

begin_function_decl
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|DeclContext
modifier|*
name|D
parameter_list|)
block|{
return|return
name|true
return|;
block|}
end_function

begin_define
define|#
directive|define
name|DECL_CONTEXT
parameter_list|(
name|Name
parameter_list|)
define|\
value|static bool classof(const Name##Decl *D) { return true; }
end_define

begin_include
include|#
directive|include
file|"clang/AST/DeclNodes.def"
end_include

begin_expr_stmt
name|void
name|dumpDeclContext
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|void
name|LoadLexicalDeclsFromExternalStorage
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|void
name|LoadVisibleDeclsFromExternalStorage
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|buildLookup
parameter_list|(
name|DeclContext
modifier|*
name|DCtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|makeDeclVisibleInContextImpl
parameter_list|(
name|NamedDecl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
unit|};
specifier|inline
name|bool
name|Decl
operator|::
name|isTemplateParameter
argument_list|()
specifier|const
block|{
return|return
name|getKind
argument_list|()
operator|==
name|TemplateTypeParm
operator|||
name|getKind
argument_list|()
operator|==
name|NonTypeTemplateParm
operator|||
name|getKind
argument_list|()
operator|==
name|TemplateTemplateParm
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// end clang.
end_comment

begin_macro
unit|namespace
name|llvm
end_macro

begin_block
block|{
comment|/// Implement a isa_impl_wrap specialization to check whether a DeclContext is
comment|/// a specific Decl.
name|template
operator|<
name|class
name|ToTy
operator|>
expr|struct
name|isa_impl_wrap
operator|<
name|ToTy
operator|,
specifier|const
operator|::
name|clang
operator|::
name|DeclContext
operator|,
specifier|const
operator|::
name|clang
operator|::
name|DeclContext
operator|>
block|{
specifier|static
name|bool
name|doit
argument_list|(
argument|const ::clang::DeclContext&Val
argument_list|)
block|{
return|return
name|ToTy
operator|::
name|classof
argument_list|(
operator|::
name|clang
operator|::
name|Decl
operator|::
name|castFromDeclContext
argument_list|(
operator|&
name|Val
argument_list|)
argument_list|)
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
name|class
name|ToTy
operator|>
expr|struct
name|isa_impl_wrap
operator|<
name|ToTy
operator|,
operator|::
name|clang
operator|::
name|DeclContext
operator|,
operator|::
name|clang
operator|::
name|DeclContext
operator|>
operator|:
name|public
name|isa_impl_wrap
operator|<
name|ToTy
operator|,
specifier|const
operator|::
name|clang
operator|::
name|DeclContext
operator|,
specifier|const
operator|::
name|clang
operator|::
name|DeclContext
operator|>
block|{}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Implement cast_convert_val for Decl -> DeclContext conversions.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|FromTy
operator|>
expr|struct
name|cast_convert_val
operator|<
operator|::
name|clang
operator|::
name|DeclContext
operator|,
name|FromTy
operator|,
name|FromTy
operator|>
block|{
specifier|static
operator|::
name|clang
operator|::
name|DeclContext
operator|&
name|doit
argument_list|(
argument|const FromTy&Val
argument_list|)
block|{
return|return
operator|*
name|FromTy
operator|::
name|castToDeclContext
argument_list|(
operator|&
name|Val
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|FromTy
operator|>
expr|struct
name|cast_convert_val
operator|<
operator|::
name|clang
operator|::
name|DeclContext
operator|,
name|FromTy
operator|*
operator|,
name|FromTy
operator|*
operator|>
block|{
specifier|static
operator|::
name|clang
operator|::
name|DeclContext
operator|*
name|doit
argument_list|(
argument|const FromTy *Val
argument_list|)
block|{
return|return
name|FromTy
operator|::
name|castToDeclContext
argument_list|(
name|Val
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|FromTy
operator|>
expr|struct
name|cast_convert_val
operator|<
specifier|const
operator|::
name|clang
operator|::
name|DeclContext
operator|,
name|FromTy
operator|,
name|FromTy
operator|>
block|{
specifier|static
specifier|const
operator|::
name|clang
operator|::
name|DeclContext
operator|&
name|doit
argument_list|(
argument|const FromTy&Val
argument_list|)
block|{
return|return
operator|*
name|FromTy
operator|::
name|castToDeclContext
argument_list|(
operator|&
name|Val
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|FromTy
operator|>
expr|struct
name|cast_convert_val
operator|<
specifier|const
operator|::
name|clang
operator|::
name|DeclContext
operator|,
name|FromTy
operator|*
operator|,
name|FromTy
operator|*
operator|>
block|{
specifier|static
specifier|const
operator|::
name|clang
operator|::
name|DeclContext
operator|*
name|doit
argument_list|(
argument|const FromTy *Val
argument_list|)
block|{
return|return
name|FromTy
operator|::
name|castToDeclContext
argument_list|(
name|Val
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// Implement cast_convert_val for DeclContext -> Decl conversions.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ToTy
operator|>
expr|struct
name|cast_convert_val
operator|<
name|ToTy
operator|,
specifier|const
operator|::
name|clang
operator|::
name|DeclContext
operator|,
specifier|const
operator|::
name|clang
operator|::
name|DeclContext
operator|>
block|{
specifier|static
name|ToTy
operator|&
name|doit
argument_list|(
argument|const ::clang::DeclContext&Val
argument_list|)
block|{
return|return
operator|*
name|reinterpret_cast
operator|<
name|ToTy
operator|*
operator|>
operator|(
name|ToTy
operator|::
name|castFromDeclContext
argument_list|(
operator|&
name|Val
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|ToTy
operator|>
expr|struct
name|cast_convert_val
operator|<
name|ToTy
operator|,
operator|::
name|clang
operator|::
name|DeclContext
operator|,
operator|::
name|clang
operator|::
name|DeclContext
operator|>
operator|:
name|public
name|cast_convert_val
operator|<
name|ToTy
operator|,
specifier|const
operator|::
name|clang
operator|::
name|DeclContext
operator|,
specifier|const
operator|::
name|clang
operator|::
name|DeclContext
operator|>
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ToTy
operator|>
expr|struct
name|cast_convert_val
operator|<
name|ToTy
operator|,
specifier|const
operator|::
name|clang
operator|::
name|DeclContext
operator|*
operator|,
specifier|const
operator|::
name|clang
operator|::
name|DeclContext
operator|*
operator|>
block|{
specifier|static
name|ToTy
operator|*
name|doit
argument_list|(
argument|const ::clang::DeclContext *Val
argument_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|ToTy
operator|*
operator|>
operator|(
name|ToTy
operator|::
name|castFromDeclContext
argument_list|(
name|Val
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|ToTy
operator|>
expr|struct
name|cast_convert_val
operator|<
name|ToTy
operator|,
operator|::
name|clang
operator|::
name|DeclContext
operator|*
operator|,
operator|::
name|clang
operator|::
name|DeclContext
operator|*
operator|>
operator|:
name|public
name|cast_convert_val
operator|<
name|ToTy
operator|,
specifier|const
operator|::
name|clang
operator|::
name|DeclContext
operator|*
operator|,
specifier|const
operator|::
name|clang
operator|::
name|DeclContext
operator|*
operator|>
block|{}
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

