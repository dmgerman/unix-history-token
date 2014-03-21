begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/Signals.h - Signal Handling support ----------*- C++ -*-===//
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
comment|// This file defines some helpful functions for dealing with the possibility of
end_comment

begin_comment
comment|// unix signals occurring while your program is running.
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
name|LLVM_SUPPORT_SIGNALS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_SIGNALS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Path.h"
end_include

begin_include
include|#
directive|include
file|<cstdio>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|sys
block|{
comment|/// This function runs all the registered interrupt handlers, including the
comment|/// removal of files registered by RemoveFileOnSignal.
name|void
name|RunInterruptHandlers
parameter_list|()
function_decl|;
comment|/// This function registers signal handlers to ensure that if a signal gets
comment|/// delivered that the named file is removed.
comment|/// @brief Remove a file if a fatal signal occurs.
name|bool
name|RemoveFileOnSignal
argument_list|(
name|StringRef
name|Filename
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
comment|/// This function removes a file from the list of files to be removed on
comment|/// signal delivery.
name|void
name|DontRemoveFileOnSignal
parameter_list|(
name|StringRef
name|Filename
parameter_list|)
function_decl|;
comment|/// When an error signal (such as SIBABRT or SIGSEGV) is delivered to the
comment|/// process, print a stack trace and then exit.
comment|/// @brief Print a stack trace if a fatal signal occurs.
name|void
name|PrintStackTraceOnErrorSignal
parameter_list|()
function_decl|;
comment|/// \brief Print the stack trace using the given \c FILE object.
name|void
name|PrintStackTrace
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
comment|/// AddSignalHandler - Add a function to be called when an abort/kill signal
comment|/// is delivered to the process.  The handler can have a cookie passed to it
comment|/// to identify what instance of the handler it is.
name|void
name|AddSignalHandler
parameter_list|(
name|void
function_decl|(
modifier|*
name|FnPtr
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|Cookie
parameter_list|)
function_decl|;
comment|/// This function registers a function to be called when the user "interrupts"
comment|/// the program (typically by pressing ctrl-c).  When the user interrupts the
comment|/// program, the specified interrupt function is called instead of the program
comment|/// being killed, and the interrupt function automatically disabled.  Note
comment|/// that interrupt functions are not allowed to call any non-reentrant
comment|/// functions.  An null interrupt function pointer disables the current
comment|/// installed function.  Note also that the handler may be executed on a
comment|/// different thread on some platforms.
comment|/// @brief Register a function to be called when ctrl-c is pressed.
name|void
name|SetInterruptFunction
parameter_list|(
name|void
function_decl|(
modifier|*
name|IF
function_decl|)
parameter_list|()
parameter_list|)
function_decl|;
block|}
comment|// End sys namespace
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

