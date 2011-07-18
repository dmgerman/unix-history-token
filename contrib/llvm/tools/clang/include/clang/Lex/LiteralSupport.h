begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- LiteralSupport.h ---------------------------------------*- C++ -*-===//
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
comment|// This file defines the NumericLiteralParser, CharLiteralParser, and
end_comment

begin_comment
comment|// StringLiteralParser interfaces.
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
name|CLANG_LITERALSUPPORT_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_LITERALSUPPORT_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/APFloat.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallString.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<cctype>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Diagnostic
decl_stmt|;
name|class
name|Preprocessor
decl_stmt|;
name|class
name|Token
decl_stmt|;
name|class
name|SourceLocation
decl_stmt|;
name|class
name|TargetInfo
decl_stmt|;
name|class
name|SourceManager
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
comment|/// NumericLiteralParser - This performs strict semantic analysis of the content
comment|/// of a ppnumber, classifying it as either integer, floating, or erroneous,
comment|/// determines the radix of the value and can convert it to a useful value.
name|class
name|NumericLiteralParser
block|{
name|Preprocessor
modifier|&
name|PP
decl_stmt|;
comment|// needed for diagnostics
specifier|const
name|char
modifier|*
specifier|const
name|ThisTokBegin
decl_stmt|;
specifier|const
name|char
modifier|*
specifier|const
name|ThisTokEnd
decl_stmt|;
specifier|const
name|char
modifier|*
name|DigitsBegin
decl_stmt|,
modifier|*
name|SuffixBegin
decl_stmt|;
comment|// markers
specifier|const
name|char
modifier|*
name|s
decl_stmt|;
comment|// cursor
name|unsigned
name|radix
decl_stmt|;
name|bool
name|saw_exponent
decl_stmt|,
name|saw_period
decl_stmt|;
name|public
label|:
name|NumericLiteralParser
argument_list|(
argument|const char *begin
argument_list|,
argument|const char *end
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|Preprocessor&PP
argument_list|)
empty_stmt|;
name|bool
name|hadError
decl_stmt|;
name|bool
name|isUnsigned
decl_stmt|;
name|bool
name|isLong
decl_stmt|;
comment|// This is *not* set for long long.
name|bool
name|isLongLong
decl_stmt|;
name|bool
name|isFloat
decl_stmt|;
comment|// 1.0f
name|bool
name|isImaginary
decl_stmt|;
comment|// 1.0i
name|bool
name|isMicrosoftInteger
decl_stmt|;
comment|// Microsoft suffix extension i8, i16, i32, or i64.
name|bool
name|isIntegerLiteral
argument_list|()
specifier|const
block|{
return|return
operator|!
name|saw_period
operator|&&
operator|!
name|saw_exponent
return|;
block|}
name|bool
name|isFloatingLiteral
argument_list|()
specifier|const
block|{
return|return
name|saw_period
operator|||
name|saw_exponent
return|;
block|}
name|bool
name|hasSuffix
argument_list|()
specifier|const
block|{
return|return
name|SuffixBegin
operator|!=
name|ThisTokEnd
return|;
block|}
name|unsigned
name|getRadix
argument_list|()
specifier|const
block|{
return|return
name|radix
return|;
block|}
comment|/// GetIntegerValue - Convert this numeric literal value to an APInt that
comment|/// matches Val's input width.  If there is an overflow (i.e., if the unsigned
comment|/// value read is larger than the APInt's bits will hold), set Val to the low
comment|/// bits of the result and return true.  Otherwise, return false.
name|bool
name|GetIntegerValue
argument_list|(
name|llvm
operator|::
name|APInt
operator|&
name|Val
argument_list|)
decl_stmt|;
comment|/// GetFloatValue - Convert this numeric literal to a floating value, using
comment|/// the specified APFloat fltSemantics (specifying float, double, etc).
comment|/// The optional bool isExact (passed-by-reference) has its value
comment|/// set to true if the returned APFloat can represent the number in the
comment|/// literal exactly, and false otherwise.
name|llvm
operator|::
name|APFloat
operator|::
name|opStatus
name|GetFloatValue
argument_list|(
name|llvm
operator|::
name|APFloat
operator|&
name|Result
argument_list|)
expr_stmt|;
name|private
label|:
name|void
name|ParseNumberStartingWithZero
parameter_list|(
name|SourceLocation
name|TokLoc
parameter_list|)
function_decl|;
comment|/// SkipHexDigits - Read and skip over any hex digits, up to End.
comment|/// Return a pointer to the first non-hex digit or End.
specifier|const
name|char
modifier|*
name|SkipHexDigits
parameter_list|(
specifier|const
name|char
modifier|*
name|ptr
parameter_list|)
block|{
while|while
condition|(
name|ptr
operator|!=
name|ThisTokEnd
operator|&&
name|isxdigit
argument_list|(
operator|*
name|ptr
argument_list|)
condition|)
name|ptr
operator|++
expr_stmt|;
return|return
name|ptr
return|;
block|}
comment|/// SkipOctalDigits - Read and skip over any octal digits, up to End.
comment|/// Return a pointer to the first non-hex digit or End.
specifier|const
name|char
modifier|*
name|SkipOctalDigits
parameter_list|(
specifier|const
name|char
modifier|*
name|ptr
parameter_list|)
block|{
while|while
condition|(
name|ptr
operator|!=
name|ThisTokEnd
operator|&&
operator|(
operator|(
operator|*
name|ptr
operator|>=
literal|'0'
operator|)
operator|&&
operator|(
operator|*
name|ptr
operator|<=
literal|'7'
operator|)
operator|)
condition|)
name|ptr
operator|++
expr_stmt|;
return|return
name|ptr
return|;
block|}
comment|/// SkipDigits - Read and skip over any digits, up to End.
comment|/// Return a pointer to the first non-hex digit or End.
specifier|const
name|char
modifier|*
name|SkipDigits
parameter_list|(
specifier|const
name|char
modifier|*
name|ptr
parameter_list|)
block|{
while|while
condition|(
name|ptr
operator|!=
name|ThisTokEnd
operator|&&
name|isdigit
argument_list|(
operator|*
name|ptr
argument_list|)
condition|)
name|ptr
operator|++
expr_stmt|;
return|return
name|ptr
return|;
block|}
comment|/// SkipBinaryDigits - Read and skip over any binary digits, up to End.
comment|/// Return a pointer to the first non-binary digit or End.
specifier|const
name|char
modifier|*
name|SkipBinaryDigits
parameter_list|(
specifier|const
name|char
modifier|*
name|ptr
parameter_list|)
block|{
while|while
condition|(
name|ptr
operator|!=
name|ThisTokEnd
operator|&&
operator|(
operator|*
name|ptr
operator|==
literal|'0'
operator|||
operator|*
name|ptr
operator|==
literal|'1'
operator|)
condition|)
name|ptr
operator|++
expr_stmt|;
return|return
name|ptr
return|;
block|}
block|}
empty_stmt|;
comment|/// CharLiteralParser - Perform interpretation and semantic analysis of a
comment|/// character literal.
name|class
name|CharLiteralParser
block|{
name|uint64_t
name|Value
decl_stmt|;
name|bool
name|IsWide
decl_stmt|;
name|bool
name|IsMultiChar
decl_stmt|;
name|bool
name|HadError
decl_stmt|;
name|public
label|:
name|CharLiteralParser
argument_list|(
argument|const char *begin
argument_list|,
argument|const char *end
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|Preprocessor&PP
argument_list|)
empty_stmt|;
name|bool
name|hadError
argument_list|()
specifier|const
block|{
return|return
name|HadError
return|;
block|}
name|bool
name|isWide
argument_list|()
specifier|const
block|{
return|return
name|IsWide
return|;
block|}
name|bool
name|isMultiChar
argument_list|()
specifier|const
block|{
return|return
name|IsMultiChar
return|;
block|}
name|uint64_t
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|Value
return|;
block|}
block|}
empty_stmt|;
comment|/// StringLiteralParser - This decodes string escape characters and performs
comment|/// wide string analysis and Translation Phase #6 (concatenation of string
comment|/// literals) (C99 5.1.1.2p1).
name|class
name|StringLiteralParser
block|{
specifier|const
name|SourceManager
modifier|&
name|SM
decl_stmt|;
specifier|const
name|LangOptions
modifier|&
name|Features
decl_stmt|;
specifier|const
name|TargetInfo
modifier|&
name|Target
decl_stmt|;
name|Diagnostic
modifier|*
name|Diags
decl_stmt|;
name|unsigned
name|MaxTokenLength
decl_stmt|;
name|unsigned
name|SizeBound
decl_stmt|;
name|unsigned
name|wchar_tByteWidth
decl_stmt|;
name|llvm
operator|::
name|SmallString
operator|<
literal|512
operator|>
name|ResultBuf
expr_stmt|;
name|char
modifier|*
name|ResultPtr
decl_stmt|;
comment|// cursor
name|public
label|:
name|StringLiteralParser
argument_list|(
argument|const Token *StringToks
argument_list|,
argument|unsigned NumStringToks
argument_list|,
argument|Preprocessor&PP
argument_list|,
argument|bool Complain = true
argument_list|)
empty_stmt|;
name|StringLiteralParser
argument_list|(
argument|const Token *StringToks
argument_list|,
argument|unsigned NumStringToks
argument_list|,
argument|const SourceManager&sm
argument_list|,
argument|const LangOptions&features
argument_list|,
argument|const TargetInfo&target
argument_list|,
argument|Diagnostic *diags =
literal|0
argument_list|)
block|:
name|SM
argument_list|(
name|sm
argument_list|)
operator|,
name|Features
argument_list|(
name|features
argument_list|)
operator|,
name|Target
argument_list|(
name|target
argument_list|)
operator|,
name|Diags
argument_list|(
name|diags
argument_list|)
operator|,
name|MaxTokenLength
argument_list|(
literal|0
argument_list|)
operator|,
name|SizeBound
argument_list|(
literal|0
argument_list|)
operator|,
name|wchar_tByteWidth
argument_list|(
literal|0
argument_list|)
operator|,
name|ResultPtr
argument_list|(
name|ResultBuf
operator|.
name|data
argument_list|()
argument_list|)
operator|,
name|hadError
argument_list|(
name|false
argument_list|)
operator|,
name|AnyWide
argument_list|(
name|false
argument_list|)
operator|,
name|Pascal
argument_list|(
argument|false
argument_list|)
block|{
name|init
argument_list|(
name|StringToks
argument_list|,
name|NumStringToks
argument_list|)
block|;   }
name|bool
name|hadError
expr_stmt|;
name|bool
name|AnyWide
decl_stmt|;
name|bool
name|Pascal
decl_stmt|;
name|llvm
operator|::
name|StringRef
name|GetString
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|StringRef
argument_list|(
name|ResultBuf
operator|.
name|data
argument_list|()
argument_list|,
name|GetStringLength
argument_list|()
argument_list|)
return|;
block|}
name|unsigned
name|GetStringLength
argument_list|()
specifier|const
block|{
return|return
name|ResultPtr
operator|-
name|ResultBuf
operator|.
name|data
argument_list|()
return|;
block|}
name|unsigned
name|GetNumStringChars
argument_list|()
specifier|const
block|{
if|if
condition|(
name|AnyWide
condition|)
return|return
name|GetStringLength
argument_list|()
operator|/
name|wchar_tByteWidth
return|;
return|return
name|GetStringLength
argument_list|()
return|;
block|}
comment|/// getOffsetOfStringByte - This function returns the offset of the
comment|/// specified byte of the string data represented by Token.  This handles
comment|/// advancing over escape sequences in the string.
comment|///
comment|/// If the Diagnostics pointer is non-null, then this will do semantic
comment|/// checking of the string literal and emit errors and warnings.
name|unsigned
name|getOffsetOfStringByte
argument_list|(
specifier|const
name|Token
operator|&
name|TheTok
argument_list|,
name|unsigned
name|ByteNo
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|void
name|init
parameter_list|(
specifier|const
name|Token
modifier|*
name|StringToks
parameter_list|,
name|unsigned
name|NumStringToks
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

