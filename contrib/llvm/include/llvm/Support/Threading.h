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

begin_include
include|#
directive|include
file|"llvm/Config/llvm-config.h"
end_include

begin_comment
comment|// for LLVM_ON_UNIX
end_comment

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|<ciso646>
end_include

begin_comment
comment|// So we can check the C++ standard lib macros.
end_comment

begin_include
include|#
directive|include
file|<functional>
end_include

begin_comment
comment|// std::call_once from libc++ is used on all Unix platforms. Other
end_comment

begin_comment
comment|// implementations like libstdc++ are known to have problems on NetBSD,
end_comment

begin_comment
comment|// OpenBSD and PowerPC.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LLVM_ON_UNIX
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|_LIBCPP_VERSION
argument_list|)
operator|||
expr|\
operator|!
operator|(
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ppc__
argument_list|)
operator|)
operator|)
end_if

begin_define
define|#
directive|define
name|LLVM_THREADING_USE_STD_CALL_ONCE
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_THREADING_USE_STD_CALL_ONCE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLVM_THREADING_USE_STD_CALL_ONCE
end_if

begin_include
include|#
directive|include
file|<mutex>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"llvm/Support/Atomic.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

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
comment|/// thread, passing it the provided \p UserData and waits for thread
comment|/// completion.
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
if|#
directive|if
name|LLVM_THREADING_USE_STD_CALL_ONCE
typedef|typedef
name|std
operator|::
name|once_flag
name|once_flag
expr_stmt|;
comment|/// This macro is the only way you should define your once flag for LLVM's
comment|/// call_once.
define|#
directive|define
name|LLVM_DEFINE_ONCE_FLAG
parameter_list|(
name|flag
parameter_list|)
value|static once_flag flag
else|#
directive|else
enum|enum
name|InitStatus
block|{
name|Uninitialized
init|=
literal|0
block|,
name|Wait
init|=
literal|1
block|,
name|Done
init|=
literal|2
block|}
enum|;
typedef|typedef
specifier|volatile
name|sys
operator|::
name|cas_flag
name|once_flag
expr_stmt|;
comment|/// This macro is the only way you should define your once flag for LLVM's
comment|/// call_once.
define|#
directive|define
name|LLVM_DEFINE_ONCE_FLAG
parameter_list|(
name|flag
parameter_list|)
value|static once_flag flag = Uninitialized
endif|#
directive|endif
comment|/// \brief Execute the function specified as a parameter once.
comment|///
comment|/// Typical usage:
comment|/// \code
comment|///   void foo() {...};
comment|///   ...
comment|///   LLVM_DEFINE_ONCE_FLAG(flag);
comment|///   call_once(flag, foo);
comment|/// \endcode
comment|///
comment|/// \param flag Flag used for tracking whether or not this has run.
comment|/// \param F Function to call once.
name|template
operator|<
name|typename
name|Function
operator|,
name|typename
operator|...
name|Args
operator|>
name|void
name|call_once
argument_list|(
argument|once_flag&flag
argument_list|,
argument|Function&&F
argument_list|,
argument|Args&&... ArgList
argument_list|)
block|{
if|#
directive|if
name|LLVM_THREADING_USE_STD_CALL_ONCE
name|std
operator|::
name|call_once
argument_list|(
name|flag
argument_list|,
name|std
operator|::
name|forward
operator|<
name|Function
operator|>
operator|(
name|F
operator|)
argument_list|,
name|std
operator|::
name|forward
operator|<
name|Args
operator|>
operator|(
name|ArgList
operator|)
operator|...
argument_list|)
block|;
else|#
directive|else
comment|// For other platforms we use a generic (if brittle) version based on our
comment|// atomics.
name|sys
operator|::
name|cas_flag
name|old_val
operator|=
name|sys
operator|::
name|CompareAndSwap
argument_list|(
operator|&
name|flag
argument_list|,
name|Wait
argument_list|,
name|Uninitialized
argument_list|)
block|;
if|if
condition|(
name|old_val
operator|==
name|Uninitialized
condition|)
block|{
name|std
operator|::
name|forward
operator|<
name|Function
operator|>
call|(
name|F
call|)
argument_list|(
name|std
operator|::
name|forward
operator|<
name|Args
operator|>
operator|(
name|ArgList
operator|)
operator|...
argument_list|)
expr_stmt|;
name|sys
operator|::
name|MemoryFence
argument_list|()
expr_stmt|;
name|TsanIgnoreWritesBegin
argument_list|()
expr_stmt|;
name|TsanHappensBefore
argument_list|(
operator|&
name|flag
argument_list|)
expr_stmt|;
name|flag
operator|=
name|Done
expr_stmt|;
name|TsanIgnoreWritesEnd
argument_list|()
expr_stmt|;
block|}
else|else
block|{
comment|// Wait until any thread doing the call has finished.
name|sys
operator|::
name|cas_flag
name|tmp
operator|=
name|flag
expr_stmt|;
name|sys
operator|::
name|MemoryFence
argument_list|()
expr_stmt|;
while|while
condition|(
name|tmp
operator|!=
name|Done
condition|)
block|{
name|tmp
operator|=
name|flag
expr_stmt|;
name|sys
operator|::
name|MemoryFence
argument_list|()
expr_stmt|;
block|}
block|}
name|TsanHappensAfter
argument_list|(
operator|&
name|flag
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
comment|/// Get the amount of currency to use for tasks requiring significant
comment|/// memory or other resources. Currently based on physical cores, if
comment|/// available for the host system, otherwise falls back to
comment|/// thread::hardware_concurrency().
comment|/// Returns 1 when LLVM is configured with LLVM_ENABLE_THREADS=OFF
name|unsigned
name|heavyweight_hardware_concurrency
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

