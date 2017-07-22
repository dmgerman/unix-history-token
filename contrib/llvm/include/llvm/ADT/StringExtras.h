begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/ADT/StringExtras.h - Useful string functions --------*- C++ -*-===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|// This file contains some functions that are useful when dealing with strings.
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
name|LLVM_ADT_STRINGEXTRAS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_STRINGEXTRAS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallString.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
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
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<cstdlib>
end_include

begin_include
include|#
directive|include
file|<cstring>
end_include

begin_include
include|#
directive|include
file|<iterator>
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
name|raw_ostream
decl_stmt|;
comment|/// hexdigit - Return the hexadecimal character for the
comment|/// given number \p X (which should be less than 16).
specifier|static
specifier|inline
name|char
name|hexdigit
parameter_list|(
name|unsigned
name|X
parameter_list|,
name|bool
name|LowerCase
init|=
name|false
parameter_list|)
block|{
specifier|const
name|char
name|HexChar
init|=
name|LowerCase
condition|?
literal|'a'
else|:
literal|'A'
decl_stmt|;
return|return
name|X
operator|<
literal|10
condition|?
literal|'0'
operator|+
name|X
else|:
name|HexChar
operator|+
name|X
operator|-
literal|10
return|;
block|}
comment|/// Construct a string ref from a boolean.
specifier|static
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
comment|/// Construct a string ref from an array ref of unsigned chars.
specifier|static
specifier|inline
name|StringRef
name|toStringRef
argument_list|(
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Input
argument_list|)
block|{
return|return
name|StringRef
argument_list|(
name|reinterpret_cast
operator|<
specifier|const
name|char
operator|*
operator|>
operator|(
name|Input
operator|.
name|begin
argument_list|()
operator|)
argument_list|,
name|Input
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
comment|/// Interpret the given character \p C as a hexadecimal digit and return its
comment|/// value.
comment|///
comment|/// If \p C is not a valid hex digit, -1U is returned.
specifier|static
specifier|inline
name|unsigned
name|hexDigitValue
parameter_list|(
name|char
name|C
parameter_list|)
block|{
if|if
condition|(
name|C
operator|>=
literal|'0'
operator|&&
name|C
operator|<=
literal|'9'
condition|)
return|return
name|C
operator|-
literal|'0'
return|;
if|if
condition|(
name|C
operator|>=
literal|'a'
operator|&&
name|C
operator|<=
literal|'f'
condition|)
return|return
name|C
operator|-
literal|'a'
operator|+
literal|10U
return|;
if|if
condition|(
name|C
operator|>=
literal|'A'
operator|&&
name|C
operator|<=
literal|'F'
condition|)
return|return
name|C
operator|-
literal|'A'
operator|+
literal|10U
return|;
return|return
operator|-
literal|1U
return|;
block|}
specifier|static
specifier|inline
name|std
operator|::
name|string
name|utohexstr
argument_list|(
argument|uint64_t X
argument_list|,
argument|bool LowerCase = false
argument_list|)
block|{
name|char
name|Buffer
index|[
literal|17
index|]
block|;
name|char
operator|*
name|BufPtr
operator|=
name|std
operator|::
name|end
argument_list|(
name|Buffer
argument_list|)
block|;
if|if
condition|(
name|X
operator|==
literal|0
condition|)
operator|*
operator|--
name|BufPtr
operator|=
literal|'0'
expr_stmt|;
while|while
condition|(
name|X
condition|)
block|{
name|unsigned
name|char
name|Mod
init|=
name|static_cast
operator|<
name|unsigned
name|char
operator|>
operator|(
name|X
operator|)
operator|&
literal|15
decl_stmt|;
operator|*
operator|--
name|BufPtr
operator|=
name|hexdigit
argument_list|(
name|Mod
argument_list|,
name|LowerCase
argument_list|)
expr_stmt|;
name|X
operator|>>=
literal|4
expr_stmt|;
block|}
return|return
name|std
operator|::
name|string
argument_list|(
name|BufPtr
argument_list|,
name|std
operator|::
name|end
argument_list|(
name|Buffer
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Convert buffer \p Input to its hexadecimal representation.
end_comment

begin_comment
comment|/// The returned string is double the size of \p Input.
end_comment

begin_expr_stmt
specifier|inline
name|std
operator|::
name|string
name|toHex
argument_list|(
argument|StringRef Input
argument_list|)
block|{
specifier|static
specifier|const
name|char
operator|*
specifier|const
name|LUT
operator|=
literal|"0123456789ABCDEF"
block|;
name|size_t
name|Length
operator|=
name|Input
operator|.
name|size
argument_list|()
block|;
name|std
operator|::
name|string
name|Output
block|;
name|Output
operator|.
name|reserve
argument_list|(
literal|2
operator|*
name|Length
argument_list|)
block|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|Length
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|unsigned
name|char
name|c
init|=
name|Input
index|[
name|i
index|]
decl_stmt|;
name|Output
operator|.
name|push_back
argument_list|(
name|LUT
index|[
name|c
operator|>>
literal|4
index|]
argument_list|)
expr_stmt|;
name|Output
operator|.
name|push_back
argument_list|(
name|LUT
index|[
name|c
operator|&
literal|15
index|]
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
name|Output
return|;
end_return

begin_expr_stmt
unit|}  inline
name|std
operator|::
name|string
name|toHex
argument_list|(
argument|ArrayRef<uint8_t> Input
argument_list|)
block|{
return|return
name|toHex
argument_list|(
name|toStringRef
argument_list|(
name|Input
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
specifier|static
specifier|inline
name|uint8_t
name|hexFromNibbles
parameter_list|(
name|char
name|MSB
parameter_list|,
name|char
name|LSB
parameter_list|)
block|{
name|unsigned
name|U1
init|=
name|hexDigitValue
argument_list|(
name|MSB
argument_list|)
decl_stmt|;
name|unsigned
name|U2
init|=
name|hexDigitValue
argument_list|(
name|LSB
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|U1
operator|!=
operator|-
literal|1U
operator|&&
name|U2
operator|!=
operator|-
literal|1U
argument_list|)
expr_stmt|;
return|return
name|static_cast
operator|<
name|uint8_t
operator|>
operator|(
operator|(
name|U1
operator|<<
literal|4
operator|)
operator||
name|U2
operator|)
return|;
block|}
end_function

begin_comment
comment|/// Convert hexadecimal string \p Input to its binary representation.
end_comment

begin_comment
comment|/// The return string is half the size of \p Input.
end_comment

begin_expr_stmt
specifier|static
specifier|inline
name|std
operator|::
name|string
name|fromHex
argument_list|(
argument|StringRef Input
argument_list|)
block|{
if|if
condition|(
name|Input
operator|.
name|empty
argument_list|()
condition|)
return|return
name|std
operator|::
name|string
argument_list|()
return|;
name|std
operator|::
name|string
name|Output
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Output
operator|.
name|reserve
argument_list|(
operator|(
name|Input
operator|.
name|size
argument_list|()
operator|+
literal|1
operator|)
operator|/
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|Input
operator|.
name|size
argument_list|()
operator|%
literal|2
operator|==
literal|1
condition|)
block|{
name|Output
operator|.
name|push_back
argument_list|(
name|hexFromNibbles
argument_list|(
literal|'0'
argument_list|,
name|Input
operator|.
name|front
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|Input
operator|=
name|Input
operator|.
name|drop_front
argument_list|()
expr_stmt|;
block|}
end_if

begin_expr_stmt
name|assert
argument_list|(
name|Input
operator|.
name|size
argument_list|()
operator|%
literal|2
operator|==
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_while
while|while
condition|(
operator|!
name|Input
operator|.
name|empty
argument_list|()
condition|)
block|{
name|uint8_t
name|Hex
init|=
name|hexFromNibbles
argument_list|(
name|Input
index|[
literal|0
index|]
argument_list|,
name|Input
index|[
literal|1
index|]
argument_list|)
decl_stmt|;
name|Output
operator|.
name|push_back
argument_list|(
name|Hex
argument_list|)
expr_stmt|;
name|Input
operator|=
name|Input
operator|.
name|drop_front
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
end_while

begin_return
return|return
name|Output
return|;
end_return

begin_comment
unit|}
comment|/// \brief Convert the string \p S to an integer of the specified type using
end_comment

begin_comment
comment|/// the radix \p Base.  If \p Base is 0, auto-detects the radix.
end_comment

begin_comment
comment|/// Returns true if the number was successfully converted, false otherwise.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|N
operator|>
name|bool
name|to_integer
argument_list|(
argument|StringRef S
argument_list|,
argument|N&Num
argument_list|,
argument|unsigned Base =
literal|0
argument_list|)
block|{
return|return
operator|!
name|S
operator|.
name|getAsInteger
argument_list|(
name|Base
argument_list|,
name|Num
argument_list|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|namespace
name|detail
block|{
name|template
operator|<
name|typename
name|N
operator|>
specifier|inline
name|bool
name|to_float
argument_list|(
argument|const Twine&T
argument_list|,
argument|N&Num
argument_list|,
argument|N (*StrTo)(const char *, char **)
argument_list|)
block|{
name|SmallString
operator|<
literal|32
operator|>
name|Storage
block|;
name|StringRef
name|S
operator|=
name|T
operator|.
name|toNullTerminatedStringRef
argument_list|(
name|Storage
argument_list|)
block|;
name|char
operator|*
name|End
block|;
name|N
name|Temp
operator|=
name|StrTo
argument_list|(
name|S
operator|.
name|data
argument_list|()
argument_list|,
operator|&
name|End
argument_list|)
block|;
if|if
condition|(
operator|*
name|End
operator|!=
literal|'\0'
condition|)
return|return
name|false
return|;
name|Num
operator|=
name|Temp
expr_stmt|;
return|return
name|true
return|;
block|}
end_decl_stmt

begin_function
unit|}  inline
name|bool
name|to_float
parameter_list|(
specifier|const
name|Twine
modifier|&
name|T
parameter_list|,
name|float
modifier|&
name|Num
parameter_list|)
block|{
return|return
name|detail
operator|::
name|to_float
argument_list|(
name|T
argument_list|,
name|Num
argument_list|,
name|strtof
argument_list|)
return|;
block|}
end_function

begin_function
specifier|inline
name|bool
name|to_float
parameter_list|(
specifier|const
name|Twine
modifier|&
name|T
parameter_list|,
name|double
modifier|&
name|Num
parameter_list|)
block|{
return|return
name|detail
operator|::
name|to_float
argument_list|(
name|T
argument_list|,
name|Num
argument_list|,
name|strtod
argument_list|)
return|;
block|}
end_function

begin_function
specifier|inline
name|bool
name|to_float
parameter_list|(
specifier|const
name|Twine
modifier|&
name|T
parameter_list|,
name|long
name|double
modifier|&
name|Num
parameter_list|)
block|{
return|return
name|detail
operator|::
name|to_float
argument_list|(
name|T
argument_list|,
name|Num
argument_list|,
name|strtold
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
specifier|static
specifier|inline
name|std
operator|::
name|string
name|utostr
argument_list|(
argument|uint64_t X
argument_list|,
argument|bool isNeg = false
argument_list|)
block|{
name|char
name|Buffer
index|[
literal|21
index|]
block|;
name|char
operator|*
name|BufPtr
operator|=
name|std
operator|::
name|end
argument_list|(
name|Buffer
argument_list|)
block|;
if|if
condition|(
name|X
operator|==
literal|0
condition|)
operator|*
operator|--
name|BufPtr
operator|=
literal|'0'
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Handle special case...
end_comment

begin_while
while|while
condition|(
name|X
condition|)
block|{
operator|*
operator|--
name|BufPtr
operator|=
literal|'0'
operator|+
name|char
argument_list|(
name|X
operator|%
literal|10
argument_list|)
expr_stmt|;
name|X
operator|/=
literal|10
expr_stmt|;
block|}
end_while

begin_if
if|if
condition|(
name|isNeg
condition|)
operator|*
operator|--
name|BufPtr
operator|=
literal|'-'
expr_stmt|;
end_if

begin_comment
comment|// Add negative sign...
end_comment

begin_return
return|return
name|std
operator|::
name|string
argument_list|(
name|BufPtr
argument_list|,
name|std
operator|::
name|end
argument_list|(
name|Buffer
argument_list|)
argument_list|)
return|;
end_return

begin_expr_stmt
unit|}  static
specifier|inline
name|std
operator|::
name|string
name|itostr
argument_list|(
argument|int64_t X
argument_list|)
block|{
if|if
condition|(
name|X
operator|<
literal|0
condition|)
return|return
name|utostr
argument_list|(
name|static_cast
operator|<
name|uint64_t
operator|>
operator|(
operator|-
name|X
operator|)
argument_list|,
name|true
argument_list|)
return|;
else|else
return|return
name|utostr
argument_list|(
name|static_cast
operator|<
name|uint64_t
operator|>
operator|(
name|X
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// StrInStrNoCase - Portable version of strcasestr.  Locates the first
end_comment

begin_comment
comment|/// occurrence of string 's1' in string 's2', ignoring case.  Returns
end_comment

begin_comment
comment|/// the offset of s2 in s1 or npos if s2 cannot be found.
end_comment

begin_expr_stmt
name|StringRef
operator|::
name|size_type
name|StrInStrNoCase
argument_list|(
argument|StringRef s1
argument_list|,
argument|StringRef s2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// getToken - This function extracts one token from source, ignoring any
end_comment

begin_comment
comment|/// leading characters that appear in the Delimiters string, and ending the
end_comment

begin_comment
comment|/// token at any of the characters that appear in the Delimiters string.  If
end_comment

begin_comment
comment|/// there are no tokens in the source string, an empty string is returned.
end_comment

begin_comment
comment|/// The function returns a pair containing the extracted token and the
end_comment

begin_comment
comment|/// remaining tail string.
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
name|getToken
argument_list|(
argument|StringRef Source
argument_list|,
argument|StringRef Delimiters =
literal|" \t\n\v\f\r"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// SplitString - Split up the specified string according to the specified
end_comment

begin_comment
comment|/// delimiters, appending the result fragments to the output list.
end_comment

begin_decl_stmt
name|void
name|SplitString
argument_list|(
name|StringRef
name|Source
argument_list|,
name|SmallVectorImpl
operator|<
name|StringRef
operator|>
operator|&
name|OutFragments
argument_list|,
name|StringRef
name|Delimiters
operator|=
literal|" \t\n\v\f\r"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// HashString - Hash function for strings.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is the Bernstein hash function.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// FIXME: Investigate whether a modified bernstein hash function performs
end_comment

begin_comment
comment|// better: http://eternallyconfuzzled.com/tuts/algorithms/jsw_tut_hashing.aspx
end_comment

begin_comment
comment|//   X*33+c -> X*33^c
end_comment

begin_function
specifier|static
specifier|inline
name|unsigned
name|HashString
parameter_list|(
name|StringRef
name|Str
parameter_list|,
name|unsigned
name|Result
init|=
literal|0
parameter_list|)
block|{
for|for
control|(
name|StringRef
operator|::
name|size_type
name|i
operator|=
literal|0
operator|,
name|e
operator|=
name|Str
operator|.
name|size
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
name|Result
operator|=
name|Result
operator|*
literal|33
operator|+
operator|(
name|unsigned
name|char
operator|)
name|Str
index|[
name|i
index|]
expr_stmt|;
return|return
name|Result
return|;
block|}
end_function

begin_comment
comment|/// Returns the English suffix for an ordinal integer (-st, -nd, -rd, -th).
end_comment

begin_function
specifier|static
specifier|inline
name|StringRef
name|getOrdinalSuffix
parameter_list|(
name|unsigned
name|Val
parameter_list|)
block|{
comment|// It is critically important that we do this perfectly for
comment|// user-written sequences with over 100 elements.
switch|switch
condition|(
name|Val
operator|%
literal|100
condition|)
block|{
case|case
literal|11
case|:
case|case
literal|12
case|:
case|case
literal|13
case|:
return|return
literal|"th"
return|;
default|default:
switch|switch
condition|(
name|Val
operator|%
literal|10
condition|)
block|{
case|case
literal|1
case|:
return|return
literal|"st"
return|;
case|case
literal|2
case|:
return|return
literal|"nd"
return|;
case|case
literal|3
case|:
return|return
literal|"rd"
return|;
default|default:
return|return
literal|"th"
return|;
block|}
block|}
block|}
end_function

begin_comment
comment|/// PrintEscapedString - Print each character of the specified string, escaping
end_comment

begin_comment
comment|/// it if it is not printable or if it is an escape char.
end_comment

begin_function_decl
name|void
name|PrintEscapedString
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|raw_ostream
modifier|&
name|Out
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|namespace
name|detail
block|{
name|template
operator|<
name|typename
name|IteratorT
operator|>
specifier|inline
name|std
operator|::
name|string
name|join_impl
argument_list|(
argument|IteratorT Begin
argument_list|,
argument|IteratorT End
argument_list|,
argument|StringRef Separator
argument_list|,
argument|std::input_iterator_tag
argument_list|)
block|{
name|std
operator|::
name|string
name|S
block|;
if|if
condition|(
name|Begin
operator|==
name|End
condition|)
return|return
name|S
return|;
name|S
operator|+=
operator|(
operator|*
name|Begin
operator|)
expr_stmt|;
while|while
condition|(
operator|++
name|Begin
operator|!=
name|End
condition|)
block|{
name|S
operator|+=
name|Separator
expr_stmt|;
name|S
operator|+=
operator|(
operator|*
name|Begin
operator|)
expr_stmt|;
block|}
return|return
name|S
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|IteratorT
operator|>
specifier|inline
name|std
operator|::
name|string
name|join_impl
argument_list|(
argument|IteratorT Begin
argument_list|,
argument|IteratorT End
argument_list|,
argument|StringRef Separator
argument_list|,
argument|std::forward_iterator_tag
argument_list|)
block|{
name|std
operator|::
name|string
name|S
block|;
if|if
condition|(
name|Begin
operator|==
name|End
condition|)
return|return
name|S
return|;
name|size_t
name|Len
operator|=
operator|(
name|std
operator|::
name|distance
argument_list|(
name|Begin
argument_list|,
name|End
argument_list|)
operator|-
literal|1
operator|)
operator|*
name|Separator
operator|.
name|size
argument_list|()
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
name|IteratorT
name|I
init|=
name|Begin
init|;
name|I
operator|!=
name|End
condition|;
operator|++
name|I
control|)
name|Len
operator|+=
operator|(
operator|*
name|Begin
operator|)
operator|.
name|size
argument_list|()
expr_stmt|;
end_for

begin_expr_stmt
name|S
operator|.
name|reserve
argument_list|(
name|Len
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|S
operator|+=
operator|(
operator|*
name|Begin
operator|)
expr_stmt|;
end_expr_stmt

begin_while
while|while
condition|(
operator|++
name|Begin
operator|!=
name|End
condition|)
block|{
name|S
operator|+=
name|Separator
expr_stmt|;
name|S
operator|+=
operator|(
operator|*
name|Begin
operator|)
expr_stmt|;
block|}
end_while

begin_return
return|return
name|S
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|typename
name|Sep
operator|>
specifier|inline
name|void
name|join_items_impl
argument_list|(
argument|std::string&Result
argument_list|,
argument|Sep Separator
argument_list|)
block|{}
name|template
operator|<
name|typename
name|Sep
operator|,
name|typename
name|Arg
operator|>
specifier|inline
name|void
name|join_items_impl
argument_list|(
argument|std::string&Result
argument_list|,
argument|Sep Separator
argument_list|,
argument|const Arg&Item
argument_list|)
block|{
name|Result
operator|+=
name|Item
block|; }
name|template
operator|<
name|typename
name|Sep
operator|,
name|typename
name|Arg1
operator|,
name|typename
operator|...
name|Args
operator|>
specifier|inline
name|void
name|join_items_impl
argument_list|(
argument|std::string&Result
argument_list|,
argument|Sep Separator
argument_list|,
argument|const Arg1&A1
argument_list|,
argument|Args&&... Items
argument_list|)
block|{
name|Result
operator|+=
name|A1
block|;
name|Result
operator|+=
name|Separator
block|;
name|join_items_impl
argument_list|(
name|Result
argument_list|,
name|Separator
argument_list|,
name|std
operator|::
name|forward
operator|<
name|Args
operator|>
operator|(
name|Items
operator|)
operator|...
argument_list|)
block|; }
specifier|inline
name|size_t
name|join_one_item_size
argument_list|(
argument|char C
argument_list|)
block|{
return|return
literal|1
return|;
block|}
end_expr_stmt

begin_function
specifier|inline
name|size_t
name|join_one_item_size
parameter_list|(
specifier|const
name|char
modifier|*
name|S
parameter_list|)
block|{
return|return
name|S
condition|?
operator|::
name|strlen
argument_list|(
name|S
argument_list|)
else|:
literal|0
return|;
block|}
end_function

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|size_t
name|join_one_item_size
argument_list|(
argument|const T&Str
argument_list|)
block|{
return|return
name|Str
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
specifier|inline
name|size_t
name|join_items_size
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_expr_stmt
name|template
operator|<
name|typename
name|A1
operator|>
specifier|inline
name|size_t
name|join_items_size
argument_list|(
argument|const A1&A
argument_list|)
block|{
return|return
name|join_one_item_size
argument_list|(
name|A
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|A1
operator|,
name|typename
operator|...
name|Args
operator|>
specifier|inline
name|size_t
name|join_items_size
argument_list|(
argument|const A1&A
argument_list|,
argument|Args&&... Items
argument_list|)
block|{
return|return
name|join_one_item_size
argument_list|(
name|A
argument_list|)
operator|+
name|join_items_size
argument_list|(
name|std
operator|::
name|forward
operator|<
name|Args
operator|>
operator|(
name|Items
operator|)
operator|...
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// end namespace detail
end_comment

begin_comment
comment|/// Joins the strings in the range [Begin, End), adding Separator between
end_comment

begin_comment
comment|/// the elements.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|IteratorT
operator|>
specifier|inline
name|std
operator|::
name|string
name|join
argument_list|(
argument|IteratorT Begin
argument_list|,
argument|IteratorT End
argument_list|,
argument|StringRef Separator
argument_list|)
block|{
name|using
name|tag
operator|=
name|typename
name|std
operator|::
name|iterator_traits
operator|<
name|IteratorT
operator|>
operator|::
name|iterator_category
block|;
return|return
name|detail
operator|::
name|join_impl
argument_list|(
name|Begin
argument_list|,
name|End
argument_list|,
name|Separator
argument_list|,
name|tag
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Joins the strings in the range [R.begin(), R.end()), adding Separator
end_comment

begin_comment
comment|/// between the elements.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Range
operator|>
specifier|inline
name|std
operator|::
name|string
name|join
argument_list|(
argument|Range&&R
argument_list|,
argument|StringRef Separator
argument_list|)
block|{
return|return
name|join
argument_list|(
name|R
operator|.
name|begin
argument_list|()
argument_list|,
name|R
operator|.
name|end
argument_list|()
argument_list|,
name|Separator
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Joins the strings in the parameter pack \p Items, adding \p Separator
end_comment

begin_comment
comment|/// between the elements.  All arguments must be implicitly convertible to
end_comment

begin_comment
comment|/// std::string, or there should be an overload of std::string::operator+=()
end_comment

begin_comment
comment|/// that accepts the argument explicitly.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Sep
operator|,
name|typename
operator|...
name|Args
operator|>
specifier|inline
name|std
operator|::
name|string
name|join_items
argument_list|(
argument|Sep Separator
argument_list|,
argument|Args&&... Items
argument_list|)
block|{
name|std
operator|::
name|string
name|Result
block|;
if|if
condition|(
sizeof|sizeof...
argument_list|(
name|Items
argument_list|)
operator|==
literal|0
condition|)
return|return
name|Result
return|;
name|size_t
name|NS
operator|=
name|detail
operator|::
name|join_one_item_size
argument_list|(
name|Separator
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|size_t
name|NI
init|=
name|detail
operator|::
name|join_items_size
argument_list|(
name|std
operator|::
name|forward
operator|<
name|Args
operator|>
operator|(
name|Items
operator|)
operator|...
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|Result
operator|.
name|reserve
argument_list|(
name|NI
operator|+
operator|(
sizeof|sizeof...
argument_list|(
name|Items
argument_list|)
operator|-
literal|1
operator|)
operator|*
name|NS
operator|+
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|detail
operator|::
name|join_items_impl
argument_list|(
name|Result
argument_list|,
name|Separator
argument_list|,
name|std
operator|::
name|forward
operator|<
name|Args
operator|>
operator|(
name|Items
operator|)
operator|...
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|Result
return|;
end_return

begin_comment
unit|}  }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_ADT_STRINGEXTRAS_H
end_comment

end_unit

