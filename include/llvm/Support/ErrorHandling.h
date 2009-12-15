begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/ErrorHandling.h - Callbacks for errors ------*- C++ -*-===//
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
comment|// This file defines an API used to indicate error conditions.
end_comment

begin_comment
comment|// Callbacks can be registered for these errors through this API.
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
name|Twine
decl_stmt|;
comment|/// An error handler callback.
typedef|typedef
name|void
argument_list|(
operator|*
name|llvm_error_handler_t
argument_list|)
argument_list|(
name|void
operator|*
name|user_data
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|reason
argument_list|)
expr_stmt|;
comment|/// llvm_instal_error_handler - Installs a new error handler to be used
comment|/// whenever a serious (non-recoverable) error is encountered by LLVM.
comment|///
comment|/// If you are using llvm_start_multithreaded, you should register the handler
comment|/// before doing that.
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
name|llvm_install_error_handler
parameter_list|(
name|llvm_error_handler_t
name|handler
parameter_list|,
name|void
modifier|*
name|user_data
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// Restores default error handling behaviour.
comment|/// This must not be called between llvm_start_multithreaded() and
comment|/// llvm_stop_multithreaded().
name|void
name|llvm_remove_error_handler
parameter_list|()
function_decl|;
comment|/// Reports a serious error, calling any installed error handler. These
comment|/// functions are intended to be used for error conditions which are outside
comment|/// the control of the compiler (I/O errors, invalid user input, etc.)
comment|///
comment|/// If no error handler is installed the default is to print the message to
comment|/// standard error, followed by a newline.
comment|/// After the error handler is called this function will call exit(1), it
comment|/// does not return.
name|NORETURN
name|void
name|llvm_report_error
parameter_list|(
specifier|const
name|char
modifier|*
name|reason
parameter_list|)
function_decl|;
name|NORETURN
name|void
name|llvm_report_error
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|reason
argument_list|)
decl_stmt|;
name|NORETURN
name|void
name|llvm_report_error
parameter_list|(
specifier|const
name|Twine
modifier|&
name|reason
parameter_list|)
function_decl|;
comment|/// This function calls abort(), and prints the optional message to stderr.
comment|/// Use the llvm_unreachable macro (that adds location info), instead of
comment|/// calling this function directly.
name|NORETURN
name|void
name|llvm_unreachable_internal
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
init|=
literal|0
parameter_list|,
specifier|const
name|char
modifier|*
name|file
init|=
literal|0
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
comment|/// Prints the message and location info to stderr in !NDEBUG builds.
end_comment

begin_comment
comment|/// This is intended to be used for "impossible" situations that imply
end_comment

begin_comment
comment|/// a bug in the compiler.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// In NDEBUG mode it only prints "UNREACHABLE executed".
end_comment

begin_comment
comment|/// Use this instead of assert(0), so that the compiler knows this path
end_comment

begin_comment
comment|/// is not reachable even for NDEBUG builds.
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

