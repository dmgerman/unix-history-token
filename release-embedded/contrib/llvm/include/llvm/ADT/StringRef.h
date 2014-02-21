begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- StringRef.h - Constant String Reference Wrapper --------*- C++ -*-===//
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
name|LLVM_ADT_STRINGREF_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_STRINGREF_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/type_traits.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstring>
end_include

begin_include
include|#
directive|include
file|<limits>
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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
name|class
name|APInt
decl_stmt|;
name|class
name|hash_code
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
comment|/// Helper functions for StringRef::getAsInteger.
name|bool
name|getAsUnsignedInteger
parameter_list|(
name|StringRef
name|Str
parameter_list|,
name|unsigned
name|Radix
parameter_list|,
name|unsigned
name|long
name|long
modifier|&
name|Result
parameter_list|)
function_decl|;
name|bool
name|getAsSignedInteger
parameter_list|(
name|StringRef
name|Str
parameter_list|,
name|unsigned
name|Radix
parameter_list|,
name|long
name|long
modifier|&
name|Result
parameter_list|)
function_decl|;
comment|/// StringRef - Represent a constant reference to a string, i.e. a character
comment|/// array and a length, which need not be null terminated.
comment|///
comment|/// This class does not own the string data, it is expected to be used in
comment|/// situations where the character data resides in some other buffer, whose
comment|/// lifetime extends past that of the StringRef. For this reason, it is not in
comment|/// general safe to store a StringRef.
name|class
name|StringRef
block|{
name|public
label|:
typedef|typedef
specifier|const
name|char
modifier|*
name|iterator
typedef|;
typedef|typedef
specifier|const
name|char
modifier|*
name|const_iterator
typedef|;
specifier|static
specifier|const
name|size_t
name|npos
init|=
operator|~
name|size_t
argument_list|(
literal|0
argument_list|)
decl_stmt|;
typedef|typedef
name|size_t
name|size_type
typedef|;
name|private
label|:
comment|/// The start of the string, in an external buffer.
specifier|const
name|char
modifier|*
name|Data
decl_stmt|;
comment|/// The length of the string.
name|size_t
name|Length
decl_stmt|;
comment|// Workaround PR5482: nearly all gcc 4.x miscompile StringRef and std::min()
comment|// Changing the arg of min to be an integer, instead of a reference to an
comment|// integer works around this bug.
specifier|static
name|size_t
name|min
parameter_list|(
name|size_t
name|a
parameter_list|,
name|size_t
name|b
parameter_list|)
block|{
return|return
name|a
operator|<
name|b
condition|?
name|a
else|:
name|b
return|;
block|}
specifier|static
name|size_t
name|max
parameter_list|(
name|size_t
name|a
parameter_list|,
name|size_t
name|b
parameter_list|)
block|{
return|return
name|a
operator|>
name|b
condition|?
name|a
else|:
name|b
return|;
block|}
comment|// Workaround memcmp issue with null pointers (undefined behavior)
comment|// by providing a specialized version
specifier|static
name|int
name|compareMemory
parameter_list|(
specifier|const
name|char
modifier|*
name|Lhs
parameter_list|,
specifier|const
name|char
modifier|*
name|Rhs
parameter_list|,
name|size_t
name|Length
parameter_list|)
block|{
if|if
condition|(
name|Length
operator|==
literal|0
condition|)
block|{
return|return
literal|0
return|;
block|}
return|return
operator|::
name|memcmp
argument_list|(
name|Lhs
argument_list|,
name|Rhs
argument_list|,
name|Length
argument_list|)
return|;
block|}
name|public
label|:
comment|/// @name Constructors
comment|/// @{
comment|/// Construct an empty string ref.
comment|/*implicit*/
name|StringRef
argument_list|()
operator|:
name|Data
argument_list|(
literal|0
argument_list|)
operator|,
name|Length
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// Construct a string ref from a cstring.
comment|/*implicit*/
name|StringRef
argument_list|(
specifier|const
name|char
operator|*
name|Str
argument_list|)
operator|:
name|Data
argument_list|(
argument|Str
argument_list|)
block|{
name|assert
argument_list|(
name|Str
operator|&&
literal|"StringRef cannot be built from a NULL argument"
argument_list|)
block|;
name|Length
operator|=
operator|::
name|strlen
argument_list|(
name|Str
argument_list|)
block|;
comment|// invoking strlen(NULL) is undefined behavior
block|}
comment|/// Construct a string ref from a pointer and length.
comment|/*implicit*/
name|StringRef
argument_list|(
argument|const char *data
argument_list|,
argument|size_t length
argument_list|)
operator|:
name|Data
argument_list|(
name|data
argument_list|)
operator|,
name|Length
argument_list|(
argument|length
argument_list|)
block|{
name|assert
argument_list|(
operator|(
name|data
operator|||
name|length
operator|==
literal|0
operator|)
operator|&&
literal|"StringRef cannot be built from a NULL argument with non-null length"
argument_list|)
block|;       }
comment|/// Construct a string ref from an std::string.
comment|/*implicit*/
name|StringRef
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Str
argument_list|)
operator|:
name|Data
argument_list|(
name|Str
operator|.
name|data
argument_list|()
argument_list|)
operator|,
name|Length
argument_list|(
argument|Str.length()
argument_list|)
block|{}
comment|/// @}
comment|/// @name Iterators
comment|/// @{
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|Data
return|;
block|}
name|iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|Data
operator|+
name|Length
return|;
block|}
comment|/// @}
comment|/// @name String Operations
comment|/// @{
comment|/// data - Get a pointer to the start of the string (which may not be null
comment|/// terminated).
specifier|const
name|char
operator|*
name|data
argument_list|()
specifier|const
block|{
return|return
name|Data
return|;
block|}
comment|/// empty - Check if the string is empty.
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|Length
operator|==
literal|0
return|;
block|}
comment|/// size - Get the string size.
name|size_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|Length
return|;
block|}
comment|/// front - Get the first character in the string.
name|char
name|front
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|empty
argument_list|()
argument_list|)
block|;
return|return
name|Data
index|[
literal|0
index|]
return|;
block|}
comment|/// back - Get the last character in the string.
name|char
name|back
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|empty
argument_list|()
argument_list|)
block|;
return|return
name|Data
index|[
name|Length
operator|-
literal|1
index|]
return|;
block|}
comment|/// equals - Check for string equality, this is more efficient than
comment|/// compare() when the relative ordering of inequal strings isn't needed.
name|bool
name|equals
argument_list|(
name|StringRef
name|RHS
argument_list|)
decl|const
block|{
return|return
operator|(
name|Length
operator|==
name|RHS
operator|.
name|Length
operator|&&
name|compareMemory
argument_list|(
name|Data
argument_list|,
name|RHS
operator|.
name|Data
argument_list|,
name|RHS
operator|.
name|Length
argument_list|)
operator|==
literal|0
operator|)
return|;
block|}
comment|/// equals_lower - Check for string equality, ignoring case.
name|bool
name|equals_lower
argument_list|(
name|StringRef
name|RHS
argument_list|)
decl|const
block|{
return|return
name|Length
operator|==
name|RHS
operator|.
name|Length
operator|&&
name|compare_lower
argument_list|(
name|RHS
argument_list|)
operator|==
literal|0
return|;
block|}
comment|/// compare - Compare two strings; the result is -1, 0, or 1 if this string
comment|/// is lexicographically less than, equal to, or greater than the \p RHS.
name|int
name|compare
argument_list|(
name|StringRef
name|RHS
argument_list|)
decl|const
block|{
comment|// Check the prefix for a mismatch.
if|if
condition|(
name|int
name|Res
init|=
name|compareMemory
argument_list|(
name|Data
argument_list|,
name|RHS
operator|.
name|Data
argument_list|,
name|min
argument_list|(
name|Length
argument_list|,
name|RHS
operator|.
name|Length
argument_list|)
argument_list|)
condition|)
return|return
name|Res
operator|<
literal|0
condition|?
operator|-
literal|1
else|:
literal|1
return|;
comment|// Otherwise the prefixes match, so we only need to check the lengths.
if|if
condition|(
name|Length
operator|==
name|RHS
operator|.
name|Length
condition|)
return|return
literal|0
return|;
return|return
name|Length
operator|<
name|RHS
operator|.
name|Length
condition|?
operator|-
literal|1
else|:
literal|1
return|;
block|}
comment|/// compare_lower - Compare two strings, ignoring case.
name|int
name|compare_lower
argument_list|(
name|StringRef
name|RHS
argument_list|)
decl|const
decl_stmt|;
comment|/// compare_numeric - Compare two strings, treating sequences of digits as
comment|/// numbers.
name|int
name|compare_numeric
argument_list|(
name|StringRef
name|RHS
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Determine the edit distance between this string and another
comment|/// string.
comment|///
comment|/// \param Other the string to compare this string against.
comment|///
comment|/// \param AllowReplacements whether to allow character
comment|/// replacements (change one character into another) as a single
comment|/// operation, rather than as two operations (an insertion and a
comment|/// removal).
comment|///
comment|/// \param MaxEditDistance If non-zero, the maximum edit distance that
comment|/// this routine is allowed to compute. If the edit distance will exceed
comment|/// that maximum, returns \c MaxEditDistance+1.
comment|///
comment|/// \returns the minimum number of character insertions, removals,
comment|/// or (if \p AllowReplacements is \c true) replacements needed to
comment|/// transform one of the given strings into the other. If zero,
comment|/// the strings are identical.
name|unsigned
name|edit_distance
argument_list|(
name|StringRef
name|Other
argument_list|,
name|bool
name|AllowReplacements
operator|=
name|true
argument_list|,
name|unsigned
name|MaxEditDistance
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// str - Get the contents as an std::string.
name|std
operator|::
name|string
name|str
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Data
operator|==
literal|0
condition|)
return|return
name|std
operator|::
name|string
argument_list|()
return|;
return|return
name|std
operator|::
name|string
argument_list|(
name|Data
argument_list|,
name|Length
argument_list|)
return|;
block|}
comment|/// @}
comment|/// @name Operator Overloads
comment|/// @{
name|char
name|operator
index|[]
argument_list|(
name|size_t
name|Index
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|Index
operator|<
name|Length
operator|&&
literal|"Invalid index!"
argument_list|)
expr_stmt|;
return|return
name|Data
index|[
name|Index
index|]
return|;
block|}
comment|/// @}
comment|/// @name Type Conversions
comment|/// @{
name|operator
name|std
operator|::
name|string
argument_list|()
specifier|const
block|{
return|return
name|str
argument_list|()
return|;
block|}
comment|/// @}
comment|/// @name String Predicates
comment|/// @{
comment|/// Check if this string starts with the given \p Prefix.
name|bool
name|startswith
argument_list|(
name|StringRef
name|Prefix
argument_list|)
decl|const
block|{
return|return
name|Length
operator|>=
name|Prefix
operator|.
name|Length
operator|&&
name|compareMemory
argument_list|(
name|Data
argument_list|,
name|Prefix
operator|.
name|Data
argument_list|,
name|Prefix
operator|.
name|Length
argument_list|)
operator|==
literal|0
return|;
block|}
comment|/// Check if this string starts with the given \p Prefix, ignoring case.
name|bool
name|startswith_lower
argument_list|(
name|StringRef
name|Prefix
argument_list|)
decl|const
decl_stmt|;
comment|/// Check if this string ends with the given \p Suffix.
name|bool
name|endswith
argument_list|(
name|StringRef
name|Suffix
argument_list|)
decl|const
block|{
return|return
name|Length
operator|>=
name|Suffix
operator|.
name|Length
operator|&&
name|compareMemory
argument_list|(
name|end
argument_list|()
operator|-
name|Suffix
operator|.
name|Length
argument_list|,
name|Suffix
operator|.
name|Data
argument_list|,
name|Suffix
operator|.
name|Length
argument_list|)
operator|==
literal|0
return|;
block|}
comment|/// Check if this string ends with the given \p Suffix, ignoring case.
name|bool
name|endswith_lower
argument_list|(
name|StringRef
name|Suffix
argument_list|)
decl|const
decl_stmt|;
comment|/// @}
comment|/// @name String Searching
comment|/// @{
comment|/// Search for the first character \p C in the string.
comment|///
comment|/// \returns The index of the first occurrence of \p C, or npos if not
comment|/// found.
name|size_t
name|find
argument_list|(
name|char
name|C
argument_list|,
name|size_t
name|From
operator|=
literal|0
argument_list|)
decl|const
block|{
for|for
control|(
name|size_t
name|i
init|=
name|min
argument_list|(
name|From
argument_list|,
name|Length
argument_list|)
init|,
name|e
init|=
name|Length
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|Data
index|[
name|i
index|]
operator|==
name|C
condition|)
return|return
name|i
return|;
return|return
name|npos
return|;
block|}
comment|/// Search for the first string \p Str in the string.
comment|///
comment|/// \returns The index of the first occurrence of \p Str, or npos if not
comment|/// found.
name|size_t
name|find
argument_list|(
name|StringRef
name|Str
argument_list|,
name|size_t
name|From
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// Search for the last character \p C in the string.
comment|///
comment|/// \returns The index of the last occurrence of \p C, or npos if not
comment|/// found.
name|size_t
name|rfind
argument_list|(
name|char
name|C
argument_list|,
name|size_t
name|From
operator|=
name|npos
argument_list|)
decl|const
block|{
name|From
operator|=
name|min
argument_list|(
name|From
argument_list|,
name|Length
argument_list|)
expr_stmt|;
name|size_t
name|i
init|=
name|From
decl_stmt|;
while|while
condition|(
name|i
operator|!=
literal|0
condition|)
block|{
operator|--
name|i
expr_stmt|;
if|if
condition|(
name|Data
index|[
name|i
index|]
operator|==
name|C
condition|)
return|return
name|i
return|;
block|}
return|return
name|npos
return|;
block|}
comment|/// Search for the last string \p Str in the string.
comment|///
comment|/// \returns The index of the last occurrence of \p Str, or npos if not
comment|/// found.
name|size_t
name|rfind
argument_list|(
name|StringRef
name|Str
argument_list|)
decl|const
decl_stmt|;
comment|/// Find the first character in the string that is \p C, or npos if not
comment|/// found. Same as find.
name|size_t
name|find_first_of
argument_list|(
name|char
name|C
argument_list|,
name|size_t
name|From
operator|=
literal|0
argument_list|)
decl|const
block|{
return|return
name|find
argument_list|(
name|C
argument_list|,
name|From
argument_list|)
return|;
block|}
comment|/// Find the first character in the string that is in \p Chars, or npos if
comment|/// not found.
comment|///
comment|/// Complexity: O(size() + Chars.size())
name|size_t
name|find_first_of
argument_list|(
name|StringRef
name|Chars
argument_list|,
name|size_t
name|From
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// Find the first character in the string that is not \p C or npos if not
comment|/// found.
name|size_t
name|find_first_not_of
argument_list|(
name|char
name|C
argument_list|,
name|size_t
name|From
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// Find the first character in the string that is not in the string
comment|/// \p Chars, or npos if not found.
comment|///
comment|/// Complexity: O(size() + Chars.size())
name|size_t
name|find_first_not_of
argument_list|(
name|StringRef
name|Chars
argument_list|,
name|size_t
name|From
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// Find the last character in the string that is \p C, or npos if not
comment|/// found.
name|size_t
name|find_last_of
argument_list|(
name|char
name|C
argument_list|,
name|size_t
name|From
operator|=
name|npos
argument_list|)
decl|const
block|{
return|return
name|rfind
argument_list|(
name|C
argument_list|,
name|From
argument_list|)
return|;
block|}
comment|/// Find the last character in the string that is in \p C, or npos if not
comment|/// found.
comment|///
comment|/// Complexity: O(size() + Chars.size())
name|size_t
name|find_last_of
argument_list|(
name|StringRef
name|Chars
argument_list|,
name|size_t
name|From
operator|=
name|npos
argument_list|)
decl|const
decl_stmt|;
comment|/// Find the last character in the string that is not \p C, or npos if not
comment|/// found.
name|size_t
name|find_last_not_of
argument_list|(
name|char
name|C
argument_list|,
name|size_t
name|From
operator|=
name|npos
argument_list|)
decl|const
decl_stmt|;
comment|/// Find the last character in the string that is not in \p Chars, or
comment|/// npos if not found.
comment|///
comment|/// Complexity: O(size() + Chars.size())
name|size_t
name|find_last_not_of
argument_list|(
name|StringRef
name|Chars
argument_list|,
name|size_t
name|From
operator|=
name|npos
argument_list|)
decl|const
decl_stmt|;
comment|/// @}
comment|/// @name Helpful Algorithms
comment|/// @{
comment|/// Return the number of occurrences of \p C in the string.
name|size_t
name|count
argument_list|(
name|char
name|C
argument_list|)
decl|const
block|{
name|size_t
name|Count
init|=
literal|0
decl_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|,
name|e
init|=
name|Length
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|Data
index|[
name|i
index|]
operator|==
name|C
condition|)
operator|++
name|Count
expr_stmt|;
return|return
name|Count
return|;
block|}
comment|/// Return the number of non-overlapped occurrences of \p Str in
comment|/// the string.
name|size_t
name|count
argument_list|(
name|StringRef
name|Str
argument_list|)
decl|const
decl_stmt|;
comment|/// Parse the current string as an integer of the specified radix.  If
comment|/// \p Radix is specified as zero, this does radix autosensing using
comment|/// extended C rules: 0 is octal, 0x is hex, 0b is binary.
comment|///
comment|/// If the string is invalid or if only a subset of the string is valid,
comment|/// this returns true to signify the error.  The string is considered
comment|/// erroneous if empty or if it overflows T.
name|template
operator|<
name|typename
name|T
operator|>
name|typename
name|enable_if_c
operator|<
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|is_signed
operator|,
name|bool
operator|>
operator|::
name|type
name|getAsInteger
argument_list|(
argument|unsigned Radix
argument_list|,
argument|T&Result
argument_list|)
specifier|const
block|{
name|long
name|long
name|LLVal
block|;
if|if
condition|(
name|getAsSignedInteger
argument_list|(
operator|*
name|this
argument_list|,
name|Radix
argument_list|,
name|LLVal
argument_list|)
operator|||
name|static_cast
operator|<
name|T
operator|>
operator|(
name|LLVal
operator|)
operator|!=
name|LLVal
condition|)
return|return
name|true
return|;
name|Result
operator|=
name|LLVal
expr_stmt|;
return|return
name|false
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|typename
name|enable_if_c
operator|<
operator|!
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|is_signed
operator|,
name|bool
operator|>
operator|::
name|type
name|getAsInteger
argument_list|(
argument|unsigned Radix
argument_list|,
argument|T&Result
argument_list|)
specifier|const
block|{
name|unsigned
name|long
name|long
name|ULLVal
block|;
if|if
condition|(
name|getAsUnsignedInteger
argument_list|(
operator|*
name|this
argument_list|,
name|Radix
argument_list|,
name|ULLVal
argument_list|)
operator|||
name|static_cast
operator|<
name|T
operator|>
operator|(
name|ULLVal
operator|)
operator|!=
name|ULLVal
condition|)
return|return
name|true
return|;
name|Result
operator|=
name|ULLVal
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|false
return|;
end_return

begin_comment
unit|}
comment|/// Parse the current string as an integer of the specified \p Radix, or of
end_comment

begin_comment
comment|/// an autosensed radix if the \p Radix given is 0.  The current value in
end_comment

begin_comment
comment|/// \p Result is discarded, and the storage is changed to be wide enough to
end_comment

begin_comment
comment|/// store the parsed integer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if the string does not solely consist of a valid
end_comment

begin_comment
comment|/// non-empty number in the appropriate base.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// APInt::fromString is superficially similar but assumes the
end_comment

begin_comment
comment|/// string is well-formed in the given radix.
end_comment

begin_macro
unit|bool
name|getAsInteger
argument_list|(
argument|unsigned Radix
argument_list|,
argument|APInt&Result
argument_list|)
end_macro

begin_decl_stmt
specifier|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name String Operations
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|// Convert the given ASCII string to lowercase.
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|lower
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Convert the given ASCII string to uppercase.
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|upper
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Substring Operations
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// Return a reference to the substring from [Start, Start + N).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Start The index of the starting character in the substring; if
end_comment

begin_comment
comment|/// the index is npos or greater than the length of the string then the
end_comment

begin_comment
comment|/// empty substring will be returned.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param N The number of characters to included in the substring. If N
end_comment

begin_comment
comment|/// exceeds the number of characters remaining in the string, the string
end_comment

begin_comment
comment|/// suffix (starting with \p Start) will be returned.
end_comment

begin_decl_stmt
name|StringRef
name|substr
argument_list|(
name|size_t
name|Start
argument_list|,
name|size_t
name|N
operator|=
name|npos
argument_list|)
decl|const
block|{
name|Start
operator|=
name|min
argument_list|(
name|Start
argument_list|,
name|Length
argument_list|)
expr_stmt|;
return|return
name|StringRef
argument_list|(
name|Data
operator|+
name|Start
argument_list|,
name|min
argument_list|(
name|N
argument_list|,
name|Length
operator|-
name|Start
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Return a StringRef equal to 'this' but with the first \p N elements
end_comment

begin_comment
comment|/// dropped.
end_comment

begin_decl_stmt
name|StringRef
name|drop_front
argument_list|(
name|size_t
name|N
operator|=
literal|1
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|size
argument_list|()
operator|>=
name|N
operator|&&
literal|"Dropping more elements than exist"
argument_list|)
expr_stmt|;
return|return
name|substr
argument_list|(
name|N
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Return a StringRef equal to 'this' but with the last \p N elements
end_comment

begin_comment
comment|/// dropped.
end_comment

begin_decl_stmt
name|StringRef
name|drop_back
argument_list|(
name|size_t
name|N
operator|=
literal|1
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|size
argument_list|()
operator|>=
name|N
operator|&&
literal|"Dropping more elements than exist"
argument_list|)
expr_stmt|;
return|return
name|substr
argument_list|(
literal|0
argument_list|,
name|size
argument_list|()
operator|-
name|N
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Return a reference to the substring from [Start, End).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Start The index of the starting character in the substring; if
end_comment

begin_comment
comment|/// the index is npos or greater than the length of the string then the
end_comment

begin_comment
comment|/// empty substring will be returned.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param End The index following the last character to include in the
end_comment

begin_comment
comment|/// substring. If this is npos, or less than \p Start, or exceeds the
end_comment

begin_comment
comment|/// number of characters remaining in the string, the string suffix
end_comment

begin_comment
comment|/// (starting with \p Start) will be returned.
end_comment

begin_decl_stmt
name|StringRef
name|slice
argument_list|(
name|size_t
name|Start
argument_list|,
name|size_t
name|End
argument_list|)
decl|const
block|{
name|Start
operator|=
name|min
argument_list|(
name|Start
argument_list|,
name|Length
argument_list|)
expr_stmt|;
name|End
operator|=
name|min
argument_list|(
name|max
argument_list|(
name|Start
argument_list|,
name|End
argument_list|)
argument_list|,
name|Length
argument_list|)
expr_stmt|;
return|return
name|StringRef
argument_list|(
name|Data
operator|+
name|Start
argument_list|,
name|End
operator|-
name|Start
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Split into two substrings around the first occurrence of a separator
end_comment

begin_comment
comment|/// character.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If \p Separator is in the string, then the result is a pair (LHS, RHS)
end_comment

begin_comment
comment|/// such that (*this == LHS + Separator + RHS) is true and RHS is
end_comment

begin_comment
comment|/// maximal. If \p Separator is not in the string, then the result is a
end_comment

begin_comment
comment|/// pair (LHS, RHS) where (*this == LHS) and (RHS == "").
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Separator The character to split on.
end_comment

begin_comment
comment|/// \returns The split substrings.
end_comment

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|StringRef
operator|,
name|StringRef
operator|>
name|split
argument_list|(
argument|char Separator
argument_list|)
specifier|const
block|{
name|size_t
name|Idx
operator|=
name|find
argument_list|(
name|Separator
argument_list|)
block|;
if|if
condition|(
name|Idx
operator|==
name|npos
condition|)
return|return
name|std
operator|::
name|make_pair
argument_list|(
operator|*
name|this
argument_list|,
name|StringRef
argument_list|()
argument_list|)
return|;
end_expr_stmt

begin_return
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|slice
argument_list|(
literal|0
argument_list|,
name|Idx
argument_list|)
argument_list|,
name|slice
argument_list|(
name|Idx
operator|+
literal|1
argument_list|,
name|npos
argument_list|)
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/// Split into two substrings around the first occurrence of a separator
end_comment

begin_comment
comment|/// string.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If \p Separator is in the string, then the result is a pair (LHS, RHS)
end_comment

begin_comment
comment|/// such that (*this == LHS + Separator + RHS) is true and RHS is
end_comment

begin_comment
comment|/// maximal. If \p Separator is not in the string, then the result is a
end_comment

begin_comment
comment|/// pair (LHS, RHS) where (*this == LHS) and (RHS == "").
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Separator - The string to split on.
end_comment

begin_comment
comment|/// \return - The split substrings.
end_comment

begin_expr_stmt
unit|std
operator|::
name|pair
operator|<
name|StringRef
operator|,
name|StringRef
operator|>
name|split
argument_list|(
argument|StringRef Separator
argument_list|)
specifier|const
block|{
name|size_t
name|Idx
operator|=
name|find
argument_list|(
name|Separator
argument_list|)
block|;
if|if
condition|(
name|Idx
operator|==
name|npos
condition|)
return|return
name|std
operator|::
name|make_pair
argument_list|(
operator|*
name|this
argument_list|,
name|StringRef
argument_list|()
argument_list|)
return|;
end_expr_stmt

begin_return
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|slice
argument_list|(
literal|0
argument_list|,
name|Idx
argument_list|)
argument_list|,
name|slice
argument_list|(
name|Idx
operator|+
name|Separator
operator|.
name|size
argument_list|()
argument_list|,
name|npos
argument_list|)
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/// Split into substrings around the occurrences of a separator string.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Each substring is stored in \p A. If \p MaxSplit is>= 0, at most
end_comment

begin_comment
comment|/// \p MaxSplit splits are done and consequently<= \p MaxSplit
end_comment

begin_comment
comment|/// elements are added to A.
end_comment

begin_comment
comment|/// If \p KeepEmpty is false, empty strings are not added to \p A. They
end_comment

begin_comment
comment|/// still count when considering \p MaxSplit
end_comment

begin_comment
comment|/// An useful invariant is that
end_comment

begin_comment
comment|/// Separator.join(A) == *this if MaxSplit == -1 and KeepEmpty == true
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param A - Where to put the substrings.
end_comment

begin_comment
comment|/// \param Separator - The string to split on.
end_comment

begin_comment
comment|/// \param MaxSplit - The maximum number of times the string is split.
end_comment

begin_comment
comment|/// \param KeepEmpty - True if empty substring should be added.
end_comment

begin_macro
unit|void
name|split
argument_list|(
argument|SmallVectorImpl<StringRef>&A
argument_list|,
argument|StringRef Separator
argument_list|,
argument|int MaxSplit = -
literal|1
argument_list|,
argument|bool KeepEmpty = true
argument_list|)
end_macro

begin_decl_stmt
specifier|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Split into two substrings around the last occurrence of a separator
end_comment

begin_comment
comment|/// character.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If \p Separator is in the string, then the result is a pair (LHS, RHS)
end_comment

begin_comment
comment|/// such that (*this == LHS + Separator + RHS) is true and RHS is
end_comment

begin_comment
comment|/// minimal. If \p Separator is not in the string, then the result is a
end_comment

begin_comment
comment|/// pair (LHS, RHS) where (*this == LHS) and (RHS == "").
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Separator - The character to split on.
end_comment

begin_comment
comment|/// \return - The split substrings.
end_comment

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|StringRef
operator|,
name|StringRef
operator|>
name|rsplit
argument_list|(
argument|char Separator
argument_list|)
specifier|const
block|{
name|size_t
name|Idx
operator|=
name|rfind
argument_list|(
name|Separator
argument_list|)
block|;
if|if
condition|(
name|Idx
operator|==
name|npos
condition|)
return|return
name|std
operator|::
name|make_pair
argument_list|(
operator|*
name|this
argument_list|,
name|StringRef
argument_list|()
argument_list|)
return|;
end_expr_stmt

begin_return
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|slice
argument_list|(
literal|0
argument_list|,
name|Idx
argument_list|)
argument_list|,
name|slice
argument_list|(
name|Idx
operator|+
literal|1
argument_list|,
name|npos
argument_list|)
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/// Return string with consecutive characters in \p Chars starting from
end_comment

begin_comment
comment|/// the left removed.
end_comment

begin_macro
unit|StringRef
name|ltrim
argument_list|(
argument|StringRef Chars =
literal|" \t\n\v\f\r"
argument_list|)
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|drop_front
argument_list|(
name|std
operator|::
name|min
argument_list|(
name|Length
argument_list|,
name|find_first_not_of
argument_list|(
name|Chars
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Return string with consecutive characters in \p Chars starting from
end_comment

begin_comment
comment|/// the right removed.
end_comment

begin_decl_stmt
name|StringRef
name|rtrim
argument_list|(
name|StringRef
name|Chars
operator|=
literal|" \t\n\v\f\r"
argument_list|)
decl|const
block|{
return|return
name|drop_back
argument_list|(
name|Length
operator|-
name|std
operator|::
name|min
argument_list|(
name|Length
argument_list|,
name|find_last_not_of
argument_list|(
name|Chars
argument_list|)
operator|+
literal|1
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Return string with consecutive characters in \p Chars starting from
end_comment

begin_comment
comment|/// the left and right removed.
end_comment

begin_decl_stmt
name|StringRef
name|trim
argument_list|(
name|StringRef
name|Chars
operator|=
literal|" \t\n\v\f\r"
argument_list|)
decl|const
block|{
return|return
name|ltrim
argument_list|(
name|Chars
argument_list|)
operator|.
name|rtrim
argument_list|(
name|Chars
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
unit|};
comment|/// @name StringRef Comparison Operators
end_comment

begin_comment
comment|/// @{
end_comment

begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|==
operator|(
name|StringRef
name|LHS
operator|,
name|StringRef
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|equals
argument_list|(
name|RHS
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|!=
operator|(
name|StringRef
name|LHS
operator|,
name|StringRef
name|RHS
operator|)
block|{
return|return
operator|!
operator|(
name|LHS
operator|==
name|RHS
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|<
operator|(
name|StringRef
name|LHS
operator|,
name|StringRef
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|compare
argument_list|(
name|RHS
argument_list|)
operator|==
operator|-
literal|1
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|<=
operator|(
name|StringRef
name|LHS
operator|,
name|StringRef
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|compare
argument_list|(
name|RHS
argument_list|)
operator|!=
literal|1
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|>
operator|(
name|StringRef
name|LHS
operator|,
name|StringRef
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|compare
argument_list|(
name|RHS
argument_list|)
operator|==
literal|1
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|>=
operator|(
name|StringRef
name|LHS
operator|,
name|StringRef
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|compare
argument_list|(
name|RHS
argument_list|)
operator|!=
operator|-
literal|1
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|std
operator|::
name|string
operator|&
name|operator
operator|+=
operator|(
name|std
operator|::
name|string
operator|&
name|buffer
operator|,
name|StringRef
name|string
operator|)
block|{
return|return
name|buffer
operator|.
name|append
argument_list|(
name|string
operator|.
name|data
argument_list|()
argument_list|,
name|string
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// \brief Compute a hash_code for a StringRef.
end_comment

begin_function_decl
name|hash_code
name|hash_value
parameter_list|(
name|StringRef
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// StringRefs can be treated like a POD type.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|isPodLike
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|isPodLike
operator|<
name|StringRef
operator|>
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
name|true
block|; }
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Construct a string ref from a boolean.
end_comment

begin_function
specifier|inline
name|StringRef
name|toStringRef
parameter_list|(
name|bool
name|B
parameter_list|)
block|{
return|return
name|StringRef
argument_list|(
name|B
condition|?
literal|"true"
else|:
literal|"false"
argument_list|)
return|;
block|}
end_function

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

