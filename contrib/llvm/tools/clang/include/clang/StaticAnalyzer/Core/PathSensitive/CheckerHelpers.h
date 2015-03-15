begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//== CheckerHelpers.h - Helper functions for checkers ------------*- C++ -*--=//
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
comment|//  This file defines CheckerVisitor.
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
name|LLVM_CLANG_STATICANALYZER_CORE_PATHSENSITIVE_CHECKERHELPERS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_STATICANALYZER_CORE_PATHSENSITIVE_CHECKERHELPERS_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Stmt.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ento
block|{
name|bool
name|containsMacro
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|)
function_decl|;
name|bool
name|containsEnum
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|)
function_decl|;
name|bool
name|containsStaticLocal
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|)
function_decl|;
name|bool
name|containsBuiltinOffsetOf
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|)
function_decl|;
name|template
operator|<
name|class
name|T
operator|>
name|bool
name|containsStmt
argument_list|(
argument|const Stmt *S
argument_list|)
block|{
if|if
condition|(
name|isa
operator|<
name|T
operator|>
operator|(
name|S
operator|)
condition|)
return|return
name|true
return|;
for|for
control|(
name|Stmt
operator|::
name|const_child_range
name|I
operator|=
name|S
operator|->
name|children
argument_list|()
init|;
name|I
condition|;
operator|++
name|I
control|)
if|if
condition|(
specifier|const
name|Stmt
modifier|*
name|child
init|=
operator|*
name|I
condition|)
if|if
condition|(
name|containsStmt
operator|<
name|T
operator|>
operator|(
name|child
operator|)
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// end GR namespace
end_comment

begin_comment
unit|}
comment|// end clang namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

