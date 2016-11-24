begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- TemplateName.h - C++ Template Name Representation-------*- C++ -*-===//
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
comment|//  This file defines the TemplateName interface and subclasses.
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
name|LLVM_CLANG_AST_TEMPLATENAME_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_TEMPLATENAME_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/NestedNameSpecifier.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/FoldingSet.h"
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
name|ASTContext
decl_stmt|;
name|class
name|DependentTemplateName
decl_stmt|;
name|class
name|DiagnosticBuilder
decl_stmt|;
name|class
name|IdentifierInfo
decl_stmt|;
name|class
name|NamedDecl
decl_stmt|;
name|class
name|NestedNameSpecifier
decl_stmt|;
enum_decl|enum
name|OverloadedOperatorKind
enum_decl|:
name|int
enum_decl|;
name|class
name|OverloadedTemplateStorage
decl_stmt|;
struct_decl|struct
name|PrintingPolicy
struct_decl|;
name|class
name|QualifiedTemplateName
decl_stmt|;
name|class
name|SubstTemplateTemplateParmPackStorage
decl_stmt|;
name|class
name|SubstTemplateTemplateParmStorage
decl_stmt|;
name|class
name|TemplateArgument
decl_stmt|;
name|class
name|TemplateDecl
decl_stmt|;
name|class
name|TemplateTemplateParmDecl
decl_stmt|;
comment|/// \brief Implementation class used to describe either a set of overloaded
comment|/// template names or an already-substituted template template parameter pack.
name|class
name|UncommonTemplateNameStorage
block|{
name|protected
label|:
enum|enum
name|Kind
block|{
name|Overloaded
block|,
name|SubstTemplateTemplateParm
block|,
name|SubstTemplateTemplateParmPack
block|}
enum|;
struct|struct
name|BitsTag
block|{
comment|/// \brief A Kind.
name|unsigned
name|Kind
range|:
literal|2
decl_stmt|;
comment|/// \brief The number of stored templates or template arguments,
comment|/// depending on which subclass we have.
name|unsigned
name|Size
range|:
literal|30
decl_stmt|;
block|}
struct|;
union|union
block|{
name|struct
name|BitsTag
name|Bits
decl_stmt|;
name|void
modifier|*
name|PointerAlignment
decl_stmt|;
block|}
union|;
name|UncommonTemplateNameStorage
argument_list|(
argument|Kind kind
argument_list|,
argument|unsigned size
argument_list|)
block|{
name|Bits
operator|.
name|Kind
operator|=
name|kind
expr_stmt|;
name|Bits
operator|.
name|Size
operator|=
name|size
expr_stmt|;
block|}
name|public
label|:
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
name|Bits
operator|.
name|Size
return|;
block|}
name|OverloadedTemplateStorage
modifier|*
name|getAsOverloadedStorage
parameter_list|()
block|{
return|return
name|Bits
operator|.
name|Kind
operator|==
name|Overloaded
condition|?
name|reinterpret_cast
operator|<
name|OverloadedTemplateStorage
operator|*
operator|>
operator|(
name|this
operator|)
else|:
name|nullptr
return|;
block|}
name|SubstTemplateTemplateParmStorage
modifier|*
name|getAsSubstTemplateTemplateParm
parameter_list|()
block|{
return|return
name|Bits
operator|.
name|Kind
operator|==
name|SubstTemplateTemplateParm
condition|?
name|reinterpret_cast
operator|<
name|SubstTemplateTemplateParmStorage
operator|*
operator|>
operator|(
name|this
operator|)
else|:
name|nullptr
return|;
block|}
name|SubstTemplateTemplateParmPackStorage
modifier|*
name|getAsSubstTemplateTemplateParmPack
parameter_list|()
block|{
return|return
name|Bits
operator|.
name|Kind
operator|==
name|SubstTemplateTemplateParmPack
condition|?
name|reinterpret_cast
operator|<
name|SubstTemplateTemplateParmPackStorage
operator|*
operator|>
operator|(
name|this
operator|)
else|:
name|nullptr
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief A structure for storing the information associated with an
comment|/// overloaded template name.
name|class
name|OverloadedTemplateStorage
range|:
name|public
name|UncommonTemplateNameStorage
block|{
name|friend
name|class
name|ASTContext
block|;
name|OverloadedTemplateStorage
argument_list|(
argument|unsigned size
argument_list|)
operator|:
name|UncommonTemplateNameStorage
argument_list|(
argument|Overloaded
argument_list|,
argument|size
argument_list|)
block|{ }
name|NamedDecl
operator|*
operator|*
name|getStorage
argument_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|NamedDecl
operator|*
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
name|NamedDecl
operator|*
specifier|const
operator|*
name|getStorage
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
name|NamedDecl
operator|*
specifier|const
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
name|public
operator|:
typedef|typedef
name|NamedDecl
modifier|*
specifier|const
modifier|*
name|iterator
typedef|;
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|getStorage
argument_list|()
return|;
block|}
name|iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|getStorage
argument_list|()
operator|+
name|size
argument_list|()
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief A structure for storing an already-substituted template template
comment|/// parameter pack.
comment|///
comment|/// This kind of template names occurs when the parameter pack has been
comment|/// provided with a template template argument pack in a context where its
comment|/// enclosing pack expansion could not be fully expanded.
name|class
name|SubstTemplateTemplateParmPackStorage
range|:
name|public
name|UncommonTemplateNameStorage
decl_stmt|,
name|public
name|llvm
decl|::
name|FoldingSetNode
block|{
name|TemplateTemplateParmDecl
modifier|*
name|Parameter
decl_stmt|;
specifier|const
name|TemplateArgument
modifier|*
name|Arguments
decl_stmt|;
name|public
label|:
name|SubstTemplateTemplateParmPackStorage
argument_list|(
argument|TemplateTemplateParmDecl *Parameter
argument_list|,
argument|unsigned Size
argument_list|,
argument|const TemplateArgument *Arguments
argument_list|)
block|:
name|UncommonTemplateNameStorage
argument_list|(
name|SubstTemplateTemplateParmPack
argument_list|,
name|Size
argument_list|)
operator|,
name|Parameter
argument_list|(
name|Parameter
argument_list|)
operator|,
name|Arguments
argument_list|(
argument|Arguments
argument_list|)
block|{ }
comment|/// \brief Retrieve the template template parameter pack being substituted.
name|TemplateTemplateParmDecl
operator|*
name|getParameterPack
argument_list|()
specifier|const
block|{
return|return
name|Parameter
return|;
block|}
comment|/// \brief Retrieve the template template argument pack with which this
comment|/// parameter was substituted.
name|TemplateArgument
name|getArgumentPack
argument_list|()
specifier|const
expr_stmt|;
name|void
name|Profile
argument_list|(
name|llvm
operator|::
name|FoldingSetNodeID
operator|&
name|ID
argument_list|,
name|ASTContext
operator|&
name|Context
argument_list|)
decl_stmt|;
specifier|static
name|void
name|Profile
argument_list|(
name|llvm
operator|::
name|FoldingSetNodeID
operator|&
name|ID
argument_list|,
name|ASTContext
operator|&
name|Context
argument_list|,
name|TemplateTemplateParmDecl
operator|*
name|Parameter
argument_list|,
specifier|const
name|TemplateArgument
operator|&
name|ArgPack
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
comment|/// \brief Represents a C++ template name within the type system.
comment|///
comment|/// A C++ template name refers to a template within the C++ type
comment|/// system. In most cases, a template name is simply a reference to a
comment|/// class template, e.g.
comment|///
comment|/// \code
comment|/// template<typename T> class X { };
comment|///
comment|/// X<int> xi;
comment|/// \endcode
comment|///
comment|/// Here, the 'X' in \c X<int> is a template name that refers to the
comment|/// declaration of the class template X, above. Template names can
comment|/// also refer to function templates, C++0x template aliases, etc.
comment|///
comment|/// Some template names are dependent. For example, consider:
comment|///
comment|/// \code
comment|/// template<typename MetaFun, typename T1, typename T2> struct apply2 {
comment|///   typedef typename MetaFun::template apply<T1, T2>::type type;
comment|/// };
comment|/// \endcode
comment|///
comment|/// Here, "apply" is treated as a template name within the typename
comment|/// specifier in the typedef. "apply" is a nested template, and can
comment|/// only be understood in the context of
name|class
name|TemplateName
block|{
typedef|typedef
name|llvm
operator|::
name|PointerUnion4
operator|<
name|TemplateDecl
operator|*
operator|,
name|UncommonTemplateNameStorage
operator|*
operator|,
name|QualifiedTemplateName
operator|*
operator|,
name|DependentTemplateName
operator|*
operator|>
name|StorageType
expr_stmt|;
name|StorageType
name|Storage
decl_stmt|;
name|explicit
name|TemplateName
parameter_list|(
name|void
modifier|*
name|Ptr
parameter_list|)
function_decl|;
name|public
label|:
comment|// \brief Kind of name that is actually stored.
enum|enum
name|NameKind
block|{
comment|/// \brief A single template declaration.
name|Template
block|,
comment|/// \brief A set of overloaded template declarations.
name|OverloadedTemplate
block|,
comment|/// \brief A qualified template name, where the qualification is kept
comment|/// to describe the source code as written.
name|QualifiedTemplate
block|,
comment|/// \brief A dependent template name that has not been resolved to a
comment|/// template (or set of templates).
name|DependentTemplate
block|,
comment|/// \brief A template template parameter that has been substituted
comment|/// for some other template name.
name|SubstTemplateTemplateParm
block|,
comment|/// \brief A template template parameter pack that has been substituted for
comment|/// a template template argument pack, but has not yet been expanded into
comment|/// individual arguments.
name|SubstTemplateTemplateParmPack
block|}
enum|;
name|TemplateName
argument_list|()
operator|:
name|Storage
argument_list|()
block|{ }
name|explicit
name|TemplateName
argument_list|(
name|TemplateDecl
operator|*
name|Template
argument_list|)
expr_stmt|;
name|explicit
name|TemplateName
parameter_list|(
name|OverloadedTemplateStorage
modifier|*
name|Storage
parameter_list|)
function_decl|;
name|explicit
name|TemplateName
parameter_list|(
name|SubstTemplateTemplateParmStorage
modifier|*
name|Storage
parameter_list|)
function_decl|;
name|explicit
name|TemplateName
parameter_list|(
name|SubstTemplateTemplateParmPackStorage
modifier|*
name|Storage
parameter_list|)
function_decl|;
name|explicit
name|TemplateName
parameter_list|(
name|QualifiedTemplateName
modifier|*
name|Qual
parameter_list|)
function_decl|;
name|explicit
name|TemplateName
parameter_list|(
name|DependentTemplateName
modifier|*
name|Dep
parameter_list|)
function_decl|;
comment|/// \brief Determine whether this template name is NULL.
name|bool
name|isNull
argument_list|()
specifier|const
expr_stmt|;
comment|// \brief Get the kind of name that is actually stored.
name|NameKind
name|getKind
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Retrieve the underlying template declaration that
comment|/// this template name refers to, if known.
comment|///
comment|/// \returns The template declaration that this template name refers
comment|/// to, if any. If the template name does not refer to a specific
comment|/// declaration because it is a dependent name, or if it refers to a
comment|/// set of function templates, returns NULL.
name|TemplateDecl
operator|*
name|getAsTemplateDecl
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Retrieve the underlying, overloaded function template
comment|// declarations that this template name refers to, if known.
comment|///
comment|/// \returns The set of overloaded function templates that this template
comment|/// name refers to, if known. If the template name does not refer to a
comment|/// specific set of function templates because it is a dependent name or
comment|/// refers to a single template, returns NULL.
name|OverloadedTemplateStorage
operator|*
name|getAsOverloadedTemplate
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Retrieve the substituted template template parameter, if
comment|/// known.
comment|///
comment|/// \returns The storage for the substituted template template parameter,
comment|/// if known. Otherwise, returns NULL.
name|SubstTemplateTemplateParmStorage
operator|*
name|getAsSubstTemplateTemplateParm
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Retrieve the substituted template template parameter pack, if
comment|/// known.
comment|///
comment|/// \returns The storage for the substituted template template parameter pack,
comment|/// if known. Otherwise, returns NULL.
name|SubstTemplateTemplateParmPackStorage
operator|*
name|getAsSubstTemplateTemplateParmPack
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Retrieve the underlying qualified template name
comment|/// structure, if any.
name|QualifiedTemplateName
operator|*
name|getAsQualifiedTemplateName
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Retrieve the underlying dependent template name
comment|/// structure, if any.
name|DependentTemplateName
operator|*
name|getAsDependentTemplateName
argument_list|()
specifier|const
expr_stmt|;
name|TemplateName
name|getUnderlying
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determines whether this is a dependent template name.
name|bool
name|isDependent
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determines whether this is a template name that somehow
comment|/// depends on a template parameter.
name|bool
name|isInstantiationDependent
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determines whether this template name contains an
comment|/// unexpanded parameter pack (for C++0x variadic templates).
name|bool
name|containsUnexpandedParameterPack
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Print the template name.
comment|///
comment|/// \param OS the output stream to which the template name will be
comment|/// printed.
comment|///
comment|/// \param SuppressNNS if true, don't print the
comment|/// nested-name-specifier that precedes the template name (if it has
comment|/// one).
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
argument_list|,
name|bool
name|SuppressNNS
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Debugging aid that dumps the template name.
name|void
name|dump
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Debugging aid that dumps the template name to standard
comment|/// error.
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
name|void
name|Profile
argument_list|(
name|llvm
operator|::
name|FoldingSetNodeID
operator|&
name|ID
argument_list|)
block|{
name|ID
operator|.
name|AddPointer
argument_list|(
name|Storage
operator|.
name|getOpaqueValue
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Retrieve the template name as a void pointer.
name|void
operator|*
name|getAsVoidPointer
argument_list|()
specifier|const
block|{
return|return
name|Storage
operator|.
name|getOpaqueValue
argument_list|()
return|;
block|}
comment|/// \brief Build a template name from a void pointer.
specifier|static
name|TemplateName
name|getFromVoidPointer
parameter_list|(
name|void
modifier|*
name|Ptr
parameter_list|)
block|{
return|return
name|TemplateName
argument_list|(
name|Ptr
argument_list|)
return|;
block|}
block|}
empty_stmt|;
comment|/// Insertion operator for diagnostics.  This allows sending TemplateName's
comment|/// into a diagnostic with<<.
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
name|TemplateName
name|N
operator|)
expr_stmt|;
comment|/// \brief A structure for storing the information associated with a
comment|/// substituted template template parameter.
name|class
name|SubstTemplateTemplateParmStorage
range|:
name|public
name|UncommonTemplateNameStorage
decl_stmt|,
name|public
name|llvm
decl|::
name|FoldingSetNode
block|{
name|friend
name|class
name|ASTContext
decl_stmt|;
name|TemplateTemplateParmDecl
modifier|*
name|Parameter
decl_stmt|;
name|TemplateName
name|Replacement
decl_stmt|;
name|SubstTemplateTemplateParmStorage
argument_list|(
argument|TemplateTemplateParmDecl *parameter
argument_list|,
argument|TemplateName replacement
argument_list|)
block|:
name|UncommonTemplateNameStorage
argument_list|(
name|SubstTemplateTemplateParm
argument_list|,
literal|0
argument_list|)
operator|,
name|Parameter
argument_list|(
name|parameter
argument_list|)
operator|,
name|Replacement
argument_list|(
argument|replacement
argument_list|)
block|{}
name|public
operator|:
name|TemplateTemplateParmDecl
operator|*
name|getParameter
argument_list|()
specifier|const
block|{
return|return
name|Parameter
return|;
block|}
name|TemplateName
name|getReplacement
argument_list|()
specifier|const
block|{
return|return
name|Replacement
return|;
block|}
name|void
name|Profile
argument_list|(
name|llvm
operator|::
name|FoldingSetNodeID
operator|&
name|ID
argument_list|)
decl_stmt|;
specifier|static
name|void
name|Profile
argument_list|(
name|llvm
operator|::
name|FoldingSetNodeID
operator|&
name|ID
argument_list|,
name|TemplateTemplateParmDecl
operator|*
name|parameter
argument_list|,
name|TemplateName
name|replacement
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
specifier|inline
name|TemplateName
name|TemplateName
operator|::
name|getUnderlying
argument_list|()
specifier|const
block|{
if|if
condition|(
name|SubstTemplateTemplateParmStorage
modifier|*
name|subst
init|=
name|getAsSubstTemplateTemplateParm
argument_list|()
condition|)
return|return
name|subst
operator|->
name|getReplacement
argument_list|()
operator|.
name|getUnderlying
argument_list|()
return|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Represents a template name that was expressed as a
end_comment

begin_comment
comment|/// qualified name.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This kind of template name refers to a template name that was
end_comment

begin_comment
comment|/// preceded by a nested name specifier, e.g., \c std::vector. Here,
end_comment

begin_comment
comment|/// the nested name specifier is "std::" and the template name is the
end_comment

begin_comment
comment|/// declaration for "vector". The QualifiedTemplateName class is only
end_comment

begin_comment
comment|/// used to provide "sugar" for template names that were expressed
end_comment

begin_comment
comment|/// with a qualified name, and has no semantic meaning. In this
end_comment

begin_comment
comment|/// manner, it is to TemplateName what ElaboratedType is to Type,
end_comment

begin_comment
comment|/// providing extra syntactic sugar for downstream clients.
end_comment

begin_decl_stmt
name|class
name|QualifiedTemplateName
range|:
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
comment|/// \brief The nested name specifier that qualifies the template name.
comment|///
comment|/// The bit is used to indicate whether the "template" keyword was
comment|/// present before the template name itself. Note that the
comment|/// "template" keyword is always redundant in this case (otherwise,
comment|/// the template name would be a dependent name and we would express
comment|/// this name with DependentTemplateName).
name|llvm
operator|::
name|PointerIntPair
operator|<
name|NestedNameSpecifier
operator|*
block|,
literal|1
operator|>
name|Qualifier
block|;
comment|/// \brief The template declaration or set of overloaded function templates
comment|/// that this qualified name refers to.
name|TemplateDecl
operator|*
name|Template
block|;
name|friend
name|class
name|ASTContext
block|;
name|QualifiedTemplateName
argument_list|(
argument|NestedNameSpecifier *NNS
argument_list|,
argument|bool TemplateKeyword
argument_list|,
argument|TemplateDecl *Template
argument_list|)
operator|:
name|Qualifier
argument_list|(
name|NNS
argument_list|,
name|TemplateKeyword
condition|?
literal|1
else|:
literal|0
argument_list|)
block|,
name|Template
argument_list|(
argument|Template
argument_list|)
block|{ }
name|public
operator|:
comment|/// \brief Return the nested name specifier that qualifies this name.
name|NestedNameSpecifier
operator|*
name|getQualifier
argument_list|()
specifier|const
block|{
return|return
name|Qualifier
operator|.
name|getPointer
argument_list|()
return|;
block|}
comment|/// \brief Whether the template name was prefixed by the "template"
comment|/// keyword.
name|bool
name|hasTemplateKeyword
argument_list|()
specifier|const
block|{
return|return
name|Qualifier
operator|.
name|getInt
argument_list|()
return|;
block|}
comment|/// \brief The template declaration that this qualified name refers
comment|/// to.
name|TemplateDecl
operator|*
name|getDecl
argument_list|()
specifier|const
block|{
return|return
name|Template
return|;
block|}
comment|/// \brief The template declaration to which this qualified name
comment|/// refers.
name|TemplateDecl
operator|*
name|getTemplateDecl
argument_list|()
specifier|const
block|{
return|return
name|Template
return|;
block|}
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|getQualifier
argument_list|()
argument_list|,
name|hasTemplateKeyword
argument_list|()
argument_list|,
name|getTemplateDecl
argument_list|()
argument_list|)
block|;   }
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|NestedNameSpecifier *NNS
argument_list|,
argument|bool TemplateKeyword
argument_list|,
argument|TemplateDecl *Template
argument_list|)
block|{
name|ID
operator|.
name|AddPointer
argument_list|(
name|NNS
argument_list|)
block|;
name|ID
operator|.
name|AddBoolean
argument_list|(
name|TemplateKeyword
argument_list|)
block|;
name|ID
operator|.
name|AddPointer
argument_list|(
name|Template
argument_list|)
block|;   }
expr|}
block|;
comment|/// \brief Represents a dependent template name that cannot be
comment|/// resolved prior to template instantiation.
comment|///
comment|/// This kind of template name refers to a dependent template name,
comment|/// including its nested name specifier (if any). For example,
comment|/// DependentTemplateName can refer to "MetaFun::template apply",
comment|/// where "MetaFun::" is the nested name specifier and "apply" is the
comment|/// template name referenced. The "template" keyword is implied.
name|class
name|DependentTemplateName
operator|:
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
comment|/// \brief The nested name specifier that qualifies the template
comment|/// name.
comment|///
comment|/// The bit stored in this qualifier describes whether the \c Name field
comment|/// is interpreted as an IdentifierInfo pointer (when clear) or as an
comment|/// overloaded operator kind (when set).
name|llvm
operator|::
name|PointerIntPair
operator|<
name|NestedNameSpecifier
operator|*
block|,
literal|1
block|,
name|bool
operator|>
name|Qualifier
block|;
comment|/// \brief The dependent template name.
expr|union
block|{
comment|/// \brief The identifier template name.
comment|///
comment|/// Only valid when the bit on \c Qualifier is clear.
specifier|const
name|IdentifierInfo
operator|*
name|Identifier
block|;
comment|/// \brief The overloaded operator name.
comment|///
comment|/// Only valid when the bit on \c Qualifier is set.
name|OverloadedOperatorKind
name|Operator
block|;   }
block|;
comment|/// \brief The canonical template name to which this dependent
comment|/// template name refers.
comment|///
comment|/// The canonical template name for a dependent template name is
comment|/// another dependent template name whose nested name specifier is
comment|/// canonical.
name|TemplateName
name|CanonicalTemplateName
block|;
name|friend
name|class
name|ASTContext
block|;
name|DependentTemplateName
argument_list|(
name|NestedNameSpecifier
operator|*
name|Qualifier
argument_list|,
specifier|const
name|IdentifierInfo
operator|*
name|Identifier
argument_list|)
operator|:
name|Qualifier
argument_list|(
name|Qualifier
argument_list|,
name|false
argument_list|)
block|,
name|Identifier
argument_list|(
name|Identifier
argument_list|)
block|,
name|CanonicalTemplateName
argument_list|(
argument|this
argument_list|)
block|{ }
name|DependentTemplateName
argument_list|(
argument|NestedNameSpecifier *Qualifier
argument_list|,
argument|const IdentifierInfo *Identifier
argument_list|,
argument|TemplateName Canon
argument_list|)
operator|:
name|Qualifier
argument_list|(
name|Qualifier
argument_list|,
name|false
argument_list|)
block|,
name|Identifier
argument_list|(
name|Identifier
argument_list|)
block|,
name|CanonicalTemplateName
argument_list|(
argument|Canon
argument_list|)
block|{ }
name|DependentTemplateName
argument_list|(
argument|NestedNameSpecifier *Qualifier
argument_list|,
argument|OverloadedOperatorKind Operator
argument_list|)
operator|:
name|Qualifier
argument_list|(
name|Qualifier
argument_list|,
name|true
argument_list|)
block|,
name|Operator
argument_list|(
name|Operator
argument_list|)
block|,
name|CanonicalTemplateName
argument_list|(
argument|this
argument_list|)
block|{ }
name|DependentTemplateName
argument_list|(
argument|NestedNameSpecifier *Qualifier
argument_list|,
argument|OverloadedOperatorKind Operator
argument_list|,
argument|TemplateName Canon
argument_list|)
operator|:
name|Qualifier
argument_list|(
name|Qualifier
argument_list|,
name|true
argument_list|)
block|,
name|Operator
argument_list|(
name|Operator
argument_list|)
block|,
name|CanonicalTemplateName
argument_list|(
argument|Canon
argument_list|)
block|{ }
name|public
operator|:
comment|/// \brief Return the nested name specifier that qualifies this name.
name|NestedNameSpecifier
operator|*
name|getQualifier
argument_list|()
specifier|const
block|{
return|return
name|Qualifier
operator|.
name|getPointer
argument_list|()
return|;
block|}
comment|/// \brief Determine whether this template name refers to an identifier.
name|bool
name|isIdentifier
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Qualifier
operator|.
name|getInt
argument_list|()
return|;
block|}
comment|/// \brief Returns the identifier to which this template name refers.
specifier|const
name|IdentifierInfo
operator|*
name|getIdentifier
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isIdentifier
argument_list|()
operator|&&
literal|"Template name isn't an identifier?"
argument_list|)
block|;
return|return
name|Identifier
return|;
block|}
comment|/// \brief Determine whether this template name refers to an overloaded
comment|/// operator.
name|bool
name|isOverloadedOperator
argument_list|()
specifier|const
block|{
return|return
name|Qualifier
operator|.
name|getInt
argument_list|()
return|;
block|}
comment|/// \brief Return the overloaded operator to which this template name refers.
name|OverloadedOperatorKind
name|getOperator
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isOverloadedOperator
argument_list|()
operator|&&
literal|"Template name isn't an overloaded operator?"
argument_list|)
block|;
return|return
name|Operator
return|;
block|}
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
block|{
if|if
condition|(
name|isIdentifier
argument_list|()
condition|)
name|Profile
argument_list|(
name|ID
argument_list|,
name|getQualifier
argument_list|()
argument_list|,
name|getIdentifier
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|Profile
argument_list|(
name|ID
argument_list|,
name|getQualifier
argument_list|()
argument_list|,
name|getOperator
argument_list|()
argument_list|)
expr_stmt|;
block|}
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|NestedNameSpecifier *NNS
argument_list|,
argument|const IdentifierInfo *Identifier
argument_list|)
block|{
name|ID
operator|.
name|AddPointer
argument_list|(
name|NNS
argument_list|)
block|;
name|ID
operator|.
name|AddBoolean
argument_list|(
name|false
argument_list|)
block|;
name|ID
operator|.
name|AddPointer
argument_list|(
name|Identifier
argument_list|)
block|;   }
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|NestedNameSpecifier *NNS
argument_list|,
argument|OverloadedOperatorKind Operator
argument_list|)
block|{
name|ID
operator|.
name|AddPointer
argument_list|(
name|NNS
argument_list|)
block|;
name|ID
operator|.
name|AddBoolean
argument_list|(
name|true
argument_list|)
block|;
name|ID
operator|.
name|AddInteger
argument_list|(
name|Operator
argument_list|)
block|;   }
expr|}
block|;  }
comment|// end namespace clang.
name|namespace
name|llvm
block|{
comment|/// \brief The clang::TemplateName class is effectively a pointer.
name|template
operator|<
operator|>
name|class
name|PointerLikeTypeTraits
operator|<
name|clang
operator|::
name|TemplateName
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
argument|clang::TemplateName TN
argument_list|)
block|{
return|return
name|TN
operator|.
name|getAsVoidPointer
argument_list|()
return|;
block|}
specifier|static
specifier|inline
name|clang
operator|::
name|TemplateName
name|getFromVoidPointer
argument_list|(
argument|void *Ptr
argument_list|)
block|{
return|return
name|clang
operator|::
name|TemplateName
operator|::
name|getFromVoidPointer
argument_list|(
name|Ptr
argument_list|)
return|;
block|}
comment|// No bits are available!
expr|enum
block|{
name|NumLowBitsAvailable
operator|=
literal|0
block|}
block|; }
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm.
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

