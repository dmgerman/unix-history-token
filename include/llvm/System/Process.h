begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/System/Process.h ------------------------------------*- C++ -*-===//
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
comment|// This file declares the llvm::sys::Process class.
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
name|LLVM_SYSTEM_PROCESS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SYSTEM_PROCESS_H
end_define

begin_include
include|#
directive|include
file|"llvm/System/TimeValue.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|sys
block|{
comment|/// This class provides an abstraction for getting information about the
comment|/// currently executing process.
comment|/// @since 1.4
comment|/// @brief An abstraction for operating system processes.
name|class
name|Process
block|{
comment|/// @name Accessors
comment|/// @{
name|public
label|:
comment|/// This static function will return the operating system's virtual memory
comment|/// page size.
comment|/// @returns The number of bytes in a virtual memory page.
comment|/// @throws nothing
comment|/// @brief Get the virtual memory page size
specifier|static
name|unsigned
name|GetPageSize
parameter_list|()
function_decl|;
comment|/// This static function will return the total amount of memory allocated
comment|/// by the process. This only counts the memory allocated via the malloc,
comment|/// calloc and realloc functions and includes any "free" holes in the
comment|/// allocated space.
comment|/// @throws nothing
comment|/// @brief Return process memory usage.
specifier|static
name|size_t
name|GetMallocUsage
parameter_list|()
function_decl|;
comment|/// This static function will return the total memory usage of the
comment|/// process. This includes code, data, stack and mapped pages usage. Notei
comment|/// that the value returned here is not necessarily the Running Set Size,
comment|/// it is the total virtual memory usage, regardless of mapped state of
comment|/// that memory.
specifier|static
name|size_t
name|GetTotalMemoryUsage
parameter_list|()
function_decl|;
comment|/// This static function will set \p user_time to the amount of CPU time
comment|/// spent in user (non-kernel) mode and \p sys_time to the amount of CPU
comment|/// time spent in system (kernel) mode.  If the operating system does not
comment|/// support collection of these metrics, a zero TimeValue will be for both
comment|/// values.
specifier|static
name|void
name|GetTimeUsage
parameter_list|(
name|TimeValue
modifier|&
name|elapsed
parameter_list|,
comment|///< Returns the TimeValue::now() giving current time
name|TimeValue
modifier|&
name|user_time
parameter_list|,
comment|///< Returns the current amount of user time for the process
name|TimeValue
modifier|&
name|sys_time
comment|///< Returns the current amount of system time for the process
parameter_list|)
function_decl|;
comment|/// This static function will return the process' current user id number.
comment|/// Not all operating systems support this feature. Where it is not
comment|/// supported, the function should return 65536 as the value.
specifier|static
name|int
name|GetCurrentUserId
parameter_list|()
function_decl|;
comment|/// This static function will return the process' current group id number.
comment|/// Not all operating systems support this feature. Where it is not
comment|/// supported, the function should return 65536 as the value.
specifier|static
name|int
name|GetCurrentGroupId
parameter_list|()
function_decl|;
comment|/// This function makes the necessary calls to the operating system to
comment|/// prevent core files or any other kind of large memory dumps that can
comment|/// occur when a program fails.
comment|/// @brief Prevent core file generation.
specifier|static
name|void
name|PreventCoreFiles
parameter_list|()
function_decl|;
comment|/// This function determines if the standard input is connected directly
comment|/// to a user's input (keyboard probably), rather than coming from a file
comment|/// or pipe.
specifier|static
name|bool
name|StandardInIsUserInput
parameter_list|()
function_decl|;
comment|/// This function determines if the standard output is connected to a
comment|/// "tty" or "console" window. That is, the output would be displayed to
comment|/// the user rather than being put on a pipe or stored in a file.
specifier|static
name|bool
name|StandardOutIsDisplayed
parameter_list|()
function_decl|;
comment|/// This function determines if the standard error is connected to a
comment|/// "tty" or "console" window. That is, the output would be displayed to
comment|/// the user rather than being put on a pipe or stored in a file.
specifier|static
name|bool
name|StandardErrIsDisplayed
parameter_list|()
function_decl|;
comment|/// This function determines if the given file descriptor is connected to
comment|/// a "tty" or "console" window. That is, the output would be displayed to
comment|/// the user rather than being put on a pipe or stored in a file.
specifier|static
name|bool
name|FileDescriptorIsDisplayed
parameter_list|(
name|int
name|fd
parameter_list|)
function_decl|;
comment|/// This function determines the number of columns in the window
comment|/// if standard output is connected to a "tty" or "console"
comment|/// window. If standard output is not connected to a tty or
comment|/// console, or if the number of columns cannot be determined,
comment|/// this routine returns zero.
specifier|static
name|unsigned
name|StandardOutColumns
parameter_list|()
function_decl|;
comment|/// This function determines the number of columns in the window
comment|/// if standard error is connected to a "tty" or "console"
comment|/// window. If standard error is not connected to a tty or
comment|/// console, or if the number of columns cannot be determined,
comment|/// this routine returns zero.
specifier|static
name|unsigned
name|StandardErrColumns
parameter_list|()
function_decl|;
comment|/// This function determines whether the terminal connected to standard
comment|/// output supports colors. If standard output is not connected to a
comment|/// terminal, this function returns false.
specifier|static
name|bool
name|StandardOutHasColors
parameter_list|()
function_decl|;
comment|/// This function determines whether the terminal connected to standard
comment|/// error supports colors. If standard error is not connected to a
comment|/// terminal, this function returns false.
specifier|static
name|bool
name|StandardErrHasColors
parameter_list|()
function_decl|;
comment|/// Whether changing colors requires the output to be flushed.
comment|/// This is needed on systems that don't support escape sequences for
comment|/// changing colors.
specifier|static
name|bool
name|ColorNeedsFlush
parameter_list|()
function_decl|;
comment|/// This function returns the colorcode escape sequences.
comment|/// If ColorNeedsFlush() is true then this function will change the colors
comment|/// and return an empty escape sequence. In that case it is the
comment|/// responsibility of the client to flush the output stream prior to
comment|/// calling this function.
specifier|static
specifier|const
name|char
modifier|*
name|OutputColor
parameter_list|(
name|char
name|c
parameter_list|,
name|bool
name|bold
parameter_list|,
name|bool
name|bg
parameter_list|)
function_decl|;
comment|/// Same as OutputColor, but only enables the bold attribute.
specifier|static
specifier|const
name|char
modifier|*
name|OutputBold
parameter_list|(
name|bool
name|bg
parameter_list|)
function_decl|;
comment|/// Resets the terminals colors, or returns an escape sequence to do so.
specifier|static
specifier|const
name|char
modifier|*
name|ResetColor
parameter_list|()
function_decl|;
comment|/// @}
block|}
empty_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

