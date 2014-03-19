begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CommandObject.h -----------------------------------------*- C++ -*-===//
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
name|liblldb_CommandObject_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_CommandObject_h_
end_define

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<set>
end_include

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

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Interpreter/Args.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Interpreter/CommandCompletions.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/StringList.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Flags.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/Mutex.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ExecutionContext.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|CommandObject
block|{
name|public
label|:
typedef|typedef
specifier|const
name|char
modifier|*
function_decl|(
name|ArgumentHelpCallbackFunction
function_decl|)
parameter_list|()
function_decl|;
struct|struct
name|ArgumentHelpCallback
block|{
name|ArgumentHelpCallbackFunction
modifier|*
name|help_callback
decl_stmt|;
name|bool
name|self_formatting
decl_stmt|;
specifier|const
name|char
operator|*
name|operator
argument_list|()
operator|(
operator|)
specifier|const
block|{
return|return
call|(
modifier|*
name|help_callback
call|)
argument_list|()
return|;
block|}
name|explicit
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
operator|(
name|help_callback
operator|!=
name|NULL
operator|)
return|;
block|}
block|}
struct|;
struct|struct
name|ArgumentTableEntry
comment|// Entries in the main argument information table
block|{
name|lldb
operator|::
name|CommandArgumentType
name|arg_type
expr_stmt|;
specifier|const
name|char
modifier|*
name|arg_name
decl_stmt|;
name|CommandCompletions
operator|::
name|CommonCompletionTypes
name|completion_type
expr_stmt|;
name|ArgumentHelpCallback
name|help_function
decl_stmt|;
specifier|const
name|char
modifier|*
name|help_text
decl_stmt|;
block|}
struct|;
struct|struct
name|CommandArgumentData
comment|// Used to build individual command argument lists
block|{
name|lldb
operator|::
name|CommandArgumentType
name|arg_type
expr_stmt|;
name|ArgumentRepetitionType
name|arg_repetition
decl_stmt|;
name|uint32_t
name|arg_opt_set_association
decl_stmt|;
comment|// This arg might be associated only with some particular option set(s).
name|CommandArgumentData
argument_list|()
operator|:
name|arg_type
argument_list|(
name|lldb
operator|::
name|eArgTypeNone
argument_list|)
operator|,
name|arg_repetition
argument_list|(
name|eArgRepeatPlain
argument_list|)
operator|,
name|arg_opt_set_association
argument_list|(
argument|LLDB_OPT_SET_ALL
argument_list|)
comment|// By default, the arg associates to all option sets.
block|{}
block|}
struct|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|CommandArgumentData
operator|>
name|CommandArgumentEntry
expr_stmt|;
comment|// Used to build individual command argument lists
specifier|static
name|ArgumentTableEntry
name|g_arguments_data
index|[
name|lldb
operator|::
name|eArgTypeLastArg
index|]
decl_stmt|;
comment|// Main argument information table
typedef|typedef
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
operator|,
name|lldb
operator|::
name|CommandObjectSP
operator|>
name|CommandMap
expr_stmt|;
name|CommandObject
argument_list|(
argument|CommandInterpreter&interpreter
argument_list|,
argument|const char *name
argument_list|,
argument|const char *help = NULL
argument_list|,
argument|const char *syntax = NULL
argument_list|,
argument|uint32_t flags =
literal|0
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|CommandObject
argument_list|()
expr_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|GetArgumentTypeAsCString
argument_list|(
specifier|const
name|lldb
operator|::
name|CommandArgumentType
name|arg_type
argument_list|)
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|GetArgumentDescriptionAsCString
argument_list|(
specifier|const
name|lldb
operator|::
name|CommandArgumentType
name|arg_type
argument_list|)
decl_stmt|;
name|CommandInterpreter
modifier|&
name|GetCommandInterpreter
parameter_list|()
block|{
return|return
name|m_interpreter
return|;
block|}
specifier|const
name|char
modifier|*
name|GetHelp
parameter_list|()
function_decl|;
name|virtual
specifier|const
name|char
modifier|*
name|GetHelpLong
parameter_list|()
function_decl|;
specifier|const
name|char
modifier|*
name|GetSyntax
parameter_list|()
function_decl|;
specifier|const
name|char
modifier|*
name|GetCommandName
parameter_list|()
function_decl|;
name|void
name|SetHelp
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
name|void
name|SetHelpLong
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
name|void
name|SetHelpLong
argument_list|(
name|std
operator|::
name|string
name|str
argument_list|)
decl_stmt|;
name|void
name|SetSyntax
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
comment|// override this to return true if you want to enable the user to delete
comment|// the Command object from the Command dictionary (aliases have their own
comment|// deletion scheme, so they do not need to care about this)
name|virtual
name|bool
name|IsRemovable
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|bool
name|IsAlias
parameter_list|()
block|{
return|return
name|m_is_alias
return|;
block|}
name|void
name|SetIsAlias
parameter_list|(
name|bool
name|value
parameter_list|)
block|{
name|m_is_alias
operator|=
name|value
expr_stmt|;
block|}
name|virtual
name|bool
name|IsMultiwordObject
parameter_list|()
block|{
return|return
name|false
return|;
block|}
name|virtual
name|lldb
operator|::
name|CommandObjectSP
name|GetSubcommandSP
argument_list|(
argument|const char *sub_cmd
argument_list|,
argument|StringList *matches = NULL
argument_list|)
block|{
return|return
name|lldb
operator|::
name|CommandObjectSP
argument_list|()
return|;
block|}
name|virtual
name|CommandObject
modifier|*
name|GetSubcommandObject
parameter_list|(
specifier|const
name|char
modifier|*
name|sub_cmd
parameter_list|,
name|StringList
modifier|*
name|matches
init|=
name|NULL
parameter_list|)
block|{
return|return
name|NULL
return|;
block|}
name|virtual
name|void
name|AproposAllSubCommands
parameter_list|(
specifier|const
name|char
modifier|*
name|prefix
parameter_list|,
specifier|const
name|char
modifier|*
name|search_word
parameter_list|,
name|StringList
modifier|&
name|commands_found
parameter_list|,
name|StringList
modifier|&
name|commands_help
parameter_list|)
block|{     }
name|void
name|GenerateHelpText
parameter_list|(
name|CommandReturnObject
modifier|&
name|result
parameter_list|)
function_decl|;
name|virtual
name|void
name|GenerateHelpText
parameter_list|(
name|Stream
modifier|&
name|result
parameter_list|)
function_decl|;
comment|// this is needed in order to allow the SBCommand class to
comment|// transparently try and load subcommands - it will fail on
comment|// anything but a multiword command, but it avoids us doing
comment|// type checkings and casts
name|virtual
name|bool
name|LoadSubCommand
argument_list|(
specifier|const
name|char
operator|*
name|cmd_name
argument_list|,
specifier|const
name|lldb
operator|::
name|CommandObjectSP
operator|&
name|command_obj
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|WantsRawCommandString
parameter_list|()
init|=
literal|0
function_decl|;
comment|// By default, WantsCompletion = !WantsRawCommandString.
comment|// Subclasses who want raw command string but desire, for example,
comment|// argument completion should override this method to return true.
name|virtual
name|bool
name|WantsCompletion
parameter_list|()
block|{
return|return
operator|!
name|WantsRawCommandString
argument_list|()
return|;
block|}
name|virtual
name|Options
modifier|*
name|GetOptions
parameter_list|()
function_decl|;
specifier|static
specifier|const
name|ArgumentTableEntry
modifier|*
name|GetArgumentTable
parameter_list|()
function_decl|;
specifier|static
name|lldb
operator|::
name|CommandArgumentType
name|LookupArgumentName
argument_list|(
specifier|const
name|char
operator|*
name|arg_name
argument_list|)
expr_stmt|;
specifier|static
name|ArgumentTableEntry
modifier|*
name|FindArgumentDataByType
argument_list|(
name|lldb
operator|::
name|CommandArgumentType
name|arg_type
argument_list|)
decl_stmt|;
name|int
name|GetNumArgumentEntries
parameter_list|()
function_decl|;
name|CommandArgumentEntry
modifier|*
name|GetArgumentEntryAtIndex
parameter_list|(
name|int
name|idx
parameter_list|)
function_decl|;
specifier|static
name|void
name|GetArgumentHelp
argument_list|(
name|Stream
operator|&
name|str
argument_list|,
name|lldb
operator|::
name|CommandArgumentType
name|arg_type
argument_list|,
name|CommandInterpreter
operator|&
name|interpreter
argument_list|)
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|GetArgumentName
argument_list|(
name|lldb
operator|::
name|CommandArgumentType
name|arg_type
argument_list|)
decl_stmt|;
comment|// Generates a nicely formatted command args string for help command output.
comment|// By default, all possible args are taken into account, for example,
comment|// '<expr | variable-name>'.  This can be refined by passing a second arg
comment|// specifying which option set(s) we are interested, which could then, for
comment|// example, produce either '<expr>' or '<variable-name>'.
name|void
name|GetFormattedCommandArguments
parameter_list|(
name|Stream
modifier|&
name|str
parameter_list|,
name|uint32_t
name|opt_set_mask
init|=
name|LLDB_OPT_SET_ALL
parameter_list|)
function_decl|;
name|bool
name|IsPairType
parameter_list|(
name|ArgumentRepetitionType
name|arg_repeat_type
parameter_list|)
function_decl|;
enum|enum
block|{
comment|//----------------------------------------------------------------------
comment|// eFlagRequiresTarget
comment|//
comment|// Ensures a valid target is contained in m_exe_ctx prior to executing
comment|// the command. If a target doesn't exist or is invalid, the command
comment|// will fail and CommandObject::GetInvalidTargetDescription() will be
comment|// returned as the error. CommandObject subclasses can override the
comment|// virtual function for GetInvalidTargetDescription() to provide custom
comment|// strings when needed.
comment|//----------------------------------------------------------------------
name|eFlagRequiresTarget
init|=
operator|(
literal|1u
operator|<<
literal|0
operator|)
block|,
comment|//----------------------------------------------------------------------
comment|// eFlagRequiresProcess
comment|//
comment|// Ensures a valid process is contained in m_exe_ctx prior to executing
comment|// the command. If a process doesn't exist or is invalid, the command
comment|// will fail and CommandObject::GetInvalidProcessDescription() will be
comment|// returned as the error. CommandObject subclasses can override the
comment|// virtual function for GetInvalidProcessDescription() to provide custom
comment|// strings when needed.
comment|//----------------------------------------------------------------------
name|eFlagRequiresProcess
init|=
operator|(
literal|1u
operator|<<
literal|1
operator|)
block|,
comment|//----------------------------------------------------------------------
comment|// eFlagRequiresThread
comment|//
comment|// Ensures a valid thread is contained in m_exe_ctx prior to executing
comment|// the command. If a thread doesn't exist or is invalid, the command
comment|// will fail and CommandObject::GetInvalidThreadDescription() will be
comment|// returned as the error. CommandObject subclasses can override the
comment|// virtual function for GetInvalidThreadDescription() to provide custom
comment|// strings when needed.
comment|//----------------------------------------------------------------------
name|eFlagRequiresThread
init|=
operator|(
literal|1u
operator|<<
literal|2
operator|)
block|,
comment|//----------------------------------------------------------------------
comment|// eFlagRequiresFrame
comment|//
comment|// Ensures a valid frame is contained in m_exe_ctx prior to executing
comment|// the command. If a frame doesn't exist or is invalid, the command
comment|// will fail and CommandObject::GetInvalidFrameDescription() will be
comment|// returned as the error. CommandObject subclasses can override the
comment|// virtual function for GetInvalidFrameDescription() to provide custom
comment|// strings when needed.
comment|//----------------------------------------------------------------------
name|eFlagRequiresFrame
init|=
operator|(
literal|1u
operator|<<
literal|3
operator|)
block|,
comment|//----------------------------------------------------------------------
comment|// eFlagRequiresRegContext
comment|//
comment|// Ensures a valid register context (from the selected frame if there
comment|// is a frame in m_exe_ctx, or from the selected thread from m_exe_ctx)
comment|// is availble from m_exe_ctx prior to executing the command. If a
comment|// target doesn't exist or is invalid, the command will fail and
comment|// CommandObject::GetInvalidRegContextDescription() will be returned as
comment|// the error. CommandObject subclasses can override the virtual function
comment|// for GetInvalidRegContextDescription() to provide custom strings when
comment|// needed.
comment|//----------------------------------------------------------------------
name|eFlagRequiresRegContext
init|=
operator|(
literal|1u
operator|<<
literal|4
operator|)
block|,
comment|//----------------------------------------------------------------------
comment|// eFlagTryTargetAPILock
comment|//
comment|// Attempts to acquire the target lock if a target is selected in the
comment|// command interpreter. If the command object fails to acquire the API
comment|// lock, the command will fail with an appropriate error message.
comment|//----------------------------------------------------------------------
name|eFlagTryTargetAPILock
init|=
operator|(
literal|1u
operator|<<
literal|5
operator|)
block|,
comment|//----------------------------------------------------------------------
comment|// eFlagProcessMustBeLaunched
comment|//
comment|// Verifies that there is a launched process in m_exe_ctx, if there
comment|// isn't, the command will fail with an appropriate error message.
comment|//----------------------------------------------------------------------
name|eFlagProcessMustBeLaunched
init|=
operator|(
literal|1u
operator|<<
literal|6
operator|)
block|,
comment|//----------------------------------------------------------------------
comment|// eFlagProcessMustBePaused
comment|//
comment|// Verifies that there is a paused process in m_exe_ctx, if there
comment|// isn't, the command will fail with an appropriate error message.
comment|//----------------------------------------------------------------------
name|eFlagProcessMustBePaused
init|=
operator|(
literal|1u
operator|<<
literal|7
operator|)
block|}
enum|;
name|bool
name|ParseOptions
parameter_list|(
name|Args
modifier|&
name|args
parameter_list|,
name|CommandReturnObject
modifier|&
name|result
parameter_list|)
function_decl|;
name|void
name|SetCommandName
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
comment|// This function really deals with CommandObjectLists, but we didn't make a
comment|// CommandObjectList class, so I'm sticking it here.  But we really should have
comment|// such a class.  Anyway, it looks up the commands in the map that match the partial
comment|// string cmd_str, inserts the matches into matches, and returns the number added.
specifier|static
name|int
name|AddNamesMatchingPartialString
parameter_list|(
name|CommandMap
modifier|&
name|in_map
parameter_list|,
specifier|const
name|char
modifier|*
name|cmd_str
parameter_list|,
name|StringList
modifier|&
name|matches
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// The input array contains a parsed version of the line.  The insertion
comment|/// point is given by cursor_index (the index in input of the word containing
comment|/// the cursor) and cursor_char_position (the position of the cursor in that word.)
comment|/// This default version handles calling option argument completions and then calls
comment|/// HandleArgumentCompletion if the cursor is on an argument, not an option.
comment|/// Don't override this method, override HandleArgumentCompletion instead unless
comment|/// you have special reasons.
comment|///
comment|/// @param[in] interpreter
comment|///    The command interpreter doing the completion.
comment|///
comment|/// @param[in] input
comment|///    The command line parsed into words
comment|///
comment|/// @param[in] cursor_index
comment|///     The index in \ainput of the word in which the cursor lies.
comment|///
comment|/// @param[in] cursor_char_pos
comment|///     The character position of the cursor in its argument word.
comment|///
comment|/// @param[in] match_start_point
comment|/// @param[in] match_return_elements
comment|///     FIXME: Not yet implemented...  If there is a match that is expensive to compute, these are
comment|///     here to allow you to compute the completions in batches.  Start the completion from \amatch_start_point,
comment|///     and return \amatch_return_elements elements.
comment|///
comment|/// @param[out] word_complete
comment|///     \btrue if this is a complete option value (a space will be inserted after the
comment|///     completion.)  \bfalse otherwise.
comment|///
comment|/// @param[out] matches
comment|///     The array of matches returned.
comment|///
comment|/// FIXME: This is the wrong return value, since we also need to make a distinction between
comment|/// total number of matches, and the window the user wants returned.
comment|///
comment|/// @return
comment|///     \btrue if we were in an option, \bfalse otherwise.
comment|//------------------------------------------------------------------
name|virtual
name|int
name|HandleCompletion
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
comment|//------------------------------------------------------------------
comment|/// The input array contains a parsed version of the line.  The insertion
comment|/// point is given by cursor_index (the index in input of the word containing
comment|/// the cursor) and cursor_char_position (the position of the cursor in that word.)
comment|/// We've constructed the map of options and their arguments as well if that is
comment|/// helpful for the completion.
comment|///
comment|/// @param[in] interpreter
comment|///    The command interpreter doing the completion.
comment|///
comment|/// @param[in] input
comment|///    The command line parsed into words
comment|///
comment|/// @param[in] cursor_index
comment|///     The index in \ainput of the word in which the cursor lies.
comment|///
comment|/// @param[in] cursor_char_pos
comment|///     The character position of the cursor in its argument word.
comment|///
comment|/// @param[in] opt_element_vector
comment|///     The results of the options parse of \a input.
comment|///
comment|/// @param[in] match_start_point
comment|/// @param[in] match_return_elements
comment|///     See CommandObject::HandleCompletions for a description of how these work.
comment|///
comment|/// @param[out] word_complete
comment|///     \btrue if this is a complete option value (a space will be inserted after the
comment|///     completion.)  \bfalse otherwise.
comment|///
comment|/// @param[out] matches
comment|///     The array of matches returned.
comment|///
comment|/// FIXME: This is the wrong return value, since we also need to make a distinction between
comment|/// total number of matches, and the window the user wants returned.
comment|///
comment|/// @return
comment|///     The number of completions.
comment|//------------------------------------------------------------------
name|virtual
name|int
name|HandleArgumentCompletion
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
name|OptionElementVector
modifier|&
name|opt_element_vector
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
block|{
return|return
literal|0
return|;
block|}
name|bool
name|HelpTextContainsWord
parameter_list|(
specifier|const
name|char
modifier|*
name|search_word
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// The flags accessor.
comment|///
comment|/// @return
comment|///     A reference to the Flags member variable.
comment|//------------------------------------------------------------------
name|Flags
modifier|&
name|GetFlags
parameter_list|()
block|{
return|return
name|m_flags
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// The flags const accessor.
comment|///
comment|/// @return
comment|///     A const reference to the Flags member variable.
comment|//------------------------------------------------------------------
specifier|const
name|Flags
operator|&
name|GetFlags
argument_list|()
specifier|const
block|{
return|return
name|m_flags
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get the command that appropriate for a "repeat" of the current command.
comment|///
comment|/// @param[in] current_command_line
comment|///    The complete current command line.
comment|///
comment|/// @return
comment|///     NULL if there is no special repeat command - it will use the current command line.
comment|///     Otherwise a pointer to the command to be repeated.
comment|///     If the returned string is the empty string, the command won't be repeated.
comment|//------------------------------------------------------------------
name|virtual
specifier|const
name|char
modifier|*
name|GetRepeatCommand
parameter_list|(
name|Args
modifier|&
name|current_command_args
parameter_list|,
name|uint32_t
name|index
parameter_list|)
block|{
return|return
name|NULL
return|;
block|}
name|CommandOverrideCallback
name|GetOverrideCallback
argument_list|()
specifier|const
block|{
return|return
name|m_command_override_callback
return|;
block|}
name|void
operator|*
name|GetOverrideCallbackBaton
argument_list|()
specifier|const
block|{
return|return
name|m_command_override_baton
return|;
block|}
name|void
name|SetOverrideCallback
parameter_list|(
name|CommandOverrideCallback
name|callback
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|)
block|{
name|m_command_override_callback
operator|=
name|callback
expr_stmt|;
name|m_command_override_baton
operator|=
name|baton
expr_stmt|;
block|}
name|virtual
name|bool
name|Execute
parameter_list|(
specifier|const
name|char
modifier|*
name|args_string
parameter_list|,
name|CommandReturnObject
modifier|&
name|result
parameter_list|)
init|=
literal|0
function_decl|;
name|protected
label|:
name|virtual
specifier|const
name|char
modifier|*
name|GetInvalidTargetDescription
parameter_list|()
block|{
return|return
literal|"invalid target, create a target using the 'target create' command"
return|;
block|}
name|virtual
specifier|const
name|char
modifier|*
name|GetInvalidProcessDescription
parameter_list|()
block|{
return|return
literal|"invalid process"
return|;
block|}
name|virtual
specifier|const
name|char
modifier|*
name|GetInvalidThreadDescription
parameter_list|()
block|{
return|return
literal|"invalid thread"
return|;
block|}
name|virtual
specifier|const
name|char
modifier|*
name|GetInvalidFrameDescription
parameter_list|()
block|{
return|return
literal|"invalid frame"
return|;
block|}
name|virtual
specifier|const
name|char
modifier|*
name|GetInvalidRegContextDescription
parameter_list|()
block|{
return|return
literal|"invalid frame, no registers"
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Check the command to make sure anything required by this
comment|/// command is available.
comment|///
comment|/// @param[out] result
comment|///     A command result object, if it is not okay to run the command
comment|///     this will be filled in with a suitable error.
comment|///
comment|/// @return
comment|///     \b true if it is okay to run this command, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|CheckRequirements
parameter_list|(
name|CommandReturnObject
modifier|&
name|result
parameter_list|)
function_decl|;
name|void
name|Cleanup
parameter_list|()
function_decl|;
name|CommandInterpreter
modifier|&
name|m_interpreter
decl_stmt|;
name|ExecutionContext
name|m_exe_ctx
decl_stmt|;
name|Mutex
operator|::
name|Locker
name|m_api_locker
expr_stmt|;
name|std
operator|::
name|string
name|m_cmd_name
expr_stmt|;
name|std
operator|::
name|string
name|m_cmd_help_short
expr_stmt|;
name|std
operator|::
name|string
name|m_cmd_help_long
expr_stmt|;
name|std
operator|::
name|string
name|m_cmd_syntax
expr_stmt|;
name|bool
name|m_is_alias
decl_stmt|;
name|Flags
name|m_flags
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|CommandArgumentEntry
operator|>
name|m_arguments
expr_stmt|;
name|CommandOverrideCallback
name|m_command_override_callback
decl_stmt|;
name|void
modifier|*
name|m_command_override_baton
decl_stmt|;
comment|// Helper function to populate IDs or ID ranges as the command argument data
comment|// to the specified command argument entry.
specifier|static
name|void
name|AddIDsArgumentData
argument_list|(
name|CommandArgumentEntry
operator|&
name|arg
argument_list|,
name|lldb
operator|::
name|CommandArgumentType
name|ID
argument_list|,
name|lldb
operator|::
name|CommandArgumentType
name|IDRange
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
name|class
name|CommandObjectParsed
range|:
name|public
name|CommandObject
block|{
name|public
operator|:
name|CommandObjectParsed
argument_list|(
argument|CommandInterpreter&interpreter
argument_list|,
argument|const char *name
argument_list|,
argument|const char *help = NULL
argument_list|,
argument|const char *syntax = NULL
argument_list|,
argument|uint32_t flags =
literal|0
argument_list|)
operator|:
name|CommandObject
argument_list|(
argument|interpreter
argument_list|,
argument|name
argument_list|,
argument|help
argument_list|,
argument|syntax
argument_list|,
argument|flags
argument_list|)
block|{}
name|virtual
operator|~
name|CommandObjectParsed
argument_list|()
block|{}
block|;
name|virtual
name|bool
name|Execute
argument_list|(
specifier|const
name|char
operator|*
name|args_string
argument_list|,
name|CommandReturnObject
operator|&
name|result
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|bool
name|DoExecute
argument_list|(
name|Args
operator|&
name|command
argument_list|,
name|CommandReturnObject
operator|&
name|result
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|WantsRawCommandString
argument_list|()
block|{
return|return
name|false
return|;
block|}
block|; }
decl_stmt|;
name|class
name|CommandObjectRaw
range|:
name|public
name|CommandObject
block|{
name|public
operator|:
name|CommandObjectRaw
argument_list|(
argument|CommandInterpreter&interpreter
argument_list|,
argument|const char *name
argument_list|,
argument|const char *help = NULL
argument_list|,
argument|const char *syntax = NULL
argument_list|,
argument|uint32_t flags =
literal|0
argument_list|)
operator|:
name|CommandObject
argument_list|(
argument|interpreter
argument_list|,
argument|name
argument_list|,
argument|help
argument_list|,
argument|syntax
argument_list|,
argument|flags
argument_list|)
block|{}
name|virtual
operator|~
name|CommandObjectRaw
argument_list|()
block|{}
block|;
name|virtual
name|bool
name|Execute
argument_list|(
specifier|const
name|char
operator|*
name|args_string
argument_list|,
name|CommandReturnObject
operator|&
name|result
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|bool
name|DoExecute
argument_list|(
specifier|const
name|char
operator|*
name|command
argument_list|,
name|CommandReturnObject
operator|&
name|result
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|WantsRawCommandString
argument_list|()
block|{
return|return
name|true
return|;
block|}
block|; }
decl_stmt|;
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
comment|// liblldb_CommandObject_h_
end_comment

end_unit

