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
file|"clang/AST/DeclObjC.h"
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
file|"clang/AST/DeclTemplate.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
define|#
directive|define
name|DISPATCH
parameter_list|(
name|NAME
parameter_list|,
name|CLASS
parameter_list|)
define|\
value|return static_cast<ImplClass*>(this)-> Visit##NAME(static_cast<CLASS*>(D))
comment|/// \brief A simple visitor class that helps create declaration visitors.
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
block|{
name|public
operator|:
name|RetTy
name|Visit
argument_list|(
argument|Decl *D
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
default|default:
name|llvm_unreachable
argument_list|(
literal|"Decl that isn't part of DeclNodes.inc!"
argument_list|)
expr_stmt|;
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
value|RetTy Visit##DERIVED##Decl(DERIVED##Decl *D) { DISPATCH(BASE, BASE); }
include|#
directive|include
file|"clang/AST/DeclNodes.inc"
name|RetTy
name|VisitDecl
argument_list|(
argument|Decl *D
argument_list|)
block|{
return|return
name|RetTy
argument_list|()
return|;
block|}
expr|}
block|;
undef|#
directive|undef
name|DISPATCH
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

