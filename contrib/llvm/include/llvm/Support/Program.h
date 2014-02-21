begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/Program.h ------------------------------------*- C++ -*-===//
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
comment|// This file declares the llvm::sys::Program class.
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
name|LLVM_SUPPORT_PROGRAM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_PROGRAM_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Path.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/system_error.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|error_code
decl_stmt|;
name|namespace
name|sys
block|{
comment|/// This is the OS-specific separator for PATH like environment variables:
comment|// a colon on Unix or a semicolon on Windows.
if|#
directive|if
name|defined
argument_list|(
name|LLVM_ON_UNIX
argument_list|)
specifier|const
name|char
name|EnvPathSeparator
init|=
literal|':'
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|LLVM_ON_WIN32
argument_list|)
specifier|const
name|char
name|EnvPathSeparator
init|=
literal|';'
decl_stmt|;
endif|#
directive|endif
comment|/// @brief This struct encapsulates information about a process.
struct|struct
name|ProcessInfo
block|{
if|#
directive|if
name|defined
argument_list|(
name|LLVM_ON_UNIX
argument_list|)
typedef|typedef
name|pid_t
name|ProcessId
typedef|;
elif|#
directive|elif
name|defined
argument_list|(
name|LLVM_ON_WIN32
argument_list|)
typedef|typedef
name|unsigned
name|long
name|ProcessId
typedef|;
comment|// Must match the type of DWORD on Windows.
typedef|typedef
name|void
modifier|*
name|HANDLE
typedef|;
comment|// Must match the type of HANDLE on Windows.
comment|/// The handle to the process (available on Windows only).
name|HANDLE
name|ProcessHandle
decl_stmt|;
else|#
directive|else
error|#
directive|error
literal|"ProcessInfo is not defined for this platform!"
endif|#
directive|endif
comment|/// The process identifier.
name|ProcessId
name|Pid
decl_stmt|;
comment|/// The return code, set after execution.
name|int
name|ReturnCode
decl_stmt|;
name|ProcessInfo
argument_list|()
expr_stmt|;
block|}
struct|;
comment|/// This static constructor (factory) will attempt to locate a program in
comment|/// the operating system's file system using some pre-determined set of
comment|/// locations to search (e.g. the PATH on Unix). Paths with slashes are
comment|/// returned unmodified.
comment|/// @returns A Path object initialized to the path of the program or a
comment|/// Path object that is empty (invalid) if the program could not be found.
comment|/// @brief Construct a Program by finding it by name.
name|std
operator|::
name|string
name|FindProgramByName
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|name
argument_list|)
expr_stmt|;
comment|// These functions change the specified standard stream (stdin, stdout, or
comment|// stderr) to binary mode. They return errc::success if the specified stream
comment|// was changed. Otherwise a platform dependent error is returned.
name|error_code
name|ChangeStdinToBinary
parameter_list|()
function_decl|;
name|error_code
name|ChangeStdoutToBinary
parameter_list|()
function_decl|;
name|error_code
name|ChangeStderrToBinary
parameter_list|()
function_decl|;
comment|/// This function executes the program using the arguments provided.  The
comment|/// invoked program will inherit the stdin, stdout, and stderr file
comment|/// descriptors, the environment and other configuration settings of the
comment|/// invoking program.
comment|/// This function waits the program to finish.
comment|/// @returns an integer result code indicating the status of the program.
comment|/// A zero or positive value indicates the result code of the program.
comment|/// -1 indicates failure to execute
comment|/// -2 indicates a crash during execution or timeout
name|int
name|ExecuteAndWait
argument_list|(
name|StringRef
name|Program
argument_list|,
comment|///< Path of the program to be executed. It is
comment|/// presumed this is the result of the FindProgramByName method.
specifier|const
name|char
operator|*
operator|*
name|args
argument_list|,
comment|///< A vector of strings that are passed to the
comment|///< program.  The first element should be the name of the program.
comment|///< The list *must* be terminated by a null char* entry.
specifier|const
name|char
operator|*
operator|*
name|env
operator|=
literal|0
argument_list|,
comment|///< An optional vector of strings to use for
comment|///< the program's environment. If not provided, the current program's
comment|///< environment will be used.
specifier|const
name|StringRef
operator|*
operator|*
name|redirects
operator|=
literal|0
argument_list|,
comment|///< An optional array of pointers to
comment|///< paths. If the array is null, no redirection is done. The array
comment|///< should have a size of at least three. The inferior process's
comment|///< stdin(0), stdout(1), and stderr(2) will be redirected to the
comment|///< corresponding paths.
comment|///< When an empty path is passed in, the corresponding file
comment|///< descriptor will be disconnected (ie, /dev/null'd) in a portable
comment|///< way.
name|unsigned
name|secondsToWait
operator|=
literal|0
argument_list|,
comment|///< If non-zero, this specifies the amount
comment|///< of time to wait for the child process to exit. If the time
comment|///< expires, the child is killed and this call returns. If zero,
comment|///< this function will wait until the child finishes or forever if
comment|///< it doesn't.
name|unsigned
name|memoryLimit
operator|=
literal|0
argument_list|,
comment|///< If non-zero, this specifies max. amount
comment|///< of memory can be allocated by process. If memory usage will be
comment|///< higher limit, the child is killed and this call returns. If zero
comment|///< - no memory limit.
name|std
operator|::
name|string
operator|*
name|ErrMsg
operator|=
literal|0
argument_list|,
comment|///< If non-zero, provides a pointer to a string
comment|///< instance in which error messages will be returned. If the string
comment|///< is non-empty upon return an error occurred while invoking the
comment|///< program.
name|bool
operator|*
name|ExecutionFailed
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// Similar to ExecuteAndWait, but returns immediately.
comment|/// @returns The \see ProcessInfo of the newly launced process.
comment|/// \note On Microsoft Windows systems, users will need to either call \see
comment|/// Wait until the process finished execution or win32 CloseHandle() API on
comment|/// ProcessInfo.ProcessHandle to avoid memory leaks.
name|ProcessInfo
name|ExecuteNoWait
argument_list|(
name|StringRef
name|Program
argument_list|,
specifier|const
name|char
operator|*
operator|*
name|args
argument_list|,
specifier|const
name|char
operator|*
operator|*
name|env
operator|=
literal|0
argument_list|,
specifier|const
name|StringRef
operator|*
operator|*
name|redirects
operator|=
literal|0
argument_list|,
name|unsigned
name|memoryLimit
operator|=
literal|0
argument_list|,
name|std
operator|::
name|string
operator|*
name|ErrMsg
operator|=
literal|0
argument_list|,
name|bool
operator|*
name|ExecutionFailed
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// Return true if the given arguments fit within system-specific
comment|/// argument length limits.
name|bool
name|argumentsFitWithinSystemLimits
argument_list|(
name|ArrayRef
operator|<
specifier|const
name|char
operator|*
operator|>
name|Args
argument_list|)
decl_stmt|;
comment|/// This function waits for the process specified by \p PI to finish.
comment|/// \returns A \see ProcessInfo struct with Pid set to:
comment|/// \li The process id of the child process if the child process has changed
comment|/// state.
comment|/// \li 0 if the child process has not changed state.
comment|/// \note Users of this function should always check the ReturnCode member of
comment|/// the \see ProcessInfo returned from this function.
name|ProcessInfo
name|Wait
argument_list|(
specifier|const
name|ProcessInfo
operator|&
name|PI
argument_list|,
comment|///< The child process that should be waited on.
name|unsigned
name|SecondsToWait
argument_list|,
comment|///< If non-zero, this specifies the amount of
comment|///< time to wait for the child process to exit. If the time expires, the
comment|///< child is killed and this function returns. If zero, this function
comment|///< will perform a non-blocking wait on the child process.
name|bool
name|WaitUntilTerminates
argument_list|,
comment|///< If true, ignores \p SecondsToWait and waits
comment|///< until child has terminated.
name|std
operator|::
name|string
operator|*
name|ErrMsg
operator|=
literal|0
comment|///< If non-zero, provides a pointer to a string
comment|///< instance in which error messages will be returned. If the string
comment|///< is non-empty upon return an error occurred while invoking the
comment|///< program.
argument_list|)
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

