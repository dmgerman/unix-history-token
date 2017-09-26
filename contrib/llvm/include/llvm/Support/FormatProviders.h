begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- FormatProviders.h - Formatters for common LLVM types -----*- C++ -*-===//
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
comment|// This file implements format providers for many common LLVM types, for example
end_comment

begin_comment
comment|// allowing precision and width specifiers for scalar and string types.
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
name|LLVM_SUPPORT_FORMATPROVIDERS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_FORMATPROVIDERS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringSwitch.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Twine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/FormatVariadicDetails.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/NativeFormatting.h"
end_include

begin_include
include|#
directive|include
file|<type_traits>
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
name|namespace
name|detail
block|{
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|use_integral_formatter
operator|:
name|public
name|std
operator|::
name|integral_constant
operator|<
name|bool
operator|,
name|is_one_of
operator|<
name|T
operator|,
name|uint8_t
operator|,
name|int16_t
operator|,
name|uint16_t
operator|,
name|int32_t
operator|,
name|uint32_t
operator|,
name|int64_t
operator|,
name|uint64_t
operator|,
name|int
operator|,
name|unsigned
operator|,
name|long
operator|,
name|unsigned
name|long
operator|,
name|long
name|long
operator|,
name|unsigned
name|long
name|long
operator|>
operator|::
name|value
operator|>
block|{}
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|use_char_formatter
operator|:
name|public
name|std
operator|::
name|integral_constant
operator|<
name|bool
operator|,
name|std
operator|::
name|is_same
operator|<
name|T
operator|,
name|char
operator|>
operator|::
name|value
operator|>
block|{}
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|is_cstring
operator|:
name|public
name|std
operator|::
name|integral_constant
operator|<
name|bool
operator|,
name|is_one_of
operator|<
name|T
operator|,
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|>
operator|::
name|value
operator|>
block|{ }
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|use_string_formatter
operator|:
name|public
name|std
operator|::
name|integral_constant
operator|<
name|bool
operator|,
name|std
operator|::
name|is_convertible
operator|<
name|T
operator|,
name|llvm
operator|::
name|StringRef
operator|>
operator|::
name|value
operator|>
block|{}
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|use_pointer_formatter
operator|:
name|public
name|std
operator|::
name|integral_constant
operator|<
name|bool
operator|,
name|std
operator|::
name|is_pointer
operator|<
name|T
operator|>
operator|::
name|value
operator|&&
operator|!
name|is_cstring
operator|<
name|T
operator|>
operator|::
name|value
operator|>
block|{}
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|use_double_formatter
operator|:
name|public
name|std
operator|::
name|integral_constant
operator|<
name|bool
operator|,
name|std
operator|::
name|is_floating_point
operator|<
name|T
operator|>
operator|::
name|value
operator|>
block|{}
expr_stmt|;
name|class
name|HelperFunctions
block|{
name|protected
label|:
specifier|static
name|Optional
operator|<
name|size_t
operator|>
name|parseNumericPrecision
argument_list|(
argument|StringRef Str
argument_list|)
block|{
name|size_t
name|Prec
block|;
name|Optional
operator|<
name|size_t
operator|>
name|Result
block|;
if|if
condition|(
name|Str
operator|.
name|empty
argument_list|()
condition|)
name|Result
operator|=
name|None
expr_stmt|;
elseif|else
if|if
condition|(
name|Str
operator|.
name|getAsInteger
argument_list|(
literal|10
argument_list|,
name|Prec
argument_list|)
condition|)
block|{
name|assert
argument_list|(
name|false
operator|&&
literal|"Invalid precision specifier"
argument_list|)
expr_stmt|;
name|Result
operator|=
name|None
expr_stmt|;
block|}
else|else
block|{
name|assert
argument_list|(
name|Prec
operator|<
literal|100
operator|&&
literal|"Precision out of range"
argument_list|)
expr_stmt|;
name|Result
operator|=
name|std
operator|::
name|min
operator|<
name|size_t
operator|>
operator|(
literal|99u
operator|,
name|Prec
operator|)
expr_stmt|;
block|}
return|return
name|Result
return|;
block|}
specifier|static
name|bool
name|consumeHexStyle
parameter_list|(
name|StringRef
modifier|&
name|Str
parameter_list|,
name|HexPrintStyle
modifier|&
name|Style
parameter_list|)
block|{
if|if
condition|(
operator|!
name|Str
operator|.
name|startswith_lower
argument_list|(
literal|"x"
argument_list|)
condition|)
return|return
name|false
return|;
if|if
condition|(
name|Str
operator|.
name|consume_front
argument_list|(
literal|"x-"
argument_list|)
condition|)
name|Style
operator|=
name|HexPrintStyle
operator|::
name|Lower
expr_stmt|;
elseif|else
if|if
condition|(
name|Str
operator|.
name|consume_front
argument_list|(
literal|"X-"
argument_list|)
condition|)
name|Style
operator|=
name|HexPrintStyle
operator|::
name|Upper
expr_stmt|;
elseif|else
if|if
condition|(
name|Str
operator|.
name|consume_front
argument_list|(
literal|"x+"
argument_list|)
operator|||
name|Str
operator|.
name|consume_front
argument_list|(
literal|"x"
argument_list|)
condition|)
name|Style
operator|=
name|HexPrintStyle
operator|::
name|PrefixLower
expr_stmt|;
elseif|else
if|if
condition|(
name|Str
operator|.
name|consume_front
argument_list|(
literal|"X+"
argument_list|)
operator|||
name|Str
operator|.
name|consume_front
argument_list|(
literal|"X"
argument_list|)
condition|)
name|Style
operator|=
name|HexPrintStyle
operator|::
name|PrefixUpper
expr_stmt|;
return|return
name|true
return|;
block|}
specifier|static
name|size_t
name|consumeNumHexDigits
parameter_list|(
name|StringRef
modifier|&
name|Str
parameter_list|,
name|HexPrintStyle
name|Style
parameter_list|,
name|size_t
name|Default
parameter_list|)
block|{
name|Str
operator|.
name|consumeInteger
argument_list|(
literal|10
argument_list|,
name|Default
argument_list|)
expr_stmt|;
if|if
condition|(
name|isPrefixedHexStyle
argument_list|(
name|Style
argument_list|)
condition|)
name|Default
operator|+=
literal|2
expr_stmt|;
return|return
name|Default
return|;
block|}
block|}
empty_stmt|;
block|}
comment|/// Implementation of format_provider<T> for integral arithmetic types.
comment|///
comment|/// The options string of an integral type has the grammar:
comment|///
comment|///   integer_options   :: [style][digits]
comment|///   style             ::<see table below>
comment|///   digits            ::<non-negative integer> 0-99
comment|///
comment|///   ==========================================================================
comment|///   |  style  |     Meaning          |      Example     | Digits Meaning     |
comment|///   --------------------------------------------------------------------------
comment|///   |         |                      |  Input |  Output |                    |
comment|///   ==========================================================================
comment|///   |   x-    | Hex no prefix, lower |   42   |    2a   | Minimum # digits   |
comment|///   |   X-    | Hex no prefix, upper |   42   |    2A   | Minimum # digits   |
comment|///   | x+ / x  | Hex + prefix, lower  |   42   |   0x2a  | Minimum # digits   |
comment|///   | X+ / X  | Hex + prefix, upper  |   42   |   0x2A  | Minimum # digits   |
comment|///   | N / n   | Digit grouped number | 123456 | 123,456 | Ignored            |
comment|///   | D / d   | Integer              | 100000 | 100000  | Ignored            |
comment|///   | (empty) | Same as D / d        |        |         |                    |
comment|///   ==========================================================================
comment|///
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|format_provider
operator|<
name|T
operator|,
name|typename
name|std
operator|::
name|enable_if
operator|<
name|detail
operator|::
name|use_integral_formatter
operator|<
name|T
operator|>
operator|::
name|value
operator|>
operator|::
name|type
operator|>
operator|:
name|public
name|detail
operator|::
name|HelperFunctions
block|{
name|private
operator|:
name|public
operator|:
specifier|static
name|void
name|format
argument_list|(
argument|const T&V
argument_list|,
argument|llvm::raw_ostream&Stream
argument_list|,
argument|StringRef Style
argument_list|)
block|{
name|HexPrintStyle
name|HS
block|;
name|size_t
name|Digits
operator|=
literal|0
block|;
if|if
condition|(
name|consumeHexStyle
argument_list|(
name|Style
argument_list|,
name|HS
argument_list|)
condition|)
block|{
name|Digits
operator|=
name|consumeNumHexDigits
argument_list|(
name|Style
argument_list|,
name|HS
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|write_hex
argument_list|(
name|Stream
argument_list|,
name|V
argument_list|,
name|HS
argument_list|,
name|Digits
argument_list|)
expr_stmt|;
return|return;
block|}
name|IntegerStyle
name|IS
init|=
name|IntegerStyle
operator|::
name|Integer
decl_stmt|;
if|if
condition|(
name|Style
operator|.
name|consume_front
argument_list|(
literal|"N"
argument_list|)
operator|||
name|Style
operator|.
name|consume_front
argument_list|(
literal|"n"
argument_list|)
condition|)
name|IS
operator|=
name|IntegerStyle
operator|::
name|Number
expr_stmt|;
elseif|else
if|if
condition|(
name|Style
operator|.
name|consume_front
argument_list|(
literal|"D"
argument_list|)
operator|||
name|Style
operator|.
name|consume_front
argument_list|(
literal|"d"
argument_list|)
condition|)
name|IS
operator|=
name|IntegerStyle
operator|::
name|Integer
expr_stmt|;
name|Style
operator|.
name|consumeInteger
argument_list|(
literal|10
argument_list|,
name|Digits
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|Style
operator|.
name|empty
argument_list|()
operator|&&
literal|"Invalid integral format style!"
argument_list|)
expr_stmt|;
name|write_integer
argument_list|(
name|Stream
argument_list|,
name|V
argument_list|,
name|Digits
argument_list|,
name|IS
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
unit|};
comment|/// Implementation of format_provider<T> for integral pointer types.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The options string of a pointer type has the grammar:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   pointer_options   :: [style][precision]
end_comment

begin_comment
comment|///   style             ::<see table below>
end_comment

begin_comment
comment|///   digits            ::<non-negative integer> 0-sizeof(void*)
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   ==========================================================================
end_comment

begin_comment
comment|///   |   S     |     Meaning          |                Example                |
end_comment

begin_comment
comment|///   --------------------------------------------------------------------------
end_comment

begin_comment
comment|///   |         |                      |       Input       |      Output       |
end_comment

begin_comment
comment|///   ==========================================================================
end_comment

begin_comment
comment|///   |   x-    | Hex no prefix, lower |    0xDEADBEEF     |     deadbeef      |
end_comment

begin_comment
comment|///   |   X-    | Hex no prefix, upper |    0xDEADBEEF     |     DEADBEEF      |
end_comment

begin_comment
comment|///   | x+ / x  | Hex + prefix, lower  |    0xDEADBEEF     |    0xdeadbeef     |
end_comment

begin_comment
comment|///   | X+ / X  | Hex + prefix, upper  |    0xDEADBEEF     |    0xDEADBEEF     |
end_comment

begin_comment
comment|///   | (empty) | Same as X+ / X       |                   |                   |
end_comment

begin_comment
comment|///   ==========================================================================
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The default precision is the number of nibbles in a machine word, and in all
end_comment

begin_comment
comment|/// cases indicates the minimum number of nibbles to print.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|format_provider
operator|<
name|T
operator|,
name|typename
name|std
operator|::
name|enable_if
operator|<
name|detail
operator|::
name|use_pointer_formatter
operator|<
name|T
operator|>
operator|::
name|value
operator|>
operator|::
name|type
operator|>
operator|:
name|public
name|detail
operator|::
name|HelperFunctions
block|{
name|private
operator|:
name|public
operator|:
specifier|static
name|void
name|format
argument_list|(
argument|const T&V
argument_list|,
argument|llvm::raw_ostream&Stream
argument_list|,
argument|StringRef Style
argument_list|)
block|{
name|HexPrintStyle
name|HS
operator|=
name|HexPrintStyle
operator|::
name|PrefixUpper
block|;
name|consumeHexStyle
argument_list|(
name|Style
argument_list|,
name|HS
argument_list|)
block|;
name|size_t
name|Digits
operator|=
name|consumeNumHexDigits
argument_list|(
name|Style
argument_list|,
name|HS
argument_list|,
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
operator|*
literal|2
argument_list|)
block|;
name|write_hex
argument_list|(
name|Stream
argument_list|,
name|reinterpret_cast
operator|<
name|std
operator|::
name|uintptr_t
operator|>
operator|(
name|V
operator|)
argument_list|,
name|HS
argument_list|,
name|Digits
argument_list|)
block|;   }
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Implementation of format_provider<T> for c-style strings and string
end_comment

begin_comment
comment|/// objects such as std::string and llvm::StringRef.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The options string of a string type has the grammar:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   string_options :: [length]
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// where `length` is an optional integer specifying the maximum number of
end_comment

begin_comment
comment|/// characters in the string to print.  If `length` is omitted, the string is
end_comment

begin_comment
comment|/// printed up to the null terminator.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|format_provider
operator|<
name|T
operator|,
name|typename
name|std
operator|::
name|enable_if
operator|<
name|detail
operator|::
name|use_string_formatter
operator|<
name|T
operator|>
operator|::
name|value
operator|>
operator|::
name|type
operator|>
block|{
specifier|static
name|void
name|format
argument_list|(
argument|const T&V
argument_list|,
argument|llvm::raw_ostream&Stream
argument_list|,
argument|StringRef Style
argument_list|)
block|{
name|size_t
name|N
operator|=
name|StringRef
operator|::
name|npos
block|;
if|if
condition|(
operator|!
name|Style
operator|.
name|empty
argument_list|()
operator|&&
name|Style
operator|.
name|getAsInteger
argument_list|(
literal|10
argument_list|,
name|N
argument_list|)
condition|)
block|{
name|assert
argument_list|(
name|false
operator|&&
literal|"Style is not a valid integer"
argument_list|)
expr_stmt|;
block|}
name|llvm
operator|::
name|StringRef
name|S
operator|=
name|V
block|;
name|Stream
operator|<<
name|S
operator|.
name|substr
argument_list|(
literal|0
argument_list|,
name|N
argument_list|)
block|;   }
end_expr_stmt

begin_comment
unit|};
comment|/// Implementation of format_provider<T> for llvm::Twine.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This follows the same rules as the string formatter.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|format_provider
operator|<
name|Twine
operator|>
block|{
specifier|static
name|void
name|format
argument_list|(
argument|const Twine&V
argument_list|,
argument|llvm::raw_ostream&Stream
argument_list|,
argument|StringRef Style
argument_list|)
block|{
name|format_provider
operator|<
name|std
operator|::
name|string
operator|>
operator|::
name|format
argument_list|(
name|V
operator|.
name|str
argument_list|()
argument_list|,
name|Stream
argument_list|,
name|Style
argument_list|)
block|;   }
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Implementation of format_provider<T> for characters.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The options string of a character type has the grammar:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   char_options :: (empty) | [integer_options]
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If `char_options` is empty, the character is displayed as an ASCII
end_comment

begin_comment
comment|/// character.  Otherwise, it is treated as an integer options string.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|format_provider
operator|<
name|T
operator|,
name|typename
name|std
operator|::
name|enable_if
operator|<
name|detail
operator|::
name|use_char_formatter
operator|<
name|T
operator|>
operator|::
name|value
operator|>
operator|::
name|type
operator|>
block|{
specifier|static
name|void
name|format
argument_list|(
argument|const char&V
argument_list|,
argument|llvm::raw_ostream&Stream
argument_list|,
argument|StringRef Style
argument_list|)
block|{
if|if
condition|(
name|Style
operator|.
name|empty
argument_list|()
condition|)
name|Stream
operator|<<
name|V
expr_stmt|;
else|else
block|{
name|int
name|X
init|=
name|static_cast
operator|<
name|int
operator|>
operator|(
name|V
operator|)
decl_stmt|;
name|format_provider
operator|<
name|int
operator|>
operator|::
name|format
argument_list|(
name|X
argument_list|,
name|Stream
argument_list|,
name|Style
argument_list|)
expr_stmt|;
block|}
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// Implementation of format_provider<T> for type `bool`
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The options string of a boolean type has the grammar:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   bool_options :: "" | "Y" | "y" | "D" | "d" | "T" | "t"
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   ==================================
end_comment

begin_comment
comment|///   |    C    |     Meaning          |
end_comment

begin_comment
comment|///   ==================================
end_comment

begin_comment
comment|///   |    Y    |       YES / NO       |
end_comment

begin_comment
comment|///   |    y    |       yes / no       |
end_comment

begin_comment
comment|///   |  D / d  |    Integer 0 or 1    |
end_comment

begin_comment
comment|///   |    T    |     TRUE / FALSE     |
end_comment

begin_comment
comment|///   |    t    |     true / false     |
end_comment

begin_comment
comment|///   | (empty) |   Equivalent to 't'  |
end_comment

begin_comment
comment|///   ==================================
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|format_provider
operator|<
name|bool
operator|>
block|{
specifier|static
name|void
name|format
argument_list|(
argument|const bool&B
argument_list|,
argument|llvm::raw_ostream&Stream
argument_list|,
argument|StringRef Style
argument_list|)
block|{
name|Stream
operator|<<
name|StringSwitch
operator|<
specifier|const
name|char
operator|*
operator|>
operator|(
name|Style
operator|)
operator|.
name|Case
argument_list|(
literal|"Y"
argument_list|,
name|B
operator|?
literal|"YES"
operator|:
literal|"NO"
argument_list|)
operator|.
name|Case
argument_list|(
literal|"y"
argument_list|,
name|B
operator|?
literal|"yes"
operator|:
literal|"no"
argument_list|)
operator|.
name|CaseLower
argument_list|(
literal|"D"
argument_list|,
name|B
operator|?
literal|"1"
operator|:
literal|"0"
argument_list|)
operator|.
name|Case
argument_list|(
literal|"T"
argument_list|,
name|B
operator|?
literal|"TRUE"
operator|:
literal|"FALSE"
argument_list|)
operator|.
name|Cases
argument_list|(
literal|"t"
argument_list|,
literal|""
argument_list|,
name|B
operator|?
literal|"true"
operator|:
literal|"false"
argument_list|)
operator|.
name|Default
argument_list|(
name|B
operator|?
literal|"1"
operator|:
literal|"0"
argument_list|)
block|;   }
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Implementation of format_provider<T> for floating point types.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The options string of a floating point type has the format:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   float_options   :: [style][precision]
end_comment

begin_comment
comment|///   style           ::<see table below>
end_comment

begin_comment
comment|///   precision       ::<non-negative integer> 0-99
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   =====================================================
end_comment

begin_comment
comment|///   |  style  |     Meaning          |      Example     |
end_comment

begin_comment
comment|///   -----------------------------------------------------
end_comment

begin_comment
comment|///   |         |                      |  Input |  Output |
end_comment

begin_comment
comment|///   =====================================================
end_comment

begin_comment
comment|///   | P / p   | Percentage           |  0.05  |  5.00%  |
end_comment

begin_comment
comment|///   | F / f   | Fixed point          |   1.0  |  1.00   |
end_comment

begin_comment
comment|///   |   E     | Exponential with E   | 100000 | 1.0E+05 |
end_comment

begin_comment
comment|///   |   e     | Exponential with e   | 100000 | 1.0e+05 |
end_comment

begin_comment
comment|///   | (empty) | Same as F / f        |        |         |
end_comment

begin_comment
comment|///   =====================================================
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The default precision is 6 for exponential (E / e) and 2 for everything
end_comment

begin_comment
comment|/// else.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|format_provider
operator|<
name|T
operator|,
name|typename
name|std
operator|::
name|enable_if
operator|<
name|detail
operator|::
name|use_double_formatter
operator|<
name|T
operator|>
operator|::
name|value
operator|>
operator|::
name|type
operator|>
operator|:
name|public
name|detail
operator|::
name|HelperFunctions
block|{
specifier|static
name|void
name|format
argument_list|(
argument|const T&V
argument_list|,
argument|llvm::raw_ostream&Stream
argument_list|,
argument|StringRef Style
argument_list|)
block|{
name|FloatStyle
name|S
block|;
if|if
condition|(
name|Style
operator|.
name|consume_front
argument_list|(
literal|"P"
argument_list|)
operator|||
name|Style
operator|.
name|consume_front
argument_list|(
literal|"p"
argument_list|)
condition|)
name|S
operator|=
name|FloatStyle
operator|::
name|Percent
expr_stmt|;
elseif|else
if|if
condition|(
name|Style
operator|.
name|consume_front
argument_list|(
literal|"F"
argument_list|)
operator|||
name|Style
operator|.
name|consume_front
argument_list|(
literal|"f"
argument_list|)
condition|)
name|S
operator|=
name|FloatStyle
operator|::
name|Fixed
expr_stmt|;
elseif|else
if|if
condition|(
name|Style
operator|.
name|consume_front
argument_list|(
literal|"E"
argument_list|)
condition|)
name|S
operator|=
name|FloatStyle
operator|::
name|ExponentUpper
expr_stmt|;
elseif|else
if|if
condition|(
name|Style
operator|.
name|consume_front
argument_list|(
literal|"e"
argument_list|)
condition|)
name|S
operator|=
name|FloatStyle
operator|::
name|Exponent
expr_stmt|;
else|else
name|S
operator|=
name|FloatStyle
operator|::
name|Fixed
expr_stmt|;
name|Optional
operator|<
name|size_t
operator|>
name|Precision
operator|=
name|parseNumericPrecision
argument_list|(
name|Style
argument_list|)
block|;
if|if
condition|(
operator|!
name|Precision
operator|.
name|hasValue
argument_list|()
condition|)
name|Precision
operator|=
name|getDefaultPrecision
argument_list|(
name|S
argument_list|)
expr_stmt|;
name|write_double
argument_list|(
name|Stream
argument_list|,
name|static_cast
operator|<
name|double
operator|>
operator|(
name|V
operator|)
argument_list|,
name|S
argument_list|,
name|Precision
argument_list|)
expr_stmt|;
end_expr_stmt

begin_empty_stmt
unit|} }
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|namespace
name|detail
block|{
name|template
operator|<
name|typename
name|IterT
operator|>
name|using
name|IterValue
operator|=
name|typename
name|std
operator|::
name|iterator_traits
operator|<
name|IterT
operator|>
operator|::
name|value_type
expr_stmt|;
name|template
operator|<
name|typename
name|IterT
operator|>
expr|struct
name|range_item_has_provider
operator|:
name|public
name|std
operator|::
name|integral_constant
operator|<
name|bool
operator|,
operator|!
name|uses_missing_provider
operator|<
name|IterValue
operator|<
name|IterT
operator|>>
operator|::
name|value
operator|>
block|{}
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// Implementation of format_provider<T> for ranges.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This will print an arbitrary range as a delimited sequence of items.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The options string of a range type has the grammar:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   range_style       ::= [separator] [element_style]
end_comment

begin_comment
comment|///   separator         ::= "$" delimeted_expr
end_comment

begin_comment
comment|///   element_style     ::= "@" delimeted_expr
end_comment

begin_comment
comment|///   delimeted_expr    ::= "[" expr "]" | "(" expr ")" | "<" expr ">"
end_comment

begin_comment
comment|///   expr              ::=<any string not containing delimeter>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// where the separator expression is the string to insert between consecutive
end_comment

begin_comment
comment|/// items in the range and the argument expression is the Style specification to
end_comment

begin_comment
comment|/// be used when formatting the underlying type.  The default separator if
end_comment

begin_comment
comment|/// unspecified is ' ' (space).  The syntax of the argument expression follows
end_comment

begin_comment
comment|/// whatever grammar is dictated by the format provider or format adapter used
end_comment

begin_comment
comment|/// to format the value type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that attempting to format an `iterator_range<T>` where no format
end_comment

begin_comment
comment|/// provider can be found for T will result in a compile error.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|IterT
operator|>
name|class
name|format_provider
operator|<
name|llvm
operator|::
name|iterator_range
operator|<
name|IterT
operator|>>
block|{
name|using
name|value
operator|=
name|typename
name|std
operator|::
name|iterator_traits
operator|<
name|IterT
operator|>
operator|::
name|value_type
block|;
name|using
name|reference
operator|=
name|typename
name|std
operator|::
name|iterator_traits
operator|<
name|IterT
operator|>
operator|::
name|reference
block|;
specifier|static
name|StringRef
name|consumeOneOption
argument_list|(
argument|StringRef&Style
argument_list|,
argument|char Indicator
argument_list|,
argument|StringRef Default
argument_list|)
block|{
if|if
condition|(
name|Style
operator|.
name|empty
argument_list|()
condition|)
return|return
name|Default
return|;
if|if
condition|(
name|Style
operator|.
name|front
argument_list|()
operator|!=
name|Indicator
condition|)
return|return
name|Default
return|;
name|Style
operator|=
name|Style
operator|.
name|drop_front
argument_list|()
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|Style
operator|.
name|empty
argument_list|()
condition|)
block|{
name|assert
argument_list|(
name|false
operator|&&
literal|"Invalid range style"
argument_list|)
expr_stmt|;
return|return
name|Default
return|;
block|}
end_if

begin_for
for|for
control|(
specifier|const
name|char
modifier|*
name|D
range|:
block|{
literal|"[]"
block|,
literal|"<>"
block|,
literal|"()"
block|}
control|)
block|{
if|if
condition|(
name|Style
operator|.
name|front
argument_list|()
operator|!=
name|D
index|[
literal|0
index|]
condition|)
continue|continue;
name|size_t
name|End
init|=
name|Style
operator|.
name|find_first_of
argument_list|(
name|D
index|[
literal|1
index|]
argument_list|)
decl_stmt|;
if|if
condition|(
name|End
operator|==
name|StringRef
operator|::
name|npos
condition|)
block|{
name|assert
argument_list|(
name|false
operator|&&
literal|"Missing range option end delimeter!"
argument_list|)
expr_stmt|;
return|return
name|Default
return|;
block|}
name|StringRef
name|Result
init|=
name|Style
operator|.
name|slice
argument_list|(
literal|1
argument_list|,
name|End
argument_list|)
decl_stmt|;
name|Style
operator|=
name|Style
operator|.
name|drop_front
argument_list|(
name|End
operator|+
literal|1
argument_list|)
expr_stmt|;
return|return
name|Result
return|;
block|}
end_for

begin_expr_stmt
name|assert
argument_list|(
name|false
operator|&&
literal|"Invalid range style!"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|Default
return|;
end_return

begin_expr_stmt
unit|}    static
name|std
operator|::
name|pair
operator|<
name|StringRef
operator|,
name|StringRef
operator|>
name|parseOptions
argument_list|(
argument|StringRef Style
argument_list|)
block|{
name|StringRef
name|Sep
operator|=
name|consumeOneOption
argument_list|(
name|Style
argument_list|,
literal|'$'
argument_list|,
literal|", "
argument_list|)
block|;
name|StringRef
name|Args
operator|=
name|consumeOneOption
argument_list|(
name|Style
argument_list|,
literal|'@'
argument_list|,
literal|""
argument_list|)
block|;
name|assert
argument_list|(
name|Style
operator|.
name|empty
argument_list|()
operator|&&
literal|"Unexpected text in range option string!"
argument_list|)
block|;
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|Sep
argument_list|,
name|Args
argument_list|)
return|;
block|}
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_expr_stmt
name|static_assert
argument_list|(
name|detail
operator|::
name|range_item_has_provider
operator|<
name|IterT
operator|>
operator|::
name|value
argument_list|,
literal|"Range value_type does not have a format provider!"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|void
name|format
argument_list|(
specifier|const
name|llvm
operator|::
name|iterator_range
operator|<
name|IterT
operator|>
operator|&
name|V
argument_list|,
name|llvm
operator|::
name|raw_ostream
operator|&
name|Stream
argument_list|,
name|StringRef
name|Style
argument_list|)
block|{
name|StringRef
name|Sep
decl_stmt|;
name|StringRef
name|ArgStyle
decl_stmt|;
name|std
operator|::
name|tie
argument_list|(
name|Sep
argument_list|,
name|ArgStyle
argument_list|)
operator|=
name|parseOptions
argument_list|(
name|Style
argument_list|)
expr_stmt|;
name|auto
name|Begin
init|=
name|V
operator|.
name|begin
argument_list|()
decl_stmt|;
name|auto
name|End
init|=
name|V
operator|.
name|end
argument_list|()
decl_stmt|;
if|if
condition|(
name|Begin
operator|!=
name|End
condition|)
block|{
name|auto
name|Adapter
init|=
name|detail
operator|::
name|build_format_adapter
argument_list|(
name|std
operator|::
name|forward
operator|<
name|reference
operator|>
operator|(
operator|*
name|Begin
operator|)
argument_list|)
decl_stmt|;
name|Adapter
operator|.
name|format
argument_list|(
name|Stream
argument_list|,
name|ArgStyle
argument_list|)
expr_stmt|;
operator|++
name|Begin
expr_stmt|;
block|}
while|while
condition|(
name|Begin
operator|!=
name|End
condition|)
block|{
name|Stream
operator|<<
name|Sep
expr_stmt|;
name|auto
name|Adapter
init|=
name|detail
operator|::
name|build_format_adapter
argument_list|(
name|std
operator|::
name|forward
operator|<
name|reference
operator|>
operator|(
operator|*
name|Begin
operator|)
argument_list|)
decl_stmt|;
name|Adapter
operator|.
name|format
argument_list|(
name|Stream
argument_list|,
name|ArgStyle
argument_list|)
expr_stmt|;
operator|++
name|Begin
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
unit|}; }
endif|#
directive|endif
end_endif

end_unit

