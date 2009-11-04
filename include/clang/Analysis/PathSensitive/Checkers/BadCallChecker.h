begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- BadCallChecker.h - Bad call checker --------------------*- C++ -*--==//
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
comment|// This defines BadCallChecker, a builtin check in GRExprEngine that performs
end_comment

begin_comment
comment|// checks for bad callee at call sites.
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
file|"clang/Analysis/PathSensitive/CheckerVisitor.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|BadCallChecker
range|:
name|public
name|CheckerVisitor
operator|<
name|BadCallChecker
operator|>
block|{
name|BuiltinBug
operator|*
name|BT
block|;
name|public
operator|:
name|BadCallChecker
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
name|void
name|PreVisitCallExpr
argument_list|(
name|CheckerContext
operator|&
name|C
argument_list|,
specifier|const
name|CallExpr
operator|*
name|CE
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

end_unit

