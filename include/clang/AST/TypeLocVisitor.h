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

begin_decl_stmt
name|namespace
name|clang
block|{
define|#
directive|define
name|DISPATCH
parameter_list|(
name|CLASS
parameter_list|)
define|\
value|return static_cast<ImplClass*>(this)->Visit ## CLASS(cast<CLASS>(TyLoc))
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
name|class
name|TypeDispatch
operator|:
name|public
name|TypeVisitor
operator|<
name|TypeDispatch
block|,
name|RetTy
operator|>
block|{
name|ImplClass
operator|*
name|Impl
block|;
name|TypeLoc
name|TyLoc
block|;
name|public
operator|:
name|TypeDispatch
argument_list|(
name|ImplClass
operator|*
name|impl
argument_list|,
name|TypeLoc
operator|&
name|tyLoc
argument_list|)
operator|:
name|Impl
argument_list|(
name|impl
argument_list|)
block|,
name|TyLoc
argument_list|(
argument|tyLoc
argument_list|)
block|{ }
define|#
directive|define
name|ABSTRACT_TYPELOC
parameter_list|(
name|CLASS
parameter_list|)
define|#
directive|define
name|TYPELOC
parameter_list|(
name|CLASS
parameter_list|,
name|PARENT
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|RetTy Visit##TYPE(TYPE *) {                                   \       return Impl->Visit##CLASS(reinterpret_cast<CLASS&>(TyLoc)); \     }
include|#
directive|include
file|"clang/AST/TypeLocNodes.def"
block|}
block|;
name|public
operator|:
name|RetTy
name|Visit
argument_list|(
argument|TypeLoc TyLoc
argument_list|)
block|{
name|TypeDispatch
name|TD
argument_list|(
name|static_cast
operator|<
name|ImplClass
operator|*
operator|>
operator|(
name|this
operator|)
argument_list|,
name|TyLoc
argument_list|)
block|;
return|return
name|TD
operator|.
name|Visit
argument_list|(
name|TyLoc
operator|.
name|getSourceType
argument_list|()
operator|.
name|getTypePtr
argument_list|()
argument_list|)
return|;
block|}
define|#
directive|define
name|TYPELOC
parameter_list|(
name|CLASS
parameter_list|,
name|PARENT
parameter_list|,
name|TYPE
parameter_list|)
value|RetTy Visit##CLASS(CLASS TyLoc) {       \   DISPATCH(PARENT);                                                          \ }
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

