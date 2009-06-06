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
argument|Decl **Params
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
name|Decl
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
name|Decl
modifier|*
modifier|*
name|iterator
typedef|;
comment|/// const_iterator - Iterates through the template parameters in this list.
typedef|typedef
name|Decl
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
name|Decl
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
name|Decl
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
specifier|const
name|Decl
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
comment|/// arguments.
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
comment|//===----------------------------------------------------------------------===//
comment|// Kinds of Templates
comment|//===----------------------------------------------------------------------===//
comment|/// TemplateDecl - The base class of all kinds of template declarations (e.g.,
comment|/// class, function, etc.). The TemplateDecl class stores the list of template
comment|/// parameters and a reference to the templated scoped declaration: the
comment|/// underlying AST node.
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
comment|/// Declaration of a template function.
name|class
name|FunctionTemplateDecl
range|:
name|public
name|TemplateDecl
block|{
name|protected
operator|:
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
argument|FunctionTemplate
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
block|{ }
name|public
operator|:
comment|/// Get the underling function declaration of the template.
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
argument|SourceLocation TSSL = SourceLocation()
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
name|VarDecl
operator|::
name|None
argument_list|,
name|TSSL
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
argument|SourceLocation TypeSpecStartLoc = SourceLocation()
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
comment|/// \brief Represents a template argument within a class template
comment|/// specialization.
name|class
name|TemplateArgument
block|{
expr|union
block|{
name|uintptr_t
name|TypeOrValue
block|;     struct
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
block|;
name|void
operator|*
name|Type
block|;     }
name|Integer
block|;   }
block|;
comment|/// \brief Location of the beginning of this template argument.
name|SourceLocation
name|StartLoc
block|;
name|public
operator|:
comment|/// \brief The type of template argument we're storing.
expr|enum
name|ArgKind
block|{
name|Null
operator|=
literal|0
block|,
comment|/// The template argument is a type. It's value is stored in the
comment|/// TypeOrValue field.
name|Type
operator|=
literal|1
block|,
comment|/// The template argument is a declaration
name|Declaration
operator|=
literal|2
block|,
comment|/// The template argument is an integral value stored in an llvm::APSInt.
name|Integral
operator|=
literal|3
block|,
comment|/// The template argument is a value- or type-dependent expression
comment|/// stored in an Expr*.
name|Expression
operator|=
literal|4
block|}
name|Kind
block|;
comment|/// \brief Construct an empty, invalid template argument.
name|TemplateArgument
argument_list|()
operator|:
name|TypeOrValue
argument_list|(
literal|0
argument_list|)
block|,
name|StartLoc
argument_list|()
block|,
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
block|;
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
block|;   }
name|TemplateArgument
operator|&
name|operator
operator|=
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
comment|/// \brief Return the kind of stored template argument.
name|ArgKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
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
comment|/// \brief Retrieve the template argument as a declaration.
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
block|}
comment|/// \brief Retrieve the template argument as an integral value.
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
block|}
specifier|const
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
comment|/// \brief Retrieve the type of the integral value.
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
empty_stmt|;
comment|/// \brief Retrieve the template argument as an expression.
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
block|}
end_decl_stmt

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
argument_list|)
expr_stmt|;
comment|// FIXME: Must be canonical!
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
comment|// FIXME: We need a canonical representation of expressions.
name|ID
operator|.
name|AddPointer
argument_list|(
name|getAsExpr
argument_list|()
argument_list|)
expr_stmt|;
break|break;
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
name|llvm
operator|::
name|SmallVector
operator|<
name|TemplateArgument
operator|,
literal|16
operator|>
name|Args
expr_stmt|;
name|ASTContext
modifier|&
name|Context
decl_stmt|;
name|public
label|:
name|TemplateArgumentListBuilder
argument_list|(
name|ASTContext
operator|&
name|Context
argument_list|)
operator|:
name|Context
argument_list|(
argument|Context
argument_list|)
block|{ }
comment|// FIXME: Should use the  index array size.
name|size_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|Args
operator|.
name|size
argument_list|()
return|;
block|}
name|size_t
name|flatSize
argument_list|()
specifier|const
block|{
return|return
name|Args
operator|.
name|size
argument_list|()
return|;
block|}
name|void
name|push_back
parameter_list|(
specifier|const
name|TemplateArgument
modifier|&
name|Arg
parameter_list|)
function_decl|;
name|TemplateArgument
modifier|*
name|getFlatArgumentList
parameter_list|()
block|{
return|return
name|Args
operator|.
name|data
argument_list|()
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
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
name|TemplateArgument
operator|*
operator|,
literal|1
operator|>
name|Arguments
expr_stmt|;
comment|/// \brief The number of template arguments in this template
comment|/// argument list.
name|unsigned
name|NumArguments
decl_stmt|;
name|public
label|:
name|TemplateArgumentList
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|TemplateArgumentListBuilder&Builder
argument_list|,
argument|bool CopyArgs
argument_list|,
argument|bool FlattenArgs
argument_list|)
empty_stmt|;
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
name|NumArguments
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
name|TemplateArgument
modifier|&
name|get
parameter_list|(
name|unsigned
name|Idx
parameter_list|)
block|{
name|assert
argument_list|(
name|Idx
operator|<
name|NumArguments
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
name|TemplateArgument
modifier|&
name|operator
function|[]
parameter_list|(
name|unsigned
name|Idx
parameter_list|)
block|{
return|return
name|get
argument_list|(
name|Idx
argument_list|)
return|;
block|}
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
name|NumArguments
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
name|NumArguments
return|;
block|}
comment|/// \brief Retrieve the flattened template argument list.
name|TemplateArgument
modifier|*
name|getFlatArgumentList
parameter_list|()
block|{
return|return
name|Arguments
operator|.
name|getPointer
argument_list|()
return|;
block|}
specifier|const
name|TemplateArgument
operator|*
name|getFlatArgumentList
argument_list|()
specifier|const
block|{
return|return
name|Arguments
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
comment|// \brief Describes the kind of template specialization that a
end_comment

begin_comment
comment|// particular template specialization declaration represents.
end_comment

begin_enum
enum|enum
name|TemplateSpecializationKind
block|{
comment|/// This template specialization was formed from a template-id but
comment|/// has not yet been declared, defined, or instantiated.
name|TSK_Undeclared
init|=
literal|0
block|,
comment|/// This template specialization was declared or defined by an
comment|/// explicit specialization (C++ [temp.expl.spec]) or partial
comment|/// specialization (C++ [temp.class.spec]).
name|TSK_ExplicitSpecialization
block|,
comment|/// This template specialization was implicitly instantiated from a
comment|/// template. (C++ [temp.inst]).
name|TSK_ImplicitInstantiation
block|,
comment|/// This template specialization was instantiated from a template
comment|/// due to an explicit instantiation request (C++ [temp.explicit]).
name|TSK_ExplicitInstantiation
block|}
enum|;
end_enum

begin_comment
comment|/// \brief Represents a class template specialization, which refers to
end_comment

begin_comment
comment|/// a class template with a given set of template arguments.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Class template specializations represent both explicit
end_comment

begin_comment
comment|/// specialization of class templates, as in the example below, and
end_comment

begin_comment
comment|/// implicit instantiations of class templates.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// template<typename T> class array;
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// template<>
end_comment

begin_comment
comment|/// class array<bool> { }; // class template specialization array<bool>
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_decl_stmt
name|class
name|ClassTemplateSpecializationDecl
range|:
name|public
name|CXXRecordDecl
decl_stmt|,
name|public
name|llvm
decl|::
name|FoldingSetNode
block|{
comment|/// \brief The template that this specialization specializes
name|ClassTemplateDecl
modifier|*
name|SpecializedTemplate
decl_stmt|;
comment|/// \brief The template arguments used to describe this specialization.
name|TemplateArgumentList
name|TemplateArgs
decl_stmt|;
comment|/// \brief The kind of specialization this declaration refers to.
comment|/// Really a value of type TemplateSpecializationKind.
name|unsigned
name|SpecializationKind
range|:
literal|2
decl_stmt|;
name|protected
label|:
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
argument_list|)
empty_stmt|;
name|public
label|:
specifier|static
name|ClassTemplateSpecializationDecl
modifier|*
name|Create
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|,
name|DeclContext
modifier|*
name|DC
parameter_list|,
name|SourceLocation
name|L
parameter_list|,
name|ClassTemplateDecl
modifier|*
name|SpecializedTemplate
parameter_list|,
name|TemplateArgumentListBuilder
modifier|&
name|Builder
parameter_list|,
name|ClassTemplateSpecializationDecl
modifier|*
name|PrevDecl
parameter_list|)
function_decl|;
comment|/// \brief Retrieve the template that this specialization specializes.
name|ClassTemplateDecl
operator|*
name|getSpecializedTemplate
argument_list|()
specifier|const
block|{
return|return
name|SpecializedTemplate
return|;
block|}
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
comment|/// \brief Sets the type of this specialization as it was written by
comment|/// the user. This will be a class template specialization type.
name|void
name|setTypeAsWritten
parameter_list|(
name|QualType
name|T
parameter_list|)
block|{
name|TypeForDecl
operator|=
name|T
operator|.
name|getTypePtr
argument_list|()
expr_stmt|;
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
decl|const
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
argument_list|)
expr_stmt|;
block|}
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
specifier|const
name|TemplateArgument
operator|*
name|TemplateArgs
argument_list|,
name|unsigned
name|NumTemplateArgs
argument_list|)
block|{
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
argument_list|)
expr_stmt|;
block|}
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
parameter_list|(
specifier|const
name|ClassTemplateSpecializationDecl
modifier|*
parameter_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|ClassTemplatePartialSpecializationDecl
modifier|*
parameter_list|)
block|{
return|return
name|true
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|ClassTemplatePartialSpecializationDecl
range|:
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
block|;   }
block|;
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
block|;  }
end_decl_stmt

begin_comment
comment|/* end of namespace clang */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

