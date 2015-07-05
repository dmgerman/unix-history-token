begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/Process.h -----------------------------------*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Provides a library for accessing information about this process and other
end_comment

begin_comment
comment|/// processes on the operating system. Also provides means of spawning
end_comment

begin_comment
comment|/// subprocess for commands. The design of this library is modeled after the
end_comment

begin_comment
comment|/// proposed design of the Boost.Process library, and is design specifically to
end_comment

begin_comment
comment|/// follow the style of standard libraries and potentially become a proposal
end_comment

begin_comment
comment|/// for a standard library.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This file declares the llvm::sys::Process class which contains a collection
end_comment

begin_comment
comment|/// of legacy static interfaces for extracting various information about the
end_comment

begin_comment
comment|/// current process. The goal is to migrate users of this API over to the new
end_comment

begin_comment
comment|/// interfaces.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_SUPPORT_PROCESS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_PROCESS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Config/llvm-config.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/TimeValue.h"
end_include

begin_include
include|#
directive|include
file|<system_error>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StringRef
decl_stmt|;
name|namespace
name|sys
block|{
comment|/// \brief A collection of legacy interfaces for querying information about the
comment|/// current executing process.
name|class
name|Process
block|{
name|public
label|:
specifier|static
name|unsigned
name|getPageSize
parameter_list|()
function_decl|;
comment|/// \brief Return process memory usage.
comment|/// This static function will return the total amount of memory allocated
comment|/// by the process. This only counts the memory allocated via the malloc,
comment|/// calloc and realloc functions and includes any "free" holes in the
comment|/// allocated space.
specifier|static
name|size_t
name|GetMallocUsage
parameter_list|()
function_decl|;
comment|/// This static function will set \p user_time to the amount of CPU time
comment|/// spent in user (non-kernel) mode and \p sys_time to the amount of CPU
comment|/// time spent in system (kernel) mode.  If the operating system does not
comment|/// support collection of these metrics, a zero TimeValue will be for both
comment|/// values.
comment|/// \param elapsed Returns the TimeValue::now() giving current time
comment|/// \param user_time Returns the current amount of user time for the process
comment|/// \param sys_time Returns the current amount of system time for the process
specifier|static
name|void
name|GetTimeUsage
parameter_list|(
name|TimeValue
modifier|&
name|elapsed
parameter_list|,
name|TimeValue
modifier|&
name|user_time
parameter_list|,
name|TimeValue
modifier|&
name|sys_time
parameter_list|)
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
comment|// This function returns the environment variable \arg name's value as a UTF-8
comment|// string. \arg Name is assumed to be in UTF-8 encoding too.
specifier|static
name|Optional
operator|<
name|std
operator|::
name|string
operator|>
name|GetEnv
argument_list|(
argument|StringRef name
argument_list|)
expr_stmt|;
comment|/// This function searches for an existing file in the list of directories
comment|/// in a PATH like environment variable, and returns the first file found,
comment|/// according to the order of the entries in the PATH like environment
comment|/// variable.
specifier|static
name|Optional
operator|<
name|std
operator|::
name|string
operator|>
name|FindInEnvPath
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|EnvName
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|FileName
argument_list|)
expr_stmt|;
comment|/// This function returns a SmallVector containing the arguments passed from
comment|/// the operating system to the program.  This function expects to be handed
comment|/// the vector passed in from main.
specifier|static
name|std
operator|::
name|error_code
name|GetArgumentVector
argument_list|(
name|SmallVectorImpl
operator|<
specifier|const
name|char
operator|*
operator|>
operator|&
name|Args
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|char
operator|*
operator|>
name|ArgsFromMain
argument_list|,
name|SpecificBumpPtrAllocator
operator|<
name|char
operator|>
operator|&
name|ArgAllocator
argument_list|)
expr_stmt|;
comment|// This functions ensures that the standard file descriptors (input, output,
comment|// and error) are properly mapped to a file descriptor before we use any of
comment|// them.  This should only be called by standalone programs, library
comment|// components should not call this.
specifier|static
name|std
operator|::
name|error_code
name|FixupStandardFileDescriptors
argument_list|()
expr_stmt|;
comment|// This function safely closes a file descriptor.  It is not safe to retry
comment|// close(2) when it returns with errno equivalent to EINTR; this is because
comment|// *nixen cannot agree if the file descriptor is, in fact, closed when this
comment|// occurs.
comment|//
comment|// N.B. Some operating systems, due to thread cancellation, cannot properly
comment|// guarantee that it will or will not be closed one way or the other!
specifier|static
name|std
operator|::
name|error_code
name|SafelyCloseFileDescriptor
argument_list|(
argument|int FD
argument_list|)
expr_stmt|;
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
comment|/// This function determines if the given file descriptor is displayd and
comment|/// supports colors.
specifier|static
name|bool
name|FileDescriptorHasColors
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
comment|/// Enables or disables whether ANSI escape sequences are used to output
comment|/// colors. This only has an effect on Windows.
comment|/// Note: Setting this option is not thread-safe and should only be done
comment|/// during initialization.
specifier|static
name|void
name|UseANSIEscapeCodes
parameter_list|(
name|bool
name|enable
parameter_list|)
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
comment|/// This function returns the escape sequence to reverse forground and
comment|/// background colors.
specifier|static
specifier|const
name|char
modifier|*
name|OutputReverse
parameter_list|()
function_decl|;
comment|/// Resets the terminals colors, or returns an escape sequence to do so.
specifier|static
specifier|const
name|char
modifier|*
name|ResetColor
parameter_list|()
function_decl|;
comment|/// Get the result of a process wide random number generator. The
comment|/// generator will be automatically seeded in non-deterministic fashion.
specifier|static
name|unsigned
name|GetRandomNumber
parameter_list|()
function_decl|;
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

