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
name|class
name|StoredDeclsMap
decl_stmt|;
name|class
name|DependentDiagnostic
decl_stmt|;
name|class
name|ASTMutationListener
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
comment|/// \brief Captures the result of checking the availability of a
comment|/// declaration.
enum|enum
name|AvailabilityResult
block|{
name|AR_Available
init|=
literal|0
block|,
name|AR_NotYetIntroduced
block|,
name|AR_Deprecated
block|,
name|AR_Unavailable
block|}
enum|;
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
name|DERIVED
parameter_list|,
name|BASE
parameter_list|)
value|DERIVED,
define|#
directive|define
name|ABSTRACT_DECL
parameter_list|(
name|DECL
parameter_list|)
define|#
directive|define
name|DECL_RANGE
parameter_list|(
name|BASE
parameter_list|,
name|START
parameter_list|,
name|END
parameter_list|)
define|\
value|first##BASE = START, last##BASE = END,
define|#
directive|define
name|LAST_DECL_RANGE
parameter_list|(
name|BASE
parameter_list|,
name|START
parameter_list|,
name|END
parameter_list|)
define|\
value|first##BASE = START, last##BASE = END
include|#
directive|include
file|"clang/AST/DeclNodes.inc"
block|}
enum|;
comment|/// \brief A placeholder type used to construct an empty shell of a
comment|/// decl-derived type that will be filled in later (e.g., by some
comment|/// deserialization method).
struct|struct
name|EmptyShell
block|{ }
struct|;
comment|/// IdentifierNamespace - The different namespaces in which
comment|/// declarations may appear.  According to C99 6.2.3, there are
comment|/// four namespaces, labels, tags, members and ordinary
comment|/// identifiers.  C++ describes lookup completely differently:
comment|/// certain lookups merely "ignore" certain kinds of declarations,
comment|/// usually based on whether the declaration is of a type, etc.
comment|///
comment|/// These are meant as bitmasks, so that searches in
comment|/// C++ can look into the "tag" namespace during ordinary lookup.
comment|///
comment|/// Decl currently provides 15 bits of IDNS bits.
enum|enum
name|IdentifierNamespace
block|{
comment|/// Labels, declared with 'x:' and referenced with 'goto x'.
name|IDNS_Label
init|=
literal|0x0001
block|,
comment|/// Tags, declared with 'struct foo;' and referenced with
comment|/// 'struct foo'.  All tags are also types.  This is what
comment|/// elaborated-type-specifiers look for in C.
name|IDNS_Tag
init|=
literal|0x0002
block|,
comment|/// Types, declared with 'struct foo', typedefs, etc.
comment|/// This is what elaborated-type-specifiers look for in C++,
comment|/// but note that it's ill-formed to find a non-tag.
name|IDNS_Type
init|=
literal|0x0004
block|,
comment|/// Members, declared with object declarations within tag
comment|/// definitions.  In C, these can only be found by "qualified"
comment|/// lookup in member expressions.  In C++, they're found by
comment|/// normal lookup.
name|IDNS_Member
init|=
literal|0x0008
block|,
comment|/// Namespaces, declared with 'namespace foo {}'.
comment|/// Lookup for nested-name-specifiers find these.
name|IDNS_Namespace
init|=
literal|0x0010
block|,
comment|/// Ordinary names.  In C, everything that's not a label, tag,
comment|/// or member ends up here.
name|IDNS_Ordinary
init|=
literal|0x0020
block|,
comment|/// Objective C @protocol.
name|IDNS_ObjCProtocol
init|=
literal|0x0040
block|,
comment|/// This declaration is a friend function.  A friend function
comment|/// declaration is always in this namespace but may also be in
comment|/// IDNS_Ordinary if it was previously declared.
name|IDNS_OrdinaryFriend
init|=
literal|0x0080
block|,
comment|/// This declaration is a friend class.  A friend class
comment|/// declaration is always in this namespace but may also be in
comment|/// IDNS_Tag|IDNS_Type if it was previously declared.
name|IDNS_TagFriend
init|=
literal|0x0100
block|,
comment|/// This declaration is a using declaration.  A using declaration
comment|/// *introduces* a number of other declarations into the current
comment|/// scope, and those declarations use the IDNS of their targets,
comment|/// but the actual using declarations go in this namespace.
name|IDNS_Using
init|=
literal|0x0200
block|,
comment|/// This declaration is a C++ operator declared in a non-class
comment|/// context.  All such operators are also in IDNS_Ordinary.
comment|/// C++ lexical operator lookup looks for these.
name|IDNS_NonMemberOperator
init|=
literal|0x0400
block|}
enum|;
comment|/// ObjCDeclQualifier - 'Qualifiers' written next to the return and
comment|/// parameter types in method declarations.  Other than remembering
comment|/// them and mangling them into the method's signature string, these
comment|/// are ignored by the compiler; they are consumed by certain
comment|/// remote-messaging frameworks.
comment|///
comment|/// in, inout, and out are mutually exclusive and apply only to
comment|/// method parameters.  bycopy and byref are mutually exclusive and
comment|/// apply only to method parameters (?).  oneway applies only to
comment|/// results.  All of these expect their corresponding parameter to
comment|/// have a particular type.  None of this is currently enforced by
comment|/// clang.
comment|///
comment|/// This should be kept in sync with ObjCDeclSpec::ObjCDeclQualifier.
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
comment|/// Loc - The location of this decl.
name|SourceLocation
name|Loc
decl_stmt|;
comment|/// DeclKind - This indicates which class this is.
name|unsigned
name|DeclKind
range|:
literal|8
decl_stmt|;
comment|/// InvalidDecl - This indicates a semantic error occurred.
name|unsigned
name|InvalidDecl
range|:
literal|1
decl_stmt|;
comment|/// HasAttrs - This indicates whether the decl has attributes or not.
name|unsigned
name|HasAttrs
range|:
literal|1
decl_stmt|;
comment|/// Implicit - Whether this declaration was implicitly generated by
comment|/// the implementation rather than explicitly written by the user.
name|unsigned
name|Implicit
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether this declaration was "used", meaning that a definition is
comment|/// required.
name|unsigned
name|Used
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether this declaration was "referenced".
comment|/// The difference with 'Used' is whether the reference appears in a
comment|/// evaluated context or not, e.g. functions used in uninstantiated templates
comment|/// are regarded as "referenced" but not "used".
name|unsigned
name|Referenced
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
comment|/// PCHLevel - the "level" of AST file from which this declaration was built.
name|unsigned
name|PCHLevel
range|:
literal|2
decl_stmt|;
comment|/// ChangedAfterLoad - if this declaration has changed since being loaded
name|unsigned
name|ChangedAfterLoad
range|:
literal|1
decl_stmt|;
comment|/// IdentifierNamespace - This specifies what IDNS_* namespace this lives in.
name|unsigned
name|IdentifierNamespace
range|:
literal|12
decl_stmt|;
comment|/// \brief Whether the \c CachedLinkage field is active.
comment|///
comment|/// This field is only valid for NamedDecls subclasses.
name|mutable
name|unsigned
name|HasCachedLinkage
range|:
literal|1
decl_stmt|;
comment|/// \brief If \c HasCachedLinkage, the linkage of this declaration.
comment|///
comment|/// This field is only valid for NamedDecls subclasses.
name|mutable
name|unsigned
name|CachedLinkage
range|:
literal|2
decl_stmt|;
name|private
label|:
name|void
name|CheckAccessDeclContext
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
name|Decl
argument_list|(
argument|Kind DK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|)
block|:
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
name|Referenced
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
name|ChangedAfterLoad
argument_list|(
name|false
argument_list|)
operator|,
name|IdentifierNamespace
argument_list|(
name|getIdentifierNamespaceForKind
argument_list|(
name|DK
argument_list|)
argument_list|)
operator|,
name|HasCachedLinkage
argument_list|(
literal|0
argument_list|)
block|{
if|if
condition|(
name|Decl
operator|::
name|CollectingStats
argument_list|()
condition|)
name|add
argument_list|(
name|DK
argument_list|)
expr_stmt|;
block|}
name|Decl
argument_list|(
argument|Kind DK
argument_list|,
argument|EmptyShell Empty
argument_list|)
block|:
name|NextDeclInContext
argument_list|(
literal|0
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
name|Referenced
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
name|ChangedAfterLoad
argument_list|(
name|false
argument_list|)
operator|,
name|IdentifierNamespace
argument_list|(
name|getIdentifierNamespaceForKind
argument_list|(
name|DK
argument_list|)
argument_list|)
operator|,
name|HasCachedLinkage
argument_list|(
literal|0
argument_list|)
block|{
if|if
condition|(
name|Decl
operator|::
name|CollectingStats
argument_list|()
condition|)
name|add
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
name|static_cast
operator|<
name|Kind
operator|>
operator|(
name|DeclKind
operator|)
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
comment|/// Finds the innermost non-closure context of this declaration.
comment|/// That is, walk out the DeclContext chain, skipping any blocks.
name|DeclContext
modifier|*
name|getNonClosureContext
parameter_list|()
function_decl|;
specifier|const
name|DeclContext
operator|*
name|getNonClosureContext
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
name|getNonClosureContext
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
ifndef|#
directive|ifndef
name|NDEBUG
name|CheckAccessDeclContext
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
name|AccessSpecifier
name|getAccess
argument_list|()
specifier|const
block|{
ifndef|#
directive|ifndef
name|NDEBUG
name|CheckAccessDeclContext
argument_list|()
block|;
endif|#
directive|endif
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
name|setAttrs
parameter_list|(
specifier|const
name|AttrVec
modifier|&
name|Attrs
parameter_list|)
function_decl|;
name|AttrVec
modifier|&
name|getAttrs
parameter_list|()
block|{
return|return
name|const_cast
operator|<
name|AttrVec
operator|&
operator|>
operator|(
name|const_cast
operator|<
specifier|const
name|Decl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getAttrs
argument_list|()
operator|)
return|;
block|}
specifier|const
name|AttrVec
operator|&
name|getAttrs
argument_list|()
specifier|const
expr_stmt|;
name|void
name|swapAttrs
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
name|void
name|dropAttrs
parameter_list|()
function_decl|;
name|void
name|addAttr
parameter_list|(
name|Attr
modifier|*
name|A
parameter_list|)
block|{
if|if
condition|(
name|hasAttrs
argument_list|()
condition|)
name|getAttrs
argument_list|()
operator|.
name|push_back
argument_list|(
name|A
argument_list|)
expr_stmt|;
else|else
name|setAttrs
argument_list|(
name|AttrVec
argument_list|(
literal|1
argument_list|,
name|A
argument_list|)
argument_list|)
expr_stmt|;
block|}
typedef|typedef
name|AttrVec
operator|::
name|const_iterator
name|attr_iterator
expr_stmt|;
comment|// FIXME: Do not rely on iterators having comparable singular values.
comment|//        Note that this should error out if they do not.
name|attr_iterator
name|attr_begin
argument_list|()
specifier|const
block|{
return|return
name|hasAttrs
argument_list|()
operator|?
name|getAttrs
argument_list|()
operator|.
name|begin
argument_list|()
operator|:
literal|0
return|;
block|}
name|attr_iterator
name|attr_end
argument_list|()
specifier|const
block|{
return|return
name|hasAttrs
argument_list|()
operator|?
name|getAttrs
argument_list|()
operator|.
name|end
argument_list|()
operator|:
literal|0
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
name|specific_attr_iterator
operator|<
name|T
operator|>
name|specific_attr_begin
argument_list|()
specifier|const
block|{
return|return
name|specific_attr_iterator
operator|<
name|T
operator|>
operator|(
name|attr_begin
argument_list|()
operator|)
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
name|specific_attr_iterator
operator|<
name|T
operator|>
name|specific_attr_end
argument_list|()
specifier|const
block|{
return|return
name|specific_attr_iterator
operator|<
name|T
operator|>
operator|(
name|attr_end
argument_list|()
operator|)
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
name|T
operator|*
name|getAttr
argument_list|()
specifier|const
block|{
return|return
name|hasAttrs
argument_list|()
operator|?
name|getSpecificAttr
operator|<
name|T
operator|>
operator|(
name|getAttrs
argument_list|()
operator|)
operator|:
literal|0
return|;
block|}
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
name|hasAttrs
argument_list|()
operator|&&
name|hasSpecificAttr
operator|<
name|T
operator|>
operator|(
name|getAttrs
argument_list|()
operator|)
return|;
block|}
comment|/// getMaxAlignment - return the maximum alignment specified by attributes
comment|/// on this decl, 0 if there are none.
name|unsigned
name|getMaxAlignment
argument_list|()
specifier|const
block|{
return|return
name|hasAttrs
argument_list|()
operator|?
name|getMaxAttrAlignment
argument_list|(
name|getAttrs
argument_list|()
argument_list|,
name|getASTContext
argument_list|()
argument_list|)
operator|:
literal|0
return|;
block|}
comment|/// setInvalidDecl - Indicates the Decl had a semantic error. This
comment|/// allows for graceful error recovery.
name|void
name|setInvalidDecl
parameter_list|(
name|bool
name|Invalid
init|=
name|true
parameter_list|)
function_decl|;
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
comment|/// isImplicit - Indicates whether the declaration was implicitly
comment|/// generated by the implementation. If false, this declaration
comment|/// was written explicitly in the source code.
name|bool
name|isImplicit
argument_list|()
specifier|const
block|{
return|return
name|Implicit
return|;
block|}
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
comment|/// \brief Whether this declaration was used, meaning that a definition
comment|/// is required.
comment|///
comment|/// \param CheckUsedAttr When true, also consider the "used" attribute
comment|/// (in addition to the "used" bit set by \c setUsed()) when determining
comment|/// whether the function is used.
name|bool
name|isUsed
argument_list|(
name|bool
name|CheckUsedAttr
operator|=
name|true
argument_list|)
decl|const
decl_stmt|;
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
comment|/// \brief Whether this declaration was referenced.
name|bool
name|isReferenced
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setReferenced
parameter_list|(
name|bool
name|R
init|=
name|true
parameter_list|)
block|{
name|Referenced
operator|=
name|R
expr_stmt|;
block|}
comment|/// \brief Determine the availability of the given declaration.
comment|///
comment|/// This routine will determine the most restrictive availability of
comment|/// the given declaration (e.g., preferring 'unavailable' to
comment|/// 'deprecated').
comment|///
comment|/// \param Message If non-NULL and the result is not \c
comment|/// AR_Available, will be set to a (possibly empty) message
comment|/// describing why the declaration has not been introduced, is
comment|/// deprecated, or is unavailable.
name|AvailabilityResult
name|getAvailability
argument_list|(
name|std
operator|::
name|string
operator|*
name|Message
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Determine whether this declaration is marked 'deprecated'.
comment|///
comment|/// \param Message If non-NULL and the declaration is deprecated,
comment|/// this will be set to the message describing why the declaration
comment|/// was deprecated (which may be empty).
name|bool
name|isDeprecated
argument_list|(
name|std
operator|::
name|string
operator|*
name|Message
operator|=
literal|0
argument_list|)
decl|const
block|{
return|return
name|getAvailability
argument_list|(
name|Message
argument_list|)
operator|==
name|AR_Deprecated
return|;
block|}
comment|/// \brief Determine whether this declaration is marked 'unavailable'.
comment|///
comment|/// \param Message If non-NULL and the declaration is unavailable,
comment|/// this will be set to the message describing why the declaration
comment|/// was made unavailable (which may be empty).
name|bool
name|isUnavailable
argument_list|(
name|std
operator|::
name|string
operator|*
name|Message
operator|=
literal|0
argument_list|)
decl|const
block|{
return|return
name|getAvailability
argument_list|(
name|Message
argument_list|)
operator|==
name|AR_Unavailable
return|;
block|}
comment|/// \brief Determine whether this is a weak-imported symbol.
comment|///
comment|/// Weak-imported symbols are typically marked with the
comment|/// 'weak_import' attribute, but may also be marked with an
comment|/// 'availability' attribute where we're targing a platform prior to
comment|/// the introduction of this feature.
name|bool
name|isWeakImported
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determines whether this symbol can be weak-imported,
comment|/// e.g., whether it would be well-formed to add the weak_import
comment|/// attribute.
comment|///
comment|/// \param IsDefinition Set to \c true to indicate that this
comment|/// declaration cannot be weak-imported because it has a definition.
name|bool
name|canBeWeakImported
argument_list|(
name|bool
operator|&
name|IsDefinition
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Retrieve the level of precompiled header from which this
comment|/// declaration was generated.
comment|///
comment|/// The PCH level of a declaration describes where the declaration originated
comment|/// from. A PCH level of 0 indicates that the declaration was parsed from
comment|/// source. A PCH level of 1 indicates that the declaration was loaded from
comment|/// a top-level AST file. A PCH level 2 indicates that the declaration was
comment|/// loaded from a PCH file the AST file depends on, and so on.
name|unsigned
name|getPCHLevel
argument_list|()
specifier|const
block|{
return|return
name|PCHLevel
return|;
block|}
comment|/// \brief The maximum PCH level that any declaration may have.
specifier|static
specifier|const
name|unsigned
name|MaxPCHLevel
init|=
literal|3
decl_stmt|;
comment|/// \brief Set the PCH level of this declaration.
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
operator|<=
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
comment|/// \brief Query whether this declaration was changed in a significant way
comment|/// since being loaded from an AST file.
comment|///
comment|/// In an epic violation of layering, what is "significant" is entirely
comment|/// up to the serialization system, but implemented in AST and Sema.
name|bool
name|isChangedSinceDeserialization
argument_list|()
specifier|const
block|{
return|return
name|ChangedAfterLoad
return|;
block|}
comment|/// \brief Mark this declaration as having changed since deserialization, or
comment|/// reset the flag.
name|void
name|setChangedSinceDeserialization
parameter_list|(
name|bool
name|Changed
parameter_list|)
block|{
name|ChangedAfterLoad
operator|=
name|Changed
expr_stmt|;
block|}
name|unsigned
name|getIdentifierNamespace
argument_list|()
specifier|const
block|{
return|return
name|IdentifierNamespace
return|;
block|}
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
specifier|static
name|unsigned
name|getIdentifierNamespaceForKind
parameter_list|(
name|Kind
name|DK
parameter_list|)
function_decl|;
name|bool
name|hasTagIdentifierNamespace
argument_list|()
specifier|const
block|{
return|return
name|isTagIdentifierNamespace
argument_list|(
name|getIdentifierNamespace
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|isTagIdentifierNamespace
parameter_list|(
name|unsigned
name|NS
parameter_list|)
block|{
comment|// TagDecls have Tag and Type set and may also have TagFriend.
return|return
operator|(
name|NS
operator|&
operator|~
name|IDNS_TagFriend
operator|)
operator|==
operator|(
name|IDNS_Tag
operator||
name|IDNS_Type
operator|)
return|;
block|}
comment|/// getLexicalDeclContext - The declaration context where this Decl was
comment|/// lexically declared (LexicalDC). May be different from
comment|/// getDeclContext() (SemanticDC).
comment|/// e.g.:
comment|///
comment|///   namespace A {
comment|///      void f(); // SemanticDC == LexicalDC == 'namespace A'
comment|///   }
comment|///   void A::f(); // SemanticDC == namespace 'A'
comment|///                // LexicalDC == global namespace
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
name|virtual
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
comment|/// setDeclContext - Set both the semantic and lexical DeclContext
comment|/// to DC.
name|void
name|setDeclContext
parameter_list|(
name|DeclContext
modifier|*
name|DC
parameter_list|)
function_decl|;
name|void
name|setLexicalDeclContext
parameter_list|(
name|DeclContext
modifier|*
name|DC
parameter_list|)
function_decl|;
comment|/// isDefinedOutsideFunctionOrMethod - This predicate returns true if this
comment|/// scoped decl is defined outside the current function or method.  This is
comment|/// roughly global variables and functions, but also handles enums (which
comment|/// could be defined inside or outside a function etc).
name|bool
name|isDefinedOutsideFunctionOrMethod
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Retrieves the "canonical" declaration of the given declaration.
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
comment|/// \brief Whether this particular Decl is a canonical one.
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
name|protected
label|:
comment|/// \brief Returns the next redeclaration or itself if this is the only decl.
comment|///
comment|/// Decl subclasses that can be redeclared should override this method so that
comment|/// Decl::redecl_iterator can iterate over them.
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
name|public
label|:
comment|/// \brief Iterates through all the redeclarations of the same decl.
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
block|}
empty_stmt|;
comment|/// \brief Returns iterator for all the redeclarations of the same decl.
comment|/// It will iterate at least once (when this decl is the only one).
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
comment|/// getBody - If this Decl represents a declaration for a body of code,
comment|///  such as a function or method definition, this method returns the
comment|///  top-level Stmt* of that body.  Otherwise this method returns null.
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
comment|/// \brief Returns true if this Decl represents a declaration for a body of
comment|/// code, such as a function or method definition.
name|virtual
name|bool
name|hasBody
argument_list|()
specifier|const
block|{
return|return
name|getBody
argument_list|()
operator|!=
literal|0
return|;
block|}
comment|/// getBodyRBrace - Gets the right brace of the body, if a body exists.
comment|/// This works whether the body is a CompoundStmt or a CXXTryStmt.
name|SourceLocation
name|getBodyRBrace
argument_list|()
specifier|const
expr_stmt|;
comment|// global temp stats (until we have a per-module visitor)
specifier|static
name|void
name|add
parameter_list|(
name|Kind
name|k
parameter_list|)
function_decl|;
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
specifier|static
name|void
name|PrintStats
parameter_list|()
function_decl|;
comment|/// isTemplateParameter - Determines whether this declaration is a
comment|/// template parameter.
name|bool
name|isTemplateParameter
argument_list|()
specifier|const
expr_stmt|;
comment|/// isTemplateParameter - Determines whether this declaration is a
comment|/// template parameter pack.
name|bool
name|isTemplateParameterPack
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Whether this declaration is a parameter pack.
name|bool
name|isParameterPack
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Whether this declaration is a function or function template.
name|bool
name|isFunctionOrFunctionTemplate
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Changes the namespace of this declaration to reflect that it's
comment|/// the object of a friend declaration.
comment|///
comment|/// These declarations appear in the lexical context of the friending
comment|/// class, but in the semantic context of the actual entity.  This property
comment|/// applies only to a specific decl object;  other redeclarations of the
comment|/// same entity may not (and probably don't) share this property.
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
operator|&
operator|(
name|IDNS_Tag
operator||
name|IDNS_Ordinary
operator||
name|IDNS_TagFriend
operator||
name|IDNS_OrdinaryFriend
operator|)
operator|)
operator|&&
literal|"namespace includes neither ordinary nor tag"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|!
operator|(
name|OldNS
operator|&
operator|~
operator|(
name|IDNS_Tag
operator||
name|IDNS_Ordinary
operator||
name|IDNS_Type
operator||
name|IDNS_TagFriend
operator||
name|IDNS_OrdinaryFriend
operator|)
operator|)
operator|&&
literal|"namespace includes other than ordinary or tag"
argument_list|)
expr_stmt|;
name|IdentifierNamespace
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|OldNS
operator|&
operator|(
name|IDNS_Tag
operator||
name|IDNS_TagFriend
operator|)
condition|)
block|{
name|IdentifierNamespace
operator||=
name|IDNS_TagFriend
expr_stmt|;
if|if
condition|(
name|PreviouslyDeclared
condition|)
name|IdentifierNamespace
operator||=
name|IDNS_Tag
operator||
name|IDNS_Type
expr_stmt|;
block|}
if|if
condition|(
name|OldNS
operator|&
operator|(
name|IDNS_Ordinary
operator||
name|IDNS_OrdinaryFriend
operator|)
condition|)
block|{
name|IdentifierNamespace
operator||=
name|IDNS_OrdinaryFriend
expr_stmt|;
if|if
condition|(
name|PreviouslyDeclared
condition|)
name|IdentifierNamespace
operator||=
name|IDNS_Ordinary
expr_stmt|;
block|}
block|}
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
comment|/// \brief Determines whether this declaration is the object of a
comment|/// friend declaration and, if so, what kind.
comment|///
comment|/// There is currently no direct way to find the associated FriendDecl.
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
block|}
end_block

begin_comment
comment|/// Specifies that this declaration is a C++ overloaded non-member.
end_comment

begin_function
name|void
name|setNonMemberOperator
parameter_list|()
block|{
name|assert
argument_list|(
name|getKind
argument_list|()
operator|==
name|Function
operator|||
name|getKind
argument_list|()
operator|==
name|FunctionTemplate
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|(
name|IdentifierNamespace
operator|&
name|IDNS_Ordinary
operator|)
operator|&&
literal|"visible non-member operators should be in ordinary namespace"
argument_list|)
expr_stmt|;
name|IdentifierNamespace
operator||=
name|IDNS_NonMemberOperator
expr_stmt|;
block|}
end_function

begin_comment
comment|// Implement isa/cast/dyncast/etc.
end_comment

begin_function
specifier|static
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

begin_function
specifier|static
name|bool
name|classofKind
parameter_list|(
name|Kind
name|K
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

begin_expr_stmt
name|void
name|dumpXML
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|dumpXML
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

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|ASTMutationListener
operator|*
name|getASTMutationListener
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

begin_decl_stmt
name|class
name|DeclContextLookupResult
range|:
name|public
name|std
operator|::
name|pair
operator|<
name|NamedDecl
operator|*
operator|*
decl_stmt|,
name|NamedDecl
modifier|*
modifier|*
decl|>
block|{
name|public
label|:
name|DeclContextLookupResult
argument_list|(
name|NamedDecl
operator|*
operator|*
name|I
argument_list|,
name|NamedDecl
operator|*
operator|*
name|E
argument_list|)
operator|:
name|std
operator|::
name|pair
operator|<
name|NamedDecl
operator|*
operator|*
operator|,
name|NamedDecl
operator|*
operator|*
operator|>
operator|(
name|I
operator|,
name|E
operator|)
block|{}
name|DeclContextLookupResult
argument_list|()
operator|:
name|std
operator|::
name|pair
operator|<
name|NamedDecl
operator|*
operator|*
operator|,
name|NamedDecl
operator|*
operator|*
operator|>
operator|(
operator|)
block|{}
name|using
name|std
operator|::
name|pair
operator|<
name|NamedDecl
operator|*
operator|*
operator|,
name|NamedDecl
operator|*
operator|*
operator|>
operator|::
name|operator
operator|=
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|DeclContextLookupConstResult
range|:
name|public
name|std
operator|::
name|pair
operator|<
name|NamedDecl
operator|*
specifier|const
operator|*
decl_stmt|,
name|NamedDecl
modifier|*
decl|const
modifier|*
decl|>
block|{
name|public
label|:
name|DeclContextLookupConstResult
argument_list|(
name|std
operator|::
name|pair
operator|<
name|NamedDecl
operator|*
operator|*
argument_list|,
name|NamedDecl
operator|*
operator|*
operator|>
name|R
argument_list|)
operator|:
name|std
operator|::
name|pair
operator|<
name|NamedDecl
operator|*
specifier|const
operator|*
operator|,
name|NamedDecl
operator|*
specifier|const
operator|*
operator|>
operator|(
name|R
operator|)
block|{}
name|DeclContextLookupConstResult
argument_list|(
name|NamedDecl
operator|*
specifier|const
operator|*
name|I
argument_list|,
name|NamedDecl
operator|*
specifier|const
operator|*
name|E
argument_list|)
operator|:
name|std
operator|::
name|pair
operator|<
name|NamedDecl
operator|*
specifier|const
operator|*
operator|,
name|NamedDecl
operator|*
specifier|const
operator|*
operator|>
operator|(
name|I
operator|,
name|E
operator|)
block|{}
name|DeclContextLookupConstResult
argument_list|()
operator|:
name|std
operator|::
name|pair
operator|<
name|NamedDecl
operator|*
specifier|const
operator|*
operator|,
name|NamedDecl
operator|*
specifier|const
operator|*
operator|>
operator|(
operator|)
block|{}
name|using
name|std
operator|::
name|pair
operator|<
name|NamedDecl
operator|*
specifier|const
operator|*
operator|,
name|NamedDecl
operator|*
specifier|const
operator|*
operator|>
operator|::
name|operator
operator|=
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

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
name|unsigned
name|DeclKind
range|:
literal|8
decl_stmt|;
comment|/// \brief Whether this declaration context also has some external
comment|/// storage that contains additional declarations that are lexically
comment|/// part of this context.
name|mutable
name|unsigned
name|ExternalLexicalStorage
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether this declaration context also has some external
comment|/// storage that contains additional declarations that are visible
comment|/// in this context.
name|mutable
name|unsigned
name|ExternalVisibleStorage
range|:
literal|1
decl_stmt|;
comment|/// \brief Pointer to the data structure used to lookup declarations
comment|/// within this context (or a DependentStoredDeclsMap if this is a
comment|/// dependent context).
name|mutable
name|StoredDeclsMap
modifier|*
name|LookupPtr
decl_stmt|;
name|protected
label|:
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
name|friend
name|class
name|ExternalASTSource
decl_stmt|;
comment|/// \brief Build up a chain of declarations.
comment|///
comment|/// \returns the first/last pair of declarations.
specifier|static
name|std
operator|::
name|pair
operator|<
name|Decl
operator|*
operator|,
name|Decl
operator|*
operator|>
name|BuildDeclChain
argument_list|(
specifier|const
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|Decl
operator|*
operator|>
operator|&
name|Decls
argument_list|)
expr_stmt|;
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
name|public
operator|:
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
name|static_cast
operator|<
name|Decl
operator|::
name|Kind
operator|>
operator|(
name|DeclKind
operator|)
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
name|isClosure
argument_list|()
specifier|const
block|{
return|return
name|DeclKind
operator|==
name|Decl
operator|::
name|Block
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
name|firstFunction
operator|&&
name|DeclKind
operator|<=
name|Decl
operator|::
name|lastFunction
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
name|firstRecord
operator|&&
name|DeclKind
operator|<=
name|Decl
operator|::
name|lastRecord
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
name|bool
name|isInlineNamespace
argument_list|()
specifier|const
expr_stmt|;
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
comment|/// C++0x scoped enums), and C++ linkage specifications.
name|bool
name|isTransparentContext
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determines whether this context is, or is nested within,
comment|/// a C++ extern "C" linkage spec.
name|bool
name|isExternCContext
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determine whether this declaration context is equivalent
comment|/// to the declaration context DC.
name|bool
name|Equals
argument_list|(
specifier|const
name|DeclContext
operator|*
name|DC
argument_list|)
decl|const
block|{
return|return
name|DC
operator|&&
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
argument_list|(
specifier|const
name|DeclContext
operator|*
name|DC
argument_list|)
decl|const
decl_stmt|;
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
specifier|const
name|DeclContext
operator|*
name|getPrimaryContext
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
name|getPrimaryContext
argument_list|()
return|;
block|}
comment|/// getRedeclContext - Retrieve the context in which an entity conflicts with
comment|/// other entities of the same name, or where it is a redeclaration if the
comment|/// two entities are compatible. This skips through transparent contexts.
name|DeclContext
modifier|*
name|getRedeclContext
parameter_list|()
function_decl|;
specifier|const
name|DeclContext
operator|*
name|getRedeclContext
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
name|getRedeclContext
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
comment|/// \brief Test if this context is part of the enclosing namespace set of
comment|/// the context NS, as defined in C++0x [namespace.def]p9. If either context
comment|/// isn't a namespace, this is equivalent to Equals().
comment|///
comment|/// The enclosing namespace set of a namespace is the namespace and, if it is
comment|/// inline, its enclosing namespace, recursively.
name|bool
name|InEnclosingNamespaceSetOf
parameter_list|(
specifier|const
name|DeclContext
modifier|*
name|NS
parameter_list|)
function|const;
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
comment|/// noload_decls_begin/end - Iterate over the declarations stored in this
end_comment

begin_comment
comment|/// context that are currently loaded; don't attempt to retrieve anything
end_comment

begin_comment
comment|/// from an external source.
end_comment

begin_expr_stmt
name|decl_iterator
name|noload_decls_begin
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|decl_iterator
name|noload_decls_end
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
name|DeclContextLookupResult
name|lookup_result
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|DeclContextLookupConstResult
name|lookup_const_result
typedef|;
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
comment|/// \brief Deserialize all the visible declarations from external storage.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Name lookup deserializes visible declarations lazily, thus a DeclContext
end_comment

begin_comment
comment|/// may not have a complete name lookup table. This function deserializes
end_comment

begin_comment
comment|/// the rest of visible declarations from the external storage and completes
end_comment

begin_comment
comment|/// the name lookup table.
end_comment

begin_function_decl
name|void
name|MaterializeVisibleDeclsFromExternalStorage
parameter_list|()
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
comment|// These are all defined in DependentDiagnostic.h.
end_comment

begin_decl_stmt
name|class
name|ddiag_iterator
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|inline
name|ddiag_iterator
name|ddiag_begin
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|inline
name|ddiag_iterator
name|ddiag_end
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Low-level accessors
end_comment

begin_comment
comment|/// \brief Retrieve the internal representation of the lookup structure.
end_comment

begin_expr_stmt
name|StoredDeclsMap
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
name|DECL
parameter_list|(
name|NAME
parameter_list|,
name|BASE
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DECL_CONTEXT
parameter_list|(
name|NAME
parameter_list|)
define|\
value|static bool classof(const NAME##Decl *D) { return true; }
end_define

begin_include
include|#
directive|include
file|"clang/AST/DeclNodes.inc"
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

begin_decl_stmt
name|friend
name|class
name|DependentDiagnostic
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|StoredDeclsMap
modifier|*
name|CreateStoredDeclsMap
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

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
comment|// Specialization selected when ToTy is not a known subclass of DeclContext.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ToTy
operator|,
name|bool
name|IsKnownSubtype
operator|=
operator|::
name|llvm
operator|::
name|is_base_of
operator|<
name|DeclContext
operator|,
name|ToTy
operator|>
operator|::
name|value
operator|>
expr|struct
name|cast_convert_decl_context
block|{
specifier|static
specifier|const
name|ToTy
operator|*
name|doit
argument_list|(
argument|const DeclContext *Val
argument_list|)
block|{
return|return
name|static_cast
operator|<
specifier|const
name|ToTy
operator|*
operator|>
operator|(
name|Decl
operator|::
name|castFromDeclContext
argument_list|(
name|Val
argument_list|)
operator|)
return|;
block|}
specifier|static
name|ToTy
operator|*
name|doit
argument_list|(
argument|DeclContext *Val
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|ToTy
operator|*
operator|>
operator|(
name|Decl
operator|::
name|castFromDeclContext
argument_list|(
name|Val
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|// Specialization selected when ToTy is a known subclass of DeclContext.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ToTy
operator|>
expr|struct
name|cast_convert_decl_context
operator|<
name|ToTy
operator|,
name|true
operator|>
block|{
specifier|static
specifier|const
name|ToTy
operator|*
name|doit
argument_list|(
argument|const DeclContext *Val
argument_list|)
block|{
return|return
name|static_cast
operator|<
specifier|const
name|ToTy
operator|*
operator|>
operator|(
name|Val
operator|)
return|;
block|}
specifier|static
name|ToTy
operator|*
name|doit
argument_list|(
argument|DeclContext *Val
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|ToTy
operator|*
operator|>
operator|(
name|Val
operator|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};   }
comment|// end clang.
end_comment

begin_macro
unit|namespace
name|llvm
end_macro

begin_block
block|{
comment|/// isa<T>(DeclContext*)
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
name|classofKind
argument_list|(
name|Val
operator|.
name|getDeclKind
argument_list|()
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
comment|/// cast<T>(DeclContext*)
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
specifier|const
name|ToTy
operator|&
name|doit
argument_list|(
argument|const ::clang::DeclContext&Val
argument_list|)
block|{
return|return
operator|*
operator|::
name|clang
operator|::
name|cast_convert_decl_context
operator|<
name|ToTy
operator|>
operator|::
name|doit
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
block|{
specifier|static
name|ToTy
operator|&
name|doit
argument_list|(
argument|::clang::DeclContext&Val
argument_list|)
block|{
return|return
operator|*
operator|::
name|clang
operator|::
name|cast_convert_decl_context
operator|<
name|ToTy
operator|>
operator|::
name|doit
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
specifier|const
name|ToTy
operator|*
name|doit
argument_list|(
argument|const ::clang::DeclContext *Val
argument_list|)
block|{
return|return
operator|::
name|clang
operator|::
name|cast_convert_decl_context
operator|<
name|ToTy
operator|>
operator|::
name|doit
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
block|{
specifier|static
name|ToTy
operator|*
name|doit
argument_list|(
argument|::clang::DeclContext *Val
argument_list|)
block|{
return|return
operator|::
name|clang
operator|::
name|cast_convert_decl_context
operator|<
name|ToTy
operator|>
operator|::
name|doit
argument_list|(
name|Val
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
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
unit|};  }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

