begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CrashRecoveryContext.h - Crash Recovery ----------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_SUPPORT_CRASHRECOVERYCONTEXT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_CRASHRECOVERYCONTEXT_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StringRef
decl_stmt|;
comment|/// \brief Crash recovery helper object.
comment|///
comment|/// This class implements support for running operations in a safe context so
comment|/// that crashes (memory errors, stack overflow, assertion violations) can be
comment|/// detected and control restored to the crashing thread. Crash detection is
comment|/// purely "best effort", the exact set of failures which can be recovered from
comment|/// is platform dependent.
comment|///
comment|/// Clients make use of this code by first calling
comment|/// CrashRecoveryContext::Enable(), and then executing unsafe operations via a
comment|/// CrashRecoveryContext object. For example:
comment|///
comment|///    void actual_work(void *);
comment|///
comment|///    void foo() {
comment|///      CrashRecoveryContext CRC;
comment|///
comment|///      if (!CRC.RunSafely(actual_work, 0)) {
comment|///         ... a crash was detected, report error to user ...
comment|///      }
comment|///
comment|///      ... no crash was detected ...
comment|///    }
comment|///
comment|/// Crash recovery contexts may not be nested.
name|class
name|CrashRecoveryContext
block|{
name|void
modifier|*
name|Impl
decl_stmt|;
name|public
label|:
name|CrashRecoveryContext
argument_list|()
operator|:
name|Impl
argument_list|(
literal|0
argument_list|)
block|{}
operator|~
name|CrashRecoveryContext
argument_list|()
expr_stmt|;
comment|/// \brief Enable crash recovery.
specifier|static
name|void
name|Enable
parameter_list|()
function_decl|;
comment|/// \brief Disable crash recovery.
specifier|static
name|void
name|Disable
parameter_list|()
function_decl|;
comment|/// \brief Return the active context, if the code is currently executing in a
comment|/// thread which is in a protected context.
specifier|static
name|CrashRecoveryContext
modifier|*
name|GetCurrent
parameter_list|()
function_decl|;
comment|/// \brief Execute the provide callback function (with the given arguments) in
comment|/// a protected context.
comment|///
comment|/// \return True if the function completed successfully, and false if the
comment|/// function crashed (or HandleCrash was called explicitly). Clients should
comment|/// make as little assumptions as possible about the program state when
comment|/// RunSafely has returned false. Clients can use getBacktrace() to retrieve
comment|/// the backtrace of the crash on failures.
name|bool
name|RunSafely
parameter_list|(
name|void
function_decl|(
modifier|*
name|Fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|UserData
parameter_list|)
function_decl|;
comment|/// \brief Execute the provide callback function (with the given arguments) in
comment|/// a protected context which is run in another thread (optionally with a
comment|/// requested stack size).
comment|///
comment|/// See RunSafely() and llvm_execute_on_thread().
name|bool
name|RunSafelyOnThread
parameter_list|(
name|void
function_decl|(
modifier|*
name|Fn
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
comment|/// \brief Explicitly trigger a crash recovery in the current process, and
comment|/// return failure from RunSafely(). This function does not return.
name|void
name|HandleCrash
parameter_list|()
function_decl|;
comment|/// \brief Return a string containing the backtrace where the crash was
comment|/// detected; or empty if the backtrace wasn't recovered.
comment|///
comment|/// This function is only valid when a crash has been detected (i.e.,
comment|/// RunSafely() has returned false.
specifier|const
name|std
operator|::
name|string
operator|&
name|getBacktrace
argument_list|()
specifier|const
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

