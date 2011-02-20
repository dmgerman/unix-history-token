begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- TemplateBase.h - Core classes for C++ templates ---------*- C++ -*-===//
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
comment|//  This file provides definitions which are common for all kinds of
end_comment

begin_comment
comment|//  template representation.
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
name|LLVM_CLANG_AST_TEMPLATEBASE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_TEMPLATEBASE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/APSInt.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/TemplateName.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|FoldingSetNodeID
decl_stmt|;
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
name|Decl
decl_stmt|;
name|class
name|DiagnosticBuilder
decl_stmt|;
name|class
name|Expr
decl_stmt|;
struct_decl|struct
name|PrintingPolicy
struct_decl|;
name|class
name|TypeSourceInfo
decl_stmt|;
comment|/// \brief Represents a template argument within a class template
comment|/// specialization.
name|class
name|TemplateArgument
block|{
name|public
label|:
comment|/// \brief The kind of template argument we're storing.
enum|enum
name|ArgKind
block|{
comment|/// \brief Represents an empty template argument, e.g., one that has not
comment|/// been deduced.
name|Null
init|=
literal|0
block|,
comment|/// The template argument is a type. Its value is stored in the
comment|/// TypeOrValue field.
name|Type
block|,
comment|/// The template argument is a declaration that was provided for a pointer
comment|/// or reference non-type template parameter.
name|Declaration
block|,
comment|/// The template argument is an integral value stored in an llvm::APSInt
comment|/// that was provided for an integral non-type template parameter.
name|Integral
block|,
comment|/// The template argument is a template name that was provided for a
comment|/// template template parameter.
name|Template
block|,
comment|/// The template argument is a pack expansion of a template name that was
comment|/// provided for a template template parameter.
name|TemplateExpansion
block|,
comment|/// The template argument is a value- or type-dependent expression
comment|/// stored in an Expr*.
name|Expression
block|,
comment|/// The template argument is actually a parameter pack. Arguments are stored
comment|/// in the Args struct.
name|Pack
block|}
enum|;
name|private
label|:
comment|/// \brief The kind of template argument we're storing.
name|unsigned
name|Kind
decl_stmt|;
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
specifier|const
name|TemplateArgument
modifier|*
name|Args
decl_stmt|;
name|unsigned
name|NumArgs
decl_stmt|;
block|}
name|Args
struct|;
struct|struct
block|{
name|void
modifier|*
name|Name
decl_stmt|;
name|unsigned
name|NumExpansions
decl_stmt|;
block|}
name|TemplateArg
struct|;
block|}
union|;
name|TemplateArgument
argument_list|(
name|TemplateName
argument_list|,
name|bool
argument_list|)
expr_stmt|;
comment|// DO NOT USE
name|public
label|:
comment|/// \brief Construct an empty, invalid template argument.
name|TemplateArgument
argument_list|()
operator|:
name|Kind
argument_list|(
name|Null
argument_list|)
operator|,
name|TypeOrValue
argument_list|(
literal|0
argument_list|)
block|{ }
comment|/// \brief Construct a template type argument.
name|TemplateArgument
argument_list|(
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
block|;   }
comment|/// \brief Construct a template argument that refers to a
comment|/// declaration, which is either an external declaration or a
comment|/// template declaration.
name|TemplateArgument
argument_list|(
name|Decl
operator|*
name|D
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
block|;   }
comment|/// \brief Construct an integral constant template argument.
name|TemplateArgument
argument_list|(
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
comment|// FIXME: Large integral values will get leaked. Do something
comment|// similar to what we did with IntegerLiteral.
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
block|;   }
comment|/// \brief Construct a template argument that is a template.
comment|///
comment|/// This form of template argument is generally used for template template
comment|/// parameters. However, the template name could be a dependent template
comment|/// name that ends up being instantiated to a function template whose address
comment|/// is taken.
comment|///
comment|/// \param Name The template name.
name|TemplateArgument
argument_list|(
argument|TemplateName Name
argument_list|)
operator|:
name|Kind
argument_list|(
argument|Template
argument_list|)
block|{
name|TemplateArg
operator|.
name|Name
operator|=
name|Name
operator|.
name|getAsVoidPointer
argument_list|()
block|;
name|TemplateArg
operator|.
name|NumExpansions
operator|=
literal|0
block|;   }
comment|/// \brief Construct a template argument that is a template pack expansion.
comment|///
comment|/// This form of template argument is generally used for template template
comment|/// parameters. However, the template name could be a dependent template
comment|/// name that ends up being instantiated to a function template whose address
comment|/// is taken.
comment|///
comment|/// \param Name The template name.
comment|///
comment|/// \param NumExpansions The number of expansions that will be generated by
comment|/// instantiating
name|TemplateArgument
argument_list|(
argument|TemplateName Name
argument_list|,
argument|llvm::Optional<unsigned> NumExpansions
argument_list|)
operator|:
name|Kind
argument_list|(
argument|TemplateExpansion
argument_list|)
block|{
name|TemplateArg
operator|.
name|Name
operator|=
name|Name
operator|.
name|getAsVoidPointer
argument_list|()
block|;
if|if
condition|(
name|NumExpansions
condition|)
name|TemplateArg
operator|.
name|NumExpansions
operator|=
operator|*
name|NumExpansions
operator|+
literal|1
expr_stmt|;
else|else
name|TemplateArg
operator|.
name|NumExpansions
operator|=
literal|0
expr_stmt|;
block|}
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
operator|:
name|Kind
argument_list|(
argument|Expression
argument_list|)
block|{
name|TypeOrValue
operator|=
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|E
operator|)
block|;   }
comment|/// \brief Construct a template argument that is a template argument pack.
comment|///
comment|/// We assume that storage for the template arguments provided
comment|/// outlives the TemplateArgument itself.
name|TemplateArgument
argument_list|(
argument|const TemplateArgument *Args
argument_list|,
argument|unsigned NumArgs
argument_list|)
operator|:
name|Kind
argument_list|(
argument|Pack
argument_list|)
block|{
name|this
operator|->
name|Args
operator|.
name|Args
operator|=
name|Args
block|;
name|this
operator|->
name|Args
operator|.
name|NumArgs
operator|=
name|NumArgs
block|;   }
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
comment|// FIXME: Large integral values will get leaked. Do something
comment|// similar to what we did with IntegerLiteral.
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
name|Other
operator|.
name|Args
operator|.
name|Args
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|Kind
operator|==
name|Template
operator|||
name|Kind
operator|==
name|TemplateExpansion
condition|)
block|{
name|TemplateArg
operator|.
name|Name
operator|=
name|Other
operator|.
name|TemplateArg
operator|.
name|Name
expr_stmt|;
name|TemplateArg
operator|.
name|NumExpansions
operator|=
name|Other
operator|.
name|TemplateArg
operator|.
name|NumExpansions
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
name|using
name|llvm
operator|::
name|APSInt
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
return|return
operator|*
name|this
return|;
block|}
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
decl_stmt|;
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
elseif|else
if|if
condition|(
name|Other
operator|.
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
name|Other
operator|.
name|Args
operator|.
name|Args
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|Kind
operator|==
name|Template
operator|||
name|Kind
operator|==
name|TemplateExpansion
condition|)
block|{
name|TemplateArg
operator|.
name|Name
operator|=
name|Other
operator|.
name|TemplateArg
operator|.
name|Name
expr_stmt|;
name|TemplateArg
operator|.
name|NumExpansions
operator|=
name|Other
operator|.
name|TemplateArg
operator|.
name|NumExpansions
expr_stmt|;
block|}
else|else
block|{
name|TypeOrValue
operator|=
name|Other
operator|.
name|TypeOrValue
expr_stmt|;
block|}
return|return
operator|*
name|this
return|;
block|}
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
block|}
comment|/// \brief Create a new template argument pack by copying the given set of
comment|/// template arguments.
specifier|static
name|TemplateArgument
name|CreatePackCopy
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|,
specifier|const
name|TemplateArgument
modifier|*
name|Args
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|)
function_decl|;
comment|/// \brief Return the kind of stored template argument.
name|ArgKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
operator|(
name|ArgKind
operator|)
name|Kind
return|;
block|}
comment|/// \brief Determine whether this template argument has no value.
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
comment|/// \brief Whether this template argument is dependent on a template
comment|/// parameter.
name|bool
name|isDependent
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Whether this template argument contains an unexpanded
comment|/// parameter pack.
name|bool
name|containsUnexpandedParameterPack
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determine whether this template argument is a pack expansion.
name|bool
name|isPackExpansion
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Retrieve the template argument as a type.
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
block|}
end_decl_stmt

begin_comment
comment|/// \brief Retrieve the template argument as a declaration.
end_comment

begin_expr_stmt
name|Decl
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
comment|/// \brief Retrieve the template argument as a template name.
end_comment

begin_macro
unit|TemplateName
name|getAsTemplate
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
if|if
condition|(
name|Kind
operator|!=
name|Template
condition|)
return|return
name|TemplateName
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|TemplateName
operator|::
name|getFromVoidPointer
argument_list|(
name|TemplateArg
operator|.
name|Name
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/// \brief Retrieve the template argument as a template name; if the argument
end_comment

begin_comment
comment|/// is a pack expansion, return the pattern as a template name.
end_comment

begin_macro
unit|TemplateName
name|getAsTemplateOrTemplatePattern
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
if|if
condition|(
name|Kind
operator|!=
name|Template
operator|&&
name|Kind
operator|!=
name|TemplateExpansion
condition|)
return|return
name|TemplateName
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|TemplateName
operator|::
name|getFromVoidPointer
argument_list|(
name|TemplateArg
operator|.
name|Name
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/// \brief Retrieve the number of expansions that a template template argument
end_comment

begin_comment
comment|/// expansion will produce, if known.
end_comment

begin_expr_stmt
unit|llvm
operator|::
name|Optional
operator|<
name|unsigned
operator|>
name|getNumTemplateExpansions
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the template argument as an integral value.
end_comment

begin_expr_stmt
name|llvm
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
comment|/// Determines whether two template arguments are superficially the
end_comment

begin_comment
comment|/// same.
end_comment

begin_decl_stmt
name|bool
name|structurallyEquals
argument_list|(
specifier|const
name|TemplateArgument
operator|&
name|Other
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief When the template argument is a pack expansion, returns
end_comment

begin_comment
comment|/// the pattern of the pack expansion.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Ellipsis Will be set to the location of the ellipsis.
end_comment

begin_expr_stmt
name|TemplateArgument
name|getPackExpansionPattern
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Print this template argument to the given output stream.
end_comment

begin_decl_stmt
name|void
name|print
argument_list|(
specifier|const
name|PrintingPolicy
operator|&
name|Policy
argument_list|,
name|llvm
operator|::
name|raw_ostream
operator|&
name|Out
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

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
specifier|const
name|ASTContext
operator|&
name|Context
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// Location information for a TemplateArgument.
end_comment

begin_struct
struct|struct
name|TemplateArgumentLocInfo
block|{
name|private
label|:
union|union
block|{
name|Expr
modifier|*
name|Expression
decl_stmt|;
name|TypeSourceInfo
modifier|*
name|Declarator
decl_stmt|;
struct|struct
block|{
name|unsigned
name|QualifierRange
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|TemplateNameLoc
decl_stmt|;
name|unsigned
name|EllipsisLoc
decl_stmt|;
block|}
name|Template
struct|;
block|}
union|;
name|public
label|:
name|TemplateArgumentLocInfo
argument_list|()
expr_stmt|;
name|TemplateArgumentLocInfo
argument_list|(
name|TypeSourceInfo
operator|*
name|TInfo
argument_list|)
operator|:
name|Declarator
argument_list|(
argument|TInfo
argument_list|)
block|{}
name|TemplateArgumentLocInfo
argument_list|(
name|Expr
operator|*
name|E
argument_list|)
operator|:
name|Expression
argument_list|(
argument|E
argument_list|)
block|{}
name|TemplateArgumentLocInfo
argument_list|(
argument|SourceRange QualifierRange
argument_list|,
argument|SourceLocation TemplateNameLoc
argument_list|,
argument|SourceLocation EllipsisLoc
argument_list|)
block|{
name|Template
operator|.
name|QualifierRange
index|[
literal|0
index|]
operator|=
name|QualifierRange
operator|.
name|getBegin
argument_list|()
operator|.
name|getRawEncoding
argument_list|()
block|;
name|Template
operator|.
name|QualifierRange
index|[
literal|1
index|]
operator|=
name|QualifierRange
operator|.
name|getEnd
argument_list|()
operator|.
name|getRawEncoding
argument_list|()
block|;
name|Template
operator|.
name|TemplateNameLoc
operator|=
name|TemplateNameLoc
operator|.
name|getRawEncoding
argument_list|()
block|;
name|Template
operator|.
name|EllipsisLoc
operator|=
name|EllipsisLoc
operator|.
name|getRawEncoding
argument_list|()
block|;   }
name|TypeSourceInfo
operator|*
name|getAsTypeSourceInfo
argument_list|()
specifier|const
block|{
return|return
name|Declarator
return|;
block|}
name|Expr
operator|*
name|getAsExpr
argument_list|()
specifier|const
block|{
return|return
name|Expression
return|;
block|}
name|SourceRange
name|getTemplateQualifierRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|SourceLocation
operator|::
name|getFromRawEncoding
argument_list|(
name|Template
operator|.
name|QualifierRange
index|[
literal|0
index|]
argument_list|)
argument_list|,
name|SourceLocation
operator|::
name|getFromRawEncoding
argument_list|(
name|Template
operator|.
name|QualifierRange
index|[
literal|1
index|]
argument_list|)
argument_list|)
return|;
block|}
name|SourceLocation
name|getTemplateNameLoc
argument_list|()
specifier|const
block|{
return|return
name|SourceLocation
operator|::
name|getFromRawEncoding
argument_list|(
name|Template
operator|.
name|TemplateNameLoc
argument_list|)
return|;
block|}
name|SourceLocation
name|getTemplateEllipsisLoc
argument_list|()
specifier|const
block|{
return|return
name|SourceLocation
operator|::
name|getFromRawEncoding
argument_list|(
name|Template
operator|.
name|EllipsisLoc
argument_list|)
return|;
block|}
block|}
struct|;
end_struct

begin_comment
comment|/// Location wrapper for a TemplateArgument.  TemplateArgument is to
end_comment

begin_comment
comment|/// TemplateArgumentLoc as Type is to TypeLoc.
end_comment

begin_decl_stmt
name|class
name|TemplateArgumentLoc
block|{
name|TemplateArgument
name|Argument
decl_stmt|;
name|TemplateArgumentLocInfo
name|LocInfo
decl_stmt|;
name|public
label|:
name|TemplateArgumentLoc
argument_list|()
block|{}
name|TemplateArgumentLoc
argument_list|(
argument|const TemplateArgument&Argument
argument_list|,
argument|TemplateArgumentLocInfo Opaque
argument_list|)
block|:
name|Argument
argument_list|(
name|Argument
argument_list|)
operator|,
name|LocInfo
argument_list|(
argument|Opaque
argument_list|)
block|{   }
name|TemplateArgumentLoc
argument_list|(
specifier|const
name|TemplateArgument
operator|&
name|Argument
argument_list|,
name|TypeSourceInfo
operator|*
name|TInfo
argument_list|)
operator|:
name|Argument
argument_list|(
name|Argument
argument_list|)
operator|,
name|LocInfo
argument_list|(
argument|TInfo
argument_list|)
block|{
name|assert
argument_list|(
name|Argument
operator|.
name|getKind
argument_list|()
operator|==
name|TemplateArgument
operator|::
name|Type
argument_list|)
block|;   }
name|TemplateArgumentLoc
argument_list|(
specifier|const
name|TemplateArgument
operator|&
name|Argument
argument_list|,
name|Expr
operator|*
name|E
argument_list|)
operator|:
name|Argument
argument_list|(
name|Argument
argument_list|)
operator|,
name|LocInfo
argument_list|(
argument|E
argument_list|)
block|{
name|assert
argument_list|(
name|Argument
operator|.
name|getKind
argument_list|()
operator|==
name|TemplateArgument
operator|::
name|Expression
argument_list|)
block|;   }
name|TemplateArgumentLoc
argument_list|(
argument|const TemplateArgument&Argument
argument_list|,
argument|SourceRange QualifierRange
argument_list|,
argument|SourceLocation TemplateNameLoc
argument_list|,
argument|SourceLocation EllipsisLoc = SourceLocation()
argument_list|)
operator|:
name|Argument
argument_list|(
name|Argument
argument_list|)
operator|,
name|LocInfo
argument_list|(
argument|QualifierRange
argument_list|,
argument|TemplateNameLoc
argument_list|,
argument|EllipsisLoc
argument_list|)
block|{
name|assert
argument_list|(
name|Argument
operator|.
name|getKind
argument_list|()
operator|==
name|TemplateArgument
operator|::
name|Template
operator|||
name|Argument
operator|.
name|getKind
argument_list|()
operator|==
name|TemplateArgument
operator|::
name|TemplateExpansion
argument_list|)
block|;   }
comment|/// \brief - Fetches the primary location of the argument.
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Argument
operator|.
name|getKind
argument_list|()
operator|==
name|TemplateArgument
operator|::
name|Template
operator|||
name|Argument
operator|.
name|getKind
argument_list|()
operator|==
name|TemplateArgument
operator|::
name|TemplateExpansion
condition|)
return|return
name|getTemplateNameLoc
argument_list|()
return|;
return|return
name|getSourceRange
argument_list|()
operator|.
name|getBegin
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief - Fetches the full source range of the argument.
end_comment

begin_expr_stmt
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|TemplateArgument
operator|&
name|getArgument
argument_list|()
specifier|const
block|{
return|return
name|Argument
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|TemplateArgumentLocInfo
name|getLocInfo
argument_list|()
specifier|const
block|{
return|return
name|LocInfo
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|TypeSourceInfo
operator|*
name|getTypeSourceInfo
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Argument
operator|.
name|getKind
argument_list|()
operator|==
name|TemplateArgument
operator|::
name|Type
argument_list|)
block|;
return|return
name|LocInfo
operator|.
name|getAsTypeSourceInfo
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|Expr
operator|*
name|getSourceExpression
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Argument
operator|.
name|getKind
argument_list|()
operator|==
name|TemplateArgument
operator|::
name|Expression
argument_list|)
block|;
return|return
name|LocInfo
operator|.
name|getAsExpr
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|Expr
operator|*
name|getSourceDeclExpression
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Argument
operator|.
name|getKind
argument_list|()
operator|==
name|TemplateArgument
operator|::
name|Declaration
argument_list|)
block|;
return|return
name|LocInfo
operator|.
name|getAsExpr
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|SourceRange
name|getTemplateQualifierRange
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Argument
operator|.
name|getKind
argument_list|()
operator|==
name|TemplateArgument
operator|::
name|Template
operator|||
name|Argument
operator|.
name|getKind
argument_list|()
operator|==
name|TemplateArgument
operator|::
name|TemplateExpansion
argument_list|)
block|;
return|return
name|LocInfo
operator|.
name|getTemplateQualifierRange
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|SourceLocation
name|getTemplateNameLoc
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Argument
operator|.
name|getKind
argument_list|()
operator|==
name|TemplateArgument
operator|::
name|Template
operator|||
name|Argument
operator|.
name|getKind
argument_list|()
operator|==
name|TemplateArgument
operator|::
name|TemplateExpansion
argument_list|)
block|;
return|return
name|LocInfo
operator|.
name|getTemplateNameLoc
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|SourceLocation
name|getTemplateEllipsisLoc
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Argument
operator|.
name|getKind
argument_list|()
operator|==
name|TemplateArgument
operator|::
name|TemplateExpansion
argument_list|)
block|;
return|return
name|LocInfo
operator|.
name|getTemplateEllipsisLoc
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief When the template argument is a pack expansion, returns
end_comment

begin_comment
comment|/// the pattern of the pack expansion.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Ellipsis Will be set to the location of the ellipsis.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param NumExpansions Will be set to the number of expansions that will
end_comment

begin_comment
comment|/// be generated from this pack expansion, if known a priori.
end_comment

begin_decl_stmt
name|TemplateArgumentLoc
name|getPackExpansionPattern
argument_list|(
name|SourceLocation
operator|&
name|Ellipsis
argument_list|,
name|llvm
operator|::
name|Optional
operator|<
name|unsigned
operator|>
operator|&
name|NumExpansions
argument_list|,
name|ASTContext
operator|&
name|Context
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// A convenient class for passing around template argument
end_comment

begin_comment
comment|/// information.  Designed to be passed by reference.
end_comment

begin_decl_stmt
name|class
name|TemplateArgumentListInfo
block|{
name|llvm
operator|::
name|SmallVector
operator|<
name|TemplateArgumentLoc
operator|,
literal|8
operator|>
name|Arguments
expr_stmt|;
name|SourceLocation
name|LAngleLoc
decl_stmt|;
name|SourceLocation
name|RAngleLoc
decl_stmt|;
name|public
label|:
name|TemplateArgumentListInfo
argument_list|()
block|{}
name|TemplateArgumentListInfo
argument_list|(
argument|SourceLocation LAngleLoc
argument_list|,
argument|SourceLocation RAngleLoc
argument_list|)
block|:
name|LAngleLoc
argument_list|(
name|LAngleLoc
argument_list|)
operator|,
name|RAngleLoc
argument_list|(
argument|RAngleLoc
argument_list|)
block|{}
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
name|void
name|setLAngleLoc
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
block|{
name|LAngleLoc
operator|=
name|Loc
expr_stmt|;
block|}
name|void
name|setRAngleLoc
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
block|{
name|RAngleLoc
operator|=
name|Loc
expr_stmt|;
block|}
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
name|Arguments
operator|.
name|size
argument_list|()
return|;
block|}
specifier|const
name|TemplateArgumentLoc
operator|*
name|getArgumentArray
argument_list|()
specifier|const
block|{
return|return
name|Arguments
operator|.
name|data
argument_list|()
return|;
block|}
specifier|const
name|TemplateArgumentLoc
modifier|&
name|operator
index|[]
argument_list|(
name|unsigned
name|I
argument_list|)
decl|const
block|{
return|return
name|Arguments
index|[
name|I
index|]
return|;
block|}
name|void
name|addArgument
parameter_list|(
specifier|const
name|TemplateArgumentLoc
modifier|&
name|Loc
parameter_list|)
block|{
name|Arguments
operator|.
name|push_back
argument_list|(
name|Loc
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
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
specifier|const
name|TemplateArgument
operator|&
name|Arg
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|inline
name|TemplateSpecializationType
operator|::
name|iterator
name|TemplateSpecializationType
operator|::
name|end
argument_list|()
specifier|const
block|{
return|return
name|getArgs
argument_list|()
operator|+
name|getNumArgs
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|DependentTemplateSpecializationType
operator|::
name|iterator
name|DependentTemplateSpecializationType
operator|::
name|end
argument_list|()
specifier|const
block|{
return|return
name|getArgs
argument_list|()
operator|+
name|getNumArgs
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
specifier|const
name|TemplateArgument
operator|&
name|TemplateSpecializationType
operator|::
name|getArg
argument_list|(
argument|unsigned Idx
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|Idx
operator|<
name|getNumArgs
argument_list|()
operator|&&
literal|"Template argument out of range"
argument_list|)
block|;
return|return
name|getArgs
argument_list|()
index|[
name|Idx
index|]
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
specifier|const
name|TemplateArgument
operator|&
name|DependentTemplateSpecializationType
operator|::
name|getArg
argument_list|(
argument|unsigned Idx
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|Idx
operator|<
name|getNumArgs
argument_list|()
operator|&&
literal|"Template argument out of range"
argument_list|)
block|;
return|return
name|getArgs
argument_list|()
index|[
name|Idx
index|]
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

