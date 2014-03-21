begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/ADT/StringExtras.h - Useful string functions -------*- C++ -*-===//
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
file|<iterator>
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
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
comment|/// utohex_buffer - Emit the specified number into the buffer specified by
comment|/// BufferEnd, returning a pointer to the start of the string.  This can be used
comment|/// like this: (note that the buffer must be large enough to handle any number):
comment|///    char Buffer[40];
comment|///    printf("0x%s", utohex_buffer(X, Buffer+40));
comment|///
comment|/// This should only be used with unsigned types.
comment|///
name|template
operator|<
name|typename
name|IntTy
operator|>
specifier|static
specifier|inline
name|char
operator|*
name|utohex_buffer
argument_list|(
argument|IntTy X
argument_list|,
argument|char *BufferEnd
argument_list|)
block|{
name|char
operator|*
name|BufPtr
operator|=
name|BufferEnd
block|;
operator|*
operator|--
name|BufPtr
operator|=
literal|0
block|;
comment|// Null terminate buffer.
if|if
condition|(
name|X
operator|==
literal|0
condition|)
block|{
operator|*
operator|--
name|BufPtr
operator|=
literal|'0'
expr_stmt|;
comment|// Handle special case.
return|return
name|BufPtr
return|;
block|}
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
argument_list|)
expr_stmt|;
name|X
operator|>>=
literal|4
expr_stmt|;
block|}
return|return
name|BufPtr
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
argument_list|)
block|{
name|char
name|Buffer
index|[
literal|17
index|]
block|;
return|return
name|utohex_buffer
argument_list|(
name|X
argument_list|,
name|Buffer
operator|+
literal|17
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|std
operator|::
name|string
name|utostr_32
argument_list|(
argument|uint32_t X
argument_list|,
argument|bool isNeg = false
argument_list|)
block|{
name|char
name|Buffer
index|[
literal|11
index|]
block|;
name|char
operator|*
name|BufPtr
operator|=
name|Buffer
operator|+
literal|11
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
comment|// Handle special case...
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
comment|// Add negative sign...
return|return
name|std
operator|::
name|string
argument_list|(
name|BufPtr
argument_list|,
name|Buffer
operator|+
literal|11
argument_list|)
return|;
block|}
end_decl_stmt

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
name|Buffer
operator|+
literal|21
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
name|Buffer
operator|+
literal|21
argument_list|)
return|;
end_return

begin_expr_stmt
unit|}   static
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
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
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

begin_comment
unit|}
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
typedef|typedef
name|typename
name|std
operator|::
name|iterator_traits
operator|<
name|IteratorT
operator|>
operator|::
name|iterator_category
name|tag
expr_stmt|;
end_expr_stmt

begin_return
return|return
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
end_return

begin_comment
unit|}  }
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

