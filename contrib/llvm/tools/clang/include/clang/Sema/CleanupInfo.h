begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CleanupInfo.cpp - Cleanup Control in Sema ------------------------===//
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
comment|//  This file implements a set of operations on whether generating an
end_comment

begin_comment
comment|//  ExprWithCleanups in a full expression.
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
name|LLVM_CLANG_SEMA_CLEANUP_INFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_CLEANUP_INFO_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|CleanupInfo
block|{
name|bool
name|ExprNeedsCleanups
init|=
name|false
decl_stmt|;
name|bool
name|CleanupsHaveSideEffects
init|=
name|false
decl_stmt|;
name|public
label|:
name|bool
name|exprNeedsCleanups
argument_list|()
specifier|const
block|{
return|return
name|ExprNeedsCleanups
return|;
block|}
name|bool
name|cleanupsHaveSideEffects
argument_list|()
specifier|const
block|{
return|return
name|CleanupsHaveSideEffects
return|;
block|}
name|void
name|setExprNeedsCleanups
parameter_list|(
name|bool
name|SideEffects
parameter_list|)
block|{
name|ExprNeedsCleanups
operator|=
name|true
expr_stmt|;
name|CleanupsHaveSideEffects
operator||=
name|SideEffects
expr_stmt|;
block|}
name|void
name|reset
parameter_list|()
block|{
name|ExprNeedsCleanups
operator|=
name|false
expr_stmt|;
name|CleanupsHaveSideEffects
operator|=
name|false
expr_stmt|;
block|}
name|void
name|mergeFrom
parameter_list|(
name|CleanupInfo
name|Rhs
parameter_list|)
block|{
name|ExprNeedsCleanups
operator||=
name|Rhs
operator|.
name|ExprNeedsCleanups
expr_stmt|;
name|CleanupsHaveSideEffects
operator||=
name|Rhs
operator|.
name|CleanupsHaveSideEffects
expr_stmt|;
block|}
block|}
empty_stmt|;
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

