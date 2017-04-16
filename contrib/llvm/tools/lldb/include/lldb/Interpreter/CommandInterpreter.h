begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CommandInterpreter.h ------------------------------------*- C++ -*-===//
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
name|liblldb_CommandInterpreter_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_CommandInterpreter_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<mutex>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Core/Broadcaster.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Debugger.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Event.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/IOHandler.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Interpreter/Args.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Interpreter/CommandAlias.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Interpreter/CommandHistory.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Interpreter/CommandObject.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Interpreter/ScriptInterpreter.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Log.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/StringList.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|CommandInterpreterRunOptions
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Construct a CommandInterpreterRunOptions object.
comment|/// This class is used to control all the instances where we run multiple
comment|/// commands, e.g.
comment|/// HandleCommands, HandleCommandsFromFile, RunCommandInterpreter.
comment|/// The meanings of the options in this object are:
comment|///
comment|/// @param[in] stop_on_continue
comment|///    If \b true execution will end on the first command that causes the
comment|///    process in the
comment|///    execution context to continue.  If \false, we won't check the execution
comment|///    status.
comment|/// @param[in] stop_on_error
comment|///    If \b true execution will end on the first command that causes an
comment|///    error.
comment|/// @param[in] stop_on_crash
comment|///    If \b true when a command causes the target to run, and the end of the
comment|///    run is a
comment|///    signal or exception, stop executing the commands.
comment|/// @param[in] echo_commands
comment|///    If \b true echo the command before executing it.  If \false, execute
comment|///    silently.
comment|/// @param[in] print_results
comment|///    If \b true print the results of the command after executing it.  If
comment|///    \false, execute silently.
comment|/// @param[in] add_to_history
comment|///    If \b true add the commands to the command history.  If \false, don't
comment|///    add them.
comment|//------------------------------------------------------------------
name|CommandInterpreterRunOptions
argument_list|(
argument|LazyBool stop_on_continue
argument_list|,
argument|LazyBool stop_on_error
argument_list|,
argument|LazyBool stop_on_crash
argument_list|,
argument|LazyBool echo_commands
argument_list|,
argument|LazyBool print_results
argument_list|,
argument|LazyBool add_to_history
argument_list|)
block|:
name|m_stop_on_continue
argument_list|(
name|stop_on_continue
argument_list|)
operator|,
name|m_stop_on_error
argument_list|(
name|stop_on_error
argument_list|)
operator|,
name|m_stop_on_crash
argument_list|(
name|stop_on_crash
argument_list|)
operator|,
name|m_echo_commands
argument_list|(
name|echo_commands
argument_list|)
operator|,
name|m_print_results
argument_list|(
name|print_results
argument_list|)
operator|,
name|m_add_to_history
argument_list|(
argument|add_to_history
argument_list|)
block|{}
name|CommandInterpreterRunOptions
argument_list|()
operator|:
name|m_stop_on_continue
argument_list|(
name|eLazyBoolCalculate
argument_list|)
operator|,
name|m_stop_on_error
argument_list|(
name|eLazyBoolCalculate
argument_list|)
operator|,
name|m_stop_on_crash
argument_list|(
name|eLazyBoolCalculate
argument_list|)
operator|,
name|m_echo_commands
argument_list|(
name|eLazyBoolCalculate
argument_list|)
operator|,
name|m_print_results
argument_list|(
name|eLazyBoolCalculate
argument_list|)
operator|,
name|m_add_to_history
argument_list|(
argument|eLazyBoolCalculate
argument_list|)
block|{}
name|void
name|SetSilent
argument_list|(
argument|bool silent
argument_list|)
block|{
name|LazyBool
name|value
operator|=
name|silent
operator|?
name|eLazyBoolNo
operator|:
name|eLazyBoolYes
block|;
name|m_echo_commands
operator|=
name|value
block|;
name|m_print_results
operator|=
name|value
block|;
name|m_add_to_history
operator|=
name|value
block|;   }
comment|// These return the default behaviors if the behavior is not
comment|// eLazyBoolCalculate.
comment|// But I've also left the ivars public since for different ways of running the
comment|// interpreter you might want to force different defaults...  In that case,
comment|// just grab
comment|// the LazyBool ivars directly and do what you want with eLazyBoolCalculate.
name|bool
name|GetStopOnContinue
argument_list|()
specifier|const
block|{
return|return
name|DefaultToNo
argument_list|(
name|m_stop_on_continue
argument_list|)
return|;
block|}
name|void
name|SetStopOnContinue
parameter_list|(
name|bool
name|stop_on_continue
parameter_list|)
block|{
name|m_stop_on_continue
operator|=
name|stop_on_continue
condition|?
name|eLazyBoolYes
else|:
name|eLazyBoolNo
expr_stmt|;
block|}
name|bool
name|GetStopOnError
argument_list|()
specifier|const
block|{
return|return
name|DefaultToNo
argument_list|(
name|m_stop_on_continue
argument_list|)
return|;
block|}
name|void
name|SetStopOnError
parameter_list|(
name|bool
name|stop_on_error
parameter_list|)
block|{
name|m_stop_on_error
operator|=
name|stop_on_error
condition|?
name|eLazyBoolYes
else|:
name|eLazyBoolNo
expr_stmt|;
block|}
name|bool
name|GetStopOnCrash
argument_list|()
specifier|const
block|{
return|return
name|DefaultToNo
argument_list|(
name|m_stop_on_crash
argument_list|)
return|;
block|}
name|void
name|SetStopOnCrash
parameter_list|(
name|bool
name|stop_on_crash
parameter_list|)
block|{
name|m_stop_on_crash
operator|=
name|stop_on_crash
condition|?
name|eLazyBoolYes
else|:
name|eLazyBoolNo
expr_stmt|;
block|}
name|bool
name|GetEchoCommands
argument_list|()
specifier|const
block|{
return|return
name|DefaultToYes
argument_list|(
name|m_echo_commands
argument_list|)
return|;
block|}
name|void
name|SetEchoCommands
parameter_list|(
name|bool
name|echo_commands
parameter_list|)
block|{
name|m_echo_commands
operator|=
name|echo_commands
condition|?
name|eLazyBoolYes
else|:
name|eLazyBoolNo
expr_stmt|;
block|}
name|bool
name|GetPrintResults
argument_list|()
specifier|const
block|{
return|return
name|DefaultToYes
argument_list|(
name|m_print_results
argument_list|)
return|;
block|}
name|void
name|SetPrintResults
parameter_list|(
name|bool
name|print_results
parameter_list|)
block|{
name|m_print_results
operator|=
name|print_results
condition|?
name|eLazyBoolYes
else|:
name|eLazyBoolNo
expr_stmt|;
block|}
name|bool
name|GetAddToHistory
argument_list|()
specifier|const
block|{
return|return
name|DefaultToYes
argument_list|(
name|m_add_to_history
argument_list|)
return|;
block|}
name|void
name|SetAddToHistory
parameter_list|(
name|bool
name|add_to_history
parameter_list|)
block|{
name|m_add_to_history
operator|=
name|add_to_history
condition|?
name|eLazyBoolYes
else|:
name|eLazyBoolNo
expr_stmt|;
block|}
name|LazyBool
name|m_stop_on_continue
decl_stmt|;
name|LazyBool
name|m_stop_on_error
decl_stmt|;
name|LazyBool
name|m_stop_on_crash
decl_stmt|;
name|LazyBool
name|m_echo_commands
decl_stmt|;
name|LazyBool
name|m_print_results
decl_stmt|;
name|LazyBool
name|m_add_to_history
decl_stmt|;
name|private
label|:
specifier|static
name|bool
name|DefaultToYes
parameter_list|(
name|LazyBool
name|flag
parameter_list|)
block|{
switch|switch
condition|(
name|flag
condition|)
block|{
case|case
name|eLazyBoolNo
case|:
return|return
name|false
return|;
default|default:
return|return
name|true
return|;
block|}
block|}
specifier|static
name|bool
name|DefaultToNo
parameter_list|(
name|LazyBool
name|flag
parameter_list|)
block|{
switch|switch
condition|(
name|flag
condition|)
block|{
case|case
name|eLazyBoolYes
case|:
return|return
name|true
return|;
default|default:
return|return
name|false
return|;
block|}
block|}
block|}
empty_stmt|;
name|class
name|CommandInterpreter
range|:
name|public
name|Broadcaster
decl_stmt|,
name|public
name|Properties
decl_stmt|,
name|public
name|IOHandlerDelegate
block|{
name|public
label|:
enum|enum
block|{
name|eBroadcastBitThreadShouldExit
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|eBroadcastBitResetPrompt
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|eBroadcastBitQuitCommandReceived
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
comment|// User entered quit
name|eBroadcastBitAsynchronousOutputData
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
name|eBroadcastBitAsynchronousErrorData
init|=
operator|(
literal|1
operator|<<
literal|4
operator|)
block|}
enum|;
enum|enum
name|ChildrenTruncatedWarningStatus
comment|// tristate boolean to manage children
comment|// truncation warning
block|{
name|eNoTruncation
init|=
literal|0
block|,
comment|// never truncated
name|eUnwarnedTruncation
init|=
literal|1
block|,
comment|// truncated but did not notify
name|eWarnedTruncation
init|=
literal|2
comment|// truncated and notified
block|}
enum|;
enum|enum
name|CommandTypes
block|{
name|eCommandTypesBuiltin
init|=
literal|0x0001
block|,
comment|// native commands such as "frame"
name|eCommandTypesUserDef
init|=
literal|0x0002
block|,
comment|// scripted commands
name|eCommandTypesAliases
init|=
literal|0x0004
block|,
comment|// aliases such as "po"
name|eCommandTypesHidden
init|=
literal|0x0008
block|,
comment|// commands prefixed with an underscore
name|eCommandTypesAllThem
init|=
literal|0xFFFF
comment|// all commands
block|}
enum|;
name|CommandInterpreter
argument_list|(
argument|Debugger&debugger
argument_list|,
argument|lldb::ScriptLanguage script_language
argument_list|,
argument|bool synchronous_execution
argument_list|)
empty_stmt|;
operator|~
name|CommandInterpreter
argument_list|()
name|override
expr_stmt|;
comment|// These two functions fill out the Broadcaster interface:
specifier|static
name|ConstString
modifier|&
name|GetStaticBroadcasterClass
parameter_list|()
function_decl|;
name|ConstString
operator|&
name|GetBroadcasterClass
argument_list|()
specifier|const
name|override
block|{
return|return
name|GetStaticBroadcasterClass
argument_list|()
return|;
block|}
name|void
name|SourceInitFile
parameter_list|(
name|bool
name|in_cwd
parameter_list|,
name|CommandReturnObject
modifier|&
name|result
parameter_list|)
function_decl|;
name|bool
name|AddCommand
argument_list|(
name|llvm
operator|::
name|StringRef
name|name
argument_list|,
specifier|const
name|lldb
operator|::
name|CommandObjectSP
operator|&
name|cmd_sp
argument_list|,
name|bool
name|can_replace
argument_list|)
decl_stmt|;
name|bool
name|AddUserCommand
argument_list|(
name|llvm
operator|::
name|StringRef
name|name
argument_list|,
specifier|const
name|lldb
operator|::
name|CommandObjectSP
operator|&
name|cmd_sp
argument_list|,
name|bool
name|can_replace
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|CommandObjectSP
name|GetCommandSPExact
argument_list|(
argument|llvm::StringRef cmd
argument_list|,
argument|bool include_aliases
argument_list|)
specifier|const
expr_stmt|;
name|CommandObject
modifier|*
name|GetCommandObject
argument_list|(
name|llvm
operator|::
name|StringRef
name|cmd
argument_list|,
name|StringList
operator|*
name|matches
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
name|bool
name|CommandExists
argument_list|(
name|llvm
operator|::
name|StringRef
name|cmd
argument_list|)
decl|const
decl_stmt|;
name|bool
name|AliasExists
argument_list|(
name|llvm
operator|::
name|StringRef
name|cmd
argument_list|)
decl|const
decl_stmt|;
name|bool
name|UserCommandExists
argument_list|(
name|llvm
operator|::
name|StringRef
name|cmd
argument_list|)
decl|const
decl_stmt|;
name|CommandAlias
modifier|*
name|AddAlias
argument_list|(
name|llvm
operator|::
name|StringRef
name|alias_name
argument_list|,
name|lldb
operator|::
name|CommandObjectSP
operator|&
name|command_obj_sp
argument_list|,
name|llvm
operator|::
name|StringRef
name|args_string
operator|=
name|llvm
operator|::
name|StringRef
argument_list|()
argument_list|)
decl_stmt|;
comment|// Remove a command if it is removable (python or regex command)
name|bool
name|RemoveCommand
argument_list|(
name|llvm
operator|::
name|StringRef
name|cmd
argument_list|)
decl_stmt|;
name|bool
name|RemoveAlias
argument_list|(
name|llvm
operator|::
name|StringRef
name|alias_name
argument_list|)
decl_stmt|;
name|bool
name|GetAliasFullName
argument_list|(
name|llvm
operator|::
name|StringRef
name|cmd
argument_list|,
name|std
operator|::
name|string
operator|&
name|full_name
argument_list|)
decl|const
decl_stmt|;
name|bool
name|RemoveUser
argument_list|(
name|llvm
operator|::
name|StringRef
name|alias_name
argument_list|)
decl_stmt|;
name|void
name|RemoveAllUser
parameter_list|()
block|{
name|m_user_dict
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
specifier|const
name|CommandAlias
modifier|*
name|GetAlias
argument_list|(
name|llvm
operator|::
name|StringRef
name|alias_name
argument_list|)
decl|const
decl_stmt|;
name|CommandObject
modifier|*
name|BuildAliasResult
argument_list|(
name|llvm
operator|::
name|StringRef
name|alias_name
argument_list|,
name|std
operator|::
name|string
operator|&
name|raw_input_string
argument_list|,
name|std
operator|::
name|string
operator|&
name|alias_result
argument_list|,
name|CommandReturnObject
operator|&
name|result
argument_list|)
decl_stmt|;
name|bool
name|HandleCommand
parameter_list|(
specifier|const
name|char
modifier|*
name|command_line
parameter_list|,
name|LazyBool
name|add_to_history
parameter_list|,
name|CommandReturnObject
modifier|&
name|result
parameter_list|,
name|ExecutionContext
modifier|*
name|override_context
init|=
name|nullptr
parameter_list|,
name|bool
name|repeat_on_empty_command
init|=
name|true
parameter_list|,
name|bool
name|no_context_switching
init|=
name|false
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Execute a list of commands in sequence.
comment|///
comment|/// @param[in] commands
comment|///    The list of commands to execute.
comment|/// @param[in,out] context
comment|///    The execution context in which to run the commands. Can be nullptr in
comment|///    which case the default
comment|///    context will be used.
comment|/// @param[in] options
comment|///    This object holds the options used to control when to stop, whether to
comment|///    execute commands,
comment|///    etc.
comment|/// @param[out] result
comment|///    This is marked as succeeding with no output if all commands execute
comment|///    safely,
comment|///    and failed with some explanation if we aborted executing the commands
comment|///    at some point.
comment|//------------------------------------------------------------------
name|void
name|HandleCommands
parameter_list|(
specifier|const
name|StringList
modifier|&
name|commands
parameter_list|,
name|ExecutionContext
modifier|*
name|context
parameter_list|,
name|CommandInterpreterRunOptions
modifier|&
name|options
parameter_list|,
name|CommandReturnObject
modifier|&
name|result
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Execute a list of commands from a file.
comment|///
comment|/// @param[in] file
comment|///    The file from which to read in commands.
comment|/// @param[in,out] context
comment|///    The execution context in which to run the commands. Can be nullptr in
comment|///    which case the default
comment|///    context will be used.
comment|/// @param[in] options
comment|///    This object holds the options used to control when to stop, whether to
comment|///    execute commands,
comment|///    etc.
comment|/// @param[out] result
comment|///    This is marked as succeeding with no output if all commands execute
comment|///    safely,
comment|///    and failed with some explanation if we aborted executing the commands
comment|///    at some point.
comment|//------------------------------------------------------------------
name|void
name|HandleCommandsFromFile
parameter_list|(
name|FileSpec
modifier|&
name|file
parameter_list|,
name|ExecutionContext
modifier|*
name|context
parameter_list|,
name|CommandInterpreterRunOptions
modifier|&
name|options
parameter_list|,
name|CommandReturnObject
modifier|&
name|result
parameter_list|)
function_decl|;
name|CommandObject
modifier|*
name|GetCommandObjectForCommand
argument_list|(
name|llvm
operator|::
name|StringRef
operator|&
name|command_line
argument_list|)
decl_stmt|;
comment|// This handles command line completion.  You are given a pointer to the
comment|// command string buffer, to the current cursor,
comment|// and to the end of the string (in case it is not NULL terminated).
comment|// You also passed in an StringList object to fill with the returns.
comment|// The first element of the array will be filled with the string that you
comment|// would need to insert at
comment|// the cursor point to complete the cursor point to the longest common
comment|// matching prefix.
comment|// If you want to limit the number of elements returned, set
comment|// max_return_elements to the number of elements
comment|// you want returned.  Otherwise set max_return_elements to -1.
comment|// If you want to start some way into the match list, then set
comment|// match_start_point to the desired start
comment|// point.
comment|// Returns:
comment|// -1 if the completion character should be inserted
comment|// -2 if the entire command line should be deleted and replaced with
comment|// matches.GetStringAtIndex(0)
comment|// INT_MAX if the number of matches is> max_return_elements, but it is
comment|// expensive to compute.
comment|// Otherwise, returns the number of matches.
comment|//
comment|// FIXME: Only max_return_elements == -1 is supported at present.
name|int
name|HandleCompletion
parameter_list|(
specifier|const
name|char
modifier|*
name|current_line
parameter_list|,
specifier|const
name|char
modifier|*
name|cursor
parameter_list|,
specifier|const
name|char
modifier|*
name|last_char
parameter_list|,
name|int
name|match_start_point
parameter_list|,
name|int
name|max_return_elements
parameter_list|,
name|StringList
modifier|&
name|matches
parameter_list|)
function_decl|;
comment|// This version just returns matches, and doesn't compute the substring.  It
comment|// is here so the
comment|// Help command can call it for the first argument.
comment|// word_complete tells whether the completions are considered a "complete"
comment|// response (so the
comment|// completer should complete the quote& put a space after the word.
name|int
name|HandleCompletionMatches
parameter_list|(
name|Args
modifier|&
name|input
parameter_list|,
name|int
modifier|&
name|cursor_index
parameter_list|,
name|int
modifier|&
name|cursor_char_position
parameter_list|,
name|int
name|match_start_point
parameter_list|,
name|int
name|max_return_elements
parameter_list|,
name|bool
modifier|&
name|word_complete
parameter_list|,
name|StringList
modifier|&
name|matches
parameter_list|)
function_decl|;
name|int
name|GetCommandNamesMatchingPartialString
parameter_list|(
specifier|const
name|char
modifier|*
name|cmd_cstr
parameter_list|,
name|bool
name|include_aliases
parameter_list|,
name|StringList
modifier|&
name|matches
parameter_list|)
function_decl|;
name|void
name|GetHelp
parameter_list|(
name|CommandReturnObject
modifier|&
name|result
parameter_list|,
name|uint32_t
name|types
init|=
name|eCommandTypesAllThem
parameter_list|)
function_decl|;
name|void
name|GetAliasHelp
parameter_list|(
specifier|const
name|char
modifier|*
name|alias_name
parameter_list|,
name|StreamString
modifier|&
name|help_string
parameter_list|)
function_decl|;
name|void
name|OutputFormattedHelpText
argument_list|(
name|Stream
operator|&
name|strm
argument_list|,
name|llvm
operator|::
name|StringRef
name|prefix
argument_list|,
name|llvm
operator|::
name|StringRef
name|help_text
argument_list|)
decl_stmt|;
name|void
name|OutputFormattedHelpText
argument_list|(
name|Stream
operator|&
name|stream
argument_list|,
name|llvm
operator|::
name|StringRef
name|command_word
argument_list|,
name|llvm
operator|::
name|StringRef
name|separator
argument_list|,
name|llvm
operator|::
name|StringRef
name|help_text
argument_list|,
name|size_t
name|max_word_len
argument_list|)
decl_stmt|;
comment|// this mimics OutputFormattedHelpText but it does perform a much simpler
comment|// formatting, basically ensuring line alignment. This is only good if you
comment|// have some complicated layout for your help text and want as little help as
comment|// reasonable in properly displaying it. Most of the times, you simply want
comment|// to type some text and have it printed in a reasonable way on screen. If
comment|// so, use OutputFormattedHelpText
name|void
name|OutputHelpText
argument_list|(
name|Stream
operator|&
name|stream
argument_list|,
name|llvm
operator|::
name|StringRef
name|command_word
argument_list|,
name|llvm
operator|::
name|StringRef
name|separator
argument_list|,
name|llvm
operator|::
name|StringRef
name|help_text
argument_list|,
name|uint32_t
name|max_word_len
argument_list|)
decl_stmt|;
name|Debugger
modifier|&
name|GetDebugger
parameter_list|()
block|{
return|return
name|m_debugger
return|;
block|}
name|ExecutionContext
name|GetExecutionContext
parameter_list|()
block|{
specifier|const
name|bool
name|thread_and_frame_only_if_stopped
init|=
name|true
decl_stmt|;
return|return
name|m_exe_ctx_ref
operator|.
name|Lock
argument_list|(
name|thread_and_frame_only_if_stopped
argument_list|)
return|;
block|}
name|void
name|UpdateExecutionContext
parameter_list|(
name|ExecutionContext
modifier|*
name|override_context
parameter_list|)
function_decl|;
name|lldb
operator|::
name|PlatformSP
name|GetPlatform
argument_list|(
argument|bool prefer_target_platform
argument_list|)
expr_stmt|;
specifier|const
name|char
modifier|*
name|ProcessEmbeddedScriptCommands
parameter_list|(
specifier|const
name|char
modifier|*
name|arg
parameter_list|)
function_decl|;
name|void
name|UpdatePrompt
argument_list|(
name|llvm
operator|::
name|StringRef
name|prompt
argument_list|)
decl_stmt|;
name|bool
name|Confirm
argument_list|(
name|llvm
operator|::
name|StringRef
name|message
argument_list|,
name|bool
name|default_answer
argument_list|)
decl_stmt|;
name|void
name|LoadCommandDictionary
parameter_list|()
function_decl|;
name|void
name|Initialize
parameter_list|()
function_decl|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|void
name|SetScriptLanguage
argument_list|(
name|lldb
operator|::
name|ScriptLanguage
name|lang
argument_list|)
decl_stmt|;
name|bool
name|HasCommands
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|HasAliases
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|HasUserCommands
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|HasAliasOptions
argument_list|()
specifier|const
expr_stmt|;
name|void
name|BuildAliasCommandArgs
argument_list|(
name|CommandObject
operator|*
name|alias_cmd_obj
argument_list|,
specifier|const
name|char
operator|*
name|alias_name
argument_list|,
name|Args
operator|&
name|cmd_args
argument_list|,
name|std
operator|::
name|string
operator|&
name|raw_input_string
argument_list|,
name|CommandReturnObject
operator|&
name|result
argument_list|)
decl_stmt|;
name|int
name|GetOptionArgumentPosition
parameter_list|(
specifier|const
name|char
modifier|*
name|in_string
parameter_list|)
function_decl|;
name|ScriptInterpreter
modifier|*
name|GetScriptInterpreter
parameter_list|(
name|bool
name|can_create
init|=
name|true
parameter_list|)
function_decl|;
name|void
name|SetScriptInterpreter
parameter_list|()
function_decl|;
name|void
name|SkipLLDBInitFiles
parameter_list|(
name|bool
name|skip_lldbinit_files
parameter_list|)
block|{
name|m_skip_lldbinit_files
operator|=
name|skip_lldbinit_files
expr_stmt|;
block|}
name|void
name|SkipAppInitFiles
parameter_list|(
name|bool
name|skip_app_init_files
parameter_list|)
block|{
name|m_skip_app_init_files
operator|=
name|m_skip_lldbinit_files
expr_stmt|;
block|}
name|bool
name|GetSynchronous
parameter_list|()
function_decl|;
name|void
name|FindCommandsForApropos
argument_list|(
name|llvm
operator|::
name|StringRef
name|word
argument_list|,
name|StringList
operator|&
name|commands_found
argument_list|,
name|StringList
operator|&
name|commands_help
argument_list|,
name|bool
name|search_builtin_commands
argument_list|,
name|bool
name|search_user_commands
argument_list|,
name|bool
name|search_alias_commands
argument_list|)
decl_stmt|;
name|bool
name|GetBatchCommandMode
parameter_list|()
block|{
return|return
name|m_batch_command_mode
return|;
block|}
name|bool
name|SetBatchCommandMode
parameter_list|(
name|bool
name|value
parameter_list|)
block|{
specifier|const
name|bool
name|old_value
init|=
name|m_batch_command_mode
decl_stmt|;
name|m_batch_command_mode
operator|=
name|value
expr_stmt|;
return|return
name|old_value
return|;
block|}
name|void
name|ChildrenTruncated
parameter_list|()
block|{
if|if
condition|(
name|m_truncation_warning
operator|==
name|eNoTruncation
condition|)
name|m_truncation_warning
operator|=
name|eUnwarnedTruncation
expr_stmt|;
block|}
name|bool
name|TruncationWarningNecessary
parameter_list|()
block|{
return|return
operator|(
name|m_truncation_warning
operator|==
name|eUnwarnedTruncation
operator|)
return|;
block|}
name|void
name|TruncationWarningGiven
parameter_list|()
block|{
name|m_truncation_warning
operator|=
name|eWarnedTruncation
expr_stmt|;
block|}
specifier|const
name|char
modifier|*
name|TruncationWarningText
parameter_list|()
block|{
return|return
literal|"*** Some of your variables have more members than the debugger "
literal|"will show by default. To show all of them, you can either use the "
literal|"--show-all-children option to %s or raise the limit by changing "
literal|"the target.max-children-count setting.\n"
return|;
block|}
specifier|const
name|CommandHistory
operator|&
name|GetCommandHistory
argument_list|()
specifier|const
block|{
return|return
name|m_command_history
return|;
block|}
name|CommandHistory
modifier|&
name|GetCommandHistory
parameter_list|()
block|{
return|return
name|m_command_history
return|;
block|}
name|bool
name|IsActive
parameter_list|()
function_decl|;
name|void
name|RunCommandInterpreter
parameter_list|(
name|bool
name|auto_handle_events
parameter_list|,
name|bool
name|spawn_thread
parameter_list|,
name|CommandInterpreterRunOptions
modifier|&
name|options
parameter_list|)
function_decl|;
name|void
name|GetLLDBCommandsFromIOHandler
parameter_list|(
specifier|const
name|char
modifier|*
name|prompt
parameter_list|,
name|IOHandlerDelegate
modifier|&
name|delegate
parameter_list|,
name|bool
name|asynchronously
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|)
function_decl|;
name|void
name|GetPythonCommandsFromIOHandler
parameter_list|(
specifier|const
name|char
modifier|*
name|prompt
parameter_list|,
name|IOHandlerDelegate
modifier|&
name|delegate
parameter_list|,
name|bool
name|asynchronously
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|GetCommandPrefix
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|// Properties
comment|//------------------------------------------------------------------
name|bool
name|GetExpandRegexAliases
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|GetPromptOnQuit
argument_list|()
specifier|const
expr_stmt|;
name|void
name|SetPromptOnQuit
parameter_list|(
name|bool
name|b
parameter_list|)
function_decl|;
name|void
name|ResolveCommand
parameter_list|(
specifier|const
name|char
modifier|*
name|command_line
parameter_list|,
name|CommandReturnObject
modifier|&
name|result
parameter_list|)
function_decl|;
name|bool
name|GetStopCmdSourceOnError
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|GetNumErrors
argument_list|()
specifier|const
block|{
return|return
name|m_num_errors
return|;
block|}
name|bool
name|GetQuitRequested
argument_list|()
specifier|const
block|{
return|return
name|m_quit_requested
return|;
block|}
name|lldb
operator|::
name|IOHandlerSP
name|GetIOHandler
argument_list|(
argument|bool force_create = false
argument_list|,
argument|CommandInterpreterRunOptions *options = nullptr
argument_list|)
expr_stmt|;
name|bool
name|GetStoppedForCrash
argument_list|()
specifier|const
block|{
return|return
name|m_stopped_for_crash
return|;
block|}
name|bool
name|GetSpaceReplPrompts
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
name|friend
name|class
name|Debugger
decl_stmt|;
comment|//------------------------------------------------------------------
comment|// IOHandlerDelegate functions
comment|//------------------------------------------------------------------
name|void
name|IOHandlerInputComplete
argument_list|(
name|IOHandler
operator|&
name|io_handler
argument_list|,
name|std
operator|::
name|string
operator|&
name|line
argument_list|)
name|override
decl_stmt|;
name|ConstString
name|IOHandlerGetControlSequence
parameter_list|(
name|char
name|ch
parameter_list|)
function|override
block|{
if|if
condition|(
name|ch
operator|==
literal|'d'
condition|)
return|return
name|ConstString
argument_list|(
literal|"quit\n"
argument_list|)
return|;
return|return
name|ConstString
argument_list|()
return|;
block|}
name|bool
name|IOHandlerInterrupt
argument_list|(
name|IOHandler
operator|&
name|io_handler
argument_list|)
name|override
decl_stmt|;
name|size_t
name|GetProcessOutput
parameter_list|()
function_decl|;
name|void
name|SetSynchronous
parameter_list|(
name|bool
name|value
parameter_list|)
function_decl|;
name|lldb
operator|::
name|CommandObjectSP
name|GetCommandSP
argument_list|(
argument|llvm::StringRef cmd
argument_list|,
argument|bool include_aliases = true
argument_list|,
argument|bool exact = true
argument_list|,
argument|StringList *matches = nullptr
argument_list|)
specifier|const
expr_stmt|;
name|private
label|:
name|Error
name|PreprocessCommand
argument_list|(
name|std
operator|::
name|string
operator|&
name|command
argument_list|)
decl_stmt|;
comment|// Completely resolves aliases and abbreviations, returning a pointer to the
comment|// final command object and updating command_line to the fully substituted
comment|// and translated command.
name|CommandObject
modifier|*
name|ResolveCommandImpl
argument_list|(
name|std
operator|::
name|string
operator|&
name|command_line
argument_list|,
name|CommandReturnObject
operator|&
name|result
argument_list|)
decl_stmt|;
name|void
name|FindCommandsForApropos
argument_list|(
name|llvm
operator|::
name|StringRef
name|word
argument_list|,
name|StringList
operator|&
name|commands_found
argument_list|,
name|StringList
operator|&
name|commands_help
argument_list|,
name|CommandObject
operator|::
name|CommandMap
operator|&
name|command_map
argument_list|)
decl_stmt|;
name|Debugger
modifier|&
name|m_debugger
decl_stmt|;
comment|// The debugger session that this interpreter is
comment|// associated with
name|ExecutionContextRef
name|m_exe_ctx_ref
decl_stmt|;
comment|// The current execution context to use
comment|// when handling commands
name|bool
name|m_synchronous_execution
decl_stmt|;
name|bool
name|m_skip_lldbinit_files
decl_stmt|;
name|bool
name|m_skip_app_init_files
decl_stmt|;
name|CommandObject
operator|::
name|CommandMap
name|m_command_dict
expr_stmt|;
comment|// Stores basic built-in commands
comment|// (they cannot be deleted, removed
comment|// or overwritten).
name|CommandObject
operator|::
name|CommandMap
name|m_alias_dict
expr_stmt|;
comment|// Stores user aliases/abbreviations for commands
name|CommandObject
operator|::
name|CommandMap
name|m_user_dict
expr_stmt|;
comment|// Stores user-defined commands
name|CommandHistory
name|m_command_history
decl_stmt|;
name|std
operator|::
name|string
name|m_repeat_command
expr_stmt|;
comment|// Stores the command that will be executed for
comment|// an empty command string.
name|lldb
operator|::
name|ScriptInterpreterSP
name|m_script_interpreter_sp
expr_stmt|;
name|std
operator|::
name|mutex
name|m_script_interpreter_mutex
expr_stmt|;
name|lldb
operator|::
name|IOHandlerSP
name|m_command_io_handler_sp
expr_stmt|;
name|char
name|m_comment_char
decl_stmt|;
name|bool
name|m_batch_command_mode
decl_stmt|;
name|ChildrenTruncatedWarningStatus
name|m_truncation_warning
decl_stmt|;
comment|// Whether we truncated
comment|// children and whether
comment|// the user has been told
name|uint32_t
name|m_command_source_depth
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
name|m_command_source_flags
expr_stmt|;
name|uint32_t
name|m_num_errors
decl_stmt|;
name|bool
name|m_quit_requested
decl_stmt|;
name|bool
name|m_stopped_for_crash
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_CommandInterpreter_h_
end_comment

end_unit

