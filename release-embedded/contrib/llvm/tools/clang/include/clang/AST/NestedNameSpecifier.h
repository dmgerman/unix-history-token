begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- NestedNameSpecifier.h - C++ nested name specifiers -----*- C++ -*-===//
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
comment|//  This file defines the NestedNameSpecifier class, which represents
end_comment

begin_comment
comment|//  a C++ nested-name-specifier.
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
name|LLVM_CLANG_AST_NESTEDNAMESPECIFIER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_NESTEDNAMESPECIFIER_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/Diagnostic.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/FoldingSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerIntPair.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|class
name|NamespaceAliasDecl
decl_stmt|;
name|class
name|NamespaceDecl
decl_stmt|;
name|class
name|IdentifierInfo
decl_stmt|;
struct_decl|struct
name|PrintingPolicy
struct_decl|;
name|class
name|Type
decl_stmt|;
name|class
name|TypeLoc
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
comment|/// \brief Represents a C++ nested name specifier, such as
comment|/// "\::std::vector<int>::".
comment|///
comment|/// C++ nested name specifiers are the prefixes to qualified
comment|/// namespaces. For example, "foo::" in "foo::x" is a nested name
comment|/// specifier. Nested name specifiers are made up of a sequence of
comment|/// specifiers, each of which can be a namespace, type, identifier
comment|/// (for dependent names), decltype specifier, or the global specifier ('::').
comment|/// The last two specifiers can only appear at the start of a
comment|/// nested-namespace-specifier.
name|class
name|NestedNameSpecifier
range|:
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
comment|/// \brief Enumeration describing
block|enum
name|StoredSpecifierKind
block|{
name|StoredIdentifier
operator|=
literal|0
block|,
name|StoredNamespaceOrAlias
operator|=
literal|1
block|,
name|StoredTypeSpec
operator|=
literal|2
block|,
name|StoredTypeSpecWithTemplate
operator|=
literal|3
block|}
block|;
comment|/// \brief The nested name specifier that precedes this nested name
comment|/// specifier.
comment|///
comment|/// The pointer is the nested-name-specifier that precedes this
comment|/// one. The integer stores one of the first four values of type
comment|/// SpecifierKind.
name|llvm
operator|::
name|PointerIntPair
operator|<
name|NestedNameSpecifier
operator|*
block|,
literal|2
block|,
name|StoredSpecifierKind
operator|>
name|Prefix
block|;
comment|/// \brief The last component in the nested name specifier, which
comment|/// can be an identifier, a declaration, or a type.
comment|///
comment|/// When the pointer is NULL, this specifier represents the global
comment|/// specifier '::'. Otherwise, the pointer is one of
comment|/// IdentifierInfo*, Namespace*, or Type*, depending on the kind of
comment|/// specifier as encoded within the prefix.
name|void
operator|*
name|Specifier
block|;
name|public
operator|:
comment|/// \brief The kind of specifier that completes this nested name
comment|/// specifier.
expr|enum
name|SpecifierKind
block|{
comment|/// \brief An identifier, stored as an IdentifierInfo*.
name|Identifier
block|,
comment|/// \brief A namespace, stored as a NamespaceDecl*.
name|Namespace
block|,
comment|/// \brief A namespace alias, stored as a NamespaceAliasDecl*.
name|NamespaceAlias
block|,
comment|/// \brief A type, stored as a Type*.
name|TypeSpec
block|,
comment|/// \brief A type that was preceded by the 'template' keyword,
comment|/// stored as a Type*.
name|TypeSpecWithTemplate
block|,
comment|/// \brief The global specifier '::'. There is no stored value.
name|Global
block|}
block|;
name|private
operator|:
comment|/// \brief Builds the global specifier.
name|NestedNameSpecifier
argument_list|()
operator|:
name|Prefix
argument_list|(
literal|0
argument_list|,
name|StoredIdentifier
argument_list|)
block|,
name|Specifier
argument_list|(
literal|0
argument_list|)
block|{ }
comment|/// \brief Copy constructor used internally to clone nested name
comment|/// specifiers.
name|NestedNameSpecifier
argument_list|(
specifier|const
name|NestedNameSpecifier
operator|&
name|Other
argument_list|)
operator|:
name|llvm
operator|::
name|FoldingSetNode
argument_list|(
name|Other
argument_list|)
block|,
name|Prefix
argument_list|(
name|Other
operator|.
name|Prefix
argument_list|)
block|,
name|Specifier
argument_list|(
argument|Other.Specifier
argument_list|)
block|{   }
name|void
name|operator
operator|=
operator|(
specifier|const
name|NestedNameSpecifier
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
block|;
comment|/// \brief Either find or insert the given nested name specifier
comment|/// mockup in the given context.
specifier|static
name|NestedNameSpecifier
operator|*
name|FindOrInsert
argument_list|(
specifier|const
name|ASTContext
operator|&
name|Context
argument_list|,
specifier|const
name|NestedNameSpecifier
operator|&
name|Mockup
argument_list|)
block|;
name|public
operator|:
comment|/// \brief Builds a specifier combining a prefix and an identifier.
comment|///
comment|/// The prefix must be dependent, since nested name specifiers
comment|/// referencing an identifier are only permitted when the identifier
comment|/// cannot be resolved.
specifier|static
name|NestedNameSpecifier
operator|*
name|Create
argument_list|(
specifier|const
name|ASTContext
operator|&
name|Context
argument_list|,
name|NestedNameSpecifier
operator|*
name|Prefix
argument_list|,
name|IdentifierInfo
operator|*
name|II
argument_list|)
block|;
comment|/// \brief Builds a nested name specifier that names a namespace.
specifier|static
name|NestedNameSpecifier
operator|*
name|Create
argument_list|(
specifier|const
name|ASTContext
operator|&
name|Context
argument_list|,
name|NestedNameSpecifier
operator|*
name|Prefix
argument_list|,
specifier|const
name|NamespaceDecl
operator|*
name|NS
argument_list|)
block|;
comment|/// \brief Builds a nested name specifier that names a namespace alias.
specifier|static
name|NestedNameSpecifier
operator|*
name|Create
argument_list|(
specifier|const
name|ASTContext
operator|&
name|Context
argument_list|,
name|NestedNameSpecifier
operator|*
name|Prefix
argument_list|,
name|NamespaceAliasDecl
operator|*
name|Alias
argument_list|)
block|;
comment|/// \brief Builds a nested name specifier that names a type.
specifier|static
name|NestedNameSpecifier
operator|*
name|Create
argument_list|(
argument|const ASTContext&Context
argument_list|,
argument|NestedNameSpecifier *Prefix
argument_list|,
argument|bool Template
argument_list|,
argument|const Type *T
argument_list|)
block|;
comment|/// \brief Builds a specifier that consists of just an identifier.
comment|///
comment|/// The nested-name-specifier is assumed to be dependent, but has no
comment|/// prefix because the prefix is implied by something outside of the
comment|/// nested name specifier, e.g., in "x->Base::f", the "x" has a dependent
comment|/// type.
specifier|static
name|NestedNameSpecifier
operator|*
name|Create
argument_list|(
specifier|const
name|ASTContext
operator|&
name|Context
argument_list|,
name|IdentifierInfo
operator|*
name|II
argument_list|)
block|;
comment|/// \brief Returns the nested name specifier representing the global
comment|/// scope.
specifier|static
name|NestedNameSpecifier
operator|*
name|GlobalSpecifier
argument_list|(
specifier|const
name|ASTContext
operator|&
name|Context
argument_list|)
block|;
comment|/// \brief Return the prefix of this nested name specifier.
comment|///
comment|/// The prefix contains all of the parts of the nested name
comment|/// specifier that preced this current specifier. For example, for a
comment|/// nested name specifier that represents "foo::bar::", the current
comment|/// specifier will contain "bar::" and the prefix will contain
comment|/// "foo::".
name|NestedNameSpecifier
operator|*
name|getPrefix
argument_list|()
specifier|const
block|{
return|return
name|Prefix
operator|.
name|getPointer
argument_list|()
return|;
block|}
comment|/// \brief Determine what kind of nested name specifier is stored.
name|SpecifierKind
name|getKind
argument_list|()
specifier|const
block|;
comment|/// \brief Retrieve the identifier stored in this nested name
comment|/// specifier.
name|IdentifierInfo
operator|*
name|getAsIdentifier
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Prefix
operator|.
name|getInt
argument_list|()
operator|==
name|StoredIdentifier
condition|)
return|return
operator|(
name|IdentifierInfo
operator|*
operator|)
name|Specifier
return|;
return|return
literal|0
return|;
block|}
comment|/// \brief Retrieve the namespace stored in this nested name
comment|/// specifier.
name|NamespaceDecl
operator|*
name|getAsNamespace
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Retrieve the namespace alias stored in this nested name
comment|/// specifier.
name|NamespaceAliasDecl
operator|*
name|getAsNamespaceAlias
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Retrieve the type stored in this nested name specifier.
specifier|const
name|Type
operator|*
name|getAsType
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Prefix
operator|.
name|getInt
argument_list|()
operator|==
name|StoredTypeSpec
operator|||
name|Prefix
operator|.
name|getInt
argument_list|()
operator|==
name|StoredTypeSpecWithTemplate
condition|)
return|return
operator|(
specifier|const
name|Type
operator|*
operator|)
name|Specifier
return|;
return|return
literal|0
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Whether this nested name specifier refers to a dependent
end_comment

begin_comment
comment|/// type or not.
end_comment

begin_expr_stmt
name|bool
name|isDependent
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Whether this nested name specifier involves a template
end_comment

begin_comment
comment|/// parameter.
end_comment

begin_expr_stmt
name|bool
name|isInstantiationDependent
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Whether this nested-name-specifier contains an unexpanded
end_comment

begin_comment
comment|/// parameter pack (for C++11 variadic templates).
end_comment

begin_expr_stmt
name|bool
name|containsUnexpandedParameterPack
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Print this nested name specifier to the given output
end_comment

begin_comment
comment|/// stream.
end_comment

begin_decl_stmt
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|PrintingPolicy
operator|&
name|Policy
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Profile
argument_list|(
name|llvm
operator|::
name|FoldingSetNodeID
operator|&
name|ID
argument_list|)
decl|const
block|{
name|ID
operator|.
name|AddPointer
argument_list|(
name|Prefix
operator|.
name|getOpaqueValue
argument_list|()
argument_list|)
expr_stmt|;
name|ID
operator|.
name|AddPointer
argument_list|(
name|Specifier
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Dump the nested name specifier to standard output to aid
end_comment

begin_comment
comment|/// in debugging.
end_comment

begin_function_decl
name|void
name|dump
parameter_list|(
specifier|const
name|LangOptions
modifier|&
name|LO
parameter_list|)
function_decl|;
end_function_decl

begin_comment
unit|};
comment|/// \brief A C++ nested-name-specifier augmented with source location
end_comment

begin_comment
comment|/// information.
end_comment

begin_decl_stmt
name|class
name|NestedNameSpecifierLoc
block|{
name|NestedNameSpecifier
modifier|*
name|Qualifier
decl_stmt|;
name|void
modifier|*
name|Data
decl_stmt|;
comment|/// \brief Determines the data length for the last component in the
comment|/// given nested-name-specifier.
specifier|static
name|unsigned
name|getLocalDataLength
parameter_list|(
name|NestedNameSpecifier
modifier|*
name|Qualifier
parameter_list|)
function_decl|;
comment|/// \brief Determines the data length for the entire
comment|/// nested-name-specifier.
specifier|static
name|unsigned
name|getDataLength
parameter_list|(
name|NestedNameSpecifier
modifier|*
name|Qualifier
parameter_list|)
function_decl|;
name|public
label|:
comment|/// \brief Construct an empty nested-name-specifier.
name|NestedNameSpecifierLoc
argument_list|()
operator|:
name|Qualifier
argument_list|(
literal|0
argument_list|)
operator|,
name|Data
argument_list|(
literal|0
argument_list|)
block|{ }
comment|/// \brief Construct a nested-name-specifier with source location information
comment|/// from
name|NestedNameSpecifierLoc
argument_list|(
name|NestedNameSpecifier
operator|*
name|Qualifier
argument_list|,
name|void
operator|*
name|Data
argument_list|)
operator|:
name|Qualifier
argument_list|(
name|Qualifier
argument_list|)
operator|,
name|Data
argument_list|(
argument|Data
argument_list|)
block|{ }
comment|/// \brief Evalutes true when this nested-name-specifier location is
comment|/// non-empty.
name|LLVM_EXPLICIT
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|Qualifier
return|;
block|}
comment|/// \brief Evalutes true when this nested-name-specifier location is
comment|/// empty.
name|bool
name|hasQualifier
argument_list|()
specifier|const
block|{
return|return
name|Qualifier
return|;
block|}
comment|/// \brief Retrieve the nested-name-specifier to which this instance
comment|/// refers.
name|NestedNameSpecifier
operator|*
name|getNestedNameSpecifier
argument_list|()
specifier|const
block|{
return|return
name|Qualifier
return|;
block|}
comment|/// \brief Retrieve the opaque pointer that refers to source-location data.
name|void
operator|*
name|getOpaqueData
argument_list|()
specifier|const
block|{
return|return
name|Data
return|;
block|}
comment|/// \brief Retrieve the source range covering the entirety of this
comment|/// nested-name-specifier.
comment|///
comment|/// For example, if this instance refers to a nested-name-specifier
comment|/// \c \::std::vector<int>::, the returned source range would cover
comment|/// from the initial '::' to the last '::'.
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|LLVM_READONLY
expr_stmt|;
comment|/// \brief Retrieve the source range covering just the last part of
comment|/// this nested-name-specifier, not including the prefix.
comment|///
comment|/// For example, if this instance refers to a nested-name-specifier
comment|/// \c \::std::vector<int>::, the returned source range would cover
comment|/// from "vector" to the last '::'.
name|SourceRange
name|getLocalSourceRange
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Retrieve the location of the beginning of this
comment|/// nested-name-specifier.
name|SourceLocation
name|getBeginLoc
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
comment|/// \brief Retrieve the location of the end of this
comment|/// nested-name-specifier.
name|SourceLocation
name|getEndLoc
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
comment|/// \brief Retrieve the location of the beginning of this
comment|/// component of the nested-name-specifier.
name|SourceLocation
name|getLocalBeginLoc
argument_list|()
specifier|const
block|{
return|return
name|getLocalSourceRange
argument_list|()
operator|.
name|getBegin
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the location of the end of this component of the
comment|/// nested-name-specifier.
name|SourceLocation
name|getLocalEndLoc
argument_list|()
specifier|const
block|{
return|return
name|getLocalSourceRange
argument_list|()
operator|.
name|getEnd
argument_list|()
return|;
block|}
comment|/// \brief Return the prefix of this nested-name-specifier.
comment|///
comment|/// For example, if this instance refers to a nested-name-specifier
comment|/// \c \::std::vector<int>::, the prefix is \c \::std::. Note that the
comment|/// returned prefix may be empty, if this is the first component of
comment|/// the nested-name-specifier.
name|NestedNameSpecifierLoc
name|getPrefix
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|Qualifier
condition|)
return|return
operator|*
name|this
return|;
return|return
name|NestedNameSpecifierLoc
argument_list|(
name|Qualifier
operator|->
name|getPrefix
argument_list|()
argument_list|,
name|Data
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief For a nested-name-specifier that refers to a type,
end_comment

begin_comment
comment|/// retrieve the type with source-location information.
end_comment

begin_expr_stmt
name|TypeLoc
name|getTypeLoc
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Determines the data length for the entire
end_comment

begin_comment
comment|/// nested-name-specifier.
end_comment

begin_expr_stmt
name|unsigned
name|getDataLength
argument_list|()
specifier|const
block|{
return|return
name|getDataLength
argument_list|(
name|Qualifier
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
name|bool
name|operator
operator|==
operator|(
name|NestedNameSpecifierLoc
name|X
operator|,
name|NestedNameSpecifierLoc
name|Y
operator|)
block|{
return|return
name|X
operator|.
name|Qualifier
operator|==
name|Y
operator|.
name|Qualifier
operator|&&
name|X
operator|.
name|Data
operator|==
name|Y
operator|.
name|Data
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
name|bool
name|operator
operator|!=
operator|(
name|NestedNameSpecifierLoc
name|X
operator|,
name|NestedNameSpecifierLoc
name|Y
operator|)
block|{
return|return
operator|!
operator|(
name|X
operator|==
name|Y
operator|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// \brief Class that aids in the construction of nested-name-specifiers along
end_comment

begin_comment
comment|/// with source-location information for all of the components of the
end_comment

begin_comment
comment|/// nested-name-specifier.
end_comment

begin_decl_stmt
name|class
name|NestedNameSpecifierLocBuilder
block|{
comment|/// \brief The current representation of the nested-name-specifier we're
comment|/// building.
name|NestedNameSpecifier
modifier|*
name|Representation
decl_stmt|;
comment|/// \brief Buffer used to store source-location information for the
comment|/// nested-name-specifier.
comment|///
comment|/// Note that we explicitly manage the buffer (rather than using a
comment|/// SmallVector) because \c Declarator expects it to be possible to memcpy()
comment|/// a \c CXXScopeSpec, and CXXScopeSpec uses a NestedNameSpecifierLocBuilder.
name|char
modifier|*
name|Buffer
decl_stmt|;
comment|/// \brief The size of the buffer used to store source-location information
comment|/// for the nested-name-specifier.
name|unsigned
name|BufferSize
decl_stmt|;
comment|/// \brief The capacity of the buffer used to store source-location
comment|/// information for the nested-name-specifier.
name|unsigned
name|BufferCapacity
decl_stmt|;
name|public
label|:
name|NestedNameSpecifierLocBuilder
argument_list|()
operator|:
name|Representation
argument_list|(
literal|0
argument_list|)
operator|,
name|Buffer
argument_list|(
literal|0
argument_list|)
operator|,
name|BufferSize
argument_list|(
literal|0
argument_list|)
operator|,
name|BufferCapacity
argument_list|(
literal|0
argument_list|)
block|{ }
name|NestedNameSpecifierLocBuilder
argument_list|(
specifier|const
name|NestedNameSpecifierLocBuilder
operator|&
name|Other
argument_list|)
expr_stmt|;
name|NestedNameSpecifierLocBuilder
modifier|&
name|operator
init|=
operator|(
specifier|const
name|NestedNameSpecifierLocBuilder
operator|&
name|Other
operator|)
decl_stmt|;
operator|~
name|NestedNameSpecifierLocBuilder
argument_list|()
block|{
if|if
condition|(
name|BufferCapacity
condition|)
name|free
argument_list|(
name|Buffer
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Retrieve the representation of the nested-name-specifier.
name|NestedNameSpecifier
operator|*
name|getRepresentation
argument_list|()
specifier|const
block|{
return|return
name|Representation
return|;
block|}
comment|/// \brief Extend the current nested-name-specifier by another
comment|/// nested-name-specifier component of the form 'type::'.
comment|///
comment|/// \param Context The AST context in which this nested-name-specifier
comment|/// resides.
comment|///
comment|/// \param TemplateKWLoc The location of the 'template' keyword, if present.
comment|///
comment|/// \param TL The TypeLoc that describes the type preceding the '::'.
comment|///
comment|/// \param ColonColonLoc The location of the trailing '::'.
name|void
name|Extend
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|,
name|SourceLocation
name|TemplateKWLoc
parameter_list|,
name|TypeLoc
name|TL
parameter_list|,
name|SourceLocation
name|ColonColonLoc
parameter_list|)
function_decl|;
comment|/// \brief Extend the current nested-name-specifier by another
comment|/// nested-name-specifier component of the form 'identifier::'.
comment|///
comment|/// \param Context The AST context in which this nested-name-specifier
comment|/// resides.
comment|///
comment|/// \param Identifier The identifier.
comment|///
comment|/// \param IdentifierLoc The location of the identifier.
comment|///
comment|/// \param ColonColonLoc The location of the trailing '::'.
name|void
name|Extend
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|,
name|IdentifierInfo
modifier|*
name|Identifier
parameter_list|,
name|SourceLocation
name|IdentifierLoc
parameter_list|,
name|SourceLocation
name|ColonColonLoc
parameter_list|)
function_decl|;
comment|/// \brief Extend the current nested-name-specifier by another
comment|/// nested-name-specifier component of the form 'namespace::'.
comment|///
comment|/// \param Context The AST context in which this nested-name-specifier
comment|/// resides.
comment|///
comment|/// \param Namespace The namespace.
comment|///
comment|/// \param NamespaceLoc The location of the namespace name.
comment|///
comment|/// \param ColonColonLoc The location of the trailing '::'.
name|void
name|Extend
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|,
name|NamespaceDecl
modifier|*
name|Namespace
parameter_list|,
name|SourceLocation
name|NamespaceLoc
parameter_list|,
name|SourceLocation
name|ColonColonLoc
parameter_list|)
function_decl|;
comment|/// \brief Extend the current nested-name-specifier by another
comment|/// nested-name-specifier component of the form 'namespace-alias::'.
comment|///
comment|/// \param Context The AST context in which this nested-name-specifier
comment|/// resides.
comment|///
comment|/// \param Alias The namespace alias.
comment|///
comment|/// \param AliasLoc The location of the namespace alias
comment|/// name.
comment|///
comment|/// \param ColonColonLoc The location of the trailing '::'.
name|void
name|Extend
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|,
name|NamespaceAliasDecl
modifier|*
name|Alias
parameter_list|,
name|SourceLocation
name|AliasLoc
parameter_list|,
name|SourceLocation
name|ColonColonLoc
parameter_list|)
function_decl|;
comment|/// \brief Turn this (empty) nested-name-specifier into the global
comment|/// nested-name-specifier '::'.
name|void
name|MakeGlobal
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|,
name|SourceLocation
name|ColonColonLoc
parameter_list|)
function_decl|;
comment|/// \brief Make a new nested-name-specifier from incomplete source-location
comment|/// information.
comment|///
comment|/// This routine should be used very, very rarely, in cases where we
comment|/// need to synthesize a nested-name-specifier. Most code should instead use
comment|/// \c Adopt() with a proper \c NestedNameSpecifierLoc.
name|void
name|MakeTrivial
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|,
name|NestedNameSpecifier
modifier|*
name|Qualifier
parameter_list|,
name|SourceRange
name|R
parameter_list|)
function_decl|;
comment|/// \brief Adopt an existing nested-name-specifier (with source-range
comment|/// information).
name|void
name|Adopt
parameter_list|(
name|NestedNameSpecifierLoc
name|Other
parameter_list|)
function_decl|;
comment|/// \brief Retrieve the source range covered by this nested-name-specifier.
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|NestedNameSpecifierLoc
argument_list|(
name|Representation
argument_list|,
name|Buffer
argument_list|)
operator|.
name|getSourceRange
argument_list|()
return|;
block|}
comment|/// \brief Retrieve a nested-name-specifier with location information,
comment|/// copied into the given AST context.
comment|///
comment|/// \param Context The context into which this nested-name-specifier will be
comment|/// copied.
name|NestedNameSpecifierLoc
name|getWithLocInContext
argument_list|(
name|ASTContext
operator|&
name|Context
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Retrieve a nested-name-specifier with location
comment|/// information based on the information in this builder.
comment|///
comment|/// This loc will contain references to the builder's internal data and may
comment|/// be invalidated by any change to the builder.
name|NestedNameSpecifierLoc
name|getTemporary
argument_list|()
specifier|const
block|{
return|return
name|NestedNameSpecifierLoc
argument_list|(
name|Representation
argument_list|,
name|Buffer
argument_list|)
return|;
block|}
comment|/// \brief Clear out this builder, and prepare it to build another
comment|/// nested-name-specifier with source-location information.
name|void
name|Clear
parameter_list|()
block|{
name|Representation
operator|=
literal|0
expr_stmt|;
name|BufferSize
operator|=
literal|0
expr_stmt|;
block|}
comment|/// \brief Retrieve the underlying buffer.
comment|///
comment|/// \returns A pair containing a pointer to the buffer of source-location
comment|/// data and the size of the source-location data that resides in that
comment|/// buffer.
name|std
operator|::
name|pair
operator|<
name|char
operator|*
operator|,
name|unsigned
operator|>
name|getBuffer
argument_list|()
specifier|const
block|{
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|Buffer
argument_list|,
name|BufferSize
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// Insertion operator for diagnostics.  This allows sending
end_comment

begin_comment
comment|/// NestedNameSpecifiers into a diagnostic with<<.
end_comment

begin_expr_stmt
specifier|inline
specifier|const
name|DiagnosticBuilder
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|DiagnosticBuilder
operator|&
name|DB
operator|,
name|NestedNameSpecifier
operator|*
name|NNS
operator|)
block|{
name|DB
operator|.
name|AddTaggedVal
argument_list|(
name|reinterpret_cast
operator|<
name|intptr_t
operator|>
operator|(
name|NNS
operator|)
argument_list|,
name|DiagnosticsEngine
operator|::
name|ak_nestednamespec
argument_list|)
block|;
return|return
name|DB
return|;
block|}
end_expr_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

