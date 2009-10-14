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
file|"llvm/ADT/FoldingSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerUnion.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|DependentTemplateName
decl_stmt|;
name|class
name|IdentifierInfo
decl_stmt|;
name|class
name|NestedNameSpecifier
decl_stmt|;
struct_decl|struct
name|PrintingPolicy
struct_decl|;
name|class
name|QualifiedTemplateName
decl_stmt|;
name|class
name|NamedDecl
decl_stmt|;
name|class
name|TemplateDecl
decl_stmt|;
name|class
name|OverloadedFunctionDecl
decl_stmt|;
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
name|OverloadedFunctionDecl
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
block|{
name|Storage
operator|=
name|StorageType
operator|::
name|getFromOpaqueValue
argument_list|(
name|Ptr
argument_list|)
expr_stmt|;
block|}
name|public
label|:
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
operator|:
name|Storage
argument_list|(
argument|Template
argument_list|)
block|{ }
name|explicit
name|TemplateName
argument_list|(
name|OverloadedFunctionDecl
operator|*
name|FunctionTemplates
argument_list|)
operator|:
name|Storage
argument_list|(
argument|FunctionTemplates
argument_list|)
block|{ }
name|explicit
name|TemplateName
argument_list|(
name|QualifiedTemplateName
operator|*
name|Qual
argument_list|)
operator|:
name|Storage
argument_list|(
argument|Qual
argument_list|)
block|{ }
name|explicit
name|TemplateName
argument_list|(
name|DependentTemplateName
operator|*
name|Dep
argument_list|)
operator|:
name|Storage
argument_list|(
argument|Dep
argument_list|)
block|{ }
comment|/// \brief Determine whether this template name is NULL.
name|bool
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|Storage
operator|.
name|isNull
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the the underlying template declaration that
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
comment|/// \brief Retrieve the the underlying, overloaded function template
comment|// declarations that this template name refers to, if known.
comment|///
comment|/// \returns The set of overloaded function templates that this template
comment|/// name refers to, if known. If the template name does not refer to a
comment|/// specific set of function templates because it is a dependent name or
comment|/// refers to a single template, returns NULL.
name|OverloadedFunctionDecl
operator|*
name|getAsOverloadedFunctionDecl
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
block|{
return|return
name|Storage
operator|.
name|dyn_cast
operator|<
name|QualifiedTemplateName
operator|*
operator|>
operator|(
operator|)
return|;
block|}
comment|/// \brief Retrieve the underlying dependent template name
comment|/// structure, if any.
name|DependentTemplateName
operator|*
name|getAsDependentTemplateName
argument_list|()
specifier|const
block|{
return|return
name|Storage
operator|.
name|dyn_cast
operator|<
name|DependentTemplateName
operator|*
operator|>
operator|(
operator|)
return|;
block|}
comment|/// \brief Determines whether this is a dependent template name.
name|bool
name|isDependent
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
name|llvm
operator|::
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
comment|/// \brief Represents a template name that was expressed as a
comment|/// qualified name.
comment|///
comment|/// This kind of template name refers to a template name that was
comment|/// preceded by a nested name specifier, e.g., \c std::vector. Here,
comment|/// the nested name specifier is "std::" and the template name is the
comment|/// declaration for "vector". The QualifiedTemplateName class is only
comment|/// used to provide "sugar" for template names that were expressed
comment|/// with a qualified name, and has no semantic meaning. In this
comment|/// manner, it is to TemplateName what QualifiedNameType is to Type,
comment|/// providing extra syntactic sugar for downstream clients.
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
name|NamedDecl
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
argument|reinterpret_cast<NamedDecl *>(Template)
argument_list|)
block|{ }
name|QualifiedTemplateName
argument_list|(
argument|NestedNameSpecifier *NNS
argument_list|,
argument|bool TemplateKeyword
argument_list|,
argument|OverloadedFunctionDecl *Template
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
argument|reinterpret_cast<NamedDecl *>(Template)
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
comment|/// \brief The template declaration or set of overloaded functions that
comment|/// that qualified name refers to.
name|NamedDecl
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
comment|/// refers, or NULL if this qualified name refers to a set of overloaded
comment|/// function templates.
name|TemplateDecl
operator|*
name|getTemplateDecl
argument_list|()
specifier|const
block|;
comment|/// \brief The set of overloaded function tempaltes to which this qualified
comment|/// name refers, or NULL if this qualified name refers to a single
comment|/// template declaration.
name|OverloadedFunctionDecl
operator|*
name|getOverloadedFunctionDecl
argument_list|()
specifier|const
block|;
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
name|getDecl
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
argument|NamedDecl *Template
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
block|}
decl_stmt|;
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
range|:
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
comment|/// \brief The nested name specifier that qualifies the template
comment|/// name.
name|NestedNameSpecifier
operator|*
name|Qualifier
block|;
comment|/// \brief The dependent template name.
specifier|const
name|IdentifierInfo
operator|*
name|Name
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
name|Name
argument_list|)
operator|:
name|Qualifier
argument_list|(
name|Qualifier
argument_list|)
block|,
name|Name
argument_list|(
name|Name
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
argument|const IdentifierInfo *Name
argument_list|,
argument|TemplateName Canon
argument_list|)
operator|:
name|Qualifier
argument_list|(
name|Qualifier
argument_list|)
block|,
name|Name
argument_list|(
name|Name
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
return|;
block|}
comment|/// \brief Return the name to which this dependent template name
comment|/// refers.
specifier|const
name|IdentifierInfo
operator|*
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
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
name|getName
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
argument|const IdentifierInfo *Name
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
name|AddPointer
argument_list|(
name|Name
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

