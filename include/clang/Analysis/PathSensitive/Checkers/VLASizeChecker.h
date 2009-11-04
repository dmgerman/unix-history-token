begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=== VLASizeChecker.h - Undefined dereference checker ----------*- C++ -*-===//
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
comment|// This defines two VLASizeCheckers, a builtin check in GRExprEngine that
end_comment

begin_comment
comment|// performs checks for declaration of VLA of undefined or zero size.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_include
include|#
directive|include
file|"clang/Analysis/PathSensitive/Checker.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|UndefSizedVLAChecker
range|:
name|public
name|Checker
block|{
name|BugType
operator|*
name|BT
block|;
name|public
operator|:
name|UndefSizedVLAChecker
argument_list|()
operator|:
name|BT
argument_list|(
literal|0
argument_list|)
block|{}
specifier|static
name|void
operator|*
name|getTag
argument_list|()
block|;
name|ExplodedNode
operator|*
name|CheckType
argument_list|(
argument|QualType T
argument_list|,
argument|ExplodedNode *Pred
argument_list|,
argument|const GRState *state
argument_list|,
argument|Stmt *S
argument_list|,
argument|GRExprEngine&Eng
argument_list|)
block|; }
decl_stmt|;
name|class
name|ZeroSizedVLAChecker
range|:
name|public
name|Checker
block|{
name|BugType
operator|*
name|BT
block|;
name|public
operator|:
name|ZeroSizedVLAChecker
argument_list|()
operator|:
name|BT
argument_list|(
literal|0
argument_list|)
block|{}
specifier|static
name|void
operator|*
name|getTag
argument_list|()
block|;
name|ExplodedNode
operator|*
name|CheckType
argument_list|(
argument|QualType T
argument_list|,
argument|ExplodedNode *Pred
argument_list|,
argument|const GRState *state
argument_list|,
argument|Stmt *S
argument_list|,
argument|GRExprEngine&Eng
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

end_unit

