begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Utils.h - Misc utilities for the front-end -------------*- C++ -*-===//
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
comment|//  This header contains miscellaneous utilities for various front-end actions
end_comment

begin_comment
comment|//  which were split from Frontend to minimise Frontend's dependencies.
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
name|LLVM_CLANG_FRONTENDTOOL_UTILS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTENDTOOL_UTILS_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|CompilerInstance
decl_stmt|;
comment|/// ExecuteCompilerInvocation - Execute the given actions described by the
comment|/// compiler invocation object in the given compiler instance.
comment|///
comment|/// \return - True on success.
name|bool
name|ExecuteCompilerInvocation
parameter_list|(
name|CompilerInstance
modifier|*
name|Clang
parameter_list|)
function_decl|;
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

