begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- TypeVisitor.h - Visitor for Stmt subclasses ------------*- C++ -*-===//
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
comment|//  This file defines the TypeVisitor interface.
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
name|LLVM_CLANG_AST_TYPEVISITOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_TYPEVISITOR_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
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
value|return static_cast<ImplClass*>(this)->Visit ## CLASS(static_cast<CLASS*>(T))
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
name|TypeVisitor
block|{
name|public
operator|:
name|RetTy
name|Visit
argument_list|(
argument|Type *T
argument_list|)
block|{
comment|// Top switch stmt: dispatch to VisitFooStmt for each FooStmt.
switch|switch
condition|(
name|T
operator|->
name|getTypeClass
argument_list|()
condition|)
block|{
default|default:
name|assert
argument_list|(
literal|0
operator|&&
literal|"Unknown type class!"
argument_list|)
expr_stmt|;
define|#
directive|define
name|ABSTRACT_TYPE
parameter_list|(
name|CLASS
parameter_list|,
name|PARENT
parameter_list|)
define|#
directive|define
name|TYPE
parameter_list|(
name|CLASS
parameter_list|,
name|PARENT
parameter_list|)
value|case Type::CLASS: DISPATCH(CLASS##Type);
include|#
directive|include
file|"clang/AST/TypeNodes.def"
block|}
block|}
comment|// If the implementation chooses not to implement a certain visit method, fall
comment|// back on superclass.
define|#
directive|define
name|TYPE
parameter_list|(
name|CLASS
parameter_list|,
name|PARENT
parameter_list|)
value|RetTy Visit##CLASS##Type(CLASS##Type *T) {       \   DISPATCH(PARENT);                                                          \ }
include|#
directive|include
file|"clang/AST/TypeNodes.def"
comment|// Base case, ignore it. :)
name|RetTy
name|VisitType
argument_list|(
argument|Type*
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

end_unit

