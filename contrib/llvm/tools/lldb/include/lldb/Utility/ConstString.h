begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ConstString.h -------------------------------------------*- C++ -*-===//
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
name|liblldb_ConstString_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ConstString_h_
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/FormatVariadic.h"
end_include

begin_comment
comment|// for format_provider
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|// for size_t
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Stream
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class ConstString ConstString.h "lldb/Utility/ConstString.h"
comment|/// @brief A uniqued constant string class.
comment|///
comment|/// Provides an efficient way to store strings as uniqued strings. After
comment|/// the strings are uniqued, finding strings that are equal to one
comment|/// another is very fast as just the pointers need to be compared. It
comment|/// also allows for many common strings from many different sources to
comment|/// be shared to keep the memory footprint low.
comment|///
comment|/// No reference counting is done on strings that are added to the
comment|/// string pool, once strings are added they are in the string pool for
comment|/// the life of the program.
comment|//----------------------------------------------------------------------
name|class
name|ConstString
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Default constructor
comment|///
comment|/// Initializes the string to an empty string.
comment|//------------------------------------------------------------------
name|ConstString
argument_list|()
operator|:
name|m_string
argument_list|(
argument|nullptr
argument_list|)
block|{}
comment|//------------------------------------------------------------------
comment|/// Copy constructor
comment|///
comment|/// Copies the string value in \a rhs into this object.
comment|///
comment|/// @param[in] rhs
comment|///     Another string object to copy.
comment|//------------------------------------------------------------------
name|ConstString
argument_list|(
specifier|const
name|ConstString
operator|&
name|rhs
argument_list|)
operator|:
name|m_string
argument_list|(
argument|rhs.m_string
argument_list|)
block|{}
name|explicit
name|ConstString
argument_list|(
specifier|const
name|llvm
operator|::
name|StringRef
operator|&
name|s
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Construct with C String value
comment|///
comment|/// Constructs this object with a C string by looking to see if the
comment|/// C string already exists in the global string pool. If it doesn't
comment|/// exist, it is added to the string pool.
comment|///
comment|/// @param[in] cstr
comment|///     A NULL terminated C string to add to the string pool.
comment|//------------------------------------------------------------------
name|explicit
name|ConstString
parameter_list|(
specifier|const
name|char
modifier|*
name|cstr
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Construct with C String value with max length
comment|///
comment|/// Constructs this object with a C string with a length. If
comment|/// \a max_cstr_len is greater than the actual length of the string,
comment|/// the string length will be truncated. This allows substrings to
comment|/// be created without the need to NULL terminate the string as it
comment|/// is passed into this function.
comment|///
comment|/// @param[in] cstr
comment|///     A pointer to the first character in the C string. The C
comment|///     string can be NULL terminated in a buffer that contains
comment|///     more characters than the length of the string, or the
comment|///     string can be part of another string and a new substring
comment|///     can be created.
comment|///
comment|/// @param[in] max_cstr_len
comment|///     The max length of \a cstr. If the string length of \a cstr
comment|///     is less than \a max_cstr_len, then the string will be
comment|///     truncated. If the string length of \a cstr is greater than
comment|///     \a max_cstr_len, then only max_cstr_len bytes will be used
comment|///     from \a cstr.
comment|//------------------------------------------------------------------
name|explicit
name|ConstString
parameter_list|(
specifier|const
name|char
modifier|*
name|cstr
parameter_list|,
name|size_t
name|max_cstr_len
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Destructor
comment|///
comment|/// Since constant string values are currently not reference counted,
comment|/// there isn't much to do here.
comment|//------------------------------------------------------------------
operator|~
name|ConstString
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|//----------------------------------------------------------------------
comment|/// C string equality binary predicate function object for ConstString
comment|/// objects.
comment|//----------------------------------------------------------------------
struct|struct
name|StringIsEqual
block|{
comment|//--------------------------------------------------------------
comment|/// C equality test.
comment|///
comment|/// Two C strings are equal when they are contained in ConstString
comment|/// objects when their pointer values are equal to each other.
comment|///
comment|/// @return
comment|///     Returns \b true if the C string in \a lhs is equal to
comment|///     the C string value in \a rhs, \b false otherwise.
comment|//--------------------------------------------------------------
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|char
operator|*
name|lhs
operator|,
specifier|const
name|char
operator|*
name|rhs
operator|)
specifier|const
block|{
return|return
name|lhs
operator|==
name|rhs
return|;
block|}
block|}
struct|;
comment|//------------------------------------------------------------------
comment|/// Convert to bool operator.
comment|///
comment|/// This allows code to check a ConstString object to see if it
comment|/// contains a valid string using code such as:
comment|///
comment|/// @code
comment|/// ConstString str(...);
comment|/// if (str)
comment|/// { ...
comment|/// @endcode
comment|///
comment|/// @return
comment|///     /b True this object contains a valid non-empty C string, \b
comment|///     false otherwise.
comment|//------------------------------------------------------------------
name|explicit
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|m_string
operator|&&
name|m_string
index|[
literal|0
index|]
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Assignment operator
comment|///
comment|/// Assigns the string in this object with the value from \a rhs.
comment|///
comment|/// @param[in] rhs
comment|///     Another string object to copy into this object.
comment|///
comment|/// @return
comment|///     A const reference to this object.
comment|//------------------------------------------------------------------
specifier|const
name|ConstString
modifier|&
name|operator
init|=
operator|(
specifier|const
name|ConstString
operator|&
name|rhs
operator|)
block|{
name|m_string
operator|=
name|rhs
operator|.
name|m_string
block|;
return|return
operator|*
name|this
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Equal to operator
comment|///
comment|/// Returns true if this string is equal to the string in \a rhs.
comment|/// This operation is very fast as it results in a pointer
comment|/// comparison since all strings are in a uniqued in a global string
comment|/// pool.
comment|///
comment|/// @param[in] rhs
comment|///     Another string object to compare this object to.
comment|///
comment|/// @return
comment|///     @li \b true if this object is equal to \a rhs.
comment|///     @li \b false if this object is not equal to \a rhs.
comment|//------------------------------------------------------------------
name|bool
name|operator
operator|==
operator|(
specifier|const
name|ConstString
operator|&
name|rhs
operator|)
specifier|const
block|{
comment|// We can do a pointer compare to compare these strings since they
comment|// must come from the same pool in order to be equal.
return|return
name|m_string
operator|==
name|rhs
operator|.
name|m_string
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Not equal to operator
comment|///
comment|/// Returns true if this string is not equal to the string in \a rhs.
comment|/// This operation is very fast as it results in a pointer
comment|/// comparison since all strings are in a uniqued in a global string
comment|/// pool.
comment|///
comment|/// @param[in] rhs
comment|///     Another string object to compare this object to.
comment|///
comment|/// @return
comment|///     @li \b true if this object is not equal to \a rhs.
comment|///     @li \b false if this object is equal to \a rhs.
comment|//------------------------------------------------------------------
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|ConstString
operator|&
name|rhs
operator|)
specifier|const
block|{
return|return
name|m_string
operator|!=
name|rhs
operator|.
name|m_string
return|;
block|}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|ConstString
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the string value as a C string.
comment|///
comment|/// Get the value of the contained string as a NULL terminated C
comment|/// string value.
comment|///
comment|/// If \a value_if_empty is nullptr, then nullptr will be returned.
comment|///
comment|/// @return
comment|///     Returns \a value_if_empty if the string is empty, otherwise
comment|///     the C string value contained in this object.
comment|//------------------------------------------------------------------
specifier|const
name|char
modifier|*
name|AsCString
argument_list|(
specifier|const
name|char
operator|*
name|value_if_empty
operator|=
name|nullptr
argument_list|)
decl|const
block|{
return|return
operator|(
name|IsEmpty
argument_list|()
condition|?
name|value_if_empty
else|:
name|m_string
operator|)
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get the string value as a llvm::StringRef
comment|///
comment|/// @return
comment|///     Returns a new llvm::StringRef object filled in with the
comment|///     needed data.
comment|//------------------------------------------------------------------
name|llvm
operator|::
name|StringRef
name|GetStringRef
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|StringRef
argument_list|(
name|m_string
argument_list|,
name|GetLength
argument_list|()
argument_list|)
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get the string value as a C string.
comment|///
comment|/// Get the value of the contained string as a NULL terminated C
comment|/// string value. Similar to the ConstString::AsCString() function,
comment|/// yet this function will always return nullptr if the string is not
comment|/// valid. So this function is a direct accessor to the string
comment|/// pointer value.
comment|///
comment|/// @return
comment|///     Returns nullptr the string is invalid, otherwise the C string
comment|///     value contained in this object.
comment|//------------------------------------------------------------------
specifier|const
name|char
operator|*
name|GetCString
argument_list|()
specifier|const
block|{
return|return
name|m_string
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get the length in bytes of string value.
comment|///
comment|/// The string pool stores the length of the string, so we can avoid
comment|/// calling strlen() on the pointer value with this function.
comment|///
comment|/// @return
comment|///     Returns the number of bytes that this string occupies in
comment|///     memory, not including the NULL termination byte.
comment|//------------------------------------------------------------------
name|size_t
name|GetLength
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Clear this object's state.
comment|///
comment|/// Clear any contained string and reset the value to the an empty
comment|/// string value.
comment|//------------------------------------------------------------------
name|void
name|Clear
parameter_list|()
block|{
name|m_string
operator|=
name|nullptr
expr_stmt|;
block|}
comment|//------------------------------------------------------------------
comment|/// Equal to operator
comment|///
comment|/// Returns true if this string is equal to the string in \a rhs.
comment|/// If case sensitive equality is tested, this operation is very
comment|/// fast as it results in a pointer comparison since all strings
comment|/// are in a uniqued in a global string pool.
comment|///
comment|/// @param[in] rhs
comment|///     The Left Hand Side const ConstString object reference.
comment|///
comment|/// @param[in] rhs
comment|///     The Right Hand Side const ConstString object reference.
comment|///
comment|/// @param[in] case_sensitive
comment|///     Case sensitivity. If true, case sensitive equality
comment|///     will be tested, otherwise character case will be ignored
comment|///
comment|/// @return
comment|///     @li \b true if this object is equal to \a rhs.
comment|///     @li \b false if this object is not equal to \a rhs.
comment|//------------------------------------------------------------------
specifier|static
name|bool
name|Equals
parameter_list|(
specifier|const
name|ConstString
modifier|&
name|lhs
parameter_list|,
specifier|const
name|ConstString
modifier|&
name|rhs
parameter_list|,
specifier|const
name|bool
name|case_sensitive
init|=
name|true
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Compare two string objects.
comment|///
comment|/// Compares the C string values contained in \a lhs and \a rhs and
comment|/// returns an integer result.
comment|///
comment|/// NOTE: only call this function when you want a true string
comment|/// comparison. If you want string equality use the, use the ==
comment|/// operator as it is much more efficient. Also if you want string
comment|/// inequality, use the != operator for the same reasons.
comment|///
comment|/// @param[in] lhs
comment|///     The Left Hand Side const ConstString object reference.
comment|///
comment|/// @param[in] rhs
comment|///     The Right Hand Side const ConstString object reference.
comment|///
comment|/// @param[in] case_sensitive
comment|///     Case sensitivity of compare. If true, case sensitive compare
comment|///     will be performed, otherwise character case will be ignored
comment|///
comment|/// @return
comment|///     @li -1 if lhs< rhs
comment|///     @li 0 if lhs == rhs
comment|///     @li 1 if lhs> rhs
comment|//------------------------------------------------------------------
specifier|static
name|int
name|Compare
parameter_list|(
specifier|const
name|ConstString
modifier|&
name|lhs
parameter_list|,
specifier|const
name|ConstString
modifier|&
name|rhs
parameter_list|,
specifier|const
name|bool
name|case_sensitive
init|=
name|true
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Dump the object description to a stream.
comment|///
comment|/// Dump the string value to the stream \a s. If the contained string
comment|/// is empty, print \a value_if_empty to the stream instead. If
comment|/// \a value_if_empty is nullptr, then nothing will be dumped to the
comment|/// stream.
comment|///
comment|/// @param[in] s
comment|///     The stream that will be used to dump the object description.
comment|///
comment|/// @param[in] value_if_empty
comment|///     The value to dump if the string is empty. If nullptr, nothing
comment|///     will be output to the stream.
comment|//------------------------------------------------------------------
name|void
name|Dump
argument_list|(
name|Stream
operator|*
name|s
argument_list|,
specifier|const
name|char
operator|*
name|value_if_empty
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Dump the object debug description to a stream.
comment|///
comment|/// @param[in] s
comment|///     The stream that will be used to dump the object description.
comment|//------------------------------------------------------------------
name|void
name|DumpDebug
argument_list|(
name|Stream
operator|*
name|s
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Test for empty string.
comment|///
comment|/// @return
comment|///     @li \b true if the contained string is empty.
comment|///     @li \b false if the contained string is not empty.
comment|//------------------------------------------------------------------
name|bool
name|IsEmpty
argument_list|()
specifier|const
block|{
return|return
name|m_string
operator|==
name|nullptr
operator|||
name|m_string
index|[
literal|0
index|]
operator|==
literal|'\0'
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Set the C string value.
comment|///
comment|/// Set the string value in the object by uniquing the \a cstr
comment|/// string value in our global string pool.
comment|///
comment|/// If the C string already exists in the global string pool, it
comment|/// finds the current entry and returns the existing value. If it
comment|/// doesn't exist, it is added to the string pool.
comment|///
comment|/// @param[in] cstr
comment|///     A NULL terminated C string to add to the string pool.
comment|//------------------------------------------------------------------
name|void
name|SetCString
parameter_list|(
specifier|const
name|char
modifier|*
name|cstr
parameter_list|)
function_decl|;
name|void
name|SetString
argument_list|(
specifier|const
name|llvm
operator|::
name|StringRef
operator|&
name|s
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Set the C string value and its mangled counterpart.
comment|///
comment|/// Object files and debug symbols often use mangled string to
comment|/// represent the linkage name for a symbol, function or global.
comment|/// The string pool can efficiently store these values and their
comment|/// counterparts so when we run into another instance of a mangled
comment|/// name, we can avoid calling the name demangler over and over on
comment|/// the same strings and then trying to unique them.
comment|///
comment|/// @param[in] demangled
comment|///     The demangled C string to correlate with the \a mangled
comment|///     name.
comment|///
comment|/// @param[in] mangled
comment|///     The already uniqued mangled ConstString to correlate the
comment|///     soon to be uniqued version of \a demangled.
comment|//------------------------------------------------------------------
name|void
name|SetCStringWithMangledCounterpart
parameter_list|(
specifier|const
name|char
modifier|*
name|demangled
parameter_list|,
specifier|const
name|ConstString
modifier|&
name|mangled
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Retrieve the mangled or demangled counterpart for a mangled
comment|/// or demangled ConstString.
comment|///
comment|/// Object files and debug symbols often use mangled string to
comment|/// represent the linkage name for a symbol, function or global.
comment|/// The string pool can efficiently store these values and their
comment|/// counterparts so when we run into another instance of a mangled
comment|/// name, we can avoid calling the name demangler over and over on
comment|/// the same strings and then trying to unique them.
comment|///
comment|/// @param[in] counterpart
comment|///     A reference to a ConstString object that might get filled in
comment|///     with the demangled/mangled counterpart.
comment|///
comment|/// @return
comment|///     /b True if \a counterpart was filled in with the counterpart
comment|///     /b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|GetMangledCounterpart
argument_list|(
name|ConstString
operator|&
name|counterpart
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Set the C string value with length.
comment|///
comment|/// Set the string value in the object by uniquing \a cstr_len bytes
comment|/// starting at the \a cstr string value in our global string pool.
comment|/// If trim is true, then \a cstr_len indicates a maximum length of
comment|/// the CString and if the actual length of the string is less, then
comment|/// it will be trimmed.
comment|///
comment|/// If the C string already exists in the global string pool, it
comment|/// finds the current entry and returns the existing value. If it
comment|/// doesn't exist, it is added to the string pool.
comment|///
comment|/// @param[in] cstr
comment|///     A NULL terminated C string to add to the string pool.
comment|///
comment|/// @param[in] cstr_len
comment|///     The maximum length of the C string.
comment|//------------------------------------------------------------------
name|void
name|SetCStringWithLength
parameter_list|(
specifier|const
name|char
modifier|*
name|cstr
parameter_list|,
name|size_t
name|cstr_len
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Set the C string value with the minimum length between
comment|/// \a fixed_cstr_len and the actual length of the C string. This
comment|/// can be used for data structures that have a fixed length to
comment|/// store a C string where the string might not be NULL terminated
comment|/// if the string takes the entire buffer.
comment|//------------------------------------------------------------------
name|void
name|SetTrimmedCStringWithLength
parameter_list|(
specifier|const
name|char
modifier|*
name|cstr
parameter_list|,
name|size_t
name|fixed_cstr_len
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get the memory cost of this object.
comment|///
comment|/// Return the size in bytes that this object takes in memory. This
comment|/// returns the size in bytes of this object, which does not include
comment|/// any the shared string values it may refer to.
comment|///
comment|/// @return
comment|///     The number of bytes that this object occupies in memory.
comment|///
comment|/// @see ConstString::StaticMemorySize ()
comment|//------------------------------------------------------------------
name|size_t
name|MemorySize
argument_list|()
specifier|const
block|{
return|return
sizeof|sizeof
argument_list|(
name|ConstString
argument_list|)
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get the size in bytes of the current global string pool.
comment|///
comment|/// Reports the size in bytes of all shared C string values,
comment|/// containers and any other values as a byte size for the
comment|/// entire string pool.
comment|///
comment|/// @return
comment|///     The number of bytes that the global string pool occupies
comment|///     in memory.
comment|//------------------------------------------------------------------
specifier|static
name|size_t
name|StaticMemorySize
parameter_list|()
function_decl|;
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// Member variables
comment|//------------------------------------------------------------------
specifier|const
name|char
modifier|*
name|m_string
decl_stmt|;
block|}
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// Stream the string value \a str to the stream \a s
comment|//------------------------------------------------------------------
name|Stream
operator|&
name|operator
operator|<<
operator|(
name|Stream
operator|&
name|s
operator|,
specifier|const
name|ConstString
operator|&
name|str
operator|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
operator|>
expr|struct
name|format_provider
operator|<
name|lldb_private
operator|::
name|ConstString
operator|>
block|{
specifier|static
name|void
name|format
argument_list|(
argument|const lldb_private::ConstString&CS
argument_list|,
argument|llvm::raw_ostream&OS
argument_list|,
argument|llvm::StringRef Options
argument_list|)
block|; }
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ConstString_h_
end_comment

end_unit

