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
name|LLVM_CLANG_AST_OPENMP_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_OPENMP_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/DeclBase.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
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
range|:
name|public
name|Decl
block|{
name|friend
name|class
name|ASTDeclReader
block|;
name|unsigned
name|NumVars
block|;
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|OMPThreadPrivateDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|)
operator|:
name|Decl
argument_list|(
name|DK
argument_list|,
name|DC
argument_list|,
name|L
argument_list|)
block|,
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
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
specifier|const
name|Expr
operator|*
specifier|const
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
expr|,
name|NumVars
operator|)
return|;
block|}
name|llvm
operator|::
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
name|getVars
argument_list|()
block|{
return|return
name|llvm
operator|::
name|MutableArrayRef
operator|<
name|Expr
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
name|Expr
operator|*
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
expr|,
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
block|;
name|public
operator|:
specifier|static
name|OMPThreadPrivateDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|ArrayRef<Expr *> VL
argument_list|)
block|;
specifier|static
name|OMPThreadPrivateDecl
operator|*
name|CreateDeserialized
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned ID
argument_list|,
argument|unsigned N
argument_list|)
block|;
typedef|typedef
name|llvm
operator|::
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
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

