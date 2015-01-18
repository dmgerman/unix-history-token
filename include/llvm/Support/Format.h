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

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_comment
comment|// FIXME: This define is wrong:
end_comment

begin_comment
comment|//  - _snprintf does not guarantee that trailing null is always added - if
end_comment

begin_comment
comment|//    there is no space for null, it does not report any error.
end_comment

begin_comment
comment|//  - According to C++ standard, snprintf should be visible in the 'std'
end_comment

begin_comment
comment|//    namespace - this define makes this impossible.
end_comment

begin_define
define|#
directive|define
name|snprintf
value|_snprintf
end_define

begin_endif
endif|#
directive|endif
end_endif

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
block|{}
comment|// Disallow polymorphic deletion.
name|virtual
name|void
name|home
argument_list|()
expr_stmt|;
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
comment|/// capture the object to be formated and the format string. When actually
end_comment

begin_comment
comment|/// printed, this synthesizes the string into a temporary buffer provided and
end_comment

begin_comment
comment|/// returns whether or not it is big enough.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|format_object1
name|final
operator|:
name|public
name|format_object_base
block|{
name|T
name|Val
block|;
name|public
operator|:
name|format_object1
argument_list|(
specifier|const
name|char
operator|*
name|fmt
argument_list|,
specifier|const
name|T
operator|&
name|val
argument_list|)
operator|:
name|format_object_base
argument_list|(
name|fmt
argument_list|)
block|,
name|Val
argument_list|(
argument|val
argument_list|)
block|{   }
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
name|snprintf
argument_list|(
name|Buffer
argument_list|,
name|BufferSize
argument_list|,
name|Fmt
argument_list|,
name|Val
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|>
name|class
name|format_object2
name|final
operator|:
name|public
name|format_object_base
block|{
name|T1
name|Val1
block|;
name|T2
name|Val2
block|;
name|public
operator|:
name|format_object2
argument_list|(
specifier|const
name|char
operator|*
name|fmt
argument_list|,
specifier|const
name|T1
operator|&
name|val1
argument_list|,
specifier|const
name|T2
operator|&
name|val2
argument_list|)
operator|:
name|format_object_base
argument_list|(
name|fmt
argument_list|)
block|,
name|Val1
argument_list|(
name|val1
argument_list|)
block|,
name|Val2
argument_list|(
argument|val2
argument_list|)
block|{   }
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
name|snprintf
argument_list|(
name|Buffer
argument_list|,
name|BufferSize
argument_list|,
name|Fmt
argument_list|,
name|Val1
argument_list|,
name|Val2
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|,
name|typename
name|T3
operator|>
name|class
name|format_object3
name|final
operator|:
name|public
name|format_object_base
block|{
name|T1
name|Val1
block|;
name|T2
name|Val2
block|;
name|T3
name|Val3
block|;
name|public
operator|:
name|format_object3
argument_list|(
specifier|const
name|char
operator|*
name|fmt
argument_list|,
specifier|const
name|T1
operator|&
name|val1
argument_list|,
specifier|const
name|T2
operator|&
name|val2
argument_list|,
specifier|const
name|T3
operator|&
name|val3
argument_list|)
operator|:
name|format_object_base
argument_list|(
name|fmt
argument_list|)
block|,
name|Val1
argument_list|(
name|val1
argument_list|)
block|,
name|Val2
argument_list|(
name|val2
argument_list|)
block|,
name|Val3
argument_list|(
argument|val3
argument_list|)
block|{   }
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
name|snprintf
argument_list|(
name|Buffer
argument_list|,
name|BufferSize
argument_list|,
name|Fmt
argument_list|,
name|Val1
argument_list|,
name|Val2
argument_list|,
name|Val3
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|,
name|typename
name|T3
operator|,
name|typename
name|T4
operator|>
name|class
name|format_object4
name|final
operator|:
name|public
name|format_object_base
block|{
name|T1
name|Val1
block|;
name|T2
name|Val2
block|;
name|T3
name|Val3
block|;
name|T4
name|Val4
block|;
name|public
operator|:
name|format_object4
argument_list|(
specifier|const
name|char
operator|*
name|fmt
argument_list|,
specifier|const
name|T1
operator|&
name|val1
argument_list|,
specifier|const
name|T2
operator|&
name|val2
argument_list|,
specifier|const
name|T3
operator|&
name|val3
argument_list|,
specifier|const
name|T4
operator|&
name|val4
argument_list|)
operator|:
name|format_object_base
argument_list|(
name|fmt
argument_list|)
block|,
name|Val1
argument_list|(
name|val1
argument_list|)
block|,
name|Val2
argument_list|(
name|val2
argument_list|)
block|,
name|Val3
argument_list|(
name|val3
argument_list|)
block|,
name|Val4
argument_list|(
argument|val4
argument_list|)
block|{   }
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
name|snprintf
argument_list|(
name|Buffer
argument_list|,
name|BufferSize
argument_list|,
name|Fmt
argument_list|,
name|Val1
argument_list|,
name|Val2
argument_list|,
name|Val3
argument_list|,
name|Val4
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|,
name|typename
name|T3
operator|,
name|typename
name|T4
operator|,
name|typename
name|T5
operator|>
name|class
name|format_object5
name|final
operator|:
name|public
name|format_object_base
block|{
name|T1
name|Val1
block|;
name|T2
name|Val2
block|;
name|T3
name|Val3
block|;
name|T4
name|Val4
block|;
name|T5
name|Val5
block|;
name|public
operator|:
name|format_object5
argument_list|(
specifier|const
name|char
operator|*
name|fmt
argument_list|,
specifier|const
name|T1
operator|&
name|val1
argument_list|,
specifier|const
name|T2
operator|&
name|val2
argument_list|,
specifier|const
name|T3
operator|&
name|val3
argument_list|,
specifier|const
name|T4
operator|&
name|val4
argument_list|,
specifier|const
name|T5
operator|&
name|val5
argument_list|)
operator|:
name|format_object_base
argument_list|(
name|fmt
argument_list|)
block|,
name|Val1
argument_list|(
name|val1
argument_list|)
block|,
name|Val2
argument_list|(
name|val2
argument_list|)
block|,
name|Val3
argument_list|(
name|val3
argument_list|)
block|,
name|Val4
argument_list|(
name|val4
argument_list|)
block|,
name|Val5
argument_list|(
argument|val5
argument_list|)
block|{   }
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
name|snprintf
argument_list|(
name|Buffer
argument_list|,
name|BufferSize
argument_list|,
name|Fmt
argument_list|,
name|Val1
argument_list|,
name|Val2
argument_list|,
name|Val3
argument_list|,
name|Val4
argument_list|,
name|Val5
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|,
name|typename
name|T3
operator|,
name|typename
name|T4
operator|,
name|typename
name|T5
operator|,
name|typename
name|T6
operator|>
name|class
name|format_object6
name|final
operator|:
name|public
name|format_object_base
block|{
name|T1
name|Val1
block|;
name|T2
name|Val2
block|;
name|T3
name|Val3
block|;
name|T4
name|Val4
block|;
name|T5
name|Val5
block|;
name|T6
name|Val6
block|;
name|public
operator|:
name|format_object6
argument_list|(
specifier|const
name|char
operator|*
name|Fmt
argument_list|,
specifier|const
name|T1
operator|&
name|Val1
argument_list|,
specifier|const
name|T2
operator|&
name|Val2
argument_list|,
specifier|const
name|T3
operator|&
name|Val3
argument_list|,
specifier|const
name|T4
operator|&
name|Val4
argument_list|,
specifier|const
name|T5
operator|&
name|Val5
argument_list|,
specifier|const
name|T6
operator|&
name|Val6
argument_list|)
operator|:
name|format_object_base
argument_list|(
name|Fmt
argument_list|)
block|,
name|Val1
argument_list|(
name|Val1
argument_list|)
block|,
name|Val2
argument_list|(
name|Val2
argument_list|)
block|,
name|Val3
argument_list|(
name|Val3
argument_list|)
block|,
name|Val4
argument_list|(
name|Val4
argument_list|)
block|,
name|Val5
argument_list|(
name|Val5
argument_list|)
block|,
name|Val6
argument_list|(
argument|Val6
argument_list|)
block|{ }
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
name|snprintf
argument_list|(
name|Buffer
argument_list|,
name|BufferSize
argument_list|,
name|Fmt
argument_list|,
name|Val1
argument_list|,
name|Val2
argument_list|,
name|Val3
argument_list|,
name|Val4
argument_list|,
name|Val5
argument_list|,
name|Val6
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
name|T
operator|>
specifier|inline
name|format_object1
operator|<
name|T
operator|>
name|format
argument_list|(
argument|const char *Fmt
argument_list|,
argument|const T&Val
argument_list|)
block|{
return|return
name|format_object1
operator|<
name|T
operator|>
operator|(
name|Fmt
operator|,
name|Val
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|>
specifier|inline
name|format_object2
operator|<
name|T1
operator|,
name|T2
operator|>
name|format
argument_list|(
argument|const char *Fmt
argument_list|,
argument|const T1&Val1
argument_list|,
argument|const T2&Val2
argument_list|)
block|{
return|return
name|format_object2
operator|<
name|T1
operator|,
name|T2
operator|>
operator|(
name|Fmt
operator|,
name|Val1
operator|,
name|Val2
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|,
name|typename
name|T3
operator|>
specifier|inline
name|format_object3
operator|<
name|T1
operator|,
name|T2
operator|,
name|T3
operator|>
name|format
argument_list|(
argument|const char *Fmt
argument_list|,
argument|const T1&Val1
argument_list|,
argument|const T2&Val2
argument_list|,
argument|const T3&Val3
argument_list|)
block|{
return|return
name|format_object3
operator|<
name|T1
operator|,
name|T2
operator|,
name|T3
operator|>
operator|(
name|Fmt
operator|,
name|Val1
operator|,
name|Val2
operator|,
name|Val3
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|,
name|typename
name|T3
operator|,
name|typename
name|T4
operator|>
specifier|inline
name|format_object4
operator|<
name|T1
operator|,
name|T2
operator|,
name|T3
operator|,
name|T4
operator|>
name|format
argument_list|(
argument|const char *Fmt
argument_list|,
argument|const T1&Val1
argument_list|,
argument|const T2&Val2
argument_list|,
argument|const T3&Val3
argument_list|,
argument|const T4&Val4
argument_list|)
block|{
return|return
name|format_object4
operator|<
name|T1
operator|,
name|T2
operator|,
name|T3
operator|,
name|T4
operator|>
operator|(
name|Fmt
operator|,
name|Val1
operator|,
name|Val2
operator|,
name|Val3
operator|,
name|Val4
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|,
name|typename
name|T3
operator|,
name|typename
name|T4
operator|,
name|typename
name|T5
operator|>
specifier|inline
name|format_object5
operator|<
name|T1
operator|,
name|T2
operator|,
name|T3
operator|,
name|T4
operator|,
name|T5
operator|>
name|format
argument_list|(
argument|const char *Fmt
argument_list|,
argument|const T1&Val1
argument_list|,
argument|const T2&Val2
argument_list|,
argument|const T3&Val3
argument_list|,
argument|const T4&Val4
argument_list|,
argument|const T5&Val5
argument_list|)
block|{
return|return
name|format_object5
operator|<
name|T1
operator|,
name|T2
operator|,
name|T3
operator|,
name|T4
operator|,
name|T5
operator|>
operator|(
name|Fmt
operator|,
name|Val1
operator|,
name|Val2
operator|,
name|Val3
operator|,
name|Val4
operator|,
name|Val5
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|,
name|typename
name|T3
operator|,
name|typename
name|T4
operator|,
name|typename
name|T5
operator|,
name|typename
name|T6
operator|>
specifier|inline
name|format_object6
operator|<
name|T1
operator|,
name|T2
operator|,
name|T3
operator|,
name|T4
operator|,
name|T5
operator|,
name|T6
operator|>
name|format
argument_list|(
argument|const char *Fmt
argument_list|,
argument|const T1&Val1
argument_list|,
argument|const T2&Val2
argument_list|,
argument|const T3&Val3
argument_list|,
argument|const T4&Val4
argument_list|,
argument|const T5&Val5
argument_list|,
argument|const T6&Val6
argument_list|)
block|{
return|return
name|format_object6
operator|<
name|T1
operator|,
name|T2
operator|,
name|T3
operator|,
name|T4
operator|,
name|T5
operator|,
name|T6
operator|>
operator|(
name|Fmt
operator|,
name|Val1
operator|,
name|Val2
operator|,
name|Val3
operator|,
name|Val4
operator|,
name|Val5
operator|,
name|Val6
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// This is a helper class used for left_justify() and right_justify().
end_comment

begin_decl_stmt
name|class
name|FormattedString
block|{
name|StringRef
name|Str
decl_stmt|;
name|unsigned
name|Width
decl_stmt|;
name|bool
name|RightJustify
decl_stmt|;
name|friend
name|class
name|raw_ostream
decl_stmt|;
name|public
label|:
name|FormattedString
argument_list|(
argument|StringRef S
argument_list|,
argument|unsigned W
argument_list|,
argument|bool R
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
name|RightJustify
argument_list|(
argument|R
argument_list|)
block|{ }
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
name|false
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
name|true
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
argument|U
argument_list|)
block|{ }
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
comment|///   OS<< format_hex(255, 4)        => 0xff
end_comment

begin_comment
comment|///   OS<< format_hex(255, 4, true)  => 0xFF
end_comment

begin_comment
comment|///   OS<< format_hex(255, 6)        => 0x00ff
end_comment

begin_comment
comment|///   OS<< format_hex(255, 2)        => 0xff
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
argument_list|)
return|;
block|}
end_function

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

