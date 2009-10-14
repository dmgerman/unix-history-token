begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/System/Program.h ------------------------------------*- C++ -*-===//
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
name|LLVM_SYSTEM_PROGRAM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SYSTEM_PROGRAM_H
end_define

begin_include
include|#
directive|include
file|"llvm/System/Path.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|sys
block|{
comment|// TODO: Add operations to communicate with the process, redirect its I/O,
comment|// etc.
comment|/// This class provides an abstraction for programs that are executable by the
comment|/// operating system. It provides a platform generic way to find executable
comment|/// programs from the path and to execute them in various ways. The sys::Path
comment|/// class is used to specify the location of the Program.
comment|/// @since 1.4
comment|/// @brief An abstraction for finding and executing programs.
name|class
name|Program
block|{
comment|/// Opaque handle for target specific data.
name|void
modifier|*
name|Data_
decl_stmt|;
comment|// Noncopyable.
name|Program
argument_list|(
specifier|const
name|Program
operator|&
name|other
argument_list|)
expr_stmt|;
name|Program
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Program
operator|&
name|other
operator|)
decl_stmt|;
comment|/// @name Methods
comment|/// @{
name|public
label|:
name|Program
argument_list|()
expr_stmt|;
operator|~
name|Program
argument_list|()
expr_stmt|;
comment|/// Return process ID of this program.
name|unsigned
name|GetPid
argument_list|()
specifier|const
expr_stmt|;
comment|/// This function executes the program using the \p arguments provided.  The
comment|/// invoked program will inherit the stdin, stdout, and stderr file
comment|/// descriptors, the environment and other configuration settings of the
comment|/// invoking program. If Path::executable() does not return true when this
comment|/// function is called then a std::string is thrown.
comment|/// @returns false in case of error, true otherwise.
comment|/// @see FindProgramByName
comment|/// @brief Executes the program with the given set of \p args.
name|bool
name|Execute
argument_list|(
specifier|const
name|Path
operator|&
name|path
argument_list|,
comment|///< sys::Path object providing the path of the
comment|///< program to be executed. It is presumed this is the result of
comment|///< the FindProgramByName method.
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
name|sys
operator|::
name|Path
operator|*
operator|*
name|redirects
operator|=
literal|0
argument_list|,
comment|///< An optional array of pointers to
comment|///< Paths. If the array is null, no redirection is done. The array
comment|///< should have a size of at least three. If the pointer in the array
comment|///< are not null, then the inferior process's stdin(0), stdout(1),
comment|///< and stderr(2) will be redirected to the corresponding Paths.
comment|///< When an empty Path is passed in, the corresponding file
comment|///< descriptor will be disconnected (ie, /dev/null'd) in a portable
comment|///< way.
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
comment|///< If non-zero, provides a pointer to a string
comment|///< instance in which error messages will be returned. If the string
comment|///< is non-empty upon return an error occurred while invoking the
comment|///< program.
argument_list|)
decl_stmt|;
comment|/// This function waits for the program to exit. This function will block
comment|/// the current program until the invoked program exits.
comment|/// @returns an integer result code indicating the status of the program.
comment|/// A zero or positive value indicates the result code of the program. A
comment|/// negative value is the signal number on which it terminated.
comment|/// @see Execute
comment|/// @brief Waits for the program to exit.
name|int
name|Wait
argument_list|(
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
name|std
operator|::
name|string
operator|*
name|ErrMsg
operator|=
literal|0
comment|///< If non-zero, provides a pointer to a string
comment|///< instance in which error messages will be returned. If the string
comment|///< is non-empty upon return an error occurred while waiting.
argument_list|)
decl_stmt|;
comment|/// This function terminates the program.
comment|/// @returns true if an error occured.
comment|/// @see Execute
comment|/// @brief Terminates the program.
name|bool
name|Kill
argument_list|(
name|std
operator|::
name|string
operator|*
name|ErrMsg
operator|=
literal|0
comment|///< If non-zero, provides a pointer to a string
comment|///< instance in which error messages will be returned. If the string
comment|///< is non-empty upon return an error occurred while killing the
comment|///< program.
argument_list|)
decl_stmt|;
comment|/// This static constructor (factory) will attempt to locate a program in
comment|/// the operating system's file system using some pre-determined set of
comment|/// locations to search (e.g. the PATH on Unix).
comment|/// @returns A Path object initialized to the path of the program or a
comment|/// Path object that is empty (invalid) if the program could not be found.
comment|/// @throws nothing
comment|/// @brief Construct a Program by finding it by name.
specifier|static
name|Path
name|FindProgramByName
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|name
argument_list|)
decl_stmt|;
comment|// These methods change the specified standard stream (stdin or stdout) to
comment|// binary mode. They return true if an error occurred
specifier|static
name|bool
name|ChangeStdinToBinary
parameter_list|()
function_decl|;
specifier|static
name|bool
name|ChangeStdoutToBinary
parameter_list|()
function_decl|;
comment|/// A convenience function equivalent to Program prg; prg.Execute(..);
comment|/// prg.Wait(..);
comment|/// @throws nothing
comment|/// @see Execute, Wait
specifier|static
name|int
name|ExecuteAndWait
argument_list|(
specifier|const
name|Path
operator|&
name|path
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
name|sys
operator|::
name|Path
operator|*
operator|*
name|redirects
operator|=
literal|0
argument_list|,
name|unsigned
name|secondsToWait
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
argument_list|)
decl_stmt|;
comment|/// A convenience function equivalent to Program prg; prg.Execute(..);
comment|/// @throws nothing
comment|/// @see Execute
specifier|static
name|void
name|ExecuteNoWait
argument_list|(
specifier|const
name|Path
operator|&
name|path
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
name|sys
operator|::
name|Path
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
argument_list|)
decl_stmt|;
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

