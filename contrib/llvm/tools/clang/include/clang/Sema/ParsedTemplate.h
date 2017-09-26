begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ParsedTemplate.h - Template Parsing Data Types ---------*- C++ -*-===//
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
comment|//  This file provides data structures that store the parsed representation of
end_comment

begin_comment
comment|//  templates.
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
name|LLVM_CLANG_SEMA_PARSEDTEMPLATE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_PARSEDTEMPLATE_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/OperatorKinds.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/TemplateKinds.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/DeclSpec.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/Ownership.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstdlib>
end_include

begin_include
include|#
directive|include
file|<new>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief Represents the parsed form of a C++ template argument.
name|class
name|ParsedTemplateArgument
block|{
name|public
label|:
comment|/// \brief Describes the kind of template argument that was parsed.
enum|enum
name|KindType
block|{
comment|/// \brief A template type parameter, stored as a type.
name|Type
block|,
comment|/// \brief A non-type template parameter, stored as an expression.
name|NonType
block|,
comment|/// \brief A template template argument, stored as a template name.
name|Template
block|}
enum|;
comment|/// \brief Build an empty template argument.
comment|///
comment|/// This template argument is invalid.
name|ParsedTemplateArgument
argument_list|()
operator|:
name|Kind
argument_list|(
name|Type
argument_list|)
operator|,
name|Arg
argument_list|(
argument|nullptr
argument_list|)
block|{ }
comment|/// \brief Create a template type argument or non-type template argument.
comment|///
comment|/// \param Arg the template type argument or non-type template argument.
comment|/// \param Loc the location of the type.
name|ParsedTemplateArgument
argument_list|(
argument|KindType Kind
argument_list|,
argument|void *Arg
argument_list|,
argument|SourceLocation Loc
argument_list|)
operator|:
name|Kind
argument_list|(
name|Kind
argument_list|)
operator|,
name|Arg
argument_list|(
name|Arg
argument_list|)
operator|,
name|Loc
argument_list|(
argument|Loc
argument_list|)
block|{ }
comment|/// \brief Create a template template argument.
comment|///
comment|/// \param SS the C++ scope specifier that precedes the template name, if
comment|/// any.
comment|///
comment|/// \param Template the template to which this template template
comment|/// argument refers.
comment|///
comment|/// \param TemplateLoc the location of the template name.
name|ParsedTemplateArgument
argument_list|(
argument|const CXXScopeSpec&SS
argument_list|,
argument|ParsedTemplateTy Template
argument_list|,
argument|SourceLocation TemplateLoc
argument_list|)
operator|:
name|Kind
argument_list|(
name|ParsedTemplateArgument
operator|::
name|Template
argument_list|)
operator|,
name|Arg
argument_list|(
name|Template
operator|.
name|getAsOpaquePtr
argument_list|()
argument_list|)
operator|,
name|SS
argument_list|(
name|SS
argument_list|)
operator|,
name|Loc
argument_list|(
name|TemplateLoc
argument_list|)
operator|,
name|EllipsisLoc
argument_list|()
block|{ }
comment|/// \brief Determine whether the given template argument is invalid.
name|bool
name|isInvalid
argument_list|()
specifier|const
block|{
return|return
name|Arg
operator|==
name|nullptr
return|;
block|}
comment|/// \brief Determine what kind of template argument we have.
name|KindType
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
comment|/// \brief Retrieve the template type argument's type.
name|ParsedType
name|getAsType
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Kind
operator|==
name|Type
operator|&&
literal|"Not a template type argument"
argument_list|)
block|;
return|return
name|ParsedType
operator|::
name|getFromOpaquePtr
argument_list|(
name|Arg
argument_list|)
return|;
block|}
comment|/// \brief Retrieve the non-type template argument's expression.
name|Expr
operator|*
name|getAsExpr
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Kind
operator|==
name|NonType
operator|&&
literal|"Not a non-type template argument"
argument_list|)
block|;
return|return
name|static_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
name|Arg
operator|)
return|;
block|}
comment|/// \brief Retrieve the template template argument's template name.
name|ParsedTemplateTy
name|getAsTemplate
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Kind
operator|==
name|Template
operator|&&
literal|"Not a template template argument"
argument_list|)
block|;
return|return
name|ParsedTemplateTy
operator|::
name|getFromOpaquePtr
argument_list|(
name|Arg
argument_list|)
return|;
block|}
comment|/// \brief Retrieve the location of the template argument.
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|Loc
return|;
block|}
comment|/// \brief Retrieve the nested-name-specifier that precedes the template
comment|/// name in a template template argument.
specifier|const
name|CXXScopeSpec
operator|&
name|getScopeSpec
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Kind
operator|==
name|Template
operator|&&
literal|"Only template template arguments can have a scope specifier"
argument_list|)
block|;
return|return
name|SS
return|;
block|}
comment|/// \brief Retrieve the location of the ellipsis that makes a template
comment|/// template argument into a pack expansion.
name|SourceLocation
name|getEllipsisLoc
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Kind
operator|==
name|Template
operator|&&
literal|"Only template template arguments can have an ellipsis"
argument_list|)
block|;
return|return
name|EllipsisLoc
return|;
block|}
comment|/// \brief Retrieve a pack expansion of the given template template
comment|/// argument.
comment|///
comment|/// \param EllipsisLoc The location of the ellipsis.
name|ParsedTemplateArgument
name|getTemplatePackExpansion
argument_list|(
name|SourceLocation
name|EllipsisLoc
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|KindType
name|Kind
decl_stmt|;
comment|/// \brief The actual template argument representation, which may be
comment|/// an \c Sema::TypeTy* (for a type), an Expr* (for an
comment|/// expression), or an Sema::TemplateTy (for a template).
name|void
modifier|*
name|Arg
decl_stmt|;
comment|/// \brief The nested-name-specifier that can accompany a template template
comment|/// argument.
name|CXXScopeSpec
name|SS
decl_stmt|;
comment|/// \brief the location of the template argument.
name|SourceLocation
name|Loc
decl_stmt|;
comment|/// \brief The ellipsis location that can accompany a template template
comment|/// argument (turning it into a template template argument expansion).
name|SourceLocation
name|EllipsisLoc
decl_stmt|;
block|}
empty_stmt|;
comment|/// \brief Information about a template-id annotation
comment|/// token.
comment|///
comment|/// A template-id annotation token contains the template declaration,
comment|/// template arguments, whether those template arguments were types,
comment|/// expressions, or template names, and the source locations for important
comment|/// tokens. All of the information about template arguments is allocated
comment|/// directly after this structure.
name|struct
name|TemplateIdAnnotation
name|final
range|:
name|private
name|llvm
operator|::
name|TrailingObjects
operator|<
name|TemplateIdAnnotation
decl_stmt|,
name|ParsedTemplateArgument
decl|>
block|{
name|friend
name|TrailingObjects
decl_stmt|;
comment|/// \brief The nested-name-specifier that precedes the template name.
name|CXXScopeSpec
name|SS
decl_stmt|;
comment|/// TemplateKWLoc - The location of the template keyword.
comment|/// For e.g. typename T::template Y<U>
name|SourceLocation
name|TemplateKWLoc
decl_stmt|;
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
comment|/// template-name.
name|ParsedTemplateTy
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
name|ParsedTemplateArgument
modifier|*
name|getTemplateArgs
parameter_list|()
block|{
return|return
name|getTrailingObjects
operator|<
name|ParsedTemplateArgument
operator|>
operator|(
operator|)
return|;
block|}
comment|/// \brief Creates a new TemplateIdAnnotation with NumArgs arguments and
comment|/// appends it to List.
specifier|static
name|TemplateIdAnnotation
modifier|*
name|Create
argument_list|(
name|CXXScopeSpec
name|SS
argument_list|,
name|SourceLocation
name|TemplateKWLoc
argument_list|,
name|SourceLocation
name|TemplateNameLoc
argument_list|,
name|IdentifierInfo
operator|*
name|Name
argument_list|,
name|OverloadedOperatorKind
name|OperatorKind
argument_list|,
name|ParsedTemplateTy
name|OpaqueTemplateName
argument_list|,
name|TemplateNameKind
name|TemplateKind
argument_list|,
name|SourceLocation
name|LAngleLoc
argument_list|,
name|SourceLocation
name|RAngleLoc
argument_list|,
name|ArrayRef
operator|<
name|ParsedTemplateArgument
operator|>
name|TemplateArgs
argument_list|,
name|SmallVectorImpl
operator|<
name|TemplateIdAnnotation
operator|*
operator|>
operator|&
name|CleanupList
argument_list|)
block|{
name|TemplateIdAnnotation
modifier|*
name|TemplateId
init|=
name|new
argument_list|(
argument|std::malloc(           totalSizeToAlloc<ParsedTemplateArgument>(TemplateArgs.size()))
argument_list|)
name|TemplateIdAnnotation
argument_list|(
name|SS
argument_list|,
name|TemplateKWLoc
argument_list|,
name|TemplateNameLoc
argument_list|,
name|Name
argument_list|,
name|OperatorKind
argument_list|,
name|OpaqueTemplateName
argument_list|,
name|TemplateKind
argument_list|,
name|LAngleLoc
argument_list|,
name|RAngleLoc
argument_list|,
name|TemplateArgs
argument_list|)
decl_stmt|;
name|CleanupList
operator|.
name|push_back
argument_list|(
name|TemplateId
argument_list|)
expr_stmt|;
return|return
name|TemplateId
return|;
block|}
name|void
name|Destroy
parameter_list|()
block|{
name|std
operator|::
name|for_each
argument_list|(
name|getTemplateArgs
argument_list|()
argument_list|,
name|getTemplateArgs
argument_list|()
operator|+
name|NumArgs
argument_list|,
index|[]
operator|(
name|ParsedTemplateArgument
operator|&
name|A
operator|)
block|{
name|A
operator|.
expr|~
name|ParsedTemplateArgument
argument_list|()
block|; }
argument_list|)
expr_stmt|;
name|this
operator|->
expr|~
name|TemplateIdAnnotation
argument_list|()
expr_stmt|;
name|free
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
name|private
label|:
name|TemplateIdAnnotation
argument_list|(
specifier|const
name|TemplateIdAnnotation
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|TemplateIdAnnotation
argument_list|(
argument|CXXScopeSpec SS
argument_list|,
argument|SourceLocation TemplateKWLoc
argument_list|,
argument|SourceLocation TemplateNameLoc
argument_list|,
argument|IdentifierInfo *Name
argument_list|,
argument|OverloadedOperatorKind OperatorKind
argument_list|,
argument|ParsedTemplateTy OpaqueTemplateName
argument_list|,
argument|TemplateNameKind TemplateKind
argument_list|,
argument|SourceLocation LAngleLoc
argument_list|,
argument|SourceLocation RAngleLoc
argument_list|,
argument|ArrayRef<ParsedTemplateArgument> TemplateArgs
argument_list|)
name|noexcept
label|:
name|SS
argument_list|(
name|SS
argument_list|)
operator|,
name|TemplateKWLoc
argument_list|(
name|TemplateKWLoc
argument_list|)
operator|,
name|TemplateNameLoc
argument_list|(
name|TemplateNameLoc
argument_list|)
operator|,
name|Name
argument_list|(
name|Name
argument_list|)
operator|,
name|Operator
argument_list|(
name|OperatorKind
argument_list|)
operator|,
name|Template
argument_list|(
name|OpaqueTemplateName
argument_list|)
operator|,
name|Kind
argument_list|(
name|TemplateKind
argument_list|)
operator|,
name|LAngleLoc
argument_list|(
name|LAngleLoc
argument_list|)
operator|,
name|RAngleLoc
argument_list|(
name|RAngleLoc
argument_list|)
operator|,
name|NumArgs
argument_list|(
argument|TemplateArgs.size()
argument_list|)
block|{
name|std
operator|::
name|uninitialized_copy
argument_list|(
name|TemplateArgs
operator|.
name|begin
argument_list|()
argument_list|,
name|TemplateArgs
operator|.
name|end
argument_list|()
argument_list|,
name|getTemplateArgs
argument_list|()
argument_list|)
block|;     }
operator|~
name|TemplateIdAnnotation
argument_list|()
operator|=
expr|default
expr_stmt|;
block|}
empty_stmt|;
comment|/// Retrieves the range of the given template parameter lists.
name|SourceRange
name|getTemplateParamsRange
parameter_list|(
name|TemplateParameterList
specifier|const
modifier|*
specifier|const
modifier|*
name|Params
parameter_list|,
name|unsigned
name|NumParams
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_SEMA_PARSEDTEMPLATE_H
end_comment

end_unit

