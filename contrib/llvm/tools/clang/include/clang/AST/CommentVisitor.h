begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CommentVisitor.h - Visitor for Comment subclasses ------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_AST_COMMENTVISITOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_COMMENTVISITOR_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Comment.h"
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
name|namespace
name|comments
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
name|CommentVisitorBase
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
value|return static_cast<ImplClass*>(this)->visit ## NAME(static_cast<PTR(CLASS)>(C))
name|RetTy
name|visit
argument_list|(
argument|PTR(Comment) C
argument_list|)
block|{
if|if
condition|(
operator|!
name|C
condition|)
return|return
name|RetTy
argument_list|()
return|;
switch|switch
condition|(
name|C
operator|->
name|getCommentKind
argument_list|()
condition|)
block|{
default|default:
name|llvm_unreachable
argument_list|(
literal|"Unknown comment kind!"
argument_list|)
expr_stmt|;
define|#
directive|define
name|ABSTRACT_COMMENT
parameter_list|(
name|COMMENT
parameter_list|)
define|#
directive|define
name|COMMENT
parameter_list|(
name|CLASS
parameter_list|,
name|PARENT
parameter_list|)
define|\
value|case Comment::CLASS##Kind: DISPATCH(CLASS, CLASS);
include|#
directive|include
file|"clang/AST/CommentNodes.inc"
undef|#
directive|undef
name|ABSTRACT_COMMENT
undef|#
directive|undef
name|COMMENT
block|}
block|}
comment|// If the derived class does not implement a certain Visit* method, fall back
comment|// on Visit* method for the superclass.
define|#
directive|define
name|ABSTRACT_COMMENT
parameter_list|(
name|COMMENT
parameter_list|)
value|COMMENT
define|#
directive|define
name|COMMENT
parameter_list|(
name|CLASS
parameter_list|,
name|PARENT
parameter_list|)
define|\
value|RetTy visit ## CLASS(PTR(CLASS) C) { DISPATCH(PARENT, PARENT); }
include|#
directive|include
file|"clang/AST/CommentNodes.inc"
undef|#
directive|undef
name|ABSTRACT_COMMENT
undef|#
directive|undef
name|COMMENT
name|RetTy
name|visitComment
argument_list|(
argument|PTR(Comment) C
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
block|}
empty_stmt|;
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
name|CommentVisitor
operator|:
name|public
name|CommentVisitorBase
operator|<
name|make_ptr
operator|,
name|ImplClass
operator|,
name|RetTy
operator|>
block|{}
expr_stmt|;
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
name|ConstCommentVisitor
operator|:
name|public
name|CommentVisitorBase
operator|<
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
comment|// end namespace comments
end_comment

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

