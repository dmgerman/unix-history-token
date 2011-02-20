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
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/APFloat.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<cctype>
end_include

begin_include
include|#
directive|include
file|<cstdio>
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
comment|/// given number \arg X (which should be less than 16).
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

begin_expr_stmt
specifier|static
specifier|inline
name|std
operator|::
name|string
name|ftostr
argument_list|(
argument|double V
argument_list|)
block|{
name|char
name|Buffer
index|[
literal|200
index|]
block|;
name|sprintf
argument_list|(
name|Buffer
argument_list|,
literal|"%20.6e"
argument_list|,
name|V
argument_list|)
block|;
name|char
operator|*
name|B
operator|=
name|Buffer
block|;
while|while
condition|(
operator|*
name|B
operator|==
literal|' '
condition|)
operator|++
name|B
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|B
return|;
end_return

begin_expr_stmt
unit|}  static
specifier|inline
name|std
operator|::
name|string
name|ftostr
argument_list|(
argument|const APFloat& V
argument_list|)
block|{
if|if
condition|(
operator|&
name|V
operator|.
name|getSemantics
argument_list|()
operator|==
operator|&
name|APFloat
operator|::
name|IEEEdouble
condition|)
return|return
name|ftostr
argument_list|(
name|V
operator|.
name|convertToDouble
argument_list|()
argument_list|)
return|;
elseif|else
if|if
condition|(
operator|&
name|V
operator|.
name|getSemantics
argument_list|()
operator|==
operator|&
name|APFloat
operator|::
name|IEEEsingle
condition|)
return|return
name|ftostr
argument_list|(
operator|(
name|double
operator|)
name|V
operator|.
name|convertToFloat
argument_list|()
argument_list|)
return|;
end_expr_stmt

begin_return
return|return
literal|"<unknown format in ftostr>"
return|;
end_return

begin_comment
comment|// error
end_comment

begin_expr_stmt
unit|}  static
specifier|inline
name|std
operator|::
name|string
name|LowercaseString
argument_list|(
argument|const std::string&S
argument_list|)
block|{
name|std
operator|::
name|string
name|result
argument_list|(
name|S
argument_list|)
block|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|<
name|S
operator|.
name|length
argument_list|()
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|isupper
argument_list|(
name|result
index|[
name|i
index|]
argument_list|)
condition|)
name|result
index|[
name|i
index|]
operator|=
name|char
argument_list|(
name|tolower
argument_list|(
name|result
index|[
name|i
index|]
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|result
return|;
end_return

begin_expr_stmt
unit|}  static
specifier|inline
name|std
operator|::
name|string
name|UppercaseString
argument_list|(
argument|const std::string&S
argument_list|)
block|{
name|std
operator|::
name|string
name|result
argument_list|(
name|S
argument_list|)
block|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|<
name|S
operator|.
name|length
argument_list|()
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|islower
argument_list|(
name|result
index|[
name|i
index|]
argument_list|)
condition|)
name|result
index|[
name|i
index|]
operator|=
name|char
argument_list|(
name|toupper
argument_list|(
name|result
index|[
name|i
index|]
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|result
return|;
end_return

begin_comment
unit|}
comment|/// StrInStrNoCase - Portable version of strcasestr.  Locates the first
end_comment

begin_comment
comment|/// occurrence of string 's1' in string 's2', ignoring case.  Returns
end_comment

begin_comment
comment|/// the offset of s2 in s1 or npos if s2 cannot be found.
end_comment

begin_expr_stmt
unit|StringRef
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
comment|/// HashString - Hash funtion for strings.
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
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

