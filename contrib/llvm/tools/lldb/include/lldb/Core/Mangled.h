begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Mangled.h -----------------------------------------------*- C++ -*-===//
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
name|liblldb_Mangled_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Mangled_h_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_comment
comment|// for LanguageType
end_comment

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_comment
comment|// for StringRef
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
name|RegularExpression
decl_stmt|;
block|}
end_decl_stmt

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
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class Mangled Mangled.h "lldb/Core/Mangled.h"
comment|/// @brief A class that handles mangled names.
comment|///
comment|/// Designed to handle mangled names. The demangled version of any names
comment|/// will be computed when the demangled name is accessed through the
comment|/// Demangled() acccessor. This class can also tokenize the demangled
comment|/// version of the name for powerful searches. Functions and symbols
comment|/// could make instances of this class for their mangled names. Uniqued
comment|/// string pools are used for the mangled, demangled, and token string
comment|/// values to allow for faster comparisons and for efficient memory use.
comment|//----------------------------------------------------------------------
name|class
name|Mangled
block|{
name|public
label|:
enum|enum
name|NamePreference
block|{
name|ePreferMangled
block|,
name|ePreferDemangled
block|,
name|ePreferDemangledWithoutArguments
block|}
enum|;
enum|enum
name|ManglingScheme
block|{
name|eManglingSchemeNone
init|=
literal|0
block|,
name|eManglingSchemeMSVC
block|,
name|eManglingSchemeItanium
block|}
enum|;
comment|//----------------------------------------------------------------------
comment|/// Default constructor.
comment|///
comment|/// Initialize with both mangled and demangled names empty.
comment|//----------------------------------------------------------------------
name|Mangled
argument_list|()
expr_stmt|;
comment|//----------------------------------------------------------------------
comment|/// Construct with name.
comment|///
comment|/// Constructor with an optional string and a boolean indicating if it is
comment|/// the mangled version.
comment|///
comment|/// @param[in] name
comment|///     The already const name to copy into this object.
comment|///
comment|/// @param[in] is_mangled
comment|///     If \b true then \a name is a mangled name, if \b false then
comment|///     \a name is demangled.
comment|//----------------------------------------------------------------------
name|Mangled
argument_list|(
argument|const ConstString&name
argument_list|,
argument|bool is_mangled
argument_list|)
empty_stmt|;
name|Mangled
argument_list|(
argument|llvm::StringRef name
argument_list|,
argument|bool is_mangled
argument_list|)
empty_stmt|;
comment|//----------------------------------------------------------------------
comment|/// Construct with name.
comment|///
comment|/// Constructor with an optional string and auto-detect if \a name is
comment|/// mangled or not.
comment|///
comment|/// @param[in] name
comment|///     The already const name to copy into this object.
comment|//----------------------------------------------------------------------
name|explicit
name|Mangled
parameter_list|(
specifier|const
name|ConstString
modifier|&
name|name
parameter_list|)
function_decl|;
name|explicit
name|Mangled
argument_list|(
name|llvm
operator|::
name|StringRef
name|name
argument_list|)
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|/// Destructor
comment|///
comment|/// Releases its ref counts on the mangled and demangled strings that
comment|/// live in the global string pool.
comment|//----------------------------------------------------------------------
operator|~
name|Mangled
argument_list|()
expr_stmt|;
comment|//----------------------------------------------------------------------
comment|/// Convert to pointer operator.
comment|///
comment|/// This allows code to check a Mangled object to see if it contains
comment|/// a valid mangled name using code such as:
comment|///
comment|/// @code
comment|/// Mangled mangled(...);
comment|/// if (mangled)
comment|/// { ...
comment|/// @endcode
comment|///
comment|/// @return
comment|///     A pointer to this object if either the mangled or unmangled
comment|///     name is set, NULL otherwise.
comment|//----------------------------------------------------------------------
name|operator
name|void
operator|*
operator|(
operator|)
specifier|const
expr_stmt|;
comment|//----------------------------------------------------------------------
comment|/// Logical NOT operator.
comment|///
comment|/// This allows code to check a Mangled object to see if it contains
comment|/// an empty mangled name using code such as:
comment|///
comment|/// @code
comment|/// Mangled mangled(...);
comment|/// if (!mangled)
comment|/// { ...
comment|/// @endcode
comment|///
comment|/// @return
comment|///     Returns \b true if the object has an empty mangled and
comment|///     unmangled name, \b false otherwise.
comment|//----------------------------------------------------------------------
name|bool
name|operator
operator|!
operator|(
operator|)
specifier|const
expr_stmt|;
comment|//----------------------------------------------------------------------
comment|/// Clear the mangled and demangled values.
comment|//----------------------------------------------------------------------
name|void
name|Clear
parameter_list|()
function_decl|;
comment|//----------------------------------------------------------------------
comment|/// Compare the mangled string values
comment|///
comment|/// Compares the Mangled::GetName() string in \a lhs and \a rhs.
comment|///
comment|/// @param[in] lhs
comment|///     A const reference to the Left Hand Side object to compare.
comment|///
comment|/// @param[in] rhs
comment|///     A const reference to the Right Hand Side object to compare.
comment|///
comment|/// @return
comment|///     @li -1 if \a lhs is less than \a rhs
comment|///     @li 0 if \a lhs is equal to \a rhs
comment|///     @li 1 if \a lhs is greater than \a rhs
comment|//----------------------------------------------------------------------
specifier|static
name|int
name|Compare
parameter_list|(
specifier|const
name|Mangled
modifier|&
name|lhs
parameter_list|,
specifier|const
name|Mangled
modifier|&
name|rhs
parameter_list|)
function_decl|;
comment|//----------------------------------------------------------------------
comment|/// Dump a description of this object to a Stream \a s.
comment|///
comment|/// Dump a Mangled object to stream \a s. We don't force our
comment|/// demangled name to be computed currently (we don't use the accessor).
comment|///
comment|/// @param[in] s
comment|///     The stream to which to dump the object description.
comment|//----------------------------------------------------------------------
name|void
name|Dump
argument_list|(
name|Stream
operator|*
name|s
argument_list|)
decl|const
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|/// Dump a debug description of this object to a Stream \a s.
comment|///
comment|/// @param[in] s
comment|///     The stream to which to dump the object description.
comment|//----------------------------------------------------------------------
name|void
name|DumpDebug
argument_list|(
name|Stream
operator|*
name|s
argument_list|)
decl|const
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|/// Demangled name get accessor.
comment|///
comment|/// @return
comment|///     A const reference to the demangled name string object.
comment|//----------------------------------------------------------------------
specifier|const
name|ConstString
modifier|&
name|GetDemangledName
argument_list|(
name|lldb
operator|::
name|LanguageType
name|language
argument_list|)
decl|const
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|/// Display demangled name get accessor.
comment|///
comment|/// @return
comment|///     A const reference to the display demangled name string object.
comment|//----------------------------------------------------------------------
name|ConstString
name|GetDisplayDemangledName
argument_list|(
name|lldb
operator|::
name|LanguageType
name|language
argument_list|)
decl|const
decl_stmt|;
name|void
name|SetDemangledName
parameter_list|(
specifier|const
name|ConstString
modifier|&
name|name
parameter_list|)
block|{
name|m_demangled
operator|=
name|name
expr_stmt|;
block|}
name|void
name|SetMangledName
parameter_list|(
specifier|const
name|ConstString
modifier|&
name|name
parameter_list|)
block|{
name|m_mangled
operator|=
name|name
expr_stmt|;
block|}
comment|//----------------------------------------------------------------------
comment|/// Mangled name get accessor.
comment|///
comment|/// @return
comment|///     A reference to the mangled name string object.
comment|//----------------------------------------------------------------------
name|ConstString
modifier|&
name|GetMangledName
parameter_list|()
block|{
return|return
name|m_mangled
return|;
block|}
comment|//----------------------------------------------------------------------
comment|/// Mangled name get accessor.
comment|///
comment|/// @return
comment|///     A const reference to the mangled name string object.
comment|//----------------------------------------------------------------------
specifier|const
name|ConstString
operator|&
name|GetMangledName
argument_list|()
specifier|const
block|{
return|return
name|m_mangled
return|;
block|}
comment|//----------------------------------------------------------------------
comment|/// Best name get accessor.
comment|///
comment|/// @param[in] preference
comment|///     Which name would you prefer to get?
comment|///
comment|/// @return
comment|///     A const reference to the preferred name string object if this
comment|///     object has a valid name of that kind, else a const reference to the
comment|///     other name is returned.
comment|//----------------------------------------------------------------------
name|ConstString
name|GetName
argument_list|(
name|lldb
operator|::
name|LanguageType
name|language
argument_list|,
name|NamePreference
name|preference
operator|=
name|ePreferDemangled
argument_list|)
decl|const
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|/// Check if "name" matches either the mangled or demangled name.
comment|///
comment|/// @param[in] name
comment|///     A name to match against both strings.
comment|///
comment|/// @return
comment|///     \b True if \a name matches either name, \b false otherwise.
comment|//----------------------------------------------------------------------
name|bool
name|NameMatches
argument_list|(
specifier|const
name|ConstString
operator|&
name|name
argument_list|,
name|lldb
operator|::
name|LanguageType
name|language
argument_list|)
decl|const
block|{
if|if
condition|(
name|m_mangled
operator|==
name|name
condition|)
return|return
name|true
return|;
return|return
name|GetDemangledName
argument_list|(
name|language
argument_list|)
operator|==
name|name
return|;
block|}
name|bool
name|NameMatches
argument_list|(
specifier|const
name|RegularExpression
operator|&
name|regex
argument_list|,
name|lldb
operator|::
name|LanguageType
name|language
argument_list|)
decl|const
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|/// Get the memory cost of this object.
comment|///
comment|/// Return the size in bytes that this object takes in memory. This
comment|/// returns the size in bytes of this object, not any shared string
comment|/// values it may refer to.
comment|///
comment|/// @return
comment|///     The number of bytes that this object occupies in memory.
comment|///
comment|/// @see ConstString::StaticMemorySize ()
comment|//----------------------------------------------------------------------
name|size_t
name|MemorySize
argument_list|()
specifier|const
expr_stmt|;
comment|//----------------------------------------------------------------------
comment|/// Set the string value in this object.
comment|///
comment|/// If \a is_mangled is \b true, then the mangled named is set to \a
comment|/// name, else the demangled name is set to \a name.
comment|///
comment|/// @param[in] name
comment|///     The already const version of the name for this object.
comment|///
comment|/// @param[in] is_mangled
comment|///     If \b true then \a name is a mangled name, if \b false then
comment|///     \a name is demangled.
comment|//----------------------------------------------------------------------
name|void
name|SetValue
parameter_list|(
specifier|const
name|ConstString
modifier|&
name|name
parameter_list|,
name|bool
name|is_mangled
parameter_list|)
function_decl|;
comment|//----------------------------------------------------------------------
comment|/// Set the string value in this object.
comment|///
comment|/// This version auto detects if the string is mangled by inspecting the
comment|/// string value and looking for common mangling prefixes.
comment|///
comment|/// @param[in] name
comment|///     The already const version of the name for this object.
comment|//----------------------------------------------------------------------
name|void
name|SetValue
parameter_list|(
specifier|const
name|ConstString
modifier|&
name|name
parameter_list|)
function_decl|;
comment|//----------------------------------------------------------------------
comment|/// Try to guess the language from the mangling.
comment|///
comment|/// For a mangled name to have a language it must have both a mangled
comment|/// and a demangled name and it can be guessed from the mangling what
comment|/// the language is.  Note: this will return C++ for any language that
comment|/// uses Itanium ABI mangling.
comment|///
comment|/// Standard C function names will return eLanguageTypeUnknown because
comment|/// they aren't mangled and it isn't clear what language the name
comment|/// represents (there will be no mangled name).
comment|///
comment|/// @return
comment|///     The language for the mangled/demangled name, eLanguageTypeUnknown
comment|///     if there is no mangled or demangled counterpart.
comment|//----------------------------------------------------------------------
name|lldb
operator|::
name|LanguageType
name|GuessLanguage
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
comment|//----------------------------------------------------------------------
comment|/// Mangled member variables.
comment|//----------------------------------------------------------------------
name|ConstString
name|m_mangled
decl_stmt|;
comment|///< The mangled version of the name
name|mutable
name|ConstString
name|m_demangled
decl_stmt|;
comment|///< Mutable so we can get it on demand with
comment|///a const version of this object
block|}
empty_stmt|;
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
name|Mangled
operator|&
name|obj
operator|)
expr_stmt|;
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
comment|// #if defined(__cplusplus)
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_Mangled_h_
end_comment

end_unit

