begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- UndefinedAssignmentChecker.h ---------------------------*- C++ -*--==//
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
comment|// This defines UndefinedAssginmentChecker, a builtin check in GRExprEngine that
end_comment

begin_comment
comment|// checks for assigning undefined values.
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
name|LLVM_CLANG_UNDEFASSIGNMENTCHECKER
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_UNDEFASSIGNMENTCHECKER
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
name|UndefinedAssignmentChecker
range|:
name|public
name|CheckerVisitor
operator|<
name|UndefinedAssignmentChecker
operator|>
block|{
name|BugType
operator|*
name|BT
block|;
name|public
operator|:
name|UndefinedAssignmentChecker
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
name|virtual
name|void
name|PreVisitBind
argument_list|(
argument|CheckerContext&C
argument_list|,
argument|const Stmt *S
argument_list|,
argument|SVal location
argument_list|,
argument|SVal val
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

