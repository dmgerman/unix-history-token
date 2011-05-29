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
comment|// in ExprEngine that check for null and undefined pointers at loads
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
name|LLVM_CLANG_GR_DEREFCHECKER
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_GR_DEREFCHECKER
end_define

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ento
block|{
name|class
name|ExprEngine
decl_stmt|;
name|class
name|ExplodedNode
decl_stmt|;
name|std
operator|::
name|pair
operator|<
name|ExplodedNode
operator|*
specifier|const
operator|*
operator|,
name|ExplodedNode
operator|*
specifier|const
operator|*
operator|>
name|GetImplicitNullDereferences
argument_list|(
name|ExprEngine
operator|&
name|Eng
argument_list|)
expr_stmt|;
block|}
comment|// end GR namespace
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

