begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CLIDebugger.h - LLVM Command Line Interface Debugger -----*- C++ -*-===//
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
comment|// This file defines the CLIDebugger class, which implements a command line
end_comment

begin_comment
comment|// interface to the LLVM Debugger library.
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
name|CLIDEBUGGER_H
end_ifndef

begin_define
define|#
directive|define
name|CLIDEBUGGER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Debugger/Debugger.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|CLICommand
decl_stmt|;
name|class
name|SourceFile
decl_stmt|;
name|class
name|SourceLanguage
decl_stmt|;
name|class
name|ProgramInfo
decl_stmt|;
name|class
name|RuntimeInfo
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
comment|/// CLIDebugger - This class implements the command line interface for the
comment|/// LLVM debugger.
name|class
name|CLIDebugger
block|{
name|LLVMContext
modifier|&
name|Context
decl_stmt|;
comment|/// Dbg - The low-level LLVM debugger object that we use to do our dirty
comment|/// work.
name|Debugger
name|Dbg
decl_stmt|;
comment|/// CommandTable - This table contains a mapping from command names to the
comment|/// CLICommand object that implements the command.
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
operator|,
name|CLICommand
operator|*
operator|>
name|CommandTable
expr_stmt|;
comment|//===------------------------------------------------------------------===//
comment|// Data related to the program that is currently loaded.  Note that the Dbg
comment|// variable also captures some information about the loaded program.  This
comment|// pointer is non-null iff Dbg.isProgramLoaded() is true.
comment|//
name|ProgramInfo
modifier|*
name|TheProgramInfo
decl_stmt|;
comment|//===------------------------------------------------------------------===//
comment|// Data related to the program that is currently executing, but has stopped.
comment|// Note that the Dbg variable also captures some information about the
comment|// loaded program.  This pointer is non-null iff Dbg.isProgramRunning() is
comment|// true.
comment|//
name|RuntimeInfo
modifier|*
name|TheRuntimeInfo
decl_stmt|;
comment|/// LastCurrentFrame - This variable holds the Frame ID of the top-level
comment|/// stack frame from the last time that the program was executed.  We keep
comment|/// this because we only want to print the source location when the current
comment|/// function changes.
name|void
modifier|*
name|LastCurrentFrame
decl_stmt|;
comment|//===------------------------------------------------------------------===//
comment|// Data directly exposed through the debugger prompt
comment|//
name|std
operator|::
name|string
name|Prompt
expr_stmt|;
comment|// set prompt, show prompt
name|unsigned
name|ListSize
decl_stmt|;
comment|// set listsize, show listsize
comment|//===------------------------------------------------------------------===//
comment|// Data to support user interaction
comment|//
comment|/// CurrentFile - The current source file we are inspecting, or null if
comment|/// none.
specifier|const
name|SourceFile
modifier|*
name|CurrentFile
decl_stmt|;
name|unsigned
name|LineListedStart
decl_stmt|,
name|LineListedEnd
decl_stmt|;
comment|/// CurrentLanguage - This contains the source language in use, if one is
comment|/// explicitly set by the user.  If this is null (the default), the language
comment|/// is automatically determined from the current stack frame.
comment|///
specifier|const
name|SourceLanguage
modifier|*
name|CurrentLanguage
decl_stmt|;
name|public
label|:
name|CLIDebugger
argument_list|(
name|LLVMContext
operator|&
name|ctxt
argument_list|)
expr_stmt|;
comment|/// getDebugger - Return the current LLVM debugger implementation being
comment|/// used.
name|Debugger
modifier|&
name|getDebugger
parameter_list|()
block|{
return|return
name|Dbg
return|;
block|}
comment|/// run - Start the debugger, returning when the user exits the debugger.
comment|/// This starts the main event loop of the CLI debugger.
comment|///
name|int
name|run
parameter_list|()
function_decl|;
comment|/// addCommand - Add a command to the CommandTable, potentially displacing a
comment|/// preexisting command.
name|void
name|addCommand
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Option
argument_list|,
name|CLICommand
operator|*
name|Cmd
argument_list|)
decl_stmt|;
comment|/// addSourceDirectory - Add a directory to search when looking for the
comment|/// source code of the program.
name|void
name|addSourceDirectory
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
comment|/// getCurrentLanguage - Return the current source language that the user is
comment|/// playing around with.  This is aquired from the current stack frame of a
comment|/// running program if one exists, but this value can be explicitly set by
comment|/// the user as well.
specifier|const
name|SourceLanguage
operator|&
name|getCurrentLanguage
argument_list|()
specifier|const
expr_stmt|;
comment|/// getProgramInfo - Return a reference to the ProgramInfo object for the
comment|/// currently loaded program.  If there is no program loaded, throw an
comment|/// exception.
name|ProgramInfo
operator|&
name|getProgramInfo
argument_list|()
specifier|const
block|{
if|if
condition|(
name|TheProgramInfo
operator|==
literal|0
condition|)
name|throw
literal|"No program is loaded."
expr_stmt|;
return|return
operator|*
name|TheProgramInfo
return|;
block|}
comment|/// getRuntimeInfo - Return a reference to the current RuntimeInfo object.
comment|/// If there is no program running, throw an exception.
name|RuntimeInfo
operator|&
name|getRuntimeInfo
argument_list|()
specifier|const
block|{
if|if
condition|(
name|TheRuntimeInfo
operator|==
literal|0
condition|)
name|throw
literal|"No program is running."
expr_stmt|;
return|return
operator|*
name|TheRuntimeInfo
return|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|// Internal implementation methods
end_comment

begin_comment
comment|/// getCommand - This looks up the specified command using a fuzzy match.
end_comment

begin_comment
comment|/// If the string exactly matches a command or is an unambiguous prefix of a
end_comment

begin_comment
comment|/// command, it returns the command.  Otherwise it throws an exception
end_comment

begin_comment
comment|/// indicating the possible ambiguous choices.
end_comment

begin_decl_stmt
name|CLICommand
modifier|*
name|getCommand
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Command
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// askYesNo - Ask the user a question, and demand a yes/no response.  If
end_comment

begin_comment
comment|/// the user says yes, return true.
end_comment

begin_decl_stmt
name|bool
name|askYesNo
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Message
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// printProgramLocation - Given a loaded and created child process that has
end_comment

begin_comment
comment|/// stopped, print its current source location.
end_comment

begin_function_decl
name|void
name|printProgramLocation
parameter_list|(
name|bool
name|PrintLocation
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// eliminateRunInfo - We are about to run the program.  Forget any state
end_comment

begin_comment
comment|/// about how the program used to be stopped.
end_comment

begin_function_decl
name|void
name|eliminateRunInfo
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// programStoppedSuccessfully - This method updates internal data
end_comment

begin_comment
comment|/// structures to reflect the fact that the program just executed a while,
end_comment

begin_comment
comment|/// and has successfully stopped.
end_comment

begin_function_decl
name|void
name|programStoppedSuccessfully
parameter_list|()
function_decl|;
end_function_decl

begin_label
name|public
label|:
end_label

begin_comment
comment|/// Builtin debugger commands, invokable by the user
end_comment

begin_comment
comment|// Program startup and shutdown options
end_comment

begin_decl_stmt
name|void
name|fileCommand
argument_list|(
name|std
operator|::
name|string
operator|&
name|Options
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// file
end_comment

begin_decl_stmt
name|void
name|createCommand
argument_list|(
name|std
operator|::
name|string
operator|&
name|Options
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// create
end_comment

begin_decl_stmt
name|void
name|killCommand
argument_list|(
name|std
operator|::
name|string
operator|&
name|Options
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// kill
end_comment

begin_decl_stmt
name|void
name|quitCommand
argument_list|(
name|std
operator|::
name|string
operator|&
name|Options
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// quit
end_comment

begin_comment
comment|// Program execution commands
end_comment

begin_decl_stmt
name|void
name|runCommand
argument_list|(
name|std
operator|::
name|string
operator|&
name|Options
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// run|r
end_comment

begin_decl_stmt
name|void
name|contCommand
argument_list|(
name|std
operator|::
name|string
operator|&
name|Options
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// cont|c|fg
end_comment

begin_decl_stmt
name|void
name|stepCommand
argument_list|(
name|std
operator|::
name|string
operator|&
name|Options
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// step|s [count]
end_comment

begin_decl_stmt
name|void
name|nextCommand
argument_list|(
name|std
operator|::
name|string
operator|&
name|Options
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// next|n [count]
end_comment

begin_decl_stmt
name|void
name|finishCommand
argument_list|(
name|std
operator|::
name|string
operator|&
name|Options
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// finish
end_comment

begin_comment
comment|// Stack frame commands
end_comment

begin_decl_stmt
name|void
name|backtraceCommand
argument_list|(
name|std
operator|::
name|string
operator|&
name|Options
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// backtrace|bt [count]
end_comment

begin_decl_stmt
name|void
name|upCommand
argument_list|(
name|std
operator|::
name|string
operator|&
name|Options
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// up
end_comment

begin_decl_stmt
name|void
name|downCommand
argument_list|(
name|std
operator|::
name|string
operator|&
name|Options
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// down
end_comment

begin_decl_stmt
name|void
name|frameCommand
argument_list|(
name|std
operator|::
name|string
operator|&
name|Options
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// frame
end_comment

begin_comment
comment|// Breakpoint related commands
end_comment

begin_decl_stmt
name|void
name|breakCommand
argument_list|(
name|std
operator|::
name|string
operator|&
name|Options
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// break|b<id>
end_comment

begin_comment
comment|// Miscellaneous commands
end_comment

begin_decl_stmt
name|void
name|infoCommand
argument_list|(
name|std
operator|::
name|string
operator|&
name|Options
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// info
end_comment

begin_decl_stmt
name|void
name|listCommand
argument_list|(
name|std
operator|::
name|string
operator|&
name|Options
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// list
end_comment

begin_decl_stmt
name|void
name|setCommand
argument_list|(
name|std
operator|::
name|string
operator|&
name|Options
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// set
end_comment

begin_decl_stmt
name|void
name|showCommand
argument_list|(
name|std
operator|::
name|string
operator|&
name|Options
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// show
end_comment

begin_decl_stmt
name|void
name|helpCommand
argument_list|(
name|std
operator|::
name|string
operator|&
name|Options
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// help
end_comment

begin_label
name|private
label|:
end_label

begin_comment
comment|/// startProgramRunning - If the program has been updated, reload it, then
end_comment

begin_comment
comment|/// start executing the program.
end_comment

begin_function_decl
name|void
name|startProgramRunning
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// printSourceLine - Print the specified line of the current source file.
end_comment

begin_comment
comment|/// If the specified line is invalid (the source file could not be loaded or
end_comment

begin_comment
comment|/// the line number is out of range), don't print anything, but return true.
end_comment

begin_function_decl
name|bool
name|printSourceLine
parameter_list|(
name|unsigned
name|LineNo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// parseLineSpec - Parses a line specifier, for use by the 'list' command.
end_comment

begin_comment
comment|/// If SourceFile is returned as a void pointer, then it was not specified.
end_comment

begin_comment
comment|/// If the line specifier is invalid, an exception is thrown.
end_comment

begin_decl_stmt
name|void
name|parseLineSpec
argument_list|(
name|std
operator|::
name|string
operator|&
name|LineSpec
argument_list|,
specifier|const
name|SourceFile
operator|*
operator|&
name|SourceFile
argument_list|,
name|unsigned
operator|&
name|LineNo
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// parseProgramOptions - This method parses the Options string and loads it
end_comment

begin_comment
comment|/// as options to be passed to the program.  This is used by the run command
end_comment

begin_comment
comment|/// and by 'set args'.
end_comment

begin_decl_stmt
name|void
name|parseProgramOptions
argument_list|(
name|std
operator|::
name|string
operator|&
name|Options
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
unit|}; }
endif|#
directive|endif
end_endif

end_unit

