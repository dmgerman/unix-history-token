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

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<map>
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

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Utility/Flags.h"
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
file|"lldb/Target/ExecutionContext.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/StringList.h"
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
comment|// This function really deals with CommandObjectLists, but we didn't make a
comment|// CommandObjectList class, so I'm sticking it here.  But we really should have
comment|// such a class.  Anyway, it looks up the commands in the map that match the
comment|// partial
comment|// string cmd_str, inserts the matches into matches, and returns the number
comment|// added.
name|template
operator|<
name|typename
name|ValueType
operator|>
name|int
name|AddNamesMatchingPartialString
argument_list|(
argument|const std::map<std::string
argument_list|,
argument|ValueType>&in_map
argument_list|,
argument|llvm::StringRef cmd_str
argument_list|,
argument|StringList&matches
argument_list|)
block|{
name|int
name|number_added
operator|=
literal|0
block|;
specifier|const
name|bool
name|add_all
operator|=
name|cmd_str
operator|.
name|empty
argument_list|()
block|;
for|for
control|(
name|auto
name|iter
init|=
name|in_map
operator|.
name|begin
argument_list|()
init|,
name|end
init|=
name|in_map
operator|.
name|end
argument_list|()
init|;
name|iter
operator|!=
name|end
condition|;
name|iter
operator|++
control|)
block|{
if|if
condition|(
name|add_all
operator|||
operator|(
name|iter
operator|->
name|first
operator|.
name|find
argument_list|(
name|cmd_str
argument_list|,
literal|0
argument_list|)
operator|==
literal|0
operator|)
condition|)
block|{
operator|++
name|number_added
expr_stmt|;
name|matches
operator|.
name|AppendString
argument_list|(
name|iter
operator|->
name|first
operator|.
name|c_str
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|number_added
return|;
block|}
name|template
operator|<
name|typename
name|ValueType
operator|>
name|size_t
name|FindLongestCommandWord
argument_list|(
argument|std::map<std::string
argument_list|,
argument|ValueType>&dict
argument_list|)
block|{
name|auto
name|end
operator|=
name|dict
operator|.
name|end
argument_list|()
block|;
name|size_t
name|max_len
operator|=
literal|0
block|;
for|for
control|(
name|auto
name|pos
init|=
name|dict
operator|.
name|begin
argument_list|()
init|;
name|pos
operator|!=
name|end
condition|;
operator|++
name|pos
control|)
block|{
name|size_t
name|len
init|=
name|pos
operator|->
name|first
operator|.
name|size
argument_list|()
decl_stmt|;
if|if
condition|(
name|max_len
operator|<
name|len
condition|)
name|max_len
operator|=
name|len
expr_stmt|;
block|}
return|return
name|max_len
return|;
block|}
name|class
name|CommandObject
block|{
name|public
label|:
typedef|typedef
name|llvm
operator|::
name|StringRef
argument_list|(
name|ArgumentHelpCallbackFunction
argument_list|)
argument_list|()
expr_stmt|;
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
name|llvm
operator|::
name|StringRef
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
name|nullptr
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
comment|// This arg might be associated only with
comment|// some particular option set(s).
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
comment|// By default, the arg
comment|// associates to all option
comment|// sets.
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
argument|llvm::StringRef name
argument_list|,
argument|llvm::StringRef help =
literal|""
argument_list|,
argument|llvm::StringRef syntax =
literal|""
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
name|virtual
name|llvm
operator|::
name|StringRef
name|GetHelp
argument_list|()
expr_stmt|;
name|virtual
name|llvm
operator|::
name|StringRef
name|GetHelpLong
argument_list|()
expr_stmt|;
name|virtual
name|llvm
operator|::
name|StringRef
name|GetSyntax
argument_list|()
expr_stmt|;
name|llvm
operator|::
name|StringRef
name|GetCommandName
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|void
name|SetHelp
argument_list|(
name|llvm
operator|::
name|StringRef
name|str
argument_list|)
decl_stmt|;
name|virtual
name|void
name|SetHelpLong
argument_list|(
name|llvm
operator|::
name|StringRef
name|str
argument_list|)
decl_stmt|;
name|void
name|SetSyntax
argument_list|(
name|llvm
operator|::
name|StringRef
name|str
argument_list|)
decl_stmt|;
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
name|CommandObjectMultiword
modifier|*
name|GetAsMultiwordCommand
parameter_list|()
block|{
return|return
name|nullptr
return|;
block|}
name|virtual
name|bool
name|IsAlias
parameter_list|()
block|{
return|return
name|false
return|;
block|}
comment|// override this to return true if your command is somehow a "dash-dash"
comment|// form of some other command (e.g. po is expr -O --); this is a powerful
comment|// hint to the help system that one cannot pass options to this command
name|virtual
name|bool
name|IsDashDashCommand
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
argument|llvm::StringRef sub_cmd
argument_list|,
argument|StringList *matches = nullptr
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
argument_list|(
name|llvm
operator|::
name|StringRef
name|sub_cmd
argument_list|,
name|StringList
operator|*
name|matches
operator|=
name|nullptr
argument_list|)
block|{
return|return
name|nullptr
return|;
block|}
name|virtual
name|void
name|AproposAllSubCommands
argument_list|(
name|llvm
operator|::
name|StringRef
name|prefix
argument_list|,
name|llvm
operator|::
name|StringRef
name|search_word
argument_list|,
name|StringList
operator|&
name|commands_found
argument_list|,
name|StringList
operator|&
name|commands_help
argument_list|)
block|{}
name|void
name|FormatLongHelpText
argument_list|(
name|Stream
operator|&
name|output_strm
argument_list|,
name|llvm
operator|::
name|StringRef
name|long_help
argument_list|)
decl_stmt|;
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
name|llvm
operator|::
name|StringRef
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
argument|llvm::StringRef arg_name
argument_list|)
expr_stmt|;
specifier|static
specifier|const
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
argument_list|(
name|llvm
operator|::
name|StringRef
name|name
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// The input array contains a parsed version of the line.  The insertion
comment|/// point is given by cursor_index (the index in input of the word containing
comment|/// the cursor) and cursor_char_position (the position of the cursor in that
comment|/// word.)
comment|/// This default version handles calling option argument completions and then
comment|/// calls
comment|/// HandleArgumentCompletion if the cursor is on an argument, not an option.
comment|/// Don't override this method, override HandleArgumentCompletion instead
comment|/// unless
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
comment|///     FIXME: Not yet implemented...  If there is a match that is expensive
comment|///     to compute, these are
comment|///     here to allow you to compute the completions in batches.  Start the
comment|///     completion from \amatch_start_point,
comment|///     and return \amatch_return_elements elements.
comment|///
comment|/// @param[out] word_complete
comment|///     \btrue if this is a complete option value (a space will be inserted
comment|///     after the
comment|///     completion.)  \bfalse otherwise.
comment|///
comment|/// @param[out] matches
comment|///     The array of matches returned.
comment|///
comment|/// FIXME: This is the wrong return value, since we also need to make a
comment|/// distinction between
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
comment|/// the cursor) and cursor_char_position (the position of the cursor in that
comment|/// word.)
comment|/// We've constructed the map of options and their arguments as well if that
comment|/// is
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
comment|///     See CommandObject::HandleCompletions for a description of how these
comment|///     work.
comment|///
comment|/// @param[out] word_complete
comment|///     \btrue if this is a complete option value (a space will be inserted
comment|///     after the
comment|///     completion.)  \bfalse otherwise.
comment|///
comment|/// @param[out] matches
comment|///     The array of matches returned.
comment|///
comment|/// FIXME: This is the wrong return value, since we also need to make a
comment|/// distinction between
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
argument_list|(
name|llvm
operator|::
name|StringRef
name|search_word
argument_list|,
name|bool
name|search_short_help
operator|=
name|true
argument_list|,
name|bool
name|search_long_help
operator|=
name|true
argument_list|,
name|bool
name|search_syntax
operator|=
name|true
argument_list|,
name|bool
name|search_options
operator|=
name|true
argument_list|)
decl_stmt|;
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
comment|///     nullptr if there is no special repeat command - it will use the
comment|///     current command line.
comment|///     Otherwise a pointer to the command to be repeated.
comment|///     If the returned string is the empty string, the command won't be
comment|///     repeated.
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
name|nullptr
return|;
block|}
name|bool
name|HasOverrideCallback
argument_list|()
specifier|const
block|{
return|return
name|m_command_override_callback
operator|||
name|m_deprecated_command_override_callback
return|;
block|}
name|void
name|SetOverrideCallback
argument_list|(
name|lldb
operator|::
name|CommandOverrideCallback
name|callback
argument_list|,
name|void
operator|*
name|baton
argument_list|)
block|{
name|m_deprecated_command_override_callback
operator|=
name|callback
expr_stmt|;
name|m_command_override_baton
operator|=
name|baton
expr_stmt|;
block|}
name|void
name|SetOverrideCallback
argument_list|(
name|lldb
operator|::
name|CommandOverrideCallbackWithResult
name|callback
argument_list|,
name|void
operator|*
name|baton
argument_list|)
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
name|bool
name|InvokeOverrideCallback
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|argv
parameter_list|,
name|CommandReturnObject
modifier|&
name|result
parameter_list|)
block|{
if|if
condition|(
name|m_command_override_callback
condition|)
return|return
name|m_command_override_callback
argument_list|(
name|m_command_override_baton
argument_list|,
name|argv
argument_list|,
name|result
argument_list|)
return|;
elseif|else
if|if
condition|(
name|m_deprecated_command_override_callback
condition|)
return|return
name|m_deprecated_command_override_callback
argument_list|(
name|m_command_override_baton
argument_list|,
name|argv
argument_list|)
return|;
else|else
return|return
name|false
return|;
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
comment|// This is for use in the command interpreter, when you either want the
comment|// selected target, or if no target
comment|// is present you want to prime the dummy target with entities that will be
comment|// copied over to new targets.
name|Target
modifier|*
name|GetSelectedOrDummyTarget
parameter_list|(
name|bool
name|prefer_dummy
init|=
name|false
parameter_list|)
function_decl|;
name|Target
modifier|*
name|GetDummyTarget
parameter_list|()
function_decl|;
comment|// If a command needs to use the "current" thread, use this call.
comment|// Command objects will have an ExecutionContext to use, and that may or may
comment|// not have a thread in it.  If it
comment|// does, you should use that by default, if not, then use the
comment|// ExecutionContext's target's selected thread, etc...
comment|// This call insulates you from the details of this calculation.
name|Thread
modifier|*
name|GetDefaultThread
parameter_list|()
function_decl|;
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
name|std
operator|::
name|unique_lock
operator|<
name|std
operator|::
name|recursive_mutex
operator|>
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
name|lldb
operator|::
name|CommandOverrideCallback
name|m_deprecated_command_override_callback
expr_stmt|;
name|lldb
operator|::
name|CommandOverrideCallbackWithResult
name|m_command_override_callback
expr_stmt|;
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
argument|const char *help = nullptr
argument_list|,
argument|const char *syntax = nullptr
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
operator|~
name|CommandObjectParsed
argument_list|()
name|override
operator|=
expr|default
block|;
name|bool
name|Execute
argument_list|(
argument|const char *args_string
argument_list|,
argument|CommandReturnObject&result
argument_list|)
name|override
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
name|bool
name|WantsRawCommandString
argument_list|()
name|override
block|{
return|return
name|false
return|;
block|}
expr|}
block|;
name|class
name|CommandObjectRaw
operator|:
name|public
name|CommandObject
block|{
name|public
operator|:
name|CommandObjectRaw
argument_list|(
argument|CommandInterpreter&interpreter
argument_list|,
argument|llvm::StringRef name
argument_list|,
argument|llvm::StringRef help =
literal|""
argument_list|,
argument|llvm::StringRef syntax =
literal|""
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
operator|~
name|CommandObjectRaw
argument_list|()
name|override
operator|=
expr|default
block|;
name|bool
name|Execute
argument_list|(
argument|const char *args_string
argument_list|,
argument|CommandReturnObject&result
argument_list|)
name|override
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
name|bool
name|WantsRawCommandString
argument_list|()
name|override
block|{
return|return
name|true
return|;
block|}
expr|}
block|;  }
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

