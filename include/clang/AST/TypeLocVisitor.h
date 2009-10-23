begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- TypeLocVisitor.h - Visitor for TypeLoc subclasses ------*- C++ -*-===//
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
comment|//  This file defines the TypeLocVisitor interface.
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
name|LLVM_CLANG_AST_TYPELOCVISITOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_TYPELOCVISITOR_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/TypeLoc.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/TypeVisitor.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
define|#
directive|define
name|DISPATCH
parameter_list|(
name|CLASSNAME
parameter_list|)
define|\
value|return static_cast<ImplClass*>(this)-> \     Visit##CLASSNAME(cast<CLASSNAME>(TyLoc))
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
name|TypeLocVisitor
block|{
name|public
operator|:
name|RetTy
name|Visit
argument_list|(
argument|TypeLoc TyLoc
argument_list|)
block|{
switch|switch
condition|(
name|TyLoc
operator|.
name|getTypeLocClass
argument_list|()
condition|)
block|{
define|#
directive|define
name|ABSTRACT_TYPELOC
parameter_list|(
name|CLASS
parameter_list|,
name|PARENT
parameter_list|)
define|#
directive|define
name|TYPELOC
parameter_list|(
name|CLASS
parameter_list|,
name|PARENT
parameter_list|)
define|\
value|case TypeLoc::CLASS: DISPATCH(CLASS##TypeLoc);
include|#
directive|include
file|"clang/AST/TypeLocNodes.def"
block|}
name|llvm
operator|::
name|llvm_unreachable
argument_list|(
literal|"unexpected type loc class!"
argument_list|)
expr_stmt|;
block|}
name|RetTy
name|Visit
argument_list|(
argument|UnqualTypeLoc TyLoc
argument_list|)
block|{
switch|switch
condition|(
name|TyLoc
operator|.
name|getTypeLocClass
argument_list|()
condition|)
block|{
define|#
directive|define
name|ABSTRACT_TYPELOC
parameter_list|(
name|CLASS
parameter_list|,
name|PARENT
parameter_list|)
define|#
directive|define
name|TYPELOC
parameter_list|(
name|CLASS
parameter_list|,
name|PARENT
parameter_list|)
define|\
value|case TypeLoc::CLASS: DISPATCH(CLASS##TypeLoc);
include|#
directive|include
file|"clang/AST/TypeLocNodes.def"
block|}
block|}
define|#
directive|define
name|TYPELOC
parameter_list|(
name|CLASS
parameter_list|,
name|PARENT
parameter_list|)
define|\
value|RetTy Visit##CLASS##TypeLoc(CLASS##TypeLoc TyLoc) { \     DISPATCH(PARENT);               \   }
include|#
directive|include
file|"clang/AST/TypeLocNodes.def"
name|RetTy
name|VisitTypeLoc
argument_list|(
argument|TypeLoc TyLoc
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
comment|// LLVM_CLANG_AST_TYPELOCVISITOR_H
end_comment

end_unit

