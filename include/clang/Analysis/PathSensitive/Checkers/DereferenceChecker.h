begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//== NullDerefChecker.h - Null dereference checker --------------*- C++ -*--==//
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
comment|// This defines NullDerefChecker and UndefDerefChecker, two builtin checks
end_comment

begin_comment
comment|// in GRExprEngine that check for null and undefined pointers at loads
end_comment

begin_comment
comment|// and stores.
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
name|LLVM_CLANG_DEREFCHECKER
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_DEREFCHECKER
end_define

begin_include
include|#
directive|include
file|"clang/Analysis/PathSensitive/Checker.h"
end_include

begin_include
include|#
directive|include
file|"clang/Analysis/PathSensitive/BugType.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ExplodedNode
decl_stmt|;
name|class
name|NullDerefChecker
range|:
name|public
name|Checker
block|{
name|BuiltinBug
operator|*
name|BT
block|;
name|llvm
operator|::
name|SmallVector
operator|<
name|ExplodedNode
operator|*
block|,
literal|2
operator|>
name|ImplicitNullDerefNodes
block|;
name|public
operator|:
name|NullDerefChecker
argument_list|()
operator|:
name|BT
argument_list|(
literal|0
argument_list|)
block|{}
name|ExplodedNode
operator|*
name|CheckLocation
argument_list|(
argument|const Stmt *S
argument_list|,
argument|ExplodedNode *Pred
argument_list|,
argument|const GRState *state
argument_list|,
argument|SVal V
argument_list|,
argument|GRExprEngine&Eng
argument_list|)
block|;
specifier|static
name|void
operator|*
name|getTag
argument_list|()
block|;
typedef|typedef
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|ExplodedNode
operator|*
operator|>
operator|::
name|iterator
name|iterator
expr_stmt|;
name|iterator
name|implicit_nodes_begin
argument_list|()
block|{
return|return
name|ImplicitNullDerefNodes
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|implicit_nodes_end
argument_list|()
block|{
return|return
name|ImplicitNullDerefNodes
operator|.
name|end
argument_list|()
return|;
block|}
block|}
empty_stmt|;
name|class
name|UndefDerefChecker
range|:
name|public
name|Checker
block|{
name|BuiltinBug
operator|*
name|BT
block|;
name|public
operator|:
name|UndefDerefChecker
argument_list|()
operator|:
name|BT
argument_list|(
literal|0
argument_list|)
block|{}
name|ExplodedNode
operator|*
name|CheckLocation
argument_list|(
argument|const Stmt *S
argument_list|,
argument|ExplodedNode *Pred
argument_list|,
argument|const GRState *state
argument_list|,
argument|SVal V
argument_list|,
argument|GRExprEngine&Eng
argument_list|)
block|;
specifier|static
name|void
operator|*
name|getTag
argument_list|()
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end clang namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

