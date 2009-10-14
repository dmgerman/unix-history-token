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
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
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
if|if
condition|(
name|Str
condition|)
name|Length
operator|=
operator|::
name|strlen
argument_list|(
name|Str
argument_list|)
expr_stmt|;
else|else
name|Length
operator|=
literal|0
expr_stmt|;
block|}
comment|/// Construct a string ref from a pointer and length.
comment|/*implicit*/
name|StringRef
argument_list|(
argument|const char *data
argument_list|,
argument|unsigned length
argument_list|)
block|:
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
name|c_str
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
specifier|const
name|StringRef
operator|&
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
name|memcmp
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
comment|/// compare - Compare two strings; the result is -1, 0, or 1 if this string
comment|/// is lexicographically less than, equal to, or greater than the \arg RHS.
name|int
name|compare
argument_list|(
specifier|const
name|StringRef
operator|&
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
name|memcmp
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
comment|/// str - Get the contents as an std::string.
name|std
operator|::
name|string
name|str
argument_list|()
specifier|const
block|{
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
comment|/// startswith - Check if this string starts with the given \arg Prefix.
name|bool
name|startswith
argument_list|(
specifier|const
name|StringRef
operator|&
name|Prefix
argument_list|)
decl|const
block|{
return|return
name|substr
argument_list|(
literal|0
argument_list|,
name|Prefix
operator|.
name|Length
argument_list|)
operator|.
name|equals
argument_list|(
name|Prefix
argument_list|)
return|;
block|}
comment|/// endswith - Check if this string ends with the given \arg Suffix.
name|bool
name|endswith
argument_list|(
specifier|const
name|StringRef
operator|&
name|Suffix
argument_list|)
decl|const
block|{
return|return
name|slice
argument_list|(
name|size
argument_list|()
operator|-
name|Suffix
operator|.
name|Length
argument_list|,
name|size
argument_list|()
argument_list|)
operator|.
name|equals
argument_list|(
name|Suffix
argument_list|)
return|;
block|}
comment|/// @}
comment|/// @name String Searching
comment|/// @{
comment|/// find - Search for the first character \arg C in the string.
comment|///
comment|/// \return - The index of the first occurence of \arg C, or npos if not
comment|/// found.
name|size_t
name|find
argument_list|(
name|char
name|C
argument_list|)
decl|const
block|{
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
return|return
name|i
return|;
return|return
name|npos
return|;
block|}
comment|/// find - Search for the first string \arg Str in the string.
comment|///
comment|/// \return - The index of the first occurence of \arg Str, or npos if not
comment|/// found.
name|size_t
name|find
argument_list|(
specifier|const
name|StringRef
operator|&
name|Str
argument_list|)
decl|const
decl_stmt|;
comment|/// rfind - Search for the last character \arg C in the string.
comment|///
comment|/// \return - The index of the last occurence of \arg C, or npos if not
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
comment|/// rfind - Search for the last string \arg Str in the string.
comment|///
comment|/// \return - The index of the last occurence of \arg Str, or npos if not
comment|/// found.
name|size_t
name|rfind
argument_list|(
specifier|const
name|StringRef
operator|&
name|Str
argument_list|)
decl|const
decl_stmt|;
comment|/// find_first_of - Find the first instance of the specified character or
comment|/// return npos if not in string.  Same as find.
name|size_type
name|find_first_of
argument_list|(
name|char
name|C
argument_list|)
decl|const
block|{
return|return
name|find
argument_list|(
name|C
argument_list|)
return|;
block|}
comment|/// find_first_of - Find the first character from the string 'Chars' in the
comment|/// current string or return npos if not in string.
name|size_type
name|find_first_of
argument_list|(
name|StringRef
name|Chars
argument_list|)
decl|const
decl_stmt|;
comment|/// find_first_not_of - Find the first character in the string that is not
comment|/// in the string 'Chars' or return npos if all are in string. Same as find.
name|size_type
name|find_first_not_of
argument_list|(
name|StringRef
name|Chars
argument_list|)
decl|const
decl_stmt|;
comment|/// @}
comment|/// @name Helpful Algorithms
comment|/// @{
comment|/// count - Return the number of occurrences of \arg C in the string.
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
comment|/// count - Return the number of non-overlapped occurrences of \arg Str in
comment|/// the string.
name|size_t
name|count
argument_list|(
specifier|const
name|StringRef
operator|&
name|Str
argument_list|)
decl|const
decl_stmt|;
comment|/// getAsInteger - Parse the current string as an integer of the specified
comment|/// radix.  If Radix is specified as zero, this does radix autosensing using
comment|/// extended C rules: 0 is octal, 0x is hex, 0b is binary.
comment|///
comment|/// If the string is invalid or if only a subset of the string is valid,
comment|/// this returns true to signify the error.  The string is considered
comment|/// erroneous if empty.
comment|///
name|bool
name|getAsInteger
argument_list|(
name|unsigned
name|Radix
argument_list|,
name|long
name|long
operator|&
name|Result
argument_list|)
decl|const
decl_stmt|;
name|bool
name|getAsInteger
argument_list|(
name|unsigned
name|Radix
argument_list|,
name|unsigned
name|long
name|long
operator|&
name|Result
argument_list|)
decl|const
decl_stmt|;
name|bool
name|getAsInteger
argument_list|(
name|unsigned
name|Radix
argument_list|,
name|int
operator|&
name|Result
argument_list|)
decl|const
decl_stmt|;
name|bool
name|getAsInteger
argument_list|(
name|unsigned
name|Radix
argument_list|,
name|unsigned
operator|&
name|Result
argument_list|)
decl|const
decl_stmt|;
comment|// TODO: Provide overloads for int/unsigned that check for overflow.
comment|/// @}
comment|/// @name Substring Operations
comment|/// @{
comment|/// substr - Return a reference to the substring from [Start, Start + N).
comment|///
comment|/// \param Start - The index of the starting character in the substring; if
comment|/// the index is npos or greater than the length of the string then the
comment|/// empty substring will be returned.
comment|///
comment|/// \param N - The number of characters to included in the substring. If N
comment|/// exceeds the number of characters remaining in the string, the string
comment|/// suffix (starting with \arg Start) will be returned.
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
comment|/// slice - Return a reference to the substring from [Start, End).
comment|///
comment|/// \param Start - The index of the starting character in the substring; if
comment|/// the index is npos or greater than the length of the string then the
comment|/// empty substring will be returned.
comment|///
comment|/// \param End - The index following the last character to include in the
comment|/// substring. If this is npos, or less than \arg Start, or exceeds the
comment|/// number of characters remaining in the string, the string suffix
comment|/// (starting with \arg Start) will be returned.
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
comment|/// split - Split into two substrings around the first occurence of a
comment|/// separator character.
comment|///
comment|/// If \arg Separator is in the string, then the result is a pair (LHS, RHS)
comment|/// such that (*this == LHS + Separator + RHS) is true and RHS is
comment|/// maximal. If \arg Separator is not in the string, then the result is a
comment|/// pair (LHS, RHS) where (*this == LHS) and (RHS == "").
comment|///
comment|/// \param Separator - The character to split on.
comment|/// \return - The split substrings.
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
block|}
comment|/// rsplit - Split into two substrings around the last occurence of a
comment|/// separator character.
comment|///
comment|/// If \arg Separator is in the string, then the result is a pair (LHS, RHS)
comment|/// such that (*this == LHS + Separator + RHS) is true and RHS is
comment|/// minimal. If \arg Separator is not in the string, then the result is a
comment|/// pair (LHS, RHS) where (*this == LHS) and (RHS == "").
comment|///
comment|/// \param Separator - The character to split on.
comment|/// \return - The split substrings.
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
specifier|const
name|StringRef
operator|&
name|LHS
operator|,
specifier|const
name|StringRef
operator|&
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
specifier|const
name|StringRef
operator|&
name|LHS
operator|,
specifier|const
name|StringRef
operator|&
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
specifier|const
name|StringRef
operator|&
name|LHS
operator|,
specifier|const
name|StringRef
operator|&
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
specifier|const
name|StringRef
operator|&
name|LHS
operator|,
specifier|const
name|StringRef
operator|&
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
specifier|const
name|StringRef
operator|&
name|LHS
operator|,
specifier|const
name|StringRef
operator|&
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
specifier|const
name|StringRef
operator|&
name|LHS
operator|,
specifier|const
name|StringRef
operator|&
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

begin_comment
comment|/// @}
end_comment

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

