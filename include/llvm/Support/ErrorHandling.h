begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/ErrorHandling.h - Fatal error handling ------*- C++ -*-===//
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
comment|// This file defines an API used to indicate fatal error conditions.  Non-fatal
end_comment

begin_comment
comment|// errors (most of them) should be handled through LLVMContext.
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
name|LLVM_SUPPORT_ERRORHANDLING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_ERRORHANDLING_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

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
name|class
name|Twine
decl_stmt|;
comment|/// An error handler callback.
typedef|typedef
name|void
argument_list|(
argument|*fatal_error_handler_t
argument_list|)
operator|(
name|void
operator|*
name|user_data
operator|,
specifier|const
name|std
operator|::
name|string
operator|&
name|reason
operator|,
name|bool
name|gen_crash_diag
operator|)
expr_stmt|;
comment|/// install_fatal_error_handler - Installs a new error handler to be used
comment|/// whenever a serious (non-recoverable) error is encountered by LLVM.
comment|///
comment|/// If no error handler is installed the default is to print the error message
comment|/// to stderr, and call exit(1).  If an error handler is installed then it is
comment|/// the handler's responsibility to log the message, it will no longer be
comment|/// printed to stderr.  If the error handler returns, then exit(1) will be
comment|/// called.
comment|///
comment|/// It is dangerous to naively use an error handler which throws an exception.
comment|/// Even though some applications desire to gracefully recover from arbitrary
comment|/// faults, blindly throwing exceptions through unfamiliar code isn't a way to
comment|/// achieve this.
comment|///
comment|/// \param user_data - An argument which will be passed to the install error
comment|/// handler.
name|void
name|install_fatal_error_handler
parameter_list|(
name|fatal_error_handler_t
name|handler
parameter_list|,
name|void
modifier|*
name|user_data
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// Restores default error handling behaviour.
name|void
name|remove_fatal_error_handler
parameter_list|()
function_decl|;
comment|/// ScopedFatalErrorHandler - This is a simple helper class which just
comment|/// calls install_fatal_error_handler in its constructor and
comment|/// remove_fatal_error_handler in its destructor.
struct|struct
name|ScopedFatalErrorHandler
block|{
name|explicit
name|ScopedFatalErrorHandler
parameter_list|(
name|fatal_error_handler_t
name|handler
parameter_list|,
name|void
modifier|*
name|user_data
init|=
name|nullptr
parameter_list|)
block|{
name|install_fatal_error_handler
argument_list|(
name|handler
argument_list|,
name|user_data
argument_list|)
expr_stmt|;
block|}
operator|~
name|ScopedFatalErrorHandler
argument_list|()
block|{
name|remove_fatal_error_handler
argument_list|()
block|; }
block|}
struct|;
comment|/// Reports a serious error, calling any installed error handler. These
comment|/// functions are intended to be used for error conditions which are outside
comment|/// the control of the compiler (I/O errors, invalid user input, etc.)
comment|///
comment|/// If no error handler is installed the default is to print the message to
comment|/// standard error, followed by a newline.
comment|/// After the error handler is called this function will call exit(1), it
comment|/// does not return.
name|LLVM_ATTRIBUTE_NORETURN
name|void
name|report_fatal_error
parameter_list|(
specifier|const
name|char
modifier|*
name|reason
parameter_list|,
name|bool
name|gen_crash_diag
init|=
name|true
parameter_list|)
function_decl|;
name|LLVM_ATTRIBUTE_NORETURN
name|void
name|report_fatal_error
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|reason
argument_list|,
name|bool
name|gen_crash_diag
operator|=
name|true
argument_list|)
decl_stmt|;
name|LLVM_ATTRIBUTE_NORETURN
name|void
name|report_fatal_error
parameter_list|(
name|StringRef
name|reason
parameter_list|,
name|bool
name|gen_crash_diag
init|=
name|true
parameter_list|)
function_decl|;
name|LLVM_ATTRIBUTE_NORETURN
name|void
name|report_fatal_error
parameter_list|(
specifier|const
name|Twine
modifier|&
name|reason
parameter_list|,
name|bool
name|gen_crash_diag
init|=
name|true
parameter_list|)
function_decl|;
comment|/// Installs a new bad alloc error handler that should be used whenever a
comment|/// bad alloc error, e.g. failing malloc/calloc, is encountered by LLVM.
comment|///
comment|/// The user can install a bad alloc handler, in order to define the behavior
comment|/// in case of failing allocations, e.g. throwing an exception. Note that this
comment|/// handler must not trigger any additional allocations itself.
comment|///
comment|/// If no error handler is installed the default is to print the error message
comment|/// to stderr, and call exit(1).  If an error handler is installed then it is
comment|/// the handler's responsibility to log the message, it will no longer be
comment|/// printed to stderr.  If the error handler returns, then exit(1) will be
comment|/// called.
comment|///
comment|///
comment|/// \param user_data - An argument which will be passed to the installed error
comment|/// handler.
name|void
name|install_bad_alloc_error_handler
parameter_list|(
name|fatal_error_handler_t
name|handler
parameter_list|,
name|void
modifier|*
name|user_data
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// Restores default bad alloc error handling behavior.
name|void
name|remove_bad_alloc_error_handler
parameter_list|()
function_decl|;
comment|/// Reports a bad alloc error, calling any user defined bad alloc
comment|/// error handler. In contrast to the generic 'report_fatal_error'
comment|/// functions, this function is expected to return, e.g. the user
comment|/// defined error handler throws an exception.
comment|///
comment|/// Note: When throwing an exception in the bad alloc handler, make sure that
comment|/// the following unwind succeeds, e.g. do not trigger additional allocations
comment|/// in the unwind chain.
comment|///
comment|/// If no error handler is installed (default), then a bad_alloc exception
comment|/// is thrown if LLVM is compiled with exception support, otherwise an assertion
comment|/// is called.
name|void
name|report_bad_alloc_error
parameter_list|(
specifier|const
name|char
modifier|*
name|Reason
parameter_list|,
name|bool
name|GenCrashDiag
init|=
name|true
parameter_list|)
function_decl|;
comment|/// This function calls abort(), and prints the optional message to stderr.
comment|/// Use the llvm_unreachable macro (that adds location info), instead of
comment|/// calling this function directly.
name|LLVM_ATTRIBUTE_NORETURN
name|void
name|llvm_unreachable_internal
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
init|=
name|nullptr
parameter_list|,
specifier|const
name|char
modifier|*
name|file
init|=
name|nullptr
parameter_list|,
name|unsigned
name|line
init|=
literal|0
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|/// Marks that the current location is not supposed to be reachable.
end_comment

begin_comment
comment|/// In !NDEBUG builds, prints the message and location info to stderr.
end_comment

begin_comment
comment|/// In NDEBUG builds, becomes an optimizer hint that the current location
end_comment

begin_comment
comment|/// is not supposed to be reachable.  On compilers that don't support
end_comment

begin_comment
comment|/// such hints, prints a reduced message instead.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Use this instead of assert(0).  It conveys intent more clearly and
end_comment

begin_comment
comment|/// allows compilers to omit some unnecessary code.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NDEBUG
end_ifndef

begin_define
define|#
directive|define
name|llvm_unreachable
parameter_list|(
name|msg
parameter_list|)
define|\
value|::llvm::llvm_unreachable_internal(msg, __FILE__, __LINE__)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|LLVM_BUILTIN_UNREACHABLE
argument_list|)
end_elif

begin_define
define|#
directive|define
name|llvm_unreachable
parameter_list|(
name|msg
parameter_list|)
value|LLVM_BUILTIN_UNREACHABLE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|llvm_unreachable
parameter_list|(
name|msg
parameter_list|)
value|::llvm::llvm_unreachable_internal()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

