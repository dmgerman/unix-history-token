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
comment|//
end_comment

begin_comment
comment|//  This file defines the C++ template declaration subclasses.
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
file|"llvm/ADT/APSInt.h"
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

begin_include
include|#
directive|include
file|<limits>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|TemplateParameterList
decl_stmt|;
name|class
name|TemplateDecl
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
comment|/// TemplateParameterList - Stores a list of template parameters for a
comment|/// TemplateDecl and its derived classes.
name|class
name|TemplateParameterList
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
decl_stmt|;
name|TemplateParameterList
argument_list|(
argument|SourceLocation TemplateLoc
argument_list|,
argument|SourceLocation LAngleLoc
argument_list|,
argument|NamedDecl **Params
argument_list|,
argument|unsigned NumParams
argument_list|,
argument|SourceLocation RAngleLoc
argument_list|)
empty_stmt|;
name|public
label|:
specifier|static
name|TemplateParameterList
modifier|*
name|Create
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|,
name|SourceLocation
name|TemplateLoc
parameter_list|,
name|SourceLocation
name|LAngleLoc
parameter_list|,
name|NamedDecl
modifier|*
modifier|*
name|Params
parameter_list|,
name|unsigned
name|NumParams
parameter_list|,
name|SourceLocation
name|RAngleLoc
parameter_list|)
function_decl|;
comment|/// iterator - Iterates through the template parameters in this list.
typedef|typedef
name|NamedDecl
modifier|*
modifier|*
name|iterator
typedef|;
comment|/// const_iterator - Iterates through the template parameters in this list.
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
name|const_iterator
name|begin
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
comment|/// \btief Returns the minimum number of arguments needed to form a
comment|/// template specialization. This may be fewer than the number of
comment|/// template parameters, if some of the parameters have default
comment|/// arguments or if there is a parameter pack.
name|unsigned
name|getMinRequiredArguments
argument_list|()
specifier|const
expr_stmt|;
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
block|}
empty_stmt|;
comment|/// \brief Represents a template argument within a class template
comment|/// specialization.
name|class
name|TemplateArgument
block|{
union|union
block|{
name|uintptr_t
name|TypeOrValue
decl_stmt|;
struct|struct
block|{
name|char
name|Value
index|[
sizeof|sizeof
argument_list|(
name|llvm
operator|::
name|APSInt
argument_list|)
index|]
decl_stmt|;
name|void
modifier|*
name|Type
decl_stmt|;
block|}
name|Integer
struct|;
struct|struct
block|{
name|TemplateArgument
modifier|*
name|Args
decl_stmt|;
name|unsigned
name|NumArgs
decl_stmt|;
name|bool
name|CopyArgs
decl_stmt|;
block|}
name|Args
struct|;
block|}
union|;
comment|/// \brief Location of the beginning of this template argument.
name|SourceLocation
name|StartLoc
decl_stmt|;
name|public
label|:
comment|/// \brief The type of template argument we're storing.
enum|enum
name|ArgKind
block|{
name|Null
init|=
literal|0
block|,
comment|/// The template argument is a type. Its value is stored in the
comment|/// TypeOrValue field.
name|Type
init|=
literal|1
block|,
comment|/// The template argument is a declaration
name|Declaration
init|=
literal|2
block|,
comment|/// The template argument is an integral value stored in an llvm::APSInt.
name|Integral
init|=
literal|3
block|,
comment|/// The template argument is a value- or type-dependent expression
comment|/// stored in an Expr*.
name|Expression
init|=
literal|4
block|,
comment|/// The template argument is actually a parameter pack. Arguments are stored
comment|/// in the Args struct.
name|Pack
init|=
literal|5
block|}
name|Kind
enum|;
comment|/// \brief Construct an empty, invalid template argument.
name|TemplateArgument
argument_list|()
operator|:
name|TypeOrValue
argument_list|(
literal|0
argument_list|)
operator|,
name|StartLoc
argument_list|()
operator|,
name|Kind
argument_list|(
argument|Null
argument_list|)
block|{ }
comment|/// \brief Construct a template type argument.
name|TemplateArgument
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|QualType T
argument_list|)
operator|:
name|Kind
argument_list|(
argument|Type
argument_list|)
block|{
name|TypeOrValue
operator|=
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|T
operator|.
name|getAsOpaquePtr
argument_list|()
operator|)
block|;
name|StartLoc
operator|=
name|Loc
block|;   }
comment|/// \brief Construct a template argument that refers to a
comment|/// declaration, which is either an external declaration or a
comment|/// template declaration.
name|TemplateArgument
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|Decl *D
argument_list|)
operator|:
name|Kind
argument_list|(
argument|Declaration
argument_list|)
block|{
comment|// FIXME: Need to be sure we have the "canonical" declaration!
name|TypeOrValue
operator|=
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|D
operator|)
block|;
name|StartLoc
operator|=
name|Loc
block|;   }
comment|/// \brief Construct an integral constant template argument.
name|TemplateArgument
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|const llvm::APSInt&Value
argument_list|,
argument|QualType Type
argument_list|)
operator|:
name|Kind
argument_list|(
argument|Integral
argument_list|)
block|{
name|new
argument_list|(
argument|Integer.Value
argument_list|)
name|llvm
operator|::
name|APSInt
argument_list|(
name|Value
argument_list|)
block|;
name|Integer
operator|.
name|Type
operator|=
name|Type
operator|.
name|getAsOpaquePtr
argument_list|()
block|;
name|StartLoc
operator|=
name|Loc
block|;   }
comment|/// \brief Construct a template argument that is an expression.
comment|///
comment|/// This form of template argument only occurs in template argument
comment|/// lists used for dependent types and for expression; it will not
comment|/// occur in a non-dependent, canonical template argument list.
name|TemplateArgument
argument_list|(
name|Expr
operator|*
name|E
argument_list|)
expr_stmt|;
comment|/// \brief Copy constructor for a template argument.
name|TemplateArgument
argument_list|(
specifier|const
name|TemplateArgument
operator|&
name|Other
argument_list|)
operator|:
name|Kind
argument_list|(
argument|Other.Kind
argument_list|)
block|{
if|if
condition|(
name|Kind
operator|==
name|Integral
condition|)
block|{
name|new
argument_list|(
argument|Integer.Value
argument_list|)
name|llvm
operator|::
name|APSInt
argument_list|(
operator|*
name|Other
operator|.
name|getAsIntegral
argument_list|()
argument_list|)
expr_stmt|;
name|Integer
operator|.
name|Type
operator|=
name|Other
operator|.
name|Integer
operator|.
name|Type
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|Kind
operator|==
name|Pack
condition|)
block|{
name|Args
operator|.
name|NumArgs
operator|=
name|Other
operator|.
name|Args
operator|.
name|NumArgs
expr_stmt|;
name|Args
operator|.
name|Args
operator|=
name|new
name|TemplateArgument
index|[
name|Args
operator|.
name|NumArgs
index|]
expr_stmt|;
for|for
control|(
name|unsigned
name|I
init|=
literal|0
init|;
name|I
operator|!=
name|Args
operator|.
name|NumArgs
condition|;
operator|++
name|I
control|)
name|Args
operator|.
name|Args
index|[
name|I
index|]
operator|=
name|Other
operator|.
name|Args
operator|.
name|Args
index|[
name|I
index|]
expr_stmt|;
block|}
else|else
name|TypeOrValue
operator|=
name|Other
operator|.
name|TypeOrValue
expr_stmt|;
name|StartLoc
operator|=
name|Other
operator|.
name|StartLoc
expr_stmt|;
block|}
name|TemplateArgument
modifier|&
name|operator
init|=
operator|(
specifier|const
name|TemplateArgument
operator|&
name|Other
operator|)
block|{
comment|// FIXME: Does not provide the strong guarantee for exception
comment|// safety.
name|using
name|llvm
operator|::
name|APSInt
block|;
comment|// FIXME: Handle Packs
name|assert
argument_list|(
name|Kind
operator|!=
name|Pack
operator|&&
literal|"FIXME: Handle packs"
argument_list|)
block|;
name|assert
argument_list|(
name|Other
operator|.
name|Kind
operator|!=
name|Pack
operator|&&
literal|"FIXME: Handle packs"
argument_list|)
block|;
if|if
condition|(
name|Kind
operator|==
name|Other
operator|.
name|Kind
operator|&&
name|Kind
operator|==
name|Integral
condition|)
block|{
comment|// Copy integral values.
operator|*
name|this
operator|->
name|getAsIntegral
argument_list|()
operator|=
operator|*
name|Other
operator|.
name|getAsIntegral
argument_list|()
expr_stmt|;
name|Integer
operator|.
name|Type
operator|=
name|Other
operator|.
name|Integer
operator|.
name|Type
expr_stmt|;
block|}
else|else
block|{
comment|// Destroy the current integral value, if that's what we're holding.
if|if
condition|(
name|Kind
operator|==
name|Integral
condition|)
name|getAsIntegral
argument_list|()
operator|->
operator|~
name|APSInt
argument_list|()
expr_stmt|;
name|Kind
operator|=
name|Other
operator|.
name|Kind
expr_stmt|;
if|if
condition|(
name|Other
operator|.
name|Kind
operator|==
name|Integral
condition|)
block|{
name|new
argument_list|(
argument|Integer.Value
argument_list|)
name|llvm
operator|::
name|APSInt
argument_list|(
operator|*
name|Other
operator|.
name|getAsIntegral
argument_list|()
argument_list|)
expr_stmt|;
name|Integer
operator|.
name|Type
operator|=
name|Other
operator|.
name|Integer
operator|.
name|Type
expr_stmt|;
block|}
else|else
name|TypeOrValue
operator|=
name|Other
operator|.
name|TypeOrValue
expr_stmt|;
block|}
name|StartLoc
operator|=
name|Other
operator|.
name|StartLoc
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt

begin_expr_stmt
operator|~
name|TemplateArgument
argument_list|()
block|{
name|using
name|llvm
operator|::
name|APSInt
block|;
if|if
condition|(
name|Kind
operator|==
name|Integral
condition|)
name|getAsIntegral
argument_list|()
operator|->
operator|~
name|APSInt
argument_list|()
expr_stmt|;
elseif|else
if|if
condition|(
name|Kind
operator|==
name|Pack
operator|&&
name|Args
operator|.
name|CopyArgs
condition|)
name|delete
index|[]
name|Args
operator|.
name|Args
decl_stmt|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Return the kind of stored template argument.
end_comment

begin_expr_stmt
name|ArgKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this template argument has no value.
end_comment

begin_expr_stmt
name|bool
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|Null
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the template argument as a type.
end_comment

begin_expr_stmt
name|QualType
name|getAsType
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Kind
operator|!=
name|Type
condition|)
return|return
name|QualType
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|QualType
operator|::
name|getFromOpaquePtr
argument_list|(
name|reinterpret_cast
operator|<
name|void
operator|*
operator|>
operator|(
name|TypeOrValue
operator|)
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/// \brief Retrieve the template argument as a declaration.
end_comment

begin_expr_stmt
unit|Decl
operator|*
name|getAsDecl
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Kind
operator|!=
name|Declaration
condition|)
return|return
literal|0
return|;
end_expr_stmt

begin_return
return|return
name|reinterpret_cast
operator|<
name|Decl
operator|*
operator|>
operator|(
name|TypeOrValue
operator|)
return|;
end_return

begin_comment
unit|}
comment|/// \brief Retrieve the template argument as an integral value.
end_comment

begin_expr_stmt
unit|llvm
operator|::
name|APSInt
operator|*
name|getAsIntegral
argument_list|()
block|{
if|if
condition|(
name|Kind
operator|!=
name|Integral
condition|)
return|return
literal|0
return|;
end_expr_stmt

begin_return
return|return
name|reinterpret_cast
operator|<
name|llvm
operator|::
name|APSInt
operator|*
operator|>
operator|(
operator|&
name|Integer
operator|.
name|Value
index|[
literal|0
index|]
operator|)
return|;
end_return

begin_expr_stmt
unit|}    const
name|llvm
operator|::
name|APSInt
operator|*
name|getAsIntegral
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|TemplateArgument
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getAsIntegral
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the type of the integral value.
end_comment

begin_expr_stmt
name|QualType
name|getIntegralType
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Kind
operator|!=
name|Integral
condition|)
return|return
name|QualType
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|QualType
operator|::
name|getFromOpaquePtr
argument_list|(
name|Integer
operator|.
name|Type
argument_list|)
return|;
end_return

begin_macro
unit|}    void
name|setIntegralType
argument_list|(
argument|QualType T
argument_list|)
end_macro

begin_block
block|{
name|assert
argument_list|(
name|Kind
operator|==
name|Integral
operator|&&
literal|"Cannot set the integral type of a non-integral template argument"
argument_list|)
expr_stmt|;
name|Integer
operator|.
name|Type
operator|=
name|T
operator|.
name|getAsOpaquePtr
argument_list|()
expr_stmt|;
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Retrieve the template argument as an expression.
end_comment

begin_expr_stmt
name|Expr
operator|*
name|getAsExpr
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Kind
operator|!=
name|Expression
condition|)
return|return
literal|0
return|;
end_expr_stmt

begin_return
return|return
name|reinterpret_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
name|TypeOrValue
operator|)
return|;
end_return

begin_comment
unit|}
comment|/// \brief Iterator that traverses the elements of a template argument pack.
end_comment

begin_decl_stmt
unit|typedef
specifier|const
name|TemplateArgument
modifier|*
name|pack_iterator
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Iterator referencing the first argument of a template argument
end_comment

begin_comment
comment|/// pack.
end_comment

begin_expr_stmt
name|pack_iterator
name|pack_begin
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Kind
operator|==
name|Pack
argument_list|)
block|;
return|return
name|Args
operator|.
name|Args
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Iterator referencing one past the last argument of a template
end_comment

begin_comment
comment|/// argument pack.
end_comment

begin_expr_stmt
name|pack_iterator
name|pack_end
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Kind
operator|==
name|Pack
argument_list|)
block|;
return|return
name|Args
operator|.
name|Args
operator|+
name|Args
operator|.
name|NumArgs
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief The number of template arguments in the given template argument
end_comment

begin_comment
comment|/// pack.
end_comment

begin_expr_stmt
name|unsigned
name|pack_size
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Kind
operator|==
name|Pack
argument_list|)
block|;
return|return
name|Args
operator|.
name|NumArgs
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the location where the template argument starts.
end_comment

begin_expr_stmt
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|StartLoc
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Construct a template argument pack.
end_comment

begin_function_decl
name|void
name|setArgumentPack
parameter_list|(
name|TemplateArgument
modifier|*
name|Args
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|,
name|bool
name|CopyArgs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Used to insert TemplateArguments into FoldingSets.
end_comment

begin_decl_stmt
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
decl|const
block|{
name|ID
operator|.
name|AddInteger
argument_list|(
name|Kind
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|Kind
condition|)
block|{
case|case
name|Null
case|:
break|break;
case|case
name|Type
case|:
name|getAsType
argument_list|()
operator|.
name|Profile
argument_list|(
name|ID
argument_list|)
expr_stmt|;
break|break;
case|case
name|Declaration
case|:
name|ID
operator|.
name|AddPointer
argument_list|(
name|getAsDecl
argument_list|()
condition|?
name|getAsDecl
argument_list|()
operator|->
name|getCanonicalDecl
argument_list|()
else|:
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
name|Integral
case|:
name|getAsIntegral
argument_list|()
operator|->
name|Profile
argument_list|(
name|ID
argument_list|)
expr_stmt|;
name|getIntegralType
argument_list|()
operator|.
name|Profile
argument_list|(
name|ID
argument_list|)
expr_stmt|;
break|break;
case|case
name|Expression
case|:
name|getAsExpr
argument_list|()
operator|->
name|Profile
argument_list|(
name|ID
argument_list|,
name|Context
argument_list|,
name|true
argument_list|)
expr_stmt|;
break|break;
case|case
name|Pack
case|:
name|ID
operator|.
name|AddInteger
argument_list|(
name|Args
operator|.
name|NumArgs
argument_list|)
expr_stmt|;
for|for
control|(
name|unsigned
name|I
init|=
literal|0
init|;
name|I
operator|!=
name|Args
operator|.
name|NumArgs
condition|;
operator|++
name|I
control|)
name|Args
operator|.
name|Args
index|[
name|I
index|]
operator|.
name|Profile
argument_list|(
name|ID
argument_list|,
name|Context
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_comment
unit|};
comment|/// \brief A helper class for making template argument lists.
end_comment

begin_decl_stmt
name|class
name|TemplateArgumentListBuilder
block|{
name|TemplateArgument
modifier|*
name|StructuredArgs
decl_stmt|;
name|unsigned
name|MaxStructuredArgs
decl_stmt|;
name|unsigned
name|NumStructuredArgs
decl_stmt|;
name|TemplateArgument
modifier|*
name|FlatArgs
decl_stmt|;
name|unsigned
name|MaxFlatArgs
decl_stmt|;
name|unsigned
name|NumFlatArgs
decl_stmt|;
name|bool
name|AddingToPack
decl_stmt|;
name|unsigned
name|PackBeginIndex
decl_stmt|;
name|public
label|:
name|TemplateArgumentListBuilder
argument_list|(
argument|const TemplateParameterList *Parameters
argument_list|,
argument|unsigned NumTemplateArgs
argument_list|)
block|:
name|StructuredArgs
argument_list|(
literal|0
argument_list|)
operator|,
name|MaxStructuredArgs
argument_list|(
name|Parameters
operator|->
name|size
argument_list|()
argument_list|)
operator|,
name|NumStructuredArgs
argument_list|(
literal|0
argument_list|)
operator|,
name|FlatArgs
argument_list|(
literal|0
argument_list|)
operator|,
name|MaxFlatArgs
argument_list|(
name|std
operator|::
name|max
argument_list|(
name|MaxStructuredArgs
argument_list|,
name|NumTemplateArgs
argument_list|)
argument_list|)
operator|,
name|NumFlatArgs
argument_list|(
literal|0
argument_list|)
operator|,
name|AddingToPack
argument_list|(
name|false
argument_list|)
operator|,
name|PackBeginIndex
argument_list|(
literal|0
argument_list|)
block|{ }
name|void
name|Append
argument_list|(
specifier|const
name|TemplateArgument
operator|&
name|Arg
argument_list|)
expr_stmt|;
name|void
name|BeginPack
parameter_list|()
function_decl|;
name|void
name|EndPack
parameter_list|()
function_decl|;
name|void
name|ReleaseArgs
parameter_list|()
function_decl|;
name|unsigned
name|flatSize
argument_list|()
specifier|const
block|{
return|return
name|NumFlatArgs
return|;
block|}
specifier|const
name|TemplateArgument
operator|*
name|getFlatArguments
argument_list|()
specifier|const
block|{
return|return
name|FlatArgs
return|;
block|}
name|unsigned
name|structuredSize
argument_list|()
specifier|const
block|{
comment|// If we don't have any structured args, just reuse the flat size.
if|if
condition|(
operator|!
name|StructuredArgs
condition|)
return|return
name|flatSize
argument_list|()
return|;
return|return
name|NumStructuredArgs
return|;
block|}
end_decl_stmt

begin_expr_stmt
specifier|const
name|TemplateArgument
operator|*
name|getStructuredArguments
argument_list|()
specifier|const
block|{
comment|// If we don't have any structured args, just reuse the flat args.
if|if
condition|(
operator|!
name|StructuredArgs
condition|)
return|return
name|getFlatArguments
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|StructuredArgs
return|;
end_return

begin_empty_stmt
unit|} }
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief A template argument list.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// FIXME: In the future, this class will be extended to support
end_comment

begin_comment
comment|/// variadic templates and member templates, which will make some of
end_comment

begin_comment
comment|/// the function names below make more sense.
end_comment

begin_decl_stmt
name|class
name|TemplateArgumentList
block|{
comment|/// \brief The template argument list.
comment|///
comment|/// The integer value will be non-zero to indicate that this
comment|/// template argument list does not own the pointer.
name|llvm
operator|::
name|PointerIntPair
operator|<
specifier|const
name|TemplateArgument
operator|*
operator|,
literal|1
operator|>
name|FlatArguments
expr_stmt|;
comment|/// \brief The number of template arguments in this template
comment|/// argument list.
name|unsigned
name|NumFlatArguments
decl_stmt|;
name|llvm
operator|::
name|PointerIntPair
operator|<
specifier|const
name|TemplateArgument
operator|*
operator|,
literal|1
operator|>
name|StructuredArguments
expr_stmt|;
name|unsigned
name|NumStructuredArguments
decl_stmt|;
name|public
label|:
name|TemplateArgumentList
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|TemplateArgumentListBuilder&Builder
argument_list|,
argument|bool TakeArgs
argument_list|)
empty_stmt|;
comment|/// \brief Produces a shallow copy of the given template argument list
name|TemplateArgumentList
argument_list|(
specifier|const
name|TemplateArgumentList
operator|&
name|Other
argument_list|)
expr_stmt|;
operator|~
name|TemplateArgumentList
argument_list|()
expr_stmt|;
comment|/// \brief Retrieve the template argument at a given index.
specifier|const
name|TemplateArgument
modifier|&
name|get
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
name|NumFlatArguments
operator|&&
literal|"Invalid template argument index"
argument_list|)
expr_stmt|;
return|return
name|getFlatArgumentList
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
comment|/// \brief Retrieve the number of template arguments in this
comment|/// template argument list.
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
name|NumFlatArguments
return|;
block|}
comment|/// \brief Retrieve the number of template arguments in the
comment|/// flattened template argument list.
name|unsigned
name|flat_size
argument_list|()
specifier|const
block|{
return|return
name|NumFlatArguments
return|;
block|}
comment|/// \brief Retrieve the flattened template argument list.
specifier|const
name|TemplateArgument
operator|*
name|getFlatArgumentList
argument_list|()
specifier|const
block|{
return|return
name|FlatArguments
operator|.
name|getPointer
argument_list|()
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Kinds of Templates
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// TemplateDecl - The base class of all kinds of template declarations (e.g.,
end_comment

begin_comment
comment|/// class, function, etc.). The TemplateDecl class stores the list of template
end_comment

begin_comment
comment|/// parameters and a reference to the templated scoped declaration: the
end_comment

begin_comment
comment|/// underlying AST node.
end_comment

begin_decl_stmt
name|class
name|TemplateDecl
range|:
name|public
name|NamedDecl
block|{
name|protected
operator|:
comment|// This is probably never used.
name|TemplateDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|DeclarationName Name
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
literal|0
argument_list|)
block|,
name|TemplateParams
argument_list|(
literal|0
argument_list|)
block|{ }
comment|// Construct a template decl with the given name and parameters.
comment|// Used when there is not templated element (tt-params, alias?).
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
literal|0
argument_list|)
block|,
name|TemplateParams
argument_list|(
argument|Params
argument_list|)
block|{ }
comment|// Construct a template decl with name, parameters, and templated element.
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
argument_list|)
block|,
name|TemplateParams
argument_list|(
argument|Params
argument_list|)
block|{ }
name|public
operator|:
operator|~
name|TemplateDecl
argument_list|()
block|;
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
comment|/// Get the underlying, templated declaration.
name|NamedDecl
operator|*
name|getTemplatedDecl
argument_list|()
specifier|const
block|{
return|return
name|TemplatedDecl
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
name|D
operator|->
name|getKind
argument_list|()
operator|>=
name|TemplateFirst
operator|&&
name|D
operator|->
name|getKind
argument_list|()
operator|<=
name|TemplateLast
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const TemplateDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const FunctionTemplateDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ClassTemplateDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const TemplateTemplateParmDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
name|protected
operator|:
name|NamedDecl
operator|*
name|TemplatedDecl
block|;
name|TemplateParameterList
operator|*
name|TemplateParams
block|; }
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
name|public
operator|:
comment|/// \brief The function template specialization that this structure
comment|/// describes.
name|FunctionDecl
operator|*
name|Function
block|;
comment|/// \brief The function template from which this function template
comment|/// specialization was generated.
comment|///
comment|/// The two bits are contain the top 4 values of TemplateSpecializationKind.
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
name|getFlatArgumentList
argument_list|()
argument_list|,
name|TemplateArguments
operator|->
name|flat_size
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
argument|const TemplateArgument *TemplateArgs
argument_list|,
argument|unsigned NumTemplateArgs
argument_list|,
argument|ASTContext&Context
argument_list|)
block|{
name|ID
operator|.
name|AddInteger
argument_list|(
name|NumTemplateArgs
argument_list|)
block|;
for|for
control|(
name|unsigned
name|Arg
init|=
literal|0
init|;
name|Arg
operator|!=
name|NumTemplateArgs
condition|;
operator|++
name|Arg
control|)
name|TemplateArgs
index|[
name|Arg
index|]
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
comment|/// template, which may be a member function, static data member, or
comment|/// member class.
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
argument_list|()
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
comment|/// Declaration of a template function.
name|class
name|FunctionTemplateDecl
operator|:
name|public
name|TemplateDecl
block|{
name|protected
operator|:
comment|/// \brief Data that is common to all of the declarations of a given
comment|/// function template.
expr|struct
name|Common
block|{
name|Common
argument_list|()
operator|:
name|InstantiatedFromMember
argument_list|(
literal|0
argument_list|,
argument|false
argument_list|)
block|{ }
comment|/// \brief The function template specializations for this function
comment|/// template, including explicit specializations and instantiations.
name|llvm
operator|::
name|FoldingSet
operator|<
name|FunctionTemplateSpecializationInfo
operator|>
name|Specializations
block|;
comment|/// \brief The member function template from which this was most
comment|/// directly instantiated (or null).
comment|///
comment|/// The boolean value indicates whether this member function template
comment|/// was explicitly specialized.
name|llvm
operator|::
name|PointerIntPair
operator|<
name|FunctionTemplateDecl
operator|*
block|,
literal|1
block|,
name|bool
operator|>
name|InstantiatedFromMember
block|;   }
block|;
comment|/// \brief A pointer to the previous declaration (if this is a redeclaration)
comment|/// or to the data that is common to all declarations of this function
comment|/// template.
name|llvm
operator|::
name|PointerUnion
operator|<
name|Common
operator|*
block|,
name|FunctionTemplateDecl
operator|*
operator|>
name|CommonOrPrev
block|;
comment|/// \brief Retrieves the "common" pointer shared by all
comment|/// (re-)declarations of the same function template. Calling this routine
comment|/// may implicitly allocate memory for the common pointer.
name|Common
operator|*
name|getCommonPtr
argument_list|()
block|;
name|FunctionTemplateDecl
argument_list|(
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
name|FunctionTemplate
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
name|CommonOrPrev
argument_list|(
argument|(Common*)
literal|0
argument_list|)
block|{ }
name|public
operator|:
name|void
name|Destroy
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|)
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
operator|)
return|;
block|}
comment|/// \brief Retrieve the set of function template specializations of this
comment|/// function template.
name|llvm
operator|::
name|FoldingSet
operator|<
name|FunctionTemplateSpecializationInfo
operator|>
operator|&
name|getSpecializations
argument_list|()
block|{
return|return
name|getCommonPtr
argument_list|()
operator|->
name|Specializations
return|;
block|}
comment|/// \brief Retrieve the previous declaration of this function template, or
comment|/// NULL if no such declaration exists.
specifier|const
name|FunctionTemplateDecl
operator|*
name|getPreviousDeclaration
argument_list|()
specifier|const
block|{
return|return
name|CommonOrPrev
operator|.
name|dyn_cast
operator|<
name|FunctionTemplateDecl
operator|*
operator|>
operator|(
operator|)
return|;
block|}
comment|/// \brief Retrieve the previous declaration of this function template, or
comment|/// NULL if no such declaration exists.
name|FunctionTemplateDecl
operator|*
name|getPreviousDeclaration
argument_list|()
block|{
return|return
name|CommonOrPrev
operator|.
name|dyn_cast
operator|<
name|FunctionTemplateDecl
operator|*
operator|>
operator|(
operator|)
return|;
block|}
comment|/// \brief Set the previous declaration of this function template.
name|void
name|setPreviousDeclaration
argument_list|(
argument|FunctionTemplateDecl *Prev
argument_list|)
block|{
if|if
condition|(
name|Prev
condition|)
name|CommonOrPrev
operator|=
name|Prev
expr_stmt|;
block|}
name|virtual
name|FunctionTemplateDecl
operator|*
name|getCanonicalDecl
argument_list|()
block|;
comment|/// \brief Retrieve the member function template that this function template
comment|/// was instantiated from.
comment|///
comment|/// This routine will return non-NULL for member function templates of
comment|/// class templates.  For example, given:
comment|///
comment|/// \code
comment|/// template<typename T>
comment|/// struct X {
comment|///   template<typename U> void f();
comment|/// };
comment|/// \endcode
comment|///
comment|/// X<int>::A<float> is a CXXMethodDecl (whose parent is X<int>, a
comment|/// ClassTemplateSpecializationDecl) for which getPrimaryTemplate() will
comment|/// return X<int>::f, a FunctionTemplateDecl (whose parent is again
comment|/// X<int>) for which getInstantiatedFromMemberTemplate() will return
comment|/// X<T>::f, a FunctionTemplateDecl (whose parent is X<T>, a
comment|/// ClassTemplateDecl).
comment|///
comment|/// \returns NULL if this is not an instantiation of a member function
comment|/// template.
name|FunctionTemplateDecl
operator|*
name|getInstantiatedFromMemberTemplate
argument_list|()
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
argument|FunctionTemplateDecl *FTD
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
name|FTD
argument_list|)
block|;   }
comment|/// \brief Determines whether this template was a specialization of a
comment|/// member template.
comment|///
comment|/// In the following example, the function template \c X<int>::f is a
comment|/// member specialization.
comment|///
comment|/// \code
comment|/// template<typename T>
comment|/// struct X {
comment|///   template<typename U> void f(T, U);
comment|/// };
comment|///
comment|/// template<> template<typename T>
comment|/// void X<int>::f(int, T);
comment|/// \endcode
name|bool
name|isMemberSpecialization
argument_list|()
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
comment|/// Create a template function node.
specifier|static
name|FunctionTemplateDecl
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
argument_list|)
block|;
comment|// Implement isa/cast/dyncast support
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|D
operator|->
name|getKind
argument_list|()
operator|==
name|FunctionTemplate
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const FunctionTemplateDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|//===----------------------------------------------------------------------===//
comment|// Kinds of Template Parameters
comment|//===----------------------------------------------------------------------===//
comment|/// The TemplateParmPosition class defines the position of a template parameter
comment|/// within a template parameter list. Because template parameter can be listed
comment|/// sequentially for out-of-line template members, each template parameter is
comment|/// given a Depth - the nesting of template parameter scopes - and a Position -
comment|/// the occurrence within the parameter list.
comment|/// This class is inheritedly privately by different kinds of template
comment|/// parameters and is not part of the Decl hierarchy. Just a facility.
name|class
name|TemplateParmPosition
block|{
name|protected
operator|:
comment|// FIXME: This should probably never be called, but it's here as
name|TemplateParmPosition
argument_list|()
operator|:
name|Depth
argument_list|(
literal|0
argument_list|)
block|,
name|Position
argument_list|(
literal|0
argument_list|)
block|{
comment|/* assert(0&& "Cannot create positionless template parameter"); */
block|}
name|TemplateParmPosition
argument_list|(
argument|unsigned D
argument_list|,
argument|unsigned P
argument_list|)
operator|:
name|Depth
argument_list|(
name|D
argument_list|)
block|,
name|Position
argument_list|(
argument|P
argument_list|)
block|{ }
comment|// FIXME: These probably don't need to be ints. int:5 for depth, int:8 for
comment|// position? Maybe?
name|unsigned
name|Depth
block|;
name|unsigned
name|Position
block|;
name|public
operator|:
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
expr|}
block|;
comment|/// TemplateTypeParmDecl - Declaration of a template type parameter,
comment|/// e.g., "T" in
comment|/// @code
comment|/// template<typename T> class vector;
comment|/// @endcode
name|class
name|TemplateTypeParmDecl
operator|:
name|public
name|TypeDecl
block|{
comment|/// \brief Whether this template type parameter was declaration with
comment|/// the 'typename' keyword. If false, it was declared with the
comment|/// 'class' keyword.
name|bool
name|Typename
operator|:
literal|1
block|;
comment|/// \brief Whether this template type parameter inherited its
comment|/// default argument.
name|bool
name|InheritedDefault
operator|:
literal|1
block|;
comment|/// \brief Whether this is a parameter pack.
name|bool
name|ParameterPack
operator|:
literal|1
block|;
comment|/// \brief The location of the default argument, if any.
name|SourceLocation
name|DefaultArgumentLoc
block|;
comment|/// \brief The default template argument, if any.
name|QualType
name|DefaultArgument
block|;
name|TemplateTypeParmDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|bool Typename
argument_list|,
argument|QualType Type
argument_list|,
argument|bool ParameterPack
argument_list|)
operator|:
name|TypeDecl
argument_list|(
name|TemplateTypeParm
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|Id
argument_list|)
block|,
name|Typename
argument_list|(
name|Typename
argument_list|)
block|,
name|InheritedDefault
argument_list|(
name|false
argument_list|)
block|,
name|ParameterPack
argument_list|(
name|ParameterPack
argument_list|)
block|,
name|DefaultArgument
argument_list|()
block|{
name|TypeForDecl
operator|=
name|Type
operator|.
name|getTypePtr
argument_list|()
block|;   }
name|public
operator|:
specifier|static
name|TemplateTypeParmDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
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
argument|bool Typename
argument_list|,
argument|bool ParameterPack
argument_list|)
block|;
comment|/// \brief Whether this template type parameter was declared with
comment|/// the 'typename' keyword. If not, it was declared with the 'class'
comment|/// keyword.
name|bool
name|wasDeclaredWithTypename
argument_list|()
specifier|const
block|{
return|return
name|Typename
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
operator|!
name|DefaultArgument
operator|.
name|isNull
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the default argument, if any.
name|QualType
name|getDefaultArgument
argument_list|()
specifier|const
block|{
return|return
name|DefaultArgument
return|;
block|}
comment|/// \brief Retrieve the location of the default argument, if any.
name|SourceLocation
name|getDefaultArgumentLoc
argument_list|()
specifier|const
block|{
return|return
name|DefaultArgumentLoc
return|;
block|}
comment|/// \brief Determines whether the default argument was inherited
comment|/// from a previous declaration of this template.
name|bool
name|defaultArgumentWasInherited
argument_list|()
specifier|const
block|{
return|return
name|InheritedDefault
return|;
block|}
comment|/// \brief Set the default argument for this template parameter, and
comment|/// whether that default argument was inherited from another
comment|/// declaration.
name|void
name|setDefaultArgument
argument_list|(
argument|QualType DefArg
argument_list|,
argument|SourceLocation DefArgLoc
argument_list|,
argument|bool Inherited
argument_list|)
block|{
name|DefaultArgument
operator|=
name|DefArg
block|;
name|DefaultArgumentLoc
operator|=
name|DefArgLoc
block|;
name|InheritedDefault
operator|=
name|Inherited
block|;   }
comment|/// \brief Returns whether this is a parameter pack.
name|bool
name|isParameterPack
argument_list|()
specifier|const
block|{
return|return
name|ParameterPack
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
name|D
operator|->
name|getKind
argument_list|()
operator|==
name|TemplateTypeParm
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const TemplateTypeParmDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// NonTypeTemplateParmDecl - Declares a non-type template parameter,
comment|/// e.g., "Size" in
comment|/// @code
comment|/// template<int Size> class array { };
comment|/// @endcode
name|class
name|NonTypeTemplateParmDecl
operator|:
name|public
name|VarDecl
block|,
name|protected
name|TemplateParmPosition
block|{
comment|/// \brief The default template argument, if any.
name|Expr
operator|*
name|DefaultArgument
block|;
name|NonTypeTemplateParmDecl
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
argument|QualType T
argument_list|,
argument|DeclaratorInfo *DInfo
argument_list|)
operator|:
name|VarDecl
argument_list|(
name|NonTypeTemplateParm
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|Id
argument_list|,
name|T
argument_list|,
name|DInfo
argument_list|,
name|VarDecl
operator|::
name|None
argument_list|)
block|,
name|TemplateParmPosition
argument_list|(
name|D
argument_list|,
name|P
argument_list|)
block|,
name|DefaultArgument
argument_list|(
literal|0
argument_list|)
block|{ }
name|public
operator|:
specifier|static
name|NonTypeTemplateParmDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
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
argument|QualType T
argument_list|,
argument|DeclaratorInfo *DInfo
argument_list|)
block|;
name|using
name|TemplateParmPosition
operator|::
name|getDepth
block|;
name|using
name|TemplateParmPosition
operator|::
name|getPosition
block|;
name|using
name|TemplateParmPosition
operator|::
name|getIndex
block|;
comment|/// \brief Determine whether this template parameter has a default
comment|/// argument.
name|bool
name|hasDefaultArgument
argument_list|()
specifier|const
block|{
return|return
name|DefaultArgument
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
return|;
block|}
comment|/// \brief Retrieve the location of the default argument, if any.
name|SourceLocation
name|getDefaultArgumentLoc
argument_list|()
specifier|const
block|;
comment|/// \brief Set the default argument for this template parameter.
name|void
name|setDefaultArgument
argument_list|(
argument|Expr *DefArg
argument_list|)
block|{
name|DefaultArgument
operator|=
name|DefArg
block|;   }
comment|// Implement isa/cast/dyncast/etc.
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|D
operator|->
name|getKind
argument_list|()
operator|==
name|NonTypeTemplateParm
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const NonTypeTemplateParmDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// TemplateTemplateParmDecl - Declares a template template parameter,
comment|/// e.g., "T" in
comment|/// @code
comment|/// template<template<typename> class T> class container { };
comment|/// @endcode
comment|/// A template template parameter is a TemplateDecl because it defines the
comment|/// name of a template and the template parameters allowable for substitution.
name|class
name|TemplateTemplateParmDecl
operator|:
name|public
name|TemplateDecl
block|,
name|protected
name|TemplateParmPosition
block|{
comment|/// \brief The default template argument, if any.
name|Expr
operator|*
name|DefaultArgument
block|;
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
argument_list|)
operator|:
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
block|,
name|TemplateParmPosition
argument_list|(
name|D
argument_list|,
name|P
argument_list|)
block|,
name|DefaultArgument
argument_list|(
literal|0
argument_list|)
block|{ }
name|public
operator|:
specifier|static
name|TemplateTemplateParmDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
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
argument_list|)
block|;
name|using
name|TemplateParmPosition
operator|::
name|getDepth
block|;
name|using
name|TemplateParmPosition
operator|::
name|getPosition
block|;
name|using
name|TemplateParmPosition
operator|::
name|getIndex
block|;
comment|/// \brief Determine whether this template parameter has a default
comment|/// argument.
name|bool
name|hasDefaultArgument
argument_list|()
specifier|const
block|{
return|return
name|DefaultArgument
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
return|;
block|}
comment|/// \brief Retrieve the location of the default argument, if any.
name|SourceLocation
name|getDefaultArgumentLoc
argument_list|()
specifier|const
block|;
comment|/// \brief Set the default argument for this template parameter.
name|void
name|setDefaultArgument
argument_list|(
argument|Expr *DefArg
argument_list|)
block|{
name|DefaultArgument
operator|=
name|DefArg
block|;   }
comment|// Implement isa/cast/dyncast/etc.
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|D
operator|->
name|getKind
argument_list|()
operator|==
name|TemplateTemplateParm
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const TemplateTemplateParmDecl *D
argument_list|)
block|{
return|return
name|true
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
comment|/// \brief The template arguments used to describe this specialization.
name|TemplateArgumentList
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
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|ClassTemplateDecl *SpecializedTemplate
argument_list|,
argument|TemplateArgumentListBuilder&Builder
argument_list|,
argument|ClassTemplateSpecializationDecl *PrevDecl
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
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|ClassTemplateDecl *SpecializedTemplate
argument_list|,
argument|TemplateArgumentListBuilder&Builder
argument_list|,
argument|ClassTemplateSpecializationDecl *PrevDecl
argument_list|)
block|;
name|virtual
name|void
name|Destroy
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|)
block|;
name|virtual
name|void
name|getNameForDiagnostic
argument_list|(
argument|std::string&S
argument_list|,
argument|const PrintingPolicy&Policy
argument_list|,
argument|bool Qualified
argument_list|)
specifier|const
block|;
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
name|getSpecializationKind
argument_list|()
operator|!=
name|TSK_ImplicitInstantiation
operator|&&
name|getSpecializationKind
argument_list|()
operator|!=
name|TSK_ExplicitInstantiationDefinition
operator|&&
name|getSpecializationKind
argument_list|()
operator|!=
name|TSK_ExplicitInstantiationDeclaration
condition|)
return|return
operator|(
name|ClassTemplateDecl
operator|*
operator|)
literal|0
return|;
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
name|const_cast
operator|<
name|ClassTemplateDecl
operator|*
operator|>
operator|(
name|SpecializedTemplate
operator|.
name|get
operator|<
name|ClassTemplateDecl
operator|*
operator|>
operator|(
operator|)
operator|)
return|;
block|}
comment|/// \brief Retrieve the set of template arguments that should be used
comment|/// to instantiate members of the class template or class template partial
comment|/// specialization from which this class template specialization was
comment|/// instantiated.
comment|///
comment|/// \returns For a class template specialization instantiated from the primary
comment|/// template, this function will return the same template arguments as
comment|/// getTemplateArgs(). For a class template specialization instantiated from
comment|/// a class template partial specialization, this function will return the
comment|/// deduced template arguments for the class template partial specialization
comment|/// itself.
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
return|return
name|getTemplateArgs
argument_list|()
return|;
block|}
comment|/// \brief Note that this class template specialization is actually an
comment|/// instantiation of the given class template partial specialization whose
comment|/// template arguments have been deduced.
name|void
name|setInstantiationOf
argument_list|(
argument|ClassTemplatePartialSpecializationDecl *PartialSpec
argument_list|,
argument|TemplateArgumentList *TemplateArgs
argument_list|)
block|{
name|SpecializedPartialSpecialization
operator|*
name|PS
operator|=
name|new
argument_list|(
argument|getASTContext()
argument_list|)
name|SpecializedPartialSpecialization
argument_list|()
block|;
name|PS
operator|->
name|PartialSpecialization
operator|=
name|PartialSpec
block|;
name|PS
operator|->
name|TemplateArgs
operator|=
name|TemplateArgs
block|;
name|SpecializedTemplate
operator|=
name|PS
block|;   }
comment|/// \brief Sets the type of this specialization as it was written by
comment|/// the user. This will be a class template specialization type.
name|void
name|setTypeAsWritten
argument_list|(
argument|QualType T
argument_list|)
block|{
name|TypeForDecl
operator|=
name|T
operator|.
name|getTypePtr
argument_list|()
block|;   }
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
specifier|const
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|TemplateArgs
operator|.
name|getFlatArgumentList
argument_list|()
argument_list|,
name|TemplateArgs
operator|.
name|flat_size
argument_list|()
argument_list|,
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
argument|const TemplateArgument *TemplateArgs
argument_list|,
argument|unsigned NumTemplateArgs
argument_list|,
argument|ASTContext&Context
argument_list|)
block|{
name|ID
operator|.
name|AddInteger
argument_list|(
name|NumTemplateArgs
argument_list|)
block|;
for|for
control|(
name|unsigned
name|Arg
init|=
literal|0
init|;
name|Arg
operator|!=
name|NumTemplateArgs
condition|;
operator|++
name|Arg
control|)
name|TemplateArgs
index|[
name|Arg
index|]
operator|.
name|Profile
argument_list|(
name|ID
argument_list|,
name|Context
argument_list|)
expr_stmt|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|D
operator|->
name|getKind
argument_list|()
operator|==
name|ClassTemplateSpecialization
operator|||
name|D
operator|->
name|getKind
argument_list|()
operator|==
name|ClassTemplatePartialSpecialization
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ClassTemplateSpecializationDecl *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ClassTemplatePartialSpecializationDecl *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
name|class
name|ClassTemplatePartialSpecializationDecl
operator|:
name|public
name|ClassTemplateSpecializationDecl
block|{
comment|/// \brief The list of template parameters
name|TemplateParameterList
operator|*
name|TemplateParams
block|;
name|ClassTemplatePartialSpecializationDecl
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|TemplateParameterList *Params
argument_list|,
argument|ClassTemplateDecl *SpecializedTemplate
argument_list|,
argument|TemplateArgumentListBuilder&Builder
argument_list|,
argument|ClassTemplatePartialSpecializationDecl *PrevDecl
argument_list|)
operator|:
name|ClassTemplateSpecializationDecl
argument_list|(
name|Context
argument_list|,
name|ClassTemplatePartialSpecialization
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|SpecializedTemplate
argument_list|,
name|Builder
argument_list|,
name|PrevDecl
argument_list|)
block|,
name|TemplateParams
argument_list|(
argument|Params
argument_list|)
block|{ }
name|public
operator|:
specifier|static
name|ClassTemplatePartialSpecializationDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|TemplateParameterList *Params
argument_list|,
argument|ClassTemplateDecl *SpecializedTemplate
argument_list|,
argument|TemplateArgumentListBuilder&Builder
argument_list|,
argument|ClassTemplatePartialSpecializationDecl *PrevDecl
argument_list|)
block|;
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
comment|// FIXME: Add Profile support!
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|D
operator|->
name|getKind
argument_list|()
operator|==
name|ClassTemplatePartialSpecialization
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ClassTemplatePartialSpecializationDecl *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// Declaration of a class template.
name|class
name|ClassTemplateDecl
operator|:
name|public
name|TemplateDecl
block|{
name|protected
operator|:
comment|/// \brief Data that is common to all of the declarations of a given
comment|/// class template.
expr|struct
name|Common
block|{
name|Common
argument_list|()
operator|:
name|InstantiatedFromMember
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
block|{}
comment|/// \brief The class template specializations for this class
comment|/// template, including explicit specializations and instantiations.
name|llvm
operator|::
name|FoldingSet
operator|<
name|ClassTemplateSpecializationDecl
operator|>
name|Specializations
block|;
comment|/// \brief The class template partial specializations for this class
comment|/// template.
name|llvm
operator|::
name|FoldingSet
operator|<
name|ClassTemplatePartialSpecializationDecl
operator|>
name|PartialSpecializations
block|;
comment|/// \brief The injected-class-name type for this class template.
name|QualType
name|InjectedClassNameType
block|;
comment|/// \brief The templated member class from which this was most
comment|/// directly instantiated (or null).
comment|///
comment|/// The boolean value indicates whether this member class template
comment|/// was explicitly specialized.
name|llvm
operator|::
name|PointerIntPair
operator|<
name|ClassTemplateDecl
operator|*
block|,
literal|1
block|,
name|bool
operator|>
name|InstantiatedFromMember
block|;   }
block|;
comment|// FIXME: Combine PreviousDeclaration with CommonPtr, as in
comment|// FunctionTemplateDecl.
comment|/// \brief Previous declaration of this class template.
name|ClassTemplateDecl
operator|*
name|PreviousDeclaration
block|;
comment|/// \brief Pointer to the data that is common to all of the
comment|/// declarations of this class template.
comment|///
comment|/// The first declaration of a class template (e.g., the declaration
comment|/// with no "previous declaration") owns this pointer.
name|Common
operator|*
name|CommonPtr
block|;
name|ClassTemplateDecl
argument_list|(
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
argument|ClassTemplateDecl *PrevDecl
argument_list|,
argument|Common *CommonPtr
argument_list|)
operator|:
name|TemplateDecl
argument_list|(
name|ClassTemplate
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
name|PreviousDeclaration
argument_list|(
name|PrevDecl
argument_list|)
block|,
name|CommonPtr
argument_list|(
argument|CommonPtr
argument_list|)
block|{ }
operator|~
name|ClassTemplateDecl
argument_list|()
block|;
name|public
operator|:
comment|/// Get the underlying class declarations of the template.
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
operator|)
return|;
block|}
comment|/// \brief Retrieve the previous declaration of this template.
name|ClassTemplateDecl
operator|*
name|getPreviousDeclaration
argument_list|()
specifier|const
block|{
return|return
name|PreviousDeclaration
return|;
block|}
name|virtual
name|ClassTemplateDecl
operator|*
name|getCanonicalDecl
argument_list|()
block|;
comment|/// Create a class template node.
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
argument|ClassTemplateDecl *PrevDecl
argument_list|)
block|;
comment|/// \brief Retrieve the set of specializations of this class template.
name|llvm
operator|::
name|FoldingSet
operator|<
name|ClassTemplateSpecializationDecl
operator|>
operator|&
name|getSpecializations
argument_list|()
block|{
return|return
name|CommonPtr
operator|->
name|Specializations
return|;
block|}
comment|/// \brief Retrieve the set of partial specializations of this class
comment|/// template.
name|llvm
operator|::
name|FoldingSet
operator|<
name|ClassTemplatePartialSpecializationDecl
operator|>
operator|&
name|getPartialSpecializations
argument_list|()
block|{
return|return
name|CommonPtr
operator|->
name|PartialSpecializations
return|;
block|}
comment|/// \brief Find a class template partial specialization with the given
comment|/// type T.
comment|///
comment|/// \brief A dependent type that names a specialization of this class
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
comment|/// \brief Retrieve the type of the injected-class-name for this
comment|/// class template.
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
name|getInjectedClassNameType
argument_list|(
name|ASTContext
operator|&
name|Context
argument_list|)
block|;
comment|/// \brief Retrieve the member class template that this class template was
comment|/// derived from.
comment|///
comment|/// This routine will return non-NULL for templated member classes of
comment|/// class templates.  For example, given:
comment|///
comment|/// \code
comment|/// template<typename T>
comment|/// struct X {
comment|///   template<typename U> struct A {};
comment|/// };
comment|/// \endcode
comment|///
comment|/// X<int>::A<float> is a ClassTemplateSpecializationDecl (whose parent
comment|/// is X<int>, also a CTSD) for which getSpecializedTemplate() will
comment|/// return X<int>::A<U>, a TemplateClassDecl (whose parent is again
comment|/// X<int>) for which getInstantiatedFromMemberTemplate() will return
comment|/// X<T>::A<U>, a TemplateClassDecl (whose parent is X<T>, also a TCD).
comment|///
comment|/// \returns null if this is not an instantiation of a member class template.
name|ClassTemplateDecl
operator|*
name|getInstantiatedFromMemberTemplate
argument_list|()
specifier|const
block|{
return|return
name|CommonPtr
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
argument|ClassTemplateDecl *CTD
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|CommonPtr
operator|->
name|InstantiatedFromMember
operator|.
name|getPointer
argument_list|()
argument_list|)
block|;
name|CommonPtr
operator|->
name|InstantiatedFromMember
operator|.
name|setPointer
argument_list|(
name|CTD
argument_list|)
block|;   }
comment|/// \brief Determines whether this template was a specialization of a
comment|/// member template.
comment|///
comment|/// In the following example, the member template \c X<int>::Inner is a
comment|/// member specialization.
comment|///
comment|/// \code
comment|/// template<typename T>
comment|/// struct X {
comment|///   template<typename U> struct Inner;
comment|/// };
comment|///
comment|/// template<> template<typename T>
comment|/// struct X<int>::Inner { /* ... */ };
comment|/// \endcode
name|bool
name|isMemberSpecialization
argument_list|()
block|{
return|return
name|CommonPtr
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
name|CommonPtr
operator|->
name|InstantiatedFromMember
operator|.
name|getPointer
argument_list|()
operator|&&
literal|"Only member templates can be member template specializations"
argument_list|)
block|;
name|CommonPtr
operator|->
name|InstantiatedFromMember
operator|.
name|setInt
argument_list|(
name|true
argument_list|)
block|;   }
comment|// Implement isa/cast/dyncast support
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|D
operator|->
name|getKind
argument_list|()
operator|==
name|ClassTemplate
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ClassTemplateDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
name|virtual
name|void
name|Destroy
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|)
block|; }
block|;
comment|/// Declaration of a friend template.  For example:
comment|///
comment|/// template<typename T> class A {
comment|///   friend class MyVector<T>; // not a friend template
comment|///   template<typename U> friend class B; // friend template
comment|///   template<typename U> friend class Foo<T>::Nested; // friend template
name|class
name|FriendTemplateDecl
operator|:
name|public
name|Decl
block|{
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
name|Type
operator|*
operator|>
name|FriendUnion
expr_stmt|;
name|private
operator|:
comment|// The number of template parameters;  always non-zero.
name|unsigned
name|NumParams
block|;
comment|// The parameter list.
name|TemplateParameterList
operator|*
operator|*
name|Params
block|;
comment|// The declaration that's a friend of this class.
name|FriendUnion
name|Friend
block|;
comment|// Location of the 'friend' specifier.
name|SourceLocation
name|FriendLoc
block|;
name|FriendTemplateDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|unsigned NParams
argument_list|,
argument|TemplateParameterList **Params
argument_list|,
argument|FriendUnion Friend
argument_list|,
argument|SourceLocation FriendLoc
argument_list|)
operator|:
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
block|,
name|NumParams
argument_list|(
name|NParams
argument_list|)
block|,
name|Params
argument_list|(
name|Params
argument_list|)
block|,
name|Friend
argument_list|(
name|Friend
argument_list|)
block|,
name|FriendLoc
argument_list|(
argument|FriendLoc
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
argument|unsigned NParams
argument_list|,
argument|TemplateParameterList **Params
argument_list|,
argument|FriendUnion Friend
argument_list|,
argument|SourceLocation FriendLoc
argument_list|)
block|;
comment|/// If this friend declaration names a templated type (or
comment|/// a dependent member type of a templated type), return that
comment|/// type;  otherwise return null.
name|Type
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
name|Type
operator|*
operator|>
operator|(
operator|)
return|;
block|}
comment|/// If this friend declaration names a templated function (or
comment|/// a member function of a templated type), return that type;
comment|/// otherwise return null.
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
comment|/// Retrieves the location of the 'friend' keyword.
name|SourceLocation
name|getFriendLoc
argument_list|()
specifier|const
block|{
return|return
name|FriendLoc
return|;
block|}
name|TemplateParameterList
operator|*
name|getTemplateParameterList
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|i
operator|<=
name|NumParams
argument_list|)
block|;
return|return
name|Params
index|[
name|i
index|]
return|;
block|}
name|unsigned
name|getNumTemplateParameters
argument_list|()
specifier|const
block|{
return|return
name|NumParams
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
name|D
operator|->
name|getKind
argument_list|()
operator|==
name|Decl
operator|::
name|FriendTemplate
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const FriendTemplateDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// Implementation of inline functions that require the template declarations
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
block|}
end_decl_stmt

begin_comment
comment|/* end of namespace clang */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

