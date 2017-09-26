begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Options.h -----------------------------------------------*- C++ -*-===//
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
name|liblldb_Options_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Options_h_
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
file|<set>
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
file|"lldb/Interpreter/Args.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
specifier|static
specifier|inline
name|bool
name|isprint8
parameter_list|(
name|int
name|ch
parameter_list|)
block|{
if|if
condition|(
name|ch
operator|&
literal|0xffffff00u
condition|)
return|return
name|false
return|;
return|return
name|isprint
argument_list|(
name|ch
argument_list|)
return|;
block|}
comment|//----------------------------------------------------------------------
comment|/// @class Options Options.h "lldb/Interpreter/Options.h"
comment|/// @brief A command line option parsing protocol class.
comment|///
comment|/// Options is designed to be subclassed to contain all needed
comment|/// options for a given command. The options can be parsed by calling:
comment|/// \code
comment|///     Status Args::ParseOptions (Options&);
comment|/// \endcode
comment|///
comment|/// The options are specified using the format defined for the libc
comment|/// options parsing function getopt_long_only:
comment|/// \code
comment|///     #include<getopt.h>
comment|///     int getopt_long_only(int argc, char * const *argv, const char
comment|///     *optstring, const struct option *longopts, int *longindex);
comment|/// \endcode
comment|///
comment|/// Example code:
comment|/// \code
comment|///     #include<getopt.h>
comment|///     #include<string>
comment|///
comment|///     class CommandOptions : public Options
comment|///     {
comment|///     public:
comment|///         virtual struct option *
comment|///         GetLongOptions() {
comment|///             return g_options;
comment|///         }
comment|///
comment|///         virtual Status
comment|///         SetOptionValue (uint32_t option_idx, int option_val, const char
comment|///         *option_arg)
comment|///         {
comment|///             Status error;
comment|///             switch (option_val)
comment|///             {
comment|///             case 'g': debug = true; break;
comment|///             case 'v': verbose = true; break;
comment|///             case 'l': log_file = option_arg; break;
comment|///             case 'f': log_flags = strtoull(option_arg, nullptr, 0); break;
comment|///             default:
comment|///                 error.SetErrorStringWithFormat("unrecognized short option
comment|///                 %c", option_val);
comment|///                 break;
comment|///             }
comment|///
comment|///             return error;
comment|///         }
comment|///
comment|///         CommandOptions (CommandInterpreter&interpreter) : debug (true),
comment|///         verbose (false), log_file (), log_flags (0)
comment|///         {}
comment|///
comment|///         bool debug;
comment|///         bool verbose;
comment|///         std::string log_file;
comment|///         uint32_t log_flags;
comment|///
comment|///         static struct option g_options[];
comment|///
comment|///     };
comment|///
comment|///     struct option CommandOptions::g_options[] =
comment|///     {
comment|///         { "debug",              no_argument,        nullptr,   'g' },
comment|///         { "log-file",           required_argument,  nullptr,   'l' },
comment|///         { "log-flags",          required_argument,  nullptr,   'f' },
comment|///         { "verbose",            no_argument,        nullptr,   'v' },
comment|///         { nullptr,              0,                  nullptr,   0   }
comment|///     };
comment|///
comment|///     int main (int argc, const char **argv, const char **envp)
comment|///     {
comment|///         CommandOptions options;
comment|///         Args main_command;
comment|///         main_command.SetArguments(argc, argv, false);
comment|///         main_command.ParseOptions(options);
comment|///
comment|///         if (options.verbose)
comment|///         {
comment|///             std::cout<< "verbose is on"<< std::endl;
comment|///         }
comment|///     }
comment|/// \endcode
comment|//----------------------------------------------------------------------
name|class
name|Options
block|{
name|public
label|:
name|Options
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|Options
argument_list|()
expr_stmt|;
name|void
name|BuildGetoptTable
parameter_list|()
function_decl|;
name|void
name|BuildValidOptionSets
parameter_list|()
function_decl|;
name|uint32_t
name|NumCommandOptions
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get the option definitions to use when parsing Args options.
comment|///
comment|/// @see Args::ParseOptions (Options&)
comment|/// @see man getopt_long_only
comment|//------------------------------------------------------------------
name|Option
modifier|*
name|GetLongOptions
parameter_list|()
function_decl|;
comment|// This gets passed the short option as an integer...
name|void
name|OptionSeen
parameter_list|(
name|int
name|short_option
parameter_list|)
function_decl|;
name|bool
name|VerifyOptions
parameter_list|(
name|CommandReturnObject
modifier|&
name|result
parameter_list|)
function_decl|;
comment|// Verify that the options given are in the options table and can
comment|// be used together, but there may be some required options that are
comment|// missing (used to verify options that get folded into command aliases).
name|bool
name|VerifyPartialOptions
parameter_list|(
name|CommandReturnObject
modifier|&
name|result
parameter_list|)
function_decl|;
name|void
name|OutputFormattedUsageText
parameter_list|(
name|Stream
modifier|&
name|strm
parameter_list|,
specifier|const
name|OptionDefinition
modifier|&
name|option_def
parameter_list|,
name|uint32_t
name|output_max_columns
parameter_list|)
function_decl|;
name|void
name|GenerateOptionUsage
parameter_list|(
name|Stream
modifier|&
name|strm
parameter_list|,
name|CommandObject
modifier|*
name|cmd
parameter_list|,
name|uint32_t
name|screen_width
parameter_list|)
function_decl|;
name|bool
name|SupportsLongOption
parameter_list|(
specifier|const
name|char
modifier|*
name|long_option
parameter_list|)
function_decl|;
comment|// The following two pure virtual functions must be defined by every
comment|// class that inherits from this class.
name|virtual
name|llvm
operator|::
name|ArrayRef
operator|<
name|OptionDefinition
operator|>
name|GetDefinitions
argument_list|()
block|{
return|return
name|llvm
operator|::
name|ArrayRef
operator|<
name|OptionDefinition
operator|>
operator|(
operator|)
return|;
block|}
comment|// Call this prior to parsing any options. This call will call the
comment|// subclass OptionParsingStarting() and will avoid the need for all
comment|// OptionParsingStarting() function instances from having to call the
comment|// Option::OptionParsingStarting() like they did before. This was error
comment|// prone and subclasses shouldn't have to do it.
name|void
name|NotifyOptionParsingStarting
parameter_list|(
name|ExecutionContext
modifier|*
name|execution_context
parameter_list|)
function_decl|;
name|Status
name|NotifyOptionParsingFinished
parameter_list|(
name|ExecutionContext
modifier|*
name|execution_context
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Set the value of an option.
comment|///
comment|/// @param[in] option_idx
comment|///     The index into the "struct option" array that was returned
comment|///     by Options::GetLongOptions().
comment|///
comment|/// @param[in] option_arg
comment|///     The argument value for the option that the user entered, or
comment|///     nullptr if there is no argument for the current option.
comment|///
comment|/// @param[in] execution_context
comment|///     The execution context to use for evaluating the option.
comment|///     May be nullptr if the option is to be evaluated outside any
comment|///     particular context.
comment|///
comment|/// @see Args::ParseOptions (Options&)
comment|/// @see man getopt_long_only
comment|//------------------------------------------------------------------
name|virtual
name|Status
name|SetOptionValue
argument_list|(
name|uint32_t
name|option_idx
argument_list|,
name|llvm
operator|::
name|StringRef
name|option_arg
argument_list|,
name|ExecutionContext
operator|*
name|execution_context
argument_list|)
init|=
literal|0
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Handles the generic bits of figuring out whether we are in an
comment|/// option, and if so completing it.
comment|///
comment|/// @param[in] input
comment|///    The command line parsed into words
comment|///
comment|/// @param[in] cursor_index
comment|///     The index in \ainput of the word in which the cursor lies.
comment|///
comment|/// @param[in] char_pos
comment|///     The character position of the cursor in its argument word.
comment|///
comment|/// @param[in] match_start_point
comment|/// @param[in] match_return_elements
comment|///     See CommandObject::HandleCompletions for a description of
comment|///     how these work.
comment|///
comment|/// @param[in] interpreter
comment|///     The interpreter that's doing the completing.
comment|///
comment|/// @param[out] word_complete
comment|///     \btrue if this is a complete option value (a space will be
comment|///     inserted after the completion.) \b false otherwise.
comment|///
comment|/// @param[out] matches
comment|///     The array of matches returned.
comment|///
comment|/// FIXME: This is the wrong return value, since we also need to
comment|/// make a distinction between total number of matches, and the
comment|/// window the user wants returned.
comment|///
comment|/// @return
comment|///     \btrue if we were in an option, \bfalse otherwise.
comment|//------------------------------------------------------------------
name|bool
name|HandleOptionCompletion
argument_list|(
name|Args
operator|&
name|input
argument_list|,
name|OptionElementVector
operator|&
name|option_map
argument_list|,
name|int
name|cursor_index
argument_list|,
name|int
name|char_pos
argument_list|,
name|int
name|match_start_point
argument_list|,
name|int
name|max_return_elements
argument_list|,
name|CommandInterpreter
operator|&
name|interpreter
argument_list|,
name|bool
operator|&
name|word_complete
argument_list|,
name|lldb_private
operator|::
name|StringList
operator|&
name|matches
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Handles the generic bits of figuring out whether we are in an
comment|/// option, and if so completing it.
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
comment|/// @param[in] char_pos
comment|///     The character position of the cursor in its argument word.
comment|///
comment|/// @param[in] opt_element_vector
comment|///     The results of the options parse of \a input.
comment|///
comment|/// @param[in] opt_element_index
comment|///     The position in \a opt_element_vector of the word in \a
comment|///     input containing the cursor.
comment|///
comment|/// @param[in] match_start_point
comment|/// @param[in] match_return_elements
comment|///     See CommandObject::HandleCompletions for a description of
comment|///     how these work.
comment|///
comment|/// @param[in] interpreter
comment|///     The command interpreter in which we're doing completion.
comment|///
comment|/// @param[out] word_complete
comment|///     \btrue if this is a complete option value (a space will
comment|///     be inserted after the completion.) \bfalse otherwise.
comment|///
comment|/// @param[out] matches
comment|///     The array of matches returned.
comment|///
comment|/// FIXME: This is the wrong return value, since we also need to
comment|/// make a distinction between total number of matches, and the
comment|/// window the user wants returned.
comment|///
comment|/// @return
comment|///     \btrue if we were in an option, \bfalse otherwise.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|HandleOptionArgumentCompletion
parameter_list|(
name|Args
modifier|&
name|input
parameter_list|,
name|int
name|cursor_index
parameter_list|,
name|int
name|char_pos
parameter_list|,
name|OptionElementVector
modifier|&
name|opt_element_vector
parameter_list|,
name|int
name|opt_element_index
parameter_list|,
name|int
name|match_start_point
parameter_list|,
name|int
name|max_return_elements
parameter_list|,
name|CommandInterpreter
modifier|&
name|interpreter
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
name|protected
label|:
comment|// This is a set of options expressed as indexes into the options table for
comment|// this Option.
typedef|typedef
name|std
operator|::
name|set
operator|<
name|int
operator|>
name|OptionSet
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|OptionSet
operator|>
name|OptionSetVector
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|Option
operator|>
name|m_getopt_table
expr_stmt|;
name|OptionSet
name|m_seen_options
decl_stmt|;
name|OptionSetVector
name|m_required_options
decl_stmt|;
name|OptionSetVector
name|m_optional_options
decl_stmt|;
name|OptionSetVector
modifier|&
name|GetRequiredOptions
parameter_list|()
block|{
name|BuildValidOptionSets
argument_list|()
expr_stmt|;
return|return
name|m_required_options
return|;
block|}
name|OptionSetVector
modifier|&
name|GetOptionalOptions
parameter_list|()
block|{
name|BuildValidOptionSets
argument_list|()
expr_stmt|;
return|return
name|m_optional_options
return|;
block|}
name|bool
name|IsASubset
parameter_list|(
specifier|const
name|OptionSet
modifier|&
name|set_a
parameter_list|,
specifier|const
name|OptionSet
modifier|&
name|set_b
parameter_list|)
function_decl|;
name|size_t
name|OptionsSetDiff
parameter_list|(
specifier|const
name|OptionSet
modifier|&
name|set_a
parameter_list|,
specifier|const
name|OptionSet
modifier|&
name|set_b
parameter_list|,
name|OptionSet
modifier|&
name|diffs
parameter_list|)
function_decl|;
name|void
name|OptionsSetUnion
parameter_list|(
specifier|const
name|OptionSet
modifier|&
name|set_a
parameter_list|,
specifier|const
name|OptionSet
modifier|&
name|set_b
parameter_list|,
name|OptionSet
modifier|&
name|union_set
parameter_list|)
function_decl|;
comment|// Subclasses must reset their option values prior to starting a new
comment|// option parse. Each subclass must override this function and revert
comment|// all option settings to default values.
name|virtual
name|void
name|OptionParsingStarting
parameter_list|(
name|ExecutionContext
modifier|*
name|execution_context
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|Status
name|OptionParsingFinished
parameter_list|(
name|ExecutionContext
modifier|*
name|execution_context
parameter_list|)
block|{
comment|// If subclasses need to know when the options are done being parsed
comment|// they can implement this function to do extra checking
name|Status
name|error
decl_stmt|;
return|return
name|error
return|;
block|}
block|}
empty_stmt|;
name|class
name|OptionGroup
block|{
name|public
label|:
name|OptionGroup
argument_list|()
operator|=
expr|default
expr_stmt|;
name|virtual
operator|~
name|OptionGroup
argument_list|()
operator|=
expr|default
expr_stmt|;
name|virtual
name|llvm
operator|::
name|ArrayRef
operator|<
name|OptionDefinition
operator|>
name|GetDefinitions
argument_list|()
operator|=
literal|0
expr_stmt|;
name|virtual
name|Status
name|SetOptionValue
argument_list|(
name|uint32_t
name|option_idx
argument_list|,
name|llvm
operator|::
name|StringRef
name|option_value
argument_list|,
name|ExecutionContext
operator|*
name|execution_context
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|OptionParsingStarting
parameter_list|(
name|ExecutionContext
modifier|*
name|execution_context
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|Status
name|OptionParsingFinished
parameter_list|(
name|ExecutionContext
modifier|*
name|execution_context
parameter_list|)
block|{
comment|// If subclasses need to know when the options are done being parsed
comment|// they can implement this function to do extra checking
name|Status
name|error
decl_stmt|;
return|return
name|error
return|;
block|}
block|}
empty_stmt|;
name|class
name|OptionGroupOptions
range|:
name|public
name|Options
block|{
name|public
operator|:
name|OptionGroupOptions
argument_list|()
operator|:
name|Options
argument_list|()
block|,
name|m_option_defs
argument_list|()
block|,
name|m_option_infos
argument_list|()
block|,
name|m_did_finalize
argument_list|(
argument|false
argument_list|)
block|{}
operator|~
name|OptionGroupOptions
argument_list|()
name|override
operator|=
expr|default
block|;
comment|//----------------------------------------------------------------------
comment|/// Append options from a OptionGroup class.
comment|///
comment|/// Append all options from \a group using the exact same option groups
comment|/// that each option is defined with.
comment|///
comment|/// @param[in] group
comment|///     A group of options to take option values from and copy their
comment|///     definitions into this class.
comment|//----------------------------------------------------------------------
name|void
name|Append
argument_list|(
name|OptionGroup
operator|*
name|group
argument_list|)
block|;
comment|//----------------------------------------------------------------------
comment|/// Append options from a OptionGroup class.
comment|///
comment|/// Append options from \a group that have a usage mask that has any bits
comment|/// in "src_mask" set. After the option definition is copied into the
comment|/// options definitions in this class, set the usage_mask to "dst_mask".
comment|///
comment|/// @param[in] group
comment|///     A group of options to take option values from and copy their
comment|///     definitions into this class.
comment|///
comment|/// @param[in] src_mask
comment|///     When copying options from \a group, you might only want some of
comment|///     the options to be appended to this group. This mask allows you
comment|///     to control which options from \a group get added. It also allows
comment|///     you to specify the same options from \a group multiple times
comment|///     for different option sets.
comment|///
comment|/// @param[in] dst_mask
comment|///     Set the usage mask for any copied options to \a dst_mask after
comment|///     copying the option definition.
comment|//----------------------------------------------------------------------
name|void
name|Append
argument_list|(
argument|OptionGroup *group
argument_list|,
argument|uint32_t src_mask
argument_list|,
argument|uint32_t dst_mask
argument_list|)
block|;
name|void
name|Finalize
argument_list|()
block|;
name|bool
name|DidFinalize
argument_list|()
block|{
return|return
name|m_did_finalize
return|;
block|}
name|Status
name|SetOptionValue
argument_list|(
argument|uint32_t option_idx
argument_list|,
argument|llvm::StringRef option_arg
argument_list|,
argument|ExecutionContext *execution_context
argument_list|)
name|override
block|;
name|void
name|OptionParsingStarting
argument_list|(
argument|ExecutionContext *execution_context
argument_list|)
name|override
block|;
name|Status
name|OptionParsingFinished
argument_list|(
argument|ExecutionContext *execution_context
argument_list|)
name|override
block|;
name|llvm
operator|::
name|ArrayRef
operator|<
name|OptionDefinition
operator|>
name|GetDefinitions
argument_list|()
name|override
block|{
name|assert
argument_list|(
name|m_did_finalize
argument_list|)
block|;
return|return
name|m_option_defs
return|;
block|}
specifier|const
name|OptionGroup
operator|*
name|GetGroupWithOption
argument_list|(
argument|char short_opt
argument_list|)
block|;    struct
name|OptionInfo
block|{
name|OptionInfo
argument_list|(
argument|OptionGroup *g
argument_list|,
argument|uint32_t i
argument_list|)
operator|:
name|option_group
argument_list|(
name|g
argument_list|)
block|,
name|option_index
argument_list|(
argument|i
argument_list|)
block|{}
name|OptionGroup
operator|*
name|option_group
block|;
comment|// The group that this option came from
name|uint32_t
name|option_index
block|;
comment|// The original option index from the OptionGroup
block|}
block|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|OptionInfo
operator|>
name|OptionInfos
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|OptionDefinition
operator|>
name|m_option_defs
decl_stmt|;
name|OptionInfos
name|m_option_infos
decl_stmt|;
name|bool
name|m_did_finalize
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_Options_h_
end_comment

end_unit

