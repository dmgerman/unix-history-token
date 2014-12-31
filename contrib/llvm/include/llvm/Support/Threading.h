begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Support/Threading.h - Control multithreading mode --*- C++ -*-===//
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
comment|// This file declares helper functions for running LLVM in a multi-threaded
end_comment

begin_comment
comment|// environment.
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
name|LLVM_SUPPORT_THREADING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_THREADING_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Returns true if LLVM is compiled with support for multi-threading, and
comment|/// false otherwise.
name|bool
name|llvm_is_multithreaded
parameter_list|()
function_decl|;
comment|/// llvm_execute_on_thread - Execute the given \p UserFn on a separate
comment|/// thread, passing it the provided \p UserData.
comment|///
comment|/// This function does not guarantee that the code will actually be executed
comment|/// on a separate thread or honoring the requested stack size, but tries to do
comment|/// so where system support is available.
comment|///
comment|/// \param UserFn - The callback to execute.
comment|/// \param UserData - An argument to pass to the callback function.
comment|/// \param RequestedStackSize - If non-zero, a requested size (in bytes) for
comment|/// the thread stack.
name|void
name|llvm_execute_on_thread
parameter_list|(
name|void
function_decl|(
modifier|*
name|UserFn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|UserData
parameter_list|,
name|unsigned
name|RequestedStackSize
init|=
literal|0
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

