begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Template.h - Template Parsing Data Types -------------------------===//
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
name|LLVM_CLANG_PARSE_TEMPLATE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_PARSE_TEMPLATE_H
end_define

begin_include
include|#
directive|include
file|"clang/Parse/DeclSpec.h"
end_include

begin_include
include|#
directive|include
file|"clang/Parse/Ownership.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
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
comment|/// \brief Build an empty template argument. This template argument
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
literal|0
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
argument|ActionBase::TemplateTy Template
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
name|get
argument_list|()
argument_list|)
operator|,
name|Loc
argument_list|(
name|TemplateLoc
argument_list|)
operator|,
name|SS
argument_list|(
argument|SS
argument_list|)
block|{ }
comment|/// \brief Determine whether the given template argument is invalid.
name|bool
name|isInvalid
argument_list|()
block|{
return|return
name|Arg
operator|==
literal|0
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
name|ActionBase
operator|::
name|TypeTy
operator|*
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
name|Arg
return|;
block|}
comment|/// \brief Retrieve the non-type template argument's expression.
name|ActionBase
operator|::
name|ExprTy
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
name|Arg
return|;
block|}
comment|/// \brief Retrieve the template template argument's template name.
name|ActionBase
operator|::
name|TemplateTy
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
name|ActionBase
operator|::
name|TemplateTy
operator|::
name|make
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
name|private
label|:
name|KindType
name|Kind
decl_stmt|;
comment|/// \brief The actual template argument representation, which may be
comment|/// an \c ActionBase::TypeTy* (for a type), an ActionBase::ExprTy* (for an
comment|/// expression), or an ActionBase::TemplateTy (for a template).
name|void
modifier|*
name|Arg
decl_stmt|;
comment|/// \brief the location of the template argument.
name|SourceLocation
name|Loc
decl_stmt|;
comment|/// \brief The nested-name-specifier that can accompany a template template
comment|/// argument.
name|CXXScopeSpec
name|SS
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
comment|/// template-name. This is an Action::TemplateTy.
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
name|ParsedTemplateArgument
modifier|*
name|getTemplateArgs
parameter_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|ParsedTemplateArgument
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
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
name|ParsedTemplateArgument
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
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DISABLE_SMART_POINTERS
argument_list|)
specifier|inline
name|void
name|ASTTemplateArgsPtr
operator|::
name|destroy
argument_list|()
block|{
if|if
condition|(
operator|!
name|Count
condition|)
return|return;
for|for
control|(
name|unsigned
name|I
init|=
literal|0
init|;
name|I
operator|!=
name|Count
condition|;
operator|++
name|I
control|)
if|if
condition|(
name|Args
index|[
name|I
index|]
operator|.
name|getKind
argument_list|()
operator|==
name|ParsedTemplateArgument
operator|::
name|NonType
condition|)
name|Actions
operator|.
name|DeleteExpr
argument_list|(
name|Args
index|[
name|I
index|]
operator|.
name|getAsExpr
argument_list|()
argument_list|)
expr_stmt|;
name|Count
operator|=
literal|0
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
specifier|inline
specifier|const
name|ParsedTemplateArgument
operator|&
name|ASTTemplateArgsPtr
operator|::
name|operator
index|[]
operator|(
name|unsigned
name|Arg
operator|)
specifier|const
block|{
return|return
name|Args
index|[
name|Arg
index|]
return|;
block|}
end_expr_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

