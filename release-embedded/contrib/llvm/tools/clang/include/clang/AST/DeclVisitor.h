begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- DeclVisitor.h - Visitor for Decl subclasses ------------*- C++ -*-===//
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
comment|//  This file defines the DeclVisitor interface.
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
name|LLVM_CLANG_AST_DECLVISITOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_DECLVISITOR_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Decl.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclCXX.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclFriend.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclObjC.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclOpenMP.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclTemplate.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|declvisitor
block|{
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|make_ptr
block|{
typedef|typedef
name|T
modifier|*
name|type
typedef|;
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|make_const_ptr
block|{
typedef|typedef
specifier|const
name|T
modifier|*
name|type
typedef|;
block|}
empty_stmt|;
comment|/// \brief A simple visitor class that helps create declaration visitors.
name|template
operator|<
name|template
operator|<
name|typename
operator|>
name|class
name|Ptr
operator|,
name|typename
name|ImplClass
operator|,
name|typename
name|RetTy
operator|=
name|void
operator|>
name|class
name|Base
block|{
name|public
operator|:
define|#
directive|define
name|PTR
parameter_list|(
name|CLASS
parameter_list|)
value|typename Ptr<CLASS>::type
define|#
directive|define
name|DISPATCH
parameter_list|(
name|NAME
parameter_list|,
name|CLASS
parameter_list|)
define|\
value|return static_cast<ImplClass*>(this)->Visit##NAME(static_cast<PTR(CLASS)>(D))
name|RetTy
name|Visit
argument_list|(
argument|PTR(Decl) D
argument_list|)
block|{
switch|switch
condition|(
name|D
operator|->
name|getKind
argument_list|()
condition|)
block|{
define|#
directive|define
name|DECL
parameter_list|(
name|DERIVED
parameter_list|,
name|BASE
parameter_list|)
define|\
value|case Decl::DERIVED: DISPATCH(DERIVED##Decl, DERIVED##Decl);
define|#
directive|define
name|ABSTRACT_DECL
parameter_list|(
name|DECL
parameter_list|)
include|#
directive|include
file|"clang/AST/DeclNodes.inc"
block|}
name|llvm_unreachable
argument_list|(
literal|"Decl that isn't part of DeclNodes.inc!"
argument_list|)
expr_stmt|;
block|}
comment|// If the implementation chooses not to implement a certain visit
comment|// method, fall back to the parent.
define|#
directive|define
name|DECL
parameter_list|(
name|DERIVED
parameter_list|,
name|BASE
parameter_list|)
define|\
value|RetTy Visit##DERIVED##Decl(PTR(DERIVED##Decl) D) { DISPATCH(BASE, BASE); }
include|#
directive|include
file|"clang/AST/DeclNodes.inc"
name|RetTy
name|VisitDecl
argument_list|(
argument|PTR(Decl) D
argument_list|)
block|{
return|return
name|RetTy
argument_list|()
return|;
block|}
undef|#
directive|undef
name|PTR
undef|#
directive|undef
name|DISPATCH
expr|}
block|;  }
comment|// end namespace declvisitor
comment|/// \brief A simple visitor class that helps create declaration visitors.
comment|///
comment|/// This class does not preserve constness of Decl pointers (see also
comment|/// ConstDeclVisitor).
name|template
operator|<
name|typename
name|ImplClass
operator|,
name|typename
name|RetTy
operator|=
name|void
operator|>
name|class
name|DeclVisitor
operator|:
name|public
name|declvisitor
operator|::
name|Base
operator|<
name|declvisitor
operator|::
name|make_ptr
operator|,
name|ImplClass
operator|,
name|RetTy
operator|>
block|{}
expr_stmt|;
comment|/// \brief A simple visitor class that helps create declaration visitors.
comment|///
comment|/// This class preserves constness of Decl pointers (see also DeclVisitor).
name|template
operator|<
name|typename
name|ImplClass
operator|,
name|typename
name|RetTy
operator|=
name|void
operator|>
name|class
name|ConstDeclVisitor
operator|:
name|public
name|declvisitor
operator|::
name|Base
operator|<
name|declvisitor
operator|::
name|make_const_ptr
operator|,
name|ImplClass
operator|,
name|RetTy
operator|>
block|{}
expr_stmt|;
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
comment|// LLVM_CLANG_AST_DECLVISITOR_H
end_comment

end_unit

