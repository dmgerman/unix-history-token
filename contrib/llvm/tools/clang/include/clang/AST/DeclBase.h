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
file|"clang/AST/AttrIterator.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclarationName.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/Specifiers.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/VersionTuple.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerUnion.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/iterator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/iterator_range.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/PrettyStackTrace.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTMutationListener
decl_stmt|;
name|class
name|BlockDecl
decl_stmt|;
name|class
name|CXXRecordDecl
decl_stmt|;
name|class
name|CompoundStmt
decl_stmt|;
name|class
name|DeclContext
decl_stmt|;
name|class
name|DeclarationName
decl_stmt|;
name|class
name|DependentDiagnostic
decl_stmt|;
name|class
name|EnumDecl
decl_stmt|;
name|class
name|ExportDecl
decl_stmt|;
name|class
name|FunctionDecl
decl_stmt|;
name|class
name|FunctionType
decl_stmt|;
enum_decl|enum
name|Linkage
enum_decl|:
name|unsigned
name|char
enum_decl|;
name|class
name|LinkageComputer
decl_stmt|;
name|class
name|LinkageSpecDecl
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|NamedDecl
decl_stmt|;
name|class
name|NamespaceDecl
decl_stmt|;
name|class
name|ObjCCategoryDecl
decl_stmt|;
name|class
name|ObjCCategoryImplDecl
decl_stmt|;
name|class
name|ObjCContainerDecl
decl_stmt|;
name|class
name|ObjCImplDecl
decl_stmt|;
name|class
name|ObjCImplementationDecl
decl_stmt|;
name|class
name|ObjCInterfaceDecl
decl_stmt|;
name|class
name|ObjCMethodDecl
decl_stmt|;
name|class
name|ObjCProtocolDecl
decl_stmt|;
struct_decl|struct
name|PrintingPolicy
struct_decl|;
name|class
name|RecordDecl
decl_stmt|;
name|class
name|Stmt
decl_stmt|;
name|class
name|StoredDeclsMap
decl_stmt|;
name|class
name|TemplateDecl
decl_stmt|;
name|class
name|TranslationUnitDecl
decl_stmt|;
name|class
name|UsingDirectiveDecl
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
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
comment|/// Note: There are objects tacked on before the *beginning* of Decl
comment|/// (and its subclasses) in its Decl::operator new(). Proper alignment
comment|/// of all subclasses (not requiring more than the alignment of Decl) is
comment|/// asserted in DeclBase.cpp.
name|class
name|LLVM_ALIGNAS
argument_list|(
comment|/*alignof(uint64_t)*/
literal|8
argument_list|)
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
comment|/// This also contains names that conflict with tags in the
comment|/// same scope but that are otherwise ordinary names (non-type
comment|/// template parameters and indirect field declarations).
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
comment|/// member, or function-local extern ends up here.
name|IDNS_Ordinary
init|=
literal|0x0020
block|,
comment|/// Objective C \@protocol.
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
block|,
comment|/// This declaration is a function-local extern declaration of a
comment|/// variable or function. This may also be IDNS_Ordinary if it
comment|/// has been declared outside any function. These act mostly like
comment|/// invisible friend declarations, but are also visible to unqualified
comment|/// lookup within the scope of the declaring function.
name|IDNS_LocalExtern
init|=
literal|0x0800
block|,
comment|/// This declaration is an OpenMP user defined reduction construction.
name|IDNS_OMPReduction
init|=
literal|0x1000
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
block|,
comment|/// The nullability qualifier is set when the nullability of the
comment|/// result or parameter was expressed via a context-sensitive
comment|/// keyword.
name|OBJC_TQ_CSNullability
init|=
literal|0x40
block|}
enum|;
name|protected
label|:
comment|// Enumeration values used in the bits stored in NextInContextAndBits.
enum|enum
block|{
comment|/// \brief Whether this declaration is a top-level declaration (function,
comment|/// global variable, etc.) that is lexically inside an objc container
comment|/// definition.
name|TopLevelDeclInObjCContainerFlag
init|=
literal|0x01
block|,
comment|/// \brief Whether this declaration is private to the module in which it was
comment|/// defined.
name|ModulePrivateFlag
init|=
literal|0x02
block|}
enum|;
comment|/// \brief The next declaration within the same lexical
comment|/// DeclContext. These pointers form the linked list that is
comment|/// traversed via DeclContext's decls_begin()/decls_end().
comment|///
comment|/// The extra two bits are used for the TopLevelDeclInObjCContainer and
comment|/// ModulePrivate bits.
name|llvm
operator|::
name|PointerIntPair
operator|<
name|Decl
operator|*
operator|,
literal|2
operator|,
name|unsigned
operator|>
name|NextInContextAndBits
expr_stmt|;
name|private
label|:
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
literal|7
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
comment|/// \brief Whether statistic collection is enabled.
specifier|static
name|bool
name|StatisticsEnabled
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
comment|/// \brief Whether this declaration was loaded from an AST file.
name|unsigned
name|FromASTFile
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether this declaration is hidden from normal name lookup, e.g.,
comment|/// because it is was loaded from an AST file is either module-private or
comment|/// because its submodule has not been made visible.
name|unsigned
name|Hidden
range|:
literal|1
decl_stmt|;
comment|/// IdentifierNamespace - This specifies what IDNS_* namespace this lives in.
name|unsigned
name|IdentifierNamespace
range|:
literal|13
decl_stmt|;
comment|/// \brief If 0, we have not computed the linkage of this declaration.
comment|/// Otherwise, it is the linkage + 1.
name|mutable
name|unsigned
name|CacheValidAndLinkage
range|:
literal|3
decl_stmt|;
name|friend
name|class
name|ASTDeclWriter
decl_stmt|;
name|friend
name|class
name|ASTDeclReader
decl_stmt|;
name|friend
name|class
name|ASTReader
decl_stmt|;
name|friend
name|class
name|LinkageComputer
decl_stmt|;
name|template
operator|<
name|typename
name|decl_type
operator|>
name|friend
name|class
name|Redeclarable
expr_stmt|;
comment|/// \brief Allocate memory for a deserialized declaration.
comment|///
comment|/// This routine must be used to allocate memory for any declaration that is
comment|/// deserialized from a module file.
comment|///
comment|/// \param Size The size of the allocated object.
comment|/// \param Ctx The context in which we will allocate memory.
comment|/// \param ID The global ID of the deserialized declaration.
comment|/// \param Extra The amount of extra space to allocate after the object.
name|void
modifier|*
name|operator
name|new
argument_list|(
name|std
operator|::
name|size_t
name|Size
argument_list|,
specifier|const
name|ASTContext
operator|&
name|Ctx
argument_list|,
name|unsigned
name|ID
argument_list|,
name|std
operator|::
name|size_t
name|Extra
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// \brief Allocate memory for a non-deserialized declaration.
name|void
modifier|*
name|operator
name|new
argument_list|(
name|std
operator|::
name|size_t
name|Size
argument_list|,
specifier|const
name|ASTContext
operator|&
name|Ctx
argument_list|,
name|DeclContext
operator|*
name|Parent
argument_list|,
name|std
operator|::
name|size_t
name|Extra
operator|=
literal|0
argument_list|)
decl_stmt|;
name|private
label|:
name|bool
name|AccessDeclContextSanity
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
name|NextInContextAndBits
argument_list|()
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
name|FromASTFile
argument_list|(
literal|0
argument_list|)
operator|,
name|Hidden
argument_list|(
name|DC
operator|&&
name|cast
operator|<
name|Decl
operator|>
operator|(
name|DC
operator|)
operator|->
name|Hidden
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
name|CacheValidAndLinkage
argument_list|(
literal|0
argument_list|)
block|{
if|if
condition|(
name|StatisticsEnabled
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
name|NextInContextAndBits
argument_list|()
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
name|FromASTFile
argument_list|(
literal|0
argument_list|)
operator|,
name|Hidden
argument_list|(
literal|0
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
name|CacheValidAndLinkage
argument_list|(
literal|0
argument_list|)
block|{
if|if
condition|(
name|StatisticsEnabled
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
comment|/// \brief Update a potentially out-of-date declaration.
name|void
name|updateOutOfDate
argument_list|(
name|IdentifierInfo
operator|&
name|II
argument_list|)
decl|const
decl_stmt|;
name|Linkage
name|getCachedLinkage
argument_list|()
specifier|const
block|{
return|return
name|Linkage
argument_list|(
name|CacheValidAndLinkage
operator|-
literal|1
argument_list|)
return|;
block|}
name|void
name|setCachedLinkage
argument_list|(
name|Linkage
name|L
argument_list|)
decl|const
block|{
name|CacheValidAndLinkage
operator|=
name|L
operator|+
literal|1
expr_stmt|;
block|}
name|bool
name|hasCachedLinkage
argument_list|()
specifier|const
block|{
return|return
name|CacheValidAndLinkage
return|;
block|}
name|public
label|:
comment|/// \brief Source range that this declaration covers.
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|LLVM_READONLY
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
name|LLVM_READONLY
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
name|LLVM_READONLY
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
name|NextInContextAndBits
operator|.
name|getPointer
argument_list|()
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
name|NextInContextAndBits
operator|.
name|getPointer
argument_list|()
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
comment|/// Find the innermost non-closure ancestor of this declaration,
comment|/// walking up through blocks, lambdas, etc.  If that ancestor is
comment|/// not a code context (!isFunctionOrMethod()), returns null.
comment|///
comment|/// A declaration may be its own non-closure context.
name|Decl
modifier|*
name|getNonClosureContext
parameter_list|()
function_decl|;
specifier|const
name|Decl
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
name|bool
name|isInStdNamespace
argument_list|()
specifier|const
expr_stmt|;
name|ASTContext
operator|&
name|getASTContext
argument_list|()
specifier|const
name|LLVM_READONLY
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
name|assert
argument_list|(
name|AccessDeclContextSanity
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|AccessSpecifier
name|getAccess
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|AccessDeclContextSanity
argument_list|()
argument_list|)
block|;
return|return
name|AccessSpecifier
argument_list|(
name|Access
argument_list|)
return|;
block|}
comment|/// \brief Retrieve the access specifier for this declaration, even though
comment|/// it may not yet have been properly set.
name|AccessSpecifier
name|getAccessUnsafe
argument_list|()
specifier|const
block|{
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
block|{
return|return
name|setAttrsImpl
argument_list|(
name|Attrs
argument_list|,
name|getASTContext
argument_list|()
argument_list|)
return|;
block|}
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
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|attr_iterator
operator|>
name|attr_range
expr_stmt|;
name|attr_range
name|attrs
argument_list|()
specifier|const
block|{
return|return
name|attr_range
argument_list|(
name|attr_begin
argument_list|()
argument_list|,
name|attr_end
argument_list|()
argument_list|)
return|;
block|}
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
name|nullptr
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
name|nullptr
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|dropAttr
argument_list|()
block|{
if|if
condition|(
operator|!
name|HasAttrs
condition|)
return|return;
name|AttrVec
operator|&
name|Vec
operator|=
name|getAttrs
argument_list|()
expr_stmt|;
name|Vec
operator|.
name|erase
argument_list|(
name|std
operator|::
name|remove_if
argument_list|(
name|Vec
operator|.
name|begin
argument_list|()
argument_list|,
name|Vec
operator|.
name|end
argument_list|()
argument_list|,
name|isa
operator|<
name|T
argument_list|,
name|Attr
operator|*
operator|>
argument_list|)
argument_list|,
name|Vec
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|Vec
operator|.
name|empty
argument_list|()
condition|)
name|HasAttrs
operator|=
name|false
expr_stmt|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
name|llvm
operator|::
name|iterator_range
operator|<
name|specific_attr_iterator
operator|<
name|T
operator|>>
name|specific_attrs
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|make_range
argument_list|(
name|specific_attr_begin
operator|<
name|T
operator|>
operator|(
operator|)
argument_list|,
name|specific_attr_end
operator|<
name|T
operator|>
operator|(
operator|)
argument_list|)
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
name|nullptr
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
expr_stmt|;
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
comment|/// \brief Whether *any* (re-)declaration of the entity was used, meaning that
comment|/// a definition is required.
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
comment|/// \brief Set whether the declaration is used, in the sense of odr-use.
comment|///
comment|/// This should only be used immediately after creating a declaration.
comment|/// It intentionally doesn't notify any listeners.
name|void
name|setIsUsed
parameter_list|()
block|{
name|getCanonicalDecl
argument_list|()
operator|->
name|Used
operator|=
name|true
expr_stmt|;
block|}
comment|/// \brief Mark the declaration used, in the sense of odr-use.
comment|///
comment|/// This notifies any mutation listeners in addition to setting a bit
comment|/// indicating the declaration is used.
name|void
name|markUsed
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|)
function_decl|;
comment|/// \brief Whether any declaration of this entity was referenced.
name|bool
name|isReferenced
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Whether this declaration was referenced. This should not be relied
comment|/// upon for anything other than debugging.
name|bool
name|isThisDeclarationReferenced
argument_list|()
specifier|const
block|{
return|return
name|Referenced
return|;
block|}
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
comment|/// \brief Whether this declaration is a top-level declaration (function,
comment|/// global variable, etc.) that is lexically inside an objc container
comment|/// definition.
name|bool
name|isTopLevelDeclInObjCContainer
argument_list|()
specifier|const
block|{
return|return
name|NextInContextAndBits
operator|.
name|getInt
argument_list|()
operator|&
name|TopLevelDeclInObjCContainerFlag
return|;
block|}
name|void
name|setTopLevelDeclInObjCContainer
parameter_list|(
name|bool
name|V
init|=
name|true
parameter_list|)
block|{
name|unsigned
name|Bits
init|=
name|NextInContextAndBits
operator|.
name|getInt
argument_list|()
decl_stmt|;
if|if
condition|(
name|V
condition|)
name|Bits
operator||=
name|TopLevelDeclInObjCContainerFlag
expr_stmt|;
else|else
name|Bits
operator|&=
operator|~
name|TopLevelDeclInObjCContainerFlag
expr_stmt|;
name|NextInContextAndBits
operator|.
name|setInt
argument_list|(
name|Bits
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Whether this declaration was marked as being private to the
comment|/// module in which it was defined.
name|bool
name|isModulePrivate
argument_list|()
specifier|const
block|{
return|return
name|NextInContextAndBits
operator|.
name|getInt
argument_list|()
operator|&
name|ModulePrivateFlag
return|;
block|}
comment|/// \brief Whether this declaration is exported (by virtue of being lexically
comment|/// within an ExportDecl or by being a NamespaceDecl).
name|bool
name|isExported
argument_list|()
specifier|const
expr_stmt|;
comment|/// Return true if this declaration has an attribute which acts as
comment|/// definition of the entity, such as 'alias' or 'ifunc'.
name|bool
name|hasDefiningAttr
argument_list|()
specifier|const
expr_stmt|;
comment|/// Return this declaration's defining attribute if it has one.
specifier|const
name|Attr
operator|*
name|getDefiningAttr
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
comment|/// \brief Specify whether this declaration was marked as being private
comment|/// to the module in which it was defined.
name|void
name|setModulePrivate
parameter_list|(
name|bool
name|MP
init|=
name|true
parameter_list|)
block|{
name|unsigned
name|Bits
init|=
name|NextInContextAndBits
operator|.
name|getInt
argument_list|()
decl_stmt|;
if|if
condition|(
name|MP
condition|)
name|Bits
operator||=
name|ModulePrivateFlag
expr_stmt|;
else|else
name|Bits
operator|&=
operator|~
name|ModulePrivateFlag
expr_stmt|;
name|NextInContextAndBits
operator|.
name|setInt
argument_list|(
name|Bits
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Set the owning module ID.
name|void
name|setOwningModuleID
parameter_list|(
name|unsigned
name|ID
parameter_list|)
block|{
name|assert
argument_list|(
name|isFromASTFile
argument_list|()
operator|&&
literal|"Only works on a deserialized declaration"
argument_list|)
expr_stmt|;
operator|*
operator|(
operator|(
name|unsigned
operator|*
operator|)
name|this
operator|-
literal|2
operator|)
operator|=
name|ID
expr_stmt|;
block|}
name|public
label|:
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
comment|///
comment|/// \param EnclosingVersion The version to compare with. If empty, assume the
comment|/// deployment target version.
name|AvailabilityResult
name|getAvailability
argument_list|(
name|std
operator|::
name|string
operator|*
name|Message
operator|=
name|nullptr
argument_list|,
name|VersionTuple
name|EnclosingVersion
operator|=
name|VersionTuple
argument_list|()
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Retrieve the version of the target platform in which this
comment|/// declaration was introduced.
comment|///
comment|/// \returns An empty version tuple if this declaration has no 'introduced'
comment|/// availability attributes, or the version tuple that's specified in the
comment|/// attribute otherwise.
name|VersionTuple
name|getVersionIntroduced
argument_list|()
specifier|const
expr_stmt|;
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
name|nullptr
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
name|nullptr
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
comment|/// \brief Determine whether this declaration came from an AST file (such as
comment|/// a precompiled header or module) rather than having been parsed.
name|bool
name|isFromASTFile
argument_list|()
specifier|const
block|{
return|return
name|FromASTFile
return|;
block|}
comment|/// \brief Retrieve the global declaration ID associated with this
comment|/// declaration, which specifies where this Decl was loaded from.
name|unsigned
name|getGlobalID
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isFromASTFile
argument_list|()
condition|)
return|return
operator|*
operator|(
operator|(
specifier|const
name|unsigned
operator|*
operator|)
name|this
operator|-
literal|1
operator|)
return|;
return|return
literal|0
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Retrieve the global ID of the module that owns this particular
end_comment

begin_comment
comment|/// declaration.
end_comment

begin_expr_stmt
name|unsigned
name|getOwningModuleID
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isFromASTFile
argument_list|()
condition|)
return|return
operator|*
operator|(
operator|(
specifier|const
name|unsigned
operator|*
operator|)
name|this
operator|-
literal|2
operator|)
return|;
end_expr_stmt

begin_return
return|return
literal|0
return|;
end_return

begin_expr_stmt
unit|}  private:
name|Module
operator|*
name|getOwningModuleSlow
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|bool
name|hasLocalOwningModuleStorage
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/// \brief Get the imported owning module, if this decl is from an imported
end_comment

begin_comment
comment|/// (non-local) module.
end_comment

begin_expr_stmt
name|Module
operator|*
name|getImportedOwningModule
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|isFromASTFile
argument_list|()
condition|)
return|return
name|nullptr
return|;
end_expr_stmt

begin_return
return|return
name|getOwningModuleSlow
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|/// \brief Get the local owning module, if known. Returns nullptr if owner is
end_comment

begin_comment
comment|/// not yet known or declaration is not from a module.
end_comment

begin_expr_stmt
unit|Module
operator|*
name|getLocalOwningModule
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isFromASTFile
argument_list|()
operator|||
operator|!
name|Hidden
condition|)
return|return
name|nullptr
return|;
end_expr_stmt

begin_return
return|return
name|reinterpret_cast
operator|<
name|Module
operator|*
specifier|const
operator|*
operator|>
operator|(
name|this
operator|)
index|[
operator|-
literal|1
index|]
return|;
end_return

begin_macro
unit|}   void
name|setLocalOwningModule
argument_list|(
argument|Module *M
argument_list|)
end_macro

begin_block
block|{
name|assert
argument_list|(
operator|!
name|isFromASTFile
argument_list|()
operator|&&
name|Hidden
operator|&&
name|hasLocalOwningModuleStorage
argument_list|()
operator|&&
literal|"should not have a cached owning module"
argument_list|)
expr_stmt|;
name|reinterpret_cast
operator|<
name|Module
operator|*
operator|*
operator|>
operator|(
name|this
operator|)
index|[
operator|-
literal|1
index|]
operator|=
name|M
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|Module
operator|*
name|getOwningModule
argument_list|()
specifier|const
block|{
return|return
name|isFromASTFile
argument_list|()
operator|?
name|getImportedOwningModule
argument_list|()
operator|:
name|getLocalOwningModule
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this declaration is hidden from name lookup.
end_comment

begin_expr_stmt
name|bool
name|isHidden
argument_list|()
specifier|const
block|{
return|return
name|Hidden
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Set whether this declaration is hidden from name lookup.
end_comment

begin_function
name|void
name|setHidden
parameter_list|(
name|bool
name|Hide
parameter_list|)
block|{
name|assert
argument_list|(
operator|(
operator|!
name|Hide
operator|||
name|isFromASTFile
argument_list|()
operator|||
name|hasLocalOwningModuleStorage
argument_list|()
operator|)
operator|&&
literal|"declaration with no owning module can't be hidden"
argument_list|)
expr_stmt|;
name|Hidden
operator|=
name|Hide
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

begin_expr_stmt
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
end_expr_stmt

begin_function
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
end_function

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

begin_comment
comment|/// Determine whether this declaration is declared out of line (outside its
end_comment

begin_comment
comment|/// semantic context).
end_comment

begin_expr_stmt
name|virtual
name|bool
name|isOutOfLine
argument_list|()
specifier|const
expr_stmt|;
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
comment|/// isDefinedOutsideFunctionOrMethod - This predicate returns true if this
end_comment

begin_comment
comment|/// scoped decl is defined outside the current function or method.  This is
end_comment

begin_comment
comment|/// roughly global variables and functions, but also handles enums (which
end_comment

begin_comment
comment|/// could be defined inside or outside a function etc).
end_comment

begin_expr_stmt
name|bool
name|isDefinedOutsideFunctionOrMethod
argument_list|()
specifier|const
block|{
return|return
name|getParentFunctionOrMethod
argument_list|()
operator|==
name|nullptr
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Returns true if this declaration lexically is inside a function.
end_comment

begin_comment
comment|/// It recognizes non-defining declarations as well as members of local
end_comment

begin_comment
comment|/// classes:
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|///     void foo() { void bar(); }
end_comment

begin_comment
comment|///     void foo2() { class ABC { void bar(); }; }
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_expr_stmt
name|bool
name|isLexicallyWithinFunctionOrMethod
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief If this decl is defined inside a function/method/block it returns
end_comment

begin_comment
comment|/// the corresponding DeclContext, otherwise it returns null.
end_comment

begin_expr_stmt
specifier|const
name|DeclContext
operator|*
name|getParentFunctionOrMethod
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_function
name|DeclContext
modifier|*
name|getParentFunctionOrMethod
parameter_list|()
block|{
return|return
name|const_cast
operator|<
name|DeclContext
operator|*
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
name|getParentFunctionOrMethod
argument_list|()
operator|)
return|;
block|}
end_function

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
name|getNextRedeclarationImpl
parameter_list|()
block|{
return|return
name|this
return|;
block|}
end_function

begin_comment
comment|/// \brief Implementation of getPreviousDecl(), to be overridden by any
end_comment

begin_comment
comment|/// subclass that has a redeclaration chain.
end_comment

begin_function
name|virtual
name|Decl
modifier|*
name|getPreviousDeclImpl
parameter_list|()
block|{
return|return
name|nullptr
return|;
block|}
end_function

begin_comment
comment|/// \brief Implementation of getMostRecentDecl(), to be overridden by any
end_comment

begin_comment
comment|/// subclass that has a redeclaration chain.
end_comment

begin_function
name|virtual
name|Decl
modifier|*
name|getMostRecentDeclImpl
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
specifier|const
name|value_type
modifier|&
name|reference
typedef|;
typedef|typedef
specifier|const
name|value_type
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
argument|nullptr
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
name|value_type
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
name|getNextRedeclarationImpl
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
operator|)
condition|?
name|Next
else|:
name|nullptr
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

begin_typedef
unit|};
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|redecl_iterator
operator|>
name|redecl_range
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief Returns an iterator range for all the redeclarations of the same
end_comment

begin_comment
comment|/// decl. It will iterate at least once (when this decl is the only one).
end_comment

begin_expr_stmt
name|redecl_range
name|redecls
argument_list|()
specifier|const
block|{
return|return
name|redecl_range
argument_list|(
name|redecls_begin
argument_list|()
argument_list|,
name|redecls_end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

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
comment|/// \brief Retrieve the previous declaration that declares the same entity
end_comment

begin_comment
comment|/// as this declaration, or NULL if there is no previous declaration.
end_comment

begin_function
name|Decl
modifier|*
name|getPreviousDecl
parameter_list|()
block|{
return|return
name|getPreviousDeclImpl
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// \brief Retrieve the most recent declaration that declares the same entity
end_comment

begin_comment
comment|/// as this declaration, or NULL if there is no previous declaration.
end_comment

begin_expr_stmt
specifier|const
name|Decl
operator|*
name|getPreviousDecl
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
name|getPreviousDeclImpl
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief True if this is the first declaration in its redeclaration chain.
end_comment

begin_expr_stmt
name|bool
name|isFirstDecl
argument_list|()
specifier|const
block|{
return|return
name|getPreviousDecl
argument_list|()
operator|==
name|nullptr
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the most recent declaration that declares the same entity
end_comment

begin_comment
comment|/// as this declaration (which may be this declaration).
end_comment

begin_function
name|Decl
modifier|*
name|getMostRecentDecl
parameter_list|()
block|{
return|return
name|getMostRecentDeclImpl
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// \brief Retrieve the most recent declaration that declares the same entity
end_comment

begin_comment
comment|/// as this declaration (which may be this declaration).
end_comment

begin_expr_stmt
specifier|const
name|Decl
operator|*
name|getMostRecentDecl
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
name|getMostRecentDeclImpl
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
name|nullptr
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Returns true if this \c Decl represents a declaration for a body of
end_comment

begin_comment
comment|/// code, such as a function or method definition.
end_comment

begin_comment
comment|/// Note that \c hasBody can also return true if any redeclaration of this
end_comment

begin_comment
comment|/// \c Decl represents a declaration for a body of code.
end_comment

begin_expr_stmt
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
name|nullptr
return|;
block|}
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
name|add
parameter_list|(
name|Kind
name|k
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|EnableStatistics
parameter_list|()
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
comment|/// \brief Whether this declaration is a parameter pack.
end_comment

begin_expr_stmt
name|bool
name|isParameterPack
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief returns true if this declaration is a template
end_comment

begin_expr_stmt
name|bool
name|isTemplateDecl
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
block|{
return|return
operator|(
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
operator|)
operator|||
name|DeclKind
operator|==
name|FunctionTemplate
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief If this is a declaration that describes some template, this
end_comment

begin_comment
comment|/// method returns that template declaration.
end_comment

begin_expr_stmt
name|TemplateDecl
operator|*
name|getDescribedTemplate
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Returns the function itself, or the templated function if this is a
end_comment

begin_comment
comment|/// function template.
end_comment

begin_expr_stmt
name|FunctionDecl
operator|*
name|getAsFunction
argument_list|()
name|LLVM_READONLY
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|FunctionDecl
operator|*
name|getAsFunction
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
name|getAsFunction
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Changes the namespace of this declaration to reflect that it's
end_comment

begin_comment
comment|/// a function-local extern declaration.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// These declarations appear in the lexical context of the extern
end_comment

begin_comment
comment|/// declaration, but in the semantic context of the enclosing namespace
end_comment

begin_comment
comment|/// scope.
end_comment

begin_function
name|void
name|setLocalExternDecl
parameter_list|()
block|{
name|assert
argument_list|(
operator|(
name|IdentifierNamespace
operator|==
name|IDNS_Ordinary
operator|||
name|IdentifierNamespace
operator|==
name|IDNS_OrdinaryFriend
operator|)
operator|&&
literal|"namespace is not ordinary"
argument_list|)
expr_stmt|;
name|Decl
modifier|*
name|Prev
init|=
name|getPreviousDecl
argument_list|()
decl_stmt|;
name|IdentifierNamespace
operator|&=
operator|~
name|IDNS_Ordinary
expr_stmt|;
name|IdentifierNamespace
operator||=
name|IDNS_LocalExtern
expr_stmt|;
if|if
condition|(
name|Prev
operator|&&
name|Prev
operator|->
name|getIdentifierNamespace
argument_list|()
operator|&
name|IDNS_Ordinary
condition|)
name|IdentifierNamespace
operator||=
name|IDNS_Ordinary
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Determine whether this is a block-scope declaration with linkage.
end_comment

begin_comment
comment|/// This will either be a local variable declaration declared 'extern', or a
end_comment

begin_comment
comment|/// local function declaration.
end_comment

begin_function
name|bool
name|isLocalExternDecl
parameter_list|()
block|{
return|return
name|IdentifierNamespace
operator|&
name|IDNS_LocalExtern
return|;
block|}
end_function

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
name|PerformFriendInjection
init|=
name|false
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
operator||
name|IDNS_LocalExtern
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
operator||
name|IDNS_LocalExtern
operator|)
operator|)
operator|&&
literal|"namespace includes other than ordinary or tag"
argument_list|)
expr_stmt|;
name|Decl
modifier|*
name|Prev
init|=
name|getPreviousDecl
argument_list|()
decl_stmt|;
name|IdentifierNamespace
operator|&=
operator|~
operator|(
name|IDNS_Ordinary
operator||
name|IDNS_Tag
operator||
name|IDNS_Type
operator|)
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
name|PerformFriendInjection
operator|||
operator|(
name|Prev
operator|&&
name|Prev
operator|->
name|getIdentifierNamespace
argument_list|()
operator|&
name|IDNS_Tag
operator|)
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
operator||
name|IDNS_LocalExtern
operator|)
condition|)
block|{
name|IdentifierNamespace
operator||=
name|IDNS_OrdinaryFriend
expr_stmt|;
if|if
condition|(
name|PerformFriendInjection
operator|||
operator|(
name|Prev
operator|&&
name|Prev
operator|->
name|getIdentifierNamespace
argument_list|()
operator|&
name|IDNS_Ordinary
operator|)
condition|)
name|IdentifierNamespace
operator||=
name|IDNS_Ordinary
expr_stmt|;
block|}
block|}
end_function

begin_enum
enum|enum
name|FriendObjectKind
block|{
name|FOK_None
block|,
comment|///< Not a friend object.
name|FOK_Declared
block|,
comment|///< A friend of a previously-declared entity.
name|FOK_Undeclared
comment|///< A friend of a previously-undeclared entity.
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
comment|/// Specifies that this declaration is a C++ overloaded non-member.
end_comment

begin_macro
unit|void
name|setNonMemberOperator
argument_list|()
end_macro

begin_block
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
end_block

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
name|raw_ostream
operator|&
name|Out
argument_list|,
name|unsigned
name|Indentation
operator|=
literal|0
argument_list|,
name|bool
name|PrintInstantiation
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print
argument_list|(
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
argument_list|,
name|bool
name|PrintInstantiation
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|void
name|printGroup
parameter_list|(
name|Decl
modifier|*
modifier|*
name|Begin
parameter_list|,
name|unsigned
name|NumDecls
parameter_list|,
name|raw_ostream
modifier|&
name|Out
parameter_list|,
specifier|const
name|PrintingPolicy
modifier|&
name|Policy
parameter_list|,
name|unsigned
name|Indentation
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Debuggers don't usually respect default arguments.
end_comment

begin_expr_stmt
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Same as dump(), but forces color printing.
end_comment

begin_expr_stmt
name|void
name|dumpColor
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|dump
argument_list|(
name|raw_ostream
operator|&
name|Out
argument_list|,
name|bool
name|Deserialize
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Looks through the Decl's underlying type to extract a FunctionType
end_comment

begin_comment
comment|/// when possible. Will return null if the type underlying the Decl does not
end_comment

begin_comment
comment|/// have a FunctionType.
end_comment

begin_decl_stmt
specifier|const
name|FunctionType
modifier|*
name|getFunctionType
argument_list|(
name|bool
name|BlocksToo
operator|=
name|true
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_function_decl
name|void
name|setAttrsImpl
parameter_list|(
specifier|const
name|AttrVec
modifier|&
name|Attrs
parameter_list|,
name|ASTContext
modifier|&
name|Ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setDeclContextsImpl
parameter_list|(
name|DeclContext
modifier|*
name|SemaDC
parameter_list|,
name|DeclContext
modifier|*
name|LexicalDC
parameter_list|,
name|ASTContext
modifier|&
name|Ctx
parameter_list|)
function_decl|;
end_function_decl

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
comment|/// \brief Determine whether two declarations declare the same entity.
end_comment

begin_function
specifier|inline
name|bool
name|declaresSameEntity
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D1
parameter_list|,
specifier|const
name|Decl
modifier|*
name|D2
parameter_list|)
block|{
if|if
condition|(
operator|!
name|D1
operator|||
operator|!
name|D2
condition|)
return|return
name|false
return|;
if|if
condition|(
name|D1
operator|==
name|D2
condition|)
return|return
name|true
return|;
return|return
name|D1
operator|->
name|getCanonicalDecl
argument_list|()
operator|==
name|D2
operator|->
name|getCanonicalDecl
argument_list|()
return|;
block|}
end_function

begin_comment
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
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief The results of name lookup within a DeclContext. This is either a
end_comment

begin_comment
comment|/// single result (with no stable storage) or a collection of results (with
end_comment

begin_comment
comment|/// stable storage provided by the lookup table).
end_comment

begin_decl_stmt
name|class
name|DeclContextLookupResult
block|{
typedef|typedef
name|ArrayRef
operator|<
name|NamedDecl
operator|*
operator|>
name|ResultTy
expr_stmt|;
name|ResultTy
name|Result
decl_stmt|;
comment|// If there is only one lookup result, it would be invalidated by
comment|// reallocations of the name table, so store it separately.
name|NamedDecl
modifier|*
name|Single
decl_stmt|;
specifier|static
name|NamedDecl
modifier|*
specifier|const
name|SingleElementDummyList
decl_stmt|;
name|public
label|:
name|DeclContextLookupResult
argument_list|()
operator|:
name|Result
argument_list|()
operator|,
name|Single
argument_list|()
block|{}
name|DeclContextLookupResult
argument_list|(
name|ArrayRef
operator|<
name|NamedDecl
operator|*
operator|>
name|Result
argument_list|)
operator|:
name|Result
argument_list|(
name|Result
argument_list|)
operator|,
name|Single
argument_list|()
block|{}
name|DeclContextLookupResult
argument_list|(
name|NamedDecl
operator|*
name|Single
argument_list|)
operator|:
name|Result
argument_list|(
name|SingleElementDummyList
argument_list|)
operator|,
name|Single
argument_list|(
argument|Single
argument_list|)
block|{}
name|class
name|iterator
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|iterator_adaptor_base
operator|<
name|iterator
operator|,
name|ResultTy
operator|::
name|iterator
operator|,
name|std
operator|::
name|random_access_iterator_tag
operator|,
name|NamedDecl
operator|*
specifier|const
operator|>
name|IteratorBase
expr_stmt|;
name|class
name|iterator
range|:
name|public
name|IteratorBase
block|{
name|value_type
name|SingleElement
block|;
name|public
operator|:
name|iterator
argument_list|()
operator|:
name|IteratorBase
argument_list|()
block|,
name|SingleElement
argument_list|()
block|{}
name|explicit
name|iterator
argument_list|(
argument|pointer Pos
argument_list|,
argument|value_type Single = nullptr
argument_list|)
operator|:
name|IteratorBase
argument_list|(
name|Pos
argument_list|)
block|,
name|SingleElement
argument_list|(
argument|Single
argument_list|)
block|{}
name|reference
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|SingleElement
operator|?
name|SingleElement
operator|:
name|IteratorBase
operator|::
name|operator
operator|*
operator|(
operator|)
return|;
block|}
expr|}
block|;
typedef|typedef
name|iterator
name|const_iterator
typedef|;
typedef|typedef
name|iterator
operator|::
name|pointer
name|pointer
expr_stmt|;
typedef|typedef
name|iterator
operator|::
name|reference
name|reference
expr_stmt|;
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|iterator
argument_list|(
name|Result
operator|.
name|begin
argument_list|()
argument_list|,
name|Single
argument_list|)
return|;
block|}
name|iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|iterator
argument_list|(
name|Result
operator|.
name|end
argument_list|()
argument_list|,
name|Single
argument_list|)
return|;
block|}
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|Result
operator|.
name|empty
argument_list|()
return|;
block|}
name|pointer
name|data
argument_list|()
specifier|const
block|{
return|return
name|Single
operator|?
operator|&
name|Single
operator|:
name|Result
operator|.
name|data
argument_list|()
return|;
block|}
name|size_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|Single
operator|?
literal|1
operator|:
name|Result
operator|.
name|size
argument_list|()
return|;
block|}
name|reference
name|front
argument_list|()
specifier|const
block|{
return|return
name|Single
operator|?
name|Single
operator|:
name|Result
operator|.
name|front
argument_list|()
return|;
block|}
name|reference
name|back
argument_list|()
specifier|const
block|{
return|return
name|Single
operator|?
name|Single
operator|:
name|Result
operator|.
name|back
argument_list|()
return|;
block|}
name|reference
name|operator
index|[]
argument_list|(
name|size_t
name|N
argument_list|)
decl|const
block|{
return|return
name|Single
condition|?
name|Single
else|:
name|Result
index|[
name|N
index|]
return|;
block|}
comment|// FIXME: Remove this from the interface
name|DeclContextLookupResult
name|slice
argument_list|(
name|size_t
name|N
argument_list|)
decl|const
block|{
name|DeclContextLookupResult
name|Sliced
init|=
name|Result
operator|.
name|slice
argument_list|(
name|N
argument_list|)
decl_stmt|;
name|Sliced
operator|.
name|Single
operator|=
name|Single
expr_stmt|;
return|return
name|Sliced
return|;
block|}
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
comment|///   ExportDecl
end_comment

begin_comment
comment|///   BlockDecl
end_comment

begin_comment
comment|///   OMPDeclareReductionDecl
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
comment|/// \brief Whether this declaration context has had external visible
comment|/// storage added since the last lookup. In this case, \c LookupPtr's
comment|/// invariant may not hold and needs to be fixed before we perform
comment|/// another lookup.
name|mutable
name|bool
name|NeedToReconcileExternalVisibleStorage
range|:
literal|1
decl_stmt|;
comment|/// \brief If \c true, this context may have local lexical declarations
comment|/// that are missing from the lookup table.
name|mutable
name|bool
name|HasLazyLocalLexicalLookups
range|:
literal|1
decl_stmt|;
comment|/// \brief If \c true, the external source may have lexical declarations
comment|/// that are missing from the lookup table.
name|mutable
name|bool
name|HasLazyExternalLexicalLookups
range|:
literal|1
decl_stmt|;
comment|/// \brief If \c true, lookups should only return identifier from
comment|/// DeclContext scope (for example TranslationUnit). Used in
comment|/// LookupQualifiedName()
name|mutable
name|bool
name|UseQualifiedLookup
range|:
literal|1
decl_stmt|;
comment|/// \brief Pointer to the data structure used to lookup declarations
comment|/// within this context (or a DependentStoredDeclsMap if this is a
comment|/// dependent context). We maintain the invariant that, if the map
comment|/// contains an entry for a DeclarationName (and we haven't lazily
comment|/// omitted anything), then it contains all relevant entries for that
comment|/// name (modulo the hasExternalDecls() flag).
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
name|friend
name|class
name|ASTDeclReader
decl_stmt|;
name|friend
name|class
name|ASTWriter
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
argument|ArrayRef<Decl*> Decls
argument_list|,
argument|bool FieldsAlreadyLoaded
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
name|NeedToReconcileExternalVisibleStorage
argument_list|(
name|false
argument_list|)
operator|,
name|HasLazyLocalLexicalLookups
argument_list|(
name|false
argument_list|)
operator|,
name|HasLazyExternalLexicalLookups
argument_list|(
name|false
argument_list|)
operator|,
name|UseQualifiedLookup
argument_list|(
name|false
argument_list|)
operator|,
name|LookupPtr
argument_list|(
name|nullptr
argument_list|)
operator|,
name|FirstDecl
argument_list|(
name|nullptr
argument_list|)
operator|,
name|LastDecl
argument_list|(
argument|nullptr
argument_list|)
block|{}
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
name|isObjCContainer
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
name|ObjCCategory
case|:
case|case
name|Decl
operator|::
name|ObjCCategoryImpl
case|:
case|case
name|Decl
operator|::
name|ObjCImplementation
case|:
case|case
name|Decl
operator|::
name|ObjCInterface
case|:
case|case
name|Decl
operator|::
name|ObjCProtocol
case|:
return|return
name|true
return|;
block|}
return|return
name|false
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
name|Captured
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
comment|/// \brief Test whether the context supports looking up names.
name|bool
name|isLookupContext
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isFunctionOrMethod
argument_list|()
operator|&&
name|DeclKind
operator|!=
name|Decl
operator|::
name|LinkageSpec
operator|&&
name|DeclKind
operator|!=
name|Decl
operator|::
name|Export
return|;
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
name|isStdNamespace
argument_list|()
specifier|const
expr_stmt|;
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
comment|/// \brief Determines whether this context or some of its ancestors is a
comment|/// linkage specification context that specifies C linkage.
name|bool
name|isExternCContext
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Retrieve the nearest enclosing C linkage specification context.
specifier|const
name|LinkageSpecDecl
operator|*
name|getExternCContext
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determines whether this context or some of its ancestors is a
comment|/// linkage specification context that specifies C++ linkage.
name|bool
name|isExternCXXContext
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
comment|/// \brief Find the nearest non-closure ancestor of this context,
comment|/// i.e. the innermost semantic parent of this context which is not
comment|/// a closure.  A context may be its own non-closure ancestor.
name|Decl
modifier|*
name|getNonClosureAncestor
parameter_list|()
function_decl|;
specifier|const
name|Decl
operator|*
name|getNonClosureAncestor
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
name|getNonClosureAncestor
argument_list|()
return|;
block|}
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
comment|/// \brief Retrieve the outermost lexically enclosing record context.
name|RecordDecl
modifier|*
name|getOuterLexicalRecordContext
parameter_list|()
function_decl|;
specifier|const
name|RecordDecl
operator|*
name|getOuterLexicalRecordContext
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
name|getOuterLexicalRecordContext
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
argument_list|(
specifier|const
name|DeclContext
operator|*
name|NS
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Collects all of the declaration contexts that are semantically
comment|/// connected to this declaration context.
comment|///
comment|/// For declaration contexts that have multiple semantically connected but
comment|/// syntactically distinct contexts, such as C++ namespaces, this routine
comment|/// retrieves the complete set of such declaration contexts in source order.
comment|/// For example, given:
comment|///
comment|/// \code
comment|/// namespace N {
comment|///   int x;
comment|/// }
comment|/// namespace N {
comment|///   int y;
comment|/// }
comment|/// \endcode
comment|///
comment|/// The \c Contexts parameter will contain both definitions of N.
comment|///
comment|/// \param Contexts Will be cleared and set to the set of declaration
comment|/// contexts that are semanticaly connected to this declaration context,
comment|/// in source order, including this context (which may be the only result,
comment|/// for non-namespace contexts).
name|void
name|collectAllContexts
argument_list|(
name|SmallVectorImpl
operator|<
name|DeclContext
operator|*
operator|>
operator|&
name|Contexts
argument_list|)
decl_stmt|;
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
specifier|const
name|value_type
modifier|&
name|reference
typedef|;
typedef|typedef
specifier|const
name|value_type
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
argument|nullptr
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
comment|// This doesn't meet the iterator requirements, but it's convenient
name|value_type
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

begin_typedef
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|decl_iterator
operator|>
name|decl_range
expr_stmt|;
end_typedef

begin_comment
comment|/// decls_begin/decls_end - Iterate over the declarations stored in
end_comment

begin_comment
comment|/// this context.
end_comment

begin_expr_stmt
name|decl_range
name|decls
argument_list|()
specifier|const
block|{
return|return
name|decl_range
argument_list|(
name|decls_begin
argument_list|()
argument_list|,
name|decls_end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

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
block|{
return|return
name|decl_iterator
argument_list|()
return|;
block|}
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
name|decl_range
name|noload_decls
argument_list|()
specifier|const
block|{
return|return
name|decl_range
argument_list|(
name|noload_decls_begin
argument_list|()
argument_list|,
name|noload_decls_end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|decl_iterator
name|noload_decls_begin
argument_list|()
specifier|const
block|{
return|return
name|decl_iterator
argument_list|(
name|FirstDecl
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|decl_iterator
name|noload_decls_end
argument_list|()
specifier|const
block|{
return|return
name|decl_iterator
argument_list|()
return|;
block|}
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

begin_comment
comment|// TODO: Add reference and pointer typedefs (with some appropriate proxy
end_comment

begin_comment
comment|// type) if we ever have a need for them.
end_comment

begin_typedef
typedef|typedef
name|void
name|reference
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
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
name|value_type
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

begin_comment
comment|// This doesn't meet the iterator requirements, but it's convenient
end_comment

begin_expr_stmt
name|value_type
name|operator
operator|->
expr|(
end_expr_stmt

begin_expr_stmt
unit|)
specifier|const
block|{
return|return
operator|*
operator|*
name|this
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

begin_comment
comment|// TODO: Add reference and pointer typedefs (with some appropriate proxy
end_comment

begin_comment
comment|// type) if we ever have a need for them.
end_comment

begin_typedef
typedef|typedef
name|void
name|reference
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
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
comment|/// filtered_decl_iterator - Construct a new iterator over a
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
name|value_type
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
name|value_type
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
comment|/// @brief Add the declaration D into this context, but suppress
end_comment

begin_comment
comment|/// searches for external declarations with the same name.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Although analogous in function to addDecl, this removes an
end_comment

begin_comment
comment|/// important check.  This is only useful if the Decl is being
end_comment

begin_comment
comment|/// added in response to an external search; in all other cases,
end_comment

begin_comment
comment|/// addDecl() is the right function to use.
end_comment

begin_comment
comment|/// See the ASTImporter for use cases.
end_comment

begin_function_decl
name|void
name|addDeclInternal
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
comment|/// @brief Checks whether a declaration is in this context.
end_comment

begin_decl_stmt
name|bool
name|containsDecl
argument_list|(
name|Decl
operator|*
name|D
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|DeclContextLookupResult
name|lookup_result
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|lookup_result
operator|::
name|iterator
name|lookup_iterator
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

begin_decl_stmt
name|lookup_result
name|lookup
argument_list|(
name|DeclarationName
name|Name
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Find the declarations with the given name that are visible
end_comment

begin_comment
comment|/// within this context; don't attempt to retrieve anything from an
end_comment

begin_comment
comment|/// external source.
end_comment

begin_function_decl
name|lookup_result
name|noload_lookup
parameter_list|(
name|DeclarationName
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief A simplistic name lookup mechanism that performs name lookup
end_comment

begin_comment
comment|/// into this declaration context without consulting the external source.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function should almost never be used, because it subverts the
end_comment

begin_comment
comment|/// usual relationship between a DeclContext and the external source.
end_comment

begin_comment
comment|/// See the ASTImporter for the (few, but important) use cases.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// FIXME: This is very inefficient; replace uses of it with uses of
end_comment

begin_comment
comment|/// noload_lookup.
end_comment

begin_decl_stmt
name|void
name|localUncachedLookup
argument_list|(
name|DeclarationName
name|Name
argument_list|,
name|SmallVectorImpl
operator|<
name|NamedDecl
operator|*
operator|>
operator|&
name|Results
argument_list|)
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

begin_function_decl
name|void
name|makeDeclVisibleInContext
parameter_list|(
name|NamedDecl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// all_lookups_iterator - An iterator that provides a view over the results
end_comment

begin_comment
comment|/// of looking up every possible name.
end_comment

begin_decl_stmt
name|class
name|all_lookups_iterator
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|all_lookups_iterator
operator|>
name|lookups_range
expr_stmt|;
end_typedef

begin_expr_stmt
name|lookups_range
name|lookups
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lookups_range
name|noload_lookups
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Iterators over all possible lookups within this context.
end_comment

begin_expr_stmt
name|all_lookups_iterator
name|lookups_begin
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|all_lookups_iterator
name|lookups_end
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Iterators over all possible lookups within this context that are
end_comment

begin_comment
comment|/// currently loaded; don't attempt to retrieve anything from an external
end_comment

begin_comment
comment|/// source.
end_comment

begin_expr_stmt
name|all_lookups_iterator
name|noload_lookups_begin
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|all_lookups_iterator
name|noload_lookups_end
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_struct_decl
struct_decl|struct
name|udir_iterator
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|llvm
operator|::
name|iterator_adaptor_base
operator|<
name|udir_iterator
operator|,
name|lookup_iterator
operator|,
name|std
operator|::
name|random_access_iterator_tag
operator|,
name|UsingDirectiveDecl
operator|*
operator|>
name|udir_iterator_base
expr_stmt|;
end_typedef

begin_decl_stmt
name|struct
name|udir_iterator
range|:
name|udir_iterator_base
block|{
name|udir_iterator
argument_list|(
argument|lookup_iterator I
argument_list|)
operator|:
name|udir_iterator_base
argument_list|(
argument|I
argument_list|)
block|{}
name|UsingDirectiveDecl
operator|*
name|operator
operator|*
operator|(
operator|)
specifier|const
block|;   }
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|udir_iterator
operator|>
name|udir_range
expr_stmt|;
end_typedef

begin_expr_stmt
name|udir_range
name|using_directives
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|// These are all defined in DependentDiagnostic.h.
end_comment

begin_decl_stmt
name|class
name|ddiag_iterator
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|DeclContext
operator|::
name|ddiag_iterator
operator|>
name|ddiag_range
expr_stmt|;
end_typedef

begin_expr_stmt
specifier|inline
name|ddiag_range
name|ddiags
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Low-level accessors
end_comment

begin_comment
comment|/// \brief Mark that there are external lexical declarations that we need
end_comment

begin_comment
comment|/// to include in our lookup table (and that are not available as external
end_comment

begin_comment
comment|/// visible lookups). These extra lookup results will be found by walking
end_comment

begin_comment
comment|/// the lexical declarations of this context. This should be used only if
end_comment

begin_comment
comment|/// setHasExternalLexicalStorage() has been called on any decl context for
end_comment

begin_comment
comment|/// which this is the primary context.
end_comment

begin_function
name|void
name|setMustBuildLookupTable
parameter_list|()
block|{
name|assert
argument_list|(
name|this
operator|==
name|getPrimaryContext
argument_list|()
operator|&&
literal|"should only be called on primary context"
argument_list|)
expr_stmt|;
name|HasLazyExternalLexicalLookups
operator|=
name|true
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Retrieve the internal representation of the lookup structure.
end_comment

begin_comment
comment|/// This may omit some names if we are lazily building the structure.
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
comment|/// \brief Ensure the lookup structure is fully-built and return it.
end_comment

begin_function_decl
name|StoredDeclsMap
modifier|*
name|buildLookup
parameter_list|()
function_decl|;
end_function_decl

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
if|if
condition|(
name|ES
operator|&&
name|LookupPtr
condition|)
name|NeedToReconcileExternalVisibleStorage
operator|=
name|true
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Determine whether the given declaration is stored in the list of
end_comment

begin_comment
comment|/// declarations lexically within this context.
end_comment

begin_decl_stmt
name|bool
name|isDeclInLexicalTraversal
argument_list|(
specifier|const
name|Decl
operator|*
name|D
argument_list|)
decl|const
block|{
return|return
name|D
operator|&&
operator|(
name|D
operator|->
name|NextInContextAndBits
operator|.
name|getPointer
argument_list|()
operator|||
name|D
operator|==
name|FirstDecl
operator|||
name|D
operator|==
name|LastDecl
operator|)
return|;
block|}
end_decl_stmt

begin_function
name|bool
name|setUseQualifiedLookup
parameter_list|(
name|bool
name|use
init|=
name|true
parameter_list|)
block|{
name|bool
name|old_value
init|=
name|UseQualifiedLookup
decl_stmt|;
name|UseQualifiedLookup
operator|=
name|use
expr_stmt|;
return|return
name|old_value
return|;
block|}
end_function

begin_expr_stmt
name|bool
name|shouldUseQualifiedLookup
argument_list|()
specifier|const
block|{
return|return
name|UseQualifiedLookup
return|;
block|}
end_expr_stmt

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

begin_expr_stmt
name|void
name|dumpDeclContext
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|void
name|dumpLookups
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|dumpLookups
argument_list|(
name|llvm
operator|::
name|raw_ostream
operator|&
name|OS
argument_list|,
name|bool
name|DumpDecls
operator|=
name|false
argument_list|,
name|bool
name|Deserialize
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|void
name|reconcileExternalVisibleStorage
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|LoadLexicalDeclsFromExternalStorage
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// @brief Makes a declaration visible within this context, but
end_comment

begin_comment
comment|/// suppresses searches for external declarations with the same
end_comment

begin_comment
comment|/// name.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Analogous to makeDeclVisibleInContext, but for the exclusive
end_comment

begin_comment
comment|/// use of addDeclInternal().
end_comment

begin_function_decl
name|void
name|makeDeclVisibleInContextInternal
parameter_list|(
name|NamedDecl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

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
name|buildLookupImpl
parameter_list|(
name|DeclContext
modifier|*
name|DCtx
parameter_list|,
name|bool
name|Internal
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|makeDeclVisibleInContextWithFlags
parameter_list|(
name|NamedDecl
modifier|*
name|D
parameter_list|,
name|bool
name|Internal
parameter_list|,
name|bool
name|Rediscoverable
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
parameter_list|,
name|bool
name|Internal
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
name|std
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
name|typename
name|To
operator|>
expr|struct
name|isa_impl
operator|<
name|To
operator|,
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
name|To
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

