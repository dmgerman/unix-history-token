begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- UndefinedArgChecker.h - Undefined arguments checker ----*- C++ -*--==//
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
comment|// checks for undefined arguments.
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
name|LLVM_CLANG_UNDEFARGCHECKER
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_UNDEFARGCHECKER
end_define

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
name|UndefinedArgChecker
range|:
name|public
name|CheckerVisitor
operator|<
name|UndefinedArgChecker
operator|>
block|{
name|BugType
operator|*
name|BT
block|;
name|public
operator|:
name|UndefinedArgChecker
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

