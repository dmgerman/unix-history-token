begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Args.h --------------------------------------------------*- C++ -*-===//
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
name|liblldb_Command_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Command_h_
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
file|<list>
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
file|<utility>
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
file|"lldb/lldb-private-types.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Error.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/OptionParser.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|int
operator|,
name|std
operator|::
name|string
operator|>
name|OptionArgValue
expr_stmt|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
operator|,
name|OptionArgValue
operator|>
name|OptionArgPair
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|OptionArgPair
operator|>
name|OptionArgVector
expr_stmt|;
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|OptionArgVector
operator|>
name|OptionArgVectorSP
expr_stmt|;
struct|struct
name|OptionArgElement
block|{
enum|enum
block|{
name|eUnrecognizedArg
init|=
operator|-
literal|1
block|,
name|eBareDash
init|=
operator|-
literal|2
block|,
name|eBareDoubleDash
init|=
operator|-
literal|3
block|}
enum|;
name|OptionArgElement
argument_list|(
argument|int defs_index
argument_list|,
argument|int pos
argument_list|,
argument|int arg_pos
argument_list|)
block|:
name|opt_defs_index
argument_list|(
name|defs_index
argument_list|)
operator|,
name|opt_pos
argument_list|(
name|pos
argument_list|)
operator|,
name|opt_arg_pos
argument_list|(
argument|arg_pos
argument_list|)
block|{     }
name|int
name|opt_defs_index
expr_stmt|;
name|int
name|opt_pos
decl_stmt|;
name|int
name|opt_arg_pos
decl_stmt|;
block|}
struct|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|OptionArgElement
operator|>
name|OptionElementVector
expr_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class Args Args.h "lldb/Interpreter/Args.h"
comment|/// @brief A command line argument class.
comment|///
comment|/// The Args class is designed to be fed a command line. The
comment|/// command line is copied into an internal buffer and then split up
comment|/// into arguments. Arguments are space delimited if there are no quotes
comment|/// (single, double, or backtick quotes) surrounding the argument. Spaces
comment|/// can be escaped using a \ character to avoid having to surround an
comment|/// argument that contains a space with quotes.
comment|//----------------------------------------------------------------------
name|class
name|Args
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Construct with an option command string.
comment|///
comment|/// @param[in] command
comment|///     A NULL terminated command that will be copied and split up
comment|///     into arguments.
comment|///
comment|/// @see Args::SetCommandString(const char *)
comment|//------------------------------------------------------------------
name|Args
argument_list|(
specifier|const
name|char
operator|*
name|command
operator|=
name|NULL
argument_list|)
expr_stmt|;
name|Args
argument_list|(
argument|const char *command
argument_list|,
argument|size_t len
argument_list|)
empty_stmt|;
name|Args
argument_list|(
specifier|const
name|Args
operator|&
name|rhs
argument_list|)
expr_stmt|;
specifier|const
name|Args
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Args
operator|&
name|rhs
operator|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor.
comment|//------------------------------------------------------------------
operator|~
name|Args
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Dump all arguments to the stream \a s.
comment|///
comment|/// @param[in] s
comment|///     The stream to which to dump all arguments in the argument
comment|///     vector.
comment|//------------------------------------------------------------------
name|void
name|Dump
parameter_list|(
name|Stream
modifier|*
name|s
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Sets the command string contained by this object.
comment|///
comment|/// The command string will be copied and split up into arguments
comment|/// that can be accessed via the accessor functions.
comment|///
comment|/// @param[in] command
comment|///     A NULL terminated command that will be copied and split up
comment|///     into arguments.
comment|///
comment|/// @see Args::GetArgumentCount() const
comment|/// @see Args::GetArgumentAtIndex (size_t) const
comment|/// @see Args::GetArgumentVector ()
comment|/// @see Args::Shift ()
comment|/// @see Args::Unshift (const char *)
comment|//------------------------------------------------------------------
name|void
name|SetCommandString
parameter_list|(
specifier|const
name|char
modifier|*
name|command
parameter_list|)
function_decl|;
name|void
name|SetCommandString
parameter_list|(
specifier|const
name|char
modifier|*
name|command
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
name|bool
name|GetCommandString
argument_list|(
name|std
operator|::
name|string
operator|&
name|command
argument_list|)
decl|const
decl_stmt|;
name|bool
name|GetQuotedCommandString
argument_list|(
name|std
operator|::
name|string
operator|&
name|command
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Gets the number of arguments left in this command object.
comment|///
comment|/// @return
comment|///     The number or arguments in this object.
comment|//------------------------------------------------------------------
name|size_t
name|GetArgumentCount
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Gets the NULL terminated C string argument pointer for the
comment|/// argument at index \a idx.
comment|///
comment|/// @return
comment|///     The NULL terminated C string argument pointer if \a idx is a
comment|///     valid argument index, NULL otherwise.
comment|//------------------------------------------------------------------
specifier|const
name|char
modifier|*
name|GetArgumentAtIndex
argument_list|(
name|size_t
name|idx
argument_list|)
decl|const
decl_stmt|;
name|char
name|GetArgumentQuoteCharAtIndex
argument_list|(
name|size_t
name|idx
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Gets the argument vector.
comment|///
comment|/// The value returned by this function can be used by any function
comment|/// that takes and vector. The return value is just like \a argv
comment|/// in the standard C entry point function:
comment|///     \code
comment|///         int main (int argc, const char **argv);
comment|///     \endcode
comment|///
comment|/// @return
comment|///     An array of NULL terminated C string argument pointers that
comment|///     also has a terminating NULL C string pointer
comment|//------------------------------------------------------------------
name|char
modifier|*
modifier|*
name|GetArgumentVector
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Gets the argument vector.
comment|///
comment|/// The value returned by this function can be used by any function
comment|/// that takes and vector. The return value is just like \a argv
comment|/// in the standard C entry point function:
comment|///     \code
comment|///         int main (int argc, const char **argv);
comment|///     \endcode
comment|///
comment|/// @return
comment|///     An array of NULL terminate C string argument pointers that
comment|///     also has a terminating NULL C string pointer
comment|//------------------------------------------------------------------
specifier|const
name|char
operator|*
operator|*
name|GetConstArgumentVector
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Appends a new argument to the end of the list argument list.
comment|///
comment|/// @param[in] arg_cstr
comment|///     The new argument as a NULL terminated C string.
comment|///
comment|/// @param[in] quote_char
comment|///     If the argument was originally quoted, put in the quote char here.
comment|///
comment|/// @return
comment|///     The NULL terminated C string of the copy of \a arg_cstr.
comment|//------------------------------------------------------------------
specifier|const
name|char
modifier|*
name|AppendArgument
parameter_list|(
specifier|const
name|char
modifier|*
name|arg_cstr
parameter_list|,
name|char
name|quote_char
init|=
literal|'\0'
parameter_list|)
function_decl|;
name|void
name|AppendArguments
parameter_list|(
specifier|const
name|Args
modifier|&
name|rhs
parameter_list|)
function_decl|;
name|void
name|AppendArguments
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Insert the argument value at index \a idx to \a arg_cstr.
comment|///
comment|/// @param[in] idx
comment|///     The index of where to insert the argument.
comment|///
comment|/// @param[in] arg_cstr
comment|///     The new argument as a NULL terminated C string.
comment|///
comment|/// @param[in] quote_char
comment|///     If the argument was originally quoted, put in the quote char here.
comment|///
comment|/// @return
comment|///     The NULL terminated C string of the copy of \a arg_cstr.
comment|//------------------------------------------------------------------
specifier|const
name|char
modifier|*
name|InsertArgumentAtIndex
parameter_list|(
name|size_t
name|idx
parameter_list|,
specifier|const
name|char
modifier|*
name|arg_cstr
parameter_list|,
name|char
name|quote_char
init|=
literal|'\0'
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Replaces the argument value at index \a idx to \a arg_cstr
comment|/// if \a idx is a valid argument index.
comment|///
comment|/// @param[in] idx
comment|///     The index of the argument that will have its value replaced.
comment|///
comment|/// @param[in] arg_cstr
comment|///     The new argument as a NULL terminated C string.
comment|///
comment|/// @param[in] quote_char
comment|///     If the argument was originally quoted, put in the quote char here.
comment|///
comment|/// @return
comment|///     The NULL terminated C string of the copy of \a arg_cstr if
comment|///     \a idx was a valid index, NULL otherwise.
comment|//------------------------------------------------------------------
specifier|const
name|char
modifier|*
name|ReplaceArgumentAtIndex
parameter_list|(
name|size_t
name|idx
parameter_list|,
specifier|const
name|char
modifier|*
name|arg_cstr
parameter_list|,
name|char
name|quote_char
init|=
literal|'\0'
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Deletes the argument value at index
comment|/// if \a idx is a valid argument index.
comment|///
comment|/// @param[in] idx
comment|///     The index of the argument that will have its value replaced.
comment|///
comment|//------------------------------------------------------------------
name|void
name|DeleteArgumentAtIndex
parameter_list|(
name|size_t
name|idx
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Sets the argument vector value, optionally copying all
comment|/// arguments into an internal buffer.
comment|///
comment|/// Sets the arguments to match those found in \a argv. All argument
comment|/// strings will be copied into an internal buffers.
comment|//
comment|//  FIXME: Handle the quote character somehow.
comment|//------------------------------------------------------------------
name|void
name|SetArguments
parameter_list|(
name|size_t
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
name|void
name|SetArguments
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Shifts the first argument C string value of the array off the
comment|/// argument array.
comment|///
comment|/// The string value will be freed, so a copy of the string should
comment|/// be made by calling Args::GetArgumentAtIndex (size_t) const
comment|/// first and copying the returned value before calling
comment|/// Args::Shift().
comment|///
comment|/// @see Args::GetArgumentAtIndex (size_t) const
comment|//------------------------------------------------------------------
name|void
name|Shift
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Inserts a class owned copy of \a arg_cstr at the beginning of
comment|/// the argument vector.
comment|///
comment|/// A copy \a arg_cstr will be made.
comment|///
comment|/// @param[in] arg_cstr
comment|///     The argument to push on the front the the argument stack.
comment|///
comment|/// @param[in] quote_char
comment|///     If the argument was originally quoted, put in the quote char here.
comment|///
comment|/// @return
comment|///     A pointer to the copy of \a arg_cstr that was made.
comment|//------------------------------------------------------------------
specifier|const
name|char
modifier|*
name|Unshift
parameter_list|(
specifier|const
name|char
modifier|*
name|arg_cstr
parameter_list|,
name|char
name|quote_char
init|=
literal|'\0'
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Parse the arguments in the contained arguments.
comment|///
comment|/// The arguments that are consumed by the argument parsing process
comment|/// will be removed from the argument vector. The arguements that
comment|/// get processed start at the second argument. The first argument
comment|/// is assumed to be the command and will not be touched.
comment|///
comment|/// @see class Options
comment|//------------------------------------------------------------------
name|Error
name|ParseOptions
parameter_list|(
name|Options
modifier|&
name|options
parameter_list|)
function_decl|;
name|size_t
name|FindArgumentIndexForOption
parameter_list|(
name|Option
modifier|*
name|long_options
parameter_list|,
name|int
name|long_options_index
parameter_list|)
function_decl|;
name|bool
name|IsPositionalArgument
parameter_list|(
specifier|const
name|char
modifier|*
name|arg
parameter_list|)
function_decl|;
comment|// The following works almost identically to ParseOptions, except that no option is required to have arguments,
comment|// and it builds up the option_arg_vector as it parses the options.
name|void
name|ParseAliasOptions
argument_list|(
name|Options
operator|&
name|options
argument_list|,
name|CommandReturnObject
operator|&
name|result
argument_list|,
name|OptionArgVector
operator|*
name|option_arg_vector
argument_list|,
name|std
operator|::
name|string
operator|&
name|raw_input_line
argument_list|)
decl_stmt|;
name|void
name|ParseArgsForCompletion
parameter_list|(
name|Options
modifier|&
name|options
parameter_list|,
name|OptionElementVector
modifier|&
name|option_element_vector
parameter_list|,
name|uint32_t
name|cursor_index
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|// Clear the arguments.
comment|//
comment|// For re-setting or blanking out the list of arguments.
comment|//------------------------------------------------------------------
name|void
name|Clear
parameter_list|()
function_decl|;
specifier|static
specifier|const
name|char
modifier|*
name|StripSpaces
argument_list|(
name|std
operator|::
name|string
operator|&
name|s
argument_list|,
name|bool
name|leading
operator|=
name|true
argument_list|,
name|bool
name|trailing
operator|=
name|true
argument_list|,
name|bool
name|return_null_if_empty
operator|=
name|true
argument_list|)
decl_stmt|;
specifier|static
name|int32_t
name|StringToSInt32
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|int32_t
name|fail_value
init|=
literal|0
parameter_list|,
name|int
name|base
init|=
literal|0
parameter_list|,
name|bool
modifier|*
name|success_ptr
init|=
name|NULL
parameter_list|)
function_decl|;
specifier|static
name|uint32_t
name|StringToUInt32
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|uint32_t
name|fail_value
init|=
literal|0
parameter_list|,
name|int
name|base
init|=
literal|0
parameter_list|,
name|bool
modifier|*
name|success_ptr
init|=
name|NULL
parameter_list|)
function_decl|;
specifier|static
name|int64_t
name|StringToSInt64
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|int64_t
name|fail_value
init|=
literal|0
parameter_list|,
name|int
name|base
init|=
literal|0
parameter_list|,
name|bool
modifier|*
name|success_ptr
init|=
name|NULL
parameter_list|)
function_decl|;
specifier|static
name|uint64_t
name|StringToUInt64
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|uint64_t
name|fail_value
init|=
literal|0
parameter_list|,
name|int
name|base
init|=
literal|0
parameter_list|,
name|bool
modifier|*
name|success_ptr
init|=
name|NULL
parameter_list|)
function_decl|;
specifier|static
name|bool
name|UInt64ValueIsValidForByteSize
parameter_list|(
name|uint64_t
name|uval64
parameter_list|,
name|size_t
name|total_byte_size
parameter_list|)
block|{
if|if
condition|(
name|total_byte_size
operator|>
literal|8
condition|)
return|return
name|false
return|;
if|if
condition|(
name|total_byte_size
operator|==
literal|8
condition|)
return|return
name|true
return|;
specifier|const
name|uint64_t
name|max
init|=
operator|(
operator|(
name|uint64_t
operator|)
literal|1
operator|<<
call|(
name|uint64_t
call|)
argument_list|(
name|total_byte_size
operator|*
literal|8
argument_list|)
operator|)
operator|-
literal|1
decl_stmt|;
return|return
name|uval64
operator|<=
name|max
return|;
block|}
specifier|static
name|bool
name|SInt64ValueIsValidForByteSize
parameter_list|(
name|int64_t
name|sval64
parameter_list|,
name|size_t
name|total_byte_size
parameter_list|)
block|{
if|if
condition|(
name|total_byte_size
operator|>
literal|8
condition|)
return|return
name|false
return|;
if|if
condition|(
name|total_byte_size
operator|==
literal|8
condition|)
return|return
name|true
return|;
specifier|const
name|int64_t
name|max
init|=
operator|(
operator|(
name|int64_t
operator|)
literal|1
operator|<<
call|(
name|uint64_t
call|)
argument_list|(
name|total_byte_size
operator|*
literal|8
operator|-
literal|1
argument_list|)
operator|)
operator|-
literal|1
decl_stmt|;
specifier|const
name|int64_t
name|min
init|=
operator|~
operator|(
name|max
operator|)
decl_stmt|;
return|return
name|min
operator|<=
name|sval64
operator|&&
name|sval64
operator|<=
name|max
return|;
block|}
specifier|static
name|lldb
operator|::
name|addr_t
name|StringToAddress
argument_list|(
argument|const ExecutionContext *exe_ctx
argument_list|,
argument|const char *s
argument_list|,
argument|lldb::addr_t fail_value
argument_list|,
argument|Error *error
argument_list|)
expr_stmt|;
specifier|static
name|bool
name|StringToBoolean
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|bool
name|fail_value
parameter_list|,
name|bool
modifier|*
name|success_ptr
parameter_list|)
function_decl|;
specifier|static
name|int64_t
name|StringToOptionEnum
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|OptionEnumValueElement
modifier|*
name|enum_values
parameter_list|,
name|int32_t
name|fail_value
parameter_list|,
name|Error
modifier|&
name|error
parameter_list|)
function_decl|;
specifier|static
name|lldb
operator|::
name|ScriptLanguage
name|StringToScriptLanguage
argument_list|(
argument|const char *s
argument_list|,
argument|lldb::ScriptLanguage fail_value
argument_list|,
argument|bool *success_ptr
argument_list|)
expr_stmt|;
specifier|static
name|Error
name|StringToFormat
argument_list|(
specifier|const
name|char
operator|*
name|s
argument_list|,
name|lldb
operator|::
name|Format
operator|&
name|format
argument_list|,
name|size_t
operator|*
name|byte_size_ptr
argument_list|)
decl_stmt|;
comment|// If non-NULL, then a byte size can precede the format character
specifier|static
name|lldb
operator|::
name|Encoding
name|StringToEncoding
argument_list|(
argument|const char *s
argument_list|,
argument|lldb::Encoding fail_value = lldb::eEncodingInvalid
argument_list|)
expr_stmt|;
specifier|static
name|uint32_t
name|StringToGenericRegister
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
specifier|static
specifier|const
name|char
modifier|*
name|StringToVersion
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|uint32_t
modifier|&
name|major
parameter_list|,
name|uint32_t
modifier|&
name|minor
parameter_list|,
name|uint32_t
modifier|&
name|update
parameter_list|)
function_decl|;
specifier|static
specifier|const
name|char
modifier|*
name|GetShellSafeArgument
argument_list|(
specifier|const
name|char
operator|*
name|unsafe_arg
argument_list|,
name|std
operator|::
name|string
operator|&
name|safe_arg
argument_list|)
decl_stmt|;
comment|// EncodeEscapeSequences will change the textual representation of common
comment|// escape sequences like "\n" (two characters) into a single '\n'. It does
comment|// this for all of the supported escaped sequences and for the \0ooo (octal)
comment|// and \xXX (hex). The resulting "dst" string will contain the character
comment|// versions of all supported escape sequences. The common supported escape
comment|// sequences are: "\a", "\b", "\f", "\n", "\r", "\t", "\v", "\'", "\"", "\\".
specifier|static
name|void
name|EncodeEscapeSequences
argument_list|(
specifier|const
name|char
operator|*
name|src
argument_list|,
name|std
operator|::
name|string
operator|&
name|dst
argument_list|)
decl_stmt|;
comment|// ExpandEscapeSequences will change a string of possibly non-printable
comment|// characters and expand them into text. So '\n' will turn into two chracters
comment|// like "\n" which is suitable for human reading. When a character is not
comment|// printable and isn't one of the common in escape sequences listed in the
comment|// help for EncodeEscapeSequences, then it will be encoded as octal. Printable
comment|// characters are left alone.
specifier|static
name|void
name|ExpandEscapedCharacters
argument_list|(
specifier|const
name|char
operator|*
name|src
argument_list|,
name|std
operator|::
name|string
operator|&
name|dst
argument_list|)
decl_stmt|;
comment|// This one isn't really relevant to Arguments per se, but we're using the Args as a
comment|// general strings container, so...
name|void
name|LongestCommonPrefix
argument_list|(
name|std
operator|::
name|string
operator|&
name|common_prefix
argument_list|)
decl_stmt|;
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// Classes that inherit from Args can see and modify these
comment|//------------------------------------------------------------------
typedef|typedef
name|std
operator|::
name|list
operator|<
name|std
operator|::
name|string
operator|>
name|arg_sstr_collection
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
specifier|const
name|char
operator|*
operator|>
name|arg_cstr_collection
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|char
operator|>
name|arg_quote_char_collection
expr_stmt|;
name|arg_sstr_collection
name|m_args
decl_stmt|;
name|arg_cstr_collection
name|m_argv
decl_stmt|;
comment|///< The current argument vector.
name|arg_quote_char_collection
name|m_args_quote_char
decl_stmt|;
name|void
name|UpdateArgsAfterOptionParsing
parameter_list|()
function_decl|;
name|void
name|UpdateArgvFromArgs
parameter_list|()
function_decl|;
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
comment|// liblldb_Command_h_
end_comment

end_unit

