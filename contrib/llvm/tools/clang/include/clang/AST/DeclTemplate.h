begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DeclTemplate.h - Classes for representing C++ templates -*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Defines the C++ template declaration subclasses.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_AST_DECLTEMPLATE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_DECLTEMPLATE_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/DeclCXX.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Redeclarable.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/TemplateBase.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerUnion.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/TrailingObjects.h"
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
enum_decl|enum
name|BuiltinTemplateKind
enum_decl|:
name|int
enum_decl|;
name|class
name|TemplateParameterList
decl_stmt|;
name|class
name|TemplateDecl
decl_stmt|;
name|class
name|RedeclarableTemplateDecl
decl_stmt|;
name|class
name|FunctionTemplateDecl
decl_stmt|;
name|class
name|ClassTemplateDecl
decl_stmt|;
name|class
name|ClassTemplatePartialSpecializationDecl
decl_stmt|;
name|class
name|TemplateTypeParmDecl
decl_stmt|;
name|class
name|NonTypeTemplateParmDecl
decl_stmt|;
name|class
name|TemplateTemplateParmDecl
decl_stmt|;
name|class
name|TypeAliasTemplateDecl
decl_stmt|;
name|class
name|VarTemplateDecl
decl_stmt|;
name|class
name|VarTemplatePartialSpecializationDecl
decl_stmt|;
comment|/// \brief Stores a template parameter of any kind.
typedef|typedef
name|llvm
operator|::
name|PointerUnion3
operator|<
name|TemplateTypeParmDecl
operator|*
operator|,
name|NonTypeTemplateParmDecl
operator|*
operator|,
name|TemplateTemplateParmDecl
operator|*
operator|>
name|TemplateParameter
expr_stmt|;
name|NamedDecl
modifier|*
name|getAsNamedDecl
parameter_list|(
name|TemplateParameter
name|P
parameter_list|)
function_decl|;
comment|/// \brief Stores a list of template parameters for a TemplateDecl and its
comment|/// derived classes.
name|class
name|TemplateParameterList
name|final
range|:
name|private
name|llvm
operator|::
name|TrailingObjects
operator|<
name|TemplateParameterList
decl_stmt|,
name|NamedDecl
modifier|*
decl_stmt|,
name|Expr
modifier|*
decl|>
block|{
comment|/// The location of the 'template' keyword.
name|SourceLocation
name|TemplateLoc
decl_stmt|;
comment|/// The locations of the '<' and '>' angle brackets.
name|SourceLocation
name|LAngleLoc
decl_stmt|,
name|RAngleLoc
decl_stmt|;
comment|/// The number of template parameters in this template
comment|/// parameter list.
name|unsigned
name|NumParams
range|:
literal|30
decl_stmt|;
comment|/// Whether this template parameter list contains an unexpanded parameter
comment|/// pack.
name|unsigned
name|ContainsUnexpandedParameterPack
range|:
literal|1
decl_stmt|;
comment|/// Whether this template parameter list has an associated requires-clause
name|unsigned
name|HasRequiresClause
range|:
literal|1
decl_stmt|;
name|protected
label|:
name|size_t
name|numTrailingObjects
argument_list|(
name|OverloadToken
operator|<
name|NamedDecl
operator|*
operator|>
argument_list|)
decl|const
block|{
return|return
name|NumParams
return|;
block|}
name|size_t
name|numTrailingObjects
argument_list|(
name|OverloadToken
operator|<
name|Expr
operator|*
operator|>
argument_list|)
decl|const
block|{
return|return
name|HasRequiresClause
return|;
block|}
name|TemplateParameterList
argument_list|(
argument|SourceLocation TemplateLoc
argument_list|,
argument|SourceLocation LAngleLoc
argument_list|,
argument|ArrayRef<NamedDecl *> Params
argument_list|,
argument|SourceLocation RAngleLoc
argument_list|,
argument|Expr *RequiresClause
argument_list|)
empty_stmt|;
name|public
label|:
specifier|static
name|TemplateParameterList
modifier|*
name|Create
argument_list|(
specifier|const
name|ASTContext
operator|&
name|C
argument_list|,
name|SourceLocation
name|TemplateLoc
argument_list|,
name|SourceLocation
name|LAngleLoc
argument_list|,
name|ArrayRef
operator|<
name|NamedDecl
operator|*
operator|>
name|Params
argument_list|,
name|SourceLocation
name|RAngleLoc
argument_list|,
name|Expr
operator|*
name|RequiresClause
argument_list|)
decl_stmt|;
comment|/// \brief Iterates through the template parameters in this list.
typedef|typedef
name|NamedDecl
modifier|*
modifier|*
name|iterator
typedef|;
comment|/// \brief Iterates through the template parameters in this list.
typedef|typedef
name|NamedDecl
modifier|*
specifier|const
modifier|*
name|const_iterator
typedef|;
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|getTrailingObjects
operator|<
name|NamedDecl
operator|*
operator|>
operator|(
operator|)
return|;
block|}
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|getTrailingObjects
operator|<
name|NamedDecl
operator|*
operator|>
operator|(
operator|)
return|;
block|}
name|iterator
name|end
parameter_list|()
block|{
return|return
name|begin
argument_list|()
operator|+
name|NumParams
return|;
block|}
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|begin
argument_list|()
operator|+
name|NumParams
return|;
block|}
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
name|NumParams
return|;
block|}
name|ArrayRef
operator|<
name|NamedDecl
operator|*
operator|>
name|asArray
argument_list|()
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|begin
argument_list|()
argument_list|,
name|end
argument_list|()
argument_list|)
return|;
block|}
name|ArrayRef
operator|<
specifier|const
name|NamedDecl
operator|*
operator|>
name|asArray
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|begin
argument_list|()
argument_list|,
name|size
argument_list|()
argument_list|)
return|;
block|}
name|NamedDecl
modifier|*
name|getParam
parameter_list|(
name|unsigned
name|Idx
parameter_list|)
block|{
name|assert
argument_list|(
name|Idx
operator|<
name|size
argument_list|()
operator|&&
literal|"Template parameter index out-of-range"
argument_list|)
expr_stmt|;
return|return
name|begin
argument_list|()
index|[
name|Idx
index|]
return|;
block|}
specifier|const
name|NamedDecl
modifier|*
name|getParam
argument_list|(
name|unsigned
name|Idx
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|Idx
operator|<
name|size
argument_list|()
operator|&&
literal|"Template parameter index out-of-range"
argument_list|)
expr_stmt|;
return|return
name|begin
argument_list|()
index|[
name|Idx
index|]
return|;
block|}
comment|/// \brief Returns the minimum number of arguments needed to form a
comment|/// template specialization.
comment|///
comment|/// This may be fewer than the number of template parameters, if some of
comment|/// the parameters have default arguments or if there is a parameter pack.
name|unsigned
name|getMinRequiredArguments
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Get the depth of this template parameter list in the set of
comment|/// template parameter lists.
comment|///
comment|/// The first template parameter list in a declaration will have depth 0,
comment|/// the second template parameter list will have depth 1, etc.
name|unsigned
name|getDepth
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determine whether this template parameter list contains an
comment|/// unexpanded parameter pack.
name|bool
name|containsUnexpandedParameterPack
argument_list|()
specifier|const
block|{
return|return
name|ContainsUnexpandedParameterPack
return|;
block|}
comment|/// \brief The constraint-expression of the associated requires-clause.
name|Expr
modifier|*
name|getRequiresClause
parameter_list|()
block|{
return|return
name|HasRequiresClause
condition|?
operator|*
name|getTrailingObjects
operator|<
name|Expr
operator|*
operator|>
operator|(
operator|)
else|:
name|nullptr
return|;
block|}
comment|/// \brief The constraint-expression of the associated requires-clause.
specifier|const
name|Expr
operator|*
name|getRequiresClause
argument_list|()
specifier|const
block|{
return|return
name|HasRequiresClause
operator|?
operator|*
name|getTrailingObjects
operator|<
name|Expr
operator|*
operator|>
operator|(
operator|)
operator|:
name|nullptr
return|;
block|}
name|SourceLocation
name|getTemplateLoc
argument_list|()
specifier|const
block|{
return|return
name|TemplateLoc
return|;
block|}
name|SourceLocation
name|getLAngleLoc
argument_list|()
specifier|const
block|{
return|return
name|LAngleLoc
return|;
block|}
name|SourceLocation
name|getRAngleLoc
argument_list|()
specifier|const
block|{
return|return
name|RAngleLoc
return|;
block|}
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|SourceRange
argument_list|(
name|TemplateLoc
argument_list|,
name|RAngleLoc
argument_list|)
return|;
block|}
name|friend
name|TrailingObjects
decl_stmt|;
name|template
operator|<
name|size_t
name|N
operator|,
name|bool
name|HasRequiresClause
operator|>
name|friend
name|class
name|FixedSizeTemplateParameterListStorage
expr_stmt|;
name|public
label|:
comment|// FIXME: workaround for MSVC 2013; remove when no longer needed
name|using
name|FixedSizeStorageOwner
init|=
name|TrailingObjects
operator|::
name|FixedSizeStorageOwner
decl_stmt|;
block|}
empty_stmt|;
comment|/// \brief Stores a list of template parameters and the associated
comment|/// requires-clause (if any) for a TemplateDecl and its derived classes.
comment|/// Suitable for creating on the stack.
name|template
operator|<
name|size_t
name|N
operator|,
name|bool
name|HasRequiresClause
operator|>
name|class
name|FixedSizeTemplateParameterListStorage
operator|:
name|public
name|TemplateParameterList
operator|::
name|FixedSizeStorageOwner
block|{
name|typename
name|TemplateParameterList
operator|::
name|FixedSizeStorage
operator|<
name|NamedDecl
operator|*
block|,
name|Expr
operator|*
operator|>
operator|::
name|with_counts
operator|<
name|N
block|,
name|HasRequiresClause
operator|?
literal|1u
operator|:
literal|0u
operator|>
operator|::
name|type
name|storage
block|;
name|public
operator|:
name|FixedSizeTemplateParameterListStorage
argument_list|(
argument|SourceLocation TemplateLoc
argument_list|,
argument|SourceLocation LAngleLoc
argument_list|,
argument|ArrayRef<NamedDecl *> Params
argument_list|,
argument|SourceLocation RAngleLoc
argument_list|,
argument|Expr *RequiresClause
argument_list|)
operator|:
name|FixedSizeStorageOwner
argument_list|(
argument|(assert(N == Params.size()),              assert(HasRequiresClause == static_cast<bool>(RequiresClause)),              new (static_cast<void *>(&storage)) TemplateParameterList(                  TemplateLoc, LAngleLoc, Params, RAngleLoc, RequiresClause))
argument_list|)
block|{}
block|}
expr_stmt|;
comment|/// \brief A template argument list.
name|class
name|TemplateArgumentList
name|final
range|:
name|private
name|llvm
operator|::
name|TrailingObjects
operator|<
name|TemplateArgumentList
decl_stmt|,
name|TemplateArgument
decl|>
block|{
comment|/// \brief The template argument list.
specifier|const
name|TemplateArgument
modifier|*
name|Arguments
decl_stmt|;
comment|/// \brief The number of template arguments in this template
comment|/// argument list.
name|unsigned
name|NumArguments
decl_stmt|;
name|TemplateArgumentList
argument_list|(
specifier|const
name|TemplateArgumentList
operator|&
name|Other
argument_list|)
operator|=
name|delete
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|TemplateArgumentList
operator|&
name|Other
operator|)
operator|=
name|delete
decl_stmt|;
comment|// Constructs an instance with an internal Argument list, containing
comment|// a copy of the Args array. (Called by CreateCopy)
name|TemplateArgumentList
argument_list|(
name|ArrayRef
operator|<
name|TemplateArgument
operator|>
name|Args
argument_list|)
expr_stmt|;
name|public
label|:
comment|/// \brief Type used to indicate that the template argument list itself is a
comment|/// stack object. It does not own its template arguments.
enum|enum
name|OnStackType
block|{
name|OnStack
block|}
enum|;
comment|/// \brief Create a new template argument list that copies the given set of
comment|/// template arguments.
specifier|static
name|TemplateArgumentList
modifier|*
name|CreateCopy
argument_list|(
name|ASTContext
operator|&
name|Context
argument_list|,
name|ArrayRef
operator|<
name|TemplateArgument
operator|>
name|Args
argument_list|)
decl_stmt|;
comment|/// \brief Construct a new, temporary template argument list on the stack.
comment|///
comment|/// The template argument list does not own the template arguments
comment|/// provided.
name|explicit
name|TemplateArgumentList
argument_list|(
name|OnStackType
argument_list|,
name|ArrayRef
operator|<
name|TemplateArgument
operator|>
name|Args
argument_list|)
range|:
name|Arguments
argument_list|(
name|Args
operator|.
name|data
argument_list|()
argument_list|)
decl_stmt|,
name|NumArguments
argument_list|(
name|Args
operator|.
name|size
argument_list|()
argument_list|)
block|{}
comment|/// \brief Produces a shallow copy of the given template argument list.
comment|///
comment|/// This operation assumes that the input argument list outlives it.
comment|/// This takes the list as a pointer to avoid looking like a copy
comment|/// constructor, since this really really isn't safe to use that
comment|/// way.
name|explicit
name|TemplateArgumentList
argument_list|(
specifier|const
name|TemplateArgumentList
operator|*
name|Other
argument_list|)
operator|:
name|Arguments
argument_list|(
name|Other
operator|->
name|data
argument_list|()
argument_list|)
operator|,
name|NumArguments
argument_list|(
argument|Other->size()
argument_list|)
block|{}
comment|/// \brief Retrieve the template argument at a given index.
specifier|const
name|TemplateArgument
operator|&
name|get
argument_list|(
argument|unsigned Idx
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|Idx
operator|<
name|NumArguments
operator|&&
literal|"Invalid template argument index"
argument_list|)
block|;
return|return
name|data
argument_list|()
index|[
name|Idx
index|]
return|;
block|}
comment|/// \brief Retrieve the template argument at a given index.
specifier|const
name|TemplateArgument
modifier|&
name|operator
index|[]
argument_list|(
name|unsigned
name|Idx
argument_list|)
decl|const
block|{
return|return
name|get
argument_list|(
name|Idx
argument_list|)
return|;
block|}
comment|/// \brief Produce this as an array ref.
name|ArrayRef
operator|<
name|TemplateArgument
operator|>
name|asArray
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|data
argument_list|()
argument_list|,
name|size
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Retrieve the number of template arguments in this
comment|/// template argument list.
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
name|NumArguments
return|;
block|}
comment|/// \brief Retrieve a pointer to the template argument list.
specifier|const
name|TemplateArgument
operator|*
name|data
argument_list|()
specifier|const
block|{
return|return
name|Arguments
return|;
block|}
name|friend
name|TrailingObjects
decl_stmt|;
block|}
empty_stmt|;
name|void
modifier|*
name|allocateDefaultArgStorageChain
parameter_list|(
specifier|const
name|ASTContext
modifier|&
name|C
parameter_list|)
function_decl|;
comment|/// Storage for a default argument. This is conceptually either empty, or an
comment|/// argument value, or a pointer to a previous declaration that had a default
comment|/// argument.
comment|///
comment|/// However, this is complicated by modules: while we require all the default
comment|/// arguments for a template to be equivalent, there may be more than one, and
comment|/// we need to track all the originating parameters to determine if the default
comment|/// argument is visible.
name|template
operator|<
name|typename
name|ParmDecl
operator|,
name|typename
name|ArgType
operator|>
name|class
name|DefaultArgStorage
block|{
comment|/// Storage for both the value *and* another parameter from which we inherit
comment|/// the default argument. This is used when multiple default arguments for a
comment|/// parameter are merged together from different modules.
block|struct
name|Chain
block|{
name|ParmDecl
operator|*
name|PrevDeclWithDefaultArg
block|;
name|ArgType
name|Value
block|;   }
block|;
name|static_assert
argument_list|(
sizeof|sizeof
argument_list|(
name|Chain
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
operator|*
literal|2
argument_list|,
literal|"non-pointer argument type?"
argument_list|)
block|;
name|llvm
operator|::
name|PointerUnion3
operator|<
name|ArgType
block|,
name|ParmDecl
operator|*
block|,
name|Chain
operator|*
operator|>
name|ValueOrInherited
block|;
specifier|static
name|ParmDecl
operator|*
name|getParmOwningDefaultArg
argument_list|(
argument|ParmDecl *Parm
argument_list|)
block|{
specifier|const
name|DefaultArgStorage
operator|&
name|Storage
operator|=
name|Parm
operator|->
name|getDefaultArgStorage
argument_list|()
block|;
if|if
condition|(
name|auto
operator|*
name|Prev
operator|=
name|Storage
operator|.
name|ValueOrInherited
operator|.
name|template
name|dyn_cast
operator|<
name|ParmDecl
operator|*
operator|>
operator|(
operator|)
condition|)
name|Parm
operator|=
name|Prev
expr_stmt|;
name|assert
argument_list|(
argument|!Parm->getDefaultArgStorage()                 .ValueOrInherited.template is<ParmDecl *>()&&
literal|"should only be one level of indirection"
argument_list|)
block|;
return|return
name|Parm
return|;
block|}
name|public
label|:
name|DefaultArgStorage
argument_list|()
operator|:
name|ValueOrInherited
argument_list|(
argument|ArgType()
argument_list|)
block|{}
comment|/// Determine whether there is a default argument for this parameter.
name|bool
name|isSet
argument_list|()
specifier|const
block|{
return|return
operator|!
name|ValueOrInherited
operator|.
name|isNull
argument_list|()
return|;
block|}
comment|/// Determine whether the default argument for this parameter was inherited
comment|/// from a previous declaration of the same entity.
name|bool
name|isInherited
argument_list|()
specifier|const
block|{
return|return
name|ValueOrInherited
operator|.
name|template
name|is
operator|<
name|ParmDecl
operator|*
operator|>
operator|(
operator|)
return|;
block|}
comment|/// Get the default argument's value. This does not consider whether the
comment|/// default argument is visible.
name|ArgType
name|get
argument_list|()
specifier|const
block|{
specifier|const
name|DefaultArgStorage
operator|*
name|Storage
operator|=
name|this
block|;
if|if
condition|(
name|auto
operator|*
name|Prev
operator|=
name|ValueOrInherited
operator|.
name|template
name|dyn_cast
operator|<
name|ParmDecl
operator|*
operator|>
operator|(
operator|)
condition|)
name|Storage
operator|=
operator|&
name|Prev
operator|->
name|getDefaultArgStorage
argument_list|()
expr_stmt|;
if|if
condition|(
name|auto
operator|*
name|C
operator|=
name|Storage
operator|->
name|ValueOrInherited
operator|.
name|template
name|dyn_cast
operator|<
name|Chain
operator|*
operator|>
operator|(
operator|)
condition|)
return|return
name|C
operator|->
name|Value
return|;
return|return
name|Storage
operator|->
name|ValueOrInherited
operator|.
name|template
name|get
operator|<
name|ArgType
operator|>
operator|(
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Get the parameter from which we inherit the default argument, if any.
end_comment

begin_comment
comment|/// This is the parameter on which the default argument was actually written.
end_comment

begin_expr_stmt
specifier|const
name|ParmDecl
operator|*
name|getInheritedFrom
argument_list|()
specifier|const
block|{
if|if
condition|(
name|auto
operator|*
name|D
operator|=
name|ValueOrInherited
operator|.
name|template
name|dyn_cast
operator|<
name|ParmDecl
operator|*
operator|>
operator|(
operator|)
condition|)
return|return
name|D
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|auto
operator|*
name|C
operator|=
name|ValueOrInherited
operator|.
name|template
name|dyn_cast
operator|<
name|Chain
operator|*
operator|>
operator|(
operator|)
condition|)
return|return
name|C
operator|->
name|PrevDeclWithDefaultArg
return|;
end_if

begin_return
return|return
name|nullptr
return|;
end_return

begin_comment
unit|}
comment|/// Set the default argument.
end_comment

begin_macro
unit|void
name|set
argument_list|(
argument|ArgType Arg
argument_list|)
end_macro

begin_block
block|{
name|assert
argument_list|(
operator|!
name|isSet
argument_list|()
operator|&&
literal|"default argument already set"
argument_list|)
expr_stmt|;
name|ValueOrInherited
operator|=
name|Arg
expr_stmt|;
block|}
end_block

begin_comment
comment|/// Set that the default argument was inherited from another parameter.
end_comment

begin_function
name|void
name|setInherited
parameter_list|(
specifier|const
name|ASTContext
modifier|&
name|C
parameter_list|,
name|ParmDecl
modifier|*
name|InheritedFrom
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|isInherited
argument_list|()
operator|&&
literal|"default argument already inherited"
argument_list|)
expr_stmt|;
name|InheritedFrom
operator|=
name|getParmOwningDefaultArg
argument_list|(
name|InheritedFrom
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|isSet
argument_list|()
condition|)
name|ValueOrInherited
operator|=
name|InheritedFrom
expr_stmt|;
else|else
name|ValueOrInherited
operator|=
name|new
argument_list|(
argument|allocateDefaultArgStorageChain(C)
argument_list|)
name|Chain
block|{
name|InheritedFrom
block|,
name|ValueOrInherited
operator|.
name|template
name|get
operator|<
name|ArgType
operator|>
operator|(
operator|)
block|}
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Remove the default argument, even if it was inherited.
end_comment

begin_function
name|void
name|clear
parameter_list|()
block|{
name|ValueOrInherited
operator|=
name|ArgType
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
unit|};
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Kinds of Templates
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// \brief Stores the template parameter list and associated constraints for
end_comment

begin_comment
comment|/// \c TemplateDecl objects that track associated constraints.
end_comment

begin_decl_stmt
name|class
name|ConstrainedTemplateDeclInfo
block|{
name|friend
name|TemplateDecl
decl_stmt|;
name|public
label|:
name|ConstrainedTemplateDeclInfo
argument_list|()
operator|:
name|TemplateParams
argument_list|()
operator|,
name|AssociatedConstraints
argument_list|()
block|{}
name|TemplateParameterList
operator|*
name|getTemplateParameters
argument_list|()
specifier|const
block|{
return|return
name|TemplateParams
return|;
block|}
name|Expr
operator|*
name|getAssociatedConstraints
argument_list|()
specifier|const
block|{
return|return
name|AssociatedConstraints
return|;
block|}
name|protected
label|:
name|void
name|setTemplateParameters
parameter_list|(
name|TemplateParameterList
modifier|*
name|TParams
parameter_list|)
block|{
name|TemplateParams
operator|=
name|TParams
expr_stmt|;
block|}
name|void
name|setAssociatedConstraints
parameter_list|(
name|Expr
modifier|*
name|AC
parameter_list|)
block|{
name|AssociatedConstraints
operator|=
name|AC
expr_stmt|;
block|}
name|TemplateParameterList
modifier|*
name|TemplateParams
decl_stmt|;
name|Expr
modifier|*
name|AssociatedConstraints
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief The base class of all kinds of template declarations (e.g.,
end_comment

begin_comment
comment|/// class, function, etc.).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The TemplateDecl class stores the list of template parameters and a
end_comment

begin_comment
comment|/// reference to the templated scoped declaration: the underlying AST node.
end_comment

begin_decl_stmt
name|class
name|TemplateDecl
range|:
name|public
name|NamedDecl
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
name|protected
operator|:
comment|// Construct a template decl with the given name and parameters.
comment|// Used when there is no templated element (e.g., for tt-params).
name|TemplateDecl
argument_list|(
argument|ConstrainedTemplateDeclInfo *CTDI
argument_list|,
argument|Kind DK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|DeclarationName Name
argument_list|,
argument|TemplateParameterList *Params
argument_list|)
operator|:
name|NamedDecl
argument_list|(
name|DK
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|Name
argument_list|)
block|,
name|TemplatedDecl
argument_list|(
name|nullptr
argument_list|,
name|false
argument_list|)
block|,
name|TemplateParams
argument_list|(
argument|CTDI
argument_list|)
block|{
name|this
operator|->
name|setTemplateParameters
argument_list|(
name|Params
argument_list|)
block|;   }
name|TemplateDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|DeclarationName Name
argument_list|,
argument|TemplateParameterList *Params
argument_list|)
operator|:
name|TemplateDecl
argument_list|(
argument|nullptr
argument_list|,
argument|DK
argument_list|,
argument|DC
argument_list|,
argument|L
argument_list|,
argument|Name
argument_list|,
argument|Params
argument_list|)
block|{}
comment|// Construct a template decl with name, parameters, and templated element.
name|TemplateDecl
argument_list|(
argument|ConstrainedTemplateDeclInfo *CTDI
argument_list|,
argument|Kind DK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|DeclarationName Name
argument_list|,
argument|TemplateParameterList *Params
argument_list|,
argument|NamedDecl *Decl
argument_list|)
operator|:
name|NamedDecl
argument_list|(
name|DK
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|Name
argument_list|)
block|,
name|TemplatedDecl
argument_list|(
name|Decl
argument_list|,
name|false
argument_list|)
block|,
name|TemplateParams
argument_list|(
argument|CTDI
argument_list|)
block|{
name|this
operator|->
name|setTemplateParameters
argument_list|(
name|Params
argument_list|)
block|;   }
name|TemplateDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|DeclarationName Name
argument_list|,
argument|TemplateParameterList *Params
argument_list|,
argument|NamedDecl *Decl
argument_list|)
operator|:
name|TemplateDecl
argument_list|(
argument|nullptr
argument_list|,
argument|DK
argument_list|,
argument|DC
argument_list|,
argument|L
argument_list|,
argument|Name
argument_list|,
argument|Params
argument_list|,
argument|Decl
argument_list|)
block|{}
name|public
operator|:
comment|/// Get the list of template parameters
name|TemplateParameterList
operator|*
name|getTemplateParameters
argument_list|()
specifier|const
block|{
specifier|const
name|auto
operator|*
specifier|const
name|CTDI
operator|=
name|TemplateParams
operator|.
name|dyn_cast
operator|<
name|ConstrainedTemplateDeclInfo
operator|*
operator|>
operator|(
operator|)
block|;
return|return
name|CTDI
condition|?
name|CTDI
operator|->
name|getTemplateParameters
argument_list|()
else|:
name|TemplateParams
operator|.
name|get
operator|<
name|TemplateParameterList
operator|*
operator|>
operator|(
operator|)
return|;
block|}
comment|/// Get the constraint-expression from the associated requires-clause (if any)
specifier|const
name|Expr
operator|*
name|getRequiresClause
argument_list|()
specifier|const
block|{
specifier|const
name|TemplateParameterList
operator|*
specifier|const
name|TP
operator|=
name|getTemplateParameters
argument_list|()
block|;
return|return
name|TP
condition|?
name|TP
operator|->
name|getRequiresClause
argument_list|()
else|:
name|nullptr
return|;
block|}
name|Expr
operator|*
name|getAssociatedConstraints
argument_list|()
specifier|const
block|{
specifier|const
name|TemplateDecl
operator|*
specifier|const
name|C
operator|=
name|cast
operator|<
name|TemplateDecl
operator|>
operator|(
name|getCanonicalDecl
argument_list|()
operator|)
block|;
specifier|const
name|auto
operator|*
specifier|const
name|CTDI
operator|=
name|C
operator|->
name|TemplateParams
operator|.
name|dyn_cast
operator|<
name|ConstrainedTemplateDeclInfo
operator|*
operator|>
operator|(
operator|)
block|;
return|return
name|CTDI
condition|?
name|CTDI
operator|->
name|getAssociatedConstraints
argument_list|()
else|:
name|nullptr
return|;
block|}
comment|/// Get the underlying, templated declaration.
name|NamedDecl
operator|*
name|getTemplatedDecl
argument_list|()
specifier|const
block|{
return|return
name|TemplatedDecl
operator|.
name|getPointer
argument_list|()
return|;
block|}
comment|// Implement isa/cast/dyncast/etc.
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classofKind
argument_list|(
argument|Kind K
argument_list|)
block|{
return|return
name|K
operator|>=
name|firstTemplate
operator|&&
name|K
operator|<=
name|lastTemplate
return|;
block|}
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|override
name|LLVM_READONLY
block|{
return|return
name|SourceRange
argument_list|(
name|getTemplateParameters
argument_list|()
operator|->
name|getTemplateLoc
argument_list|()
argument_list|,
name|TemplatedDecl
operator|.
name|getPointer
argument_list|()
operator|->
name|getSourceRange
argument_list|()
operator|.
name|getEnd
argument_list|()
argument_list|)
return|;
block|}
comment|/// Whether this is a (C++ Concepts TS) function or variable concept.
name|bool
name|isConcept
argument_list|()
specifier|const
block|{
return|return
name|TemplatedDecl
operator|.
name|getInt
argument_list|()
return|;
block|}
name|void
name|setConcept
argument_list|()
block|{
name|TemplatedDecl
operator|.
name|setInt
argument_list|(
name|true
argument_list|)
block|; }
name|protected
operator|:
comment|/// \brief The named declaration from which this template was instantiated.
comment|/// (or null).
comment|///
comment|/// The boolean value will be true to indicate that this template
comment|/// (function or variable) is a concept.
name|llvm
operator|::
name|PointerIntPair
operator|<
name|NamedDecl
operator|*
block|,
literal|1
block|,
name|bool
operator|>
name|TemplatedDecl
block|;
comment|/// \brief The template parameter list and optional requires-clause
comment|/// associated with this declaration; alternatively, a
comment|/// \c ConstrainedTemplateDeclInfo if the associated constraints of the
comment|/// template are being tracked by this particular declaration.
name|llvm
operator|::
name|PointerUnion
operator|<
name|TemplateParameterList
operator|*
block|,
name|ConstrainedTemplateDeclInfo
operator|*
operator|>
name|TemplateParams
block|;
name|void
name|setTemplateParameters
argument_list|(
argument|TemplateParameterList *TParams
argument_list|)
block|{
if|if
condition|(
name|auto
operator|*
specifier|const
name|CTDI
operator|=
name|TemplateParams
operator|.
name|dyn_cast
operator|<
name|ConstrainedTemplateDeclInfo
operator|*
operator|>
operator|(
operator|)
condition|)
block|{
name|CTDI
operator|->
name|setTemplateParameters
argument_list|(
name|TParams
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|TemplateParams
operator|=
name|TParams
expr_stmt|;
block|}
block|}
name|void
name|setAssociatedConstraints
argument_list|(
argument|Expr *AC
argument_list|)
block|{
name|assert
argument_list|(
name|isCanonicalDecl
argument_list|()
operator|&&
literal|"Attaching associated constraints to non-canonical Decl"
argument_list|)
block|;
name|TemplateParams
operator|.
name|get
operator|<
name|ConstrainedTemplateDeclInfo
operator|*
operator|>
operator|(
operator|)
operator|->
name|setAssociatedConstraints
argument_list|(
name|AC
argument_list|)
block|;   }
name|public
operator|:
comment|/// \brief Initialize the underlying templated declaration and
comment|/// template parameters.
name|void
name|init
argument_list|(
argument|NamedDecl *templatedDecl
argument_list|,
argument|TemplateParameterList* templateParams
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|TemplatedDecl
operator|.
name|getPointer
argument_list|()
operator|&&
literal|"TemplatedDecl already set!"
argument_list|)
block|;
name|assert
argument_list|(
operator|!
name|TemplateParams
operator|&&
literal|"TemplateParams already set!"
argument_list|)
block|;
name|TemplatedDecl
operator|.
name|setPointer
argument_list|(
name|templatedDecl
argument_list|)
block|;
name|TemplateParams
operator|=
name|templateParams
block|;   }
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Provides information about a function template specialization,
end_comment

begin_comment
comment|/// which is a FunctionDecl that has been explicitly specialization or
end_comment

begin_comment
comment|/// instantiated from a function template.
end_comment

begin_decl_stmt
name|class
name|FunctionTemplateSpecializationInfo
range|:
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
name|FunctionTemplateSpecializationInfo
argument_list|(
argument|FunctionDecl *FD
argument_list|,
argument|FunctionTemplateDecl *Template
argument_list|,
argument|TemplateSpecializationKind TSK
argument_list|,
argument|const TemplateArgumentList *TemplateArgs
argument_list|,
argument|const ASTTemplateArgumentListInfo *TemplateArgsAsWritten
argument_list|,
argument|SourceLocation POI
argument_list|)
operator|:
name|Function
argument_list|(
name|FD
argument_list|)
block|,
name|Template
argument_list|(
name|Template
argument_list|,
name|TSK
operator|-
literal|1
argument_list|)
block|,
name|TemplateArguments
argument_list|(
name|TemplateArgs
argument_list|)
block|,
name|TemplateArgumentsAsWritten
argument_list|(
name|TemplateArgsAsWritten
argument_list|)
block|,
name|PointOfInstantiation
argument_list|(
argument|POI
argument_list|)
block|{ }
name|public
operator|:
specifier|static
name|FunctionTemplateSpecializationInfo
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|FunctionDecl *FD
argument_list|,
argument|FunctionTemplateDecl *Template
argument_list|,
argument|TemplateSpecializationKind TSK
argument_list|,
argument|const TemplateArgumentList *TemplateArgs
argument_list|,
argument|const TemplateArgumentListInfo *TemplateArgsAsWritten
argument_list|,
argument|SourceLocation POI
argument_list|)
block|;
comment|/// \brief The function template specialization that this structure
comment|/// describes.
name|FunctionDecl
operator|*
name|Function
block|;
comment|/// \brief The function template from which this function template
comment|/// specialization was generated.
comment|///
comment|/// The two bits contain the top 4 values of TemplateSpecializationKind.
name|llvm
operator|::
name|PointerIntPair
operator|<
name|FunctionTemplateDecl
operator|*
block|,
literal|2
operator|>
name|Template
block|;
comment|/// \brief The template arguments used to produce the function template
comment|/// specialization from the function template.
specifier|const
name|TemplateArgumentList
operator|*
name|TemplateArguments
block|;
comment|/// \brief The template arguments as written in the sources, if provided.
specifier|const
name|ASTTemplateArgumentListInfo
operator|*
name|TemplateArgumentsAsWritten
block|;
comment|/// \brief The point at which this function template specialization was
comment|/// first instantiated.
name|SourceLocation
name|PointOfInstantiation
block|;
comment|/// \brief Retrieve the template from which this function was specialized.
name|FunctionTemplateDecl
operator|*
name|getTemplate
argument_list|()
specifier|const
block|{
return|return
name|Template
operator|.
name|getPointer
argument_list|()
return|;
block|}
comment|/// \brief Determine what kind of template specialization this is.
name|TemplateSpecializationKind
name|getTemplateSpecializationKind
argument_list|()
specifier|const
block|{
return|return
call|(
name|TemplateSpecializationKind
call|)
argument_list|(
name|Template
operator|.
name|getInt
argument_list|()
operator|+
literal|1
argument_list|)
return|;
block|}
name|bool
name|isExplicitSpecialization
argument_list|()
specifier|const
block|{
return|return
name|getTemplateSpecializationKind
argument_list|()
operator|==
name|TSK_ExplicitSpecialization
return|;
block|}
comment|/// \brief True if this declaration is an explicit specialization,
comment|/// explicit instantiation declaration, or explicit instantiation
comment|/// definition.
name|bool
name|isExplicitInstantiationOrSpecialization
argument_list|()
specifier|const
block|{
return|return
name|isTemplateExplicitInstantiationOrSpecialization
argument_list|(
name|getTemplateSpecializationKind
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Set the template specialization kind.
name|void
name|setTemplateSpecializationKind
argument_list|(
argument|TemplateSpecializationKind TSK
argument_list|)
block|{
name|assert
argument_list|(
name|TSK
operator|!=
name|TSK_Undeclared
operator|&&
literal|"Cannot encode TSK_Undeclared for a function template specialization"
argument_list|)
block|;
name|Template
operator|.
name|setInt
argument_list|(
name|TSK
operator|-
literal|1
argument_list|)
block|;   }
comment|/// \brief Retrieve the first point of instantiation of this function
comment|/// template specialization.
comment|///
comment|/// The point of instantiation may be an invalid source location if this
comment|/// function has yet to be instantiated.
name|SourceLocation
name|getPointOfInstantiation
argument_list|()
specifier|const
block|{
return|return
name|PointOfInstantiation
return|;
block|}
comment|/// \brief Set the (first) point of instantiation of this function template
comment|/// specialization.
name|void
name|setPointOfInstantiation
argument_list|(
argument|SourceLocation POI
argument_list|)
block|{
name|PointOfInstantiation
operator|=
name|POI
block|;   }
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
name|TemplateArguments
operator|->
name|asArray
argument_list|()
argument_list|,
name|Function
operator|->
name|getASTContext
argument_list|()
argument_list|)
block|;   }
specifier|static
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|,
argument|ArrayRef<TemplateArgument> TemplateArgs
argument_list|,
argument|ASTContext&Context
argument_list|)
block|{
name|ID
operator|.
name|AddInteger
argument_list|(
name|TemplateArgs
operator|.
name|size
argument_list|()
argument_list|)
block|;
for|for
control|(
specifier|const
name|TemplateArgument
modifier|&
name|TemplateArg
range|:
name|TemplateArgs
control|)
name|TemplateArg
operator|.
name|Profile
argument_list|(
name|ID
argument_list|,
name|Context
argument_list|)
expr_stmt|;
block|}
expr|}
block|;
comment|/// \brief Provides information a specialization of a member of a class
comment|/// template, which may be a member function, static data member,
comment|/// member class or member enumeration.
name|class
name|MemberSpecializationInfo
block|{
comment|// The member declaration from which this member was instantiated, and the
comment|// manner in which the instantiation occurred (in the lower two bits).
name|llvm
operator|::
name|PointerIntPair
operator|<
name|NamedDecl
operator|*
block|,
literal|2
operator|>
name|MemberAndTSK
block|;
comment|// The point at which this member was first instantiated.
name|SourceLocation
name|PointOfInstantiation
block|;
name|public
operator|:
name|explicit
name|MemberSpecializationInfo
argument_list|(
argument|NamedDecl *IF
argument_list|,
argument|TemplateSpecializationKind TSK
argument_list|,
argument|SourceLocation POI = SourceLocation()
argument_list|)
operator|:
name|MemberAndTSK
argument_list|(
name|IF
argument_list|,
name|TSK
operator|-
literal|1
argument_list|)
block|,
name|PointOfInstantiation
argument_list|(
argument|POI
argument_list|)
block|{
name|assert
argument_list|(
name|TSK
operator|!=
name|TSK_Undeclared
operator|&&
literal|"Cannot encode undeclared template specializations for members"
argument_list|)
block|;   }
comment|/// \brief Retrieve the member declaration from which this member was
comment|/// instantiated.
name|NamedDecl
operator|*
name|getInstantiatedFrom
argument_list|()
specifier|const
block|{
return|return
name|MemberAndTSK
operator|.
name|getPointer
argument_list|()
return|;
block|}
comment|/// \brief Determine what kind of template specialization this is.
name|TemplateSpecializationKind
name|getTemplateSpecializationKind
argument_list|()
specifier|const
block|{
return|return
call|(
name|TemplateSpecializationKind
call|)
argument_list|(
name|MemberAndTSK
operator|.
name|getInt
argument_list|()
operator|+
literal|1
argument_list|)
return|;
block|}
name|bool
name|isExplicitSpecialization
argument_list|()
specifier|const
block|{
return|return
name|getTemplateSpecializationKind
argument_list|()
operator|==
name|TSK_ExplicitSpecialization
return|;
block|}
comment|/// \brief Set the template specialization kind.
name|void
name|setTemplateSpecializationKind
argument_list|(
argument|TemplateSpecializationKind TSK
argument_list|)
block|{
name|assert
argument_list|(
name|TSK
operator|!=
name|TSK_Undeclared
operator|&&
literal|"Cannot encode undeclared template specializations for members"
argument_list|)
block|;
name|MemberAndTSK
operator|.
name|setInt
argument_list|(
name|TSK
operator|-
literal|1
argument_list|)
block|;   }
comment|/// \brief Retrieve the first point of instantiation of this member.
comment|/// If the point of instantiation is an invalid location, then this member
comment|/// has not yet been instantiated.
name|SourceLocation
name|getPointOfInstantiation
argument_list|()
specifier|const
block|{
return|return
name|PointOfInstantiation
return|;
block|}
comment|/// \brief Set the first point of instantiation.
name|void
name|setPointOfInstantiation
argument_list|(
argument|SourceLocation POI
argument_list|)
block|{
name|PointOfInstantiation
operator|=
name|POI
block|;   }
expr|}
block|;
comment|/// \brief Provides information about a dependent function-template
comment|/// specialization declaration.
comment|///
comment|/// Since explicit function template specialization and instantiation
comment|/// declarations can only appear in namespace scope, and you can only
comment|/// specialize a member of a fully-specialized class, the only way to
comment|/// get one of these is in a friend declaration like the following:
comment|///
comment|/// \code
comment|///   template \<class T> void foo(T);
comment|///   template \<class T> class A {
comment|///     friend void foo<>(T);
comment|///   };
comment|/// \endcode
name|class
name|DependentFunctionTemplateSpecializationInfo
name|final
operator|:
name|private
name|llvm
operator|::
name|TrailingObjects
operator|<
name|DependentFunctionTemplateSpecializationInfo
block|,
name|TemplateArgumentLoc
block|,
name|FunctionTemplateDecl
operator|*
operator|>
block|{
comment|/// The number of potential template candidates.
name|unsigned
name|NumTemplates
block|;
comment|/// The number of template arguments.
name|unsigned
name|NumArgs
block|;
comment|/// The locations of the left and right angle brackets.
name|SourceRange
name|AngleLocs
block|;
name|size_t
name|numTrailingObjects
argument_list|(
argument|OverloadToken<TemplateArgumentLoc>
argument_list|)
specifier|const
block|{
return|return
name|NumArgs
return|;
block|}
name|size_t
name|numTrailingObjects
argument_list|(
argument|OverloadToken<FunctionTemplateDecl *>
argument_list|)
specifier|const
block|{
return|return
name|NumTemplates
return|;
block|}
name|DependentFunctionTemplateSpecializationInfo
argument_list|(
specifier|const
name|UnresolvedSetImpl
operator|&
name|Templates
argument_list|,
specifier|const
name|TemplateArgumentListInfo
operator|&
name|TemplateArgs
argument_list|)
block|;
name|public
operator|:
specifier|static
name|DependentFunctionTemplateSpecializationInfo
operator|*
name|Create
argument_list|(
name|ASTContext
operator|&
name|Context
argument_list|,
specifier|const
name|UnresolvedSetImpl
operator|&
name|Templates
argument_list|,
specifier|const
name|TemplateArgumentListInfo
operator|&
name|TemplateArgs
argument_list|)
block|;
comment|/// \brief Returns the number of function templates that this might
comment|/// be a specialization of.
name|unsigned
name|getNumTemplates
argument_list|()
specifier|const
block|{
return|return
name|NumTemplates
return|;
block|}
comment|/// \brief Returns the i'th template candidate.
name|FunctionTemplateDecl
operator|*
name|getTemplate
argument_list|(
argument|unsigned I
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|I
operator|<
name|getNumTemplates
argument_list|()
operator|&&
literal|"template index out of range"
argument_list|)
block|;
return|return
name|getTrailingObjects
operator|<
name|FunctionTemplateDecl
operator|*
operator|>
operator|(
operator|)
index|[
name|I
index|]
return|;
block|}
comment|/// \brief Returns the explicit template arguments that were given.
specifier|const
name|TemplateArgumentLoc
operator|*
name|getTemplateArgs
argument_list|()
specifier|const
block|{
return|return
name|getTrailingObjects
operator|<
name|TemplateArgumentLoc
operator|>
operator|(
operator|)
return|;
block|}
comment|/// \brief Returns the number of explicit template arguments that were given.
name|unsigned
name|getNumTemplateArgs
argument_list|()
specifier|const
block|{
return|return
name|NumArgs
return|;
block|}
comment|/// \brief Returns the nth template argument.
specifier|const
name|TemplateArgumentLoc
operator|&
name|getTemplateArg
argument_list|(
argument|unsigned I
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|I
operator|<
name|getNumTemplateArgs
argument_list|()
operator|&&
literal|"template arg index out of range"
argument_list|)
block|;
return|return
name|getTemplateArgs
argument_list|()
index|[
name|I
index|]
return|;
block|}
name|SourceLocation
name|getLAngleLoc
argument_list|()
specifier|const
block|{
return|return
name|AngleLocs
operator|.
name|getBegin
argument_list|()
return|;
block|}
name|SourceLocation
name|getRAngleLoc
argument_list|()
specifier|const
block|{
return|return
name|AngleLocs
operator|.
name|getEnd
argument_list|()
return|;
block|}
name|friend
name|TrailingObjects
block|; }
block|;
comment|/// Declaration of a redeclarable template.
name|class
name|RedeclarableTemplateDecl
operator|:
name|public
name|TemplateDecl
block|,
name|public
name|Redeclarable
operator|<
name|RedeclarableTemplateDecl
operator|>
block|{
typedef|typedef
name|Redeclarable
operator|<
name|RedeclarableTemplateDecl
operator|>
name|redeclarable_base
expr_stmt|;
name|RedeclarableTemplateDecl
operator|*
name|getNextRedeclarationImpl
argument_list|()
name|override
block|{
return|return
name|getNextRedeclaration
argument_list|()
return|;
block|}
name|RedeclarableTemplateDecl
operator|*
name|getPreviousDeclImpl
argument_list|()
name|override
block|{
return|return
name|getPreviousDecl
argument_list|()
return|;
block|}
name|RedeclarableTemplateDecl
operator|*
name|getMostRecentDeclImpl
argument_list|()
name|override
block|{
return|return
name|getMostRecentDecl
argument_list|()
return|;
block|}
name|protected
operator|:
name|template
operator|<
name|typename
name|EntryType
operator|>
expr|struct
name|SpecEntryTraits
block|{
typedef|typedef
name|EntryType
name|DeclType
typedef|;
specifier|static
name|DeclType
operator|*
name|getDecl
argument_list|(
argument|EntryType *D
argument_list|)
block|{
return|return
name|D
return|;
block|}
specifier|static
name|ArrayRef
operator|<
name|TemplateArgument
operator|>
name|getTemplateArgs
argument_list|(
argument|EntryType *D
argument_list|)
block|{
return|return
name|D
operator|->
name|getTemplateArgs
argument_list|()
operator|.
name|asArray
argument_list|()
return|;
block|}
expr|}
block|;
name|template
operator|<
name|typename
name|EntryType
block|,
name|typename
name|SETraits
operator|=
name|SpecEntryTraits
operator|<
name|EntryType
operator|>
block|,
name|typename
name|DeclType
operator|=
name|typename
name|SETraits
operator|::
name|DeclType
operator|>
expr|struct
name|SpecIterator
operator|:
name|llvm
operator|::
name|iterator_adaptor_base
operator|<
name|SpecIterator
operator|<
name|EntryType
block|,
name|SETraits
block|,
name|DeclType
operator|>
block|,
name|typename
name|llvm
operator|::
name|FoldingSetVector
operator|<
name|EntryType
operator|>
operator|::
name|iterator
block|,
name|typename
name|std
operator|::
name|iterator_traits
operator|<
name|typename
name|llvm
operator|::
name|FoldingSetVector
operator|<
name|EntryType
operator|>
operator|::
name|iterator
operator|>
operator|::
name|iterator_category
block|,
name|DeclType
operator|*
block|,
name|ptrdiff_t
block|,
name|DeclType
operator|*
block|,
name|DeclType
operator|*
operator|>
block|{
name|SpecIterator
argument_list|()
block|{}
name|explicit
name|SpecIterator
argument_list|(
argument|typename llvm::FoldingSetVector<EntryType>::iterator SetIter
argument_list|)
operator|:
name|SpecIterator
operator|::
name|iterator_adaptor_base
argument_list|(
argument|std::move(SetIter)
argument_list|)
block|{}
name|DeclType
operator|*
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|SETraits
operator|::
name|getDecl
argument_list|(
operator|&
operator|*
name|this
operator|->
name|I
argument_list|)
operator|->
name|getMostRecentDecl
argument_list|()
return|;
block|}
name|DeclType
operator|*
name|operator
operator|->
expr|(
block|)
specifier|const
block|{
return|return
operator|*
operator|*
name|this
return|;
block|}
expr|}
block|;
name|template
operator|<
name|typename
name|EntryType
operator|>
specifier|static
name|SpecIterator
operator|<
name|EntryType
operator|>
name|makeSpecIterator
argument_list|(
argument|llvm::FoldingSetVector<EntryType>&Specs
argument_list|,
argument|bool isEnd
argument_list|)
block|{
return|return
name|SpecIterator
operator|<
name|EntryType
operator|>
operator|(
name|isEnd
operator|?
name|Specs
operator|.
name|end
argument_list|()
operator|:
name|Specs
operator|.
name|begin
argument_list|()
operator|)
return|;
block|}
name|template
operator|<
name|class
name|EntryType
operator|>
name|typename
name|SpecEntryTraits
operator|<
name|EntryType
operator|>
operator|::
name|DeclType
operator|*
name|findSpecializationImpl
argument_list|(
name|llvm
operator|::
name|FoldingSetVector
operator|<
name|EntryType
operator|>
operator|&
name|Specs
argument_list|,
name|ArrayRef
operator|<
name|TemplateArgument
operator|>
name|Args
argument_list|,
name|void
operator|*
operator|&
name|InsertPos
argument_list|)
block|;
name|template
operator|<
name|class
name|Derived
block|,
name|class
name|EntryType
operator|>
name|void
name|addSpecializationImpl
argument_list|(
name|llvm
operator|::
name|FoldingSetVector
operator|<
name|EntryType
operator|>
operator|&
name|Specs
argument_list|,
name|EntryType
operator|*
name|Entry
argument_list|,
name|void
operator|*
name|InsertPos
argument_list|)
block|;    struct
name|CommonBase
block|{
name|CommonBase
argument_list|()
operator|:
name|InstantiatedFromMember
argument_list|(
argument|nullptr
argument_list|,
argument|false
argument_list|)
block|{ }
comment|/// \brief The template from which this was most
comment|/// directly instantiated (or null).
comment|///
comment|/// The boolean value indicates whether this template
comment|/// was explicitly specialized.
name|llvm
operator|::
name|PointerIntPair
operator|<
name|RedeclarableTemplateDecl
operator|*
block|,
literal|1
block|,
name|bool
operator|>
name|InstantiatedFromMember
block|;   }
block|;
comment|/// \brief Pointer to the common data shared by all declarations of this
comment|/// template.
name|mutable
name|CommonBase
operator|*
name|Common
block|;
comment|/// \brief Retrieves the "common" pointer shared by all (re-)declarations of
comment|/// the same template. Calling this routine may implicitly allocate memory
comment|/// for the common pointer.
name|CommonBase
operator|*
name|getCommonPtr
argument_list|()
specifier|const
block|;
name|virtual
name|CommonBase
operator|*
name|newCommon
argument_list|(
argument|ASTContext&C
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|// Construct a template decl with name, parameters, and templated element.
name|RedeclarableTemplateDecl
argument_list|(
argument|ConstrainedTemplateDeclInfo *CTDI
argument_list|,
argument|Kind DK
argument_list|,
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|DeclarationName Name
argument_list|,
argument|TemplateParameterList *Params
argument_list|,
argument|NamedDecl *Decl
argument_list|)
operator|:
name|TemplateDecl
argument_list|(
name|CTDI
argument_list|,
name|DK
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|Name
argument_list|,
name|Params
argument_list|,
name|Decl
argument_list|)
block|,
name|redeclarable_base
argument_list|(
name|C
argument_list|)
block|,
name|Common
argument_list|()
block|{}
name|RedeclarableTemplateDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|DeclarationName Name
argument_list|,
argument|TemplateParameterList *Params
argument_list|,
argument|NamedDecl *Decl
argument_list|)
operator|:
name|RedeclarableTemplateDecl
argument_list|(
argument|nullptr
argument_list|,
argument|DK
argument_list|,
argument|C
argument_list|,
argument|DC
argument_list|,
argument|L
argument_list|,
argument|Name
argument_list|,
argument|Params
argument_list|,
argument|Decl
argument_list|)
block|{}
name|public
operator|:
name|template
operator|<
name|class
name|decl_type
operator|>
name|friend
name|class
name|RedeclarableTemplate
block|;
comment|/// \brief Retrieves the canonical declaration of this template.
name|RedeclarableTemplateDecl
operator|*
name|getCanonicalDecl
argument_list|()
name|override
block|{
return|return
name|getFirstDecl
argument_list|()
return|;
block|}
specifier|const
name|RedeclarableTemplateDecl
operator|*
name|getCanonicalDecl
argument_list|()
specifier|const
block|{
return|return
name|getFirstDecl
argument_list|()
return|;
block|}
comment|/// \brief Determines whether this template was a specialization of a
comment|/// member template.
comment|///
comment|/// In the following example, the function template \c X<int>::f and the
comment|/// member template \c X<int>::Inner are member specializations.
comment|///
comment|/// \code
comment|/// template<typename T>
comment|/// struct X {
comment|///   template<typename U> void f(T, U);
comment|///   template<typename U> struct Inner;
comment|/// };
comment|///
comment|/// template<> template<typename T>
comment|/// void X<int>::f(int, T);
comment|/// template<> template<typename T>
comment|/// struct X<int>::Inner { /* ... */ };
comment|/// \endcode
name|bool
name|isMemberSpecialization
argument_list|()
specifier|const
block|{
return|return
name|getCommonPtr
argument_list|()
operator|->
name|InstantiatedFromMember
operator|.
name|getInt
argument_list|()
return|;
block|}
comment|/// \brief Note that this member template is a specialization.
name|void
name|setMemberSpecialization
argument_list|()
block|{
name|assert
argument_list|(
name|getCommonPtr
argument_list|()
operator|->
name|InstantiatedFromMember
operator|.
name|getPointer
argument_list|()
operator|&&
literal|"Only member templates can be member template specializations"
argument_list|)
block|;
name|getCommonPtr
argument_list|()
operator|->
name|InstantiatedFromMember
operator|.
name|setInt
argument_list|(
name|true
argument_list|)
block|;   }
comment|/// \brief Retrieve the member template from which this template was
comment|/// instantiated, or NULL if this template was not instantiated from a
comment|/// member template.
comment|///
comment|/// A template is instantiated from a member template when the member
comment|/// template itself is part of a class template (or member thereof). For
comment|/// example, given
comment|///
comment|/// \code
comment|/// template<typename T>
comment|/// struct X {
comment|///   template<typename U> void f(T, U);
comment|/// };
comment|///
comment|/// void test(X<int> x) {
comment|///   x.f(1, 'a');
comment|/// };
comment|/// \endcode
comment|///
comment|/// \c X<int>::f is a FunctionTemplateDecl that describes the function
comment|/// template
comment|///
comment|/// \code
comment|/// template<typename U> void X<int>::f(int, U);
comment|/// \endcode
comment|///
comment|/// which was itself created during the instantiation of \c X<int>. Calling
comment|/// getInstantiatedFromMemberTemplate() on this FunctionTemplateDecl will
comment|/// retrieve the FunctionTemplateDecl for the original template \c f within
comment|/// the class template \c X<T>, i.e.,
comment|///
comment|/// \code
comment|/// template<typename T>
comment|/// template<typename U>
comment|/// void X<T>::f(T, U);
comment|/// \endcode
name|RedeclarableTemplateDecl
operator|*
name|getInstantiatedFromMemberTemplate
argument_list|()
specifier|const
block|{
return|return
name|getCommonPtr
argument_list|()
operator|->
name|InstantiatedFromMember
operator|.
name|getPointer
argument_list|()
return|;
block|}
name|void
name|setInstantiatedFromMemberTemplate
argument_list|(
argument|RedeclarableTemplateDecl *TD
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|getCommonPtr
argument_list|()
operator|->
name|InstantiatedFromMember
operator|.
name|getPointer
argument_list|()
argument_list|)
block|;
name|getCommonPtr
argument_list|()
operator|->
name|InstantiatedFromMember
operator|.
name|setPointer
argument_list|(
name|TD
argument_list|)
block|;   }
typedef|typedef
name|redeclarable_base
operator|::
name|redecl_range
name|redecl_range
expr_stmt|;
typedef|typedef
name|redeclarable_base
operator|::
name|redecl_iterator
name|redecl_iterator
expr_stmt|;
name|using
name|redeclarable_base
operator|::
name|redecls_begin
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|redecls_end
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|redecls
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|getPreviousDecl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|getMostRecentDecl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|isFirstDecl
expr_stmt|;
end_expr_stmt

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
name|D
parameter_list|)
block|{
return|return
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
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
name|K
operator|>=
name|firstRedeclarableTemplate
operator|&&
name|K
operator|<=
name|lastRedeclarableTemplate
return|;
block|}
end_function

begin_decl_stmt
name|friend
name|class
name|ASTReader
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|ASTDeclReader
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|ASTDeclWriter
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|RedeclarableTemplateDecl
operator|::
name|SpecEntryTraits
operator|<
name|FunctionTemplateSpecializationInfo
operator|>
block|{
typedef|typedef
name|FunctionDecl
name|DeclType
typedef|;
specifier|static
name|DeclType
operator|*
name|getDecl
argument_list|(
argument|FunctionTemplateSpecializationInfo *I
argument_list|)
block|{
return|return
name|I
operator|->
name|Function
return|;
block|}
specifier|static
name|ArrayRef
operator|<
name|TemplateArgument
operator|>
name|getTemplateArgs
argument_list|(
argument|FunctionTemplateSpecializationInfo *I
argument_list|)
block|{
return|return
name|I
operator|->
name|TemplateArguments
operator|->
name|asArray
argument_list|()
return|;
block|}
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// Declaration of a template function.
end_comment

begin_decl_stmt
name|class
name|FunctionTemplateDecl
range|:
name|public
name|RedeclarableTemplateDecl
block|{
name|protected
operator|:
comment|/// \brief Data that is common to all of the declarations of a given
comment|/// function template.
expr|struct
name|Common
operator|:
name|CommonBase
block|{
name|Common
argument_list|()
operator|:
name|InjectedArgs
argument_list|()
block|,
name|LazySpecializations
argument_list|()
block|{ }
comment|/// \brief The function template specializations for this function
comment|/// template, including explicit specializations and instantiations.
name|llvm
operator|::
name|FoldingSetVector
operator|<
name|FunctionTemplateSpecializationInfo
operator|>
name|Specializations
block|;
comment|/// \brief The set of "injected" template arguments used within this
comment|/// function template.
comment|///
comment|/// This pointer refers to the template arguments (there are as
comment|/// many template arguments as template parameaters) for the function
comment|/// template, and is allocated lazily, since most function templates do not
comment|/// require the use of this information.
name|TemplateArgument
operator|*
name|InjectedArgs
block|;
comment|/// \brief If non-null, points to an array of specializations known only
comment|/// by their external declaration IDs.
comment|///
comment|/// The first value in the array is the number of of specializations
comment|/// that follow.
name|uint32_t
operator|*
name|LazySpecializations
block|;   }
block|;
name|FunctionTemplateDecl
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|DeclarationName Name
argument_list|,
argument|TemplateParameterList *Params
argument_list|,
argument|NamedDecl *Decl
argument_list|)
operator|:
name|RedeclarableTemplateDecl
argument_list|(
argument|FunctionTemplate
argument_list|,
argument|C
argument_list|,
argument|DC
argument_list|,
argument|L
argument_list|,
argument|Name
argument_list|,
argument|Params
argument_list|,
argument|Decl
argument_list|)
block|{}
name|CommonBase
operator|*
name|newCommon
argument_list|(
argument|ASTContext&C
argument_list|)
specifier|const
name|override
block|;
name|Common
operator|*
name|getCommonPtr
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|Common
operator|*
operator|>
operator|(
name|RedeclarableTemplateDecl
operator|::
name|getCommonPtr
argument_list|()
operator|)
return|;
block|}
name|friend
name|class
name|FunctionDecl
block|;
comment|/// \brief Retrieve the set of function template specializations of this
comment|/// function template.
name|llvm
operator|::
name|FoldingSetVector
operator|<
name|FunctionTemplateSpecializationInfo
operator|>
operator|&
name|getSpecializations
argument_list|()
specifier|const
block|;
comment|/// \brief Add a specialization of this function template.
comment|///
comment|/// \param InsertPos Insert position in the FoldingSetVector, must have been
comment|///        retrieved by an earlier call to findSpecialization().
name|void
name|addSpecialization
argument_list|(
name|FunctionTemplateSpecializationInfo
operator|*
name|Info
argument_list|,
name|void
operator|*
name|InsertPos
argument_list|)
block|;
name|public
operator|:
comment|/// \brief Load any lazily-loaded specializations from the external source.
name|void
name|LoadLazySpecializations
argument_list|()
specifier|const
block|;
comment|/// Get the underlying function declaration of the template.
name|FunctionDecl
operator|*
name|getTemplatedDecl
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|FunctionDecl
operator|*
operator|>
operator|(
name|TemplatedDecl
operator|.
name|getPointer
argument_list|()
operator|)
return|;
block|}
comment|/// Returns whether this template declaration defines the primary
comment|/// pattern.
name|bool
name|isThisDeclarationADefinition
argument_list|()
specifier|const
block|{
return|return
name|getTemplatedDecl
argument_list|()
operator|->
name|isThisDeclarationADefinition
argument_list|()
return|;
block|}
comment|/// \brief Return the specialization with the provided arguments if it exists,
comment|/// otherwise return the insertion point.
name|FunctionDecl
operator|*
name|findSpecialization
argument_list|(
name|ArrayRef
operator|<
name|TemplateArgument
operator|>
name|Args
argument_list|,
name|void
operator|*
operator|&
name|InsertPos
argument_list|)
block|;
name|FunctionTemplateDecl
operator|*
name|getCanonicalDecl
argument_list|()
name|override
block|{
return|return
name|cast
operator|<
name|FunctionTemplateDecl
operator|>
operator|(
name|RedeclarableTemplateDecl
operator|::
name|getCanonicalDecl
argument_list|()
operator|)
return|;
block|}
specifier|const
name|FunctionTemplateDecl
operator|*
name|getCanonicalDecl
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|FunctionTemplateDecl
operator|>
operator|(
name|RedeclarableTemplateDecl
operator|::
name|getCanonicalDecl
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Retrieve the previous declaration of this function template, or
comment|/// NULL if no such declaration exists.
name|FunctionTemplateDecl
operator|*
name|getPreviousDecl
argument_list|()
block|{
return|return
name|cast_or_null
operator|<
name|FunctionTemplateDecl
operator|>
operator|(
name|static_cast
operator|<
name|RedeclarableTemplateDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getPreviousDecl
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Retrieve the previous declaration of this function template, or
comment|/// NULL if no such declaration exists.
specifier|const
name|FunctionTemplateDecl
operator|*
name|getPreviousDecl
argument_list|()
specifier|const
block|{
return|return
name|cast_or_null
operator|<
name|FunctionTemplateDecl
operator|>
operator|(
name|static_cast
operator|<
specifier|const
name|RedeclarableTemplateDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getPreviousDecl
argument_list|()
operator|)
return|;
block|}
name|FunctionTemplateDecl
operator|*
name|getMostRecentDecl
argument_list|()
block|{
return|return
name|cast
operator|<
name|FunctionTemplateDecl
operator|>
operator|(
name|static_cast
operator|<
name|RedeclarableTemplateDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getMostRecentDecl
argument_list|()
operator|)
return|;
block|}
specifier|const
name|FunctionTemplateDecl
operator|*
name|getMostRecentDecl
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|FunctionTemplateDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getMostRecentDecl
argument_list|()
return|;
block|}
name|FunctionTemplateDecl
operator|*
name|getInstantiatedFromMemberTemplate
argument_list|()
specifier|const
block|{
return|return
name|cast_or_null
operator|<
name|FunctionTemplateDecl
operator|>
operator|(
name|RedeclarableTemplateDecl
operator|::
name|getInstantiatedFromMemberTemplate
argument_list|()
operator|)
return|;
block|}
typedef|typedef
name|SpecIterator
operator|<
name|FunctionTemplateSpecializationInfo
operator|>
name|spec_iterator
expr_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|spec_iterator
operator|>
name|spec_range
expr_stmt|;
end_typedef

begin_expr_stmt
name|spec_range
name|specializations
argument_list|()
specifier|const
block|{
return|return
name|spec_range
argument_list|(
name|spec_begin
argument_list|()
argument_list|,
name|spec_end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|spec_iterator
name|spec_begin
argument_list|()
specifier|const
block|{
return|return
name|makeSpecIterator
argument_list|(
name|getSpecializations
argument_list|()
argument_list|,
name|false
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|spec_iterator
name|spec_end
argument_list|()
specifier|const
block|{
return|return
name|makeSpecIterator
argument_list|(
name|getSpecializations
argument_list|()
argument_list|,
name|true
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the "injected" template arguments that correspond to the
end_comment

begin_comment
comment|/// template parameters of this function template.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Although the C++ standard has no notion of the "injected" template
end_comment

begin_comment
comment|/// arguments for a function template, the notion is convenient when
end_comment

begin_comment
comment|/// we need to perform substitutions inside the definition of a function
end_comment

begin_comment
comment|/// template.
end_comment

begin_expr_stmt
name|ArrayRef
operator|<
name|TemplateArgument
operator|>
name|getInjectedTemplateArgs
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Create a function template node.
end_comment

begin_function_decl
specifier|static
name|FunctionTemplateDecl
modifier|*
name|Create
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|,
name|DeclContext
modifier|*
name|DC
parameter_list|,
name|SourceLocation
name|L
parameter_list|,
name|DeclarationName
name|Name
parameter_list|,
name|TemplateParameterList
modifier|*
name|Params
parameter_list|,
name|NamedDecl
modifier|*
name|Decl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Create an empty function template node.
end_comment

begin_function_decl
specifier|static
name|FunctionTemplateDecl
modifier|*
name|CreateDeserialized
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|,
name|unsigned
name|ID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Implement isa/cast/dyncast support
end_comment

begin_function
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
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
name|K
operator|==
name|FunctionTemplate
return|;
block|}
end_function

begin_decl_stmt
name|friend
name|class
name|ASTDeclReader
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|ASTDeclWriter
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Kinds of Template Parameters
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// \brief Defines the position of a template parameter within a template
end_comment

begin_comment
comment|/// parameter list.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Because template parameter can be listed
end_comment

begin_comment
comment|/// sequentially for out-of-line template members, each template parameter is
end_comment

begin_comment
comment|/// given a Depth - the nesting of template parameter scopes - and a Position -
end_comment

begin_comment
comment|/// the occurrence within the parameter list.
end_comment

begin_comment
comment|/// This class is inheritedly privately by different kinds of template
end_comment

begin_comment
comment|/// parameters and is not part of the Decl hierarchy. Just a facility.
end_comment

begin_decl_stmt
name|class
name|TemplateParmPosition
block|{
name|TemplateParmPosition
argument_list|()
operator|=
name|delete
expr_stmt|;
name|protected
label|:
name|TemplateParmPosition
argument_list|(
argument|unsigned D
argument_list|,
argument|unsigned P
argument_list|)
block|:
name|Depth
argument_list|(
name|D
argument_list|)
operator|,
name|Position
argument_list|(
argument|P
argument_list|)
block|{ }
comment|// FIXME: These probably don't need to be ints. int:5 for depth, int:8 for
comment|// position? Maybe?
name|unsigned
name|Depth
expr_stmt|;
name|unsigned
name|Position
decl_stmt|;
name|public
label|:
comment|/// Get the nesting depth of the template parameter.
name|unsigned
name|getDepth
argument_list|()
specifier|const
block|{
return|return
name|Depth
return|;
block|}
name|void
name|setDepth
parameter_list|(
name|unsigned
name|D
parameter_list|)
block|{
name|Depth
operator|=
name|D
expr_stmt|;
block|}
comment|/// Get the position of the template parameter within its parameter list.
name|unsigned
name|getPosition
argument_list|()
specifier|const
block|{
return|return
name|Position
return|;
block|}
name|void
name|setPosition
parameter_list|(
name|unsigned
name|P
parameter_list|)
block|{
name|Position
operator|=
name|P
expr_stmt|;
block|}
comment|/// Get the index of the template parameter within its parameter list.
name|unsigned
name|getIndex
argument_list|()
specifier|const
block|{
return|return
name|Position
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Declaration of a template type parameter.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For example, "T" in
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// template<typename T> class vector;
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_decl_stmt
name|class
name|TemplateTypeParmDecl
range|:
name|public
name|TypeDecl
block|{
comment|/// \brief Whether this template type parameter was declaration with
comment|/// the 'typename' keyword.
comment|///
comment|/// If false, it was declared with the 'class' keyword.
name|bool
name|Typename
operator|:
literal|1
block|;
comment|/// \brief The default template argument, if any.
typedef|typedef
name|DefaultArgStorage
operator|<
name|TemplateTypeParmDecl
operator|,
name|TypeSourceInfo
operator|*
operator|>
name|DefArgStorage
expr_stmt|;
name|DefArgStorage
name|DefaultArgument
decl_stmt|;
end_decl_stmt

begin_macro
name|TemplateTypeParmDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation KeyLoc
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|bool Typename
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|TypeDecl
argument_list|(
name|TemplateTypeParm
argument_list|,
name|DC
argument_list|,
name|IdLoc
argument_list|,
name|Id
argument_list|,
name|KeyLoc
argument_list|)
operator|,
name|Typename
argument_list|(
name|Typename
argument_list|)
operator|,
name|DefaultArgument
argument_list|()
block|{ }
comment|/// Sema creates these on the stack during auto type deduction.
name|friend
name|class
name|Sema
expr_stmt|;
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_function_decl
specifier|static
name|TemplateTypeParmDecl
modifier|*
name|Create
parameter_list|(
specifier|const
name|ASTContext
modifier|&
name|C
parameter_list|,
name|DeclContext
modifier|*
name|DC
parameter_list|,
name|SourceLocation
name|KeyLoc
parameter_list|,
name|SourceLocation
name|NameLoc
parameter_list|,
name|unsigned
name|D
parameter_list|,
name|unsigned
name|P
parameter_list|,
name|IdentifierInfo
modifier|*
name|Id
parameter_list|,
name|bool
name|Typename
parameter_list|,
name|bool
name|ParameterPack
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|TemplateTypeParmDecl
modifier|*
name|CreateDeserialized
parameter_list|(
specifier|const
name|ASTContext
modifier|&
name|C
parameter_list|,
name|unsigned
name|ID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Whether this template type parameter was declared with
end_comment

begin_comment
comment|/// the 'typename' keyword.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If not, it was declared with the 'class' keyword.
end_comment

begin_expr_stmt
name|bool
name|wasDeclaredWithTypename
argument_list|()
specifier|const
block|{
return|return
name|Typename
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|DefArgStorage
operator|&
name|getDefaultArgStorage
argument_list|()
specifier|const
block|{
return|return
name|DefaultArgument
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this template parameter has a default
end_comment

begin_comment
comment|/// argument.
end_comment

begin_expr_stmt
name|bool
name|hasDefaultArgument
argument_list|()
specifier|const
block|{
return|return
name|DefaultArgument
operator|.
name|isSet
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the default argument, if any.
end_comment

begin_expr_stmt
name|QualType
name|getDefaultArgument
argument_list|()
specifier|const
block|{
return|return
name|DefaultArgument
operator|.
name|get
argument_list|()
operator|->
name|getType
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieves the default argument's source information, if any.
end_comment

begin_expr_stmt
name|TypeSourceInfo
operator|*
name|getDefaultArgumentInfo
argument_list|()
specifier|const
block|{
return|return
name|DefaultArgument
operator|.
name|get
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieves the location of the default argument declaration.
end_comment

begin_expr_stmt
name|SourceLocation
name|getDefaultArgumentLoc
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Determines whether the default argument was inherited
end_comment

begin_comment
comment|/// from a previous declaration of this template.
end_comment

begin_expr_stmt
name|bool
name|defaultArgumentWasInherited
argument_list|()
specifier|const
block|{
return|return
name|DefaultArgument
operator|.
name|isInherited
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Set the default argument for this template parameter.
end_comment

begin_function
name|void
name|setDefaultArgument
parameter_list|(
name|TypeSourceInfo
modifier|*
name|DefArg
parameter_list|)
block|{
name|DefaultArgument
operator|.
name|set
argument_list|(
name|DefArg
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Set that this default argument was inherited from another
end_comment

begin_comment
comment|/// parameter.
end_comment

begin_function
name|void
name|setInheritedDefaultArgument
parameter_list|(
specifier|const
name|ASTContext
modifier|&
name|C
parameter_list|,
name|TemplateTypeParmDecl
modifier|*
name|Prev
parameter_list|)
block|{
name|DefaultArgument
operator|.
name|setInherited
argument_list|(
name|C
argument_list|,
name|Prev
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Removes the default argument of this template parameter.
end_comment

begin_function
name|void
name|removeDefaultArgument
parameter_list|()
block|{
name|DefaultArgument
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Set whether this template type parameter was declared with
end_comment

begin_comment
comment|/// the 'typename' or 'class' keyword.
end_comment

begin_function
name|void
name|setDeclaredWithTypename
parameter_list|(
name|bool
name|withTypename
parameter_list|)
block|{
name|Typename
operator|=
name|withTypename
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Retrieve the depth of the template parameter.
end_comment

begin_expr_stmt
name|unsigned
name|getDepth
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the index of the template parameter.
end_comment

begin_expr_stmt
name|unsigned
name|getIndex
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Returns whether this is a parameter pack.
end_comment

begin_expr_stmt
name|bool
name|isParameterPack
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|override
name|LLVM_READONLY
expr_stmt|;
end_expr_stmt

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
name|D
parameter_list|)
block|{
return|return
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
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
name|K
operator|==
name|TemplateTypeParm
return|;
block|}
end_function

begin_comment
unit|};
comment|/// NonTypeTemplateParmDecl - Declares a non-type template parameter,
end_comment

begin_comment
comment|/// e.g., "Size" in
end_comment

begin_comment
comment|/// @code
end_comment

begin_comment
comment|/// template<int Size> class array { };
end_comment

begin_comment
comment|/// @endcode
end_comment

begin_decl_stmt
name|class
name|NonTypeTemplateParmDecl
name|final
range|:
name|public
name|DeclaratorDecl
decl_stmt|,
name|protected
name|TemplateParmPosition
decl_stmt|,
name|private
name|llvm
decl|::
name|TrailingObjects
decl|<
name|NonTypeTemplateParmDecl
decl_stmt|,
name|std
decl|::
name|pair
decl|<
name|QualType
decl_stmt|,
name|TypeSourceInfo
modifier|*
decl|>>
block|{
comment|/// \brief The default template argument, if any, and whether or not
comment|/// it was inherited.
typedef|typedef
name|DefaultArgStorage
operator|<
name|NonTypeTemplateParmDecl
operator|,
name|Expr
operator|*
operator|>
name|DefArgStorage
expr_stmt|;
name|DefArgStorage
name|DefaultArgument
decl_stmt|;
comment|// FIXME: Collapse this into TemplateParamPosition; or, just move depth/index
comment|// down here to save memory.
comment|/// \brief Whether this non-type template parameter is a parameter pack.
name|bool
name|ParameterPack
decl_stmt|;
comment|/// \brief Whether this non-type template parameter is an "expanded"
comment|/// parameter pack, meaning that its type is a pack expansion and we
comment|/// already know the set of types that expansion expands to.
name|bool
name|ExpandedParameterPack
decl_stmt|;
comment|/// \brief The number of types in an expanded parameter pack.
name|unsigned
name|NumExpandedTypes
decl_stmt|;
name|size_t
name|numTrailingObjects
argument_list|(
name|OverloadToken
operator|<
name|std
operator|::
name|pair
operator|<
name|QualType
argument_list|,
name|TypeSourceInfo
operator|*
operator|>>
argument_list|)
decl|const
block|{
return|return
name|NumExpandedTypes
return|;
block|}
name|NonTypeTemplateParmDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|unsigned D
argument_list|,
argument|unsigned P
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|,
argument|bool ParameterPack
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|)
block|:
name|DeclaratorDecl
argument_list|(
name|NonTypeTemplateParm
argument_list|,
name|DC
argument_list|,
name|IdLoc
argument_list|,
name|Id
argument_list|,
name|T
argument_list|,
name|TInfo
argument_list|,
name|StartLoc
argument_list|)
operator|,
name|TemplateParmPosition
argument_list|(
name|D
argument_list|,
name|P
argument_list|)
operator|,
name|ParameterPack
argument_list|(
name|ParameterPack
argument_list|)
operator|,
name|ExpandedParameterPack
argument_list|(
name|false
argument_list|)
operator|,
name|NumExpandedTypes
argument_list|(
literal|0
argument_list|)
block|{ }
name|NonTypeTemplateParmDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|unsigned D
argument_list|,
argument|unsigned P
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|,
argument|ArrayRef<QualType> ExpandedTypes
argument_list|,
argument|ArrayRef<TypeSourceInfo *> ExpandedTInfos
argument_list|)
expr_stmt|;
name|friend
name|class
name|ASTDeclReader
decl_stmt|;
name|friend
name|TrailingObjects
decl_stmt|;
name|public
label|:
specifier|static
name|NonTypeTemplateParmDecl
modifier|*
name|Create
parameter_list|(
specifier|const
name|ASTContext
modifier|&
name|C
parameter_list|,
name|DeclContext
modifier|*
name|DC
parameter_list|,
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|IdLoc
parameter_list|,
name|unsigned
name|D
parameter_list|,
name|unsigned
name|P
parameter_list|,
name|IdentifierInfo
modifier|*
name|Id
parameter_list|,
name|QualType
name|T
parameter_list|,
name|bool
name|ParameterPack
parameter_list|,
name|TypeSourceInfo
modifier|*
name|TInfo
parameter_list|)
function_decl|;
specifier|static
name|NonTypeTemplateParmDecl
modifier|*
name|Create
argument_list|(
specifier|const
name|ASTContext
operator|&
name|C
argument_list|,
name|DeclContext
operator|*
name|DC
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|IdLoc
argument_list|,
name|unsigned
name|D
argument_list|,
name|unsigned
name|P
argument_list|,
name|IdentifierInfo
operator|*
name|Id
argument_list|,
name|QualType
name|T
argument_list|,
name|TypeSourceInfo
operator|*
name|TInfo
argument_list|,
name|ArrayRef
operator|<
name|QualType
operator|>
name|ExpandedTypes
argument_list|,
name|ArrayRef
operator|<
name|TypeSourceInfo
operator|*
operator|>
name|ExpandedTInfos
argument_list|)
decl_stmt|;
specifier|static
name|NonTypeTemplateParmDecl
modifier|*
name|CreateDeserialized
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|,
name|unsigned
name|ID
parameter_list|)
function_decl|;
specifier|static
name|NonTypeTemplateParmDecl
modifier|*
name|CreateDeserialized
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|,
name|unsigned
name|ID
parameter_list|,
name|unsigned
name|NumExpandedTypes
parameter_list|)
function_decl|;
name|using
name|TemplateParmPosition
operator|::
name|getDepth
expr_stmt|;
name|using
name|TemplateParmPosition
operator|::
name|setDepth
expr_stmt|;
name|using
name|TemplateParmPosition
operator|::
name|getPosition
expr_stmt|;
name|using
name|TemplateParmPosition
operator|::
name|setPosition
expr_stmt|;
name|using
name|TemplateParmPosition
operator|::
name|getIndex
expr_stmt|;
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|override
name|LLVM_READONLY
expr_stmt|;
specifier|const
name|DefArgStorage
operator|&
name|getDefaultArgStorage
argument_list|()
specifier|const
block|{
return|return
name|DefaultArgument
return|;
block|}
comment|/// \brief Determine whether this template parameter has a default
comment|/// argument.
name|bool
name|hasDefaultArgument
argument_list|()
specifier|const
block|{
return|return
name|DefaultArgument
operator|.
name|isSet
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the default argument, if any.
name|Expr
operator|*
name|getDefaultArgument
argument_list|()
specifier|const
block|{
return|return
name|DefaultArgument
operator|.
name|get
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the location of the default argument, if any.
name|SourceLocation
name|getDefaultArgumentLoc
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determines whether the default argument was inherited
comment|/// from a previous declaration of this template.
name|bool
name|defaultArgumentWasInherited
argument_list|()
specifier|const
block|{
return|return
name|DefaultArgument
operator|.
name|isInherited
argument_list|()
return|;
block|}
comment|/// \brief Set the default argument for this template parameter, and
comment|/// whether that default argument was inherited from another
comment|/// declaration.
name|void
name|setDefaultArgument
parameter_list|(
name|Expr
modifier|*
name|DefArg
parameter_list|)
block|{
name|DefaultArgument
operator|.
name|set
argument_list|(
name|DefArg
argument_list|)
expr_stmt|;
block|}
name|void
name|setInheritedDefaultArgument
parameter_list|(
specifier|const
name|ASTContext
modifier|&
name|C
parameter_list|,
name|NonTypeTemplateParmDecl
modifier|*
name|Parm
parameter_list|)
block|{
name|DefaultArgument
operator|.
name|setInherited
argument_list|(
name|C
argument_list|,
name|Parm
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Removes the default argument of this template parameter.
name|void
name|removeDefaultArgument
parameter_list|()
block|{
name|DefaultArgument
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
comment|/// \brief Whether this parameter is a non-type template parameter pack.
comment|///
comment|/// If the parameter is a parameter pack, the type may be a
comment|/// \c PackExpansionType. In the following example, the \c Dims parameter
comment|/// is a parameter pack (whose type is 'unsigned').
comment|///
comment|/// \code
comment|/// template<typename T, unsigned ...Dims> struct multi_array;
comment|/// \endcode
name|bool
name|isParameterPack
argument_list|()
specifier|const
block|{
return|return
name|ParameterPack
return|;
block|}
comment|/// \brief Whether this parameter pack is a pack expansion.
comment|///
comment|/// A non-type template parameter pack is a pack expansion if its type
comment|/// contains an unexpanded parameter pack. In this case, we will have
comment|/// built a PackExpansionType wrapping the type.
name|bool
name|isPackExpansion
argument_list|()
specifier|const
block|{
return|return
name|ParameterPack
operator|&&
name|getType
argument_list|()
operator|->
name|getAs
operator|<
name|PackExpansionType
operator|>
operator|(
operator|)
return|;
block|}
comment|/// \brief Whether this parameter is a non-type template parameter pack
comment|/// that has a known list of different types at different positions.
comment|///
comment|/// A parameter pack is an expanded parameter pack when the original
comment|/// parameter pack's type was itself a pack expansion, and that expansion
comment|/// has already been expanded. For example, given:
comment|///
comment|/// \code
comment|/// template<typename ...Types>
comment|/// struct X {
comment|///   template<Types ...Values>
comment|///   struct Y { /* ... */ };
comment|/// };
comment|/// \endcode
comment|///
comment|/// The parameter pack \c Values has a \c PackExpansionType as its type,
comment|/// which expands \c Types. When \c Types is supplied with template arguments
comment|/// by instantiating \c X, the instantiation of \c Values becomes an
comment|/// expanded parameter pack. For example, instantiating
comment|/// \c X<int, unsigned int> results in \c Values being an expanded parameter
comment|/// pack with expansion types \c int and \c unsigned int.
comment|///
comment|/// The \c getExpansionType() and \c getExpansionTypeSourceInfo() functions
comment|/// return the expansion types.
name|bool
name|isExpandedParameterPack
argument_list|()
specifier|const
block|{
return|return
name|ExpandedParameterPack
return|;
block|}
comment|/// \brief Retrieves the number of expansion types in an expanded parameter
comment|/// pack.
name|unsigned
name|getNumExpansionTypes
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|ExpandedParameterPack
operator|&&
literal|"Not an expansion parameter pack"
argument_list|)
block|;
return|return
name|NumExpandedTypes
return|;
block|}
comment|/// \brief Retrieve a particular expansion type within an expanded parameter
comment|/// pack.
name|QualType
name|getExpansionType
argument_list|(
name|unsigned
name|I
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|I
operator|<
name|NumExpandedTypes
operator|&&
literal|"Out-of-range expansion type index"
argument_list|)
expr_stmt|;
name|auto
name|TypesAndInfos
init|=
name|getTrailingObjects
operator|<
name|std
operator|::
name|pair
operator|<
name|QualType
decl_stmt|,
name|TypeSourceInfo
modifier|*
decl|>>
argument_list|()
decl_stmt|;
return|return
name|TypesAndInfos
index|[
name|I
index|]
operator|.
name|first
return|;
block|}
comment|/// \brief Retrieve a particular expansion type source info within an
comment|/// expanded parameter pack.
name|TypeSourceInfo
modifier|*
name|getExpansionTypeSourceInfo
argument_list|(
name|unsigned
name|I
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|I
operator|<
name|NumExpandedTypes
operator|&&
literal|"Out-of-range expansion type index"
argument_list|)
expr_stmt|;
name|auto
name|TypesAndInfos
init|=
name|getTrailingObjects
operator|<
name|std
operator|::
name|pair
operator|<
name|QualType
decl_stmt|,
name|TypeSourceInfo
modifier|*
decl|>>
argument_list|()
decl_stmt|;
return|return
name|TypesAndInfos
index|[
name|I
index|]
operator|.
name|second
return|;
block|}
comment|// Implement isa/cast/dyncast/etc.
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classofKind
parameter_list|(
name|Kind
name|K
parameter_list|)
block|{
return|return
name|K
operator|==
name|NonTypeTemplateParm
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// TemplateTemplateParmDecl - Declares a template template parameter,
end_comment

begin_comment
comment|/// e.g., "T" in
end_comment

begin_comment
comment|/// @code
end_comment

begin_comment
comment|/// template<template<typename> class T> class container { };
end_comment

begin_comment
comment|/// @endcode
end_comment

begin_comment
comment|/// A template template parameter is a TemplateDecl because it defines the
end_comment

begin_comment
comment|/// name of a template and the template parameters allowable for substitution.
end_comment

begin_decl_stmt
name|class
name|TemplateTemplateParmDecl
name|final
range|:
name|public
name|TemplateDecl
decl_stmt|,
name|protected
name|TemplateParmPosition
decl_stmt|,
name|private
name|llvm
decl|::
name|TrailingObjects
decl|<
name|TemplateTemplateParmDecl
decl_stmt|,
name|TemplateParameterList
modifier|*
decl|>
block|{
name|void
name|anchor
argument_list|()
name|override
expr_stmt|;
comment|/// \brief The default template argument, if any.
typedef|typedef
name|DefaultArgStorage
operator|<
name|TemplateTemplateParmDecl
operator|,
name|TemplateArgumentLoc
operator|*
operator|>
name|DefArgStorage
expr_stmt|;
name|DefArgStorage
name|DefaultArgument
decl_stmt|;
comment|/// \brief Whether this parameter is a parameter pack.
name|bool
name|ParameterPack
decl_stmt|;
comment|/// \brief Whether this template template parameter is an "expanded"
comment|/// parameter pack, meaning that it is a pack expansion and we
comment|/// already know the set of template parameters that expansion expands to.
name|bool
name|ExpandedParameterPack
decl_stmt|;
comment|/// \brief The number of parameters in an expanded parameter pack.
name|unsigned
name|NumExpandedParams
decl_stmt|;
name|TemplateTemplateParmDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|unsigned D
argument_list|,
argument|unsigned P
argument_list|,
argument|bool ParameterPack
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|TemplateParameterList *Params
argument_list|)
block|:
name|TemplateDecl
argument_list|(
name|TemplateTemplateParm
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|Id
argument_list|,
name|Params
argument_list|)
operator|,
name|TemplateParmPosition
argument_list|(
name|D
argument_list|,
name|P
argument_list|)
operator|,
name|ParameterPack
argument_list|(
name|ParameterPack
argument_list|)
operator|,
name|ExpandedParameterPack
argument_list|(
name|false
argument_list|)
operator|,
name|NumExpandedParams
argument_list|(
literal|0
argument_list|)
block|{ }
name|TemplateTemplateParmDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|unsigned D
argument_list|,
argument|unsigned P
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|TemplateParameterList *Params
argument_list|,
argument|ArrayRef<TemplateParameterList *> Expansions
argument_list|)
expr_stmt|;
name|public
label|:
specifier|static
name|TemplateTemplateParmDecl
modifier|*
name|Create
parameter_list|(
specifier|const
name|ASTContext
modifier|&
name|C
parameter_list|,
name|DeclContext
modifier|*
name|DC
parameter_list|,
name|SourceLocation
name|L
parameter_list|,
name|unsigned
name|D
parameter_list|,
name|unsigned
name|P
parameter_list|,
name|bool
name|ParameterPack
parameter_list|,
name|IdentifierInfo
modifier|*
name|Id
parameter_list|,
name|TemplateParameterList
modifier|*
name|Params
parameter_list|)
function_decl|;
specifier|static
name|TemplateTemplateParmDecl
modifier|*
name|Create
argument_list|(
specifier|const
name|ASTContext
operator|&
name|C
argument_list|,
name|DeclContext
operator|*
name|DC
argument_list|,
name|SourceLocation
name|L
argument_list|,
name|unsigned
name|D
argument_list|,
name|unsigned
name|P
argument_list|,
name|IdentifierInfo
operator|*
name|Id
argument_list|,
name|TemplateParameterList
operator|*
name|Params
argument_list|,
name|ArrayRef
operator|<
name|TemplateParameterList
operator|*
operator|>
name|Expansions
argument_list|)
decl_stmt|;
specifier|static
name|TemplateTemplateParmDecl
modifier|*
name|CreateDeserialized
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|,
name|unsigned
name|ID
parameter_list|)
function_decl|;
specifier|static
name|TemplateTemplateParmDecl
modifier|*
name|CreateDeserialized
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|,
name|unsigned
name|ID
parameter_list|,
name|unsigned
name|NumExpansions
parameter_list|)
function_decl|;
name|using
name|TemplateParmPosition
operator|::
name|getDepth
expr_stmt|;
name|using
name|TemplateParmPosition
operator|::
name|setDepth
expr_stmt|;
name|using
name|TemplateParmPosition
operator|::
name|getPosition
expr_stmt|;
name|using
name|TemplateParmPosition
operator|::
name|setPosition
expr_stmt|;
name|using
name|TemplateParmPosition
operator|::
name|getIndex
expr_stmt|;
comment|/// \brief Whether this template template parameter is a template
comment|/// parameter pack.
comment|///
comment|/// \code
comment|/// template<template<class T> ...MetaFunctions> struct Apply;
comment|/// \endcode
name|bool
name|isParameterPack
argument_list|()
specifier|const
block|{
return|return
name|ParameterPack
return|;
block|}
comment|/// \brief Whether this parameter pack is a pack expansion.
comment|///
comment|/// A template template parameter pack is a pack expansion if its template
comment|/// parameter list contains an unexpanded parameter pack.
name|bool
name|isPackExpansion
argument_list|()
specifier|const
block|{
return|return
name|ParameterPack
operator|&&
name|getTemplateParameters
argument_list|()
operator|->
name|containsUnexpandedParameterPack
argument_list|()
return|;
block|}
comment|/// \brief Whether this parameter is a template template parameter pack that
comment|/// has a known list of different template parameter lists at different
comment|/// positions.
comment|///
comment|/// A parameter pack is an expanded parameter pack when the original parameter
comment|/// pack's template parameter list was itself a pack expansion, and that
comment|/// expansion has already been expanded. For exampe, given:
comment|///
comment|/// \code
comment|/// template<typename...Types> struct Outer {
comment|///   template<template<Types> class...Templates> struct Inner;
comment|/// };
comment|/// \endcode
comment|///
comment|/// The parameter pack \c Templates is a pack expansion, which expands the
comment|/// pack \c Types. When \c Types is supplied with template arguments by
comment|/// instantiating \c Outer, the instantiation of \c Templates is an expanded
comment|/// parameter pack.
name|bool
name|isExpandedParameterPack
argument_list|()
specifier|const
block|{
return|return
name|ExpandedParameterPack
return|;
block|}
comment|/// \brief Retrieves the number of expansion template parameters in
comment|/// an expanded parameter pack.
name|unsigned
name|getNumExpansionTemplateParameters
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|ExpandedParameterPack
operator|&&
literal|"Not an expansion parameter pack"
argument_list|)
block|;
return|return
name|NumExpandedParams
return|;
block|}
comment|/// \brief Retrieve a particular expansion type within an expanded parameter
comment|/// pack.
name|TemplateParameterList
modifier|*
name|getExpansionTemplateParameters
argument_list|(
name|unsigned
name|I
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|I
operator|<
name|NumExpandedParams
operator|&&
literal|"Out-of-range expansion type index"
argument_list|)
expr_stmt|;
return|return
name|getTrailingObjects
operator|<
name|TemplateParameterList
operator|*
operator|>
operator|(
operator|)
index|[
name|I
index|]
return|;
block|}
specifier|const
name|DefArgStorage
operator|&
name|getDefaultArgStorage
argument_list|()
specifier|const
block|{
return|return
name|DefaultArgument
return|;
block|}
comment|/// \brief Determine whether this template parameter has a default
comment|/// argument.
name|bool
name|hasDefaultArgument
argument_list|()
specifier|const
block|{
return|return
name|DefaultArgument
operator|.
name|isSet
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the default argument, if any.
specifier|const
name|TemplateArgumentLoc
operator|&
name|getDefaultArgument
argument_list|()
specifier|const
block|{
specifier|static
specifier|const
name|TemplateArgumentLoc
name|None
block|;
return|return
name|DefaultArgument
operator|.
name|isSet
argument_list|()
condition|?
operator|*
name|DefaultArgument
operator|.
name|get
argument_list|()
else|:
name|None
return|;
block|}
comment|/// \brief Retrieve the location of the default argument, if any.
name|SourceLocation
name|getDefaultArgumentLoc
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determines whether the default argument was inherited
comment|/// from a previous declaration of this template.
name|bool
name|defaultArgumentWasInherited
argument_list|()
specifier|const
block|{
return|return
name|DefaultArgument
operator|.
name|isInherited
argument_list|()
return|;
block|}
comment|/// \brief Set the default argument for this template parameter, and
comment|/// whether that default argument was inherited from another
comment|/// declaration.
name|void
name|setDefaultArgument
parameter_list|(
specifier|const
name|ASTContext
modifier|&
name|C
parameter_list|,
specifier|const
name|TemplateArgumentLoc
modifier|&
name|DefArg
parameter_list|)
function_decl|;
name|void
name|setInheritedDefaultArgument
parameter_list|(
specifier|const
name|ASTContext
modifier|&
name|C
parameter_list|,
name|TemplateTemplateParmDecl
modifier|*
name|Prev
parameter_list|)
block|{
name|DefaultArgument
operator|.
name|setInherited
argument_list|(
name|C
argument_list|,
name|Prev
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Removes the default argument of this template parameter.
name|void
name|removeDefaultArgument
parameter_list|()
block|{
name|DefaultArgument
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|override
name|LLVM_READONLY
block|{
name|SourceLocation
name|End
operator|=
name|getLocation
argument_list|()
block|;
if|if
condition|(
name|hasDefaultArgument
argument_list|()
operator|&&
operator|!
name|defaultArgumentWasInherited
argument_list|()
condition|)
name|End
operator|=
name|getDefaultArgument
argument_list|()
operator|.
name|getSourceRange
argument_list|()
operator|.
name|getEnd
argument_list|()
expr_stmt|;
return|return
name|SourceRange
argument_list|(
name|getTemplateParameters
argument_list|()
operator|->
name|getTemplateLoc
argument_list|()
argument_list|,
name|End
argument_list|)
return|;
block|}
end_decl_stmt

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
name|D
parameter_list|)
block|{
return|return
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
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
name|K
operator|==
name|TemplateTemplateParm
return|;
block|}
end_function

begin_decl_stmt
name|friend
name|class
name|ASTDeclReader
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|ASTDeclWriter
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|TrailingObjects
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// \brief Represents the builtin template declaration which is used to
end_comment

begin_comment
comment|/// implement __make_integer_seq and other builtin templates.  It serves
end_comment

begin_comment
comment|/// no real purpose beyond existing as a place to hold template parameters.
end_comment

begin_decl_stmt
name|class
name|BuiltinTemplateDecl
range|:
name|public
name|TemplateDecl
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
name|BuiltinTemplateDecl
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|DeclarationName Name
argument_list|,
argument|BuiltinTemplateKind BTK
argument_list|)
block|;
name|BuiltinTemplateKind
name|BTK
block|;
name|public
operator|:
comment|// Implement isa/cast/dyncast support
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classofKind
argument_list|(
argument|Kind K
argument_list|)
block|{
return|return
name|K
operator|==
name|BuiltinTemplate
return|;
block|}
specifier|static
name|BuiltinTemplateDecl
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|DeclarationName Name
argument_list|,
argument|BuiltinTemplateKind BTK
argument_list|)
block|{
return|return
name|new
argument_list|(
argument|C
argument_list|,
argument|DC
argument_list|)
name|BuiltinTemplateDecl
argument_list|(
name|C
argument_list|,
name|DC
argument_list|,
name|Name
argument_list|,
name|BTK
argument_list|)
return|;
block|}
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|override
name|LLVM_READONLY
block|{
return|return
name|SourceRange
argument_list|()
return|;
block|}
name|BuiltinTemplateKind
name|getBuiltinTemplateKind
argument_list|()
specifier|const
block|{
return|return
name|BTK
return|;
block|}
expr|}
block|;
comment|/// \brief Represents a class template specialization, which refers to
comment|/// a class template with a given set of template arguments.
comment|///
comment|/// Class template specializations represent both explicit
comment|/// specialization of class templates, as in the example below, and
comment|/// implicit instantiations of class templates.
comment|///
comment|/// \code
comment|/// template<typename T> class array;
comment|///
comment|/// template<>
comment|/// class array<bool> { }; // class template specialization array<bool>
comment|/// \endcode
name|class
name|ClassTemplateSpecializationDecl
operator|:
name|public
name|CXXRecordDecl
block|,
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
comment|/// \brief Structure that stores information about a class template
comment|/// specialization that was instantiated from a class template partial
comment|/// specialization.
block|struct
name|SpecializedPartialSpecialization
block|{
comment|/// \brief The class template partial specialization from which this
comment|/// class template specialization was instantiated.
name|ClassTemplatePartialSpecializationDecl
operator|*
name|PartialSpecialization
block|;
comment|/// \brief The template argument list deduced for the class template
comment|/// partial specialization itself.
specifier|const
name|TemplateArgumentList
operator|*
name|TemplateArgs
block|;   }
block|;
comment|/// \brief The template that this specialization specializes
name|llvm
operator|::
name|PointerUnion
operator|<
name|ClassTemplateDecl
operator|*
block|,
name|SpecializedPartialSpecialization
operator|*
operator|>
name|SpecializedTemplate
block|;
comment|/// \brief Further info for explicit template specialization/instantiation.
block|struct
name|ExplicitSpecializationInfo
block|{
comment|/// \brief The type-as-written.
name|TypeSourceInfo
operator|*
name|TypeAsWritten
block|;
comment|/// \brief The location of the extern keyword.
name|SourceLocation
name|ExternLoc
block|;
comment|/// \brief The location of the template keyword.
name|SourceLocation
name|TemplateKeywordLoc
block|;
name|ExplicitSpecializationInfo
argument_list|()
operator|:
name|TypeAsWritten
argument_list|(
name|nullptr
argument_list|)
block|,
name|ExternLoc
argument_list|()
block|,
name|TemplateKeywordLoc
argument_list|()
block|{}
block|}
block|;
comment|/// \brief Further info for explicit template specialization/instantiation.
comment|/// Does not apply to implicit specializations.
name|ExplicitSpecializationInfo
operator|*
name|ExplicitInfo
block|;
comment|/// \brief The template arguments used to describe this specialization.
specifier|const
name|TemplateArgumentList
operator|*
name|TemplateArgs
block|;
comment|/// \brief The point where this template was instantiated (if any)
name|SourceLocation
name|PointOfInstantiation
block|;
comment|/// \brief The kind of specialization this declaration refers to.
comment|/// Really a value of type TemplateSpecializationKind.
name|unsigned
name|SpecializationKind
operator|:
literal|3
block|;
name|protected
operator|:
name|ClassTemplateSpecializationDecl
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|Kind DK
argument_list|,
argument|TagKind TK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|ClassTemplateDecl *SpecializedTemplate
argument_list|,
argument|ArrayRef<TemplateArgument> Args
argument_list|,
argument|ClassTemplateSpecializationDecl *PrevDecl
argument_list|)
block|;
name|explicit
name|ClassTemplateSpecializationDecl
argument_list|(
argument|ASTContext&C
argument_list|,
argument|Kind DK
argument_list|)
block|;
name|public
operator|:
specifier|static
name|ClassTemplateSpecializationDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|TagKind TK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|ClassTemplateDecl *SpecializedTemplate
argument_list|,
argument|ArrayRef<TemplateArgument> Args
argument_list|,
argument|ClassTemplateSpecializationDecl *PrevDecl
argument_list|)
block|;
specifier|static
name|ClassTemplateSpecializationDecl
operator|*
name|CreateDeserialized
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned ID
argument_list|)
block|;
name|void
name|getNameForDiagnostic
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|const PrintingPolicy&Policy
argument_list|,
argument|bool Qualified
argument_list|)
specifier|const
name|override
block|;
comment|// FIXME: This is broken. CXXRecordDecl::getMostRecentDecl() returns a
comment|// different "most recent" declaration from this function for the same
comment|// declaration, because we don't override getMostRecentDeclImpl(). But
comment|// it's not clear that we should override that, because the most recent
comment|// declaration as a CXXRecordDecl sometimes is the injected-class-name.
name|ClassTemplateSpecializationDecl
operator|*
name|getMostRecentDecl
argument_list|()
block|{
name|CXXRecordDecl
operator|*
name|Recent
operator|=
name|static_cast
operator|<
name|CXXRecordDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getMostRecentDecl
argument_list|()
block|;
while|while
condition|(
operator|!
name|isa
operator|<
name|ClassTemplateSpecializationDecl
operator|>
operator|(
name|Recent
operator|)
condition|)
block|{
comment|// FIXME: Does injected class name need to be in the redeclarations chain?
name|assert
argument_list|(
name|Recent
operator|->
name|isInjectedClassName
argument_list|()
operator|&&
name|Recent
operator|->
name|getPreviousDecl
argument_list|()
argument_list|)
expr_stmt|;
name|Recent
operator|=
name|Recent
operator|->
name|getPreviousDecl
argument_list|()
expr_stmt|;
block|}
return|return
name|cast
operator|<
name|ClassTemplateSpecializationDecl
operator|>
operator|(
name|Recent
operator|)
return|;
block|}
comment|/// \brief Retrieve the template that this specialization specializes.
name|ClassTemplateDecl
operator|*
name|getSpecializedTemplate
argument_list|()
specifier|const
block|;
comment|/// \brief Retrieve the template arguments of the class template
comment|/// specialization.
specifier|const
name|TemplateArgumentList
operator|&
name|getTemplateArgs
argument_list|()
specifier|const
block|{
return|return
operator|*
name|TemplateArgs
return|;
block|}
comment|/// \brief Determine the kind of specialization that this
comment|/// declaration represents.
name|TemplateSpecializationKind
name|getSpecializationKind
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|TemplateSpecializationKind
operator|>
operator|(
name|SpecializationKind
operator|)
return|;
block|}
name|bool
name|isExplicitSpecialization
argument_list|()
specifier|const
block|{
return|return
name|getSpecializationKind
argument_list|()
operator|==
name|TSK_ExplicitSpecialization
return|;
block|}
comment|/// \brief True if this declaration is an explicit specialization,
comment|/// explicit instantiation declaration, or explicit instantiation
comment|/// definition.
name|bool
name|isExplicitInstantiationOrSpecialization
argument_list|()
specifier|const
block|{
return|return
name|isTemplateExplicitInstantiationOrSpecialization
argument_list|(
name|getTemplateSpecializationKind
argument_list|()
argument_list|)
return|;
block|}
name|void
name|setSpecializationKind
argument_list|(
argument|TemplateSpecializationKind TSK
argument_list|)
block|{
name|SpecializationKind
operator|=
name|TSK
block|;   }
comment|/// \brief Get the point of instantiation (if any), or null if none.
name|SourceLocation
name|getPointOfInstantiation
argument_list|()
specifier|const
block|{
return|return
name|PointOfInstantiation
return|;
block|}
name|void
name|setPointOfInstantiation
argument_list|(
argument|SourceLocation Loc
argument_list|)
block|{
name|assert
argument_list|(
name|Loc
operator|.
name|isValid
argument_list|()
operator|&&
literal|"point of instantiation must be valid!"
argument_list|)
block|;
name|PointOfInstantiation
operator|=
name|Loc
block|;   }
comment|/// \brief If this class template specialization is an instantiation of
comment|/// a template (rather than an explicit specialization), return the
comment|/// class template or class template partial specialization from which it
comment|/// was instantiated.
name|llvm
operator|::
name|PointerUnion
operator|<
name|ClassTemplateDecl
operator|*
block|,
name|ClassTemplatePartialSpecializationDecl
operator|*
operator|>
name|getInstantiatedFrom
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|isTemplateInstantiation
argument_list|(
name|getSpecializationKind
argument_list|()
argument_list|)
condition|)
return|return
name|llvm
operator|::
name|PointerUnion
operator|<
name|ClassTemplateDecl
operator|*
operator|,
name|ClassTemplatePartialSpecializationDecl
operator|*
operator|>
operator|(
operator|)
return|;
return|return
name|getSpecializedTemplateOrPartial
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the class template or class template partial
comment|/// specialization which was specialized by this.
name|llvm
operator|::
name|PointerUnion
operator|<
name|ClassTemplateDecl
operator|*
block|,
name|ClassTemplatePartialSpecializationDecl
operator|*
operator|>
name|getSpecializedTemplateOrPartial
argument_list|()
specifier|const
block|{
if|if
condition|(
name|SpecializedPartialSpecialization
modifier|*
name|PartialSpec
init|=
name|SpecializedTemplate
operator|.
name|dyn_cast
operator|<
name|SpecializedPartialSpecialization
operator|*
operator|>
operator|(
operator|)
condition|)
return|return
name|PartialSpec
operator|->
name|PartialSpecialization
return|;
return|return
name|SpecializedTemplate
operator|.
name|get
operator|<
name|ClassTemplateDecl
operator|*
operator|>
operator|(
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Retrieve the set of template arguments that should be used
end_comment

begin_comment
comment|/// to instantiate members of the class template or class template partial
end_comment

begin_comment
comment|/// specialization from which this class template specialization was
end_comment

begin_comment
comment|/// instantiated.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns For a class template specialization instantiated from the primary
end_comment

begin_comment
comment|/// template, this function will return the same template arguments as
end_comment

begin_comment
comment|/// getTemplateArgs(). For a class template specialization instantiated from
end_comment

begin_comment
comment|/// a class template partial specialization, this function will return the
end_comment

begin_comment
comment|/// deduced template arguments for the class template partial specialization
end_comment

begin_comment
comment|/// itself.
end_comment

begin_expr_stmt
specifier|const
name|TemplateArgumentList
operator|&
name|getTemplateInstantiationArgs
argument_list|()
specifier|const
block|{
if|if
condition|(
name|SpecializedPartialSpecialization
modifier|*
name|PartialSpec
init|=
name|SpecializedTemplate
operator|.
name|dyn_cast
operator|<
name|SpecializedPartialSpecialization
operator|*
operator|>
operator|(
operator|)
condition|)
return|return
operator|*
name|PartialSpec
operator|->
name|TemplateArgs
return|;
end_expr_stmt

begin_return
return|return
name|getTemplateArgs
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|/// \brief Note that this class template specialization is actually an
end_comment

begin_comment
comment|/// instantiation of the given class template partial specialization whose
end_comment

begin_comment
comment|/// template arguments have been deduced.
end_comment

begin_macro
unit|void
name|setInstantiationOf
argument_list|(
argument|ClassTemplatePartialSpecializationDecl *PartialSpec
argument_list|,
argument|const TemplateArgumentList *TemplateArgs
argument_list|)
end_macro

begin_block
block|{
name|assert
argument_list|(
operator|!
name|SpecializedTemplate
operator|.
name|is
operator|<
name|SpecializedPartialSpecialization
operator|*
operator|>
operator|(
operator|)
operator|&&
literal|"Already set to a class template partial specialization!"
argument_list|)
expr_stmt|;
name|SpecializedPartialSpecialization
modifier|*
name|PS
init|=
name|new
argument_list|(
argument|getASTContext()
argument_list|)
name|SpecializedPartialSpecialization
argument_list|()
decl_stmt|;
name|PS
operator|->
name|PartialSpecialization
operator|=
name|PartialSpec
expr_stmt|;
name|PS
operator|->
name|TemplateArgs
operator|=
name|TemplateArgs
expr_stmt|;
name|SpecializedTemplate
operator|=
name|PS
expr_stmt|;
block|}
end_block

begin_comment
comment|/// \brief Note that this class template specialization is an instantiation
end_comment

begin_comment
comment|/// of the given class template.
end_comment

begin_function
name|void
name|setInstantiationOf
parameter_list|(
name|ClassTemplateDecl
modifier|*
name|TemplDecl
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|SpecializedTemplate
operator|.
name|is
operator|<
name|SpecializedPartialSpecialization
operator|*
operator|>
operator|(
operator|)
operator|&&
literal|"Previously set to a class template partial specialization!"
argument_list|)
expr_stmt|;
name|SpecializedTemplate
operator|=
name|TemplDecl
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Sets the type of this specialization as it was written by
end_comment

begin_comment
comment|/// the user. This will be a class template specialization type.
end_comment

begin_function
name|void
name|setTypeAsWritten
parameter_list|(
name|TypeSourceInfo
modifier|*
name|T
parameter_list|)
block|{
if|if
condition|(
operator|!
name|ExplicitInfo
condition|)
name|ExplicitInfo
operator|=
name|new
argument_list|(
argument|getASTContext()
argument_list|)
name|ExplicitSpecializationInfo
expr_stmt|;
name|ExplicitInfo
operator|->
name|TypeAsWritten
operator|=
name|T
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Gets the type of this specialization as it was written by
end_comment

begin_comment
comment|/// the user, if it was so written.
end_comment

begin_expr_stmt
name|TypeSourceInfo
operator|*
name|getTypeAsWritten
argument_list|()
specifier|const
block|{
return|return
name|ExplicitInfo
operator|?
name|ExplicitInfo
operator|->
name|TypeAsWritten
operator|:
name|nullptr
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Gets the location of the extern keyword, if present.
end_comment

begin_expr_stmt
name|SourceLocation
name|getExternLoc
argument_list|()
specifier|const
block|{
return|return
name|ExplicitInfo
operator|?
name|ExplicitInfo
operator|->
name|ExternLoc
operator|:
name|SourceLocation
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Sets the location of the extern keyword.
end_comment

begin_function
name|void
name|setExternLoc
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
block|{
if|if
condition|(
operator|!
name|ExplicitInfo
condition|)
name|ExplicitInfo
operator|=
name|new
argument_list|(
argument|getASTContext()
argument_list|)
name|ExplicitSpecializationInfo
expr_stmt|;
name|ExplicitInfo
operator|->
name|ExternLoc
operator|=
name|Loc
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Sets the location of the template keyword.
end_comment

begin_function
name|void
name|setTemplateKeywordLoc
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
block|{
if|if
condition|(
operator|!
name|ExplicitInfo
condition|)
name|ExplicitInfo
operator|=
name|new
argument_list|(
argument|getASTContext()
argument_list|)
name|ExplicitSpecializationInfo
expr_stmt|;
name|ExplicitInfo
operator|->
name|TemplateKeywordLoc
operator|=
name|Loc
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Gets the location of the template keyword, if present.
end_comment

begin_expr_stmt
name|SourceLocation
name|getTemplateKeywordLoc
argument_list|()
specifier|const
block|{
return|return
name|ExplicitInfo
operator|?
name|ExplicitInfo
operator|->
name|TemplateKeywordLoc
operator|:
name|SourceLocation
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|override
name|LLVM_READONLY
expr_stmt|;
end_expr_stmt

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
name|Profile
argument_list|(
name|ID
argument_list|,
name|TemplateArgs
operator|->
name|asArray
argument_list|()
argument_list|,
name|getASTContext
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
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
name|ArrayRef
operator|<
name|TemplateArgument
operator|>
name|TemplateArgs
argument_list|,
name|ASTContext
operator|&
name|Context
argument_list|)
block|{
name|ID
operator|.
name|AddInteger
argument_list|(
name|TemplateArgs
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
for|for
control|(
specifier|const
name|TemplateArgument
modifier|&
name|TemplateArg
range|:
name|TemplateArgs
control|)
name|TemplateArg
operator|.
name|Profile
argument_list|(
name|ID
argument_list|,
name|Context
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_function
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
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
name|K
operator|>=
name|firstClassTemplateSpecialization
operator|&&
name|K
operator|<=
name|lastClassTemplateSpecialization
return|;
block|}
end_function

begin_decl_stmt
name|friend
name|class
name|ASTDeclReader
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|ASTDeclWriter
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|};
name|class
name|ClassTemplatePartialSpecializationDecl
range|:
name|public
name|ClassTemplateSpecializationDecl
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
comment|/// \brief The list of template parameters
name|TemplateParameterList
operator|*
name|TemplateParams
block|;
comment|/// \brief The source info for the template arguments as written.
comment|/// FIXME: redundant with TypeAsWritten?
specifier|const
name|ASTTemplateArgumentListInfo
operator|*
name|ArgsAsWritten
block|;
comment|/// \brief The class template partial specialization from which this
comment|/// class template partial specialization was instantiated.
comment|///
comment|/// The boolean value will be true to indicate that this class template
comment|/// partial specialization was specialized at this level.
name|llvm
operator|::
name|PointerIntPair
operator|<
name|ClassTemplatePartialSpecializationDecl
operator|*
block|,
literal|1
block|,
name|bool
operator|>
name|InstantiatedFromMember
block|;
name|ClassTemplatePartialSpecializationDecl
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|TagKind TK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|TemplateParameterList *Params
argument_list|,
argument|ClassTemplateDecl *SpecializedTemplate
argument_list|,
argument|ArrayRef<TemplateArgument> Args
argument_list|,
argument|const ASTTemplateArgumentListInfo *ArgsAsWritten
argument_list|,
argument|ClassTemplatePartialSpecializationDecl *PrevDecl
argument_list|)
block|;
name|ClassTemplatePartialSpecializationDecl
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|)
operator|:
name|ClassTemplateSpecializationDecl
argument_list|(
name|C
argument_list|,
name|ClassTemplatePartialSpecialization
argument_list|)
block|,
name|TemplateParams
argument_list|(
name|nullptr
argument_list|)
block|,
name|ArgsAsWritten
argument_list|(
name|nullptr
argument_list|)
block|,
name|InstantiatedFromMember
argument_list|(
argument|nullptr
argument_list|,
argument|false
argument_list|)
block|{}
name|public
operator|:
specifier|static
name|ClassTemplatePartialSpecializationDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|TagKind TK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|TemplateParameterList *Params
argument_list|,
argument|ClassTemplateDecl *SpecializedTemplate
argument_list|,
argument|ArrayRef<TemplateArgument> Args
argument_list|,
argument|const TemplateArgumentListInfo&ArgInfos
argument_list|,
argument|QualType CanonInjectedType
argument_list|,
argument|ClassTemplatePartialSpecializationDecl *PrevDecl
argument_list|)
block|;
specifier|static
name|ClassTemplatePartialSpecializationDecl
operator|*
name|CreateDeserialized
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned ID
argument_list|)
block|;
name|ClassTemplatePartialSpecializationDecl
operator|*
name|getMostRecentDecl
argument_list|()
block|{
return|return
name|cast
operator|<
name|ClassTemplatePartialSpecializationDecl
operator|>
operator|(
name|static_cast
operator|<
name|ClassTemplateSpecializationDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getMostRecentDecl
argument_list|()
operator|)
return|;
block|}
comment|/// Get the list of template parameters
name|TemplateParameterList
operator|*
name|getTemplateParameters
argument_list|()
specifier|const
block|{
return|return
name|TemplateParams
return|;
block|}
comment|/// Get the template arguments as written.
specifier|const
name|ASTTemplateArgumentListInfo
operator|*
name|getTemplateArgsAsWritten
argument_list|()
specifier|const
block|{
return|return
name|ArgsAsWritten
return|;
block|}
comment|/// \brief Retrieve the member class template partial specialization from
comment|/// which this particular class template partial specialization was
comment|/// instantiated.
comment|///
comment|/// \code
comment|/// template<typename T>
comment|/// struct Outer {
comment|///   template<typename U> struct Inner;
comment|///   template<typename U> struct Inner<U*> { }; // #1
comment|/// };
comment|///
comment|/// Outer<float>::Inner<int*> ii;
comment|/// \endcode
comment|///
comment|/// In this example, the instantiation of \c Outer<float>::Inner<int*> will
comment|/// end up instantiating the partial specialization
comment|/// \c Outer<float>::Inner<U*>, which itself was instantiated from the class
comment|/// template partial specialization \c Outer<T>::Inner<U*>. Given
comment|/// \c Outer<float>::Inner<U*>, this function would return
comment|/// \c Outer<T>::Inner<U*>.
name|ClassTemplatePartialSpecializationDecl
operator|*
name|getInstantiatedFromMember
argument_list|()
specifier|const
block|{
specifier|const
name|ClassTemplatePartialSpecializationDecl
operator|*
name|First
operator|=
name|cast
operator|<
name|ClassTemplatePartialSpecializationDecl
operator|>
operator|(
name|getFirstDecl
argument_list|()
operator|)
block|;
return|return
name|First
operator|->
name|InstantiatedFromMember
operator|.
name|getPointer
argument_list|()
return|;
block|}
name|ClassTemplatePartialSpecializationDecl
operator|*
name|getInstantiatedFromMemberTemplate
argument_list|()
specifier|const
block|{
return|return
name|getInstantiatedFromMember
argument_list|()
return|;
block|}
name|void
name|setInstantiatedFromMember
argument_list|(
argument|ClassTemplatePartialSpecializationDecl *PartialSpec
argument_list|)
block|{
name|ClassTemplatePartialSpecializationDecl
operator|*
name|First
operator|=
name|cast
operator|<
name|ClassTemplatePartialSpecializationDecl
operator|>
operator|(
name|getFirstDecl
argument_list|()
operator|)
block|;
name|First
operator|->
name|InstantiatedFromMember
operator|.
name|setPointer
argument_list|(
name|PartialSpec
argument_list|)
block|;   }
comment|/// \brief Determines whether this class template partial specialization
comment|/// template was a specialization of a member partial specialization.
comment|///
comment|/// In the following example, the member template partial specialization
comment|/// \c X<int>::Inner<T*> is a member specialization.
comment|///
comment|/// \code
comment|/// template<typename T>
comment|/// struct X {
comment|///   template<typename U> struct Inner;
comment|///   template<typename U> struct Inner<U*>;
comment|/// };
comment|///
comment|/// template<> template<typename T>
comment|/// struct X<int>::Inner<T*> { /* ... */ };
comment|/// \endcode
name|bool
name|isMemberSpecialization
argument_list|()
block|{
name|ClassTemplatePartialSpecializationDecl
operator|*
name|First
operator|=
name|cast
operator|<
name|ClassTemplatePartialSpecializationDecl
operator|>
operator|(
name|getFirstDecl
argument_list|()
operator|)
block|;
return|return
name|First
operator|->
name|InstantiatedFromMember
operator|.
name|getInt
argument_list|()
return|;
block|}
comment|/// \brief Note that this member template is a specialization.
name|void
name|setMemberSpecialization
argument_list|()
block|{
name|ClassTemplatePartialSpecializationDecl
operator|*
name|First
operator|=
name|cast
operator|<
name|ClassTemplatePartialSpecializationDecl
operator|>
operator|(
name|getFirstDecl
argument_list|()
operator|)
block|;
name|assert
argument_list|(
name|First
operator|->
name|InstantiatedFromMember
operator|.
name|getPointer
argument_list|()
operator|&&
literal|"Only member templates can be member template specializations"
argument_list|)
block|;
return|return
name|First
operator|->
name|InstantiatedFromMember
operator|.
name|setInt
argument_list|(
name|true
argument_list|)
return|;
block|}
comment|/// Retrieves the injected specialization type for this partial
comment|/// specialization.  This is not the same as the type-decl-type for
comment|/// this partial specialization, which is an InjectedClassNameType.
name|QualType
name|getInjectedSpecializationType
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getTypeForDecl
argument_list|()
operator|&&
literal|"partial specialization has no type set!"
argument_list|)
block|;
return|return
name|cast
operator|<
name|InjectedClassNameType
operator|>
operator|(
name|getTypeForDecl
argument_list|()
operator|)
operator|->
name|getInjectedSpecializationType
argument_list|()
return|;
block|}
comment|// FIXME: Add Profile support!
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classofKind
argument_list|(
argument|Kind K
argument_list|)
block|{
return|return
name|K
operator|==
name|ClassTemplatePartialSpecialization
return|;
block|}
name|friend
name|class
name|ASTDeclReader
block|;
name|friend
name|class
name|ASTDeclWriter
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Declaration of a class template.
end_comment

begin_decl_stmt
name|class
name|ClassTemplateDecl
range|:
name|public
name|RedeclarableTemplateDecl
block|{
name|protected
operator|:
comment|/// \brief Data that is common to all of the declarations of a given
comment|/// class template.
expr|struct
name|Common
operator|:
name|CommonBase
block|{
name|Common
argument_list|()
operator|:
name|LazySpecializations
argument_list|()
block|{ }
comment|/// \brief The class template specializations for this class
comment|/// template, including explicit specializations and instantiations.
name|llvm
operator|::
name|FoldingSetVector
operator|<
name|ClassTemplateSpecializationDecl
operator|>
name|Specializations
block|;
comment|/// \brief The class template partial specializations for this class
comment|/// template.
name|llvm
operator|::
name|FoldingSetVector
operator|<
name|ClassTemplatePartialSpecializationDecl
operator|>
name|PartialSpecializations
block|;
comment|/// \brief The injected-class-name type for this class template.
name|QualType
name|InjectedClassNameType
block|;
comment|/// \brief If non-null, points to an array of specializations (including
comment|/// partial specializations) known only by their external declaration IDs.
comment|///
comment|/// The first value in the array is the number of of specializations/
comment|/// partial specializations that follow.
name|uint32_t
operator|*
name|LazySpecializations
block|;   }
block|;
comment|/// \brief Retrieve the set of specializations of this class template.
name|llvm
operator|::
name|FoldingSetVector
operator|<
name|ClassTemplateSpecializationDecl
operator|>
operator|&
name|getSpecializations
argument_list|()
specifier|const
block|;
comment|/// \brief Retrieve the set of partial specializations of this class
comment|/// template.
name|llvm
operator|::
name|FoldingSetVector
operator|<
name|ClassTemplatePartialSpecializationDecl
operator|>
operator|&
name|getPartialSpecializations
argument_list|()
block|;
name|ClassTemplateDecl
argument_list|(
argument|ConstrainedTemplateDeclInfo *CTDI
argument_list|,
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|DeclarationName Name
argument_list|,
argument|TemplateParameterList *Params
argument_list|,
argument|NamedDecl *Decl
argument_list|)
operator|:
name|RedeclarableTemplateDecl
argument_list|(
argument|CTDI
argument_list|,
argument|ClassTemplate
argument_list|,
argument|C
argument_list|,
argument|DC
argument_list|,
argument|L
argument_list|,
argument|Name
argument_list|,
argument|Params
argument_list|,
argument|Decl
argument_list|)
block|{}
name|ClassTemplateDecl
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|DeclarationName Name
argument_list|,
argument|TemplateParameterList *Params
argument_list|,
argument|NamedDecl *Decl
argument_list|)
operator|:
name|ClassTemplateDecl
argument_list|(
argument|nullptr
argument_list|,
argument|C
argument_list|,
argument|DC
argument_list|,
argument|L
argument_list|,
argument|Name
argument_list|,
argument|Params
argument_list|,
argument|Decl
argument_list|)
block|{}
name|CommonBase
operator|*
name|newCommon
argument_list|(
argument|ASTContext&C
argument_list|)
specifier|const
name|override
block|;
name|Common
operator|*
name|getCommonPtr
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|Common
operator|*
operator|>
operator|(
name|RedeclarableTemplateDecl
operator|::
name|getCommonPtr
argument_list|()
operator|)
return|;
block|}
name|public
operator|:
comment|/// \brief Load any lazily-loaded specializations from the external source.
name|void
name|LoadLazySpecializations
argument_list|()
specifier|const
block|;
comment|/// \brief Get the underlying class declarations of the template.
name|CXXRecordDecl
operator|*
name|getTemplatedDecl
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|CXXRecordDecl
operator|*
operator|>
operator|(
name|TemplatedDecl
operator|.
name|getPointer
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Returns whether this template declaration defines the primary
comment|/// class pattern.
name|bool
name|isThisDeclarationADefinition
argument_list|()
specifier|const
block|{
return|return
name|getTemplatedDecl
argument_list|()
operator|->
name|isThisDeclarationADefinition
argument_list|()
return|;
block|}
comment|// FIXME: remove default argument for AssociatedConstraints
comment|/// \brief Create a class template node.
specifier|static
name|ClassTemplateDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|DeclarationName Name
argument_list|,
argument|TemplateParameterList *Params
argument_list|,
argument|NamedDecl *Decl
argument_list|,
argument|Expr *AssociatedConstraints = nullptr
argument_list|)
block|;
comment|/// \brief Create an empty class template node.
specifier|static
name|ClassTemplateDecl
operator|*
name|CreateDeserialized
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned ID
argument_list|)
block|;
comment|/// \brief Return the specialization with the provided arguments if it exists,
comment|/// otherwise return the insertion point.
name|ClassTemplateSpecializationDecl
operator|*
name|findSpecialization
argument_list|(
name|ArrayRef
operator|<
name|TemplateArgument
operator|>
name|Args
argument_list|,
name|void
operator|*
operator|&
name|InsertPos
argument_list|)
block|;
comment|/// \brief Insert the specified specialization knowing that it is not already
comment|/// in. InsertPos must be obtained from findSpecialization.
name|void
name|AddSpecialization
argument_list|(
name|ClassTemplateSpecializationDecl
operator|*
name|D
argument_list|,
name|void
operator|*
name|InsertPos
argument_list|)
block|;
name|ClassTemplateDecl
operator|*
name|getCanonicalDecl
argument_list|()
name|override
block|{
return|return
name|cast
operator|<
name|ClassTemplateDecl
operator|>
operator|(
name|RedeclarableTemplateDecl
operator|::
name|getCanonicalDecl
argument_list|()
operator|)
return|;
block|}
specifier|const
name|ClassTemplateDecl
operator|*
name|getCanonicalDecl
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|ClassTemplateDecl
operator|>
operator|(
name|RedeclarableTemplateDecl
operator|::
name|getCanonicalDecl
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Retrieve the previous declaration of this class template, or
comment|/// NULL if no such declaration exists.
name|ClassTemplateDecl
operator|*
name|getPreviousDecl
argument_list|()
block|{
return|return
name|cast_or_null
operator|<
name|ClassTemplateDecl
operator|>
operator|(
name|static_cast
operator|<
name|RedeclarableTemplateDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getPreviousDecl
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Retrieve the previous declaration of this class template, or
comment|/// NULL if no such declaration exists.
specifier|const
name|ClassTemplateDecl
operator|*
name|getPreviousDecl
argument_list|()
specifier|const
block|{
return|return
name|cast_or_null
operator|<
name|ClassTemplateDecl
operator|>
operator|(
name|static_cast
operator|<
specifier|const
name|RedeclarableTemplateDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getPreviousDecl
argument_list|()
operator|)
return|;
block|}
name|ClassTemplateDecl
operator|*
name|getMostRecentDecl
argument_list|()
block|{
return|return
name|cast
operator|<
name|ClassTemplateDecl
operator|>
operator|(
name|static_cast
operator|<
name|RedeclarableTemplateDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getMostRecentDecl
argument_list|()
operator|)
return|;
block|}
specifier|const
name|ClassTemplateDecl
operator|*
name|getMostRecentDecl
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|ClassTemplateDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getMostRecentDecl
argument_list|()
return|;
block|}
name|ClassTemplateDecl
operator|*
name|getInstantiatedFromMemberTemplate
argument_list|()
specifier|const
block|{
return|return
name|cast_or_null
operator|<
name|ClassTemplateDecl
operator|>
operator|(
name|RedeclarableTemplateDecl
operator|::
name|getInstantiatedFromMemberTemplate
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Return the partial specialization with the provided arguments if it
comment|/// exists, otherwise return the insertion point.
name|ClassTemplatePartialSpecializationDecl
operator|*
name|findPartialSpecialization
argument_list|(
name|ArrayRef
operator|<
name|TemplateArgument
operator|>
name|Args
argument_list|,
name|void
operator|*
operator|&
name|InsertPos
argument_list|)
block|;
comment|/// \brief Insert the specified partial specialization knowing that it is not
comment|/// already in. InsertPos must be obtained from findPartialSpecialization.
name|void
name|AddPartialSpecialization
argument_list|(
name|ClassTemplatePartialSpecializationDecl
operator|*
name|D
argument_list|,
name|void
operator|*
name|InsertPos
argument_list|)
block|;
comment|/// \brief Retrieve the partial specializations as an ordered list.
name|void
name|getPartialSpecializations
argument_list|(
name|SmallVectorImpl
operator|<
name|ClassTemplatePartialSpecializationDecl
operator|*
operator|>
operator|&
name|PS
argument_list|)
block|;
comment|/// \brief Find a class template partial specialization with the given
comment|/// type T.
comment|///
comment|/// \param T a dependent type that names a specialization of this class
comment|/// template.
comment|///
comment|/// \returns the class template partial specialization that exactly matches
comment|/// the type \p T, or NULL if no such partial specialization exists.
name|ClassTemplatePartialSpecializationDecl
operator|*
name|findPartialSpecialization
argument_list|(
argument|QualType T
argument_list|)
block|;
comment|/// \brief Find a class template partial specialization which was instantiated
comment|/// from the given member partial specialization.
comment|///
comment|/// \param D a member class template partial specialization.
comment|///
comment|/// \returns the class template partial specialization which was instantiated
comment|/// from the given member partial specialization, or NULL if no such partial
comment|/// specialization exists.
name|ClassTemplatePartialSpecializationDecl
operator|*
name|findPartialSpecInstantiatedFromMember
argument_list|(
name|ClassTemplatePartialSpecializationDecl
operator|*
name|D
argument_list|)
block|;
comment|/// \brief Retrieve the template specialization type of the
comment|/// injected-class-name for this class template.
comment|///
comment|/// The injected-class-name for a class template \c X is \c
comment|/// X<template-args>, where \c template-args is formed from the
comment|/// template arguments that correspond to the template parameters of
comment|/// \c X. For example:
comment|///
comment|/// \code
comment|/// template<typename T, int N>
comment|/// struct array {
comment|///   typedef array this_type; // "array" is equivalent to "array<T, N>"
comment|/// };
comment|/// \endcode
name|QualType
name|getInjectedClassNameSpecialization
argument_list|()
block|;
typedef|typedef
name|SpecIterator
operator|<
name|ClassTemplateSpecializationDecl
operator|>
name|spec_iterator
expr_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|spec_iterator
operator|>
name|spec_range
expr_stmt|;
end_typedef

begin_expr_stmt
name|spec_range
name|specializations
argument_list|()
specifier|const
block|{
return|return
name|spec_range
argument_list|(
name|spec_begin
argument_list|()
argument_list|,
name|spec_end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|spec_iterator
name|spec_begin
argument_list|()
specifier|const
block|{
return|return
name|makeSpecIterator
argument_list|(
name|getSpecializations
argument_list|()
argument_list|,
name|false
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|spec_iterator
name|spec_end
argument_list|()
specifier|const
block|{
return|return
name|makeSpecIterator
argument_list|(
name|getSpecializations
argument_list|()
argument_list|,
name|true
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Implement isa/cast/dyncast support
end_comment

begin_function
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
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
name|K
operator|==
name|ClassTemplate
return|;
block|}
end_function

begin_decl_stmt
name|friend
name|class
name|ASTDeclReader
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|ASTDeclWriter
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// \brief Declaration of a friend template.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For example:
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// template \<typename T> class A {
end_comment

begin_comment
comment|///   friend class MyVector<T>; // not a friend template
end_comment

begin_comment
comment|///   template \<typename U> friend class B; // not a friend template
end_comment

begin_comment
comment|///   template \<typename U> friend class Foo<T>::Nested; // friend template
end_comment

begin_comment
comment|/// };
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \note This class is not currently in use.  All of the above
end_comment

begin_comment
comment|/// will yield a FriendDecl, not a FriendTemplateDecl.
end_comment

begin_decl_stmt
name|class
name|FriendTemplateDecl
range|:
name|public
name|Decl
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
typedef|typedef
name|llvm
operator|::
name|PointerUnion
operator|<
name|NamedDecl
operator|*
operator|,
name|TypeSourceInfo
operator|*
operator|>
name|FriendUnion
expr_stmt|;
name|private
operator|:
comment|// The number of template parameters;  always non-zero.
name|unsigned
name|NumParams
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The parameter list.
end_comment

begin_decl_stmt
name|TemplateParameterList
modifier|*
modifier|*
name|Params
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The declaration that's a friend of this class.
end_comment

begin_decl_stmt
name|FriendUnion
name|Friend
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Location of the 'friend' specifier.
end_comment

begin_decl_stmt
name|SourceLocation
name|FriendLoc
decl_stmt|;
end_decl_stmt

begin_macro
name|FriendTemplateDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|MutableArrayRef<TemplateParameterList *> Params
argument_list|,
argument|FriendUnion Friend
argument_list|,
argument|SourceLocation FriendLoc
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|Decl
argument_list|(
name|Decl
operator|::
name|FriendTemplate
argument_list|,
name|DC
argument_list|,
name|Loc
argument_list|)
operator|,
name|NumParams
argument_list|(
name|Params
operator|.
name|size
argument_list|()
argument_list|)
operator|,
name|Params
argument_list|(
name|Params
operator|.
name|data
argument_list|()
argument_list|)
operator|,
name|Friend
argument_list|(
name|Friend
argument_list|)
operator|,
name|FriendLoc
argument_list|(
argument|FriendLoc
argument_list|)
block|{}
name|FriendTemplateDecl
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Decl
argument_list|(
name|Decl
operator|::
name|FriendTemplate
argument_list|,
name|Empty
argument_list|)
operator|,
name|NumParams
argument_list|(
literal|0
argument_list|)
operator|,
name|Params
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|public
operator|:
specifier|static
name|FriendTemplateDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|MutableArrayRef<TemplateParameterList *> Params
argument_list|,
argument|FriendUnion Friend
argument_list|,
argument|SourceLocation FriendLoc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
specifier|static
name|FriendTemplateDecl
modifier|*
name|CreateDeserialized
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|,
name|unsigned
name|ID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// If this friend declaration names a templated type (or
end_comment

begin_comment
comment|/// a dependent member type of a templated type), return that
end_comment

begin_comment
comment|/// type;  otherwise return null.
end_comment

begin_expr_stmt
name|TypeSourceInfo
operator|*
name|getFriendType
argument_list|()
specifier|const
block|{
return|return
name|Friend
operator|.
name|dyn_cast
operator|<
name|TypeSourceInfo
operator|*
operator|>
operator|(
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// If this friend declaration names a templated function (or
end_comment

begin_comment
comment|/// a member function of a templated type), return that type;
end_comment

begin_comment
comment|/// otherwise return null.
end_comment

begin_expr_stmt
name|NamedDecl
operator|*
name|getFriendDecl
argument_list|()
specifier|const
block|{
return|return
name|Friend
operator|.
name|dyn_cast
operator|<
name|NamedDecl
operator|*
operator|>
operator|(
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieves the location of the 'friend' keyword.
end_comment

begin_expr_stmt
name|SourceLocation
name|getFriendLoc
argument_list|()
specifier|const
block|{
return|return
name|FriendLoc
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|TemplateParameterList
modifier|*
name|getTemplateParameterList
argument_list|(
name|unsigned
name|i
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|i
operator|<=
name|NumParams
argument_list|)
expr_stmt|;
return|return
name|Params
index|[
name|i
index|]
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|unsigned
name|getNumTemplateParameters
argument_list|()
specifier|const
block|{
return|return
name|NumParams
return|;
block|}
end_expr_stmt

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
name|D
parameter_list|)
block|{
return|return
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
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
name|K
operator|==
name|Decl
operator|::
name|FriendTemplate
return|;
block|}
end_function

begin_decl_stmt
name|friend
name|class
name|ASTDeclReader
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// \brief Declaration of an alias template.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For example:
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// template \<typename T> using V = std::map<T*, int, MyCompare<T>>;
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_decl_stmt
name|class
name|TypeAliasTemplateDecl
range|:
name|public
name|RedeclarableTemplateDecl
block|{
name|protected
operator|:
typedef|typedef
name|CommonBase
name|Common
typedef|;
name|TypeAliasTemplateDecl
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|DeclarationName Name
argument_list|,
argument|TemplateParameterList *Params
argument_list|,
argument|NamedDecl *Decl
argument_list|)
operator|:
name|RedeclarableTemplateDecl
argument_list|(
argument|TypeAliasTemplate
argument_list|,
argument|C
argument_list|,
argument|DC
argument_list|,
argument|L
argument_list|,
argument|Name
argument_list|,
argument|Params
argument_list|,
argument|Decl
argument_list|)
block|{}
name|CommonBase
operator|*
name|newCommon
argument_list|(
argument|ASTContext&C
argument_list|)
specifier|const
name|override
decl_stmt|;
end_decl_stmt

begin_function
name|Common
modifier|*
name|getCommonPtr
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|Common
operator|*
operator|>
operator|(
name|RedeclarableTemplateDecl
operator|::
name|getCommonPtr
argument_list|()
operator|)
return|;
block|}
end_function

begin_label
name|public
label|:
end_label

begin_comment
comment|/// Get the underlying function declaration of the template.
end_comment

begin_expr_stmt
name|TypeAliasDecl
operator|*
name|getTemplatedDecl
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|TypeAliasDecl
operator|*
operator|>
operator|(
name|TemplatedDecl
operator|.
name|getPointer
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_function
name|TypeAliasTemplateDecl
modifier|*
name|getCanonicalDecl
parameter_list|()
function|override
block|{
return|return
name|cast
operator|<
name|TypeAliasTemplateDecl
operator|>
operator|(
name|RedeclarableTemplateDecl
operator|::
name|getCanonicalDecl
argument_list|()
operator|)
return|;
block|}
end_function

begin_expr_stmt
specifier|const
name|TypeAliasTemplateDecl
operator|*
name|getCanonicalDecl
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|TypeAliasTemplateDecl
operator|>
operator|(
name|RedeclarableTemplateDecl
operator|::
name|getCanonicalDecl
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the previous declaration of this function template, or
end_comment

begin_comment
comment|/// NULL if no such declaration exists.
end_comment

begin_function
name|TypeAliasTemplateDecl
modifier|*
name|getPreviousDecl
parameter_list|()
block|{
return|return
name|cast_or_null
operator|<
name|TypeAliasTemplateDecl
operator|>
operator|(
name|static_cast
operator|<
name|RedeclarableTemplateDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getPreviousDecl
argument_list|()
operator|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Retrieve the previous declaration of this function template, or
end_comment

begin_comment
comment|/// NULL if no such declaration exists.
end_comment

begin_expr_stmt
specifier|const
name|TypeAliasTemplateDecl
operator|*
name|getPreviousDecl
argument_list|()
specifier|const
block|{
return|return
name|cast_or_null
operator|<
name|TypeAliasTemplateDecl
operator|>
operator|(
name|static_cast
operator|<
specifier|const
name|RedeclarableTemplateDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getPreviousDecl
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|TypeAliasTemplateDecl
operator|*
name|getInstantiatedFromMemberTemplate
argument_list|()
specifier|const
block|{
return|return
name|cast_or_null
operator|<
name|TypeAliasTemplateDecl
operator|>
operator|(
name|RedeclarableTemplateDecl
operator|::
name|getInstantiatedFromMemberTemplate
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Create a function template node.
end_comment

begin_function_decl
specifier|static
name|TypeAliasTemplateDecl
modifier|*
name|Create
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|,
name|DeclContext
modifier|*
name|DC
parameter_list|,
name|SourceLocation
name|L
parameter_list|,
name|DeclarationName
name|Name
parameter_list|,
name|TemplateParameterList
modifier|*
name|Params
parameter_list|,
name|NamedDecl
modifier|*
name|Decl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Create an empty alias template node.
end_comment

begin_function_decl
specifier|static
name|TypeAliasTemplateDecl
modifier|*
name|CreateDeserialized
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|,
name|unsigned
name|ID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Implement isa/cast/dyncast support
end_comment

begin_function
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
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
name|K
operator|==
name|TypeAliasTemplate
return|;
block|}
end_function

begin_decl_stmt
name|friend
name|class
name|ASTDeclReader
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|ASTDeclWriter
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// \brief Declaration of a function specialization at template class scope.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is a non-standard extension needed to support MSVC.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For example:
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// template<class T>
end_comment

begin_comment
comment|/// class A {
end_comment

begin_comment
comment|///    template<class U> void foo(U a) { }
end_comment

begin_comment
comment|///    template<> void foo(int a) { }
end_comment

begin_comment
comment|/// }
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// "template<> foo(int a)" will be saved in Specialization as a normal
end_comment

begin_comment
comment|/// CXXMethodDecl. Then during an instantiation of class A, it will be
end_comment

begin_comment
comment|/// transformed into an actual function specialization.
end_comment

begin_decl_stmt
name|class
name|ClassScopeFunctionSpecializationDecl
range|:
name|public
name|Decl
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|ClassScopeFunctionSpecializationDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|CXXMethodDecl *FD
argument_list|,
argument|bool Args
argument_list|,
argument|TemplateArgumentListInfo TemplArgs
argument_list|)
operator|:
name|Decl
argument_list|(
name|Decl
operator|::
name|ClassScopeFunctionSpecialization
argument_list|,
name|DC
argument_list|,
name|Loc
argument_list|)
block|,
name|Specialization
argument_list|(
name|FD
argument_list|)
block|,
name|HasExplicitTemplateArgs
argument_list|(
name|Args
argument_list|)
block|,
name|TemplateArgs
argument_list|(
argument|std::move(TemplArgs)
argument_list|)
block|{}
name|ClassScopeFunctionSpecializationDecl
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Decl
argument_list|(
argument|Decl::ClassScopeFunctionSpecialization
argument_list|,
argument|Empty
argument_list|)
block|{}
name|CXXMethodDecl
operator|*
name|Specialization
block|;
name|bool
name|HasExplicitTemplateArgs
block|;
name|TemplateArgumentListInfo
name|TemplateArgs
block|;
name|public
operator|:
name|CXXMethodDecl
operator|*
name|getSpecialization
argument_list|()
specifier|const
block|{
return|return
name|Specialization
return|;
block|}
name|bool
name|hasExplicitTemplateArgs
argument_list|()
specifier|const
block|{
return|return
name|HasExplicitTemplateArgs
return|;
block|}
specifier|const
name|TemplateArgumentListInfo
operator|&
name|templateArgs
argument_list|()
specifier|const
block|{
return|return
name|TemplateArgs
return|;
block|}
specifier|static
name|ClassScopeFunctionSpecializationDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|CXXMethodDecl *FD
argument_list|,
argument|bool HasExplicitTemplateArgs
argument_list|,
argument|TemplateArgumentListInfo TemplateArgs
argument_list|)
block|{
return|return
name|new
argument_list|(
argument|C
argument_list|,
argument|DC
argument_list|)
name|ClassScopeFunctionSpecializationDecl
argument_list|(
name|DC
argument_list|,
name|Loc
argument_list|,
name|FD
argument_list|,
name|HasExplicitTemplateArgs
argument_list|,
name|std
operator|::
name|move
argument_list|(
name|TemplateArgs
argument_list|)
argument_list|)
return|;
block|}
specifier|static
name|ClassScopeFunctionSpecializationDecl
operator|*
name|CreateDeserialized
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|unsigned ID
argument_list|)
block|;
comment|// Implement isa/cast/dyncast/etc.
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classofKind
argument_list|(
argument|Kind K
argument_list|)
block|{
return|return
name|K
operator|==
name|Decl
operator|::
name|ClassScopeFunctionSpecialization
return|;
block|}
name|friend
name|class
name|ASTDeclReader
block|;
name|friend
name|class
name|ASTDeclWriter
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Implementation of inline functions that require the template declarations
end_comment

begin_expr_stmt
specifier|inline
name|AnyFunctionDecl
operator|::
name|AnyFunctionDecl
argument_list|(
name|FunctionTemplateDecl
operator|*
name|FTD
argument_list|)
operator|:
name|Function
argument_list|(
argument|FTD
argument_list|)
block|{ }
comment|/// \brief Represents a variable template specialization, which refers to
comment|/// a variable template with a given set of template arguments.
comment|///
comment|/// Variable template specializations represent both explicit
comment|/// specializations of variable templates, as in the example below, and
comment|/// implicit instantiations of variable templates.
comment|///
comment|/// \code
comment|/// template<typename T> constexpr T pi = T(3.1415926535897932385);
comment|///
comment|/// template<>
comment|/// constexpr float pi<float>; // variable template specialization pi<float>
comment|/// \endcode
name|class
name|VarTemplateSpecializationDecl
operator|:
name|public
name|VarDecl
operator|,
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
comment|/// \brief Structure that stores information about a variable template
comment|/// specialization that was instantiated from a variable template partial
comment|/// specialization.
block|struct
name|SpecializedPartialSpecialization
block|{
comment|/// \brief The variable template partial specialization from which this
comment|/// variable template specialization was instantiated.
name|VarTemplatePartialSpecializationDecl
operator|*
name|PartialSpecialization
block|;
comment|/// \brief The template argument list deduced for the variable template
comment|/// partial specialization itself.
specifier|const
name|TemplateArgumentList
operator|*
name|TemplateArgs
block|;   }
block|;
comment|/// \brief The template that this specialization specializes.
name|llvm
operator|::
name|PointerUnion
operator|<
name|VarTemplateDecl
operator|*
block|,
name|SpecializedPartialSpecialization
operator|*
operator|>
name|SpecializedTemplate
block|;
comment|/// \brief Further info for explicit template specialization/instantiation.
block|struct
name|ExplicitSpecializationInfo
block|{
comment|/// \brief The type-as-written.
name|TypeSourceInfo
operator|*
name|TypeAsWritten
block|;
comment|/// \brief The location of the extern keyword.
name|SourceLocation
name|ExternLoc
block|;
comment|/// \brief The location of the template keyword.
name|SourceLocation
name|TemplateKeywordLoc
block|;
name|ExplicitSpecializationInfo
argument_list|()
operator|:
name|TypeAsWritten
argument_list|(
name|nullptr
argument_list|)
block|,
name|ExternLoc
argument_list|()
block|,
name|TemplateKeywordLoc
argument_list|()
block|{}
block|}
block|;
comment|/// \brief Further info for explicit template specialization/instantiation.
comment|/// Does not apply to implicit specializations.
name|ExplicitSpecializationInfo
operator|*
name|ExplicitInfo
block|;
comment|/// \brief The template arguments used to describe this specialization.
specifier|const
name|TemplateArgumentList
operator|*
name|TemplateArgs
block|;
name|TemplateArgumentListInfo
name|TemplateArgsInfo
block|;
comment|/// \brief The point where this template was instantiated (if any).
name|SourceLocation
name|PointOfInstantiation
block|;
comment|/// \brief The kind of specialization this declaration refers to.
comment|/// Really a value of type TemplateSpecializationKind.
name|unsigned
name|SpecializationKind
operator|:
literal|3
block|;
name|protected
operator|:
name|VarTemplateSpecializationDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|ASTContext&Context
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|VarTemplateDecl *SpecializedTemplate
argument_list|,
argument|QualType T
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|,
argument|StorageClass S
argument_list|,
argument|ArrayRef<TemplateArgument> Args
argument_list|)
block|;
name|explicit
name|VarTemplateSpecializationDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|ASTContext&Context
argument_list|)
block|;
name|public
operator|:
specifier|static
name|VarTemplateSpecializationDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|VarTemplateDecl *SpecializedTemplate
argument_list|,
argument|QualType T
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|,
argument|StorageClass S
argument_list|,
argument|ArrayRef<TemplateArgument> Args
argument_list|)
block|;
specifier|static
name|VarTemplateSpecializationDecl
operator|*
name|CreateDeserialized
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned ID
argument_list|)
block|;
name|void
name|getNameForDiagnostic
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|const PrintingPolicy&Policy
argument_list|,
argument|bool Qualified
argument_list|)
specifier|const
name|override
block|;
name|VarTemplateSpecializationDecl
operator|*
name|getMostRecentDecl
argument_list|()
block|{
name|VarDecl
operator|*
name|Recent
operator|=
name|static_cast
operator|<
name|VarDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getMostRecentDecl
argument_list|()
block|;
return|return
name|cast
operator|<
name|VarTemplateSpecializationDecl
operator|>
operator|(
name|Recent
operator|)
return|;
block|}
comment|/// \brief Retrieve the template that this specialization specializes.
name|VarTemplateDecl
operator|*
name|getSpecializedTemplate
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the template arguments of the variable template
end_comment

begin_comment
comment|/// specialization.
end_comment

begin_expr_stmt
specifier|const
name|TemplateArgumentList
operator|&
name|getTemplateArgs
argument_list|()
specifier|const
block|{
return|return
operator|*
name|TemplateArgs
return|;
block|}
end_expr_stmt

begin_comment
comment|// TODO: Always set this when creating the new specialization?
end_comment

begin_function_decl
name|void
name|setTemplateArgsInfo
parameter_list|(
specifier|const
name|TemplateArgumentListInfo
modifier|&
name|ArgsInfo
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
specifier|const
name|TemplateArgumentListInfo
operator|&
name|getTemplateArgsInfo
argument_list|()
specifier|const
block|{
return|return
name|TemplateArgsInfo
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine the kind of specialization that this
end_comment

begin_comment
comment|/// declaration represents.
end_comment

begin_expr_stmt
name|TemplateSpecializationKind
name|getSpecializationKind
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|TemplateSpecializationKind
operator|>
operator|(
name|SpecializationKind
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|isExplicitSpecialization
argument_list|()
specifier|const
block|{
return|return
name|getSpecializationKind
argument_list|()
operator|==
name|TSK_ExplicitSpecialization
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief True if this declaration is an explicit specialization,
end_comment

begin_comment
comment|/// explicit instantiation declaration, or explicit instantiation
end_comment

begin_comment
comment|/// definition.
end_comment

begin_expr_stmt
name|bool
name|isExplicitInstantiationOrSpecialization
argument_list|()
specifier|const
block|{
return|return
name|isTemplateExplicitInstantiationOrSpecialization
argument_list|(
name|getTemplateSpecializationKind
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setSpecializationKind
parameter_list|(
name|TemplateSpecializationKind
name|TSK
parameter_list|)
block|{
name|SpecializationKind
operator|=
name|TSK
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Get the point of instantiation (if any), or null if none.
end_comment

begin_expr_stmt
name|SourceLocation
name|getPointOfInstantiation
argument_list|()
specifier|const
block|{
return|return
name|PointOfInstantiation
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setPointOfInstantiation
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
block|{
name|assert
argument_list|(
name|Loc
operator|.
name|isValid
argument_list|()
operator|&&
literal|"point of instantiation must be valid!"
argument_list|)
expr_stmt|;
name|PointOfInstantiation
operator|=
name|Loc
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief If this variable template specialization is an instantiation of
end_comment

begin_comment
comment|/// a template (rather than an explicit specialization), return the
end_comment

begin_comment
comment|/// variable template or variable template partial specialization from which
end_comment

begin_comment
comment|/// it was instantiated.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|PointerUnion
operator|<
name|VarTemplateDecl
operator|*
operator|,
name|VarTemplatePartialSpecializationDecl
operator|*
operator|>
name|getInstantiatedFrom
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|isTemplateInstantiation
argument_list|(
name|getSpecializationKind
argument_list|()
argument_list|)
condition|)
return|return
name|llvm
operator|::
name|PointerUnion
operator|<
name|VarTemplateDecl
operator|*
operator|,
name|VarTemplatePartialSpecializationDecl
operator|*
operator|>
operator|(
operator|)
return|;
end_expr_stmt

begin_return
return|return
name|getSpecializedTemplateOrPartial
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|/// \brief Retrieve the variable template or variable template partial
end_comment

begin_comment
comment|/// specialization which was specialized by this.
end_comment

begin_expr_stmt
unit|llvm
operator|::
name|PointerUnion
operator|<
name|VarTemplateDecl
operator|*
operator|,
name|VarTemplatePartialSpecializationDecl
operator|*
operator|>
name|getSpecializedTemplateOrPartial
argument_list|()
specifier|const
block|{
if|if
condition|(
name|SpecializedPartialSpecialization
modifier|*
name|PartialSpec
init|=
name|SpecializedTemplate
operator|.
name|dyn_cast
operator|<
name|SpecializedPartialSpecialization
operator|*
operator|>
operator|(
operator|)
condition|)
return|return
name|PartialSpec
operator|->
name|PartialSpecialization
return|;
end_expr_stmt

begin_return
return|return
name|SpecializedTemplate
operator|.
name|get
operator|<
name|VarTemplateDecl
operator|*
operator|>
operator|(
operator|)
return|;
end_return

begin_comment
unit|}
comment|/// \brief Retrieve the set of template arguments that should be used
end_comment

begin_comment
comment|/// to instantiate the initializer of the variable template or variable
end_comment

begin_comment
comment|/// template partial specialization from which this variable template
end_comment

begin_comment
comment|/// specialization was instantiated.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns For a variable template specialization instantiated from the
end_comment

begin_comment
comment|/// primary template, this function will return the same template arguments
end_comment

begin_comment
comment|/// as getTemplateArgs(). For a variable template specialization instantiated
end_comment

begin_comment
comment|/// from a variable template partial specialization, this function will the
end_comment

begin_comment
comment|/// return deduced template arguments for the variable template partial
end_comment

begin_comment
comment|/// specialization itself.
end_comment

begin_expr_stmt
unit|const
name|TemplateArgumentList
operator|&
name|getTemplateInstantiationArgs
argument_list|()
specifier|const
block|{
if|if
condition|(
name|SpecializedPartialSpecialization
modifier|*
name|PartialSpec
init|=
name|SpecializedTemplate
operator|.
name|dyn_cast
operator|<
name|SpecializedPartialSpecialization
operator|*
operator|>
operator|(
operator|)
condition|)
return|return
operator|*
name|PartialSpec
operator|->
name|TemplateArgs
return|;
end_expr_stmt

begin_return
return|return
name|getTemplateArgs
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|/// \brief Note that this variable template specialization is actually an
end_comment

begin_comment
comment|/// instantiation of the given variable template partial specialization whose
end_comment

begin_comment
comment|/// template arguments have been deduced.
end_comment

begin_macro
unit|void
name|setInstantiationOf
argument_list|(
argument|VarTemplatePartialSpecializationDecl *PartialSpec
argument_list|,
argument|const TemplateArgumentList *TemplateArgs
argument_list|)
end_macro

begin_block
block|{
name|assert
argument_list|(
operator|!
name|SpecializedTemplate
operator|.
name|is
operator|<
name|SpecializedPartialSpecialization
operator|*
operator|>
operator|(
operator|)
operator|&&
literal|"Already set to a variable template partial specialization!"
argument_list|)
expr_stmt|;
name|SpecializedPartialSpecialization
modifier|*
name|PS
init|=
name|new
argument_list|(
argument|getASTContext()
argument_list|)
name|SpecializedPartialSpecialization
argument_list|()
decl_stmt|;
name|PS
operator|->
name|PartialSpecialization
operator|=
name|PartialSpec
expr_stmt|;
name|PS
operator|->
name|TemplateArgs
operator|=
name|TemplateArgs
expr_stmt|;
name|SpecializedTemplate
operator|=
name|PS
expr_stmt|;
block|}
end_block

begin_comment
comment|/// \brief Note that this variable template specialization is an instantiation
end_comment

begin_comment
comment|/// of the given variable template.
end_comment

begin_function
name|void
name|setInstantiationOf
parameter_list|(
name|VarTemplateDecl
modifier|*
name|TemplDecl
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|SpecializedTemplate
operator|.
name|is
operator|<
name|SpecializedPartialSpecialization
operator|*
operator|>
operator|(
operator|)
operator|&&
literal|"Previously set to a variable template partial specialization!"
argument_list|)
expr_stmt|;
name|SpecializedTemplate
operator|=
name|TemplDecl
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Sets the type of this specialization as it was written by
end_comment

begin_comment
comment|/// the user.
end_comment

begin_function
name|void
name|setTypeAsWritten
parameter_list|(
name|TypeSourceInfo
modifier|*
name|T
parameter_list|)
block|{
if|if
condition|(
operator|!
name|ExplicitInfo
condition|)
name|ExplicitInfo
operator|=
name|new
argument_list|(
argument|getASTContext()
argument_list|)
name|ExplicitSpecializationInfo
expr_stmt|;
name|ExplicitInfo
operator|->
name|TypeAsWritten
operator|=
name|T
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Gets the type of this specialization as it was written by
end_comment

begin_comment
comment|/// the user, if it was so written.
end_comment

begin_expr_stmt
name|TypeSourceInfo
operator|*
name|getTypeAsWritten
argument_list|()
specifier|const
block|{
return|return
name|ExplicitInfo
operator|?
name|ExplicitInfo
operator|->
name|TypeAsWritten
operator|:
name|nullptr
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Gets the location of the extern keyword, if present.
end_comment

begin_expr_stmt
name|SourceLocation
name|getExternLoc
argument_list|()
specifier|const
block|{
return|return
name|ExplicitInfo
operator|?
name|ExplicitInfo
operator|->
name|ExternLoc
operator|:
name|SourceLocation
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Sets the location of the extern keyword.
end_comment

begin_function
name|void
name|setExternLoc
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
block|{
if|if
condition|(
operator|!
name|ExplicitInfo
condition|)
name|ExplicitInfo
operator|=
name|new
argument_list|(
argument|getASTContext()
argument_list|)
name|ExplicitSpecializationInfo
expr_stmt|;
name|ExplicitInfo
operator|->
name|ExternLoc
operator|=
name|Loc
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Sets the location of the template keyword.
end_comment

begin_function
name|void
name|setTemplateKeywordLoc
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
block|{
if|if
condition|(
operator|!
name|ExplicitInfo
condition|)
name|ExplicitInfo
operator|=
name|new
argument_list|(
argument|getASTContext()
argument_list|)
name|ExplicitSpecializationInfo
expr_stmt|;
name|ExplicitInfo
operator|->
name|TemplateKeywordLoc
operator|=
name|Loc
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Gets the location of the template keyword, if present.
end_comment

begin_expr_stmt
name|SourceLocation
name|getTemplateKeywordLoc
argument_list|()
specifier|const
block|{
return|return
name|ExplicitInfo
operator|?
name|ExplicitInfo
operator|->
name|TemplateKeywordLoc
operator|:
name|SourceLocation
argument_list|()
return|;
block|}
end_expr_stmt

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
name|Profile
argument_list|(
name|ID
argument_list|,
name|TemplateArgs
operator|->
name|asArray
argument_list|()
argument_list|,
name|getASTContext
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
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
name|ArrayRef
operator|<
name|TemplateArgument
operator|>
name|TemplateArgs
argument_list|,
name|ASTContext
operator|&
name|Context
argument_list|)
block|{
name|ID
operator|.
name|AddInteger
argument_list|(
name|TemplateArgs
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
for|for
control|(
specifier|const
name|TemplateArgument
modifier|&
name|TemplateArg
range|:
name|TemplateArgs
control|)
name|TemplateArg
operator|.
name|Profile
argument_list|(
name|ID
argument_list|,
name|Context
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_function
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
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
name|K
operator|>=
name|firstVarTemplateSpecialization
operator|&&
name|K
operator|<=
name|lastVarTemplateSpecialization
return|;
block|}
end_function

begin_decl_stmt
name|friend
name|class
name|ASTDeclReader
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|ASTDeclWriter
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|};
name|class
name|VarTemplatePartialSpecializationDecl
range|:
name|public
name|VarTemplateSpecializationDecl
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
comment|/// \brief The list of template parameters
name|TemplateParameterList
operator|*
name|TemplateParams
block|;
comment|/// \brief The source info for the template arguments as written.
comment|/// FIXME: redundant with TypeAsWritten?
specifier|const
name|ASTTemplateArgumentListInfo
operator|*
name|ArgsAsWritten
block|;
comment|/// \brief The variable template partial specialization from which this
comment|/// variable template partial specialization was instantiated.
comment|///
comment|/// The boolean value will be true to indicate that this variable template
comment|/// partial specialization was specialized at this level.
name|llvm
operator|::
name|PointerIntPair
operator|<
name|VarTemplatePartialSpecializationDecl
operator|*
block|,
literal|1
block|,
name|bool
operator|>
name|InstantiatedFromMember
block|;
name|VarTemplatePartialSpecializationDecl
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|TemplateParameterList *Params
argument_list|,
argument|VarTemplateDecl *SpecializedTemplate
argument_list|,
argument|QualType T
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|,
argument|StorageClass S
argument_list|,
argument|ArrayRef<TemplateArgument> Args
argument_list|,
argument|const ASTTemplateArgumentListInfo *ArgInfos
argument_list|)
block|;
name|VarTemplatePartialSpecializationDecl
argument_list|(
name|ASTContext
operator|&
name|Context
argument_list|)
operator|:
name|VarTemplateSpecializationDecl
argument_list|(
name|VarTemplatePartialSpecialization
argument_list|,
name|Context
argument_list|)
block|,
name|TemplateParams
argument_list|(
name|nullptr
argument_list|)
block|,
name|ArgsAsWritten
argument_list|(
name|nullptr
argument_list|)
block|,
name|InstantiatedFromMember
argument_list|(
argument|nullptr
argument_list|,
argument|false
argument_list|)
block|{}
name|public
operator|:
specifier|static
name|VarTemplatePartialSpecializationDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|TemplateParameterList *Params
argument_list|,
argument|VarTemplateDecl *SpecializedTemplate
argument_list|,
argument|QualType T
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|,
argument|StorageClass S
argument_list|,
argument|ArrayRef<TemplateArgument> Args
argument_list|,
argument|const TemplateArgumentListInfo&ArgInfos
argument_list|)
block|;
specifier|static
name|VarTemplatePartialSpecializationDecl
operator|*
name|CreateDeserialized
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned ID
argument_list|)
block|;
name|VarTemplatePartialSpecializationDecl
operator|*
name|getMostRecentDecl
argument_list|()
block|{
return|return
name|cast
operator|<
name|VarTemplatePartialSpecializationDecl
operator|>
operator|(
name|static_cast
operator|<
name|VarTemplateSpecializationDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getMostRecentDecl
argument_list|()
operator|)
return|;
block|}
comment|/// Get the list of template parameters
name|TemplateParameterList
operator|*
name|getTemplateParameters
argument_list|()
specifier|const
block|{
return|return
name|TemplateParams
return|;
block|}
comment|/// Get the template arguments as written.
specifier|const
name|ASTTemplateArgumentListInfo
operator|*
name|getTemplateArgsAsWritten
argument_list|()
specifier|const
block|{
return|return
name|ArgsAsWritten
return|;
block|}
comment|/// \brief Retrieve the member variable template partial specialization from
comment|/// which this particular variable template partial specialization was
comment|/// instantiated.
comment|///
comment|/// \code
comment|/// template<typename T>
comment|/// struct Outer {
comment|///   template<typename U> U Inner;
comment|///   template<typename U> U* Inner<U*> = (U*)(0); // #1
comment|/// };
comment|///
comment|/// template int* Outer<float>::Inner<int*>;
comment|/// \endcode
comment|///
comment|/// In this example, the instantiation of \c Outer<float>::Inner<int*> will
comment|/// end up instantiating the partial specialization
comment|/// \c Outer<float>::Inner<U*>, which itself was instantiated from the
comment|/// variable template partial specialization \c Outer<T>::Inner<U*>. Given
comment|/// \c Outer<float>::Inner<U*>, this function would return
comment|/// \c Outer<T>::Inner<U*>.
name|VarTemplatePartialSpecializationDecl
operator|*
name|getInstantiatedFromMember
argument_list|()
specifier|const
block|{
specifier|const
name|VarTemplatePartialSpecializationDecl
operator|*
name|First
operator|=
name|cast
operator|<
name|VarTemplatePartialSpecializationDecl
operator|>
operator|(
name|getFirstDecl
argument_list|()
operator|)
block|;
return|return
name|First
operator|->
name|InstantiatedFromMember
operator|.
name|getPointer
argument_list|()
return|;
block|}
name|void
name|setInstantiatedFromMember
argument_list|(
argument|VarTemplatePartialSpecializationDecl *PartialSpec
argument_list|)
block|{
name|VarTemplatePartialSpecializationDecl
operator|*
name|First
operator|=
name|cast
operator|<
name|VarTemplatePartialSpecializationDecl
operator|>
operator|(
name|getFirstDecl
argument_list|()
operator|)
block|;
name|First
operator|->
name|InstantiatedFromMember
operator|.
name|setPointer
argument_list|(
name|PartialSpec
argument_list|)
block|;   }
comment|/// \brief Determines whether this variable template partial specialization
comment|/// was a specialization of a member partial specialization.
comment|///
comment|/// In the following example, the member template partial specialization
comment|/// \c X<int>::Inner<T*> is a member specialization.
comment|///
comment|/// \code
comment|/// template<typename T>
comment|/// struct X {
comment|///   template<typename U> U Inner;
comment|///   template<typename U> U* Inner<U*> = (U*)(0);
comment|/// };
comment|///
comment|/// template<> template<typename T>
comment|/// U* X<int>::Inner<T*> = (T*)(0) + 1;
comment|/// \endcode
name|bool
name|isMemberSpecialization
argument_list|()
block|{
name|VarTemplatePartialSpecializationDecl
operator|*
name|First
operator|=
name|cast
operator|<
name|VarTemplatePartialSpecializationDecl
operator|>
operator|(
name|getFirstDecl
argument_list|()
operator|)
block|;
return|return
name|First
operator|->
name|InstantiatedFromMember
operator|.
name|getInt
argument_list|()
return|;
block|}
comment|/// \brief Note that this member template is a specialization.
name|void
name|setMemberSpecialization
argument_list|()
block|{
name|VarTemplatePartialSpecializationDecl
operator|*
name|First
operator|=
name|cast
operator|<
name|VarTemplatePartialSpecializationDecl
operator|>
operator|(
name|getFirstDecl
argument_list|()
operator|)
block|;
name|assert
argument_list|(
name|First
operator|->
name|InstantiatedFromMember
operator|.
name|getPointer
argument_list|()
operator|&&
literal|"Only member templates can be member template specializations"
argument_list|)
block|;
return|return
name|First
operator|->
name|InstantiatedFromMember
operator|.
name|setInt
argument_list|(
name|true
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classofKind
argument_list|(
argument|Kind K
argument_list|)
block|{
return|return
name|K
operator|==
name|VarTemplatePartialSpecialization
return|;
block|}
name|friend
name|class
name|ASTDeclReader
block|;
name|friend
name|class
name|ASTDeclWriter
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Declaration of a variable template.
end_comment

begin_decl_stmt
name|class
name|VarTemplateDecl
range|:
name|public
name|RedeclarableTemplateDecl
block|{
name|protected
operator|:
comment|/// \brief Data that is common to all of the declarations of a given
comment|/// variable template.
expr|struct
name|Common
operator|:
name|CommonBase
block|{
name|Common
argument_list|()
operator|:
name|LazySpecializations
argument_list|()
block|{}
comment|/// \brief The variable template specializations for this variable
comment|/// template, including explicit specializations and instantiations.
name|llvm
operator|::
name|FoldingSetVector
operator|<
name|VarTemplateSpecializationDecl
operator|>
name|Specializations
block|;
comment|/// \brief The variable template partial specializations for this variable
comment|/// template.
name|llvm
operator|::
name|FoldingSetVector
operator|<
name|VarTemplatePartialSpecializationDecl
operator|>
name|PartialSpecializations
block|;
comment|/// \brief If non-null, points to an array of specializations (including
comment|/// partial specializations) known ownly by their external declaration IDs.
comment|///
comment|/// The first value in the array is the number of of specializations/
comment|/// partial specializations that follow.
name|uint32_t
operator|*
name|LazySpecializations
block|;   }
block|;
comment|/// \brief Retrieve the set of specializations of this variable template.
name|llvm
operator|::
name|FoldingSetVector
operator|<
name|VarTemplateSpecializationDecl
operator|>
operator|&
name|getSpecializations
argument_list|()
specifier|const
block|;
comment|/// \brief Retrieve the set of partial specializations of this class
comment|/// template.
name|llvm
operator|::
name|FoldingSetVector
operator|<
name|VarTemplatePartialSpecializationDecl
operator|>
operator|&
name|getPartialSpecializations
argument_list|()
block|;
name|VarTemplateDecl
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|DeclarationName Name
argument_list|,
argument|TemplateParameterList *Params
argument_list|,
argument|NamedDecl *Decl
argument_list|)
operator|:
name|RedeclarableTemplateDecl
argument_list|(
argument|VarTemplate
argument_list|,
argument|C
argument_list|,
argument|DC
argument_list|,
argument|L
argument_list|,
argument|Name
argument_list|,
argument|Params
argument_list|,
argument|Decl
argument_list|)
block|{}
name|CommonBase
operator|*
name|newCommon
argument_list|(
argument|ASTContext&C
argument_list|)
specifier|const
name|override
block|;
name|Common
operator|*
name|getCommonPtr
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|Common
operator|*
operator|>
operator|(
name|RedeclarableTemplateDecl
operator|::
name|getCommonPtr
argument_list|()
operator|)
return|;
block|}
name|public
operator|:
comment|/// \brief Load any lazily-loaded specializations from the external source.
name|void
name|LoadLazySpecializations
argument_list|()
specifier|const
block|;
comment|/// \brief Get the underlying variable declarations of the template.
name|VarDecl
operator|*
name|getTemplatedDecl
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|VarDecl
operator|*
operator|>
operator|(
name|TemplatedDecl
operator|.
name|getPointer
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Returns whether this template declaration defines the primary
comment|/// variable pattern.
name|bool
name|isThisDeclarationADefinition
argument_list|()
specifier|const
block|{
return|return
name|getTemplatedDecl
argument_list|()
operator|->
name|isThisDeclarationADefinition
argument_list|()
return|;
block|}
name|VarTemplateDecl
operator|*
name|getDefinition
argument_list|()
block|;
comment|/// \brief Create a variable template node.
specifier|static
name|VarTemplateDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|DeclarationName Name
argument_list|,
argument|TemplateParameterList *Params
argument_list|,
argument|VarDecl *Decl
argument_list|)
block|;
comment|/// \brief Create an empty variable template node.
specifier|static
name|VarTemplateDecl
operator|*
name|CreateDeserialized
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned ID
argument_list|)
block|;
comment|/// \brief Return the specialization with the provided arguments if it exists,
comment|/// otherwise return the insertion point.
name|VarTemplateSpecializationDecl
operator|*
name|findSpecialization
argument_list|(
name|ArrayRef
operator|<
name|TemplateArgument
operator|>
name|Args
argument_list|,
name|void
operator|*
operator|&
name|InsertPos
argument_list|)
block|;
comment|/// \brief Insert the specified specialization knowing that it is not already
comment|/// in. InsertPos must be obtained from findSpecialization.
name|void
name|AddSpecialization
argument_list|(
name|VarTemplateSpecializationDecl
operator|*
name|D
argument_list|,
name|void
operator|*
name|InsertPos
argument_list|)
block|;
name|VarTemplateDecl
operator|*
name|getCanonicalDecl
argument_list|()
name|override
block|{
return|return
name|cast
operator|<
name|VarTemplateDecl
operator|>
operator|(
name|RedeclarableTemplateDecl
operator|::
name|getCanonicalDecl
argument_list|()
operator|)
return|;
block|}
specifier|const
name|VarTemplateDecl
operator|*
name|getCanonicalDecl
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|VarTemplateDecl
operator|>
operator|(
name|RedeclarableTemplateDecl
operator|::
name|getCanonicalDecl
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Retrieve the previous declaration of this variable template, or
comment|/// NULL if no such declaration exists.
name|VarTemplateDecl
operator|*
name|getPreviousDecl
argument_list|()
block|{
return|return
name|cast_or_null
operator|<
name|VarTemplateDecl
operator|>
operator|(
name|static_cast
operator|<
name|RedeclarableTemplateDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getPreviousDecl
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Retrieve the previous declaration of this variable template, or
comment|/// NULL if no such declaration exists.
specifier|const
name|VarTemplateDecl
operator|*
name|getPreviousDecl
argument_list|()
specifier|const
block|{
return|return
name|cast_or_null
operator|<
name|VarTemplateDecl
operator|>
operator|(
name|static_cast
operator|<
specifier|const
name|RedeclarableTemplateDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getPreviousDecl
argument_list|()
operator|)
return|;
block|}
name|VarTemplateDecl
operator|*
name|getMostRecentDecl
argument_list|()
block|{
return|return
name|cast
operator|<
name|VarTemplateDecl
operator|>
operator|(
name|static_cast
operator|<
name|RedeclarableTemplateDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getMostRecentDecl
argument_list|()
operator|)
return|;
block|}
specifier|const
name|VarTemplateDecl
operator|*
name|getMostRecentDecl
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|VarTemplateDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getMostRecentDecl
argument_list|()
return|;
block|}
name|VarTemplateDecl
operator|*
name|getInstantiatedFromMemberTemplate
argument_list|()
specifier|const
block|{
return|return
name|cast_or_null
operator|<
name|VarTemplateDecl
operator|>
operator|(
name|RedeclarableTemplateDecl
operator|::
name|getInstantiatedFromMemberTemplate
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Return the partial specialization with the provided arguments if it
comment|/// exists, otherwise return the insertion point.
name|VarTemplatePartialSpecializationDecl
operator|*
name|findPartialSpecialization
argument_list|(
name|ArrayRef
operator|<
name|TemplateArgument
operator|>
name|Args
argument_list|,
name|void
operator|*
operator|&
name|InsertPos
argument_list|)
block|;
comment|/// \brief Insert the specified partial specialization knowing that it is not
comment|/// already in. InsertPos must be obtained from findPartialSpecialization.
name|void
name|AddPartialSpecialization
argument_list|(
name|VarTemplatePartialSpecializationDecl
operator|*
name|D
argument_list|,
name|void
operator|*
name|InsertPos
argument_list|)
block|;
comment|/// \brief Retrieve the partial specializations as an ordered list.
name|void
name|getPartialSpecializations
argument_list|(
name|SmallVectorImpl
operator|<
name|VarTemplatePartialSpecializationDecl
operator|*
operator|>
operator|&
name|PS
argument_list|)
block|;
comment|/// \brief Find a variable template partial specialization which was
comment|/// instantiated
comment|/// from the given member partial specialization.
comment|///
comment|/// \param D a member variable template partial specialization.
comment|///
comment|/// \returns the variable template partial specialization which was
comment|/// instantiated
comment|/// from the given member partial specialization, or NULL if no such partial
comment|/// specialization exists.
name|VarTemplatePartialSpecializationDecl
operator|*
name|findPartialSpecInstantiatedFromMember
argument_list|(
name|VarTemplatePartialSpecializationDecl
operator|*
name|D
argument_list|)
block|;
typedef|typedef
name|SpecIterator
operator|<
name|VarTemplateSpecializationDecl
operator|>
name|spec_iterator
expr_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|spec_iterator
operator|>
name|spec_range
expr_stmt|;
end_typedef

begin_expr_stmt
name|spec_range
name|specializations
argument_list|()
specifier|const
block|{
return|return
name|spec_range
argument_list|(
name|spec_begin
argument_list|()
argument_list|,
name|spec_end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|spec_iterator
name|spec_begin
argument_list|()
specifier|const
block|{
return|return
name|makeSpecIterator
argument_list|(
name|getSpecializations
argument_list|()
argument_list|,
name|false
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|spec_iterator
name|spec_end
argument_list|()
specifier|const
block|{
return|return
name|makeSpecIterator
argument_list|(
name|getSpecializations
argument_list|()
argument_list|,
name|true
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Implement isa/cast/dyncast support
end_comment

begin_function
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
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
name|K
operator|==
name|VarTemplate
return|;
block|}
end_function

begin_decl_stmt
name|friend
name|class
name|ASTDeclReader
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|ASTDeclWriter
decl_stmt|;
end_decl_stmt

begin_function
unit|};
specifier|inline
name|NamedDecl
modifier|*
name|getAsNamedDecl
parameter_list|(
name|TemplateParameter
name|P
parameter_list|)
block|{
if|if
condition|(
name|auto
operator|*
name|PD
operator|=
name|P
operator|.
name|dyn_cast
operator|<
name|TemplateTypeParmDecl
operator|*
operator|>
operator|(
operator|)
condition|)
return|return
name|PD
return|;
if|if
condition|(
name|auto
operator|*
name|PD
operator|=
name|P
operator|.
name|dyn_cast
operator|<
name|NonTypeTemplateParmDecl
operator|*
operator|>
operator|(
operator|)
condition|)
return|return
name|PD
return|;
return|return
name|P
operator|.
name|get
operator|<
name|TemplateTemplateParmDecl
operator|*
operator|>
operator|(
operator|)
return|;
block|}
end_function

begin_function
specifier|inline
name|TemplateDecl
modifier|*
name|getAsTypeTemplateDecl
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
block|{
name|auto
operator|*
name|TD
operator|=
name|dyn_cast
operator|<
name|TemplateDecl
operator|>
operator|(
name|D
operator|)
expr_stmt|;
return|return
name|TD
operator|&&
operator|(
name|isa
operator|<
name|ClassTemplateDecl
operator|>
operator|(
name|TD
operator|)
operator|||
name|isa
operator|<
name|ClassTemplatePartialSpecializationDecl
operator|>
operator|(
name|TD
operator|)
operator|||
name|isa
operator|<
name|TypeAliasTemplateDecl
operator|>
operator|(
name|TD
operator|)
operator|||
name|isa
operator|<
name|TemplateTemplateParmDecl
operator|>
operator|(
name|TD
operator|)
operator|)
condition|?
name|TD
else|:
name|nullptr
return|;
block|}
end_function

begin_comment
unit|}
comment|/* end of namespace clang */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

