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
file|<utility>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Utility/Status.h"
end_include

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

begin_decl_stmt
name|namespace
name|lldb_private
block|{
struct_decl|struct
name|Option
struct_decl|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|tuple
operator|<
name|std
operator|::
name|string
operator|,
name|int
operator|,
name|std
operator|::
name|string
operator|>>
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
block|{}
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
struct|struct
name|ArgEntry
block|{
name|private
label|:
name|friend
name|class
name|Args
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|char
index|[]
operator|>
name|ptr
expr_stmt|;
name|char
modifier|*
name|data
parameter_list|()
block|{
return|return
name|ptr
operator|.
name|get
argument_list|()
return|;
block|}
name|public
label|:
name|ArgEntry
argument_list|()
operator|=
expr|default
expr_stmt|;
name|ArgEntry
argument_list|(
argument|llvm::StringRef str
argument_list|,
argument|char quote
argument_list|)
empty_stmt|;
name|llvm
operator|::
name|StringRef
name|ref
expr_stmt|;
name|char
name|quote
decl_stmt|;
specifier|const
name|char
operator|*
name|c_str
argument_list|()
specifier|const
block|{
return|return
name|ptr
operator|.
name|get
argument_list|()
return|;
block|}
block|}
struct|;
comment|//------------------------------------------------------------------
comment|/// Construct with an option command string.
comment|///
comment|/// @param[in] command
comment|///     A NULL terminated command that will be copied and split up
comment|///     into arguments.
comment|///
comment|/// @see Args::SetCommandString(llvm::StringRef)
comment|//------------------------------------------------------------------
name|Args
argument_list|(
argument|llvm::StringRef command = llvm::StringRef()
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
comment|/// Dump all entries to the stream \a s using label \a label_name.
comment|///
comment|/// If label_name is nullptr, the dump operation is skipped.
comment|///
comment|/// @param[in] s
comment|///     The stream to which to dump all arguments in the argument
comment|///     vector.
comment|/// @param[in] label_name
comment|///     The label_name to use as the label printed for each
comment|///     entry of the args like so:
comment|///       {label_name}[{index}]={value}
comment|//------------------------------------------------------------------
name|void
name|Dump
argument_list|(
name|Stream
operator|&
name|s
argument_list|,
specifier|const
name|char
operator|*
name|label_name
operator|=
literal|"argv"
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Sets the command string contained by this object.
comment|///
comment|/// The command string will be copied and split up into arguments
comment|/// that can be accessed via the accessor functions.
comment|///
comment|/// @param[in] command
comment|///     A command StringRef that will be copied and split up
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
argument_list|(
name|llvm
operator|::
name|StringRef
name|command
argument_list|)
decl_stmt|;
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
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|GetArgumentCount
argument_list|()
operator|==
literal|0
return|;
block|}
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
name|llvm
operator|::
name|ArrayRef
operator|<
name|ArgEntry
operator|>
name|entries
argument_list|()
specifier|const
block|{
return|return
name|m_entries
return|;
block|}
name|char
name|GetArgumentQuoteCharAtIndex
argument_list|(
name|size_t
name|idx
argument_list|)
decl|const
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|ArgEntry
operator|>
operator|::
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|m_entries
operator|.
name|begin
argument_list|()
return|;
block|}
name|std
operator|::
name|vector
operator|<
name|ArgEntry
operator|>
operator|::
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|m_entries
operator|.
name|end
argument_list|()
return|;
block|}
name|size_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|GetArgumentCount
argument_list|()
return|;
block|}
specifier|const
name|ArgEntry
modifier|&
name|operator
index|[]
argument_list|(
name|size_t
name|n
argument_list|)
decl|const
block|{
return|return
name|m_entries
index|[
name|n
index|]
return|;
block|}
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
comment|/// Gets the argument as an ArrayRef. Note that the return value does *not*
comment|/// have a nullptr const char * at the end, as the size of the list is
comment|/// embedded in the ArrayRef object.
comment|//------------------------------------------------------------------
name|llvm
operator|::
name|ArrayRef
operator|<
specifier|const
name|char
operator|*
operator|>
name|GetArgumentArrayRef
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|m_argv
argument_list|)
operator|.
name|drop_back
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Appends a new argument to the end of the list argument list.
comment|///
comment|/// @param[in] arg_cstr
comment|///     The new argument as a NULL terminated C string.
comment|///
comment|/// @param[in] quote_char
comment|///     If the argument was originally quoted, put in the quote char here.
comment|//------------------------------------------------------------------
name|void
name|AppendArgument
argument_list|(
name|llvm
operator|::
name|StringRef
name|arg_str
argument_list|,
name|char
name|quote_char
operator|=
literal|'\0'
argument_list|)
decl_stmt|;
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
name|void
name|InsertArgumentAtIndex
argument_list|(
name|size_t
name|idx
argument_list|,
name|llvm
operator|::
name|StringRef
name|arg_str
argument_list|,
name|char
name|quote_char
operator|=
literal|'\0'
argument_list|)
decl_stmt|;
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
comment|//------------------------------------------------------------------
name|void
name|ReplaceArgumentAtIndex
argument_list|(
name|size_t
name|idx
argument_list|,
name|llvm
operator|::
name|StringRef
name|arg_str
argument_list|,
name|char
name|quote_char
operator|=
literal|'\0'
argument_list|)
decl_stmt|;
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
comment|///     The argument to push on the front of the argument stack.
comment|///
comment|/// @param[in] quote_char
comment|///     If the argument was originally quoted, put in the quote char here.
comment|//------------------------------------------------------------------
name|void
name|Unshift
argument_list|(
name|llvm
operator|::
name|StringRef
name|arg_str
argument_list|,
name|char
name|quote_char
operator|=
literal|'\0'
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Parse the arguments in the contained arguments.
comment|///
comment|/// The arguments that are consumed by the argument parsing process
comment|/// will be removed from the argument vector. The arguments that
comment|/// get processed start at the second argument. The first argument
comment|/// is assumed to be the command and will not be touched.
comment|///
comment|/// param[in] platform_sp
comment|///   The platform used for option validation.  This is necessary
comment|///   because an empty execution_context is not enough to get us
comment|///   to a reasonable platform.  If the platform isn't given,
comment|///   we'll try to get it from the execution context.  If we can't
comment|///   get it from the execution context, we'll skip validation.
comment|///
comment|/// param[in] require_validation
comment|///   When true, it will fail option parsing if validation could
comment|///   not occur due to not having a platform.
comment|///
comment|/// @see class Options
comment|//------------------------------------------------------------------
name|Status
name|ParseOptions
argument_list|(
name|Options
operator|&
name|options
argument_list|,
name|ExecutionContext
operator|*
name|execution_context
argument_list|,
name|lldb
operator|::
name|PlatformSP
name|platform_sp
argument_list|,
name|bool
name|require_validation
argument_list|)
decl_stmt|;
name|bool
name|IsPositionalArgument
parameter_list|(
specifier|const
name|char
modifier|*
name|arg
parameter_list|)
function_decl|;
comment|// The following works almost identically to ParseOptions, except that no
comment|// option is required to have arguments, and it builds up the
comment|// option_arg_vector as it parses the options.
name|std
operator|::
name|string
name|ParseAliasOptions
argument_list|(
argument|Options&options
argument_list|,
argument|CommandReturnObject&result
argument_list|,
argument|OptionArgVector *option_arg_vector
argument_list|,
argument|llvm::StringRef raw_input_line
argument_list|)
expr_stmt|;
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
argument|llvm::StringRef s
argument_list|,
argument|lldb::addr_t fail_value
argument_list|,
argument|Status *error
argument_list|)
expr_stmt|;
specifier|static
name|bool
name|StringToBoolean
argument_list|(
name|llvm
operator|::
name|StringRef
name|s
argument_list|,
name|bool
name|fail_value
argument_list|,
name|bool
operator|*
name|success_ptr
argument_list|)
decl_stmt|;
specifier|static
name|char
name|StringToChar
argument_list|(
name|llvm
operator|::
name|StringRef
name|s
argument_list|,
name|char
name|fail_value
argument_list|,
name|bool
operator|*
name|success_ptr
argument_list|)
decl_stmt|;
specifier|static
name|int64_t
name|StringToOptionEnum
argument_list|(
name|llvm
operator|::
name|StringRef
name|s
argument_list|,
name|OptionEnumValueElement
operator|*
name|enum_values
argument_list|,
name|int32_t
name|fail_value
argument_list|,
name|Status
operator|&
name|error
argument_list|)
decl_stmt|;
specifier|static
name|lldb
operator|::
name|ScriptLanguage
name|StringToScriptLanguage
argument_list|(
argument|llvm::StringRef s
argument_list|,
argument|lldb::ScriptLanguage fail_value
argument_list|,
argument|bool *success_ptr
argument_list|)
expr_stmt|;
comment|// TODO: Use StringRef
specifier|static
name|Status
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
comment|// If non-NULL, then a
comment|// byte size can precede
comment|// the format character
specifier|static
name|lldb
operator|::
name|Encoding
name|StringToEncoding
argument_list|(
argument|llvm::StringRef s
argument_list|,
argument|lldb::Encoding fail_value = lldb::eEncodingInvalid
argument_list|)
expr_stmt|;
specifier|static
name|uint32_t
name|StringToGenericRegister
argument_list|(
name|llvm
operator|::
name|StringRef
name|s
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|StringToVersion
argument_list|(
name|llvm
operator|::
name|StringRef
name|string
argument_list|,
name|uint32_t
operator|&
name|major
argument_list|,
name|uint32_t
operator|&
name|minor
argument_list|,
name|uint32_t
operator|&
name|update
argument_list|)
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|GetShellSafeArgument
argument_list|(
specifier|const
name|FileSpec
operator|&
name|shell
argument_list|,
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
comment|// characters and expand them into text. So '\n' will turn into two characters
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
specifier|static
name|std
operator|::
name|string
name|EscapeLLDBCommandArgument
argument_list|(
argument|const std::string&arg
argument_list|,
argument|char quote_char
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Add or replace an environment variable with the given value.
comment|///
comment|/// This command adds the environment variable if it is not already
comment|/// present using the given value.  If the environment variable is
comment|/// already in the list, it replaces the first such occurrence
comment|/// with the new value.
comment|//------------------------------------------------------------------
name|void
name|AddOrReplaceEnvironmentVariable
argument_list|(
name|llvm
operator|::
name|StringRef
name|env_var_name
argument_list|,
name|llvm
operator|::
name|StringRef
name|new_value
argument_list|)
decl_stmt|;
comment|/// Return whether a given environment variable exists.
comment|///
comment|/// This command treats Args like a list of environment variables,
comment|/// as used in ProcessLaunchInfo.  It treats each argument as
comment|/// an {env_var_name}={value} or an {env_var_name} entry.
comment|///
comment|/// @param[in] env_var_name
comment|///     Specifies the name of the environment variable to check.
comment|///
comment|/// @param[out] argument_index
comment|///     If non-null, then when the environment variable is found,
comment|///     the index of the argument position will be returned in
comment|///     the size_t pointed to by this argument.
comment|///
comment|/// @return
comment|///     true if the specified env var name exists in the list in
comment|///     either of the above-mentioned formats; otherwise, false.
comment|//------------------------------------------------------------------
name|bool
name|ContainsEnvironmentVariable
argument_list|(
name|llvm
operator|::
name|StringRef
name|env_var_name
argument_list|,
name|size_t
operator|*
name|argument_index
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|size_t
name|FindArgumentIndexForOption
argument_list|(
name|Option
operator|*
name|long_options
argument_list|,
name|int
name|long_options_index
argument_list|)
decl|const
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|ArgEntry
operator|>
name|m_entries
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|char
operator|*
operator|>
name|m_argv
expr_stmt|;
name|void
name|UpdateArgsAfterOptionParsing
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

