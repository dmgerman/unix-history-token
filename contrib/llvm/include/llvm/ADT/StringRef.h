begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- StringRef.h - Constant String Reference Wrapper ----------*- C++ -*-===//
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
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/iterator_range.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
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
file|<cstddef>
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
file|<type_traits>
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
name|class
name|APInt
decl_stmt|;
name|class
name|hash_code
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
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
name|bool
name|consumeUnsignedInteger
parameter_list|(
name|StringRef
modifier|&
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
name|consumeSignedInteger
parameter_list|(
name|StringRef
modifier|&
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
name|using
name|iterator
init|=
specifier|const
name|char
operator|*
decl_stmt|;
name|using
name|const_iterator
init|=
specifier|const
name|char
operator|*
decl_stmt|;
name|using
name|size_type
init|=
name|size_t
decl_stmt|;
name|private
label|:
comment|/// The start of the string, in an external buffer.
specifier|const
name|char
modifier|*
name|Data
init|=
name|nullptr
decl_stmt|;
comment|/// The length of the string.
name|size_t
name|Length
init|=
literal|0
decl_stmt|;
comment|// Workaround memcmp issue with null pointers (undefined behavior)
comment|// by providing a specialized version
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
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
operator|=
expr|default
expr_stmt|;
comment|/// Disable conversion from nullptr.  This prevents things like
comment|/// if (S == nullptr)
name|StringRef
argument_list|(
name|std
operator|::
name|nullptr_t
argument_list|)
operator|=
name|delete
expr_stmt|;
comment|/// Construct a string ref from a cstring.
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
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
name|Str
argument_list|)
operator|,
name|Length
argument_list|(
argument|Str ? ::strlen(Str) :
literal|0
argument_list|)
block|{}
comment|/// Construct a string ref from a pointer and length.
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
comment|/*implicit*/
name|constexpr
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
block|{}
comment|/// Construct a string ref from an std::string.
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
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
specifier|static
name|StringRef
name|withNullAsEmpty
argument_list|(
argument|const char *data
argument_list|)
block|{
return|return
name|StringRef
argument_list|(
name|data
operator|?
name|data
operator|:
literal|""
argument_list|)
return|;
block|}
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
specifier|const
name|unsigned
name|char
operator|*
name|bytes_begin
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
specifier|const
name|unsigned
name|char
operator|*
operator|>
operator|(
name|begin
argument_list|()
operator|)
return|;
block|}
specifier|const
name|unsigned
name|char
operator|*
name|bytes_end
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
specifier|const
name|unsigned
name|char
operator|*
operator|>
operator|(
name|end
argument_list|()
operator|)
return|;
block|}
name|iterator_range
operator|<
specifier|const
name|unsigned
name|char
operator|*
operator|>
name|bytes
argument_list|()
specifier|const
block|{
return|return
name|make_range
argument_list|(
name|bytes_begin
argument_list|()
argument_list|,
name|bytes_end
argument_list|()
argument_list|)
return|;
block|}
comment|/// @}
comment|/// @name String Operations
comment|/// @{
comment|/// data - Get a pointer to the start of the string (which may not be null
comment|/// terminated).
name|LLVM_NODISCARD
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
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
name|LLVM_NODISCARD
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
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
name|LLVM_NODISCARD
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
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
name|LLVM_NODISCARD
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
name|LLVM_NODISCARD
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
comment|// copy - Allocate copy in Allocator and return StringRef to it.
name|template
operator|<
name|typename
name|Allocator
operator|>
name|LLVM_NODISCARD
name|StringRef
name|copy
argument_list|(
argument|Allocator&A
argument_list|)
specifier|const
block|{
comment|// Don't request a length 0 copy from the allocator.
if|if
condition|(
name|empty
argument_list|()
condition|)
return|return
name|StringRef
argument_list|()
return|;
name|char
operator|*
name|S
operator|=
name|A
operator|.
name|template
name|Allocate
operator|<
name|char
operator|>
operator|(
name|Length
operator|)
expr_stmt|;
name|std
operator|::
name|copy
argument_list|(
name|begin
argument_list|()
argument_list|,
name|end
argument_list|()
argument_list|,
name|S
argument_list|)
expr_stmt|;
return|return
name|StringRef
argument_list|(
name|S
argument_list|,
name|Length
argument_list|)
return|;
block|}
comment|/// equals - Check for string equality, this is more efficient than
comment|/// compare() when the relative ordering of inequal strings isn't needed.
name|LLVM_NODISCARD
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
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
name|LLVM_NODISCARD
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
name|LLVM_NODISCARD
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
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
name|std
operator|::
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
name|LLVM_NODISCARD
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
name|LLVM_NODISCARD
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
name|LLVM_NODISCARD
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
name|LLVM_NODISCARD
name|std
operator|::
name|string
name|str
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|Data
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
end_decl_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Operator Overloads
end_comment

begin_comment
comment|/// @{
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
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
end_decl_stmt

begin_comment
comment|/// Disallow accidental assignment from a temporary std::string.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The declaration here is extra complicated so that `stringRef = {}`
end_comment

begin_comment
comment|/// and `stringRef = "abc"` continue to select the move assignment operator.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|typename
name|std
operator|::
name|enable_if
operator|<
name|std
operator|::
name|is_same
operator|<
name|T
operator|,
name|std
operator|::
name|string
operator|>
operator|::
name|value
operator|,
name|StringRef
operator|>
operator|::
name|type
operator|&
name|operator
operator|=
operator|(
name|T
operator|&&
name|Str
operator|)
operator|=
name|delete
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Type Conversions
end_comment

begin_comment
comment|/// @{
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name String Predicates
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// Check if this string starts with the given \p Prefix.
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
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
end_decl_stmt

begin_comment
comment|/// Check if this string starts with the given \p Prefix, ignoring case.
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
name|bool
name|startswith_lower
argument_list|(
name|StringRef
name|Prefix
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Check if this string ends with the given \p Suffix.
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
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
end_decl_stmt

begin_comment
comment|/// Check if this string ends with the given \p Suffix, ignoring case.
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
name|bool
name|endswith_lower
argument_list|(
name|StringRef
name|Suffix
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name String Searching
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// Search for the first character \p C in the string.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns The index of the first occurrence of \p C, or npos if not
end_comment

begin_comment
comment|/// found.
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
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
name|size_t
name|FindBegin
init|=
name|std
operator|::
name|min
argument_list|(
name|From
argument_list|,
name|Length
argument_list|)
decl_stmt|;
if|if
condition|(
name|FindBegin
operator|<
name|Length
condition|)
block|{
comment|// Avoid calling memchr with nullptr.
comment|// Just forward to memchr, which is faster than a hand-rolled loop.
if|if
condition|(
specifier|const
name|void
modifier|*
name|P
init|=
operator|::
name|memchr
argument_list|(
name|Data
operator|+
name|FindBegin
argument_list|,
name|C
argument_list|,
name|Length
operator|-
name|FindBegin
argument_list|)
condition|)
return|return
name|static_cast
operator|<
specifier|const
name|char
operator|*
operator|>
operator|(
name|P
operator|)
operator|-
name|Data
return|;
block|}
return|return
name|npos
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Search for the first character \p C in the string, ignoring case.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns The index of the first occurrence of \p C, or npos if not
end_comment

begin_comment
comment|/// found.
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
name|size_t
name|find_lower
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
end_decl_stmt

begin_comment
comment|/// Search for the first character satisfying the predicate \p F
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns The index of the first character satisfying \p F starting from
end_comment

begin_comment
comment|/// \p From, or npos if not found.
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
name|size_t
name|find_if
argument_list|(
name|function_ref
operator|<
name|bool
argument_list|(
name|char
argument_list|)
operator|>
name|F
argument_list|,
name|size_t
name|From
operator|=
literal|0
argument_list|)
decl|const
block|{
name|StringRef
name|S
init|=
name|drop_front
argument_list|(
name|From
argument_list|)
decl_stmt|;
while|while
condition|(
operator|!
name|S
operator|.
name|empty
argument_list|()
condition|)
block|{
if|if
condition|(
name|F
argument_list|(
name|S
operator|.
name|front
argument_list|()
argument_list|)
condition|)
return|return
name|size
argument_list|()
operator|-
name|S
operator|.
name|size
argument_list|()
return|;
name|S
operator|=
name|S
operator|.
name|drop_front
argument_list|()
expr_stmt|;
block|}
return|return
name|npos
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Search for the first character not satisfying the predicate \p F
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns The index of the first character not satisfying \p F starting
end_comment

begin_comment
comment|/// from \p From, or npos if not found.
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
name|size_t
name|find_if_not
argument_list|(
name|function_ref
operator|<
name|bool
argument_list|(
name|char
argument_list|)
operator|>
name|F
argument_list|,
name|size_t
name|From
operator|=
literal|0
argument_list|)
decl|const
block|{
return|return
name|find_if
argument_list|(
index|[
name|F
index|]
operator|(
name|char
name|c
operator|)
block|{
return|return
operator|!
name|F
argument_list|(
name|c
argument_list|)
return|;
block|}
operator|,
name|From
block|)
decl_stmt|;
end_decl_stmt

begin_comment
unit|}
comment|/// Search for the first string \p Str in the string.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns The index of the first occurrence of \p Str, or npos if not
end_comment

begin_comment
comment|/// found.
end_comment

begin_decl_stmt
unit|LLVM_NODISCARD
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
end_decl_stmt

begin_comment
comment|/// Search for the first string \p Str in the string, ignoring case.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns The index of the first occurrence of \p Str, or npos if not
end_comment

begin_comment
comment|/// found.
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
name|size_t
name|find_lower
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
end_decl_stmt

begin_comment
comment|/// Search for the last character \p C in the string.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns The index of the last occurrence of \p C, or npos if not
end_comment

begin_comment
comment|/// found.
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
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
name|std
operator|::
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
end_decl_stmt

begin_comment
comment|/// Search for the last character \p C in the string, ignoring case.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns The index of the last occurrence of \p C, or npos if not
end_comment

begin_comment
comment|/// found.
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
name|size_t
name|rfind_lower
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
end_decl_stmt

begin_comment
comment|/// Search for the last string \p Str in the string.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns The index of the last occurrence of \p Str, or npos if not
end_comment

begin_comment
comment|/// found.
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
name|size_t
name|rfind
argument_list|(
name|StringRef
name|Str
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Search for the last string \p Str in the string, ignoring case.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns The index of the last occurrence of \p Str, or npos if not
end_comment

begin_comment
comment|/// found.
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
name|size_t
name|rfind_lower
argument_list|(
name|StringRef
name|Str
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Find the first character in the string that is \p C, or npos if not
end_comment

begin_comment
comment|/// found. Same as find.
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
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
end_decl_stmt

begin_comment
comment|/// Find the first character in the string that is in \p Chars, or npos if
end_comment

begin_comment
comment|/// not found.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Complexity: O(size() + Chars.size())
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
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
end_decl_stmt

begin_comment
comment|/// Find the first character in the string that is not \p C or npos if not
end_comment

begin_comment
comment|/// found.
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
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
end_decl_stmt

begin_comment
comment|/// Find the first character in the string that is not in the string
end_comment

begin_comment
comment|/// \p Chars, or npos if not found.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Complexity: O(size() + Chars.size())
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
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
end_decl_stmt

begin_comment
comment|/// Find the last character in the string that is \p C, or npos if not
end_comment

begin_comment
comment|/// found.
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
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
end_decl_stmt

begin_comment
comment|/// Find the last character in the string that is in \p C, or npos if not
end_comment

begin_comment
comment|/// found.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Complexity: O(size() + Chars.size())
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
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
end_decl_stmt

begin_comment
comment|/// Find the last character in the string that is not \p C, or npos if not
end_comment

begin_comment
comment|/// found.
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
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
end_decl_stmt

begin_comment
comment|/// Find the last character in the string that is not in \p Chars, or
end_comment

begin_comment
comment|/// npos if not found.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Complexity: O(size() + Chars.size())
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
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
end_decl_stmt

begin_comment
comment|/// Return true if the given string is a substring of *this, and false
end_comment

begin_comment
comment|/// otherwise.
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
name|bool
name|contains
argument_list|(
name|StringRef
name|Other
argument_list|)
decl|const
block|{
return|return
name|find
argument_list|(
name|Other
argument_list|)
operator|!=
name|npos
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Return true if the given character is contained in *this, and false
end_comment

begin_comment
comment|/// otherwise.
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
name|bool
name|contains
argument_list|(
name|char
name|C
argument_list|)
decl|const
block|{
return|return
name|find_first_of
argument_list|(
name|C
argument_list|)
operator|!=
name|npos
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Return true if the given string is a substring of *this, and false
end_comment

begin_comment
comment|/// otherwise.
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
name|bool
name|contains_lower
argument_list|(
name|StringRef
name|Other
argument_list|)
decl|const
block|{
return|return
name|find_lower
argument_list|(
name|Other
argument_list|)
operator|!=
name|npos
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Return true if the given character is contained in *this, and false
end_comment

begin_comment
comment|/// otherwise.
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
name|bool
name|contains_lower
argument_list|(
name|char
name|C
argument_list|)
decl|const
block|{
return|return
name|find_lower
argument_list|(
name|C
argument_list|)
operator|!=
name|npos
return|;
block|}
end_decl_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Helpful Algorithms
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// Return the number of occurrences of \p C in the string.
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
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
end_decl_stmt

begin_comment
comment|/// Return the number of non-overlapped occurrences of \p Str in
end_comment

begin_comment
comment|/// the string.
end_comment

begin_decl_stmt
name|size_t
name|count
argument_list|(
name|StringRef
name|Str
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Parse the current string as an integer of the specified radix.  If
end_comment

begin_comment
comment|/// \p Radix is specified as zero, this does radix autosensing using
end_comment

begin_comment
comment|/// extended C rules: 0 is octal, 0x is hex, 0b is binary.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If the string is invalid or if only a subset of the string is valid,
end_comment

begin_comment
comment|/// this returns true to signify the error.  The string is considered
end_comment

begin_comment
comment|/// erroneous if empty or if it overflows T.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|typename
name|std
operator|::
name|enable_if
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
end_expr_stmt

begin_return
return|return
name|false
return|;
end_return

begin_expr_stmt
unit|}      template
operator|<
name|typename
name|T
operator|>
name|typename
name|std
operator|::
name|enable_if
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
comment|// The additional cast to unsigned long long is required to avoid the
comment|// Visual C++ warning C4805: '!=' : unsafe mix of type 'bool' and type
comment|// 'unsigned __int64' when instantiating getAsInteger with T = bool.
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
name|unsigned
name|long
name|long
operator|>
operator|(
name|static_cast
operator|<
name|T
operator|>
operator|(
name|ULLVal
operator|)
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
comment|/// Parse the current string as an integer of the specified radix.  If
end_comment

begin_comment
comment|/// \p Radix is specified as zero, this does radix autosensing using
end_comment

begin_comment
comment|/// extended C rules: 0 is octal, 0x is hex, 0b is binary.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If the string does not begin with a number of the specified radix,
end_comment

begin_comment
comment|/// this returns true to signify the error. The string is considered
end_comment

begin_comment
comment|/// erroneous if empty or if it overflows T.
end_comment

begin_comment
comment|/// The portion of the string representing the discovered numeric value
end_comment

begin_comment
comment|/// is removed from the beginning of the string.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|T
operator|>
name|typename
name|std
operator|::
name|enable_if
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
name|consumeInteger
argument_list|(
argument|unsigned Radix
argument_list|,
argument|T&Result
argument_list|)
block|{
name|long
name|long
name|LLVal
block|;
if|if
condition|(
name|consumeSignedInteger
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
name|long
name|long
operator|>
operator|(
name|static_cast
operator|<
name|T
operator|>
operator|(
name|LLVal
operator|)
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
end_expr_stmt

begin_return
return|return
name|false
return|;
end_return

begin_expr_stmt
unit|}      template
operator|<
name|typename
name|T
operator|>
name|typename
name|std
operator|::
name|enable_if
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
name|consumeInteger
argument_list|(
argument|unsigned Radix
argument_list|,
argument|T&Result
argument_list|)
block|{
name|unsigned
name|long
name|long
name|ULLVal
block|;
if|if
condition|(
name|consumeUnsignedInteger
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
name|unsigned
name|long
name|long
operator|>
operator|(
name|static_cast
operator|<
name|T
operator|>
operator|(
name|ULLVal
operator|)
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
comment|/// Parse the current string as an IEEE double-precision floating
end_comment

begin_comment
comment|/// point value.  The string must be a well-formed double.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If \p AllowInexact is false, the function will fail if the string
end_comment

begin_comment
comment|/// cannot be represented exactly.  Otherwise, the function only fails
end_comment

begin_comment
comment|/// in case of an overflow or underflow.
end_comment

begin_decl_stmt
name|bool
name|getAsDouble
argument_list|(
name|double
operator|&
name|Result
argument_list|,
name|bool
name|AllowInexact
operator|=
name|true
argument_list|)
decl|const
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
name|LLVM_NODISCARD
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
name|LLVM_NODISCARD
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
name|LLVM_NODISCARD
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
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
name|std
operator|::
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
name|std
operator|::
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
comment|/// Return a StringRef equal to 'this' but with only the first \p N
end_comment

begin_comment
comment|/// elements remaining.  If \p N is greater than the length of the
end_comment

begin_comment
comment|/// string, the entire string is returned.
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
name|StringRef
name|take_front
argument_list|(
name|size_t
name|N
operator|=
literal|1
argument_list|)
decl|const
block|{
if|if
condition|(
name|N
operator|>=
name|size
argument_list|()
condition|)
return|return
operator|*
name|this
return|;
return|return
name|drop_back
argument_list|(
name|size
argument_list|()
operator|-
name|N
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Return a StringRef equal to 'this' but with only the last \p N
end_comment

begin_comment
comment|/// elements remaining.  If \p N is greater than the length of the
end_comment

begin_comment
comment|/// string, the entire string is returned.
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
name|StringRef
name|take_back
argument_list|(
name|size_t
name|N
operator|=
literal|1
argument_list|)
decl|const
block|{
if|if
condition|(
name|N
operator|>=
name|size
argument_list|()
condition|)
return|return
operator|*
name|this
return|;
return|return
name|drop_front
argument_list|(
name|size
argument_list|()
operator|-
name|N
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Return the longest prefix of 'this' such that every character
end_comment

begin_comment
comment|/// in the prefix satisfies the given predicate.
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
name|StringRef
name|take_while
argument_list|(
name|function_ref
operator|<
name|bool
argument_list|(
name|char
argument_list|)
operator|>
name|F
argument_list|)
decl|const
block|{
return|return
name|substr
argument_list|(
literal|0
argument_list|,
name|find_if_not
argument_list|(
name|F
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Return the longest prefix of 'this' such that no character in
end_comment

begin_comment
comment|/// the prefix satisfies the given predicate.
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
name|StringRef
name|take_until
argument_list|(
name|function_ref
operator|<
name|bool
argument_list|(
name|char
argument_list|)
operator|>
name|F
argument_list|)
decl|const
block|{
return|return
name|substr
argument_list|(
literal|0
argument_list|,
name|find_if
argument_list|(
name|F
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
name|LLVM_NODISCARD
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
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
name|LLVM_NODISCARD
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
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
comment|/// Return a StringRef equal to 'this', but with all characters satisfying
end_comment

begin_comment
comment|/// the given predicate dropped from the beginning of the string.
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
name|StringRef
name|drop_while
argument_list|(
name|function_ref
operator|<
name|bool
argument_list|(
name|char
argument_list|)
operator|>
name|F
argument_list|)
decl|const
block|{
return|return
name|substr
argument_list|(
name|find_if_not
argument_list|(
name|F
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Return a StringRef equal to 'this', but with all characters not
end_comment

begin_comment
comment|/// satisfying the given predicate dropped from the beginning of the string.
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
name|StringRef
name|drop_until
argument_list|(
name|function_ref
operator|<
name|bool
argument_list|(
name|char
argument_list|)
operator|>
name|F
argument_list|)
decl|const
block|{
return|return
name|substr
argument_list|(
name|find_if
argument_list|(
name|F
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Returns true if this StringRef has the given prefix and removes that
end_comment

begin_comment
comment|/// prefix.
end_comment

begin_function
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
name|bool
name|consume_front
parameter_list|(
name|StringRef
name|Prefix
parameter_list|)
block|{
if|if
condition|(
operator|!
name|startswith
argument_list|(
name|Prefix
argument_list|)
condition|)
return|return
name|false
return|;
operator|*
name|this
operator|=
name|drop_front
argument_list|(
name|Prefix
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
end_function

begin_comment
comment|/// Returns true if this StringRef has the given suffix and removes that
end_comment

begin_comment
comment|/// suffix.
end_comment

begin_function
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
name|bool
name|consume_back
parameter_list|(
name|StringRef
name|Suffix
parameter_list|)
block|{
if|if
condition|(
operator|!
name|endswith
argument_list|(
name|Suffix
argument_list|)
condition|)
return|return
name|false
return|;
operator|*
name|this
operator|=
name|drop_back
argument_list|(
name|Suffix
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
end_function

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
comment|/// substring. If this is npos or exceeds the number of characters
end_comment

begin_comment
comment|/// remaining in the string, the string suffix (starting with \p Start)
end_comment

begin_comment
comment|/// will be returned. If this is less than \p Start, an empty string will
end_comment

begin_comment
comment|/// be returned.
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
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
name|std
operator|::
name|min
argument_list|(
name|Start
argument_list|,
name|Length
argument_list|)
expr_stmt|;
name|End
operator|=
name|std
operator|::
name|min
argument_list|(
name|std
operator|::
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
name|LLVM_NODISCARD
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
unit|LLVM_NODISCARD
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
comment|/// \p MaxSplit splits are done and consequently<= \p MaxSplit + 1
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
comment|/// Split into substrings around the occurrences of a separator character.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Each substring is stored in \p A. If \p MaxSplit is>= 0, at most
end_comment

begin_comment
comment|/// \p MaxSplit splits are done and consequently<= \p MaxSplit + 1
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

begin_decl_stmt
name|void
name|split
argument_list|(
name|SmallVectorImpl
operator|<
name|StringRef
operator|>
operator|&
name|A
argument_list|,
name|char
name|Separator
argument_list|,
name|int
name|MaxSplit
operator|=
operator|-
literal|1
argument_list|,
name|bool
name|KeepEmpty
operator|=
name|true
argument_list|)
decl|const
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
name|LLVM_NODISCARD
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
comment|/// Return string with consecutive \p Char characters starting from the
end_comment

begin_comment
comment|/// the left removed.
end_comment

begin_decl_stmt
unit|LLVM_NODISCARD
name|StringRef
name|ltrim
argument_list|(
name|char
name|Char
argument_list|)
decl|const
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
name|Char
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Return string with consecutive characters in \p Chars starting from
end_comment

begin_comment
comment|/// the left removed.
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
name|StringRef
name|ltrim
argument_list|(
name|StringRef
name|Chars
operator|=
literal|" \t\n\v\f\r"
argument_list|)
decl|const
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
end_decl_stmt

begin_comment
comment|/// Return string with consecutive \p Char characters starting from the
end_comment

begin_comment
comment|/// right removed.
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
name|StringRef
name|rtrim
argument_list|(
name|char
name|Char
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
name|Char
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
comment|/// the right removed.
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
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
comment|/// Return string with consecutive \p Char characters starting from the
end_comment

begin_comment
comment|/// left and right removed.
end_comment

begin_decl_stmt
name|LLVM_NODISCARD
name|StringRef
name|trim
argument_list|(
name|char
name|Char
argument_list|)
decl|const
block|{
return|return
name|ltrim
argument_list|(
name|Char
argument_list|)
operator|.
name|rtrim
argument_list|(
name|Char
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
name|LLVM_NODISCARD
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
comment|/// A wrapper around a string literal that serves as a proxy for constructing
end_comment

begin_comment
comment|/// global tables of StringRefs with the length computed at compile time.
end_comment

begin_comment
comment|/// In order to avoid the invocation of a global constructor, StringLiteral
end_comment

begin_comment
comment|/// should *only* be used in a constexpr context, as such:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// constexpr StringLiteral S("test");
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|StringLiteral
range|:
name|public
name|StringRef
block|{
name|public
operator|:
name|template
operator|<
name|size_t
name|N
operator|>
name|constexpr
name|StringLiteral
argument_list|(
argument|const char (&Str)[N]
argument_list|)
if|#
directive|if
name|defined
argument_list|(
name|__clang__
argument_list|)
operator|&&
name|__has_attribute
argument_list|(
name|enable_if
argument_list|)
pragma|#
directive|pragma
name|clang
name|diagnostic
name|push
pragma|#
directive|pragma
name|clang
name|diagnostic
name|ignored
literal|"-Wgcc-compat"
name|__attribute
argument_list|(
operator|(
name|enable_if
argument_list|(
name|__builtin_strlen
argument_list|(
name|Str
argument_list|)
operator|==
name|N
operator|-
literal|1
argument_list|,
literal|"invalid string literal"
argument_list|)
operator|)
argument_list|)
pragma|#
directive|pragma
name|clang
name|diagnostic
name|pop
endif|#
directive|endif
operator|:
name|StringRef
argument_list|(
argument|Str
argument_list|,
argument|N -
literal|1
argument_list|)
block|{     }
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// @name StringRef Comparison Operators
end_comment

begin_comment
comment|/// @{
end_comment

begin_expr_stmt
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
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
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
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
name|LLVM_NODISCARD
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
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_ADT_STRINGREF_H
end_comment

end_unit

