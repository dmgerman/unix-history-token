begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Debugger.h - LLVM debugger library interface -------------*- C++ -*-===//
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
comment|// This file defines the LLVM source-level debugger library interface.
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
name|LLVM_DEBUGGER_DEBUGGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGGER_DEBUGGER_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Module
decl_stmt|;
name|class
name|InferiorProcess
decl_stmt|;
comment|/// Debugger class - This class implements the LLVM source-level debugger.
comment|/// This allows clients to handle the user IO processing without having to
comment|/// worry about how the debugger itself works.
comment|///
name|class
name|Debugger
block|{
comment|// State the debugger needs when starting and stopping the program.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|ProgramArguments
expr_stmt|;
comment|// The environment to run the program with.  This should eventually be
comment|// changed to vector of strings when we allow the user to edit the
comment|// environment.
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|Environment
decl_stmt|;
comment|// Program - The currently loaded program, or null if none is loaded.
name|Module
modifier|*
name|Program
decl_stmt|;
comment|// Process - The currently executing inferior process.
name|InferiorProcess
modifier|*
name|Process
decl_stmt|;
name|Debugger
argument_list|(
specifier|const
name|Debugger
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|Debugger
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|public
label|:
name|Debugger
argument_list|()
expr_stmt|;
operator|~
name|Debugger
argument_list|()
expr_stmt|;
comment|//===------------------------------------------------------------------===//
comment|// Methods for manipulating and inspecting the execution environment.
comment|//
comment|/// initializeEnvironment - Specify the environment the program should run
comment|/// with.  This is used to initialize the environment of the program to the
comment|/// environment of the debugger.
name|void
name|initializeEnvironment
parameter_list|(
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|envp
parameter_list|)
block|{
name|Environment
operator|=
name|envp
expr_stmt|;
block|}
comment|/// setWorkingDirectory - Specify the working directory for the program to
comment|/// be started from.
name|void
name|setWorkingDirectory
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Dir
argument_list|)
block|{
comment|// FIXME: implement
block|}
name|template
operator|<
name|typename
name|It
operator|>
name|void
name|setProgramArguments
argument_list|(
argument|It I
argument_list|,
argument|It E
argument_list|)
block|{
name|ProgramArguments
operator|.
name|assign
argument_list|(
name|I
argument_list|,
name|E
argument_list|)
block|;     }
name|unsigned
name|getNumProgramArguments
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|ProgramArguments
operator|.
name|size
argument_list|()
operator|)
return|;
block|}
specifier|const
name|std
operator|::
name|string
operator|&
name|getProgramArgument
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
return|return
name|ProgramArguments
index|[
name|i
index|]
return|;
block|}
comment|//===------------------------------------------------------------------===//
comment|// Methods for manipulating and inspecting the program currently loaded.
comment|//
comment|/// isProgramLoaded - Return true if there is a program currently loaded.
comment|///
name|bool
name|isProgramLoaded
argument_list|()
specifier|const
block|{
return|return
name|Program
operator|!=
literal|0
return|;
block|}
comment|/// getProgram - Return the LLVM module corresponding to the program.
comment|///
name|Module
operator|*
name|getProgram
argument_list|()
specifier|const
block|{
return|return
name|Program
return|;
block|}
comment|/// getProgramPath - Get the path of the currently loaded program, or an
comment|/// empty string if none is loaded.
name|std
operator|::
name|string
name|getProgramPath
argument_list|()
specifier|const
expr_stmt|;
comment|/// loadProgram - If a program is currently loaded, unload it.  Then search
comment|/// the PATH for the specified program, loading it when found.  If the
comment|/// specified program cannot be found, an exception is thrown to indicate
comment|/// the error.
name|void
name|loadProgram
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Path
argument_list|)
decl_stmt|;
comment|/// unloadProgram - If a program is running, kill it, then unload all traces
comment|/// of the current program.  If no program is loaded, this method silently
comment|/// succeeds.
name|void
name|unloadProgram
parameter_list|()
function_decl|;
comment|//===------------------------------------------------------------------===//
comment|// Methods for manipulating and inspecting the program currently running.
comment|//
comment|// If the program is running, and the debugger is active, then we know that
comment|// the program has stopped.  This being the case, we can inspect the
comment|// program, ask it for its source location, set breakpoints, etc.
comment|//
comment|/// isProgramRunning - Return true if a program is loaded and has a
comment|/// currently active instance.
name|bool
name|isProgramRunning
argument_list|()
specifier|const
block|{
return|return
name|Process
operator|!=
literal|0
return|;
block|}
comment|/// getRunningProcess - If there is no program running, throw an exception.
comment|/// Otherwise return the running process so that it can be inspected by the
comment|/// debugger.
specifier|const
name|InferiorProcess
operator|&
name|getRunningProcess
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Process
operator|==
literal|0
condition|)
name|throw
literal|"No process running."
expr_stmt|;
return|return
operator|*
name|Process
return|;
block|}
comment|/// createProgram - Create an instance of the currently loaded program,
comment|/// killing off any existing one.  This creates the program and stops it at
comment|/// the first possible moment.  If there is no program loaded or if there is
comment|/// a problem starting the program, this method throws an exception.
name|void
name|createProgram
parameter_list|()
function_decl|;
comment|/// killProgram - If the program is currently executing, kill off the
comment|/// process and free up any state related to the currently running program.
comment|/// If there is no program currently running, this just silently succeeds.
comment|/// If something horrible happens when killing the program, an exception
comment|/// gets thrown.
name|void
name|killProgram
parameter_list|()
function_decl|;
comment|//===------------------------------------------------------------------===//
comment|// Methods for continuing execution.  These methods continue the execution
comment|// of the program by some amount.  If the program is successfully stopped,
comment|// execution returns, otherwise an exception is thrown.
comment|//
comment|// NOTE: These methods should always be used in preference to directly
comment|// accessing the Dbg object, because these will delete the Process object if
comment|// the process unexpectedly dies.
comment|//
comment|/// stepProgram - Implement the 'step' command, continuing execution until
comment|/// the next possible stop point.
name|void
name|stepProgram
parameter_list|()
function_decl|;
comment|/// nextProgram - Implement the 'next' command, continuing execution until
comment|/// the next possible stop point that is in the current function.
name|void
name|nextProgram
parameter_list|()
function_decl|;
comment|/// finishProgram - Implement the 'finish' command, continuing execution
comment|/// until the specified frame ID returns.
name|void
name|finishProgram
parameter_list|(
name|void
modifier|*
name|Frame
parameter_list|)
function_decl|;
comment|/// contProgram - Implement the 'cont' command, continuing execution until
comment|/// the next breakpoint is encountered.
name|void
name|contProgram
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|NonErrorException
block|{
name|std
operator|::
name|string
name|Message
expr_stmt|;
name|public
label|:
name|NonErrorException
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|M
argument_list|)
operator|:
name|Message
argument_list|(
argument|M
argument_list|)
block|{}
specifier|const
name|std
operator|::
name|string
operator|&
name|getMessage
argument_list|()
specifier|const
block|{
return|return
name|Message
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

