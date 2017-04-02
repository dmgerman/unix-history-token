begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DeclOpenMP.h - Classes for representing OpenMP directives -*- C++ -*-===//
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
comment|/// \brief This file defines OpenMP nodes for declarative directives.
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
name|LLVM_CLANG_AST_DECLOPENMP_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_DECLOPENMP_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Decl.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Expr.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/ExternalASTSource.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/TrailingObjects.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief This represents '#pragma omp threadprivate ...' directive.
comment|/// For example, in the following, both 'a' and 'A::b' are threadprivate:
comment|///
comment|/// \code
comment|/// int a;
comment|/// #pragma omp threadprivate(a)
comment|/// struct A {
comment|///   static int b;
comment|/// #pragma omp threadprivate(b)
comment|/// };
comment|/// \endcode
comment|///
name|class
name|OMPThreadPrivateDecl
name|final
range|:
name|public
name|Decl
decl_stmt|,
name|private
name|llvm
decl|::
name|TrailingObjects
decl|<
name|OMPThreadPrivateDecl
decl_stmt|,
name|Expr
modifier|*
decl|>
block|{
name|friend
name|class
name|ASTDeclReader
decl_stmt|;
name|friend
name|TrailingObjects
decl_stmt|;
name|unsigned
name|NumVars
decl_stmt|;
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|OMPThreadPrivateDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|)
block|:
name|Decl
argument_list|(
name|DK
argument_list|,
name|DC
argument_list|,
name|L
argument_list|)
operator|,
name|NumVars
argument_list|(
literal|0
argument_list|)
block|{ }
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|getVars
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|getTrailingObjects
operator|<
name|Expr
operator|*
operator|>
operator|(
operator|)
argument_list|,
name|NumVars
argument_list|)
return|;
block|}
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
name|getVars
argument_list|()
block|{
return|return
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|(
name|getTrailingObjects
operator|<
name|Expr
operator|*
operator|>
operator|(
operator|)
operator|,
name|NumVars
operator|)
return|;
block|}
name|void
name|setVars
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|VL
argument_list|)
decl_stmt|;
name|public
label|:
specifier|static
name|OMPThreadPrivateDecl
modifier|*
name|Create
argument_list|(
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
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|VL
argument_list|)
decl_stmt|;
specifier|static
name|OMPThreadPrivateDecl
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
name|N
parameter_list|)
function_decl|;
typedef|typedef
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|::
name|iterator
name|varlist_iterator
expr_stmt|;
typedef|typedef
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
operator|::
name|iterator
name|varlist_const_iterator
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|varlist_iterator
operator|>
name|varlist_range
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|varlist_const_iterator
operator|>
name|varlist_const_range
expr_stmt|;
name|unsigned
name|varlist_size
argument_list|()
specifier|const
block|{
return|return
name|NumVars
return|;
block|}
name|bool
name|varlist_empty
argument_list|()
specifier|const
block|{
return|return
name|NumVars
operator|==
literal|0
return|;
block|}
name|varlist_range
name|varlists
parameter_list|()
block|{
return|return
name|varlist_range
argument_list|(
name|varlist_begin
argument_list|()
argument_list|,
name|varlist_end
argument_list|()
argument_list|)
return|;
block|}
name|varlist_const_range
name|varlists
argument_list|()
specifier|const
block|{
return|return
name|varlist_const_range
argument_list|(
name|varlist_begin
argument_list|()
argument_list|,
name|varlist_end
argument_list|()
argument_list|)
return|;
block|}
name|varlist_iterator
name|varlist_begin
parameter_list|()
block|{
return|return
name|getVars
argument_list|()
operator|.
name|begin
argument_list|()
return|;
block|}
name|varlist_iterator
name|varlist_end
parameter_list|()
block|{
return|return
name|getVars
argument_list|()
operator|.
name|end
argument_list|()
return|;
block|}
name|varlist_const_iterator
name|varlist_begin
argument_list|()
specifier|const
block|{
return|return
name|getVars
argument_list|()
operator|.
name|begin
argument_list|()
return|;
block|}
name|varlist_const_iterator
name|varlist_end
argument_list|()
specifier|const
block|{
return|return
name|getVars
argument_list|()
operator|.
name|end
argument_list|()
return|;
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
name|OMPThreadPrivate
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief This represents '#pragma omp declare reduction ...' directive.
comment|/// For example, in the following, declared reduction 'foo' for types 'int' and
comment|/// 'float':
comment|///
comment|/// \code
comment|/// #pragma omp declare reduction (foo : int,float : omp_out += omp_in) \
comment|///                     initializer (omp_priv = 0)
comment|/// \endcode
comment|///
comment|/// Here 'omp_out += omp_in' is a combiner and 'omp_priv = 0' is an initializer.
name|class
name|OMPDeclareReductionDecl
name|final
range|:
name|public
name|ValueDecl
decl_stmt|,
name|public
name|DeclContext
block|{
name|private
label|:
name|friend
name|class
name|ASTDeclReader
decl_stmt|;
comment|/// \brief Combiner for declare reduction construct.
name|Expr
modifier|*
name|Combiner
decl_stmt|;
comment|/// \brief Initializer for declare reduction construct.
name|Expr
modifier|*
name|Initializer
decl_stmt|;
comment|/// \brief Reference to the previous declare reduction construct in the same
comment|/// scope with the same name. Required for proper templates instantiation if
comment|/// the declare reduction construct is declared inside compound statement.
name|LazyDeclPtr
name|PrevDeclInScope
decl_stmt|;
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|OMPDeclareReductionDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|DeclarationName Name
argument_list|,
argument|QualType Ty
argument_list|,
argument|OMPDeclareReductionDecl *PrevDeclInScope
argument_list|)
block|:
name|ValueDecl
argument_list|(
name|DK
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|Name
argument_list|,
name|Ty
argument_list|)
operator|,
name|DeclContext
argument_list|(
name|DK
argument_list|)
operator|,
name|Combiner
argument_list|(
name|nullptr
argument_list|)
operator|,
name|Initializer
argument_list|(
name|nullptr
argument_list|)
operator|,
name|PrevDeclInScope
argument_list|(
argument|PrevDeclInScope
argument_list|)
block|{}
name|void
name|setPrevDeclInScope
argument_list|(
argument|OMPDeclareReductionDecl *Prev
argument_list|)
block|{
name|PrevDeclInScope
operator|=
name|Prev
block|;   }
name|public
operator|:
comment|/// \brief Create declare reduction node.
specifier|static
name|OMPDeclareReductionDecl
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
argument|QualType T
argument_list|,
argument|OMPDeclareReductionDecl *PrevDeclInScope
argument_list|)
expr_stmt|;
comment|/// \brief Create deserialized declare reduction node.
specifier|static
name|OMPDeclareReductionDecl
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
comment|/// \brief Get combiner expression of the declare reduction construct.
name|Expr
modifier|*
name|getCombiner
parameter_list|()
block|{
return|return
name|Combiner
return|;
block|}
specifier|const
name|Expr
operator|*
name|getCombiner
argument_list|()
specifier|const
block|{
return|return
name|Combiner
return|;
block|}
comment|/// \brief Set combiner expression for the declare reduction construct.
name|void
name|setCombiner
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|)
block|{
name|Combiner
operator|=
name|E
expr_stmt|;
block|}
comment|/// \brief Get initializer expression (if specified) of the declare reduction
comment|/// construct.
name|Expr
modifier|*
name|getInitializer
parameter_list|()
block|{
return|return
name|Initializer
return|;
block|}
specifier|const
name|Expr
operator|*
name|getInitializer
argument_list|()
specifier|const
block|{
return|return
name|Initializer
return|;
block|}
comment|/// \brief Set initializer expression for the declare reduction construct.
name|void
name|setInitializer
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|)
block|{
name|Initializer
operator|=
name|E
expr_stmt|;
block|}
comment|/// \brief Get reference to previous declare reduction construct in the same
comment|/// scope with the same name.
name|OMPDeclareReductionDecl
modifier|*
name|getPrevDeclInScope
parameter_list|()
function_decl|;
specifier|const
name|OMPDeclareReductionDecl
operator|*
name|getPrevDeclInScope
argument_list|()
specifier|const
expr_stmt|;
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
name|OMPDeclareReduction
return|;
block|}
specifier|static
name|DeclContext
modifier|*
name|castToDeclContext
parameter_list|(
specifier|const
name|OMPDeclareReductionDecl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|static_cast
operator|<
name|DeclContext
operator|*
operator|>
operator|(
name|const_cast
operator|<
name|OMPDeclareReductionDecl
operator|*
operator|>
operator|(
name|D
operator|)
operator|)
return|;
block|}
specifier|static
name|OMPDeclareReductionDecl
modifier|*
name|castFromDeclContext
parameter_list|(
specifier|const
name|DeclContext
modifier|*
name|DC
parameter_list|)
block|{
return|return
name|static_cast
operator|<
name|OMPDeclareReductionDecl
operator|*
operator|>
operator|(
name|const_cast
operator|<
name|DeclContext
operator|*
operator|>
operator|(
name|DC
operator|)
operator|)
return|;
block|}
block|}
empty_stmt|;
comment|/// Pseudo declaration for capturing expressions. Also is used for capturing of
comment|/// non-static data members in non-static member functions.
comment|///
comment|/// Clang supports capturing of variables only, but OpenMP 4.5 allows to
comment|/// privatize non-static members of current class in non-static member
comment|/// functions. This pseudo-declaration allows properly handle this kind of
comment|/// capture by wrapping captured expression into a variable-like declaration.
name|class
name|OMPCapturedExprDecl
name|final
range|:
name|public
name|VarDecl
block|{
name|friend
name|class
name|ASTDeclReader
block|;
name|void
name|anchor
argument_list|()
name|override
block|;
name|OMPCapturedExprDecl
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType Type
argument_list|,
argument|SourceLocation StartLoc
argument_list|)
operator|:
name|VarDecl
argument_list|(
argument|OMPCapturedExpr
argument_list|,
argument|C
argument_list|,
argument|DC
argument_list|,
argument|StartLoc
argument_list|,
argument|SourceLocation()
argument_list|,
argument|Id
argument_list|,
argument|Type
argument_list|,
argument|nullptr
argument_list|,
argument|SC_None
argument_list|)
block|{
name|setImplicit
argument_list|()
block|;   }
name|public
operator|:
specifier|static
name|OMPCapturedExprDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|,
argument|SourceLocation StartLoc
argument_list|)
block|;
specifier|static
name|OMPCapturedExprDecl
operator|*
name|CreateDeserialized
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned ID
argument_list|)
block|;
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|override
name|LLVM_READONLY
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
name|OMPCapturedExpr
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

