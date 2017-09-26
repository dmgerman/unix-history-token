begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Format.h - Efficient printf-style formatting for streams -*- C++ -*-===//
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
comment|// This file implements the format() function, which can be used with other
end_comment

begin_comment
comment|// LLVM subsystems to provide printf-style formatting.  This gives all the power
end_comment

begin_comment
comment|// and risk of printf.  This can be used like this (with raw_ostreams as an
end_comment

begin_comment
comment|// example):
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    OS<< "mynumber: "<< format("%4.5f", 1234.412)<< '\n';
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Or if you prefer:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  OS<< format("mynumber: %4.5f\n", 1234.412);
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
name|LLVM_SUPPORT_FORMAT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_FORMAT_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
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

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstdio>
end_include

begin_include
include|#
directive|include
file|<tuple>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// This is a helper class used for handling formatted output.  It is the
comment|/// abstract base class of a templated derived class.
name|class
name|format_object_base
block|{
name|protected
label|:
specifier|const
name|char
modifier|*
name|Fmt
decl_stmt|;
operator|~
name|format_object_base
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|// Disallow polymorphic deletion.
name|format_object_base
argument_list|(
specifier|const
name|format_object_base
operator|&
argument_list|)
operator|=
expr|default
expr_stmt|;
name|virtual
name|void
name|home
parameter_list|()
function_decl|;
comment|// Out of line virtual method.
comment|/// Call snprintf() for this object, on the given buffer and size.
name|virtual
name|int
name|snprint
argument_list|(
name|char
operator|*
name|Buffer
argument_list|,
name|unsigned
name|BufferSize
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|public
label|:
name|format_object_base
argument_list|(
specifier|const
name|char
operator|*
name|fmt
argument_list|)
operator|:
name|Fmt
argument_list|(
argument|fmt
argument_list|)
block|{}
comment|/// Format the object into the specified buffer.  On success, this returns
comment|/// the length of the formatted string.  If the buffer is too small, this
comment|/// returns a length to retry with, which will be larger than BufferSize.
name|unsigned
name|print
argument_list|(
argument|char *Buffer
argument_list|,
argument|unsigned BufferSize
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|BufferSize
operator|&&
literal|"Invalid buffer size!"
argument_list|)
block|;
comment|// Print the string, leaving room for the terminating null.
name|int
name|N
operator|=
name|snprint
argument_list|(
name|Buffer
argument_list|,
name|BufferSize
argument_list|)
block|;
comment|// VC++ and old GlibC return negative on overflow, just double the size.
if|if
condition|(
name|N
operator|<
literal|0
condition|)
return|return
name|BufferSize
operator|*
literal|2
return|;
comment|// Other implementations yield number of bytes needed, not including the
comment|// final '\0'.
if|if
condition|(
name|unsigned
argument_list|(
name|N
argument_list|)
operator|>=
name|BufferSize
condition|)
return|return
name|N
operator|+
literal|1
return|;
comment|// Otherwise N is the length of output (not including the final '\0').
return|return
name|N
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// These are templated helper classes used by the format function that
end_comment

begin_comment
comment|/// capture the object to be formatted and the format string. When actually
end_comment

begin_comment
comment|/// printed, this synthesizes the string into a temporary buffer provided and
end_comment

begin_comment
comment|/// returns whether or not it is big enough.
end_comment

begin_comment
comment|// Helper to validate that format() parameters are scalars or pointers.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
operator|...
name|Args
operator|>
expr|struct
name|validate_format_parameters
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|Arg
operator|,
name|typename
operator|...
name|Args
operator|>
expr|struct
name|validate_format_parameters
operator|<
name|Arg
operator|,
name|Args
operator|...
operator|>
block|{
name|static_assert
argument_list|(
name|std
operator|::
name|is_scalar
operator|<
name|Arg
operator|>
operator|::
name|value
argument_list|,
literal|"format can't be used with non fundamental / non pointer type"
argument_list|)
block|;
name|validate_format_parameters
argument_list|()
block|{
name|validate_format_parameters
operator|<
name|Args
operator|...
operator|>
operator|(
operator|)
block|; }
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|validate_format_parameters
operator|<
operator|>
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
operator|...
name|Ts
operator|>
name|class
name|format_object
name|final
operator|:
name|public
name|format_object_base
block|{
name|std
operator|::
name|tuple
operator|<
name|Ts
operator|...
operator|>
name|Vals
block|;
name|template
operator|<
name|std
operator|::
name|size_t
operator|...
name|Is
operator|>
name|int
name|snprint_tuple
argument_list|(
argument|char *Buffer
argument_list|,
argument|unsigned BufferSize
argument_list|,
argument|index_sequence<Is...>
argument_list|)
specifier|const
block|{
ifdef|#
directive|ifdef
name|_MSC_VER
return|return
name|_snprintf
argument_list|(
name|Buffer
argument_list|,
name|BufferSize
argument_list|,
name|Fmt
argument_list|,
name|std
operator|::
name|get
operator|<
name|Is
operator|>
operator|(
name|Vals
operator|)
operator|...
argument_list|)
return|;
else|#
directive|else
return|return
name|snprintf
argument_list|(
name|Buffer
argument_list|,
name|BufferSize
argument_list|,
name|Fmt
argument_list|,
name|std
operator|::
name|get
operator|<
name|Is
operator|>
operator|(
name|Vals
operator|)
operator|...
argument_list|)
return|;
endif|#
directive|endif
block|}
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_expr_stmt
name|format_object
argument_list|(
specifier|const
name|char
operator|*
name|fmt
argument_list|,
specifier|const
name|Ts
operator|&
operator|...
name|vals
argument_list|)
operator|:
name|format_object_base
argument_list|(
name|fmt
argument_list|)
operator|,
name|Vals
argument_list|(
argument|vals...
argument_list|)
block|{
name|validate_format_parameters
operator|<
name|Ts
operator|...
operator|>
operator|(
operator|)
block|;   }
name|int
name|snprint
argument_list|(
argument|char *Buffer
argument_list|,
argument|unsigned BufferSize
argument_list|)
specifier|const
name|override
block|{
return|return
name|snprint_tuple
argument_list|(
name|Buffer
argument_list|,
name|BufferSize
argument_list|,
name|index_sequence_for
operator|<
name|Ts
operator|...
operator|>
operator|(
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// These are helper functions used to produce formatted output.  They use
end_comment

begin_comment
comment|/// template type deduction to construct the appropriate instance of the
end_comment

begin_comment
comment|/// format_object class to simplify their construction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is typically used like:
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|///   OS<< format("%0.4f", myfloat)<< '\n';
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
operator|...
name|Ts
operator|>
specifier|inline
name|format_object
operator|<
name|Ts
operator|...
operator|>
name|format
argument_list|(
argument|const char *Fmt
argument_list|,
argument|const Ts&... Vals
argument_list|)
block|{
return|return
name|format_object
operator|<
name|Ts
operator|...
operator|>
operator|(
name|Fmt
operator|,
name|Vals
operator|...
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// This is a helper class for left_justify, right_justify, and center_justify.
end_comment

begin_decl_stmt
name|class
name|FormattedString
block|{
name|public
label|:
enum|enum
name|Justification
block|{
name|JustifyNone
block|,
name|JustifyLeft
block|,
name|JustifyRight
block|,
name|JustifyCenter
block|}
enum|;
name|FormattedString
argument_list|(
argument|StringRef S
argument_list|,
argument|unsigned W
argument_list|,
argument|Justification J
argument_list|)
block|:
name|Str
argument_list|(
name|S
argument_list|)
operator|,
name|Width
argument_list|(
name|W
argument_list|)
operator|,
name|Justify
argument_list|(
argument|J
argument_list|)
block|{}
name|private
operator|:
name|StringRef
name|Str
expr_stmt|;
name|unsigned
name|Width
decl_stmt|;
name|Justification
name|Justify
decl_stmt|;
name|friend
name|class
name|raw_ostream
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// left_justify - append spaces after string so total output is
end_comment

begin_comment
comment|/// \p Width characters.  If \p Str is larger that \p Width, full string
end_comment

begin_comment
comment|/// is written with no padding.
end_comment

begin_function
specifier|inline
name|FormattedString
name|left_justify
parameter_list|(
name|StringRef
name|Str
parameter_list|,
name|unsigned
name|Width
parameter_list|)
block|{
return|return
name|FormattedString
argument_list|(
name|Str
argument_list|,
name|Width
argument_list|,
name|FormattedString
operator|::
name|JustifyLeft
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// right_justify - add spaces before string so total output is
end_comment

begin_comment
comment|/// \p Width characters.  If \p Str is larger that \p Width, full string
end_comment

begin_comment
comment|/// is written with no padding.
end_comment

begin_function
specifier|inline
name|FormattedString
name|right_justify
parameter_list|(
name|StringRef
name|Str
parameter_list|,
name|unsigned
name|Width
parameter_list|)
block|{
return|return
name|FormattedString
argument_list|(
name|Str
argument_list|,
name|Width
argument_list|,
name|FormattedString
operator|::
name|JustifyRight
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// center_justify - add spaces before and after string so total output is
end_comment

begin_comment
comment|/// \p Width characters.  If \p Str is larger that \p Width, full string
end_comment

begin_comment
comment|/// is written with no padding.
end_comment

begin_function
specifier|inline
name|FormattedString
name|center_justify
parameter_list|(
name|StringRef
name|Str
parameter_list|,
name|unsigned
name|Width
parameter_list|)
block|{
return|return
name|FormattedString
argument_list|(
name|Str
argument_list|,
name|Width
argument_list|,
name|FormattedString
operator|::
name|JustifyCenter
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// This is a helper class used for format_hex() and format_decimal().
end_comment

begin_decl_stmt
name|class
name|FormattedNumber
block|{
name|uint64_t
name|HexValue
decl_stmt|;
name|int64_t
name|DecValue
decl_stmt|;
name|unsigned
name|Width
decl_stmt|;
name|bool
name|Hex
decl_stmt|;
name|bool
name|Upper
decl_stmt|;
name|bool
name|HexPrefix
decl_stmt|;
name|friend
name|class
name|raw_ostream
decl_stmt|;
name|public
label|:
name|FormattedNumber
argument_list|(
argument|uint64_t HV
argument_list|,
argument|int64_t DV
argument_list|,
argument|unsigned W
argument_list|,
argument|bool H
argument_list|,
argument|bool U
argument_list|,
argument|bool Prefix
argument_list|)
block|:
name|HexValue
argument_list|(
name|HV
argument_list|)
operator|,
name|DecValue
argument_list|(
name|DV
argument_list|)
operator|,
name|Width
argument_list|(
name|W
argument_list|)
operator|,
name|Hex
argument_list|(
name|H
argument_list|)
operator|,
name|Upper
argument_list|(
name|U
argument_list|)
operator|,
name|HexPrefix
argument_list|(
argument|Prefix
argument_list|)
block|{}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// format_hex - Output \p N as a fixed width hexadecimal. If number will not
end_comment

begin_comment
comment|/// fit in width, full number is still printed.  Examples:
end_comment

begin_comment
comment|///   OS<< format_hex(255, 4)              => 0xff
end_comment

begin_comment
comment|///   OS<< format_hex(255, 4, true)        => 0xFF
end_comment

begin_comment
comment|///   OS<< format_hex(255, 6)              => 0x00ff
end_comment

begin_comment
comment|///   OS<< format_hex(255, 2)              => 0xff
end_comment

begin_function
specifier|inline
name|FormattedNumber
name|format_hex
parameter_list|(
name|uint64_t
name|N
parameter_list|,
name|unsigned
name|Width
parameter_list|,
name|bool
name|Upper
init|=
name|false
parameter_list|)
block|{
name|assert
argument_list|(
name|Width
operator|<=
literal|18
operator|&&
literal|"hex width must be<= 18"
argument_list|)
expr_stmt|;
return|return
name|FormattedNumber
argument_list|(
name|N
argument_list|,
literal|0
argument_list|,
name|Width
argument_list|,
name|true
argument_list|,
name|Upper
argument_list|,
name|true
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// format_hex_no_prefix - Output \p N as a fixed width hexadecimal. Does not
end_comment

begin_comment
comment|/// prepend '0x' to the outputted string.  If number will not fit in width,
end_comment

begin_comment
comment|/// full number is still printed.  Examples:
end_comment

begin_comment
comment|///   OS<< format_hex_no_prefix(255, 2)              => ff
end_comment

begin_comment
comment|///   OS<< format_hex_no_prefix(255, 2, true)        => FF
end_comment

begin_comment
comment|///   OS<< format_hex_no_prefix(255, 4)              => 00ff
end_comment

begin_comment
comment|///   OS<< format_hex_no_prefix(255, 1)              => ff
end_comment

begin_function
specifier|inline
name|FormattedNumber
name|format_hex_no_prefix
parameter_list|(
name|uint64_t
name|N
parameter_list|,
name|unsigned
name|Width
parameter_list|,
name|bool
name|Upper
init|=
name|false
parameter_list|)
block|{
name|assert
argument_list|(
name|Width
operator|<=
literal|16
operator|&&
literal|"hex width must be<= 16"
argument_list|)
expr_stmt|;
return|return
name|FormattedNumber
argument_list|(
name|N
argument_list|,
literal|0
argument_list|,
name|Width
argument_list|,
name|true
argument_list|,
name|Upper
argument_list|,
name|false
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// format_decimal - Output \p N as a right justified, fixed-width decimal. If
end_comment

begin_comment
comment|/// number will not fit in width, full number is still printed.  Examples:
end_comment

begin_comment
comment|///   OS<< format_decimal(0, 5)     => "    0"
end_comment

begin_comment
comment|///   OS<< format_decimal(255, 5)   => "  255"
end_comment

begin_comment
comment|///   OS<< format_decimal(-1, 3)    => " -1"
end_comment

begin_comment
comment|///   OS<< format_decimal(12345, 3) => "12345"
end_comment

begin_function
specifier|inline
name|FormattedNumber
name|format_decimal
parameter_list|(
name|int64_t
name|N
parameter_list|,
name|unsigned
name|Width
parameter_list|)
block|{
return|return
name|FormattedNumber
argument_list|(
literal|0
argument_list|,
name|N
argument_list|,
name|Width
argument_list|,
name|false
argument_list|,
name|false
argument_list|,
name|false
argument_list|)
return|;
block|}
end_function

begin_decl_stmt
name|class
name|FormattedBytes
block|{
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Bytes
expr_stmt|;
comment|// If not None, display offsets for each line relative to starting value.
name|Optional
operator|<
name|uint64_t
operator|>
name|FirstByteOffset
expr_stmt|;
name|uint32_t
name|IndentLevel
decl_stmt|;
comment|// Number of characters to indent each line.
name|uint32_t
name|NumPerLine
decl_stmt|;
comment|// Number of bytes to show per line.
name|uint8_t
name|ByteGroupSize
decl_stmt|;
comment|// How many hex bytes are grouped without spaces
name|bool
name|Upper
decl_stmt|;
comment|// Show offset and hex bytes as upper case.
name|bool
name|ASCII
decl_stmt|;
comment|// Show the ASCII bytes for the hex bytes to the right.
name|friend
name|class
name|raw_ostream
decl_stmt|;
name|public
label|:
name|FormattedBytes
argument_list|(
argument|ArrayRef<uint8_t> B
argument_list|,
argument|uint32_t IL
argument_list|,
argument|Optional<uint64_t> O
argument_list|,
argument|uint32_t NPL
argument_list|,
argument|uint8_t BGS
argument_list|,
argument|bool U
argument_list|,
argument|bool A
argument_list|)
block|:
name|Bytes
argument_list|(
name|B
argument_list|)
operator|,
name|FirstByteOffset
argument_list|(
name|O
argument_list|)
operator|,
name|IndentLevel
argument_list|(
name|IL
argument_list|)
operator|,
name|NumPerLine
argument_list|(
name|NPL
argument_list|)
operator|,
name|ByteGroupSize
argument_list|(
name|BGS
argument_list|)
operator|,
name|Upper
argument_list|(
name|U
argument_list|)
operator|,
name|ASCII
argument_list|(
argument|A
argument_list|)
block|{
if|if
condition|(
name|ByteGroupSize
operator|>
name|NumPerLine
condition|)
name|ByteGroupSize
operator|=
name|NumPerLine
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
specifier|inline
name|FormattedBytes
name|format_bytes
argument_list|(
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Bytes
argument_list|,
name|Optional
operator|<
name|uint64_t
operator|>
name|FirstByteOffset
operator|=
name|None
argument_list|,
name|uint32_t
name|NumPerLine
operator|=
literal|16
argument_list|,
name|uint8_t
name|ByteGroupSize
operator|=
literal|4
argument_list|,
name|uint32_t
name|IndentLevel
operator|=
literal|0
argument_list|,
name|bool
name|Upper
operator|=
name|false
argument_list|)
block|{
return|return
name|FormattedBytes
argument_list|(
name|Bytes
argument_list|,
name|IndentLevel
argument_list|,
name|FirstByteOffset
argument_list|,
name|NumPerLine
argument_list|,
name|ByteGroupSize
argument_list|,
name|Upper
argument_list|,
name|false
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|inline
name|FormattedBytes
name|format_bytes_with_ascii
argument_list|(
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Bytes
argument_list|,
name|Optional
operator|<
name|uint64_t
operator|>
name|FirstByteOffset
operator|=
name|None
argument_list|,
name|uint32_t
name|NumPerLine
operator|=
literal|16
argument_list|,
name|uint8_t
name|ByteGroupSize
operator|=
literal|4
argument_list|,
name|uint32_t
name|IndentLevel
operator|=
literal|0
argument_list|,
name|bool
name|Upper
operator|=
name|false
argument_list|)
block|{
return|return
name|FormattedBytes
argument_list|(
name|Bytes
argument_list|,
name|IndentLevel
argument_list|,
name|FirstByteOffset
argument_list|,
name|NumPerLine
argument_list|,
name|ByteGroupSize
argument_list|,
name|Upper
argument_list|,
name|true
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

