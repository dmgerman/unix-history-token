begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Iostreams base classes -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004
end_comment

begin_comment
comment|// Free Software Foundation, Inc.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is part of the GNU ISO C++ Library.  This library is free
end_comment

begin_comment
comment|// software; you can redistribute it and/or modify it under the
end_comment

begin_comment
comment|// terms of the GNU General Public License as published by the
end_comment

begin_comment
comment|// Free Software Foundation; either version 2, or (at your option)
end_comment

begin_comment
comment|// any later version.
end_comment

begin_comment
comment|// This library is distributed in the hope that it will be useful,
end_comment

begin_comment
comment|// but WITHOUT ANY WARRANTY; without even the implied warranty of
end_comment

begin_comment
comment|// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
end_comment

begin_comment
comment|// GNU General Public License for more details.
end_comment

begin_comment
comment|// You should have received a copy of the GNU General Public License along
end_comment

begin_comment
comment|// with this library; see the file COPYING.  If not, write to the Free
end_comment

begin_comment
comment|// Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307,
end_comment

begin_comment
comment|// USA.
end_comment

begin_comment
comment|// As a special exception, you may use this file as part of a free software
end_comment

begin_comment
comment|// library without restriction.  Specifically, if other files instantiate
end_comment

begin_comment
comment|// templates or use macros or inline functions from this file, or you compile
end_comment

begin_comment
comment|// this file and link it with other files to produce an executable, this
end_comment

begin_comment
comment|// file does not by itself cause the resulting executable to be covered by
end_comment

begin_comment
comment|// the GNU General Public License.  This exception does not however
end_comment

begin_comment
comment|// invalidate any other reasons why the executable file might be covered by
end_comment

begin_comment
comment|// the GNU General Public License.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ISO C++ 14882: 27.4  Iostreams base classes
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/** @file ios_base.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IOS_BASE_H
end_ifndef

begin_define
define|#
directive|define
name|_IOS_BASE_H
value|1
end_define

begin_pragma
pragma|#
directive|pragma
name|GCC
name|system_header
end_pragma

begin_include
include|#
directive|include
file|<bits/atomicity.h>
end_include

begin_include
include|#
directive|include
file|<bits/localefwd.h>
end_include

begin_include
include|#
directive|include
file|<bits/locale_classes.h>
end_include

begin_decl_stmt
name|namespace
name|std
block|{
comment|// The following definitions of bitmask types are enums, not ints,
comment|// as permitted (but not required) in the standard, in order to provide
comment|// better type safety in iostream calls.  A side effect is that
comment|// expressions involving them are no longer compile-time constants.
enum|enum
name|_Ios_Fmtflags
block|{
name|_S_boolalpha
init|=
literal|1L
operator|<<
literal|0
block|,
name|_S_dec
init|=
literal|1L
operator|<<
literal|1
block|,
name|_S_fixed
init|=
literal|1L
operator|<<
literal|2
block|,
name|_S_hex
init|=
literal|1L
operator|<<
literal|3
block|,
name|_S_internal
init|=
literal|1L
operator|<<
literal|4
block|,
name|_S_left
init|=
literal|1L
operator|<<
literal|5
block|,
name|_S_oct
init|=
literal|1L
operator|<<
literal|6
block|,
name|_S_right
init|=
literal|1L
operator|<<
literal|7
block|,
name|_S_scientific
init|=
literal|1L
operator|<<
literal|8
block|,
name|_S_showbase
init|=
literal|1L
operator|<<
literal|9
block|,
name|_S_showpoint
init|=
literal|1L
operator|<<
literal|10
block|,
name|_S_showpos
init|=
literal|1L
operator|<<
literal|11
block|,
name|_S_skipws
init|=
literal|1L
operator|<<
literal|12
block|,
name|_S_unitbuf
init|=
literal|1L
operator|<<
literal|13
block|,
name|_S_uppercase
init|=
literal|1L
operator|<<
literal|14
block|,
name|_S_adjustfield
init|=
name|_S_left
operator||
name|_S_right
operator||
name|_S_internal
block|,
name|_S_basefield
init|=
name|_S_dec
operator||
name|_S_oct
operator||
name|_S_hex
block|,
name|_S_floatfield
init|=
name|_S_scientific
operator||
name|_S_fixed
block|,
name|_S_ios_fmtflags_end
init|=
literal|1L
operator|<<
literal|16
block|}
enum|;
specifier|inline
name|_Ios_Fmtflags
name|operator
function|&(
name|_Ios_Fmtflags
name|__a
function|,
name|_Ios_Fmtflags
function|__b
block|)
block|{
return|return
name|_Ios_Fmtflags
argument_list|(
name|static_cast
operator|<
name|int
operator|>
operator|(
name|__a
operator|)
operator|&
name|static_cast
operator|<
name|int
operator|>
operator|(
name|__b
operator|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
specifier|inline
name|_Ios_Fmtflags
name|operator
operator||
operator|(
name|_Ios_Fmtflags
name|__a
operator|,
name|_Ios_Fmtflags
name|__b
operator|)
block|{
return|return
name|_Ios_Fmtflags
argument_list|(
name|static_cast
operator|<
name|int
operator|>
operator|(
name|__a
operator|)
operator||
name|static_cast
operator|<
name|int
operator|>
operator|(
name|__b
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
specifier|inline
name|_Ios_Fmtflags
name|operator
modifier|^
parameter_list|(
name|_Ios_Fmtflags
name|__a
parameter_list|,
name|_Ios_Fmtflags
name|__b
parameter_list|)
block|{
return|return
name|_Ios_Fmtflags
argument_list|(
name|static_cast
operator|<
name|int
operator|>
operator|(
name|__a
operator|)
operator|^
name|static_cast
operator|<
name|int
operator|>
operator|(
name|__b
operator|)
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
specifier|inline
name|_Ios_Fmtflags
operator|&
name|operator
operator||=
operator|(
name|_Ios_Fmtflags
operator|&
name|__a
operator|,
name|_Ios_Fmtflags
name|__b
operator|)
block|{
return|return
name|__a
operator|=
name|__a
operator||
name|__b
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|_Ios_Fmtflags
operator|&
name|operator
operator|&=
operator|(
name|_Ios_Fmtflags
operator|&
name|__a
operator|,
name|_Ios_Fmtflags
name|__b
operator|)
block|{
return|return
name|__a
operator|=
name|__a
operator|&
name|__b
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|_Ios_Fmtflags
operator|&
name|operator
operator|^=
operator|(
name|_Ios_Fmtflags
operator|&
name|__a
operator|,
name|_Ios_Fmtflags
name|__b
operator|)
block|{
return|return
name|__a
operator|=
name|__a
operator|^
name|__b
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|_Ios_Fmtflags
name|operator
operator|~
operator|(
name|_Ios_Fmtflags
name|__a
operator|)
block|{
return|return
name|_Ios_Fmtflags
argument_list|(
operator|~
name|static_cast
operator|<
name|int
operator|>
operator|(
name|__a
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_enum
enum|enum
name|_Ios_Openmode
block|{
name|_S_app
init|=
literal|1L
operator|<<
literal|0
block|,
name|_S_ate
init|=
literal|1L
operator|<<
literal|1
block|,
name|_S_bin
init|=
literal|1L
operator|<<
literal|2
block|,
name|_S_in
init|=
literal|1L
operator|<<
literal|3
block|,
name|_S_out
init|=
literal|1L
operator|<<
literal|4
block|,
name|_S_trunc
init|=
literal|1L
operator|<<
literal|5
block|,
name|_S_ios_openmode_end
init|=
literal|1L
operator|<<
literal|16
block|}
enum|;
end_enum

begin_function
specifier|inline
name|_Ios_Openmode
name|operator
function|&(
name|_Ios_Openmode
name|__a
function|,
name|_Ios_Openmode
function|__b
end_function

begin_block
unit|)
block|{
return|return
name|_Ios_Openmode
argument_list|(
name|static_cast
operator|<
name|int
operator|>
operator|(
name|__a
operator|)
operator|&
name|static_cast
operator|<
name|int
operator|>
operator|(
name|__b
operator|)
argument_list|)
return|;
block|}
end_block

begin_expr_stmt
specifier|inline
name|_Ios_Openmode
name|operator
operator||
operator|(
name|_Ios_Openmode
name|__a
operator|,
name|_Ios_Openmode
name|__b
operator|)
block|{
return|return
name|_Ios_Openmode
argument_list|(
name|static_cast
operator|<
name|int
operator|>
operator|(
name|__a
operator|)
operator||
name|static_cast
operator|<
name|int
operator|>
operator|(
name|__b
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
specifier|inline
name|_Ios_Openmode
name|operator
modifier|^
parameter_list|(
name|_Ios_Openmode
name|__a
parameter_list|,
name|_Ios_Openmode
name|__b
parameter_list|)
block|{
return|return
name|_Ios_Openmode
argument_list|(
name|static_cast
operator|<
name|int
operator|>
operator|(
name|__a
operator|)
operator|^
name|static_cast
operator|<
name|int
operator|>
operator|(
name|__b
operator|)
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
specifier|inline
name|_Ios_Openmode
operator|&
name|operator
operator||=
operator|(
name|_Ios_Openmode
operator|&
name|__a
operator|,
name|_Ios_Openmode
name|__b
operator|)
block|{
return|return
name|__a
operator|=
name|__a
operator||
name|__b
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|_Ios_Openmode
operator|&
name|operator
operator|&=
operator|(
name|_Ios_Openmode
operator|&
name|__a
operator|,
name|_Ios_Openmode
name|__b
operator|)
block|{
return|return
name|__a
operator|=
name|__a
operator|&
name|__b
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|_Ios_Openmode
operator|&
name|operator
operator|^=
operator|(
name|_Ios_Openmode
operator|&
name|__a
operator|,
name|_Ios_Openmode
name|__b
operator|)
block|{
return|return
name|__a
operator|=
name|__a
operator|^
name|__b
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|_Ios_Openmode
name|operator
operator|~
operator|(
name|_Ios_Openmode
name|__a
operator|)
block|{
return|return
name|_Ios_Openmode
argument_list|(
operator|~
name|static_cast
operator|<
name|int
operator|>
operator|(
name|__a
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_enum
enum|enum
name|_Ios_Iostate
block|{
name|_S_goodbit
init|=
literal|0
block|,
name|_S_badbit
init|=
literal|1L
operator|<<
literal|0
block|,
name|_S_eofbit
init|=
literal|1L
operator|<<
literal|1
block|,
name|_S_failbit
init|=
literal|1L
operator|<<
literal|2
block|,
name|_S_ios_iostate_end
init|=
literal|1L
operator|<<
literal|16
block|}
enum|;
end_enum

begin_function
specifier|inline
name|_Ios_Iostate
name|operator
function|&(
name|_Ios_Iostate
name|__a
function|,
name|_Ios_Iostate
function|__b
end_function

begin_block
unit|)
block|{
return|return
name|_Ios_Iostate
argument_list|(
name|static_cast
operator|<
name|int
operator|>
operator|(
name|__a
operator|)
operator|&
name|static_cast
operator|<
name|int
operator|>
operator|(
name|__b
operator|)
argument_list|)
return|;
block|}
end_block

begin_expr_stmt
specifier|inline
name|_Ios_Iostate
name|operator
operator||
operator|(
name|_Ios_Iostate
name|__a
operator|,
name|_Ios_Iostate
name|__b
operator|)
block|{
return|return
name|_Ios_Iostate
argument_list|(
name|static_cast
operator|<
name|int
operator|>
operator|(
name|__a
operator|)
operator||
name|static_cast
operator|<
name|int
operator|>
operator|(
name|__b
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
specifier|inline
name|_Ios_Iostate
name|operator
modifier|^
parameter_list|(
name|_Ios_Iostate
name|__a
parameter_list|,
name|_Ios_Iostate
name|__b
parameter_list|)
block|{
return|return
name|_Ios_Iostate
argument_list|(
name|static_cast
operator|<
name|int
operator|>
operator|(
name|__a
operator|)
operator|^
name|static_cast
operator|<
name|int
operator|>
operator|(
name|__b
operator|)
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
specifier|inline
name|_Ios_Iostate
operator|&
name|operator
operator||=
operator|(
name|_Ios_Iostate
operator|&
name|__a
operator|,
name|_Ios_Iostate
name|__b
operator|)
block|{
return|return
name|__a
operator|=
name|__a
operator||
name|__b
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|_Ios_Iostate
operator|&
name|operator
operator|&=
operator|(
name|_Ios_Iostate
operator|&
name|__a
operator|,
name|_Ios_Iostate
name|__b
operator|)
block|{
return|return
name|__a
operator|=
name|__a
operator|&
name|__b
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|_Ios_Iostate
operator|&
name|operator
operator|^=
operator|(
name|_Ios_Iostate
operator|&
name|__a
operator|,
name|_Ios_Iostate
name|__b
operator|)
block|{
return|return
name|__a
operator|=
name|__a
operator|^
name|__b
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|_Ios_Iostate
name|operator
operator|~
operator|(
name|_Ios_Iostate
name|__a
operator|)
block|{
return|return
name|_Ios_Iostate
argument_list|(
operator|~
name|static_cast
operator|<
name|int
operator|>
operator|(
name|__a
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_enum
enum|enum
name|_Ios_Seekdir
block|{
name|_S_beg
init|=
literal|0
block|,
name|_S_cur
init|=
name|SEEK_CUR
block|,
name|_S_end
init|=
name|SEEK_END
block|,
name|_S_ios_seekdir_end
init|=
literal|1L
operator|<<
literal|16
block|}
enum|;
end_enum

begin_comment
comment|// 27.4.2  Class ios_base
end_comment

begin_comment
comment|/**    *  @brief  The very top of the I/O class hierarchy.    *    *  This class defines everything that can be defined about I/O that does    *  not depend on the type of characters being input or output.  Most    *  people will only see @c ios_base when they need to specify the full    *  name of the various I/O flags (e.g., the openmodes).   */
end_comment

begin_decl_stmt
name|class
name|ios_base
block|{
name|public
label|:
comment|// 27.4.2.1.1  Class ios_base::failure
comment|/// These are thrown to indicate problems.  Doc me.
name|class
name|failure
range|:
name|public
name|exception
block|{
name|public
operator|:
comment|// _GLIBCXX_RESOLVE_LIB_DEFECTS
comment|// 48.  Use of non-existent exception constructor
name|explicit
name|failure
argument_list|(
argument|const string& __str
argument_list|)
name|throw
argument_list|()
block|;
comment|// This declaration is not useless:
comment|// http://gcc.gnu.org/onlinedocs/gcc-3.0.2/gcc_6.html#SEC118
name|virtual
operator|~
name|failure
argument_list|()
name|throw
argument_list|()
block|;
name|virtual
specifier|const
name|char
operator|*
name|what
argument_list|()
specifier|const
name|throw
argument_list|()
block|;
name|private
operator|:
name|string
name|_M_msg
block|;     }
decl_stmt|;
comment|// 27.4.2.1.2  Type ios_base::fmtflags
comment|/**      *  @brief This is a bitmask type.      *      *  @c "_Ios_Fmtflags" is implementation-defined, but it is valid to      *  perform bitwise operations on these values and expect the Right      *  Thing to happen.  Defined objects of type fmtflags are:      *  - boolalpha      *  - dec      *  - fixed      *  - hex      *  - internal      *  - left      *  - oct      *  - right      *  - scientific      *  - showbase      *  - showpoint      *  - showpos      *  - skipws      *  - unitbuf      *  - uppercase      *  - adjustfield      *  - basefield      *  - floatfield     */
typedef|typedef
name|_Ios_Fmtflags
name|fmtflags
typedef|;
comment|/// Insert/extract @c bool in alphabetic rather than numeric format.
specifier|static
specifier|const
name|fmtflags
name|boolalpha
init|=
name|fmtflags
argument_list|(
name|__ios_flags
operator|::
name|_S_boolalpha
argument_list|)
decl_stmt|;
comment|/// Converts integer input or generates integer output in decimal base.
specifier|static
specifier|const
name|fmtflags
name|dec
init|=
name|fmtflags
argument_list|(
name|__ios_flags
operator|::
name|_S_dec
argument_list|)
decl_stmt|;
comment|/// Generate floating-point output in fixed-point notation.
specifier|static
specifier|const
name|fmtflags
name|fixed
init|=
name|fmtflags
argument_list|(
name|__ios_flags
operator|::
name|_S_fixed
argument_list|)
decl_stmt|;
comment|/// Converts integer input or generates integer output in hexadecimal base.
specifier|static
specifier|const
name|fmtflags
name|hex
init|=
name|fmtflags
argument_list|(
name|__ios_flags
operator|::
name|_S_hex
argument_list|)
decl_stmt|;
comment|/// Adds fill characters at a designated internal point in certain
comment|/// generated output, or identical to @c right if no such point is
comment|/// designated.
specifier|static
specifier|const
name|fmtflags
name|internal
init|=
name|fmtflags
argument_list|(
name|__ios_flags
operator|::
name|_S_internal
argument_list|)
decl_stmt|;
comment|/// Adds fill characters on the right (final positions) of certain
comment|/// generated output.  (I.e., the thing you print is flush left.)
specifier|static
specifier|const
name|fmtflags
name|left
init|=
name|fmtflags
argument_list|(
name|__ios_flags
operator|::
name|_S_left
argument_list|)
decl_stmt|;
comment|/// Converts integer input or generates integer output in octal base.
specifier|static
specifier|const
name|fmtflags
name|oct
init|=
name|fmtflags
argument_list|(
name|__ios_flags
operator|::
name|_S_oct
argument_list|)
decl_stmt|;
comment|/// Adds fill characters on the left (initial positions) of certain
comment|/// generated output.  (I.e., the thing you print is flush right.)
specifier|static
specifier|const
name|fmtflags
name|right
init|=
name|fmtflags
argument_list|(
name|__ios_flags
operator|::
name|_S_right
argument_list|)
decl_stmt|;
comment|/// Generates floating-point output in scientific notation.
specifier|static
specifier|const
name|fmtflags
name|scientific
init|=
name|fmtflags
argument_list|(
name|__ios_flags
operator|::
name|_S_scientific
argument_list|)
decl_stmt|;
comment|/// Generates a prefix indicating the numeric base of generated integer
comment|/// output.
specifier|static
specifier|const
name|fmtflags
name|showbase
init|=
name|fmtflags
argument_list|(
name|__ios_flags
operator|::
name|_S_showbase
argument_list|)
decl_stmt|;
comment|/// Generates a decimal-point character unconditionally in generated
comment|/// floating-point output.
specifier|static
specifier|const
name|fmtflags
name|showpoint
init|=
name|fmtflags
argument_list|(
name|__ios_flags
operator|::
name|_S_showpoint
argument_list|)
decl_stmt|;
comment|/// Generates a + sign in non-negative generated numeric output.
specifier|static
specifier|const
name|fmtflags
name|showpos
init|=
name|fmtflags
argument_list|(
name|__ios_flags
operator|::
name|_S_showpos
argument_list|)
decl_stmt|;
comment|/// Skips leading white space before certain input operations.
specifier|static
specifier|const
name|fmtflags
name|skipws
init|=
name|fmtflags
argument_list|(
name|__ios_flags
operator|::
name|_S_skipws
argument_list|)
decl_stmt|;
comment|/// Flushes output after each output operation.
specifier|static
specifier|const
name|fmtflags
name|unitbuf
init|=
name|fmtflags
argument_list|(
name|__ios_flags
operator|::
name|_S_unitbuf
argument_list|)
decl_stmt|;
comment|/// Replaces certain lowercase letters with their uppercase equivalents
comment|/// in generated output.
specifier|static
specifier|const
name|fmtflags
name|uppercase
init|=
name|fmtflags
argument_list|(
name|__ios_flags
operator|::
name|_S_uppercase
argument_list|)
decl_stmt|;
comment|/// A mask of left|right|internal.  Useful for the 2-arg form of @c setf.
specifier|static
specifier|const
name|fmtflags
name|adjustfield
init|=
name|fmtflags
argument_list|(
name|__ios_flags
operator|::
name|_S_adjustfield
argument_list|)
decl_stmt|;
comment|/// A mask of dec|oct|hex.  Useful for the 2-arg form of @c setf.
specifier|static
specifier|const
name|fmtflags
name|basefield
init|=
name|fmtflags
argument_list|(
name|__ios_flags
operator|::
name|_S_basefield
argument_list|)
decl_stmt|;
comment|/// A mask of scientific|fixed.  Useful for the 2-arg form of @c setf.
specifier|static
specifier|const
name|fmtflags
name|floatfield
init|=
name|fmtflags
argument_list|(
name|__ios_flags
operator|::
name|_S_floatfield
argument_list|)
decl_stmt|;
comment|// 27.4.2.1.3  Type ios_base::iostate
comment|/**      *  @brief This is a bitmask type.      *      *  @c "_Ios_Iostate" is implementation-defined, but it is valid to      *  perform bitwise operations on these values and expect the Right      *  Thing to happen.  Defined objects of type iostate are:      *  - badbit      *  - eofbit      *  - failbit      *  - goodbit     */
typedef|typedef
name|_Ios_Iostate
name|iostate
typedef|;
comment|/// Indicates a loss of integrity in an input or output sequence (such
comment|/// as an irrecoverable read error from a file).
specifier|static
specifier|const
name|iostate
name|badbit
init|=
name|iostate
argument_list|(
name|__ios_flags
operator|::
name|_S_badbit
argument_list|)
decl_stmt|;
comment|/// Indicates that an input operation reached the end of an input sequence.
specifier|static
specifier|const
name|iostate
name|eofbit
init|=
name|iostate
argument_list|(
name|__ios_flags
operator|::
name|_S_eofbit
argument_list|)
decl_stmt|;
comment|/// Indicates that an input operation failed to read the expected
comment|/// characters, or that an output operation failed to generate the
comment|/// desired characters.
specifier|static
specifier|const
name|iostate
name|failbit
init|=
name|iostate
argument_list|(
name|__ios_flags
operator|::
name|_S_failbit
argument_list|)
decl_stmt|;
comment|/// Indicates all is well.
specifier|static
specifier|const
name|iostate
name|goodbit
init|=
name|iostate
argument_list|(
literal|0
argument_list|)
decl_stmt|;
comment|// 27.4.2.1.4  Type ios_base::openmode
comment|/**      *  @brief This is a bitmask type.      *      *  @c "_Ios_Openmode" is implementation-defined, but it is valid to      *  perform bitwise operations on these values and expect the Right      *  Thing to happen.  Defined objects of type openmode are:      *  - app      *  - ate      *  - binary      *  - in      *  - out      *  - trunc     */
typedef|typedef
name|_Ios_Openmode
name|openmode
typedef|;
comment|/// Seek to end before each write.
specifier|static
specifier|const
name|openmode
name|app
init|=
name|openmode
argument_list|(
name|__ios_flags
operator|::
name|_S_app
argument_list|)
decl_stmt|;
comment|/// Open and seek to end immediately after opening.
specifier|static
specifier|const
name|openmode
name|ate
init|=
name|openmode
argument_list|(
name|__ios_flags
operator|::
name|_S_ate
argument_list|)
decl_stmt|;
comment|/// Perform input and output in binary mode (as opposed to text mode).
comment|/// This is probably not what you think it is; see
comment|/// http://gcc.gnu.org/onlinedocs/libstdc++/27_io/howto.html#3 and
comment|/// http://gcc.gnu.org/onlinedocs/libstdc++/27_io/howto.html#7 for more.
specifier|static
specifier|const
name|openmode
name|binary
init|=
name|openmode
argument_list|(
name|__ios_flags
operator|::
name|_S_bin
argument_list|)
decl_stmt|;
comment|/// Open for input.  Default for @c ifstream and fstream.
specifier|static
specifier|const
name|openmode
name|in
init|=
name|openmode
argument_list|(
name|__ios_flags
operator|::
name|_S_in
argument_list|)
decl_stmt|;
comment|/// Open for output.  Default for @c ofstream and fstream.
specifier|static
specifier|const
name|openmode
name|out
init|=
name|openmode
argument_list|(
name|__ios_flags
operator|::
name|_S_out
argument_list|)
decl_stmt|;
comment|/// Open for input.  Default for @c ofstream.
specifier|static
specifier|const
name|openmode
name|trunc
init|=
name|openmode
argument_list|(
name|__ios_flags
operator|::
name|_S_trunc
argument_list|)
decl_stmt|;
comment|// 27.4.2.1.5  Type ios_base::seekdir
comment|/**      *  @brief This is an enumerated type.      *      *  @c "_Ios_Seekdir" is implementation-defined.  Defined values      *  of type seekdir are:      *  - beg      *  - cur, equivalent to @c SEEK_CUR in the C standard library.      *  - end, equivalent to @c SEEK_END in the C standard library.     */
typedef|typedef
name|_Ios_Seekdir
name|seekdir
typedef|;
comment|/// Request a seek relative to the beginning of the stream.
specifier|static
specifier|const
name|seekdir
name|beg
init|=
name|seekdir
argument_list|(
literal|0
argument_list|)
decl_stmt|;
comment|/// Request a seek relative to the current position within the sequence.
specifier|static
specifier|const
name|seekdir
name|cur
init|=
name|seekdir
argument_list|(
name|SEEK_CUR
argument_list|)
decl_stmt|;
comment|/// Request a seek relative to the current end of the sequence.
specifier|static
specifier|const
name|seekdir
name|end
init|=
name|seekdir
argument_list|(
name|SEEK_END
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|_GLIBCXX_DEPRECATED
comment|// Annex D.6
typedef|typedef
name|int
name|io_state
typedef|;
typedef|typedef
name|int
name|open_mode
typedef|;
typedef|typedef
name|int
name|seek_dir
typedef|;
typedef|typedef
name|std
operator|::
name|streampos
name|streampos
expr_stmt|;
typedef|typedef
name|std
operator|::
name|streamoff
name|streamoff
expr_stmt|;
endif|#
directive|endif
comment|// Callbacks;
comment|/**      *  @brief  The set of events that may be passed to an event callback.      *      *  erase_event is used during ~ios() and copyfmt().  imbue_event is used      *  during imbue().  copyfmt_event is used during copyfmt().     */
enum|enum
name|event
block|{
name|erase_event
block|,
name|imbue_event
block|,
name|copyfmt_event
block|}
enum|;
comment|/**      *  @brief  The type of an event callback function.      *  @param  event  One of the members of the event enum.      *  @param  ios_base  Reference to the ios_base object.      *  @param  int  The integer provided when the callback was registered.      *      *  Event callbacks are user defined functions that get called during      *  several ios_base and basic_ios functions, specifically imbue(),      *  copyfmt(), and ~ios().     */
typedef|typedef
name|void
function_decl|(
modifier|*
name|event_callback
function_decl|)
parameter_list|(
name|event
parameter_list|,
name|ios_base
modifier|&
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/**      *  @brief  Add the callback __fn with parameter __index.      *  @param  __fn  The function to add.      *  @param  __index  The integer to pass to the function when invoked.      *      *  Registers a function as an event callback with an integer parameter to      *  be passed to the function when invoked.  Multiple copies of the      *  function are allowed.  If there are multiple callbacks, they are      *  invoked in the order they were registered.     */
name|void
name|register_callback
parameter_list|(
name|event_callback
name|__fn
parameter_list|,
name|int
name|__index
parameter_list|)
function_decl|;
name|protected
label|:
comment|//@{
comment|/**      *  @if maint      *  ios_base data members (doc me)      *  @endif     */
name|streamsize
name|_M_precision
decl_stmt|;
name|streamsize
name|_M_width
decl_stmt|;
name|fmtflags
name|_M_flags
decl_stmt|;
name|iostate
name|_M_exception
decl_stmt|;
name|iostate
name|_M_streambuf_state
decl_stmt|;
comment|//@}
comment|// 27.4.2.6  Members for callbacks
comment|// 27.4.2.6  ios_base callbacks
struct|struct
name|_Callback_list
block|{
comment|// Data Members
name|_Callback_list
modifier|*
name|_M_next
decl_stmt|;
name|ios_base
operator|::
name|event_callback
name|_M_fn
expr_stmt|;
name|int
name|_M_index
decl_stmt|;
name|_Atomic_word
name|_M_refcount
decl_stmt|;
comment|// 0 means one reference.
name|_Callback_list
argument_list|(
argument|ios_base::event_callback __fn
argument_list|,
argument|int __index
argument_list|,
argument|_Callback_list* __cb
argument_list|)
block|:
name|_M_next
argument_list|(
name|__cb
argument_list|)
operator|,
name|_M_fn
argument_list|(
name|__fn
argument_list|)
operator|,
name|_M_index
argument_list|(
name|__index
argument_list|)
operator|,
name|_M_refcount
argument_list|(
literal|0
argument_list|)
block|{ }
name|void
name|_M_add_reference
argument_list|()
block|{
name|__gnu_cxx
operator|::
name|__atomic_add
argument_list|(
operator|&
name|_M_refcount
argument_list|,
literal|1
argument_list|)
block|; }
comment|// 0 => OK to delete.
name|int
name|_M_remove_reference
argument_list|()
block|{
return|return
name|__gnu_cxx
operator|::
name|__exchange_and_add
argument_list|(
operator|&
name|_M_refcount
argument_list|,
operator|-
literal|1
argument_list|)
return|;
block|}
block|}
struct|;
name|_Callback_list
modifier|*
name|_M_callbacks
decl_stmt|;
name|void
name|_M_call_callbacks
parameter_list|(
name|event
name|__ev
parameter_list|)
function_decl|throw
parameter_list|()
function_decl|;
name|void
name|_M_dispose_callbacks
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|// 27.4.2.5  Members for iword/pword storage
struct|struct
name|_Words
block|{
name|void
modifier|*
name|_M_pword
decl_stmt|;
name|long
name|_M_iword
decl_stmt|;
name|_Words
argument_list|()
operator|:
name|_M_pword
argument_list|(
literal|0
argument_list|)
operator|,
name|_M_iword
argument_list|(
literal|0
argument_list|)
block|{ }
block|}
struct|;
comment|// Only for failed iword/pword calls.
name|_Words
name|_M_word_zero
decl_stmt|;
comment|// Guaranteed storage.
comment|// The first 5 iword and pword slots are reserved for internal use.
specifier|static
specifier|const
name|int
name|_S_local_word_size
init|=
literal|8
decl_stmt|;
name|_Words
name|_M_local_word
index|[
name|_S_local_word_size
index|]
decl_stmt|;
comment|// Allocated storage.
name|int
name|_M_word_size
decl_stmt|;
name|_Words
modifier|*
name|_M_word
decl_stmt|;
name|_Words
modifier|&
name|_M_grow_words
parameter_list|(
name|int
name|__index
parameter_list|,
name|bool
name|__iword
parameter_list|)
function_decl|;
comment|// Members for locale and locale caching.
name|locale
name|_M_ios_locale
decl_stmt|;
name|void
name|_M_init
parameter_list|()
function_decl|;
name|public
label|:
comment|// 27.4.2.1.6  Class ios_base::Init
comment|// Used to initialize standard streams. In theory, g++ could use
comment|// -finit-priority to order this stuff correctly without going
comment|// through these machinations.
name|class
name|Init
block|{
name|friend
name|class
name|ios_base
decl_stmt|;
name|public
label|:
name|Init
argument_list|()
expr_stmt|;
operator|~
name|Init
argument_list|()
expr_stmt|;
name|private
label|:
specifier|static
name|_Atomic_word
name|_S_refcount
decl_stmt|;
specifier|static
name|bool
name|_S_synced_with_stdio
decl_stmt|;
block|}
empty_stmt|;
comment|// [27.4.2.2] fmtflags state functions
comment|/**      *  @brief  Access to format flags.      *  @return  The format control flags for both input and output.     */
specifier|inline
name|fmtflags
name|flags
argument_list|()
specifier|const
block|{
return|return
name|_M_flags
return|;
block|}
comment|/**      *  @brief  Setting new format flags all at once.      *  @param  fmtfl  The new flags to set.      *  @return  The previous format control flags.      *      *  This function overwrites all the format flags with @a fmtfl.     */
specifier|inline
name|fmtflags
name|flags
parameter_list|(
name|fmtflags
name|__fmtfl
parameter_list|)
block|{
name|fmtflags
name|__old
init|=
name|_M_flags
decl_stmt|;
name|_M_flags
operator|=
name|__fmtfl
expr_stmt|;
return|return
name|__old
return|;
block|}
comment|/**      *  @brief  Setting new format flags.      *  @param  fmtfl  Additional flags to set.      *  @return  The previous format control flags.      *      *  This function sets additional flags in format control.  Flags that      *  were previously set remain set.     */
specifier|inline
name|fmtflags
name|setf
parameter_list|(
name|fmtflags
name|__fmtfl
parameter_list|)
block|{
name|fmtflags
name|__old
init|=
name|_M_flags
decl_stmt|;
name|_M_flags
operator||=
name|__fmtfl
expr_stmt|;
return|return
name|__old
return|;
block|}
comment|/**      *  @brief  Setting new format flags.      *  @param  fmtfl  Additional flags to set.      *  @param  mask  The flags mask for @a fmtfl.      *  @return  The previous format control flags.      *      *  This function clears @a mask in the format flags, then sets      *  @a fmtfl @c& @a mask.  An example mask is @c ios_base::adjustfield.     */
specifier|inline
name|fmtflags
name|setf
parameter_list|(
name|fmtflags
name|__fmtfl
parameter_list|,
name|fmtflags
name|__mask
parameter_list|)
block|{
name|fmtflags
name|__old
init|=
name|_M_flags
decl_stmt|;
name|_M_flags
operator|&=
operator|~
name|__mask
expr_stmt|;
name|_M_flags
operator||=
operator|(
name|__fmtfl
operator|&
name|__mask
operator|)
expr_stmt|;
return|return
name|__old
return|;
block|}
comment|/**      *  @brief  Clearing format flags.      *  @param  mask  The flags to unset.      *      *  This function clears @a mask in the format flags.     */
specifier|inline
name|void
name|unsetf
parameter_list|(
name|fmtflags
name|__mask
parameter_list|)
block|{
name|_M_flags
operator|&=
operator|~
name|__mask
expr_stmt|;
block|}
comment|/**      *  @brief  Flags access.      *  @return  The precision to generate on certain output operations.      *      *  @if maint      *  Be careful if you try to give a definition of "precision" here; see      *  DR 189.      *  @endif     */
specifier|inline
name|streamsize
name|precision
argument_list|()
specifier|const
block|{
return|return
name|_M_precision
return|;
block|}
comment|/**      *  @brief  Changing flags.      *  @param  prec  The new precision value.      *  @return  The previous value of precision().     */
specifier|inline
name|streamsize
name|precision
parameter_list|(
name|streamsize
name|__prec
parameter_list|)
block|{
name|streamsize
name|__old
init|=
name|_M_precision
decl_stmt|;
name|_M_precision
operator|=
name|__prec
expr_stmt|;
return|return
name|__old
return|;
block|}
comment|/**      *  @brief  Flags access.      *  @return  The minimum field width to generate on output operations.      *      *  "Minimum field width" refers to the number of characters.     */
specifier|inline
name|streamsize
name|width
argument_list|()
specifier|const
block|{
return|return
name|_M_width
return|;
block|}
comment|/**      *  @brief  Changing flags.      *  @param  wide  The new width value.      *  @return  The previous value of width().     */
specifier|inline
name|streamsize
name|width
parameter_list|(
name|streamsize
name|__wide
parameter_list|)
block|{
name|streamsize
name|__old
init|=
name|_M_width
decl_stmt|;
name|_M_width
operator|=
name|__wide
expr_stmt|;
return|return
name|__old
return|;
block|}
comment|// [27.4.2.4] ios_base static members
comment|/**      *  @brief  Interaction with the standard C I/O objects.      *  @param  sync  Whether to synchronize or not.      *  @return  True if the standard streams were previously synchronized.      *      *  The synchronization referred to is @e only that between the standard      *  C facilities (e.g., stdout) and the standard C++ objects (e.g.,      *  cout).  User-declared streams are unaffected.  See      *  http://gcc.gnu.org/onlinedocs/libstdc++/27_io/howto.html#8 for more.     */
specifier|static
name|bool
name|sync_with_stdio
parameter_list|(
name|bool
name|__sync
init|=
name|true
parameter_list|)
function_decl|;
comment|// [27.4.2.3] ios_base locale functions
comment|/**      *  @brief  Setting a new locale.      *  @param  loc  The new locale.      *  @return  The previous locale.      *      *  Sets the new locale for this stream, and then invokes each callback      *  with imbue_event.     */
name|locale
name|imbue
parameter_list|(
specifier|const
name|locale
modifier|&
name|__loc
parameter_list|)
function_decl|;
comment|/**      *  @brief  Locale access      *  @return  A copy of the current locale.      *      *  If @c imbue(loc) has previously been called, then this function      *  returns @c loc.  Otherwise, it returns a copy of @c std::locale(),      *  the global C++ locale.     */
specifier|inline
name|locale
name|getloc
argument_list|()
specifier|const
block|{
return|return
name|_M_ios_locale
return|;
block|}
comment|/**      *  @brief  Locale access      *  @return  A reference to the current locale.      *      *  Like getloc above, but returns a reference instead of      *  generating a copy.     */
specifier|inline
specifier|const
name|locale
operator|&
name|_M_getloc
argument_list|()
specifier|const
block|{
return|return
name|_M_ios_locale
return|;
block|}
comment|// [27.4.2.5] ios_base storage functions
comment|/**      *  @brief  Access to unique indices.      *  @return  An integer different from all previous calls.      *      *  This function returns a unique integer every time it is called.  It      *  can be used for any purpose, but is primarily intended to be a unique      *  index for the iword and pword functions.  The expectation is that an      *  application calls xalloc in order to obtain an index in the iword and      *  pword arrays that can be used without fear of conflict.      *      *  The implementation maintains a static variable that is incremented and      *  returned on each invocation.  xalloc is guaranteed to return an index      *  that is safe to use in the iword and pword arrays.     */
specifier|static
name|int
name|xalloc
parameter_list|()
function_decl|throw
parameter_list|()
function_decl|;
comment|/**      *  @brief  Access to integer array.      *  @param  __ix  Index into the array.      *  @return  A reference to an integer associated with the index.      *      *  The iword function provides access to an array of integers that can be      *  used for any purpose.  The array grows as required to hold the      *  supplied index.  All integers in the array are initialized to 0.      *      *  The implementation reserves several indices.  You should use xalloc to      *  obtain an index that is safe to use.  Also note that since the array      *  can grow dynamically, it is not safe to hold onto the reference.     */
specifier|inline
name|long
modifier|&
name|iword
parameter_list|(
name|int
name|__ix
parameter_list|)
block|{
name|_Words
modifier|&
name|__word
init|=
operator|(
name|__ix
operator|<
name|_M_word_size
operator|)
condition|?
name|_M_word
index|[
name|__ix
index|]
else|:
name|_M_grow_words
argument_list|(
name|__ix
argument_list|,
name|true
argument_list|)
decl_stmt|;
return|return
name|__word
operator|.
name|_M_iword
return|;
block|}
comment|/**      *  @brief  Access to void pointer array.      *  @param  __ix  Index into the array.      *  @return  A reference to a void* associated with the index.      *      *  The pword function provides access to an array of pointers that can be      *  used for any purpose.  The array grows as required to hold the      *  supplied index.  All pointers in the array are initialized to 0.      *      *  The implementation reserves several indices.  You should use xalloc to      *  obtain an index that is safe to use.  Also note that since the array      *  can grow dynamically, it is not safe to hold onto the reference.     */
specifier|inline
name|void
modifier|*
modifier|&
name|pword
parameter_list|(
name|int
name|__ix
parameter_list|)
block|{
name|_Words
modifier|&
name|__word
init|=
operator|(
name|__ix
operator|<
name|_M_word_size
operator|)
condition|?
name|_M_word
index|[
name|__ix
index|]
else|:
name|_M_grow_words
argument_list|(
name|__ix
argument_list|,
name|false
argument_list|)
decl_stmt|;
return|return
name|__word
operator|.
name|_M_pword
return|;
block|}
comment|// Destructor
comment|/**      *  Invokes each callback with erase_event.  Destroys local storage.      *      *  Note that the ios_base object for the standard streams never gets      *  destroyed.  As a result, any callbacks registered with the standard      *  streams will not get invoked with erase_event (unless copyfmt is      *  used).     */
name|virtual
operator|~
name|ios_base
argument_list|()
expr_stmt|;
name|protected
label|:
name|ios_base
argument_list|()
expr_stmt|;
comment|// _GLIBCXX_RESOLVE_LIB_DEFECTS
comment|// 50.  Copy constructor and assignment operator of ios_base
name|private
label|:
name|ios_base
argument_list|(
specifier|const
name|ios_base
operator|&
argument_list|)
expr_stmt|;
name|ios_base
modifier|&
name|operator
init|=
operator|(
specifier|const
name|ios_base
operator|&
operator|)
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// [27.4.5.1] fmtflags manipulators
end_comment

begin_comment
comment|/// Calls base.setf(ios_base::boolalpha).
end_comment

begin_function
specifier|inline
name|ios_base
modifier|&
name|boolalpha
parameter_list|(
name|ios_base
modifier|&
name|__base
parameter_list|)
block|{
name|__base
operator|.
name|setf
argument_list|(
name|ios_base
operator|::
name|boolalpha
argument_list|)
expr_stmt|;
return|return
name|__base
return|;
block|}
end_function

begin_comment
comment|/// Calls base.unsetf(ios_base::boolalpha).
end_comment

begin_function
specifier|inline
name|ios_base
modifier|&
name|noboolalpha
parameter_list|(
name|ios_base
modifier|&
name|__base
parameter_list|)
block|{
name|__base
operator|.
name|unsetf
argument_list|(
name|ios_base
operator|::
name|boolalpha
argument_list|)
expr_stmt|;
return|return
name|__base
return|;
block|}
end_function

begin_comment
comment|/// Calls base.setf(ios_base::showbase).
end_comment

begin_function
specifier|inline
name|ios_base
modifier|&
name|showbase
parameter_list|(
name|ios_base
modifier|&
name|__base
parameter_list|)
block|{
name|__base
operator|.
name|setf
argument_list|(
name|ios_base
operator|::
name|showbase
argument_list|)
expr_stmt|;
return|return
name|__base
return|;
block|}
end_function

begin_comment
comment|/// Calls base.unsetf(ios_base::showbase).
end_comment

begin_function
specifier|inline
name|ios_base
modifier|&
name|noshowbase
parameter_list|(
name|ios_base
modifier|&
name|__base
parameter_list|)
block|{
name|__base
operator|.
name|unsetf
argument_list|(
name|ios_base
operator|::
name|showbase
argument_list|)
expr_stmt|;
return|return
name|__base
return|;
block|}
end_function

begin_comment
comment|/// Calls base.setf(ios_base::showpoint).
end_comment

begin_function
specifier|inline
name|ios_base
modifier|&
name|showpoint
parameter_list|(
name|ios_base
modifier|&
name|__base
parameter_list|)
block|{
name|__base
operator|.
name|setf
argument_list|(
name|ios_base
operator|::
name|showpoint
argument_list|)
expr_stmt|;
return|return
name|__base
return|;
block|}
end_function

begin_comment
comment|/// Calls base.unsetf(ios_base::showpoint).
end_comment

begin_function
specifier|inline
name|ios_base
modifier|&
name|noshowpoint
parameter_list|(
name|ios_base
modifier|&
name|__base
parameter_list|)
block|{
name|__base
operator|.
name|unsetf
argument_list|(
name|ios_base
operator|::
name|showpoint
argument_list|)
expr_stmt|;
return|return
name|__base
return|;
block|}
end_function

begin_comment
comment|/// Calls base.setf(ios_base::showpos).
end_comment

begin_function
specifier|inline
name|ios_base
modifier|&
name|showpos
parameter_list|(
name|ios_base
modifier|&
name|__base
parameter_list|)
block|{
name|__base
operator|.
name|setf
argument_list|(
name|ios_base
operator|::
name|showpos
argument_list|)
expr_stmt|;
return|return
name|__base
return|;
block|}
end_function

begin_comment
comment|/// Calls base.unsetf(ios_base::showpos).
end_comment

begin_function
specifier|inline
name|ios_base
modifier|&
name|noshowpos
parameter_list|(
name|ios_base
modifier|&
name|__base
parameter_list|)
block|{
name|__base
operator|.
name|unsetf
argument_list|(
name|ios_base
operator|::
name|showpos
argument_list|)
expr_stmt|;
return|return
name|__base
return|;
block|}
end_function

begin_comment
comment|/// Calls base.setf(ios_base::skipws).
end_comment

begin_function
specifier|inline
name|ios_base
modifier|&
name|skipws
parameter_list|(
name|ios_base
modifier|&
name|__base
parameter_list|)
block|{
name|__base
operator|.
name|setf
argument_list|(
name|ios_base
operator|::
name|skipws
argument_list|)
expr_stmt|;
return|return
name|__base
return|;
block|}
end_function

begin_comment
comment|/// Calls base.unsetf(ios_base::skipws).
end_comment

begin_function
specifier|inline
name|ios_base
modifier|&
name|noskipws
parameter_list|(
name|ios_base
modifier|&
name|__base
parameter_list|)
block|{
name|__base
operator|.
name|unsetf
argument_list|(
name|ios_base
operator|::
name|skipws
argument_list|)
expr_stmt|;
return|return
name|__base
return|;
block|}
end_function

begin_comment
comment|/// Calls base.setf(ios_base::uppercase).
end_comment

begin_function
specifier|inline
name|ios_base
modifier|&
name|uppercase
parameter_list|(
name|ios_base
modifier|&
name|__base
parameter_list|)
block|{
name|__base
operator|.
name|setf
argument_list|(
name|ios_base
operator|::
name|uppercase
argument_list|)
expr_stmt|;
return|return
name|__base
return|;
block|}
end_function

begin_comment
comment|/// Calls base.unsetf(ios_base::uppercase).
end_comment

begin_function
specifier|inline
name|ios_base
modifier|&
name|nouppercase
parameter_list|(
name|ios_base
modifier|&
name|__base
parameter_list|)
block|{
name|__base
operator|.
name|unsetf
argument_list|(
name|ios_base
operator|::
name|uppercase
argument_list|)
expr_stmt|;
return|return
name|__base
return|;
block|}
end_function

begin_comment
comment|/// Calls base.setf(ios_base::unitbuf).
end_comment

begin_function
specifier|inline
name|ios_base
modifier|&
name|unitbuf
parameter_list|(
name|ios_base
modifier|&
name|__base
parameter_list|)
block|{
name|__base
operator|.
name|setf
argument_list|(
name|ios_base
operator|::
name|unitbuf
argument_list|)
expr_stmt|;
return|return
name|__base
return|;
block|}
end_function

begin_comment
comment|/// Calls base.unsetf(ios_base::unitbuf).
end_comment

begin_function
specifier|inline
name|ios_base
modifier|&
name|nounitbuf
parameter_list|(
name|ios_base
modifier|&
name|__base
parameter_list|)
block|{
name|__base
operator|.
name|unsetf
argument_list|(
name|ios_base
operator|::
name|unitbuf
argument_list|)
expr_stmt|;
return|return
name|__base
return|;
block|}
end_function

begin_comment
comment|// [27.4.5.2] adjustfield anipulators
end_comment

begin_comment
comment|/// Calls base.setf(ios_base::internal, ios_base::adjustfield).
end_comment

begin_function
specifier|inline
name|ios_base
modifier|&
name|internal
parameter_list|(
name|ios_base
modifier|&
name|__base
parameter_list|)
block|{
name|__base
operator|.
name|setf
argument_list|(
name|ios_base
operator|::
name|internal
argument_list|,
name|ios_base
operator|::
name|adjustfield
argument_list|)
expr_stmt|;
return|return
name|__base
return|;
block|}
end_function

begin_comment
comment|/// Calls base.setf(ios_base::left, ios_base::adjustfield).
end_comment

begin_function
specifier|inline
name|ios_base
modifier|&
name|left
parameter_list|(
name|ios_base
modifier|&
name|__base
parameter_list|)
block|{
name|__base
operator|.
name|setf
argument_list|(
name|ios_base
operator|::
name|left
argument_list|,
name|ios_base
operator|::
name|adjustfield
argument_list|)
expr_stmt|;
return|return
name|__base
return|;
block|}
end_function

begin_comment
comment|/// Calls base.setf(ios_base::right, ios_base::adjustfield).
end_comment

begin_function
specifier|inline
name|ios_base
modifier|&
name|right
parameter_list|(
name|ios_base
modifier|&
name|__base
parameter_list|)
block|{
name|__base
operator|.
name|setf
argument_list|(
name|ios_base
operator|::
name|right
argument_list|,
name|ios_base
operator|::
name|adjustfield
argument_list|)
expr_stmt|;
return|return
name|__base
return|;
block|}
end_function

begin_comment
comment|// [27.4.5.3] basefield anipulators
end_comment

begin_comment
comment|/// Calls base.setf(ios_base::dec, ios_base::basefield).
end_comment

begin_function
specifier|inline
name|ios_base
modifier|&
name|dec
parameter_list|(
name|ios_base
modifier|&
name|__base
parameter_list|)
block|{
name|__base
operator|.
name|setf
argument_list|(
name|ios_base
operator|::
name|dec
argument_list|,
name|ios_base
operator|::
name|basefield
argument_list|)
expr_stmt|;
return|return
name|__base
return|;
block|}
end_function

begin_comment
comment|/// Calls base.setf(ios_base::hex, ios_base::basefield).
end_comment

begin_function
specifier|inline
name|ios_base
modifier|&
name|hex
parameter_list|(
name|ios_base
modifier|&
name|__base
parameter_list|)
block|{
name|__base
operator|.
name|setf
argument_list|(
name|ios_base
operator|::
name|hex
argument_list|,
name|ios_base
operator|::
name|basefield
argument_list|)
expr_stmt|;
return|return
name|__base
return|;
block|}
end_function

begin_comment
comment|/// Calls base.setf(ios_base::oct, ios_base::basefield).
end_comment

begin_function
specifier|inline
name|ios_base
modifier|&
name|oct
parameter_list|(
name|ios_base
modifier|&
name|__base
parameter_list|)
block|{
name|__base
operator|.
name|setf
argument_list|(
name|ios_base
operator|::
name|oct
argument_list|,
name|ios_base
operator|::
name|basefield
argument_list|)
expr_stmt|;
return|return
name|__base
return|;
block|}
end_function

begin_comment
comment|// [27.4.5.4] floatfield anipulators
end_comment

begin_comment
comment|/// Calls base.setf(ios_base::fixed, ios_base::floatfield).
end_comment

begin_function
specifier|inline
name|ios_base
modifier|&
name|fixed
parameter_list|(
name|ios_base
modifier|&
name|__base
parameter_list|)
block|{
name|__base
operator|.
name|setf
argument_list|(
name|ios_base
operator|::
name|fixed
argument_list|,
name|ios_base
operator|::
name|floatfield
argument_list|)
expr_stmt|;
return|return
name|__base
return|;
block|}
end_function

begin_comment
comment|/// Calls base.setf(ios_base::scientific, ios_base::floatfield).
end_comment

begin_function
specifier|inline
name|ios_base
modifier|&
name|scientific
parameter_list|(
name|ios_base
modifier|&
name|__base
parameter_list|)
block|{
name|__base
operator|.
name|setf
argument_list|(
name|ios_base
operator|::
name|scientific
argument_list|,
name|ios_base
operator|::
name|floatfield
argument_list|)
expr_stmt|;
return|return
name|__base
return|;
block|}
end_function

begin_comment
unit|}
comment|// namespace std
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IOS_BASE_H */
end_comment

end_unit

