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
file|"clang/AST/TemplateName.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

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
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/TrailingObjects.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|FoldingSetNodeID
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
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
name|class
name|ValueDecl
decl_stmt|;
comment|/// \brief Represents a template argument.
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
comment|/// The template argument is a type.
name|Type
block|,
comment|/// The template argument is a declaration that was provided for a pointer,
comment|/// reference, or pointer to member non-type template parameter.
name|Declaration
block|,
comment|/// The template argument is a null pointer or null pointer to member that
comment|/// was provided for a non-type template parameter.
name|NullPtr
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
comment|/// The template argument is an expression, and we've not resolved it to one
comment|/// of the other forms yet, either because it's dependent or because we're
comment|/// representing a non-canonical template argument (for instance, in a
comment|/// TemplateSpecializationType). Also used to represent a non-dependent
comment|/// __uuidof expression (a Microsoft extension).
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
struct|struct
name|DA
block|{
name|unsigned
name|Kind
decl_stmt|;
name|void
modifier|*
name|QT
decl_stmt|;
name|ValueDecl
modifier|*
name|D
decl_stmt|;
block|}
struct|;
struct|struct
name|I
block|{
name|unsigned
name|Kind
decl_stmt|;
comment|// We store a decomposed APSInt with the data allocated by ASTContext if
comment|// BitWidth> 64. The memory may be shared between multiple
comment|// TemplateArgument instances.
name|unsigned
name|BitWidth
range|:
literal|31
decl_stmt|;
name|unsigned
name|IsUnsigned
range|:
literal|1
decl_stmt|;
union|union
block|{
name|uint64_t
name|VAL
decl_stmt|;
comment|///< Used to store the<= 64 bits integer value.
specifier|const
name|uint64_t
modifier|*
name|pVal
decl_stmt|;
comment|///< Used to store the>64 bits integer value.
block|}
union|;
name|void
modifier|*
name|Type
decl_stmt|;
block|}
struct|;
struct|struct
name|A
block|{
name|unsigned
name|Kind
decl_stmt|;
name|unsigned
name|NumArgs
decl_stmt|;
specifier|const
name|TemplateArgument
modifier|*
name|Args
decl_stmt|;
block|}
struct|;
struct|struct
name|TA
block|{
name|unsigned
name|Kind
decl_stmt|;
name|unsigned
name|NumExpansions
decl_stmt|;
name|void
modifier|*
name|Name
decl_stmt|;
block|}
struct|;
struct|struct
name|TV
block|{
name|unsigned
name|Kind
decl_stmt|;
name|uintptr_t
name|V
decl_stmt|;
block|}
struct|;
union|union
block|{
name|struct
name|DA
name|DeclArg
decl_stmt|;
name|struct
name|I
name|Integer
decl_stmt|;
name|struct
name|A
name|Args
decl_stmt|;
name|struct
name|TA
name|TemplateArg
decl_stmt|;
name|struct
name|TV
name|TypeOrValue
decl_stmt|;
block|}
union|;
name|TemplateArgument
argument_list|(
name|TemplateName
argument_list|,
name|bool
argument_list|)
operator|=
name|delete
expr_stmt|;
name|public
label|:
comment|/// \brief Construct an empty, invalid template argument.
name|constexpr
name|TemplateArgument
argument_list|()
operator|:
name|TypeOrValue
argument_list|(
argument|{Null
argument_list|,
literal|0
argument|}
argument_list|)
block|{}
comment|/// \brief Construct a template type argument.
name|TemplateArgument
argument_list|(
argument|QualType T
argument_list|,
argument|bool isNullPtr = false
argument_list|)
block|{
name|TypeOrValue
operator|.
name|Kind
operator|=
name|isNullPtr
operator|?
name|NullPtr
operator|:
name|Type
block|;
name|TypeOrValue
operator|.
name|V
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
argument|ValueDecl *D
argument_list|,
argument|QualType QT
argument_list|)
block|{
name|assert
argument_list|(
name|D
operator|&&
literal|"Expected decl"
argument_list|)
block|;
name|DeclArg
operator|.
name|Kind
operator|=
name|Declaration
block|;
name|DeclArg
operator|.
name|QT
operator|=
name|QT
operator|.
name|getAsOpaquePtr
argument_list|()
block|;
name|DeclArg
operator|.
name|D
operator|=
name|D
block|;   }
comment|/// \brief Construct an integral constant template argument. The memory to
comment|/// store the value is allocated with Ctx.
name|TemplateArgument
argument_list|(
argument|ASTContext&Ctx
argument_list|,
argument|const llvm::APSInt&Value
argument_list|,
argument|QualType Type
argument_list|)
expr_stmt|;
comment|/// \brief Construct an integral constant template argument with the same
comment|/// value as Other but a different type.
name|TemplateArgument
argument_list|(
argument|const TemplateArgument&Other
argument_list|,
argument|QualType Type
argument_list|)
block|{
name|Integer
operator|=
name|Other
operator|.
name|Integer
expr_stmt|;
name|Integer
operator|.
name|Type
operator|=
name|Type
operator|.
name|getAsOpaquePtr
argument_list|()
expr_stmt|;
block|}
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
block|{
name|TemplateArg
operator|.
name|Kind
operator|=
name|Template
expr_stmt|;
name|TemplateArg
operator|.
name|Name
operator|=
name|Name
operator|.
name|getAsVoidPointer
argument_list|()
expr_stmt|;
name|TemplateArg
operator|.
name|NumExpansions
operator|=
literal|0
expr_stmt|;
block|}
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
argument|Optional<unsigned> NumExpansions
argument_list|)
block|{
name|TemplateArg
operator|.
name|Kind
operator|=
name|TemplateExpansion
expr_stmt|;
name|TemplateArg
operator|.
name|Name
operator|=
name|Name
operator|.
name|getAsVoidPointer
argument_list|()
expr_stmt|;
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
argument|Expr *E
argument_list|)
block|{
name|TypeOrValue
operator|.
name|Kind
operator|=
name|Expression
expr_stmt|;
name|TypeOrValue
operator|.
name|V
operator|=
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|E
operator|)
expr_stmt|;
block|}
comment|/// \brief Construct a template argument that is a template argument pack.
comment|///
comment|/// We assume that storage for the template arguments provided
comment|/// outlives the TemplateArgument itself.
name|explicit
name|TemplateArgument
argument_list|(
name|ArrayRef
operator|<
name|TemplateArgument
operator|>
name|Args
argument_list|)
block|{
name|this
operator|->
name|Args
operator|.
name|Kind
operator|=
name|Pack
expr_stmt|;
name|this
operator|->
name|Args
operator|.
name|Args
operator|=
name|Args
operator|.
name|data
argument_list|()
expr_stmt|;
name|this
operator|->
name|Args
operator|.
name|NumArgs
operator|=
name|Args
operator|.
name|size
argument_list|()
expr_stmt|;
block|}
specifier|static
name|TemplateArgument
name|getEmptyPack
parameter_list|()
block|{
return|return
name|TemplateArgument
argument_list|(
name|None
argument_list|)
return|;
block|}
comment|/// \brief Create a new template argument pack by copying the given set of
comment|/// template arguments.
specifier|static
name|TemplateArgument
name|CreatePackCopy
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
name|TypeOrValue
operator|.
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
name|getKind
argument_list|()
operator|==
name|Null
return|;
block|}
comment|/// \brief Whether this template argument is dependent on a template
comment|/// parameter such that its result can change from one instantiation to
comment|/// another.
name|bool
name|isDependent
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Whether this template argument is dependent on a template
comment|/// parameter.
name|bool
name|isInstantiationDependent
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
comment|/// \brief Retrieve the type for a type template argument.
name|QualType
name|getAsType
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getKind
argument_list|()
operator|==
name|Type
operator|&&
literal|"Unexpected kind"
argument_list|)
block|;
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
operator|.
name|V
operator|)
argument_list|)
return|;
block|}
comment|/// \brief Retrieve the declaration for a declaration non-type
comment|/// template argument.
name|ValueDecl
operator|*
name|getAsDecl
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getKind
argument_list|()
operator|==
name|Declaration
operator|&&
literal|"Unexpected kind"
argument_list|)
block|;
return|return
name|DeclArg
operator|.
name|D
return|;
block|}
name|QualType
name|getParamTypeForDecl
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getKind
argument_list|()
operator|==
name|Declaration
operator|&&
literal|"Unexpected kind"
argument_list|)
block|;
return|return
name|QualType
operator|::
name|getFromOpaquePtr
argument_list|(
name|DeclArg
operator|.
name|QT
argument_list|)
return|;
block|}
comment|/// \brief Retrieve the type for null non-type template argument.
name|QualType
name|getNullPtrType
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getKind
argument_list|()
operator|==
name|NullPtr
operator|&&
literal|"Unexpected kind"
argument_list|)
block|;
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
operator|.
name|V
operator|)
argument_list|)
return|;
block|}
comment|/// \brief Retrieve the template name for a template name argument.
name|TemplateName
name|getAsTemplate
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getKind
argument_list|()
operator|==
name|Template
operator|&&
literal|"Unexpected kind"
argument_list|)
block|;
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
block|}
comment|/// \brief Retrieve the template argument as a template name; if the argument
comment|/// is a pack expansion, return the pattern as a template name.
name|TemplateName
name|getAsTemplateOrTemplatePattern
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|getKind
argument_list|()
operator|==
name|Template
operator|||
name|getKind
argument_list|()
operator|==
name|TemplateExpansion
operator|)
operator|&&
literal|"Unexpected kind"
argument_list|)
block|;
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
block|}
comment|/// \brief Retrieve the number of expansions that a template template argument
comment|/// expansion will produce, if known.
name|Optional
operator|<
name|unsigned
operator|>
name|getNumTemplateExpansions
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Retrieve the template argument as an integral value.
comment|// FIXME: Provide a way to read the integral data without copying the value.
name|llvm
operator|::
name|APSInt
name|getAsIntegral
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getKind
argument_list|()
operator|==
name|Integral
operator|&&
literal|"Unexpected kind"
argument_list|)
block|;
name|using
name|namespace
name|llvm
block|;
if|if
condition|(
name|Integer
operator|.
name|BitWidth
operator|<=
literal|64
condition|)
return|return
name|APSInt
argument_list|(
name|APInt
argument_list|(
name|Integer
operator|.
name|BitWidth
argument_list|,
name|Integer
operator|.
name|VAL
argument_list|)
argument_list|,
name|Integer
operator|.
name|IsUnsigned
argument_list|)
return|;
name|unsigned
name|NumWords
operator|=
name|APInt
operator|::
name|getNumWords
argument_list|(
name|Integer
operator|.
name|BitWidth
argument_list|)
expr_stmt|;
return|return
name|APSInt
argument_list|(
name|APInt
argument_list|(
name|Integer
operator|.
name|BitWidth
argument_list|,
name|makeArrayRef
argument_list|(
name|Integer
operator|.
name|pVal
argument_list|,
name|NumWords
argument_list|)
argument_list|)
argument_list|,
name|Integer
operator|.
name|IsUnsigned
argument_list|)
return|;
block|}
comment|/// \brief Retrieve the type of the integral value.
name|QualType
name|getIntegralType
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getKind
argument_list|()
operator|==
name|Integral
operator|&&
literal|"Unexpected kind"
argument_list|)
block|;
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
block|}
name|void
name|setIntegralType
parameter_list|(
name|QualType
name|T
parameter_list|)
block|{
name|assert
argument_list|(
name|getKind
argument_list|()
operator|==
name|Integral
operator|&&
literal|"Unexpected kind"
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
comment|/// \brief If this is a non-type template argument, get its type. Otherwise,
comment|/// returns a null QualType.
name|QualType
name|getNonTypeTemplateArgumentType
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Retrieve the template argument as an expression.
name|Expr
operator|*
name|getAsExpr
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getKind
argument_list|()
operator|==
name|Expression
operator|&&
literal|"Unexpected kind"
argument_list|)
block|;
return|return
name|reinterpret_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
name|TypeOrValue
operator|.
name|V
operator|)
return|;
block|}
comment|/// \brief Iterator that traverses the elements of a template argument pack.
typedef|typedef
specifier|const
name|TemplateArgument
modifier|*
name|pack_iterator
typedef|;
comment|/// \brief Iterator referencing the first argument of a template argument
comment|/// pack.
name|pack_iterator
name|pack_begin
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getKind
argument_list|()
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
comment|/// \brief Iterator referencing one past the last argument of a template
comment|/// argument pack.
name|pack_iterator
name|pack_end
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getKind
argument_list|()
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
comment|/// \brief Iterator range referencing all of the elements of a template
comment|/// argument pack.
name|ArrayRef
operator|<
name|TemplateArgument
operator|>
name|pack_elements
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|pack_begin
argument_list|()
argument_list|,
name|pack_end
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief The number of template arguments in the given template argument
comment|/// pack.
name|unsigned
name|pack_size
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getKind
argument_list|()
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
comment|/// \brief Return the array of arguments in this template argument pack.
name|ArrayRef
operator|<
name|TemplateArgument
operator|>
name|getPackAsArray
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getKind
argument_list|()
operator|==
name|Pack
argument_list|)
block|;
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|Args
operator|.
name|Args
argument_list|,
name|Args
operator|.
name|NumArgs
argument_list|)
return|;
block|}
comment|/// \brief Determines whether two template arguments are superficially the
comment|/// same.
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
comment|/// \brief When the template argument is a pack expansion, returns
comment|/// the pattern of the pack expansion.
name|TemplateArgument
name|getPackExpansionPattern
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Print this template argument to the given output stream.
name|void
name|print
argument_list|(
specifier|const
name|PrintingPolicy
operator|&
name|Policy
argument_list|,
name|raw_ostream
operator|&
name|Out
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Debugging aid that dumps the template argument.
name|void
name|dump
argument_list|(
name|raw_ostream
operator|&
name|Out
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Debugging aid that dumps the template argument to standard error.
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Used to insert TemplateArguments into FoldingSets.
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
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// Location information for a TemplateArgument.
end_comment

begin_struct
struct|struct
name|TemplateArgumentLocInfo
block|{
name|private
label|:
struct|struct
name|T
block|{
comment|// FIXME: We'd like to just use the qualifier in the TemplateName,
comment|// but template arguments get canonicalized too quickly.
name|NestedNameSpecifier
modifier|*
name|Qualifier
decl_stmt|;
name|void
modifier|*
name|QualifierLocData
decl_stmt|;
name|unsigned
name|TemplateNameLoc
decl_stmt|;
name|unsigned
name|EllipsisLoc
decl_stmt|;
block|}
struct|;
union|union
block|{
name|struct
name|T
name|Template
decl_stmt|;
name|Expr
modifier|*
name|Expression
decl_stmt|;
name|TypeSourceInfo
modifier|*
name|Declarator
decl_stmt|;
block|}
union|;
name|public
label|:
name|constexpr
name|TemplateArgumentLocInfo
argument_list|()
operator|:
name|Template
argument_list|(
argument|{nullptr
argument_list|,
argument|nullptr
argument_list|,
literal|0
argument_list|,
literal|0
argument|}
argument_list|)
block|{}
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
argument|NestedNameSpecifierLoc QualifierLoc
argument_list|,
argument|SourceLocation TemplateNameLoc
argument_list|,
argument|SourceLocation EllipsisLoc
argument_list|)
block|{
name|Template
operator|.
name|Qualifier
operator|=
name|QualifierLoc
operator|.
name|getNestedNameSpecifier
argument_list|()
block|;
name|Template
operator|.
name|QualifierLocData
operator|=
name|QualifierLoc
operator|.
name|getOpaqueData
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
name|NestedNameSpecifierLoc
name|getTemplateQualifierLoc
argument_list|()
specifier|const
block|{
return|return
name|NestedNameSpecifierLoc
argument_list|(
name|Template
operator|.
name|Qualifier
argument_list|,
name|Template
operator|.
name|QualifierLocData
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
name|constexpr
name|TemplateArgumentLoc
parameter_list|()
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
argument|NestedNameSpecifierLoc QualifierLoc
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
argument|QualifierLoc
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
name|LLVM_READONLY
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
name|Expr
operator|*
name|getSourceNullPtrExpression
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
name|NullPtr
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
name|getSourceIntegralExpression
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
name|Integral
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
name|NestedNameSpecifierLoc
name|getTemplateQualifierLoc
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
name|getTemplateQualifierLoc
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
comment|// This can leak if used in an AST node, use ASTTemplateArgumentListInfo
comment|// instead.
name|void
modifier|*
name|operator
name|new
parameter_list|(
name|size_t
name|bytes
parameter_list|,
name|ASTContext
modifier|&
name|C
parameter_list|)
init|=
name|delete
function_decl|;
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
name|llvm
operator|::
name|ArrayRef
operator|<
name|TemplateArgumentLoc
operator|>
name|arguments
argument_list|()
specifier|const
block|{
return|return
name|Arguments
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
name|TemplateArgumentLoc
modifier|&
name|operator
function|[]
parameter_list|(
name|unsigned
name|I
parameter_list|)
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

begin_comment
comment|/// \brief Represents an explicit template argument list in C++, e.g.,
end_comment

begin_comment
comment|/// the "<int>" in "sort<int>".
end_comment

begin_comment
comment|/// This is safe to be used inside an AST node, in contrast with
end_comment

begin_comment
comment|/// TemplateArgumentListInfo.
end_comment

begin_decl_stmt
name|struct
name|ASTTemplateArgumentListInfo
name|final
range|:
name|private
name|llvm
operator|::
name|TrailingObjects
operator|<
name|ASTTemplateArgumentListInfo
decl_stmt|,
name|TemplateArgumentLoc
decl|>
block|{
name|private
label|:
name|friend
name|TrailingObjects
decl_stmt|;
name|friend
name|class
name|ASTNodeImporter
decl_stmt|;
name|ASTTemplateArgumentListInfo
argument_list|(
specifier|const
name|TemplateArgumentListInfo
operator|&
name|List
argument_list|)
expr_stmt|;
name|public
label|:
comment|/// \brief The source location of the left angle bracket ('<').
name|SourceLocation
name|LAngleLoc
decl_stmt|;
comment|/// \brief The source location of the right angle bracket ('>').
name|SourceLocation
name|RAngleLoc
decl_stmt|;
comment|/// \brief The number of template arguments in TemplateArgs.
name|unsigned
name|NumTemplateArgs
decl_stmt|;
comment|/// \brief Retrieve the template arguments
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
name|llvm
operator|::
name|ArrayRef
operator|<
name|TemplateArgumentLoc
operator|>
name|arguments
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|getTemplateArgs
argument_list|()
argument_list|,
name|NumTemplateArgs
argument_list|)
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
name|getTemplateArgs
argument_list|()
index|[
name|I
index|]
return|;
block|}
specifier|static
specifier|const
name|ASTTemplateArgumentListInfo
modifier|*
name|Create
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|&
name|List
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Represents an explicit template argument list in C++, e.g.,
end_comment

begin_comment
comment|/// the "<int>" in "sort<int>".
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// It is intended to be used as a trailing object on AST nodes, and
end_comment

begin_comment
comment|/// as such, doesn't contain the array of TemplateArgumentLoc itself,
end_comment

begin_comment
comment|/// but expects the containing object to also provide storage for
end_comment

begin_comment
comment|/// that.
end_comment

begin_struct
struct|struct
name|alignas
argument_list|(
argument|void *
argument_list|)
name|ASTTemplateKWAndArgsInfo
block|{
comment|/// \brief The source location of the left angle bracket ('<').
name|SourceLocation
name|LAngleLoc
decl_stmt|;
comment|/// \brief The source location of the right angle bracket ('>').
name|SourceLocation
name|RAngleLoc
decl_stmt|;
comment|/// \brief The source location of the template keyword; this is used
comment|/// as part of the representation of qualified identifiers, such as
comment|/// S<T>::template apply<T>.  Will be empty if this expression does
comment|/// not have a template keyword.
name|SourceLocation
name|TemplateKWLoc
decl_stmt|;
comment|/// \brief The number of template arguments in TemplateArgs.
name|unsigned
name|NumTemplateArgs
decl_stmt|;
name|void
name|initializeFrom
parameter_list|(
name|SourceLocation
name|TemplateKWLoc
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|&
name|List
parameter_list|,
name|TemplateArgumentLoc
modifier|*
name|OutArgArray
parameter_list|)
function_decl|;
name|void
name|initializeFrom
parameter_list|(
name|SourceLocation
name|TemplateKWLoc
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|&
name|List
parameter_list|,
name|TemplateArgumentLoc
modifier|*
name|OutArgArray
parameter_list|,
name|bool
modifier|&
name|Dependent
parameter_list|,
name|bool
modifier|&
name|InstantiationDependent
parameter_list|,
name|bool
modifier|&
name|ContainsUnexpandedParameterPack
parameter_list|)
function_decl|;
name|void
name|initializeFrom
parameter_list|(
name|SourceLocation
name|TemplateKWLoc
parameter_list|)
function_decl|;
name|void
name|copyInto
argument_list|(
specifier|const
name|TemplateArgumentLoc
operator|*
name|ArgArray
argument_list|,
name|TemplateArgumentListInfo
operator|&
name|List
argument_list|)
decl|const
decl_stmt|;
block|}
struct|;
end_struct

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

